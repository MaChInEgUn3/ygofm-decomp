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
    ".global func_80068FD8\n"
    "func_80068FD8:\n"
".word 0x8C870000\n\t" /* 80068FD8: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80068FDC: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80068FE0: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80068FE4: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80068FE8: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80068FEC: sll        $a2, $a2, 2 */
".word 0xAC900028\n\t" /* 80068FF0: sw         $s0, 0x28($a0) */
".word 0xAC91002C\n\t" /* 80068FF4: sw         $s1, 0x2C($a0) */
".word 0xAC920030\n\t" /* 80068FF8: sw         $s2, 0x30($a0) */
".word 0xAC930034\n\t" /* 80068FFC: sw         $s3, 0x34($a0) */
".word 0xAC940038\n\t" /* 80069000: sw         $s4, 0x38($a0) */
".word 0xAC95003C\n\t" /* 80069004: sw         $s5, 0x3C($a0) */
".word 0x130000B4\n\t" /* 80069008: beqz       $t8, .L800692DC */
".word 0x00A63821\n\t" /* 8006900C: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80069010: lui        $s0, %hi(D_8009AFB8) */
".word 0x8E10AFB8\n\t" /* 80069014: lw         $s0, %lo(D_8009AFB8)($s0) */
".word 0x3C11800A\n\t" /* 80069018: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 8006901C: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80069020: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80069024: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x02006021\n\t" /* 80069028: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 8006902C: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 80069030: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 80069034: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 80069038: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 8006903C: bnez       $v0, .L80069078 */
".word 0x02006021\n\t" /* 80069040: addu      $t4, $s0, $zero */
".word 0x8CF10008\n\t" /* 80069044: lw         $s1, 0x8($a3) */
".word 0x3C010060\n\t" /* 80069048: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 8006904C: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 80069050: bnez       $s1, .L80069078 */
".word 0x00000000\n\t" /* 80069054: nop */
".word 0x12400008\n\t" /* 80069058: beqz       $s2, .L8006907C */
".word 0x00000000\n\t" /* 8006905C: nop */
".word 0x94F20006\n\t" /* 80069060: lhu        $s2, 0x6($a3) */
".word 0x3C0C800A\n\t" /* 80069064: lui        $t4, %hi(D_8009AFC8) */
".word 0x8D8CAFC8\n\t" /* 80069068: lw         $t4, %lo(D_8009AFC8)($t4) */
".word 0x00129400\n\t" /* 8006906C: sll        $s2, $s2, 16 */
".word 0x0801A41F\n\t" /* 80069070: j          .L8006907C */
".word 0x3C110020\n\t" /* 80069074: lui       $s1, (0x200000 >> 16) */
".L80069078:\n\t"
".word 0x24120000\n\t" /* 80069078: addiu      $s2, $zero, 0x0 */
".L8006907C:\n\t"
".word 0x3C0D800A\n\t" /* 8006907C: lui        $t5, %hi(D_8009AFE4) */
".word 0x81ADAFE4\n\t" /* 80069080: lb         $t5, %lo(D_8009AFE4)($t5) */
".word 0x00109E02\n\t" /* 80069084: srl        $s3, $s0, 24 */
".word 0x00139E00\n\t" /* 80069088: sll        $s3, $s3, 24 */
".word 0x24010001\n\t" /* 8006908C: addiu      $at, $zero, 0x1 */
".word 0x11A10092\n\t" /* 80069090: beq        $t5, $at, .L800692DC */
".word 0x3C14E200\n\t" /* 80069094: lui       $s4, (0xE2000000 >> 16) */
".word 0x3C0D800A\n\t" /* 80069098: lui        $t5, %hi(D_8009AFE0) */
".word 0x8DADAFE0\n\t" /* 8006909C: lw         $t5, %lo(D_8009AFE0)($t5) */
".word 0x8C85001C\n\t" /* 800690A0: lw         $a1, 0x1C($a0) */
".word 0x8C860024\n\t" /* 800690A4: lw         $a2, 0x24($a0) */
".word 0x11A00002\n\t" /* 800690A8: beqz       $t5, .L800690B4 */
".word 0x00000000\n\t" /* 800690AC: nop */
".word 0x24C60004\n\t" /* 800690B0: addiu      $a2, $a2, 0x4 */
".L800690B4:\n\t"
".word 0x8C8D0004\n\t" /* 800690B4: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 800690B8: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 800690BC: lw         $t7, 0x4($t5) */
".L800690C0:\n\t"
".word 0x2403FFFF\n\t" /* 800690C0: addiu      $v1, $zero, -0x1 */
".word 0x8CE80010\n\t" /* 800690C4: lw         $t0, 0x10($a3) */
".word 0x98E8000E\n\t" /* 800690C8: lwr        $t0, 0xE($a3) */
".word 0x8CE90014\n\t" /* 800690CC: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 800690D0: lw         $t2, 0x18($a3) */
".word 0x8CEB001C\n\t" /* 800690D4: lw         $t3, 0x1C($a3) */
".word 0x00086C02\n\t" /* 800690D8: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 800690DC: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800690E0: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 800690E4: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 800690E8: lw         $t5, 0x0($t5) */
".word 0x10430078\n\t" /* 800690EC: beq        $v0, $v1, .L800692D0 */
".word 0x48828000\n\t" /* 800690F0: mtc2      $v0, $16 ( handwritten instruction ) */
".word 0x488D6000\n\t" /* 800690F4: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0xAF2D000C\n\t" /* 800690F8: sw         $t5, 0xC($t9) */
".word 0x00096C02\n\t" /* 800690FC: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80069100: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80069104: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80069108: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 8006910C: lw         $t5, 0x0($t5) */
".word 0x1043006F\n\t" /* 80069110: beq        $v0, $v1, .L800692D0 */
".word 0x48828800\n\t" /* 80069114: mtc2      $v0, $17 ( handwritten instruction ) */
".word 0x488D6800\n\t" /* 80069118: mtc2       $t5, $13 ( handwritten instruction ) */
".word 0xAF2D0018\n\t" /* 8006911C: sw         $t5, 0x18($t9) */
".word 0x000A6C02\n\t" /* 80069120: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 80069124: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80069128: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 8006912C: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80069130: lw         $t5, 0x0($t5) */
".word 0x10430066\n\t" /* 80069134: beq        $v0, $v1, .L800692D0 */
".word 0x48829000\n\t" /* 80069138: mtc2      $v0, $18 ( handwritten instruction ) */
".word 0x488D7000\n\t" /* 8006913C: mtc2       $t5, $14 ( handwritten instruction ) */
".word 0xAF2D0024\n\t" /* 80069140: sw         $t5, 0x24($t9) */
".word 0x000B6C02\n\t" /* 80069144: srl        $t5, $t3, 16 */
".word 0x000D68C0\n\t" /* 80069148: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006914C: addu       $t5, $t5, $a1 */
".word 0x8DA20004\n\t" /* 80069150: lw         $v0, 0x4($t5) */
".word 0x8DAD0000\n\t" /* 80069154: lw         $t5, 0x0($t5) */
".word 0x1043005D\n\t" /* 80069158: beq        $v0, $v1, .L800692D0 */
".word 0x48829800\n\t" /* 8006915C: mtc2      $v0, $19 ( handwritten instruction ) */
".word 0xAF2D0030\n\t" /* 80069160: sw         $t5, 0x30($t9) */
".word 0x00084400\n\t" /* 80069164: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80069168: srl        $t0, $t0, 13 */
".word 0x4B400006\n\t" /* 8006916C: nclip */
".word 0x00094C00\n\t" /* 80069170: sll        $t1, $t1, 16 */
".word 0x4802C000\n\t" /* 80069174: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00094B42\n\t" /* 80069178: srl        $t1, $t1, 13 */
".word 0x1C400009\n\t" /* 8006917C: bgtz       $v0, .L800691A4 */
".word 0x00000000\n\t" /* 80069180: nop */
".word 0x488D6000\n\t" /* 80069184: mtc2       $t5, $12 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80069188: nop */
".word 0x00000000\n\t" /* 8006918C: nop */
".word 0x4B400006\n\t" /* 80069190: nclip */
".word 0x4802C000\n\t" /* 80069194: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80069198: nop */
".word 0x1C40004C\n\t" /* 8006919C: bgtz       $v0, .L800692D0 */
".word 0x00000000\n\t" /* 800691A0: nop */
".L800691A4:\n\t"
".word 0x000A5400\n\t" /* 800691A4: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 800691A8: srl        $t2, $t2, 13 */
".word 0x000B5C00\n\t" /* 800691AC: sll        $t3, $t3, 16 */
".word 0x000B5B42\n\t" /* 800691B0: srl        $t3, $t3, 13 */
".word 0x01064021\n\t" /* 800691B4: addu       $t0, $t0, $a2 */
".word 0x01264821\n\t" /* 800691B8: addu       $t1, $t1, $a2 */
".word 0x01465021\n\t" /* 800691BC: addu       $t2, $t2, $a2 */
".word 0x01665821\n\t" /* 800691C0: addu       $t3, $t3, $a2 */
".word 0x8D080000\n\t" /* 800691C4: lw         $t0, 0x0($t0) */
".word 0x8D290000\n\t" /* 800691C8: lw         $t1, 0x0($t1) */
".word 0x8D4A0000\n\t" /* 800691CC: lw         $t2, 0x0($t2) */
".word 0x8D6B0000\n\t" /* 800691D0: lw         $t3, 0x0($t3) */
".word 0x01134025\n\t" /* 800691D4: or         $t0, $t0, $s3 */
".word 0xAF280008\n\t" /* 800691D8: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 800691DC: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 800691E0: sw         $t2, 0x20($t9) */
".word 0xAF2B002C\n\t" /* 800691E4: sw         $t3, 0x2C($t9) */
".word 0x4B68002E\n\t" /* 800691E8: avsz4 */
".word 0x8CF50000\n\t" /* 800691EC: lw         $s5, 0x0($a3) */
".word 0x8CE80004\n\t" /* 800691F0: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 800691F4: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 800691F8: lw         $t2, 0xC($a3) */
".word 0x8CEB0010\n\t" /* 800691FC: lw         $t3, 0x10($a3) */
".word 0x48023800\n\t" /* 80069200: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80069204: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80069208: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 8006920C: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80069210: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80069214: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80069218: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 8006921C: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80069220: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80069224: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80069228: lw         $t5, 0x0($v0) */
".L8006922C:\n\t"
".word 0xAF280010\n\t" /* 8006922C: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 80069230: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 80069234: sw         $t2, 0x28($t9) */
".word 0xAF2B0034\n\t" /* 80069238: sw         $t3, 0x34($t9) */
".word 0xAF350004\n\t" /* 8006923C: sw         $s5, 0x4($t9) */
".word 0xAF340038\n\t" /* 80069240: sw         $s4, 0x38($t9) */
".word 0x000D6A00\n\t" /* 80069244: sll        $t5, $t5, 8 */
".word 0x35AD000E\n\t" /* 80069248: ori        $t5, $t5, 0xE */
".word 0x000D0A02\n\t" /* 8006924C: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80069250: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80069254: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80069258: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 8006925C: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80069260: srl        $t5, $t5, 8 */
".word 0x10600019\n\t" /* 80069264: beqz       $v1, .L800692CC */
".word 0xAC4D0000\n\t" /* 80069268: sw        $t5, 0x0($v0) */
".word 0x12400017\n\t" /* 8006926C: beqz       $s2, .L800692CC */
".word 0x00084400\n\t" /* 80069270: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 80069274: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 80069278: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 8006927C: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80069280: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80069284: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 80069288: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 8006928C: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 80069290: lw         $v1, 0xC($t9) */
".word 0xAF2C0044\n\t" /* 80069294: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 80069298: sw         $v1, 0x48($t9) */
".word 0x8F230018\n\t" /* 8006929C: lw         $v1, 0x18($t9) */
".word 0xAF2C0050\n\t" /* 800692A0: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 800692A4: sw         $v1, 0x54($t9) */
".word 0x8F230024\n\t" /* 800692A8: lw         $v1, 0x24($t9) */
".word 0xAF2C005C\n\t" /* 800692AC: sw         $t4, 0x5C($t9) */
".word 0xAF230060\n\t" /* 800692B0: sw         $v1, 0x60($t9) */
".word 0x8F230030\n\t" /* 800692B4: lw         $v1, 0x30($t9) */
".word 0xAF2C0068\n\t" /* 800692B8: sw         $t4, 0x68($t9) */
".word 0xAF23006C\n\t" /* 800692BC: sw         $v1, 0x6C($t9) */
".word 0x2739003C\n\t" /* 800692C0: addiu      $t9, $t9, 0x3C */
".word 0x0801A48B\n\t" /* 800692C4: j          .L8006922C */
".word 0x24030000\n\t" /* 800692C8: addiu     $v1, $zero, 0x0 */
".L800692CC:\n\t"
".word 0x2739003C\n\t" /* 800692CC: addiu      $t9, $t9, 0x3C */
".L800692D0:\n\t"
".word 0x2718FFFF\n\t" /* 800692D0: addiu      $t8, $t8, -0x1 */
".word 0x1700FF7A\n\t" /* 800692D4: bnez       $t8, .L800690C0 */
".word 0x24E70020\n\t" /* 800692D8: addiu     $a3, $a3, 0x20 */
".L800692DC:\n\t"
".word 0x8C900028\n\t" /* 800692DC: lw         $s0, 0x28($a0) */
".word 0x8C91002C\n\t" /* 800692E0: lw         $s1, 0x2C($a0) */
".word 0x8C920030\n\t" /* 800692E4: lw         $s2, 0x30($a0) */
".word 0x8C930034\n\t" /* 800692E8: lw         $s3, 0x34($a0) */
".word 0x8C940038\n\t" /* 800692EC: lw         $s4, 0x38($a0) */
".word 0x8C95003C\n\t" /* 800692F0: lw         $s5, 0x3C($a0) */
".word 0x8C820000\n\t" /* 800692F4: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 800692F8: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 800692FC: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80069300: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80069304: jr         $ra */
".word 0x00000000\n\t" /* 80069308: nop */
    ".set reorder\n"
);
