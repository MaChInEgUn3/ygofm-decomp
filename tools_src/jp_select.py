#!/usr/bin/env python3
"""Select the next Japanese promotion batch against CURRENT master, and write its spec.

    .venv/bin/python tools_src/jp_select.py NAME [--max-fn 30] [--exclude unit,unit]

Writes <his tree>/tmp/jp_batch_gates/spec_NAME.txt for tools_src/jp_batch.py.

WHY THIS EXISTS. Until 2026-09-22 the selection lived only as ad-hoc shell in a
session, and a power cut wiped the scratchpad it ran from. Every rule below cost a
failure to learn; none of it belongs in /tmp.

WHAT IT GUARDS AGAINST:
  * selecting once and building later: ai_script_actions landed upstream between
    selection and build, and the apply refused it. Selection reads origin/master
    at the moment it runs, so run it IMMEDIATELY before jp_batch.py;
  * a truncated harvest: every open PR that touches the Japanese manifest is read,
    each call retried, and ANY failed call aborts the selection -- an error
    redirected to /dev/null once turned a failed call into "claims nothing";
  * a harvest judged by its total: `gh api pulls/N/files` diffs against the PR's
    merge base, so an unrebased branch inflates the count. A drop between runs is
    not a fault; a failed call is;
  * filtering PRs by title: #5719 was titled differently and was invisible;
  * re-deriving known failures by spending a clean build on them: DEFERRED carries
    each unit whose failure class is measured, with the reason beside it.
"""
import argparse, json, os, pathlib, struct, subprocess, sys, time

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
KG = pathlib.Path(os.environ.get("YGOFM_KG", "/home/marchaleski/memories-decomp"))
OUT = KG / "tmp/jp_batch_gates"
REPO = "krystalgamer/memories-decomp"
MANIFEST = "config/slpm_86398/matching_c.json"

# unit -> the measured reason it cannot be promoted yet (classes as in docs/MERGE_KRYSTALGAMER.md)
DEFERRED = {
    "main_mode_runners":          "A: calls overlay imports (MainMenu_*); the JP side has no overlay symbol maps",
    "main_run_password_menu":     "A: calls overlay imports (Password_*)",
    "main_run_selection_menus":   "A: link fails inside Main_RunMenu, overlay imports",
    "main_run_frontend_menus":    "A: link fails inside Main_RunMenu, overlay imports",
    "main_frame":                 "C: source DEFINES D_8009AF0C, which the JP initialized_data blob already carries",
    "duel_trap_resolution":       "C: source DEFINES gDuel_abTrapAttackThresholds, already in the JP blob",
    "display_object_fade_callbacks": "D: func_80039BE0 defined twice in the JP layout",
    "script_image_commands":      "E: alias chain -- gFade_State, then D_8009B0F4_abs and D_8009B134_abs",
    "func_800339D0":              "F: links, then bytes differ at 0x80033820 (profile gcc_2_8_1_g8_split)",
    "sd_arm_busy_callback":       "F: links, then bytes differ; source hardcodes 0x8009B45C",
    "duel_effect_create_channel": "F predicted: source hardcodes 0x8009B34D, in a region measured to shift",
    "func_80018FEC": "measured by batch 19's link: undefined reference to D_8009B23A (nothing on the JP side names it)",
    "func_800388D8": "E: batch 20's link, undefined reference to gFade_State (the script_image_commands alias chain)",
    "func_8004E9A0": "measured by batch 20's link: undefined D_8009B468 and gModel_abImageCopyFrameRows",
}


def sh(cmd, check=True):
    r = subprocess.run(cmd, cwd=KG, shell=isinstance(cmd, str), capture_output=True, text=True)
    if check and r.returncode:
        sys.exit(f"FAILED: {cmd}\n{(r.stdout + r.stderr).strip()[-600:]}")
    return r


def clean_units():
    """Scan against origin/master on a scratch branch, then return to where we were."""
    if sh(["git", "status", "--short"]).stdout.strip(): sys.exit("dirty tree -- clean it first")
    back = sh(["git", "rev-parse", "--abbrev-ref", "HEAD"]).stdout.strip()
    sh(["git", "fetch", "-q", "origin"])
    sh(["git", "checkout", "-q", "-B", "jp/select_scratch", "origin/master"])
    try:
        sh("rm -rf tmp/splat/slpm_86398 && MAKEFLAGS=-j2 make japanese-split")
        import jp_promote as M
        cache = {}
        def words(exe, addr, size):
            b = cache.get(exe)
            if b is None: b = cache[exe] = exe.read_bytes()
            o = addr - M.LOAD + M.HDR
            return list(struct.unpack("<%dI" % (size // 4), b[o:o + size]))
        M.words = words
        us, jp, pairs, names, jpsyms = M.load_all()
        units = {}
        for src in sorted({x["source"] for x in us.values()}):
            a0 = min(a for a in us if us[a]["source"] == src)
            r = M.analyze(us, jp, pairs, names, jpsyms, a0)
            if r.get("ok"):
                units[src.rsplit("/", 1)[-1][:-2]] = (a0, list(r["jps"]))
        return units
    finally:
        sh(["git", "checkout", "-q", back], check=False)
        sh(["git", "branch", "-D", "jp/select_scratch"], check=False)


def harvest():
    """Every address an open PR adds to the Japanese manifest. Any failed call aborts."""
    prs = json.loads(sh(["gh", "pr", "list", "--repo", REPO, "--state", "open", "--limit", "200",
                         "--json", "number"]).stdout)
    claimed, failed = {}, []
    for pr in (p["number"] for p in prs):
        for attempt in range(3):
            r = subprocess.run(["gh", "api", f"repos/{REPO}/pulls/{pr}/files", "--paginate", "--jq",
                                f'.[] | select(.filename == "{MANIFEST}") | .patch'],
                               capture_output=True, text=True)
            if r.returncode == 0: break
            time.sleep(3)
        else:
            failed.append((pr, r.stderr.strip()[:120])); continue
        for line in r.stdout.splitlines():
            if line.startswith("+") and '"address"' in line:
                for tok in line.split('"'):
                    if tok.lower().startswith("0x"):
                        claimed.setdefault(int(tok, 16), []).append(pr)
    if failed:
        sys.exit("harvest had failed calls -- refusing to judge overlap on it:\n" +
                 "\n".join(f"  #{p}: {e}" for p, e in failed))
    return claimed, len(prs)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("name"); ap.add_argument("--max-fn", type=int, default=30)
    ap.add_argument("--exclude", default="", help="units already in flight, comma-separated")
    a = ap.parse_args()
    exclude = {u for u in a.exclude.split(",") if u}
    units = clean_units()
    master = {int(x["address"], 16) for x in json.loads(
        sh(["git", "show", f"origin/master:{MANIFEST}"]).stdout)["functions"]}
    claimed, nprs = harvest()
    free, skipped = [], {"deferred": 0, "in flight": 0, "landed": 0, "claimed": 0}
    for unit, (a0, jps) in units.items():
        if unit in DEFERRED: skipped["deferred"] += 1; continue
        if unit in exclude: skipped["in flight"] += 1; continue
        if any(j in master for j in jps): skipped["landed"] += 1; continue
        if any(j in claimed for j in jps): skipped["claimed"] += 1; continue
        free.append((unit, a0, len(jps)))
    sel, tot = [], 0
    for unit, a0, n in sorted(free, key=lambda u: (-u[2], u[0])):
        if tot + n > a.max_fn: continue
        sel.append((unit, a0, n)); tot += n
    OUT.mkdir(parents=True, exist_ok=True)
    spec = OUT / f"spec_{a.name}.txt"
    spec.write_text("".join(f"{u}|{a0:#x}|\n" for u, a0, _ in sel))
    print(f"clean units: {len(units)}; open PRs harvested: {nprs}, {len(claimed)} claimed addresses, 0 failed calls")
    print("skipped: " + ", ".join(f"{k} {v}" for k, v in skipped.items()))
    print(f"free: {len(free)} units, {sum(u[2] for u in free)} functions")
    print(f"selected: {len(sel)} units, {tot} functions -> {spec}")


if __name__ == "__main__":
    main()
