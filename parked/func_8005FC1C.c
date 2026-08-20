#include "common.h"

void func_80069E44(void);
void func_80069F94(void);
void func_8006A0E8(void);
void func_8006A268(void);
void func_8006A3F0(void);
void func_8006A540(void);
void func_8006A694(void);
void func_8006A814(void);
void func_8006A99C(void);
void func_8006AAFC(void);
void func_8006AC88(void);
void func_8006ADE8(void);

s32 func_8005FC1C(s32 arg0) {
    u8 *p;
    s32 n;
    s32 v;
    u32 t;

    p = D_800F5918;
    n = 0;

    if (arg0 == (s32)func_80089E20) {
        v = -1;
    } else {
        do {
            if (*(s32 *)p == arg0) {
                v = *(s32 *)(p + 4);
                goto have;
            }
            n++;
            p += 8;
        } while (n < 0x50);
        v = -1;
    }

have:
    t = v & 0xFFFF0000;

    switch (t) {
    case 0:
    case 0x100000:
    case 0x200000:
    case 0x300000:
        switch (v & 0xFFFF) {
        case 9:
            return (s32)func_80069E44;
        case 0x209:
            return (s32)func_8006A3F0;
        case 0x11:
            return (s32)func_8006A0E8;
        case 0x211:
            return (s32)func_8006A694;
        case 0xD:
            return (s32)func_80069F94;
        case 0x20D:
            return (s32)func_8006A540;
        case 0x15:
            return (s32)func_8006A268;
        case 0x215:
            return (s32)func_8006A814;
        }
        return arg0;
    case 0x1000000:
    case 0x1100000:
    case 0x1200000:
    case 0x1300000:
        switch (v & 0xFFFF) {
        case 0xD:
            return (s32)func_8006A99C;
        case 0x20D:
            return (s32)func_8006AC88;
        case 0x15:
            return (s32)func_8006AAFC;
        case 0x215:
            return (s32)func_8006ADE8;
        }
        return arg0;
    }
    return arg0;
}
