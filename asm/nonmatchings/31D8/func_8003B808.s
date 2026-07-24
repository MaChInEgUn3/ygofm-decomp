nonmatching func_8003B808, 0x1B4

glabel func_8003B808
    /* 2C008 8003B808 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2C00C 8003B80C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2C010 8003B810 21808000 */  addu       $s0, $a0, $zero
    /* 2C014 8003B814 0500A22C */  sltiu      $v0, $a1, 0x5
    /* 2C018 8003B818 64004010 */  beqz       $v0, .L8003B9AC
    /* 2C01C 8003B81C 1400BFAF */   sw        $ra, 0x14($sp)
    /* 2C020 8003B820 0180023C */  lui        $v0, %hi(jtbl_80010348)
    /* 2C024 8003B824 48034224 */  addiu      $v0, $v0, %lo(jtbl_80010348)
    /* 2C028 8003B828 80180500 */  sll        $v1, $a1, 2
    /* 2C02C 8003B82C 21186200 */  addu       $v1, $v1, $v0
    /* 2C030 8003B830 0000628C */  lw         $v0, 0x0($v1)
    /* 2C034 8003B834 00000000 */  nop
    /* 2C038 8003B838 08004000 */  jr         $v0
    /* 2C03C 8003B83C 00000000 */   nop
  jlabel .L8003B840
    /* 2C040 8003B840 DDFF043C */  lui        $a0, (0xFFDDFFFF >> 16)
    /* 2C044 8003B844 FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 2C048 8003B848 00010224 */  addiu      $v0, $zero, 0x100
    /* 2C04C 8003B84C 320002A6 */  sh         $v0, 0x32($s0)
    /* 2C050 8003B850 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C054 8003B854 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C058 8003B858 40000324 */  addiu      $v1, $zero, 0x40
    /* 2C05C 8003B85C 300000A6 */  sh         $zero, 0x30($s0)
    /* 2C060 8003B860 040003A6 */  sh         $v1, 0x4($s0)
    /* 2C064 8003B864 24104400 */  and        $v0, $v0, $a0
    /* 2C068 8003B868 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C06C 8003B86C F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C070 8003B870 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C074 8003B874 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C078 8003B878 0100043C */  lui        $a0, (0x10000 >> 16)
    /* 2C07C 8003B87C 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 2C080 8003B880 25104400 */  or         $v0, $v0, $a0
    /* 2C084 8003B884 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C088 8003B888 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C08C 8003B88C 02000224 */  addiu      $v0, $zero, 0x2
    /* 2C090 8003B890 460002A2 */  sb         $v0, 0x46($s0)
    /* 2C094 8003B894 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 2C098 8003B898 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 2C09C 8003B89C 10000224 */  addiu      $v0, $zero, 0x10
    /* 2C0A0 8003B8A0 060002A6 */  sh         $v0, 0x6($s0)
    /* 2C0A4 8003B8A4 080003AE */  sw         $v1, 0x8($s0)
    /* 2C0A8 8003B8A8 00086324 */  addiu      $v1, $v1, 0x800
    /* 2C0AC 8003B8AC 6BEE0008 */  j          .L8003B9AC
    /* 2C0B0 8003B8B0 0C0003AE */   sw        $v1, 0xC($s0)
  jlabel .L8003B8B4
    /* 2C0B4 8003B8B4 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2C0B8 8003B8B8 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C0BC 8003B8BC 00080224 */  addiu      $v0, $zero, 0x800
    /* 2C0C0 8003B8C0 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 2C0C4 8003B8C4 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C0C8 8003B8C8 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C0CC 8003B8CC 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 2C0D0 8003B8D0 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 2C0D4 8003B8D4 65EE0008 */  j          .L8003B994
    /* 2C0D8 8003B8D8 24104400 */   and       $v0, $v0, $a0
  jlabel .L8003B8DC
    /* 2C0DC 8003B8DC F0000224 */  addiu      $v0, $zero, 0xF0
    /* 2C0E0 8003B8E0 020002A6 */  sh         $v0, 0x2($s0)
    /* 2C0E4 8003B8E4 00010224 */  addiu      $v0, $zero, 0x100
    /* 2C0E8 8003B8E8 040002A6 */  sh         $v0, 0x4($s0)
    /* 2C0EC 8003B8EC 04000224 */  addiu      $v0, $zero, 0x4
    /* 2C0F0 8003B8F0 0A80053C */  lui        $a1, %hi(D_8009B118)
    /* 2C0F4 8003B8F4 18B1A58C */  lw         $a1, %lo(D_8009B118)($a1)
    /* 2C0F8 8003B8F8 21200002 */  addu       $a0, $s0, $zero
    /* 2C0FC 8003B8FC 000000A6 */  sh         $zero, 0x0($s0)
    /* 2C100 8003B900 7A07020C */  jal        func_80081DE8
    /* 2C104 8003B904 060002A6 */   sh        $v0, 0x6($s0)
    /* 2C108 8003B908 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2C10C 8003B90C FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C110 8003B910 1B80023C */  lui        $v0, %hi(D_801AF000)
    /* 2C114 8003B914 00F04224 */  addiu      $v0, $v0, %lo(D_801AF000)
    /* 2C118 8003B918 0C0002AE */  sw         $v0, 0xC($s0)
    /* 2C11C 8003B91C 080002AE */  sw         $v0, 0x8($s0)
    /* 2C120 8003B920 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C124 8003B924 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C128 8003B928 00080324 */  addiu      $v1, $zero, 0x800
    /* 2C12C 8003B92C 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 2C130 8003B930 24104400 */  and        $v0, $v0, $a0
    /* 2C134 8003B934 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C138 8003B938 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C13C 8003B93C 6AEE0008 */  j          .L8003B9A8
    /* 2C140 8003B940 01000224 */   addiu     $v0, $zero, 0x1
  jlabel .L8003B944
    /* 2C144 8003B944 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2C148 8003B948 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C14C 8003B94C 0100023C */  lui        $v0, (0x18000 >> 16)
    /* 2C150 8003B950 00804234 */  ori        $v0, $v0, (0x18000 & 0xFFFF)
    /* 2C154 8003B954 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 2C158 8003B958 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C15C 8003B95C F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C160 8003B960 0180033C */  lui        $v1, %hi(D_80010000)
    /* 2C164 8003B964 0000638C */  lw         $v1, %lo(D_80010000)($v1)
    /* 2C168 8003B968 65EE0008 */  j          .L8003B994
    /* 2C16C 8003B96C 24104400 */   and       $v0, $v0, $a0
  jlabel .L8003B970
    /* 2C170 8003B970 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2C174 8003B974 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C178 8003B978 00280224 */  addiu      $v0, $zero, 0x2800
    /* 2C17C 8003B97C 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 2C180 8003B980 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C184 8003B984 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C188 8003B988 0180033C */  lui        $v1, %hi(D_800101D8)
    /* 2C18C 8003B98C D801638C */  lw         $v1, %lo(D_800101D8)($v1)
    /* 2C190 8003B990 24104400 */  and        $v0, $v0, $a0
  .L8003B994:
    /* 2C194 8003B994 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C198 8003B998 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C19C 8003B99C 01000224 */  addiu      $v0, $zero, 0x1
    /* 2C1A0 8003B9A0 0C0003AE */  sw         $v1, 0xC($s0)
    /* 2C1A4 8003B9A4 080003AE */  sw         $v1, 0x8($s0)
  .L8003B9A8:
    /* 2C1A8 8003B9A8 460002A2 */  sb         $v0, 0x46($s0)
  .L8003B9AC:
    /* 2C1AC 8003B9AC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2C1B0 8003B9B0 1000B08F */  lw         $s0, 0x10($sp)
    /* 2C1B4 8003B9B4 0800E003 */  jr         $ra
    /* 2C1B8 8003B9B8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003B808
