nonmatching func_8008C224, 0x1B0

glabel func_8008C224
    /* 7CA24 8008C224 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7CA28 8008C228 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7CA2C 8008C22C 21888000 */  addu       $s1, $a0, $zero
    /* 7CA30 8008C230 1800BFAF */  sw         $ra, 0x18($sp)
    /* 7CA34 8008C234 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7CA38 8008C238 0000238E */  lw         $v1, 0x0($s1)
    /* 7CA3C 8008C23C 0A001024 */  addiu      $s0, $zero, 0xA
    /* 7CA40 8008C240 15007010 */  beq        $v1, $s0, .L8008C298
    /* 7CA44 8008C244 0B006228 */   slti      $v0, $v1, 0xB
    /* 7CA48 8008C248 05004010 */  beqz       $v0, .L8008C260
    /* 7CA4C 8008C24C 1E000224 */   addiu     $v0, $zero, 0x1E
    /* 7CA50 8008C250 09006010 */  beqz       $v1, .L8008C278
    /* 7CA54 8008C254 21100000 */   addu      $v0, $zero, $zero
    /* 7CA58 8008C258 F0300208 */  j          .L8008C3C0
    /* 7CA5C 8008C25C 00000000 */   nop
  .L8008C260:
    /* 7CA60 8008C260 29006210 */  beq        $v1, $v0, .L8008C308
    /* 7CA64 8008C264 20000224 */   addiu     $v0, $zero, 0x20
    /* 7CA68 8008C268 4D006210 */  beq        $v1, $v0, .L8008C3A0
    /* 7CA6C 8008C26C 21100000 */   addu      $v0, $zero, $zero
    /* 7CA70 8008C270 F0300208 */  j          .L8008C3C0
    /* 7CA74 8008C274 00000000 */   nop
  .L8008C278:
    /* 7CA78 8008C278 0980043C */  lui        $a0, %hi(func_8008B974)
    /* 7CA7C 8008C27C 74B98424 */  addiu      $a0, $a0, %lo(func_8008B974)
    /* 7CA80 8008C280 0A80013C */  lui        $at, %hi(D_80099E90)
    /* 7CA84 8008C284 909E20AC */  sw         $zero, %lo(D_80099E90)($at)
    /* 7CA88 8008C288 3834020C */  jal        func_8008D0E0
    /* 7CA8C 8008C28C 000030AE */   sw        $s0, 0x0($s1)
    /* 7CA90 8008C290 F0300208 */  j          .L8008C3C0
    /* 7CA94 8008C294 21100000 */   addu      $v0, $zero, $zero
  .L8008C298:
    /* 7CA98 8008C298 1080043C */  lui        $a0, %hi(D_800FE34C)
    /* 7CA9C 8008C29C 4CE38424 */  addiu      $a0, $a0, %lo(D_800FE34C)
    /* 7CAA0 8008C2A0 0000828C */  lw         $v0, 0x0($a0)
    /* 7CAA4 8008C2A4 00000000 */  nop
    /* 7CAA8 8008C2A8 45004014 */  bnez       $v0, .L8008C3C0
    /* 7CAAC 8008C2AC 01000224 */   addiu     $v0, $zero, 0x1
    /* 7CAB0 8008C2B0 10009024 */  addiu      $s0, $a0, 0x10
  .L8008C2B4:
    /* 7CAB4 8008C2B4 0000048E */  lw         $a0, 0x0($s0)
    /* 7CAB8 8008C2B8 0400058E */  lw         $a1, 0x4($s0)
    /* 7CABC 8008C2BC 38CE010C */  jal        func_800738E0
    /* 7CAC0 8008C2C0 21300000 */   addu      $a2, $zero, $zero
    /* 7CAC4 8008C2C4 0400038E */  lw         $v1, 0x4($s0)
    /* 7CAC8 8008C2C8 00000000 */  nop
    /* 7CACC 8008C2CC F9FF4314 */  bne        $v0, $v1, .L8008C2B4
    /* 7CAD0 8008C2D0 00000000 */   nop
    /* 7CAD4 8008C2D4 5835020C */  jal        func_8008D560
    /* 7CAD8 8008C2D8 00000000 */   nop
    /* 7CADC 8008C2DC 1080103C */  lui        $s0, %hi(D_800FE35C)
    /* 7CAE0 8008C2E0 5CE31026 */  addiu      $s0, $s0, %lo(D_800FE35C)
  .L8008C2E4:
    /* 7CAE4 8008C2E4 0000048E */  lw         $a0, 0x0($s0)
    /* 7CAE8 8008C2E8 0C00058E */  lw         $a1, 0xC($s0)
    /* 7CAEC 8008C2EC 0800068E */  lw         $a2, 0x8($s0)
    /* 7CAF0 8008C2F0 3CCE010C */  jal        func_800738F0
    /* 7CAF4 8008C2F4 00000000 */   nop
    /* 7CAF8 8008C2F8 FAFF4014 */  bnez       $v0, .L8008C2E4
    /* 7CAFC 8008C2FC 1E000224 */   addiu     $v0, $zero, 0x1E
    /* 7CB00 8008C300 EF300208 */  j          .L8008C3BC
    /* 7CB04 8008C304 000022AE */   sw        $v0, 0x0($s1)
  .L8008C308:
    /* 7CB08 8008C308 0636020C */  jal        func_8008D818
    /* 7CB0C 8008C30C 00000000 */   nop
    /* 7CB10 8008C310 2B004010 */  beqz       $v0, .L8008C3C0
    /* 7CB14 8008C314 21100000 */   addu      $v0, $zero, $zero
    /* 7CB18 8008C318 9A35020C */  jal        func_8008D668
    /* 7CB1C 8008C31C 00000000 */   nop
    /* 7CB20 8008C320 21204000 */  addu       $a0, $v0, $zero
    /* 7CB24 8008C324 17008010 */  beqz       $a0, .L8008C384
    /* 7CB28 8008C328 00000000 */   nop
    /* 7CB2C 8008C32C 0A80023C */  lui        $v0, %hi(D_80099E90)
    /* 7CB30 8008C330 909E428C */  lw         $v0, %lo(D_80099E90)($v0)
    /* 7CB34 8008C334 00000000 */  nop
    /* 7CB38 8008C338 01004224 */  addiu      $v0, $v0, 0x1
    /* 7CB3C 8008C33C 0A80013C */  lui        $at, %hi(D_80099E90)
    /* 7CB40 8008C340 909E22AC */  sw         $v0, %lo(D_80099E90)($at)
    /* 7CB44 8008C344 04004228 */  slti       $v0, $v0, 0x4
    /* 7CB48 8008C348 03004010 */  beqz       $v0, .L8008C358
    /* 7CB4C 8008C34C 04000224 */   addiu     $v0, $zero, 0x4
    /* 7CB50 8008C350 EF300208 */  j          .L8008C3BC
    /* 7CB54 8008C354 000030AE */   sw        $s0, 0x0($s1)
  .L8008C358:
    /* 7CB58 8008C358 0A008214 */  bne        $a0, $v0, .L8008C384
    /* 7CB5C 8008C35C 00000000 */   nop
    /* 7CB60 8008C360 5835020C */  jal        func_8008D560
    /* 7CB64 8008C364 00000000 */   nop
    /* 7CB68 8008C368 1080043C */  lui        $a0, %hi(D_800FE358)
    /* 7CB6C 8008C36C 58E3848C */  lw         $a0, %lo(D_800FE358)($a0)
    /* 7CB70 8008C370 E82C020C */  jal        func_8008B3A0
    /* 7CB74 8008C374 00000000 */   nop
    /* 7CB78 8008C378 20000224 */  addiu      $v0, $zero, 0x20
    /* 7CB7C 8008C37C EF300208 */  j          .L8008C3BC
    /* 7CB80 8008C380 000022AE */   sw        $v0, 0x0($s1)
  .L8008C384:
    /* 7CB84 8008C384 DD33020C */  jal        func_8008CF74
    /* 7CB88 8008C388 00000000 */   nop
    /* 7CB8C 8008C38C 1080033C */  lui        $v1, %hi(D_800FE348)
    /* 7CB90 8008C390 48E36324 */  addiu      $v1, $v1, %lo(D_800FE348)
    /* 7CB94 8008C394 040062AC */  sw         $v0, 0x4($v1)
    /* 7CB98 8008C398 F0300208 */  j          .L8008C3C0
    /* 7CB9C 8008C39C 01000224 */   addiu     $v0, $zero, 0x1
  .L8008C3A0:
    /* 7CBA0 8008C3A0 1536020C */  jal        func_8008D854
    /* 7CBA4 8008C3A4 00000000 */   nop
    /* 7CBA8 8008C3A8 05004010 */  beqz       $v0, .L8008C3C0
    /* 7CBAC 8008C3AC 21100000 */   addu      $v0, $zero, $zero
    /* 7CBB0 8008C3B0 D035020C */  jal        func_8008D740
    /* 7CBB4 8008C3B4 00000000 */   nop
    /* 7CBB8 8008C3B8 000020AE */  sw         $zero, 0x0($s1)
  .L8008C3BC:
    /* 7CBBC 8008C3BC 21100000 */  addu       $v0, $zero, $zero
  .L8008C3C0:
    /* 7CBC0 8008C3C0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 7CBC4 8008C3C4 1400B18F */  lw         $s1, 0x14($sp)
    /* 7CBC8 8008C3C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 7CBCC 8008C3CC 0800E003 */  jr         $ra
    /* 7CBD0 8008C3D0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008C224
