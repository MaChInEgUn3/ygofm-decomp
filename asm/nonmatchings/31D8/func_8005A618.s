nonmatching func_8005A618, 0x90

glabel func_8005A618
    /* 4AE18 8005A618 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4AE1C 8005A61C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4AE20 8005A620 21808000 */  addu       $s0, $a0, $zero
    /* 4AE24 8005A624 C0101000 */  sll        $v0, $s0, 3
    /* 4AE28 8005A628 23105000 */  subu       $v0, $v0, $s0
    /* 4AE2C 8005A62C 00110200 */  sll        $v0, $v0, 4
    /* 4AE30 8005A630 21105000 */  addu       $v0, $v0, $s0
    /* 4AE34 8005A634 40110200 */  sll        $v0, $v0, 5
    /* 4AE38 8005A638 0F80033C */  lui        $v1, %hi(D_800F3938)
    /* 4AE3C 8005A63C 38396324 */  addiu      $v1, $v1, %lo(D_800F3938)
    /* 4AE40 8005A640 21206200 */  addu       $a0, $v1, $v0
    /* 4AE44 8005A644 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4AE48 8005A648 06018490 */  lbu        $a0, 0x106($a0)
    /* 4AE4C 8005A64C 21104300 */  addu       $v0, $v0, $v1
    /* 4AE50 8005A650 21104400 */  addu       $v0, $v0, $a0
    /* 4AE54 8005A654 0A004490 */  lbu        $a0, 0xA($v0)
    /* 4AE58 8005A658 697C010C */  jal        func_8005F1A4
    /* 4AE5C 8005A65C 1F008430 */   andi      $a0, $a0, 0x1F
    /* 4AE60 8005A660 02004484 */  lh         $a0, 0x2($v0)
    /* 4AE64 8005A664 0600001E */  bgtz       $s0, .L8005A680
    /* 4AE68 8005A668 00148324 */   addiu     $v1, $a0, 0x1400
    /* 4AE6C 8005A66C 001C8324 */  addiu      $v1, $a0, 0x1C00
    /* 4AE70 8005A670 06006104 */  bgez       $v1, .L8005A68C
    /* 4AE74 8005A674 21106000 */   addu      $v0, $v1, $zero
    /* 4AE78 8005A678 A3690108 */  j          .L8005A68C
    /* 4AE7C 8005A67C FF2B8224 */   addiu     $v0, $a0, 0x2BFF
  .L8005A680:
    /* 4AE80 8005A680 02006104 */  bgez       $v1, .L8005A68C
    /* 4AE84 8005A684 21106000 */   addu      $v0, $v1, $zero
    /* 4AE88 8005A688 FF238224 */  addiu      $v0, $a0, 0x23FF
  .L8005A68C:
    /* 4AE8C 8005A68C 03130200 */  sra        $v0, $v0, 12
    /* 4AE90 8005A690 00130200 */  sll        $v0, $v0, 12
    /* 4AE94 8005A694 23106200 */  subu       $v0, $v1, $v0
    /* 4AE98 8005A698 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4AE9C 8005A69C 1000B08F */  lw         $s0, 0x10($sp)
    /* 4AEA0 8005A6A0 0800E003 */  jr         $ra
    /* 4AEA4 8005A6A4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8005A618
