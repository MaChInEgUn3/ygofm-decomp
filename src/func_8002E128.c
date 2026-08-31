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

typedef struct { char pad0[8]; u16 unk8; char pad1[0x26]; s16 unk30; s16 unk32; } SubObj;
typedef struct { char pad0[4]; s32 unk4; u16 unk8; } InnerObj;
typedef struct {
    InnerObj *unk0; u16 unk4; char pad1[0xA]; u8 unk10; char pad2[3];
    SubObj *unk14; char pad3[0x10]; SubObj *unk28; s16 unk2C;
    char pad4[0xE]; s16 unk3C;
} Obj;

extern u8 D_80090BA8[];
extern u8 D_80090C00[];
extern s32 func_8004002C(void);
extern void func_8002E060(void *arg0, s32 arg1, s32 arg2);
extern void func_80040510(void *arg0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9);
extern InnerObj *func_800400AC(s32 arg0, s32 arg1);

void func_8002E128(Obj *arg0, s32 arg1) {
    register s32 s1 asm("s1");
    s32 row;
    register InnerObj *s0 asm("s0");
    register u8 *tab1 asm("s0");

    s1 = arg1;
    if (s1 < 0) s1 = arg0->unk3C;
    arg0->unk3C = s1;
    if (s1 >= 0x200) {
        s0 = func_800400AC(func_8004002C(), 3);
        func_80040510(s0, 0, 0, 0x200, 0x100, 0, 0, 0x10, 0, 0xF0);
        __asm__ __volatile__(
            "sra $v0,$s1,4\nandi $v0,$v0,15\nsll $v1,$v0,2\naddu $v1,$v1,$v0\n"
            "sll $v1,$v1,1\nandi $v0,$s1,15\naddu $s1,$v1,$v0\nlui $a0,0x100\n"
            "lw $v0,4($s0)\nlhu $v1,8($s0)\nor $v0,$v0,$a0\nandi $v1,$v1,0xfff7\n"
            "sw $v0,4($s0)\nli $v0,1\nsh $v1,8($s0)\nsll $v1,$s1,1\n"
            "addu $v1,$v1,$s1\nsll $v1,$v1,1\nsb $v0,16(%2)\n"
            "lui $v0,%%hi(D_80090C00)\naddiu $v0,$v0,%%lo(D_80090C00)\n"
            "sw $s0,0(%2)\naddu $s0,$v1,$v0"
            : "+r" (s0), "+r" (s1) : "r" (arg0) : "$2", "$3", "$4", "memory");
        tab1 = (u8 *)s0;
        arg0->unk4 = 0;
        if (tab1[0] & 1) {
            func_8002E060((u8 *)arg0 + 0x14, 0x14, 1);
            arg0->unk14->unk30 = tab1[1]; arg0->unk14->unk32 = tab1[2];
        }
        if (tab1[0] & 2) {
            func_8002E060((u8 *)arg0 + 0x28, 0x16, 2);
            arg0->unk28->unk30 = tab1[3]; arg0->unk28->unk32 = tab1[4];
            arg0->unk2C = tab1[5];
            if (tab1[0] & 0x80) { arg0->unk28->unk8 |= 8; return; }
        }
    } else {
        func_8002E060(arg0, 0x10, 0);
        if (s1 >= 0x100) {
            register u8 *tab2 asm("s0"); register u8 flag2 asm("s1");
            register s32 hi asm("v1"); register s32 idx asm("v0");
            register u8 *base2 asm("v1");
            hi = (s1 >> 4) & 0xF; idx = hi * 10; hi = s1 & 0xF; idx += hi;
            __asm__ __volatile__("" : "+r" (idx));
            base2 = D_80090BA8; idx *= 2;
            __asm__ __volatile__("" : "+r" (idx));
            tab2 = base2 + idx; flag2 = tab2[0];
            if (flag2 & 1) func_8002E060((u8 *)arg0 + 0x14, 0x12, 1);
            { s32 bit2 = flag2 & 2; __asm__ __volatile__("" : "+r" (flag2));
              if (bit2) { func_8002E060((u8 *)arg0 + 0x28, 0x14, 2); arg0->unk2C = tab2[1]; return; } }
            return;
        }
        arg0->unk14 = 0; arg0->unk28 = 0;
    }
}
