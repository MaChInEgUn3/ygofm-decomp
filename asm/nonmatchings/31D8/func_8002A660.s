nonmatching func_8002A660, 0x58

glabel func_8002A660
    /* 1AE60 8002A660 0A008284 */  lh         $v0, 0xA($a0)
    /* 1AE64 8002A664 0A80033C */  lui        $v1, %hi(D_8009B148)
    /* 1AE68 8002A668 48B16384 */  lh         $v1, %lo(D_8009B148)($v1)
    /* 1AE6C 8002A66C 0A80013C */  lui        $at, %hi(D_8009B146)
    /* 1AE70 8002A670 46B120A4 */  sh         $zero, %lo(D_8009B146)($at)
    /* 1AE74 8002A674 23284300 */  subu       $a1, $v0, $v1
    /* 1AE78 8002A678 4000A228 */  slti       $v0, $a1, 0x40
    /* 1AE7C 8002A67C 0A008394 */  lhu        $v1, 0xA($a0)
    /* 1AE80 8002A680 03004010 */  beqz       $v0, .L8002A690
    /* 1AE84 8002A684 C0FF6224 */   addiu     $v0, $v1, -0x40
    /* 1AE88 8002A688 0A80013C */  lui        $at, %hi(D_8009B148)
    /* 1AE8C 8002A68C 48B122A4 */  sh         $v0, %lo(D_8009B148)($at)
  .L8002A690:
    /* 1AE90 8002A690 B000A228 */  slti       $v0, $a1, 0xB0
    /* 1AE94 8002A694 06004014 */  bnez       $v0, .L8002A6B0
    /* 1AE98 8002A698 00000000 */   nop
    /* 1AE9C 8002A69C 0A008294 */  lhu        $v0, 0xA($a0)
    /* 1AEA0 8002A6A0 00000000 */  nop
    /* 1AEA4 8002A6A4 50FF4224 */  addiu      $v0, $v0, -0xB0
    /* 1AEA8 8002A6A8 0A80013C */  lui        $at, %hi(D_8009B148)
    /* 1AEAC 8002A6AC 48B122A4 */  sh         $v0, %lo(D_8009B148)($at)
  .L8002A6B0:
    /* 1AEB0 8002A6B0 0800E003 */  jr         $ra
    /* 1AEB4 8002A6B4 00000000 */   nop
endlabel func_8002A660
