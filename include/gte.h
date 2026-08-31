#ifndef GTE_H
#define GTE_H

/* GTE (coprocessor 2) access, spelled the way the PsyQ SDK spells it.
 *
 * C has no operators for the geometry engine, so every decomp reaches it
 * through inline asm. The question krystalgamer raised on 2026-08-31 is which
 * inline asm: the SDK ships these as macros -- `gte_ldv0()`, `gte_rtps()`,
 * `gte_stsxy()` in INLINE_C.H / GTEMAC.H -- and a decomp should call those
 * rather than hand-roll the same instructions at every call site, which is
 * what this tree was doing in 21 files.
 *
 * The names and the operand conventions below are the SDK's, deliberately, so
 * the source reads the way a PS1 programmer's would and transfers to anyone
 * who knows the API.
 *
 * WHY THIS IS A LOCAL HEADER AND NOT THE SDK'S OWN. INLINE_C.H is the
 * "DMPSX version 3" macro set: its command macros emit a *cookie*, not an
 * instruction -- `gte_rtps()` is `nop; nop; .word 0x0000007f`, and 0x7F is not
 * a COP2 word. Sony's `dmpsx` pass rewrote those cookies into real
 * instructions, and this pipeline does not run dmpsx (maspsx has no such
 * pass). Including the SDK header directly would assemble 0x7F as a literal
 * word and silently produce a different binary. GTEMAC.H does not help
 * either: it is a layer on top of INLINE_C.H and calls the same macros.
 *
 * So the command macros here go through the assembler mnemonics in
 * `include/gte_macros.inc`, which maspsx already includes (`--macro-inc`) and
 * which carry the real encodings -- `rtps` is `cop2op 0x01,0x01`, i.e.
 * 0x4A180001. Same words, right spelling, no cookie.
 *
 * The load and store macros ARE the SDK's, verbatim: those are ordinary
 * lwc2/swc2 and needed no translation.
 */

/* Load a 16-bit XYZ vector into VXY0/VZ0. */
#define gte_ldv0(r0) __asm__ volatile(                                        \
    "lwc2 $0, 0(%0);"                                                         \
    "lwc2 $1, 4(%0)"                                                          \
    : : "r"(r0))

/* Perspective-transform one vertex. The two nops are the SDK's: the GTE needs
 * them before the command issues, and they are part of the retail bytes. */
#define gte_rtps() __asm__ volatile(                                          \
    "nop;"                                                                    \
    "nop;"                                                                    \
    "rtps")

/* Store the transformed screen XY (SXY2). */
#define gte_stsxy(r0) __asm__ volatile(                                       \
    "swc2 $14, 0(%0)"                                                         \
    : : "r"(r0) : "memory")

/* Store the transformed Z (SZ3). */
#define gte_stsz(r0) __asm__ volatile(                                        \
    "swc2 $19, 0(%0)"                                                         \
    : : "r"(r0) : "memory")

/* Store MAC0, the general-purpose accumulator. */
#define gte_stopz(r0) __asm__ volatile(                                       \
    "swc2 $24, 0(%0)"                                                         \
    : : "r"(r0) : "memory")

/* Store the interpolated depth cue (RGB2). */
#define gte_strgb(r0) __asm__ volatile(                                       \
    "swc2 $22, 0(%0)"                                                         \
    : : "r"(r0) : "memory")

#endif /* GTE_H */
