/* MATCH 2026-09-05, pure C at default -O2 -G8 with the assembler at -G0
 * (PER_FUNC_AS_FLAGS) and D_8009B361 on its scalar arm. Replaces a
 * transcription. The candidate had sat at 8 of 10 (every register name)
 * with D_8009B361 as an unsized array: retail loads the one-byte selector
 * self-referencing through $a0 -- the bare form -- and forms the table base
 * in $v0 FIRST, straddling that load with cc1psx's own pair. The bare
 * symbol is one instruction to the scheduler and cannot be reordered
 * against the pair, which is what puts every register where retail has it.
 * The listing has no %gp_rel, so `as -G0` is free (WORKFLOW step 0).
 */
#define D_8009B361_IN_DATA
#include "common.h"

s8 func_80070710(void) {
    return *(s8 *)&D_800917F0[D_8009B361 * 9];
}
