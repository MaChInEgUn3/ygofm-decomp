nonmatching func_8002EA0C, 0x13C

glabel func_8002EA0C
    /* 1F20C 8002EA0C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1F210 8002EA10 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1F214 8002EA14 EDB8000C */  jal        func_8002E3B4
    /* 1F218 8002EA18 00000000 */   nop
    /* 1F21C 8002EA1C 2B004014 */  bnez       $v0, .L8002EACC
    /* 1F220 8002EA20 00000000 */   nop
    /* 1F224 8002EA24 0A80063C */  lui        $a2, %hi(D_8009B146)
    /* 1F228 8002EA28 46B1C684 */  lh         $a2, %lo(D_8009B146)($a2)
    /* 1F22C 8002EA2C A0038387 */  lh         $v1, %gp_rel(D_8009B2A8)($gp)
    /* 1F230 8002EA30 94038487 */  lh         $a0, %gp_rel(D_8009B29C)($gp)
    /* 1F234 8002EA34 23186600 */  subu       $v1, $v1, $a2
    /* 1F238 8002EA38 001C0300 */  sll        $v1, $v1, 16
    /* 1F23C 8002EA3C 1A006400 */  div        $zero, $v1, $a0
    /* 1F240 8002EA40 02008014 */  bnez       $a0, .L8002EA4C
    /* 1F244 8002EA44 00000000 */   nop
    /* 1F248 8002EA48 0D000700 */  break      7
  .L8002EA4C:
    /* 1F24C 8002EA4C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 1F250 8002EA50 04008114 */  bne        $a0, $at, .L8002EA64
    /* 1F254 8002EA54 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 1F258 8002EA58 02006114 */  bne        $v1, $at, .L8002EA64
    /* 1F25C 8002EA5C 00000000 */   nop
    /* 1F260 8002EA60 0D000600 */  break      6
  .L8002EA64:
    /* 1F264 8002EA64 12180000 */  mflo       $v1
    /* 1F268 8002EA68 0A80053C */  lui        $a1, %hi(D_8009B148)
    /* 1F26C 8002EA6C 48B1A584 */  lh         $a1, %lo(D_8009B148)($a1)
    /* 1F270 8002EA70 A2038287 */  lh         $v0, %gp_rel(D_8009B2AA)($gp)
    /* 1F274 8002EA74 00000000 */  nop
    /* 1F278 8002EA78 23104500 */  subu       $v0, $v0, $a1
    /* 1F27C 8002EA7C 00140200 */  sll        $v0, $v0, 16
    /* 1F280 8002EA80 1A004400 */  div        $zero, $v0, $a0
    /* 1F284 8002EA84 02008014 */  bnez       $a0, .L8002EA90
    /* 1F288 8002EA88 00000000 */   nop
    /* 1F28C 8002EA8C 0D000700 */  break      7
  .L8002EA90:
    /* 1F290 8002EA90 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 1F294 8002EA94 04008114 */  bne        $a0, $at, .L8002EAA8
    /* 1F298 8002EA98 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 1F29C 8002EA9C 02004114 */  bne        $v0, $at, .L8002EAA8
    /* 1F2A0 8002EAA0 00000000 */   nop
    /* 1F2A4 8002EAA4 0D000600 */  break      6
  .L8002EAA8:
    /* 1F2A8 8002EAA8 12100000 */  mflo       $v0
    /* 1F2AC 8002EAAC 00340600 */  sll        $a2, $a2, 16
    /* 1F2B0 8002EAB0 0080C634 */  ori        $a2, $a2, 0x8000
    /* 1F2B4 8002EAB4 7C0386AF */  sw         $a2, %gp_rel(D_8009B284)($gp)
    /* 1F2B8 8002EAB8 002C0500 */  sll        $a1, $a1, 16
    /* 1F2BC 8002EABC 0080A534 */  ori        $a1, $a1, 0x8000
    /* 1F2C0 8002EAC0 800385AF */  sw         $a1, %gp_rel(D_8009B288)($gp)
    /* 1F2C4 8002EAC4 8C0383AF */  sw         $v1, %gp_rel(D_8009B294)($gp)
    /* 1F2C8 8002EAC8 900382AF */  sw         $v0, %gp_rel(D_8009B298)($gp)
  .L8002EACC:
    /* 1F2CC 8002EACC 7C03828F */  lw         $v0, %gp_rel(D_8009B284)($gp)
    /* 1F2D0 8002EAD0 8C03848F */  lw         $a0, %gp_rel(D_8009B294)($gp)
    /* 1F2D4 8002EAD4 8003838F */  lw         $v1, %gp_rel(D_8009B288)($gp)
    /* 1F2D8 8002EAD8 9003858F */  lw         $a1, %gp_rel(D_8009B298)($gp)
    /* 1F2DC 8002EADC 21104400 */  addu       $v0, $v0, $a0
    /* 1F2E0 8002EAE0 7C0382AF */  sw         $v0, %gp_rel(D_8009B284)($gp)
    /* 1F2E4 8002EAE4 03140200 */  sra        $v0, $v0, 16
    /* 1F2E8 8002EAE8 0A80013C */  lui        $at, %hi(D_8009B146)
    /* 1F2EC 8002EAEC 46B122A4 */  sh         $v0, %lo(D_8009B146)($at)
    /* 1F2F0 8002EAF0 94038297 */  lhu        $v0, %gp_rel(D_8009B29C)($gp)
    /* 1F2F4 8002EAF4 21186500 */  addu       $v1, $v1, $a1
    /* 1F2F8 8002EAF8 800383AF */  sw         $v1, %gp_rel(D_8009B288)($gp)
    /* 1F2FC 8002EAFC 031C0300 */  sra        $v1, $v1, 16
    /* 1F300 8002EB00 0A80013C */  lui        $at, %hi(D_8009B148)
    /* 1F304 8002EB04 48B123A4 */  sh         $v1, %lo(D_8009B148)($at)
    /* 1F308 8002EB08 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1F30C 8002EB0C 940382A7 */  sh         $v0, %gp_rel(D_8009B29C)($gp)
    /* 1F310 8002EB10 00140200 */  sll        $v0, $v0, 16
    /* 1F314 8002EB14 0800401C */  bgtz       $v0, .L8002EB38
    /* 1F318 8002EB18 00000000 */   nop
    /* 1F31C 8002EB1C A0038297 */  lhu        $v0, %gp_rel(D_8009B2A8)($gp)
    /* 1F320 8002EB20 A2038397 */  lhu        $v1, %gp_rel(D_8009B2AA)($gp)
    /* 1F324 8002EB24 740380A7 */  sh         $zero, %gp_rel(D_8009B27C)($gp)
    /* 1F328 8002EB28 0A80013C */  lui        $at, %hi(D_8009B146)
    /* 1F32C 8002EB2C 46B122A4 */  sh         $v0, %lo(D_8009B146)($at)
    /* 1F330 8002EB30 0A80013C */  lui        $at, %hi(D_8009B148)
    /* 1F334 8002EB34 48B123A4 */  sh         $v1, %lo(D_8009B148)($at)
  .L8002EB38:
    /* 1F338 8002EB38 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1F33C 8002EB3C 00000000 */  nop
    /* 1F340 8002EB40 0800E003 */  jr         $ra
    /* 1F344 8002EB44 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002EA0C
