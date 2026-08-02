#include "common.h"

/* Retail emits no epilogue: the frame is set up and $ra saved, and the
   function just ends after the last call.  That is gcc dropping the epilogue
   behind a call it knows cannot return. */
void func_8008FB8C(u8 *arg0, s32 arg1) __attribute__((noreturn));

void func_80030FD0(void) {
    func_80015AD8();
    func_800403F0();
    func_80035A64();
    func_8008FB8C(D_800E9DC0, 2);
}
