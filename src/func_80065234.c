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
    ".global func_80065234\n"
    "func_80065234:\n"
".word 0x8C870000\n\t" /* 80065234: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80065238: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 8006523C: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80065240: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80065244: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80065248: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 8006524C: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80065250: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80065254: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80065258: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 8006525C: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 80065260: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 80065264: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 80065268: sw         $s7, 0x3C($a0) */
".word 0x130000AB\n\t" /* 8006526C: beqz       $t8, .L8006551C */
".word 0x00A63821\n\t" /* 80065270: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80065274: lui        $s0, %hi(D_8009AFB0) */
".word 0x8E10AFB0\n\t" /* 80065278: lw         $s0, %lo(D_8009AFB0)($s0) */
".word 0x3C11800A\n\t" /* 8006527C: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80065280: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80065284: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80065288: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 8006528C: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80065290: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80065294: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80065298: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 8006529C: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 800652A0: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 800652A4: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 800652A8: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 800652AC: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 800652B0: bnez       $v0, .L800652EC */
".word 0x02006021\n\t" /* 800652B4: addu      $t4, $s0, $zero */
".word 0x8CF10008\n\t" /* 800652B8: lw         $s1, 0x8($a3) */
".word 0x3C010060\n\t" /* 800652BC: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 800652C0: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 800652C4: bnez       $s1, .L800652EC */
".word 0x00000000\n\t" /* 800652C8: nop */
".word 0x12400008\n\t" /* 800652CC: beqz       $s2, .L800652F0 */
".word 0x00000000\n\t" /* 800652D0: nop */
".word 0x94F20006\n\t" /* 800652D4: lhu        $s2, 0x6($a3) */
".word 0x3C0C800A\n\t" /* 800652D8: lui        $t4, %hi(D_8009AFC0) */
".word 0x8D8CAFC0\n\t" /* 800652DC: lw         $t4, %lo(D_8009AFC0)($t4) */
".word 0x00129400\n\t" /* 800652E0: sll        $s2, $s2, 16 */
".word 0x080194BC\n\t" /* 800652E4: j          .L800652F0 */
".word 0x3C110020\n\t" /* 800652E8: lui       $s1, (0x200000 >> 16) */
".L800652EC:\n\t"
".word 0x24120000\n\t" /* 800652EC: addiu      $s2, $zero, 0x0 */
".L800652F0:\n\t"
".word 0x00109E02\n\t" /* 800652F0: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 800652F4: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 800652F8: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 800652FC: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80065300: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80065304: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80065308: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 8006530C: lw         $t7, 0x4($t5) */
".L80065310:\n\t"
".word 0x8CE80014\n\t" /* 80065310: lw         $t0, 0x14($a3) */
".word 0x8CE90018\n\t" /* 80065314: lw         $t1, 0x18($a3) */
".word 0x00086C00\n\t" /* 80065318: sll        $t5, $t0, 16 */
".word 0x000D6B42\n\t" /* 8006531C: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80065320: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 80065324: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80065328: lwc2       $1, 0x4($t5) */
".word 0x00086C02\n\t" /* 8006532C: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80065330: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80065334: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80065338: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 8006533C: lwc2       $3, 0x4($t5) */
".word 0x00096C00\n\t" /* 80065340: sll        $t5, $t1, 16 */
".word 0x000D6B42\n\t" /* 80065344: srl        $t5, $t5, 13 */
".word 0x01A56821\n\t" /* 80065348: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 8006534C: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80065350: lwc2       $5, 0x4($t5) */
".word 0x00095C02\n\t" /* 80065354: srl        $t3, $t1, 16 */
".word 0x000B58C0\n\t" /* 80065358: sll        $t3, $t3, 3 */
".word 0x4A280030\n\t" /* 8006535C: rtpt */
".word 0x24010001\n\t" /* 80065360: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 80065364: beq        $s6, $at, .L80065390 */
".word 0x01656821\n\t" /* 80065368: addu      $t5, $t3, $a1 */
".word 0x4842F800\n\t" /* 8006536C: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80065370: nop */
".word 0x04400066\n\t" /* 80065374: bltz       $v0, .L80065510 */
".word 0x00000000\n\t" /* 80065378: nop */
".word 0x4B400006\n\t" /* 8006537C: nclip */
".word 0x4802C000\n\t" /* 80065380: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80065384: nop */
".word 0x18400061\n\t" /* 80065388: blez       $v0, .L80065510 */
".word 0x00000000\n\t" /* 8006538C: nop */
".L80065390:\n\t"
".word 0xC9A00000\n\t" /* 80065390: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80065394: lwc2       $1, 0x4($t5) */
".word 0xEB2C000C\n\t" /* 80065398: swc2       $12, 0xC($t9) */
".word 0xEB2D0014\n\t" /* 8006539C: swc2       $13, 0x14($t9) */
".word 0xEB2E001C\n\t" /* 800653A0: swc2       $14, 0x1C($t9) */
".word 0x00000000\n\t" /* 800653A4: nop */
".word 0x00000000\n\t" /* 800653A8: nop */
".word 0x4A180001\n\t" /* 800653AC: rtps */
".word 0x94E80012\n\t" /* 800653B0: lhu        $t0, 0x12($a3) */
".word 0x24010001\n\t" /* 800653B4: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 800653B8: beq        $s6, $at, .L800653D0 */
".word 0x000840C0\n\t" /* 800653BC: sll       $t0, $t0, 3 */
".word 0x4842F800\n\t" /* 800653C0: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800653C4: nop */
".word 0x04400051\n\t" /* 800653C8: bltz       $v0, .L80065510 */
".word 0x00000000\n\t" /* 800653CC: nop */
".L800653D0:\n\t"
".word 0x4B68002E\n\t" /* 800653D0: avsz4 */
".word 0x8CF50000\n\t" /* 800653D4: lw         $s5, 0x0($a3) */
".word 0x12C00010\n\t" /* 800653D8: beqz       $s6, .L8006541C */
".word 0x01066821\n\t" /* 800653DC: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 800653E0: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800653E4: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 800653E8: nop */
".word 0x00000000\n\t" /* 800653EC: nop */
".word 0x4B08041B\n\t" /* 800653F0: nccs */
".word 0x12E00003\n\t" /* 800653F4: beqz       $s7, .L80065404 */
".word 0x00084042\n\t" /* 800653F8: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 800653FC: addu       $t0, $t0, $s7 */
".word 0xE9160000\n\t" /* 80065400: swc2       $22, 0x0($t0) */
".L80065404:\n\t"
".word 0xEB360008\n\t" /* 80065404: swc2       $22, 0x8($t9) */
".word 0x24010001\n\t" /* 80065408: addiu      $at, $zero, 0x1 */
".word 0x12C10040\n\t" /* 8006540C: beq        $s6, $at, .L80065510 */
".word 0x00000000\n\t" /* 80065410: nop */
".word 0x0801950D\n\t" /* 80065414: j          .L80065434 */
".word 0x00000000\n\t" /* 80065418: nop */
".L8006541C:\n\t"
".word 0x00084042\n\t" /* 8006541C: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80065420: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80065424: lw         $t0, 0x0($v1) */
".word 0x00000000\n\t" /* 80065428: nop */
".word 0xAF280008\n\t" /* 8006542C: sw         $t0, 0x8($t9) */
".word 0xA333000B\n\t" /* 80065430: sb         $s3, 0xB($t9) */
".L80065434:\n\t"
".word 0x8CE80004\n\t" /* 80065434: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80065438: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 8006543C: lw         $t2, 0xC($a3) */
".word 0x8CEB0010\n\t" /* 80065440: lw         $t3, 0x10($a3) */
".word 0x48023800\n\t" /* 80065444: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80065448: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 8006544C: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 80065450: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80065454: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80065458: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 8006545C: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80065460: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80065464: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80065468: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 8006546C: lw         $t5, 0x0($v0) */
".word 0xEB2E0024\n\t" /* 80065470: swc2       $14, 0x24($t9) */
".L80065474:\n\t"
".word 0xAF280010\n\t" /* 80065474: sw         $t0, 0x10($t9) */
".word 0xAF290018\n\t" /* 80065478: sw         $t1, 0x18($t9) */
".word 0xAF2A0020\n\t" /* 8006547C: sw         $t2, 0x20($t9) */
".word 0xAF2B0028\n\t" /* 80065480: sw         $t3, 0x28($t9) */
".word 0xAF350004\n\t" /* 80065484: sw         $s5, 0x4($t9) */
".word 0xAF34002C\n\t" /* 80065488: sw         $s4, 0x2C($t9) */
".word 0x000D6A00\n\t" /* 8006548C: sll        $t5, $t5, 8 */
".word 0x35AD000B\n\t" /* 80065490: ori        $t5, $t5, 0xB */
".word 0x000D0A02\n\t" /* 80065494: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80065498: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 8006549C: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 800654A0: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 800654A4: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 800654A8: srl        $t5, $t5, 8 */
".word 0x10600017\n\t" /* 800654AC: beqz       $v1, .L8006550C */
".word 0xAC4D0000\n\t" /* 800654B0: sw        $t5, 0x0($v0) */
".word 0x12400015\n\t" /* 800654B4: beqz       $s2, .L8006550C */
".word 0x00000000\n\t" /* 800654B8: nop */
".word 0x3C01FF9F\n\t" /* 800654BC: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800654C0: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800654C4: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 800654C8: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 800654CC: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 800654D0: lw         $v1, 0xC($t9) */
".word 0x00084400\n\t" /* 800654D4: sll        $t0, $t0, 16 */
".word 0xAF23003C\n\t" /* 800654D8: sw         $v1, 0x3C($t9) */
".word 0x8F230014\n\t" /* 800654DC: lw         $v1, 0x14($t9) */
".word 0x00084402\n\t" /* 800654E0: srl        $t0, $t0, 16 */
".word 0xAF230044\n\t" /* 800654E4: sw         $v1, 0x44($t9) */
".word 0x8F23001C\n\t" /* 800654E8: lw         $v1, 0x1C($t9) */
".word 0x01124025\n\t" /* 800654EC: or         $t0, $t0, $s2 */
".word 0xAF23004C\n\t" /* 800654F0: sw         $v1, 0x4C($t9) */
".word 0x8F230024\n\t" /* 800654F4: lw         $v1, 0x24($t9) */
".word 0xAF2C0038\n\t" /* 800654F8: sw         $t4, 0x38($t9) */
".word 0xAF230054\n\t" /* 800654FC: sw         $v1, 0x54($t9) */
".word 0x27390030\n\t" /* 80065500: addiu      $t9, $t9, 0x30 */
".word 0x0801951D\n\t" /* 80065504: j          .L80065474 */
".word 0x24030000\n\t" /* 80065508: addiu     $v1, $zero, 0x0 */
".L8006550C:\n\t"
".word 0x27390030\n\t" /* 8006550C: addiu      $t9, $t9, 0x30 */
".L80065510:\n\t"
".word 0x2718FFFF\n\t" /* 80065510: addiu      $t8, $t8, -0x1 */
".word 0x1700FF7E\n\t" /* 80065514: bnez       $t8, .L80065310 */
".word 0x24E7001C\n\t" /* 80065518: addiu     $a3, $a3, 0x1C */
".L8006551C:\n\t"
".word 0x8C900020\n\t" /* 8006551C: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80065520: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 80065524: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80065528: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 8006552C: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 80065530: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 80065534: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 80065538: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 8006553C: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80065540: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80065544: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80065548: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 8006554C: jr         $ra */
".word 0x00000000\n\t" /* 80065550: nop */
    ".set reorder\n"
);
