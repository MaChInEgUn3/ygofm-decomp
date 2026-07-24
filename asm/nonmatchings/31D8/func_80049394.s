nonmatching func_80049394, 0x64

glabel func_80049394
    /* 39B94 80049394 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 39B98 80049398 1000B0AF */  sw         $s0, 0x10($sp)
    /* 39B9C 8004939C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 39BA0 800493A0 0424010C */  jal        func_80049010
    /* 39BA4 800493A4 21808000 */   addu      $s0, $a0, $zero
    /* 39BA8 800493A8 05000012 */  beqz       $s0, .L800493C0
    /* 39BAC 800493AC 1E80033C */   lui       $v1, (0x801EA800 >> 16)
    /* 39BB0 800493B0 0A80023C */  lui        $v0, %hi(D_8009B45C)
    /* 39BB4 800493B4 5CB4428C */  lw         $v0, %lo(D_8009B45C)($v0)
    /* 39BB8 800493B8 F4240108 */  j          .L800493D0
    /* 39BBC 800493BC 641550AC */   sw        $s0, 0x1564($v0)
  .L800493C0:
    /* 39BC0 800493C0 0A80023C */  lui        $v0, %hi(D_8009B45C)
    /* 39BC4 800493C4 5CB4428C */  lw         $v0, %lo(D_8009B45C)($v0)
    /* 39BC8 800493C8 00A86334 */  ori        $v1, $v1, (0x801EA800 & 0xFFFF)
    /* 39BCC 800493CC 641543AC */  sw         $v1, 0x1564($v0)
  .L800493D0:
    /* 39BD0 800493D0 0A80023C */  lui        $v0, %hi(D_8009B45C)
    /* 39BD4 800493D4 5CB4428C */  lw         $v0, %lo(D_8009B45C)($v0)
    /* 39BD8 800493D8 00000000 */  nop
    /* 39BDC 800493DC 6415438C */  lw         $v1, 0x1564($v0)
    /* 39BE0 800493E0 FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 39BE4 800493E4 000062A4 */  sh         $v0, 0x0($v1)
    /* 39BE8 800493E8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 39BEC 800493EC 1000B08F */  lw         $s0, 0x10($sp)
    /* 39BF0 800493F0 0800E003 */  jr         $ra
    /* 39BF4 800493F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80049394
