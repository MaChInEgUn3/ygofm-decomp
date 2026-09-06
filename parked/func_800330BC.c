/* 273/273 and 17 differing (2026-09-06, first pass). gp=0 and at=0, so
 * WORKFLOW's first recipe branch: both flag halfwords keep their real scalar
 * declarations and the unit assembles at -G0, which is where retail's
 * %hi/%lo pairs come from (the default -G8 renders them as one bare
 * instruction each and the function is eight short). Both are volatile:
 * each is read twice in a row, once for the mask and once for the sub-bit.
 * The levers, in the order they landed:
 *   - `u = *(u16 *)(p + 0x2D3C);` hoisted ABOVE the `a != b` test, so its
 *     lhu fills the load-delay slot retail fills (inside the if it is -1 and
 *     the slot is a nop);
 *   - the four byte counter updates written as `t = (p[K] = p[K] +- 1);`.
 *     This is the whole difference between 106 and 20: the embedded
 *     assignment makes the store the value's own definition, so the `sb`
 *     sits between the `addiu` and the `sll 24` the way retail has it.
 *     `t = p[K] + 1; p[K] = t;` is 106, the two-statement split against one
 *     name is 194, no local at all is +1, a `u8` local is +1, `s8 t` is +7,
 *     and one name per site is +1;
 *   - the `sel:` block (the c >= 0 arm) written at the END of the first
 *     flag's arm and reached by `goto sel;` from the second, which is where
 *     retail lays it out;
 *   - `q = row * 0x10 + (col * 2 + D_80090DD8);` named, so the `+ 1` stays
 *     the load's displacement instead of folding into %lo(D_80090DD8+1).
 *   - the second `c = -1;` written as `s = -1; c = s;` -- `s` is dead there
 *     and reassigned in the arm below, so this is the borrow-a-dead-name
 *     hint; the permuter found it as `c = (s = -1);` and the plain two
 *     statements score the same 16. Without it the two -1s are merged and
 *     retail materialises the constant twice;
 *   - the table address written FLAT, `q = D_80090DD8 + row * 0x10 +
 *     col * 2;`, which is 16 -> 12: the parenthesised grouping evaluates the
 *     col term first and retail reads the row byte first. Six other
 *     groupings (a named row, two named bytes, `&D_80090DD8[...]`, a
 *     two-statement base) are all 16 or 17.
 * Residue, 12 lines in two groups: (1) `a` is $v1 where retail has $a0 while
 * `u` takes $a0 -- ten lines, and eight read orders at the head are 12, 13 or
 * much worse (dropping `u` entirely and reading the symbol twice is +5);
 * (2) the two `if (t < s) s = t;` clamps come out `bne` where retail has
 * `beq` -- the else form, an empty else, the ternary and a goto form are all
 * 16 or worse. Permuter run 2026-09-06 from the 17 base: 660 iterations,
 * three outputs, best re-scores 16 and is the `c = (s = -1)` above. */
#define D_8009B394_IS_VOLATILE
#define D_8009B3A4_IS_VOLATILE
#include "common.h"

void func_80031E04(u8 *arg0, s32 arg1);
void func_80032C48(u8 *arg0);

s32 func_800330BC(u8 *p) {
    s32 s;
    s32 c;
    s32 a;
    s32 b;
    s32 t;
    s32 u;
    u8 *q;

    a = *(s16 *)(p + 0x2D3C);
    b = *(s8 *)(p + 0x2D48);
    s = a | b;
    if (s != 0) {
        s = (a + b + 1) * 0x98 / *(s16 *)(p + 0x2D42);
    }
    *(s16 *)(*(s32 *)(p + 0x2D38) + 0x32) = s + 0x29;
top:
    a = *(s16 *)(p + 0x2D3C);
    b = *(s16 *)(p + 0x2D3E);
    u = *(u16 *)(p + 0x2D3C);
    if (a != b) {
        if (b < a) {
            t = u - 1;
        } else {
            t = u + 1;
        }
        *(s16 *)(p + 0x2D3C) = t;
        func_80031E04(p, 8);
        return 1;
    }
    c = -1;
    if (D_8009B3A4 & 0xC) {
        s = a;
        if (D_8009B3A4 & 8) {
            if (s == *(s16 *)(p + 0x2D40) - 8) {
                if (*(s8 *)(p + 0x2D48) != 7) {
                    c = 7;
                }
            }
            s += 8;
            t = *(s16 *)(p + 0x2D40) - 8;
            if (t < s) {
                s = t;
            }
        } else {
            if (s == 0) {
                if (*(s8 *)(p + 0x2D48) == 0) {
                    c = 0;
                }
            }
            s -= 8;
        }
        if (s < 0) {
            s = 0;
        }
        *(s16 *)(p + 0x2D3E) = s;
        if (*(s16 *)(p + 0x2D3C) != s) {
            func_8003FEE0(6);
            goto top;
        }
sel:
        if (c >= 0) {
            p[0x2D48] = c;
            *(s16 *)(*(s32 *)(p + 0x2D34) + 0x32) = c * 0x16 + 0x2A;
            func_8003FEE0(6);
        }
        return 1;
    }
    s = -1;
    c = s;
    if (D_8009B394 & 3) {
        s = a;
        if (D_8009B394 & 2) {
            if (s == *(s16 *)(p + 0x2D40) - 8) {
                if (*(s8 *)(p + 0x2D48) != 7) {
                    c = 7;
                }
            }
            s += 0x32;
            t = *(s16 *)(p + 0x2D40) - 8;
            if (t < s) {
                s = t;
            }
        } else {
            if (s == 0) {
                if (*(s8 *)(p + 0x2D48) == 0) {
                    c = 0;
                }
            }
            s -= 0x32;
            if (s < 0) {
                s = 0;
            }
        }
        if (*(s16 *)(p + 0x2D3C) == s) {
            goto sel;
        }
        func_8003FEE0(6);
        *(s16 *)(p + 0x2D3E) = s;
        *(s16 *)(p + 0x2D3C) = s;
        func_80031E04(p, 8);
        return 1;
    }
    if (D_8009B394 & 0x5000) {
        s = a;
        if (D_8009B394 & 0x4000) {
            t = (p[0x2D48] = p[0x2D48] + 1);
            if ((s8)t >= 8) {
                s += 1;
                p[0x2D48] = 7;
            }
        } else {
            t = (p[0x2D48] = p[0x2D48] - 1);
            if ((s8)t < 0) {
                s -= 1;
                p[0x2D48] = 0;
            }
        }
        *(s16 *)(*(s32 *)(p + 0x2D34) + 0x32) = *(s8 *)(p + 0x2D48) * 0x16 + 0x2A;
        if (*(s16 *)(p + 0x2D40) - 8 < s) {
            return 1;
        }
        if (s < 0) {
            return 1;
        }
        func_8003FEE0(6);
        *(s16 *)(p + 0x2D3E) = s;
        if (*(s16 *)(p + 0x2D3C) != s) {
            goto top;
        }
        return 1;
    }
    if (D_8009B394 & 0x900) {
        if (D_8009B394 & 0x800) {
            t = (p[0x2D46] = p[0x2D46] + 1);
            if ((s8)t >= 7) {
                p[0x2D46] = 0;
            }
        } else {
            t = (p[0x2D46] = p[0x2D46] - 1);
            if ((s8)t < 0) {
                p[0x2D46] = 6;
            }
        }
        func_8003FEE0(0x2F);
        q = D_80090DD8 + p[0x2D47] * 0x10 + *(s8 *)(p + 0x2D46) * 2;
        p[0x2D45] = q[1] & 0xF;
        func_80032C48(p);
        return 1;
    }
    return 0;
}
