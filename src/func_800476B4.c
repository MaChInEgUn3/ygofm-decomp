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

/* Appends a batch of sound events to the mixer's pending-entry table. The
   argument block starts with the entry count; the ids sit two bytes apart from
   +8 and the 8-byte payloads eight bytes apart from +0x1A0. For each entry
   whose id is not the 0xFFFF skip sentinel it records the id's slot in the
   lookup array f43C, copies the payload into the next free f444 entry, biases
   that entry's f6 by the caller's rate (the high 28 bits of a1), and bumps the
   fill index f440.

   MATCHED 0/53, -G0 -mno-split-addresses --keep-large-ori, w1 2026-08-29,
   from a banked 43/53 and an 11/53 near-miss. Pure C, no inline asm.

   THIS UNIT NEEDS --keep-large-ori: the sentinel is a genuine
   `ori $t3,$zero,0xffff` (0xFFFF >= 0x8000), and without the flag ccpsx.sh
   rewrites it to a sign-extending `addiu`.

   THREE THINGS CLOSED IT, and each retired a standing "source cannot reach
   this" verdict on this address.

   1. LOOP ROTATION (43 -> 16 -> 11). The ROM's pre-guard block is only
      `move t1,a0 / lw v0,0(t1) / nop / blez / move a3,zero`, and the tell is
      that unfilled load-delay nop: four instructions were available to fill
      it and none did, so they were not in that block -- they were in the loop
      PREHEADER, and gcc 2.8.1 never sinks into one. So `i = 0;` goes OUTSIDE
      the guard (it is the branch's delay slot, which runs either way) and
      everything else inside it, with a `do {} while` re-reading the count at
      the bottom. An `if (count <= 0) return;` guard instead duplicates the
      count func_800738F0 and costs 35 words.

   2. TWO dst POINTERS, NOT ONE REASSIGNED (11 -> 3). The func_8008E390 destination
      and the f6-update pointer live in different registers for their whole
      lives in the ROM ($v0 and $v1), and one C variable cannot express that.
      Writing the post-copy recompute through a separate `dstB` closes an
      eight-word cluster -- the addu, the swl/swr pair and the following
      lhu/lw/sll -- that four earlier passes had filed as a commutative-operand
      or "register-role swap immune to source hints" problem.
      Related and worth keeping: the ROM's `addu v0,v0,v1` func_8008FAF0 the SHIFT
      first, and the C front end discards that -- `pointer_int_sum()` always
      builds PLUS_EXPR(ptr,int), so `(u8*)f444 + slot*8` and `slot*8 + (u8*)f444`
      are the same tree. Doing the addition in integer type,
      `(struct Entry *)(slot440 * 8 + (s32)f444)`, really does swap the
      operands -- but on its own it is worth zero, because local-alloc still
      ties the destination to the other operand. It only pays with `dstB`.

   3. PIN THE SENTINEL (3 -> 0). The last three words were a rotation of four
      register-only preheader instructions: the ROM has
      `li t3,0xffff / srl t2 / move t0 / move a2` and every candidate put the
      `li` LAST whatever the source said. It was not a preheader statement at
      all -- cse propagated 0xFFFF into the in-loop compare and loop.c hoisted
      it back out as a MOVABLE, and move_movables emits at loop_start, i.e.
      after everything already there. A hard-register local is not a movable,
      so `register s32 sentinel asm("t3")` (compared against directly in the
      loop) keeps it an ordinary preheader statement whose position the source
      controls. Three asm launders on the same value were all measured WORSE:
      the lever is the pin, not opacity.

   MEASURED DEAD: the indexed-loop rewrite (`base + i*2 + 8` /
   `base + i*8 + 0x1A0`, no walker at all) is 46/53 at 54w across three
   spellings of each func_800738F0 -- so unlike its sibling func_8005C388,
   this function's two walking pointers really are source-level, not gcc givs.
   Full history and the dead-lever list: match/sketches/func_800476B4_v2.c. */

struct Entry {
    char pad[6];
    u16 f6;                     /* 0x06 */
};

struct S8009B45C {
    char pad0[0x43C];
    u16 *f43C;                  /* 0x43C  id -> slot lookup */
    u16 f440;                   /* 0x440  fill index into f444 */
    char pad1[2];
    struct Entry *f444;         /* 0x444  entry table */
};

extern struct S8009B45C *D_8009B45C;

void func_800476B4(void *a0, u32 a1) {
    register s32 i asm("a3");
    u8 *base = (u8 *)a0;

    i = 0;
    if (*(s32 *)base > 0) {
        u8 *payloadBase;
        register u8 *idBase asm("a2");
        u32 rate;
        register s32 sentinel asm("t3");

        sentinel = 0xFFFF;
        rate = a1 >> 4;
        payloadBase = base;
        idBase = base;

        do {
            u16 id = *(u16 *)(idBase + 8);

            if (id != sentinel) {
                register struct S8009B45C *g asm("a1") = D_8009B45C;

                g->f43C[id] = g->f440;

                {
                    u16 slot440 = g->f440;
                    struct Entry *f444 = g->f444;
                    register struct Entry *dst asm("v0") =
                        (struct Entry *)(slot440 * 8 + (s32)f444);
                    register struct Entry *dstB asm("v1");
                    register struct S8009B45C *g2 asm("a0") = g;

                    __builtin_memcpy(dst, payloadBase + 0x1A0, 8);
                    dstB = (struct Entry *)(g2->f440 * 8 + (s32)g2->f444);
                    dstB->f6 = dstB->f6 + rate;
                    g2->f440 = g2->f440 + 1;
                }
            }

            payloadBase += 8;
            idBase += 2;
            i++;
        } while (i < *(s32 *)base);
    }
}
