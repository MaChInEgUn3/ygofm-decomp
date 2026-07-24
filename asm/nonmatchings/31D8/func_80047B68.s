nonmatching func_80047B68, 0x4C

glabel func_80047B68
    /* 38368 80047B68 0A80033C */  lui        $v1, %hi(D_8009B45C)
    /* 3836C 80047B6C 5CB4638C */  lw         $v1, %lo(D_8009B45C)($v1)
    /* 38370 80047B70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 38374 80047B74 1000BFAF */  sw         $ra, 0x10($sp)
    /* 38378 80047B78 42046294 */  lhu        $v0, 0x442($v1)
    /* 3837C 80047B7C FFFF8530 */  andi       $a1, $a0, 0xFFFF
    /* 38380 80047B80 08004510 */  beq        $v0, $a1, .L80047BA4
    /* 38384 80047B84 01000224 */   addiu     $v0, $zero, 0x1
    /* 38388 80047B88 40006294 */  lhu        $v0, 0x40($v1)
    /* 3838C 80047B8C 420464A4 */  sh         $a0, 0x442($v1)
    /* 38390 80047B90 2120A000 */  addu       $a0, $a1, $zero
    /* 38394 80047B94 02004234 */  ori        $v0, $v0, 0x2
    /* 38398 80047B98 E21D010C */  jal        func_80047788
    /* 3839C 80047B9C 400062A4 */   sh        $v0, 0x40($v1)
    /* 383A0 80047BA0 01000224 */  addiu      $v0, $zero, 0x1
  .L80047BA4:
    /* 383A4 80047BA4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 383A8 80047BA8 00000000 */  nop
    /* 383AC 80047BAC 0800E003 */  jr         $ra
    /* 383B0 80047BB0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80047B68
