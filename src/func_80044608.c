/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

extern u8 D_8009B43D;
extern volatile s32 D_8009B450;
extern u8 D_8009B43C;
extern u8 D_8009B44E;
extern s8 D_8009B43E;
extern u8 D_8009B437;
extern void *D_8009B444;
extern s32 D_8009B440;
extern s32 D_8009B438;

extern s32 D_800F2AE0[];
extern s32 D_800F2AF0[];
extern u8 D_800F2888[];
extern u8 D_8009AF7C[];

extern void func_80043D48(s32 *a0);
extern s32 func_8008B330(s32 a0);
extern s32 func_8008B3A0(s32 a0);
extern s32 func_8008B340(s32 a0);
extern void func_80044470();
extern s32 func_80044544();

s32 func_80044608(void) {
    s32 v0;
    register s32 one asm("a0");
    s32 v1;

    v1 = D_8009B43D;
    if (v1 == 1) {
        goto state1;
    }
    if (v1 < 2) {
        if (v1 == 0) {
            goto state0;
        }
        goto ret;
    }
    if (v1 == 2) {
        goto state2;
    }
    goto ret;

state0:
    v1 = D_8009B450;
    if (v1 == 1) {
        goto state0_info;
    }
    if (v1 < 2) {
        if (v1 != 0) {
            goto ret;
        }
    } else {
        if (v1 == 2) {
            goto ret;
        }
        if (v1 == 3) {
            goto sub_poll_entry;
        }
        goto ret;
    }
    goto state0_zero;

state0_info:
    v0 = D_8009B43C - 1;
    D_8009B43C = (u8) v0;
    if ((s8) v0 == 0) {
        goto ret;
    }
    func_80043D48(D_800F2AE0);
    func_8008B330(D_8009B437);
    return -1;

state0_zero:
    if (D_8009B44E & 0x80) {
        if (D_8009B43E != 8) {
            goto ret;
        }
    }
    D_8009B450 = 3;
sub_poll_entry:
    if (D_8009B43E == 1) {
        goto ret;
    }
    D_8009B43C = 0xA;
    D_8009B43D = (u8) (D_8009B43D + 1);
sub_retry:
    func_80043D48(D_800F2AF0);
    func_8008B3A0(D_8009B437);
    return -1;

state1:
    v0 = D_8009B450;
    if (v0 == 0) {
        goto state1_zero;
    }
    v1 = D_8009B450;
    if (v1 != 2) {
        goto ret;
    }
    v0 = D_8009B43C - 1;
    D_8009B43C = (u8) v0;
    if ((s8) v0 > 0) {
        goto sub_retry;
    }
    goto ret;

state1_zero:
    D_8009B43C = 0xA;
    D_8009B43D = 2;
load_retry:
    func_80043D48(D_800F2AE0);
    func_8008B340(D_8009B437);
    return -1;

state2:
    v0 = D_8009B450;
    if (v0 == 2) {
        v0 = D_8009B43C - 1;
        D_8009B43C = (u8) v0;
        if ((s8) v0 > 0) {
            goto load_retry;
        }
    }

    D_8009B44E |= 0x80;
    v1 = D_8009B450;
    if (v1 != 0) {
        goto after_load;
    }
    D_8009B444 = D_800F2888;
    func_80044470(D_8009B437, D_8009AF7C, D_800F2888, &D_8009B440);
    D_8009B438 = func_80044544(D_8009B444, D_8009B440);

after_load:
    if (D_8009B450 == 3) {
        D_8009B450 = 4;
    }
ret:
    return D_8009B450;
}
