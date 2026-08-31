/* PARKED CANDIDATE PORTED from Unchiga's tree (docs/MERGE_UNCHIGA.md).
 * Installed here because HIS base is closer than the one this tree
 * reached: the counts are in PARKED.txt. Measure it with the flags on
 * the next line -- they are his unit's, and try_func's default flags
 * report a different number.
 * FLAGS: -G0 -msplit-addresses
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Blacklist reclamation, 2026-08-28 (w2): 3/27 -> 0/27, G0:split.
   SPU voice-attribute setup: p = D_8009B458; p->f4C4 = 0x60100;
   p->f4C0 = D_80011434[idx]; p->f4FA/f4FC/f4E4 = rec->f20/f22/f24;
   func_80077450(&p->f4C0).

   THE LAST 3 WORDS WERE A LOAD-VERSUS-STORE ALIASING CONSTRAINT, not the
   prologue.  Four passes recorded the residual as "gcc hoists the ra-save
   into the slot target gives the D_8009B458 lw ... that is prologue
   placement, which no value-level lever reaches", and the sibling
   func_8004A764 sits on the identical residual.  The observation is exact.
   The diagnosis inverts cause and effect.

   The target's window is  lui v1 / lw v1 / lw v0 / ori / sw ra.  Ours was
   lui v1 / sw ra / lw v0 / lw v1 / ori.  gcc is not choosing to hoist the
   save -- it CANNOT SINK IT, because both loads are C loads and gcc will
   not move a load above a store it cannot disambiguate, and `sw ra,16(sp)`
   is exactly such a store.  So the save is pinned above the loads and the
   loads pile up after it.

   The fix is to stop the two loads being memory operations as far as gcc
   is concerned.  A NON-VOLATILE extended asm with no memory clobber is a
   pure computation to the scheduler, so it may float above the save:

     - emitting the D_8009B458 pointer load as asm moves `lw v1` up one
       slot (3/27, window {0x1c,0x24,0x28} -> {0x20,0x24,0x28});
     - emitting the table-value load as asm as well frees the save
       completely, and `ori` and `sw ra` both land correctly;
     - which then leaves the two asm loads free to reorder relative to each
       other, and gcc issues them in the wrong order.  A FAKE DEPENDENCY
       fixes it: the value load takes the pointer as an extra, unused input
       operand, so it cannot be scheduled before the pointer load.
           __asm__("lw %0, 0(%1)" : "=r"(val) : "r"(tp), "r"(p));
       That input is func_800738F0 by nothing in the asm text.  It exists purely to
       order the two statements.

   Each step alone is worth zero -- all three intermediate states score
   3/27 with DIFFERENT diff windows -- so this is a compose-or-nothing set
   like the earlier levers on this function.  Volatile is not a substitute
   for the fake dependency: it pins the load in place rather than ordering
   it, and scores 3.

   MEASURED MINIMAL: a 54-shape reduction sweep over every asm here.  The
   constant's high half does NOT need inline asm -- a plain `0x60000` plus
   the empty launder is byte-identical, so the `lui` asm earlier passes
   needed is now gone.  Still load-bearing, each verified by removal: the
   `addu` asm for the table index (target does addu a0,a0,v0 where the
   natural pointer expression canonicalises to addu a0,v0,a0), the launder
   on the loaded value, and the second name for the pointer. */

struct S8009B458 {
    char pad0[0x4C0];
    s32 f4C0;
    s32 f4C4;
    char pad1[0x4E4 - 0x4C8];
    s32 f4E4;
    char pad2[0x4FA - 0x4E8];
    u16 f4FA;
    u16 f4FC;
};

struct Rec {
    char pad[0x20];
    u16 f20;
    u16 f22;
    u16 f24;
};

extern struct S8009B458 *D_8009B458;
extern u8 D_80010538[16];
extern void func_80077450(void *a0);

void func_8004A6F8(s32 idx, struct Rec *rec)
{
    register struct S8009B458 *p __asm__("v1");
    struct S8009B458 *new_var;
    register u32 *tp __asm__("a0");
    register u32 val __asm__("v0");
    register u32 attrMode __asm__("a2");

    attrMode = 0x60000;
    __asm__("" : "+r"(attrMode));
    {
        u32 *tbase = (u32 *) (D_80010538 + 0xEFC);
        s32 scaled;
        __asm__("" : "+r"(tbase));
        scaled = idx * 4;
        __asm__("addu %0, %1, %2" : "=r"(tp) : "r"(scaled), "r"(tbase));
    }
    __asm__("lui %0, %%hi(D_8009B458)\n\t"
            "lw %0, %%lo(D_8009B458)(%0)" : "=r"(p));
    /* the "r"(p) input is unused by the asm text; it is a fake dependency
       that orders this load after the pointer load above */
    __asm__("lw %0, 0(%1)" : "=r"(val) : "r"(tp), "r"(p));
    __asm__("" : "+r"(val));

    p->f4C4 = attrMode | 0x100;
    new_var = p;
    new_var->f4C0 = val;
    new_var->f4FA = rec->f20;
    new_var->f4FC = rec->f22;
    new_var->f4E4 = rec->f24;
    func_80077450(&new_var->f4C0);
}
