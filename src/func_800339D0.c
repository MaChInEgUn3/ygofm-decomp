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

/* Initializes or cleans up an object build, then refreshes its copied records. */

#define P_U8(p, o) (*((u8 *) (p) + (o)))
#define P_S8(p, o) (*(signed char *) ((u8 *) (p) + (o)))
#define P_U16(p, o) (*(u16 *) ((u8 *) (p) + (o)))
#define P_S32(p, o) (*(s32 *) ((u8 *) (p) + (o)))
#define P_PTR(p, o) (*(void **) ((u8 *) (p) + (o)))

/* $gp+0x3F0 -- not currently in symbol_addrs.txt under any name. */
extern u8 D_8009B2F8;
extern u8 D_8009AF76[];
extern u8 D_8009B140[];
extern signed char D_8009B34D[];
extern u8 D_800EB0F8[64];

extern int func_80032B38(char *a0);
extern void func_8003FEE0(s32 code);
extern int func_80033998(void);
/* returns whatever func_80035AF0 (called internally) leaves in $v0 -- the
   object pointer it creates -- even though other call sites treat this as
   void; per-file declarations are independent (project convention). */
extern void *func_80035C38(void *a0, int a1, int a2, int a3, int p6, int p7, int arg7);
extern void func_80039794(void);
extern void func_80015BD8(u8 a0, u8 a1);
extern void func_80035B7C(void *a0);
extern void func_80032370(void);

void func_800339D0(void *arg0) {
    u8 *s0;
    u8 *v1;
    u8 *a0p;
    s32 v0;
    register s32 i asm("a1");

    if (func_80032B38((char *) arg0) == 0) {
        func_8003FEE0(8);
        if (func_80033998() != 0) {
            v0 = P_U16(arg0, 0x633E) | 0x4000;
            {
                register s32 flags asm("v0");
                register s32 tf asm("v1");
                flags = v0;
                tf = D_8009B2F8;
                P_U16(arg0, 0x633E) = (u16) flags;
                if (tf & 0x80) {
                    s0 = (u8 *) func_80035C38((void *) 0, 8, 0x28, 0x78, 0xF0, 0x10, 0x1028);
                    P_U8(s0, 0x59) = 0xA;
                } else {
                    register void *nullArg asm("a0");
                    nullArg = (void *) 0;
                    __asm__ __volatile__("" : "+r"(nullArg));
                    s0 = (u8 *) func_80035C38(nullArg, 9, 0x30, 0x60, 0xE0, 0x30, 0x20);
                P_U8(s0, 0x59) = 0xA;
                do {
                    func_80039794();
                } while (P_S32(s0, 0x30) == 0);
                }
            }
            func_80015BD8(0xA0, 2);
            v0 = D_8009AF76[0] - 8;
            D_8009B140[0] = (u8) v0;
        }
    }

    if (P_U16(arg0, 0x633E) & 0x4000) {
        a0p = (u8 *) arg0 + 0x5D98;
        func_80039794();
        {
        register s32 expected asm("v1");
        u8 *ebAddr;
        ebAddr = (u8 *) 0x800F0000;
        __asm__ __volatile__("" : "+r"(ebAddr));
        s0 = ebAddr - 0x4F08;
        v0 = P_S32(s0, 0x34);
        expected = 0x2000;
        if ((v0 & 0x2008) == expected) {
            u8 ff;
            func_80035B7C(s0);
            ff = 0xFF;
            if ((D_8009B2F8 & 0x80) == 0 && D_8009B34D[0] != 0) {
                P_U16(arg0, 0x633E) = P_U16(arg0, 0x633E) & 0xBFFF;
            } else {
                v0 = P_U16(arg0, 0x6340);
                P_U16(arg0, 0x633E) = (u16) v0;
                func_80015BD8(ff, 2);
            }
        }
        }
    } else {
        a0p = (u8 *) arg0 + 0x5D98;
        v1 = P_PTR(arg0, 0) + 0x50;
        for (i = 0; i < 0x2D2; i++) {
            *v1++ = *a0p++;
        }

        {
            u8 *a0b = (u8 *) P_PTR(arg0, 0);
            u8 *v1b;
            i = 0;
            v1b = (u8 *) arg0 + 0x2D54;
            do {
                P_U16(a0b, 0) = 0;
                if (P_U8(v1b, 9) != 0) {
                    P_U16(a0b, 0) = P_U16(v1b, 0);
                }
                a0b += 2;
                v1b += 0x10;
                i++;
            } while (i < 0x28);
        }

        func_80032370();
        P_U16(arg0, 0x633E) = 0;
    }
}

