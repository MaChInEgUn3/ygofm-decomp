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
    ".global func_80063F90\n"
    "func_80063F90:\n"
".word 0x8C870000\n\t" /* 80063F90: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80063F94: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80063F98: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80063F9C: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80063FA0: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80063FA4: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80063FA8: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80063FAC: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80063FB0: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80063FB4: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 80063FB8: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 80063FBC: sw         $s7, 0x34($a0) */
".word 0x13000095\n\t" /* 80063FC0: beqz       $t8, .L80064218 */
".word 0x00A63821\n\t" /* 80063FC4: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80063FC8: lui        $s0, %hi(D_8009AFAC) */
".word 0x8E10AFAC\n\t" /* 80063FCC: lw         $s0, %lo(D_8009AFAC)($s0) */
".word 0x3C11800A\n\t" /* 80063FD0: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80063FD4: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80063FD8: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80063FDC: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80063FE0: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80063FE4: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80063FE8: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80063FEC: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80063FF0: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 80063FF4: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 80063FF8: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 80063FFC: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 80064000: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 80064004: bnez       $v0, .L80064040 */
".word 0x02006021\n\t" /* 80064008: addu      $t4, $s0, $zero */
".word 0x8CF10004\n\t" /* 8006400C: lw         $s1, 0x4($a3) */
".word 0x3C010060\n\t" /* 80064010: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 80064014: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 80064018: bnez       $s1, .L80064040 */
".word 0x00000000\n\t" /* 8006401C: nop */
".word 0x12400008\n\t" /* 80064020: beqz       $s2, .L80064044 */
".word 0x00000000\n\t" /* 80064024: nop */
".word 0x94F20002\n\t" /* 80064028: lhu        $s2, 0x2($a3) */
".word 0x3C0C800A\n\t" /* 8006402C: lui        $t4, %hi(D_8009AFBC) */
".word 0x8D8CAFBC\n\t" /* 80064030: lw         $t4, %lo(D_8009AFBC)($t4) */
".word 0x00129400\n\t" /* 80064034: sll        $s2, $s2, 16 */
".word 0x08019011\n\t" /* 80064038: j          .L80064044 */
".word 0x3C110020\n\t" /* 8006403C: lui       $s1, (0x200000 >> 16) */
".L80064040:\n\t"
".word 0x24120000\n\t" /* 80064040: addiu      $s2, $zero, 0x0 */
".L80064044:\n\t"
".word 0x00109E02\n\t" /* 80064044: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 80064048: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 8006404C: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80064050: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80064054: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80064058: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 8006405C: lw         $t7, 0x4($t5) */
".L80064060:\n\t"
".word 0x8CE8000C\n\t" /* 80064060: lw         $t0, 0xC($a3) */
".word 0x8CE90010\n\t" /* 80064064: lw         $t1, 0x10($a3) */
".word 0x00086C02\n\t" /* 80064068: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 8006406C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80064070: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80064074: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80064078: lwc2       $1, 0x4($t5) */
".word 0x00096C00\n\t" /* 8006407C: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 80064080: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80064084: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80064088: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 8006408C: lwc2       $3, 0x4($t5) */
".word 0x00096C02\n\t" /* 80064090: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80064094: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80064098: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 8006409C: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 800640A0: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 800640A4: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 800640A8: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 800640AC: rtpt */
".word 0x24010001\n\t" /* 800640B0: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 800640B4: beq        $s6, $at, .L800640E0 */
".word 0x00000000\n\t" /* 800640B8: nop */
".word 0x4842F800\n\t" /* 800640BC: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800640C0: nop */
".word 0x04400051\n\t" /* 800640C4: bltz       $v0, .L8006420C */
".word 0x00000000\n\t" /* 800640C8: nop */
".word 0x4B400006\n\t" /* 800640CC: nclip */
".word 0x4802C000\n\t" /* 800640D0: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800640D4: nop */
".word 0x1840004C\n\t" /* 800640D8: blez       $v0, .L8006420C */
".word 0x00000000\n\t" /* 800640DC: nop */
".L800640E0:\n\t"
".word 0x4B58002D\n\t" /* 800640E0: avsz3 */
".word 0x12C00010\n\t" /* 800640E4: beqz       $s6, .L80064128 */
".word 0x01066821\n\t" /* 800640E8: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 800640EC: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800640F0: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 800640F4: nop */
".word 0x00000000\n\t" /* 800640F8: nop */
".word 0x4B08041B\n\t" /* 800640FC: nccs */
".word 0x12E00003\n\t" /* 80064100: beqz       $s7, .L80064110 */
".word 0x00084042\n\t" /* 80064104: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80064108: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 8006410C: swc2       $22, 0x0($t0) */
".L80064110:\n\t"
".word 0xEB360004\n\t" /* 80064110: swc2       $22, 0x4($t9) */
".word 0x24010001\n\t" /* 80064114: addiu      $at, $zero, 0x1 */
".word 0x12C1003C\n\t" /* 80064118: beq        $s6, $at, .L8006420C */
".word 0x00000000\n\t" /* 8006411C: nop */
".word 0x08019050\n\t" /* 80064120: j          .L80064140 */
".word 0x00000000\n\t" /* 80064124: nop */
".L80064128:\n\t"
".word 0x00084042\n\t" /* 80064128: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 8006412C: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80064130: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 80064134: nop */
".word 0xAF280004\n\t" /* 80064138: sw         $t0, 0x4($t9) */
".word 0xA3330007\n\t" /* 8006413C: sb         $s3, 0x7($t9) */
".L80064140:\n\t"
".word 0x8CE80000\n\t" /* 80064140: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80064144: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80064148: lw         $t2, 0x8($a3) */
".word 0x48023800\n\t" /* 8006414C: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80064150: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80064154: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80064158: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 8006415C: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80064160: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80064164: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80064168: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 8006416C: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80064170: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80064174: lw         $t5, 0x0($v0) */
".word 0xEB2C0008\n\t" /* 80064178: swc2       $12, 0x8($t9) */
".word 0xEB2D0010\n\t" /* 8006417C: swc2       $13, 0x10($t9) */
".word 0xEB2E0018\n\t" /* 80064180: swc2       $14, 0x18($t9) */
".L80064184:\n\t"
".word 0xAF28000C\n\t" /* 80064184: sw         $t0, 0xC($t9) */
".word 0xAF290014\n\t" /* 80064188: sw         $t1, 0x14($t9) */
".word 0xAF2A001C\n\t" /* 8006418C: sw         $t2, 0x1C($t9) */
".word 0x000D6A00\n\t" /* 80064190: sll        $t5, $t5, 8 */
".word 0x35AD0007\n\t" /* 80064194: ori        $t5, $t5, 0x7 */
".word 0x000D0A02\n\t" /* 80064198: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 8006419C: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 800641A0: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 800641A4: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 800641A8: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 800641AC: srl        $t5, $t5, 8 */
".word 0x10600015\n\t" /* 800641B0: beqz       $v1, .L80064208 */
".word 0xAC4D0000\n\t" /* 800641B4: sw        $t5, 0x0($v0) */
".word 0x12400013\n\t" /* 800641B8: beqz       $s2, .L80064208 */
".word 0x00000000\n\t" /* 800641BC: nop */
".word 0x3C01FF9F\n\t" /* 800641C0: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800641C4: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800641C8: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 800641CC: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 800641D0: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 800641D4: lw         $v1, 0x8($t9) */
".word 0x00084400\n\t" /* 800641D8: sll        $t0, $t0, 16 */
".word 0xAF230028\n\t" /* 800641DC: sw         $v1, 0x28($t9) */
".word 0x8F230010\n\t" /* 800641E0: lw         $v1, 0x10($t9) */
".word 0x00084402\n\t" /* 800641E4: srl        $t0, $t0, 16 */
".word 0xAF230030\n\t" /* 800641E8: sw         $v1, 0x30($t9) */
".word 0x8F230018\n\t" /* 800641EC: lw         $v1, 0x18($t9) */
".word 0x01124025\n\t" /* 800641F0: or         $t0, $t0, $s2 */
".word 0xAF230038\n\t" /* 800641F4: sw         $v1, 0x38($t9) */
".word 0xAF2C0024\n\t" /* 800641F8: sw         $t4, 0x24($t9) */
".word 0x27390020\n\t" /* 800641FC: addiu      $t9, $t9, 0x20 */
".word 0x08019061\n\t" /* 80064200: j          .L80064184 */
".word 0x24030000\n\t" /* 80064204: addiu     $v1, $zero, 0x0 */
".L80064208:\n\t"
".word 0x27390020\n\t" /* 80064208: addiu      $t9, $t9, 0x20 */
".L8006420C:\n\t"
".word 0x2718FFFF\n\t" /* 8006420C: addiu      $t8, $t8, -0x1 */
".word 0x1700FF93\n\t" /* 80064210: bnez       $t8, .L80064060 */
".word 0x24E70014\n\t" /* 80064214: addiu     $a3, $a3, 0x14 */
".L80064218:\n\t"
".word 0x8C900020\n\t" /* 80064218: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 8006421C: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80064220: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80064224: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 80064228: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 8006422C: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 80064230: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80064234: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80064238: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 8006423C: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80064240: jr         $ra */
".word 0x00000000\n\t" /* 80064244: nop */
    ".set reorder\n"
);
