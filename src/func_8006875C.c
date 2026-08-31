/* ASSEMBLY DEBT -- this is a TRANSCRIPTION, not a decompilation.
 * The body below is the retail instruction stream written out as inline
 * asm. It is byte-exact and therefore invisible to build.py, which is
 * exactly the problem: the oracle cannot tell transcribed assembly from
 * real C, so nothing but this comment stops it being counted as done.
 * Ported from Unchiga's tree, where it is tracked as known debt.
 * Rewriting it as C is open work; see docs/ASM_DEBT.md.
 */
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

/* Whole-function raw-asm transcription (GTE OT-insert family, see
   project_gte_register_spill_and_pin_techniques.md). */
__asm__(
    ".set noreorder\n"
    ".global func_8006875C\n"
    "func_8006875C:\n"
".word 0x8C870000\n\t" /* 8006875C: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80068760: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80068764: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80068768: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 8006876C: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80068770: sll        $a2, $a2, 2 */
".word 0xAC900028\n\t" /* 80068774: sw         $s0, 0x28($a0) */
".word 0xAC91002C\n\t" /* 80068778: sw         $s1, 0x2C($a0) */
".word 0xAC920030\n\t" /* 8006877C: sw         $s2, 0x30($a0) */
".word 0xAC930034\n\t" /* 80068780: sw         $s3, 0x34($a0) */
".word 0x13000094\n\t" /* 80068784: beqz       $t8, .L800689D8 */
".word 0x00A63821\n\t" /* 80068788: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 8006878C: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 80068790: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 80068794: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80068798: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 8006879C: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 800687A0: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x02006021\n\t" /* 800687A4: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 800687A8: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 800687AC: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 800687B0: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 800687B4: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 800687B8: bnez       $v0, .L800687F4 */
".word 0x02006021\n\t" /* 800687BC: addu      $t4, $s0, $zero */
".word 0x8CF10004\n\t" /* 800687C0: lw         $s1, 0x4($a3) */
".word 0x3C010060\n\t" /* 800687C4: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 800687C8: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 800687CC: bnez       $s1, .L800687F4 */
".word 0x00000000\n\t" /* 800687D0: nop */
".word 0x12400008\n\t" /* 800687D4: beqz       $s2, .L800687F8 */
".word 0x00000000\n\t" /* 800687D8: nop */
".word 0x94F20002\n\t" /* 800687DC: lhu        $s2, 0x2($a3) */
".word 0x3C0C800A\n\t" /* 800687E0: lui        $t4, %hi(D_8009AFC4) */
".word 0x8D8CAFC4\n\t" /* 800687E4: lw         $t4, %lo(D_8009AFC4)($t4) */
".word 0x00129400\n\t" /* 800687E8: sll        $s2, $s2, 16 */
".word 0x0801A1FE\n\t" /* 800687EC: j          .L800687F8 */
".word 0x3C110020\n\t" /* 800687F0: lui       $s1, (0x200000 >> 16) */
".L800687F4:\n\t"
".word 0x24120000\n\t" /* 800687F4: addiu      $s2, $zero, 0x0 */
".L800687F8:\n\t"
".word 0x3C0D800A\n\t" /* 800687F8: lui        $t5, %hi(D_8009AFE4) */
".word 0x81ADAFE4\n\t" /* 800687FC: lb         $t5, %lo(D_8009AFE4)($t5) */
".word 0x00109E02\n\t" /* 80068800: srl        $s3, $s0, 24 */
".word 0x00139E00\n\t" /* 80068804: sll        $s3, $s3, 24 */
".word 0x24010001\n\t" /* 80068808: addiu      $at, $zero, 0x1 */
".word 0x11A10072\n\t" /* 8006880C: beq        $t5, $at, .L800689D8 */
".word 0x00000000\n\t" /* 80068810: nop */
".word 0x3C0D800A\n\t" /* 80068814: lui        $t5, %hi(D_8009AFE0) */
".word 0x8DADAFE0\n\t" /* 80068818: lw         $t5, %lo(D_8009AFE0)($t5) */
".word 0x8C85001C\n\t" /* 8006881C: lw         $a1, 0x1C($a0) */
".word 0x8C860024\n\t" /* 80068820: lw         $a2, 0x24($a0) */
".word 0x11A00002\n\t" /* 80068824: beqz       $t5, .L80068830 */
".word 0x00000000\n\t" /* 80068828: nop */
".word 0x24C60004\n\t" /* 8006882C: addiu      $a2, $a2, 0x4 */
".L80068830:\n\t"
".word 0x8C8D0004\n\t" /* 80068830: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80068834: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80068838: lw         $t7, 0x4($t5) */
".L8006883C:\n\t"
".word 0x2403FFFF\n\t" /* 8006883C: addiu      $v1, $zero, -0x1 */
".word 0x8CE8000C\n\t" /* 80068840: lw         $t0, 0xC($a3) */
".word 0x8CE90010\n\t" /* 80068844: lw         $t1, 0x10($a3) */
".word 0x8CEA0014\n\t" /* 80068848: lw         $t2, 0x14($a3) */
".word 0x00086C02\n\t" /* 8006884C: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80068850: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80068854: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80068858: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 8006885C: lw         $t5, 0x0($t5) */
".word 0x1043005A\n\t" /* 80068860: beq        $v0, $v1, .L800689CC */
".word 0x48828800\n\t" /* 80068864: mtc2      $v0, $17 ( handwritten instruction ) */
".word 0x488D6000\n\t" /* 80068868: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0xAF2D0008\n\t" /* 8006886C: sw         $t5, 0x8($t9) */
".word 0x00096C02\n\t" /* 80068870: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80068874: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80068878: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 8006887C: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80068880: lw         $t5, 0x0($t5) */
".word 0x10430051\n\t" /* 80068884: beq        $v0, $v1, .L800689CC */
".word 0x48829000\n\t" /* 80068888: mtc2      $v0, $18 ( handwritten instruction ) */
".word 0x488D6800\n\t" /* 8006888C: mtc2       $t5, $13 ( handwritten instruction ) */
".word 0xAF2D0014\n\t" /* 80068890: sw         $t5, 0x14($t9) */
".word 0x000A6C02\n\t" /* 80068894: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80068898: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006889C: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 800688A0: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 800688A4: lw         $t5, 0x0($t5) */
".word 0x10430048\n\t" /* 800688A8: beq        $v0, $v1, .L800689CC */
".word 0x48829800\n\t" /* 800688AC: mtc2      $v0, $19 ( handwritten instruction ) */
".word 0x488D7000\n\t" /* 800688B0: mtc2       $t5, $14 ( handwritten instruction ) */
".word 0xAF2D0020\n\t" /* 800688B4: sw         $t5, 0x20($t9) */
".word 0x00084400\n\t" /* 800688B8: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 800688BC: srl        $t0, $t0, 13 */
".word 0x4B400006\n\t" /* 800688C0: nclip */
".word 0x00094C00\n\t" /* 800688C4: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 800688C8: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 800688CC: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 800688D0: srl        $t2, $t2, 13 */
".word 0x01064021\n\t" /* 800688D4: addu       $t0, $t0, $a2 */
".word 0x4802C000\n\t" /* 800688D8: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x01264821\n\t" /* 800688DC: addu       $t1, $t1, $a2 */
".word 0x1840003A\n\t" /* 800688E0: blez       $v0, .L800689CC */
".word 0x01465021\n\t" /* 800688E4: addu      $t2, $t2, $a2 */
".word 0x8D080000\n\t" /* 800688E8: lw         $t0, 0x0($t0) */
".word 0x8D290000\n\t" /* 800688EC: lw         $t1, 0x0($t1) */
".word 0x8D4A0000\n\t" /* 800688F0: lw         $t2, 0x0($t2) */
".word 0x01134025\n\t" /* 800688F4: or         $t0, $t0, $s3 */
".word 0xAF280004\n\t" /* 800688F8: sw         $t0, 0x4($t9) */
".word 0xAF290010\n\t" /* 800688FC: sw         $t1, 0x10($t9) */
".word 0xAF2A001C\n\t" /* 80068900: sw         $t2, 0x1C($t9) */
".word 0x4B58002D\n\t" /* 80068904: avsz3 */
".word 0x8CE80000\n\t" /* 80068908: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 8006890C: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80068910: lw         $t2, 0x8($a3) */
".word 0x48023800\n\t" /* 80068914: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80068918: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 8006891C: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80068920: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80068924: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80068928: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 8006892C: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80068930: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80068934: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80068938: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 8006893C: lw         $t5, 0x0($v0) */
".L80068940:\n\t"
".word 0xAF28000C\n\t" /* 80068940: sw         $t0, 0xC($t9) */
".word 0xAF290018\n\t" /* 80068944: sw         $t1, 0x18($t9) */
".word 0xAF2A0024\n\t" /* 80068948: sw         $t2, 0x24($t9) */
".word 0x000D6A00\n\t" /* 8006894C: sll        $t5, $t5, 8 */
".word 0x35AD0009\n\t" /* 80068950: ori        $t5, $t5, 0x9 */
".word 0x000D0A02\n\t" /* 80068954: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80068958: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 8006895C: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80068960: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80068964: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80068968: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 8006896C: beqz       $v1, .L800689C8 */
".word 0xAC4D0000\n\t" /* 80068970: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 80068974: beqz       $s2, .L800689C8 */
".word 0x00084400\n\t" /* 80068978: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 8006897C: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80068980: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80068984: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80068988: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 8006898C: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80068990: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80068994: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80068998: lw         $v1, 0x8($t9) */
".word 0xAF2C002C\n\t" /* 8006899C: sw         $t4, 0x2C($t9) */
".word 0xAF230030\n\t" /* 800689A0: sw         $v1, 0x30($t9) */
".word 0x8F230014\n\t" /* 800689A4: lw         $v1, 0x14($t9) */
".word 0xAF2C0038\n\t" /* 800689A8: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 800689AC: sw         $v1, 0x3C($t9) */
".word 0x8F230020\n\t" /* 800689B0: lw         $v1, 0x20($t9) */
".word 0xAF2C0044\n\t" /* 800689B4: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 800689B8: sw         $v1, 0x48($t9) */
".word 0x27390028\n\t" /* 800689BC: addiu      $t9, $t9, 0x28 */
".word 0x0801A250\n\t" /* 800689C0: j          .L80068940 */
".word 0x24030000\n\t" /* 800689C4: addiu     $v1, $zero, 0x0 */
".L800689C8:\n\t"
".word 0x27390028\n\t" /* 800689C8: addiu      $t9, $t9, 0x28 */
".L800689CC:\n\t"
".word 0x2718FFFF\n\t" /* 800689CC: addiu      $t8, $t8, -0x1 */
".word 0x1700FF9A\n\t" /* 800689D0: bnez       $t8, .L8006883C */
".word 0x24E70018\n\t" /* 800689D4: addiu     $a3, $a3, 0x18 */
".L800689D8:\n\t"
".word 0x8C900028\n\t" /* 800689D8: lw         $s0, 0x28($a0) */
".word 0x8C91002C\n\t" /* 800689DC: lw         $s1, 0x2C($a0) */
".word 0x8C920030\n\t" /* 800689E0: lw         $s2, 0x30($a0) */
".word 0x8C930034\n\t" /* 800689E4: lw         $s3, 0x34($a0) */
".word 0x8C820000\n\t" /* 800689E8: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 800689EC: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 800689F0: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 800689F4: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 800689F8: jr         $ra */
".word 0x00000000\n\t" /* 800689FC: nop */
    ".set reorder\n"
);
