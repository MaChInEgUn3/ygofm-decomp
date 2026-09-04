# Offering functions to krystalgamer/memories-decomp

On 2026-09-04 krystalgamer said in #general, replying to Unchiga: *"btw don't
wait to get a bulk of data, feel free to throw smaller PRs"*, and answered
"claro" when asked directly whether matched functions from this tree should
come as PRs too. The repo owner here confirmed that as a go-ahead the same
afternoon. It is recorded because the standing rule in this project is that a
relayed permission is not one — the go-ahead has to come from the repo owner,
every time, and this is that record for this round.

## The measurement

His `config/slus_01411/functions.csv` carries a per-function `status` column.
Cross it against `src/func_*.c` here:

| his status | count |
|---|---:|
| `matching_c` | 806 |
| `unmatched_asm` | 327 |
| `sdk_asm` | 598 |
| `handwritten_asm` | 63 |

**166 functions are matched here and `unmatched_asm` there**, totalling
63,688 bytes. The list is `docs/merge/krystalgamer_gap.txt`, smallest first.
A further 72 of this tree's parked candidates sit in his unmatched set too;
those are not matches and are not offerable as code, though their PARKED.txt
diagnoses may still be worth something to him.

## Why the C should port, and why that is not yet proven

His `config/slus_01411/attempts.csv` logs each attempt with its compiler
profile, and the rows read `gcc-2.8.1-psx`, `profile=gcc_2_8_1_g8`. That is
**the same compiler this tree uses**, which removes the objection that
sank the earlier assumption about the other tree — WORKFLOW's toolchain
section is emphatic that a different pipeline can reach the same bytes from a
different SDK, and equally that a shared compiler is not by itself a shared
pipeline. He splits at a different game/SDK boundary (0x80073704 against
0x80073840 here, per LIBRARY_FUNCS.txt) and organises `src/` by real source
names — `ai_fusion.c`, `duel_field_display_objects.c` — not by
`func_XXXXXXXX.c`, so every port also needs a home and a declaration.

**Nothing is offered until it has been built in HIS tree and seen to match
there.** Sending unverified C would be precisely the failure he raised in the
same conversation, that half the community tools "rely on a partial
understanding of the game". His `make match` bootstraps its own toolchain
under `tools/environments`, which is the next piece of work and is not
instant on this box.

## Order of work

1. Bootstrap his build here and reproduce his stated SHA-256
   `84a54ed7…` before touching anything.
2. Calibrate: compile a handful of functions he ALREADY matches, from his
   sources, and confirm byte-identical output. That proves the harness, not
   the port.
3. Take the smallest gap functions first — `func_80030FA0`, `func_8005C5D4`,
   `func_8004A764` — port this tree's C into his file layout, and build.
4. Only what matches there goes in a PR, in small batches, as he asked.
