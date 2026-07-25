#!/usr/bin/env python3
"""
Try compiler/assembler flag combinations for one function until it matches.

    python tools_src/sweep_flags.py func_8001700C

Writes each candidate combination to config/flag_overrides.json, runs the
build, and reports the first one under which the function stops differing.
On success the winning combination is left in place so it can be moved
into build.py's tables; on failure the override file is removed.

This exists because sweeping by hand meant editing build.py by string
substitution, which failed silently more than once -- and a flag that
never took effect is indistinguishable from a flag that did not help.
"""

import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OVERRIDES = ROOT / "config" / "flag_overrides.json"
BUILD = [str(ROOT / ".venv" / "bin" / "python"), "tools_src/build.py"]

# Ordered cheapest/most-likely first. The -fno-delayed-branch entries are
# for functions whose target leaves a *branch* delay slot empty, and the
# -fno-schedule-insns2 entries for a *load* delay slot the retail code leaves
# as a nop; see the "unfilled delay slot" section of docs/DECISIONS.md.
# Note -fno-schedule-insns (without the 2) is accepted but changes nothing --
# it was verified to produce byte-identical cc1psx output, so do not add it.
COMBOS = [
    ("O2 G8",                 ["-quiet", "-O2", "-G8"], None),
    ("O1 G8",                 ["-quiet", "-O1", "-G8"], None),
    ("O2 G8 nosched2",        ["-quiet", "-O2", "-G8", "-fno-schedule-insns2"], None),
    ("O1 G8 nosched2",        ["-quiet", "-O1", "-G8", "-fno-schedule-insns2"], None),
    ("O2 G8 macro",           ["-quiet", "-O2", "-G8",
                               "-mno-split-addresses"], None),
    ("O1 G8 macro",           ["-quiet", "-O1", "-G8",
                               "-mno-split-addresses"], None),
    ("O2 G0",                 ["-quiet", "-O2", "-G0"], "-G0"),
    ("O1 G0",                 ["-quiet", "-O1", "-G0"], "-G0"),
    ("O2 G0 nosched2",        ["-quiet", "-O2", "-G0", "-fno-schedule-insns2"], "-G0"),
    ("O2 G8 nosched2 nodelay", ["-quiet", "-O2", "-G8", "-fno-schedule-insns2",
                                "-fno-delayed-branch"], None),
    ("O2 G0 nosched2 macro",  ["-quiet", "-O2", "-G0", "-fno-schedule-insns2",
                               "-mno-split-addresses"], "-G0"),
    ("O2 G8 nodelay",         ["-quiet", "-O2", "-G8", "-fno-delayed-branch"], None),
    ("O1 G8 nodelay",         ["-quiet", "-O1", "-G8", "-fno-delayed-branch"], None),
    ("O2 G0 nodelay",         ["-quiet", "-O2", "-G0", "-fno-delayed-branch"], "-G0"),
    ("O1 G0 nodelay",         ["-quiet", "-O1", "-G0", "-fno-delayed-branch"], "-G0"),
    ("O2 G0 nodelay macro",   ["-quiet", "-O2", "-G0", "-fno-delayed-branch",
                               "-mno-split-addresses"], "-G0"),
    ("O1 G0 nodelay macro",   ["-quiet", "-O1", "-G0", "-fno-delayed-branch",
                               "-mno-split-addresses"], "-G0"),
    ("O2 G8 nodelay macro",   ["-quiet", "-O2", "-G8", "-fno-delayed-branch",
                               "-mno-split-addresses"], None),
]


def build_reports(func):
    """Run the build; return True only if it completed and `func` matched.

    The "completed" half is not pedantry. This function used to fall through
    to "is `func` named in the output?" whenever the byte-identical line was
    absent -- including when the build *failed*. A link error names the file
    as `src/func_X.c:(.text+0x24): relocation truncated`, which matches none
    of the patterns below, so a crashed build read as a clean one and the
    sweeper reported a combination that does not even link as a MATCH.

    Absence of a complaint is not evidence of success when the thing that
    would have complained never ran.
    """
    r = subprocess.run(BUILD, cwd=ROOT, capture_output=True, text=True)
    out = r.stdout + r.stderr
    if "OK: build is byte-identical" in out:
        return True, "whole build matches"
    if r.returncode != 0 or "sha1  :" not in out:
        return False, "build failed"
    # Named either as a size error or in the differing list.
    bad = any(func in line for line in out.splitlines()
              if line.strip().startswith(func) or f" {func}:" in line
              or f"  {func} " in line or f"({func}" in line)
    return (not bad), ("clean" if not bad else "differs")


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    func = sys.argv[1]
    if not (ROOT / "src" / f"{func}.c").exists():
        sys.exit(f"src/{func}.c does not exist -- write a candidate first")

    for label, cc, asf in COMBOS:
        # "as" is always set, to None when the combination wants the default.
        # Omitting it instead left whatever PER_FUNC_AS_FLAGS already held for
        # this function in place, so a combination labelled "O2 G8" could
        # silently be tested against a -G0 assembler -- and report a match that
        # does not reproduce when the entry is removed.
        spec = {"cc": cc, "as": asf}
        OVERRIDES.write_text(json.dumps({func: spec}, indent=1))
        ok, why = build_reports(func)
        print(f"  {'MATCH' if ok else 'no   '}  {label}"
              f"{'' if ok else '  (' + why + ')'}", flush=True)
        if ok:
            print(f"\nleft config/flag_overrides.json holding: {label}")
            print(f"  cc: {' '.join(cc)}\n  as: {asf or '(default)'}")
            return 0

    OVERRIDES.unlink(missing_ok=True)
    print(f"\nno combination matched {func}; override file removed")
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
