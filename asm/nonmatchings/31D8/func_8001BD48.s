nonmatching func_8001BD48, 0x40

glabel func_8001BD48
    /* C548 8001BD48 0A80023C */  lui        $v0, %hi(D_8009B361)
    /* C54C 8001BD4C 61B34280 */  lb         $v0, %lo(D_8009B361)($v0)
    /* C550 8001BD50 00000000 */  nop
    /* C554 8001BD54 0A004104 */  bgez       $v0, .L8001BD80
    /* C558 8001BD58 00000000 */   nop
    /* C55C 8001BD5C 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* C560 8001BD60 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* C564 8001BD64 00000000 */  nop
    /* C568 8001BD68 00014230 */  andi       $v0, $v0, 0x100
    /* C56C 8001BD6C 04004010 */  beqz       $v0, .L8001BD80
    /* C570 8001BD70 01000224 */   addiu     $v0, $zero, 0x1
    /* C574 8001BD74 5C0282A3 */  sb         $v0, %gp_rel(D_8009B164)($gp)
    /* C578 8001BD78 0800E003 */  jr         $ra
    /* C57C 8001BD7C 01000224 */   addiu     $v0, $zero, 0x1
  .L8001BD80:
    /* C580 8001BD80 0800E003 */  jr         $ra
    /* C584 8001BD84 21100000 */   addu      $v0, $zero, $zero
endlabel func_8001BD48
