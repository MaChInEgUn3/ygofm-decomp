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
    ".global func_80062058\n"
    "func_80062058:\n"
".word 0x8C870000\n\t" /* 80062058: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 8006205C: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80062060: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 80062064: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80062068: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 8006206C: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80062070: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 80062074: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80062078: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 8006207C: sw         $s3, 0x2C($a0) */
".word 0xAC940030\n\t" /* 80062080: sw         $s4, 0x30($a0) */
".word 0xAC950034\n\t" /* 80062084: sw         $s5, 0x34($a0) */
".word 0xAC960038\n\t" /* 80062088: sw         $s6, 0x38($a0) */
".word 0xAC97003C\n\t" /* 8006208C: sw         $s7, 0x3C($a0) */
".word 0x1300009C\n\t" /* 80062090: beqz       $t8, .L80062304 */
".word 0x00A63821\n\t" /* 80062094: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80062098: lui        $s0, %hi(D_8009AFB4) */
".word 0x8E10AFB4\n\t" /* 8006209C: lw         $s0, %lo(D_8009AFB4)($s0) */
".word 0x3C11800A\n\t" /* 800620A0: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 800620A4: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 800620A8: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 800620AC: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 800620B0: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 800620B4: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 800620B8: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 800620BC: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 800620C0: addu       $t4, $s0, $zero */
".word 0x00109E02\n\t" /* 800620C4: srl        $s3, $s0, 24 */
".word 0x3C14E200\n\t" /* 800620C8: lui        $s4, (0xE2000000 >> 16) */
".word 0x8C850018\n\t" /* 800620CC: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 800620D0: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 800620D4: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 800620D8: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 800620DC: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 800620E0: lw         $t7, 0x4($t5) */
".L800620E4:\n\t"
".word 0x8CE80010\n\t" /* 800620E4: lw         $t0, 0x10($a3) */
".word 0x8CE90014\n\t" /* 800620E8: lw         $t1, 0x14($a3) */
".word 0x8CEA0018\n\t" /* 800620EC: lw         $t2, 0x18($a3) */
".word 0x00086C02\n\t" /* 800620F0: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 800620F4: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800620F8: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 800620FC: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80062100: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 80062104: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 80062108: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006210C: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 80062110: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80062114: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 80062118: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 8006211C: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 80062120: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 80062124: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 80062128: lwc2       $5, 0x4($t5) */
".word 0x00084400\n\t" /* 8006212C: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80062130: srl        $t0, $t0, 13 */
".word 0x4A280030\n\t" /* 80062134: rtpt */
".word 0x00094C00\n\t" /* 80062138: sll        $t1, $t1, 16 */
".word 0x00094B42\n\t" /* 8006213C: srl        $t1, $t1, 13 */
".word 0x000A5400\n\t" /* 80062140: sll        $t2, $t2, 16 */
".word 0x24010001\n\t" /* 80062144: addiu      $at, $zero, 0x1 */
".word 0x12C1000A\n\t" /* 80062148: beq        $s6, $at, .L80062174 */
".word 0x000A5342\n\t" /* 8006214C: srl       $t2, $t2, 13 */
".word 0x4842F800\n\t" /* 80062150: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80062154: nop */
".word 0x04400067\n\t" /* 80062158: bltz       $v0, .L800622F8 */
".word 0x00000000\n\t" /* 8006215C: nop */
".word 0x4B400006\n\t" /* 80062160: nclip */
".word 0x4802C000\n\t" /* 80062164: mfc2       $v0, $24 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80062168: nop */
".word 0x18400062\n\t" /* 8006216C: blez       $v0, .L800622F8 */
".word 0x00000000\n\t" /* 80062170: nop */
".L80062174:\n\t"
".word 0x4B58002D\n\t" /* 80062174: avsz3 */
".word 0x8CF50000\n\t" /* 80062178: lw         $s5, 0x0($a3) */
".word 0x12C0001E\n\t" /* 8006217C: beqz       $s6, .L800621F8 */
".word 0x01066821\n\t" /* 80062180: addu      $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80062184: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80062188: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 8006218C: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 80062190: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80062194: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 80062198: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 8006219C: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 800621A0: lwc2       $5, 0x4($t5) */
".word 0x00000000\n\t" /* 800621A4: nop */
".word 0x00000000\n\t" /* 800621A8: nop */
".word 0x4B18043F\n\t" /* 800621AC: ncct */
".word 0x12E00009\n\t" /* 800621B0: beqz       $s7, .L800621D8 */
".word 0x00084042\n\t" /* 800621B4: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 800621B8: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 800621BC: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 800621C0: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 800621C4: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 800621C8: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 800621CC: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 800621D0: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 800621D4: swc2       $22, 0x0($t2) */
".L800621D8:\n\t"
".word 0xEB340008\n\t" /* 800621D8: swc2       $20, 0x8($t9) */
".word 0xEB350014\n\t" /* 800621DC: swc2       $21, 0x14($t9) */
".word 0xEB360020\n\t" /* 800621E0: swc2       $22, 0x20($t9) */
".word 0x24010001\n\t" /* 800621E4: addiu      $at, $zero, 0x1 */
".word 0x12C10043\n\t" /* 800621E8: beq        $s6, $at, .L800622F8 */
".word 0x00000000\n\t" /* 800621EC: nop */
".word 0x0801888B\n\t" /* 800621F0: j          .L8006222C */
".word 0x00000000\n\t" /* 800621F4: nop */
".L800621F8:\n\t"
".word 0x00084042\n\t" /* 800621F8: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 800621FC: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80062200: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 80062204: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 80062208: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 8006220C: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 80062210: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 80062214: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 80062218: lw         $t2, 0x0($v1) */
".word 0xAF280008\n\t" /* 8006221C: sw         $t0, 0x8($t9) */
".word 0xAF290014\n\t" /* 80062220: sw         $t1, 0x14($t9) */
".word 0xAF2A0020\n\t" /* 80062224: sw         $t2, 0x20($t9) */
".word 0xA333000B\n\t" /* 80062228: sb         $s3, 0xB($t9) */
".L8006222C:\n\t"
".word 0x8CE80004\n\t" /* 8006222C: lw         $t0, 0x4($a3) */
".word 0x8CE90008\n\t" /* 80062230: lw         $t1, 0x8($a3) */
".word 0x8CEA000C\n\t" /* 80062234: lw         $t2, 0xC($a3) */
".word 0x48023800\n\t" /* 80062238: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 8006223C: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80062240: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 80062244: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 80062248: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 8006224C: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80062250: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80062254: lw         $t5, 0x0($v0) */
".word 0xEB2C000C\n\t" /* 80062258: swc2       $12, 0xC($t9) */
".word 0xEB2D0018\n\t" /* 8006225C: swc2       $13, 0x18($t9) */
".word 0xEB2E0024\n\t" /* 80062260: swc2       $14, 0x24($t9) */
".L80062264:\n\t"
".word 0xAF280010\n\t" /* 80062264: sw         $t0, 0x10($t9) */
".word 0xAF29001C\n\t" /* 80062268: sw         $t1, 0x1C($t9) */
".word 0xAF2A0028\n\t" /* 8006226C: sw         $t2, 0x28($t9) */
".word 0xAF350004\n\t" /* 80062270: sw         $s5, 0x4($t9) */
".word 0xAF34002C\n\t" /* 80062274: sw         $s4, 0x2C($t9) */
".word 0x000D6A00\n\t" /* 80062278: sll        $t5, $t5, 8 */
".word 0x35AD000B\n\t" /* 8006227C: ori        $t5, $t5, 0xB */
".word 0x000D0A02\n\t" /* 80062280: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80062284: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 80062288: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 8006228C: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80062290: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80062294: srl        $t5, $t5, 8 */
".word 0x10600016\n\t" /* 80062298: beqz       $v1, .L800622F4 */
".word 0xAC4D0000\n\t" /* 8006229C: sw        $t5, 0x0($v0) */
".word 0x12400014\n\t" /* 800622A0: beqz       $s2, .L800622F4 */
".word 0x00084400\n\t" /* 800622A4: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 800622A8: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 800622AC: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 800622B0: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800622B4: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800622B8: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 800622BC: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 800622C0: or         $t1, $t1, $at */
".word 0x8F23000C\n\t" /* 800622C4: lw         $v1, 0xC($t9) */
".word 0xAF2C0038\n\t" /* 800622C8: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 800622CC: sw         $v1, 0x3C($t9) */
".word 0x8F230018\n\t" /* 800622D0: lw         $v1, 0x18($t9) */
".word 0xAF2C0044\n\t" /* 800622D4: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 800622D8: sw         $v1, 0x48($t9) */
".word 0x8F230024\n\t" /* 800622DC: lw         $v1, 0x24($t9) */
".word 0xAF2C0050\n\t" /* 800622E0: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 800622E4: sw         $v1, 0x54($t9) */
".word 0x27390030\n\t" /* 800622E8: addiu      $t9, $t9, 0x30 */
".word 0x08018899\n\t" /* 800622EC: j          .L80062264 */
".word 0x24030000\n\t" /* 800622F0: addiu     $v1, $zero, 0x0 */
".L800622F4:\n\t"
".word 0x27390030\n\t" /* 800622F4: addiu      $t9, $t9, 0x30 */
".L800622F8:\n\t"
".word 0x2718FFFF\n\t" /* 800622F8: addiu      $t8, $t8, -0x1 */
".word 0x1700FF79\n\t" /* 800622FC: bnez       $t8, .L800620E4 */
".word 0x24E7001C\n\t" /* 80062300: addiu     $a3, $a3, 0x1C */
".L80062304:\n\t"
".word 0x8C900020\n\t" /* 80062304: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80062308: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 8006230C: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80062310: lw         $s3, 0x2C($a0) */
".word 0x8C940030\n\t" /* 80062314: lw         $s4, 0x30($a0) */
".word 0x8C950034\n\t" /* 80062318: lw         $s5, 0x34($a0) */
".word 0x8C960038\n\t" /* 8006231C: lw         $s6, 0x38($a0) */
".word 0x8C97003C\n\t" /* 80062320: lw         $s7, 0x3C($a0) */
".word 0x8C820000\n\t" /* 80062324: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80062328: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 8006232C: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80062330: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 80062334: jr         $ra */
".word 0x00000000\n\t" /* 80062338: nop */
    ".set reorder\n"
);
