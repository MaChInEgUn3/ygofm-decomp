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
    u8 *g;
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
            *(s16 *)(g + 0x1A) = D_8009AF2D;
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
            *(s16 *)(g + 2) = -0x18;
            *(u16 *)g = D_800908A0[0xC];
        } while (0);
        *(u16 *)(g + 4) = D_800908A0[0xD];
        return;
    s1:
        *(u16 *)g = 0xA0;
        y = 0x78;
        goto put;
    s2:
        *(u16 *)g = 0xA0;
        y = 0x70;
        goto put;
    s3:
        *(u16 *)g = 0xA0;
        y = 0x70;
    put:
        *(s16 *)(g + 2) = y;
    }
}
