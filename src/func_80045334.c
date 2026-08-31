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

/* Build and enqueue a type-0x21 message for an active 0x8xxx/0x9xxx id. */

typedef struct {
    u8 pad0[0x40];
    u16 f40;
    u8 pad1[0x4A - 0x42];
    u8 f4A;
    u8 pad2[0x518 - 0x4B];
    void *f518;
    void *f51C;
    void *f520;
    u8 pad3[0x534 - 0x524];
    u16 f534;
} S8009B45C;

typedef struct {
    u8 type;
    u8 pad0;
    u16 id;
    u32 data;
    u32 val2;
    void *ptr2;
} Msg;

extern S8009B45C *D_8009B45C[16];
extern S8009B45C *D_8009B45C[16];
extern S8009B45C *D_8009B45C[16];
#define D_8009B45C (D_8009B45C[0])
#define D_8009B45C (D_8009B45C[0])
#define D_8009B45C (D_8009B45C[0])

extern void func_800464F0(s32 a0);
extern void func_80045BE8(Msg *m);

void func_80045334(s32 a0) {
    register S8009B45C *rec asm("a1") = D_8009B45C;
    register s32 s3 asm("s3") = a0;
    Msg msg;
    u8 pad_experiment[32];
    (void)pad_experiment;

    if (!(rec->f4A & 0x80)) {
        return;
    }
    if (!(rec->f4A & 0x40) && (u16)s3 > 0x9FFF) {
        return;
    }
    if (!(a0 & 0x8000)) {
        return;
    }

    {
        s32 mask = a0 & 0xF000;
        s32 s2;
        register void *ptr asm("v0");
        register u32 data asm("s0");

        rec->f534 = (u16)a0;

        if (mask == 0x8000) {
            goto case1;
        }
        s3 += 0x6000;
        if (mask == 0x9000) {
            goto case2;
        }
        goto default_case;

    case1:
        s3 = a0 + mask;
        ptr = rec->f51C;
        s2 = 0x50;
        goto tail;

    case2:
        s3 = a0 + 0x7000;
        ptr = rec->f518;
        s2 = 0x60;
        goto tail;

    default_case:
        s2 = 0x70;
        ptr = D_8009B45C->f520;

    tail:
        data = *(u32 *)ptr;
        asm volatile("" : "+r" (data));
        {
            register void *ptr2 asm("s1") = (u8 *)ptr + 8;
            func_800464F0(a0);
            {
                register u32 mtype asm("v0") = 0x21;
                msg.type = mtype;
                msg.id = (u16)s3;
                msg.data = data;
                msg.ptr2 = ptr2;
                msg.val2 = s2;
                func_80045BE8(&msg);
            }
        }
    }

    D_8009B45C->f40 = (D_8009B45C->f40 | 1) & 0xFFFB;
}
