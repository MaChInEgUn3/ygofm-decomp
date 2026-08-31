/* PARKED CANDIDATE PORTED from Unchiga's tree (docs/MERGE_UNCHIGA.md).
 * Installed here because HIS base is closer than the one this tree
 * reached: the counts are in PARKED.txt. Measure it with the flags on
 * the next line -- they are his unit's, and try_func's default flags
 * report a different number.
 * FLAGS: -G0 -mno-split-addresses
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* 0x80049920 -- SPU voice release sweep.
 *
 * Walks the D_8009B458 slot array (0x28 stride, *(s16*)(base+0x510) entries)
 * in lockstep with the per-voice bitmask table at 0x80011434 (D_80010538+0xEFC).
 * For every slot whose pending/busy byte at +0x18D is non-zero it polls
 * func_80077090 (func_80077090); on status 3 (KEY-ON acknowledged) the slot's
 * counter is re-func_800738F0 and either retried via func_80076ED0 (func_80076ED0) until the
 * status settles, or simply bumped by one.  Every voice actually released is
 * OR-ed into `mask`, which is handed to func_80076ED0 once at the end.
 *
 * Sibling of func_8004AAFC / func_8004A7C0 (same slot array, same +0x18D byte,
 * same func_80076ED0/func_80077090 retry idiom).
 *
 * Shape notes, all load-bearing for the match:
 *  - one D_8009B458 extern alias per reload SITE (the loop reloads it four
 *    times; a single alias collapses them), and each of the three record-address
 *    computations gets its OWN register-pinned local because the ROM uses a
 *    different register triple at each site.
 *  - `mask = idx;` sits ABOVE the `if (count > 0)`: it is the insn the delayed
 *    branch pass pulls into the blez delay slot.  gcc-2.8.1 reorg.c's backward
 *    scan takes the nearest preceding delay-eligible insn, so anything eligible
 *    emitted between it and the branch steals the slot -- which is why
 *    `keyDone` must NOT carry an initialiser on its declaration (that emits
 *    `li s5,2` into the pre-branch block).  See WORKFLOW.md DS-2 / GCC_INTERNALS.md.
 *  - the table pointer is a literal absolute address, materialised lui-into-v0
 *    then addiu-into-s1; plain C address arithmetic folds both halves into one
 *    register.
 *
 * Flags: -G0 -mno-split-addresses
 */

extern u8 *D_8009B458;
extern u8 *D_8009B458;
extern u8 *D_8009B458;
extern u8 *D_8009B458;

extern void func_80076ED0(s32 a0, u32 a1);
extern s32 func_80077090(s32 a0);

void func_80049920(void) {
    register u8 *baseV1 asm("v1");
    s32 count;
    register s32 idx asm("s4");
    s32 off;
    register s32 mask asm("s3");
    s32 keyDone;
    s32 *table;
    s32 v0;

    idx = 0;
    baseV1 = D_8009B458;
    mask = idx;
    count = *(s16 *)(baseV1 + 0x510);
    if (count > 0) {
        keyDone = 2;
        off = idx;
        {
            register s32 hi asm("v0") = 0x80010000;
            __asm__("addiu %0, %1, 0x1434" : "=r" (table) : "r" (hi));
        }
        do {
            register u8 *rec1 asm("v0");

            rec1 = baseV1 + off;
            if (rec1[0x18D] != 0) {
                if (func_80077090(*table) == 3) {
                    register u8 *base2 asm("v0");
                    register u8 *rec2 asm("a0");
                    register u8 subVal2 asm("v1");

                    base2 = D_8009B458;
                    rec2 = base2 + off;
                    subVal2 = rec2[0x18D];
                    if (subVal2 >= 2) {
                        s32 *p = table;
                        register u8 *base3 asm("v0");

                        mask |= *p;
                        do {
                            func_80076ED0(0, *p);
                            v0 = func_80077090(*p);
                        } while (v0 != keyDone && v0 != 0);
                        base3 = D_8009B458;
                        base3 = base3 + off;
                        base3[0x18D] = 0;
                    } else {
                        register u8 inc asm("v0");
                        inc = (u8) (subVal2 + 1);
                        rec2[0x18D] = inc;
                    }
                }
            }
            off += 0x28;
            baseV1 = D_8009B458;
            count = *(s16 *)(baseV1 + 0x510);
            table++;
            idx++;
        } while (idx < count);
    }
    if (mask != 0) {
        func_80076ED0(0, mask);
    }
}
