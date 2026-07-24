nonmatching func_80058FB0, 0x50

glabel func_80058FB0
    /* 497B0 80058FB0 C0180400 */  sll        $v1, $a0, 3
    /* 497B4 80058FB4 23186400 */  subu       $v1, $v1, $a0
    /* 497B8 80058FB8 00190300 */  sll        $v1, $v1, 4
    /* 497BC 80058FBC 21186400 */  addu       $v1, $v1, $a0
    /* 497C0 80058FC0 40190300 */  sll        $v1, $v1, 5
    /* 497C4 80058FC4 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 497C8 80058FC8 402C4224 */  addiu      $v0, $v0, %lo(D_800F2C40)
    /* 497CC 80058FCC 21186200 */  addu       $v1, $v1, $v0
    /* 497D0 80058FD0 D00D6294 */  lhu        $v0, 0xDD0($v1)
    /* 497D4 80058FD4 00000000 */  nop
    /* 497D8 80058FD8 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 497DC 80058FDC D20D6294 */  lhu        $v0, 0xDD2($v1)
    /* 497E0 80058FE0 00000000 */  nop
    /* 497E4 80058FE4 0200A2A4 */  sh         $v0, 0x2($a1)
    /* 497E8 80058FE8 D40D6294 */  lhu        $v0, 0xDD4($v1)
    /* 497EC 80058FEC 00000000 */  nop
    /* 497F0 80058FF0 0400A2A4 */  sh         $v0, 0x4($a1)
    /* 497F4 80058FF4 D60D6294 */  lhu        $v0, 0xDD6($v1)
    /* 497F8 80058FF8 0800E003 */  jr         $ra
    /* 497FC 80058FFC 0600A2A4 */   sh        $v0, 0x6($a1)
endlabel func_80058FB0
