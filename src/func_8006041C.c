#include "common.h"

void func_80033DB0(void);
void func_80034830(void);
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
void func_80063F90(void);
void func_80064248(void);
void func_80064568(void);
void func_80064868(void);
void func_80064C1C(void);
void func_80064EF4(void);
void func_80065234(void);
void func_80065554(void);
void func_80065928(void);
void func_80065BCC(void);
void func_80065ED8(void);
void func_800661C4(void);
void func_80066564(void);
void func_80066828(void);
void func_80066B54(void);
void func_80066E60(void);

s32 func_8006041C(s32 arg0) {
    u32 t;

    t = arg0 & 0xFFFF0000;
    switch (t) {
    case 0:
        switch ((u32)arg0 & 0xFFFF) {
        case 0:
            return (s32)func_80089E20;
        case 0x9:
            return (s32)func_800612C0;
        case 0xD:
            return (s32)func_8006151C;
        case 0x11:
            return (s32)func_800617E0;
        case 0x15:
            return (s32)func_80061A84;
        case 0x209:
            return (s32)func_80061DDC;
        case 0x20D:
            return (s32)func_80062058;
        case 0x211:
            return (s32)func_8006233C;
        case 0x215:
            return (s32)func_80062600;
        }
        break;
    case 0x20000:
        switch ((u32)arg0 & 0xFFFF) {
        case 0xD:
            return (s32)func_80033DB0;
        case 0x15:
            return (s32)func_80034830;
        }
        break;
    case 0x100000:
        switch ((u32)arg0 & 0xFFFF) {
        case 0x9:
            return (s32)func_80062978;
        case 0xD:
            return (s32)func_80062BC0;
        case 0x11:
            return (s32)func_80062E70;
        case 0x15:
            return (s32)func_80063100;
        case 0x209:
            return (s32)func_80063444;
        case 0x20D:
            return (s32)func_800636AC;
        case 0x211:
            return (s32)func_8006397C;
        case 0x215:
            return (s32)func_80063C2C;
        }
        break;
    case 0x200000:
        switch ((u32)arg0 & 0xFFFF) {
        case 0x9:
            return (s32)func_80063F90;
        case 0xD:
            return (s32)func_80064248;
        case 0x11:
            return (s32)func_80064568;
        case 0x15:
            return (s32)func_80064868;
        case 0x209:
            return (s32)func_80064C1C;
        case 0x20D:
            return (s32)func_80064EF4;
        case 0x211:
            return (s32)func_80065234;
        case 0x215:
            return (s32)func_80065554;
        }
        break;
    case 0x300000:
        switch ((u32)arg0 & 0xFFFF) {
        case 0x9:
            return (s32)func_80065928;
        case 0xD:
            return (s32)func_80065BCC;
        case 0x11:
            return (s32)func_80065ED8;
        case 0x15:
            return (s32)func_800661C4;
        case 0x209:
            return (s32)func_80066564;
        case 0x20D:
            return (s32)func_80066828;
        case 0x211:
            return (s32)func_80066B54;
        case 0x215:
            return (s32)func_80066E60;
        }
        break;
    }
    return (s32)func_80089E20;
}
