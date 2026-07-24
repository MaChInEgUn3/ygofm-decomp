nonmatching func_8005A010, 0x64

glabel func_8005A010
    /* 4A810 8005A010 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4A814 8005A014 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4A818 8005A018 21888000 */  addu       $s1, $a0, $zero
    /* 4A81C 8005A01C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4A820 8005A020 2190A000 */  addu       $s2, $a1, $zero
    /* 4A824 8005A024 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4A828 8005A028 5D7C010C */  jal        func_8005F174
    /* 4A82C 8005A02C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4A830 8005A030 21804000 */  addu       $s0, $v0, $zero
    /* 4A834 8005A034 01000224 */  addiu      $v0, $zero, 0x1
    /* 4A838 8005A038 05000216 */  bne        $s0, $v0, .L8005A050
    /* 4A83C 8005A03C 0F80023C */   lui       $v0, %hi(D_800F2B20)
    /* 4A840 8005A040 637C010C */  jal        func_8005F18C
    /* 4A844 8005A044 00000000 */   nop
    /* 4A848 8005A048 04005010 */  beq        $v0, $s0, .L8005A05C
    /* 4A84C 8005A04C 0F80023C */   lui       $v0, %hi(D_800F2B20)
  .L8005A050:
    /* 4A850 8005A050 202B4224 */  addiu      $v0, $v0, %lo(D_800F2B20)
    /* 4A854 8005A054 220051A4 */  sh         $s1, 0x22($v0)
    /* 4A858 8005A058 2A0052A4 */  sh         $s2, 0x2A($v0)
  .L8005A05C:
    /* 4A85C 8005A05C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4A860 8005A060 1800B28F */  lw         $s2, 0x18($sp)
    /* 4A864 8005A064 1400B18F */  lw         $s1, 0x14($sp)
    /* 4A868 8005A068 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A86C 8005A06C 0800E003 */  jr         $ra
    /* 4A870 8005A070 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8005A010
