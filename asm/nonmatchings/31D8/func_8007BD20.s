nonmatching func_8007BD20, 0xE0

glabel func_8007BD20
    /* 6C520 8007BD20 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C524 8007BD24 03000324 */  addiu      $v1, $zero, 0x3
    /* 6C528 8007BD28 0980023C */  lui        $v0, %hi(D_80093880)
    /* 6C52C 8007BD2C 80384224 */  addiu      $v0, $v0, %lo(D_80093880)
    /* 6C530 8007BD30 08004424 */  addiu      $a0, $v0, 0x8
    /* 6C534 8007BD34 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6C538 8007BD38 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C53C 8007BD3C 000040AC */  sw         $zero, 0x0($v0)
    /* 6C540 8007BD40 040040A0 */  sb         $zero, 0x4($v0)
  .L8007BD44:
    /* 6C544 8007BD44 000080A0 */  sb         $zero, 0x0($a0)
    /* 6C548 8007BD48 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 6C54C 8007BD4C FDFF6104 */  bgez       $v1, .L8007BD44
    /* 6C550 8007BD50 FFFF8424 */   addiu     $a0, $a0, -0x1
    /* 6C554 8007BD54 0980023C */  lui        $v0, %hi(D_8009388C)
    /* 6C558 8007BD58 8C384224 */  addiu      $v0, $v0, %lo(D_8009388C)
    /* 6C55C 8007BD5C 000040AC */  sw         $zero, 0x0($v0)
    /* 6C560 8007BD60 07000324 */  addiu      $v1, $zero, 0x7
    /* 6C564 8007BD64 0B004224 */  addiu      $v0, $v0, 0xB
  .L8007BD68:
    /* 6C568 8007BD68 000040A0 */  sb         $zero, 0x0($v0)
    /* 6C56C 8007BD6C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 6C570 8007BD70 FDFF6104 */  bgez       $v1, .L8007BD68
    /* 6C574 8007BD74 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 6C578 8007BD78 0980103C */  lui        $s0, %hi(D_80093898)
    /* 6C57C 8007BD7C 98381026 */  addiu      $s0, $s0, %lo(D_80093898)
    /* 6C580 8007BD80 02000224 */  addiu      $v0, $zero, 0x2
    /* 6C584 8007BD84 080002AE */  sw         $v0, 0x8($s0)
    /* 6C588 8007BD88 0E000224 */  addiu      $v0, $zero, 0xE
    /* 6C58C 8007BD8C 0C0002AE */  sw         $v0, 0xC($s0)
    /* 6C590 8007BD90 15000224 */  addiu      $v0, $zero, 0x15
    /* 6C594 8007BD94 21200000 */  addu       $a0, $zero, $zero
    /* 6C598 8007BD98 16000526 */  addiu      $a1, $s0, 0x16
    /* 6C59C 8007BD9C 000000A2 */  sb         $zero, 0x0($s0)
    /* 6C5A0 8007BDA0 040000AE */  sw         $zero, 0x4($s0)
    /* 6C5A4 8007BDA4 100002AE */  sw         $v0, 0x10($s0)
    /* 6C5A8 8007BDA8 140000A2 */  sb         $zero, 0x14($s0)
    /* 6C5AC 8007BDAC 80F9010C */  jal        func_8007E600
    /* 6C5B0 8007BDB0 150000A2 */   sb        $zero, 0x15($s0)
    /* 6C5B4 8007BDB4 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C5B8 8007BDB8 1A0000A2 */  sb         $zero, 0x1A($s0)
    /* 6C5BC 8007BDBC 1B0000A2 */  sb         $zero, 0x1B($s0)
    /* 6C5C0 8007BDC0 1C0000A2 */  sb         $zero, 0x1C($s0)
    /* 6C5C4 8007BDC4 1D0000A2 */  sb         $zero, 0x1D($s0)
    /* 6C5C8 8007BDC8 1E0000A2 */  sb         $zero, 0x1E($s0)
    /* 6C5CC 8007BDCC 1F0000A2 */  sb         $zero, 0x1F($s0)
    /* 6C5D0 8007BDD0 200000AE */  sw         $zero, 0x20($s0)
    /* 6C5D4 8007BDD4 240002AE */  sw         $v0, 0x24($s0)
    /* 6C5D8 8007BDD8 280000AE */  sw         $zero, 0x28($s0)
    /* 6C5DC 8007BDDC 300000AE */  sw         $zero, 0x30($s0)
    /* 6C5E0 8007BDE0 2C0000AE */  sw         $zero, 0x2C($s0)
    /* 6C5E4 8007BDE4 340000AE */  sw         $zero, 0x34($s0)
    /* 6C5E8 8007BDE8 380000A2 */  sb         $zero, 0x38($s0)
    /* 6C5EC 8007BDEC 390000A2 */  sb         $zero, 0x39($s0)
    /* 6C5F0 8007BDF0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6C5F4 8007BDF4 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C5F8 8007BDF8 0800E003 */  jr         $ra
    /* 6C5FC 8007BDFC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BD20
