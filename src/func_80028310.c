#define D_8009B254_IS_SCALAR
#include "common.h"
s32 func_800282E8(void);
void func_80039794(void);
s32 func_8003B734(void);

void func_80028310(void) {
    u8 *p;
    u16 f;

    if (func_800282E8() == 0) {
        func_80035BE4(0, D_8009B244, 0x10, 0xB0, 0x120, 0x30);
        return;
    }
    func_80039794();
    p = (u8 *)D_800EB0F8;
    if ((D_8009B248 & 0x40) == 0) {
        f = *(u16 *)(p + 0x34);
        if ((f & 0x2000) == 0) {
            return;
        }
        if ((f & 0x10) == 0) {
            *(u8 **)(p + 0x30) = func_800374F4(p);
            D_8009B248 |= 0x40;
            return;
        }
    } else {
        if (func_8003B734() == 0) {
            return;
        }
        func_8003FEE0(0xB);
    }
    func_80035B7C(p);
    D_8009B254 |= 0x40;
}
