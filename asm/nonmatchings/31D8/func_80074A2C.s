nonmatching func_80074A2C, 0x24

glabel func_80074A2C
    /* 6522C 80074A2C 0600A010 */  beqz       $a1, .L80074A48
    /* 65230 80074A30 FFFFA224 */   addiu     $v0, $a1, -0x1
    /* 65234 80074A34 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L80074A38:
    /* 65238 80074A38 000080AC */  sw         $zero, 0x0($a0)
    /* 6523C 80074A3C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 65240 80074A40 FDFF4314 */  bne        $v0, $v1, .L80074A38
    /* 65244 80074A44 04008424 */   addiu     $a0, $a0, 0x4
  .L80074A48:
    /* 65248 80074A48 0800E003 */  jr         $ra
    /* 6524C 80074A4C 00000000 */   nop
endlabel func_80074A2C
