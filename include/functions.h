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

void func_8002CD8C(void);
s32 func_8002E3B4(void);
void func_80033C90(void);  /* PROVISIONAL */
u8 *func_80035AF0(s32 arg0, s32 arg1, s32 arg2);
void func_80040390(void);  /* PROVISIONAL */
void func_8004A518(void);  /* PROVISIONAL */
void func_8007BE00(void);  /* PROVISIONAL */
s32 func_8007BF60(void);
void func_800878D0(void);  /* PROVISIONAL */
void func_8008B4B8(void);  /* PROVISIONAL */
void func_80038024(u8 *arg0, s32 arg1);
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
s32 func_80045208(s32 arg0, s16 arg1);
void func_800473F0(s32 arg0, s32 arg1);
void func_80048658(s32 arg0, s32 arg1, s32 arg2);
void func_80059908(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80012D4C(void);  /* PROVISIONAL */
void func_8004733C(s32 arg0, s32 arg1);
void func_800490F0(s16 arg0, u8 arg1);
void func_80049108(s16 arg0, u8 arg1);
void func_80049230(s16 arg0, s16 arg1);
void func_8007DE4C(void);
void func_8007E860(void (*arg0)(void));
void func_8003A920(u8 *arg0, s16 arg1, s16 arg2);
void func_8003E490(void);  /* PROVISIONAL */
void func_8003E854(void);  /* PROVISIONAL */
void func_8003F454(void);  /* PROVISIONAL */
u8 *func_80040468(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void func_8004B9E0(void);  /* PROVISIONAL */
s32 func_800705AC(void);  /* PROVISIONAL */
s32 func_8002C604(void);
void func_8003F758(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3);
s32 func_8003F8D4(void);
void func_80049010(void);  /* PROVISIONAL */
void func_80015780(void);
void func_800157DC(void);
void func_8001581C(s32 arg0);
void func_800158B8(void);
void func_80015904(void);
void func_80015944(s32 arg0);
void func_80015998(void);
void func_8001572C(void);
void func_80015870(void);
void func_80042A00(u8 *arg0);
void func_80042A28(u8 *arg0);
void func_800472A8(s32 arg0);
void func_80047AD0(s32 arg0);
void func_800530C4(void);  /* PROVISIONAL */
void func_800533D8(void);  /* PROVISIONAL */
void func_8005BB7C(s32 arg0);
s32 func_8005BE3C(void);  /* PROVISIONAL */
void func_80042A50(u8 *arg0);
void func_80047EC4(void);  /* PROVISIONAL */
void func_80049434(void);  /* PROVISIONAL */
void func_80075B60(void);  /* PROVISIONAL */
void func_80015010(void);
void func_80027DF8(u8 *arg0, s32 arg1);
void func_80024DC8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80045BE8(void *arg0);  /* PROVISIONAL */
void func_80045114(void);  /* PROVISIONAL */
void func_8004A2F8(void);  /* PROVISIONAL */
s32 func_8004BAE4(u8 *arg0);
u8 *func_80089E20(u8 **arg0);
u8 *func_80089E40(u8 **arg0);  /* PROVISIONAL */
u8 *func_80089ED0(u8 **arg0);  /* PROVISIONAL */
void func_80015D18(u8 *arg0);  /* PROVISIONAL */
void func_80056250(s32 arg0, u8 *arg1, s32 arg2, s32 arg3);  /* PROVISIONAL */
s32 func_8002CCA8(s32 arg0);  /* PROVISIONAL */
void func_8002CCE4(s32 arg0);  /* PROVISIONAL */
void func_8003BEB8(void);
void func_8016A080(void);  /* PROVISIONAL */
void func_8016A37C(void);  /* PROVISIONAL */
void func_800404CC(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7);
void func_80014E1C(s32 arg0, u8 *arg1, s32 arg2, s32 arg3,
                   void *arg4, s32 arg5, s32 arg6);  /* PROVISIONAL */
void func_8005B64C(void);  /* PROVISIONAL */
/* Was PROVISIONAL void(void): it searches D_801D0200 for a halfword and
 * returns the index or -1. */
s32 func_8002C4DC(s32 arg0);
void func_80032184(void);  /* PROVISIONAL */
void func_800137E4(void);  /* PROVISIONAL */
void func_80044F58(s32 arg0);  /* PROVISIONAL */
void func_8005C388(u8 *arg0, s32 arg1, s32 arg2, s32 arg3,
                   s32 arg4);  /* PROVISIONAL */
void func_8003BA14(void);  /* PROVISIONAL */
void func_8003BD14(void);  /* PROVISIONAL */
void func_8003C328(void);  /* PROVISIONAL */
s32 func_8003D288(u8 *arg0, u8 *arg1);
void func_800492D8(void);  /* PROVISIONAL */
void func_80049640(void);  /* PROVISIONAL */
void func_80076D90(s32 arg0);  /* PROVISIONAL */
s32 func_8007E710(s32 arg0);  /* PROVISIONAL */
void func_800243F4(s32 arg0, u8 *arg1, u8 *arg2);  /* PROVISIONAL */
s32 func_8002892C(void);  /* PROVISIONAL */
void func_800373C8(u8 *arg0, s32 arg1, s32 arg2);
void func_80036C14(u8 *arg0, s32 arg1);  /* PROVISIONAL */
void func_800393B0(u8 *arg0);  /* PROVISIONAL */
s32 func_8006041C(s32 arg0);  /* PROVISIONAL */
s32 func_800608B8(s32 arg0);  /* PROVISIONAL */
void func_80060170(s32 arg0, s32 arg1);
void func_80015D0C(void);
void func_8004B854(void);  /* PROVISIONAL */
s32 func_8002EE5C(void);  /* PROVISIONAL */
/* arg0 is a record index, not a pointer: it is scaled by 100 and added to
 * D_800EB0F8. The PROVISIONAL u8 * was a guess. */
void func_80035AB8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_8004B910(void);  /* PROVISIONAL */
void func_8003B9BC(void);  /* PROVISIONAL */
void func_80168FB4(void);  /* PROVISIONAL */
void func_80058B4C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7);  /* PROVISIONAL */
u8 *func_8005CEF0(u8 **arg0);  /* PROVISIONAL */
u8 *func_8005D378(u8 **arg0);  /* PROVISIONAL */
void func_80022EEC(void);  /* PROVISIONAL */
void func_80022F98(u8 *arg0, u8 *arg1);
s32 func_8004CABC(void);
s16 func_80049F50(void);
void func_8002A660(u8 *arg0);
u32 func_8004BB34(u8 *arg0);
s32 func_8004BBBC(s32 arg0);
void func_8004C0AC(u8 *arg0);
s32 func_8004C560(u8 *arg0);
void func_800495DC(void);
void func_800495EC(void);
s32 func_80070870(s32 arg0);
s32 func_800708C4(s32 arg0);
void func_8003B6AC(s32 arg0, s32 arg1);
void func_80040CAC(void);
void func_80046FA0(s16 arg0);
s32 func_80070920(s32 arg0, s32 arg1);
void func_8003C628(void);
void func_80035B7C(u8 *arg0);
void func_80038798(u8 *arg0);
void func_8002D6C8(void);
void func_80026BA4(s32 arg0, s32 arg1);
s32 func_800440B4(s32 arg0, s32 arg1);
s32 func_80058F74(s32 arg0);
u8 *func_800591C0(s32 arg0, u32 arg1);
void func_80035CA8(s32 arg0);
void func_80035DB8(s32 arg0);
void func_800378D8(u8 *arg0);
void func_80037914(u8 *arg0);
void func_80037950(u8 *arg0);
void func_800380D4(u8 *arg0);
s32 func_80059AA8(s32 arg0, s32 arg1);
void func_8002EE20(void);
s32 func_80033500(u8 *arg0);
void func_8003798C(u8 *arg0);
void func_80037D6C(u8 *arg0);
void func_80038110(u8 *arg0);
s32 func_80041464(u8 *arg0, u8 *arg1);
s32 func_80042B08(s32 arg0, s32 arg1);
/* None of these four reads $a0 before writing one. */
void func_8001306C(void);
void func_80012DB4(void);
void func_80012E5C(void);
void func_8003CCD8(void);
u8 *func_8002C5CC(void);
s32 func_80033998(void);
void func_800143DC(void);
s32 func_80030294(void);
void func_80030250(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6);
void func_8002BAB4(void);   /* no read of $a0 before it writes one */
void func_8002BFCC(void);   /* likewise */
void func_8003FF34(void);
void func_80015A00(void);
void func_8004763C(void);
void func_80012D84(s32 arg0);
void func_80023144(u8 *arg0, s32 arg1);  /* PROVISIONAL */
void func_801683EC(void);  /* PROVISIONAL */
s32 func_80169C08(void);  /* PROVISIONAL */
void func_80031CD4(u8 *arg0, s32 arg1);  /* PROVISIONAL */
void func_8003B808(void);  /* PROVISIONAL */
void func_8016824C(u8 *arg0);  /* PROVISIONAL */
void func_800356A0(u8 *arg0, u8 *arg1, s32 arg2);  /* PROVISIONAL */
void func_8003D03C(u8 *arg0);  /* PROVISIONAL */
void func_80044DC0(s32 arg0);  /* PROVISIONAL */
void func_800540B4(s32 arg0);  /* PROVISIONAL */
s32 func_80073704(s32 arg0, s32 arg1, s32 arg2);  /* PROVISIONAL */
s32 func_80073734(s32 arg0, s32 arg1, s32 arg2);  /* PROVISIONAL */
void func_80073724(s32 arg0);  /* PROVISIONAL */
void func_80058A7C(s32 arg0, s32 arg1, Words7 *arg2);  /* PROVISIONAL */
s32 func_8007AFA4(void);  /* PROVISIONAL */
s32 func_800170C8(u8 *arg0);
s32 func_8001EE44(s32 arg0, s32 arg1);  /* PROVISIONAL */
void func_80041D60(u8 *arg0);  /* PROVISIONAL */
void func_80040410(u8 *arg0, u8 arg1);
void func_80039E9C(void);  /* PROVISIONAL */
void func_80030198(void);  /* PROVISIONAL */
void func_80031084(void);  /* PROVISIONAL */
void func_800357E8(s32 arg0);  /* PROVISIONAL */
void func_8003CF14(u8 *arg0);  /* PROVISIONAL */
void func_80052D2C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);  /* PROVISIONAL */
s32 func_80037C74(u8 *arg0);  /* PROVISIONAL */
void func_80046990(s32 arg0, s32 arg1, s32 arg2);  /* PROVISIONAL */
void func_8003BF00(void);  /* PROVISIONAL */
void func_80045F3C(void);  /* PROVISIONAL */
void func_80046A08(void);  /* PROVISIONAL */
void func_8005ABA0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);  /* PROVISIONAL */
void func_80019B2C(u8 *arg0);
void func_8004544C(void);

#endif /* FUNCTIONS_H */
s32 func_80042B98(u8 *arg0);
void func_8004036C(s32 arg0);
void func_80059700(s32 arg0, s32 arg1);
void func_8005F3B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_80059590(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_8005F174(void);
s32 func_8005F18C(void);
void func_800171A8(void);
void func_8003CDF8(void);
void func_80024200(void);
void func_8003CE48(void);
void func_8003D0F4(u8 *arg0);
void func_80049138(s16 arg0, s32 arg1);
s32 func_8007058C(void);
void func_80013940(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80014134(u8 arg0);
void func_8007B468(s32 arg0, void *arg1, s32 arg2, void (*arg3)(u8), s32 arg4);
void func_80014294(u8 arg0);
void func_8007B1F4(s32 arg0, void *arg1, void (*arg2)(u8), s32 arg3);
void func_80014220(u8 arg0);
void func_800141A8(u8 arg0);
void func_8007DE38(s32 arg0);
void func_8007DD50(void (*arg0)(void), s32 arg1);
void func_80013C28(void);
void func_800140A0(u8 arg0);
void func_80014308(u8 arg0);
s32 func_8004006C(void);
u8 *func_800400AC(s32 arg0, s32 arg1);
void func_80042918(u8 *arg0);
s32 func_8003CEB8(u8 *arg0, s32 arg1);
u32 func_8003CE74(void);
void func_8003C120(void);
void func_8003CC38(void);
void func_800857C0(s32 arg0);
void func_8001352C(void);
s32 func_8003FCD8(void);
void func_8005B85C(void);
void func_8005922C(u8 *arg0, s32 arg1);
void func_8005F91C(s32 arg0, void *arg1, void *arg2, s32 arg3);
u8 *func_80017F04(u8 *arg0);
u8 *func_80014EEC(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5, s32 arg6);
void func_800289BC(void);
s32 func_8002C7E8(s32 arg0, s32 arg1);
void func_8002FD10(s32 arg0);
void func_8002FA54(void);
void func_80015B00(void);
void func_8003C7A0(void);
void func_80036DBC(u8 *arg0);
s32 func_8005C4F0(u8 *arg0, u8 *arg1);
s32 func_8005B8A0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void func_8004503C(s16 arg0, u8 arg1, s32 arg2);
void func_800473CC(s32 arg0);
u8 *func_8005F1A4(s32 arg0);
void func_8003134C(void);
s32 func_800358FC(s32 arg0);
void func_8003B378(u8 *arg0, s32 arg1);
s32 *func_800249E0(void);
u8 *func_80024C1C(s16 arg0, s16 arg1, s16 arg2);
void func_80058FB0(s32 arg0, u8 *arg1);
void func_8004A6D8(void);
void func_8016866C(s32 arg0);
void func_80168FCC(void);
void func_800134B4(void);
void func_80032C48(u8 *arg0);
void func_80058938(s32 arg0, s32 arg1, Word4 arg2, Word4 arg3, s32 arg4, s32 arg5);
void func_800428EC(u8 *arg0, s32 arg1);
s32 func_8004002C(void);
void func_80015DB8(u8 *arg0);
