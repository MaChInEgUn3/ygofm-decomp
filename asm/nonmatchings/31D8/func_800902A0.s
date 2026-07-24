/* Handwritten function */
nonmatching func_800902A0, 0x34C

glabel func_800902A0
    /* 80AA0 800902A0 0A80083C */  lui        $t0, %hi(D_8009A0C8)
    /* 80AA4 800902A4 C8A00825 */  addiu      $t0, $t0, %lo(D_8009A0C8)
    /* 80AA8 800902A8 0008C620 */  addi       $a2, $a2, 0x800 /* handwritten instruction */
    /* 80AAC 800902AC 0100013C */  lui        $at, (0x10000 >> 16)
    /* 80AB0 800902B0 2038C100 */  add        $a3, $a2, $at /* handwritten instruction */
    /* 80AB4 800902B4 0F008014 */  bnez       $a0, .L800902F4
    /* 80AB8 800902B8 0000098D */   lw        $t1, 0x0($t0)
    /* 80ABC 800902BC 0A80083C */  lui        $t0, %hi(D_8009A0CC)
    /* 80AC0 800902C0 CCA00825 */  addiu      $t0, $t0, %lo(D_8009A0CC)
    /* 80AC4 800902C4 0000048D */  lw         $a0, 0x0($t0)
    /* 80AC8 800902C8 0400058D */  lw         $a1, 0x4($t0)
    /* 80ACC 800902CC 0800028D */  lw         $v0, 0x8($t0)
    /* 80AD0 800902D0 0C00038D */  lw         $v1, 0xC($t0)
    /* 80AD4 800902D4 10000C8D */  lw         $t4, 0x10($t0)
    /* 80AD8 800902D8 14000D8D */  lw         $t5, 0x14($t0)
    /* 80ADC 800902DC 18000F8D */  lw         $t7, 0x18($t0)
    /* 80AE0 800902E0 1C00188D */  lw         $t8, 0x1C($t0)
    /* 80AE4 800902E4 2000198D */  lw         $t9, 0x20($t0)
    /* 80AE8 800902E8 20482901 */  add        $t1, $t1, $t1 /* handwritten instruction */
    /* 80AEC 800902EC 64000010 */  b          .L80090480
    /* 80AF0 800902F0 2070A900 */   add       $t6, $a1, $t1 /* handwritten instruction */
  .L800902F4:
    /* 80AF4 800902F4 20680000 */  add        $t5, $zero, $zero /* handwritten instruction */
    /* 80AF8 800902F8 20780000 */  add        $t7, $zero, $zero /* handwritten instruction */
    /* 80AFC 800902FC 20C00000 */  add        $t8, $zero, $zero /* handwritten instruction */
    /* 80B00 80090300 20C80000 */  add        $t9, $zero, $zero /* handwritten instruction */
    /* 80B04 80090304 20482901 */  add        $t1, $t1, $t1 /* handwritten instruction */
    /* 80B08 80090308 2070A900 */  add        $t6, $a1, $t1 /* handwritten instruction */
    /* 80B0C 8009030C 0000898C */  lw         $t1, 0x0($a0)
    /* 80B10 80090310 04008C94 */  lhu        $t4, 0x4($a0)
    /* 80B14 80090314 06008A94 */  lhu        $t2, 0x6($a0)
    /* 80B18 80090318 08008294 */  lhu        $v0, 0x8($a0)
    /* 80B1C 8009031C 0A008394 */  lhu        $v1, 0xA($a0)
    /* 80B20 80090320 FDFF4A21 */  addi       $t2, $t2, -0x3 /* handwritten instruction */
    /* 80B24 80090324 02004005 */  bltz       $t2, .L80090330
    /* 80B28 80090328 80620C00 */   sll       $t4, $t4, 10
    /* 80B2C 8009032C 01000D20 */  addi       $t5, $zero, 0x1 /* handwritten instruction */
  .L80090330:
    /* 80B30 80090330 0C008420 */  addi       $a0, $a0, 0xC /* handwritten instruction */
    /* 80B34 80090334 00140200 */  sll        $v0, $v0, 16
    /* 80B38 80090338 25104300 */  or         $v0, $v0, $v1
    /* 80B3C 8009033C 25180000 */  or         $v1, $zero, $zero
    /* 80B40 80090340 0000A9AC */  sw         $t1, 0x0($a1)
    /* 80B44 80090344 FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 80B48 80090348 80480900 */  sll        $t1, $t1, 2
    /* 80B4C 8009034C 04002925 */  addiu      $t1, $t1, 0x4
    /* 80B50 80090350 20482501 */  add        $t1, $t1, $a1 /* handwritten instruction */
    /* 80B54 80090354 0A80083C */  lui        $t0, %hi(D_8009A0F0)
    /* 80B58 80090358 F0A00825 */  addiu      $t0, $t0, %lo(D_8009A0F0)
    /* 80B5C 8009035C 000009AD */  sw         $t1, 0x0($t0)
    /* 80B60 80090360 0200A520 */  addi       $a1, $a1, 0x2 /* handwritten instruction */
  .L80090364:
    /* 80B64 80090364 3500A011 */  beqz       $t5, .L8009043C
    /* 80B68 80090368 82450200 */   srl       $t0, $v0, 22
    /* 80B6C 8009036C FF030139 */  xori       $at, $t0, 0x3FF
    /* 80B70 80090370 85002010 */  beqz       $at, .L80090588
    /* 80B74 80090374 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* 80B78 80090378 FDFFA121 */  addi       $at, $t5, -0x3 /* handwritten instruction */
    /* 80B7C 8009037C 02002004 */  bltz       $at, .L80090388
    /* 80B80 80090380 00FCC120 */   addi      $at, $a2, -0x400 /* handwritten instruction */
    /* 80B84 80090384 00FC2120 */  addi       $at, $at, -0x400 /* handwritten instruction */
  .L80090388:
    /* 80B88 80090388 02460200 */  srl        $t0, $v0, 24
    /* 80B8C 8009038C 80400800 */  sll        $t0, $t0, 2
    /* 80B90 80090390 20400101 */  add        $t0, $t0, $at /* handwritten instruction */
    /* 80B94 80090394 00000995 */  lhu        $t1, 0x0($t0)
    /* 80B98 80090398 02000A95 */  lhu        $t2, 0x2($t0)
    /* 80B9C 8009039C 24400000 */  and        $t0, $zero, $zero
    /* 80BA0 800903A0 0A004011 */  beqz       $t2, .L800903CC
    /* 80BA4 800903A4 04102201 */   sllv      $v0, $v0, $t1
    /* 80BA8 800903A8 20000120 */  addi       $at, $zero, 0x20 /* handwritten instruction */
    /* 80BAC 800903AC 22082A00 */  sub        $at, $at, $t2 /* handwritten instruction */
    /* 80BB0 800903B0 06402200 */  srlv       $t0, $v0, $at
    /* 80BB4 800903B4 04004004 */  bltz       $v0, .L800903C8
    /* 80BB8 800903B8 04104201 */   sllv      $v0, $v0, $t2
    /* 80BBC 800903BC FFFF0B20 */  addi       $t3, $zero, -0x1 /* handwritten instruction */
    /* 80BC0 800903C0 06582B00 */  srlv       $t3, $t3, $at
    /* 80BC4 800903C4 22400B01 */  sub        $t0, $t0, $t3 /* handwritten instruction */
  .L800903C8:
    /* 80BC8 800903C8 20186A00 */  add        $v1, $v1, $t2 /* handwritten instruction */
  .L800903CC:
    /* 80BCC 800903CC 20186900 */  add        $v1, $v1, $t1 /* handwritten instruction */
    /* 80BD0 800903D0 10006130 */  andi       $at, $v1, 0x10
    /* 80BD4 800903D4 05002010 */  beqz       $at, .L800903EC
    /* 80BD8 800903D8 0F006330 */   andi      $v1, $v1, 0xF
    /* 80BDC 800903DC 00008994 */  lhu        $t1, 0x0($a0)
    /* 80BE0 800903E0 02008420 */  addi       $a0, $a0, 0x2 /* handwritten instruction */
    /* 80BE4 800903E4 04486900 */  sllv       $t1, $t1, $v1
    /* 80BE8 800903E8 25104900 */  or         $v0, $v0, $t1
  .L800903EC:
    /* 80BEC 800903EC FEFFA121 */  addi       $at, $t5, -0x2 /* handwritten instruction */
    /* 80BF0 800903F0 0800201C */  bgtz       $at, .L80090414
    /* 80BF4 800903F4 20482803 */   add       $t1, $t9, $t0 /* handwritten instruction */
    /* 80BF8 800903F8 04002010 */  beqz       $at, .L8009040C
    /* 80BFC 800903FC 20480803 */   add       $t1, $t8, $t0 /* handwritten instruction */
    /* 80C00 80090400 2048E801 */  add        $t1, $t7, $t0 /* handwritten instruction */
    /* 80C04 80090404 04000010 */  b          .L80090418
    /* 80C08 80090408 2078E801 */   add       $t7, $t7, $t0 /* handwritten instruction */
  .L8009040C:
    /* 80C0C 8009040C 02000010 */  b          .L80090418
    /* 80C10 80090410 20C00803 */   add       $t8, $t8, $t0 /* handwritten instruction */
  .L80090414:
    /* 80C14 80090414 20C82803 */  add        $t9, $t9, $t0 /* handwritten instruction */
  .L80090418:
    /* 80C18 80090418 80480900 */  sll        $t1, $t1, 2
    /* 80C1C 8009041C FF032931 */  andi       $t1, $t1, 0x3FF
    /* 80C20 80090420 25488901 */  or         $t1, $t4, $t1
    /* 80C24 80090424 0100AD21 */  addi       $t5, $t5, 0x1 /* handwritten instruction */
    /* 80C28 80090428 F9FFA121 */  addi       $at, $t5, -0x7 /* handwritten instruction */
    /* 80C2C 8009042C 11002014 */  bnez       $at, .L80090474
    /* 80C30 80090430 0000A9A4 */   sh        $t1, 0x0($a1)
    /* 80C34 80090434 0F000010 */  b          .L80090474
    /* 80C38 80090438 FAFFAD21 */   addi      $t5, $t5, -0x6 /* handwritten instruction */
  .L8009043C:
    /* 80C3C 8009043C FF010139 */  xori       $at, $t0, 0x1FF
    /* 80C40 80090440 51002010 */  beqz       $at, .L80090588
    /* 80C44 80090444 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* 80C48 80090448 80120200 */  sll        $v0, $v0, 10
    /* 80C4C 8009044C 0A006320 */  addi       $v1, $v1, 0xA /* handwritten instruction */
    /* 80C50 80090450 10006130 */  andi       $at, $v1, 0x10
    /* 80C54 80090454 05002010 */  beqz       $at, .L8009046C
    /* 80C58 80090458 0F006330 */   andi      $v1, $v1, 0xF
    /* 80C5C 8009045C 00008994 */  lhu        $t1, 0x0($a0)
    /* 80C60 80090460 02008420 */  addi       $a0, $a0, 0x2 /* handwritten instruction */
    /* 80C64 80090464 04486900 */  sllv       $t1, $t1, $v1
    /* 80C68 80090468 25104900 */  or         $v0, $v0, $t1
  .L8009046C:
    /* 80C6C 8009046C 25408801 */  or         $t0, $t4, $t0
    /* 80C70 80090470 0000A8A4 */  sh         $t0, 0x0($a1)
  .L80090474:
    /* 80C74 80090474 2308AE00 */  subu       $at, $a1, $t6
    /* 80C78 80090478 4F002104 */  bgez       $at, .L800905B8
    /* 80C7C 8009047C 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
  .L80090480:
    /* 80C80 80090480 C2440200 */  srl        $t0, $v0, 19
    /* 80C84 80090484 C0400800 */  sll        $t0, $t0, 3
    /* 80C88 80090488 20400601 */  add        $t0, $t0, $a2 /* handwritten instruction */
    /* 80C8C 8009048C 0000098D */  lw         $t1, 0x0($t0)
    /* 80C90 80090490 00000000 */  nop
    /* 80C94 80090494 11002015 */  bnez       $t1, .L800904DC
    /* 80C98 80090498 FF002131 */   andi      $at, $t1, 0xFF
    /* 80C9C 8009049C 00120200 */  sll        $v0, $v0, 8
    /* 80CA0 800904A0 08006320 */  addi       $v1, $v1, 0x8 /* handwritten instruction */
    /* 80CA4 800904A4 10006130 */  andi       $at, $v1, 0x10
    /* 80CA8 800904A8 05002010 */  beqz       $at, .L800904C0
    /* 80CAC 800904AC 0F006330 */   andi      $v1, $v1, 0xF
    /* 80CB0 800904B0 00008894 */  lhu        $t0, 0x0($a0)
    /* 80CB4 800904B4 02008420 */  addi       $a0, $a0, 0x2 /* handwritten instruction */
    /* 80CB8 800904B8 04406800 */  sllv       $t0, $t0, $v1
    /* 80CBC 800904BC 25104800 */  or         $v0, $v0, $t0
  .L800904C0:
    /* 80CC0 800904C0 C2450200 */  srl        $t0, $v0, 23
    /* 80CC4 800904C4 80400800 */  sll        $t0, $t0, 2
    /* 80CC8 800904C8 20400701 */  add        $t0, $t0, $a3 /* handwritten instruction */
    /* 80CCC 800904CC 0000098D */  lw         $t1, 0x0($t0)
    /* 80CD0 800904D0 20580000 */  add        $t3, $zero, $zero /* handwritten instruction */
    /* 80CD4 800904D4 02000010 */  b          .L800904E0
    /* 80CD8 800904D8 FF002131 */   andi      $at, $t1, 0xFF
  .L800904DC:
    /* 80CDC 800904DC 04000B8D */  lw         $t3, 0x4($t0)
  .L800904E0:
    /* 80CE0 800904E0 04102200 */  sllv       $v0, $v0, $at
    /* 80CE4 800904E4 20186100 */  add        $v1, $v1, $at /* handwritten instruction */
    /* 80CE8 800904E8 10006130 */  andi       $at, $v1, 0x10
    /* 80CEC 800904EC 05002010 */  beqz       $at, .L80090504
    /* 80CF0 800904F0 0F006330 */   andi      $v1, $v1, 0xF
    /* 80CF4 800904F4 00008894 */  lhu        $t0, 0x0($a0)
    /* 80CF8 800904F8 02008420 */  addi       $a0, $a0, 0x2 /* handwritten instruction */
    /* 80CFC 800904FC 04406800 */  sllv       $t0, $t0, $v1
    /* 80D00 80090500 25104800 */  or         $v0, $v0, $t0
  .L80090504:
    /* 80D04 80090504 024C0900 */  srl        $t1, $t1, 16
    /* 80D08 80090508 1F7C2139 */  xori       $at, $t1, 0x7C1F
    /* 80D0C 8009050C 15002010 */  beqz       $at, .L80090564
    /* 80D10 80090510 00FE2139 */   xori      $at, $t1, 0xFE00
    /* 80D14 80090514 93FF2010 */  beqz       $at, .L80090364
    /* 80D18 80090518 0000A9A4 */   sh        $t1, 0x0($a1)
    /* 80D1C 8009051C D8FF6011 */  beqz       $t3, .L80090480
    /* 80D20 80090520 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* 80D24 80090524 FFFF6A31 */  andi       $t2, $t3, 0xFFFF
    /* 80D28 80090528 1F7C4139 */  xori       $at, $t2, 0x7C1F
    /* 80D2C 8009052C 0D002010 */  beqz       $at, .L80090564
    /* 80D30 80090530 00FE4139 */   xori      $at, $t2, 0xFE00
    /* 80D34 80090534 8BFF2010 */  beqz       $at, .L80090364
    /* 80D38 80090538 0000AAA4 */   sh        $t2, 0x0($a1)
    /* 80D3C 8009053C 02540B00 */  srl        $t2, $t3, 16
    /* 80D40 80090540 CFFF4011 */  beqz       $t2, .L80090480
    /* 80D44 80090544 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* 80D48 80090548 1F7C4139 */  xori       $at, $t2, 0x7C1F
    /* 80D4C 8009054C 05002010 */  beqz       $at, .L80090564
    /* 80D50 80090550 00FE4139 */   xori      $at, $t2, 0xFE00
    /* 80D54 80090554 83FF2010 */  beqz       $at, .L80090364
    /* 80D58 80090558 0000AAA4 */   sh        $t2, 0x0($a1)
    /* 80D5C 8009055C C8FF0010 */  b          .L80090480
    /* 80D60 80090560 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
  .L80090564:
    /* 80D64 80090564 02440200 */  srl        $t0, $v0, 16
    /* 80D68 80090568 0000A8A4 */  sh         $t0, 0x0($a1)
    /* 80D6C 8009056C 0200A520 */  addi       $a1, $a1, 0x2 /* handwritten instruction */
    /* 80D70 80090570 00008894 */  lhu        $t0, 0x0($a0)
    /* 80D74 80090574 02008420 */  addi       $a0, $a0, 0x2 /* handwritten instruction */
    /* 80D78 80090578 00140200 */  sll        $v0, $v0, 16
    /* 80D7C 8009057C 04406800 */  sllv       $t0, $t0, $v1
    /* 80D80 80090580 BFFF0010 */  b          .L80090480
    /* 80D84 80090584 25104800 */   or        $v0, $v0, $t0
  .L80090588:
    /* 80D88 80090588 0A80083C */  lui        $t0, %hi(D_8009A0F0)
    /* 80D8C 8009058C F0A00825 */  addiu      $t0, $t0, %lo(D_8009A0F0)
    /* 80D90 80090590 0000098D */  lw         $t1, 0x0($t0)
    /* 80D94 80090594 00FE0834 */  ori        $t0, $zero, 0xFE00
  .L80090598:
    /* 80D98 80090598 2308A900 */  subu       $at, $a1, $t1
    /* 80D9C 8009059C 04002104 */  bgez       $at, .L800905B0
    /* 80DA0 800905A0 00000000 */   nop
    /* 80DA4 800905A4 0000A8A4 */  sh         $t0, 0x0($a1)
    /* 80DA8 800905A8 FBFF0010 */  b          .L80090598
    /* 80DAC 800905AC 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
  .L800905B0:
    /* 80DB0 800905B0 0800E003 */  jr         $ra
    /* 80DB4 800905B4 20100000 */   add       $v0, $zero, $zero /* handwritten instruction */
  .L800905B8:
    /* 80DB8 800905B8 0A80083C */  lui        $t0, %hi(D_8009A0CC)
    /* 80DBC 800905BC CCA00825 */  addiu      $t0, $t0, %lo(D_8009A0CC)
    /* 80DC0 800905C0 000004AD */  sw         $a0, 0x0($t0)
    /* 80DC4 800905C4 040005AD */  sw         $a1, 0x4($t0)
    /* 80DC8 800905C8 080002AD */  sw         $v0, 0x8($t0)
    /* 80DCC 800905CC 0C0003AD */  sw         $v1, 0xC($t0)
    /* 80DD0 800905D0 10000CAD */  sw         $t4, 0x10($t0)
    /* 80DD4 800905D4 14000DAD */  sw         $t5, 0x14($t0)
    /* 80DD8 800905D8 18000FAD */  sw         $t7, 0x18($t0)
    /* 80DDC 800905DC 1C0018AD */  sw         $t8, 0x1C($t0)
    /* 80DE0 800905E0 200019AD */  sw         $t9, 0x20($t0)
    /* 80DE4 800905E4 0800E003 */  jr         $ra
    /* 80DE8 800905E8 01000220 */   addi      $v0, $zero, 0x1 /* handwritten instruction */
endlabel func_800902A0
    /* 80DEC 800905EC 00000000 */  nop
