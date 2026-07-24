nonmatching func_80089DD8, 0x3C

glabel func_80089DD8
    /* 7A5D8 80089DD8 0800A624 */  addiu      $a2, $a1, 0x8
    /* 7A5DC 80089DDC 0600A594 */  lhu        $a1, 0x6($a1)
    /* 7A5E0 80089DE0 00000000 */  nop
    /* 7A5E4 80089DE4 0900A010 */  beqz       $a1, .L80089E0C
    /* 7A5E8 80089DE8 21180000 */   addu      $v1, $zero, $zero
  .L80089DEC:
    /* 7A5EC 80089DEC 000086AC */  sw         $a2, 0x0($a0)
    /* 7A5F0 80089DF0 0400C294 */  lhu        $v0, 0x4($a2)
    /* 7A5F4 80089DF4 01006324 */  addiu      $v1, $v1, 0x1
    /* 7A5F8 80089DF8 80100200 */  sll        $v0, $v0, 2
    /* 7A5FC 80089DFC 2130C200 */  addu       $a2, $a2, $v0
    /* 7A600 80089E00 2A106500 */  slt        $v0, $v1, $a1
    /* 7A604 80089E04 F9FF4014 */  bnez       $v0, .L80089DEC
    /* 7A608 80089E08 04008424 */   addiu     $a0, $a0, 0x4
  .L80089E0C:
    /* 7A60C 80089E0C 0800E003 */  jr         $ra
    /* 7A610 80089E10 2110A000 */   addu      $v0, $a1, $zero
endlabel func_80089DD8
    /* 7A614 80089E14 00000000 */  nop
    /* 7A618 80089E18 00000000 */  nop
    /* 7A61C 80089E1C 00000000 */  nop
