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
   transcription, verified byte-exact (0/166 diffs); signed off in
   config/asm_allowed.txt. */
__asm__(
    ".set noreorder\n"
    ".global func_8006930C\n"
    "func_8006930C:\n"
    ".word 0x8c870000\n"   /* 8006930C: lw $a3, 0x0($a0) */
    ".word 0x8c990010\n"   /* 80069310: lw $t9, 0x10($a0) */
    ".word 0x94f80002\n"   /* 80069314: lhu $t8, 0x2($a3) */
    ".word 0x8ce60004\n"   /* 80069318: lw $a2, 0x4($a3) */
    ".word 0x8c850014\n"   /* 8006931C: lw $a1, 0x14($a0) */
    ".word 0x00063080\n"   /* 80069320: sll $a2, $a2, 2 */
    ".word 0xac900028\n"   /* 80069324: sw $s0, 0x28($a0) */
    ".word 0xac91002c\n"   /* 80069328: sw $s1, 0x2C($a0) */
    ".word 0xac920030\n"   /* 8006932C: sw $s2, 0x30($a0) */
    ".word 0xac930034\n"   /* 80069330: sw $s3, 0x34($a0) */
    ".word 0x13000091\n"   /* 80069334: beqz $t8, .L8006957C */
    ".word 0x00a63821\n"   /* 80069338: addu $a3, $a1, $a2 */
    ".word 0x3c10800a\n"   /* 8006933C: lui $s0, %hi(D_8009AFB4) */
    ".word 0x8e10afb4\n"   /* 80069340: lw $s0, %lo(D_8009AFB4)($s0) */
    ".word 0x3c11800a\n"   /* 80069344: lui $s1, %hi(D_8009AFD8) */
    ".word 0x8e31afd8\n"   /* 80069348: lw $s1, %lo(D_8009AFD8)($s1) */
    ".word 0x3c12800a\n"   /* 8006934C: lui $s2, %hi(D_8009AFDC) */
    ".word 0x8e52afdc\n"   /* 80069350: lw $s2, %lo(D_8009AFDC)($s2) */
    ".word 0x02006021\n"   /* 80069354: addu $t4, $s0, $zero */
    ".word 0x3c02800a\n"   /* 80069358: lui $v0, %hi(D_8009AFE5) */
    ".word 0x8042afe5\n"   /* 8006935C: lb $v0, %lo(D_8009AFE5)($v0) */
    ".word 0x3c010200\n"   /* 80069360: lui $at, (0x2000000 >> 16) */
    ".word 0x02018025\n"   /* 80069364: or $s0, $s0, $at */
    ".word 0x1440000e\n"   /* 80069368: bnez $v0, .L800693A4 */
    ".word 0x02006021\n"   /* 8006936C: addu $t4, $s0, $zero */
    ".word 0x8cf10004\n"   /* 80069370: lw $s1, 0x4($a3) */
    ".word 0x3c010060\n"   /* 80069374: lui $at, (0x600000 >> 16) */
    ".word 0x02218824\n"   /* 80069378: and $s1, $s1, $at */
    ".word 0x16200009\n"   /* 8006937C: bnez $s1, .L800693A4 */
    ".word 0x00000000\n"   /* 80069380: nop */
    ".word 0x12400008\n"   /* 80069384: beqz $s2, .L800693A8 */
    ".word 0x00000000\n"   /* 80069388: nop */
    ".word 0x94f20002\n"   /* 8006938C: lhu $s2, 0x2($a3) */
    ".word 0x3c0c800a\n"   /* 80069390: lui $t4, %hi(D_8009AFC4) */
    ".word 0x8d8cafc4\n"   /* 80069394: lw $t4, %lo(D_8009AFC4)($t4) */
    ".word 0x00129400\n"   /* 80069398: sll $s2, $s2, 16 */
    ".word 0x0801a4ea\n"   /* 8006939C: j .L800693A8 */
    ".word 0x3c110020\n"   /* 800693A0: lui $s1, (0x200000 >> 16) */
    ".word 0x24120000\n"   /* 800693A4: addiu $s2, $zero, 0x0 */
    ".word 0x3c0d800a\n"   /* 800693A8: lui $t5, %hi(D_8009AFE4) */
    ".word 0x81adafe4\n"   /* 800693AC: lb $t5, %lo(D_8009AFE4)($t5) */
    ".word 0x00109e02\n"   /* 800693B0: srl $s3, $s0, 24 */
    ".word 0x00139e00\n"   /* 800693B4: sll $s3, $s3, 24 */
    ".word 0x24010001\n"   /* 800693B8: addiu $at, $zero, 0x1 */
    ".word 0x11a1006f\n"   /* 800693BC: beq $t5, $at, .L8006957C */
    ".word 0x00000000\n"   /* 800693C0: nop */
    ".word 0x3c0d800a\n"   /* 800693C4: lui $t5, %hi(D_8009AFE0) */
    ".word 0x8dadafe0\n"   /* 800693C8: lw $t5, %lo(D_8009AFE0)($t5) */
    ".word 0x8c85001c\n"   /* 800693CC: lw $a1, 0x1C($a0) */
    ".word 0x8c860024\n"   /* 800693D0: lw $a2, 0x24($a0) */
    ".word 0x11a00002\n"   /* 800693D4: beqz $t5, .L800693E0 */
    ".word 0x00000000\n"   /* 800693D8: nop */
    ".word 0x24c60004\n"   /* 800693DC: addiu $a2, $a2, 0x4 */
    ".word 0x8c8d0004\n"   /* 800693E0: lw $t5, 0x4($a0) */
    ".word 0x8c8e0008\n"   /* 800693E4: lw $t6, 0x8($a0) */
    ".word 0x8daf0004\n"   /* 800693E8: lw $t7, 0x4($t5) */
    ".word 0x2403ffff\n"   /* 800693EC: addiu $v1, $zero, -0x1 */
    ".word 0x8ce8000c\n"   /* 800693F0: lw $t0, 0xC($a3) */
    ".word 0x8ce90010\n"   /* 800693F4: lw $t1, 0x10($a3) */
    ".word 0x8cea0014\n"   /* 800693F8: lw $t2, 0x14($a3) */
    ".word 0x00086c02\n"   /* 800693FC: srl $t5, $t0, 16 */
    ".word 0x000d68c0\n"   /* 80069400: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 80069404: addu $t5, $t5, $a1 */
    ".word 0x8da20004\n"   /* 80069408: lw $v0, 0x4($t5) */
    ".word 0x8dad0000\n"   /* 8006940C: lw $t5, 0x0($t5) */
    ".word 0x10430057\n"   /* 80069410: beq $v0, $v1, .L80069570 */
    ".word 0x48828800\n"   /* 80069414: mtc2 $v0, $17 */
    ".word 0x488d6000\n"   /* 80069418: mtc2 $t5, $12 */
    ".word 0xaf2d0008\n"   /* 8006941C: sw $t5, 0x8($t9) */
    ".word 0x00096c02\n"   /* 80069420: srl $t5, $t1, 16 */
    ".word 0x000d68c0\n"   /* 80069424: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 80069428: addu $t5, $t5, $a1 */
    ".word 0x8da20004\n"   /* 8006942C: lw $v0, 0x4($t5) */
    ".word 0x8dad0000\n"   /* 80069430: lw $t5, 0x0($t5) */
    ".word 0x1043004e\n"   /* 80069434: beq $v0, $v1, .L80069570 */
    ".word 0x48829000\n"   /* 80069438: mtc2 $v0, $18 */
    ".word 0x488d6800\n"   /* 8006943C: mtc2 $t5, $13 */
    ".word 0xaf2d0014\n"   /* 80069440: sw $t5, 0x14($t9) */
    ".word 0x000a6c02\n"   /* 80069444: srl $t5, $t2, 16 */
    ".word 0x000d68c0\n"   /* 80069448: sll $t5, $t5, 3 */
    ".word 0x01a56821\n"   /* 8006944C: addu $t5, $t5, $a1 */
    ".word 0x8da20004\n"   /* 80069450: lw $v0, 0x4($t5) */
    ".word 0x8dad0000\n"   /* 80069454: lw $t5, 0x0($t5) */
    ".word 0x10430045\n"   /* 80069458: beq $v0, $v1, .L80069570 */
    ".word 0x48829800\n"   /* 8006945C: mtc2 $v0, $19 */
    ".word 0x488d7000\n"   /* 80069460: mtc2 $t5, $14 */
    ".word 0xaf2d0020\n"   /* 80069464: sw $t5, 0x20($t9) */
    ".word 0x00084400\n"   /* 80069468: sll $t0, $t0, 16 */
    ".word 0x00084342\n"   /* 8006946C: srl $t0, $t0, 13 */
    ".word 0x00094c00\n"   /* 80069470: sll $t1, $t1, 16 */
    ".word 0x00094b42\n"   /* 80069474: srl $t1, $t1, 13 */
    ".word 0x000a5400\n"   /* 80069478: sll $t2, $t2, 16 */
    ".word 0x000a5342\n"   /* 8006947C: srl $t2, $t2, 13 */
    ".word 0x01064021\n"   /* 80069480: addu $t0, $t0, $a2 */
    ".word 0x01264821\n"   /* 80069484: addu $t1, $t1, $a2 */
    ".word 0x01465021\n"   /* 80069488: addu $t2, $t2, $a2 */
    ".word 0x8d080000\n"   /* 8006948C: lw $t0, 0x0($t0) */
    ".word 0x8d290000\n"   /* 80069490: lw $t1, 0x0($t1) */
    ".word 0x8d4a0000\n"   /* 80069494: lw $t2, 0x0($t2) */
    ".word 0x4b58002d\n"   /* 80069498: avsz3 */
    ".word 0x01134025\n"   /* 8006949C: or $t0, $t0, $s3 */
    ".word 0xaf280004\n"   /* 800694A0: sw $t0, 0x4($t9) */
    ".word 0xaf290010\n"   /* 800694A4: sw $t1, 0x10($t9) */
    ".word 0xaf2a001c\n"   /* 800694A8: sw $t2, 0x1C($t9) */
    ".word 0x8ce80000\n"   /* 800694AC: lw $t0, 0x0($a3) */
    ".word 0x8ce90004\n"   /* 800694B0: lw $t1, 0x4($a3) */
    ".word 0x8cea0008\n"   /* 800694B4: lw $t2, 0x8($a3) */
    ".word 0x48023800\n"   /* 800694B8: mfc2 $v0, $7 */
    ".word 0x3c010200\n"   /* 800694BC: lui $at, (0x2000000 >> 16) */
    ".word 0x02011824\n"   /* 800694C0: and $v1, $s0, $at */
    ".word 0x3c01ff9f\n"   /* 800694C4: lui $at, (0xFF9FFFFF >> 16) */
    ".word 0x3421ffff\n"   /* 800694C8: ori $at, $at, (0xFF9FFFFF & 0xFFFF) */
    ".word 0x01214824\n"   /* 800694CC: and $t1, $t1, $at */
    ".word 0x01314825\n"   /* 800694D0: or $t1, $t1, $s1 */
    ".word 0x01c21006\n"   /* 800694D4: srlv $v0, $v0, $t6 */
    ".word 0x00021080\n"   /* 800694D8: sll $v0, $v0, 2 */
    ".word 0x004f1021\n"   /* 800694DC: addu $v0, $v0, $t7 */
    ".word 0x8c4d0000\n"   /* 800694E0: lw $t5, 0x0($v0) */
    ".word 0xaf28000c\n"   /* 800694E4: sw $t0, 0xC($t9) */
    ".word 0xaf290018\n"   /* 800694E8: sw $t1, 0x18($t9) */
    ".word 0xaf2a0024\n"   /* 800694EC: sw $t2, 0x24($t9) */
    ".word 0x000d6a00\n"   /* 800694F0: sll $t5, $t5, 8 */
    ".word 0x35ad0009\n"   /* 800694F4: ori $t5, $t5, 0x9 */
    ".word 0x000d0a02\n"   /* 800694F8: srl $at, $t5, 8 */
    ".word 0x000d6e00\n"   /* 800694FC: sll $t5, $t5, 24 */
    ".word 0x01a16825\n"   /* 80069500: or $t5, $t5, $at */
    ".word 0xaf2d0000\n"   /* 80069504: sw $t5, 0x0($t9) */
    ".word 0x00196a00\n"   /* 80069508: sll $t5, $t9, 8 */
    ".word 0x000d6a02\n"   /* 8006950C: srl $t5, $t5, 8 */
    ".word 0x10600016\n"   /* 80069510: beqz $v1, .L8006956C */
    ".word 0xac4d0000\n"   /* 80069514: sw $t5, 0x0($v0) */
    ".word 0x12400014\n"   /* 80069518: beqz $s2, .L8006956C */
    ".word 0x00084400\n"   /* 8006951C: sll $t0, $t0, 16 */
    ".word 0x00084402\n"   /* 80069520: srl $t0, $t0, 16 */
    ".word 0x01124025\n"   /* 80069524: or $t0, $t0, $s2 */
    ".word 0x3c01ff9f\n"   /* 80069528: lui $at, (0xFF9FFFFF >> 16) */
    ".word 0x3421ffff\n"   /* 8006952C: ori $at, $at, (0xFF9FFFFF & 0xFFFF) */
    ".word 0x01214824\n"   /* 80069530: and $t1, $t1, $at */
    ".word 0x3c010040\n"   /* 80069534: lui $at, (0x400000 >> 16) */
    ".word 0x01214825\n"   /* 80069538: or $t1, $t1, $at */
    ".word 0x8f230008\n"   /* 8006953C: lw $v1, 0x8($t9) */
    ".word 0xaf2c002c\n"   /* 80069540: sw $t4, 0x2C($t9) */
    ".word 0xaf230030\n"   /* 80069544: sw $v1, 0x30($t9) */
    ".word 0x8f230014\n"   /* 80069548: lw $v1, 0x14($t9) */
    ".word 0xaf2c0038\n"   /* 8006954C: sw $t4, 0x38($t9) */
    ".word 0xaf23003c\n"   /* 80069550: sw $v1, 0x3C($t9) */
    ".word 0x8f230020\n"   /* 80069554: lw $v1, 0x20($t9) */
    ".word 0xaf2c0044\n"   /* 80069558: sw $t4, 0x44($t9) */
    ".word 0xaf230048\n"   /* 8006955C: sw $v1, 0x48($t9) */
    ".word 0x27390028\n"   /* 80069560: addiu $t9, $t9, 0x28 */
    ".word 0x0801a539\n"   /* 80069564: j .L800694E4 */
    ".word 0x24030000\n"   /* 80069568: addiu $v1, $zero, 0x0 */
    ".word 0x27390028\n"   /* 8006956C: addiu $t9, $t9, 0x28 */
    ".word 0x2718ffff\n"   /* 80069570: addiu $t8, $t8, -0x1 */
    ".word 0x1700ff9d\n"   /* 80069574: bnez $t8, .L800693EC */
    ".word 0x24e70018\n"   /* 80069578: addiu $a3, $a3, 0x18 */
    ".word 0x8c900028\n"   /* 8006957C: lw $s0, 0x28($a0) */
    ".word 0x8c91002c\n"   /* 80069580: lw $s1, 0x2C($a0) */
    ".word 0x8c920030\n"   /* 80069584: lw $s2, 0x30($a0) */
    ".word 0x8c930034\n"   /* 80069588: lw $s3, 0x34($a0) */
    ".word 0x8c820000\n"   /* 8006958C: lw $v0, 0x0($a0) */
    ".word 0x3c018010\n"   /* 80069590: lui $at, %hi(D_800FE240) */
    ".word 0xac39e240\n"   /* 80069594: sw $t9, %lo(D_800FE240)($at) */
    ".word 0x24420008\n"   /* 80069598: addiu $v0, $v0, 0x8 */
    ".word 0x03e00008\n"   /* 8006959C: jr $ra */
    ".word 0x00000000\n"   /* 800695A0: nop */
    ".set reorder\n"
);
