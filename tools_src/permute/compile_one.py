#!/usr/bin/env python3
"""Compile one already-preprocessed C file to a .o with the project toolchain.

The permuter hands us a file that gcc -E has already flattened, so cpp has
nothing left to do; everything after it is build.py's own pipeline, imported
rather than restated so the two cannot drift.
"""
import os
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import build as B  # noqa: E402

FUNC = os.environ.get("PERMUTER_FUNC", "")


def main():
    src, out = Path(sys.argv[1]), Path(sys.argv[-1])
    scratch = out.parent
    asm = scratch / (src.stem + ".s")
    masm = scratch / (src.stem + ".maspsx.s")

    flags = B.PER_FUNC_FLAGS.get(FUNC, B.CC1_FLAGS)
    r = subprocess.run([*B.PSYQ_RUNNER, str(B.CC1PSX), *flags,
                        str(src), "-o", str(asm)],
                       capture_output=True, text=True)
    if r.returncode != 0 or not asm.exists():
        sys.stderr.write(r.stderr[-3000:])
        return 1

    with open(asm) as fin, open(masm, "w") as fout:
        r = subprocess.run([str(B.VENV_PYTHON), str(B.MASPSX),
                            f"--aspsx-version={B.ASPSX_VERSION}",
                            "--macro-inc", "--expand-div"],
                           stdin=fin, stdout=fout, stderr=subprocess.PIPE,
                           text=True, cwd=B.ROOT)
    if r.returncode != 0:
        sys.stderr.write(r.stderr[-3000:])
        return 1

    text = masm.read_text().splitlines()
    if FUNC in B.SMALL_DATA_NOP_FUNCS:
        text = B.insert_small_data_load_delay_nops(
            text, sdata_limit=B.effective_sdata_limit(FUNC))
    if FUNC in B.DELAY_SLOT_MACRO_FUNCS:
        text = B.fill_delay_slot_with_macro_tail(text)
    if FUNC in B.LA_CALL_FUNCS:
        text = B.split_address_across_call(text)
    if FUNC in B.HOIST_EPILOGUE_FUNCS:
        text = B.hoist_epilogue_out_of_delay_slot(text)
    masm.write_text("\n".join(text) + "\n")

    as_flags = list(B.AS_FLAGS)
    override = B.PER_FUNC_AS_FLAGS.get(FUNC)
    if override:
        as_flags.append(override)
    r = subprocess.run([str(B.AS), *as_flags, "-o", str(out), str(masm)],
                       capture_output=True, text=True, cwd=B.ROOT)
    if r.returncode != 0:
        sys.stderr.write(r.stderr[-3000:])
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
