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

struct Rect {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
};

struct Rec {
    u8 pad0[4];
    s32 unk4;
};

extern s32 D_8009B0AC __attribute__((section(".data")));
#define D_8009B0AC (*(u8 *)&D_8009B0AC)
extern s32 D_8009B0F4 __attribute__((section(".data")));
#define D_8009B0F4 D_8009B0F4
extern s32 D_8009B134 __attribute__((section(".data")));
#define D_8009B134 D_8009B134
extern u8 D_8009B145 __attribute__((section(".data")));
#define D_8009B145 D_8009B145
extern s16 D_8009B146 __attribute__((section(".data")));
#define D_8009B146 D_8009B146
extern s16 D_8009B148 __attribute__((section(".data")));
#define D_8009B148 D_8009B148
extern u8 D_800E9D70[100];
#define D_800E9D70 (*(struct Rect *)D_800E9D70)
extern u8 D_800E9ECE[100];
#define D_800E9ECE (D_800E9ECE[0])
extern u8 D_800EAE98[100];
extern u16 D_8009B27C;
extern struct Rec *D_8009B280;
extern u16 D_8009B2A8;
extern u16 D_8009B2AA;
extern u16 D_8009B270;

extern void func_8007FA38(struct Rect *, s32, s32);
extern void func_8004036C(void *);
extern void func_80015C0C(void);
extern s32 func_8004006C(void);
extern void func_80015C84(u8);
extern void func_8002DF2C(void *, s32);
extern void func_8002E00C(void *);
extern void func_8002E128(void *, s32);
extern s32 func_8002E3B4(void);
extern struct Rec *func_80040510(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern struct Rec *func_800400AC(s32, s32);

void func_8002E730(void) {
    struct Rec *rec;
    u16 flags;
    s32 ret;
    s32 masked;
    register u32 mask asm("v0");

    ret = func_8002E3B4();
    mask = 0x2000000;
    if (ret == 0) {
        D_800E9D70.x = 0;
        D_800E9D70.y = 0;
        D_800E9D70.w = 0x140;
        D_800E9D70.h = 0xA0;
        if (D_8009B0AC == 0) {
            D_800E9D70.x = 0x140;
        }
        func_8007FA38(&D_800E9D70, 0x1C0, 0x100);
        return;
    }

    mask |= 0x30;
    masked = D_8009B0F4 & mask;
    if ((masked | D_8009B134) != 0) {
        return;
    }
    if (D_800E9ECE & 0x80) {
        return;
    }

    flags = D_8009B27C;
    if (!(flags & 0x4000)) {
        D_8009B27C = flags | 0x4000;
        rec = func_800400AC(func_8004006C(), 3);
        func_80040510((s32)rec, 0, 0, 0x140, 0xA0, 0, 0, 0x17, 0, 0xF4);
        D_8009B280 = rec;
        rec->unk4 |= 0x2000000;
        func_8002E00C(D_800EAE98);
        D_8009B146 = D_8009B2A8;
        D_8009B148 = D_8009B2AA;
        if (D_8009B145 == 0) {
            func_80015C84(D_8009B145);
        }
        func_8002DF2C(D_800EAE98, D_8009B270 & 0xFFF);
        return;
    }
    if (!(flags & 0x2000)) {
        D_8009B27C = flags | 0x2000;
        func_8004036C(D_8009B280);
        func_8002E128(D_800EAE98, -1);
        if (D_8009B145 == 0 && !(D_8009B270 & 0x4000)) {
            func_80015C0C();
        }
        return;
    }
    D_8009B27C = 0;
}
