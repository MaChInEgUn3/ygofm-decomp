#!/usr/bin/env python3
"""
Install ported functions measured by port_sweep.py into this tree.

    .venv/bin/python tools_src/port_install.py func_X [func_Y ...]

For each function (its row in build/port/port_specs.json must exist, i.e.
port_sweep.py ran on it): write src/<func>.c from the pruned unit with a
header naming the origin; replace that function's rows in tools_src/build.py
with his compiler profile (cc list, and the assembler -G when it is not the
default); add any of his linker aliases the unit uses to
config/symbol_aliases.txt; delete parked/<func>.c. It does NOT build, mark
PARKED.txt or sync the count -- run build.py next and gate the commit on its
exit status, then `sync_count.py` and a `MATCH` line per park entry.
"""
import json
import pathlib
import re
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
OUT = ROOT / "build" / "port"
KG_COMMIT_FILE = ROOT.parent / "memories-decomp"


def kg_commit():
    r = subprocess.run(["git", "rev-parse", "--short=12", "HEAD"], cwd=KG_COMMIT_FILE,
                       capture_output=True, text=True)
    return r.stdout.strip() or "unknown"


def main():
    funcs = sys.argv[1:]
    specs = json.loads((OUT / "port_specs.json").read_text())
    missing = [f for f in funcs if f not in specs]
    if missing:
        sys.exit(f"no spec for {missing}; run port_sweep.py on them first")
    commit = kg_commit()

    for f in funcs:
        s = specs[f]
        body = (OUT / f"port_pruned_{f}.c").read_text()
        header = (
            "/* Ported from krystalgamer/memories-decomp at commit " + commit + ",\n"
            " * " + s["source"] + (f" ({s['name']})" if s["name"] != f else "") + ", profile " + s["profile"] + ".\n"
            " * The declarations above the function are the subset of that tree's headers\n"
            " * this unit needs, preprocessed and with symbols renamed to this tree's\n"
            " * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical\n"
            " * under the flag row in tools_src/build.py. */\n")
        (ROOT / "src" / f"{f}.c").write_text(header + body)

    bp = ROOT / "tools_src/build.py"
    text = bp.read_text()
    names = set(funcs)
    row = re.compile(r'^\s*"(func_[0-9A-F]{8})":')
    asrow = re.compile(r'^PER_FUNC_AS_FLAGS\["(func_[0-9A-F]{8})"\]')
    ccrow = re.compile(r'^PER_FUNC_FLAGS\["(func_[0-9A-F]{8})"\]')
    kept, dropped = [], 0
    for line in text.splitlines(keepends=True):
        m = row.match(line) or asrow.match(line) or ccrow.match(line)
        if m and m.group(1) in names:
            dropped += 1
            continue
        kept.append(line)
    text = "".join(kept)
    block = [f"# Ported from krystalgamer/memories-decomp ({commit}); rows are his compiler\n"
             f"# profiles in this table's terms, measured through try_func and the build.\n"]
    for f in funcs:
        block.append(f"PER_FUNC_FLAGS[\"{f}\"] = {specs[f]['cc']!r}\n")
        g = specs[f]["as"]
        if g and g != "-G8":
            block.append(f"PER_FUNC_AS_FLAGS[\"{f}\"] = \"{g}\"\n")
    block.append("\n")
    anchor = "# Optional experiment file, so sweeping flags for one function never means\n"
    assert text.count(anchor) == 1, "build.py anchor comment not found exactly once"
    text = text.replace(anchor, "".join(block) + anchor)
    bp.write_text(text)
    print(f"build.py: dropped {dropped} old rows, added {len(block) - 2}")

    al = ROOT / "config/symbol_aliases.txt"
    at = al.read_text()
    added = []
    for f in funcs:
        for name, addr in specs[f].get("aliases", {}).items():
            if not re.search(r"(?m)^" + re.escape(name) + r"\s*=", at):
                at = at.rstrip("\n") + f"\n{name} = {addr};\n"
                added.append(name)
    if added:
        al.write_text(at)
        print("aliases added:", added)

    removed = 0
    for f in funcs:
        p = ROOT / "parked" / f"{f}.c"
        if p.exists():
            p.unlink()
            removed += 1
    print("parked files removed:", removed)

    sys.path.insert(0, str(ROOT / "tools_src"))
    import build as B
    bad = [f for f in funcs if list(B.PER_FUNC_FLAGS.get(f, [])) != list(specs[f]["cc"])
           or (B.PER_FUNC_AS_FLAGS.get(f) or "-G8") != (specs[f]["as"] or "-G8")]
    print("table mismatches:", bad)
    if bad:
        sys.exit(1)


if __name__ == "__main__":
    main()
