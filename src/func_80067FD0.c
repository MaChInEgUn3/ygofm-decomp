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

/* GTE OT-insert leaf, part of the gte_ot_insert_* family (see
   gte_ot_insert_transformed_tris.c for the shared family rationale):
   pure cop2 sequences with 9+ live registers and zero jal calls, no C
   shape can emit these under gcc 2.8.1. Whole-function raw-asm
   transcription, verified byte-exact (0/163 diffs); signed off in
   config/asm_allowed.txt. */
__asm__(
    ".set noreorder\n"
    ".global func_80067FD0\n"
    "func_80067FD0:\n"
    ".word 0x8c870000\n"   /* 80067FD0: lw $a3, 0x0($a0) */
    ".word 0x8c990010\n"   /* 80067FD4: lw $t9, 0x10($a0) */
    ".word 0x94f80002\n"   /* 80067FD8: lhu $t8, 0x2($a3) */
    ".word 0x8ce60004\n"   /* 80067FDC: lw $a2, 0x4($a3) */
    ".word 0x8c850014\n"   /* 80067FE0: lw $a1, 0x14($a0) */
    ".word 0x00063080\n"   /* 80067FE4: sll $a2, $a2, 2 */
    ".word 0xac900028\n"   /* 80067FE8: sw $s0, 0x28($a0) */
    ".word 0xac91002c\n"   /* 80067FEC: sw $s1, 0x2C($a0) */
    ".word 0xac920030\n"   /* 80067FF0: sw $s2, 0x30($a0) */
    ".word 0xac930034\n"   /* 80067FF4: sw $s3, 0x34($a0) */
    ".word 0x1300008e\n"   /* 80067FF8: beqz $t8, .L80068234 */
    ".word 0x00a63821\n"   /* 80067FFC: addu $a3, $a1, $a2 */
    ".word 0x3c10800a\n"   /* 80068000: lui $s0, %hi(D_8009AFB8) */
    ".word 0x8e10afb8\n"   /* 80068004: lw $s0, %lo(D_8009AFB8)($s0) */
    ".word 0x3c11800a\n"   /* 80068008: lui $s1, %hi(D_8009AFD8) */
    ".word 0x8e31afd8\n"   /* 8006800C: lw $s1, %lo(D_8009AFD8)($s1) */
    ".word 0x3c12800a\n"   /* 80068010: lui $s2, %hi(D_8009AFDC) */
    ".word 0x8e52afdc\n"   /* 80068014: lw $s2, %lo(D_8009AFDC)($s2) */
    ".word 0x02006021\n"   /* 80068018: addu $t4, $s0, $zero */
    ".word 0x3c0d800a\n"   /* 8006801C: lui $t5, %hi(D_8009AFE4) */
    ".word 0x81adafe4\n"   /* 80068020: lb $t5, %lo(D_8009AFE4)($t5) */
    ".word 0x00109e02\n"   /* 80068024: srl $s3, $s0, 24 */
    ".word 0x00139e00\n"   /* 80068028: sll $s3, $s3, 24 */
    ".word 0x24010001\n"   /* 8006802C: addiu $at, $zero, 0x1 */
    ".word 0x11a10080\n"   /* 80068030: beq $t5, $at, .L80068234 */
    ".word 0x00000000\n"   /* 80068034: nop */
    ".word 0x3c0d800a\n"   /* 80068038: lui $t5, %hi(D_8009AFE0) */
    ".word 0x8dadafe0\n"   /* 8006803C: lw $t5, %lo(D_8009AFE0)($t5) */
    ".word 0x8c85001c\n"   /* 80068040: lw $a1, 0x1C($a0) */
    ".word 0x8c860024\n"   /* 80068044: lw $a2, 0x24($a0) */
    ".word 0x11a00002\n"   /* 80068048: beqz $t5, .L80068054 */
    ".word 0x00000000\n"   /* 8006804C: nop */
    ".word 0x24c60004\n"   /* 80068050: addiu $a2, $a2, 0x4 */
    ".word 0x8c8d0004\n"   /* 80068054: lw $t5, 0x4($a0) */
    ".word 0x8c8e0008\n"   /* 80068058: lw $t6, 0x8($a0) */
    ".word 0x8daf0004\n"   /* 8006805C: lw $t7, 0x4($t5) */
    ".word 0x2403ffff\n"   /* 80068060: addiu $v1, $zero, -0x1 */
    ".word 0x8ce8000c\n"   /* 80068064: lw $t0, 0xC($a3) */
    ".word 0x98e8000a\n"   /* 80068068: lwr $t0, 0xA($a3) */
    ".word 0x8ce90010\n"   /* 8006806C: lw $t1, 0x10($a3) */
    ".word 0x8cea0014\n"   /* 80068070: lw $t2, 0x14($a3) */
    ".word 0x8ceb0018\n"   /* 80068074: lw $t3, 0x18($a3) */
    ".word 0x00086c02\n"   /* 80068078: srl $t5, $t0, 16 */
    ".word 0x000d68c0\n"   /* 8006807C: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 80068080: addu $t5, $t5, $a1 */
    ".word 0x8da20004\n"   /* 80068084: lw $v0, 0x4($t5) */
    ".word 0x8dad0000\n"   /* 80068088: lw $t5, 0x0($t5) */
    ".word 0x10430066\n"   /* 8006808C: beq $v0, $v1, .L80068228 */
    ".word 0x48828000\n"   /* 80068090: mtc2 $v0, $16 */
    ".word 0x488d6000\n"   /* 80068094: mtc2 $t5, $12 */
    ".word 0xaf2d0008\n"   /* 80068098: sw $t5, 0x8($t9) */
    ".word 0x00096c02\n"   /* 8006809C: srl $t5, $t1, 16 */
    ".word 0x000d68c0\n"   /* 800680A0: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 800680A4: addu $t5, $t5, $a1 */
    ".word 0x8da20004\n"   /* 800680A8: lw $v0, 0x4($t5) */
    ".word 0x8dad0000\n"   /* 800680AC: lw $t5, 0x0($t5) */
    ".word 0x1043005d\n"   /* 800680B0: beq $v0, $v1, .L80068228 */
    ".word 0x48828800\n"   /* 800680B4: mtc2 $v0, $17 */
    ".word 0x488d6800\n"   /* 800680B8: mtc2 $t5, $13 */
    ".word 0xaf2d0014\n"   /* 800680BC: sw $t5, 0x14($t9) */
    ".word 0x000a6c02\n"   /* 800680C0: srl $t5, $t2, 16 */
    ".word 0x000d68c0\n"   /* 800680C4: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 800680C8: addu $t5, $t5, $a1 */
    ".word 0x8da20004\n"   /* 800680CC: lw $v0, 0x4($t5) */
    ".word 0x8dad0000\n"   /* 800680D0: lw $t5, 0x0($t5) */
    ".word 0x10430054\n"   /* 800680D4: beq $v0, $v1, .L80068228 */
    ".word 0x48829000\n"   /* 800680D8: mtc2 $v0, $18 */
    ".word 0x488d7000\n"   /* 800680DC: mtc2 $t5, $14 */
    ".word 0xaf2d0020\n"   /* 800680E0: sw $t5, 0x20($t9) */
    ".word 0x000b6c02\n"   /* 800680E4: srl $t5, $t3, 16 */
    ".word 0x000d68c0\n"   /* 800680E8: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 800680EC: addu $t5, $t5, $a1 */
    ".word 0x8da20004\n"   /* 800680F0: lw $v0, 0x4($t5) */
    ".word 0x8dad0000\n"   /* 800680F4: lw $t5, 0x0($t5) */
    ".word 0x1043004b\n"   /* 800680F8: beq $v0, $v1, .L80068228 */
    ".word 0x48829800\n"   /* 800680FC: mtc2 $v0, $19 */
    ".word 0xaf2d002c\n"   /* 80068100: sw $t5, 0x2C($t9) */
    ".word 0x00084400\n"   /* 80068104: sll $t0, $t0, 16 */
    ".word 0x00084342\n"   /* 80068108: srl $t0, $t0, 13 */
    ".word 0x00094c00\n"   /* 8006810C: sll $t1, $t1, 16 */
    ".word 0x00094b42\n"   /* 80068110: srl $t1, $t1, 13 */
    ".word 0x000a5400\n"   /* 80068114: sll $t2, $t2, 16 */
    ".word 0x000a5342\n"   /* 80068118: srl $t2, $t2, 13 */
    ".word 0x000b5c00\n"   /* 8006811C: sll $t3, $t3, 16 */
    ".word 0x000b5b42\n"   /* 80068120: srl $t3, $t3, 13 */
    ".word 0x01064021\n"   /* 80068124: addu $t0, $t0, $a2 */
    ".word 0x01264821\n"   /* 80068128: addu $t1, $t1, $a2 */
    ".word 0x01465021\n"   /* 8006812C: addu $t2, $t2, $a2 */
    ".word 0x01665821\n"   /* 80068130: addu $t3, $t3, $a2 */
    ".word 0x8d080000\n"   /* 80068134: lw $t0, 0x0($t0) */
    ".word 0x8d290000\n"   /* 80068138: lw $t1, 0x0($t1) */
    ".word 0x8d4a0000\n"   /* 8006813C: lw $t2, 0x0($t2) */
    ".word 0x8d6b0000\n"   /* 80068140: lw $t3, 0x0($t3) */
    ".word 0x4b68002e\n"   /* 80068144: avsz4 */
    ".word 0x01134025\n"   /* 80068148: or $t0, $t0, $s3 */
    ".word 0xaf280004\n"   /* 8006814C: sw $t0, 0x4($t9) */
    ".word 0xaf290010\n"   /* 80068150: sw $t1, 0x10($t9) */
    ".word 0xaf2a001c\n"   /* 80068154: sw $t2, 0x1C($t9) */
    ".word 0xaf2b0028\n"   /* 80068158: sw $t3, 0x28($t9) */
    ".word 0x8ce80000\n"   /* 8006815C: lw $t0, 0x0($a3) */
    ".word 0x8ce90004\n"   /* 80068160: lw $t1, 0x4($a3) */
    ".word 0x8cea0008\n"   /* 80068164: lw $t2, 0x8($a3) */
    ".word 0x8ceb000c\n"   /* 80068168: lw $t3, 0xC($a3) */
    ".word 0x48023800\n"   /* 8006816C: mfc2 $v0, $7 */
    ".word 0x3c010200\n"   /* 80068170: lui $at, (0x2000000 >> 16) */
    ".word 0x02011824\n"   /* 80068174: and $v1, $s0, $at */
    ".word 0x01314825\n"   /* 80068178: or $t1, $t1, $s1 */
    ".word 0x01c21006\n"   /* 8006817C: srlv $v0, $v0, $t6 */
    ".word 0x00021080\n"   /* 80068180: sll $v0, $v0, 2 */
    ".word 0x004f1021\n"   /* 80068184: addu $v0, $v0, $t7 */
    ".word 0x8c4d0000\n"   /* 80068188: lw $t5, 0x0($v0) */
    ".word 0xaf28000c\n"   /* 8006818C: sw $t0, 0xC($t9) */
    ".word 0xaf290018\n"   /* 80068190: sw $t1, 0x18($t9) */
    ".word 0xaf2a0024\n"   /* 80068194: sw $t2, 0x24($t9) */
    ".word 0xaf2b0030\n"   /* 80068198: sw $t3, 0x30($t9) */
    ".word 0x000d6a00\n"   /* 8006819C: sll $t5, $t5, 8 */
    ".word 0x35ad000c\n"   /* 800681A0: ori $t5, $t5, 0xC */
    ".word 0x000d0a02\n"   /* 800681A4: srl $at, $t5, 8 */
    ".word 0x000d6e00\n"   /* 800681A8: sll $t5, $t5, 24 */
    ".word 0x01a16825\n"   /* 800681AC: or $t5, $t5, $at */
    ".word 0xaf2d0000\n"   /* 800681B0: sw $t5, 0x0($t9) */
    ".word 0x00196a00\n"   /* 800681B4: sll $t5, $t9, 8 */
    ".word 0x000d6a02\n"   /* 800681B8: srl $t5, $t5, 8 */
    ".word 0x10600019\n"   /* 800681BC: beqz $v1, .L80068224 */
    ".word 0xac4d0000\n"   /* 800681C0: sw $t5, 0x0($v0) */
    ".word 0x12400017\n"   /* 800681C4: beqz $s2, .L80068224 */
    ".word 0x00084400\n"   /* 800681C8: sll $t0, $t0, 16 */
    ".word 0x00084402\n"   /* 800681CC: srl $t0, $t0, 16 */
    ".word 0x01124025\n"   /* 800681D0: or $t0, $t0, $s2 */
    ".word 0x3c01ff9f\n"   /* 800681D4: lui $at, (0xFF9FFFFF >> 16) */
    ".word 0x3421ffff\n"   /* 800681D8: ori $at, $at, (0xFF9FFFFF & 0xFFFF) */
    ".word 0x01214824\n"   /* 800681DC: and $t1, $t1, $at */
    ".word 0x3c010040\n"   /* 800681E0: lui $at, (0x400000 >> 16) */
    ".word 0x01214825\n"   /* 800681E4: or $t1, $t1, $at */
    ".word 0x8f230008\n"   /* 800681E8: lw $v1, 0x8($t9) */
    ".word 0xaf2c0038\n"   /* 800681EC: sw $t4, 0x38($t9) */
    ".word 0xaf23003c\n"   /* 800681F0: sw $v1, 0x3C($t9) */
    ".word 0x8f230014\n"   /* 800681F4: lw $v1, 0x14($t9) */
    ".word 0xaf2c0044\n"   /* 800681F8: sw $t4, 0x44($t9) */
    ".word 0xaf230048\n"   /* 800681FC: sw $v1, 0x48($t9) */
    ".word 0x8f230020\n"   /* 80068200: lw $v1, 0x20($t9) */
    ".word 0xaf2c0050\n"   /* 80068204: sw $t4, 0x50($t9) */
    ".word 0xaf230054\n"   /* 80068208: sw $v1, 0x54($t9) */
    ".word 0x8f23002c\n"   /* 8006820C: lw $v1, 0x2C($t9) */
    ".word 0xaf2c005c\n"   /* 80068210: sw $t4, 0x5C($t9) */
    ".word 0xaf230060\n"   /* 80068214: sw $v1, 0x60($t9) */
    ".word 0x27390034\n"   /* 80068218: addiu $t9, $t9, 0x34 */
    ".word 0x0801a063\n"   /* 8006821C: j .L8006818C */
    ".word 0x24030000\n"   /* 80068220: addiu $v1, $zero, 0x0 */
    ".word 0x27390034\n"   /* 80068224: addiu $t9, $t9, 0x34 */
    ".word 0x2718ffff\n"   /* 80068228: addiu $t8, $t8, -0x1 */
    ".word 0x1700ff8c\n"   /* 8006822C: bnez $t8, .L80068060 */
    ".word 0x24e7001c\n"   /* 80068230: addiu $a3, $a3, 0x1C */
    ".word 0x8c900028\n"   /* 80068234: lw $s0, 0x28($a0) */
    ".word 0x8c91002c\n"   /* 80068238: lw $s1, 0x2C($a0) */
    ".word 0x8c920030\n"   /* 8006823C: lw $s2, 0x30($a0) */
    ".word 0x8c930034\n"   /* 80068240: lw $s3, 0x34($a0) */
    ".word 0x8c820000\n"   /* 80068244: lw $v0, 0x0($a0) */
    ".word 0x3c018010\n"   /* 80068248: lui $at, %hi(D_800FE240) */
    ".word 0xac39e240\n"   /* 8006824C: sw $t9, %lo(D_800FE240)($at) */
    ".word 0x24420008\n"   /* 80068250: addiu $v0, $v0, 0x8 */
    ".word 0x03e00008\n"   /* 80068254: jr $ra */
    ".word 0x00000000\n"   /* 80068258: nop */
    ".set reorder\n"
);
