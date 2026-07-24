nonmatching func_80035CA8, 0x3C

glabel func_80035CA8
    /* 264A8 80035CA8 0F80023C */  lui        $v0, %hi(D_800EAF08)
    /* 264AC 80035CAC 08AF4324 */  addiu      $v1, $v0, %lo(D_800EAF08)
    /* 264B0 80035CB0 01008424 */  addiu      $a0, $a0, 0x1
    /* 264B4 80035CB4 21280000 */  addu       $a1, $zero, $zero
  .L80035CB8:
    /* 264B8 80035CB8 00006290 */  lbu        $v0, 0x0($v1)
    /* 264BC 80035CBC 00000000 */  nop
    /* 264C0 80035CC0 02004414 */  bne        $v0, $a0, .L80035CCC
    /* 264C4 80035CC4 00000000 */   nop
    /* 264C8 80035CC8 000060A0 */  sb         $zero, 0x0($v1)
  .L80035CCC:
    /* 264CC 80035CCC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 264D0 80035CD0 F000A228 */  slti       $v0, $a1, 0xF0
    /* 264D4 80035CD4 F8FF4014 */  bnez       $v0, .L80035CB8
    /* 264D8 80035CD8 01006324 */   addiu     $v1, $v1, 0x1
    /* 264DC 80035CDC 0800E003 */  jr         $ra
    /* 264E0 80035CE0 00000000 */   nop
endlabel func_80035CA8
