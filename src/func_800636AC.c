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
    ".global func_800636AC\n"
    "func_800636AC:\n"
".word 0x8C870000\n\t" /* 800636AC: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 800636B0: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 800636B4: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 800636B8: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 800636BC: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 800636C0: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 800636C4: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 800636C8: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 800636CC: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 800636D0: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 800636D4: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 800636D8: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 800636DC: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 800636E0: sw         $s7, 0x3C($a0) */
".word 0x13000097\n\t" /* 800636E4: beqz       $t8, .L80063944 */
".word 0x00A63821\n\t" /* 800636E8: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 800636EC: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 800636F0: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 800636F4: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 800636F8: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800636FC: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80063700: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80063704: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80063708: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 8006370C: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80063710: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80063714: addu       $t4, $s0, $zero */
".word 0x00109E02\n\t" /* 80063718: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 8006371C: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 80063720: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80063724: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80063728: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 8006372C: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80063730: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80063734: lw         $t7, 0x4($t5) */
".L80063738:\n\t"
".word 0x8CE80010\n\t" /* 80063738: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 8006373C: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 80063740: lw         $t2, 0x18($a3) */
".word 0x00086C02\n\t" /* 80063744: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80063748: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006374C: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80063750: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80063754: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 80063758: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 8006375C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80063760: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80063764: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80063768: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 8006376C: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80063770: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80063774: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80063778: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 8006377C: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 80063780: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80063784: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 80063788: rtpt */
".word 0x00094C00\n\t" /* 8006378C: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 80063790: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 80063794: sll        $t2, $t2, 16 */
".word 0x24010001\n\t" /* 80063798: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 8006379C: beq        $s6, $at, .L800637B4 */
".word 0x000A5342\n\t" /* 800637A0: srl       $t2, $t2, 13 */
".word 0x4842F800\n\t" /* 800637A4: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800637A8: nop */
".word 0x04400062\n\t" /* 800637AC: bltz       $v0, .L80063938 */
".word 0x00000000\n\t" /* 800637B0: nop */
".L800637B4:\n\t"
".word 0x4B58002D\n\t" /* 800637B4: avsz3 */
".word 0x8CF50000\n\t" /* 800637B8: lw         $s5, 0x0($a3) */
".word 0x12C0001E\n\t" /* 800637BC: beqz       $s6, .L80063838 */
".word 0x01066821\n\t" /* 800637C0: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 800637C4: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800637C8: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 800637CC: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 800637D0: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 800637D4: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 800637D8: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 800637DC: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 800637E0: lwc2       $5, 0x4($t5) */
".word 0x00000000\n\t" /* 800637E4: nop */
".word 0x00000000\n\t" /* 800637E8: nop */
".word 0x4B18043F\n\t" /* 800637EC: ncct */
".word 0x12E00009\n\t" /* 800637F0: beqz       $s7, .L80063818 */
".word 0x00084042\n\t" /* 800637F4: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 800637F8: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 800637FC: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 80063800: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 80063804: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 80063808: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 8006380C: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 80063810: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 80063814: swc2       $22, 0x0($t2) */
".L80063818:\n\t"
".word 0xEB340008\n\t" /* 80063818: swc2       $20, 0x8($t9) */
".word 0xEB350014\n\t" /* 8006381C: swc2       $21, 0x14($t9) */
".word 0xEB360020\n\t" /* 80063820: swc2       $22, 0x20($t9) */
".word 0x24010001\n\t" /* 80063824: addiu      $at, $zero, 0x1 */
".word 0x12C10043\n\t" /* 80063828: beq        $s6, $at, .L80063938 */
".word 0x00000000\n\t" /* 8006382C: nop */
".word 0x08018E1B\n\t" /* 80063830: j          .L8006386C */
".word 0x00000000\n\t" /* 80063834: nop */
".L80063838:\n\t"
".word 0x00084042\n\t" /* 80063838: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 8006383C: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80063840: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 80063844: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 80063848: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 8006384C: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 80063850: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 80063854: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 80063858: lw         $t2, 0x0($v1) */
".word 0xAF280008\n\t" /* 8006385C: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 80063860: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 80063864: sw         $t2, 0x20($t9) */
".word 0xA333000B\n\t" /* 80063868: sb         $s3, 0xB($t9) */
".L8006386C:\n\t"
".word 0x8CE80004\n\t" /* 8006386C: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80063870: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80063874: lw         $t2, 0xC($a3) */
".word 0x48023800\n\t" /* 80063878: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 8006387C: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80063880: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 80063884: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80063888: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 8006388C: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80063890: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80063894: lw         $t5, 0x0($v0) */
".word 0xEB2C000C\n\t" /* 80063898: swc2       $12, 0xC($t9) */
".word 0xEB2D0018\n\t" /* 8006389C: swc2       $13, 0x18($t9) */
".word 0xEB2E0024\n\t" /* 800638A0: swc2       $14, 0x24($t9) */
".L800638A4:\n\t"
".word 0xAF280010\n\t" /* 800638A4: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 800638A8: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 800638AC: sw         $t2, 0x28($t9) */
".word 0xAF350004\n\t" /* 800638B0: sw         $s5, 0x4($t9) */
".word 0xAF34002C\n\t" /* 800638B4: sw         $s4, 0x2C($t9) */
".word 0x000D6A00\n\t" /* 800638B8: sll        $t5, $t5, 8 */
".word 0x35AD000B\n\t" /* 800638BC: ori        $t5, $t5, 0xB */
".word 0x000D0A02\n\t" /* 800638C0: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 800638C4: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 800638C8: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 800638CC: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 800638D0: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 800638D4: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 800638D8: beqz       $v1, .L80063934 */
".word 0xAC4D0000\n\t" /* 800638DC: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 800638E0: beqz       $s2, .L80063934 */
".word 0x00084400\n\t" /* 800638E4: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 800638E8: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 800638EC: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 800638F0: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800638F4: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800638F8: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 800638FC: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80063900: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 80063904: lw         $v1, 0xC($t9) */
".word 0xAF2C0038\n\t" /* 80063908: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 8006390C: sw         $v1, 0x3C($t9) */
".word 0x8F230018\n\t" /* 80063910: lw         $v1, 0x18($t9) */
".word 0xAF2C0044\n\t" /* 80063914: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80063918: sw         $v1, 0x48($t9) */
".word 0x8F230024\n\t" /* 8006391C: lw         $v1, 0x24($t9) */
".word 0xAF2C0050\n\t" /* 80063920: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80063924: sw         $v1, 0x54($t9) */
".word 0x27390030\n\t" /* 80063928: addiu      $t9, $t9, 0x30 */
".word 0x08018E29\n\t" /* 8006392C: j          .L800638A4 */
".word 0x24030000\n\t" /* 80063930: addiu     $v1, $zero, 0x0 */
".L80063934:\n\t"
".word 0x27390030\n\t" /* 80063934: addiu      $t9, $t9, 0x30 */
".L80063938:\n\t"
".word 0x2718FFFF\n\t" /* 80063938: addiu      $t8, $t8, -0x1 */
".word 0x1700FF7E\n\t" /* 8006393C: bnez       $t8, .L80063738 */
".word 0x24E7001C\n\t" /* 80063940: addiu     $a3, $a3, 0x1C */
".L80063944:\n\t"
".word 0x8C900020\n\t" /* 80063944: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80063948: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 8006394C: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80063950: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 80063954: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 80063958: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 8006395C: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 80063960: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80063964: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80063968: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 8006396C: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80063970: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80063974: jr         $ra */
".word 0x00000000\n\t" /* 80063978: nop */
    ".set reorder\n"
);
