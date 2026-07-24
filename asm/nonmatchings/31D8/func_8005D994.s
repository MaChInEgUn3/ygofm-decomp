nonmatching func_8005D994, 0x210

glabel func_8005D994
    /* 4E194 8005D994 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 4E198 8005D998 2400B1AF */  sw         $s1, 0x24($sp)
    /* 4E19C 8005D99C 5000B18F */  lw         $s1, 0x50($sp)
    /* 4E1A0 8005D9A0 2800B2AF */  sw         $s2, 0x28($sp)
    /* 4E1A4 8005D9A4 21908000 */  addu       $s2, $a0, $zero
    /* 4E1A8 8005D9A8 3000B4AF */  sw         $s4, 0x30($sp)
    /* 4E1AC 8005D9AC 21A0A000 */  addu       $s4, $a1, $zero
    /* 4E1B0 8005D9B0 3400B5AF */  sw         $s5, 0x34($sp)
    /* 4E1B4 8005D9B4 21A8C000 */  addu       $s5, $a2, $zero
    /* 4E1B8 8005D9B8 3800B6AF */  sw         $s6, 0x38($sp)
    /* 4E1BC 8005D9BC 21B0E000 */  addu       $s6, $a3, $zero
    /* 4E1C0 8005D9C0 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 4E1C4 8005D9C4 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 4E1C8 8005D9C8 8264010C */  jal        func_80059208
    /* 4E1CC 8005D9CC 2000B0AF */   sw        $s0, 0x20($sp)
    /* 4E1D0 8005D9D0 1000A427 */  addiu      $a0, $sp, 0x10
    /* 4E1D4 8005D9D4 21280000 */  addu       $a1, $zero, $zero
    /* 4E1D8 8005D9D8 08000624 */  addiu      $a2, $zero, 0x8
    /* 4E1DC 8005D9DC F438020C */  jal        func_8008E3D0
    /* 4E1E0 8005D9E0 21984000 */   addu      $s3, $v0, $zero
    /* 4E1E4 8005D9E4 80004236 */  ori        $v0, $s2, 0x80
    /* 4E1E8 8005D9E8 1600A2A7 */  sh         $v0, 0x16($sp)
    /* 4E1EC 8005D9EC 73018293 */  lbu        $v0, %gp_rel(D_8009B07B)($gp)
    /* 4E1F0 8005D9F0 01001024 */  addiu      $s0, $zero, 0x1
    /* 4E1F4 8005D9F4 05005014 */  bne        $v0, $s0, .L8005DA0C
    /* 4E1F8 8005D9F8 02000224 */   addiu     $v0, $zero, 0x2
    /* 4E1FC 8005D9FC 74018293 */  lbu        $v0, %gp_rel(D_8009B07C)($gp)
    /* 4E200 8005DA00 00000000 */  nop
    /* 4E204 8005DA04 5D005010 */  beq        $v0, $s0, .L8005DB7C
    /* 4E208 8005DA08 02000224 */   addiu     $v0, $zero, 0x2
  .L8005DA0C:
    /* 4E20C 8005DA0C 04004216 */  bne        $s2, $v0, .L8005DA20
    /* 4E210 8005DA10 21204000 */   addu      $a0, $v0, $zero
    /* 4E214 8005DA14 EC63010C */  jal        func_80058FB0
    /* 4E218 8005DA18 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4E21C 8005DA1C 1600B0A7 */  sh         $s0, 0x16($sp)
  .L8005DA20:
    /* 4E220 8005DA20 17002012 */  beqz       $s1, .L8005DA80
    /* 4E224 8005DA24 00000000 */   nop
    /* 4E228 8005DA28 0200401E */  bgtz       $s2, .L8005DA34
    /* 4E22C 8005DA2C FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 4E230 8005DA30 01000424 */  addiu      $a0, $zero, 0x1
  .L8005DA34:
    /* 4E234 8005DA34 00002286 */  lh         $v0, 0x0($s1)
    /* 4E238 8005DA38 00000000 */  nop
    /* 4E23C 8005DA3C 18004400 */  mult       $v0, $a0
    /* 4E240 8005DA40 1000A297 */  lhu        $v0, 0x10($sp)
    /* 4E244 8005DA44 12400000 */  mflo       $t0
    /* 4E248 8005DA48 21104800 */  addu       $v0, $v0, $t0
    /* 4E24C 8005DA4C 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 4E250 8005DA50 1200A297 */  lhu        $v0, 0x12($sp)
    /* 4E254 8005DA54 02002396 */  lhu        $v1, 0x2($s1)
    /* 4E258 8005DA58 00000000 */  nop
    /* 4E25C 8005DA5C 21104300 */  addu       $v0, $v0, $v1
    /* 4E260 8005DA60 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 4E264 8005DA64 04002286 */  lh         $v0, 0x4($s1)
    /* 4E268 8005DA68 00000000 */  nop
    /* 4E26C 8005DA6C 18004400 */  mult       $v0, $a0
    /* 4E270 8005DA70 1400A297 */  lhu        $v0, 0x14($sp)
    /* 4E274 8005DA74 12400000 */  mflo       $t0
    /* 4E278 8005DA78 21104800 */  addu       $v0, $v0, $t0
    /* 4E27C 8005DA7C 1400A2A7 */  sh         $v0, 0x14($sp)
  .L8005DA80:
    /* 4E280 8005DA80 1800B4A7 */  sh         $s4, 0x18($sp)
    /* 4E284 8005DA84 02006286 */  lh         $v0, 0x2($s3)
    /* 4E288 8005DA88 0300401E */  bgtz       $s2, .L8005DA98
    /* 4E28C 8005DA8C 0010A626 */   addiu     $a2, $s5, 0x1000
    /* 4E290 8005DA90 A7760108 */  j          .L8005DA9C
    /* 4E294 8005DA94 00F44224 */   addiu     $v0, $v0, -0xC00
  .L8005DA98:
    /* 4E298 8005DA98 00FC4224 */  addiu      $v0, $v0, -0x400
  .L8005DA9C:
    /* 4E29C 8005DA9C 2330C200 */  subu       $a2, $a2, $v0
    /* 4E2A0 8005DAA0 0200C104 */  bgez       $a2, .L8005DAAC
    /* 4E2A4 8005DAA4 2110C000 */   addu      $v0, $a2, $zero
    /* 4E2A8 8005DAA8 FF0FC224 */  addiu      $v0, $a2, 0xFFF
  .L8005DAAC:
    /* 4E2AC 8005DAAC 03130200 */  sra        $v0, $v0, 12
    /* 4E2B0 8005DAB0 00130200 */  sll        $v0, $v0, 12
    /* 4E2B4 8005DAB4 2310C200 */  subu       $v0, $a2, $v0
    /* 4E2B8 8005DAB8 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 4E2BC 8005DABC 1A00A287 */  lh         $v0, 0x1A($sp)
    /* 4E2C0 8005DAC0 1A00A397 */  lhu        $v1, 0x1A($sp)
    /* 4E2C4 8005DAC4 01084228 */  slti       $v0, $v0, 0x801
    /* 4E2C8 8005DAC8 02004014 */  bnez       $v0, .L8005DAD4
    /* 4E2CC 8005DACC 00F06224 */   addiu     $v0, $v1, -0x1000
    /* 4E2D0 8005DAD0 1A00A2A7 */  sh         $v0, 0x1A($sp)
  .L8005DAD4:
    /* 4E2D4 8005DAD4 1A00A287 */  lh         $v0, 0x1A($sp)
    /* 4E2D8 8005DAD8 1A00A397 */  lhu        $v1, 0x1A($sp)
    /* 4E2DC 8005DADC 00F84228 */  slti       $v0, $v0, -0x800
    /* 4E2E0 8005DAE0 02004010 */  beqz       $v0, .L8005DAEC
    /* 4E2E4 8005DAE4 00106224 */   addiu     $v0, $v1, 0x1000
    /* 4E2E8 8005DAE8 1A00A2A7 */  sh         $v0, 0x1A($sp)
  .L8005DAEC:
    /* 4E2EC 8005DAEC 0010C426 */  addiu      $a0, $s6, 0x1000
    /* 4E2F0 8005DAF0 02008104 */  bgez       $a0, .L8005DAFC
    /* 4E2F4 8005DAF4 21108000 */   addu      $v0, $a0, $zero
    /* 4E2F8 8005DAF8 FF1FC226 */  addiu      $v0, $s6, 0x1FFF
  .L8005DAFC:
    /* 4E2FC 8005DAFC 03130200 */  sra        $v0, $v0, 12
    /* 4E300 8005DB00 00130200 */  sll        $v0, $v0, 12
    /* 4E304 8005DB04 04006396 */  lhu        $v1, 0x4($s3)
    /* 4E308 8005DB08 23108200 */  subu       $v0, $a0, $v0
    /* 4E30C 8005DB0C 23184300 */  subu       $v1, $v0, $v1
    /* 4E310 8005DB10 00140300 */  sll        $v0, $v1, 16
    /* 4E314 8005DB14 03140200 */  sra        $v0, $v0, 16
    /* 4E318 8005DB18 01084228 */  slti       $v0, $v0, 0x801
    /* 4E31C 8005DB1C 03004014 */  bnez       $v0, .L8005DB2C
    /* 4E320 8005DB20 1C00A3A7 */   sh        $v1, 0x1C($sp)
    /* 4E324 8005DB24 00F06224 */  addiu      $v0, $v1, -0x1000
    /* 4E328 8005DB28 1C00A2A7 */  sh         $v0, 0x1C($sp)
  .L8005DB2C:
    /* 4E32C 8005DB2C 1C00A287 */  lh         $v0, 0x1C($sp)
    /* 4E330 8005DB30 1C00A397 */  lhu        $v1, 0x1C($sp)
    /* 4E334 8005DB34 00F84228 */  slti       $v0, $v0, -0x800
    /* 4E338 8005DB38 02004010 */  beqz       $v0, .L8005DB44
    /* 4E33C 8005DB3C 00106224 */   addiu     $v0, $v1, 0x1000
    /* 4E340 8005DB40 1C00A2A7 */  sh         $v0, 0x1C($sp)
  .L8005DB44:
    /* 4E344 8005DB44 72018483 */  lb         $a0, %gp_rel(D_8009B07A)($gp)
    /* 4E348 8005DB48 04000224 */  addiu      $v0, $zero, 0x4
    /* 4E34C 8005DB4C 1E00A2A7 */  sh         $v0, 0x1E($sp)
    /* 4E350 8005DB50 72018293 */  lbu        $v0, %gp_rel(D_8009B07A)($gp)
    /* 4E354 8005DB54 03008104 */  bgez       $a0, .L8005DB64
    /* 4E358 8005DB58 01004224 */   addiu     $v0, $v0, 0x1
    /* 4E35C 8005DB5C DB760108 */  j          .L8005DB6C
    /* 4E360 8005DB60 21200000 */   addu      $a0, $zero, $zero
  .L8005DB64:
    /* 4E364 8005DB64 720182A3 */  sb         $v0, %gp_rel(D_8009B07A)($gp)
    /* 4E368 8005DB68 2A200400 */  slt        $a0, $zero, $a0
  .L8005DB6C:
    /* 4E36C 8005DB6C 1800A527 */  addiu      $a1, $sp, 0x18
    /* 4E370 8005DB70 5400A78F */  lw         $a3, 0x54($sp)
    /* 4E374 8005DB74 477E010C */  jal        func_8005F91C
    /* 4E378 8005DB78 1000A627 */   addiu     $a2, $sp, 0x10
  .L8005DB7C:
    /* 4E37C 8005DB7C 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 4E380 8005DB80 3800B68F */  lw         $s6, 0x38($sp)
    /* 4E384 8005DB84 3400B58F */  lw         $s5, 0x34($sp)
    /* 4E388 8005DB88 3000B48F */  lw         $s4, 0x30($sp)
    /* 4E38C 8005DB8C 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 4E390 8005DB90 2800B28F */  lw         $s2, 0x28($sp)
    /* 4E394 8005DB94 2400B18F */  lw         $s1, 0x24($sp)
    /* 4E398 8005DB98 2000B08F */  lw         $s0, 0x20($sp)
    /* 4E39C 8005DB9C 0800E003 */  jr         $ra
    /* 4E3A0 8005DBA0 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8005D994
