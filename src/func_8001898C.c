/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
/* msearch:winner-begin
   target      0x8001898C
   sketch      func_8001898C_wip.c
   combo       G8:split
   ready-flags -G8 -msplit-addresses --keep-large-ori
   The flags this source was 0 diffs under. File it with:
     python3 tools/worklist.py ready 0x8001898C --unit UNIT --name NAME --flags "-G8 -msplit-addresses --keep-large-ori"
   msearch:winner-end */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

typedef struct {
    u8 pad0[8];
    void *unk8;
    u16 unkC;
} S800E9F10;

typedef struct {
    void *unk0;
    u8 pad1[0x16 - 4];
    u16 unk16;
    u8 pad2[0x1C - 0x18];
} TableEntry;

typedef struct {
    u8 pad0[0x40];
    s16 unk40;
} Placeholder;

typedef struct {
    u8 pad0[0x1A];
    s16 unk1A;
} Obj;

extern u16 D_8009B23A;
extern u8 D_8009B1D5;
extern u8 D_8009B1EC;
extern u16 D_8009B162;
extern s8 *D_8009B1C8;
extern S800E9F10 *D_8009B1B4;
extern Obj *D_8009B1F0[2];
extern Placeholder *D_8009B21C;
extern u8 D_800E9FF0[64];
extern S800E9F10 D_800E9F10[];
extern void *D_800EA030[];
extern TableEntry D_801A7AD8[];

extern void func_800176D0(void);
extern void func_80018080(void *a0);
extern void func_800249E0(s32 a0, s8 a1);
extern void *func_80018004(void *a0, s32 a1, s32 a2);

void func_8001898C(void) {
    u8 a0;
    u16 v1;
    s32 i;
    TableEntry *s2;
    u16 *s0;
    s8 sp10[5];
    Obj *obj;
    s32 s3;
    void **s6;
    register s32 s0_2 asm("s0");
    s32 s5;
    TableEntry *s2_2;
    TableEntry *s4;
    s32 a0_2;
    s8 *a1p;
    s8 *bytePtr;
    void **eaTable;

    if (!(D_8009B23A & 0x8000)) {
        D_8009B23A = D_8009B23A | 0x8000;
        D_8009B21C->unk40 = (s16) ((D_8009B1D5 * 0x10) | 0x2E0);
        func_800176D0();
        a0 = D_8009B1D5;
        D_8009B1C8 = (s8 *) (D_800E9FF0 + (a0 << 5));
        D_8009B1B4 = (S800E9F10 *) ((u8 *) D_800E9F10 + a0 * 0x70);
        eaTable = D_800EA030;
        D_8009B1B4->unk8 = eaTable;
        if (D_8009B1C8[0x19] != 0) {
            s8 tmp19 = D_8009B1C8[0x19] - 1;
            D_8009B1C8[0x19] = tmp19;
            if (tmp19 <= 0) {
                D_8009B1C8[0x19] = 0;
                obj = D_8009B1F0[D_8009B1D5];
                obj->unk1A = (s16) (0xFFFD - D_8009B1D5);
                D_8009B1F0[D_8009B1D5] = 0;
            }
        }
        s2 = D_801A7AD8;
        i = 0;
        s0 = (u16 *) ((u8 *) D_801A7AD8 + 0x16);
        D_8009B1C8[1] += 1;
        do {
            v1 = *s0;
            if (v1 & 0x8000) {
                *s0 = v1 & 0xBFFF;
                func_80018080(s2->unk0);
                i += 1;
                __asm__ volatile("" ::: "memory");
                s0 = (u16 *) ((u8 *) s0 + 0x1C);
            } else {
                *s0 = 0;
                i += 1;
                s0 = (u16 *) ((u8 *) s0 + 0x1C);
            }
            s2 = (TableEntry *) ((u8 *) s2 + 0x1C);
        } while (i < 0x1E);

        for (i = 0; i < 5; i++) {
            register u8 copiedByte asm("v1");

            bytePtr = D_8009B1C8;
            bytePtr += i;
            copiedByte = bytePtr[0x1A];
            sp10[i] = copiedByte;
            bytePtr = D_8009B1C8;
            bytePtr += i;
            bytePtr[0x1A] = -1;
        }

        s3 = 0;
        i = s3;
        s6 = eaTable;
        s5 = 0xE;
        {
            register s32 playerCalc asm("v1");
            register s32 mulTmp asm("v0");

            playerCalc = D_8009B1D5;
            mulTmp = playerCalc << 4;
            s0_2 = mulTmp - playerCalc;
        }
        s2_2 = (TableEntry *)((u8 *)D_801A7AD8 + s0_2 * 0x1C);
        s4 = s2_2;
        do {
            a1p = &sp10[i];
            s2_2->unk16 = 0;
            s2_2->unk0 = 0;
            a0_2 = s0_2;
            if (*a1p >= 0) {
                s0_2 += 1;
                bytePtr = D_8009B1C8;
                bytePtr += s3;
                bytePtr[0x1A] = (u8)*a1p;
                s3 += 1;
                func_800249E0(a0_2, *a1p);
                *s6 = func_80018004(s4, s5, 0x292);
                s6 = (void **) ((u8 *) s6 + 0xC);
                s5 += 0x3C;
                s4 = (TableEntry *) ((u8 *) s4 + 0x1C);
            }
            i += 1;
            s2_2 = (TableEntry *) ((u8 *) s2_2 + 0x1C);
        } while (i < 5);

        D_8009B1EC = (u8) (5 - s3);
        D_8009B162 = 2;
        a0 = D_8009B1D5;
        D_8009B1B4 = (S800E9F10 *) ((u8 *) D_800E9F10 + a0 * 0x70);
        D_8009B1B4->unkC = 0xAE;
        return;
    }
    if (D_8009B162 == 0) {
        D_8009B23A = 3;
    }
}

