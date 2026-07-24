nonmatching func_8003FE80, 0x60

glabel func_8003FE80
    /* 30680 8003FE80 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 30684 8003FE84 0F80023C */  lui        $v0, %hi(D_800E9EA8)
    /* 30688 8003FE88 A89E4224 */  addiu      $v0, $v0, %lo(D_800E9EA8)
    /* 3068C 8003FE8C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 30690 8003FE90 1000448C */  lw         $a0, 0x10($v0)
    /* 30694 8003FE94 1400458C */  lw         $a1, 0x14($v0)
    /* 30698 8003FE98 1800468C */  lw         $a2, 0x18($v0)
    /* 3069C 8003FE9C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 306A0 8003FEA0 000582A3 */  sb         $v0, %gp_rel(D_8009B408)($gp)
    /* 306A4 8003FEA4 641A010C */  jal        func_80046990
    /* 306A8 8003FEA8 00000000 */   nop
  .L8003FEAC:
    /* 306AC 8003FEAC 0F1C010C */  jal        func_8004703C
    /* 306B0 8003FEB0 00000000 */   nop
    /* 306B4 8003FEB4 08004230 */  andi       $v0, $v0, 0x8
    /* 306B8 8003FEB8 05004010 */  beqz       $v0, .L8003FED0
    /* 306BC 8003FEBC 00000000 */   nop
    /* 306C0 8003FEC0 534B000C */  jal        func_80012D4C
    /* 306C4 8003FEC4 00000000 */   nop
    /* 306C8 8003FEC8 ABFF0008 */  j          .L8003FEAC
    /* 306CC 8003FECC 00000000 */   nop
  .L8003FED0:
    /* 306D0 8003FED0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 306D4 8003FED4 00000000 */  nop
    /* 306D8 8003FED8 0800E003 */  jr         $ra
    /* 306DC 8003FEDC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003FE80
