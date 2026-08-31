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
    ".global func_800617E0\n"
    "func_800617E0:\n"
".word 0x8C870000\n\t" /* 800617E0: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 800617E4: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 800617E8: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 800617EC: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 800617F0: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 800617F4: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 800617F8: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 800617FC: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80061800: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80061804: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 80061808: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 8006180C: sw         $s7, 0x34($a0) */
".word 0x13000090\n\t" /* 80061810: beqz       $t8, .L80061A54 */
".word 0x00A63821\n\t" /* 80061814: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80061818: lui        $s0, %hi(D_8009AFB0) */
".word 0x8E10AFB0\n\t" /* 8006181C: lw         $s0, %lo(D_8009AFB0)($s0) */
".word 0x3C11800A\n\t" /* 80061820: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80061824: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80061828: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 8006182C: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80061830: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80061834: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80061838: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 8006183C: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80061840: addu       $t4, $s0, $zero */
".word 0x00109E02\n\t" /* 80061844: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 80061848: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 8006184C: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80061850: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80061854: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80061858: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 8006185C: lw         $t7, 0x4($t5) */
".L80061860:\n\t"
".word 0x8CE80010\n\t" /* 80061860: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 80061864: lw         $t1, 0x14($a3) */
".word 0x00086C00\n\t" /* 80061868: sll        $t5, $t0, 16 */
".word 0x000D6B42\n\t" /* 8006186C: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80061870: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80061874: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80061878: lwc2       $1, 0x4($t5) */
".word 0x00086C02\n\t" /* 8006187C: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80061880: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80061884: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80061888: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 8006188C: lwc2       $3, 0x4($t5) */
".word 0x00096C00\n\t" /* 80061890: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 80061894: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80061898: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 8006189C: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 800618A0: lwc2       $5, 0x4($t5) */
".word 0x00095C02\n\t" /* 800618A4: srl        $t3, $t1, 16 */
".word 0x000B58C0\n\t" /* 800618A8: sll        $t3, $t3, 3 */
".word 0x4A280030\n\t" /* 800618AC: rtpt */
".word 0x24010001\n\t" /* 800618B0: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 800618B4: beq        $s6, $at, .L800618E0 */
".word 0x01656821\n\t" /* 800618B8: addu      $t5, $t3, $a1 */
".word 0x4842F800\n\t" /* 800618BC: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800618C0: nop */
".word 0x04400060\n\t" /* 800618C4: bltz       $v0, .L80061A48 */
".word 0x00000000\n\t" /* 800618C8: nop */
".word 0x4B400006\n\t" /* 800618CC: nclip */
".word 0x4802C000\n\t" /* 800618D0: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800618D4: nop */
".word 0x1840005B\n\t" /* 800618D8: blez       $v0, .L80061A48 */
".word 0x00000000\n\t" /* 800618DC: nop */
".L800618E0:\n\t"
".word 0xC9A00000\n\t" /* 800618E0: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800618E4: lwc2       $1, 0x4($t5) */
".word 0xEB2C0008\n\t" /* 800618E8: swc2       $12, 0x8($t9) */
".word 0xEB2D0010\n\t" /* 800618EC: swc2       $13, 0x10($t9) */
".word 0xEB2E0018\n\t" /* 800618F0: swc2       $14, 0x18($t9) */
".word 0x00000000\n\t" /* 800618F4: nop */
".word 0x00000000\n\t" /* 800618F8: nop */
".word 0x4A180001\n\t" /* 800618FC: rtps */
".word 0x94E8000E\n\t" /* 80061900: lhu        $t0, 0xE($a3) */
".word 0x24010001\n\t" /* 80061904: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80061908: beq        $s6, $at, .L80061920 */
".word 0x000840C0\n\t" /* 8006190C: sll       $t0, $t0, 3 */
".word 0x4842F800\n\t" /* 80061910: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80061914: nop */
".word 0x0440004B\n\t" /* 80061918: bltz       $v0, .L80061A48 */
".word 0x00000000\n\t" /* 8006191C: nop */
".L80061920:\n\t"
".word 0x4B68002E\n\t" /* 80061920: avsz4 */
".word 0x12C00010\n\t" /* 80061924: beqz       $s6, .L80061968 */
".word 0x01066821\n\t" /* 80061928: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 8006192C: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80061930: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80061934: nop */
".word 0x00000000\n\t" /* 80061938: nop */
".word 0x4B08041B\n\t" /* 8006193C: nccs */
".word 0x12E00003\n\t" /* 80061940: beqz       $s7, .L80061950 */
".word 0x00084042\n\t" /* 80061944: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80061948: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 8006194C: swc2       $22, 0x0($t0) */
".L80061950:\n\t"
".word 0xEB360004\n\t" /* 80061950: swc2       $22, 0x4($t9) */
".word 0x24010001\n\t" /* 80061954: addiu      $at, $zero, 0x1 */
".word 0x12C1003B\n\t" /* 80061958: beq        $s6, $at, .L80061A48 */
".word 0x00000000\n\t" /* 8006195C: nop */
".word 0x08018660\n\t" /* 80061960: j          .L80061980 */
".word 0x00000000\n\t" /* 80061964: nop */
".L80061968:\n\t"
".word 0x00084042\n\t" /* 80061968: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 8006196C: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80061970: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 80061974: nop */
".word 0xAF280004\n\t" /* 80061978: sw         $t0, 0x4($t9) */
".word 0xA3330007\n\t" /* 8006197C: sb         $s3, 0x7($t9) */
".L80061980:\n\t"
".word 0x8CE80000\n\t" /* 80061980: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80061984: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80061988: lw         $t2, 0x8($a3) */
".word 0x8CEB000C\n\t" /* 8006198C: lw         $t3, 0xC($a3) */
".word 0x48023800\n\t" /* 80061990: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80061994: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80061998: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 8006199C: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 800619A0: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 800619A4: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 800619A8: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 800619AC: lw         $t5, 0x0($v0) */
".word 0xEB2E0020\n\t" /* 800619B0: swc2       $14, 0x20($t9) */
".L800619B4:\n\t"
".word 0xAF28000C\n\t" /* 800619B4: sw         $t0, 0xC($t9) */
".word 0xAF290014\n\t" /* 800619B8: sw         $t1, 0x14($t9) */
".word 0xAF2A001C\n\t" /* 800619BC: sw         $t2, 0x1C($t9) */
".word 0xAF2B0024\n\t" /* 800619C0: sw         $t3, 0x24($t9) */
".word 0x000D6A00\n\t" /* 800619C4: sll        $t5, $t5, 8 */
".word 0x35AD0009\n\t" /* 800619C8: ori        $t5, $t5, 0x9 */
".word 0x000D0A02\n\t" /* 800619CC: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 800619D0: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 800619D4: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 800619D8: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 800619DC: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 800619E0: srl        $t5, $t5, 8 */
".word 0x10600017\n\t" /* 800619E4: beqz       $v1, .L80061A44 */
".word 0xAC4D0000\n\t" /* 800619E8: sw        $t5, 0x0($v0) */
".word 0x12400015\n\t" /* 800619EC: beqz       $s2, .L80061A44 */
".word 0x00000000\n\t" /* 800619F0: nop */
".word 0x3C01FF9F\n\t" /* 800619F4: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800619F8: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800619FC: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80061A00: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80061A04: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80061A08: lw         $v1, 0x8($t9) */
".word 0x00084400\n\t" /* 80061A0C: sll        $t0, $t0, 16 */
".word 0xAF230030\n\t" /* 80061A10: sw         $v1, 0x30($t9) */
".word 0x8F230010\n\t" /* 80061A14: lw         $v1, 0x10($t9) */
".word 0x00084402\n\t" /* 80061A18: srl        $t0, $t0, 16 */
".word 0xAF230038\n\t" /* 80061A1C: sw         $v1, 0x38($t9) */
".word 0x8F230018\n\t" /* 80061A20: lw         $v1, 0x18($t9) */
".word 0x01124025\n\t" /* 80061A24: or         $t0, $t0, $s2 */
".word 0xAF230040\n\t" /* 80061A28: sw         $v1, 0x40($t9) */
".word 0x8F230020\n\t" /* 80061A2C: lw         $v1, 0x20($t9) */
".word 0xAF2C002C\n\t" /* 80061A30: sw         $t4, 0x2C($t9) */
".word 0xAF230048\n\t" /* 80061A34: sw         $v1, 0x48($t9) */
".word 0x27390028\n\t" /* 80061A38: addiu      $t9, $t9, 0x28 */
".word 0x0801866D\n\t" /* 80061A3C: j          .L800619B4 */
".word 0x24030000\n\t" /* 80061A40: addiu     $v1, $zero, 0x0 */
".L80061A44:\n\t"
".word 0x27390028\n\t" /* 80061A44: addiu      $t9, $t9, 0x28 */
".L80061A48:\n\t"
".word 0x2718FFFF\n\t" /* 80061A48: addiu      $t8, $t8, -0x1 */
".word 0x1700FF84\n\t" /* 80061A4C: bnez       $t8, .L80061860 */
".word 0x24E70018\n\t" /* 80061A50: addiu     $a3, $a3, 0x18 */
".L80061A54:\n\t"
".word 0x8C900020\n\t" /* 80061A54: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80061A58: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80061A5C: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80061A60: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 80061A64: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 80061A68: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 80061A6C: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80061A70: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80061A74: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80061A78: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80061A7C: jr         $ra */
".word 0x00000000\n\t" /* 80061A80: nop */
    ".set reorder\n"
);
