#!/usr/bin/env python3
"""
Build harness for the Yu-Gi-Oh! Forbidden Memories matching decompilation.

Reproduces the original SLUS_014.11 executable from asm/ + src/ using the
real PsyQ 4.6 toolchain, then verifies the result is byte-identical to the
retail binary via sha1.

Layout is driven by the linker script, not by compiler output order. Every
function is placed individually, in address order:

  * a function that has been decompiled lives in src/<func_name>.c and is
    compiled to its own object;
  * every run of consecutive not-yet-decompiled functions is gathered into
    one generated .s (build/gen/) and assembled as a single object.

This matters because cc1psx, when small-data is enabled (-G, required to
reproduce gp-relative global access), defers ALL C function output to the
end of the translation unit. Mixing INCLUDE_ASM with real C in one file
would therefore scramble .text. Placing each function separately makes
emission order irrelevant. See docs/DECISIONS.md.

Pipeline per C file:
    CPPPSX.EXE -> CC1PSX.EXE -> maspsx -> mipsel-none-elf-as

Run from the repo root:  python tools_src/build.py
"""

import argparse
import bisect
import concurrent.futures as cf
import hashlib
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# --- platform ----------------------------------------------------------------
# The PsyQ SDK is a set of 32-bit Windows executables, so it runs natively on
# Windows and under Wine elsewhere. Everything else differs only in naming:
# Linux gets MIPS binutils from the distro (mips-linux-gnu-*), while on
# Windows we ship a prebuilt mipsel-none-elf toolchain under tools/.
WINDOWS = os.name == "nt"

# --- toolchain locations (all gitignored, see docs/DECISIONS.md) -------------
# PsyQ 4.5 is the game's compiler, not 4.6. Both reproduce almost every
# function, but 4.6 cannot emit retail's combination of scheduled ordering
# with -O1-style register reuse, and 4.5 can. Measured: with the same 220
# sources, 4.5 is byte-identical and 4.6 leaves func_800495A4 wrong, with
# no function matching under 4.6 that fails under 4.5. Set YGOFM_PSYQ=46 to
# compare. See the toolchain-version section of docs/DECISIONS.md.
if os.environ.get("YGOFM_PSYQ") == "46":
    PSYQ_BIN = ROOT / "tools" / "psyq46" / "Psy-Q - 46" / "BIN"
else:
    PSYQ_BIN = ROOT / "tools" / "psyq45" / "BIN"
CPPPSX = PSYQ_BIN / "CPPPSX.EXE"
CC1PSX = PSYQ_BIN / "CC1PSX.EXE"
# Prefix used to invoke the PsyQ executables. Empty on Windows.
PSYQ_RUNNER = [] if WINDOWS else ["wine"]

if WINDOWS:
    MIPS_BIN = ROOT / "tools" / "mips" / "bin"
    AS = MIPS_BIN / "mipsel-none-elf-as.exe"
    LD = MIPS_BIN / "mipsel-none-elf-ld.exe"
    OBJCOPY = MIPS_BIN / "mipsel-none-elf-objcopy.exe"
    OBJDUMP = MIPS_BIN / "mipsel-none-elf-objdump.exe"
    VENV_PYTHON = ROOT / ".venv" / "Scripts" / "python.exe"
else:
    MIPS_BIN = Path("/usr/bin")
    AS = MIPS_BIN / "mips-linux-gnu-as"
    LD = MIPS_BIN / "mips-linux-gnu-ld"
    OBJCOPY = MIPS_BIN / "mips-linux-gnu-objcopy"
    OBJDUMP = MIPS_BIN / "mips-linux-gnu-objdump"
    VENV_PYTHON = ROOT / ".venv" / "bin" / "python"

MASPSX = ROOT / "tools" / "maspsx" / "maspsx.py"

# --- project layout ----------------------------------------------------------
SRC = ROOT / "src"
ASM_FUNCS = ROOT / "asm" / "nonmatchings" / "31D8"
BUILD = ROOT / "build"
GEN = BUILD / "gen"
SPLAT_LD = ROOT / "config" / "slus_014.11.ld"
GEN_LD = GEN / "slus_014.11.ld"
BOUNDARIES = ROOT / "docs" / "FILE_BOUNDARIES.txt"
ELF = BUILD / "slus_014.11.elf"
TARGET_BIN = BUILD / "slus_014.11.bin"
EXPECTED_SHA1 = "84747e64f6da8e764206ec203e489acf8c9dcf7d"

# The object splat's linker script expects the whole code segment to come
# from; we substitute our per-function objects for it.
SPLAT_CODE_OBJ = "build/src/31D8.o"

# ASPSX version bundled with PsyQ 4.6; maspsx emulates its quirks.
ASPSX_VERSION = "2.79"  # PsyQ 4.5 ships aspsx 2.79 (4.6 shipped 2.86).
# Set from the SDK we now know the game used, not from a measurement: the
# corpus does not currently discriminate -- 2.79 and 2.86 both produce a
# byte-identical build, because the only behaviour maspsx varies between them
# is gp_allow_la, which no decompiled function exercises yet -- re-measured at
# 777 functions on 2026-08-10 by building the whole corpus at 2.86, still
# byte-identical, so the "yet" is holding much longer than expected. Provenance is
# the tiebreaker, and the distinction is recorded so nobody reads the passing
# build as evidence for the number.

# -G8 enables small-data/gp-relative access, which the retail code uses for
# most globals. The assembler's -G must match, or it cannot assume a bare
# symbol is small data and expands each reference into a lui/%lo pair.
# The -O level is NOT confirmed for this game and may vary per function;
# see docs/DECISIONS.md.
CC1_FLAGS = ["-quiet", "-O2", "-G8"]

CPP_FLAGS = [
    "-undef", "-D__GNUC__=2", "-lang-c",
    "-Dmips", "-D__mips__", "-D__mips",
    "-Dpsx", "-D__psx__", "-D__psx",
    "-D_PSYQ", "-D__EXTENSIONS__", "-D_MIPSEL",
    "-D__CHAR_UNSIGNED__", "-D_LANGUAGE_C", "-DLANGUAGE_C",
    "-Iinclude",
]

# -no-pad-sections and -O0 are required for byte-exact section contents.
AS_FLAGS = [
    "-EL", "-march=r3000", "-mtune=r3000",
    "-no-pad-sections", "-O0", "-G8",
    "-I.", "-Iinclude",
]

# Per-function compiler flags. The retail game was built from ~234 separate
# translation units and clearly did not use one flag set throughout, so
# expect this table to keep growing; it is normal, not a smell.
#
# Two recurring cases so far:
#   -O1        some units were built at -O1; it changes register allocation.
#   -G0        a unit whose globals are reached with explicit %hi/%lo pairs
#              rather than gp-relative. Such a function usually needs
#              PER_FUNC_AS_FLAGS too, so the assembler agrees.
_O1_G8 = ["-quiet", "-O1", "-G8"]
# I deleted the -fno-schedule-insns2 lists after the 4.5 switch, on the
# grounds that nothing needed them any more. That was true of the corpus at
# that moment and not true in general -- func_800855B0 needs one. Restored,
# with the correct claim: the flag was *usually* compensating for 4.6, and
# most entries went away, but it is still occasionally what retail wants.
_O2_G0_NOSCHED2_MACRO = ["-quiet", "-O2", "-G0", "-fno-schedule-insns2",
                         "-mno-split-addresses"]
# First user is func_80014A5C. gcc's sched1 hoists a load of one global above
# a store to another to fill the load-delay slot; retail leaves the nop, so
# that pass did not run on this unit. Neither `volatile` spelling stops the
# hoist -- gcc 2.8 moves a non-volatile *and* a volatile load across a
# volatile store -- so this is a flag, not a source shape.
_O2_G8_NOSCHED1 = ["-quiet", "-O2", "-G8", "-fno-schedule-insns"]
# First user is func_80060E70 (parked): retail keeps a cursor at the loop's
# base with `+0xA` in every offset, and strength reduction biases it to
# base+10 with zero offsets instead.
_O2_G8_NOSTRENGTH = ["-quiet", "-O2", "-G8", "-fno-strength-reduce"]
_O2_G8_NOSCHED2 = ["-quiet", "-O2", "-G8", "-fno-schedule-insns2"]
_O2_G0_NOSCHED1 = ["-quiet", "-O2", "-G0", "-fno-schedule-insns"]
_O1_G0 = ["-quiet", "-O1", "-G0"]
_O2_G0 = ["-quiet", "-O2", "-G0"]
# Macro-form addressing does *not* imply -G0. At -G8 with -mno-split-addresses
# cc1psx emits the bare symbol for every global and the assembler picks the
# form per symbol: gp-relative for small data, lui $at + %lo for aggregates.
# That is the only way to get both in one function.
_O2_G8_MACRO = ["-quiet", "-O2", "-G8", "-mno-split-addresses"]
# Hypothesis under test: some units were built without gcc filling delay
# slots, leaving that to aspsx.
_O2_G0_NODELAY = ["-quiet", "-O2", "-G0", "-fno-delayed-branch"]
_O1_G0_NODELAY = ["-quiet", "-O1", "-G0", "-fno-delayed-branch"]

_O2_G0_NODELAY_MACRO = ["-quiet", "-O2", "-G0", "-fno-delayed-branch",
                        "-mno-split-addresses"]
# -mno-split-addresses leaves the address in macro form for the assembler to
# expand via $at, which is what the retail code shows for these.
_O1_G0_MACRO = ["-quiet", "-O1", "-G0", "-mno-split-addresses"]

_G0_FUNCS = [
    "func_8003B734", "func_80058F10", "func_8004544C", "func_80049594",
    "func_800495DC", "func_8007BAC0", "func_8007BF04",
    "func_8007BF14", "func_8007BF30", "func_8007BF40", "func_8007BF50",
    "func_8007BF60", "func_8007CD14", "func_8007F5C4", "func_80085320",
    "func_80044FE4", "func_8004503C", "func_800490F0", "func_80049108",
    "func_80049120", "func_800744F4", "func_80080B6C",
    "func_800901D4", "func_80030090", "func_800300AC",
    "func_80082274", ]
# Stores the assembler expands through $at. These need the macro form from
# the compiler *and* an assembler that will not treat the symbol as small
# data, so they carry a PER_FUNC_AS_FLAGS entry too.
_G0_MACRO_FUNCS = [
    "func_80038898",
    "func_80082A80", "func_8008D1E0", "func_8008D1F4", "func_8008D208",
    "func_8008D21C", "func_8008D230", "func_8008D244", "func_8008D258",
    "func_8008D26C", "func_8002F930", "func_8002F94C", "func_8002FA28", 
    ]

PER_FUNC_FLAGS = {
    "func_800493F8": _O2_G0,
    "func_80014A5C": _O2_G8_NOSCHED1,
    "func_8005A53C": _O2_G0_NOSCHED1,
    "func_8002EC74": _O2_G8_MACRO,
    "func_80037A58": _O2_G8_MACRO,
    "func_80012B50": _O2_G8_NOSCHED1,
    # Parked; kept so PARKED.txt's difference count is reproducible.
    "func_80060E70": _O2_G8_NOSTRENGTH,
    "func_80031000": _O2_G8_MACRO,
    "func_80044DC0": _O2_G8_MACRO,
    "func_80041D60": _O2_G8_MACRO,
    "func_800386B8": _O2_G8_MACRO,
    "func_800375A4": _O2_G8_MACRO,
    "func_8002DF2C": _O2_G8_MACRO,
    "func_8003D518": _O2_G8_MACRO,
    "func_8001755C": _O2_G0_NOSCHED2_MACRO,
    "func_80024DC8": _O2_G8_MACRO,
    "func_8002CD8C": _O2_G8_MACRO,
    "func_8002D0E0": _O2_G8_MACRO,
    "func_80030C10": _O2_G8_MACRO,
    "func_8004B70C": _O2_G8_MACRO,
    "func_8004B6E8": _O2_G8_MACRO,
    "func_8004B990": _O2_G8_MACRO,
    "func_800494F4": _O2_G8_MACRO,
    "func_80047F38": _O2_G8_MACRO,
    "func_80047BB4": _O2_G8_MACRO,
    "func_80012DB4": _O2_G8_MACRO,
    "func_80047EC4": _O2_G8_MACRO,
    "func_8004B910": _O2_G8_MACRO,
    "func_800359B0": _O2_G8_MACRO,
    "func_8004B9E0": _O2_G8_MACRO,
    "func_80049138": _O2_G8_MACRO,
    "func_80033C90": _O2_G8_MACRO,
    "func_80033CA8": _O2_G8_MACRO,
    "func_8002EB48": _O2_G8_MACRO,
    "func_8003D0F4": _O2_G8_MACRO,
    "func_8003767C": _O2_G8_MACRO,
    "func_8002D370": _O2_G8_MACRO,
    "func_8002622C": _O2_G8_MACRO,
    "func_8003798C": _O2_G8_MACRO,
    "func_800438B8": _O2_G8_MACRO,
    "func_80030CB0": _O2_G8_MACRO,
    "func_80039BE0": _O2_G8_MACRO,
    "func_8003771C": _O2_G8_MACRO,
    "func_80029108": _O2_G8_MACRO,
    "func_80030E30": _O2_G8_MACRO,
    "func_80037CE0": _O1_G8,
    "func_80030E7C": _O2_G8_MACRO,
    "func_80044D48": _O2_G0,
    "func_800495A4": _O2_G0,
    "func_80049EC8": _O2_G0,
    "func_80049F10": _O2_G0,
    "func_80049200": _O2_G0,
    "func_80070988": _O1_G8,
    "func_80049600": _O2_G0_NOSCHED2_MACRO,
    "func_800855B0": _O2_G0_NOSCHED2_MACRO,
    "func_8003CDF8": _O1_G8,
    "func_8003CE48": _O1_G8,
    "func_800498F8": _O2_G0_NODELAY_MACRO,
    "func_80030EC8": _O2_G8_MACRO,
    "func_8004763C": _O2_G8_MACRO,
    "func_8002CE64": _O2_G8_MACRO,
    "func_8001798C": _O2_G8_MACRO,
    "func_80049394": _O2_G8_MACRO,
    "func_8002D2D8": _O2_G8_MACRO,
    "func_80017708": ["-quiet", "-O2", "-G8", "-fno-strength-reduce"],
    # func_800722CC: the two reads at +6 inside the search loop get their own
    # biased giv, which costs a callee-saved register and five instructions.
    "func_800722CC": ["-quiet", "-O2", "-G8", "-fno-strength-reduce"],
    # PARKED at +9. Without it gcc gives the record cursor a second, biased
    # register ($s0 = $s3 + 4, reading 2($s0) where retail reads 6($s3)),
    # which is +13 and four differences worse.
    "func_80071700": ["-quiet", "-O2", "-G8", "-fno-strength-reduce"],
    # PARKED at 131/131. Without it gcc gives the record cursor a biased giv
    # for the +0x5150 store and the function is +5.
    "func_80013154": ["-quiet", "-O2", "-G8", "-fno-strength-reduce"],
    # PARKED at 60 differences.  Without this the last nested loop is reversed
    # (countdown + bgez) where retail counts up against slti 32, and the outer
    # `sll i,6` becomes a giv -- one instruction short and much further out.
    "func_80047480": ["-quiet", "-O2", "-G8", "-fno-strength-reduce"],
    # func_80058938: the found-record arm's two Word4 block copies force their
    # destination addresses into registers, and strength reduction turns the
    # r+0x14 one into a giv that every neighbouring store is then rebased on
    # (sh -8/-6/-10 off an r+20 anchor). Retail addresses everything as plain
    # displacements off the cursor; only the flag removes the anchor.
    "func_80058938": _O2_G8_NOSTRENGTH,
    # func_8002C6C8: same anchor phenomenon without a block move -- the
    # record walk's field references get rebased on a base+0x14 giv that
    # retail does not have, and the anchor also eats the callee-saved
    # register the D_800F2848 address hoist wants. Third user of the flag.
    "func_8002C6C8": _O2_G8_NOSTRENGTH,
    # The record walk builds a second giv biased at +2 because most of the
    # reads are there, which costs a callee-saved register and four frame
    # instructions; retail has one cursor with displacements 0, 2, 6 and 9.
    "func_80071B64": _O2_G8_NOSTRENGTH,
    "func_8004C8C8": _O2_G8_NOSTRENGTH,
    "func_8007308C": _O2_G8_NOSTRENGTH,
    "func_80039794": _O2_G8_NOSTRENGTH,
    # Parked: this row is the permuter's base, not a match. At default flags
    # the store order is right and the two sll/ori pairs float (8); under
    # -fno-schedule-insns2 the pairs are right and three stores float (9),
    # and store position is the half a source mutation can actually reach.
    "func_80022D94": _O2_G8_NOSCHED2,
}
PER_FUNC_FLAGS.update({n: _O1_G0 for n in _G0_FUNCS})
PER_FUNC_FLAGS.update({n: _O1_G0_MACRO for n in _G0_MACRO_FUNCS})

# Per-function assembler flags. Needed when the compiler emits a bare symbol
# reference and the assembler's -G decides whether to make it gp-relative or
# expand it into a lui/%lo pair through $at.
# Functions where the assembler must split an expanded address macro across
# a branch delay slot -- see fill_delay_slot_with_macro_tail().
# Functions needing load-delay nops restored for extern small-data symbols
# -- see insert_small_data_load_delay_nops().
# Functions in the library region whose target has the aspsx-hoisted
# epilogue; see hoist_epilogue_out_of_delay_slot().
HOIST_EPILOGUE_FUNCS = {
    "func_8007E258", "func_8007E350", "func_8007E370", "func_800857C0",
    "func_8008B7E0", "func_8008D48C",
}

SMALL_DATA_NOP_FUNCS = {
    # `lbu` of a struct field followed by a gp-relative `sb` of it: maspsx
    # expects the store to expand through $at and fill the slot.
    "func_80015310",
    "func_8002CEE8",
    "func_8002D7CC",
    "func_8002E5AC",
    "func_8002DC38",
    "func_8002D180",
    "func_8002D62C",
    "func_8003CDF8",
    "func_8003CE48",
    "func_80025028",
    "func_8002D6C8",
    "func_8002D370",
    "func_8002D730",
    "func_80012DB4",
}

# Functions where an address computation, not a memory op, is split across a
# call's delay slot. See split_address_across_call.
LA_CALL_FUNCS = {
    "func_8002CE64",
}
DELAY_SLOT_MACRO_FUNCS = {
    "func_8007A628", "func_8007BEBC", "func_8007BEC8", "func_8007BED4",
    "func_8007BEE0", "func_8007CD04", "func_800862C0",
}
# Audit hook. YGOFM_DROP_POSTPASS=func_A,func_B removes those names from the
# post-pass sets before anything derives from them, so a post-pass entry can be
# tested the way a flag override can. Needed because these sets also feed
# PER_FUNC_FLAGS below: a function in DELAY_SLOT_MACRO_FUNCS takes its compiler
# flags from that membership, so "are the flags needed" and "is the post-pass
# needed" are different questions and only the first is reachable through
# config/flag_overrides.json.
_DROP = {n for n in os.environ.get("YGOFM_DROP_POSTPASS", "").split(",") if n}
if _DROP:
    DELAY_SLOT_MACRO_FUNCS -= _DROP
    SMALL_DATA_NOP_FUNCS -= _DROP
    HOIST_EPILOGUE_FUNCS -= _DROP
    # Every post-pass set must be listed here. LA_CALL_FUNCS was added and
    # this line was not, so dropping its only member changed nothing and the
    # audit reported the post-pass unnecessary -- the same false-UNNEEDED the
    # stamp bug produced eight of. A new set means a new line here.
    LA_CALL_FUNCS -= _DROP

# DELAY_SLOT_MACRO_FUNCS used to imply -O1 -G0 -mno-split-addresses flags and a
# -G0 assembler as well as the post-pass. The flag audit showed all seven match
# with default flags under PsyQ 4.5 while still needing the post-pass, so the
# set now means only what its name says: this function needs the delay-slot
# macro rewrite. The old coupling was compensating for the wrong compiler.
# The assembler's -G must match the compiler's, in both directions. When
# cc1psx is at -G0 it sometimes emits a bare symbol reference (`lw $3,sym`)
# and leaves the expansion to the assembler; an assembler still at -G8 then
# decides the symbol is small data and collapses the lui/%lo pair into one
# gp-relative instruction, leaving the function an instruction short. So
# every -G0 function gets a -G0 assembler, not just the macro-form ones.
PER_FUNC_AS_FLAGS = {n: "-G0" for n in _G0_FUNCS + _G0_MACRO_FUNCS}
# A -G8 compiler with a -G0 assembler. cc1psx at -G8 emits the bare symbol
# form `lw $3,D_8009B458` and leaves the expansion to the assembler; a -G0
# assembler expands it to lui/lw where a -G8 one would collapse it to a single
# gp-relative load. The comment above says the two -G settings must match, and
# that is the usual case -- these are the exceptions, where the mismatch is
# exactly what reproduces retail.
PER_FUNC_AS_FLAGS["func_8003AC48"] = "-G0"
PER_FUNC_AS_FLAGS["func_80061008"] = "-G0"
PER_FUNC_AS_FLAGS["func_8005A53C"] = "-G0"
PER_FUNC_AS_FLAGS["func_800610E0"] = "-G0"
PER_FUNC_AS_FLAGS["func_80024734"] = "-G0"
PER_FUNC_AS_FLAGS["func_80048D08"] = "-G0"
PER_FUNC_AS_FLAGS["func_80047480"] = "-G0"
PER_FUNC_AS_FLAGS["func_8004A518"] = "-G0"
PER_FUNC_AS_FLAGS["func_8003BF00"] = "-G0"
PER_FUNC_AS_FLAGS["func_80043328"] = "-G0"
PER_FUNC_AS_FLAGS["func_8002DDFC"] = "-G0"
PER_FUNC_AS_FLAGS["func_80046768"] = "-G4"
PER_FUNC_AS_FLAGS["func_800339D0"] = "-G4"
PER_FUNC_AS_FLAGS["func_80043960"] = "-G1"
PER_FUNC_AS_FLAGS["func_80013154"] = "-G1"
PER_FUNC_AS_FLAGS["func_80040DD8"] = "-G0"
# Same body as func_80040DD8 with a 12-byte stride; retail reaches
# D_8009B146/D_8009B148 and D_800EFE42 with bare %hi/%lo pairs, and the
# function has no %gp_rel at all, so any -G is free.
PER_FUNC_AS_FLAGS["func_80041068"] = "-G0"
PER_FUNC_AS_FLAGS["func_80040588"] = "-G4"
PER_FUNC_AS_FLAGS["func_800408D0"] = "-G4"
PER_FUNC_AS_FLAGS["func_8002CEE8"] = "-G1"
PER_FUNC_AS_FLAGS["func_8004BE88"] = "-G0"
PER_FUNC_AS_FLAGS["func_8002DA1C"] = "-G1"
PER_FUNC_AS_FLAGS["func_8002D7CC"] = "-G1"
PER_FUNC_AS_FLAGS["func_80048A28"] = "-G0"
PER_FUNC_AS_FLAGS["func_8003BA14"] = "-G0"
PER_FUNC_AS_FLAGS["func_8005B64C"] = "-G0"
PER_FUNC_AS_FLAGS["func_80012E5C"] = "-G4"
PER_FUNC_AS_FLAGS["func_8003B808"] = "-G0"
PER_FUNC_AS_FLAGS["func_800136E4"] = "-G2"
PER_FUNC_AS_FLAGS["func_8002D458"] = "-G2"
PER_FUNC_AS_FLAGS["func_80030FA0"] = "-G2"
PER_FUNC_AS_FLAGS["func_8004ACE4"] = "-G0"
PER_FUNC_AS_FLAGS["func_80048920"] = "-G0"
# Parked; kept so PARKED.txt's difference count is reproducible.
PER_FUNC_AS_FLAGS["func_80047DB0"] = "-G0"
PER_FUNC_AS_FLAGS["func_8001944C"] = "-G0"
PER_FUNC_AS_FLAGS["func_8003CCD8"] = "-G4"
PER_FUNC_AS_FLAGS["func_80048658"] = "-G0"
PER_FUNC_AS_FLAGS["func_80030F40"] = "-G0"
PER_FUNC_AS_FLAGS["func_8002A2F4"] = "-G0"
# Parked, so no src/ file reads this; kept so PARKED.txt's difference count
# is reproducible from the repo.
PER_FUNC_AS_FLAGS["func_80031CD4"] = "-G0"
PER_FUNC_AS_FLAGS["func_800245EC"] = "-G0"
PER_FUNC_AS_FLAGS["func_80038530"] = "-G0"
PER_FUNC_AS_FLAGS["func_8003C7A0"] = "-G1"
PER_FUNC_AS_FLAGS["func_8002D180"] = "-G1"
PER_FUNC_AS_FLAGS["func_80020BE4"] = "-G0"
PER_FUNC_AS_FLAGS["func_8002E470"] = "-G4"
PER_FUNC_AS_FLAGS["func_8002EA0C"] = "-G4"
PER_FUNC_AS_FLAGS["func_800175A0"] = "-G4"
PER_FUNC_AS_FLAGS["func_8004BBBC"] = "-G0"
PER_FUNC_AS_FLAGS["func_8003D46C"] = "-G0"
PER_FUNC_AS_FLAGS["func_8004C77C"] = "-G0"
# Parked; kept so PARKED.txt's difference counts reproduce.
PER_FUNC_AS_FLAGS["func_8004A764"] = "-G0"
PER_FUNC_AS_FLAGS["func_8004A6F8"] = "-G0"
PER_FUNC_AS_FLAGS["func_800497E0"] = "-G0"
PER_FUNC_AS_FLAGS["func_80047788"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049CF8"] = "-G0"
PER_FUNC_AS_FLAGS["func_8004A43C"] = "-G0"
PER_FUNC_AS_FLAGS["func_80039AFC"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049010"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049DD8"] = "-G0"
PER_FUNC_AS_FLAGS["func_80047CC4"] = "-G0"
PER_FUNC_AS_FLAGS["func_8005B260"] = "-G0"
PER_FUNC_AS_FLAGS["func_8005B36C"] = "-G0"
PER_FUNC_AS_FLAGS["func_8004B734"] = "-G0"
PER_FUNC_AS_FLAGS["func_80048F14"] = "-G0"
PER_FUNC_AS_FLAGS["func_8003700C"] = "-G1"
PER_FUNC_AS_FLAGS["func_80013360"] = "-G4"
PER_FUNC_AS_FLAGS["func_8002F4C0"] = "-G0"
PER_FUNC_AS_FLAGS["func_800464F0"] = "-G0"
PER_FUNC_AS_FLAGS["func_8003B9BC"] = "-G0"
PER_FUNC_AS_FLAGS["func_8001BD48"] = "-G1"
PER_FUNC_AS_FLAGS["func_8004BAE4"] = "-G0"
# Parked; kept so PARKED.txt's difference counts reproduce.
PER_FUNC_AS_FLAGS["func_8004CABC"] = "-G0"
PER_FUNC_AS_FLAGS["func_800240B0"] = "-G2"
PER_FUNC_AS_FLAGS["func_80024200"] = "-G2"
# func_80025D30: D_8009B260 declared [8] must be non-small while D_8009B20C,
# declared [2] in that unit, stays gp-relative -- the window is 4 <= G < 8.
PER_FUNC_AS_FLAGS["func_80025D30"] = "-G4"
# D_8009B260 bare while the four-byte D_8009B17C beside it keeps %gp_rel:
# the window is 4 <= G < 8, and the declaration is inflated to eight to open
# it (func_80025BEC).
PER_FUNC_AS_FLAGS["func_80025BEC"] = "-G4"
# Same window as func_80025BEC: D_8009B408 declared eight and bare, the
# gp-relative neighbours are one and four bytes, so 4 <= G < 8.
PER_FUNC_AS_FLAGS["func_8003C628"] = "-G4"
PER_FUNC_AS_FLAGS["func_80012B50"] = "-G4"
PER_FUNC_AS_FLAGS["func_80060E70"] = "-G0"
# Parked; kept so PARKED.txt's difference count is reproducible.
PER_FUNC_AS_FLAGS["func_8002FB78"] = "-G0"
PER_FUNC_AS_FLAGS["func_80043BCC"] = "-G1"
# Parked; kept so PARKED.txt's difference count is reproducible.
PER_FUNC_AS_FLAGS["func_8003A01C"] = "-G0"
# Parked; kept so PARKED.txt's difference count is reproducible.
PER_FUNC_AS_FLAGS["func_800434F4"] = "-G0"
PER_FUNC_AS_FLAGS["func_800289BC"] = "-G0"
# Parked; kept so PARKED.txt's difference count is reproducible.
PER_FUNC_AS_FLAGS["func_8005B4D8"] = "-G0"
PER_FUNC_AS_FLAGS["func_8002DC38"] = "-G1"
PER_FUNC_AS_FLAGS["func_8003F7D4"] = "-G0"
PER_FUNC_AS_FLAGS["func_8003594C"] = "-G2"
PER_FUNC_AS_FLAGS["func_800498F8"] = "-G0"
PER_FUNC_AS_FLAGS["func_8004545C"] = "-G0"
PER_FUNC_AS_FLAGS["func_8002A660"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049F50"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049C40"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049308"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049BAC"] = "-G0"
PER_FUNC_AS_FLAGS["func_8004A2F8"] = "-G0"
PER_FUNC_AS_FLAGS["func_80047AD0"] = "-G0"
PER_FUNC_AS_FLAGS["func_800388D8"] = "-G0"
PER_FUNC_AS_FLAGS["func_80023FBC"] = "-G0"
PER_FUNC_AS_FLAGS["func_8001755C"] = "-G0"
PER_FUNC_AS_FLAGS["func_80044DA0"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049CB0"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049EC8"] = "-G0"
PER_FUNC_AS_FLAGS["func_80044D48"] = "-G0"
PER_FUNC_AS_FLAGS["func_80029164"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049230"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049A64"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049544"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049640"] = "-G0"
# These three are parked, not in src/, so these entries are inert for the
# build. They are here anyway because check_try_func.py's negative phase runs
# try_func over parked/ and try_func reads these tables: without them the three
# differ under default flags for the *addressing form*, not for the residual
# difference they were parked on, and a future try_func bug that hid the real
# difference would still pass the check.
PER_FUNC_AS_FLAGS["func_8004C84C"] = "-G0"
# gp == 0 in func_8004C8C8, so any -G is free; it reaches D_8009B458 through
# %hi/%lo four times and the scalar declaration plus a -G0 assembler is the
# form that gives it (recipe branch 1).
PER_FUNC_AS_FLAGS["func_8004C8C8"] = "-G0"
# gp == 0 in func_8004C5C8; scalar D_8009B458 plus a -G0 assembler gives the
# %hi/%lo pair the listing has (recipe branch 1).
PER_FUNC_AS_FLAGS["func_8004C5C8"] = "-G0"
# gp == 0 in func_8004BCE8; scalar D_8009B458 plus a -G0 assembler.
PER_FUNC_AS_FLAGS["func_8004BCE8"] = "-G0"
# func_8003C328: gp == 0, so any -G is free (recipe branch 1). -G0 rather than
# -G4 because D_8009B118 must be non-small here too -- all three of its
# references in retail are %hi/%lo pairs, and at -G4 (four bytes) it stays
# small and each one comes out an instruction short. Its sibling func_8003C120
# wants -G4: there the same guard costs +3. Decide per unit, not by precedent.
PER_FUNC_AS_FLAGS["func_8003C328"] = "-G0"
# func_8003C120 is func_8003C328's sibling and wants the same threshold.
PER_FUNC_AS_FLAGS["func_8003C120"] = "-G4"
# func_8005C1F4: D_800F5D44 declared [8] must be non-small while the 4-byte
# D_8009B498 stays gp-relative -- the window is 4 <= G < 8.
PER_FUNC_AS_FLAGS["func_8005C1F4"] = "-G4"
# func_80032184: gp == 0, so -G0 is free and both D_8009B0F4 and D_8009B118
# get the %hi/%lo pairs retail has (recipe branch 1).
PER_FUNC_AS_FLAGS["func_80032184"] = "-G0"
# func_8003BD14: same dispatcher shape as func_80032184 -- gp == 0, so -G0,
# and the volatile arm for the back-to-back read-modify-writes in mode 0.
PER_FUNC_AS_FLAGS["func_8003BD14"] = "-G0"
# gp == 0 in func_80048768; scalar D_8009B45C plus a -G0 assembler.
PER_FUNC_AS_FLAGS["func_80048768"] = "-G0"
# gp == 0 in func_8003353C; every global there is %hi/%lo, so -G0 is free.
PER_FUNC_AS_FLAGS["func_8003353C"] = "-G0"
# func_8002596C: same pair as func_80025D30 -- D_8009B260 declared [8] must be
# non-small while D_8009B20C, declared [2] here, stays gp-relative.
PER_FUNC_AS_FLAGS["func_8002596C"] = "-G4"
# func_800371A8: every gp-relative symbol here is one byte, so the window
# 1 <= G < 2 exists -- D_8009B398 (u16 scalar) goes bare and stays one
# instruction to the delay-slot filler, which is retail's nop.
PER_FUNC_AS_FLAGS["func_800371A8"] = "-G1"
# func_8002FD10: D_8009B146/D_8009B148 declared [4] (eight bytes) go non-small
# at -G4 and expand through $at, while the four-byte D_8009B2A0 and the
# two-byte D_8009B2A4 keep %gp_rel. Same pair of knobs as func_8002E470.
PER_FUNC_AS_FLAGS["func_8002FD10"] = "-G4"
# func_800257A0: D_8009B112 inflated to eight bytes goes non-small at -G4
# while the one- and two-byte gp scalars beside it stay %gp_rel.
PER_FUNC_AS_FLAGS["func_800257A0"] = "-G4"
# func_80024E58: D_8009B364 inflated to eight bytes for the $at store, while
# the four-byte D_8009B17C/D_8009B1C8/D_8009B214 stay %gp_rel.
PER_FUNC_AS_FLAGS["func_80024E58"] = "-G4"
# func_80015310: every gp-relative symbol in it is one byte, so the four-byte
# D_8009B0D8 goes bare at -G2 -- one instruction to the delay-slot filler,
# which is retail's nop in front of the pair.
PER_FUNC_AS_FLAGS["func_80015310"] = "-G2"
# func_8003DA40: the only gp-relative symbol is a one-byte flag, so the u16
# D_8009AF76 goes bare at -G1 and the pair stays in one register.
PER_FUNC_AS_FLAGS["func_8003DA40"] = "-G1"
# func_8002E730: five symbols want the non-small form and the gp-relative ones
# top out at four bytes, so every bare-wanting symbol is sized into (4, 8].
PER_FUNC_AS_FLAGS["func_8002E730"] = "-G4"
# func_800307B8: D_8009B398 inflated to eight bytes goes non-small at -G4
# while the one- and two-byte gp scalars around it stay %gp_rel.
PER_FUNC_AS_FLAGS["func_800307B8"] = "-G4"
# gp == 0 in func_8004AAFC; scalar D_8009B458 with a -G0 assembler.
PER_FUNC_AS_FLAGS["func_8004AAFC"] = "-G0"
# gp == 0 in func_800336F0; every symbol wants the assembler's bare form.
PER_FUNC_AS_FLAGS["func_800336F0"] = "-G0"
# gp == 0 in func_8004A940; scalar D_8009B458 with a -G0 assembler.
PER_FUNC_AS_FLAGS["func_8004A940"] = "-G0"
# gp == 0 in func_8002C9B4 and it reaches D_8009B1D5 through %hi/%lo, so the
# scalar declaration plus a -G0 assembler is free here (recipe branch 1).
PER_FUNC_AS_FLAGS["func_8002C9B4"] = "-G0"
# gp == 0 in func_80020D4C: the aggregate arm gives cc1psx a %hi/%lo pair it
# hoists into a branch delay slot retail leaves empty, so take the scalar and
# a -G0 assembler instead (recipe branch 1, the delay-slot side).
PER_FUNC_AS_FLAGS["func_80020D4C"] = "-G0"
# func_80039794 needs D_8009B0C1 non-small while D_8009B35A (2 bytes) and
# D_8009B356 (1) stay gp-relative: recipe branch 3, declared size 8 and -G4.
PER_FUNC_AS_FLAGS["func_80039794"] = "-G4"
PER_FUNC_AS_FLAGS["func_80045484"] = "-G0"
PER_FUNC_AS_FLAGS["func_8004A854"] = "-G0"
PER_FUNC_AS_FLAGS["func_800493F8"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049600"] = "-G0"
PER_FUNC_AS_FLAGS["func_800495EC"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049F10"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049200"] = "-G0"
PER_FUNC_AS_FLAGS["func_800855B0"] = "-G0"
PER_FUNC_AS_FLAGS["func_800495A4"] = "-G0"
# D_8009B361 declared [8] (_IS_SIZED) so 8 > 4 takes it out of small data while
# the one-byte gp-relative D_8009B1D5 beside it stays in. The point is the
# delay slot, not the addressing: bare, the reference is one instruction to
# gcc, so it cannot be half-hoisted into the bgez's slot and retail's nop
# survives. Same lever as func_800175A0.
PER_FUNC_AS_FLAGS["func_80019CC8"] = "-G4"
# No %gp_rel anywhere in the function, so any -G is free: recipe branch 1.
# The real scalar declaration plus -G0 gives the assembler's own expansion
# through the destination register, which is retail's lui $v1 / lw $v1(...$v1).
# The unsized-array arm is cc1psx's pair and splits it across two registers.
PER_FUNC_AS_FLAGS["func_80047B68"] = "-G0"
# Recipe branch 2: the bare-wanting symbol is WIDER than the gp-relative one.
# D_800FE240 is a four-byte scalar and needs the assembler's own expansion
# through the destination register (retail's lui $a0 / lw $a0,...($a0)); the
# only other access is the one-byte D_8009AFA2, which must stay %gp_rel. Small
# data is size <= -G, so the window is 1 <= G < 4 and -G2 sits in the middle.
# -G0 takes D_8009AFA2 out with it and costs 43.
PER_FUNC_AS_FLAGS["func_8005A8C4"] = "-G2"
# Recipe branch 1 again (no %gp_rel in the function at all), but reached from
# the delay-slot side rather than the addressing side: the two instructions
# are the same either way, and what differs is that retail leaves the branch
# in front of them holding a nop. cc1psx's split pair is two instructions to
# the delay-slot filler, so it hoists the lui; the scalar declaration is one,
# so the slot stays empty and the assembler expands it after the branch.
PER_FUNC_AS_FLAGS["func_800151D8"] = "-G0"
# Recipe branch 1 again, and the same delay-slot use as func_800151D8: no
# %gp_rel anywhere, so any -G is free, and the scalar declaration makes
# D_8009B1D5 one instruction to gcc. Under the aggregate arm cc1psx's own
# %hi/%lo pair is two, and gcc hoists the lui out of the block into the
# search loop's load delay slot, where retail leaves a nop.
PER_FUNC_AS_FLAGS["func_8002C7E8"] = "-G0"
PER_FUNC_AS_FLAGS["func_8003AAE4"] = "-G0"
PER_FUNC_AS_FLAGS["func_80049920"] = "-G0"
PER_FUNC_AS_FLAGS["func_8004A0FC"] = "-G0"
PER_FUNC_AS_FLAGS["func_800478EC"] = "-G0"

# Optional experiment file, so sweeping flags for one function never means
# rewriting this script (editing it by string substitution silently failed
# more than once, and a flag that never took effect looks exactly like a
# flag that did not help). Format:
#   {"func_8001700C": {"cc": ["-quiet", "-O2", "-G0"], "as": "-G0"}}
_OVERRIDES = ROOT / "config" / "flag_overrides.json"
if _OVERRIDES.exists():
    import json
    for _name, _spec in json.loads(_OVERRIDES.read_text()).items():
        if "cc" in _spec:
            PER_FUNC_FLAGS[_name] = _spec["cc"]
        if "as" in _spec:
            PER_FUNC_AS_FLAGS[_name] = _spec["as"]
        # A null value means "use the default", which is what makes it
        # possible to audit an existing entry by dropping it. Without
        # this the override file could only add or change, never remove,
        # so every table entry stayed an untested inherited assumption.
        if _spec.get("cc", False) is None:
            PER_FUNC_FLAGS.pop(_name, None)
        if _spec.get("as", False) is None:
            PER_FUNC_AS_FLAGS.pop(_name, None)


def run(cmd, **kwargs):
    kwargs.setdefault("cwd", ROOT)
    result = subprocess.run([str(c) for c in cmd], capture_output=True,
                            text=True, **kwargs)
    if result.returncode != 0:
        sys.stderr.write(f"\nCommand failed: {' '.join(str(c) for c in cmd)}\n")
        for stream in (result.stdout, result.stderr):
            if stream:
                sys.stderr.write(stream[:8000] + "\n")
        raise SystemExit(1)
    return result


def check_toolchain():
    missing = [str(p) for p in (CPPPSX, CC1PSX, AS, LD, OBJCOPY, MASPSX,
                                VENV_PYTHON) if not p.exists()]
    if missing:
        sys.stderr.write("Missing toolchain components "
                         "(see docs/DECISIONS.md for where to get each):\n")
        for m in missing:
            sys.stderr.write(f"  {m}\n")
        raise SystemExit(1)


def func_addr(name):
    return int(name.split("_")[1], 16)


def ordered_functions():
    """Every function in the code segment, in address order."""
    names = [p.stem for p in ASM_FUNCS.glob("func_*.s")]
    if not names:
        sys.exit(f"no disassembly in {ASM_FUNCS} — run `splat split` first")
    return sorted(names, key=func_addr)


def boundary_functions():
    """Functions that end an original translation unit.

    The retail binary pads each object's .text out to 16 bytes. For a
    function still assembled from its .s that padding is already in the
    file; for one we've decompiled we have to reinstate it, which the
    linker script does with an explicit ALIGN.
    """
    if not BOUNDARIES.exists():
        return set()
    out = set()
    for line in BOUNDARIES.read_text().splitlines():
        if line.startswith("#") or not line.strip():
            continue
        parts = line.split()
        if len(parts) >= 2:
            out.add(parts[1])
    return out


def headers():
    """Every header a source file could pull in via common.h."""
    return sorted((ROOT / "include").glob("*.h"))


# This script holds the per-function flag tables, so a change to it can change
# any object's contents -- it counts as a dependency of everything.
SELF = Path(__file__).resolve()


def is_stale(target: Path, deps) -> bool:
    """True if `target` needs rebuilding from `deps` (mtime comparison).

    Deliberately conservative: a missing dependency counts as stale rather
    than being ignored, so a mistake here costs a rebuild, never a wrong
    binary. The sha1 check at the end is the backstop either way.
    """
    if not target.exists():
        return True
    t = target.stat().st_mtime
    return any(not d.exists() or d.stat().st_mtime > t for d in deps)


def compile_c(name):
    """cpppsx -> cc1psx -> maspsx -> as for one decompiled function."""
    src = SRC / f"{name}.c"
    out_dir = BUILD / "src"
    out_dir.mkdir(parents=True, exist_ok=True)
    pre = out_dir / f"{name}.i"
    asm = out_dir / f"{name}.s"
    masm = out_dir / f"{name}.maspsx.s"
    obj = out_dir / f"{name}.o"

    # The flags themselves are an input, so record them beside the object and
    # rebuild when they change. mtime alone is not enough: PER_FUNC_FLAGS can
    # come from config/flag_overrides.json, and rewriting that file leaves
    # every mtime in the dependency list untouched. Before this stamp existed,
    # a sweep that only rewrote the override file silently reused the stale
    # object and reported the *previous* flags' result -- so every sweep
    # reported the default flags no matter what was in the file. Making the
    # override file an mtime dependency does not work either: is_stale treats
    # a missing dependency as stale, so with no override file present every
    # function would rebuild on every run.
    flags = PER_FUNC_FLAGS.get(name, CC1_FLAGS)
    stamp = obj.with_suffix(".flags")
    # The stamp must name every input that shapes this object, not just the
    # compiler flags. Post-pass membership rewrites the assembly, so it belongs
    # here too -- leaving it out meant YGOFM_DROP_POSTPASS changed no mtime and
    # no stamp, the stale object was reused, and the post-pass audit read that
    # cached object as proof the post-pass was unnecessary. Eight false
    # "UNNEEDED" verdicts. This is the third time in this project that an input
    # the build did not watch produced confident nonsense; see the sweep-void
    # section of docs/DECISIONS.md for the first two.
    passes = ",".join(sorted(
        p for p, s in (("delay", DELAY_SLOT_MACRO_FUNCS),
                       ("sdnop", SMALL_DATA_NOP_FUNCS),
                       ("lacall", LA_CALL_FUNCS),
                       ("hoist", HOIST_EPILOGUE_FUNCS)) if name in s))
    want = (" ".join(flags) + " || " + (PER_FUNC_AS_FLAGS.get(name) or "")
            + " || " + str(PSYQ_BIN) + " || " + passes)
    fresh = (not is_stale(obj, [src, SELF, *headers()])
             and stamp.exists() and stamp.read_text() == want)
    if fresh:
        return obj
    stamp.write_text(want)
    run([*PSYQ_RUNNER, CPPPSX, *CPP_FLAGS, src.relative_to(ROOT).as_posix(),
         pre.relative_to(ROOT).as_posix()])
    run([*PSYQ_RUNNER, CC1PSX, *flags, pre.relative_to(ROOT).as_posix(),
         "-o", asm.relative_to(ROOT).as_posix()])

    # --expand-div: aspsx expands `div`/`rem` into the checked sequence
    # (`bne`+`break 7` for the divisor, the -1/0x80000000 pair and `break 6`
    # for the overflow), and retail has those checks. Without it maspsx emits
    # the bare `div`, which is what kept every function containing a real
    # division out of reach -- candidates.py was filtering them as
    # hand-written on the `break`. See DECISIONS.md.
    with open(asm) as fin, open(masm, "w") as fout:
        r = subprocess.run(
            [str(VENV_PYTHON), str(MASPSX),
             f"--aspsx-version={ASPSX_VERSION}", "--macro-inc", "--expand-div"],
            stdin=fin, stdout=fout, stderr=subprocess.PIPE, text=True, cwd=ROOT)
    if r.returncode != 0:
        sys.stderr.write(f"maspsx failed on {src.name}:\n{r.stderr[:8000]}\n")
        raise SystemExit(1)

    # Post-passes that emulate aspsx behaviour maspsx does not reproduce.
    if (name in DELAY_SLOT_MACRO_FUNCS or name in SMALL_DATA_NOP_FUNCS
            or name in HOIST_EPILOGUE_FUNCS or name in LA_CALL_FUNCS):
        text = masm.read_text().splitlines()
        if name in DELAY_SLOT_MACRO_FUNCS:
            text = fill_delay_slot_with_macro_tail(text)
        if name in SMALL_DATA_NOP_FUNCS:
            text = insert_small_data_load_delay_nops(
                text, sdata_limit=effective_sdata_limit(name))
        if name in LA_CALL_FUNCS:
            text = split_address_across_call(text)
        if name in HOIST_EPILOGUE_FUNCS:
            text = hoist_epilogue_out_of_delay_slot(text)
        masm.write_text("\n".join(text) + "\n")

    as_flags = list(AS_FLAGS)
    override = PER_FUNC_AS_FLAGS.get(name)
    if override:
        # later -G wins, so appending is enough to override the default
        as_flags.append(override)
    run([AS, *as_flags, "-o", obj.relative_to(ROOT).as_posix(),
         masm.relative_to(ROOT).as_posix()])
    return obj


_BARE_SYM_MEMOP = re.compile(
    r"^\s*(sw|sh|sb|lhu|lbu|lw|lh|lb)\s+(\$\w+)\s*,\s*([A-Za-z_]\w*)\s*$")
_JUMP = re.compile(r"^\s*(j|jr)\s+(\$\w+)\s*$")
_NOP = re.compile(r"^\s*nop\b")


def fill_delay_slot_with_macro_tail(lines):
    """Emulate aspsx splitting an expanded address macro across a delay slot.

    cc1psx (with -mno-split-addresses) emits a bare-symbol memory op such as
    `sw $4,D_800F5F80` and leaves the address expansion to the assembler.
    The original assembler expanded it to `lui $at,%hi` + `sw ...%lo($at)`
    *and* scheduled the second half into the following branch's delay slot,
    giving three instructions:

        lui $at,%hi(sym)
        jr  $ra
        sw  $a0,%lo(sym)($at)

    GNU as treats the expansion as indivisible and will not move half of it
    into a delay slot, so it emits four instructions instead and the
    function fails to match. maspsx passes this case straight through (it
    only rewrites bare symbols it knows to be small data), so we do the
    expansion ourselves, here.

    Only applies to the exact `memop / jump / nop` sequence; anything else
    is left untouched.
    """
    out, i = [], 0
    while i < len(lines):
        m = _BARE_SYM_MEMOP.match(lines[i])
        if (m and i + 2 < len(lines)
                and _JUMP.match(lines[i + 1]) and _NOP.match(lines[i + 2])):
            op, reg, sym = m.groups()
            out += [
                ".set\tnoat",
                f"lui\t$at,%hi({sym})",
                lines[i + 1].strip(),
                f"{op}\t{reg},%lo({sym})($at)",
                ".set\tat",
            ]
            i += 3
            continue
        out.append(lines[i])
        i += 1
    return out


_LA_SYM = re.compile(r"^\s*la\s+(\$\w+)\s*,\s*([A-Za-z_]\w*)\s*$")
_CALL = re.compile(r"^\s*(jal|j|jr)\b")


def split_address_across_call(lines):
    """The `la` counterpart of fill_delay_slot_with_macro_tail.

    With -mno-split-addresses cc1psx emits `la $4,D_800EAE98` and leaves the
    expansion alone. aspsx expanded it to lui/addiu *and* put the addiu in the
    following call's delay slot:

        lui   $a0,%hi(sym)
        jal   func
        addiu $a0,$a0,%lo(sym)

    GNU as keeps the pair together and the call gets a nop, one instruction
    too many. The existing macro post-pass does not cover this because it
    matches a memory op, not an address computation, and it writes through
    $at, which is wrong here -- the address stays in the argument register.

    Only the exact `la / call / nop` sequence is touched.
    """
    out, i = [], 0
    while i < len(lines):
        m = _LA_SYM.match(lines[i])
        if (m and i + 2 < len(lines)
                and _CALL.match(lines[i + 1]) and _NOP.match(lines[i + 2])):
            reg, sym = m.groups()
            out += [
                f"lui\t{reg},%hi({sym})",
                lines[i + 1].strip(),
                f"addiu\t{reg},{reg},%lo({sym})",
            ]
            i += 3
            continue
        out.append(lines[i])
        i += 1
    return out


_ANY_LOAD = re.compile(r"^\s*(lhu|lbu|lw|lh|lb)\s+(\$\w+)\s*,")
_LOAD_BARE_SYM = re.compile(
    r"^\s*(lhu|lbu|lw|lh|lb)\s+(\$\w+)\s*,\s*([A-Za-z_]\w*)\s*$")
_EXTERN = re.compile(r"^\s*\.extern\s+([A-Za-z_]\w*)\s*,\s*(\d+)")


def effective_sdata_limit(name):
    """The assembler's -G for one function: the default 8 unless overridden.

    This matters to insert_small_data_load_delay_nops, which decides what is
    small data by comparing `.extern sym,size` against the threshold. Passing
    the default 8 for a function that assembles at -G1 or -G2 would insert a
    nop after a load whose *next* instruction is going to expand through $at
    and fill the slot by itself -- one instruction too many. The fictional
    sizes make it sharper still: D_8009B368[2], D_8009B26C[4] and
    D_8009B408[8] are all "small" at 8 and were each chosen to fall outside
    the threshold their own function assembles at.
    """
    override = PER_FUNC_AS_FLAGS.get(name)
    if override:
        m = re.search(r"-G(\d+)", override)
        if m:
            return int(m.group(1))
    return 8


def insert_small_data_load_delay_nops(lines, sdata_limit=8):
    """Restore load-delay nops maspsx omits for extern small-data symbols.

    On the R3000 a loaded value is not available to the next instruction.
    maspsx normally inserts the required nop, but it skips the case where
    the following instruction will be expanded through $at -- the lui of
    that expansion fills the delay naturally. To decide, it needs to know
    whether the symbol is small data, and it deliberately ignores
    `.extern sym,size` when building that set. Every global we declare is
    extern (the definitions come from splat's data dumps), so maspsx
    assumes $at expansion for all of them.

    With -G8 the assembler instead emits a single gp-relative instruction,
    no lui, and the nop really is needed -- so the function comes out
    several instructions short. We recover the size information from the
    `.extern` directives the compiler emits and insert the nops ourselves.
    """
    small = {m.group(1) for m in (_EXTERN.match(l) for l in lines)
             if m and int(m.group(2)) <= sdata_limit}
    if not small:
        return lines

    def is_real_instruction(line):
        s = line.split("#")[0].strip()
        return bool(s) and not s.startswith(".") and not s.endswith(":")

    out = []
    for i, line in enumerate(lines):
        out.append(line)
        body_here = line.split("#")[0]
        m = _LOAD_BARE_SYM.match(body_here)
        if m and m.group(3) in small:
            reg = m.group(2)
        else:
            # The same omission happens the other way round: an ordinary load
            # followed by a bare-symbol memory op on a *small* symbol. maspsx
            # decides by the following instruction -- it expects that to expand
            # through $at and fill the slot -- so which of the two touches the
            # small symbol does not matter to it, and the first version of this
            # pass only handled the load side. func_80025028 is the case where
            # the store is the small one.
            m2 = _ANY_LOAD.match(body_here)
            if not m2:
                continue
            reg = m2.group(2)
            nxt0 = next((lines[j] for j in range(i + 1, len(lines))
                         if is_real_instruction(lines[j])), None)
            if nxt0 is None:
                continue
            m3 = _BARE_SYM_MEMOP.match(nxt0.split("#")[0])
            if not m3 or m3.group(3) not in small:
                continue
        nxt = next((lines[j] for j in range(i + 1, len(lines))
                    if is_real_instruction(lines[j])), None)
        if nxt is None:
            continue
        body = nxt.split("#")[0].strip()
        if body.startswith("nop"):
            continue
        if re.search(rf"{re.escape(reg)}\b", body):
            out.append("nop # load delay: extern small-data symbol")
    return out


def hoist_epilogue_out_of_delay_slot(lines):
    """Emulate aspsx hoisting a delay-slot instruction into a load-delay slot.

    cc1psx ends a small frame with the stack restore in the jr delay slot:

        lw    $31,16($sp)
        .set  noreorder
        j     $31
        addu  $sp,$sp,24

    `lw $31` immediately before a `jr $31` is a load-delay hazard. maspsx
    resolves it by inserting a nop after the load and leaving the restore in
    the delay slot. Real aspsx instead moves the restore up into the load
    delay and leaves the branch delay slot empty -- same cycle count, but two
    instructions swapped, which is a mismatch.

    Both shapes are in the retail binary, produced from byte-identical cc1psx
    output, so this is an assembler difference and not a compiler flag. The
    split is by address and very sharp: across 313 sampled functions the
    hoisted form appears only at 0x800742E8 and above and the maspsx form only
    at 0x80072F54 and below. So this pass is opt-in per function rather than
    global -- see HOIST_EPILOGUE_FUNCS.
    """
    def body(line):
        return line.split("#")[0].strip()

    def is_real(line):
        s = body(line)
        return bool(s) and not s.startswith(".") and not s.endswith(":")

    out = list(lines)
    for i, line in enumerate(out):
        m = re.match(r"(lw|lh|lhu|lb|lbu)\s+(\$\w+)\s*,", body(line))
        if not m:
            continue
        reg = m.group(2)
        idx = [j for j in range(i + 1, len(out)) if is_real(out[j])][:3]
        if len(idx) < 3:
            continue
        nop_i, jump_i, slot_i = idx
        if not body(out[nop_i]).startswith("nop"):
            continue
        if not re.match(rf"(j|jr)\s+{re.escape(reg)}\s*$", body(out[jump_i])):
            continue
        slot = body(out[slot_i])
        if re.search(rf"{re.escape(reg)}\b", slot) or slot.startswith("nop"):
            continue
        out[nop_i], out[slot_i] = out[slot_i], out[nop_i]
    return out


def object_func_size(obj, name):
    """Size of `name` as compiled, read back from the object's symbol table."""
    r = run([OBJDUMP, "-t",
             obj.relative_to(ROOT).as_posix()])
    for line in r.stdout.splitlines():
        parts = line.split()
        if parts and parts[-1] == name and len(parts) >= 5:
            try:
                return int(parts[-2], 16)
            except ValueError:
                continue
    return None


def object_section_size(obj, section):
    """Byte size of one section in an object, or 0 if it has none."""
    r = run([OBJDUMP, "-h", obj.relative_to(ROOT).as_posix()])
    for line in r.stdout.splitlines():
        parts = line.split()
        if len(parts) >= 3 and parts[1] == section:
            return int(parts[2], 16)
    return 0


def assemble_run(index, names):
    """Assemble a run of consecutive not-yet-decompiled functions."""
    GEN.mkdir(parents=True, exist_ok=True)
    stub = GEN / f"run_{index:04d}.s"
    lines = ['.include "include/macro.inc"', "", ".section .text",
             ".set noat", ".set noreorder", ""]
    for n in names:
        lines.append(f'.include "asm/nonmatchings/31D8/{n}.s"')
    text = "\n".join(lines) + "\n"
    # Only touch the stub when its contents actually change: rewriting it
    # unconditionally would bump its mtime and defeat the staleness check
    # below. The contents encode which functions are in this run, so a
    # change in the decompiled set is caught here.
    if not stub.exists() or stub.read_text() != text:
        stub.write_text(text)

    obj = GEN / f"run_{index:04d}.o"
    deps = [stub, SELF, *headers(),
            *(ASM_FUNCS / f"{n}.s" for n in names)]
    if not is_stale(obj, deps):
        return obj
    run([AS, *AS_FLAGS, "-o", obj.relative_to(ROOT).as_posix(),
         stub.relative_to(ROOT).as_posix()])
    return obj


def assemble_gen(src: Path) -> Path:
    """Assemble a stub we generated in build/gen (rodata runs)."""
    obj = src.with_suffix(".o")
    if not is_stale(obj, [src, SELF]):
        return obj
    run([AS, *AS_FLAGS, "-o", obj.relative_to(ROOT).as_posix(),
         src.relative_to(ROOT).as_posix()])
    return obj


def assemble_plain(src: Path) -> Path:
    obj = BUILD / src.relative_to(ROOT).with_suffix(".o")
    obj.parent.mkdir(parents=True, exist_ok=True)
    if not is_stale(obj, [src, SELF, *headers()]):
        return obj
    run([AS, *AS_FLAGS, "-o", obj.relative_to(ROOT).as_posix(),
         src.relative_to(ROOT).as_posix()])
    return obj


# --------------------------------------------------------------------------
# Jump tables.
#
# A `switch` dense enough for cc1psx to build a table puts that table in the
# object's .rodata and reaches it as %hi(.rodata)/%lo(.rodata) -- offset zero
# of the section. splat has already disassembled the same bytes into
# asm/data/800.rodata.s as `jtbl_<addr>`, so compiling such a function means
# the table exists twice and neither copy is where the other belongs.
#
# The fix is the same one .text already uses: split splat's rodata at the
# tables owned by functions we compile, and place the compiled object's
# .rodata in the hole. Ownership is derived from the table's own entries --
# `.word .L800XXXXX` targets land inside exactly one function -- rather than
# from the disassembly of the owner, which stops being read once it is
# decompiled.
RODATA_SRC = ROOT / "asm" / "data" / "800.rodata.s"
RODATA_OBJ_LINE = "build/asm/data/800.rodata.o(.rodata);"
RODATA_OBJ_STEM = "build/asm/data/800.rodata.o("


def rodata_blocks():
    """(name, first_line, last_line) for each dlabel block, in file order."""
    lines = RODATA_SRC.read_text().splitlines()
    out, start = [], None
    for i, line in enumerate(lines):
        if line.startswith("nonmatching ") and start is None:
            start = i
        m = re.match(r"^dlabel (\S+)", line)
        if m and start is None:
            start = i
        m = re.match(r"^enddlabel (\S+)", line)
        if m:
            out.append((m.group(1), start, i))
            start = None
    return lines, out


def jtbl_owners(lines, blocks):
    """jtbl name -> the function whose body its entries point into."""
    spans = []
    for name in ordered_functions():
        a = func_addr(name)
        spans.append((a, a + (target_size(name) or 0), name))
    spans.sort()
    starts = [s[0] for s in spans]

    def owner(addr):
        i = bisect.bisect_right(starts, addr) - 1
        if i >= 0 and spans[i][0] <= addr < spans[i][1]:
            return spans[i][2]
        return None

    out = {}
    for name, s, e in blocks:
        if not name.startswith("jtbl_"):
            continue
        body = "\n".join(lines[s:e + 1])
        owners = {owner(int(t, 16))
                  for t in re.findall(r"\.word \.L([0-9A-Fa-f]{8})", body)}
        owners.discard(None)
        if len(owners) == 1:
            out[name] = owners.pop()
    return out


def plan_rodata(decompiled):
    """Linker entries for .rodata, with compiled objects in the holes.

    Returns None when no decompiled function owns a table, so the ordinary
    single-object line is kept and nothing about the build changes.

    Everything outside an owned table is copied through verbatim, including
    the lines between blocks and the tail after the last one -- the first
    version of this carved out only the dlabel..enddlabel spans and lost the
    16 bytes the file ends with.
    """
    lines, blocks = rodata_blocks()
    owners = jtbl_owners(lines, blocks)
    mine = set(decompiled)
    if not any(f in mine for f in owners.values()):
        return None

    # Contiguous spans of lines belonging to one compiled owner.
    holes = []          # (first_line, last_line, func)
    i = 0
    while i < len(blocks):
        f = owners.get(blocks[i][0])
        if f in mine:
            j = i
            while j + 1 < len(blocks) and owners.get(blocks[j + 1][0]) == f:
                j += 1
            holes.append((blocks[i][1], blocks[j][2], f))
            i = j + 1
        else:
            i += 1

    preamble = ['.include "macro.inc"', "", '.section .rodata, "a"', ""]
    entries, runs, index, pos = [], [], 0, 0

    def emit(chunk):
        nonlocal index
        if not any(l.strip() for l in chunk):
            return
        # `.align 3` is a no-op in splat's file -- it lists every padding byte
        # explicitly, so the whole segment is contiguous -- but only because
        # that segment starts 8-aligned. A chunk that starts 4 mod 8 would
        # have the same directive emit four real bytes. Drop the wide aligns;
        # the byte-for-byte listing is what carries the layout.
        chunk = [l for l in chunk if not re.match(r"\s*\.align\s+[3-9]\s*$", l)]
        text = "\n".join(preamble + chunk) + "\n"
        stub = GEN / f"rodata_{index:04d}.s"
        stub.parent.mkdir(parents=True, exist_ok=True)
        if not stub.exists() or stub.read_text() != text:
            stub.write_text(text)
        runs.append(stub)
        entries.append(
            f"{stub.with_suffix('.o').relative_to(ROOT).as_posix()}(.rodata);")
        index += 1

    def next_addr(i):
        """Address of the first data line at or after line i."""
        for l in lines[i:]:
            m = re.search(r"/\*\s*\w+\s+([0-9A-Fa-f]{8})(?:\s+\w+)?\s*\*/", l)
            if m:
                return int(m.group(1), 16)
        return None

    for first, last, f in holes:
        emit(lines[pos:first])
        # Reinstate the hole's original extent. cc1psx aligns each table to 8
        # (`.align 3`) *relative to its own section*, so two tables that shared
        # a translation unit have padding between them that separate objects
        # cannot reproduce: jtbl_8001194C is seven live words and one word of
        # padding belonging to the table after it. How much to add is only
        # known once the object exists, so leave a marker and let main() fill
        # it in -- an absolute `. = 0x...` here instead moves _gp and the whole
        # small-data window with it.
        start, end = next_addr(first), next_addr(last + 1)
        span = (end - start) if (start and end) else 0
        entries.append((f, span))
        pos = last + 1
    emit(lines[pos:])
    return entries, runs


def write_linker_script(text_entries, rodata_entries=None):
    """Rewrite splat's linker script to place our per-function objects.

    splat emits a single `build/src/31D8.o(<section>);` line per section,
    assuming one object for the whole code segment. We swap the .text one
    for the ordered per-function list and drop the rest, since our objects
    contribute no rodata/data/bss of their own.
    """
    GEN.mkdir(parents=True, exist_ok=True)
    out = []
    for line in SPLAT_LD.read_text().splitlines():
        stripped = line.strip()
        if rodata_entries is not None and stripped.startswith(RODATA_OBJ_STEM):
            if stripped != RODATA_OBJ_LINE:
                continue  # the undivided object is not built when we split
            indent = line[: len(line) - len(line.lstrip())]
            out.extend(indent + e for e in rodata_entries)
            continue
        m = re.match(rf"{re.escape(SPLAT_CODE_OBJ)}\((\.\w+)\);", stripped)
        if not m:
            out.append(line)
            continue
        if m.group(1) != ".text":
            continue  # our objects have no data/bss to contribute
        indent = line[: len(line) - len(line.lstrip())]
        out.extend(indent + e for e in text_entries)
    GEN_LD.write_text("\n".join(out) + "\n")


def read_defsyms():
    """splat emits symbols it couldn't place as `name = 0xADDR;` lines.

    config/symbol_aliases.txt is ours, in the same format, and exists because
    the retail code sometimes materialises one address twice in a single basic
    block -- which cc1psx will not do from one symbol, since it CSEs the
    address. Two independent materialisations mean the original source saw two
    distinct objects at the same place, so we need a second name for it. splat
    only ever emits one symbol per address, and its auto files are regenerated,
    so the aliases live in a file of their own.
    """
    defsyms = []
    for name in ("undefined_syms_auto.txt", "undefined_funcs_auto.txt",
                 "symbol_aliases.txt"):
        path = ROOT / "config" / name
        if not path.exists():
            continue
        for line in path.read_text().splitlines():
            line = line.split("//")[0].split("#")[0].strip().rstrip(";").strip()
            if not line or "=" not in line:
                continue
            sym, _, value = line.partition("=")
            defsyms += ["--defsym", f"{sym.strip()}={value.strip()}"]
    return defsyms


def link_and_verify():
    # -EL is not optional on Linux: mips-linux-gnu-ld defaults to big-endian
    # while the PS1 is little-endian, and it rejects our (correctly
    # little-endian) objects with "endianness incompatible with that of the
    # selected emulation". The Windows mipsel-none-elf-ld already defaults
    # to LE, so passing it there is a harmless no-op.
    run([LD, "-EL", "-T", GEN_LD.relative_to(ROOT).as_posix(),
         "-Map", (BUILD / "slus_014.11.map").relative_to(ROOT).as_posix(),
         "--no-check-sections", *read_defsyms(),
         "-o", ELF.relative_to(ROOT).as_posix()])
    run([OBJCOPY, "-O", "binary", ELF.relative_to(ROOT).as_posix(),
         TARGET_BIN.relative_to(ROOT).as_posix()])

    actual = hashlib.sha1(TARGET_BIN.read_bytes()).hexdigest()
    print(f"\nbuilt : {TARGET_BIN.relative_to(ROOT)}")
    print(f"sha1  : {actual}")
    print(f"want  : {EXPECTED_SHA1}")
    if actual == EXPECTED_SHA1:
        print("\nOK: build is byte-identical to the retail executable.")
        return 0

    original = ROOT / "extracted" / "SLUS_014.11"
    if not original.exists():
        print("\nMISMATCH (original not present for a byte-level diff)")
        return 1

    want, got = original.read_bytes(), TARGET_BIN.read_bytes()
    print(f"\nMISMATCH: {len(got)} bytes built vs {len(want)} expected")
    report_bad_functions(want, got)
    return 1


def report_bad_functions(want, got):
    """Map differing bytes back to the functions they belong to.

    With a whole-binary diff the first bad byte is rarely informative: one
    wrong function shifts everything after it. Attributing differences to
    named functions says directly which sources to look at.
    """
    funcs = ordered_functions()
    spans = []           # (start_file_off, end_file_off, name)
    for name in funcs:
        addr = func_addr(name)
        size = target_size(name)
        start = 0x800 + (addr - 0x80010000)
        spans.append((start, start + size, name))

    limit = min(len(want), len(got))
    bad, first_off = [], None
    for start, end, name in spans:
        if start >= limit:
            break
        chunk_end = min(end, limit)
        if want[start:chunk_end] != got[start:chunk_end]:
            bad.append(name)
            if first_off is None:
                first_off = start

    decompiled = [n for n in bad if (SRC / f"{n}.c").exists()]
    if decompiled:
        print(f"\n{len(decompiled)} decompiled function(s) differ — "
              f"these are the ones to fix:")
        # Truncated by default so a cascade does not bury the summary.
        # YGOFM_ALL_DIFFS=1 prints the whole list -- needed whenever the
        # list itself is the data, e.g. comparing two toolchain versions.
        limit = None if os.environ.get("YGOFM_ALL_DIFFS") else 25
        for n in decompiled[:limit]:
            print(f"  {n}   (src/{n}.c)")
        if limit and len(decompiled) > limit:
            print(f"  ... and {len(decompiled) - limit} more "
                  f"(set YGOFM_ALL_DIFFS=1 to list all)")
    if bad and not decompiled:
        print("\nNo decompiled function differs directly; the first bad "
              f"region is {bad[0]}, which is still assembled from .s — "
              "this usually means something before it changed size.")
    if not bad:
        print("\nAll function bodies match; the difference is outside "
              "function bodies (padding, data, or alignment).")


def target_size(name):
    """Size of a function as recorded in its disassembly header."""
    path = ASM_FUNCS / f"{name}.s"
    first = path.read_text().split("\n", 1)[0]
    m = re.search(r",\s*(0x[0-9A-Fa-f]+)", first)
    return int(m.group(1), 16) if m else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--clean", action="store_true", help="remove build/ first")
    ap.add_argument("-j", "--jobs", type=int, default=12,
                    help="concurrent compile/assemble jobs "
                         "(latency-bound, so oversubscribing cores helps)")
    args = ap.parse_args()

    check_toolchain()
    if args.clean and BUILD.exists():
        shutil.rmtree(BUILD)
    BUILD.mkdir(parents=True, exist_ok=True)

    functions = ordered_functions()
    decompiled = [n for n in functions if (SRC / f"{n}.c").exists()]
    boundaries = boundary_functions()
    print(f"{len(functions)} functions, {len(decompiled)} decompiled")

    # Plan first, build second. Walking the address-ordered list decides
    # which objects exist and in what order they are placed; the actual
    # compiling is then order-independent and can run concurrently.
    plan = []          # (kind, payload) in .text placement order
    pending, run_index = [], 0
    for name in functions:
        if (SRC / f"{name}.c").exists():
            if pending:
                plan.append(("run", (run_index, pending)))
                run_index += 1
                pending = []
            plan.append(("c", name))
            if name in boundaries:
                # reinstate the original object's 16-byte .text padding
                plan.append(("align", None))
        else:
            pending.append(name)
    if pending:
        plan.append(("run", (run_index, pending)))

    plain = sorted((ROOT / "asm").glob("*.s")) + \
        sorted((ROOT / "asm" / "data").glob("*.s"))

    # .rodata: only split when a decompiled function owns a jump table.
    # When we do split, the undivided object must not be assembled at all --
    # it would define every jtbl symbol a second time.
    rodata = plan_rodata(decompiled)
    rodata_entries, rodata_runs = rodata if rodata else (None, [])
    if rodata_entries is not None:
        plain = [p for p in plain if p != RODATA_SRC]

    # Almost all of the wall time here is waiting on subprocesses -- a full
    # build spends minutes of real time on seconds of CPU, and under Wine
    # each PsyQ invocation pays process-startup latency. So oversubscribe
    # the cores rather than matching them.
    jobs = {}
    with cf.ThreadPoolExecutor(max_workers=args.jobs) as pool:
        for kind, payload in plan:
            if kind == "c":
                jobs[("c", payload)] = pool.submit(compile_c, payload)
            elif kind == "run":
                index, names = payload
                jobs[("run", index)] = pool.submit(assemble_run, index, names)
        for src in plain:
            jobs[("plain", src)] = pool.submit(assemble_plain, src)
        for stub in rodata_runs:
            jobs[("rodata", stub)] = pool.submit(assemble_gen, stub)
        # Surface the first failure rather than a wall of tracebacks.
        for fut in cf.as_completed(jobs.values()):
            fut.result()

    text_entries, size_errors = [], []
    for kind, payload in plan:
        if kind == "align":
            text_entries.append(". = ALIGN(., 16);")
            continue
        key = ("c", payload) if kind == "c" else ("run", payload[0])
        obj = jobs[key].result()
        text_entries.append(f"{obj.relative_to(ROOT).as_posix()}(.text);")
        if kind == "c":
            # A wrong-sized function shifts everything after it, so the
            # whole-binary diff would blame dozens of innocent functions.
            # Catching size errors here keeps the blame local.
            built, wanted = object_func_size(obj, payload), target_size(payload)
            if built is not None and wanted and built != wanted:
                size_errors.append((payload, built, wanted))

    if size_errors:
        print(f"\n{len(size_errors)} function(s) compiled to the wrong size. "
              "Fix these first — each one shifts everything after it, so any "
              "other reported difference is probably just fallout:")
        for name, built, wanted in size_errors:
            delta = (built - wanted) // 4
            print(f"  {name}: {built:#x} vs {wanted:#x} expected "
                  f"({delta:+d} instructions)   src/{name}.c")

    if rodata_entries is not None:
        resolved = []
        for e in rodata_entries:
            if isinstance(e, str):
                resolved.append(e)
                continue
            name, span = e
            obj = jobs[("c", name)].result()
            resolved.append(f"{obj.relative_to(ROOT).as_posix()}(.rodata);")
            pad = span - object_section_size(obj, ".rodata")
            if pad > 0:
                resolved.append(f". = . + {pad};")
            elif pad < 0:
                raise SystemExit(
                    f"{name}: compiled .rodata is {-pad} bytes larger than the "
                    f"{span}-byte hole splat left for its jump table")
        rodata_entries = resolved

    write_linker_script(text_entries, rodata_entries)
    print(f"placed {len(text_entries)} entries in .text")
    return link_and_verify()


if __name__ == "__main__":
    raise SystemExit(main())
