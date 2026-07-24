nonmatching func_80013B68, 0xC0

glabel func_80013B68
    /* 4368 80013B68 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 436C 80013B6C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4370 80013B70 21888000 */  addu       $s1, $a0, $zero
    /* 4374 80013B74 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4378 80013B78 2190A000 */  addu       $s2, $a1, $zero
    /* 437C 80013B7C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 4380 80013B80 2198C000 */  addu       $s3, $a2, $zero
    /* 4384 80013B84 2000B4AF */  sw         $s4, 0x20($sp)
    /* 4388 80013B88 21A0E000 */  addu       $s4, $a3, $zero
    /* 438C 80013B8C EC01828F */  lw         $v0, %gp_rel(D_8009B0F4)($gp)
    /* 4390 80013B90 DFFF0324 */  addiu      $v1, $zero, -0x21
    /* 4394 80013B94 2400BFAF */  sw         $ra, 0x24($sp)
    /* 4398 80013B98 1000B0AF */  sw         $s0, 0x10($sp)
    /* 439C 80013B9C 24104300 */  and        $v0, $v0, $v1
    /* 43A0 80013BA0 0F80033C */  lui        $v1, %hi(D_800E9E18)
    /* 43A4 80013BA4 EC0182AF */  sw         $v0, %gp_rel(D_8009B0F4)($gp)
    /* 43A8 80013BA8 EC01828F */  lw         $v0, %gp_rel(D_8009B0F4)($gp)
    /* 43AC 80013BAC 00000000 */  nop
    /* 43B0 80013BB0 10004230 */  andi       $v0, $v0, 0x10
    /* 43B4 80013BB4 08004010 */  beqz       $v0, .L80013BD8
    /* 43B8 80013BB8 189E7024 */   addiu     $s0, $v1, %lo(D_800E9E18)
    /* 43BC 80013BBC EC01828F */  lw         $v0, %gp_rel(D_8009B0F4)($gp)
    /* 43C0 80013BC0 0800033C */  lui        $v1, (0x80000 >> 16)
    /* 43C4 80013BC4 24104300 */  and        $v0, $v0, $v1
    /* 43C8 80013BC8 04004010 */  beqz       $v0, .L80013BDC
    /* 43CC 80013BCC 04000224 */   addiu     $v0, $zero, 0x4
    /* 43D0 80013BD0 0454000C */  jal        func_80015010
    /* 43D4 80013BD4 00000000 */   nop
  .L80013BD8:
    /* 43D8 80013BD8 04000224 */  addiu      $v0, $zero, 0x4
  .L80013BDC:
    /* 43DC 80013BDC 380013A2 */  sb         $s3, 0x38($s0)
    /* 43E0 80013BE0 390014A2 */  sb         $s4, 0x39($s0)
    /* 43E4 80013BE4 460002A2 */  sb         $v0, 0x46($s0)
    /* 43E8 80013BE8 EC01828F */  lw         $v0, %gp_rel(D_8009B0F4)($gp)
    /* 43EC 80013BEC 0800033C */  lui        $v1, (0x80000 >> 16)
    /* 43F0 80013BF0 240011AE */  sw         $s1, 0x24($s0)
    /* 43F4 80013BF4 340012AE */  sw         $s2, 0x34($s0)
    /* 43F8 80013BF8 2C0003AE */  sw         $v1, 0x2C($s0)
    /* 43FC 80013BFC 2400BF8F */  lw         $ra, 0x24($sp)
    /* 4400 80013C00 2000B48F */  lw         $s4, 0x20($sp)
    /* 4404 80013C04 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4408 80013C08 1800B28F */  lw         $s2, 0x18($sp)
    /* 440C 80013C0C 1400B18F */  lw         $s1, 0x14($sp)
    /* 4410 80013C10 20004234 */  ori        $v0, $v0, 0x20
    /* 4414 80013C14 EC0182AF */  sw         $v0, %gp_rel(D_8009B0F4)($gp)
    /* 4418 80013C18 21100002 */  addu       $v0, $s0, $zero
    /* 441C 80013C1C 1000B08F */  lw         $s0, 0x10($sp)
    /* 4420 80013C20 0800E003 */  jr         $ra
    /* 4424 80013C24 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80013B68
