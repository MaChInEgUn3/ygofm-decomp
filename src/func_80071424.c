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

/* Store the signed byte at D_8009B361 into the D_800F5B98 word array, at the
   index func_8007058C returns. Fifteen words, one call and one store.

   THE RESIDUAL WAS THE DESTINATION OF THE ADDRESS ADD, NOT ITS OPERANDS.
   Target `addu v0,v0,v1` then `sw a0,0(v0)`; gcc emits `addu v1,v0,v1` /
   `sw a0,0(v1)`. Operand order agrees -- only which of the two dead inputs
   the sum is allowed to overwrite differs, and the store follows it. The
   sixteen index/pointer spellings already in the sketch all sit at 2/15 or
   worse, so nothing about how the store is written reaches this.

   Naming the base in its own variable makes it WORSE, and that is worth
   knowing before trying it: `int *base = D_800F5B98; int *p = base + idx;`
   moves the lui/addiu pair relative to the sll and goes to 6/15, as does
   keeping the base live past the add with an empty launder -- which is the
   lever that closed the same-shaped `addu` in func_80035700. The two
   functions look like one family and are not: there the destination was the
   parameter's own register and liveness decided it; here both inputs are
   dead and the choice is plain allocation order.

   What works is pinning the base pointer to $v1, which is the register it
   already occupies. The pin does not change where the base lives -- it
   changes what the allocator may reuse for the sum, so the sum falls to $v0
   and the store addresses through it. 0/15. Reusing one variable for the
   index and then the address, and pinning that instead, is 3/15: it fixes
   the add and breaks the address materialisation above it. */

extern s32 func_8007058C(void);
extern s32 D_800F5B98[];
extern s8 D_8009B361[];

void func_80071424(void) {
    register s32 *p asm("v1");
    s32 idx;

    idx = func_8007058C();
    p = D_800F5B98;
    p += idx;
    *p = D_8009B361[0];
}
