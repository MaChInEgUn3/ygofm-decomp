#include "common.h"

/* Reads an opcode byte and dispatches through the handler table. */
void func_80038B4C(u8 *arg0) {
    u8 **pp = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p = *pp;
    s32 op = *p;

    *pp = p + 1;
    D_80090EAC[op](arg0);
}
