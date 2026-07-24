nonmatching func_8002D62C, 0x58

glabel func_8002D62C
    /* 1DE2C 8002D62C 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1DE30 8002D630 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DE34 8002D634 40006230 */  andi       $v0, $v1, 0x40
    /* 1DE38 8002D638 07004014 */  bnez       $v0, .L8002D658
    /* 1DE3C 8002D63C 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1DE40 8002D640 40006234 */  ori        $v0, $v1, 0x40
    /* 1DE44 8002D644 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DE48 8002D648 FEEE000C */  jal        func_8003BBF8
    /* 1DE4C 8002D64C 00000000 */   nop
    /* 1DE50 8002D650 FBA0050C */  jal        func_801683EC
    /* 1DE54 8002D654 00000000 */   nop
  .L8002D658:
    /* 1DE58 8002D658 02A7050C */  jal        func_80169C08
    /* 1DE5C 8002D65C 00000000 */   nop
    /* 1DE60 8002D660 04004010 */  beqz       $v0, .L8002D674
    /* 1DE64 8002D664 00000000 */   nop
    /* 1DE68 8002D668 61038293 */  lbu        $v0, %gp_rel(D_8009B269)($gp)
    /* 1DE6C 8002D66C 00000000 */  nop
    /* 1DE70 8002D670 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
  .L8002D674:
    /* 1DE74 8002D674 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1DE78 8002D678 00000000 */  nop
    /* 1DE7C 8002D67C 0800E003 */  jr         $ra
    /* 1DE80 8002D680 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D62C
