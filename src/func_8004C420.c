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

/* MIDI/command-stream byte dispatcher (was blacklisted at 0x8004C420,
   reclaimed and decompiled to real C by claude-w3). Reads a command byte via
   func_8004BAE4(arg0); if the high bit is set it's a fresh running-status
   byte (cached to arg0->f29 unless it's 0xFF, and the busy flag arg0->f28 is
   cleared); otherwise it reuses the cached arg0->f29 byte and sets
   arg0->f28=1. Looks up a 16-entry s32 dispatch table at D_80010538+0xF4C
   indexed by (status>>4)&0xF. If table[idx]!=0: conditionally reads 1-2 more
   stream bytes (a 2nd only if arg0->f28==0, a 3rd only if table[idx]==2) and
   calls func_8004C114(arg0, status, byte2, byte3). Otherwise dispatches on
   the raw command byte itself: 0xF0 -> func_8004C0AC(arg0,cmd); 0xFF -> reads
   one more byte and calls func_8004BE88(arg0,byte); anything else ->
   func_8004BE80(cmd&0xFF, cmd). All paths return 0.

   The original blacklist note had 13 .word lines confusing m2c: 8 are real
   JAL (func_8004BAE4/func_8004BAE4 x4, func_8004C114, func_8004BE88/
   func_8004BE88, func_8004C0AC, func_8004BE80 x1 each); the other 5
   are local J-opcode gotos to this function's OWN labels -- m2c had invented
   fake callees func_8004C480/func_8004C540 for those, which was wrong.

   Register-shape note (this is what stalled the prior session at 50/80):
   from right after the first func_8004BAE4() call, the target keeps ONE
   value ("cmd") live in $a0 and $a1 SIMULTANEOUSLY -- the delay slot of the
   high-bit test unconditionally copies a1->a0, and neither register is
   reassigned independently until the final default-case dispatch, where $a0
   gets re-masked (cmd&0xFF) but $a1 keeps the original raw value for
   func_8004C0AC's 2nd arg and func_8004BE80's 2nd arg. Pinning `cmd` itself
   to $a1 and a second alias to $a0 (both `register ... asm("reg")`) is what
   let gcc reproduce the target's exact redundant-looking `move a0,a1` and
   the later reads that pick one register over the other; plain C variables
   let the compiler CSE the two away and pick the "wrong" one at three
   separate points. 0/80 with -G8 -msplit-addresses. */

extern s32 func_8004BAE4(void *arg0);
extern void func_8004C114(void *arg0, s32 status, s32 byte2, s32 byte3);
extern void func_8004C0AC(void *arg0, s32 cmd);
extern void func_8004BE88(void *arg0, s32 byte);
extern void func_8004BE80(s32 cmd_masked, s32 cmd_raw);
extern u8 D_80010538[16];

typedef struct {
    char pad[0x28];
    u8 f28; /* busy flag: 1 = mid-message, waiting on more bytes */
    u8 f29; /* cached running-status byte */
} MidiChan;

s32 func_8004C420(MidiChan *arg0) {
    register s32 cmd asm("a1");
    u32 status;
    register s32 tableVal asm("s3");
    s32 masked;
    s32 *table;
    s32 byte3 = 0; /* $s4, zeroed at function entry (before the other callee-
                      saved register spills) -- must be a top-level local
                      initializer, not scoped inside the tableVal!=0 block. */

    cmd = func_8004BAE4(arg0);
    {
        register s32 a0copy asm("a0") = cmd;
        if (!(cmd & 0x80)) {
            status = arg0->f29;
            arg0->f28 = 1;
        } else {
            status = cmd;
            if ((a0copy & 0xFF) != 0xFF) {
                arg0->f29 = cmd;
            }
            arg0->f28 = 0;
        }

        table = (s32 *) (D_80010538 + 0xF4C);
        tableVal = table[(status >> 4) & 0xF];
        if (tableVal != 0) {
            register s32 byte2 asm("s2") = a0copy;
            if (arg0->f28 == 0) {
                byte2 = func_8004BAE4(arg0);
            }
            if (tableVal == 2) {
                byte3 = func_8004BAE4(arg0);
            }
            func_8004C114(arg0, status & 0xFF, byte2 & 0xFF, byte3 & 0xFF);
            return 0;
        }

        masked = a0copy & 0xFF;
        if (masked == 0xF0) {
            goto case_f0;
        }
        if (masked != 0xFF) {
            goto case_default;
        }
        func_8004BE88(arg0, func_8004BAE4(arg0) & 0xFF);
        return 0;
    }
case_f0:
    func_8004C0AC(arg0, cmd);
    return 0;
case_default:
    func_8004BE80(masked, cmd);
    return 0;
}
