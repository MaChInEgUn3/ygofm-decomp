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
    ".global func_800661C4\n"
    "func_800661C4:\n"
".word 0x8C870000\n\t" /* 800661C4: lw         $a3, 0x0($a0) */
".word 0x8C990010\n\t" /* 800661C8: lw         $t9, 0x10($a0) */
".word 0x94F80002\n\t" /* 800661CC: lhu        $t8, 0x2($a3) */
".word 0x8CE60004\n\t" /* 800661D0: lw         $a2, 0x4($a3) */
".word 0x8C850014\n\t" /* 800661D4: lw         $a1, 0x14($a0) */
".word 0x00063080\n\t" /* 800661D8: sll        $a2, $a2, 2 */
".word 0xAC900020\n\t" /* 800661DC: sw         $s0, 0x20($a0) */
".word 0xAC910024\n\t" /* 800661E0: sw         $s1, 0x24($a0) */
".word 0xAC920028\n\t" /* 800661E4: sw         $s2, 0x28($a0) */
".word 0xAC93002C\n\t" /* 800661E8: sw         $s3, 0x2C($a0) */
".word 0xAC960030\n\t" /* 800661EC: sw         $s6, 0x30($a0) */
".word 0xAC970034\n\t" /* 800661F0: sw         $s7, 0x34($a0) */
".word 0x130000CF\n\t" /* 800661F4: beqz       $t8, .L80066534 */
".word 0x00A63821\n\t" /* 800661F8: addu      $a3, $a1, $a2 */
".word 0x3C10800A\n\t" /* 800661FC: lui        $s0, %hi(D_8009AFB8) */
".word 0x8E10AFB8\n\t" /* 80066200: lw         $s0, %lo(D_8009AFB8)($s0) */
".word 0x3C11800A\n\t" /* 80066204: lui        $s1, %hi(D_8009AFD8) */
".word 0x8E31AFD8\n\t" /* 80066208: lw         $s1, %lo(D_8009AFD8)($s1) */
".word 0x3C12800A\n\t" /* 8006620C: lui        $s2, %hi(D_8009AFDC) */
".word 0x8E52AFDC\n\t" /* 80066210: lw         $s2, %lo(D_8009AFDC)($s2) */
".word 0x3C16800A\n\t" /* 80066214: lui        $s6, %hi(D_8009AFE4) */
".word 0x82D6AFE4\n\t" /* 80066218: lb         $s6, %lo(D_8009AFE4)($s6) */
".word 0x3C17800A\n\t" /* 8006621C: lui        $s7, %hi(D_8009AFE0) */
".word 0x8EF7AFE0\n\t" /* 80066220: lw         $s7, %lo(D_8009AFE0)($s7) */
".word 0x02006021\n\t" /* 80066224: addu       $t4, $s0, $zero */
".word 0x3C02800A\n\t" /* 80066228: lui        $v0, %hi(D_8009AFE5) */
".word 0x8042AFE5\n\t" /* 8006622C: lb         $v0, %lo(D_8009AFE5)($v0) */
".word 0x3C010200\n\t" /* 80066230: lui        $at, (0x2000000 >> 16) */
".word 0x02018025\n\t" /* 80066234: or         $s0, $s0, $at */
".word 0x1440000E\n\t" /* 80066238: bnez       $v0, .L80066274 */
".word 0x02006021\n\t" /* 8006623C: addu      $t4, $s0, $zero */
".word 0x8CF10004\n\t" /* 80066240: lw         $s1, 0x4($a3) */
".word 0x3C010060\n\t" /* 80066244: lui        $at, (0x600000 >> 16) */
".word 0x02218824\n\t" /* 80066248: and        $s1, $s1, $at */
".word 0x16200009\n\t" /* 8006624C: bnez       $s1, .L80066274 */
".word 0x00000000\n\t" /* 80066250: nop */
".word 0x12400008\n\t" /* 80066254: beqz       $s2, .L80066278 */
".word 0x00000000\n\t" /* 80066258: nop */
".word 0x94F20002\n\t" /* 8006625C: lhu        $s2, 0x2($a3) */
".word 0x3C0C800A\n\t" /* 80066260: lui        $t4, %hi(D_8009AFC8) */
".word 0x8D8CAFC8\n\t" /* 80066264: lw         $t4, %lo(D_8009AFC8)($t4) */
".word 0x00129400\n\t" /* 80066268: sll        $s2, $s2, 16 */
".word 0x0801989E\n\t" /* 8006626C: j          .L80066278 */
".word 0x3C110020\n\t" /* 80066270: lui       $s1, (0x200000 >> 16) */
".L80066274:\n\t"
".word 0x24120000\n\t" /* 80066274: addiu      $s2, $zero, 0x0 */
".L80066278:\n\t"
".word 0x00109E02\n\t" /* 80066278: srl        $s3, $s0, 24 */
".word 0x8C850018\n\t" /* 8006627C: lw         $a1, 0x18($a0) */
".word 0x8C86001C\n\t" /* 80066280: lw         $a2, 0x1C($a0) */
".word 0x48903000\n\t" /* 80066284: mtc2       $s0, $6 ( handwritten instruction ) */
".word 0x8C8D0004\n\t" /* 80066288: lw         $t5, 0x4($a0) */
".word 0x8C8E0008\n\t" /* 8006628C: lw         $t6, 0x8($a0) */
".word 0x8DAF0004\n\t" /* 80066290: lw         $t7, 0x4($t5) */
".L80066294:\n\t"
".word 0x8CE8000C\n\t" /* 80066294: lw         $t0, 0xC($a3) */
".word 0x98E8000A\n\t" /* 80066298: lwr        $t0, 0xA($a3) */
".word 0x8CE90010\n\t" /* 8006629C: lw         $t1, 0x10($a3) */
".word 0x8CEA0014\n\t" /* 800662A0: lw         $t2, 0x14($a3) */
".word 0x8CEB0018\n\t" /* 800662A4: lw         $t3, 0x18($a3) */
".word 0x00086C02\n\t" /* 800662A8: srl        $t5, $t0, 16 */
".word 0x000D68C0\n\t" /* 800662AC: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800662B0: addu       $t5, $t5, $a1 */
".word 0xC9A00000\n\t" /* 800662B4: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 800662B8: lwc2       $1, 0x4($t5) */
".word 0x00096C02\n\t" /* 800662BC: srl        $t5, $t1, 16 */
".word 0x000D68C0\n\t" /* 800662C0: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800662C4: addu       $t5, $t5, $a1 */
".word 0xC9A20000\n\t" /* 800662C8: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 800662CC: lwc2       $3, 0x4($t5) */
".word 0x000A6C02\n\t" /* 800662D0: srl        $t5, $t2, 16 */
".word 0x000D68C0\n\t" /* 800662D4: sll        $t5, $t5, 3 */
".word 0x01A56821\n\t" /* 800662D8: addu       $t5, $t5, $a1 */
".word 0xC9A40000\n\t" /* 800662DC: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 800662E0: lwc2       $5, 0x4($t5) */
".word 0x000B6C02\n\t" /* 800662E4: srl        $t5, $t3, 16 */
".word 0x000D68C0\n\t" /* 800662E8: sll        $t5, $t5, 3 */
".word 0x4A280030\n\t" /* 800662EC: rtpt */
".word 0x000B5C00\n\t" /* 800662F0: sll        $t3, $t3, 16 */
".word 0x000B5B42\n\t" /* 800662F4: srl        $t3, $t3, 13 */
".word 0x24010001\n\t" /* 800662F8: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 800662FC: beq        $s6, $at, .L80066314 */
".word 0x01A56821\n\t" /* 80066300: addu      $t5, $t5, $a1 */
".word 0x4842F800\n\t" /* 80066304: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80066308: nop */
".word 0x04400086\n\t" /* 8006630C: bltz       $v0, .L80066528 */
".word 0x00000000\n\t" /* 80066310: nop */
".L80066314:\n\t"
".word 0xC9A00000\n\t" /* 80066314: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80066318: lwc2       $1, 0x4($t5) */
".word 0xEB2C0008\n\t" /* 8006631C: swc2       $12, 0x8($t9) */
".word 0xEB2D0014\n\t" /* 80066320: swc2       $13, 0x14($t9) */
".word 0xEB2E0020\n\t" /* 80066324: swc2       $14, 0x20($t9) */
".word 0x00084400\n\t" /* 80066328: sll        $t0, $t0, 16 */
".word 0x00084342\n\t" /* 8006632C: srl        $t0, $t0, 13 */
".word 0x4A180001\n\t" /* 80066330: rtps */
".word 0x00094C00\n\t" /* 80066334: sll        $t1, $t1, 16 */
".word 0x24010001\n\t" /* 80066338: addiu      $at, $zero, 0x1 */
".word 0x12C10005\n\t" /* 8006633C: beq        $s6, $at, .L80066354 */
".word 0x00094B42\n\t" /* 80066340: srl       $t1, $t1, 13 */
".word 0x4842F800\n\t" /* 80066344: cfc2       $v0, $31 ( handwritten instruction ) */
".word 0x00000000\n\t" /* 80066348: nop */
".word 0x04400076\n\t" /* 8006634C: bltz       $v0, .L80066528 */
".word 0x00000000\n\t" /* 80066350: nop */
".L80066354:\n\t"
".word 0x4B68002E\n\t" /* 80066354: avsz4 */
".word 0xEB2E002C\n\t" /* 80066358: swc2       $14, 0x2C($t9) */
".word 0x000A5400\n\t" /* 8006635C: sll        $t2, $t2, 16 */
".word 0x000A5342\n\t" /* 80066360: srl        $t2, $t2, 13 */
".word 0x12C00029\n\t" /* 80066364: beqz       $s6, .L8006640C */
".word 0x01666821\n\t" /* 80066368: addu      $t5, $t3, $a2 */
".word 0xC9A00000\n\t" /* 8006636C: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80066370: lwc2       $1, 0x4($t5) */
".word 0x00000000\n\t" /* 80066374: nop */
".word 0x00000000\n\t" /* 80066378: nop */
".word 0x4B08041B\n\t" /* 8006637C: nccs */
".word 0x01066821\n\t" /* 80066380: addu       $t5, $t0, $a2 */
".word 0xC9A00000\n\t" /* 80066384: lwc2       $0, 0x0($t5) */
".word 0xC9A10004\n\t" /* 80066388: lwc2       $1, 0x4($t5) */
".word 0x01266821\n\t" /* 8006638C: addu       $t5, $t1, $a2 */
".word 0xC9A20000\n\t" /* 80066390: lwc2       $2, 0x0($t5) */
".word 0xC9A30004\n\t" /* 80066394: lwc2       $3, 0x4($t5) */
".word 0x01466821\n\t" /* 80066398: addu       $t5, $t2, $a2 */
".word 0xC9A40000\n\t" /* 8006639C: lwc2       $4, 0x0($t5) */
".word 0xC9A50004\n\t" /* 800663A0: lwc2       $5, 0x4($t5) */
".word 0x12E00003\n\t" /* 800663A4: beqz       $s7, .L800663B4 */
".word 0x000B5842\n\t" /* 800663A8: srl       $t3, $t3, 1 */
".word 0x01775821\n\t" /* 800663AC: addu       $t3, $t3, $s7 */
".word 0xE9760000\n\t" /* 800663B0: swc2       $22, 0x0($t3) */
".L800663B4:\n\t"
".word 0xEB360028\n\t" /* 800663B4: swc2       $22, 0x28($t9) */
".word 0x00000000\n\t" /* 800663B8: nop */
".word 0x00000000\n\t" /* 800663BC: nop */
".word 0x4B18043F\n\t" /* 800663C0: ncct */
".word 0x12E00009\n\t" /* 800663C4: beqz       $s7, .L800663EC */
".word 0x00084042\n\t" /* 800663C8: srl       $t0, $t0, 1 */
".word 0x01174021\n\t" /* 800663CC: addu       $t0, $t0, $s7 */
".word 0x00094842\n\t" /* 800663D0: srl        $t1, $t1, 1 */
".word 0x01374821\n\t" /* 800663D4: addu       $t1, $t1, $s7 */
".word 0x000A5042\n\t" /* 800663D8: srl        $t2, $t2, 1 */
".word 0x01575021\n\t" /* 800663DC: addu       $t2, $t2, $s7 */
".word 0xE9140000\n\t" /* 800663E0: swc2       $20, 0x0($t0) */
".word 0xE9350000\n\t" /* 800663E4: swc2       $21, 0x0($t1) */
".word 0xE9560000\n\t" /* 800663E8: swc2       $22, 0x0($t2) */
".L800663EC:\n\t"
".word 0xEB340004\n\t" /* 800663EC: swc2       $20, 0x4($t9) */
".word 0xEB350010\n\t" /* 800663F0: swc2       $21, 0x10($t9) */
".word 0xEB36001C\n\t" /* 800663F4: swc2       $22, 0x1C($t9) */
".word 0x24010001\n\t" /* 800663F8: addiu      $at, $zero, 0x1 */
".word 0x12C1004A\n\t" /* 800663FC: beq        $s6, $at, .L80066528 */
".word 0x00000000\n\t" /* 80066400: nop */
".word 0x08019914\n\t" /* 80066404: j          .L80066450 */
".word 0x00000000\n\t" /* 80066408: nop */
".L8006640C:\n\t"
".word 0x00084042\n\t" /* 8006640C: srl        $t0, $t0, 1 */
".word 0x01171821\n\t" /* 80066410: addu       $v1, $t0, $s7 */
".word 0x8C680000\n\t" /* 80066414: lw         $t0, 0x0($v1) */
".word 0x00094842\n\t" /* 80066418: srl        $t1, $t1, 1 */
".word 0x01371821\n\t" /* 8006641C: addu       $v1, $t1, $s7 */
".word 0x8C690000\n\t" /* 80066420: lw         $t1, 0x0($v1) */
".word 0x000A5042\n\t" /* 80066424: srl        $t2, $t2, 1 */
".word 0x01571821\n\t" /* 80066428: addu       $v1, $t2, $s7 */
".word 0x8C6A0000\n\t" /* 8006642C: lw         $t2, 0x0($v1) */
".word 0x000B5842\n\t" /* 80066430: srl        $t3, $t3, 1 */
".word 0x01771821\n\t" /* 80066434: addu       $v1, $t3, $s7 */
".word 0x8C6B0000\n\t" /* 80066438: lw         $t3, 0x0($v1) */
".word 0xAF280004\n\t" /* 8006643C: sw         $t0, 0x4($t9) */
".word 0xAF290010\n\t" /* 80066440: sw         $t1, 0x10($t9) */
".word 0xAF2A001C\n\t" /* 80066444: sw         $t2, 0x1C($t9) */
".word 0xAF2B0028\n\t" /* 80066448: sw         $t3, 0x28($t9) */
".word 0xA3330007\n\t" /* 8006644C: sb         $s3, 0x7($t9) */
".L80066450:\n\t"
".word 0x8CE80000\n\t" /* 80066450: lw         $t0, 0x0($a3) */
".word 0x8CE90004\n\t" /* 80066454: lw         $t1, 0x4($a3) */
".word 0x8CEA0008\n\t" /* 80066458: lw         $t2, 0x8($a3) */
".word 0x8CEB000C\n\t" /* 8006645C: lw         $t3, 0xC($a3) */
".word 0x48023800\n\t" /* 80066460: mfc2       $v0, $7 ( handwritten instruction ) */
".word 0x3C010200\n\t" /* 80066464: lui        $at, (0x2000000 >> 16) */
".word 0x02011824\n\t" /* 80066468: and        $v1, $s0, $at */
".word 0x3C01FF9F\n\t" /* 8006646C: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 80066470: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 80066474: and        $t1, $t1, $at */
".word 0x01314825\n\t" /* 80066478: or         $t1, $t1, $s1 */
".word 0x01C21006\n\t" /* 8006647C: srlv       $v0, $v0, $t6 */
".word 0x00021080\n\t" /* 80066480: sll        $v0, $v0, 2 */
".word 0x004F1021\n\t" /* 80066484: addu       $v0, $v0, $t7 */
".word 0x8C4D0000\n\t" /* 80066488: lw         $t5, 0x0($v0) */
".L8006648C:\n\t"
".word 0xAF28000C\n\t" /* 8006648C: sw         $t0, 0xC($t9) */
".word 0xAF290018\n\t" /* 80066490: sw         $t1, 0x18($t9) */
".word 0xAF2A0024\n\t" /* 80066494: sw         $t2, 0x24($t9) */
".word 0xAF2B0030\n\t" /* 80066498: sw         $t3, 0x30($t9) */
".word 0x000D6A00\n\t" /* 8006649C: sll        $t5, $t5, 8 */
".word 0x35AD000C\n\t" /* 800664A0: ori        $t5, $t5, 0xC */
".word 0x000D0A02\n\t" /* 800664A4: srl        $at, $t5, 8 */
".word 0x000D6E00\n\t" /* 800664A8: sll        $t5, $t5, 24 */
".word 0x01A16825\n\t" /* 800664AC: or         $t5, $t5, $at */
".word 0xAF2D0000\n\t" /* 800664B0: sw         $t5, 0x0($t9) */
".word 0x00196A00\n\t" /* 800664B4: sll        $t5, $t9, 8 */
".word 0x000D6A02\n\t" /* 800664B8: srl        $t5, $t5, 8 */
".word 0x10600019\n\t" /* 800664BC: beqz       $v1, .L80066524 */
".word 0xAC4D0000\n\t" /* 800664C0: sw        $t5, 0x0($v0) */
".word 0x12400017\n\t" /* 800664C4: beqz       $s2, .L80066524 */
".word 0x00084400\n\t" /* 800664C8: sll       $t0, $t0, 16 */
".word 0x00084402\n\t" /* 800664CC: srl        $t0, $t0, 16 */
".word 0x01124025\n\t" /* 800664D0: or         $t0, $t0, $s2 */
".word 0x3C01FF9F\n\t" /* 800664D4: lui        $at, (0xFF9FFFFF >> 16) */
".word 0x3421FFFF\n\t" /* 800664D8: ori        $at, $at, (0xFF9FFFFF & 0xFFFF) */
".word 0x01214824\n\t" /* 800664DC: and        $t1, $t1, $at */
".word 0x3C010040\n\t" /* 800664E0: lui        $at, (0x400000 >> 16) */
".word 0x01214825\n\t" /* 800664E4: or         $t1, $t1, $at */
".word 0x8F230008\n\t" /* 800664E8: lw         $v1, 0x8($t9) */
".word 0xAF2C0038\n\t" /* 800664EC: sw         $t4, 0x38($t9) */
".word 0xAF23003C\n\t" /* 800664F0: sw         $v1, 0x3C($t9) */
".word 0x8F230014\n\t" /* 800664F4: lw         $v1, 0x14($t9) */
".word 0xAF2C0044\n\t" /* 800664F8: sw         $t4, 0x44($t9) */
".word 0xAF230048\n\t" /* 800664FC: sw         $v1, 0x48($t9) */
".word 0x8F230020\n\t" /* 80066500: lw         $v1, 0x20($t9) */
".word 0xAF2C0050\n\t" /* 80066504: sw         $t4, 0x50($t9) */
".word 0xAF230054\n\t" /* 80066508: sw         $v1, 0x54($t9) */
".word 0x8F23002C\n\t" /* 8006650C: lw         $v1, 0x2C($t9) */
".word 0xAF2C005C\n\t" /* 80066510: sw         $t4, 0x5C($t9) */
".word 0xAF230060\n\t" /* 80066514: sw         $v1, 0x60($t9) */
".word 0x27390034\n\t" /* 80066518: addiu      $t9, $t9, 0x34 */
".word 0x08019923\n\t" /* 8006651C: j          .L8006648C */
".word 0x24030000\n\t" /* 80066520: addiu     $v1, $zero, 0x0 */
".L80066524:\n\t"
".word 0x27390034\n\t" /* 80066524: addiu      $t9, $t9, 0x34 */
".L80066528:\n\t"
".word 0x2718FFFF\n\t" /* 80066528: addiu      $t8, $t8, -0x1 */
".word 0x1700FF59\n\t" /* 8006652C: bnez       $t8, .L80066294 */
".word 0x24E7001C\n\t" /* 80066530: addiu     $a3, $a3, 0x1C */
".L80066534:\n\t"
".word 0x8C900020\n\t" /* 80066534: lw         $s0, 0x20($a0) */
".word 0x8C910024\n\t" /* 80066538: lw         $s1, 0x24($a0) */
".word 0x8C920028\n\t" /* 8006653C: lw         $s2, 0x28($a0) */
".word 0x8C93002C\n\t" /* 80066540: lw         $s3, 0x2C($a0) */
".word 0x8C960030\n\t" /* 80066544: lw         $s6, 0x30($a0) */
".word 0x8C970034\n\t" /* 80066548: lw         $s7, 0x34($a0) */
".word 0x8C820000\n\t" /* 8006654C: lw         $v0, 0x0($a0) */
".word 0x3C018010\n\t" /* 80066550: lui        $at, %hi(D_800FE240) */
".word 0xAC39E240\n\t" /* 80066554: sw         $t9, %lo(D_800FE240)($at) */
".word 0x24420008\n\t" /* 80066558: addiu      $v0, $v0, 0x8 */
".word 0x03E00008\n\t" /* 8006655C: jr         $ra */
".word 0x00000000\n\t" /* 80066560: nop */
    ".set reorder\n"
);
