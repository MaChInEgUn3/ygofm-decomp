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
    ".global func_80064568\n"
    "func_80064568:\n"
".word 0x8C870000\n\t" /* 80064568: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 8006456C: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80064570: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80064574: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80064578: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 8006457C: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80064580: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80064584: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80064588: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 8006458C: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 80064590: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 80064594: sw         $s7, 0x34($a0) */
".word 0x130000A7\n\t" /* 80064598: beqz       $t8, .L80064838 */
".word 0x00A63821\n\t" /* 8006459C: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 800645A0: lui        $s0, %hi(D_8009AFB0) */
".word 0x8E10AFB0\n\t" /* 800645A4: lw         $s0, %lo(D_8009AFB0)($s0) */
".word 0x3C11800A\n\t" /* 800645A8: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 800645AC: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800645B0: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 800645B4: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 800645B8: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 800645BC: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 800645C0: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 800645C4: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 800645C8: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 800645CC: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 800645D0: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 800645D4: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 800645D8: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 800645DC: bnez       $v0, .L80064618 */
".word 0x02006021\n\t" /* 800645E0: addu      $t4, $s0, $zero */
".word 0x8CF10004\n\t" /* 800645E4: lw         $s1, 0x4($a3) */
".word 0x3C010060\n\t" /* 800645E8: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 800645EC: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 800645F0: bnez       $s1, .L80064618 */
".word 0x00000000\n\t" /* 800645F4: nop */
".word 0x12400008\n\t" /* 800645F8: beqz       $s2, .L8006461C */
".word 0x00000000\n\t" /* 800645FC: nop */
".word 0x94F20002\n\t" /* 80064600: lhu        $s2, 0x2($a3) */
".word 0x3C0C800A\n\t" /* 80064604: lui        $t4, %hi(D_8009AFC0) */
".word 0x8D8CAFC0\n\t" /* 80064608: lw         $t4, %lo(D_8009AFC0)($t4) */
".word 0x00129400\n\t" /* 8006460C: sll        $s2, $s2, 16 */
".word 0x08019187\n\t" /* 80064610: j          .L8006461C */
".word 0x3C110020\n\t" /* 80064614: lui       $s1, (0x200000 >> 16) */
".L80064618:\n\t"
".word 0x24120000\n\t" /* 80064618: addiu      $s2, $zero, 0x0 */
".L8006461C:\n\t"
".word 0x00109E02\n\t" /* 8006461C: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 80064620: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80064624: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80064628: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 8006462C: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80064630: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80064634: lw         $t7, 0x4($t5) */
".L80064638:\n\t"
".word 0x8CE80010\n\t" /* 80064638: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 8006463C: lw         $t1, 0x14($a3) */
".word 0x00086C00\n\t" /* 80064640: sll        $t5, $t0, 16 */
".word 0x000D6B42\n\t" /* 80064644: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80064648: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 8006464C: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80064650: lwc2       $1, 0x4($t5) */
".word 0x00086C02\n\t" /* 80064654: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80064658: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006465C: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80064660: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80064664: lwc2       $3, 0x4($t5) */
".word 0x00096C00\n\t" /* 80064668: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 8006466C: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80064670: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80064674: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80064678: lwc2       $5, 0x4($t5) */
".word 0x00095C02\n\t" /* 8006467C: srl        $t3, $t1, 16 */
".word 0x000B58C0\n\t" /* 80064680: sll        $t3, $t3, 3 */
".word 0x4A280030\n\t" /* 80064684: rtpt */
".word 0x24010001\n\t" /* 80064688: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 8006468C: beq        $s6, $at, .L800646B8 */
".word 0x01656821\n\t" /* 80064690: addu      $t5, $t3, $a1 */
".word 0x4842F800\n\t" /* 80064694: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80064698: nop */
".word 0x04400063\n\t" /* 8006469C: bltz       $v0, .L8006482C */
".word 0x00000000\n\t" /* 800646A0: nop */
".word 0x4B400006\n\t" /* 800646A4: nclip */
".word 0x4802C000\n\t" /* 800646A8: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800646AC: nop */
".word 0x1840005E\n\t" /* 800646B0: blez       $v0, .L8006482C */
".word 0x00000000\n\t" /* 800646B4: nop */
".L800646B8:\n\t"
".word 0xC9A00000\n\t" /* 800646B8: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800646BC: lwc2       $1, 0x4($t5) */
".word 0xEB2C0008\n\t" /* 800646C0: swc2       $12, 0x8($t9) */
".word 0xEB2D0010\n\t" /* 800646C4: swc2       $13, 0x10($t9) */
".word 0xEB2E0018\n\t" /* 800646C8: swc2       $14, 0x18($t9) */
".word 0x00000000\n\t" /* 800646CC: nop */
".word 0x00000000\n\t" /* 800646D0: nop */
".word 0x4A180001\n\t" /* 800646D4: rtps */
".word 0x94E8000E\n\t" /* 800646D8: lhu        $t0, 0xE($a3) */
".word 0x24010001\n\t" /* 800646DC: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 800646E0: beq        $s6, $at, .L800646F8 */
".word 0x000840C0\n\t" /* 800646E4: sll       $t0, $t0, 3 */
".word 0x4842F800\n\t" /* 800646E8: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800646EC: nop */
".word 0x0440004E\n\t" /* 800646F0: bltz       $v0, .L8006482C */
".word 0x00000000\n\t" /* 800646F4: nop */
".L800646F8:\n\t"
".word 0x4B68002E\n\t" /* 800646F8: avsz4 */
".word 0x12C00010\n\t" /* 800646FC: beqz       $s6, .L80064740 */
".word 0x01066821\n\t" /* 80064700: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80064704: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80064708: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 8006470C: nop */
".word 0x00000000\n\t" /* 80064710: nop */
".word 0x4B08041B\n\t" /* 80064714: nccs */
".word 0x12E00003\n\t" /* 80064718: beqz       $s7, .L80064728 */
".word 0x00084042\n\t" /* 8006471C: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80064720: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 80064724: swc2       $22, 0x0($t0) */
".L80064728:\n\t"
".word 0xEB360004\n\t" /* 80064728: swc2       $22, 0x4($t9) */
".word 0x24010001\n\t" /* 8006472C: addiu      $at, $zero, 0x1 */
".word 0x12C1003E\n\t" /* 80064730: beq        $s6, $at, .L8006482C */
".word 0x00000000\n\t" /* 80064734: nop */
".word 0x080191D6\n\t" /* 80064738: j          .L80064758 */
".word 0x00000000\n\t" /* 8006473C: nop */
".L80064740:\n\t"
".word 0x00084042\n\t" /* 80064740: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80064744: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80064748: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 8006474C: nop */
".word 0xAF280004\n\t" /* 80064750: sw         $t0, 0x4($t9) */
".word 0xA3330007\n\t" /* 80064754: sb         $s3, 0x7($t9) */
".L80064758:\n\t"
".word 0x8CE80000\n\t" /* 80064758: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 8006475C: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80064760: lw         $t2, 0x8($a3) */
".word 0x8CEB000C\n\t" /* 80064764: lw         $t3, 0xC($a3) */
".word 0x48023800\n\t" /* 80064768: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 8006476C: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80064770: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80064774: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80064778: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 8006477C: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80064780: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80064784: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80064788: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 8006478C: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80064790: lw         $t5, 0x0($v0) */
".word 0xEB2E0020\n\t" /* 80064794: swc2       $14, 0x20($t9) */
".L80064798:\n\t"
".word 0xAF28000C\n\t" /* 80064798: sw         $t0, 0xC($t9) */
".word 0xAF290014\n\t" /* 8006479C: sw         $t1, 0x14($t9) */
".word 0xAF2A001C\n\t" /* 800647A0: sw         $t2, 0x1C($t9) */
".word 0xAF2B0024\n\t" /* 800647A4: sw         $t3, 0x24($t9) */
".word 0x000D6A00\n\t" /* 800647A8: sll        $t5, $t5, 8 */
".word 0x35AD0009\n\t" /* 800647AC: ori        $t5, $t5, 0x9 */
".word 0x000D0A02\n\t" /* 800647B0: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 800647B4: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 800647B8: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 800647BC: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 800647C0: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 800647C4: srl        $t5, $t5, 8 */
".word 0x10600017\n\t" /* 800647C8: beqz       $v1, .L80064828 */
".word 0xAC4D0000\n\t" /* 800647CC: sw        $t5, 0x0($v0) */
".word 0x12400015\n\t" /* 800647D0: beqz       $s2, .L80064828 */
".word 0x00000000\n\t" /* 800647D4: nop */
".word 0x3C01FF9F\n\t" /* 800647D8: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800647DC: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800647E0: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 800647E4: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 800647E8: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 800647EC: lw         $v1, 0x8($t9) */
".word 0x00084400\n\t" /* 800647F0: sll        $t0, $t0, 16 */
".word 0xAF230030\n\t" /* 800647F4: sw         $v1, 0x30($t9) */
".word 0x8F230010\n\t" /* 800647F8: lw         $v1, 0x10($t9) */
".word 0x00084402\n\t" /* 800647FC: srl        $t0, $t0, 16 */
".word 0xAF230038\n\t" /* 80064800: sw         $v1, 0x38($t9) */
".word 0x8F230018\n\t" /* 80064804: lw         $v1, 0x18($t9) */
".word 0x01124025\n\t" /* 80064808: or         $t0, $t0, $s2 */
".word 0xAF230040\n\t" /* 8006480C: sw         $v1, 0x40($t9) */
".word 0x8F230020\n\t" /* 80064810: lw         $v1, 0x20($t9) */
".word 0xAF2C002C\n\t" /* 80064814: sw         $t4, 0x2C($t9) */
".word 0xAF230048\n\t" /* 80064818: sw         $v1, 0x48($t9) */
".word 0x27390028\n\t" /* 8006481C: addiu      $t9, $t9, 0x28 */
".word 0x080191E6\n\t" /* 80064820: j          .L80064798 */
".word 0x24030000\n\t" /* 80064824: addiu     $v1, $zero, 0x0 */
".L80064828:\n\t"
".word 0x27390028\n\t" /* 80064828: addiu      $t9, $t9, 0x28 */
".L8006482C:\n\t"
".word 0x2718FFFF\n\t" /* 8006482C: addiu      $t8, $t8, -0x1 */
".word 0x1700FF81\n\t" /* 80064830: bnez       $t8, .L80064638 */
".word 0x24E70018\n\t" /* 80064834: addiu     $a3, $a3, 0x18 */
".L80064838:\n\t"
".word 0x8C900020\n\t" /* 80064838: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 8006483C: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80064840: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80064844: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 80064848: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 8006484C: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 80064850: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80064854: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80064858: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 8006485C: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80064860: jr         $ra */
".word 0x00000000\n\t" /* 80064864: nop */
    ".set reorder\n"
);
