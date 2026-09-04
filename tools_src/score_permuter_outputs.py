"""Score every stored permuter output against its parked candidate.

The permuter writes each improvement it finds to
build/permuter/<func>/output-<score>-<n>/source.c and then exits. Reading
those files is a separate act, and for most of this project's life nobody
performed it: the first run of this script over 72 directories found TEN
functions whose stored output beat the installed candidate, including one
(func_80031EE4) that was a complete MATCH and had been sitting unnoticed.

Two things this cannot do for you. The dirname score is the permuter's own
weighted metric and does not agree with try_func's difference count, so every
output is re-scored here. And a better count is not a better candidate: two of
the first seven finds were semantically WRONG and scored far better than the
correct source -- one deleted a store the target has, another cast an index the
target does not mask. Diff any winner against the base with whitespace
normalised, decompose it, and check the claim against the listing before
installing anything.

Run it after any batch of permuter work, and after picking up an old park.
"""
import subprocess, pathlib, re, json, os
# Repo root, derived from this file's location -- it was hardcoded to one
# machine's home directory, which both leaked a username into a public repo
# and made the tool run against the wrong tree on any other checkout.
# HAZARD: this writes and then DELETES config/flag_overrides.json, which
# try_func.py and build.py both read. Do not run it while you are measuring a
# candidate through an override of your own -- the delete lands mid-run and the
# measurement silently falls back to the default assembler flags. Same class as
# WORKFLOW's rule about background jobs that rewrite build.py.
root=pathlib.Path(__file__).resolve().parent.parent
os.chdir(root)
hits=0; checked=0
for d in sorted(root.glob('build/permuter/func_*')):
    f=d.name
    outs=sorted(d.glob('output-*/source.c'))
    cand=root/f'parked/{f}.c'
    if not outs or not cand.exists(): continue
    txt=cand.read_text()
    ov={f:{"as":"-G0"}} if '"as": "-G0"' in txt else None
    if ov: open('config/flag_overrides.json','w').write(json.dumps(ov))
    def score(p):
        r=subprocess.run(['.venv/bin/python','tools_src/try_func.py',f,str(p)],
                         capture_output=True,text=True)
        # (abs(length error), differences): a count is only comparable at
        # equal length -- func_8004803C's "137 -> 98" was a 158/157 output.
        m=re.search(r'(\d+) target instruction\(s\), (\d+) built', r.stdout)
        le=abs(int(m.group(2))-int(m.group(1))) if m else 999
        m=re.search(r'(\d+) differing', r.stdout)
        n=int(m.group(1)) if m else (0 if 'MATCH' in r.stdout else 999)
        return (le,n)
    base=score(cand); checked+=1
    best=min((score(p),str(p)) for p in outs)
    if os.path.exists('config/flag_overrides.json'): os.remove('config/flag_overrides.json')
    if best[0] < base:
        hits+=1; print(f"MELHOR {f}: len{base[0]}/{base[1]} -> len{best[0][0]}/{best[0][1]}  {best[1]}", flush=True)
print(f"FIM: {checked} funcoes checadas, {hits} com saida melhor", flush=True)
