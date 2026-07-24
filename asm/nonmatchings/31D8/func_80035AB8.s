nonmatching func_80035AB8, 0x38

glabel func_80035AB8
    /* 262B8 80035AB8 40100400 */  sll        $v0, $a0, 1
    /* 262BC 80035ABC 21104400 */  addu       $v0, $v0, $a0
    /* 262C0 80035AC0 C0100200 */  sll        $v0, $v0, 3
    /* 262C4 80035AC4 21104400 */  addu       $v0, $v0, $a0
    /* 262C8 80035AC8 80100200 */  sll        $v0, $v0, 2
    /* 262CC 80035ACC 0F80033C */  lui        $v1, %hi(D_800EB0F8)
    /* 262D0 80035AD0 F8B06324 */  addiu      $v1, $v1, %lo(D_800EB0F8)
    /* 262D4 80035AD4 1000A48F */  lw         $a0, 0x10($sp)
    /* 262D8 80035AD8 21104300 */  addu       $v0, $v0, $v1
    /* 262DC 80035ADC 3C0045A4 */  sh         $a1, 0x3C($v0)
    /* 262E0 80035AE0 400046A4 */  sh         $a2, 0x40($v0)
    /* 262E4 80035AE4 3E0047A4 */  sh         $a3, 0x3E($v0)
    /* 262E8 80035AE8 0800E003 */  jr         $ra
    /* 262EC 80035AEC 420044A4 */   sh        $a0, 0x42($v0)
endlabel func_80035AB8
