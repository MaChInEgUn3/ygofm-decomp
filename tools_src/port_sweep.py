#!/usr/bin/env python3
"""
Port and measure parked functions from krystalgamer's tree in one sweep.

    .venv/bin/python tools_src/port_sweep.py                # every parked function he has as C
    .venv/bin/python tools_src/port_sweep.py func_X func_Y  # just these

For each function: port_kg.py (preprocess, rename, prune), then try_func on
the pruned unit at his compiler profile, with his assembler -G supplied
through config/flag_overrides.json for the duration of the run. The file is
written before the first measurement and deleted after the last, and the
sweep refuses to start if one already exists -- that file is read by every
try_func and build.py, so a stale one silently changes other measurements
(the WORKFLOW paragraph on background jobs that rewrite shared config).

Prints one row per function: name, target/built counts, MATCH or the last
line of try_func. build/port/port_specs.json keeps the rows' flags so an
install can copy them into build.py. A MATCH here is try_func's verdict, not
the build's: try_func does not link, so run build.py before believing it.
"""
import concurrent.futures as cf
import json
import os
import pathlib
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
KG = pathlib.Path(os.environ.get("YGOFM_KG", ROOT.parent / "memories-decomp"))
OUT = ROOT / "build" / "port"
OVR = ROOT / "config" / "flag_overrides.json"
PY = sys.executable


def candidates():
    mc = {int(f["address"], 16) for f in
          json.load(open(KG / "config/slus_01411/matching_c.json"))["functions"]}
    return [p.stem for p in sorted((ROOT / "parked").glob("func_*.c")) if int(p.stem[5:], 16) in mc]


def measure(f, flags):
    r = subprocess.run([PY, "tools_src/try_func.py", f, str(OUT / f"port_pruned_{f}.c"), *flags],
                       cwd=ROOT, capture_output=True, text=True)
    (OUT / f"port_r_{f}.txt").write_text(r.stdout + r.stderr)
    lines = (r.stdout + r.stderr).splitlines()
    cnt = [l for l in lines if "target instruction" in l]
    verdict = "MATCH" if any(l.strip() == "MATCH" for l in lines) else (lines[-1].strip()[:100] if lines else "no output")
    return f, (cnt[-1].split("<--")[0].strip() if cnt else "no count"), verdict


def main():
    funcs = sys.argv[1:] or candidates()
    if not funcs:
        print("nothing to port: no parked function is matching_c in", KG)
        return
    OUT.mkdir(parents=True, exist_ok=True)
    specs = {}
    for f in funcs:
        try:
            r = subprocess.run([PY, "tools_src/port_kg.py", f, "--json"], cwd=ROOT,
                               capture_output=True, text=True, timeout=180)
        except subprocess.TimeoutExpired:
            print(f"{f}\tPORT-FAIL\tport_kg.py exceeded 180 s", flush=True)
            continue
        if r.returncode:
            print(f"{f}\tPORT-FAIL\t{(r.stderr or r.stdout).strip().splitlines()[-1][:120]}", flush=True)
            continue
        specs[f] = json.loads([l for l in r.stdout.splitlines() if l.startswith("JSON ")][0][5:])
    if OVR.exists():
        sys.exit(f"{OVR} exists; another sweep or an experiment owns it -- not starting")
    spec_file = OUT / "port_specs.json"
    merged = json.loads(spec_file.read_text()) if spec_file.exists() else {}
    merged.update(specs)          # keep earlier rows so port_install can find them
    spec_file.write_text(json.dumps(merged, indent=1))
    OVR.write_text(json.dumps({f: {"cc": s["cc"], "as": s["as"] or None} for f, s in specs.items()}, indent=1))
    try:
        with cf.ThreadPoolExecutor(max_workers=4) as ex:
            for f, cnt, verdict in ex.map(lambda f: measure(f, specs[f]["cc"]), list(specs)):
                print(f"{f}\t{cnt}\t{verdict}", flush=True)
    finally:
        OVR.unlink(missing_ok=True)
        print("flag_overrides.json removed:", not OVR.exists(), flush=True)


if __name__ == "__main__":
    main()
