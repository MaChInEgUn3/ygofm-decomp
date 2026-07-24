nonmatching func_8008F0D8, 0x128

glabel func_8008F0D8
    /* 7F8D8 8008F0D8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7F8DC 8008F0DC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7F8E0 8008F0E0 21808000 */  addu       $s0, $a0, $zero
    /* 7F8E4 8008F0E4 00260400 */  sll        $a0, $a0, 24
    /* 7F8E8 8008F0E8 03260400 */  sra        $a0, $a0, 24
    /* 7F8EC 8008F0EC 09000224 */  addiu      $v0, $zero, 0x9
    /* 7F8F0 8008F0F0 09008210 */  beq        $a0, $v0, .L8008F118
    /* 7F8F4 8008F0F4 1400BFAF */   sw        $ra, 0x14($sp)
    /* 7F8F8 8008F0F8 0A000224 */  addiu      $v0, $zero, 0xA
    /* 7F8FC 8008F0FC 10008214 */  bne        $a0, $v0, .L8008F140
    /* 7F900 8008F100 FF000232 */   andi      $v0, $s0, 0xFF
    /* 7F904 8008F104 E83B020C */  jal        func_8008EFA0
    /* 7F908 8008F108 0D000424 */   addiu     $a0, $zero, 0xD
    /* 7F90C 8008F10C 0A80013C */  lui        $at, %hi(D_80099EB8)
    /* 7F910 8008F110 5D3C0208 */  j          .L8008F174
    /* 7F914 8008F114 B89E20AC */   sw        $zero, %lo(D_80099EB8)($at)
  .L8008F118:
    /* 7F918 8008F118 E83B020C */  jal        func_8008EFA0
    /* 7F91C 8008F11C 20000424 */   addiu     $a0, $zero, 0x20
    /* 7F920 8008F120 0A80023C */  lui        $v0, %hi(D_80099EB8)
    /* 7F924 8008F124 B89E428C */  lw         $v0, %lo(D_80099EB8)($v0)
    /* 7F928 8008F128 00000000 */  nop
    /* 7F92C 8008F12C 07004230 */  andi       $v0, $v0, 0x7
    /* 7F930 8008F130 24004010 */  beqz       $v0, .L8008F1C4
    /* 7F934 8008F134 00000000 */   nop
    /* 7F938 8008F138 463C0208 */  j          .L8008F118
    /* 7F93C 8008F13C 00000000 */   nop
  .L8008F140:
    /* 7F940 8008F140 0A80013C */  lui        $at, %hi(D_80099EE9)
    /* 7F944 8008F144 21082200 */  addu       $at, $at, $v0
    /* 7F948 8008F148 E99E2280 */  lb         $v0, %lo(D_80099EE9)($at)
    /* 7F94C 8008F14C 00000000 */  nop
    /* 7F950 8008F150 97004230 */  andi       $v0, $v0, 0x97
    /* 7F954 8008F154 07004010 */  beqz       $v0, .L8008F174
    /* 7F958 8008F158 00000000 */   nop
    /* 7F95C 8008F15C 0A80023C */  lui        $v0, %hi(D_80099EB8)
    /* 7F960 8008F160 B89E428C */  lw         $v0, %lo(D_80099EB8)($v0)
    /* 7F964 8008F164 00000000 */  nop
    /* 7F968 8008F168 01004224 */  addiu      $v0, $v0, 0x1
    /* 7F96C 8008F16C 0A80013C */  lui        $at, %hi(D_80099EB8)
    /* 7F970 8008F170 B89E22AC */  sw         $v0, %lo(D_80099EB8)($at)
  .L8008F174:
    /* 7F974 8008F174 0A80063C */  lui        $a2, %hi(D_80099EBC)
    /* 7F978 8008F178 BC9EC68C */  lw         $a2, %lo(D_80099EBC)($a2)
    /* 7F97C 8008F17C 00000000 */  nop
    /* 7F980 8008F180 2000C228 */  slti       $v0, $a2, 0x20
    /* 7F984 8008F184 07004014 */  bnez       $v0, .L8008F1A4
    /* 7F988 8008F188 00000000 */   nop
    /* 7F98C 8008F18C 1080053C */  lui        $a1, %hi(D_800FE708)
    /* 7F990 8008F190 08E7A524 */  addiu      $a1, $a1, %lo(D_800FE708)
    /* 7F994 8008F194 40CE010C */  jal        func_80073900
    /* 7F998 8008F198 01000424 */   addiu     $a0, $zero, 0x1
    /* 7F99C 8008F19C 0A80013C */  lui        $at, %hi(D_80099EBC)
    /* 7F9A0 8008F1A0 BC9E20AC */  sw         $zero, %lo(D_80099EBC)($at)
  .L8008F1A4:
    /* 7F9A4 8008F1A4 0A80023C */  lui        $v0, %hi(D_80099EBC)
    /* 7F9A8 8008F1A8 BC9E428C */  lw         $v0, %lo(D_80099EBC)($v0)
    /* 7F9AC 8008F1AC 1080013C */  lui        $at, %hi(D_800FE708)
    /* 7F9B0 8008F1B0 21082200 */  addu       $at, $at, $v0
    /* 7F9B4 8008F1B4 08E730A0 */  sb         $s0, %lo(D_800FE708)($at)
    /* 7F9B8 8008F1B8 01004224 */  addiu      $v0, $v0, 0x1
    /* 7F9BC 8008F1BC 0A80013C */  lui        $at, %hi(D_80099EBC)
    /* 7F9C0 8008F1C0 BC9E22AC */  sw         $v0, %lo(D_80099EBC)($at)
  .L8008F1C4:
    /* 7F9C4 8008F1C4 0A80063C */  lui        $a2, %hi(D_80099EBC)
    /* 7F9C8 8008F1C8 BC9EC68C */  lw         $a2, %lo(D_80099EBC)($a2)
    /* 7F9CC 8008F1CC 00000000 */  nop
    /* 7F9D0 8008F1D0 0700C018 */  blez       $a2, .L8008F1F0
    /* 7F9D4 8008F1D4 00000000 */   nop
    /* 7F9D8 8008F1D8 1080053C */  lui        $a1, %hi(D_800FE708)
    /* 7F9DC 8008F1DC 08E7A524 */  addiu      $a1, $a1, %lo(D_800FE708)
    /* 7F9E0 8008F1E0 40CE010C */  jal        func_80073900
    /* 7F9E4 8008F1E4 01000424 */   addiu     $a0, $zero, 0x1
    /* 7F9E8 8008F1E8 0A80013C */  lui        $at, %hi(D_80099EBC)
    /* 7F9EC 8008F1EC BC9E20AC */  sw         $zero, %lo(D_80099EBC)($at)
  .L8008F1F0:
    /* 7F9F0 8008F1F0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7F9F4 8008F1F4 1000B08F */  lw         $s0, 0x10($sp)
    /* 7F9F8 8008F1F8 0800E003 */  jr         $ra
    /* 7F9FC 8008F1FC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008F0D8
