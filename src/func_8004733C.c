/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* func_8004733C -- no confirmed real name. Gated forwarder: when bit 1 of
   the global control byte at +0x4A is set, route a 16-bit id to one of two
   handlers. Ids with 0x8000 set go to func_80045208 (after a fixed
   func_800473CC(0x7000) prologue call); ordinary ids go to
   func_80049230, biased down by 0x7000 when they sit at or above it.
   Reached from func_80047314 (0x80047324).

   Span 0x8004733C-0x800473CC, 36 insns. config/function_ranges.txt splits
   it into F 8004733C (R 4) + F 80047340 (R 8C): the first word is the
   D_8009B45C load that gcc hoisted above the prologue -- the documented
   leading-load-before-prologue boundary bug, not a separate function.
   Every measurement needs --len 0x90.

   0/36, G8 (both split settings), 2026-08-29 (w4). Two register pins, no
   inline asm; the sketch at match/sketches/func_8004733C.c carries the
   full attempt history from 9/36 -> 7/36 -> 1/36 -> 0/36.

   Why the two pins are needed:

   - `t` pinned to $s1 reproduces target's prologue exactly: gcc saves s0
     and emits `move s0,a1` early, then defers `move s1,a0` into the flag
     gate's own branch delay slot. Dropping the pin swaps the two pairs
     (11/36); pinning a1 to $s0 as well costs a scratch move and a word.

   - `m` pinned to $v0 is what closes the last word. Target speculates the
     else path's mask into the `beqz`'s delay slot as `andi v0,s1,0xffff`
     -- reading the saved copy, writing the same register the just-consumed
     flag test used. Written against `t` with no pin, gcc coalesces the
     mask INTO $s1 (`andi s1,s1,0xffff`), which cannot be speculated
     because $s1 is still live on the if path, so the slot fills with a nop
     and the tail shifts a word (18/36 at 37 words). Written against the
     raw parameter instead it does get speculated but reads $a0 (1/36).
     Pinning the mask to $v0 forces a fresh destination, and gcc's
     delay-slot filler then steals it exactly as the target does.
     Equivalent and also 0/36: any use of `t` after the mask (an empty
     `__asm__("" :: "r"(t))` on either side of the `if`), which blocks the
     same coalesce by keeping $s1 live. The pin is the cheaper statement of
     the same fact. */

struct S8009B45C_47 {
    char pad[0x4A];
    u8 f4A;  /* 0x4A -- control flags; bit 1 enables this dispatch */
};
extern struct S8009B45C_47 *D_8009B45C;

extern void func_800473CC(s32 arg0);
extern void func_80045208(s32 arg0, s16 arg1);
extern void func_80049230(s16 arg0, s16 arg1);

void func_8004733C(s32 a0, s32 a1) {
    register s32 t asm("s1") = a0;

    if (!(D_8009B45C->f4A & 2))
        return;

    if (a0 & 0x8000) {
        func_800473CC(0x7000);
        func_80045208(t & 0xFFFF, (s16) a1);
    } else {
        register u32 m asm("v0");

        m = t & 0xFFFF;
        if (m >= 0x7000u) {
            a0 -= 0x7000;
        }
        func_80049230((s16) a0, (s16) a1);
    }
}
