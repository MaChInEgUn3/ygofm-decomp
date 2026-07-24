nonmatching func_8007C458, 0x88

glabel func_8007C458
    /* 6CC58 8007C458 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6CC5C 8007C45C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6CC60 8007C460 34E8010C */  jal        func_8007A0D0
    /* 6CC64 8007C464 00000000 */   nop
    /* 6CC68 8007C468 0980023C */  lui        $v0, %hi(D_800938C8)
    /* 6CC6C 8007C46C C8384224 */  addiu      $v0, $v0, %lo(D_800938C8)
    /* 6CC70 8007C470 0000438C */  lw         $v1, 0x0($v0)
    /* 6CC74 8007C474 BCFF4490 */  lbu        $a0, -0x44($v0)
    /* 6CC78 8007C478 01006324 */  addiu      $v1, $v1, 0x1
    /* 6CC7C 8007C47C 80200400 */  sll        $a0, $a0, 2
    /* 6CC80 8007C480 000043AC */  sw         $v1, 0x0($v0)
    /* 6CC84 8007C484 0980033C */  lui        $v1, %hi(D_800938D4)
    /* 6CC88 8007C488 21186400 */  addu       $v1, $v1, $a0
    /* 6CC8C 8007C48C D438638C */  lw         $v1, %lo(D_800938D4)($v1)
    /* 6CC90 8007C490 00000000 */  nop
    /* 6CC94 8007C494 05006010 */  beqz       $v1, .L8007C4AC
    /* 6CC98 8007C498 FCFF4424 */   addiu     $a0, $v0, -0x4
    /* 6CC9C 8007C49C 00110300 */  sll        $v0, $v1, 4
    /* 6CCA0 8007C4A0 23104300 */  subu       $v0, $v0, $v1
    /* 6CCA4 8007C4A4 2CF10108 */  j          .L8007C4B0
    /* 6CCA8 8007C4A8 80100200 */   sll       $v0, $v0, 2
  .L8007C4AC:
    /* 6CCAC 8007C4AC 1E000224 */  addiu      $v0, $zero, 0x1E
  .L8007C4B0:
    /* 6CCB0 8007C4B0 000082AC */  sw         $v0, 0x0($a0)
    /* 6CCB4 8007C4B4 0980023C */  lui        $v0, %hi(D_80093884)
    /* 6CCB8 8007C4B8 84384224 */  addiu      $v0, $v0, %lo(D_80093884)
    /* 6CCBC 8007C4BC 21300000 */  addu       $a2, $zero, $zero
    /* 6CCC0 8007C4C0 00004490 */  lbu        $a0, 0x0($v0)
    /* 6CCC4 8007C4C4 0800458C */  lw         $a1, 0x8($v0)
    /* 6CCC8 8007C4C8 0FE7010C */  jal        func_80079C3C
    /* 6CCCC 8007C4CC 01000724 */   addiu     $a3, $zero, 0x1
    /* 6CCD0 8007C4D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6CCD4 8007C4D4 21100000 */  addu       $v0, $zero, $zero
    /* 6CCD8 8007C4D8 0800E003 */  jr         $ra
    /* 6CCDC 8007C4DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007C458
