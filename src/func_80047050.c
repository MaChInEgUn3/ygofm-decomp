#include "common.h"

void func_80047050(void) {
    if (D_8009B458[0x509] != 0) {
        func_800495A4();
    }
    func_80045F3C();
    if (*(u16 *)(D_8009B45C + 0x40) & 8) {
        func_80046A08();
    }
}
