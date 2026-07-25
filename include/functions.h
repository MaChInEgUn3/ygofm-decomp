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
void func_80016784(u8 *arg0, s32 arg1, s16 arg2, s16 arg3);
void func_80023D08(u8 *arg0);
void func_80023FBC(u8 *arg0);  /* PROVISIONAL */
void func_80024914(u8 *arg0);
s32 func_80036D3C(u8 *arg0);
void func_80044598(s32 arg0, s32 arg1, s32 arg2);
s32 func_80045208(s32 arg0, s32 arg1);
void func_800473F0(s32 arg0, s32 arg1);
void func_80048658(s32 arg0, s32 arg1, s32 arg2);
void func_80059908(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80012D4C(void);  /* PROVISIONAL */
void func_8004733C(s32 arg0, s32 arg1);
void func_800490F0(s16 arg0, u8 arg1);
void func_80049108(s16 arg0, u8 arg1);
void func_80049230(s16 arg0, s32 arg1);
void func_8007DE4C(void);
void func_8007E860(void (*arg0)(void));
void func_8003A920(u8 *arg0, s16 arg1, s16 arg2);
void func_8003E490(void);  /* PROVISIONAL */
void func_8003E854(void);  /* PROVISIONAL */
void func_8003F454(void);  /* PROVISIONAL */
void func_80040468(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void func_8004B9E0(void);  /* PROVISIONAL */
s32 func_800705AC(void);  /* PROVISIONAL */
void func_80019B2C(void);
void func_8004544C(void);

#endif /* FUNCTIONS_H */
