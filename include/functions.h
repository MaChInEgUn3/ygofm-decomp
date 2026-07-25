#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types.h"

/*
 * Declarations for functions referenced across files -- callers, and
 * anywhere a function's address is taken. Declared centrally for the same
 * reason as the globals in variables.h: a signature mismatch between two
 * files changes codegen silently.
 *
 * A function listed here need not be decompiled; the declaration only has
 * to agree with how it is used, since the definition may still come from
 * assembly.
 */

void func_8002CD8C(void);
s32 func_8002E3B4(void);
void func_80033C90(void);
void func_80035AF0(s32 arg0, s32 arg1, s32 arg2);
void func_80040390(void);
void func_8004A518(void);
void func_8007BE00(void);
s32 func_8007BF60(void);
void func_800878D0(void);
void func_8008B4B8(void);
void func_80038024(s32 arg0, s32 arg1);
void func_80039F90(u8 *arg0);
void func_8004020C(s32 arg0);
void func_80045334(s32 arg0);
void func_80047314(s32 arg0);
void func_80047430(s32 arg0, s32 arg1);
void func_80019B2C(void);
void func_8004544C(void);

#endif /* FUNCTIONS_H */
