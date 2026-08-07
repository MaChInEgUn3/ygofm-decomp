# Contributing

**Read `docs/WORKFLOW.md` first.** It is the operational minimum: the ordered
list of what to check when a function does not match, the four global
addressing forms, and every source-shape lever that has actually been measured
against this binary. `docs/DECISIONS.md` is the long-form reasoning, including
the rules that were retracted and why.

## The gate

A change is mergeable only if the build is byte-identical:

```
.venv/bin/python tools_src/build.py && echo GREEN
```

**Check the exit status, not the last lines of output.** Piping through `tail`
reads as green when the build died early, because the last thing printed is
then the function count. Two commits in this project went in red exactly that
way, one of them the commit that noticed the first.

**There is no CI and there cannot be.** Verifying anything requires the PsyQ
SDK and an executable extracted from your own disc, neither of which is
distributable. Verification is on you, and a PR that says "builds clean"
without the sha1 matching is not reviewable.

## Adding a function

Write `src/func_XXXXXXXX.c` and rebuild — placement is automatic. Get targets
from `tools_src/candidates.py` and `tools_src/siblings.py`. Note that the short
instruction bands are exhausted (see the README's status table): everything
remaining under 25 instructions is parked, so unclaimed work starts around 51.

Before parking anything, run `tools_src/sweep_try.py <func>`, and below ~25
instructions run `tools_src/permute.py <func> --run` — that is mandatory rather
than advisory, and it has produced matches that no hand sweep could reach,
because two levers can be coupled such that each one measured alone reads as a
regression.

## The standard the docs are held to

This matters more than style, and it is the one thing a PR will be pushed back
on:

**A claim about mechanism names the counterexample that was checked, or says
explicitly that it was not established.** Write "N shapes measured,
discriminator not established" rather than inventing a reason. Every
"cannot match" filter this project has written has eventually been retracted —
six of six — each reasoned from a couple of samples instead of counted. If a
claim is about the whole binary, scan the whole binary, and reuse the filters
in `candidates.py` rather than re-deriving them.

Two corollaries that have each cost real time here:

- **A tool's answer only counts if it measured what you think.** A filter that
  silently matches nothing looks exactly like a filter with nothing to match.
- **Never rank candidates by difference count alone.** The diff is positional,
  so one missing instruction marks every line after it as differing. A
  candidate one `nop` short can score worse than one with seven genuine
  register disagreements.

## Parked functions

If you take a parked function, delete both `parked/<func>.c` and its
`docs/PARKED.txt` entry when it matches. A stale candidate file shows up as a
false failure in `check_try_func.py`'s parked direction.
