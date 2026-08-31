/* PARKED CANDIDATE PORTED from Unchiga's tree (docs/MERGE_UNCHIGA.md).
 * Installed here because HIS base is closer than the one this tree
 * reached: the counts are in PARKED.txt. Measure it with the flags on
 * the next line -- they are his unit's, and try_func's default flags
 * report a different number.
 * FLAGS: -G8 -msplit-addresses
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern u8 D_8009B062;
extern s32 func_8008FBE0(s32 a0);

/* Busy-wait-with-timeout: if the flag is already set, skip straight to
 * clearing it and returning. Otherwise count down from 0x7FFFFF, bailing
 * early (WITHOUT counting that iteration) the moment the flag gets set by
 * something else, or calling the timeout handler if the counter runs out
 * first. Target's decrement lives in a branch's delay slot -- it ALWAYS
 * executes once per loop visit -- and gets undone with a following
 * increment only on the early-bail path.
 *
 * Was documented as the GCC strength-reduction/induction-variable family
 * (same class as func_8002E00C/func_80035A64) and stuck at 17/22: the
 * natural `while(v1>0){v1--; if(flag){v1++;break;}}` shape is
 * semantically right but gcc represented the loop with a fresh
 * up-counting induction variable instead of decrementing v1 itself.
 * Landed 0/22 via three independent, compounding fixes -- NONE of them
 * were actually about defeating strength reduction; the real causes were
 * elsewhere:
 *
 * 1. Loop shape: a `for(;;){ if(v1<=0){timeout();break;} v1--;
 *    if(flag==0)continue; v1++; break; }` (each branch of the disasm
 *    written as its own explicit if/continue/break, no implicit `while`
 *    wrapper around an internal `if{break;}`) got the loop's own test +
 *    body layout byte-exact immediately (17/22 -> 13/22). The plain
 *    `while(v1>0){v1--; if(flag){...}}` form triggered a completely
 *    different gcc loop-rotation strategy (an always-taken
 *    `move v0,zero; beqz v0,X` peel artifact) that this shape avoids.
 *
 * 2. The `v1++` undo on the early-bail path is functionally DEAD CODE
 *    (v1 is never func_800738F0 again after the loop) -- both the `for` and
 *    `goto`-based rewrites let gcc's DCE silently drop it (13/22 with
 *    the increment MISSING, one word short). An `asm volatile("" ::
 *    "r"(v1))` func_800738F0 barrier placed right after `v1++` (before the
 *    `break`) is enough to keep it alive without affecting anything
 *    else (13/22 -> 6/22, loop body now byte-exact end to end).
 *
 * 3. The prologue's constant load: gcc's own choice for materializing
 *    0x7FFFFF is `lui v1,0x7f; ori v1,v1,0xffff` (the "natural"/unadjusted
 *    split), but target uses `lui v1,0x80; addiu v1,v1,-1` (the
 *    %hi/%lo-style adjusted split, normally reserved for symbol
 *    addresses) -- and schedules the `lui` HALF unconditionally before
 *    the flag-check branch while leaving the `addiu` half for after
 *    (only reached on the not-taken/flag==0 path). No portable C source
 *    form of the literal (arithmetic vs plain hex, signed vs unsigned,
 *    register pin) changed gcc's own choice of split; forcing BOTH
 *    halves via raw `__asm__` -- the `lui` unconditionally before the
 *    `if`, the `addiu` unconditionally as the first thing inside it --
 *    reproduces the exact split and its scheduling (6/22 -> 0/22). */
s32 func_8005C5D4(void) {
    register s32 v1 asm("v1");

    __asm__("lui %0,0x80" : "=r" (v1));
    if (D_8009B062 == 0) {
        __asm__("addiu %0,%1,-1" : "=r" (v1) : "0" (v1));
        for (;;) {
            if (v1 <= 0) {
                func_8008FBE0(1);
                break;
            }
            v1--;
            if (D_8009B062 == 0) {
                continue;
            }
            v1++;
            asm volatile("" :: "r" (v1));
            break;
        }
    }
    D_8009B062 = 0;
    return 0;
}
