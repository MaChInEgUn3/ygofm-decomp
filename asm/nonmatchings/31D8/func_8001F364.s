nonmatching func_8001F364, 0x1F8

glabel func_8001F364
    /* FB64 8001F364 5A028297 */  lhu        $v0, %gp_rel(D_8009B162)($gp)
    /* FB68 8001F368 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* FB6C 8001F36C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* FB70 8001F370 75004014 */  bnez       $v0, .L8001F548
    /* FB74 8001F374 1800B0AF */   sw        $s0, 0x18($sp)
    /* FB78 8001F378 08038297 */  lhu        $v0, %gp_rel(D_8009B210)($gp)
    /* FB7C 8001F37C 01001024 */  addiu      $s0, $zero, 0x1
    /* FB80 8001F380 0F004330 */  andi       $v1, $v0, 0xF
    /* FB84 8001F384 25007010 */  beq        $v1, $s0, .L8001F41C
    /* FB88 8001F388 02006228 */   slti      $v0, $v1, 0x2
    /* FB8C 8001F38C 05004010 */  beqz       $v0, .L8001F3A4
    /* FB90 8001F390 02000224 */   addiu     $v0, $zero, 0x2
    /* FB94 8001F394 09006010 */  beqz       $v1, .L8001F3BC
    /* FB98 8001F398 01000224 */   addiu     $v0, $zero, 0x1
    /* FB9C 8001F39C 537D0008 */  j          .L8001F54C
    /* FBA0 8001F3A0 00000000 */   nop
  .L8001F3A4:
    /* FBA4 8001F3A4 47006210 */  beq        $v1, $v0, .L8001F4C4
    /* FBA8 8001F3A8 03000224 */   addiu     $v0, $zero, 0x3
    /* FBAC 8001F3AC 54006210 */  beq        $v1, $v0, .L8001F500
    /* FBB0 8001F3B0 01000224 */   addiu     $v0, $zero, 0x1
    /* FBB4 8001F3B4 537D0008 */  j          .L8001F54C
    /* FBB8 8001F3B8 00000000 */   nop
  .L8001F3BC:
    /* FBBC 8001F3BC 10000424 */  addiu      $a0, $zero, 0x10
    /* FBC0 8001F3C0 08020524 */  addiu      $a1, $zero, 0x208
    /* FBC4 8001F3C4 00020624 */  addiu      $a2, $zero, 0x200
    /* FBC8 8001F3C8 0F80023C */  lui        $v0, %hi(D_800F284A)
    /* FBCC 8001F3CC CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* FBD0 8001F3D0 4A284784 */  lh         $a3, %lo(D_800F284A)($v0)
    /* FBD4 8001F3D4 40100300 */  sll        $v0, $v1, 1
    /* FBD8 8001F3D8 21104300 */  addu       $v0, $v0, $v1
    /* FBDC 8001F3DC 80100200 */  sll        $v0, $v0, 2
    /* FBE0 8001F3E0 23104300 */  subu       $v0, $v0, $v1
    /* FBE4 8001F3E4 C0100200 */  sll        $v0, $v0, 3
    /* FBE8 8001F3E8 21104300 */  addu       $v0, $v0, $v1
    /* FBEC 8001F3EC 80100200 */  sll        $v0, $v0, 2
    /* FBF0 8001F3F0 B2000324 */  addiu      $v1, $zero, 0xB2
    /* FBF4 8001F3F4 23186200 */  subu       $v1, $v1, $v0
    /* FBF8 8001F3F8 658B000C */  jal        func_80022D94
    /* FBFC 8001F3FC 1000A3AF */   sw        $v1, 0x10($sp)
    /* FC00 8001F400 10000224 */  addiu      $v0, $zero, 0x10
    /* FC04 8001F404 5A0282A7 */  sh         $v0, %gp_rel(D_8009B162)($gp)
    /* FC08 8001F408 14000224 */  addiu      $v0, $zero, 0x14
    /* FC0C 8001F40C 080390A7 */  sh         $s0, %gp_rel(D_8009B210)($gp)
    /* FC10 8001F410 C80282A7 */  sh         $v0, %gp_rel(D_8009B1D0)($gp)
    /* FC14 8001F414 537D0008 */  j          .L8001F54C
    /* FC18 8001F418 01000224 */   addiu     $v0, $zero, 0x1
  .L8001F41C:
    /* FC1C 8001F41C C8028297 */  lhu        $v0, %gp_rel(D_8009B1D0)($gp)
    /* FC20 8001F420 00000000 */  nop
    /* FC24 8001F424 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* FC28 8001F428 C80282A7 */  sh         $v0, %gp_rel(D_8009B1D0)($gp)
    /* FC2C 8001F42C 00140200 */  sll        $v0, $v0, 16
    /* FC30 8001F430 4600401C */  bgtz       $v0, .L8001F54C
    /* FC34 8001F434 01000224 */   addiu     $v0, $zero, 0x1
    /* FC38 8001F438 0400063C */  lui        $a2, (0x48000 >> 16)
    /* FC3C 8001F43C 0080C634 */  ori        $a2, $a2, (0x48000 & 0xFFFF)
    /* FC40 8001F440 1680033C */  lui        $v1, %hi(D_8015C424)
    /* FC44 8001F444 B0028593 */  lbu        $a1, %gp_rel(D_8009B1B8)($gp)
    /* FC48 8001F448 24C46324 */  addiu      $v1, $v1, %lo(D_8015C424)
    /* FC4C 8001F44C C0100500 */  sll        $v0, $a1, 3
    /* FC50 8001F450 23104500 */  subu       $v0, $v0, $a1
    /* FC54 8001F454 80100200 */  sll        $v0, $v0, 2
    /* FC58 8001F458 21104300 */  addu       $v0, $v0, $v1
    /* FC5C 8001F45C 21104600 */  addu       $v0, $v0, $a2
    /* FC60 8001F460 B436508C */  lw         $s0, 0x36B4($v0)
    /* FC64 8001F464 A3B1000C */  jal        func_8002C68C
    /* FC68 8001F468 08000424 */   addiu     $a0, $zero, 0x8
    /* FC6C 8001F46C 30000396 */  lhu        $v1, 0x30($s0)
    /* FC70 8001F470 00000000 */  nop
    /* FC74 8001F474 000043A4 */  sh         $v1, 0x0($v0)
    /* FC78 8001F478 32000396 */  lhu        $v1, 0x32($s0)
    /* FC7C 8001F47C 00000000 */  nop
    /* FC80 8001F480 020043A4 */  sh         $v1, 0x2($v0)
    /* FC84 8001F484 34000396 */  lhu        $v1, 0x34($s0)
    /* FC88 8001F488 1A80043C */  lui        $a0, %hi(D_801A7AD8)
    /* FC8C 8001F48C 040043A4 */  sh         $v1, 0x4($v0)
    /* FC90 8001F490 6A000392 */  lbu        $v1, 0x6A($s0)
    /* FC94 8001F494 D87A8424 */  addiu      $a0, $a0, %lo(D_801A7AD8)
    /* FC98 8001F498 C0100300 */  sll        $v0, $v1, 3
    /* FC9C 8001F49C 23104300 */  subu       $v0, $v0, $v1
    /* FCA0 8001F4A0 80100200 */  sll        $v0, $v0, 2
    /* FCA4 8001F4A4 5592000C */  jal        func_80024954
    /* FCA8 8001F4A8 21204400 */   addu      $a0, $v0, $a0
    /* FCAC 8001F4AC B8FF000C */  jal        func_8003FEE0
    /* FCB0 8001F4B0 17000424 */   addiu     $a0, $zero, 0x17
    /* FCB4 8001F4B4 02000224 */  addiu      $v0, $zero, 0x2
    /* FCB8 8001F4B8 080382A7 */  sh         $v0, %gp_rel(D_8009B210)($gp)
    /* FCBC 8001F4BC 537D0008 */  j          .L8001F54C
    /* FCC0 8001F4C0 01000224 */   addiu     $v0, $zero, 0x1
  .L8001F4C4:
    /* FCC4 8001F4C4 10000424 */  addiu      $a0, $zero, 0x10
    /* FCC8 8001F4C8 58020524 */  addiu      $a1, $zero, 0x258
    /* FCCC 8001F4CC 0F80023C */  lui        $v0, %hi(D_800F284A)
    /* FCD0 8001F4D0 4A284784 */  lh         $a3, %lo(D_800F284A)($v0)
    /* FCD4 8001F4D4 00010624 */  addiu      $a2, $zero, 0x100
    /* FCD8 8001F4D8 658B000C */  jal        func_80022D94
    /* FCDC 8001F4DC 1000A0AF */   sw        $zero, 0x10($sp)
    /* FCE0 8001F4E0 10000224 */  addiu      $v0, $zero, 0x10
    /* FCE4 8001F4E4 5A0282A7 */  sh         $v0, %gp_rel(D_8009B162)($gp)
    /* FCE8 8001F4E8 03000224 */  addiu      $v0, $zero, 0x3
    /* FCEC 8001F4EC 080382A7 */  sh         $v0, %gp_rel(D_8009B210)($gp)
    /* FCF0 8001F4F0 14000224 */  addiu      $v0, $zero, 0x14
    /* FCF4 8001F4F4 C80282A7 */  sh         $v0, %gp_rel(D_8009B1D0)($gp)
    /* FCF8 8001F4F8 537D0008 */  j          .L8001F54C
    /* FCFC 8001F4FC 01000224 */   addiu     $v0, $zero, 0x1
  .L8001F500:
    /* FD00 8001F500 C8028297 */  lhu        $v0, %gp_rel(D_8009B1D0)($gp)
    /* FD04 8001F504 00000000 */  nop
    /* FD08 8001F508 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* FD0C 8001F50C C80282A7 */  sh         $v0, %gp_rel(D_8009B1D0)($gp)
    /* FD10 8001F510 00140200 */  sll        $v0, $v0, 16
    /* FD14 8001F514 0D00401C */  bgtz       $v0, .L8001F54C
    /* FD18 8001F518 01000224 */   addiu     $v0, $zero, 0x1
    /* FD1C 8001F51C 0F80023C */  lui        $v0, %hi(D_800E9FF0)
    /* FD20 8001F520 CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* FD24 8001F524 F09F4224 */  addiu      $v0, $v0, %lo(D_800E9FF0)
    /* FD28 8001F528 01006338 */  xori       $v1, $v1, 0x1
    /* FD2C 8001F52C 40190300 */  sll        $v1, $v1, 5
    /* FD30 8001F530 21186200 */  addu       $v1, $v1, $v0
    /* FD34 8001F534 06006490 */  lbu        $a0, 0x6($v1)
    /* FD38 8001F538 21100000 */  addu       $v0, $zero, $zero
    /* FD3C 8001F53C 01008424 */  addiu      $a0, $a0, 0x1
    /* FD40 8001F540 537D0008 */  j          .L8001F54C
    /* FD44 8001F544 060064A0 */   sb        $a0, 0x6($v1)
  .L8001F548:
    /* FD48 8001F548 01000224 */  addiu      $v0, $zero, 0x1
  .L8001F54C:
    /* FD4C 8001F54C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* FD50 8001F550 1800B08F */  lw         $s0, 0x18($sp)
    /* FD54 8001F554 0800E003 */  jr         $ra
    /* FD58 8001F558 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001F364
