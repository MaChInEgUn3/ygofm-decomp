nonmatching func_8008D668, 0xD8

glabel func_8008D668
    /* 7DE68 8008D668 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7DE6C 8008D66C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7DE70 8008D670 1000B0AF */  sw         $s0, 0x10($sp)
  .L8008D674:
    /* 7DE74 8008D674 1080023C */  lui        $v0, %hi(D_800FE41C)
    /* 7DE78 8008D678 1CE4428C */  lw         $v0, %lo(D_800FE41C)($v0)
    /* 7DE7C 8008D67C 1080043C */  lui        $a0, %hi(D_800FE418)
    /* 7DE80 8008D680 18E4848C */  lw         $a0, %lo(D_800FE418)($a0)
    /* 7DE84 8008D684 1080033C */  lui        $v1, %hi(D_800FE420)
    /* 7DE88 8008D688 20E4638C */  lw         $v1, %lo(D_800FE420)($v1)
    /* 7DE8C 8008D68C 40100200 */  sll        $v0, $v0, 1
    /* 7DE90 8008D690 21208200 */  addu       $a0, $a0, $v0
    /* 7DE94 8008D694 80180300 */  sll        $v1, $v1, 2
    /* 7DE98 8008D698 1080023C */  lui        $v0, %hi(D_800FE424)
    /* 7DE9C 8008D69C 24E4428C */  lw         $v0, %lo(D_800FE424)($v0)
    /* 7DEA0 8008D6A0 21208300 */  addu       $a0, $a0, $v1
    /* 7DEA4 8008D6A4 C0100200 */  sll        $v0, $v0, 3
    /* 7DEA8 8008D6A8 21808200 */  addu       $s0, $a0, $v0
    /* 7DEAC 8008D6AC F1FF0012 */  beqz       $s0, .L8008D674
    /* 7DEB0 8008D6B0 00000000 */   nop
    /* 7DEB4 8008D6B4 1080043C */  lui        $a0, %hi(D_800FE408)
    /* 7DEB8 8008D6B8 08E4848C */  lw         $a0, %lo(D_800FE408)($a0)
    /* 7DEBC 8008D6BC 20CE010C */  jal        func_80073880
    /* 7DEC0 8008D6C0 00000000 */   nop
    /* 7DEC4 8008D6C4 1080043C */  lui        $a0, %hi(D_800FE40C)
    /* 7DEC8 8008D6C8 0CE4848C */  lw         $a0, %lo(D_800FE40C)($a0)
    /* 7DECC 8008D6CC 20CE010C */  jal        func_80073880
    /* 7DED0 8008D6D0 00000000 */   nop
    /* 7DED4 8008D6D4 1080043C */  lui        $a0, %hi(D_800FE410)
    /* 7DED8 8008D6D8 10E4848C */  lw         $a0, %lo(D_800FE410)($a0)
    /* 7DEDC 8008D6DC 20CE010C */  jal        func_80073880
    /* 7DEE0 8008D6E0 00000000 */   nop
    /* 7DEE4 8008D6E4 1080043C */  lui        $a0, %hi(D_800FE414)
    /* 7DEE8 8008D6E8 14E4848C */  lw         $a0, %lo(D_800FE414)($a0)
    /* 7DEEC 8008D6EC 20CE010C */  jal        func_80073880
    /* 7DEF0 8008D6F0 00000000 */   nop
    /* 7DEF4 8008D6F4 1080013C */  lui        $at, %hi(D_800FE424)
    /* 7DEF8 8008D6F8 24E420AC */  sw         $zero, %lo(D_800FE424)($at)
    /* 7DEFC 8008D6FC 1080023C */  lui        $v0, %hi(D_800FE424)
    /* 7DF00 8008D700 24E4428C */  lw         $v0, %lo(D_800FE424)($v0)
    /* 7DF04 8008D704 1080013C */  lui        $at, %hi(D_800FE420)
    /* 7DF08 8008D708 20E422AC */  sw         $v0, %lo(D_800FE420)($at)
    /* 7DF0C 8008D70C 1080023C */  lui        $v0, %hi(D_800FE420)
    /* 7DF10 8008D710 20E4428C */  lw         $v0, %lo(D_800FE420)($v0)
    /* 7DF14 8008D714 1080013C */  lui        $at, %hi(D_800FE41C)
    /* 7DF18 8008D718 1CE422AC */  sw         $v0, %lo(D_800FE41C)($at)
    /* 7DF1C 8008D71C 1080033C */  lui        $v1, %hi(D_800FE41C)
    /* 7DF20 8008D720 1CE4638C */  lw         $v1, %lo(D_800FE41C)($v1)
    /* 7DF24 8008D724 43101000 */  sra        $v0, $s0, 1
    /* 7DF28 8008D728 1080013C */  lui        $at, %hi(D_800FE418)
    /* 7DF2C 8008D72C 18E423AC */  sw         $v1, %lo(D_800FE418)($at)
    /* 7DF30 8008D730 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7DF34 8008D734 1000B08F */  lw         $s0, 0x10($sp)
    /* 7DF38 8008D738 0800E003 */  jr         $ra
    /* 7DF3C 8008D73C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008D668
