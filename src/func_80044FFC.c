#include "common.h"

void func_80044FFC(s32 arg0, s32 arg1, s32 arg2) {
    Msg30 m;

    m.kind = 0x29;
    m.unk8 = (s16)arg0;
    m.unk2 = arg1 & 0xFF;
    m.unk1 = arg2;
    func_80045BE8(&m);
}
