#include "common.h"

void func_80059CE4(void) {
    u8 *p = D_800F56F0;

    func_8008AD50(p);

    if (D_8009AF94 == 0xF) {
        func_8004EB00();
    }
    if (D_8009AF94 == 0x13) {
        func_8004FE2C();
    }
    if (D_8009AF94 == 0x14) {
        func_800507D0();
    }

    func_8008AD50(p);
    func_800540B4(0);
    func_800540B4(1);
    func_800540B4(2);
    func_800559D4(0);
    func_800559D4(1);
    func_8004DE24();
    func_8004E9A0();
    func_800528AC();
    func_800556E8(0);
    func_800556E8(1);
    func_800556E8(2);

    if (func_8005FB08() == 0) {
        func_8005DBA4();
    }

    func_80051A48();
}
