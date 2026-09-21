/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_intro_controller.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern s32 (*D_800114E8[4])(s32, s32);
extern ModelSlot D_800F2C40[3 ];
void func_80059284(s32 index, s32 value);
extern u8 *D_8009AF88;
extern u16 D_8009AF96;
extern s8 D_8009AF9A;
extern u8 D_8009AFA0;
extern u8 D_8009AFE9;
extern u32 D_8009AFEC[];
extern char D_8009AFF4[];
void func_80059590(
    s32 slot,
    s32 mode,
    s32 target0,
    s32 target1,
    s32 target2
);
void func_80047314(u32 value);
void func_8005F27C(s32 mode, s32 coefficient, SVECTOR *offset);
void func_8005F3B8(s32 mode, s32 y, s32 a, s32 b, SVECTOR *offset);
void func_8005F588(s32 value);
void func_8005F5C8(s32 mode, s32 coefficient, SVECTOR *offset, s32 arg);
void func_8005F714(s32 first, s32 second, s32 arg);
void func_8005F91C(
    s32 mode,
    ModelEffectEndpoint *first,
    ModelEffectEndpoint *second,
    s32 arg
);
ModelEffectCoefficient *func_8005F1A4(s32 index);
void func_8005A188(int value);
int func_8005A878(int arg);
s32 func_8005A618(s32 index);
s32 func_8005FB08(void);
s32 func_8005FB14(void);
s32 func_8005F174(void);
void func_8005F180(s32 value);
s32 func_80058E1C(void);
void func_80050F24(s32 index);
void func_80059EBC(s32 value);
void func_80059F18(s32 first, s32 second, s32 third, s32 fourth);
void func_8005A010(s32 first, s32 second);
void func_8005A0DC(s32 value);
s32 func_8005A2E0(s32 index);
extern ;
extern u16 D_8009B478;
extern u16 D_8009B47A;
void func_8004EB00(void);
void func_8004EB00(void)
{
    s32 (*handlers[4])(s32, s32);
    SVECTOR offset;
    s32 n;

    *(ModelSlotS32Quad *)handlers = *(ModelSlotS32Quad *)D_800114E8;
    n = 1;
    if (((D_801D4244[D_800F2C40[1].field_DF8] >> 0x1A) & 0x1F) == 1) {
        n = 2;
    }
    switch ((s8)(D_8009AF9A + 1)) {
    case 0:
        break;
    case 1:
        func_800595C8(2, -0x1000, -0x1000, -0x1000);
        func_80059590(0, 5, 0, 0, 0);
        func_80059590(1, 5, 0, 0, 0);
        D_8009AF9A++;
        break;
    case 2:
        func_80047314(D_8009AF96);
        D_8009AF9A++;
        break;
    case 3: {
        ModelEffectCoefficient *coef;
        s32 a;

        *(ModelBytes8 *)&offset = *(ModelBytes8 *)D_8009AFEC;
        a = 0x78;
        switch (D_8009AF88[0xA0]) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
            func_8005F27C(2, 0xA, 0);
            break;
        case 2:
            coef = func_8005F1A4(0xA);
            func_8005F3B8(2, 0x64, coef->angle + 0x800, -0x400, 0);
            offset.vx = coef->field_00;
            offset.vy = -0x1000;
            offset.vz = coef->field_04 + 0x400;
            a = 0x96;
            break;
        }
        func_8005F91C(0, (void *)&offset, (void *)0, a);
        D_8009AF9A++;
        break;
    }
    case 4:
        if (D_800F2C40[2].field_DA0[0] < 0x800) {
            func_80059284(2, 3);
            D_800F2C40[2].field_DA0[0] += 0x40;
            D_800F2C40[2].field_DA0[1] += 0x40;
            D_800F2C40[2].field_DA0[2] += 0x40;
        } else if (func_8005FB08() != 0) {
            func_80059EBC(0);
            func_8005F588(1);
            func_8005F5C8(0, 0, 0, -0xC);
            func_8005F714(0, 0, 0x4000);
            D_8009AF9A++;
        }
        break;
    case 5:
        if (D_800F2C40[0].field_E1F != 0) {
            s16 *r = (s16 *)func_8005FB14();
            if (r != 0 && r[3] == 2) {
                func_8005F588(1);
                func_8005F5C8(0, 0, 0, -0xC);
                func_8005F714(0, 0, 0x4000);
                D_8009AFA0 = 0;
                handlers[0](D_800F2C40[0].field_DEC, 0);
                D_800F2C40[0].field_E15 = 0;
                D_8009AF9A++;
            }
        }
        break;
    case 6:
        if (D_800F2C40[0].field_E15 == 0) {
            D_8009AFA0 = 0;
            if (handlers[0](D_800F2C40[0].field_DEC, -1) != 2) {
                break;
            }
            D_800F2C40[0].field_E15++;
        }
        if ((s8)D_800F2C40[0].field_DC0[0] >= 0) {
            D_800F2C40[0].field_DC0[0] += 2;
            D_800F2C40[0].field_DC0[1] += 2;
            D_800F2C40[0].field_DC0[2] += 2;
        } else {
            if (D_800F2C40[0].field_E11 != 4) {
                func_80059284(0, 3);
            }
            func_80059590(0, 0, 0x80, 0x80, 0x80);
            func_80059590(1, 0, 0x80, 0x80, 0x80);
            func_80057AF4(0, 2, 1);
            D_8009AFE9 = 0;
            D_8009AF9A++;
        }
        break;
    case 7:
        if (D_800F2C40[0].field_E11 != 4) {
            func_80059284(0, 3);
        }
        if (D_800F2C40[0].field_E0F == 0) {
            D_8009AFE9 += func_80058E1C();
            if (D_8009AFE9 >= 0x3C && D_800F2C40[1].field_E1F != 0) {
                func_8005F588(1);
                func_8005F5C8(1, 0, 0, -0xA);
                func_8005F714(1, 1, 0x4000);
                D_8009AF9A++;
            }
        }
        break;
    case 8: {
        s16 *r;

        if (D_800F2C40[0].field_E11 != 4) {
            func_80059284(0, 3);
        }
        r = (s16 *)func_8005FB14();
        if (r != 0 && r[3] == 2) {
            func_8005F27C(1, 0, 0);
            D_8009AF9A++;
        }
        break;
    }
    case 9:
        if ((s8)D_800F2C40[1].field_DC0[0] >= 0) {
            D_800F2C40[1].field_DC0[0] += 2;
            D_800F2C40[1].field_DC0[1] += 2;
            D_800F2C40[1].field_DC0[2] += 2;
        } else {
            func_80057AF4(1, 2, 1);
            D_8009AFE9 = 0;
            D_8009AF9A++;
        }
        break;
    case 10:
        if (D_800F2C40[1].field_E0F == 0) {
            D_8009AFE9 += func_80058E1C();
            if (D_8009AFE9 >= 0x3C) {
                s32 kind;
                s32 off;

                kind = D_800F2C40[0].field_CF8.prefix.bytes.field_0A[D_800F2C40[0].field_DFE] & 0x1F;
                off = -0x14;
                if (kind == 1) {
                    goto s10_m0;
                }
                if (kind < 2) {
                    goto s10_m3;
                }
                if (kind == 2) {
                    goto s10_m1;
                }
                if (kind == 3) {
                    goto s10_m2;
                }
                kind = 3;
                goto s10_teste;
            s10_m0:
                kind = 0;
                goto s10_teste;
            s10_m1:
                kind = 1;
                goto s10_teste;
            s10_m2:
                kind = 2;
                goto s10_teste;
            s10_m3:
                kind = 3;
            s10_teste:
                if ((u32)kind < 2) {
                    off = off / 2;
                }
                func_8005F5C8(0, kind, 0, off);
                D_8009AF9A++;
            }
        }
        break;
    case 11:
        if (func_8005FB08() != 0) {
            func_80059F18(1, -1, 0, -0x1E);
            D_8009AF9A++;
        }
        break;
    case 12:
        if (func_8005A878(1) != 0) {
            s32 a;
            s32 b;
            s32 d;

            a = func_8005A618(0);
            b = (func_80058E1C() + 2) * 8;
            d = (s16)D_8009B47A - a;
            if (d >= 0 ? b >= d : b >= a - (s16)D_8009B47A) {
                func_80050F24(0);
                D_8009AFA0 = 1;
                handlers[n](D_800F2C40[1].field_DEC, 0x18E);
                D_800F2C40[1].field_E15 = 0xFF;
                D_8009AF9A++;
            }
        }
        break;
    case 13: {
        s32 a;
        s32 cl;

        if (D_800F2C40[1].field_E0F != 5) {
            if (D_800F2C40[1].field_E0F != 6) {
                if (D_800F2C40[1].field_E0F == 8) {
                    a = 3;
                } else {
                    a = 0;
                }
            } else {
                a = 2;
            }
        } else {
            a = 1;
        }
        if (D_800F2C40[1].field_E15 == 0xFF && D_800F2C40[1].field_E0F == 8) {
            D_800F2C40[1].field_E15 = 0;
        }
        if (D_800F2C40[1].field_E15 == 0) {
            D_8009AFA0 = 1;
            handlers[n](D_800F2C40[1].field_DEC, -1);
        }
        if (D_800F2C40[0].field_E0E == 2) {
            if (D_800F2C40[0].field_E0F == 0) {
                a = 4;
            }
        } else if (func_8005F174() == 0) {
            a = 0;
        }
        if (a != 0) {
            a = func_8005A2E0(1) * 0x1E / 1000;
            if (func_8005F174() == 2) {
                func_8005F180(1);
            }
            func_8005F91C(0, (void *)0, (void *)0, 0);
            cl = a;
            if (cl < 0xA) {
                cl = 0xA;
            }
            func_80059F18(1, -1, 1, cl);
            D_8009AF9A++;
        }
        break;
    }
    case 14:
        if (D_800F2C40[1].field_E0F == 6) {
            D_8009AF9A = 0x14;
            break;
        }
        if (D_800F2C40[1].field_E15 == 0) {
            D_8009AFA0 = 1;
            handlers[n](D_800F2C40[1].field_DEC, -1);
        }
        if (func_8005A878(1) != 0 && func_8005FB08() != 0
            && D_800F2C40[0].field_E0E == 2 && D_800F2C40[0].field_E0F == 0
            && D_800F2C40[1].field_E0E == 2 && D_800F2C40[1].field_E0F == 0) {
            if (D_800F2C40[1].field_DFF != 0) {
                func_8005A0DC(0x78);
                D_8009AF9A = 0x1E;
            } else {
                D_8009AF9A++;
            }
        }
        break;
    case 15:
        if (func_8005FB08() != 0) {
            func_80059F18(1, -1, 1, -0x1E);
            D_8009AF9A++;
        }
        break;
    case 16:
        if (func_8005A878(1) != 0) {
            s32 a;
            s32 b;
            s32 d;

            a = func_8005A618(1);
            b = (func_80058E1C() + 2) * 8;
            d = (s16)D_8009B47A - a;
            if (d >= 0 ? b >= d : b >= a - (s16)D_8009B47A) {
                func_80050F24(1);
                D_8009AF9A++;
            }
        }
        break;
    case 17: {
        s32 a;
        s32 cl;

        if (D_800F2C40[0].field_E0F != 5) {
            if (D_800F2C40[0].field_E0F != 6) {
                if (D_800F2C40[0].field_E0F == 8) {
                    a = 3;
                } else {
                    a = 0;
                }
            } else {
                a = 2;
            }
        } else {
            a = 1;
        }
        if (D_800F2C40[1].field_E0E == 2) {
            if (D_800F2C40[1].field_E0F == 0) {
                a = 4;
            }
        } else if (func_8005F174() == 0) {
            a = 0;
        }
        if (a != 0) {
            a = func_8005A2E0(0) * 0x1E / 1000;
            if (func_8005F174() == 2) {
                func_8005F180(1);
            }
            func_8005F91C(0, (void *)0, (void *)0, 0);
            cl = a;
            if (cl < 0xA) {
                cl = 0xA;
            }
            func_80059F18(1, -1, 0, cl);
            D_8009AF9A++;
        }
        break;
    }
    case 18:
        if (D_800F2C40[0].field_E0F == 6) {
            D_8009AF9A = 0x14;
            break;
        }
        if (func_8005A878(1) != 0 && func_8005FB08() != 0
            && D_800F2C40[0].field_E0E == 2 && D_800F2C40[0].field_E0F == 0
            && D_800F2C40[1].field_E0E == 2 && D_800F2C40[1].field_E0F == 0) {
            func_8007EF84(D_8009AFF4);
        }
        break;
    case 21: {
        s32 f = D_800F2C40[0].field_E0F != 6;
        ModelSlot *slot = &D_800F2C40[f ^ 1];

        if (slot->field_E0E == 2) {
            if (slot->field_E0F == 0 && D_800F2C40[f].field_E16 == 0x23) {
                if (D_800F2C40[1].field_DFF == 0
                    && D_800F2C40[0].field_CF8.prefix.values.field_00 == D_800F2C40[1].field_CF8.prefix.values.field_00) {
                    if (D_800F2C40[1].field_E13 == 0xFF) {
                        D_800F2C40[1].field_E13 = 0x80;
                    }
                    func_80057AF4(1, 6, 1);
                }
                func_8005F91C(0, (void *)0, (void *)0, 0);
                if (func_8005A878(1) != 0) {
                    s32 b = func_8005A2E0(f) * 0x1E / 1000;
                    if (b < 0xA) {
                        b = 0xA;
                    }
                    func_80059F18(1, -1, f, -b);
                }
                D_8009AF9A++;
            }
        }
        break;
    }
    case 22: {
        s32 f = D_800F2C40[0].field_E0F != 6;
        ModelSlot *slot = &D_800F2C40[f];

        if (slot->field_E13 == 0 && func_8005A878(1) != 0) {
            func_80059590(f, 5, 0x80, 0x80, 0x80);
            D_8009AFA0 = f;
            handlers[3](slot->field_DEC, 0);
            slot->field_E15 = 0;
            D_8009AF9A++;
        }
        break;
    }
    case 23: {
        s32 f = D_800F2C40[0].field_E0F != 6;
        ModelSlot *slot = &D_800F2C40[f];
        s32 a;
        s32 v;

        if (slot->field_E15 == 0) {
            D_8009AFA0 = f;
            if (handlers[3](slot->field_DEC, -1) != 2) {
                break;
            }
            slot->field_E15++;
        }
        if (slot->field_DC0[0] != 0) {
            slot->field_DC0[0] -= 2;
            slot->field_DC0[1] -= 2;
            slot->field_DC0[2] -= 2;
            break;
        }
        v = (s16)D_8009B47A;
        if (f > 0) {
            a = (v + 0xC00) % 0x1000;
        } else {
            a = (v + 0x400) % 0x1000;
        }
        if ((u32)(a - 0x201) < 0xBFF) {
            s32 g = f ^ 1;
            s32 b = func_8005A2E0(g) * 0x1E / 1000;

            if (b < 0x1E) {
                b = 0x1E;
            }
            func_80059F18(1, -1, g, -b);
            D_8009AF9A++;
        }
        break;
    }
    case 24: {
        s32 f = D_800F2C40[0].field_E0F == 6;

        if (func_8005FB08() != 0) {
            s32 a = (s16)D_8009B478;
            if (func_8005F1B8(f, 0x2BC) + 0xA >= a && func_8005A878(1) != 0) {
                if (D_800F2C40[0].field_CF8.prefix.values.field_00 == D_800F2C40[1].field_CF8.prefix.values.field_00
                    && D_800F2C40[1].field_DFF == 0) {
                    D_8009AFA0 = 1;
                    handlers[3](D_800F2C40[1].field_DEC, 0);
                    D_800F2C40[1].field_E15 = 0;
                    D_8009AF9A = 0x19;
                    D_8009AFE9 = 0;
                } else {
                    func_8005F714(-1, f, 0x4000);
                    func_8005A010(-1, f);
                    func_80057AF4(f, 7, 1);
                    D_8009AF9A++;
                }
            }
        }
        break;
    }
    case 25: {
        s32 f = D_800F2C40[0].field_E0F == 6;

        if (D_800F2C40[f].field_E0F != 7) {
            func_8005F91C(0, (void *)0, (void *)0, 0);
            func_80059F18(1, -1, f, -0x1E);
            D_8009AFE9 = 0x3C;
            D_8009AF9A++;
        }
        break;
    }
    case 26: {
        s32 f = D_800F2C40[0].field_E0F == 6;

        if (D_800F2C40[f].field_E13 == 0 && func_8005A878(1) != 0) {
            D_8009AFE9 += func_80058E1C();
            if (D_8009AFE9 >= 0x3C) {
                func_80059590(f, 5, 0x80, 0x80, 0x80);
                D_8009AF9A++;
            }
        }
        break;
    }
    case 27: {
        s32 f = D_800F2C40[0].field_E0F == 6;
        ModelSlot *slot;
        ModelSlot *base;

        if (D_800F2C40[0].field_CF8.prefix.values.field_00 == D_800F2C40[1].field_CF8.prefix.values.field_00
            && D_800F2C40[1].field_DFF == 0 && D_800F2C40[1].field_E15 == 0) {
            D_8009AFA0 = 1;
            if (handlers[3](D_800F2C40[1].field_DEC, -1) != 2) {
                break;
            }
            D_800F2C40[1].field_E15++;
        }
        base = D_800F2C40;
        slot = &base[f];
        if (slot->field_DC0[0] != 0) {
            slot->field_DC0[0] -= 2;
            slot->field_DC0[1] -= 2;
            slot->field_DC0[2] -= 2;
        } else {
            D_8009AF9A++;
        }
        break;
    }
    case 28:
        if (func_8005A878(1) != 0) {
            D_8009AF9A = 0x28;
        }
        break;
    case 31:
        if (D_800F2C40[1].field_E15 == 0) {
            D_8009AFA0 = 1;
            if (handlers[n](D_800F2C40[1].field_DEC, -2) == 2) {
                D_800F2C40[1].field_E15++;
            }
        } else if (func_8005A878(1) != 0) {
            func_80059590(1, 5, 0x80, 0x80, 0x80);
            D_8009AF9A++;
        }
        break;
    case 32:
        if (D_800F2C40[1].field_DC0[0] != 0) {
            D_800F2C40[1].field_DC0[0] -= 2;
            D_800F2C40[1].field_DC0[1] -= 2;
            D_800F2C40[1].field_DC0[2] -= 2;
        } else {
            s32 a = (s16)D_8009B47A + 0xC00;

            if ((u32)(a % 0x1000 - 0x201) < 0xBFF) {
                s32 b = func_8005A2E0(0) * 0x1E / 1000;
                if (b < 0x1E) {
                    b = 0x1E;
                }
                func_80059F18(1, -1, 0, -b);
                D_8009AF9A++;
            }
        }
        break;
    case 33:
        if (func_8005FB08() != 0 && func_8005A878(1) != 0) {
            func_80059590(0, 5, 0x80, 0x80, 0x80);
            D_8009AF9A++;
        }
        break;
    case 34:
        if (D_800F2C40[0].field_DC0[0] != 0) {
            D_800F2C40[0].field_DC0[0] -= 2;
            D_800F2C40[0].field_DC0[1] -= 2;
            D_800F2C40[0].field_DC0[2] -= 2;
        } else {
            D_8009AF9A = 0x28;
        }
        break;
    case 41:
        func_80059284(2, 3);
        func_80015904();
        D_8009AF9A++;
        break;
    case 42:
        func_80059284(2, 3);
        if (!(D_800E9ECE[0] & 0x80)) {
            func_8004763C();
            D_8009AF9A = -2;
        }
        break;
    }
    func_8005A188(1);
}
