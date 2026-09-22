#!/usr/bin/env python3
"""Build one Japanese promotion batch in krystalgamer's tree, in ONE pass from origin/master.

    .venv/bin/python tools_src/jp_batch.py SPEC --branch jp/batchN            # build, gate, commit locally
    .venv/bin/python tools_src/jp_batch.py SPEC --branch jp/batchN --no-gates # stop after the structural checks

SPEC is a text file, one unit per line:

    unit|us_addr|absorbed_unit:jp_addr,absorbed_unit:jp_addr
    sound_frontend|0x8003fe80|                  <- a wholly unpromoted unit: empty third field

WHY THIS LIVES IN THE REPO. Its predecessor was a shell script in the session
scratchpad under /tmp, and a restart of the Claude Code process on 2026-09-22
recreated that directory empty. It carried a full day of fixes, every one of
which cost a failed build to find. Nothing that took a failure to learn belongs
in /tmp.

WHY A SINGLE PASS. A per-unit script that re-takes master's three config files on
every run silently UNDOES the absorptions already committed on the branch, while
re-absorbing only the unit being run: master still carries every landed
single-function unit, so the second unit's run restored the first unit's absorbed
entries beside its whole-unit c line, splat regenerated their nonmatching stubs,
and the assembler met `glabel` with no macros. That reads exactly like a stale
artifact and wiping tmp/splat changes nothing. So the batch is declared once and
applied once, and re-running it on a moved master is the re-merge.

WHAT EACH STEP GUARDS AGAINST, each learned from a failed build:
  * absorption carries a POSITIVE CONTROL: if the plain address string is in the
    manifest, the entry regex must match exactly once, or the run fails. An
    earlier version uppercased the whole address ("0X80044B38") and matched
    nothing, then reported "nothing to remove" and carried on;
  * removing the LAST manifest entry leaves a dangling comma before the "]";
  * absorbing means removing every split boundary STRICTLY INSIDE the unit's
    range, not only the absorbed unit's own c line, or the leftover range is
    assembled beside the wrapper and the link reports multiple definitions;
  * the manifest invariant is asserted on the PARSED json, never on a numstat:
    git coalesces identical lines around an insertion, so +42/-12 renders as
    +37/-7 with the same net;
  * ALIASES handles a symbol whose Japanese address is already named under a
    different name (splat refuses a second name for one address), by renaming the
    identifier in the wrapper instead of writing a symbols line;
  * ASM_LABELS handles a shared source that declares a view with an asm label of
    its own: pre-declaring the identifier with the Japanese label wins, because
    gcc 2.8.1 fixes an extern's RTL at its FIRST declaration (#5697, and measured
    again on sound_output_transition);
  * gate logs go under the tree's own tmp/, which survives a process restart.
"""
import argparse, collections, json, os, pathlib, re, subprocess, sys

KG = pathlib.Path(os.environ.get("YGOFM_KG", "/home/marchaleski/memories-decomp"))
TOOL = pathlib.Path(__file__).resolve().parent / "jp_promote.py"
PY = str(KG / "tools/environments/python/bin/python")
SHA = "ee3f45584fb747fd33c9560f0fc68ced03b399fbd9a2e9d6a71eb0f5daa89585"
MC = KG / "config/slpm_86398/matching_c.json"
SPLIT = KG / "config/slpm_86398/split.yaml"
SYMS = KG / "config/slpm_86398/symbols.txt"
US_MC = KG / "config/slus_01411/matching_c.json"
CFG = [str(MC.relative_to(KG)), str(SPLIT.relative_to(KG)), str(SYMS.relative_to(KG))]
LOGS = KG / "tmp/jp_batch_gates"
LOAD, HDR = 0x80010000, 0x800

# unit -> [(name the shared source uses, name the Japanese symbols already give that address)]
ALIASES = {
    # upstream model_packet_handler_lookup.c already carries this exact #define
    "func_8005CEF0": [("func_8005CEF0", "func_8005EEDC")],
    "model_interpolate_transform": [("func_8005D378", "func_8005F364")],
}
# unit -> lines to pre-declare before `#include "../<unit>.c"`
ASM_LABELS = {
    "sound_output_transition": ['#include "../sound.h"',
        'extern SDValue *volatile g_SDValue_output_transition asm("gJapanese_SDValue");'],
    "sound_output_state": ['#include "../sound.h"',
        'extern SDValue *volatile g_SDValue_output_level asm("gJapanese_SDValue");'],
}


def run(cmd, log=None, check=True):
    out = subprocess.run(cmd, cwd=KG, shell=isinstance(cmd, str), capture_output=True, text=True)
    if log:
        LOGS.mkdir(parents=True, exist_ok=True)
        (LOGS / log).write_text(out.stdout + out.stderr)
    if check and out.returncode:
        tail = (out.stdout + out.stderr).strip().splitlines()[-8:]
        sys.exit(f"FAILED: {cmd}\n" + "\n".join(tail) + (f"\n(full log: {LOGS / log})" if log else ""))
    return out


def parse_spec(path):
    rows = []
    for line in pathlib.Path(path).read_text().splitlines():
        if not line.strip() or line.lstrip().startswith("#"): continue
        unit, addr, absorbed = (line.split("|") + ["", ""])[:3]
        pairs = [tuple(p.split(":")) for p in absorbed.split(",") if p.strip()]
        rows.append((unit.strip(), addr.strip(), pairs))
    return rows


def absorb(rows):
    removed = 0
    for unit, _addr, pairs in rows:
        for absorbed, a in pairs:
            t = MC.read_text(); n0 = len(json.loads(t)["functions"])
            present = a.lower() in t.lower()
            blk = re.compile(r'\n *\{\n *"address": "%s",\n(?: *"[a-z]+": "[^"]*",?\n)+ *\},?' % re.escape(a),
                             re.M | re.I)
            hits = blk.findall(t)
            if not present: sys.exit(f"{absorbed} at {a} is not in master's manifest -- has it changed?")
            if len(hits) != 1:
                sys.exit(f"POSITIVE CONTROL FAILED: manifest contains {a} as text, the entry regex matched {len(hits)} times")
            t = re.sub(r',(\s*\])', r'\1', t.replace(hits[0], "", 1))
            if len(json.loads(t)["functions"]) != n0 - 1: sys.exit("manifest did not lose exactly one entry")
            MC.write_text(t); removed += 1
            s = SPLIT.read_text()
            lines = [l for l in s.splitlines(keepends=True) if f"game/japanese/{absorbed}" in l]
            if len(lines) > 1: sys.exit(f"split carries {len(lines)} lines for {absorbed}")
            if lines: SPLIT.write_text(s.replace(lines[0], "", 1))
            w = KG / f"src/game/japanese/{absorbed}.c"
            if w.exists(): run(["git", "rm", "-q", "-f", str(w.relative_to(KG))])
            print(f"  absorbed {absorbed} at {a} (manifest {n0} -> {n0 - 1})")
    # exact-duplicate symbols lines that two landings can each produce break master's own split
    seen, out, dup = set(), [], []
    for l in SYMS.read_text().splitlines(keepends=True):
        if l.strip() and l in seen: dup.append(l.strip()); continue
        seen.add(l); out.append(l)
    if dup: SYMS.write_text("".join(out)); print("  dropped duplicate symbols line(s):", dup)
    return removed


def unit_entries(unit):
    f = json.loads(MC.read_text())["functions"]
    cands = [f"src/game/japanese/{unit}.c", f"src/game/{unit}.c"]
    counts = {c: [x for x in f if x["source"] == c] for c in cands}
    jsrc = max(cands, key=lambda c: len(counts[c]))
    return jsrc, counts[jsrc]


def apply_aliases(rows):
    batch = {u for u, _, _ in rows}
    syms = SYMS.read_text()
    for unit, pairs in ALIASES.items():
        if unit not in batch: continue
        w = KG / f"src/game/japanese/{unit}.c"
        defines = []
        for src_name, jp_name in pairs:
            if not re.search(rf'^\s*{re.escape(jp_name)}\s*=', syms, re.M):
                sys.exit(f"{jp_name} is not named in the Japanese symbols")
            defines.append(f"#define {src_name} {jp_name}")
            # the apply wrote `src_name = <jp addr>`, which splat refuses beside jp_name
            syms = re.sub(rf"^{re.escape(src_name)}\s*=.*\n", "", syms, flags=re.M)
        SYMS.write_text(syms)
        if w.exists():
            t = w.read_text(); inc = f'#include "../{unit}.c"'
            add = [d for d in defines if d not in t]
            if add: w.write_text(t.replace("\n" + inc, "\n" + "\n".join(add) + "\n\n" + inc))
            print(f"  {unit}: wrapper existed, {len(add)} #define(s) added")
            continue
        w.write_text('#include "../../types.h"\n\n' + "\n".join(defines) + f'\n\n#include "../{unit}.c"\n')
        t = MC.read_text(); old, new = f'"src/game/{unit}.c"', f'"src/game/japanese/{unit}.c"'
        if not t.count(old): sys.exit(f"no manifest entry sourced at {old}")
        MC.write_text(t.replace(old, new))
        s = SPLIT.read_text(); o, n = f", c, game/{unit}]", f", c, game/japanese/{unit}]"
        if s.count(o) != 1: sys.exit(f"split carries {s.count(o)} lines for {o}")
        SPLIT.write_text(s.replace(o, n))
        print(f"  {unit}: wrapper written and repointed for {len(defines)} alias(es)")


def apply_asm_labels(rows):
    batch = {u for u, _, _ in rows}
    for unit, lines in ASM_LABELS.items():
        if unit not in batch: continue
        w = KG / f"src/game/japanese/{unit}.c"
        if not w.exists(): sys.exit(f"{unit} has no wrapper to pre-declare in")
        t = w.read_text(); inc = f'#include "../{unit}.c"'
        if inc not in t: sys.exit(f"{unit} wrapper does not include the shared source")
        if lines[-1] in t: print(f"  {unit}: pre-declaration already present"); continue
        w.write_text(t.replace("\n" + inc, "\n" + "\n".join(lines) + "\n\n" + inc))
        print(f"  {unit}: pre-declared with the Japanese label")


def check_structure(rows):
    us = json.loads(US_MC.read_text())["functions"]
    f = json.loads(MC.read_text())["functions"]
    pat = re.compile(r'^\s*-\s*\[\s*(0x[0-9a-fA-F]+)\s*,')
    total = 0
    for unit, _addr, pairs in rows:
        expect = len([x for x in us if x["source"] == f"src/game/{unit}.c"])
        jsrc, mine = unit_entries(unit)
        if len(mine) != expect: sys.exit(f"{unit}: {len(mine)} entries under {jsrc}, the US manifest says {expect}")
        total += expect
        lo = min(int(x["address"], 16) for x in mine)
        hi = max(int(x["address"], 16) + int(x["size"], 16) for x in mine)
        S, E = lo - LOAD + HDR, hi - LOAD + HDR
        keep, dropped = [], []
        for l in SPLIT.read_text().splitlines(keepends=True):
            m = pat.match(l)
            if m and S < int(m.group(1), 16) < E: dropped.append(l.strip()); continue
            keep.append(l)
        if dropped: SPLIT.write_text("".join(keep))
        seg = ("game/japanese/" if jsrc.startswith("src/game/japanese/") else "game/") + unit
        if f"[{S:#x}, c, {seg}]" not in "".join(keep): sys.exit(f"{unit}: c line [{S:#x}, c, {seg}] missing")
        for absorbed, _ in pairs:
            if [x for x in f if x["source"] == f"src/game/japanese/{absorbed}.c"]: sys.exit(f"{absorbed} still in manifest")
            if (KG / f"src/game/japanese/{absorbed}.c").exists(): sys.exit(f"{absorbed}.c still on disk")
        print(f"  {unit}: {expect} entries under {jsrc}, {S:#x}..{E:#x}, {len(dropped)} inner boundary line(s) dropped")
    dup = {a: n for a, n in collections.Counter(x["address"].lower() for x in json.loads(MC.read_text())["functions"]).items() if n > 1}
    if dup: sys.exit(f"duplicate manifest addresses: {dup}")
    print(f"  manifest: {len(json.loads(MC.read_text())['functions'])} entries, {total} functions in the batch, every address unique")
    return total


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("spec"); ap.add_argument("--branch", required=True)
    ap.add_argument("--no-gates", action="store_true")
    a = ap.parse_args()
    rows = parse_spec(a.spec)
    if not rows: sys.exit("empty spec")
    if run(["git", "status", "--short"]).stdout.strip(): sys.exit("dirty tree -- clean it first")
    run(["git", "fetch", "-q", "origin"])
    run(["git", "checkout", "-q", "-B", a.branch, "origin/master"])
    run("rm -rf tmp/splat/slpm_86398")
    print(f"batch of {len(rows)} unit(s) on {a.branch} from origin/master")
    absorb(rows)
    run("MAKEFLAGS=-j2 make japanese-split", log="split1.log")
    for unit, addr, _ in rows:
        out = run([PY, str(TOOL), "apply", addr], check=False)
        if out.returncode: sys.exit(f"apply {unit} failed: {(out.stdout + out.stderr).strip()[-300:]}")
        print(" ", out.stdout.strip().splitlines()[-1][:150] if out.stdout.strip() else f"applied {unit}")
    apply_aliases(rows)
    apply_asm_labels(rows)
    total = check_structure(rows)
    run("MAKEFLAGS=-j2 make japanese-split", log="split2.log")
    # Each config file must end in EXACTLY one newline. The promoter appends lines and
    # the dedupe rewrites the file, and between them a trailing blank line appeared:
    # batch 18 passed every build gate and then failed `git diff --check` on
    # "symbols.txt:1075: new blank line at EOF". Normalise before staging.
    for f in (MC, SPLIT, SYMS):
        t = f.read_text(); n = t.rstrip("\n") + "\n"
        if n != t: f.write_text(n)
    run(["git", "add", *CFG, "src/game/japanese/", "src/game/"])
    if a.no_gates:
        print(f"structural checks passed for {total} functions; gates skipped"); return
    run("MAKEFLAGS=-j2 make verify-japanese-inputs", log="g1_inputs.log")
    m = run("MAKEFLAGS=-j2 make japanese-match", log="g2_match.log", check=False)
    body = m.stdout + m.stderr
    if m.returncode or not re.search(r"^MATCH  tmp/project-build/SLPM_863\.98", body, re.M) or SHA not in body:
        diag = [l for l in body.splitlines()
                if re.search(r"in function|undefined reference|multiple definition|mismatch at file offset", l)
                and "sound_init" not in l]
        sys.exit("japanese-match FAILED -- the unit to drop is named here:\n  " + "\n  ".join(diag[-6:] or body.splitlines()[-4:])
                 + f"\n(full log: {LOGS / 'g2_match.log'})")
    print("  japanese-match MATCH, sha256 ok")
    for t in ("basic-types", "check-data-symbols", "check-metadata", "external-attempts",
              "check-notes", "check-matching-source-contracts"):
        run(f"MAKEFLAGS=-j2 make {t}", log=f"g_{t}.log"); print(f"  {t} ok")
    run([PY, "-m", "unittest", "discover", "-s", "tools/project/tests"], log="g_unittest.log"); print("  unittest ok")
    run(["git", "diff", "--cached", "--check"])
    units = ", ".join(u for u, _, _ in rows)
    msg = (f"Match {len(rows)} Japanese unit(s): {units}\n\n"
           f"{total} functions promoted from the unchanged US sources. Gated: "
           "verify-japanese-inputs, japanese-match MATCH sha256 ee3f4558..., basic-types, "
           "check-data-symbols, check-metadata, external-attempts, check-notes, "
           "check-matching-source-contracts, the unit test suite, and assertions that each unit "
           "holds exactly the US manifest's function count, that no manifest address repeats, and "
           "that no split boundary lies strictly inside any unit's range.\n\n"
           "Co-Authored-By: Claude Opus 5 <noreply@anthropic.com>\n")
    c = subprocess.run(["git", "commit", "-q", "-F", "-"], cwd=KG, input=msg, text=True, capture_output=True)
    if c.returncode: sys.exit(f"commit failed: {c.stderr.strip()}")
    head = run(["git", "rev-parse", "--short=12", "HEAD"]).stdout.strip()
    print(f"committed {head} on {a.branch}: {total} functions, {len(rows)} unit(s); not pushed")


if __name__ == "__main__":
    main()
