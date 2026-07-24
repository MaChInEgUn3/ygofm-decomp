nonmatching func_8008C16C, 0xB8

glabel func_8008C16C
    /* 7C96C 8008C16C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7C970 8008C170 1080073C */  lui        $a3, %hi(D_800FE35C)
    /* 7C974 8008C174 5CE3E724 */  addiu      $a3, $a3, %lo(D_800FE35C)
    /* 7C978 8008C178 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7C97C 8008C17C 0000E28C */  lw         $v0, 0x0($a3)
    /* 7C980 8008C180 00000000 */  nop
    /* 7C984 8008C184 04004104 */  bgez       $v0, .L8008C198
    /* 7C988 8008C188 21408000 */   addu      $t0, $a0, $zero
    /* 7C98C 8008C18C 0180043C */  lui        $a0, %hi(D_8001259C)
    /* 7C990 8008C190 82300208 */  j          .L8008C208
    /* 7C994 8008C194 9C258424 */   addiu     $a0, $a0, %lo(D_8001259C)
  .L8008C198:
    /* 7C998 8008C198 ECFFE28C */  lw         $v0, -0x14($a3)
    /* 7C99C 8008C19C 00000000 */  nop
    /* 7C9A0 8008C1A0 04004018 */  blez       $v0, .L8008C1B4
    /* 7C9A4 8008C1A4 ECFFE324 */   addiu     $v1, $a3, -0x14
    /* 7C9A8 8008C1A8 0180043C */  lui        $a0, %hi(D_80012478)
    /* 7C9AC 8008C1AC 82300208 */  j          .L8008C208
    /* 7C9B0 8008C1B0 78248424 */   addiu     $a0, $a0, %lo(D_80012478)
  .L8008C1B4:
    /* 7C9B4 8008C1B4 7F00C230 */  andi       $v0, $a2, 0x7F
    /* 7C9B8 8008C1B8 04004010 */  beqz       $v0, .L8008C1CC
    /* 7C9BC 8008C1BC 7F00A230 */   andi      $v0, $a1, 0x7F
    /* 7C9C0 8008C1C0 0180043C */  lui        $a0, %hi(D_800125C0)
    /* 7C9C4 8008C1C4 82300208 */  j          .L8008C208
    /* 7C9C8 8008C1C8 C0258424 */   addiu     $a0, $a0, %lo(D_800125C0)
  .L8008C1CC:
    /* 7C9CC 8008C1CC 0C004014 */  bnez       $v0, .L8008C200
    /* 7C9D0 8008C1D0 05000224 */   addiu     $v0, $zero, 0x5
    /* 7C9D4 8008C1D4 0980043C */  lui        $a0, %hi(func_8008C224)
    /* 7C9D8 8008C1D8 24C28424 */  addiu      $a0, $a0, %lo(func_8008C224)
    /* 7C9DC 8008C1DC ECFFE2AC */  sw         $v0, -0x14($a3)
    /* 7C9E0 8008C1E0 040060AC */  sw         $zero, 0x4($v1)
    /* 7C9E4 8008C1E4 080060AC */  sw         $zero, 0x8($v1)
    /* 7C9E8 8008C1E8 180065AC */  sw         $a1, 0x18($v1)
    /* 7C9EC 8008C1EC 200068AC */  sw         $t0, 0x20($v1)
    /* 7C9F0 8008C1F0 3834020C */  jal        func_8008D0E0
    /* 7C9F4 8008C1F4 1C0066AC */   sw        $a2, 0x1C($v1)
    /* 7C9F8 8008C1F8 85300208 */  j          .L8008C214
    /* 7C9FC 8008C1FC 01000224 */   addiu     $v0, $zero, 0x1
  .L8008C200:
    /* 7CA00 8008C200 0180043C */  lui        $a0, %hi(D_800125EC)
    /* 7CA04 8008C204 EC258424 */  addiu      $a0, $a0, %lo(D_800125EC)
  .L8008C208:
    /* 7CA08 8008C208 1C3A020C */  jal        func_8008E870
    /* 7CA0C 8008C20C 00000000 */   nop
    /* 7CA10 8008C210 21100000 */  addu       $v0, $zero, $zero
  .L8008C214:
    /* 7CA14 8008C214 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7CA18 8008C218 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7CA1C 8008C21C 0800E003 */  jr         $ra
    /* 7CA20 8008C220 00000000 */   nop
endlabel func_8008C16C
