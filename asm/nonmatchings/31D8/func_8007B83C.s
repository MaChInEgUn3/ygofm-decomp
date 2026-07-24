nonmatching func_8007B83C, 0x1F0

glabel func_8007B83C
    /* 6C03C 8007B83C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6C040 8007B840 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C044 8007B844 21808000 */  addu       $s0, $a0, $zero
    /* 6C048 8007B848 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6C04C 8007B84C 2188A000 */  addu       $s1, $a1, $zero
    /* 6C050 8007B850 46000012 */  beqz       $s0, .L8007B96C
    /* 6C054 8007B854 1800BFAF */   sw        $ra, 0x18($sp)
    /* 6C058 8007B858 BCF8010C */  jal        func_8007E2F0
    /* 6C05C 8007B85C 21200000 */   addu      $a0, $zero, $zero
    /* 6C060 8007B860 0F80033C */  lui        $v1, %hi(D_800F5F70)
    /* 6C064 8007B864 705F638C */  lw         $v1, %lo(D_800F5F70)($v1)
    /* 6C068 8007B868 21200000 */  addu       $a0, $zero, $zero
    /* 6C06C 8007B86C 00110300 */  sll        $v0, $v1, 4
  .L8007B870:
    /* 6C070 8007B870 0F80013C */  lui        $at, %hi(D_800F5EF0)
    /* 6C074 8007B874 21082200 */  addu       $at, $at, $v0
    /* 6C078 8007B878 F05E228C */  lw         $v0, %lo(D_800F5EF0)($at)
    /* 6C07C 8007B87C 00000000 */  nop
    /* 6C080 8007B880 14005010 */  beq        $v0, $s0, .L8007B8D4
    /* 6C084 8007B884 01006324 */   addiu     $v1, $v1, 0x1
    /* 6C088 8007B888 08006228 */  slti       $v0, $v1, 0x8
    /* 6C08C 8007B88C 02004014 */  bnez       $v0, .L8007B898
    /* 6C090 8007B890 00000000 */   nop
    /* 6C094 8007B894 21180000 */  addu       $v1, $zero, $zero
  .L8007B898:
    /* 6C098 8007B898 01008424 */  addiu      $a0, $a0, 0x1
    /* 6C09C 8007B89C 08008228 */  slti       $v0, $a0, 0x8
    /* 6C0A0 8007B8A0 F3FF4014 */  bnez       $v0, .L8007B870
    /* 6C0A4 8007B8A4 00110300 */   sll       $v0, $v1, 4
    /* 6C0A8 8007B8A8 0F80023C */  lui        $v0, %hi(D_800F5F70)
    /* 6C0AC 8007B8AC 705F428C */  lw         $v0, %lo(D_800F5F70)($v0)
    /* 6C0B0 8007B8B0 00000000 */  nop
    /* 6C0B4 8007B8B4 00110200 */  sll        $v0, $v0, 4
    /* 6C0B8 8007B8B8 0F80013C */  lui        $at, %hi(D_800F5EF0)
    /* 6C0BC 8007B8BC 21082200 */  addu       $at, $at, $v0
    /* 6C0C0 8007B8C0 F05E228C */  lw         $v0, %lo(D_800F5EF0)($at)
    /* 6C0C4 8007B8C4 00000000 */  nop
    /* 6C0C8 8007B8C8 2A100202 */  slt        $v0, $s0, $v0
    /* 6C0CC 8007B8CC 02004010 */  beqz       $v0, .L8007B8D8
    /* 6C0D0 8007B8D0 21180000 */   addu      $v1, $zero, $zero
  .L8007B8D4:
    /* 6C0D4 8007B8D4 07000324 */  addiu      $v1, $zero, 0x7
  .L8007B8D8:
    /* 6C0D8 8007B8D8 07000224 */  addiu      $v0, $zero, 0x7
    /* 6C0DC 8007B8DC 4E006214 */  bne        $v1, $v0, .L8007BA18
    /* 6C0E0 8007B8E0 21100000 */   addu      $v0, $zero, $zero
    /* 6C0E4 8007B8E4 0F80023C */  lui        $v0, %hi(D_800F5F70)
    /* 6C0E8 8007B8E8 705F428C */  lw         $v0, %lo(D_800F5F70)($v0)
    /* 6C0EC 8007B8EC 00000000 */  nop
    /* 6C0F0 8007B8F0 FFFF4324 */  addiu      $v1, $v0, -0x1
    /* 6C0F4 8007B8F4 02006104 */  bgez       $v1, .L8007B900
    /* 6C0F8 8007B8F8 00000000 */   nop
    /* 6C0FC 8007B8FC 07000324 */  addiu      $v1, $zero, 0x7
  .L8007B900:
    /* 6C100 8007B900 11000012 */  beqz       $s0, .L8007B948
    /* 6C104 8007B904 21200000 */   addu      $a0, $zero, $zero
    /* 6C108 8007B908 00310300 */  sll        $a2, $v1, 4
  .L8007B90C:
    /* 6C10C 8007B90C 0F80023C */  lui        $v0, %hi(D_800F5EF0)
    /* 6C110 8007B910 21104600 */  addu       $v0, $v0, $a2
    /* 6C114 8007B914 F05E428C */  lw         $v0, %lo(D_800F5EF0)($v0)
    /* 6C118 8007B918 00000000 */  nop
    /* 6C11C 8007B91C 21005010 */  beq        $v0, $s0, .L8007B9A4
    /* 6C120 8007B920 FFFF6324 */   addiu     $v1, $v1, -0x1
    /* 6C124 8007B924 02006104 */  bgez       $v1, .L8007B930
    /* 6C128 8007B928 00000000 */   nop
    /* 6C12C 8007B92C 07000324 */  addiu      $v1, $zero, 0x7
  .L8007B930:
    /* 6C130 8007B930 01008424 */  addiu      $a0, $a0, 0x1
    /* 6C134 8007B934 08008228 */  slti       $v0, $a0, 0x8
    /* 6C138 8007B938 F4FF4014 */  bnez       $v0, .L8007B90C
    /* 6C13C 8007B93C 00310300 */   sll       $a2, $v1, 4
    /* 6C140 8007B940 7EEE0108 */  j          .L8007B9F8
    /* 6C144 8007B944 21800000 */   addu      $s0, $zero, $zero
  .L8007B948:
    /* 6C148 8007B948 00310300 */  sll        $a2, $v1, 4
    /* 6C14C 8007B94C 0F80023C */  lui        $v0, %hi(D_800F5EF0)
    /* 6C150 8007B950 21104600 */  addu       $v0, $v0, $a2
    /* 6C154 8007B954 F05E428C */  lw         $v0, %lo(D_800F5EF0)($v0)
    /* 6C158 8007B958 00000000 */  nop
    /* 6C15C 8007B95C 11004014 */  bnez       $v0, .L8007B9A4
    /* 6C160 8007B960 21800000 */   addu      $s0, $zero, $zero
    /* 6C164 8007B964 7EEE0108 */  j          .L8007B9F8
    /* 6C168 8007B968 00000000 */   nop
  .L8007B96C:
    /* 6C16C 8007B96C 0F80023C */  lui        $v0, %hi(D_800F5F70)
    /* 6C170 8007B970 705F428C */  lw         $v0, %lo(D_800F5F70)($v0)
    /* 6C174 8007B974 00000000 */  nop
    /* 6C178 8007B978 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 6C17C 8007B97C 03004104 */  bgez       $v0, .L8007B98C
    /* 6C180 8007B980 00310200 */   sll       $a2, $v0, 4
    /* 6C184 8007B984 07000224 */  addiu      $v0, $zero, 0x7
    /* 6C188 8007B988 00310200 */  sll        $a2, $v0, 4
  .L8007B98C:
    /* 6C18C 8007B98C 0F80023C */  lui        $v0, %hi(D_800F5EF0)
    /* 6C190 8007B990 21104600 */  addu       $v0, $v0, $a2
    /* 6C194 8007B994 F05E428C */  lw         $v0, %lo(D_800F5EF0)($v0)
    /* 6C198 8007B998 00000000 */  nop
    /* 6C19C 8007B99C 16004010 */  beqz       $v0, .L8007B9F8
    /* 6C1A0 8007B9A0 21800000 */   addu      $s0, $zero, $zero
  .L8007B9A4:
    /* 6C1A4 8007B9A4 0F80053C */  lui        $a1, %hi(D_800F5DE0)
    /* 6C1A8 8007B9A8 E05DA524 */  addiu      $a1, $a1, %lo(D_800F5DE0)
    /* 6C1AC 8007B9AC 0F80023C */  lui        $v0, %hi(D_800F5EF0)
    /* 6C1B0 8007B9B0 21104600 */  addu       $v0, $v0, $a2
    /* 6C1B4 8007B9B4 F05E428C */  lw         $v0, %lo(D_800F5EF0)($v0)
    /* 6C1B8 8007B9B8 0F80033C */  lui        $v1, %hi(D_800F5EF4)
    /* 6C1BC 8007B9BC 21186600 */  addu       $v1, $v1, $a2
    /* 6C1C0 8007B9C0 F45E638C */  lw         $v1, %lo(D_800F5EF4)($v1)
    /* 6C1C4 8007B9C4 0F80043C */  lui        $a0, %hi(D_800F5EF8)
    /* 6C1C8 8007B9C8 21208600 */  addu       $a0, $a0, $a2
    /* 6C1CC 8007B9CC F85E848C */  lw         $a0, %lo(D_800F5EF8)($a0)
    /* 6C1D0 8007B9D0 0000A2AC */  sw         $v0, 0x0($a1)
    /* 6C1D4 8007B9D4 0400A3AC */  sw         $v1, 0x4($a1)
    /* 6C1D8 8007B9D8 0800A4AC */  sw         $a0, 0x8($a1)
    /* 6C1DC 8007B9DC 0F80023C */  lui        $v0, %hi(D_800F5EFC)
    /* 6C1E0 8007B9E0 21104600 */  addu       $v0, $v0, $a2
    /* 6C1E4 8007B9E4 FC5E428C */  lw         $v0, %lo(D_800F5EFC)($v0)
    /* 6C1E8 8007B9E8 00000000 */  nop
    /* 6C1EC 8007B9EC 0C00A2AC */  sw         $v0, 0xC($a1)
    /* 6C1F0 8007B9F0 0F80103C */  lui        $s0, %hi(D_800F5DE0)
    /* 6C1F4 8007B9F4 E05D1026 */  addiu      $s0, $s0, %lo(D_800F5DE0)
  .L8007B9F8:
    /* 6C1F8 8007B9F8 06000012 */  beqz       $s0, .L8007BA14
    /* 6C1FC 8007B9FC 21202002 */   addu      $a0, $s1, $zero
    /* 6C200 8007BA00 5BF3010C */  jal        func_8007CD6C
    /* 6C204 8007BA04 05000526 */   addiu     $a1, $s0, 0x5
    /* 6C208 8007BA08 04000292 */  lbu        $v0, 0x4($s0)
    /* 6C20C 8007BA0C 86EE0108 */  j          .L8007BA18
    /* 6C210 8007BA10 00000000 */   nop
  .L8007BA14:
    /* 6C214 8007BA14 06000224 */  addiu      $v0, $zero, 0x6
  .L8007BA18:
    /* 6C218 8007BA18 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6C21C 8007BA1C 1400B18F */  lw         $s1, 0x14($sp)
    /* 6C220 8007BA20 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C224 8007BA24 0800E003 */  jr         $ra
    /* 6C228 8007BA28 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007B83C
