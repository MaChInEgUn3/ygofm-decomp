nonmatching func_8004A940, 0x1BC

glabel func_8004A940
    /* 3B140 8004A940 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3B144 8004A944 21488000 */  addu       $t1, $a0, $zero
    /* 3B148 8004A948 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3B14C 8004A94C 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3B150 8004A950 FFFF0A24 */  addiu      $t2, $zero, -0x1
    /* 3B154 8004A954 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3B158 8004A958 10056284 */  lh         $v0, 0x510($v1)
    /* 3B15C 8004A95C 00000000 */  nop
    /* 3B160 8004A960 0B004018 */  blez       $v0, .L8004A990
    /* 3B164 8004A964 21200000 */   addu      $a0, $zero, $zero
    /* 3B168 8004A968 63000724 */  addiu      $a3, $zero, 0x63
    /* 3B16C 8004A96C 21304000 */  addu       $a2, $v0, $zero
  .L8004A970:
    /* 3B170 8004A970 83016290 */  lbu        $v0, 0x183($v1)
    /* 3B174 8004A974 00000000 */  nop
    /* 3B178 8004A978 5C004710 */  beq        $v0, $a3, .L8004AAEC
    /* 3B17C 8004A97C 21108000 */   addu      $v0, $a0, $zero
    /* 3B180 8004A980 01008424 */  addiu      $a0, $a0, 0x1
    /* 3B184 8004A984 2A108600 */  slt        $v0, $a0, $a2
    /* 3B188 8004A988 F9FF4014 */  bnez       $v0, .L8004A970
    /* 3B18C 8004A98C 28006324 */   addiu     $v1, $v1, 0x28
  .L8004A990:
    /* 3B190 8004A990 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3B194 8004A994 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3B198 8004A998 00000000 */  nop
    /* 3B19C 8004A99C 10056284 */  lh         $v0, 0x510($v1)
    /* 3B1A0 8004A9A0 00000000 */  nop
    /* 3B1A4 8004A9A4 0E004018 */  blez       $v0, .L8004A9E0
    /* 3B1A8 8004A9A8 21200000 */   addu      $a0, $zero, $zero
    /* 3B1AC 8004A9AC 21304000 */  addu       $a2, $v0, $zero
  .L8004A9B0:
    /* 3B1B0 8004A9B0 8D016290 */  lbu        $v0, 0x18D($v1)
    /* 3B1B4 8004A9B4 00000000 */  nop
    /* 3B1B8 8004A9B8 49004010 */  beqz       $v0, .L8004AAE0
    /* 3B1BC 8004A9BC 00000000 */   nop
    /* 3B1C0 8004A9C0 01008424 */  addiu      $a0, $a0, 0x1
    /* 3B1C4 8004A9C4 2A108600 */  slt        $v0, $a0, $a2
    /* 3B1C8 8004A9C8 F9FF4014 */  bnez       $v0, .L8004A9B0
    /* 3B1CC 8004A9CC 28006324 */   addiu     $v1, $v1, 0x28
    /* 3B1D0 8004A9D0 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3B1D4 8004A9D4 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3B1D8 8004A9D8 00000000 */  nop
    /* 3B1DC 8004A9DC 10056284 */  lh         $v0, 0x510($v1)
  .L8004A9E0:
    /* 3B1E0 8004A9E0 00000000 */  nop
    /* 3B1E4 8004A9E4 15004018 */  blez       $v0, .L8004AA3C
    /* 3B1E8 8004A9E8 21200000 */   addu      $a0, $zero, $zero
    /* 3B1EC 8004A9EC FF002831 */  andi       $t0, $t1, 0xFF
    /* 3B1F0 8004A9F0 FF00A730 */  andi       $a3, $a1, 0xFF
    /* 3B1F4 8004A9F4 21308000 */  addu       $a2, $a0, $zero
  .L8004A9F8:
    /* 3B1F8 8004A9F8 21106600 */  addu       $v0, $v1, $a2
    /* 3B1FC 8004A9FC 83014590 */  lbu        $a1, 0x183($v0)
    /* 3B200 8004AA00 00000000 */  nop
    /* 3B204 8004AA04 0500A814 */  bne        $a1, $t0, .L8004AA1C
    /* 3B208 8004AA08 00000000 */   nop
    /* 3B20C 8004AA0C 85014290 */  lbu        $v0, 0x185($v0)
    /* 3B210 8004AA10 00000000 */  nop
    /* 3B214 8004AA14 33004710 */  beq        $v0, $a3, .L8004AAE4
    /* 3B218 8004AA18 00000000 */   nop
  .L8004AA1C:
    /* 3B21C 8004AA1C 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3B220 8004AA20 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3B224 8004AA24 00000000 */  nop
    /* 3B228 8004AA28 10056284 */  lh         $v0, 0x510($v1)
    /* 3B22C 8004AA2C 01008424 */  addiu      $a0, $a0, 0x1
    /* 3B230 8004AA30 2A108200 */  slt        $v0, $a0, $v0
    /* 3B234 8004AA34 F0FF4014 */  bnez       $v0, .L8004A9F8
    /* 3B238 8004AA38 2800C624 */   addiu     $a2, $a2, 0x28
  .L8004AA3C:
    /* 3B23C 8004AA3C 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3B240 8004AA40 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3B244 8004AA44 00000000 */  nop
    /* 3B248 8004AA48 10056284 */  lh         $v0, 0x510($v1)
    /* 3B24C 8004AA4C 00000000 */  nop
    /* 3B250 8004AA50 0C004018 */  blez       $v0, .L8004AA84
    /* 3B254 8004AA54 21200000 */   addu      $a0, $zero, $zero
    /* 3B258 8004AA58 21284000 */  addu       $a1, $v0, $zero
  .L8004AA5C:
    /* 3B25C 8004AA5C 8D016290 */  lbu        $v0, 0x18D($v1)
    /* 3B260 8004AA60 00000000 */  nop
    /* 3B264 8004AA64 1E004010 */  beqz       $v0, .L8004AAE0
    /* 3B268 8004AA68 00000000 */   nop
    /* 3B26C 8004AA6C 01008424 */  addiu      $a0, $a0, 0x1
    /* 3B270 8004AA70 2A108500 */  slt        $v0, $a0, $a1
    /* 3B274 8004AA74 F9FF4014 */  bnez       $v0, .L8004AA5C
    /* 3B278 8004AA78 28006324 */   addiu     $v1, $v1, 0x28
    /* 3B27C 8004AA7C 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3B280 8004AA80 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
  .L8004AA84:
    /* 3B284 8004AA84 FFFF0634 */  ori        $a2, $zero, 0xFFFF
    /* 3B288 8004AA88 10056284 */  lh         $v0, 0x510($v1)
    /* 3B28C 8004AA8C 00000000 */  nop
    /* 3B290 8004AA90 0E004018 */  blez       $v0, .L8004AACC
    /* 3B294 8004AA94 21200000 */   addu      $a0, $zero, $zero
    /* 3B298 8004AA98 21384000 */  addu       $a3, $v0, $zero
    /* 3B29C 8004AA9C 21286000 */  addu       $a1, $v1, $zero
  .L8004AAA0:
    /* 3B2A0 8004AAA0 9E01A394 */  lhu        $v1, 0x19E($a1)
    /* 3B2A4 8004AAA4 00000000 */  nop
    /* 3B2A8 8004AAA8 2B106600 */  sltu       $v0, $v1, $a2
    /* 3B2AC 8004AAAC 03004010 */  beqz       $v0, .L8004AABC
    /* 3B2B0 8004AAB0 00000000 */   nop
    /* 3B2B4 8004AAB4 21306000 */  addu       $a2, $v1, $zero
    /* 3B2B8 8004AAB8 21508000 */  addu       $t2, $a0, $zero
  .L8004AABC:
    /* 3B2BC 8004AABC 01008424 */  addiu      $a0, $a0, 0x1
    /* 3B2C0 8004AAC0 2A108700 */  slt        $v0, $a0, $a3
    /* 3B2C4 8004AAC4 F6FF4014 */  bnez       $v0, .L8004AAA0
    /* 3B2C8 8004AAC8 2800A524 */   addiu     $a1, $a1, 0x28
  .L8004AACC:
    /* 3B2CC 8004AACC FEFF0234 */  ori        $v0, $zero, 0xFFFE
    /* 3B2D0 8004AAD0 2B104600 */  sltu       $v0, $v0, $a2
    /* 3B2D4 8004AAD4 05004014 */  bnez       $v0, .L8004AAEC
    /* 3B2D8 8004AAD8 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3B2DC 8004AADC 21204001 */  addu       $a0, $t2, $zero
  .L8004AAE0:
    /* 3B2E0 8004AAE0 FF002531 */  andi       $a1, $t1, 0xFF
  .L8004AAE4:
    /* 3B2E4 8004AAE4 392A010C */  jal        func_8004A8E4
    /* 3B2E8 8004AAE8 00000000 */   nop
  .L8004AAEC:
    /* 3B2EC 8004AAEC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3B2F0 8004AAF0 00000000 */  nop
    /* 3B2F4 8004AAF4 0800E003 */  jr         $ra
    /* 3B2F8 8004AAF8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004A940
