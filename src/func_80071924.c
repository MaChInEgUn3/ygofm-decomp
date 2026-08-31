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
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u16 unk6;
    s32 unk8;
} Entry;

extern s32 D_800F5B98[];
extern u8 D_801AB000[];

extern s32 func_8007058C(void);
extern void func_80070738(s32 mode, s32 *out0, s32 *out1);
extern s32 func_80070920(s32 a0, s32 a1);

void func_80071924(void) {
    register s32 s5 asm("s5");
    s32 s4;
    s32 mode;
    s32 s2;
    s32 fp;
    s32 s7;
    s32 sp18;
    s32 sp10;
    s32 sp14;
    s32 s1;
    register s32 one asm("s6");
    s32 v0;
    s32 v1;
    Entry *s0;

    s5 = D_800F5B98[func_8007058C()];
    s4 = 0;
    mode = D_800F5B98[func_8007058C()];
    s2 = 0x270F;
    fp = D_800F5B98[func_8007058C()];
    s7 = D_800F5B98[func_8007058C()];
    sp18 = func_8007058C();
    func_80070738(mode, &sp10, &sp14);
    s1 = sp10;
    if (sp14 >= s1) {
        one = 1;
        __asm__ __volatile__("");
        {
            register u8 *base asm("v1");
            register s32 index asm("v0");
            base = (u8 *) 0x801B0000;
            __asm__ __volatile__("" : "+r" (base));
            base -= 0x5000;
            index = s1 << one;
            index += s1;
            index <<= 2;
            s0 = (Entry *) ((u32) index + (u32) base);
        }
        for (;;) {
            __asm__ __volatile__("" : "+r" (s0));
            if (s0->unk0 != 0) {
                {
                    register s32 cmp asm("v0");
                    if (mode == one) {
                        goto check_4000;
                    }
                    cmp = 4;
                    if (mode == cmp) {
                        goto check_4000;
                    }
                    cmp = 5;
                    if (mode != cmp) {
                        goto after_4000;
                    }
                }
            check_4000:
                if (s0->unk6 & 0x4000) {
                    goto skip;
                }
            after_4000:
                {
                    register s32 cmp asm("v0");
                    cmp = 4;
                    if (mode == cmp) {
                        if (s0->unk6 & 0x800) {
                            goto skip;
                        }
                    }
                    cmp = 5;
                    if (mode == cmp) {
                        if (!(s0->unk6 & 0x800)) {
                            goto skip;
                        }
                    }
                }
                v0 = mode - 3;
                if (((u32) v0 < 3) && (s0->unk6 & 0x1000) && (fp == one)) {
                    goto skip;
                }
                if (func_80070920(s7, s1) == 0) {
                    if (s5 == 0) {
                        v1 = s0->unk2;
                        v0 = v1 < s2;
                    } else if (s5 == one) {
                        v1 = s0->unk4;
                        v0 = v1 < s2;
                    } else {
                        s32 a0;
                        a0 = s0->unk2;
                        __asm__ __volatile__("" : "+r" (a0));
                        v1 = s0->unk4;
                        if (v1 < a0) {
                            if (a0 < s2) {
                                s2 = a0;
                                s4 = s1;
                                goto next;
                            }
                            goto skip;
                        }
                        v0 = v1 < s2;
                    }
                    if (v0) {
                        s2 = v1;
                        s4 = s1;
                    }
                }
            }
        skip:
        next:
            v0 = sp14;
            s1 += 1;
            if (v0 < s1) {
                break;
            }
            s0 += 1;
        }
    }
    D_800F5B98[sp18] = s4;
}

