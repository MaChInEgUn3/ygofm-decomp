nonmatching func_8004A7C0, 0x94

glabel func_8004A7C0
    /* 3AFC0 8004A7C0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3AFC4 8004A7C4 80280400 */  sll        $a1, $a0, 2
    /* 3AFC8 8004A7C8 2120A400 */  addu       $a0, $a1, $a0
    /* 3AFCC 8004A7CC C0200400 */  sll        $a0, $a0, 3
    /* 3AFD0 8004A7D0 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3AFD4 8004A7D4 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3AFD8 8004A7D8 80018424 */  addiu      $a0, $a0, 0x180
    /* 3AFDC 8004A7DC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3AFE0 8004A7E0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3AFE4 8004A7E4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3AFE8 8004A7E8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3AFEC 8004A7EC 21884400 */  addu       $s1, $v0, $a0
    /* 3AFF0 8004A7F0 03002292 */  lbu        $v0, 0x3($s1)
    /* 3AFF4 8004A7F4 00000000 */  nop
    /* 3AFF8 8004A7F8 1000422C */  sltiu      $v0, $v0, 0x10
    /* 3AFFC 8004A7FC 0F004010 */  beqz       $v0, .L8004A83C
    /* 3B000 8004A800 0180023C */   lui       $v0, %hi(D_80011434)
    /* 3B004 8004A804 34144224 */  addiu      $v0, $v0, %lo(D_80011434)
    /* 3B008 8004A808 2180A200 */  addu       $s0, $a1, $v0
    /* 3B00C 8004A80C 02001224 */  addiu      $s2, $zero, 0x2
  .L8004A810:
    /* 3B010 8004A810 0000058E */  lw         $a1, 0x0($s0)
    /* 3B014 8004A814 B4DB010C */  jal        func_80076ED0
    /* 3B018 8004A818 21200000 */   addu      $a0, $zero, $zero
    /* 3B01C 8004A81C 0000048E */  lw         $a0, 0x0($s0)
    /* 3B020 8004A820 24DC010C */  jal        func_80077090
    /* 3B024 8004A824 00000000 */   nop
    /* 3B028 8004A828 03005210 */  beq        $v0, $s2, .L8004A838
    /* 3B02C 8004A82C 00000000 */   nop
    /* 3B030 8004A830 F7FF4014 */  bnez       $v0, .L8004A810
    /* 3B034 8004A834 00000000 */   nop
  .L8004A838:
    /* 3B038 8004A838 0F0020A2 */  sb         $zero, 0xF($s1)
  .L8004A83C:
    /* 3B03C 8004A83C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3B040 8004A840 1800B28F */  lw         $s2, 0x18($sp)
    /* 3B044 8004A844 1400B18F */  lw         $s1, 0x14($sp)
    /* 3B048 8004A848 1000B08F */  lw         $s0, 0x10($sp)
    /* 3B04C 8004A84C 0800E003 */  jr         $ra
    /* 3B050 8004A850 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8004A7C0
