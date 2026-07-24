nonmatching func_80059FAC, 0x64

glabel func_80059FAC
    /* 4A7AC 80059FAC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4A7B0 80059FB0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4A7B4 80059FB4 21888000 */  addu       $s1, $a0, $zero
    /* 4A7B8 80059FB8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4A7BC 80059FBC 2190A000 */  addu       $s2, $a1, $zero
    /* 4A7C0 80059FC0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4A7C4 80059FC4 5D7C010C */  jal        func_8005F174
    /* 4A7C8 80059FC8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4A7CC 80059FCC 21804000 */  addu       $s0, $v0, $zero
    /* 4A7D0 80059FD0 01000224 */  addiu      $v0, $zero, 0x1
    /* 4A7D4 80059FD4 05000216 */  bne        $s0, $v0, .L80059FEC
    /* 4A7D8 80059FD8 0F80023C */   lui       $v0, %hi(D_800F2B20)
    /* 4A7DC 80059FDC 637C010C */  jal        func_8005F18C
    /* 4A7E0 80059FE0 00000000 */   nop
    /* 4A7E4 80059FE4 04005010 */  beq        $v0, $s0, .L80059FF8
    /* 4A7E8 80059FE8 0F80023C */   lui       $v0, %hi(D_800F2B20)
  .L80059FEC:
    /* 4A7EC 80059FEC 202B4224 */  addiu      $v0, $v0, %lo(D_800F2B20)
    /* 4A7F0 80059FF0 120051A4 */  sh         $s1, 0x12($v0)
    /* 4A7F4 80059FF4 1A0052A4 */  sh         $s2, 0x1A($v0)
  .L80059FF8:
    /* 4A7F8 80059FF8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4A7FC 80059FFC 1800B28F */  lw         $s2, 0x18($sp)
    /* 4A800 8005A000 1400B18F */  lw         $s1, 0x14($sp)
    /* 4A804 8005A004 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A808 8005A008 0800E003 */  jr         $ra
    /* 4A80C 8005A00C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80059FAC
