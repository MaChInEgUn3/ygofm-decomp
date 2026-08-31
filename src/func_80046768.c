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
typedef int s32;

struct Big45C {
    u8 pad0[0x40];
    u16 f40;
    u16 f42;
    u16 f44;
    u8 pad46[3];
    u8 f49;
    u8 f4A;
    u8 pad4B[0x1619 - 0x4B];
    u8 rec0[16];
    u8 rec1[16];
    u8 rec2[16];
    u8 f1649;
    u8 f164A;
    u8 f164B;
};

extern struct Big45C *D_8009B45C;
extern u8 *D_8009B458;
extern s32 D_8009B460;
extern void (*D_8009B0F0)(void) __attribute__((section(".data")));
extern void (*D_8009B120)(void) __attribute__((section(".data")));
extern u8 D_80010784[12];
extern u8 D_80010790[12];
extern u8 D_8001079C[12];

extern void func_8004666C(void);
extern void func_800466C8(void);
extern void func_800478EC(void);
extern void func_80044D48(void);
extern void func_8004671C(void);
extern void func_80046FA0(s32);
extern void func_80048F14(void);
extern void func_800494F4(void *a, s32 b, s32 c, struct Big45C *d);

#define P_U8(p, o) (*((u8 *) (p) + (o)))
#define P_S32(p, o) (*(s32 *) ((u8 *) (p) + (o)))

void func_80046768(s32 arg0) {
    register s32 val1650 asm("v1") = 0x801E1650;
    register s32 *p asm("a1") = (s32 *) 0x801E0000;
    register u32 bound asm("a2") = (u32) p;
    register struct Big45C *copy asm("v0");

    bound |= 0xa7ff;
    copy = (struct Big45C *) p;
    D_8009B45C = copy;
    D_8009B460 = val1650;
    do {
        *p = 0;
        p++;
    } while ((u32) p <= bound);

    D_8009B0F0 = func_8004666C;
    D_8009B120 = func_800466C8;
    __builtin_memcpy(D_8009B45C->rec0, D_80010784, 0xB);
    __builtin_memcpy(D_8009B45C->rec1, D_80010790, 0xA);
    __builtin_memcpy(D_8009B45C->rec2, D_8001079C, 0xA);

    D_8009B45C->f4A = 3;
    if (arg0 & 0xFF) {
        D_8009B45C->f4A = (u8) (D_8009B45C->f4A | 0xF0);
    }

    {
        register s32 ff asm("a1") = 0xFF;
        D_8009B45C->f1649 = ff;
        D_8009B45C->f164A = 0xD2;
        D_8009B45C->f164B = ff;
        {
            register struct Big45C *storep asm("v0") = D_8009B45C;
            s32 t1649 = storep->f1649;
            s32 t164a = storep->f164A;
            register struct Big45C *callp asm("a3");
            storep->f49 = ff;
            storep->f42 = t1649;
            storep->f44 = t164a;
            callp = D_8009B45C;
            P_U8(callp, 0x1584) = ff;
            func_800494F4((void *) 0x801E1670, ff, t164a, callp);
        }
    }

    func_8004671C();
    func_80044D48();
    func_80048F14();
    func_80046FA0(0);

    {
        register u8 *p458a asm("v0") = D_8009B458;
        p458a[0x509] = 0;
        {
            register u8 *p458b asm("v1") = D_8009B458;
            register struct Big45C *p45c asm("a0") = D_8009B45C;
            P_S32(p458b, 0x50C) = (s32) func_800478EC;
            p45c->f40 = 0;
        }
    }
}
