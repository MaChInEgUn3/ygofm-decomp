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
 *
 * Declarations marked PROVISIONAL have no evidence behind their signature.
 * They come from decompiling a *pure thunk* -- a function whose whole body is
 * one call. Argument forwarding costs no instructions on MIPS, because $a0..$a3
 * are already in place, so `void f(int a) { g(a); }` and `void f(void) { g(); }`
 * compile identically. The thunk's asm therefore says nothing about its
 * callee's arity, and neither does the callee's own asm when it never reads an
 * argument register.
 *
 * Evidence for a signature can come from two places: the callee reading $aN
 * before writing it, or any *call site* setting $aN up. Where neither exists,
 * the declaration below is a guess that happens to match. It matters later:
 * the first function decompiled that calls one of these with real argument
 * setup will be blamed for a mismatch that is really a stale prototype here.
 * Widen the signature at that point rather than fighting the caller.
 */

void func_8002CD8C(void);  /* PROVISIONAL */
s32 func_8002E3B4(void);  /* PROVISIONAL */
void func_80033C90(void);  /* PROVISIONAL */
void func_80035AF0(s32 arg0, s32 arg1, s32 arg2);
void func_80040390(void);  /* PROVISIONAL */
void func_8004A518(void);  /* PROVISIONAL */
void func_8007BE00(void);  /* PROVISIONAL */
s32 func_8007BF60(void);  /* PROVISIONAL */
void func_800878D0(void);  /* PROVISIONAL */
void func_8008B4B8(void);  /* PROVISIONAL */
void func_80038024(s32 arg0, s32 arg1);
void func_80039F90(u8 *arg0);
void func_8004020C(s32 arg0);
void func_80045334(s32 arg0);
void func_80047314(s32 arg0);
void func_80047430(s32 arg0, s32 arg1);
void func_80019B2C(void);
void func_8004544C(void);

#endif /* FUNCTIONS_H */
