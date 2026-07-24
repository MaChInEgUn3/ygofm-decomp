nonmatching func_80019564, 0xA4

glabel func_80019564
    /* 9D64 80019564 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 9D68 80019568 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 9D6C 8001956C 21888000 */  addu       $s1, $a0, $zero
    /* 9D70 80019570 3000BFAF */  sw         $ra, 0x30($sp)
    /* 9D74 80019574 0B00010C */  jal        func_8004002C
    /* 9D78 80019578 2800B0AF */   sw        $s0, 0x28($sp)
    /* 9D7C 8001957C 21204000 */  addu       $a0, $v0, $zero
    /* 9D80 80019580 2B00010C */  jal        func_800400AC
    /* 9D84 80019584 01000524 */   addiu     $a1, $zero, 0x1
    /* 9D88 80019588 21804000 */  addu       $s0, $v0, $zero
    /* 9D8C 8001958C 21200002 */  addu       $a0, $s0, $zero
    /* 9D90 80019590 30002586 */  lh         $a1, 0x30($s1)
    /* 9D94 80019594 32002686 */  lh         $a2, 0x32($s1)
    /* 9D98 80019598 C4000224 */  addiu      $v0, $zero, 0xC4
    /* 9D9C 8001959C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 9DA0 800195A0 15000224 */  addiu      $v0, $zero, 0x15
    /* 9DA4 800195A4 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 9DA8 800195A8 1400A0AF */  sw         $zero, 0x14($sp)
    /* 9DAC 800195AC 1800A0AF */  sw         $zero, 0x18($sp)
    /* 9DB0 800195B0 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 9DB4 800195B4 2000A0AF */  sw         $zero, 0x20($sp)
    /* 9DB8 800195B8 4401010C */  jal        func_80040510
    /* 9DBC 800195BC 2400A0AF */   sw        $zero, 0x24($sp)
    /* 9DC0 800195C0 21200002 */  addu       $a0, $s0, $zero
    /* 9DC4 800195C4 46000224 */  addiu      $v0, $zero, 0x46
    /* 9DC8 800195C8 180002A6 */  sh         $v0, 0x18($s0)
    /* 9DCC 800195CC 480002A6 */  sh         $v0, 0x48($s0)
    /* 9DD0 800195D0 62000224 */  addiu      $v0, $zero, 0x62
    /* 9DD4 800195D4 1A0002A6 */  sh         $v0, 0x1A($s0)
    /* 9DD8 800195D8 460A010C */  jal        func_80042918
    /* 9DDC 800195DC 4A0002A6 */   sh        $v0, 0x4A($s0)
    /* 9DE0 800195E0 21100002 */  addu       $v0, $s0, $zero
    /* 9DE4 800195E4 0400438C */  lw         $v1, 0x4($v0)
    /* 9DE8 800195E8 0002043C */  lui        $a0, (0x2000000 >> 16)
    /* 9DEC 800195EC 25186400 */  or         $v1, $v1, $a0
    /* 9DF0 800195F0 040043AC */  sw         $v1, 0x4($v0)
    /* 9DF4 800195F4 3000BF8F */  lw         $ra, 0x30($sp)
    /* 9DF8 800195F8 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 9DFC 800195FC 2800B08F */  lw         $s0, 0x28($sp)
    /* 9E00 80019600 0800E003 */  jr         $ra
    /* 9E04 80019604 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_80019564
