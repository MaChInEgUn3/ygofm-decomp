/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8004ADE8.c, profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern unsigned long func_80076820 (long on_off, unsigned long voice_bit);
extern unsigned long func_80076B10 (void);
extern void func_80077120 (SpuVoiceAttr *attr);
extern u8 *D_8009B458;
extern s32 D_80011434[20];
s32 func_8004A854(s32 value);
s32 func_8004A940(s32 value, s32 variant);
s32 func_80049FB4(s32 note_high, s32 note_low, s32 base, s32 offset);
void func_8004A0FC(SDSecondaryObject *object,
                                 SDSecondaryRecord *channel);
s32 func_8004A3BC(SDSecondaryObject *entry, s32 value);
void func_8004ADE8(s32 channel, s32 note, s32 velocity);
void func_8004ADE8(arg0, arg1, velocity)
s32 arg0;
s32 arg1;
u8 velocity;
{
    s32 channel;
    s32 note;
    u8 *prog;
    s32 used;
    u8 program;
    u8 *vab;
    u8 *rec;
    s32 ch;
    u32 tidx;
    u32 key;
    u8 *hdr;
    u8 *tone;
    u8 *obj;
    s32 idx;
    s32 i;
    s32 sum;
    s16 vag;
    u16 *sizes;
    u8 stolen;
    s32 level;
    s32 pitch;
    s32 amode;
    s32 *voice;
    s32 vm;
    s32 soff;
    s32 vi;
    u16 adsr1;
    u16 adsr2;
    u8 tr;
    s32 nb;
    u8 td;

    channel = arg0;
    note = arg1;
    hdr = *(u8 **)(D_8009B458 + 0x4A8);
    rec = D_8009B458 + (channel & 0xFF) * 0x18 ;
    program = rec[0];
    vab = hdr;
    used = 0;
    i = 0;
    if (program != 0) {
        do {
            if (vab[i * 0x10 + 0x20] != 0) {
                used++;
            }
            i++;
        } while (i < program);
    }
    prog = &vab[program * 0x10 + 0x20];
    if (prog[0] == 0) {
        return;
    }
    tidx = 0;
    key = note;
    key = key & 0xFF;
    ch = channel & 0xFF;
    do {
        level = note & 0x7F;
        tone = &vab[(used * 16 + (tidx & 0xFFFF)) * 32 + 0x820];
        if (key < tone[6]) {
            goto next;
        }
        if (tone[7] < key) {
            goto next;
        }
        {
            u32 limit = rec[6] & 0xF0;

            stolen = 0;
            if (limit != 0) {
                if ((rec[6] & 0xF) >= (limit >> 4)) {
                    idx = func_8004A854(ch);
                    if (idx == -1) {
                        idx = func_8004A940(ch, key);
                        goto have;
                    }
                    stolen = 1;
                    goto have;
                }
            }
        }
        do {
            do {
                idx = func_8004A940(channel & 0xFF, key);
            } while (0);
        } while (0);
    have:
        if (idx == -1) {
            goto next;
        }
        i = 0;
        sum = 0;
        vag = *(s16 *)(tone + 0x16);
        sizes = (u16 *)(*(u8 **)(D_8009B458 + 0x4A8)
                        + (*(u16 *)(hdr + 0x12)) * 512 + 0x820);
        obj = &D_8009B458[idx * 0x28  + 0x180];
        if (vag > 0) {
            do {
                sum = sum + sizes[i];
                i++;
            } while (i < vag);
        }
        sum = sum + sum * 7;
        voice = &D_80011434[idx];
        vm = *voice;
        *(s32 *)(D_8009B458 + 0x4C4) = 0x6019F;
        *(s16 *)(D_8009B458 + 0x4CC) = 0;
        *(s16 *)(D_8009B458 + 0x4CE) = 0;
        nb = *(s32 *)(D_8009B458 + 0x4B8);
        *(s32 *)(D_8009B458 + 0x4C0) = vm;
        *(s32 *)(D_8009B458 + 0x4DC) = nb + sum;
        adsr1 = *(u16 *)(tone + 0x10);
        *(s16 *)(D_8009B458 + 0x4FA) = adsr1;
        *(u16 *)(obj + 0x20) = adsr1;
        adsr2 = *(u16 *)(tone + 0x12);
        *(s16 *)(D_8009B458 + 0x4FC) = adsr2;
        *(u16 *)(obj + 0x22) = adsr2;
        if ((*(u16 *)(tone + 0x10) & 0x80) == 0) {
            amode = 1;
            *(s32 *)(D_8009B458 + 0x4E4) = amode;
        } else {
            amode = 5;
            *(s32 *)(D_8009B458 + 0x4E4) = amode;
        }
        *(u16 *)(obj + 0x24) = *(u16 *)(D_8009B458 + 0x4E4);
        rec[4] = velocity;
        obj[0x12] = tone[4];
        obj[0x13] = tone[5];
        soff = idx * 0x28  + 0x180;
        obj[0x11] = tone[0xC];
        td = tone[0xD];
        obj[0] = idx;
        obj[2] = program;
        obj[4] = tidx;
        obj[6] = obj[5] = level;
        obj[3] = channel;
        obj[0xD] = 1;
        obj[0x10] = td;
        ((SDSecondaryObject *)obj)->field_0008 = prog[1];
        ((SDSecondaryObject *)obj)->field_000A = prog[4];
        ((SDSecondaryObject *)obj)->field_0009 = tone[2];
        tr = tone[3];
        ((SDSecondaryObject *)obj)->field_000E = velocity;
        *(u16 *)(obj + 0x1E) = 0xFFFF;
        ((SDSecondaryObject *)obj)->field_000B = tr;
        func_8004A0FC(
            (SDSecondaryObject *)(D_8009B458 + soff),
            (SDSecondaryRecord *)(D_8009B458 + ch * 0x18 ));
        *(s16 *)(D_8009B458 + 0x4C8) =
            (((SDSecondaryObject *)obj)->level_left *
             *(u16 *)(D_8009B458 + 0x514)) >> 7;
        *(s16 *)(D_8009B458 + 0x4CA) =
            (((SDSecondaryObject *)obj)->level_right *
             *(u16 *)(D_8009B458 + 0x516)) >> 7;
        obj[5] = level;
        *(s16 *)(obj + 0x1C) = rec[7];
        *(s16 *)(obj + 0x1A) = -1;
        pitch = func_8004A3BC((SDSecondaryObject *)obj, rec[7]) + obj[6] * 128;
        vi = idx;
        *(s16 *)(D_8009B458 + 0x4D4) =
            func_80049FB4((s16)pitch >> 7, pitch & 0x7F, tone[4], tone[5]);
        func_80077120((SpuVoiceAttr *)(D_8009B458 + 0x4C0));
        if (stolen == 0) {
            if ((rec[6] & 0xF) < 0xF) {
                rec[6] = rec[6] + 1;
            }
        }
        obj[0xF] = 1;
        if (rec[0x10] == 0) {
            if ((tone[1] & 4) != 0) {
                s32 *m = &D_80011434[vi];
                do {
                    func_80076820(1 , *m);
                } while ((func_80076B10() & *m) == 0);
            } else {
                s32 *m = &D_80011434[vi];
                do {
                    func_80076820(0 , *m);
                } while ((func_80076B10() & *m) != 0);
            }
        } else if (rec[0x10] != 1) {
            s32 *m = &D_80011434[vi];
            do {
                func_80076820(1 , *m);
            } while ((func_80076B10() & *m) == 0);
        } else {
            s32 *m = &D_80011434[vi];
            do {
                func_80076820(0 , *m);
            } while ((func_80076B10() & *m) != 0);
        }
    next:
        tidx++;
    } while ((tidx & 0xFFFF) < prog[0]);
}
