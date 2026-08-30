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

/* Starts a CD func_800738F0 for stream entry `idx` and hands the header off to the
   decoder. D_8009151C is a table of {u16 size; u16 speed;} records: if this
   entry carries a speed override it replaces the caller's, then the sizes of
   all preceding entries are summed to give the entry's byte offset into the
   stream. func_8007E600 starts the func_800738F0 at D_800E9EB4 + offset into an 8-byte
   stack buffer, func_8007E710 parses that header, and func_8005B8A0 receives
   the parsed value plus this entry's own size.

   MATCHED 0/55, -G0 -msplit-addresses, w1 2026-08-29, from a banked 11/55.
   The one inline asm is EMPTY and emits no instructions.

   Both globals must be absolute -- -G8 gives 55/55 -- and `speed` is s32, not
   u16: the target passes it on with a plain `move a2,s1`, where a u16 costs an
   `andi a2,s1,0xffff`.

   TWO LEVERS, and BOTH refute a claim in this function's own banked header,
   which is why they are spelled out.

   1. THE LOOP WALKER IS A gcc INDUCTION VARIABLE (6 words). The banked header
      said "the loop's walking pointer must be a SEPARATE $v1-pinned local,
      which is what produces target's `move v1,a1`". It must NOT: that pin is
      exactly what kept the table base in $v1 and the indexed entry in $a0,
      mirrored from the ROM. Written as a plain indexed loop with no walker at
      all, gcc strength-reduces it and emits `move v1,a1` as the giv's own
      preheader init, which frees $a1 for the base -- the ROM's assignment.
      (Opposite answer to func_800476B4 the same day, where the indexed rewrite
      is 46/53 and the walkers really are source-level. Walker-vs-index is
      per-function evidence; LOOP-1's `-dL` dump settles it in one compile.)

   2. THE SECOND TABLE MATERIALISATION WANTS $a1 (5 words). The ROM uses $a1 as
      the scratch for D_8009151C and only afterwards loads it with arg1, because
      that `move a1,s2` anti-depends on the `addu v1,v1,a1` that reads the
      scratch. Pinning the second table pointer to $a1, with the func_8007E710
      result held in its own temp first, reproduces it. This bounds the banked
      note's "`register ... *base asm(\"a1\")` costs a word, 36/55": that was a
      pin on the FIRST materialisation; on the SECOND it is free.

   3. THE LAST THREE WORDS were a rotation -- the ROM has
      `addiu a0,sp,24 / lui a1,0x8009 / addiu a1,a1,5404` and every candidate
      put the `addiu a0` last. `b` below is a DEAD $a0-pinned local: assigning
      it emits that `addiu a0,sp,24`, and the empty `asm volatile("")` after it
      is what keeps it there, splitting the scheduling region so the table
      address cannot be emitted ahead of it. The call still passes `buf`
      directly. Do not remove either half -- together they are the instruction,
      and dropping either gives 3/55. Assigning `b` WITHOUT the barrier is also
      3/55, measured; the barrier is the whole lever.

   Sketch, the four-arm dead-lever list and the earlier corrected `//@ target`
   warning: match/sketches/lookup_speed_and_start_read_v2.c. */

struct SpeedEntry {
    u16 f0;                     /* 0x00  entry size in bytes */
    u16 f2;                     /* 0x02  speed override, 0 = keep caller's */
};

extern struct SpeedEntry D_8009151C[64];
extern s32 D_800E9EB4;

extern void func_8007E600(s32 pos, void *buf, s32 len);
extern s32 func_8007E710(void *buf);
extern void func_8005B8A0(void *buf, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);

void func_8005C388(s32 idx, s32 arg1, s32 speed, s32 arg3,
                                 s32 arg4) {
    s32 buf[2];
    struct SpeedEntry *base;
    struct SpeedEntry *e;
    s32 i;
    s32 total;

    base = D_8009151C;

    e = &base[idx];
    if (e->f2 != 0) {
        speed = e->f2;
    }
    i = 0;
    total = 0;
    if (idx > 0) {
        do {
            total += base[i].f0;
            i += 1;
        } while (i < idx);
    }
    func_8007E600(D_800E9EB4 + total, buf, total);
    {
        register struct SpeedEntry *t2 asm("a1");
        register void *b asm("a0");
        s32 t;

        t = func_8007E710(buf);

        /* dead $a0 local + barrier: emits the ROM's `addiu a0,sp,24` ahead
           of the table address and pins it there -- see the header */
        b = buf;
        __asm__ volatile ("");

        t2 = D_8009151C;
        t += t2[idx].f0;
        func_8005B8A0(buf, arg1, speed, t, arg3, arg4);
    }
}
