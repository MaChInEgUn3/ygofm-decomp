nonmatching func_80012B50, 0x184

glabel func_80012B50
    /* 3350 80012B50 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3354 80012B54 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3358 80012B58 9E4A000C */  jal        func_80012A78
    /* 335C 80012B5C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3360 80012B60 2CCE010C */  jal        func_800738B0
    /* 3364 80012B64 00000000 */   nop
    /* 3368 80012B68 E4D0010C */  jal        func_80074390
    /* 336C 80012B6C 00000000 */   nop
    /* 3370 80012B70 3015020C */  jal        func_800854C0
    /* 3374 80012B74 00000000 */   nop
    /* 3378 80012B78 30CE010C */  jal        func_800738C0
    /* 337C 80012B7C 00000000 */   nop
    /* 3380 80012B80 21D1010C */  jal        func_80074484
    /* 3384 80012B84 00000000 */   nop
    /* 3388 80012B88 14CE010C */  jal        func_80073850
    /* 338C 80012B8C 02000424 */   addiu     $a0, $zero, 0x2
    /* 3390 80012B90 8DFD010C */  jal        func_8007F634
    /* 3394 80012B94 21200000 */   addu      $a0, $zero, $zero
    /* 3398 80012B98 4357000C */  jal        func_80015D0C
    /* 339C 80012B9C 00000000 */   nop
    /* 33A0 80012BA0 0A80043C */  lui        $a0, %hi(D_8009B4A8)
    /* 33A4 80012BA4 A8B48424 */  addiu      $a0, $a0, %lo(D_8009B4A8)
    /* 33A8 80012BA8 01000324 */  addiu      $v1, $zero, 0x1
    /* 33AC 80012BAC C40180AF */  sw         $zero, %gp_rel(D_8009B0CC)($gp)
    /* 33B0 80012BB0 C00180AF */  sw         $zero, %gp_rel(D_8009B0C8)($gp)
    /* 33B4 80012BB4 B80180A3 */  sb         $zero, %gp_rel(D_8009B0C0)($gp)
    /* 33B8 80012BB8 940180AF */  sw         $zero, %gp_rel(D_8009B09C)($gp)
    /* 33BC 80012BBC 9401858F */  lw         $a1, %gp_rel(D_8009B09C)($gp)
    /* 33C0 80012BC0 00500224 */  addiu      $v0, $zero, 0x5000
    /* 33C4 80012BC4 BB0180A3 */  sb         $zero, %gp_rel(D_8009B0C3)($gp)
    /* 33C8 80012BC8 B90180A3 */  sb         $zero, %gp_rel(D_8009B0C1)($gp)
    /* 33CC 80012BCC D00183AF */  sw         $v1, %gp_rel(D_8009B0D8)($gp)
    /* 33D0 80012BD0 900182A7 */  sh         $v0, %gp_rel(D_8009B098)($gp)
    /* 33D4 80012BD4 C90180A3 */  sb         $zero, %gp_rel(D_8009B0D1)($gp)
    /* 33D8 80012BD8 0A80013C */  lui        $at, %hi(D_8009B230)
    /* 33DC 80012BDC 30B223A0 */  sb         $v1, %lo(D_8009B230)($at)
    /* 33E0 80012BE0 AC0184AF */  sw         $a0, %gp_rel(D_8009B0B4)($gp)
    /* 33E4 80012BE4 BC0185AF */  sw         $a1, %gp_rel(D_8009B0C4)($gp)
    /* 33E8 80012BE8 554C000C */  jal        func_80013154
    /* 33EC 80012BEC 00000000 */   nop
    /* 33F0 80012BF0 FC00010C */  jal        func_800403F0
    /* 33F4 80012BF4 00000000 */   nop
    /* 33F8 80012BF8 6C54000C */  jal        func_800151B0
    /* 33FC 80012BFC 00000000 */   nop
    /* 3400 80012C00 2D4D000C */  jal        func_800134B4
    /* 3404 80012C04 00000000 */   nop
    /* 3408 80012C08 96D6000C */  jal        func_80035A58
    /* 340C 80012C0C 00000000 */   nop
    /* 3410 80012C10 99D6000C */  jal        func_80035A64
    /* 3414 80012C14 00000000 */   nop
    /* 3418 80012C18 72ED000C */  jal        func_8003B5C8
    /* 341C 80012C1C 00000000 */   nop
    /* 3420 80012C20 0F80023C */  lui        $v0, %hi(D_800E9EC0)
    /* 3424 80012C24 C09E4490 */  lbu        $a0, %lo(D_800E9EC0)($v0)
    /* 3428 80012C28 DA19010C */  jal        func_80046768
    /* 342C 80012C2C 00000000 */   nop
    /* 3430 80012C30 0180043C */  lui        $a0, %hi(func_80012CD4)
    /* 3434 80012C34 08D1010C */  jal        func_80074420
    /* 3438 80012C38 D42C8424 */   addiu     $a0, $a0, %lo(func_80012CD4)
    /* 343C 80012C3C A0FF000C */  jal        func_8003FE80
    /* 3440 80012C40 00000000 */   nop
    /* 3444 80012C44 5555043C */  lui        $a0, (0x55555555 >> 16)
    /* 3448 80012C48 7039020C */  jal        func_8008E5C0
    /* 344C 80012C4C 55558434 */   ori       $a0, $a0, (0x55555555 & 0xFFFF)
    /* 3450 80012C50 8DFD010C */  jal        func_8007F634
    /* 3454 80012C54 01000424 */   addiu     $a0, $zero, 0x1
    /* 3458 80012C58 63B3000C */  jal        func_8002CD8C
    /* 345C 80012C5C 00000000 */   nop
    /* 3460 80012C60 63B3000C */  jal        func_8002CD8C
    /* 3464 80012C64 00000000 */   nop
    /* 3468 80012C68 580E010C */  jal        func_80043960
    /* 346C 80012C6C 21200000 */   addu      $a0, $zero, $zero
    /* 3470 80012C70 0F80043C */  lui        $a0, %hi(D_800E9DC0)
    /* 3474 80012C74 D43E020C */  jal        func_8008FB50
    /* 3478 80012C78 C09D8424 */   addiu     $a0, $a0, %lo(D_800E9DC0)
    /* 347C 80012C7C 63B3000C */  jal        func_8002CD8C
    /* 3480 80012C80 21804000 */   addu      $s0, $v0, $zero
    /* 3484 80012C84 05000012 */  beqz       $s0, .L80012C9C
    /* 3488 80012C88 00000000 */   nop
    /* 348C 80012C8C 176E010C */  jal        func_8005B85C
    /* 3490 80012C90 00000000 */   nop
    /* 3494 80012C94 F94D000C */  jal        func_800137E4
    /* 3498 80012C98 00000000 */   nop
  .L80012C9C:
    /* 349C 80012C9C F30E010C */  jal        func_80043BCC
    /* 34A0 80012CA0 00000000 */   nop
    /* 34A4 80012CA4 16B5000C */  jal        func_8002D458
    /* 34A8 80012CA8 21204000 */   addu      $a0, $v0, $zero
    /* 34AC 80012CAC 08000224 */  addiu      $v0, $zero, 0x8
    /* 34B0 80012CB0 0A80013C */  lui        $at, %hi(D_8009B269)
    /* 34B4 80012CB4 69B222A0 */  sb         $v0, %lo(D_8009B269)($at)
    /* 34B8 80012CB8 5DB7000C */  jal        func_8002DD74
    /* 34BC 80012CBC 00000000 */   nop
    /* 34C0 80012CC0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 34C4 80012CC4 1000B08F */  lw         $s0, 0x10($sp)
    /* 34C8 80012CC8 21100000 */  addu       $v0, $zero, $zero
    /* 34CC 80012CCC 0800E003 */  jr         $ra
    /* 34D0 80012CD0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012B50
