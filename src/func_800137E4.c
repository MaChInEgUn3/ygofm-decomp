/* PORTED test */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Runs the per-frame update batch until both busy words are clear, then
   drains whatever D_8009B134 still has outstanding.

   D_8009B0F4's bits 0x02000030 and D_8009B134 together say "work is
   pending"; bit 0x20 additionally gates the func_80015038 step, so a frame
   with 0x20 set runs only func_80012D4C.

   Written as an explicit-break loop rather than `while (cond)`: the target
   evaluates the condition twice (once before the loop, once at the bottom),
   which is what this shape produces -- a plain `while` makes gcc share one
   evaluation and comes out three words short. */

extern u32 D_8009B0F4;
extern u32 D_8009B134;
extern void func_80015038(void);
extern void func_80012D4C(void);

void func_800137E4(void) {
    for (;;) {
        if (((D_8009B0F4 & 0x02000030) | D_8009B134) == 0) {
            break;
        }
        if ((D_8009B0F4 & 0x20) == 0) {
            func_80015038();
        }
        func_80012D4C();
    }

    while (D_8009B134 != 0) {
        func_80012D4C();
    }
}
