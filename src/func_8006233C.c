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
    ".global func_8006233C\n"
    "func_8006233C:\n"
".word 0x8C870000\n\t" /* 8006233C: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80062340: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80062344: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80062348: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 8006234C: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80062350: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80062354: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80062358: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 8006235C: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80062360: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 80062364: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 80062368: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 8006236C: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 80062370: sw         $s7, 0x3C($a0) */
".word 0x13000094\n\t" /* 80062374: beqz       $t8, .L800625C8 */
".word 0x00A63821\n\t" /* 80062378: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 8006237C: lui        $s0, %hi(D_8009AFB0) */
".word 0x8E10AFB0\n\t" /* 80062380: lw         $s0, %lo(D_8009AFB0)($s0) */
".word 0x3C11800A\n\t" /* 80062384: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80062388: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 8006238C: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80062390: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80062394: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80062398: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 8006239C: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 800623A0: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 800623A4: addu       $t4, $s0, $zero */
".word 0x00109E02\n\t" /* 800623A8: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 800623AC: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 800623B0: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 800623B4: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 800623B8: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 800623BC: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 800623C0: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 800623C4: lw         $t7, 0x4($t5) */
".L800623C8:\n\t"
".word 0x8CE80014\n\t" /* 800623C8: lw         $t0, 0x14($a3) */
".word 0x8CE90018\n\t" /* 800623CC: lw         $t1, 0x18($a3) */
".word 0x00086C00\n\t" /* 800623D0: sll        $t5, $t0, 16 */
".word 0x000D6B42\n\t" /* 800623D4: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 800623D8: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 800623DC: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800623E0: lwc2       $1, 0x4($t5) */
".word 0x00086C02\n\t" /* 800623E4: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 800623E8: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800623EC: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 800623F0: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 800623F4: lwc2       $3, 0x4($t5) */
".word 0x00096C00\n\t" /* 800623F8: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 800623FC: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80062400: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80062404: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80062408: lwc2       $5, 0x4($t5) */
".word 0x00095C02\n\t" /* 8006240C: srl        $t3, $t1, 16 */
".word 0x000B58C0\n\t" /* 80062410: sll        $t3, $t3, 3 */
".word 0x4A280030\n\t" /* 80062414: rtpt */
".word 0x24010001\n\t" /* 80062418: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 8006241C: beq        $s6, $at, .L80062448 */
".word 0x01656821\n\t" /* 80062420: addu      $t5, $t3, $a1 */
".word 0x4842F800\n\t" /* 80062424: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80062428: nop */
".word 0x04400063\n\t" /* 8006242C: bltz       $v0, .L800625BC */
".word 0x00000000\n\t" /* 80062430: nop */
".word 0x4B400006\n\t" /* 80062434: nclip */
".word 0x4802C000\n\t" /* 80062438: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 8006243C: nop */
".word 0x1840005E\n\t" /* 80062440: blez       $v0, .L800625BC */
".word 0x00000000\n\t" /* 80062444: nop */
".L80062448:\n\t"
".word 0xC9A00000\n\t" /* 80062448: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 8006244C: lwc2       $1, 0x4($t5) */
".word 0xEB2C000C\n\t" /* 80062450: swc2       $12, 0xC($t9) */
".word 0xEB2D0014\n\t" /* 80062454: swc2       $13, 0x14($t9) */
".word 0xEB2E001C\n\t" /* 80062458: swc2       $14, 0x1C($t9) */
".word 0x00000000\n\t" /* 8006245C: nop */
".word 0x00000000\n\t" /* 80062460: nop */
".word 0x4A180001\n\t" /* 80062464: rtps */
".word 0x94E80012\n\t" /* 80062468: lhu        $t0, 0x12($a3) */
".word 0x24010001\n\t" /* 8006246C: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80062470: beq        $s6, $at, .L80062488 */
".word 0x000840C0\n\t" /* 80062474: sll       $t0, $t0, 3 */
".word 0x4842F800\n\t" /* 80062478: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 8006247C: nop */
".word 0x0440004E\n\t" /* 80062480: bltz       $v0, .L800625BC */
".word 0x00000000\n\t" /* 80062484: nop */
".L80062488:\n\t"
".word 0x4B68002E\n\t" /* 80062488: avsz4 */
".word 0x8CF50000\n\t" /* 8006248C: lw         $s5, 0x0($a3) */
".word 0x12C00010\n\t" /* 80062490: beqz       $s6, .L800624D4 */
".word 0x01066821\n\t" /* 80062494: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80062498: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 8006249C: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 800624A0: nop */
".word 0x00000000\n\t" /* 800624A4: nop */
".word 0x4B08041B\n\t" /* 800624A8: nccs */
".word 0x12E00003\n\t" /* 800624AC: beqz       $s7, .L800624BC */
".word 0x00084042\n\t" /* 800624B0: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 800624B4: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 800624B8: swc2       $22, 0x0($t0) */
".L800624BC:\n\t"
".word 0xEB360008\n\t" /* 800624BC: swc2       $22, 0x8($t9) */
".word 0x24010001\n\t" /* 800624C0: addiu      $at, $zero, 0x1 */
".word 0x12C1003D\n\t" /* 800624C4: beq        $s6, $at, .L800625BC */
".word 0x00000000\n\t" /* 800624C8: nop */
".word 0x0801893B\n\t" /* 800624CC: j          .L800624EC */
".word 0x00000000\n\t" /* 800624D0: nop */
".L800624D4:\n\t"
".word 0x00084042\n\t" /* 800624D4: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 800624D8: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 800624DC: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 800624E0: nop */
".word 0xAF280008\n\t" /* 800624E4: sw         $t0, 0x8($t9) */
".word 0xA333000B\n\t" /* 800624E8: sb         $s3, 0xB($t9) */
".L800624EC:\n\t"
".word 0x8CE80004\n\t" /* 800624EC: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 800624F0: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 800624F4: lw         $t2, 0xC($a3) */
".word 0x8CEB0010\n\t" /* 800624F8: lw         $t3, 0x10($a3) */
".word 0x48023800\n\t" /* 800624FC: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80062500: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80062504: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 80062508: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 8006250C: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80062510: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80062514: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80062518: lw         $t5, 0x0($v0) */
".word 0xEB2E0024\n\t" /* 8006251C: swc2       $14, 0x24($t9) */
".L80062520:\n\t"
".word 0xAF280010\n\t" /* 80062520: sw         $t0, 0x10($t9) */
".word 0xAF290018\n\t" /* 80062524: sw         $t1, 0x18($t9) */
".word 0xAF2A0020\n\t" /* 80062528: sw         $t2, 0x20($t9) */
".word 0xAF2B0028\n\t" /* 8006252C: sw         $t3, 0x28($t9) */
".word 0xAF350004\n\t" /* 80062530: sw         $s5, 0x4($t9) */
".word 0xAF34002C\n\t" /* 80062534: sw         $s4, 0x2C($t9) */
".word 0x000D6A00\n\t" /* 80062538: sll        $t5, $t5, 8 */
".word 0x35AD000B\n\t" /* 8006253C: ori        $t5, $t5, 0xB */
".word 0x000D0A02\n\t" /* 80062540: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80062544: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80062548: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 8006254C: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80062550: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80062554: srl        $t5, $t5, 8 */
".word 0x10600017\n\t" /* 80062558: beqz       $v1, .L800625B8 */
".word 0xAC4D0000\n\t" /* 8006255C: sw        $t5, 0x0($v0) */
".word 0x12400015\n\t" /* 80062560: beqz       $s2, .L800625B8 */
".word 0x00000000\n\t" /* 80062564: nop */
".word 0x3C01FF9F\n\t" /* 80062568: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 8006256C: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80062570: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80062574: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80062578: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 8006257C: lw         $v1, 0xC($t9) */
".word 0x00084400\n\t" /* 80062580: sll        $t0, $t0, 16 */
".word 0xAF23003C\n\t" /* 80062584: sw         $v1, 0x3C($t9) */
".word 0x8F230014\n\t" /* 80062588: lw         $v1, 0x14($t9) */
".word 0x00084402\n\t" /* 8006258C: srl        $t0, $t0, 16 */
".word 0xAF230044\n\t" /* 80062590: sw         $v1, 0x44($t9) */
".word 0x8F23001C\n\t" /* 80062594: lw         $v1, 0x1C($t9) */
".word 0x01124025\n\t" /* 80062598: or         $t0, $t0, $s2 */
".word 0xAF23004C\n\t" /* 8006259C: sw         $v1, 0x4C($t9) */
".word 0x8F230024\n\t" /* 800625A0: lw         $v1, 0x24($t9) */
".word 0xAF2C0038\n\t" /* 800625A4: sw         $t4, 0x38($t9) */
".word 0xAF230054\n\t" /* 800625A8: sw         $v1, 0x54($t9) */
".word 0x27390030\n\t" /* 800625AC: addiu      $t9, $t9, 0x30 */
".word 0x08018948\n\t" /* 800625B0: j          .L80062520 */
".word 0x24030000\n\t" /* 800625B4: addiu     $v1, $zero, 0x0 */
".L800625B8:\n\t"
".word 0x27390030\n\t" /* 800625B8: addiu      $t9, $t9, 0x30 */
".L800625BC:\n\t"
".word 0x2718FFFF\n\t" /* 800625BC: addiu      $t8, $t8, -0x1 */
".word 0x1700FF81\n\t" /* 800625C0: bnez       $t8, .L800623C8 */
".word 0x24E7001C\n\t" /* 800625C4: addiu     $a3, $a3, 0x1C */
".L800625C8:\n\t"
".word 0x8C900020\n\t" /* 800625C8: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 800625CC: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 800625D0: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 800625D4: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 800625D8: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 800625DC: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 800625E0: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 800625E4: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 800625E8: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 800625EC: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 800625F0: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 800625F4: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 800625F8: jr         $ra */
".word 0x00000000\n\t" /* 800625FC: nop */
    ".set reorder\n"
);
