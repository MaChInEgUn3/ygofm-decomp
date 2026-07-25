#!/usr/bin/env python3
"""
Test every per-function flag override by dropping it and rebuilding.

    python tools_src/audit_flags.py            # report only
    python tools_src/audit_flags.py --prune    # also print the entries to delete

Every entry in PER_FUNC_FLAGS / PER_FUNC_AS_FLAGS was derived under PsyQ 4.6,
which turned out to be the wrong compiler (see docs/DECISIONS.md). So each is a
hypothesis that has never been tested against the compiler the game actually
used. This drops them one at a time -- never in batches, because a single
wrong-sized function shifts everything after it and a batch result cannot be
attributed -- and reports which ones the build no longer needs.

An entry that collapses to the default was compensating for the wrong compiler.
An entry that survives is real evidence for the first time.
"""

import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OVERRIDES = ROOT / "config" / "flag_overrides.json"
BUILD = [str(ROOT / ".venv" / "bin" / "python"), "tools_src/build.py"]


def build_ok():
    r = subprocess.run(BUILD, cwd=ROOT, capture_output=True, text=True)
    return "OK: build is byte-identical" in (r.stdout + r.stderr)


def main():
    sys.path.insert(0, str(ROOT / "tools_src"))
    import build as B

    if OVERRIDES.exists():
        sys.exit("config/flag_overrides.json exists; move it aside first -- "
                 "the audit needs to own that file")

    entries = sorted(set(B.PER_FUNC_FLAGS) | set(B.PER_FUNC_AS_FLAGS))
    entries = [n for n in entries if (ROOT / "src" / f"{n}.c").exists()]
    print(f"auditing {len(entries)} functions with a flag override\n")

    if not build_ok():
        sys.exit("baseline build is not byte-identical; fix that first")

    unneeded = []
    try:
        for n in entries:
            OVERRIDES.write_text(json.dumps({n: {"cc": None, "as": None}}))
            ok = build_ok()
            print(f"  {'UNNEEDED' if ok else 'needed  '}  {n}"
                  f"    {' '.join(B.PER_FUNC_FLAGS.get(n, B.CC1_FLAGS))}"
                  f"{' / as ' + B.PER_FUNC_AS_FLAGS[n] if n in B.PER_FUNC_AS_FLAGS else ''}",
                  flush=True)
            if ok:
                unneeded.append(n)
    finally:
        OVERRIDES.unlink(missing_ok=True)

    print(f"\n{len(unneeded)} of {len(entries)} overrides are unnecessary "
          f"under the current toolchain")
    if unneeded and "--prune" in sys.argv:
        print("\ndelete these entries from build.py:")
        for n in unneeded:
            print(f"  {n}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
