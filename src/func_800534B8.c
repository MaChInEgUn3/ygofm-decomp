/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_debug_controller.c (ModelDebug_UpdateController), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern ModelDebugState D_8009B004;
extern ModelDebugDisplayState D_8009B008;
extern char D_8009B00C[];
extern char D_8009B014[];
extern char D_8009B01C[];
extern char D_8009B024[];
extern char D_8009B02C[];
s32 func_800534B8(void);
extern char D_80011518[];
extern char D_8001152C[];
extern char D_80011540[];
extern char D_80011554[];
extern char D_80011564[];
extern volatile u16 D_8009B398 __attribute__((section(".data")));
extern u16 D_8009B3A4 __attribute__((section(".data")));
extern volatile u16 D_8009B394 __attribute__((section(".data")));
extern u16 D_8009B39A __attribute__((section(".data")));
extern ModelSlot D_800F2C40[3 ];
s32 func_80056504(
    s32 slot, s32 model, s32 p2, s32 p3, s32 p4, s32 p5, s32 arg6
);
void func_80056828(s32 index);
extern u8 *D_8009AF88;
extern s8 D_8009AF9A;
extern u8 D_8009AFA1;
extern int func_8007EF84();
extern s16 D_8009B488[3 ];
extern u8 D_8009B48E[2];
extern u8 D_8009B490[2];
void func_80053248(s32 idx, ...);
void func_800533D8(void);
void func_80059AEC(s32 value);
s32 func_80059AA8(s32 index, s32 value);
void func_8005922C(struct _GsCOORDUNIT *unit, VECTOR *scale);
void func_800137E4(void);
extern u32 D_8009B134_abs __attribute__((section(".data")));
extern int  func_8008E590(void);
extern ModelDebugState D_8009B004;
s32 func_800534B8(void)
{
    s32 reload = 0;
    char *normal = D_8009B00C;
    char *selected = D_8009B014;
    ModelSlot *slots;

    if (D_8009AF9A == -2)
        return 1;
    if (D_8009AF9A >= 40)
        return 0;
    if ((D_8009B398 & 0x20) || (D_8009B39A & 0x20)) {
        D_8009AF9A = 40;
        return 0;
    }
    slots = D_800F2C40;
    if (!slots[2].field_E1F) {
        func_80059AEC(1);
        func_8007EF84(D_80011518, slots[2].field_DF8, slots[2].field_E14);
        if (slots[2].field_E14 == 255) {
            if (!((D_8009B0F4_abs & 0x2000030) | D_8009B134_abs))
                func_80056504(2, -1, -1, -1, -1, -1, 0);
        } else {
            func_80056828(2);
        }
        if (D_800F2C40[2].field_E1F) {
            ModelSlot *stage = D_800F2C40;
            s32 height;

            stage += 2;
             

            *(u16 *)&D_8009B004.fields.height =
                ((ModelBackgroundRecord *)D_8009AF88)->stage_height;
            height = D_8009B004.fields.height;
            if (stage->field_D18) {
                stage->field_D18->rot.vx = 0;
                stage->field_D18->rot.vy = 0;
                stage->field_D18->rot.vz = 0;
                stage->field_D18->matrix.t[0] = 0;
                stage->field_D18->matrix.t[1] = height;
                stage->field_D18->matrix.t[2] = 0;
            }
            func_8005922C(stage->field_D18, 0);
            D_8009AF9A = 0;
        }
    } else if (!slots[0].field_E1F) {
        func_80059AEC(1);
        func_8007EF84(D_8001152C, slots[0].field_DF8, slots[0].field_E14);
        if (slots[0].field_E14 == 255) {
            if (!((D_8009B0F4_abs & 0x2000030) | D_8009B134_abs))
                func_80056504(0, -1, -1, -1, -1, -1, 0);
        } else {
            func_80056828(0);
        }
        if (D_800F2C40[0].field_E1F)
            func_80059AA8(0, ((D_8009AF88[0xA1] >> 1) ^ 1) & 1);
    } else if (!slots[1].field_E1F) {
        func_80059AEC(1);
        func_8007EF84(D_80011540, slots[1].field_DF8, slots[1].field_E14);
        if (slots[1].field_E14 == 255) {
            if (!((D_8009B0F4_abs & 0x2000030) | D_8009B134_abs))
                func_80056504(1, -1, -1, -1, -1, -1, 0);
        } else {
            func_80056828(1);
        }
        if (D_800F2C40[1].field_E1F)
            func_80059AA8(1, ((D_8009AF88[0xA1] >> 1) ^ 1) & 1);
    }
    if ((D_8009B3A4 & 0x100) && (D_8009B39A & 0x100))
        D_8009B008.display_enabled ^= 1;
    if (!D_8009B008.display_enabled)
        return 0;
    if (D_8009AF9A == -2) {
        s32 i = 0;
        s32 excluded;
        s32 value;

        while (1) {
            do {
                value = (func_8008E590() >> 8) % 722;
                excluded = 720;
            } while ((u32)value >= 722);
            if ((u32)(value - 300) >= 50 && (u32)(value - 650) >= 50 && value != excluded) {
                D_8009B488[i] = value;
                if ((u16)value != D_800F2C40[i].field_DF8) {
                    i++;
                    if (i >= 2)
                        break;
                }
            }
        }
        reload++;
        D_8009B488[2] = (func_8008E590() >> 8) % 7;
    }
    if (D_8009B398 & 0x10)
        reload++;
    if (D_8009B394 & 0x900) {
        if (D_8009B394 & 0x100)
            D_8009B488[2] = ((u16)D_8009B488[2] + 6) % 7;
        else
            D_8009B488[2] = ((u16)D_8009B488[2] + 8) % 7;
    }
    if (D_8009B394 & 0xA000) {
        if (D_8009B394 & 0x8000)
            D_8009AFA1 = (D_8009AFA1 + 5) % 6;
        else
            D_8009AFA1 = (D_8009AFA1 + 7) % 6;
    }
    if (D_8009B3A4 & 0x80) {
        if (D_8009B394 & 0x5000) {
            if (D_8009B394 & 0x1000)
                D_8009B004.halfwords[1] -= 10;
            else
                D_8009B004.halfwords[1] += 10;
            if (D_800F2C40[2].field_E1F) {
                ModelSlot *stage = D_800F2C40;
                s32 height;

                stage += 2;
                height = D_8009B004.fields.height;
                if (stage->field_D18) {
                    stage->field_D18->rot.vx = 0;
                    stage->field_D18->rot.vy = 0;
                    stage->field_D18->rot.vz = 0;
                    stage->field_D18->matrix.t[0] = 0;
                    stage->field_D18->matrix.t[1] = height;
                    stage->field_D18->matrix.t[2] = 0;
                }
                func_8005922C(stage->field_D18, 0);
            }
        }
    } else if (D_8009B394 & 0x5000) {
        s32 side = D_8009AFA1 >= 3u;
        u16 *number = (u16 *)&D_8009B488[side];
        s32 digits[3] = {
            (u16)((u16)(*number / 100u) % 10u),
            (u16)((u16)(*number / 10u) % 10u),
            (u16)(*number % 10u)
        };

        if (D_8009B394 & 0x1000) {
            digits[(u8)(D_8009AFA1 % 3u)] =
                (digits[(u8)(D_8009AFA1 % 3u)] + 11) % 10;
        } else {
            digits[(u8)(D_8009AFA1 % 3u)] =
                (digits[(u8)(D_8009AFA1 % 3u)] + 9) % 10;
        }
        D_8009B488[side] = 100 * digits[0] + 10 * digits[1] + digits[2];
    }
    if (D_8009B398 & 4)
        D_8009B48E[0] ^= 1;
    if (D_8009B398 & 1)
        D_8009B490[0] ^= 1;
    if (D_8009B398 & 8)
        D_8009B48E[1] ^= 1;
    if (D_8009B398 & 2)
        D_8009B490[1] ^= 1;
    func_8007EF84(D_8009B01C, D_8009AFA1 == 0 ?
        selected : normal, (u16)((u16)((u16)D_8009B488[0] / 100u) % 10u));
    func_8007EF84(D_8009B01C, D_8009AFA1 == 1 ?
        selected : normal, (u16)((u16)((u16)D_8009B488[0] / 10u) % 10u));
    func_8007EF84(D_8009B01C, D_8009AFA1 == 2 ?
        selected : normal, (u16)((u16)D_8009B488[0] % 10u));
    func_8007EF84(normal);
    func_8007EF84(D_80011554, D_8009B48E[0], D_8009B490[0]);
    func_8007EF84(D_8009B024);
    func_8007EF84(D_8009B01C, D_8009AFA1 == 3 ?
        selected : normal, (u16)((u16)((u16)D_8009B488[1] / 100u) % 10u));
    func_8007EF84(D_8009B01C, D_8009AFA1 == 4 ?
        selected : normal, (u16)((u16)((u16)D_8009B488[1] / 10u) % 10u));
    func_8007EF84(D_8009B01C, D_8009AFA1 == 5 ?
        selected : normal, (u16)((u16)D_8009B488[1] % 10u));
    func_8007EF84(normal);
    func_8007EF84(D_80011554, D_8009B48E[1], D_8009B490[1]);
    func_8007EF84(D_8009B02C);
    func_8007EF84(D_80011564, (u16)D_8009B488[2], D_8009B004.fields.height);
    if (reload) {
        func_800137E4();
        func_800533D8();
        func_80053248(0, (u16)D_8009B488[0], -1, -1,
            D_8009B48E[0], D_8009B490[0]);
        func_80053248(1, (u16)D_8009B488[1], -1, -1,
            D_8009B48E[1], D_8009B490[1]);
        func_80053248(2, (u16)D_8009B488[2]);
    }
    return 0;
}
