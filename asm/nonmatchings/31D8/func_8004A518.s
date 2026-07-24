nonmatching func_8004A518, 0x1C0

glabel func_8004A518
    /* 3AD18 8004A518 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3AD1C 8004A51C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 3AD20 8004A520 21A80000 */  addu       $s5, $zero, $zero
    /* 3AD24 8004A524 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3AD28 8004A528 2188A002 */  addu       $s1, $s5, $zero
    /* 3AD2C 8004A52C 72000524 */  addiu      $a1, $zero, 0x72
    /* 3AD30 8004A530 01000724 */  addiu      $a3, $zero, 0x1
    /* 3AD34 8004A534 FF000624 */  addiu      $a2, $zero, 0xFF
    /* 3AD38 8004A538 18050424 */  addiu      $a0, $zero, 0x518
    /* 3AD3C 8004A53C 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3AD40 8004A540 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3AD44 8004A544 7F000224 */  addiu      $v0, $zero, 0x7F
    /* 3AD48 8004A548 2800BFAF */  sw         $ra, 0x28($sp)
    /* 3AD4C 8004A54C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3AD50 8004A550 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3AD54 8004A554 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3AD58 8004A558 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3AD5C 8004A55C 120562A4 */  sh         $v0, 0x512($v1)
  .L8004A560:
    /* 3AD60 8004A560 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3AD64 8004A564 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3AD68 8004A568 01003126 */  addiu      $s1, $s1, 0x1
    /* 3AD6C 8004A56C 21104400 */  addu       $v0, $v0, $a0
    /* 3AD70 8004A570 000040AC */  sw         $zero, 0x0($v0)
    /* 3AD74 8004A574 040040AC */  sw         $zero, 0x4($v0)
    /* 3AD78 8004A578 260040A0 */  sb         $zero, 0x26($v0)
    /* 3AD7C 8004A57C 1C0040AC */  sw         $zero, 0x1C($v0)
    /* 3AD80 8004A580 080040AC */  sw         $zero, 0x8($v0)
    /* 3AD84 8004A584 0C0040AC */  sw         $zero, 0xC($v0)
    /* 3AD88 8004A588 140045A4 */  sh         $a1, 0x14($v0)
    /* 3AD8C 8004A58C 160045A4 */  sh         $a1, 0x16($v0)
    /* 3AD90 8004A590 240047A0 */  sb         $a3, 0x24($v0)
    /* 3AD94 8004A594 100040AC */  sw         $zero, 0x10($v0)
    /* 3AD98 8004A598 180040A4 */  sh         $zero, 0x18($v0)
    /* 3AD9C 8004A59C 270040A0 */  sb         $zero, 0x27($v0)
    /* 3ADA0 8004A5A0 280046A0 */  sb         $a2, 0x28($v0)
    /* 3ADA4 8004A5A4 290040A0 */  sb         $zero, 0x29($v0)
    /* 3ADA8 8004A5A8 2B0040A0 */  sb         $zero, 0x2B($v0)
    /* 3ADAC 8004A5AC 1000222A */  slti       $v0, $s1, 0x10
    /* 3ADB0 8004A5B0 EBFF4014 */  bnez       $v0, .L8004A560
    /* 3ADB4 8004A5B4 2C008424 */   addiu     $a0, $a0, 0x2C
    /* 3ADB8 8004A5B8 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3ADBC 8004A5BC 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3ADC0 8004A5C0 00000000 */  nop
    /* 3ADC4 8004A5C4 10056284 */  lh         $v0, 0x510($v1)
    /* 3ADC8 8004A5C8 00000000 */  nop
    /* 3ADCC 8004A5CC 20004018 */  blez       $v0, .L8004A650
    /* 3ADD0 8004A5D0 21880000 */   addu      $s1, $zero, $zero
    /* 3ADD4 8004A5D4 40001424 */  addiu      $s4, $zero, 0x40
    /* 3ADD8 8004A5D8 0180023C */  lui        $v0, %hi(D_80011434)
    /* 3ADDC 8004A5DC 34145324 */  addiu      $s3, $v0, %lo(D_80011434)
    /* 3ADE0 8004A5E0 80011224 */  addiu      $s2, $zero, 0x180
  .L8004A5E4:
    /* 3ADE4 8004A5E4 21202002 */  addu       $a0, $s1, $zero
    /* 3ADE8 8004A5E8 21187200 */  addu       $v1, $v1, $s2
    /* 3ADEC 8004A5EC 0000708E */  lw         $s0, 0x0($s3)
    /* 3ADF0 8004A5F0 63000224 */  addiu      $v0, $zero, 0x63
    /* 3ADF4 8004A5F4 030062A0 */  sb         $v0, 0x3($v1)
    /* 3ADF8 8004A5F8 40000224 */  addiu      $v0, $zero, 0x40
    /* 3ADFC 8004A5FC 000071A0 */  sb         $s1, 0x0($v1)
    /* 3AE00 8004A600 0D0060A0 */  sb         $zero, 0xD($v1)
    /* 3AE04 8004A604 0F0060A0 */  sb         $zero, 0xF($v1)
    /* 3AE08 8004A608 0C0062A0 */  sb         $v0, 0xC($v1)
    /* 3AE0C 8004A60C 1A0074A4 */  sh         $s4, 0x1A($v1)
    /* 3AE10 8004A610 1C0074A4 */  sh         $s4, 0x1C($v1)
    /* 3AE14 8004A614 D929010C */  jal        func_8004A764
    /* 3AE18 8004A618 1E0060A4 */   sh        $zero, 0x1E($v1)
    /* 3AE1C 8004A61C 21200000 */  addu       $a0, $zero, $zero
    /* 3AE20 8004A620 04007326 */  addiu      $s3, $s3, 0x4
    /* 3AE24 8004A624 28005226 */  addiu      $s2, $s2, 0x28
    /* 3AE28 8004A628 B4DB010C */  jal        func_80076ED0
    /* 3AE2C 8004A62C 21280002 */   addu      $a1, $s0, $zero
    /* 3AE30 8004A630 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3AE34 8004A634 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3AE38 8004A638 01003126 */  addiu      $s1, $s1, 0x1
    /* 3AE3C 8004A63C 10056284 */  lh         $v0, 0x510($v1)
    /* 3AE40 8004A640 00000000 */  nop
    /* 3AE44 8004A644 2A102202 */  slt        $v0, $s1, $v0
    /* 3AE48 8004A648 E6FF4014 */  bnez       $v0, .L8004A5E4
    /* 3AE4C 8004A64C 25A8B002 */   or        $s5, $s5, $s0
  .L8004A650:
    /* 3AE50 8004A650 21880000 */  addu       $s1, $zero, $zero
    /* 3AE54 8004A654 40000624 */  addiu      $a2, $zero, 0x40
    /* 3AE58 8004A658 7F000524 */  addiu      $a1, $zero, 0x7F
    /* 3AE5C 8004A65C 7F000424 */  addiu      $a0, $zero, 0x7F
    /* 3AE60 8004A660 21182002 */  addu       $v1, $s1, $zero
  .L8004A664:
    /* 3AE64 8004A664 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3AE68 8004A668 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3AE6C 8004A66C 01003126 */  addiu      $s1, $s1, 0x1
    /* 3AE70 8004A670 21104300 */  addu       $v0, $v0, $v1
    /* 3AE74 8004A674 010046A0 */  sb         $a2, 0x1($v0)
    /* 3AE78 8004A678 030045A0 */  sb         $a1, 0x3($v0)
    /* 3AE7C 8004A67C 040040A0 */  sb         $zero, 0x4($v0)
    /* 3AE80 8004A680 050045A0 */  sb         $a1, 0x5($v0)
    /* 3AE84 8004A684 070046A0 */  sb         $a2, 0x7($v0)
    /* 3AE88 8004A688 080044AC */  sw         $a0, 0x8($v0)
    /* 3AE8C 8004A68C 0C0044AC */  sw         $a0, 0xC($v0)
    /* 3AE90 8004A690 100040A0 */  sb         $zero, 0x10($v0)
    /* 3AE94 8004A694 140040A4 */  sh         $zero, 0x14($v0)
    /* 3AE98 8004A698 060040A0 */  sb         $zero, 0x6($v0)
    /* 3AE9C 8004A69C 1000222A */  slti       $v0, $s1, 0x10
    /* 3AEA0 8004A6A0 F0FF4014 */  bnez       $v0, .L8004A664
    /* 3AEA4 8004A6A4 18006324 */   addiu     $v1, $v1, 0x18
    /* 3AEA8 8004A6A8 21200000 */  addu       $a0, $zero, $zero
    /* 3AEAC 8004A6AC B4DB010C */  jal        func_80076ED0
    /* 3AEB0 8004A6B0 2128A002 */   addu      $a1, $s5, $zero
    /* 3AEB4 8004A6B4 2800BF8F */  lw         $ra, 0x28($sp)
    /* 3AEB8 8004A6B8 2400B58F */  lw         $s5, 0x24($sp)
    /* 3AEBC 8004A6BC 2000B48F */  lw         $s4, 0x20($sp)
    /* 3AEC0 8004A6C0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3AEC4 8004A6C4 1800B28F */  lw         $s2, 0x18($sp)
    /* 3AEC8 8004A6C8 1400B18F */  lw         $s1, 0x14($sp)
    /* 3AECC 8004A6CC 1000B08F */  lw         $s0, 0x10($sp)
    /* 3AED0 8004A6D0 0800E003 */  jr         $ra
    /* 3AED4 8004A6D4 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8004A518
