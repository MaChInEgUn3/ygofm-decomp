nonmatching func_8003BF00, 0x1C0

glabel func_8003BF00
    /* 2C700 8003BF00 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2C704 8003BF04 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2C708 8003BF08 0600A22C */  sltiu      $v0, $a1, 0x6
    /* 2C70C 8003BF0C 68004010 */  beqz       $v0, .L8003C0B0
    /* 2C710 8003BF10 21308000 */   addu      $a2, $a0, $zero
    /* 2C714 8003BF14 0180023C */  lui        $v0, %hi(jtbl_80010360)
    /* 2C718 8003BF18 60034224 */  addiu      $v0, $v0, %lo(jtbl_80010360)
    /* 2C71C 8003BF1C 80180500 */  sll        $v1, $a1, 2
    /* 2C720 8003BF20 21186200 */  addu       $v1, $v1, $v0
    /* 2C724 8003BF24 0000628C */  lw         $v0, 0x0($v1)
    /* 2C728 8003BF28 00000000 */  nop
    /* 2C72C 8003BF2C 08004000 */  jr         $v0
    /* 2C730 8003BF30 00000000 */   nop
  jlabel .L8003BF34
    /* 2C734 8003BF34 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2C738 8003BF38 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C73C 8003BF3C 00300224 */  addiu      $v0, $zero, 0x3000
    /* 2C740 8003BF40 1C00C2AC */  sw         $v0, 0x1C($a2)
    /* 2C744 8003BF44 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C748 8003BF48 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C74C 8003BF4C 0180033C */  lui        $v1, %hi(D_800101D8)
    /* 2C750 8003BF50 D801638C */  lw         $v1, %lo(D_800101D8)($v1)
    /* 2C754 8003BF54 1AF00008 */  j          .L8003C068
    /* 2C758 8003BF58 24104400 */   and       $v0, $v0, $a0
  jlabel .L8003BF5C
    /* 2C75C 8003BF5C DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2C760 8003BF60 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C764 8003BF64 0400023C */  lui        $v0, (0x43000 >> 16)
    /* 2C768 8003BF68 00304234 */  ori        $v0, $v0, (0x43000 & 0xFFFF)
    /* 2C76C 8003BF6C 1C00C2AC */  sw         $v0, 0x1C($a2)
    /* 2C770 8003BF70 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C774 8003BF74 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C778 8003BF78 0180033C */  lui        $v1, %hi(D_80010000)
    /* 2C77C 8003BF7C 0000638C */  lw         $v1, %lo(D_80010000)($v1)
    /* 2C780 8003BF80 1AF00008 */  j          .L8003C068
    /* 2C784 8003BF84 24104400 */   and       $v0, $v0, $a0
  jlabel .L8003BF88
    /* 2C788 8003BF88 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2C78C 8003BF8C FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C790 8003BF90 1B80023C */  lui        $v0, %hi(D_801AF000)
    /* 2C794 8003BF94 00F04224 */  addiu      $v0, $v0, %lo(D_801AF000)
    /* 2C798 8003BF98 0C00C2AC */  sw         $v0, 0xC($a2)
    /* 2C79C 8003BF9C 0800C2AC */  sw         $v0, 0x8($a2)
    /* 2C7A0 8003BFA0 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C7A4 8003BFA4 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C7A8 8003BFA8 00080324 */  addiu      $v1, $zero, 0x800
    /* 2C7AC 8003BFAC 1C00C3AC */  sw         $v1, 0x1C($a2)
    /* 2C7B0 8003BFB0 24104400 */  and        $v0, $v0, $a0
    /* 2C7B4 8003BFB4 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C7B8 8003BFB8 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C7BC 8003BFBC 01000224 */  addiu      $v0, $zero, 0x1
    /* 2C7C0 8003BFC0 2CF00008 */  j          .L8003C0B0
    /* 2C7C4 8003BFC4 4600C2A0 */   sb        $v0, 0x46($a2)
  jlabel .L8003BFC8
    /* 2C7C8 8003BFC8 DDFF043C */  lui        $a0, (0xFFDDFFFF >> 16)
    /* 2C7CC 8003BFCC FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 2C7D0 8003BFD0 C0010224 */  addiu      $v0, $zero, 0x1C0
    /* 2C7D4 8003BFD4 3000C2A4 */  sh         $v0, 0x30($a2)
    /* 2C7D8 8003BFD8 00010224 */  addiu      $v0, $zero, 0x100
    /* 2C7DC 8003BFDC 3200C2A4 */  sh         $v0, 0x32($a2)
    /* 2C7E0 8003BFE0 40000224 */  addiu      $v0, $zero, 0x40
    /* 2C7E4 8003BFE4 0400C2A4 */  sh         $v0, 0x4($a2)
    /* 2C7E8 8003BFE8 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C7EC 8003BFEC F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C7F0 8003BFF0 10000324 */  addiu      $v1, $zero, 0x10
    /* 2C7F4 8003BFF4 0600C3A4 */  sh         $v1, 0x6($a2)
    /* 2C7F8 8003BFF8 24104400 */  and        $v0, $v0, $a0
    /* 2C7FC 8003BFFC 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C800 8003C000 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C804 8003C004 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C808 8003C008 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C80C 8003C00C 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 2C810 8003C010 25104300 */  or         $v0, $v0, $v1
    /* 2C814 8003C014 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C818 8003C018 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C81C 8003C01C 02000224 */  addiu      $v0, $zero, 0x2
    /* 2C820 8003C020 4600C2A0 */  sb         $v0, 0x46($a2)
    /* 2C824 8003C024 0A80023C */  lui        $v0, %hi(D_8009B118)
    /* 2C828 8003C028 18B1428C */  lw         $v0, %lo(D_8009B118)($v0)
    /* 2C82C 8003C02C 00800334 */  ori        $v1, $zero, 0x8000
    /* 2C830 8003C030 1C00C3AC */  sw         $v1, 0x1C($a2)
    /* 2C834 8003C034 0800C2AC */  sw         $v0, 0x8($a2)
    /* 2C838 8003C038 00084224 */  addiu      $v0, $v0, 0x800
    /* 2C83C 8003C03C 2CF00008 */  j          .L8003C0B0
    /* 2C840 8003C040 0C00C2AC */   sw        $v0, 0xC($a2)
  jlabel .L8003C044
    /* 2C844 8003C044 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2C848 8003C048 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C84C 8003C04C 00080224 */  addiu      $v0, $zero, 0x800
    /* 2C850 8003C050 1C00C2AC */  sw         $v0, 0x1C($a2)
    /* 2C854 8003C054 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C858 8003C058 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C85C 8003C05C 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 2C860 8003C060 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 2C864 8003C064 24104400 */  and        $v0, $v0, $a0
  .L8003C068:
    /* 2C868 8003C068 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C86C 8003C06C F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C870 8003C070 01000224 */  addiu      $v0, $zero, 0x1
    /* 2C874 8003C074 0C00C3AC */  sw         $v1, 0xC($a2)
    /* 2C878 8003C078 0800C3AC */  sw         $v1, 0x8($a2)
    /* 2C87C 8003C07C 2CF00008 */  j          .L8003C0B0
    /* 2C880 8003C080 4600C2A0 */   sb        $v0, 0x46($a2)
  jlabel .L8003C084
    /* 2C884 8003C084 00010224 */  addiu      $v0, $zero, 0x100
    /* 2C888 8003C088 F0000324 */  addiu      $v1, $zero, 0xF0
    /* 2C88C 8003C08C 0000C2A4 */  sh         $v0, 0x0($a2)
    /* 2C890 8003C090 0400C2A4 */  sh         $v0, 0x4($a2)
    /* 2C894 8003C094 04000224 */  addiu      $v0, $zero, 0x4
    /* 2C898 8003C098 0A80053C */  lui        $a1, %hi(D_8009B118)
    /* 2C89C 8003C09C 18B1A58C */  lw         $a1, %lo(D_8009B118)($a1)
    /* 2C8A0 8003C0A0 2120C000 */  addu       $a0, $a2, $zero
    /* 2C8A4 8003C0A4 0200C3A4 */  sh         $v1, 0x2($a2)
    /* 2C8A8 8003C0A8 7A07020C */  jal        func_80081DE8
    /* 2C8AC 8003C0AC 0600C2A4 */   sh        $v0, 0x6($a2)
  .L8003C0B0:
    /* 2C8B0 8003C0B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2C8B4 8003C0B4 00000000 */  nop
    /* 2C8B8 8003C0B8 0800E003 */  jr         $ra
    /* 2C8BC 8003C0BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003BF00
