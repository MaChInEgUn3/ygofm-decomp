/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/mem_card_dialog_load_save.c (MemCardDialog_UpdateLoad), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern s8 D_8009B34D __attribute__((section(".data")));
void func_8003E490(void)
{
    s32 files;
    s32 message;

    switch (D_8009B3EB & 0xF) {
    case 0:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 ;
            func_8003E46C(0xC8, 0x20);
            break;
        }
        D_8009B3EB = 1;
        if (D_8009B34D != 0) {
            D_8009B3EB = 9;
            break;
        }
         
    case 1:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 ;
            D_801D5648[0] = (D_8009B3F9 >> 4) + 1;
            message = 0xD4;
            if ((D_8009B3FA & 0x200) != 0) {
                message = 0xC0;
            }
            func_8003E46C(message, 0);
            do {
            } while (func_8008BC90(D_8009B3F9) == 0);
            goto io_pending;
        }
        switch (D_8009B3F4) {
        case 0:
        case 3:
            D_8009B3EB = 2;
            break;
        case 1:
            D_8009B3EB = 5;
            break;
        case 2:
        case 4:
            D_8009B3EB = 6;
            break;
        }
        break;
    case 2:
        if (func_8008CA78(D_8009B3F9, (char *)D_800EFE18,
                               (struct DIRENTRY *)D_800EFBC0, (long *)&files, 0,
                               15 ) != 0) {
            D_8009B3EB = 6;
            break;
        }
        if (files == 0) {
            D_8009B3EB = 6;
            break;
        }
        D_8009B3EB = 3;
         
    case 3:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 ;
            func_8003E46C(0xD5, 0);
            func_8008C638(D_8009B3F9, (char *)D_800EFE18,
                            (unsigned long *)D_8009B3D0,
                            D_8009B3C4,
                            D_8009B3C2);
        io_pending:
            D_8009B3FA |= 0x1000 ;
            break;
        }
        switch (D_8009B3F4) {
        case 0:
            D_8009B3EB = 7;
            if (func_8003D174(D_8009B3D0) != 0) {
                break;
            }
            D_8009B3EB = 4;
            if ((D_8009B3FA & 0x400) != 0) {
                func_8003E46C(0xBD, 0x18);
                break;
            }
            D_8009B3FA |= 0x400;
            break;
        case 1:
            D_8009B3EB = 5;
            break;
        case 2:
        case 3:
            D_8009B3EB = 8;
            break;
        case 4:
            break;
        case 5:
            D_8009B3EB = 6;
            break;
        }
        break;
    case 4:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 ;
            func_8003E46C(0xBD, 0x10);
            break;
        }
        if ((D_8009B3EB & 0x40 ) == 0) {
            D_8009B3EB |= 0x40 ;
            func_8003E46C(0xBC, 0x20);
            break;
        }
        D_8009B3EB = 9;
        if (D_8009B34D != 0) {
            break;
        }
        D_8009B3EB = 3;
        D_8009B3C4 += 0x680 ;
        break;
    case 5:
        func_8003E46C(0xC1, 0x18);
        break;
    case 6:
        func_8003E46C(0xD3, 0x18);
        break;
    case 7:
        D_8009B3EF = 1;
        if ((D_8009B3FA & 0x200) != 0) {
            func_8003E46C(0xD0, 8);
            break;
        }
        D_8009B3D4 = 0;
        func_8003E46C(0xD0, 0x18);
        break;
    case 8:
        func_8003E46C(0xD3, 0x18);
        break;
    case 9:
        D_8009B3EF = 3;
        func_8003E46C(0xC7, 0x18);
        break;
    }
}
