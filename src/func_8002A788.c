#define FUNC_8002A6B8_ARG
#define D_8009B3A4_IS_VOLATILE
#define D_8009B26C_SIZED
#define D_8009B269_SIZED
#include "common.h"

void func_8002A788(u8 *p) {
    s32 v;
    s32 x;
    s32 y;
    s32 sp;
    s32 d;

    if (func_8002A3CC() == 0) {
        if ((D_8009B398 & 0x40) != 0) {
            v = func_8002A6B8(p);
            if ((func_80029EB0(p, v) & 0x80) != 0) {
                *(s16 *)(p + 6) = v;
                p[0] = 2;
                return;
            }
        }
        if ((D_8009B398 & 0x20) != 0) {
            D_8009B26C[0] = D_8009B269[0];
            return;
        }
        if ((D_8009B3A4 & 0xF00C) != 0) {
            x = *(s8 *)&D_8009B258;
            y = *(s8 *)&D_8009B259;
            sp = 6;
            if ((D_8009B3A4 & 0x80) != 0) {
                sp = 2;
            }
            if ((D_8009B3A4 & 0xC) != 0) {
                if ((D_8009B3A4 & 8) != 0) {
                    y += 0xA;
                    if (y >= 0x28) {
                        y = 0x27;
                    }
                } else {
                    y -= 0xA;
                    if (y < 0) {
                        y = 0;
                    }
                }
                d = y - *(s8 *)&D_8009B259;
                if (d >= 0) {
                    sp = d * 2;
                } else {
                    sp = (*(s8 *)&D_8009B259 - y) * 2;
                }
            } else {
                if ((D_8009B3A4 & 0xA000) != 0) {
                    if ((D_8009B3A4 & 0x2000) != 0) {
                        x += 1;
                        if (x >= 0x14) {
                            x = 0x13;
                            if (y < 0x27) {
                                x = 0;
                                y += 1;
                                goto quad;
                            }
                        }
                    } else {
                        x -= 1;
                        if (x < 0) {
                            x = 0;
                            if (y != 0) {
                                x = 0x13;
                                y -= 1;
quad:
                                sp *= 4;
                            }
                        }
                    }
                }
                if ((D_8009B3A4 & 0x5000) != 0) {
                    if ((D_8009B3A4 & 0x4000) != 0) {
                        y += 1;
                        if (y >= 0x28) {
                            y = 0x27;
                        }
                    } else {
                        y -= 1;
                        if (y < 0) {
                            y = 0;
                        }
                    }
                }
            }
            func_8002A4A8(x, y, sp);
        }
    }
    func_8002A660(p);
}
