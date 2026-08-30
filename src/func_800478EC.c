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

/* D_8009B45C's struct, viewed for the 4 fields this function touches
   (0x424/0x428/0x42C/0x434 -- inside m2c_types.h's S8009B45C pad_411[0x27]
   gap; see src/s8009b45c_init.c's header for the struct's other named
   fields). Per one of 4 SPU voice slots i (bit mask 1<<(20+i), matching the
   0xF00000 4-voice group used elsewhere, e.g. src/retry_spu_key_until_
   nonzero.c): f424[i]/f428[i] are a countdown-goal/countdown-progress pair,
   f42C[i] is an independent u16 timer, and f434 is a per-slot active-bit
   byte (bit i per slot). */
struct S8009B45C_pad {
    char pad[0x424];
    u8 f424[4];
    u8 f428[4];
    u16 f42C[4];
    u8 f434;
};

extern struct S8009B45C_pad *D_8009B45C;
extern void func_80047864(s32 idx);
extern void func_80076ED0(s32 a0, u32 a1);
extern s32 func_80077090(s32 a0);

/* Per-frame release watchdog for 4 SPU voice slots (bits 20-23). For each
   slot i: if f428[i] is set, it is subtracted from the f424[i] goal
   (clamped to 0); while the goal has not yet reached 0, func_80047864(i)
   is called and the slot is skipped for the rest of this iteration.
   Once the goal reaches 0, the slot's active bit in f434 is cleared,
   f428[i] is reset, the voice is keyed off (func_80076ED0(0, mask)), and its
   bit is folded into the running accum mask. Independent of that: f42C[i]
   is a separate down-counter that, on reaching 0, force-keys the voice off
   if func_80077090() still reports it live; and regardless of either
   path, a voice whose status reads 3 (stuck) and that has not already been
   queued this pass is also force-keyed off. All accumulated voice bits are
   applied in one final func_80076ED0(0, accum) after the loop. */
void func_800478EC(void) {
    s32 mask;
    s32 bit2;
    s32 accum;
    s32 i;
    s32 v0;
    u16 timer;

    mask = 0x100000;
    bit2 = 1;
    accum = 0;
    for (i = 0; i < 4; i++) {
        if (D_8009B45C->f428[i] != 0) {
            if (D_8009B45C->f428[i] >= D_8009B45C->f424[i]) {
                D_8009B45C->f424[i] = 0;
            } else {
                D_8009B45C->f424[i] = D_8009B45C->f424[i] - D_8009B45C->f428[i];
            }
            if (D_8009B45C->f424[i] != 0) {
                func_80047864(i);
                goto tail;
            }
            D_8009B45C->f434 &= ~bit2;
            D_8009B45C->f428[i] = 0;
            func_80076ED0(0, mask);
            accum |= mask;
        }
    tail:
        timer = D_8009B45C->f42C[i];
        if (timer != 0) {
            timer -= 1;
            D_8009B45C->f42C[i] = timer;
            if (timer == 0) {
                v0 = func_80077090(mask);
                if (v0 != 0) {
                    func_80076ED0(0, mask);
                    accum |= mask;
                }
            }
        }
        v0 = func_80077090(mask);
        if (v0 == 3 && !(accum & mask)) {
            func_80076ED0(0, mask);
            accum |= mask;
        }
        bit2 <<= 1;
        mask <<= 1;
    }
    if (accum != 0) {
        func_80076ED0(0, accum);
    }
}
