nonmatching func_80042AD8, 0x30

glabel func_80042AD8
    /* 332D8 80042AD8 0400A104 */  bgez       $a1, .L80042AEC
    /* 332DC 80042ADC 00000000 */   nop
    /* 332E0 80042AE0 23208600 */  subu       $a0, $a0, $a2
    /* 332E4 80042AE4 BD0A0108 */  j          .L80042AF4
    /* 332E8 80042AE8 2A108500 */   slt       $v0, $a0, $a1
  .L80042AEC:
    /* 332EC 80042AEC 21208600 */  addu       $a0, $a0, $a2
    /* 332F0 80042AF0 2A10A400 */  slt        $v0, $a1, $a0
  .L80042AF4:
    /* 332F4 80042AF4 02004010 */  beqz       $v0, .L80042B00
    /* 332F8 80042AF8 00000000 */   nop
    /* 332FC 80042AFC 2120A000 */  addu       $a0, $a1, $zero
  .L80042B00:
    /* 33300 80042B00 0800E003 */  jr         $ra
    /* 33304 80042B04 21108000 */   addu      $v0, $a0, $zero
endlabel func_80042AD8
