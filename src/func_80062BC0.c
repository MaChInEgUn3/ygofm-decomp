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
    ".global func_80062BC0\n"
    "func_80062BC0:\n"
".word 0x8C870000\n\t" /* 80062BC0: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80062BC4: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80062BC8: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80062BCC: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80062BD0: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80062BD4: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80062BD8: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80062BDC: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80062BE0: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80062BE4: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 80062BE8: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 80062BEC: sw         $s7, 0x34($a0) */
".word 0x13000093\n\t" /* 80062BF0: beqz       $t8, .L80062E40 */
".word 0x00A63821\n\t" /* 80062BF4: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80062BF8: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 80062BFC: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 80062C00: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80062C04: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80062C08: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80062C0C: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80062C10: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80062C14: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80062C18: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80062C1C: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80062C20: addu       $t4, $s0, $zero */
".word 0x00109E02\n\t" /* 80062C24: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 80062C28: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80062C2C: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80062C30: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80062C34: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80062C38: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80062C3C: lw         $t7, 0x4($t5) */
".L80062C40:\n\t"
".word 0x8CE8000C\n\t" /* 80062C40: lw         $t0, 0xC($a3) */
".word 0x8CE90010\n\t" /* 80062C44: lw         $t1, 0x10($a3) */
".word 0x8CEA0014\n\t" /* 80062C48: lw         $t2, 0x14($a3) */
".word 0x00086C02\n\t" /* 80062C4C: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80062C50: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80062C54: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80062C58: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80062C5C: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 80062C60: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80062C64: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80062C68: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80062C6C: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80062C70: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 80062C74: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80062C78: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80062C7C: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80062C80: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80062C84: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 80062C88: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80062C8C: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 80062C90: rtpt */
".word 0x00094C00\n\t" /* 80062C94: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 80062C98: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 80062C9C: sll        $t2, $t2, 16 */
".word 0x24010001\n\t" /* 80062CA0: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80062CA4: beq        $s6, $at, .L80062CBC */
".word 0x000A5342\n\t" /* 80062CA8: srl       $t2, $t2, 13 */
".word 0x4842F800\n\t" /* 80062CAC: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80062CB0: nop */
".word 0x0440005F\n\t" /* 80062CB4: bltz       $v0, .L80062E34 */
".word 0x00000000\n\t" /* 80062CB8: nop */
".L80062CBC:\n\t"
".word 0x4B58002D\n\t" /* 80062CBC: avsz3 */
".word 0x12C0001E\n\t" /* 80062CC0: beqz       $s6, .L80062D3C */
".word 0x01066821\n\t" /* 80062CC4: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80062CC8: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80062CCC: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 80062CD0: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 80062CD4: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80062CD8: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 80062CDC: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 80062CE0: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80062CE4: lwc2       $5, 0x4($t5) */
".word 0x00000000\n\t" /* 80062CE8: nop */
".word 0x00000000\n\t" /* 80062CEC: nop */
".word 0x4B18043F\n\t" /* 80062CF0: ncct */
".word 0x12E00009\n\t" /* 80062CF4: beqz       $s7, .L80062D1C */
".word 0x00084042\n\t" /* 80062CF8: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 80062CFC: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 80062D00: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 80062D04: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 80062D08: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 80062D0C: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 80062D10: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 80062D14: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 80062D18: swc2       $22, 0x0($t2) */
".L80062D1C:\n\t"
".word 0xEB340004\n\t" /* 80062D1C: swc2       $20, 0x4($t9) */
".word 0xEB350010\n\t" /* 80062D20: swc2       $21, 0x10($t9) */
".word 0xEB36001C\n\t" /* 80062D24: swc2       $22, 0x1C($t9) */
".word 0x24010001\n\t" /* 80062D28: addiu      $at, $zero, 0x1 */
".word 0x12C10041\n\t" /* 80062D2C: beq        $s6, $at, .L80062E34 */
".word 0x00000000\n\t" /* 80062D30: nop */
".word 0x08018B5C\n\t" /* 80062D34: j          .L80062D70 */
".word 0x00000000\n\t" /* 80062D38: nop */
".L80062D3C:\n\t"
".word 0x00084042\n\t" /* 80062D3C: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80062D40: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80062D44: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 80062D48: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 80062D4C: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 80062D50: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 80062D54: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 80062D58: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 80062D5C: lw         $t2, 0x0($v1) */
".word 0xAF280004\n\t" /* 80062D60: sw         $t0, 0x4($t9) */
".word 0xAF290010\n\t" /* 80062D64: sw         $t1, 0x10($t9) */
".word 0xAF2A001C\n\t" /* 80062D68: sw         $t2, 0x1C($t9) */
".word 0xA3330007\n\t" /* 80062D6C: sb         $s3, 0x7($t9) */
".L80062D70:\n\t"
".word 0x8CE80000\n\t" /* 80062D70: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80062D74: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80062D78: lw         $t2, 0x8($a3) */
".word 0x48023800\n\t" /* 80062D7C: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80062D80: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80062D84: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 80062D88: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80062D8C: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80062D90: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80062D94: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80062D98: lw         $t5, 0x0($v0) */
".word 0xEB2C0008\n\t" /* 80062D9C: swc2       $12, 0x8($t9) */
".word 0xEB2D0014\n\t" /* 80062DA0: swc2       $13, 0x14($t9) */
".word 0xEB2E0020\n\t" /* 80062DA4: swc2       $14, 0x20($t9) */
".L80062DA8:\n\t"
".word 0xAF28000C\n\t" /* 80062DA8: sw         $t0, 0xC($t9) */
".word 0xAF290018\n\t" /* 80062DAC: sw         $t1, 0x18($t9) */
".word 0xAF2A0024\n\t" /* 80062DB0: sw         $t2, 0x24($t9) */
".word 0x000D6A00\n\t" /* 80062DB4: sll        $t5, $t5, 8 */
".word 0x35AD0009\n\t" /* 80062DB8: ori        $t5, $t5, 0x9 */
".word 0x000D0A02\n\t" /* 80062DBC: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80062DC0: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80062DC4: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80062DC8: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80062DCC: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80062DD0: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 80062DD4: beqz       $v1, .L80062E30 */
".word 0xAC4D0000\n\t" /* 80062DD8: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 80062DDC: beqz       $s2, .L80062E30 */
".word 0x00084400\n\t" /* 80062DE0: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80062DE4: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80062DE8: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 80062DEC: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80062DF0: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80062DF4: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80062DF8: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 80062DFC: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 80062E00: lw         $v1, 0x8($t9) */
".word 0xAF2C002C\n\t" /* 80062E04: sw         $t4, 0x2C($t9) */
".word 0xAF230030\n\t" /* 80062E08: sw         $v1, 0x30($t9) */
".word 0x8F230014\n\t" /* 80062E0C: lw         $v1, 0x14($t9) */
".word 0xAF2C0038\n\t" /* 80062E10: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 80062E14: sw         $v1, 0x3C($t9) */
".word 0x8F230020\n\t" /* 80062E18: lw         $v1, 0x20($t9) */
".word 0xAF2C0044\n\t" /* 80062E1C: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80062E20: sw         $v1, 0x48($t9) */
".word 0x27390028\n\t" /* 80062E24: addiu      $t9, $t9, 0x28 */
".word 0x08018B6A\n\t" /* 80062E28: j          .L80062DA8 */
".word 0x24030000\n\t" /* 80062E2C: addiu     $v1, $zero, 0x0 */
".L80062E30:\n\t"
".word 0x27390028\n\t" /* 80062E30: addiu      $t9, $t9, 0x28 */
".L80062E34:\n\t"
".word 0x2718FFFF\n\t" /* 80062E34: addiu      $t8, $t8, -0x1 */
".word 0x1700FF81\n\t" /* 80062E38: bnez       $t8, .L80062C40 */
".word 0x24E70018\n\t" /* 80062E3C: addiu     $a3, $a3, 0x18 */
".L80062E40:\n\t"
".word 0x8C900020\n\t" /* 80062E40: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80062E44: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80062E48: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80062E4C: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 80062E50: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 80062E54: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 80062E58: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80062E5C: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80062E60: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80062E64: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80062E68: jr         $ra */
".word 0x00000000\n\t" /* 80062E6C: nop */
    ".set reorder\n"
);
