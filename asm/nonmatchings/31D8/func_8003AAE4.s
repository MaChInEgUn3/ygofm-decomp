nonmatching func_8003AAE4, 0x164

glabel func_8003AAE4
    /* 2B2E4 8003AAE4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2B2E8 8003AAE8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2B2EC 8003AAEC 21988000 */  addu       $s3, $a0, $zero
    /* 2B2F0 8003AAF0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2B2F4 8003AAF4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2B2F8 8003AAF8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2B2FC 8003AAFC C7E7000C */  jal        func_80039F1C
    /* 2B300 8003AB00 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2B304 8003AB04 1E004014 */  bnez       $v0, .L8003AB80
    /* 2B308 8003AB08 68000224 */   addiu     $v0, $zero, 0x68
    /* 2B30C 8003AB0C 340062A6 */  sh         $v0, 0x34($s3)
    /* 2B310 8003AB10 32006292 */  lbu        $v0, 0x32($s3)
    /* 2B314 8003AB14 3C006392 */  lbu        $v1, 0x3C($s3)
    /* 2B318 8003AB18 10004234 */  ori        $v0, $v0, 0x10
    /* 2B31C 8003AB1C 03006010 */  beqz       $v1, .L8003AB2C
    /* 2B320 8003AB20 320062A2 */   sb        $v0, 0x32($s3)
    /* 2B324 8003AB24 D8000224 */  addiu      $v0, $zero, 0xD8
    /* 2B328 8003AB28 340062A6 */  sh         $v0, 0x34($s3)
  .L8003AB2C:
    /* 2B32C 8003AB2C 34006586 */  lh         $a1, 0x34($s3)
    /* 2B330 8003AB30 36006686 */  lh         $a2, 0x36($s3)
    /* 2B334 8003AB34 48EA000C */  jal        func_8003A920
    /* 2B338 8003AB38 21206002 */   addu      $a0, $s3, $zero
    /* 2B33C 8003AB3C 21206002 */  addu       $a0, $s3, $zero
    /* 2B340 8003AB40 0000628E */  lw         $v0, 0x0($s3)
    /* 2B344 8003AB44 0050053C */  lui        $a1, (0x50000000 >> 16)
    /* 2B348 8003AB48 16005280 */  lb         $s2, 0x16($v0)
    /* 2B34C 8003AB4C 67005190 */  lbu        $s1, 0x67($v0)
    /* 2B350 8003AB50 10E9000C */  jal        func_8003A440
    /* 2B354 8003AB54 21304002 */   addu      $a2, $s2, $zero
    /* 2B358 8003AB58 21206002 */  addu       $a0, $s3, $zero
    /* 2B35C 8003AB5C 0C007026 */  addiu      $s0, $s3, 0xC
    /* 2B360 8003AB60 21280002 */  addu       $a1, $s0, $zero
    /* 2B364 8003AB64 7BE8000C */  jal        func_8003A1EC
    /* 2B368 8003AB68 21302002 */   addu      $a2, $s1, $zero
    /* 2B36C 8003AB6C 21200002 */  addu       $a0, $s0, $zero
    /* 2B370 8003AB70 0060053C */  lui        $a1, (0x60000000 >> 16)
    /* 2B374 8003AB74 10E9000C */  jal        func_8003A440
    /* 2B378 8003AB78 FFFF4626 */   addiu     $a2, $s2, -0x1
    /* 2B37C 8003AB7C 400060A6 */  sh         $zero, 0x40($s3)
  .L8003AB80:
    /* 2B380 8003AB80 0A80023C */  lui        $v0, %hi(D_8009B0D8)
    /* 2B384 8003AB84 D8B0428C */  lw         $v0, %lo(D_8009B0D8)($v0)
    /* 2B388 8003AB88 40006396 */  lhu        $v1, 0x40($s3)
    /* 2B38C 8003AB8C C0100200 */  sll        $v0, $v0, 3
    /* 2B390 8003AB90 21186200 */  addu       $v1, $v1, $v0
    /* 2B394 8003AB94 400063A6 */  sh         $v1, 0x40($s3)
    /* 2B398 8003AB98 001C0300 */  sll        $v1, $v1, 16
    /* 2B39C 8003AB9C 031C0300 */  sra        $v1, $v1, 16
    /* 2B3A0 8003ABA0 80006228 */  slti       $v0, $v1, 0x80
    /* 2B3A4 8003ABA4 0E004014 */  bnez       $v0, .L8003ABE0
    /* 2B3A8 8003ABA8 00120300 */   sll       $v0, $v1, 8
    /* 2B3AC 8003ABAC 0000628E */  lw         $v0, 0x0($s3)
    /* 2B3B0 8003ABB0 21206002 */  addu       $a0, $s3, $zero
    /* 2B3B4 8003ABB4 330060A2 */  sb         $zero, 0x33($s3)
    /* 2B3B8 8003ABB8 16004680 */  lb         $a2, 0x16($v0)
    /* 2B3BC 8003ABBC 10E9000C */  jal        func_8003A440
    /* 2B3C0 8003ABC0 21280000 */   addu      $a1, $zero, $zero
    /* 2B3C4 8003ABC4 E4E7000C */  jal        func_80039F90
    /* 2B3C8 8003ABC8 0C006426 */   addiu     $a0, $s3, 0xC
    /* 2B3CC 8003ABCC 32006292 */  lbu        $v0, 0x32($s3)
    /* 2B3D0 8003ABD0 00000000 */  nop
    /* 2B3D4 8003ABD4 EF004230 */  andi       $v0, $v0, 0xEF
    /* 2B3D8 8003ABD8 0BEB0008 */  j          .L8003AC2C
    /* 2B3DC 8003ABDC 320062A2 */   sb        $v0, 0x32($s3)
  .L8003ABE0:
    /* 2B3E0 8003ABE0 21206000 */  addu       $a0, $v1, $zero
    /* 2B3E4 8003ABE4 001C0400 */  sll        $v1, $a0, 16
    /* 2B3E8 8003ABE8 25104300 */  or         $v0, $v0, $v1
    /* 2B3EC 8003ABEC 25208200 */  or         $a0, $a0, $v0
    /* 2B3F0 8003ABF0 02000524 */  addiu      $a1, $zero, 0x2
    /* 2B3F4 8003ABF4 08006226 */  addiu      $v0, $s3, 0x8
  .L8003ABF8:
    /* 2B3F8 8003ABF8 0000438C */  lw         $v1, 0x0($v0)
    /* 2B3FC 8003ABFC 00000000 */  nop
    /* 2B400 8003AC00 02006010 */  beqz       $v1, .L8003AC0C
    /* 2B404 8003AC04 00000000 */   nop
    /* 2B408 8003AC08 0C0064AC */  sw         $a0, 0xC($v1)
  .L8003AC0C:
    /* 2B40C 8003AC0C 0C00438C */  lw         $v1, 0xC($v0)
    /* 2B410 8003AC10 00000000 */  nop
    /* 2B414 8003AC14 02006010 */  beqz       $v1, .L8003AC20
    /* 2B418 8003AC18 00000000 */   nop
    /* 2B41C 8003AC1C 0C0064AC */  sw         $a0, 0xC($v1)
  .L8003AC20:
    /* 2B420 8003AC20 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 2B424 8003AC24 F4FFA104 */  bgez       $a1, .L8003ABF8
    /* 2B428 8003AC28 FCFF4224 */   addiu     $v0, $v0, -0x4
  .L8003AC2C:
    /* 2B42C 8003AC2C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2B430 8003AC30 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2B434 8003AC34 1800B28F */  lw         $s2, 0x18($sp)
    /* 2B438 8003AC38 1400B18F */  lw         $s1, 0x14($sp)
    /* 2B43C 8003AC3C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2B440 8003AC40 0800E003 */  jr         $ra
    /* 2B444 8003AC44 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003AAE4
