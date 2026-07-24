nonmatching func_8003767C, 0xA0

glabel func_8003767C
    /* 27E7C 8003767C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 27E80 80037680 1000B0AF */  sw         $s0, 0x10($sp)
    /* 27E84 80037684 1400BFAF */  sw         $ra, 0x14($sp)
    /* 27E88 80037688 0A80013C */  lui        $at, %hi(D_8009B2AA)
    /* 27E8C 8003768C AAB220A4 */  sh         $zero, %lo(D_8009B2AA)($at)
    /* 27E90 80037690 0A80013C */  lui        $at, %hi(D_8009B2A8)
    /* 27E94 80037694 A8B220A4 */  sh         $zero, %lo(D_8009B2A8)($at)
    /* 27E98 80037698 4FDB000C */  jal        func_80036D3C
    /* 27E9C 8003769C 21808000 */   addu      $s0, $a0, $zero
    /* 27EA0 800376A0 0A80013C */  lui        $at, %hi(D_8009B270)
    /* 27EA4 800376A4 70B222A4 */  sh         $v0, %lo(D_8009B270)($at)
    /* 27EA8 800376A8 00804230 */  andi       $v0, $v0, 0x8000
    /* 27EAC 800376AC 11004010 */  beqz       $v0, .L800376F4
    /* 27EB0 800376B0 05000224 */   addiu     $v0, $zero, 0x5
    /* 27EB4 800376B4 58000282 */  lb         $v0, 0x58($s0)
    /* 27EB8 800376B8 00000000 */  nop
    /* 27EBC 800376BC 80100200 */  sll        $v0, $v0, 2
    /* 27EC0 800376C0 21100202 */  addu       $v0, $s0, $v0
    /* 27EC4 800376C4 0000438C */  lw         $v1, 0x0($v0)
    /* 27EC8 800376C8 00000000 */  nop
    /* 27ECC 800376CC 00006590 */  lbu        $a1, 0x0($v1)
    /* 27ED0 800376D0 01006324 */  addiu      $v1, $v1, 0x1
    /* 27ED4 800376D4 000043AC */  sw         $v1, 0x0($v0)
    /* 27ED8 800376D8 0A80013C */  lui        $at, %hi(D_8009B2AA)
    /* 27EDC 800376DC AAB225A4 */  sh         $a1, %lo(D_8009B2AA)($at)
    /* 27EE0 800376E0 4FDB000C */  jal        func_80036D3C
    /* 27EE4 800376E4 21200002 */   addu      $a0, $s0, $zero
    /* 27EE8 800376E8 0A80013C */  lui        $at, %hi(D_8009B2A8)
    /* 27EEC 800376EC A8B222A4 */  sh         $v0, %lo(D_8009B2A8)($at)
    /* 27EF0 800376F0 05000224 */  addiu      $v0, $zero, 0x5
  .L800376F4:
    /* 27EF4 800376F4 4F0482A3 */  sb         $v0, %gp_rel(D_8009B357)($gp)
    /* 27EF8 800376F8 05000224 */  addiu      $v0, $zero, 0x5
    /* 27EFC 800376FC 0A80013C */  lui        $at, %hi(D_8009B27C)
    /* 27F00 80037700 7CB222A4 */  sh         $v0, %lo(D_8009B27C)($at)
    /* 27F04 80037704 0A000224 */  addiu      $v0, $zero, 0xA
    /* 27F08 80037708 510002A2 */  sb         $v0, 0x51($s0)
    /* 27F0C 8003770C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 27F10 80037710 1000B08F */  lw         $s0, 0x10($sp)
    /* 27F14 80037714 0800E003 */  jr         $ra
    /* 27F18 80037718 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003767C
