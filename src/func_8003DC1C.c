/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8003DC1C.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern int func_8007EF84();
extern int func_8008E870(const char *fmt, ...);
s32 func_8004413C(s32 channel);
s32 func_800441DC(s32 channel, s32 name, s32 buffer, s32 offset, s32 size);
s32 func_800442E4(s32 channel, s32 name, s32 buffer, s32 offset, s32 size);
s32 func_80044278(s32 channel, s32 buffer, s32 sector);
s32 func_80044380(s32 channel, s32 buffer, s32 sector);
s32 func_800443EC(s32 channel, s32 name, s32 blocks);
s32 func_80044838(s32 mode, s32 *request, s32 *result);
extern u8 D_80010384[];
s32 func_80044CD4(u8 *name);
extern struct DIRENTRY *D_8009B444 __attribute__((section(".data")));
extern s32 D_8009B440 __attribute__((section(".data")));
extern s32 D_8009B438 __attribute__((section(".data")));
extern MemCardWorkArea D_800EF6D0;
extern u16 D_8009B3CC;
extern u8 D_8009B3CF;
extern u8 D_8009B3DD;
extern u8 D_8009B3D5;
extern s32 D_8009B3C8;
extern s32 D_8009B3E4;
extern void (*D_80090F88[5 ])(
    MemCardWorkRoot *root, MemCardWorkSlot *slot
);
extern u8 D_8021007A __attribute__((section(".data")));
extern u8 D_8021007B __attribute__((section(".data")));
extern u8 D_8021007C __attribute__((section(".data")));
extern u8 D_8021007D __attribute__((section(".data")));
extern u8 D_8021007E __attribute__((section(".data")));
extern u8 D_8021007F __attribute__((section(".data")));
extern char D_8009AF6C[];
extern char D_80010378[];
extern char D_80010398[];
extern char D_800103A4[];
void func_8003DC1C(void);
void func_80043E30(long val);
void func_80043EBC(void);
extern DuelEffectChannel D_800EB0F8[4 ];
extern u8 D_8009B3C1;
extern u8 D_8009B3C7;
DuelEffectChannel *func_8003D46C(s32 value, s32 set_flags);
extern s8 D_8009B34D __attribute__((section(".data")));
void func_80039794(void);
void func_800356A0(u8 *destination, u8 *source, u32 length);
void func_80035748(u8 *destination, s32 value, u32 length);
extern u8 D_801D4000[];
void func_8003DC1C(void)
{
    MemCardWorkRoot *root = &D_800EF6D0.root;
    MemCardWorkSlot *slot = &D_800EF6D0.slots[D_8009B3DD];
    s32 zero = 0;
    s32 status;
    s32 index;
    s32 offset;
    s32 remaining;
    u8 *cursor;
    s32 message;
    s32 checksum;
    u8 *name;

    if (D_8009B3CC & 0x2000) {
        index = zero;
        if (index < D_8009B440) {
            do {
                func_8007EF84(D_8009AF6C, &D_8009B444[index]);
                index++;
            } while (index < D_8009B440);
        }
        func_8007EF84(D_80010378, slot->free_blocks);
    }
    status = -1;
    if (D_8009B3CC & 0x4000)
        status = func_80044838(1, &D_8009B3E4, &D_8009B3C8);
    if ((D_8009B3CC & 0x1000) && status != 0 && status == 1) {
        switch (D_8009B3E4) {
        case 2:
            D_8009B3CC |= 0x2000;
            switch (D_8009B3C8) {
            case 3:
                D_8009B3CC |= 0x800;
            case 0:
                slot->free_blocks = (u8)D_8009B438;
                goto success;
            case 4:
                D_8009B3CC |= 2;
                D_8009B3D5 = 1;
                break;
            case 1:
            default:
                D_8009B3D5 = 2;
                break;
            }
            break;
        case 3:
            if (D_8009B3C8 == 0) {
                index = root->chunk;
                remaining = (u16)root->remaining - index;
                root->remaining = remaining;
                if ((s32)((u32)remaining << 16) > 0) {
                    slot->cursor += index;
                    root->offset += index;
                    if (root->remaining < root->chunk)
                        root->chunk = (u16)root->remaining;
                } else {
                    D_8009B3D5 = 0;
                }
            } else {
                D_8009B3D5 = 1;
            }
            break;
        case 4:
            if (D_8009B3C8 == 0) {
                index = root->chunk;
                remaining = (u16)root->remaining - index;
                root->remaining = remaining;
                if ((s32)((u32)remaining << 16) > 0) {
                    slot->cursor += index;
                    root->offset += index;
                    if (root->remaining < root->chunk)
                        root->chunk = (u16)root->remaining;
                } else {
                    D_8009B3D5 = 0;
                }
            } else {
                D_8009B3D5 = 1;
            }
            break;
        case 8:
        case 11:
        case 12:
            D_8009B3D5 = 1;
            if (D_8009B3C8)
                break;
success:
            D_8009B3D5 = 0;
            break;
        }
    }
    if (D_8009B3C1 & 0xF) {
        status = 1;
        D_80090F88[D_8009B3C1 & 0xF](root, slot);
    }
    if (status >= 0)
        return;
    if (D_8009B3CC & 0x400) {
        DuelEffectChannel *text = &D_800EB0F8[root->text_index];
        func_80039794();
        if ((*(u32 *)&text->flags_34 & 0x2008) == 0x2000)
            D_8009B3CC &= ~0x400;
        return;
    }
    switch (D_8009B3CF & 0xF) {
    case 0:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            D_8009B3C1 = 1;
            break;
        }
        if (D_8009B34D) {
            D_8009B3C1 = 2;
            break;
        }
        func_80043E30(1);
        func_80043EBC();
        D_8009B3CF = 1;
        D_8009B3CC |= 0x4000;
    case 1:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            D_8009B3CC |= 0x1000;
            func_8004413C(zero);
            break;
        }
        D_8009B3CF = 4;
    case 4:
        if (!(D_8009B3CC & 0x2000))
            break;
        D_8009B3CC &= ~0x1000;
        if (D_8009B3D5 == 2) {
            message = 0xD2;
            goto show_message;
        }
        if (!(D_8009B3C7 & 1))
            D_8009B3CF = 5;
        else
            D_8009B3CF = 7;
        break;
    case 5:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            index = func_80044CD4(D_80010384);
            if (index < 0 || (D_8009B3CC & 2)) {
                message = 0xD3;
                goto show_message;
            }
            func_80044278(zero, 0x80210000 ,
                D_8009B444[index].head / 64);
            break;
        }
        if (D_8009B3D5) {
            message = 0xD8;
            goto show_message;
        }
        D_8009B3CF = 6;
    case 6:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            name = D_80010384;
            index = func_80044CD4(name);
            message = 0xD3;
            if (index < 0 || (D_8009B3CC & 2))
                goto show_message;
            func_8003D46C(0x80D5, 0);
            slot->entry_index = index;
            D_8009B3CC |= 0x1000;
            func_800441DC(
                zero,
                (s32)name,
                0x80200000 ,
                0x200 ,
                8192  - 0x200 
            );
            break;
        }
        message = 0xD7;
        if (D_8009B3D5 == 1)
            message = 0xD8;
        goto show_message;
    case 7: {
        s32 wait;
        s32 result;
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            if (D_8009B3CC & 2) {
                D_8009B3CF = 9;
                break;
            }
            name = D_80010384;
            if (func_80044CD4(name) < 0) {
                D_8009B3CF = 10;
                break;
            }
            func_8003D46C(0x80D6, 0);
            func_800356A0(
                (u8 *)0x80300000 ,
                D_801D4000,
                0x200 
            );
            func_80035748(
                (u8 *)0x80300200 ,
                0x86,
                (1 << 11 ) 
            );
            func_800442E4(
                zero,
                (s32)name,
                0x80300000 ,
                0,
                0x200  + (1 << 11 ) 
            );
            D_8009B3CC |= 0x1000;
            break;
        }
        result = D_8009B3D5;
        if (result == 1) {
            message = 0xD9;
            wait = result;
        } else {
            message = 0xD7;
            wait = 1;
            D_8009B3CF = 8;
        }
        func_8003D46C(message, wait);
        remaining = D_8009B3CC | 0x400;
        D_8009B3CC = remaining;
        remaining = 8;
        D_8009B3CF = remaining;
    }
    case 8:
        if (!(D_8009B3CF & 0x80)) {
            s32 i;
            s32 sector;
            D_8009B3CF |= 0x80;
            index = func_80044CD4(D_80010384);
            checksum = 0;
            i = 0;
            D_8021007E = 1;
            D_8021007D = 255;
            D_8021007C = 255;
            D_8021007B = 255;
            D_8021007A = 255;
            do {
                checksum ^= (*(u8 (*)[128 ])0x80210000 ) [i];
                i++;
            } while (i < 0x7F);
            sector = D_8009B444[index].head;
            D_8021007F = checksum;
            if (sector < 0)
                sector += 63;
            func_80044380(zero, 0x80210000 , sector >> 6);
            break;
        }
        if (!D_8009B3D5)
            break;
        message = 0xD9;
show_message:
        func_8003D46C(message, 1);
        D_8009B3CC |= 0x400;
        break;
    case 9:
    case 10:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            if (slot->free_blocks >= root->blocks)
                func_800443EC(zero, (s32)D_80010384, root->blocks);
            break;
        }
        if (!D_8009B3D5)
            func_8008E870(D_80010398);
        func_8008E870(D_800103A4);
        break;
    }
}
