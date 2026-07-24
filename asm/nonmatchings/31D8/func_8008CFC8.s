nonmatching func_8008CFC8, 0xAC

glabel func_8008CFC8
    /* 7D7C8 8008CFC8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7D7CC 8008CFCC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7D7D0 8008CFD0 7234020C */  jal        func_8008D1C8
    /* 7D7D4 8008CFD4 00000000 */   nop
    /* 7D7D8 8008CFD8 18004014 */  bnez       $v0, .L8008D03C
    /* 7D7DC 8008CFDC 00000000 */   nop
    /* 7D7E0 8008CFE0 5734020C */  jal        func_8008D15C
    /* 7D7E4 8008CFE4 00000000 */   nop
    /* 7D7E8 8008CFE8 7234020C */  jal        func_8008D1C8
    /* 7D7EC 8008CFEC 00000000 */   nop
    /* 7D7F0 8008CFF0 12004010 */  beqz       $v0, .L8008D03C
    /* 7D7F4 8008CFF4 01000224 */   addiu     $v0, $zero, 0x1
    /* 7D7F8 8008CFF8 1080033C */  lui        $v1, %hi(D_800FE348)
    /* 7D7FC 8008CFFC 48E36324 */  addiu      $v1, $v1, %lo(D_800FE348)
    /* 7D800 8008D000 080062AC */  sw         $v0, 0x8($v1)
    /* 7D804 8008D004 0000628C */  lw         $v0, 0x0($v1)
    /* 7D808 8008D008 1080053C */  lui        $a1, %hi(D_800FE338)
    /* 7D80C 8008D00C 38E3A524 */  addiu      $a1, $a1, %lo(D_800FE338)
    /* 7D810 8008D010 0000A2AC */  sw         $v0, 0x0($a1)
    /* 7D814 8008D014 0400628C */  lw         $v0, 0x4($v1)
    /* 7D818 8008D018 4400668C */  lw         $a2, 0x44($v1)
    /* 7D81C 8008D01C 0400A2AC */  sw         $v0, 0x4($a1)
    /* 7D820 8008D020 000060AC */  sw         $zero, 0x0($v1)
    /* 7D824 8008D024 0500C010 */  beqz       $a2, .L8008D03C
    /* 7D828 8008D028 040060AC */   sw        $zero, 0x4($v1)
    /* 7D82C 8008D02C 0000A48C */  lw         $a0, 0x0($a1)
    /* 7D830 8008D030 0400A58C */  lw         $a1, 0x4($a1)
    /* 7D834 8008D034 09F8C000 */  jalr       $a2
    /* 7D838 8008D038 00000000 */   nop
  .L8008D03C:
    /* 7D83C 8008D03C 1080023C */  lui        $v0, %hi(D_800FE348)
    /* 7D840 8008D040 48E34224 */  addiu      $v0, $v0, %lo(D_800FE348)
    /* 7D844 8008D044 5000438C */  lw         $v1, 0x50($v0)
    /* 7D848 8008D048 00000000 */  nop
    /* 7D84C 8008D04C 01006324 */  addiu      $v1, $v1, 0x1
    /* 7D850 8008D050 500043AC */  sw         $v1, 0x50($v0)
    /* 7D854 8008D054 5400438C */  lw         $v1, 0x54($v0)
    /* 7D858 8008D058 00000000 */  nop
    /* 7D85C 8008D05C 01006324 */  addiu      $v1, $v1, 0x1
    /* 7D860 8008D060 540043AC */  sw         $v1, 0x54($v0)
    /* 7D864 8008D064 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7D868 8008D068 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7D86C 8008D06C 0800E003 */  jr         $ra
    /* 7D870 8008D070 00000000 */   nop
endlabel func_8008CFC8
