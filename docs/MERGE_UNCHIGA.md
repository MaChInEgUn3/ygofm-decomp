# The second decompilation, and what this repo took from it

On 2026-08-30 Unchiga — who also wrote the PSXRecomp-based native port of this
game — shared a zip of his own matching decomp of `SLUS_014.11`. This file is
the record of what was checked, what was taken, and on what terms. Nothing here
was pushed: the GitHub remote is paused by the user's decision until the two of
them agree how the collaboration works.

## The rule everything below obeys

**His build going green is not evidence here. Ours is.** He verifies a
byte-identical rebuild with his own `make check`; that claim is unverifiable on
this machine (his tree needs WSL and `mips-linux-gnu`) and it does not need to
be. `tools_src/build.py` produces one file whose sha1 either is
`84747e64f6da8e764206ec203e489acf8c9dcf7d` or is not, and that is the only
"yes" this repo accepts — for his C exactly as for ours.

The corollary is the merge policy: **what keeps the build green goes in.**
Nothing goes in on anyone's say-so, and nothing goes in because it looks right.

## What the two trees actually are

Same target, different everything else. His toolchain is PsyQ 4.6/4.7 with
ASPSX ≥ 2.56 semantics; ours is 4.5 with aspsx 2.79. He splits per translation
unit with a `c` subsegment per function in splat; we build per-function objects.
He declares globals inline in each `.c`; we centralise them in
`include/variables.h`. In this project a declaration is a codegen input, so the
last difference is not cosmetic — it is why his C cannot simply be copied into
`src/`.

Counting, below our `0x80073840` scope cut: he has **981** units of real C
against our 823, with 764 in common, 217 only his and 59 only ours. That
comparison took two attempts. The first said 1084 and was wrong: **112 of his
`src/*.c` are `INCLUDE_ASM` stubs** that carve an extent for a staged near-miss
and say so in their own header comment — one reads *"It is NOT a match and
claims nothing about the C."* Counting a `c` subsegment as coverage is the
same filter mistake `docs/WORKFLOW.md` documents for the `lui $at` pool.

## `tools_src/transplant.py` — the merge as a measurement

Per function: read his unit from his splat config, rewrite his semantic
identifiers to our `func_%08X` / `D_%08X` form through his `symbol_addrs.txt`,
translate his per-unit flags, compile with our toolchain, diff against the
retail listing. Output is a manifest, not an installation.

Three things it took a wrong turn on first, each worth keeping:

**Compile against HIS prelude, not our headers.** His files declare every
global they touch inline, and some of those are struct-typed —
`extern struct T800E9E18 D_800E9E18[];` where our `variables.h` says
`u8 D_800E9E18[]`. Stripping his so ours wins turns `x[0].field46` into a
compile error; keeping both is `conflicting types`. Neither measures anything.
Replacing his `#include "common.h"` with the six typedefs his own `common.h`
contains makes each file self-contained, which asks the honest question: does
*his* C, as *he* wrote it, produce the retail bytes under *our* compiler?
Reconciling declarations is a separate step for the ones that land.

**Pass his flags.** His `config/unit_flags.txt` carries `-G0` / `-G8` /
`-mno-split-addresses` per unit, the same knobs as our `PER_FUNC_FLAGS`.
Measuring his C under our defaults is not measuring his C — the first probe
scored −6/42 on `func_800137E4` and would have been written down as "does not
port".

**Filter the flags.** That same file mixes in flags for his assembler shim.
`--keep-large-ori` handed to cc1psx is a hard error that reads as failure;
`func_800136E4` is 0/2 once it is dropped.

Calibration — his C for 14 functions **this tree already matches** — came back
12 MATCH, 1 at two differences, 1 error. His C ports.

## The overlay, and why it is now real

`docs/DISC.txt` listed three open steps before overlay work could mean
anything: find the archive, work out the container, extract exact bytes. All
three are closed, and not on his word. His extractor run against **our own**
`YUGIOH.img` produces a 90,112-byte image with sha1
`77b6430db58439e9577533d4f4fa2762996cf6fc`, byte-identical to the copy he
shipped. Two discs, one extractor, the same bytes — that is what turns "his
reference" into "a reference". Installed as `tools_src/extract_overlay.py`;
the details and the two corrections to DISC.txt are in that file's docstring
and at the end of DISC.txt.

Whether overlay C lives in this repo or in a sibling target is a question
about the collaboration, not about the code, and it stays open. It needs its
own oracle either way: the EXE's bytes at 0x80146000 are zero, so attaching
the overlay to the main hash would make correct code go red.

## Names: annotation, never a rename

`config/names_unchiga.txt` carries 1,035 of his semantic names as
`addr → canonical → his name`. Nothing is renamed. Every tool here, every
`PARKED.txt` entry and every paragraph of `WORKFLOW.md` is keyed to the address
form, which is the one thing that cannot be wrong; his names are interpretation
arrived at under a different toolchain. Treat them the way
`docs/EXTERNAL_LEADS.txt` says to treat a wiki guess — a hypothesis to check
against a listing. What they are worth is reading time on a 170-instruction
function, which is the same argument the community RAM map earned its place on.

## Handling

His zip and anything unpacked from it are gitignored (`/ygofm-decomp.zip`,
`/*.zip`, `/third_party/`). This matters concretely: the zip landed in the repo
root, was not ignored, and the autonomous loop runs `git add -A` every block —
one more iteration would have committed 107 MB of his work to a public
repository. It also contains `orig/SLUS_014.11`, the retail binary this project
never commits, and his `.git` with his full history. Neither ever touches a
tracked path.

Ported functions land in commits labelled as ported, with his header comments
preserved, so the work stays attributable and revertible while terms are still
being agreed.

## Open, for the conversation

- Under what licence does his contribution come? `tools_src/` here is MIT;
  `asm/` and `src/` carry no declared licence.
- Does overlay work live here or in a sibling repo?
- The 59 in-scope functions this tree has and his does not are the offer back.
