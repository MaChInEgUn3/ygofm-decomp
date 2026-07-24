nonmatching func_8003F758, 0x7C

glabel func_8003F758
    /* 2FF58 8003F758 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2FF5C 8003F75C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2FF60 8003F760 21908000 */  addu       $s2, $a0, $zero
    /* 2FF64 8003F764 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2FF68 8003F768 2180A000 */  addu       $s0, $a1, $zero
    /* 2FF6C 8003F76C 0F80043C */  lui        $a0, %hi(D_800EFE18)
    /* 2FF70 8003F770 18FE8424 */  addiu      $a0, $a0, %lo(D_800EFE18)
    /* 2FF74 8003F774 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2FF78 8003F778 2188E000 */  addu       $s1, $a3, $zero
    /* 2FF7C 8003F77C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2FF80 8003F780 BC39020C */  jal        func_8008E6F0
    /* 2FF84 8003F784 2128C000 */   addu      $a1, $a2, $zero
    /* 2FF88 8003F788 FF1F0326 */  addiu      $v1, $s0, 0x1FFF
    /* 2FF8C 8003F78C 00020224 */  addiu      $v0, $zero, 0x200
    /* 2FF90 8003F790 F10480A3 */  sb         $zero, %gp_rel(D_8009B3F9)($gp)
    /* 2FF94 8003F794 BA0490A7 */  sh         $s0, %gp_rel(D_8009B3C2)($gp)
    /* 2FF98 8003F798 BC0482A7 */  sh         $v0, %gp_rel(D_8009B3C4)($gp)
    /* 2FF9C 8003F79C 03006104 */  bgez       $v1, .L8003F7AC
    /* 2FFA0 8003F7A0 43130300 */   sra       $v0, $v1, 13
    /* 2FFA4 8003F7A4 FE3F0326 */  addiu      $v1, $s0, 0x3FFE
    /* 2FFA8 8003F7A8 43130300 */  sra        $v0, $v1, 13
  .L8003F7AC:
    /* 2FFAC 8003F7AC D40482A3 */  sb         $v0, %gp_rel(D_8009B3DC)($gp)
    /* 2FFB0 8003F7B0 C80492AF */  sw         $s2, %gp_rel(D_8009B3D0)($gp)
    /* 2FFB4 8003F7B4 D0FD000C */  jal        func_8003F740
    /* 2FFB8 8003F7B8 21202002 */   addu      $a0, $s1, $zero
    /* 2FFBC 8003F7BC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2FFC0 8003F7C0 1800B28F */  lw         $s2, 0x18($sp)
    /* 2FFC4 8003F7C4 1400B18F */  lw         $s1, 0x14($sp)
    /* 2FFC8 8003F7C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 2FFCC 8003F7CC 0800E003 */  jr         $ra
    /* 2FFD0 8003F7D0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003F758
