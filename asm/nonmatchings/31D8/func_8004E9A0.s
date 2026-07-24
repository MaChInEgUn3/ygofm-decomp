nonmatching func_8004E9A0, 0x160

glabel func_8004E9A0
    /* 3F1A0 8004E9A0 0F80023C */  lui        $v0, %hi(D_800F569F)
    /* 3F1A4 8004E9A4 9F564290 */  lbu        $v0, %lo(D_800F569F)($v0)
    /* 3F1A8 8004E9A8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3F1AC 8004E9AC 50004010 */  beqz       $v0, .L8004EAF0
    /* 3F1B0 8004E9B0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 3F1B4 8004E9B4 8000828F */  lw         $v0, %gp_rel(D_8009AF88)($gp)
    /* 3F1B8 8004E9B8 00000000 */  nop
    /* 3F1BC 8004E9BC A0004390 */  lbu        $v1, 0xA0($v0)
    /* 3F1C0 8004E9C0 01000224 */  addiu      $v0, $zero, 0x1
    /* 3F1C4 8004E9C4 05006210 */  beq        $v1, $v0, .L8004E9DC
    /* 3F1C8 8004E9C8 04000224 */   addiu     $v0, $zero, 0x4
    /* 3F1CC 8004E9CC 1F006210 */  beq        $v1, $v0, .L8004EA4C
    /* 3F1D0 8004E9D0 00000000 */   nop
    /* 3F1D4 8004E9D4 BC3A0108 */  j          .L8004EAF0
    /* 3F1D8 8004E9D8 00000000 */   nop
  .L8004E9DC:
    /* 3F1DC 8004E9DC 5CD0010C */  jal        func_80074170
    /* 3F1E0 8004E9E0 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 3F1E4 8004E9E4 21384000 */  addu       $a3, $v0, $zero
    /* 3F1E8 8004E9E8 0200E104 */  bgez       $a3, .L8004E9F4
    /* 3F1EC 8004E9EC 5555023C */   lui       $v0, (0x55555556 >> 16)
    /* 3F1F0 8004E9F0 0700E724 */  addiu      $a3, $a3, 0x7
  .L8004E9F4:
    /* 3F1F4 8004E9F4 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* 3F1F8 8004E9F8 C3180700 */  sra        $v1, $a3, 3
    /* 3F1FC 8004E9FC 18006200 */  mult       $v1, $v0
    /* 3F200 8004EA00 60058427 */  addiu      $a0, $gp, %gp_rel(D_8009B468)
    /* 3F204 8004EA04 C0010624 */  addiu      $a2, $zero, 0x1C0
    /* 3F208 8004EA08 2110C000 */  addu       $v0, $a2, $zero
    /* 3F20C 8004EA0C 620582A7 */  sh         $v0, %gp_rel(D_8009B46A)($gp)
    /* 3F210 8004EA10 10000224 */  addiu      $v0, $zero, 0x10
    /* 3F214 8004EA14 640582A7 */  sh         $v0, %gp_rel(D_8009B46C)($gp)
    /* 3F218 8004EA18 40000224 */  addiu      $v0, $zero, 0x40
    /* 3F21C 8004EA1C 660582A7 */  sh         $v0, %gp_rel(D_8009B46E)($gp)
    /* 3F220 8004EA20 C3170700 */  sra        $v0, $a3, 31
    /* 3F224 8004EA24 10400000 */  mfhi       $t0
    /* 3F228 8004EA28 23380201 */  subu       $a3, $t0, $v0
    /* 3F22C 8004EA2C 40100700 */  sll        $v0, $a3, 1
    /* 3F230 8004EA30 21104700 */  addu       $v0, $v0, $a3
    /* 3F234 8004EA34 23386200 */  subu       $a3, $v1, $v0
    /* 3F238 8004EA38 00110700 */  sll        $v0, $a3, 4
    /* 3F23C 8004EA3C D0024224 */  addiu      $v0, $v0, 0x2D0
    /* 3F240 8004EA40 600582A7 */  sh         $v0, %gp_rel(D_8009B468)($gp)
    /* 3F244 8004EA44 BA3A0108 */  j          .L8004EAE8
    /* 3F248 8004EA48 C0020524 */   addiu     $a1, $zero, 0x2C0
  .L8004EA4C:
    /* 3F24C 8004EA4C 5CD0010C */  jal        func_80074170
    /* 3F250 8004EA50 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 3F254 8004EA54 6666033C */  lui        $v1, (0x66666667 >> 16)
    /* 3F258 8004EA58 67666334 */  ori        $v1, $v1, (0x66666667 & 0xFFFF)
    /* 3F25C 8004EA5C 18004300 */  mult       $v0, $v1
    /* 3F260 8004EA60 08000424 */  addiu      $a0, $zero, 0x8
    /* 3F264 8004EA64 C3170200 */  sra        $v0, $v0, 31
    /* 3F268 8004EA68 10180000 */  mfhi       $v1
    /* 3F26C 8004EA6C 83180300 */  sra        $v1, $v1, 2
    /* 3F270 8004EA70 23186200 */  subu       $v1, $v1, $v0
    /* 3F274 8004EA74 1A006400 */  div        $zero, $v1, $a0
    /* 3F278 8004EA78 02008014 */  bnez       $a0, .L8004EA84
    /* 3F27C 8004EA7C 00000000 */   nop
    /* 3F280 8004EA80 0D000700 */  break      7
  .L8004EA84:
    /* 3F284 8004EA84 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 3F288 8004EA88 04008114 */  bne        $a0, $at, .L8004EA9C
    /* 3F28C 8004EA8C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 3F290 8004EA90 02006114 */  bne        $v1, $at, .L8004EA9C
    /* 3F294 8004EA94 00000000 */   nop
    /* 3F298 8004EA98 0D000600 */  break      6
  .L8004EA9C:
    /* 3F29C 8004EA9C 10380000 */  mfhi       $a3
    /* 3F2A0 8004EAA0 20020524 */  addiu      $a1, $zero, 0x220
    /* 3F2A4 8004EAA4 68010624 */  addiu      $a2, $zero, 0x168
    /* 3F2A8 8004EAA8 60058427 */  addiu      $a0, $gp, %gp_rel(D_8009B468)
    /* 3F2AC 8004EAAC 60020224 */  addiu      $v0, $zero, 0x260
    /* 3F2B0 8004EAB0 600582A7 */  sh         $v0, %gp_rel(D_8009B468)($gp)
    /* 3F2B4 8004EAB4 0980023C */  lui        $v0, %hi(D_80091508)
    /* 3F2B8 8004EAB8 08154224 */  addiu      $v0, $v0, %lo(D_80091508)
    /* 3F2BC 8004EABC 2138E200 */  addu       $a3, $a3, $v0
    /* 3F2C0 8004EAC0 0000E390 */  lbu        $v1, 0x0($a3)
    /* 3F2C4 8004EAC4 20000224 */  addiu      $v0, $zero, 0x20
    /* 3F2C8 8004EAC8 640582A7 */  sh         $v0, %gp_rel(D_8009B46C)($gp)
    /* 3F2CC 8004EACC 18000224 */  addiu      $v0, $zero, 0x18
    /* 3F2D0 8004EAD0 660582A7 */  sh         $v0, %gp_rel(D_8009B46E)($gp)
    /* 3F2D4 8004EAD4 40100300 */  sll        $v0, $v1, 1
    /* 3F2D8 8004EAD8 21104300 */  addu       $v0, $v0, $v1
    /* 3F2DC 8004EADC C0100200 */  sll        $v0, $v0, 3
    /* 3F2E0 8004EAE0 80014224 */  addiu      $v0, $v0, 0x180
    /* 3F2E4 8004EAE4 620582A7 */  sh         $v0, %gp_rel(D_8009B46A)($gp)
  .L8004EAE8:
    /* 3F2E8 8004EAE8 8EFE010C */  jal        func_8007FA38
    /* 3F2EC 8004EAEC 00000000 */   nop
  .L8004EAF0:
    /* 3F2F0 8004EAF0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3F2F4 8004EAF4 00000000 */  nop
    /* 3F2F8 8004EAF8 0800E003 */  jr         $ra
    /* 3F2FC 8004EAFC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004E9A0
