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

/* Object initializer. Copies arg2 into f18, runs func_80013940(arg0,arg1,
   arg3,-arg4) as a setup call, resets a handful of state fields, then either
   leaves the object idle (arg7==0), stores arg7 verbatim into f34 when the
   0x01000000 bit of arg1 is set, stores arg7 into both f8 and fC when arg7
   is negative, or (arg7 positive) arms it: splits arg7 into f30/f32, sets
   fixed fields f4/f6, and derives f8/fC from the D_8009B118 counter. */
struct Obj {
    char pad0[0x4];
    s16 f4;
    s16 f6;
    s32 f8;
    s32 fC;
    s32 f10;
    char pad1[0x18 - 0x14];
    s32 f18;
    s32 f1C;
    s32 f20;
    char pad3[0x2C - 0x24];
    s32 f2C;
    s16 f30;
    s16 f32;
    s32 f34;
    char pad4[0x40 - 0x38];
    s32 f40;
    s16 f44;
    u8 f46;
    u8 f47;
};

extern void func_80013940(void *a0, s32 a1, s32 a2, s32 a3);
extern s32 D_8009B118;

void *func_80013998(struct Obj *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                     s32 arg5, s32 arg6, s32 arg7) {
    arg0->f18 = arg2;
    func_80013940(arg0, arg1, arg3, -arg4);
    arg0->f46 = 1;
    arg0->f47 = 0;
    arg0->f44 = 0;
    arg0->f1C = 0;
    arg0->f20 = arg5;
    arg0->f40 = arg6;

    if (arg7 != 0) {
        if (arg1 & 0x01000000) {
            arg0->f34 = arg7;
            goto exit;
        }
        arg0->f1C = arg0->f10;
        if (arg7 < 0) {
            arg0->f46 = 1;
            arg0->fC = arg7;
            arg0->f8 = arg7;
            goto exit;
        }
        arg1 |= 0x10000;
        arg0->f46 = 2;
        arg0->f32 = (s16)((u32)arg7 >> 16);
        arg0->f4 = 0x40;
        arg0->f30 = (s16)arg7;
        arg0->f6 = 0x10;
        arg0->f8 = D_8009B118;
        arg0->fC = D_8009B118 + 0x800;
    }
exit:
    arg0->f2C = arg1;
    return arg0;
}
