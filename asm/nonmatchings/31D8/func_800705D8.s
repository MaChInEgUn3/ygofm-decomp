nonmatching func_800705D8, 0x78

glabel func_800705D8
    /* 60DD8 800705D8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 60DDC 800705DC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 60DE0 800705E0 21888000 */  addu       $s1, $a0, $zero
    /* 60DE4 800705E4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 60DE8 800705E8 0F80123C */  lui        $s2, %hi(D_800F5BE8)
    /* 60DEC 800705EC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 60DF0 800705F0 E85B5026 */  addiu      $s0, $s2, %lo(D_800F5BE8)
    /* 60DF4 800705F4 21200002 */  addu       $a0, $s0, $zero
    /* 60DF8 800705F8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 60DFC 800705FC D838020C */  jal        func_8008E360
    /* 60E00 80070600 D4000524 */   addiu     $a1, $zero, 0xD4
    /* 60E04 80070604 0F80043C */  lui        $a0, %hi(D_800EAE88)
    /* 60E08 80070608 88AE8424 */  addiu      $a0, $a0, %lo(D_800EAE88)
    /* 60E0C 8007060C D838020C */  jal        func_8008E360
    /* 60E10 80070610 0C000524 */   addiu     $a1, $zero, 0xC
    /* 60E14 80070614 0F80043C */  lui        $a0, %hi(D_800F5B98)
    /* 60E18 80070618 985B8424 */  addiu      $a0, $a0, %lo(D_800F5B98)
    /* 60E1C 8007061C D838020C */  jal        func_8008E360
    /* 60E20 80070620 50000524 */   addiu     $a1, $zero, 0x50
    /* 60E24 80070624 02002016 */  bnez       $s1, .L80070630
    /* 60E28 80070628 01000224 */   addiu     $v0, $zero, 0x1
    /* 60E2C 8007062C E85B42A2 */  sb         $v0, %lo(D_800F5BE8)($s2)
  .L80070630:
    /* 60E30 80070630 040011AE */  sw         $s1, 0x4($s0)
    /* 60E34 80070634 080011AE */  sw         $s1, 0x8($s0)
    /* 60E38 80070638 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 60E3C 8007063C 1800B28F */  lw         $s2, 0x18($sp)
    /* 60E40 80070640 1400B18F */  lw         $s1, 0x14($sp)
    /* 60E44 80070644 1000B08F */  lw         $s0, 0x10($sp)
    /* 60E48 80070648 0800E003 */  jr         $ra
    /* 60E4C 8007064C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800705D8
