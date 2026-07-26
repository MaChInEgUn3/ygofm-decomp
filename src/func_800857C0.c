#include "common.h"

/* The one caller passes a value in $a0 that this ignores -- retail's caller
   was compiled without a prototype in scope. Declared with the parameter so
   the call site can be written as it was. */
void func_800857C0(s32 arg0) {
    func_800878D0();
}
