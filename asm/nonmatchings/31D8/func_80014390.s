nonmatching func_80014390, 0x4C

glabel func_80014390
    /* 4B90 80014390 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4B94 80014394 FF008430 */  andi       $a0, $a0, 0xFF
    /* 4B98 80014398 02000224 */  addiu      $v0, $zero, 0x2
    /* 4B9C 8001439C 0B008214 */  bne        $a0, $v0, .L800143CC
    /* 4BA0 800143A0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 4BA4 800143A4 C4F9010C */  jal        func_8007E710
    /* 4BA8 800143A8 2120A000 */   addu      $a0, $a1, $zero
    /* 4BAC 800143AC 21184000 */  addu       $v1, $v0, $zero
    /* 4BB0 800143B0 02006018 */  blez       $v1, .L800143BC
    /* 4BB4 800143B4 0F80023C */   lui       $v0, %hi(D_800E9E90)
    /* 4BB8 800143B8 909E43AC */  sw         $v1, %lo(D_800E9E90)($v0)
  .L800143BC:
    /* 4BBC 800143BC EC01828F */  lw         $v0, %gp_rel(D_8009B0F4)($gp)
    /* 4BC0 800143C0 FFF70324 */  addiu      $v1, $zero, -0x801
    /* 4BC4 800143C4 24104300 */  and        $v0, $v0, $v1
    /* 4BC8 800143C8 EC0182AF */  sw         $v0, %gp_rel(D_8009B0F4)($gp)
  .L800143CC:
    /* 4BCC 800143CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4BD0 800143D0 00000000 */  nop
    /* 4BD4 800143D4 0800E003 */  jr         $ra
    /* 4BD8 800143D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80014390
