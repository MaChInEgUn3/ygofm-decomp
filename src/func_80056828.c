/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_load_step.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
int func_80074170(int mode);
extern int func_8008E870(const char *fmt, ...);
extern ModelSlot D_800F2C40[3 ];
extern u8 D_8009AFA0;
extern u8 *D_80010000 __attribute__((section(".data")));
extern u8 *D_80010004 __attribute__((section(".data")));
extern s32 D_80010008 __attribute__((section(".data")));
extern u8 *D_8001000C __attribute__((section(".data")));
extern u8 *D_80010010 __attribute__((section(".data")));
void func_8004CB0C(s32 slot, u8 *hmd, s32 size, s32 flags);
void func_8004D75C(s32 slot);
void func_8004D914(s32 slot);
void func_800590DC(s32 index);
void func_8005A468(s32 index, s32 speed);
void func_8005A4C4(ModelSlot *record, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_800582C0(s32 side, s32 tint, s32 level);
void func_8005F198(s32 value);
void func_8004DC38(ModelSlot *slot, s32 i, s32 n, u32 pos);
void func_80048D08(s32 side, u32 *src);
extern u8 D_801A8000[];
extern char D_80011594[];
void func_80056828(s32 index);
static inline s16 load_phase(ModelSlot *slot)
{
    return slot->field_E14;
}
void func_80056828(s32 index)
{
    ModelSlot *slot = &D_800F2C40[index];
    s32 started = func_80074170(1);
    s32 state = slot->field_E14;
    s32 work;
    s32 amount;
    s32 offset;

    if (state == 0 || state == 255) {
        return;
    }
    switch (load_phase(slot)) {
    case 1: {
        u8 *payload = (u8 *)D_80010008;
        s32 size = 0xC000;
        switch (index) {
        case 0:
            payload = D_80010000;
            break;
        case 1:
            payload = D_80010004;
            break;
        }
        if (*(s32 *)payload != 0) {
            size = *(s32 *)payload;
        }
        func_8004CB0C(index, payload, size, -1);
        break;
    }
    case 2:
        func_8004D75C(index);
        break;
    case 3:
        func_8004D914(index);
        break;
    case 4: {
        ModelSlot *p = &D_800F2C40[index];
        s32 sum = 0;
        s32 i, count, byte, missing;
        if (index < 2) {
            i = sum;
            if (sum < p->field_E1B) {
                missing = 0xFFFF;
                count = p->field_E1B;
                do {
                    if (p->field_2C8[1][i] != missing) {
                        byte = i / 8;
                        if ((p->field_BEC[byte] >> (i - byte * 8)) & 1) {
                            sum += 0x14;
                        } else {
                            sum += 0xC;
                        }
                    }
                    i++;
                } while (i < count);
            }
        }
        amount = (p->field_DF0 = (s32)p->field_DE0 + sum);
        p->field_DF4 = amount + p->field_E02 * 4;
        func_8005A4C4(p, 0, 0, 0, index == 1 ? 0x800 : 0);
        break;
    }
    case 5: {
        ModelSlot *p = &D_800F2C40[index];
        ModelSlotPart **part = p->field_1E0;
        s32 i;
        for (i = 0; i < p->field_E1B; i++) {
            (*part)->ii = 0xFFFF;
            (*part)->ti = (*part)->start;
            (*part)->aframe = 0xFFFF;
            (*part)->sid = (*part)->start_sid;
            (*part)->rframe = 0;
            (*part)->speed = 0x10;
            part++;
        }
        break;
    }
    case 6:
        slot->field_E1F = 1;
        func_800590DC(index);
        slot->field_E1F = 0;
        break;
    case 7: {
        ModelSlot *p = &D_800F2C40[index];
        amount = p->field_E0D * 2;
        offset = amount;
        switch (p->field_E16) {
        case 0x23:
            offset = 0;
            func_8005A468(index, offset);
            break;
        case 0x3E:
            offset = amount;
            func_8005A468(index, offset);
            break;
        case 0x3C:
            offset = -offset;
            func_8005A468(index, offset);
            break;
        }
        if (index >= 2) {
            slot->field_E1F = 1;
        }
        break;
    }
    case 8:
        func_800582C0(index, slot->field_E0C, slot->field_E0A);
        break;
    case 9: {
        ModelSlot *p = &D_800F2C40[index];
        u8 *context;
        ModelControlHandler handler;
        s32 selected;
        s32 position;
        s32 i;
        work = ((ModelControlCommandView *)p)->commands[2];
        context = (u8 *)p->field_DE8;
        D_8009AFA0 = index;
        if (work >= 0) {
            if (index != 0) {
                handler = (ModelControlHandler)(D_80010010 + 4);
            } else {
                handler = (ModelControlHandler)(D_8001000C + 4);
            }
            func_8005F198(1);
            handler(context, ((ModelControlCommandView *)p)->commands[2] % 1000);
            func_8005F198(0);
        }
        selected = p->field_BF5;
        p->field_E0E = 6;
        position = p->field_E06;
        for (i = 0; i < p->field_E1B; i++) {
            s32 current = p->field_BF5;
            if (selected != 0) {
                p->field_1E0[i]->sid = selected;
                current = selected;
            }
            func_8004DC38(p, i, current, position);
        }
        if (selected != 0) {
            p->field_BF5 = selected;
        }
        break;
    }
    case 10:
        if (slot->field_E1D == 0) {
            func_80048D08(
                index, (u32 *)(D_801A8000 + (index << 11))
            );
        }
        break;
    case 11:
        if (slot->field_E1D == 0) {
            slot->field_E1E = 1;
        }
        slot->field_E1F = 1;
        break;
    }
    work = func_80074170(1);
    func_8008E870(D_80011594, slot->field_E14, work - started);
    {
        s32 next;
        if (slot->field_E1F != 0) {
            next = 255;
        } else {
            next = slot->field_E14 + 1;
        }
        slot->field_E14 = next;
    }
}
