/* 201/201 and 23 differing (2026-09-07; was 24 with an UNINITIALISED READ).
 * The installed candidate stored through `g`, a name that was never assigned
 * anywhere in the function -- inherited from the permuter output this park was
 * decomposed from, and nobody noticed because it compiles and scores. The
 * honest reading is the call result: `e = func_8002C604(D_8009AF2C);` and every
 * store through `e`. That is 23, i.e. BETTER than the unsound 24, so the read
 * was not even buying anything.
 *
 * Residue: retail copies the record pointer into $a1 (`addu $a1,$v0,$zero`)
 * after the +0x1A store and runs the +0/+2/+4 stores through the copy, where we
 * keep it in $s0 for the whole block. A second name does NOT reproduce the
 * copy: borrowing the dead `b` after the 0x1A store is 23 (coalesced away),
 * borrowing it before is +1/35, a fresh name before is +1/35, and splitting
 * only the s1/s2/s3 arm is 23. So the copy is not a source-level second name
 * -- WORKFLOW's dead-assignment rule says a plain copy always coalesces and
 * only a DERIVED value survives, and no derived spelling is legal here because
 * the stores need the same address.
 *
 * krystalgamer's matched copy is described as "Small-data sized arrays, empty
 * case 0 for the dispatch tree, separate case bodies". The dispatch tree we
 * already reproduce (beq 1 / slti 2 / beq 2 / beq 3 is exactly the goto chain
 * written here, and `if (m == 0)` is his empty case 0 one level down); what is
 * untried is writing both dispatches as real `switch` statements with separate
 * case bodies instead of the shared `put:` join.
 */
#define FUNC_80017F04_FULL
#define D_8009B394_SIZED_VOLATILE
#define D_8009B398_SIZED_VOLATILE
#define D_8009B3A4_IS_VOLATILE_SIZED
#include "common.h"
extern u8 D_8009AF2E;
extern s32 D_8009B180;
extern s32 D_8009B184;
extern u8 D_801A7B80[];

void func_800222F4(void) {
    u8 *e;
    u8 *b;
    s32 y;
    s32 m;

    if ((D_8009B3A4[0] & 0x800) != 0) {
        func_800220B8();
    }
    if ((D_8009B23A & 0x8000) == 0) {
        D_8009B23A = D_8009B23A | 0xC000;
        *(u8 *)((s32)&D_8009B16C + 2) = 0;
        D_8009AF2E = 0;
        D_8009AF2A = 0;
        D_8009AF2D = 0;
        D_8009B184 = 0;
        D_8009B180 = 0;
    }
    if ((D_8009B23A & 0x4000) != 0) {
        D_8009B23A = D_8009B23A & 0xBFFF;
        func_80029528(0);
        func_8004036C(D_8009B180);
        func_8004036C(D_8009B184);
        D_8009B184 = 0;
        D_8009B180 = 0;
        m = D_8009AF2E;
        if (m == 1) {
            goto m1;
        }
        if (m >= 2) {
            if (m == 2) {
                goto m2;
            }
            if (m == 3) {
                goto m3;
            }
        }
        return;
    m1:
        {
            func_80029164(0, 1);
            func_800137E4();
            e = (u8 *)func_800291E0(0, -1, -1);
            *(s16 *)(e + 0x30) = 0x5A;
            *(s16 *)(e + 0x32) = 0x16;
            func_80012D84(4);
            func_8001944C(e);
            return;
        }
    m2:
        D_8009B180 = (s32)func_80017F04(D_801A7B80, 0x86, 0x52);
        return;
    m3:
        D_8009B180 = (s32)func_80017F04(D_801A7B80, 0x5C, 0x52);
        D_8009B184 = (s32)func_80017F04(D_801A7B80 + 0x1C, 0xB0, 0x52);
        return;
    }
    if ((D_8009B398[0] & 0x100) != 0) {
        D_8009B23A = D_8009B23A | 0x4000;
        D_8009AF2E = D_8009AF2E + 1;
        if (D_8009AF2E >= 4) {
            D_8009AF2E = 0;
        }
        return;
    }
    if ((D_8009B398[0] & 0xA000) != 0) {
        D_8009AF2A = D_8009AF2A ^ 1;
        return;
    }
    if ((D_8009B394[0] & 0x5000) != 0) {
        b = &D_8009AF2C;
        b[D_8009AF2A] = b[D_8009AF2A] + 1;
        if ((D_8009B394[0] & 0x4000) != 0) {
            b[D_8009AF2A] = b[D_8009AF2A] - 2;
        }
        return;
    }
    if ((D_8009B398[0] & 0x40) != 0) {
        e = func_8002C604(D_8009AF2C);
        *(u8 *)((s32)&D_8009B16C + 2) = (*(u8 *)((s32)&D_8009B16C + 2) + 1) & 7;
        do {
            *(s16 *)(e + 0x1A) = D_8009AF2D;
            m = D_8009AF2E;
            if (m == 1) {
                goto s1;
            }
            if (m >= 2) {
                goto ge2;
            }
            if (m == 0) {
                goto s0;
            }
            return;
        ge2:
            if (m == 2) {
                goto s2;
            }
            if (m == 3) {
                goto s3;
            }
            return;
        s0:
            *(s16 *)(e + 2) = -0x18;
            *(u16 *)e = D_800908A0[0xC];
        } while (0);
        *(u16 *)(e + 4) = D_800908A0[0xD];
        return;
    s1:
        *(u16 *)e = 0xA0;
        y = 0x78;
        goto put;
    s2:
        *(u16 *)e = 0xA0;
        y = 0x70;
        goto put;
    s3:
        *(u16 *)e = 0xA0;
        y = 0x70;
    put:
        *(s16 *)(e + 2) = y;
    }
}
