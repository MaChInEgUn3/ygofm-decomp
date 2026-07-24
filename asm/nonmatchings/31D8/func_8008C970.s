nonmatching func_8008C970, 0x108

glabel func_8008C970
    /* 7D170 8008C970 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7D174 8008C974 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7D178 8008C978 21888000 */  addu       $s1, $a0, $zero
    /* 7D17C 8008C97C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 7D180 8008C980 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7D184 8008C984 0000238E */  lw         $v1, 0x0($s1)
    /* 7D188 8008C988 0A001024 */  addiu      $s0, $zero, 0xA
    /* 7D18C 8008C98C 14007010 */  beq        $v1, $s0, .L8008C9E0
    /* 7D190 8008C990 0B006228 */   slti      $v0, $v1, 0xB
    /* 7D194 8008C994 05004010 */  beqz       $v0, .L8008C9AC
    /* 7D198 8008C998 0B000224 */   addiu     $v0, $zero, 0xB
    /* 7D19C 8008C99C 09006010 */  beqz       $v1, .L8008C9C4
    /* 7D1A0 8008C9A0 21100000 */   addu      $v0, $zero, $zero
    /* 7D1A4 8008C9A4 99320208 */  j          .L8008CA64
    /* 7D1A8 8008C9A8 00000000 */   nop
  .L8008C9AC:
    /* 7D1AC 8008C9AC 1C006210 */  beq        $v1, $v0, .L8008CA20
    /* 7D1B0 8008C9B0 14000224 */   addiu     $v0, $zero, 0x14
    /* 7D1B4 8008C9B4 21006210 */  beq        $v1, $v0, .L8008CA3C
    /* 7D1B8 8008C9B8 21100000 */   addu      $v0, $zero, $zero
    /* 7D1BC 8008C9BC 99320208 */  j          .L8008CA64
    /* 7D1C0 8008C9C0 00000000 */   nop
  .L8008C9C4:
    /* 7D1C4 8008C9C4 0980043C */  lui        $a0, %hi(func_8008B974)
    /* 7D1C8 8008C9C8 74B98424 */  addiu      $a0, $a0, %lo(func_8008B974)
    /* 7D1CC 8008C9CC 0A80013C */  lui        $at, %hi(D_80099E9C)
    /* 7D1D0 8008C9D0 3834020C */  jal        func_8008D0E0
    /* 7D1D4 8008C9D4 9C9E20AC */   sw        $zero, %lo(D_80099E9C)($at)
    /* 7D1D8 8008C9D8 98320208 */  j          .L8008CA60
    /* 7D1DC 8008C9DC 000030AE */   sw        $s0, 0x0($s1)
  .L8008C9E0:
    /* 7D1E0 8008C9E0 1080103C */  lui        $s0, %hi(D_800FE34C)
    /* 7D1E4 8008C9E4 4CE31026 */  addiu      $s0, $s0, %lo(D_800FE34C)
    /* 7D1E8 8008C9E8 0000028E */  lw         $v0, 0x0($s0)
    /* 7D1EC 8008C9EC 00000000 */  nop
    /* 7D1F0 8008C9F0 1C004014 */  bnez       $v0, .L8008CA64
    /* 7D1F4 8008C9F4 01000224 */   addiu     $v0, $zero, 0x1
    /* 7D1F8 8008C9F8 20000426 */  addiu      $a0, $s0, 0x20
    /* 7D1FC 8008C9FC 34CE010C */  jal        func_800738D0
    /* 7D200 8008CA00 01800534 */   ori       $a1, $zero, 0x8001
    /* 7D204 8008CA04 06004104 */  bgez       $v0, .L8008CA20
    /* 7D208 8008CA08 100002AE */   sw        $v0, 0x10($s0)
    /* 7D20C 8008CA0C FCFF0326 */  addiu      $v1, $s0, -0x4
    /* 7D210 8008CA10 05000224 */  addiu      $v0, $zero, 0x5
    /* 7D214 8008CA14 040062AC */  sw         $v0, 0x4($v1)
    /* 7D218 8008CA18 99320208 */  j          .L8008CA64
    /* 7D21C 8008CA1C 01000224 */   addiu     $v0, $zero, 0x1
  .L8008CA20:
    /* 7D220 8008CA20 14000224 */  addiu      $v0, $zero, 0x14
    /* 7D224 8008CA24 0980043C */  lui        $a0, %hi(func_8008C48C)
    /* 7D228 8008CA28 8CC48424 */  addiu      $a0, $a0, %lo(func_8008C48C)
    /* 7D22C 8008CA2C 3834020C */  jal        func_8008D0E0
    /* 7D230 8008CA30 000022AE */   sw        $v0, 0x0($s1)
    /* 7D234 8008CA34 99320208 */  j          .L8008CA64
    /* 7D238 8008CA38 21100000 */   addu      $v0, $zero, $zero
  .L8008CA3C:
    /* 7D23C 8008CA3C 1080103C */  lui        $s0, %hi(D_800FE35C)
    /* 7D240 8008CA40 5CE31026 */  addiu      $s0, $s0, %lo(D_800FE35C)
    /* 7D244 8008CA44 0000048E */  lw         $a0, 0x0($s0)
    /* 7D248 8008CA48 44CE010C */  jal        func_80073910
    /* 7D24C 8008CA4C 00000000 */   nop
    /* 7D250 8008CA50 01000224 */  addiu      $v0, $zero, 0x1
    /* 7D254 8008CA54 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 7D258 8008CA58 99320208 */  j          .L8008CA64
    /* 7D25C 8008CA5C 000003AE */   sw        $v1, 0x0($s0)
  .L8008CA60:
    /* 7D260 8008CA60 21100000 */  addu       $v0, $zero, $zero
  .L8008CA64:
    /* 7D264 8008CA64 1800BF8F */  lw         $ra, 0x18($sp)
    /* 7D268 8008CA68 1400B18F */  lw         $s1, 0x14($sp)
    /* 7D26C 8008CA6C 1000B08F */  lw         $s0, 0x10($sp)
    /* 7D270 8008CA70 0800E003 */  jr         $ra
    /* 7D274 8008CA74 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008C970
