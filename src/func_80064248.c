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
   project_gte_register_spill_and_pin_techniques.md). Sibling of func_80065BCC
   (src/gte_ot_insert_transformed_tris_gouraud_transluc.c) with an added NCLIP
   backface-cull test between RTPT and the SXY/AVSZ3 steps (same NCLIP shape
   as func_80061DDC's family, src/gte_ot_insert_transformed_tris_lit_id_clip.c)
   -- i.e. func_80065BCC plus clip, as the unit name says. Pure cop2 leaf: 0
   jal, 1 jr, 25 cop2/mtc2/mfc2/lwc2/swc2 ops -- function-code decode confirms
   RTPT (0x280030), NCLIP (0x1400006), AVSZ3 (0x158002d), NCCT (0x118043f), so
   this is gouraud (NCCT, 3-vertex lighting) with an NCLIP cull. Verified
   0-diff by direct disassembly + re-encoding against the ROM bytes at file
   offset 0x54A48, length 0x320 (200 instructions); GTE standing rule entry in
   config/asm_allowed.txt. */
__asm__(
    ".set noreorder\n"
    ".global func_80064248\n"
    "func_80064248:\n"
    ".word 0x8C870000\n\t" /* 80064248: lw      $a3, 0($a0) */
    ".word 0x8C990010\n\t" /* 8006424C: lw      $t9, 16($a0) */
    ".word 0x94F80002\n\t" /* 80064250: lhu     $t8, 2($a3) */
    ".word 0x8CE60004\n\t" /* 80064254: lw      $a2, 4($a3) */
    ".word 0x8C850014\n\t" /* 80064258: lw      $a1, 20($a0) */
    ".word 0x00063080\n\t" /* 8006425C: sll     $a2, $a2, 0x2 */
    ".word 0xAC900020\n\t" /* 80064260: sw      $s0, 32($a0) */
    ".word 0xAC910024\n\t" /* 80064264: sw      $s1, 36($a0) */
    ".word 0xAC920028\n\t" /* 80064268: sw      $s2, 40($a0) */
    ".word 0xAC93002C\n\t" /* 8006426C: sw      $s3, 44($a0) */
    ".word 0xAC960030\n\t" /* 80064270: sw      $s6, 48($a0) */
    ".word 0xAC970034\n\t" /* 80064274: sw      $s7, 52($a0) */
    ".word 0x130000AF\n\t" /* 80064278: beqz    $t8, .L80064538 */
    ".word 0x00A63821\n\t" /* 8006427C: addu    $a3, $a1, $a2 */
    ".word 0x3C10800A\n\t" /* 80064280: lui     $s0, %hi(D_8009AFB4) */
    ".word 0x8E10AFB4\n\t" /* 80064284: lw      $s0, %lo(D_8009AFB4)($s0) */
    ".word 0x3C11800A\n\t" /* 80064288: lui     $s1, %hi(D_8009AFD8) */
    ".word 0x8E31AFD8\n\t" /* 8006428C: lw      $s1, %lo(D_8009AFD8)($s1) */
    ".word 0x3C12800A\n\t" /* 80064290: lui     $s2, %hi(D_8009AFDC) */
    ".word 0x8E52AFDC\n\t" /* 80064294: lw      $s2, %lo(D_8009AFDC)($s2) */
    ".word 0x3C16800A\n\t" /* 80064298: lui     $s6, %hi(D_8009AFE4) */
    ".word 0x82D6AFE4\n\t" /* 8006429C: lb      $s6, %lo(D_8009AFE4)($s6) */
    ".word 0x3C17800A\n\t" /* 800642A0: lui     $s7, %hi(D_8009AFE0) */
    ".word 0x8EF7AFE0\n\t" /* 800642A4: lw      $s7, %lo(D_8009AFE0)($s7) */
    ".word 0x02006021\n\t" /* 800642A8: addu    $t4, $s0, $zero */
    ".word 0x3C02800A\n\t" /* 800642AC: lui     $v0, %hi(D_8009AFE5) */
    ".word 0x8042AFE5\n\t" /* 800642B0: lb      $v0, %lo(D_8009AFE5)($v0) */
    ".word 0x3C010200\n\t" /* 800642B4: lui     $at, 0x200 */
    ".word 0x02018025\n\t" /* 800642B8: or      $s0, $s0, $at */
    ".word 0x1440000E\n\t" /* 800642BC: bnez    $v0, .L800642F8 */
    ".word 0x02006021\n\t" /* 800642C0: addu    $t4, $s0, $zero */
    ".word 0x8CF10004\n\t" /* 800642C4: lw      $s1, 4($a3) */
    ".word 0x3C010060\n\t" /* 800642C8: lui     $at, 0x60 */
    ".word 0x02218824\n\t" /* 800642CC: and     $s1, $s1, $at */
    ".word 0x16200009\n\t" /* 800642D0: bnez    $s1, .L800642F8 */
    ".word 0x00000000\n\t" /* 800642D4: nop */
    ".word 0x12400008\n\t" /* 800642D8: beqz    $s2, .L800642FC */
    ".word 0x00000000\n\t" /* 800642DC: nop */
    ".word 0x94F20002\n\t" /* 800642E0: lhu     $s2, 2($a3) */
    ".word 0x3C0C800A\n\t" /* 800642E4: lui     $t4, %hi(D_8009AFC4) */
    ".word 0x8D8CAFC4\n\t" /* 800642E8: lw      $t4, %lo(D_8009AFC4)($t4) */
    ".word 0x00129400\n\t" /* 800642EC: sll     $s2, $s2, 0x10 */
    ".word 0x080190BF\n\t" /* 800642F0: j       .L800642FC */
    ".word 0x3C110020\n\t" /* 800642F4: lui     $s1, 0x20 */
    ".L800642F8:\n\t"
    ".word 0x24120000\n\t" /* 800642F8: addiu   $s2, $zero, 0x0 */
    ".L800642FC:\n\t"
    ".word 0x00109E02\n\t" /* 800642FC: srl     $s3, $s0, 0x18 */
    ".word 0x8C850018\n\t" /* 80064300: lw      $a1, 24($a0) */
    ".word 0x8C86001C\n\t" /* 80064304: lw      $a2, 28($a0) */
    ".word 0x48903000\n\t" /* 80064308: mtc2    $s0, $6 */
    ".word 0x8C8D0004\n\t" /* 8006430C: lw      $t5, 4($a0) */
    ".word 0x8C8E0008\n\t" /* 80064310: lw      $t6, 8($a0) */
    ".word 0x8DAF0004\n\t" /* 80064314: lw      $t7, 4($t5) */
    ".L80064318:\n\t"
    ".word 0x8CE8000C\n\t" /* 80064318: lw      $t0, 12($a3) */
    ".word 0x8CE90010\n\t" /* 8006431C: lw      $t1, 16($a3) */
    ".word 0x8CEA0014\n\t" /* 80064320: lw      $t2, 20($a3) */
    ".word 0x00086C02\n\t" /* 80064324: srl     $t5, $t0, 0x10 */
    ".word 0x000D68C0\n\t" /* 80064328: sll     $t5, $t5, 0x3 */
    ".word 0x01A56821\n\t" /* 8006432C: addu    $t5, $t5, $a1 */
    ".word 0xC9A00000\n\t" /* 80064330: lwc2    $0, 0($t5) */
    ".word 0xC9A10004\n\t" /* 80064334: lwc2    $1, 4($t5) */
    ".word 0x00096C02\n\t" /* 80064338: srl     $t5, $t1, 0x10 */
    ".word 0x000D68C0\n\t" /* 8006433C: sll     $t5, $t5, 0x3 */
    ".word 0x01A56821\n\t" /* 80064340: addu    $t5, $t5, $a1 */
    ".word 0xC9A20000\n\t" /* 80064344: lwc2    $2, 0($t5) */
    ".word 0xC9A30004\n\t" /* 80064348: lwc2    $3, 4($t5) */
    ".word 0x000A6C02\n\t" /* 8006434C: srl     $t5, $t2, 0x10 */
    ".word 0x000D68C0\n\t" /* 80064350: sll     $t5, $t5, 0x3 */
    ".word 0x01A56821\n\t" /* 80064354: addu    $t5, $t5, $a1 */
    ".word 0xC9A40000\n\t" /* 80064358: lwc2    $4, 0($t5) */
    ".word 0xC9A50004\n\t" /* 8006435C: lwc2    $5, 4($t5) */
    ".word 0x00084400\n\t" /* 80064360: sll     $t0, $t0, 0x10 */
    ".word 0x00084342\n\t" /* 80064364: srl     $t0, $t0, 0xd */
    ".word 0x4A280030\n\t" /* 80064368: rtpt */
    ".word 0x00094C00\n\t" /* 8006436C: sll     $t1, $t1, 0x10 */
    ".word 0x00094B42\n\t" /* 80064370: srl     $t1, $t1, 0xd */
    ".word 0x000A5400\n\t" /* 80064374: sll     $t2, $t2, 0x10 */
    ".word 0x24010001\n\t" /* 80064378: addiu   $at, $zero, 0x1 */
    ".word 0x12C1000A\n\t" /* 8006437C: beq     $s6, $at, .L800643A8 */
    ".word 0x000A5342\n\t" /* 80064380: srl     $t2, $t2, 0xd */
    ".word 0x4842F800\n\t" /* 80064384: cfc2    $v0, $31 */
    ".word 0x00000000\n\t" /* 80064388: nop */
    ".word 0x04400067\n\t" /* 8006438C: bltz    $v0, .L8006452C */
    ".word 0x00000000\n\t" /* 80064390: nop */
    ".word 0x4B400006\n\t" /* 80064394: nclip */
    ".word 0x4802C000\n\t" /* 80064398: mfc2    $v0, $24 */
    ".word 0x00000000\n\t" /* 8006439C: nop */
    ".word 0x18400062\n\t" /* 800643A0: blez    $v0, .L8006452C */
    ".word 0x00000000\n\t" /* 800643A4: nop */
    ".L800643A8:\n\t"
    ".word 0x4B58002D\n\t" /* 800643A8: avsz3 */
    ".word 0x12C0001E\n\t" /* 800643AC: beqz    $s6, .L80064428 */
    ".word 0x01066821\n\t" /* 800643B0: addu    $t5, $t0, $a2 */
    ".word 0xC9A00000\n\t" /* 800643B4: lwc2    $0, 0($t5) */
    ".word 0xC9A10004\n\t" /* 800643B8: lwc2    $1, 4($t5) */
    ".word 0x01266821\n\t" /* 800643BC: addu    $t5, $t1, $a2 */
    ".word 0xC9A20000\n\t" /* 800643C0: lwc2    $2, 0($t5) */
    ".word 0xC9A30004\n\t" /* 800643C4: lwc2    $3, 4($t5) */
    ".word 0x01466821\n\t" /* 800643C8: addu    $t5, $t2, $a2 */
    ".word 0xC9A40000\n\t" /* 800643CC: lwc2    $4, 0($t5) */
    ".word 0xC9A50004\n\t" /* 800643D0: lwc2    $5, 4($t5) */
    ".word 0x00000000\n\t" /* 800643D4: nop */
    ".word 0x00000000\n\t" /* 800643D8: nop */
    ".word 0x4B18043F\n\t" /* 800643DC: ncct */
    ".word 0x12E00009\n\t" /* 800643E0: beqz    $s7, .L80064408 */
    ".word 0x00084042\n\t" /* 800643E4: srl     $t0, $t0, 0x1 */
    ".word 0x01174021\n\t" /* 800643E8: addu    $t0, $t0, $s7 */
    ".word 0x00094842\n\t" /* 800643EC: srl     $t1, $t1, 0x1 */
    ".word 0x01374821\n\t" /* 800643F0: addu    $t1, $t1, $s7 */
    ".word 0x000A5042\n\t" /* 800643F4: srl     $t2, $t2, 0x1 */
    ".word 0x01575021\n\t" /* 800643F8: addu    $t2, $t2, $s7 */
    ".word 0xE9140000\n\t" /* 800643FC: swc2    $20, 0($t0) */
    ".word 0xE9350000\n\t" /* 80064400: swc2    $21, 0($t1) */
    ".word 0xE9560000\n\t" /* 80064404: swc2    $22, 0($t2) */
    ".L80064408:\n\t"
    ".word 0xEB340004\n\t" /* 80064408: swc2    $20, 4($t9) */
    ".word 0xEB350010\n\t" /* 8006440C: swc2    $21, 16($t9) */
    ".word 0xEB36001C\n\t" /* 80064410: swc2    $22, 28($t9) */
    ".word 0x24010001\n\t" /* 80064414: addiu   $at, $zero, 0x1 */
    ".word 0x12C10044\n\t" /* 80064418: beq     $s6, $at, .L8006452C */
    ".word 0x00000000\n\t" /* 8006441C: nop */
    ".word 0x08019117\n\t" /* 80064420: j       .L8006445C */
    ".word 0x00000000\n\t" /* 80064424: nop */
    ".L80064428:\n\t"
    ".word 0x00084042\n\t" /* 80064428: srl     $t0, $t0, 0x1 */
    ".word 0x01171821\n\t" /* 8006442C: addu    $v1, $t0, $s7 */
    ".word 0x8C680000\n\t" /* 80064430: lw      $t0, 0($v1) */
    ".word 0x00094842\n\t" /* 80064434: srl     $t1, $t1, 0x1 */
    ".word 0x01371821\n\t" /* 80064438: addu    $v1, $t1, $s7 */
    ".word 0x8C690000\n\t" /* 8006443C: lw      $t1, 0($v1) */
    ".word 0x000A5042\n\t" /* 80064440: srl     $t2, $t2, 0x1 */
    ".word 0x01571821\n\t" /* 80064444: addu    $v1, $t2, $s7 */
    ".word 0x8C6A0000\n\t" /* 80064448: lw      $t2, 0($v1) */
    ".word 0xAF280004\n\t" /* 8006444C: sw      $t0, 4($t9) */
    ".word 0xAF290010\n\t" /* 80064450: sw      $t1, 16($t9) */
    ".word 0xAF2A001C\n\t" /* 80064454: sw      $t2, 28($t9) */
    ".word 0xA3330007\n\t" /* 80064458: sb      $s3, 7($t9) */
    ".L8006445C:\n\t"
    ".word 0x8CE80000\n\t" /* 8006445C: lw      $t0, 0($a3) */
    ".word 0x8CE90004\n\t" /* 80064460: lw      $t1, 4($a3) */
    ".word 0x8CEA0008\n\t" /* 80064464: lw      $t2, 8($a3) */
    ".word 0x48023800\n\t" /* 80064468: mfc2    $v0, $7 */
    ".word 0x3C010200\n\t" /* 8006446C: lui     $at, 0x200 */
    ".word 0x02011824\n\t" /* 80064470: and     $v1, $s0, $at */
    ".word 0x3C01FF9F\n\t" /* 80064474: lui     $at, 0xff9f */
    ".word 0x3421FFFF\n\t" /* 80064478: ori     $at, $at, 0xffff */
    ".word 0x01214824\n\t" /* 8006447C: and     $t1, $t1, $at */
    ".word 0x01314825\n\t" /* 80064480: or      $t1, $t1, $s1 */
    ".word 0x01C21006\n\t" /* 80064484: srlv    $v0, $v0, $t6 */
    ".word 0x00021080\n\t" /* 80064488: sll     $v0, $v0, 0x2 */
    ".word 0x004F1021\n\t" /* 8006448C: addu    $v0, $v0, $t7 */
    ".word 0x8C4D0000\n\t" /* 80064490: lw      $t5, 0($v0) */
    ".word 0xEB2C0008\n\t" /* 80064494: swc2    $12, 8($t9) */
    ".word 0xEB2D0014\n\t" /* 80064498: swc2    $13, 20($t9) */
    ".word 0xEB2E0020\n\t" /* 8006449C: swc2    $14, 32($t9) */
    ".L800644A0:\n\t"
    ".word 0xAF28000C\n\t" /* 800644A0: sw      $t0, 12($t9) */
    ".word 0xAF290018\n\t" /* 800644A4: sw      $t1, 24($t9) */
    ".word 0xAF2A0024\n\t" /* 800644A8: sw      $t2, 36($t9) */
    ".word 0x000D6A00\n\t" /* 800644AC: sll     $t5, $t5, 0x8 */
    ".word 0x35AD0009\n\t" /* 800644B0: ori     $t5, $t5, 0x9 */
    ".word 0x000D0A02\n\t" /* 800644B4: srl     $at, $t5, 0x8 */
    ".word 0x000D6E00\n\t" /* 800644B8: sll     $t5, $t5, 0x18 */
    ".word 0x01A16825\n\t" /* 800644BC: or      $t5, $t5, $at */
    ".word 0xAF2D0000\n\t" /* 800644C0: sw      $t5, 0($t9) */
    ".word 0x00196A00\n\t" /* 800644C4: sll     $t5, $t9, 0x8 */
    ".word 0x000D6A02\n\t" /* 800644C8: srl     $t5, $t5, 0x8 */
    ".word 0x10600016\n\t" /* 800644CC: beqz    $v1, .L80064528 */
    ".word 0xAC4D0000\n\t" /* 800644D0: sw      $t5, 0($v0) */
    ".word 0x12400014\n\t" /* 800644D4: beqz    $s2, .L80064528 */
    ".word 0x00084400\n\t" /* 800644D8: sll     $t0, $t0, 0x10 */
    ".word 0x00084402\n\t" /* 800644DC: srl     $t0, $t0, 0x10 */
    ".word 0x01124025\n\t" /* 800644E0: or      $t0, $t0, $s2 */
    ".word 0x3C01FF9F\n\t" /* 800644E4: lui     $at, 0xff9f */
    ".word 0x3421FFFF\n\t" /* 800644E8: ori     $at, $at, 0xffff */
    ".word 0x01214824\n\t" /* 800644EC: and     $t1, $t1, $at */
    ".word 0x3C010040\n\t" /* 800644F0: lui     $at, 0x40 */
    ".word 0x01214825\n\t" /* 800644F4: or      $t1, $t1, $at */
    ".word 0x8F230008\n\t" /* 800644F8: lw      $v1, 8($t9) */
    ".word 0xAF2C002C\n\t" /* 800644FC: sw      $t4, 44($t9) */
    ".word 0xAF230030\n\t" /* 80064500: sw      $v1, 48($t9) */
    ".word 0x8F230014\n\t" /* 80064504: lw      $v1, 20($t9) */
    ".word 0xAF2C0038\n\t" /* 80064508: sw      $t4, 56($t9) */
    ".word 0xAF23003C\n\t" /* 8006450C: sw      $v1, 60($t9) */
    ".word 0x8F230020\n\t" /* 80064510: lw      $v1, 32($t9) */
    ".word 0xAF2C0044\n\t" /* 80064514: sw      $t4, 68($t9) */
    ".word 0xAF230048\n\t" /* 80064518: sw      $v1, 72($t9) */
    ".word 0x27390028\n\t" /* 8006451C: addiu   $t9, $t9, 40 */
    ".word 0x08019128\n\t" /* 80064520: j       .L800644A0 */
    ".word 0x24030000\n\t" /* 80064524: addiu   $v1, $zero, 0x0 */
    ".L80064528:\n\t"
    ".word 0x27390028\n\t" /* 80064528: addiu   $t9, $t9, 40 */
    ".L8006452C:\n\t"
    ".word 0x2718FFFF\n\t" /* 8006452C: addiu   $t8, $t8, -1 */
    ".word 0x1700FF79\n\t" /* 80064530: bnez    $t8, .L80064318 */
    ".word 0x24E70018\n\t" /* 80064534: addiu   $a3, $a3, 24 */
    ".L80064538:\n\t"
    ".word 0x8C900020\n\t" /* 80064538: lw      $s0, 32($a0) */
    ".word 0x8C910024\n\t" /* 8006453C: lw      $s1, 36($a0) */
    ".word 0x8C920028\n\t" /* 80064540: lw      $s2, 40($a0) */
    ".word 0x8C93002C\n\t" /* 80064544: lw      $s3, 44($a0) */
    ".word 0x8C960030\n\t" /* 80064548: lw      $s6, 48($a0) */
    ".word 0x8C970034\n\t" /* 8006454C: lw      $s7, 52($a0) */
    ".word 0x8C820000\n\t" /* 80064550: lw      $v0, 0($a0) */
    ".word 0x3C018010\n\t" /* 80064554: lui     $at, %hi(D_800FE240) */
    ".word 0xAC39E240\n\t" /* 80064558: sw      $t9, %lo(D_800FE240)($at) */
    ".word 0x24420008\n\t" /* 8006455C: addiu   $v0, $v0, 8 */
    ".word 0x03E00008\n\t" /* 80064560: jr      $ra */
    ".word 0x00000000\n\t" /* 80064564: nop */
    ".set reorder\n"
);
