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

/* GTE quad OT-insert loop, sibling of func_80066E60
   (src/gte_ot_insert_transformed_quads_gouraud_id_transluc.c) with an
   added NCLIP backface-cull test between RTPT and the SXY/AVSZ3 steps,
   matching the NCLIP found in func_80061DDC's family
   (src/gte_ot_insert_transformed_tris_lit_id_clip.c) -- i.e.
   func_80066E60 plus clip. Whole-function raw-asm transcription (GTE
   OT-insert family, see project_gte_register_spill_and_pin_techniques.md).
   Pure cop2 leaf, zero jal calls, 245 insns. */
__asm__(
    ".set noreorder\n"
    ".global func_80065554\n"
    "func_80065554:\n"
".word 0x8C870000\n\t" /* 80065554: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80065558: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 8006555C: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80065560: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80065564: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80065568: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 8006556C: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80065570: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80065574: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80065578: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 8006557C: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 80065580: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 80065584: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 80065588: sw         $s7, 0x3C($a0) */
".word 0x130000D8\n\t" /* 8006558C: beqz       $t8, .L800658F0 */
".word 0x00A63821\n\t" /* 80065590: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80065594: lui        $s0, %hi(D_8009AFB8) */
".word 0x8E10AFB8\n\t" /* 80065598: lw         $s0, %lo(D_8009AFB8)($s0) */
".word 0x3C11800A\n\t" /* 8006559C: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 800655A0: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800655A4: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 800655A8: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 800655AC: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 800655B0: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 800655B4: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 800655B8: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 800655BC: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 800655C0: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 800655C4: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 800655C8: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 800655CC: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 800655D0: bnez       $v0, .L8006560C */
".word 0x02006021\n\t" /* 800655D4: addu      $t4, $s0, $zero */
".word 0x8CF10008\n\t" /* 800655D8: lw         $s1, 0x8($a3) */
".word 0x3C010060\n\t" /* 800655DC: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 800655E0: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 800655E4: bnez       $s1, .L8006560C */
".word 0x00000000\n\t" /* 800655E8: nop */
".word 0x12400008\n\t" /* 800655EC: beqz       $s2, .L80065610 */
".word 0x00000000\n\t" /* 800655F0: nop */
".word 0x94F20006\n\t" /* 800655F4: lhu        $s2, 0x6($a3) */
".word 0x3C0C800A\n\t" /* 800655F8: lui        $t4, %hi(D_8009AFC8) */
".word 0x8D8CAFC8\n\t" /* 800655FC: lw         $t4, %lo(D_8009AFC8)($t4) */
".word 0x00129400\n\t" /* 80065600: sll        $s2, $s2, 16 */
".word 0x08019584\n\t" /* 80065604: j          .L80065610 */
".word 0x3C110020\n\t" /* 80065608: lui       $s1, (0x200000 >> 16) */
".L8006560C:\n\t"
".word 0x24120000\n\t" /* 8006560C: addiu      $s2, $zero, 0x0 */
".L80065610:\n\t"
".word 0x00109E02\n\t" /* 80065610: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 80065614: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 80065618: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 8006561C: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80065620: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80065624: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80065628: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 8006562C: lw         $t7, 0x4($t5) */
".L80065630:\n\t"
".word 0x8CE80010\n\t" /* 80065630: lw         $t0, 0x10($a3) */
".word 0x98E8000E\n\t" /* 80065634: lwr        $t0, 0xE($a3) */
".word 0x8CE90014\n\t" /* 80065638: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 8006563C: lw         $t2, 0x18($a3) */
".word 0x8CEB001C\n\t" /* 80065640: lw         $t3, 0x1C($a3) */
".word 0x00086C02\n\t" /* 80065644: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80065648: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006564C: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80065650: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80065654: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 80065658: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 8006565C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80065660: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80065664: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80065668: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 8006566C: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80065670: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80065674: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80065678: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 8006567C: lwc2       $5, 0x4($t5) */
".word 0x000B6C02\n\t" /* 80065680: srl        $t5, $t3, 16 */
".word 0x000D68C0\n\t" /* 80065684: sll        $t5, $t5, 3 */
".word 0x4A280030\n\t" /* 80065688: rtpt */
".word 0x000B5C00\n\t" /* 8006568C: sll        $t3, $t3, 16 */
".word 0x000B5B42\n\t" /* 80065690: srl        $t3, $t3, 13 */
".word 0x24010001\n\t" /* 80065694: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 80065698: beq        $s6, $at, .L800656C4 */
".word 0x01A56821\n\t" /* 8006569C: addu      $t5, $t5, $a1 */
".word 0x4842F800\n\t" /* 800656A0: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800656A4: nop */
".word 0x0440008E\n\t" /* 800656A8: bltz       $v0, .L800658E4 */
".word 0x00000000\n\t" /* 800656AC: nop */
".word 0x4B400006\n\t" /* 800656B0: nclip */
".word 0x4802C000\n\t" /* 800656B4: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800656B8: nop */
".word 0x18400089\n\t" /* 800656BC: blez       $v0, .L800658E4 */
".word 0x00000000\n\t" /* 800656C0: nop */
".L800656C4:\n\t"
".word 0xC9A00000\n\t" /* 800656C4: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800656C8: lwc2       $1, 0x4($t5) */
".word 0xEB2C000C\n\t" /* 800656CC: swc2       $12, 0xC($t9) */
".word 0xEB2D0018\n\t" /* 800656D0: swc2       $13, 0x18($t9) */
".word 0xEB2E0024\n\t" /* 800656D4: swc2       $14, 0x24($t9) */
".word 0x00084400\n\t" /* 800656D8: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 800656DC: srl        $t0, $t0, 13 */
".word 0x4A180001\n\t" /* 800656E0: rtps */
".word 0x00094C00\n\t" /* 800656E4: sll        $t1, $t1, 16 */
".word 0x24010001\n\t" /* 800656E8: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 800656EC: beq        $s6, $at, .L80065704 */
".word 0x00094B42\n\t" /* 800656F0: srl       $t1, $t1, 13 */
".word 0x4842F800\n\t" /* 800656F4: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800656F8: nop */
".word 0x04400079\n\t" /* 800656FC: bltz       $v0, .L800658E4 */
".word 0x00000000\n\t" /* 80065700: nop */
".L80065704:\n\t"
".word 0x4B68002E\n\t" /* 80065704: avsz4 */
".word 0xEB2E0030\n\t" /* 80065708: swc2       $14, 0x30($t9) */
".word 0x000A5400\n\t" /* 8006570C: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80065710: srl        $t2, $t2, 13 */
".word 0x8CF50000\n\t" /* 80065714: lw         $s5, 0x0($a3) */
".word 0x12C00029\n\t" /* 80065718: beqz       $s6, .L800657C0 */
".word 0x01666821\n\t" /* 8006571C: addu      $t5, $t3, $a2 */
".word 0xC9A00000\n\t" /* 80065720: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80065724: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80065728: nop */
".word 0x00000000\n\t" /* 8006572C: nop */
".word 0x4B08041B\n\t" /* 80065730: nccs */
".word 0x01066821\n\t" /* 80065734: addu       $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80065738: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 8006573C: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 80065740: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 80065744: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80065748: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 8006574C: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 80065750: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80065754: lwc2       $5, 0x4($t5) */
".word 0x12E00003\n\t" /* 80065758: beqz       $s7, .L80065768 */
".word 0x000B5842\n\t" /* 8006575C: srl       $t3, $t3, 1 */
".word 0x01775821\n\t" /* 80065760: addu       $t3, $t3, $s7 */
".word 0xE9760000\n\t" /* 80065764: swc2       $22, 0x0($t3) */
".L80065768:\n\t"
".word 0xEB36002C\n\t" /* 80065768: swc2       $22, 0x2C($t9) */
".word 0x00000000\n\t" /* 8006576C: nop */
".word 0x00000000\n\t" /* 80065770: nop */
".word 0x4B18043F\n\t" /* 80065774: ncct */
".word 0x12E00009\n\t" /* 80065778: beqz       $s7, .L800657A0 */
".word 0x00084042\n\t" /* 8006577C: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80065780: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 80065784: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 80065788: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 8006578C: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 80065790: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 80065794: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 80065798: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 8006579C: swc2       $22, 0x0($t2) */
".L800657A0:\n\t"
".word 0xEB340008\n\t" /* 800657A0: swc2       $20, 0x8($t9) */
".word 0xEB350014\n\t" /* 800657A4: swc2       $21, 0x14($t9) */
".word 0xEB360020\n\t" /* 800657A8: swc2       $22, 0x20($t9) */
".word 0x24010001\n\t" /* 800657AC: addiu      $at, $zero, 0x1 */
".word 0x12C1004C\n\t" /* 800657B0: beq        $s6, $at, .L800658E4 */
".word 0x00000000\n\t" /* 800657B4: nop */
".word 0x08019601\n\t" /* 800657B8: j          .L80065804 */
".word 0x00000000\n\t" /* 800657BC: nop */
".L800657C0:\n\t"
".word 0x00084042\n\t" /* 800657C0: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 800657C4: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 800657C8: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 800657CC: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 800657D0: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 800657D4: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 800657D8: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 800657DC: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 800657E0: lw         $t2, 0x0($v1) */
".word 0x000B5842\n\t" /* 800657E4: srl        $t3, $t3, 1 */
".word 0x01771821\n\t" /* 800657E8: addu       $v1, $t3, $s7 */
".word 0x8C6B0000\n\t" /* 800657EC: lw         $t3, 0x0($v1) */
".word 0xAF280008\n\t" /* 800657F0: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 800657F4: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 800657F8: sw         $t2, 0x20($t9) */
".word 0xAF2B002C\n\t" /* 800657FC: sw         $t3, 0x2C($t9) */
".word 0xA333000B\n\t" /* 80065800: sb         $s3, 0xB($t9) */
".L80065804:\n\t"
".word 0x8CE80004\n\t" /* 80065804: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80065808: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 8006580C: lw         $t2, 0xC($a3) */
".word 0x8CEB0010\n\t" /* 80065810: lw         $t3, 0x10($a3) */
".word 0x48023800\n\t" /* 80065814: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80065818: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 8006581C: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80065820: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80065824: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80065828: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 8006582C: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80065830: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80065834: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80065838: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 8006583C: lw         $t5, 0x0($v0) */
".L80065840:\n\t"
".word 0xAF280010\n\t" /* 80065840: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 80065844: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 80065848: sw         $t2, 0x28($t9) */
".word 0xAF2B0034\n\t" /* 8006584C: sw         $t3, 0x34($t9) */
".word 0xAF350004\n\t" /* 80065850: sw         $s5, 0x4($t9) */
".word 0xAF340038\n\t" /* 80065854: sw         $s4, 0x38($t9) */
".word 0x000D6A00\n\t" /* 80065858: sll        $t5, $t5, 8 */
".word 0x35AD000E\n\t" /* 8006585C: ori        $t5, $t5, 0xE */
".word 0x000D0A02\n\t" /* 80065860: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80065864: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80065868: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 8006586C: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80065870: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80065874: srl        $t5, $t5, 8 */
".word 0x10600019\n\t" /* 80065878: beqz       $v1, .L800658E0 */
".word 0xAC4D0000\n\t" /* 8006587C: sw        $t5, 0x0($v0) */
".word 0x12400017\n\t" /* 80065880: beqz       $s2, .L800658E0 */
".word 0x00084400\n\t" /* 80065884: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80065888: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 8006588C: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80065890: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80065894: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80065898: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 8006589C: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 800658A0: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 800658A4: lw         $v1, 0xC($t9) */
".word 0xAF2C0044\n\t" /* 800658A8: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 800658AC: sw         $v1, 0x48($t9) */
".word 0x8F230018\n\t" /* 800658B0: lw         $v1, 0x18($t9) */
".word 0xAF2C0050\n\t" /* 800658B4: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 800658B8: sw         $v1, 0x54($t9) */
".word 0x8F230024\n\t" /* 800658BC: lw         $v1, 0x24($t9) */
".word 0xAF2C005C\n\t" /* 800658C0: sw         $t4, 0x5C($t9) */
".word 0xAF230060\n\t" /* 800658C4: sw         $v1, 0x60($t9) */
".word 0x8F230030\n\t" /* 800658C8: lw         $v1, 0x30($t9) */
".word 0xAF2C0068\n\t" /* 800658CC: sw         $t4, 0x68($t9) */
".word 0xAF23006C\n\t" /* 800658D0: sw         $v1, 0x6C($t9) */
".word 0x2739003C\n\t" /* 800658D4: addiu      $t9, $t9, 0x3C */
".word 0x08019610\n\t" /* 800658D8: j          .L80065840 */
".word 0x24030000\n\t" /* 800658DC: addiu     $v1, $zero, 0x0 */
".L800658E0:\n\t"
".word 0x2739003C\n\t" /* 800658E0: addiu      $t9, $t9, 0x3C */
".L800658E4:\n\t"
".word 0x2718FFFF\n\t" /* 800658E4: addiu      $t8, $t8, -0x1 */
".word 0x1700FF51\n\t" /* 800658E8: bnez       $t8, .L80065630 */
".word 0x24E70020\n\t" /* 800658EC: addiu     $a3, $a3, 0x20 */
".L800658F0:\n\t"
".word 0x8C900020\n\t" /* 800658F0: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 800658F4: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 800658F8: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 800658FC: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 80065900: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 80065904: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 80065908: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 8006590C: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80065910: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80065914: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80065918: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 8006591C: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80065920: jr         $ra */
".word 0x00000000\n\t" /* 80065924: nop */
    ".set reorder\n"
);
