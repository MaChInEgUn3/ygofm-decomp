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

/* If level>=2, return val unchanged. Else fills a local struct via
   func_80059000(level, &local), reads local.f6 (clamped to a minimum of
   50), subtracts 300 to get delta; if delta!=0, adjusts val by
   (delta * half) / 750, where half is val itself for delta<=0 or
   val rounded toward zero by half (the classic signed-div-by-2 rounding
   trick) for delta>0. */

struct Local {
    char pad[6];
    s16 f6;
};

extern void func_80059000(s32 level, struct Local *out);

s32 func_8005F1B8(s32 level, s32 val) {
    struct Local local;
    s16 delta;

    if (level >= 2) {
        return val;
    }

    func_80059000(level, &local);

    if (local.f6 < 50) {
        local.f6 = 50;
    }

    local.f6 -= 300;
    delta = local.f6;

    if (delta != 0) {
        s32 divisor = 750;
        s32 half = val;
        if (delta > 0) {
            half = (s32)(val + ((u32)val >> 31)) >> 1;
        }
        val += (delta * half) / divisor;
    }

    return val;
}
