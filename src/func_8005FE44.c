#include "common.h"

void func_800612C0(void);
void func_8006151C(void);
void func_800617E0(void);
void func_80061A84(void);
void func_80061DDC(void);
void func_80062058(void);
void func_8006233C(void);
void func_80062600(void);
void func_80062978(void);
void func_80062BC0(void);
void func_80062E70(void);
void func_80063100(void);
void func_80063444(void);
void func_800636AC(void);
void func_8006397C(void);
void func_80063C2C(void);
void func_80067354(void);
void func_8006759C(void);
void func_80067858(void);
void func_80067ABC(void);
void func_80067D94(void);
void func_80067FD0(void);
void func_8006825C(void);
void func_800684B4(void);

s32 func_8005FE44(s32 arg0) {
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
    case 0x200000:
        switch (v & 0xFFFF) {
        case 0x9:
            return (s32)func_800612C0;
        case 0x209:
            return (s32)func_80061DDC;
        case 0x11:
            return (s32)func_800617E0;
        case 0x211:
            return (s32)func_8006233C;
        case 0xD:
            return (s32)func_8006151C;
        case 0x20D:
            return (s32)func_80062058;
        case 0x15:
            return (s32)func_80061A84;
        case 0x215:
            return (s32)func_80062600;
        }
        break;
    case 0x300000:
        switch (v & 0xFFFF) {
        case 0x9:
            return (s32)func_80062978;
        case 0x209:
            return (s32)func_80063444;
        case 0x11:
            return (s32)func_80062E70;
        case 0x211:
            return (s32)func_8006397C;
        case 0xD:
            return (s32)func_80062BC0;
        case 0x20D:
            return (s32)func_800636AC;
        case 0x15:
            return (s32)func_80063100;
        case 0x215:
            return (s32)func_80063C2C;
        }
        break;
    case 0x1200000:
        switch (v & 0xFFFF) {
        case 0xD:
            return (s32)func_80067354;
        case 0x20D:
            return (s32)func_80067858;
        case 0x15:
            return (s32)func_8006759C;
        case 0x215:
            return (s32)func_80067ABC;
        }
        break;
    case 0x1300000:
        switch (v & 0xFFFF) {
        case 0xD:
            return (s32)func_80067D94;
        case 0x20D:
            return (s32)func_8006825C;
        case 0x15:
            return (s32)func_80067FD0;
        case 0x215:
            return (s32)func_800684B4;
        }
        break;
    }
    return arg0;
}
