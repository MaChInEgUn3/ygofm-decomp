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
    ".global func_80063100\n"
    "func_80063100:\n"
".word 0x8C870000\n\t" /* 80063100: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 80063104: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 80063108: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 8006310C: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 80063110: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 80063114: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 80063118: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 8006311C: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 80063120: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 80063124: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 80063128: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 8006312C: sw         $s7, 0x34($a0) */
".word 0x130000B8\n\t" /* 80063130: beqz       $t8, .L80063414 */
".word 0x00A63821\n\t" /* 80063134: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 80063138: lui        $s0, %hi(D_8009AFB8) */
".word 0x8E10AFB8\n\t" /* 8006313C: lw         $s0, %lo(D_8009AFB8)($s0) */
".word 0x3C11800A\n\t" /* 80063140: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80063144: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 80063148: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 8006314C: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80063150: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80063154: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 80063158: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 8006315C: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80063160: addu       $t4, $s0, $zero */
".word 0x00109E02\n\t" /* 80063164: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 80063168: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 8006316C: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80063170: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80063174: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 80063178: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 8006317C: lw         $t7, 0x4($t5) */
".L80063180:\n\t"
".word 0x8CE8000C\n\t" /* 80063180: lw         $t0, 0xC($a3) */
".word 0x98E8000A\n\t" /* 80063184: lwr        $t0, 0xA($a3) */
".word 0x8CE90010\n\t" /* 80063188: lw         $t1, 0x10($a3) */
".word 0x8CEA0014\n\t" /* 8006318C: lw         $t2, 0x14($a3) */
".word 0x8CEB0018\n\t" /* 80063190: lw         $t3, 0x18($a3) */
".word 0x00086C02\n\t" /* 80063194: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 80063198: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 8006319C: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 800631A0: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800631A4: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 800631A8: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 800631AC: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800631B0: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 800631B4: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 800631B8: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 800631BC: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 800631C0: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800631C4: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 800631C8: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 800631CC: lwc2       $5, 0x4($t5) */
".word 0x000B6C02\n\t" /* 800631D0: srl        $t5, $t3, 16 */
".word 0x000D68C0\n\t" /* 800631D4: sll        $t5, $t5, 3 */
".word 0x4A280030\n\t" /* 800631D8: rtpt */
".word 0x000B5C00\n\t" /* 800631DC: sll        $t3, $t3, 16 */
".word 0x000B5B42\n\t" /* 800631E0: srl        $t3, $t3, 13 */
".word 0x24010001\n\t" /* 800631E4: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 800631E8: beq        $s6, $at, .L80063200 */
".word 0x01A56821\n\t" /* 800631EC: addu      $t5, $t5, $a1 */
".word 0x4842F800\n\t" /* 800631F0: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 800631F4: nop */
".word 0x04400083\n\t" /* 800631F8: bltz       $v0, .L80063408 */
".word 0x00000000\n\t" /* 800631FC: nop */
".L80063200:\n\t"
".word 0xC9A00000\n\t" /* 80063200: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80063204: lwc2       $1, 0x4($t5) */
".word 0xEB2C0008\n\t" /* 80063208: swc2       $12, 0x8($t9) */
".word 0xEB2D0014\n\t" /* 8006320C: swc2       $13, 0x14($t9) */
".word 0xEB2E0020\n\t" /* 80063210: swc2       $14, 0x20($t9) */
".word 0x00084400\n\t" /* 80063214: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 80063218: srl        $t0, $t0, 13 */
".word 0x4A180001\n\t" /* 8006321C: rtps */
".word 0x00094C00\n\t" /* 80063220: sll        $t1, $t1, 16 */
".word 0x24010001\n\t" /* 80063224: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 80063228: beq        $s6, $at, .L80063240 */
".word 0x00094B42\n\t" /* 8006322C: srl       $t1, $t1, 13 */
".word 0x4842F800\n\t" /* 80063230: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80063234: nop */
".word 0x04400073\n\t" /* 80063238: bltz       $v0, .L80063408 */
".word 0x00000000\n\t" /* 8006323C: nop */
".L80063240:\n\t"
".word 0x4B68002E\n\t" /* 80063240: avsz4 */
".word 0xEB2E002C\n\t" /* 80063244: swc2       $14, 0x2C($t9) */
".word 0x000A5400\n\t" /* 80063248: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 8006324C: srl        $t2, $t2, 13 */
".word 0x12C00029\n\t" /* 80063250: beqz       $s6, .L800632F8 */
".word 0x01666821\n\t" /* 80063254: addu      $t5, $t3, $a2 */
".word 0xC9A00000\n\t" /* 80063258: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 8006325C: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80063260: nop */
".word 0x00000000\n\t" /* 80063264: nop */
".word 0x4B08041B\n\t" /* 80063268: nccs */
".word 0x01066821\n\t" /* 8006326C: addu       $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80063270: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80063274: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 80063278: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 8006327C: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80063280: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 80063284: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 80063288: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 8006328C: lwc2       $5, 0x4($t5) */
".word 0x12E00003\n\t" /* 80063290: beqz       $s7, .L800632A0 */
".word 0x000B5842\n\t" /* 80063294: srl       $t3, $t3, 1 */
".word 0x01775821\n\t" /* 80063298: addu       $t3, $t3, $s7 */
".word 0xE9760000\n\t" /* 8006329C: swc2       $22, 0x0($t3) */
".L800632A0:\n\t"
".word 0xEB360028\n\t" /* 800632A0: swc2       $22, 0x28($t9) */
".word 0x00000000\n\t" /* 800632A4: nop */
".word 0x00000000\n\t" /* 800632A8: nop */
".word 0x4B18043F\n\t" /* 800632AC: ncct */
".word 0x12E00009\n\t" /* 800632B0: beqz       $s7, .L800632D8 */
".word 0x00084042\n\t" /* 800632B4: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 800632B8: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 800632BC: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 800632C0: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 800632C4: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 800632C8: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 800632CC: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 800632D0: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 800632D4: swc2       $22, 0x0($t2) */
".L800632D8:\n\t"
".word 0xEB340004\n\t" /* 800632D8: swc2       $20, 0x4($t9) */
".word 0xEB350010\n\t" /* 800632DC: swc2       $21, 0x10($t9) */
".word 0xEB36001C\n\t" /* 800632E0: swc2       $22, 0x1C($t9) */
".word 0x24010001\n\t" /* 800632E4: addiu      $at, $zero, 0x1 */
".word 0x12C10047\n\t" /* 800632E8: beq        $s6, $at, .L80063408 */
".word 0x00000000\n\t" /* 800632EC: nop */
".word 0x08018CCF\n\t" /* 800632F0: j          .L8006333C */
".word 0x00000000\n\t" /* 800632F4: nop */
".L800632F8:\n\t"
".word 0x00084042\n\t" /* 800632F8: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 800632FC: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80063300: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 80063304: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 80063308: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 8006330C: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 80063310: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 80063314: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 80063318: lw         $t2, 0x0($v1) */
".word 0x000B5842\n\t" /* 8006331C: srl        $t3, $t3, 1 */
".word 0x01771821\n\t" /* 80063320: addu       $v1, $t3, $s7 */
".word 0x8C6B0000\n\t" /* 80063324: lw         $t3, 0x0($v1) */
".word 0xAF280004\n\t" /* 80063328: sw         $t0, 0x4($t9) */
".word 0xAF290010\n\t" /* 8006332C: sw         $t1, 0x10($t9) */
".word 0xAF2A001C\n\t" /* 80063330: sw         $t2, 0x1C($t9) */
".word 0xAF2B0028\n\t" /* 80063334: sw         $t3, 0x28($t9) */
".word 0xA3330007\n\t" /* 80063338: sb         $s3, 0x7($t9) */
".L8006333C:\n\t"
".word 0x8CE80000\n\t" /* 8006333C: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80063340: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80063344: lw         $t2, 0x8($a3) */
".word 0x8CEB000C\n\t" /* 80063348: lw         $t3, 0xC($a3) */
".word 0x48023800\n\t" /* 8006334C: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80063350: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80063354: and        $v1, $s0, $at */
".word 0x01314825\n\t" /* 80063358: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 8006335C: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80063360: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80063364: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80063368: lw         $t5, 0x0($v0) */
".L8006336C:\n\t"
".word 0xAF28000C\n\t" /* 8006336C: sw         $t0, 0xC($t9) */
".word 0xAF290018\n\t" /* 80063370: sw         $t1, 0x18($t9) */
".word 0xAF2A0024\n\t" /* 80063374: sw         $t2, 0x24($t9) */
".word 0xAF2B0030\n\t" /* 80063378: sw         $t3, 0x30($t9) */
".word 0x000D6A00\n\t" /* 8006337C: sll        $t5, $t5, 8 */
".word 0x35AD000C\n\t" /* 80063380: ori        $t5, $t5, 0xC */
".word 0x000D0A02\n\t" /* 80063384: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 80063388: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 8006338C: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 80063390: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 80063394: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 80063398: srl        $t5, $t5, 8 */
".word 0x10600019\n\t" /* 8006339C: beqz       $v1, .L80063404 */
".word 0xAC4D0000\n\t" /* 800633A0: sw        $t5, 0x0($v0) */
".word 0x12400017\n\t" /* 800633A4: beqz       $s2, .L80063404 */
".word 0x00084400\n\t" /* 800633A8: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 800633AC: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 800633B0: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 800633B4: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800633B8: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800633BC: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 800633C0: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 800633C4: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 800633C8: lw         $v1, 0x8($t9) */
".word 0xAF2C0038\n\t" /* 800633CC: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 800633D0: sw         $v1, 0x3C($t9) */
".word 0x8F230014\n\t" /* 800633D4: lw         $v1, 0x14($t9) */
".word 0xAF2C0044\n\t" /* 800633D8: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 800633DC: sw         $v1, 0x48($t9) */
".word 0x8F230020\n\t" /* 800633E0: lw         $v1, 0x20($t9) */
".word 0xAF2C0050\n\t" /* 800633E4: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 800633E8: sw         $v1, 0x54($t9) */
".word 0x8F23002C\n\t" /* 800633EC: lw         $v1, 0x2C($t9) */
".word 0xAF2C005C\n\t" /* 800633F0: sw         $t4, 0x5C($t9) */
".word 0xAF230060\n\t" /* 800633F4: sw         $v1, 0x60($t9) */
".word 0x27390034\n\t" /* 800633F8: addiu      $t9, $t9, 0x34 */
".word 0x08018CDB\n\t" /* 800633FC: j          .L8006336C */
".word 0x24030000\n\t" /* 80063400: addiu     $v1, $zero, 0x0 */
".L80063404:\n\t"
".word 0x27390034\n\t" /* 80063404: addiu      $t9, $t9, 0x34 */
".L80063408:\n\t"
".word 0x2718FFFF\n\t" /* 80063408: addiu      $t8, $t8, -0x1 */
".word 0x1700FF5C\n\t" /* 8006340C: bnez       $t8, .L80063180 */
".word 0x24E7001C\n\t" /* 80063410: addiu     $a3, $a3, 0x1C */
".L80063414:\n\t"
".word 0x8C900020\n\t" /* 80063414: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80063418: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 8006341C: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80063420: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 80063424: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 80063428: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 8006342C: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80063430: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80063434: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80063438: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 8006343C: jr         $ra */
".word 0x00000000\n\t" /* 80063440: nop */
    ".set reorder\n"
);
