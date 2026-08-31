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

/* function_ranges.txt mis-splits this: 0x8001D5B4 is a 1-insn stub (the
   leading gp+0x25A load) that flows straight into the truncated 0x8001D5B8
   entry, which itself has no return of its own -- one path tail-jumps
   (plain j, not jal) into the MIDDLE of sibling function func_8001D518's
   epilogue (address 0x8001D598, its "sh v1,8(s0)" instruction), reusing
   that function's shared tail/return sequence. gcc has no construct for
   jumping into another symbol's body, so this whole function is raw asm.
   maspsx also inserts a spurious extra nop after branch/jal mnemonics
   inside a hand-written noreorder block, so every branch and the jal are
   encoded as raw .word, matching func_800356A0.c's
   established technique. */
__asm__(
    ".set noreorder\n"
    ".global func_8001D5B4\n"
    "func_8001D5B4:\n"
    "lhu $v0, 0x25A($gp)\n"
    "addiu $sp, $sp, -0x18\n"
    "sw $s0, 0x10($sp)\n"
    "addu $s0, $a0, $zero\n"
    ".word 0x10400003\n"   /* beqz $v0,.L8001D5D4 */
    "sw $ra, 0x14($sp)\n"
    ".word 0x08007596\n"   /* j 0x8001D598 (tail-jump into func_8001D518) */
    "addiu $v0, $zero, -1\n"
    ".L8001D5D4:\n"
    "lb $a1, 0x258($gp)\n"
    ".word 0x0c009022\n"   /* jal func_80024088 */
    "addu $a0, $s0, $zero\n"
    ".word 0x10400003\n"   /* beqz $v0,.L8001D5F0 */
    "addiu $v0, $zero, -1\n"
    ".L8001D5E8:\n"
    ".word 0x08007598\n"   /* j .L8001D660 */
    "addiu $v0, $zero, 1\n"
    ".L8001D5F0:\n"
    "lb $v1, 0x2CF($gp)\n"
    "sb $v0, 0x258($gp)\n"
    "lb $v0, 0x10($s0)\n"
    "nop\n"
    ".word 0x1062000a\n"   /* beq $v1,$v0,.L8001D62C */
    "addiu $v0, $zero, 1\n"
    "sb $v0, 0x258($gp)\n"
    "lb $v0, 0x10($s0)\n"
    "nop\n"
    "slt $v0, $v1, $v0\n"
    ".word 0x1040fff3\n"   /* beqz $v0,.L8001D5E8 */
    "addiu $v0, $zero, 3\n"
    "sb $v0, 0x258($gp)\n"
    ".word 0x08007598\n"   /* j .L8001D660 */
    "addiu $v0, $zero, 1\n"
    ".L8001D62C:\n"
    "lb $v1, 0x2CE($gp)\n"
    "lb $v0, 0xF($s0)\n"
    "nop\n"
    ".word 0x10620009\n"   /* beq $v1,$v0,.L8001D660 */
    "addu $v0, $zero, $zero\n"
    "sb $zero, 0x258($gp)\n"
    "lb $v0, 0xF($s0)\n"
    "nop\n"
    "slt $v0, $v1, $v0\n"
    ".word 0x1040ffe5\n"   /* beqz $v0,.L8001D5E8 */
    "addiu $v0, $zero, 2\n"
    "sb $v0, 0x258($gp)\n"
    "addiu $v0, $zero, 1\n"
    ".L8001D660:\n"
    "lw $ra, 0x14($sp)\n"
    "lw $s0, 0x10($sp)\n"
    "jr $ra\n"
    "addiu $sp, $sp, 0x18\n"
    ".set reorder\n"
);
