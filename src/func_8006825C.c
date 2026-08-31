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

/* GTE precomputed-color (GT3, extra id field + fixed 0xE2000000 tag word)
   triangle OT-insert loop, no NCLIP backface-cull step. ~150 instructions
   with 6 saved registers (s0-s5) live across the loop plus 4 GTE-fed
   scratch regs (t4-t7); C-level register pinning proved unworkable, so
   transcribed verbatim from the raw disassembly instead (same technique
   as func_8002CEE8.c, see project_gte_register_spill_and_pin_techniques.md
   and project_whole_function_raw_asm_transcription_technique.md).
   Zero jal calls in this function (pure GTE leaf, mtc2/avsz3/mfc2 only),
   so every address reference is a literal absolute (baked in from the
   original linked ROM), not a relocatable symbol reference. */
__asm__(
    ".set noreorder\n"
    ".global func_8006825C\n"
    "func_8006825C:\n"
".word 0x8C870000\n\t" /* 8006825C: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80068260: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80068264: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80068268: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 8006826C: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80068270: sll        $a2, $a2, 2 */
".word 0xAC900028\n\t" /* 80068274: sw         $s0, 0x28($a0) */
".word 0xAC91002C\n\t" /* 80068278: sw         $s1, 0x2C($a0) */
".word 0xAC920030\n\t" /* 8006827C: sw         $s2, 0x30($a0) */
".word 0xAC930034\n\t" /* 80068280: sw         $s3, 0x34($a0) */
".word 0xAC940038\n\t" /* 80068284: sw         $s4, 0x38($a0) */
".word 0xAC95003C\n\t" /* 80068288: sw         $s5, 0x3C($a0) */
".word 0x1300007D\n\t" /* 8006828C: beqz       $t8, .L80068484 */
".word 0x00A63821\n\t" /* 80068290: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80068294: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 80068298: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 8006829C: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 800682A0: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800682A4: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 800682A8: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x02006021\n\t" /* 800682AC: addu       $t4, $s0, $zero */
".word 0x3C0D800A\n\t" /* 800682B0: lui        $t5, %hi(D_8009AFE4) */
".word 0x81ADAFE4\n\t" /* 800682B4: lb         $t5, %lo(D_8009AFE4)($t5) */
".word 0x00109E02\n\t" /* 800682B8: srl        $s3, $s0, 24 */
".word 0x00139E00\n\t" /* 800682BC: sll        $s3, $s3, 24 */
".word 0x24010001\n\t" /* 800682C0: addiu      $at, $zero, 0x1 */
".word 0x11A1006F\n\t" /* 800682C4: beq        $t5, $at, .L80068484 */
".word 0x3C14E200\n\t" /* 800682C8: lui       $s4, (0xE2000000 >> 16) */
".word 0x3C0D800A\n\t" /* 800682CC: lui        $t5, %hi(D_8009AFE0) */
".word 0x8DADAFE0\n\t" /* 800682D0: lw         $t5, %lo(D_8009AFE0)($t5) */
".word 0x8C85001C\n\t" /* 800682D4: lw         $a1, 0x1C($a0) */
".word 0x8C860024\n\t" /* 800682D8: lw         $a2, 0x24($a0) */
".word 0x11A00002\n\t" /* 800682DC: beqz       $t5, .L800682E8 */
".word 0x00000000\n\t" /* 800682E0: nop */
".word 0x24C60004\n\t" /* 800682E4: addiu      $a2, $a2, 0x4 */
".L800682E8:\n\t"
".word 0x8C8D0004\n\t" /* 800682E8: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 800682EC: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 800682F0: lw         $t7, 0x4($t5) */
".L800682F4:\n\t"
".word 0x2403FFFF\n\t" /* 800682F4: addiu      $v1, $zero, -0x1 */
".word 0x8CE80010\n\t" /* 800682F8: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 800682FC: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 80068300: lw         $t2, 0x18($a3) */
".word 0x00086C02\n\t" /* 80068304: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80068308: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006830C: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80068310: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80068314: lw         $t5, 0x0($t5) */
".word 0x10430057\n\t" /* 80068318: beq        $v0, $v1, .L80068478 */
".word 0x48828800\n\t" /* 8006831C: mtc2      $v0, $17 ( handwritten instruction ) */
".word 0x488D6000\n\t" /* 80068320: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0xAF2D000C\n\t" /* 80068324: sw         $t5, 0xC($t9) */
".word 0x00096C02\n\t" /* 80068328: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 8006832C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80068330: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80068334: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80068338: lw         $t5, 0x0($t5) */
".word 0x1043004E\n\t" /* 8006833C: beq        $v0, $v1, .L80068478 */
".word 0x48829000\n\t" /* 80068340: mtc2      $v0, $18 ( handwritten instruction ) */
".word 0x488D6800\n\t" /* 80068344: mtc2       $t5, $13 ( handwritten instruction ) */
".word 0xAF2D0018\n\t" /* 80068348: sw         $t5, 0x18($t9) */
".word 0x000A6C02\n\t" /* 8006834C: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80068350: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80068354: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80068358: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 8006835C: lw         $t5, 0x0($t5) */
".word 0x10430045\n\t" /* 80068360: beq        $v0, $v1, .L80068478 */
".word 0x48829800\n\t" /* 80068364: mtc2      $v0, $19 ( handwritten instruction ) */
".word 0x488D7000\n\t" /* 80068368: mtc2       $t5, $14 ( handwritten instruction ) */
".word 0xAF2D0024\n\t" /* 8006836C: sw         $t5, 0x24($t9) */
".word 0x00084400\n\t" /* 80068370: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80068374: srl        $t0, $t0, 13 */
".word 0x00094C00\n\t" /* 80068378: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 8006837C: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 80068380: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80068384: srl        $t2, $t2, 13 */
".word 0x01064021\n\t" /* 80068388: addu       $t0, $t0, $a2 */
".word 0x01264821\n\t" /* 8006838C: addu       $t1, $t1, $a2 */
".word 0x01465021\n\t" /* 80068390: addu       $t2, $t2, $a2 */
".word 0x8D080000\n\t" /* 80068394: lw         $t0, 0x0($t0) */
".word 0x8D290000\n\t" /* 80068398: lw         $t1, 0x0($t1) */
".word 0x8D4A0000\n\t" /* 8006839C: lw         $t2, 0x0($t2) */
".word 0x4B58002D\n\t" /* 800683A0: avsz3 */
".word 0x01134025\n\t" /* 800683A4: or         $t0, $t0, $s3 */
".word 0xAF280008\n\t" /* 800683A8: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 800683AC: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 800683B0: sw         $t2, 0x20($t9) */
".word 0x8CF50000\n\t" /* 800683B4: lw         $s5, 0x0($a3) */
".word 0x8CE80004\n\t" /* 800683B8: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 800683BC: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 800683C0: lw         $t2, 0xC($a3) */
".word 0x48023800\n\t" /* 800683C4: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 800683C8: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 800683CC: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 800683D0: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 800683D4: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 800683D8: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 800683DC: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 800683E0: lw         $t5, 0x0($v0) */
".L800683E4:\n\t"
".word 0xAF280010\n\t" /* 800683E4: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 800683E8: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 800683EC: sw         $t2, 0x28($t9) */
".word 0xAF350004\n\t" /* 800683F0: sw         $s5, 0x4($t9) */
".word 0xAF34002C\n\t" /* 800683F4: sw         $s4, 0x2C($t9) */
".word 0x000D6A00\n\t" /* 800683F8: sll        $t5, $t5, 8 */
".word 0x35AD000B\n\t" /* 800683FC: ori        $t5, $t5, 0xB */
".word 0x000D0A02\n\t" /* 80068400: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80068404: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80068408: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 8006840C: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80068410: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80068414: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 80068418: beqz       $v1, .L80068474 */
".word 0xAC4D0000\n\t" /* 8006841C: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 80068420: beqz       $s2, .L80068474 */
".word 0x00084400\n\t" /* 80068424: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80068428: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 8006842C: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80068430: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80068434: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80068438: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 8006843C: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80068440: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 80068444: lw         $v1, 0xC($t9) */
".word 0xAF2C0038\n\t" /* 80068448: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 8006844C: sw         $v1, 0x3C($t9) */
".word 0x8F230018\n\t" /* 80068450: lw         $v1, 0x18($t9) */
".word 0xAF2C0044\n\t" /* 80068454: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80068458: sw         $v1, 0x48($t9) */
".word 0x8F230024\n\t" /* 8006845C: lw         $v1, 0x24($t9) */
".word 0xAF2C0050\n\t" /* 80068460: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80068464: sw         $v1, 0x54($t9) */
".word 0x27390030\n\t" /* 80068468: addiu      $t9, $t9, 0x30 */
".word 0x0801A0F9\n\t" /* 8006846C: j          .L800683E4 */
".word 0x24030000\n\t" /* 80068470: addiu     $v1, $zero, 0x0 */
".L80068474:\n\t"
".word 0x27390030\n\t" /* 80068474: addiu      $t9, $t9, 0x30 */
".L80068478:\n\t"
".word 0x2718FFFF\n\t" /* 80068478: addiu      $t8, $t8, -0x1 */
".word 0x1700FF9D\n\t" /* 8006847C: bnez       $t8, .L800682F4 */
".word 0x24E7001C\n\t" /* 80068480: addiu     $a3, $a3, 0x1C */
".L80068484:\n\t"
".word 0x8C900028\n\t" /* 80068484: lw         $s0, 0x28($a0) */
".word 0x8C91002C\n\t" /* 80068488: lw         $s1, 0x2C($a0) */
".word 0x8C920030\n\t" /* 8006848C: lw         $s2, 0x30($a0) */
".word 0x8C930034\n\t" /* 80068490: lw         $s3, 0x34($a0) */
".word 0x8C940038\n\t" /* 80068494: lw         $s4, 0x38($a0) */
".word 0x8C95003C\n\t" /* 80068498: lw         $s5, 0x3C($a0) */
".word 0x8C820000\n\t" /* 8006849C: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 800684A0: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 800684A4: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 800684A8: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 800684AC: jr         $ra */
".word 0x00000000\n\t" /* 800684B0: nop */
    ".set reorder\n"
);
