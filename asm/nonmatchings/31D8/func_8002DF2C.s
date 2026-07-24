nonmatching func_8002DF2C, 0xE0

glabel func_8002DF2C
    /* 1E72C 8002DF2C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1E730 8002DF30 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1E734 8002DF34 02008010 */  beqz       $a0, .L8002DF40
    /* 1E738 8002DF38 2000B0AF */   sw        $s0, 0x20($sp)
    /* 1E73C 8002DF3C 3C0085A4 */  sh         $a1, 0x3C($a0)
  .L8002DF40:
    /* 1E740 8002DF40 03110500 */  sra        $v0, $a1, 4
    /* 1E744 8002DF44 0F004230 */  andi       $v0, $v0, 0xF
    /* 1E748 8002DF48 80180200 */  sll        $v1, $v0, 2
    /* 1E74C 8002DF4C 21186200 */  addu       $v1, $v1, $v0
    /* 1E750 8002DF50 40180300 */  sll        $v1, $v1, 1
    /* 1E754 8002DF54 0F00A230 */  andi       $v0, $a1, 0xF
    /* 1E758 8002DF58 21186200 */  addu       $v1, $v1, $v0
    /* 1E75C 8002DF5C 032A0500 */  sra        $a1, $a1, 8
    /* 1E760 8002DF60 01000224 */  addiu      $v0, $zero, 0x1
    /* 1E764 8002DF64 0E00A210 */  beq        $a1, $v0, .L8002DFA0
    /* 1E768 8002DF68 0200A228 */   slti      $v0, $a1, 0x2
    /* 1E76C 8002DF6C 05004010 */  beqz       $v0, .L8002DF84
    /* 1E770 8002DF70 00000000 */   nop
    /* 1E774 8002DF74 0800A010 */  beqz       $a1, .L8002DF98
    /* 1E778 8002DF78 21001024 */   addiu     $s0, $zero, 0x21
    /* 1E77C 8002DF7C FFB70008 */  j          .L8002DFFC
    /* 1E780 8002DF80 00000000 */   nop
  .L8002DF84:
    /* 1E784 8002DF84 02000224 */  addiu      $v0, $zero, 0x2
    /* 1E788 8002DF88 0800A210 */  beq        $a1, $v0, .L8002DFAC
    /* 1E78C 8002DF8C 71001024 */   addiu     $s0, $zero, 0x71
    /* 1E790 8002DF90 FFB70008 */  j          .L8002DFFC
    /* 1E794 8002DF94 00000000 */   nop
  .L8002DF98:
    /* 1E798 8002DF98 ECB70008 */  j          .L8002DFB0
    /* 1E79C 8002DF9C 21300000 */   addu      $a2, $zero, $zero
  .L8002DFA0:
    /* 1E7A0 8002DFA0 51001024 */  addiu      $s0, $zero, 0x51
    /* 1E7A4 8002DFA4 ECB70008 */  j          .L8002DFB0
    /* 1E7A8 8002DFA8 72060624 */   addiu     $a2, $zero, 0x672
  .L8002DFAC:
    /* 1E7AC 8002DFAC BC130624 */  addiu      $a2, $zero, 0x13BC
  .L8002DFB0:
    /* 1E7B0 8002DFB0 18007000 */  mult       $v1, $s0
    /* 1E7B4 8002DFB4 0380023C */  lui        $v0, %hi(D_8002DDFC)
    /* 1E7B8 8002DFB8 FCDD4224 */  addiu      $v0, $v0, %lo(D_8002DDFC)
    /* 1E7BC 8002DFBC 21200000 */  addu       $a0, $zero, $zero
    /* 1E7C0 8002DFC0 21288000 */  addu       $a1, $a0, $zero
    /* 1E7C4 8002DFC4 21380002 */  addu       $a3, $s0, $zero
    /* 1E7C8 8002DFC8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1E7CC 8002DFCC 1400A0AF */  sw         $zero, 0x14($sp)
    /* 1E7D0 8002DFD0 1800A0AF */  sw         $zero, 0x18($sp)
    /* 1E7D4 8002DFD4 12400000 */  mflo       $t0
    /* 1E7D8 8002DFD8 2130C800 */  addu       $a2, $a2, $t0
    /* 1E7DC 8002DFDC BB53000C */  jal        func_80014EEC
    /* 1E7E0 8002DFE0 D521C624 */   addiu     $a2, $a2, 0x21D5
    /* 1E7E4 8002DFE4 2C00438C */  lw         $v1, 0x2C($v0)
    /* 1E7E8 8002DFE8 FFFF0426 */  addiu      $a0, $s0, -0x1
    /* 1E7EC 8002DFEC 380044AC */  sw         $a0, 0x38($v0)
    /* 1E7F0 8002DFF0 10006334 */  ori        $v1, $v1, 0x10
    /* 1E7F4 8002DFF4 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 1E7F8 8002DFF8 F4B023AC */  sw         $v1, %lo(D_8009B0F4)($at)
  .L8002DFFC:
    /* 1E7FC 8002DFFC 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1E800 8002E000 2000B08F */  lw         $s0, 0x20($sp)
    /* 1E804 8002E004 0800E003 */  jr         $ra
    /* 1E808 8002E008 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8002DF2C
