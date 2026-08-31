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
   target      0x80040588
   sketch      func_80040588.c
   combo       G8:split
   ready-flags -G8 -msplit-addresses
   The flags this source was 0 diffs under. File it with:
     python3 tools/worklist.py ready 0x80040588 --unit UNIT --name NAME --flags "-G8 -msplit-addresses"
   msearch:winner-end */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Fresh untouched target (overseer-assigned). function_ranges.txt truncates
   this at 159 insns; scout.py dossier confirms the real span is 163 insns,
   0x80040588..0x80040814, merging 4 F entries (--exclude 0x80040804
   0x80040808 0x8004080C).

   Walks the D_800EFE48 active-slot chain from head D_800EFE3A (same
   0x70-stride Slot/f2-chain/f24-callback/f8&0xC0-gate shape as
   func_80040814.c, func_800400AC.c). For each
   qualifying slot it builds a GPU sprite packet in scratchpad (0x1F800320,
   same DigitPacket-style layout as func_80016E70.c, extended with
   unk18/unk1C/unk20 this function alone uses), optionally repositions it
   via func_80041F90(slot, x, y, out) -- the same landed func_80041F90.c,
   called with `slot` itself as its `struct Obj *obj` (confirmed: a0 is set
   from `addu a0,s0,zero` in the branch's own delay slot, NOT the earlier
   f14 func_800738F0 visible textually before it, which gets clobbered) -- and
   dispatches the packet via func_80042188 (asm_allowed, 0-diff
   hand-transcribed, same 5-arg (packet,target,handler,flags,pos) shape
   documented in func_80016784.c's header). A retry-in-place loop (goto to
   the slot's own top) fires when func_80041F90's callback sets D_8009B424
   nonzero; three different paths compute the final `flags` (a3) argument
   differently (0x10000|f14 unmodified from early in the slot, vs
   0xF0000|f14 after a successful reposition, vs 0x30000|f14 on the
   plain/no-reposition path) before converging on the one shared
   func_80042188 call site. */

struct Slot {
    u16 f0;
    u16 f2;
    u32 f4;
    u16 f8;
    u8 fA;
    u8 fB;
    u32 fC;
    u32 f10;
    u16 f14;
    u8 f16;
    u8 f17;
    s16 f18;
    s16 f1A;
    u8 pad1C[0x22 - 0x1C];
    u8 f22;
    u8 pad23[0x24 - 0x23];
    void (*f24)(void *);
    u8 pad28[0x30 - 0x28];
    u32 f30;
    u8 pad34[0x3C - 0x34];
    u32 f3C;
    u32 f40;
    u32 f44;
    u32 f48;
    u8 pad4C[0x5C - 0x4C];
    u16 f5C;
    u8 pad5E[0x66 - 0x5E];
    u8 f66;
    u8 pad67[0x70 - 0x67];
};

struct Scratch {
    u32 unk0;
    u16 unk4;
    u16 unk6;
    u32 unk8;
    u16 unkC;
    u16 unkE;
    u32 unk10;
    u32 unk14;
    u16 unk18;
    u16 unk1A;
    u32 unk1C;
    u32 unk20;
};

extern s16 D_800EFE3A[16];
extern struct Slot D_800EFE48[];
extern s32 D_800E9D90[];
extern u16 D_8009B146[];
extern u16 D_8009B148[];
extern s32 D_8009B424;

extern s32 func_80041F90(void *obj, s32 arg1, s32 arg2, void *out);
extern void func_80042188(void *packet, void *target, s32 handler, s32 flags, void *pos);
extern void func_80082840(void *a0, s32 a1);

#define SCRATCH ((struct Scratch *) 0x1F800320)
#define TARGET ((u8 *) 0x1F800344)
#define POS ((void *) 0x1F800398)

void func_80040588(void) {
    register s32 idx asm("s3") = D_800EFE3A[0];
    struct Scratch *scratch;
    u8 *target;
    u8 *posBase;
    register s32 *handlerTable asm("s6");

    if (idx < 0) {
        return;
    }

    target = TARGET;
    scratch = SCRATCH;
    posBase = (u8 *)0x1F800378;
    __asm__ __volatile__(
        "lui $v0, 0x800f\n\taddiu %0, $v0, -25200"
        : "=r"(handlerTable)
        :
        : "v0");

    do {
        register s32 recOff asm("v1");
        register struct Slot *recBase asm("v0");
        struct Slot *rec;
        s32 handler;
        s32 flags;
        register s32 flagRaw asm("a0");
        register s32 flagMask asm("v1");

        recOff = (idx * 8 - idx) * 16;
        recBase = D_800EFE48;
        rec = (struct Slot *)((u8 *)recBase + recOff);

        idx = (s16) rec->f2;

    retry:
        if (rec->f24) {
            rec->f24(rec);
        }

        if (((rec->f8 & 0xC0) ^ 0xC0) != 0) {
            goto loop_tail;
        }

        scratch->unk0 = rec->f4;
        __asm__ __volatile__(
            "lw $v0, 12(%3)\n\t"
            "lbu $v1, 23(%3)\n\t"
            "sw $v0, 20(%4)\n\t"
            "lw $v0, 48(%3)\n\t"
            "nop\n\t"
            "sw $v0, 4(%4)\n\t"
            "lw $v0, 60(%3)\n\t"
            "nop\n\t"
            "sw $v0, 8(%4)\n\t"
            "lw $v0, 64(%3)\n\t"
            "sll $v1, $v1, 2\n\t"
            "sw $v0, 16(%4)\n\t"
            "lhu $v0, 92(%3)\n\t"
            "addu $v1, $v1, %5\n\t"
            "sh $v0, 14(%4)\n\t"
            "lbu $v0, 102(%3)\n\t"
            "lhu %1, 20(%3)\n\t"
            "lw %0, 0($v1)\n\t"
            "lui %2, 1\n\t"
            "sh $v0, 12(%4)"
            : "=r"(handler), "=r"(flagRaw), "=r"(flagMask)
            : "r"(rec), "r"(scratch), "r"(handlerTable)
            : "v0", "memory");
        flags = flagRaw | flagMask;

        if (!(rec->f8 & 8)) {
            __asm__ __volatile__(
                "lhu $v0, 4(%0)\n\t"
                "lui $a0, 0x800a\n\t"
                "lhu $a0, -20154($a0)\n\t"
                "lhu $v1, 6(%0)\n\t"
                "lui $a1, 0x800a\n\t"
                "lhu $a1, -20152($a1)\n\t"
                "subu $v0, $v0, $a0\n\t"
                "subu $v1, $v1, $a1\n\t"
                "sh $v0, 4(%0)\n\t"
                "sh $v1, 6(%0)"
                :
                : "r"(scratch)
                : "v0", "v1", "a0", "a1", "memory");
        }

        if (rec->f8 & 4) {
            s32 a1 = (s16)scratch->unk4 + rec->f18;
            s32 a2 = (s16)scratch->unk6 + rec->f1A;
            s32 ret;

            D_8009B424 = 0;
            ret = func_80041F90(rec, a1, a2, posBase + 0x20);
            if (ret <= 0) {
                goto loop_tail;
            }
            if (D_8009B424 != 0) {
                goto retry;
            }

            target[3] = 9;
            *(u32 *) (target + 4) = scratch->unk14;
            target[7] = 0x2C;
            if (scratch->unk0 & 0x40000000) {
                func_80082840(target, 1);
            }

            flags = rec->f14 | 0xF0000;
            goto dispatch;
        }

        if (scratch->unk0 & 0x8000000) {
            goto dispatch;
        }

        scratch->unk20 = rec->f22 * 45 * 128;
        scratch->unk1C = rec->f44;
        *(u32 *)&scratch->unk18 = rec->f48;
        scratch->unk4 = scratch->unk4 + scratch->unk18;
        scratch->unk6 = scratch->unk6 + scratch->unk1A;
        flags = rec->f14 | 0x30000;

    dispatch:
        func_80042188(scratch, target, handler, flags, posBase + 0x20);

    loop_tail:;
    } while (idx >= 0);
}
