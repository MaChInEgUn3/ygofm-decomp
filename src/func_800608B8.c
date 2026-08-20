#include "common.h"

void func_80067220(void);
void func_80067354(void);
void func_8006759C(void);
void func_80067858(void);
void func_80067ABC(void);
void func_80067D94(void);
void func_80067FD0(void);
void func_8006825C(void);
void func_800684B4(void);
void func_8006875C(void);
void func_80068A00(void);
void func_80068D18(void);
void func_80068FD8(void);
void func_8006930C(void);
void func_800695A4(void);
void func_8006988C(void);
void func_80069B40(void);

s32 func_800608B8(s32 arg0) {
    u32 t;
    u32 u;

    t = arg0 & 0xFFFF0000;
    switch (t) {
    case 0x1000000:
        u = arg0 & 0xFFFF;
        switch (u) {
        case 0x0:
            return (s32)func_80067220;
        case 0xD:
            return (s32)func_80067354;
        case 0x15:
            return (s32)func_8006759C;
        case 0x20D:
            return (s32)func_80067858;
        case 0x215:
            return (s32)func_80067ABC;
        }
        break;
    case 0x1100000:
        u = arg0 & 0xFFFF;
        switch (u) {
        case 0xD:
            return (s32)func_80067D94;
        case 0x15:
            return (s32)func_80067FD0;
        case 0x20D:
            return (s32)func_8006825C;
        case 0x215:
            return (s32)func_800684B4;
        }
        break;
    case 0x1200000:
        u = arg0 & 0xFFFF;
        switch (u) {
        case 0xD:
            return (s32)func_8006875C;
        case 0x15:
            return (s32)func_80068A00;
        case 0x20D:
            return (s32)func_80068D18;
        case 0x215:
            return (s32)func_80068FD8;
        }
        break;
    case 0x1300000:
        u = arg0 & 0xFFFF;
        switch (u) {
        case 0xD:
            return (s32)func_8006930C;
        case 0x15:
            return (s32)func_800695A4;
        case 0x20D:
            return (s32)func_8006988C;
        case 0x215:
            return (s32)func_80069B40;
        }
        break;
    }
    return (s32)func_80089E20;
}
