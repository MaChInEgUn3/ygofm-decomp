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

/* Consume one command byte from the D_8009B290 stream, or re-func_800738F0 a latched
   one, and clear the busy flag unless the byte says to keep going.

   func_8002E3B4 gates it. When it reports ready, the next stream byte is
   taken and the pointer advanced, func_800158B8 runs, and the byte's low six
   bits -- if any are set -- are latched into D_800E9ECF. When it reports NOT
   ready, nothing is consumed and the previously latched byte at D_800E9ECE is
   examined instead. Either way bit 7 is a CONTINUE flag: clear means clear
   D_8009B27C on the way out, set means leave it alone. Same stream and same
   gate as func_8002EDB0, which takes the other branch of the same protocol.

   THE TWO ARMS TEST BIT 7 IN OPPOSITE SENSES, AND THAT IS THE MATCH. The
   target's consuming arm does `beqz` TO the shared clear, then jumps past it;
   the latched arm does `bnez` to the RETURN and falls through into the clear.
   Written the obvious way -- `if (bit) return;` at the end of each arm, with
   one `D_8009B27C = 0;` after the if/else -- gcc cross-jumps the two tails
   into a single shared `bnez`, which is correct code and THREE WORDS SHORT of
   the target at 29 against 32. That shortfall makes the diff count unreadable,
   which is why this sat at 16/32.

   Distinct locals for the two masks do not stop it (the merge is on the RTL
   branch, not on the variables), and neither does giving each arm its own
   store, its own pinned temp, or inverting the gate -- all still 29 words. A
   `goto` to the shared clear is what reproduces the opposite senses, and with
   it the whole function falls out at 0/32.

   The byte globals must be declared OVERSIZED. D_800E9ECE and D_800E9ECF are
   single bytes; as plain scalars they land in small data at -G8 and the unit
   does not link, because they sit ~0x4F000 from $gp and GPREL16 cannot reach.
   Declaring them `[16]` forces absolute lui/%lo addressing, which is what the
   target uses -- while D_8009B290 stays small and IS reached through $gp
   (`lw v0,904(gp)`). Both addressing modes in one unit, decided per symbol by
   its declared size. */

extern u8 *D_8009B290;
extern u16 D_8009B27C;
extern u8 D_800E9ECE[16];
extern u8 D_800E9ECF[16];
extern s32 func_8002E3B4(void);
extern void func_800158B8(void);

void func_8002F440(void) {
    u8 s0;
    s32 m;

    if (func_8002E3B4() == 0) {
        s0 = *D_8009B290++;
        func_800158B8();
        m = s0 & 0x3F;
        if (m != 0) {
            D_800E9ECF[0] = m;
        }
        if ((s0 & 0x80) == 0) {
            goto clear;
        }
        return;
    }
    if ((D_800E9ECE[0] & 0x80) != 0) {
        return;
    }
clear:
    D_8009B27C = 0;
}
