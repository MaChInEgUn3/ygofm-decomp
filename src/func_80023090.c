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

/* func_80023090 (0x80023090, 45 words).  Sole caller: 0x80023394.
 *
 * Compare the field records under two cursors.  Each cursor carries a grid
 * position (col at 0xF, row at 0x10); D_800907D8 is a byte grid of 5-wide
 * rows, paged by D_8009B1D5 (0 or 1) at 20 bytes per page, so
 *
 *     slot = D_800907D8[row * 5 + col + D_8009B1D5 * 20]
 *
 * is the field-slot number under a cursor.  Those two slot numbers index the
 * 0x1C-stride record table D_801A7AD8, and func_8001EE44 orders the two
 * records.  Returns 4 when they compare equal, 1 when the first is lower,
 * and 6 otherwise.
 *
 * WHY THE THREE HARD-REGISTER LOCALS AND THE BARRIER (all zero words -- none
 * of them emits an instruction; each one only decides a register or a
 * placement, and the function is 0/45 with them and 6..27/45 without):
 *
 *   table1/table2 in $t1/$a3   The two table bases are materialised into the
 *     prologue in the ROM's own registers; unpinned, gcc picks others and
 *     the whole prologue plus `sw ra` shifts (33/45 -> 29/45 when these two
 *     pins were first added).
 *   d20 in $a2   `D_8009B1D5 * 20` is shared by both index expressions and
 *     the ROM keeps it in $a2 across the first table load.  Without the pin
 *     it lands in $v1 and trades places with `brow`, which costs six words.
 *   off1 in $a0   The scaled offset `slot1 * 0x1C`.  $a0 arrives holding the
 *     first cursor pointer, is dead after the `lb` of its col, and the ROM
 *     reuses it first for D_8009B1D5 and then for this offset.  Pinning it
 *     is what pulls the last `sll` of the x8/-x1/x4 sequence up next to the
 *     other two: sched2 ranks that group above the second index's sum (its
 *     chain is three loads deep against one) and emits backwards, so without
 *     a name of its own the tail insn is dragged past the whole sum.
 *   the empty `asm volatile` memory barrier   holds the D_8009B1D5 func_800738F0
 *     below the table-base setup instead of letting it float to the top.
 *
 * Both index sums need their OWN named accumulator (acc0, acc1): written as
 * bare subexpressions, fold reassociates the second one so that `+ col` and
 * `+ D_8009B1D5 * 20` trade places.  One shared accumulator assigned twice is
 * worse than two -- it lengthens the live range across the first table load.
 */

struct Cursor {
    char pad0[0xF];
    s8 col;  /* 0xF  */
    s8 row;  /* 0x10 */
};

struct FieldRecord {
    char pad0[0x16];
    u16 f16;
    char pad1[0x1C - 0x18];
};

extern u8 D_800907D8[];
extern struct FieldRecord D_801A7AD8[];
extern u8 D_8009B1D5;
extern s32 func_8001EE44(struct FieldRecord *, struct FieldRecord *);

s32 func_80023090(struct Cursor *cursorA, struct Cursor *cursorB) {
    register u8 *grid asm("t1") = D_800907D8;
    register struct FieldRecord *records asm("a3") = D_801A7AD8;
    s32 slotA;
    s32 slotB;
    s32 order;
    struct FieldRecord *recA;
    struct FieldRecord *recB;
    s32 accA;
    s32 accB;
    s32 rowB;
    register s32 page asm("a2");
    s32 side;
    register s32 offA asm("a0");

    __asm__ volatile("" ::: "memory");
    rowB = cursorB->row;
    accA = cursorA->row * 5 + cursorA->col;
    side = D_8009B1D5;
    page = side * 20;
    slotA = grid[accA + page];
    offA = slotA * 0x1C;
    recA = (struct FieldRecord *) ((u8 *) records + offA);
    accB = rowB * 5 + cursorB->col;
    slotB = grid[accB + page];
    recB = &records[slotB];

    order = func_8001EE44(recA, recB);

    if (order == 0) {
        return 4;
    }
    if (order < 0) {
        return 1;
    }
    return 6;
}
