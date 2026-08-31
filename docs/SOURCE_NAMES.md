# Names recovered from the retail binary itself

The binary carries **no debug symbols** — krystalgamer's first observation about
this game on 2026-08-31, and it is correct. What it does carry is a handful of
strings that the original build left behind, and those name real things: two
source files, one global, one struct field, and three line numbers.

This is a small seam, not a naming scheme. Two translation units out of tens.
It is written down because the evidence is *exact* — an assert's arguments are
the compiler's own `__FILE__` and `__LINE__`, not anybody's guess — and this
project has nowhere else that is true.

    strings -a -t x extracted/SLUS_014.11

## The assert

    0x1fec  Assertion failed: file "%s", line %d

`func_8008E870` is `printf` (both it and `func_8008FBD0`, which follows it and
takes 1, are already in `docs/LIBRARY_FUNCS.txt`). Its `$a1` is the file and
its `$a2` is the line, so every call site names its own translation unit and
position:

| function | source file | line | in scope | decompiled |
|---|---|---|---|---|
| `func_8005C7BC` | `S3000000.C` | 87 (twice) | yes | no, 520 instructions |
| `func_80070D00` | `src/hirata/H_mctrl1.c` | 379 | yes | yes |
| `func_80070DA8` | `src/hirata/H_mctrl1.c` | 403 | yes | yes |

Three things follow, in decreasing order of how sure they are.

**Certain: two functions share a translation unit.** `func_80070D00` and
`func_80070DA8` are both in `src/hirata/H_mctrl1.c`. The project has no other
direct evidence of a TU boundary anywhere — splat has the whole text as one
`31D8` blob and `build.py` emits one object per function precisely because
nothing tells it where files end.

**Strong: source order and address order agree.** The two are 24 source lines
apart (379 → 403) and 0xA8 bytes apart (42 instructions), in the same
direction. That is the assumption the entire linker-driven layout rests on,
and this is the only place it is *checked* rather than assumed.

**Useful for a specific function: `func_8005C7BC` asserts twice at the same
line.** One `assert()` at `S3000000.C:87`, emitted twice, each followed by
`func_8008FBD0(1)`. Nothing in C duplicates a `__LINE__`, so this is the
compiler duplicating a tail — which is the cross-jumping question in
`docs/WORKFLOW.md` step 5, answered in advance for a function nobody has
written yet. Write the assert **once** and expect two copies.

Naming, hypothesis only: `H_` is plausibly the prefix for the files of a
developer whose directory is `hirata`, and `mctrl` plausibly memory-card
control. Neither is evidence and neither is in `variables.h`.

## A named global, from a debug printf

    0x0f84  SD_bgm.dat
    0x0f90  SD_se.dat
    0x0f9c  MASTER.XA
    0x0fa8  g_SDValue->s_stGlobalHdrSE.s_wSD_NUM_SEGROUP:%d
    0x0fdc  Set SMF Mixer Out:%d
    0x0ff4  Set CD Mixer Out:%d

`func_80046A08` (in scope, 273 instructions, not decompiled) passes 0x800107A8
to `printf`. The string is a debug trace someone wrote by hand, so it spells an
expression out of the original source: a global **`g_SDValue`**, a struct member
**`s_stGlobalHdrSE`**, and its field **`s_wSD_NUM_SEGROUP`**. The convention is
legible — `g_` global, `s_` struct member, `s_w` a word-sized one — and it is
the only place in this binary where the original naming style is visible at all.

## What this is not

It is not a route to naming functions. Not one function name appears anywhere
in this binary; the strings above name *files*, one *variable* and one *field*.
Whatever method krystalgamer has in mind is a different one, and this does not
substitute for it.

The `$Id:` strings are a third thing again and belong to Sony, not to this
game:

    $Id: intr.c,v 1.75  1997/02/07  makoto
    $Id: bios.c,v 1.86  1997/03/28  makoto
    $Id: sys.c,v 1.140  1998/01/12  noda

Those date the linked **runtime library** — which is exactly the axis
krystalgamer separated from the compiler on 2026-08-31 (see the Toolchain
section of `docs/WORKFLOW.md`). They say nothing about which `cc1psx` compiled
the game, and it would be the same mistake again to read them that way. A
January 1998 `sys.c` is a lower bound on the library, and only that.
