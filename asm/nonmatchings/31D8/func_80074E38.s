nonmatching func_80074E38, 0x24

glabel func_80074E38
    /* 65638 80074E38 0600A010 */  beqz       $a1, .L80074E54
    /* 6563C 80074E3C FFFFA224 */   addiu     $v0, $a1, -0x1
    /* 65640 80074E40 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L80074E44:
    /* 65644 80074E44 000080AC */  sw         $zero, 0x0($a0)
    /* 65648 80074E48 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 6564C 80074E4C FDFF4314 */  bne        $v0, $v1, .L80074E44
    /* 65650 80074E50 04008424 */   addiu     $a0, $a0, 0x4
  .L80074E54:
    /* 65654 80074E54 0800E003 */  jr         $ra
    /* 65658 80074E58 00000000 */   nop
endlabel func_80074E38
    /* 6565C 80074E5C 00000000 */  nop
