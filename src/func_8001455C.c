/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80014294.c (File_StepActiveTransfer), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_8001455C(void)
{
    FileTransferDescriptor *p;
    void (*cb)(void);
    void (*cb2)(void);
    u8 *q;
    s32 n;
    s32 m;

    p = &D_800E9E60;
    if (D_8009B0F4 & 0x1000 ) {
        if (!(D_8009B0F4 & 0x800 )) {
            if (func_8007B1F4(0x10, 0, (DslCB)func_80014390, 0) > 0) {
                D_8009B0F4 =
                    D_8009B0F4 | 0x800 ;
            }
        }
    }
    if (D_8009B0F4 & 0x400 ) {
        return;
    }
    if (D_8009B0F4 & 0x80000 ) {
        if (!(D_8009B112 & 0x8000)) {
            D_8009B112 = D_8009B112 | 0x8000;
            if ((D_8009B112 & 3) == 0) {
                D_8009B112 = 0;
                goto call_144B8;
            }
            if (!(D_8009B112 & 0x2000)) {
                D_8009B100 = 0;
            }
            if (D_8009B112 & 2) {
                D_8009B112 = D_8009B112 & 0xFFFE;
            } else {
                p->field_30.word = 0;
            }
        }
        switch (D_8009B100) {
        case 0:
            D_8009B112 = D_8009B112 | 0x2000;
            D_8009B100 = 1;
        case 1:
            if (func_8007B1F4(9, 0, (DslCB)func_80014220, -1) <= 0) {
                return;
            }
            D_8009B0F4 = D_8009B0F4 | 0x400 ;
            cb = D_8009B120;
            goto call_back;
        case 2:
            D_8009B112 = D_8009B112 & 0xDFFF;
            if (D_8009B112 & 1) {
                goto set_state3;
            }
            D_8009B112 = 0;
call_144B8:
            func_800144B8();
            return;
set_state3:
            D_8009B100 = 3;
        case 3:
            D_8009B112 = D_8009B112 | 0x1000;
            q = &D_8009B11C_byte + 1;
             

            *q = ((u8 *)&p->callback_data)[0];
            q[-1] = ((u8 *)&p->callback_data)[1];
            if (func_8007B1F4(0xD, (u8 *)(q - 1), (DslCB)func_80014294, -1) <= 0) {
                return;
            }
            D_8009B0F4 = D_8009B0F4 | 0x400 ;
            return;
        case 4:
            func_8007E600(
                p->absolute_lba, ((CdlLOC *)( D_8009B104 )) 
            );
            if (func_8007B468(
                    0x4A, ((DslLOC *)( D_8009B104 )) , 0x1B,
                    (DslCB)func_80014308, -1) <= 0) {
                return;
            }
            D_8009B0F4 = D_8009B0F4 | 0x400 ;
            return;
        case 5:
            D_8009B100 = 6;
            D_8009B0EC = 0x258;
            D_8009B112 = D_8009B112 & 0xEFFF;
            D_8009B112 = D_8009B112 | 0x4000;
            cb2 = D_8009B0F0;
            if (cb2 != 0) {
                cb2();
            }
        case 6:
            D_8009B0EC = D_8009B0EC - 1;
            if ((s16)D_8009B0EC > 0) {
                if ((s32)p->field_30.word < p->direct_destination) {
                    return;
                }
            }
            D_8009B112 = D_8009B112 & 0x3FFC;
            cb = D_8009B120;
            D_8009B112 = D_8009B112 | 2;
call_back:
            if (cb != 0) {
                cb();
            }
        }
        return;
    }
    if (p->done == 5) {
        switch (p->substate) {
        case 0:
            func_8007DDD4();
            func_8007E860(0);
            if (func_8007B1F4(9, 0, (DslCB)func_800141A8, -1) <= 0) {
                return;
            }
            D_8009B0F4 = D_8009B0F4 | 0x400 ;
            return;
        case 1:
            func_8007DDD4();
            func_8007E860(0);
            goto call_144B8;
        }
        return;
    }
    if (D_8009B0F4 & 0x80) {
        if (D_8009B0F4 & 0x100) {
            return;
        }
        goto call_144B8;
    }
    func_8007E600(p->absolute_lba, ((CdlLOC *)( D_8009B104 )) );
    if (D_8009B0F4 & 0x100000) {
        if ((s32)D_8009B0F4 < 0) {
            goto call_144B8;
        }
        if (func_8007B468(
                0xA0, ((DslLOC *)( D_8009B104 )) , 0x15,
                (DslCB)func_80014134, -1) <= 0) {
            return;
        }
        D_8009B0F4 = D_8009B0F4 | 0x480;
        return;
    }
    if (!(D_8009B0F4 & 0x800000)) {
        D_8009B0F4 = D_8009B0F4 | 0x800000;
        if (p->phase_callback != 0) {
            p->phase_callback(p, p->result++);
        }
        p->phase_remaining = p->phase_size;
        return;
    }
    if (D_8009B0F4 & 0x400000) {
        if (func_80077240(0) == 0) {
            return;
        }
        D_8009B0F4 = D_8009B0F4 & 0xFFBFFFFF;
    }
    if ((s32)D_8009B0F4 >= 0) {
        if (func_8007B468(
                0xA0, ((DslLOC *)( D_8009B104 )) , 6,
                (DslCB)func_800140A0, -1) == 0) {
            return;
        }
        D_8009B0F4 = D_8009B0F4 | 0x400 ;
    }
    D_8009B0F4 = D_8009B0F4 | 0x180;
}
