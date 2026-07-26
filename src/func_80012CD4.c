#include "common.h"

void func_80012CD4(void) {
    D_8009B09C++;
    D_8009B0C4++;
    D_8009B0C3 = 1;
    D_8009B0C8++;
    func_8003CC38();

    if (D_8009AF0C == 0) {
        D_8009AF0C = 1;
        func_80047050();
        D_8009AF0C = 0;
        D_8009B0C3 = 0;
    }
}
