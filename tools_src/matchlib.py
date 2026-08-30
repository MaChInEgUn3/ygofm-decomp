#!/usr/bin/env python3
"""
Shared scoring core: compile one candidate, score it against the target.

There were three copies of "shell out to try_func and parse its stdout" in
this tree (transplant.py, install_ported.py, and the scratchpad aligner)
before this file existed, and try_func's own docstring is a record of what
drifting copies cost here -- it once carried a stale SDK path and a stale
aspsx version and printed confident side-by-side diffs about the wrong
compiler. So the scoring path is one function, in-process, and everything
else calls it.

In-process also makes the enumerator possible at all. Shelling out costs a
Python start plus a re-import of build.py per variant, which is most of the
wall clock when you are compiling hundreds of variants; calling `built_lines`
directly pays that once per worker process.

Two disciplines are baked in here rather than written down somewhere and
remembered:

  * **A diffs count is never reported without both word counts.** The
    positional diff marks every line after a missing instruction as differing,
    so a candidate one word short scores like the length of its tail while a
    candidate with seven real register disagreements scores seven. Ranking by
    diffs alone inverts the truth exactly when you are closest. Everything
    here ranks by `(abs(len_err), diffs)` and carries `len_err` in the result.
  * **Identical instruction streams collapse.** Each result carries a hash of
    the built stream, so N variants that compile to the same thing are one
    row. That is not just deduplication: "several spellings score identically"
    is this project's standing signal that the axis is wrong, and collapsing
    prints it for free instead of leaving it to be noticed.
"""

import hashlib
import os
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import build as B  # noqa: E402
import try_func as T  # noqa: E402

ROOT = B.ROOT

_TARGETS = {}


def target(func):
    """The retail listing's instructions, cached -- it never changes."""
    if func not in _TARGETS:
        _TARGETS[func] = T.target_lines(func)
    return _TARGETS[func]


class Result:
    """One measurement. `len_err` is built minus target, in instructions."""

    __slots__ = ("status", "len_err", "diffs", "key", "flags", "note")

    def __init__(self, status, len_err=None, diffs=None, key=None,
                 flags=(), note=""):
        self.status, self.len_err, self.diffs = status, len_err, diffs
        self.key, self.flags, self.note = key, tuple(flags), note

    @property
    def rank(self):
        """The project's ordering: length first, then differences.

        Not because length is more important, but because a length error makes
        the difference count meaningless -- see the class docstring. A zero
        here can still be two faults cancelling (func_8004A518's `u16` adds an
        `andi` the target lacks and suppresses a hoist the target wants), so a
        zero that arrives without an explanation is worth one structural read
        before it is trusted.
        """
        if self.status != "OK":
            return (99, 10 ** 6)
        return (abs(self.len_err), self.diffs)

    def __str__(self):
        if self.status != "OK":
            return "%-6s %s" % (self.status, self.note[:60])
        if self.diffs == 0 and self.len_err == 0:
            return "MATCH"
        return "len %+d  diffs %d" % (self.len_err, self.diffs)


def score(func, text, cc_flags):
    """Compile `text` for `func` under `cc_flags` and score it.

    Never raises for a bad candidate: `built_lines` calls sys.exit on a
    compile error, which would take a worker process down mid-sweep, so that
    is caught and reported as a row like any other. A sweep that dies on the
    first candidate that does not compile is not a sweep.
    """
    src = T.SCRATCH / "cand.c"
    T.SCRATCH.mkdir(parents=True, exist_ok=True)
    src.write_text(text)
    try:
        built = T.built_lines(func, src, list(cc_flags))
    except SystemExit as e:
        return Result("ERROR", flags=cc_flags, note=str(e).replace("\n", " "))
    except Exception as e:  # noqa: BLE001 -- a sweep must not die on one row
        return Result("ERROR", flags=cc_flags, note=repr(e))

    tgt = target(func)
    built = T.renumber_labels(built)
    tgt_n = T.renumber_labels(list(tgt))
    key = hashlib.sha1("\n".join(built).encode()).hexdigest()[:12]
    diffs = sum(1 for a, b in zip(tgt_n, built) if a != b) + \
        abs(len(tgt_n) - len(built))
    return Result("OK", len(built) - len(tgt_n), diffs, key, cc_flags)


def score_preprocessed(func, itext, cc_flags):
    """Same as `score`, but `itext` is already preprocessed.

    This is what makes the enumerator affordable. Wine is the whole cost here
    -- `cpppsx` and `cc1psx` are ~1.9 s each through it while `as` and
    `objdump` are native and round to zero -- so preprocessing once per sketch
    instead of once per variant is a straight halving. The price is that a
    variant body may not contain a preprocessor directive; msearch refuses a
    sketch that has one rather than let a body through unpreprocessed.
    """
    T.SCRATCH.mkdir(parents=True, exist_ok=True)
    pre = T.SCRATCH / "cand.i"
    pre.write_text(itext)
    try:
        built = _from_i(func, pre, list(cc_flags))
    except SystemExit as e:
        return Result("ERROR", flags=cc_flags, note=str(e).replace("\n", " "))
    except Exception as e:  # noqa: BLE001
        return Result("ERROR", flags=cc_flags, note=repr(e))
    tgt = T.renumber_labels(list(target(func)))
    built = T.renumber_labels(built)
    key = hashlib.sha1("\n".join(built).encode()).hexdigest()[:12]
    diffs = sum(1 for a, b in zip(tgt, built) if a != b) + \
        abs(len(tgt) - len(built))
    return Result("OK", len(built) - len(tgt), diffs, key, cc_flags)


def _from_i(func, pre, flags):
    """cc1psx -> maspsx -> as -> objdump, starting from a `.i`.

    Deliberately a re-use of try_func's own post-passes rather than a second
    copy of them: the per-function fixups (delay-slot macro tails, small-data
    load nops, the la/call split, the epilogue hoist) are part of what "the
    bytes" means here, and a scoring path that skipped them would quietly
    disagree with the build on exactly the functions that needed them.
    """
    import subprocess
    asm = T.SCRATCH / "cand.s"
    r = subprocess.run([str(c) for c in (
        *B.PSYQ_RUNNER, B.CC1PSX, *flags,
        pre.relative_to(ROOT).as_posix(), "-o", asm.relative_to(ROOT).as_posix())],
        cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("cc1psx: " + (r.stderr or r.stdout)[:300])

    masm = T.SCRATCH / "cand.maspsx.s"
    with open(asm) as fin, open(masm, "w") as fout:
        r = subprocess.run(
            [str(B.VENV_PYTHON), str(B.MASPSX),
             f"--aspsx-version={B.ASPSX_VERSION}", "--macro-inc", "--expand-div"],
            stdin=fin, stdout=fout, stderr=subprocess.PIPE, text=True, cwd=ROOT)
    if r.returncode:
        raise SystemExit("maspsx: " + r.stderr[:300])

    text = masm.read_text().splitlines()
    if func in B.DELAY_SLOT_MACRO_FUNCS:
        text = B.fill_delay_slot_with_macro_tail(text)
    if func in B.SMALL_DATA_NOP_FUNCS:
        text = B.insert_small_data_load_delay_nops(
            text, sdata_limit=B.effective_sdata_limit(func))
    if func in B.LA_CALL_FUNCS:
        text = B.split_address_across_call(text)
    if func in B.HOIST_EPILOGUE_FUNCS:
        text = B.hoist_epilogue_out_of_delay_slot(text)
    masm.write_text("\n".join(text) + "\n")

    obj = T.SCRATCH / "cand.o"
    as_flags = list(B.AS_FLAGS)
    over = B.PER_FUNC_AS_FLAGS.get(func)
    if over:
        as_flags.append(over)
    r = subprocess.run([str(B.AS), *as_flags, "-o",
                        obj.relative_to(ROOT).as_posix(),
                        masm.relative_to(ROOT).as_posix()],
                       cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("as: " + r.stderr[:300])
    r = subprocess.run([str(B.OBJDUMP), "-dr", "-z", "--no-show-raw-insn",
                        obj.relative_to(ROOT).as_posix()],
                       cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("objdump: " + r.stderr[:300])
    return T._from_objdump(r.stdout, func)


# ------------------------------------------------------------------ runs

def runs(func, text, cc_flags):
    """Aligned insert/delete/replace runs, with a word delta per run.

    Ported in spirit from Unchiga's `tools/streamdiff.py`, and the reason to
    have it is his one sharp sentence about reading it: **an insert/delete
    PAIR is a REORDERING -- only a run with a non-zero word delta is missing
    or extra code.** difflib will happily align two similar loops to each
    other in the wrong order, and a whole afternoon here went into reading
    reorderings as lost instructions.
    """
    import difflib
    import re

    src = T.SCRATCH / "cand.c"
    T.SCRATCH.mkdir(parents=True, exist_ok=True)
    src.write_text(text)
    built = T.renumber_labels(T.built_lines(func, src, list(cc_flags)))
    tgt = T.renumber_labels(list(target(func)))

    def norm(x):
        return re.sub(r"\$[a-z0-9]+", "R", x)

    sm = difflib.SequenceMatcher(None, [norm(x) for x in tgt],
                                 [norm(x) for x in built], autojunk=False)
    out = []
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            continue
        out.append({
            "tag": tag,
            "target": tgt[i1:i2],
            "built": built[j1:j2],
            "words": (j2 - j1) - (i2 - i1),
        })
    return out
