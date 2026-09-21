#!/usr/bin/env python3
"""variants.py FUNC BASE.c SPEC.json -- SPEC: {"name": [[old,new],...], ...}; each old must occur exactly once."""
import json, subprocess, sys, pathlib, concurrent.futures as cf, re
SP = pathlib.Path(__file__).resolve().parent.parent / "build" / "variants"   # outputs v_<func>_<name>.c/.txt
SP.mkdir(parents=True, exist_ok=True)
f, base, spec = sys.argv[1], pathlib.Path(sys.argv[2]), json.load(open(sys.argv[3]))
flags = sys.argv[4:] or ["-quiet","-O2","-G8","-fno-builtin","-msplit-addresses"]
src = base.read_text()
def run(name):
    t = src
    for old, new in spec[name]:
        assert t.count(old) == 1, (name, old[:60], t.count(old))
        t = t.replace(old, new)
    p = SP / f"v_{f}_{name}.c"; p.write_text(t + f"\n/* variant {name} */\n")
    r = subprocess.run([".venv/bin/python","tools_src/try_func.py", f, str(p), *flags], capture_output=True, text=True, cwd="/home/marchaleski/ygofm")
    out = r.stdout + r.stderr; (SP / f"v_{f}_{name}.txt").write_text(out)
    cnt = [l for l in out.splitlines() if "target instruction" in l]
    d = [l for l in out.splitlines() if "differing instruction" in l]
    m = "MATCH" if any(l.strip()=="MATCH" for l in out.splitlines()) else ""
    return name, (cnt[-1].split("<--")[0].strip() if cnt else out.strip().splitlines()[-1][:80]), (d[-1].strip() if d else ""), m
with cf.ThreadPoolExecutor(4) as ex:
    for row in ex.map(run, list(spec)): print("\t".join(row), flush=True)
