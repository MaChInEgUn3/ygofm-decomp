nonmatching func_8008EFA0, 0xFC

glabel func_8008EFA0
    /* 7F7A0 8008EFA0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7F7A4 8008EFA4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7F7A8 8008EFA8 21808000 */  addu       $s0, $a0, $zero
    /* 7F7AC 8008EFAC 00260400 */  sll        $a0, $a0, 24
    /* 7F7B0 8008EFB0 03260400 */  sra        $a0, $a0, 24
    /* 7F7B4 8008EFB4 09000224 */  addiu      $v0, $zero, 0x9
    /* 7F7B8 8008EFB8 09008210 */  beq        $a0, $v0, .L8008EFE0
    /* 7F7BC 8008EFBC 1400BFAF */   sw        $ra, 0x14($sp)
    /* 7F7C0 8008EFC0 0A000224 */  addiu      $v0, $zero, 0xA
    /* 7F7C4 8008EFC4 10008214 */  bne        $a0, $v0, .L8008F008
    /* 7F7C8 8008EFC8 FF000232 */   andi      $v0, $s0, 0xFF
    /* 7F7CC 8008EFCC E83B020C */  jal        func_8008EFA0
    /* 7F7D0 8008EFD0 0D000424 */   addiu     $a0, $zero, 0xD
    /* 7F7D4 8008EFD4 0A80013C */  lui        $at, %hi(D_80099EB8)
    /* 7F7D8 8008EFD8 0F3C0208 */  j          .L8008F03C
    /* 7F7DC 8008EFDC B89E20AC */   sw        $zero, %lo(D_80099EB8)($at)
  .L8008EFE0:
    /* 7F7E0 8008EFE0 E83B020C */  jal        func_8008EFA0
    /* 7F7E4 8008EFE4 20000424 */   addiu     $a0, $zero, 0x20
    /* 7F7E8 8008EFE8 0A80023C */  lui        $v0, %hi(D_80099EB8)
    /* 7F7EC 8008EFEC B89E428C */  lw         $v0, %lo(D_80099EB8)($v0)
    /* 7F7F0 8008EFF0 00000000 */  nop
    /* 7F7F4 8008EFF4 07004230 */  andi       $v0, $v0, 0x7
    /* 7F7F8 8008EFF8 24004010 */  beqz       $v0, .L8008F08C
    /* 7F7FC 8008EFFC 00000000 */   nop
    /* 7F800 8008F000 F83B0208 */  j          .L8008EFE0
    /* 7F804 8008F004 00000000 */   nop
  .L8008F008:
    /* 7F808 8008F008 0A80013C */  lui        $at, %hi(D_80099EE9)
    /* 7F80C 8008F00C 21082200 */  addu       $at, $at, $v0
    /* 7F810 8008F010 E99E2280 */  lb         $v0, %lo(D_80099EE9)($at)
    /* 7F814 8008F014 00000000 */  nop
    /* 7F818 8008F018 97004230 */  andi       $v0, $v0, 0x97
    /* 7F81C 8008F01C 07004010 */  beqz       $v0, .L8008F03C
    /* 7F820 8008F020 00000000 */   nop
    /* 7F824 8008F024 0A80023C */  lui        $v0, %hi(D_80099EB8)
    /* 7F828 8008F028 B89E428C */  lw         $v0, %lo(D_80099EB8)($v0)
    /* 7F82C 8008F02C 00000000 */  nop
    /* 7F830 8008F030 01004224 */  addiu      $v0, $v0, 0x1
    /* 7F834 8008F034 0A80013C */  lui        $at, %hi(D_80099EB8)
    /* 7F838 8008F038 B89E22AC */  sw         $v0, %lo(D_80099EB8)($at)
  .L8008F03C:
    /* 7F83C 8008F03C 0A80063C */  lui        $a2, %hi(D_80099EBC)
    /* 7F840 8008F040 BC9EC68C */  lw         $a2, %lo(D_80099EBC)($a2)
    /* 7F844 8008F044 00000000 */  nop
    /* 7F848 8008F048 2000C228 */  slti       $v0, $a2, 0x20
    /* 7F84C 8008F04C 07004014 */  bnez       $v0, .L8008F06C
    /* 7F850 8008F050 00000000 */   nop
    /* 7F854 8008F054 1080053C */  lui        $a1, %hi(D_800FE708)
    /* 7F858 8008F058 08E7A524 */  addiu      $a1, $a1, %lo(D_800FE708)
    /* 7F85C 8008F05C 40CE010C */  jal        func_80073900
    /* 7F860 8008F060 01000424 */   addiu     $a0, $zero, 0x1
    /* 7F864 8008F064 0A80013C */  lui        $at, %hi(D_80099EBC)
    /* 7F868 8008F068 BC9E20AC */  sw         $zero, %lo(D_80099EBC)($at)
  .L8008F06C:
    /* 7F86C 8008F06C 0A80033C */  lui        $v1, %hi(D_80099EBC)
    /* 7F870 8008F070 BC9E6324 */  addiu      $v1, $v1, %lo(D_80099EBC)
    /* 7F874 8008F074 0000628C */  lw         $v0, 0x0($v1)
    /* 7F878 8008F078 1080013C */  lui        $at, %hi(D_800FE708)
    /* 7F87C 8008F07C 21082200 */  addu       $at, $at, $v0
    /* 7F880 8008F080 08E730A0 */  sb         $s0, %lo(D_800FE708)($at)
    /* 7F884 8008F084 01004224 */  addiu      $v0, $v0, 0x1
    /* 7F888 8008F088 000062AC */  sw         $v0, 0x0($v1)
  .L8008F08C:
    /* 7F88C 8008F08C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7F890 8008F090 1000B08F */  lw         $s0, 0x10($sp)
    /* 7F894 8008F094 0800E003 */  jr         $ra
    /* 7F898 8008F098 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008EFA0
