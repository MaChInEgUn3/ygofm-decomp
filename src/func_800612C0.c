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
    ".global func_800612C0\n"
    "func_800612C0:\n"
".word 0x8C870000\n\t" /* 800612C0: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 800612C4: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 800612C8: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 800612CC: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 800612D0: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 800612D4: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 800612D8: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 800612DC: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 800612E0: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 800612E4: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 800612E8: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 800612EC: sw         $s7, 0x34($a0) */
".word 0x1300007E\n\t" /* 800612F0: beqz       $t8, .L800614EC */
".word 0x00A63821\n\t" /* 800612F4: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 800612F8: lui        $s0, %hi(D_8009AFAC) */
".word 0x8E10AFAC\n\t" /* 800612FC: lw         $s0, %lo(D_8009AFAC)($s0) */
".word 0x3C11800A\n\t" /* 80061300: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80061304: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80061308: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 8006130C: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80061310: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80061314: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80061318: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 8006131C: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80061320: addu       $t4, $s0, $zero */
".word 0x00109E02\n\t" /* 80061324: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 80061328: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 8006132C: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80061330: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80061334: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80061338: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 8006133C: lw         $t7, 0x4($t5) */
".L80061340:\n\t"
".word 0x8CE8000C\n\t" /* 80061340: lw         $t0, 0xC($a3) */
".word 0x8CE90010\n\t" /* 80061344: lw         $t1, 0x10($a3) */
".word 0x00086C02\n\t" /* 80061348: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 8006134C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80061350: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80061354: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80061358: lwc2       $1, 0x4($t5) */
".word 0x00096C00\n\t" /* 8006135C: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 80061360: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80061364: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80061368: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 8006136C: lwc2       $3, 0x4($t5) */
".word 0x00096C02\n\t" /* 80061370: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80061374: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80061378: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 8006137C: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80061380: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 80061384: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80061388: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 8006138C: rtpt */
".word 0x24010001\n\t" /* 80061390: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 80061394: beq        $s6, $at, .L800613C0 */
".word 0x00000000\n\t" /* 80061398: nop */
".word 0x4842F800\n\t" /* 8006139C: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800613A0: nop */
".word 0x0440004E\n\t" /* 800613A4: bltz       $v0, .L800614E0 */
".word 0x00000000\n\t" /* 800613A8: nop */
".word 0x4B400006\n\t" /* 800613AC: nclip */
".word 0x4802C000\n\t" /* 800613B0: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800613B4: nop */
".word 0x18400049\n\t" /* 800613B8: blez       $v0, .L800614E0 */
".word 0x00000000\n\t" /* 800613BC: nop */
".L800613C0:\n\t"
".word 0x4B58002D\n\t" /* 800613C0: avsz3 */
".word 0x12C00010\n\t" /* 800613C4: beqz       $s6, .L80061408 */
".word 0x01066821\n\t" /* 800613C8: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 800613CC: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800613D0: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 800613D4: nop */
".word 0x00000000\n\t" /* 800613D8: nop */
".word 0x4B08041B\n\t" /* 800613DC: nccs */
".word 0x12E00003\n\t" /* 800613E0: beqz       $s7, .L800613F0 */
".word 0x00084042\n\t" /* 800613E4: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 800613E8: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 800613EC: swc2       $22, 0x0($t0) */
".L800613F0:\n\t"
".word 0xEB360004\n\t" /* 800613F0: swc2       $22, 0x4($t9) */
".word 0x24010001\n\t" /* 800613F4: addiu      $at, $zero, 0x1 */
".word 0x12C10039\n\t" /* 800613F8: beq        $s6, $at, .L800614E0 */
".word 0x00000000\n\t" /* 800613FC: nop */
".word 0x08018508\n\t" /* 80061400: j          .L80061420 */
".word 0x00000000\n\t" /* 80061404: nop */
".L80061408:\n\t"
".word 0x00084042\n\t" /* 80061408: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 8006140C: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80061410: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 80061414: nop */
".word 0xAF280004\n\t" /* 80061418: sw         $t0, 0x4($t9) */
".word 0xA3330007\n\t" /* 8006141C: sb         $s3, 0x7($t9) */
".L80061420:\n\t"
".word 0x8CE80000\n\t" /* 80061420: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80061424: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80061428: lw         $t2, 0x8($a3) */
".word 0x48023800\n\t" /* 8006142C: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80061430: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80061434: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 80061438: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 8006143C: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80061440: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80061444: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80061448: lw         $t5, 0x0($v0) */
".word 0xEB2C0008\n\t" /* 8006144C: swc2       $12, 0x8($t9) */
".word 0xEB2D0010\n\t" /* 80061450: swc2       $13, 0x10($t9) */
".word 0xEB2E0018\n\t" /* 80061454: swc2       $14, 0x18($t9) */
".L80061458:\n\t"
".word 0xAF28000C\n\t" /* 80061458: sw         $t0, 0xC($t9) */
".word 0xAF290014\n\t" /* 8006145C: sw         $t1, 0x14($t9) */
".word 0xAF2A001C\n\t" /* 80061460: sw         $t2, 0x1C($t9) */
".word 0x000D6A00\n\t" /* 80061464: sll        $t5, $t5, 8 */
".word 0x35AD0007\n\t" /* 80061468: ori        $t5, $t5, 0x7 */
".word 0x000D0A02\n\t" /* 8006146C: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80061470: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80061474: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80061478: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 8006147C: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80061480: srl        $t5, $t5, 8 */
".word 0x10600015\n\t" /* 80061484: beqz       $v1, .L800614DC */
".word 0xAC4D0000\n\t" /* 80061488: sw        $t5, 0x0($v0) */
".word 0x12400013\n\t" /* 8006148C: beqz       $s2, .L800614DC */
".word 0x00000000\n\t" /* 80061490: nop */
".word 0x3C01FF9F\n\t" /* 80061494: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80061498: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 8006149C: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 800614A0: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 800614A4: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 800614A8: lw         $v1, 0x8($t9) */
".word 0x00084400\n\t" /* 800614AC: sll        $t0, $t0, 16 */
".word 0xAF230028\n\t" /* 800614B0: sw         $v1, 0x28($t9) */
".word 0x8F230010\n\t" /* 800614B4: lw         $v1, 0x10($t9) */
".word 0x00084402\n\t" /* 800614B8: srl        $t0, $t0, 16 */
".word 0xAF230030\n\t" /* 800614BC: sw         $v1, 0x30($t9) */
".word 0x8F230018\n\t" /* 800614C0: lw         $v1, 0x18($t9) */
".word 0x01124025\n\t" /* 800614C4: or         $t0, $t0, $s2 */
".word 0xAF230038\n\t" /* 800614C8: sw         $v1, 0x38($t9) */
".word 0xAF2C0024\n\t" /* 800614CC: sw         $t4, 0x24($t9) */
".word 0x27390020\n\t" /* 800614D0: addiu      $t9, $t9, 0x20 */
".word 0x08018516\n\t" /* 800614D4: j          .L80061458 */
".word 0x24030000\n\t" /* 800614D8: addiu     $v1, $zero, 0x0 */
".L800614DC:\n\t"
".word 0x27390020\n\t" /* 800614DC: addiu      $t9, $t9, 0x20 */
".L800614E0:\n\t"
".word 0x2718FFFF\n\t" /* 800614E0: addiu      $t8, $t8, -0x1 */
".word 0x1700FF96\n\t" /* 800614E4: bnez       $t8, .L80061340 */
".word 0x24E70014\n\t" /* 800614E8: addiu     $a3, $a3, 0x14 */
".L800614EC:\n\t"
".word 0x8C900020\n\t" /* 800614EC: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 800614F0: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 800614F4: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 800614F8: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 800614FC: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 80061500: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 80061504: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80061508: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 8006150C: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80061510: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80061514: jr         $ra */
".word 0x00000000\n\t" /* 80061518: nop */
    ".set reorder\n"
);
