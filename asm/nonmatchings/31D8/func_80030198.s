nonmatching func_80030198, 0xB8

glabel func_80030198
    /* 20998 80030198 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2099C 8003019C 01000424 */  addiu      $a0, $zero, 0x1
    /* 209A0 800301A0 80000224 */  addiu      $v0, $zero, 0x80
    /* 209A4 800301A4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 209A8 800301A8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 209AC 800301AC AA0382A3 */  sb         $v0, %gp_rel(D_8009B2B2)($gp)
    /* 209B0 800301B0 E30380A3 */  sb         $zero, %gp_rel(D_8009B2EB)($gp)
    /* 209B4 800301B4 E80380A3 */  sb         $zero, %gp_rel(D_8009B2F0)($gp)
    /* 209B8 800301B8 ABED000C */  jal        func_8003B6AC
    /* 209BC 800301BC 21288000 */   addu      $a1, $a0, $zero
    /* 209C0 800301C0 01000424 */  addiu      $a0, $zero, 0x1
    /* 209C4 800301C4 0F000524 */  addiu      $a1, $zero, 0xF
    /* 209C8 800301C8 20010224 */  addiu      $v0, $zero, 0x120
    /* 209CC 800301CC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 209D0 800301D0 A0000224 */  addiu      $v0, $zero, 0xA0
    /* 209D4 800301D4 10000624 */  addiu      $a2, $zero, 0x10
    /* 209D8 800301D8 2138C000 */  addu       $a3, $a2, $zero
    /* 209DC 800301DC F9D6000C */  jal        func_80035BE4
    /* 209E0 800301E0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 209E4 800301E4 21204000 */  addu       $a0, $v0, $zero
    /* 209E8 800301E8 10000224 */  addiu      $v0, $zero, 0x10
    /* 209EC 800301EC 5A0082A0 */  sb         $v0, 0x5A($a0)
    /* 209F0 800301F0 85E6000C */  jal        func_80039A14
    /* 209F4 800301F4 5B0082A0 */   sb        $v0, 0x5B($a0)
    /* 209F8 800301F8 0B00010C */  jal        func_8004002C
    /* 209FC 800301FC 00000000 */   nop
    /* 20A00 80030200 21204000 */  addu       $a0, $v0, $zero
    /* 20A04 80030204 2B00010C */  jal        func_800400AC
    /* 20A08 80030208 04000524 */   addiu     $a1, $zero, 0x4
    /* 20A0C 8003020C 21804000 */  addu       $s0, $v0, $zero
    /* 20A10 80030210 21200002 */  addu       $a0, $s0, $zero
    /* 20A14 80030214 DC0390AF */  sw         $s0, %gp_rel(D_8009B2E4)($gp)
    /* 20A18 80030218 F709010C */  jal        func_800427DC
    /* 20A1C 8003021C 21280000 */   addu      $a1, $zero, $zero
    /* 20A20 80030220 C0000224 */  addiu      $v0, $zero, 0xC0
    /* 20A24 80030224 450002A2 */  sb         $v0, 0x45($s0)
    /* 20A28 80030228 3D0002A2 */  sb         $v0, 0x3D($s0)
    /* 20A2C 8003022C 350002A2 */  sb         $v0, 0x35($s0)
    /* 20A30 80030230 32C0000C */  jal        func_800300C8
    /* 20A34 80030234 2D0002A2 */   sb        $v0, 0x2D($s0)
    /* 20A38 80030238 8056000C */  jal        func_80015A00
    /* 20A3C 8003023C 00000000 */   nop
    /* 20A40 80030240 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 20A44 80030244 1800B08F */  lw         $s0, 0x18($sp)
    /* 20A48 80030248 0800E003 */  jr         $ra
    /* 20A4C 8003024C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80030198
