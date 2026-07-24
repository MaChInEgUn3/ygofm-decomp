nonmatching func_8003B6AC, 0x68

glabel func_8003B6AC
    /* 2BEAC 8003B6AC 0980033C */  lui        $v1, %hi(D_80090E58)
    /* 2BEB0 8003B6B0 580E6324 */  addiu      $v1, $v1, %lo(D_80090E58)
    /* 2BEB4 8003B6B4 40100400 */  sll        $v0, $a0, 1
    /* 2BEB8 8003B6B8 21104300 */  addu       $v0, $v0, $v1
    /* 2BEBC 8003B6BC 01008424 */  addiu      $a0, $a0, 0x1
    /* 2BEC0 8003B6C0 40200400 */  sll        $a0, $a0, 1
    /* 2BEC4 8003B6C4 21208300 */  addu       $a0, $a0, $v1
    /* 2BEC8 8003B6C8 00004694 */  lhu        $a2, 0x0($v0)
    /* 2BECC 8003B6CC 00008294 */  lhu        $v0, 0x0($a0)
    /* 2BED0 8003B6D0 00000000 */  nop
    /* 2BED4 8003B6D4 2A10C200 */  slt        $v0, $a2, $v0
    /* 2BED8 8003B6D8 0C004010 */  beqz       $v0, .L8003B70C
    /* 2BEDC 8003B6DC 0F80033C */   lui       $v1, %hi(D_800EB288)
    /* 2BEE0 8003B6E0 88B26324 */  addiu      $v1, $v1, %lo(D_800EB288)
    /* 2BEE4 8003B6E4 C0100600 */  sll        $v0, $a2, 3
    /* 2BEE8 8003B6E8 23104600 */  subu       $v0, $v0, $a2
    /* 2BEEC 8003B6EC 80100200 */  sll        $v0, $v0, 2
    /* 2BEF0 8003B6F0 21184300 */  addu       $v1, $v0, $v1
  .L8003B6F4:
    /* 2BEF4 8003B6F4 180065A0 */  sb         $a1, 0x18($v1)
    /* 2BEF8 8003B6F8 00008294 */  lhu        $v0, 0x0($a0)
    /* 2BEFC 8003B6FC 0100C624 */  addiu      $a2, $a2, 0x1
    /* 2BF00 8003B700 2A10C200 */  slt        $v0, $a2, $v0
    /* 2BF04 8003B704 FBFF4014 */  bnez       $v0, .L8003B6F4
    /* 2BF08 8003B708 1C006324 */   addiu     $v1, $v1, 0x1C
  .L8003B70C:
    /* 2BF0C 8003B70C 0800E003 */  jr         $ra
    /* 2BF10 8003B710 00000000 */   nop
endlabel func_8003B6AC
