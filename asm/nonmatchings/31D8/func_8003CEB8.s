nonmatching func_8003CEB8, 0x5C

glabel func_8003CEB8
    /* 2D6B8 8003CEB8 21180000 */  addu       $v1, $zero, $zero
    /* 2D6BC 8003CEBC 1300A018 */  blez       $a1, .L8003CF0C
    /* 2D6C0 8003CEC0 21380000 */   addu      $a3, $zero, $zero
    /* 2D6C4 8003CEC4 21108700 */  addu       $v0, $a0, $a3
  .L8003CEC8:
    /* 2D6C8 8003CEC8 00004290 */  lbu        $v0, 0x0($v0)
    /* 2D6CC 8003CECC 07000624 */  addiu      $a2, $zero, 0x7
    /* 2D6D0 8003CED0 00120200 */  sll        $v0, $v0, 8
    /* 2D6D4 8003CED4 26186200 */  xor        $v1, $v1, $v0
    /* 2D6D8 8003CED8 00806230 */  andi       $v0, $v1, 0x8000
  .L8003CEDC:
    /* 2D6DC 8003CEDC 03004010 */  beqz       $v0, .L8003CEEC
    /* 2D6E0 8003CEE0 40100300 */   sll       $v0, $v1, 1
    /* 2D6E4 8003CEE4 BCF30008 */  j          .L8003CEF0
    /* 2D6E8 8003CEE8 21104338 */   xori      $v1, $v0, 0x1021
  .L8003CEEC:
    /* 2D6EC 8003CEEC 40180300 */  sll        $v1, $v1, 1
  .L8003CEF0:
    /* 2D6F0 8003CEF0 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 2D6F4 8003CEF4 F9FFC104 */  bgez       $a2, .L8003CEDC
    /* 2D6F8 8003CEF8 00806230 */   andi      $v0, $v1, 0x8000
    /* 2D6FC 8003CEFC 0100E724 */  addiu      $a3, $a3, 0x1
    /* 2D700 8003CF00 2A10E500 */  slt        $v0, $a3, $a1
    /* 2D704 8003CF04 F0FF4014 */  bnez       $v0, .L8003CEC8
    /* 2D708 8003CF08 21108700 */   addu      $v0, $a0, $a3
  .L8003CF0C:
    /* 2D70C 8003CF0C 0800E003 */  jr         $ra
    /* 2D710 8003CF10 FFFF6230 */   andi      $v0, $v1, 0xFFFF
endlabel func_8003CEB8
