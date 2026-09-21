/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/mem_card_dialog_load_save.c (MemCardDialog_UpdateSave), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern s8 D_8009B34D __attribute__((section(".data")));
extern ;
void func_8003E854(void)
{
    s32 files;
    s32 needed;
    s32 result;
    s32 mode;
    s32 message;

    switch (D_8009B3EB & 0xF) {
    case 0:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 ;
            D_801D5648[0] = (D_8009B3F9 >> 4) + 1;
            func_8003E46C(0xC9, 0x20);
            break;
        }
        D_8009B3EB = 1;
        if (D_8009B34D != 0) {
            D_8009B3EB = 0xC;
            break;
        }
         
    case 1:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 ;
            func_8003E46C(0xD4, 0);
            do {
            } while (func_8008BC90(0) == 0);
            goto io_pending;
        }
        switch (D_8009B3F4) {
        case 0:
        case 3:
            D_8009B3EB = 3;
            break;
        case 4:
            D_8009B3EB = 4;
            if (D_8009B3FA & 0x100) {
                break;
            }
            if (D_8009B3D4 != 0) {
                break;
            }
            D_8009B3EB = 0xE;
            break;
        case 1:
            D_8009B3EB = 9;
            break;
        case 2:
            D_8009B3EB = 0xD;
            break;
        }
        break;
    case 2:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 ;
            D_8009B3EC = 3;
            break;
        }
        if ((D_8009B3EB & 0x40 ) == 0) {
            break;
        }
        func_8003E46C(0xB8, 0x18);
        break;
    case 3:
        if (func_8008CA78(0, (char *)D_8009AF70,
                               (struct DIRENTRY *)D_800EFBC0, (long *)&files, 0,
                               15 ) != 0) {
            D_8009B3EB = 0xD;
            break;
        }
        if (func_80044598(D_800EFE18, (struct DIRENTRY *)D_800EFBC0, files) >= 0) {
            D_8009B3EB = 7;
            break;
        }
        if ((D_8009B3FA & 0x100) == 0 && D_8009B3D4 == 0) {
            D_8009B3EB = 0xE;
            break;
        }
        message = func_80044544((struct DIRENTRY *)D_800EFBC0, files);
        needed = D_8009B3DC;
        if (message >= needed) {
            D_8009B3EB = 6;
            goto create;
        }
        D_801D5608[0].blocks.used = 15  - message;
        D_801D5608[0].blocks.needed = needed;
        func_8003E46C(0xDB, 0x18);
        break;
    case 4:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 ;
            func_8003E46C(0xDE, 0x10);
            break;
        }
        if ((D_8009B3EB & 0x40 ) == 0) {
            D_8009B3EB |= 0x40 ;
            func_8003E46C(0xDF, 0x20);
            break;
        }
        if (D_8009B34D == 0) {
            D_8009B3EB = 0xC;
            break;
        }
        D_8009B3EB = 5;
        func_8003E46C(0xBE, 0);
        break;
    case 5:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 ;
            do {
            } while (func_8008BC90(0) == 0);
            goto io_pending;
        }
        if (D_8009B3F0 != 2) {
            break;
        }
        switch (D_8009B3F4) {
        case 0:
            func_8003E46C(0xC3, 0x18);
            break;
        case 3:
            func_8003E46C(0xC3, 0x18);
            break;
        case 2:
            D_8009B3EB = 0xD;
            break;
        case 4:
            if ((D_8009B3EB & 0x40 ) == 0) {
                D_8009B3EB |= 0x40 ;
                if (func_8008CF00(0) != 0) {
                    func_8003E46C(0xDD, 0x18);
                    break;
                }
                func_8003E46C(0xBF, 0x10);
                break;
            }
            D_8009B3EB = 1;
            break;
        case 1:
            D_8009B3EB = 9;
            break;
        }
        break;
    case 6:
    create:
        if (func_8008CE04(0, (char *)D_800EFE18, D_8009B3DC) != 0) {
            D_8009B3EB = 0xB;
            break;
        }
        if ((D_8009B3FA & 0x100) == 0) {
            D_8009B3C4 = 0;
            D_8009B3D0 -= 0x200 ;
            D_8009B3C2 += 0x200 ;
        }
        D_8009B3EB = 8;
        goto func_80073900;
    case 7:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 ;
            D_8009B3EC = 0;
            func_8008C638(0, (char *)D_800EFE18,
                            (unsigned long *)D_801DC000,
                            D_8009B3C4, 0x480);
            goto io_pending;
        }
        if ((D_8009B3EB & 0x40 ) == 0) {
            mode = D_8009B3F4;
            D_8009B3EB |= 0x40 ;
            if (mode != 0) {
                D_8009B3EB = 0xD;
                if (mode == 1) {
                    D_8009B3EB = 9;
                }
            } else {
                if (D_8009B3D4 != 0) {
                    goto message_cf;
                }
                if (func_8003D2B8(
                        (SaveDataState *)D_8009B3D0,
                        (SaveDataState *)D_801DC000) != 0) {
                    goto message_cf;
                }
                if (D_8009B3EC != 0) {
                    goto state_e;
                }
                D_8009B3EC++;
                D_8009B3EB &= ~0x40 ;
                func_8008C638(0, (char *)D_800EFE18,
                                (unsigned long *)D_801DC000,
                                D_8009B3C4 + 0x680 , 0x480);
                goto io_pending;
            }
            break;
        state_e:
            D_8009B3EB = 0xE;
            break;
        message_cf:
            func_8003E46C(0xCF, 0x20);
            break;
        }
        if (D_8009B34D == 0) {
            D_8009B3EB = 8;
            goto func_80073900;
        }
        D_8009B3EB = 0xC;
        break;
    case 8:
    func_80073900:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 ;
            func_8003E46C(0xD6, 0);
            func_8008C858(0, (char *)D_800EFE18,
                             (unsigned long *)D_8009B3D0,
                             D_8009B3C4,
                             D_8009B3C2);
        io_pending:
            D_8009B3FA |= 0x1000 ;
            break;
        }
        result = D_8009B3F4;
        if (result != 0) {
            D_8009B3EB = 0xB;
            if (result == 1) {
                D_8009B3EB = 9;
            }
            break;
        }
        D_8009B3EB = 0xA;
        break;
    case 9:
        func_8003E46C(0xD2, 0x18);
        break;
    case 10:
        D_8009B3EF = 1;
        message = 0xCC;
        if ((D_8009B3FA & 0x100) == 0) {
            message = 0xD1;
            D_8009B3D4 = 0;
            D_8009B3B8 = (s32)((u32)D_8009B3B8 + 1);
        }
        func_8003E46C(message, 0x18);
        break;
    case 11:
        func_8003E46C(0xD9, 0x18);
        break;
    case 12:
        func_8003E46C(0xCD, 0x18);
        D_8009B3EF = 3;
        break;
    case 13:
        func_8003E46C(0xDA, 0x18);
        break;
    case 14:
        func_8003E46C(0xCE, 0x18);
        break;
    }
}
