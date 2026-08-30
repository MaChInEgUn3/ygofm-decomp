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

extern int func_8007D3F0(void *file, int arg);

/* Thin wrapper around the PsyQ CD-ROM directory lookup func_8007D3F0, called
 * with this wrapper's own two arguments in the opposite order
 * (arg, file) -> func_8007D3F0(file, arg), and mapping the library's result to
 * a simple status: -1 when the lookup returned 0 (not found) or -1 (error),
 * 0 otherwise.
 *
 * Two register pins are load-bearing here and both were confirmed by cmp.sh
 * rather than guessed:
 *   - the call result lives in $v1 (gcc's unpinned choice is $a0, the
 *     wrapper's own first-parameter register, dead once its value has been
 *     consumed as the call's second argument).  Pinning it took 4/16 -> 2/16.
 *   - the -1 the second comparison tests against lives in $v0 (gcc's unpinned
 *     choice is $a0 again).  Pinning that too took 2/16 -> 0/16.
 * An earlier pass pinned this second value to $a0 -- i.e. to the register the
 * candidate was already using -- and correctly observed no change; the header
 * it left behind had the two disassembly columns transposed, which is what
 * made the residual look unreachable.  The target's instruction is
 * `addiu $v0,$zero,-1` in the beqz delay slot.
 *
 * 22 unpinned shapes (renamed locals, explicit ptr/len intermediates,
 * cast-through-int, `long` result, Yoda comparisons, two-name aliases, a named
 * `neg1` constant, a dead `a0 = 0;` func_80073900, the ||-form range check, and the
 * flat if-return chain) all sit at 4/16 or worse; see
 * match/sketches/ds_search_file_swapped_8005c4f0.c.
 */
int func_8005C4F0(int arg, void *file) {
    register int result asm("v1") = func_8007D3F0(file, arg);
    register int neg1 asm("v0") = -1;

    if (result != 0) {
        if (result != neg1) {
            return 0;
        }
    }
    return -1;
}
