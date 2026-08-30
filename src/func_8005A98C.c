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

/* rgb_to_hls_8005a98c / func_8005A98C (0x8005A98C, 133 words).
 *
 *     void *func_8005A98C(void *out, s8 r, u8 g, s8 b, u8 range)
 *
 * Foley & van Dam style RGB -> HLS conversion.  Copies r,g,b into a local
 * u8 sp[3]; finds mx/mn, the INDEX of the max and min channel, with a
 * running-index loop; then vmax = sp[mx], vmin = sp[mn], range2 = range*2,
 * sum = vmax+vmin, lit = (sum << 12) / range2.  delta = vmax - vmin; if
 * delta is 0, hue and sat stay 0.  Otherwise sat = (delta << 12) / sum when
 * lit < 0x801 and (delta << 12) / (range2 - sum) above it -- the classic
 * HLS saturation split at 50% lightness -- and
 * hue = mx*0x2000 + ((sp[(mx+1)%3] - sp[(mx+2)%3]) << 12) / delta, plus
 * 0x6000 if negative (the hue-sextant formula, sextant width 0x2000).
 * `out` receives { s32 val0; s16 hue; s16 sat; }.
 *
 * MATCHES AT ALL FOUR FLAG COMBOS (0/133 each).  A four-way tie is a
 * finding, not a choice: recorded as settled-undetermined; the manifest
 * carries gcc's own default, -G8 -msplit-addresses.
 *
 * The hard-register variables and the two empty `__asm__` statements are
 * load-bearing.  What each one is for, since none of it is guessable from
 * the C:
 *
 *   maxptr/minptr in $v0/$v1, and the launder on maxptr.  The ROM computes
 *   BOTH addresses before either load (addu v0,sp,t1 / addu v1,sp,t0 / lbu
 *   / ... / lbu).  Without the launder gcc sinks each address to its own
 *   load and reuses one register for both, because maxptr dies at its
 *   load.  The launder keeps them simultaneously live; it emits nothing.
 *
 *   arg4masked in $v0, and the launder after it.  The ROM func_8008FAF0 the range
 *   mask in $v0 -- maxptr's just-freed register -- and shifts it into $a2
 *   as a separate instruction (andi v0 / ... / sll a2,v0,1).  The pin alone
 *   does NOT fire: the value has a single use, so gcc materialises it
 *   straight into the consumer's register (the LA-1 single-use-pin caveat).
 *   The launder gives it a second reference and the pin then holds.
 *
 *   dvd in $v1.  The dividend `sum << 12` must land in $v1; first-fit
 *   ascending gives it $v0, which is free by then.  This pin is what the
 *   next note is about.
 *
 *   idx1p is deliberately NOT pinned, and that is the last lever.  It used
 *   to be `register s32 idx1p asm("v1")`, which is where the ROM keeps it.
 *   TWO variables pinned to $v1 in disjoint scopes do not cost one word
 *   each -- they interact: with both pins the dividend came out right and
 *   the (var_t1+1)%3 block's magic-multiply constant moved three words,
 *   and with neither, the reverse.  Dropping the second pin and keeping
 *   only the dividend's gave both.  Generalisable: before adding a pin,
 *   check whether the same hard register is already pinned elsewhere in
 *   the function; a pin is function-wide even when the declaration is
 *   scoped, so the second one is not free.
 *
 * Ladder: 9/133 banked (unsearched, no ALT blocks) -> 7 (w1's first knobs)
 * -> 6 (launder maxptr) -> 3 (launder arg4masked) -> 0 (pin the dividend to
 * $v1 AND unpin idx1p).  Derivation in match/sketches/func_8005A98C_v2.c.
 */

struct HueSatOut {
    s32 val0;
    s16 hue;
    s16 sat;
};

void *func_8005A98C(void *arg0, s8 arg1, u8 arg2, s8 arg3, u8 arg4)
{
    s8 sp[3];
    struct HueSatOut res;
    register s32 temp_a1 __asm__("a1");
    register s32 temp_a2 __asm__("a2");
    register s32 temp_a3 __asm__("a3");
    register u32 arg4masked __asm__("v0");
    s32 temp_lo;
    s32 temp_v0;
    s32 var_a0;
    s32 var_t0;
    s32 var_t1;
    register u32 temp_a0 asm("a0");
    u8 temp_a1_2;
    register u32 temp_a1_3 asm("a1");
    var_t1 = 0;
    var_t0 = 0;
    var_a0 = 1;
    sp[0] = arg1;
    sp[1] = arg2;
    sp[2] = arg3;
    do
    {
        temp_a1_2 = sp[var_a0];
        if (temp_a1_2 > ((u8) sp[var_t1]))
        {
            var_t1 = var_a0;
        }
        if (temp_a1_2 < ((u8) sp[var_t0]))
        {
            var_t0 = var_a0;
        }
        var_a0 += 1;
    }
    while (var_a0 < 3);
    {
        register u8 *maxptr __asm__("v0");
        register u8 *minptr __asm__("v1");
        maxptr = (u8 *) (&sp[var_t1]);
        minptr = (u8 *) (&sp[var_t0]);
        __asm__ volatile ("" : "+r" (maxptr));
        temp_a1_3 = *maxptr;
        arg4masked = ((u32) arg4) & 0xFF;
        __asm__ volatile ("" : "+r" (arg4masked));
        temp_a0 = *minptr;
        temp_a2 = arg4masked * 2;
    }
    temp_a3 = temp_a1_3 + temp_a0;
    {
        register s32 dvd asm("v1");
        dvd = temp_a3 << 0xC;
        temp_lo = dvd / temp_a2;
    }
    res.sat = 0;
    res.val0 = 0;
    temp_a1 = temp_a1_3 - temp_a0;
    res.hue = (s16) temp_lo;
    if (temp_a1 != 0)
    {
        if (((u32) (temp_lo & 0xFFFF)) < 0x801U)
        {
            res.sat = (s16) (((s32) (temp_a1 << 0xC)) / temp_a3);
        }
        else
        {
            temp_lo = (s32) (temp_a2 - temp_a3);
            res.sat = (s16) (((s32) (temp_a1 << 0xC)) / temp_lo);
        }
        {
            s32 idx1p;
            register s32 idx2p __asm__("a0");
            s32 diffval;
            s32 new_var;
            s32 new_var2;
            idx1p = var_t1 + 1;
            new_var = idx1p % 3;
            idx2p = var_t1 + 2;
            new_var2 = idx2p % 3;
            diffval = ((u8) sp[new_var]) - ((u8) sp[new_var2]);
            temp_v0 = (var_t1 << 0xD) + ((diffval << 0xC) / temp_a1);
        }
        res.val0 = temp_v0;
        if (temp_v0 < 0)
        {
            res.val0 = temp_v0 + 0x6000;
        }
    }
    *((struct HueSatOut *) arg0) = res;
    return arg0;
}
