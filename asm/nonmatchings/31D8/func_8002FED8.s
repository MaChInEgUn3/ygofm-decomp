nonmatching func_8002FED8, 0xFC

glabel func_8002FED8
    /* 206D8 8002FED8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 206DC 8002FEDC 21308000 */  addu       $a2, $a0, $zero
    /* 206E0 8002FEE0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 206E4 8002FEE4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 206E8 8002FEE8 0400C394 */  lhu        $v1, 0x4($a2)
    /* 206EC 8002FEEC 00000000 */  nop
    /* 206F0 8002FEF0 00806230 */  andi       $v0, $v1, 0x8000
    /* 206F4 8002FEF4 04004014 */  bnez       $v0, .L8002FF08
    /* 206F8 8002FEF8 2180A000 */   addu      $s0, $a1, $zero
    /* 206FC 8002FEFC 00806234 */  ori        $v0, $v1, 0x8000
    /* 20700 8002FF00 0400C2A4 */  sh         $v0, 0x4($a2)
    /* 20704 8002FF04 0600C0A4 */  sh         $zero, 0x6($a2)
  .L8002FF08:
    /* 20708 8002FF08 0600C494 */  lhu        $a0, 0x6($a2)
    /* 2070C 8002FF0C 00000000 */  nop
    /* 20710 8002FF10 20008424 */  addiu      $a0, $a0, 0x20
    /* 20714 8002FF14 FF0F8430 */  andi       $a0, $a0, 0xFFF
    /* 20718 8002FF18 A819020C */  jal        func_800866A0
    /* 2071C 8002FF1C 0600C4A4 */   sh        $a0, 0x6($a2)
    /* 20720 8002FF20 40180200 */  sll        $v1, $v0, 1
    /* 20724 8002FF24 21186200 */  addu       $v1, $v1, $v0
    /* 20728 8002FF28 C0100300 */  sll        $v0, $v1, 3
    /* 2072C 8002FF2C 03004104 */  bgez       $v0, .L8002FF3C
    /* 20730 8002FF30 032B0200 */   sra       $a1, $v0, 12
    /* 20734 8002FF34 FF0F4224 */  addiu      $v0, $v0, 0xFFF
    /* 20738 8002FF38 032B0200 */  sra        $a1, $v0, 12
  .L8002FF3C:
    /* 2073C 8002FF3C 0200A014 */  bnez       $a1, .L8002FF48
    /* 20740 8002FF40 18000224 */   addiu     $v0, $zero, 0x18
    /* 20744 8002FF44 01000524 */  addiu      $a1, $zero, 0x1
  .L8002FF48:
    /* 20748 8002FF48 0300A214 */  bne        $a1, $v0, .L8002FF58
    /* 2074C 8002FF4C 98FFA224 */   addiu     $v0, $a1, -0x68
    /* 20750 8002FF50 17000524 */  addiu      $a1, $zero, 0x17
    /* 20754 8002FF54 98FFA224 */  addiu      $v0, $a1, -0x68
  .L8002FF58:
    /* 20758 8002FF58 0E0002A2 */  sb         $v0, 0xE($s0)
    /* 2075C 8002FF5C 0D0002A2 */  sb         $v0, 0xD($s0)
    /* 20760 8002FF60 0C0002A2 */  sb         $v0, 0xC($s0)
    /* 20764 8002FF64 0F80023C */  lui        $v0, %hi(D_800EAE98)
    /* 20768 8002FF68 98AE448C */  lw         $a0, %lo(D_800EAE98)($v0)
    /* 2076C 8002FF6C 00000000 */  nop
    /* 20770 8002FF70 09008010 */  beqz       $a0, .L8002FF98
    /* 20774 8002FF74 98AE4624 */   addiu     $a2, $v0, %lo(D_800EAE98)
    /* 20778 8002FF78 1800A224 */  addiu      $v0, $a1, 0x18
    /* 2077C 8002FF7C C21F0200 */  srl        $v1, $v0, 31
    /* 20780 8002FF80 21104300 */  addu       $v0, $v0, $v1
    /* 20784 8002FF84 43100200 */  sra        $v0, $v0, 1
    /* 20788 8002FF88 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 2078C 8002FF8C 0E0082A0 */  sb         $v0, 0xE($a0)
    /* 20790 8002FF90 0D0082A0 */  sb         $v0, 0xD($a0)
    /* 20794 8002FF94 0C0082A0 */  sb         $v0, 0xC($a0)
  .L8002FF98:
    /* 20798 8002FF98 1400C48C */  lw         $a0, 0x14($a2)
    /* 2079C 8002FF9C 00000000 */  nop
    /* 207A0 8002FFA0 08008010 */  beqz       $a0, .L8002FFC4
    /* 207A4 8002FFA4 1800A224 */   addiu     $v0, $a1, 0x18
    /* 207A8 8002FFA8 C21F0200 */  srl        $v1, $v0, 31
    /* 207AC 8002FFAC 21104300 */  addu       $v0, $v0, $v1
    /* 207B0 8002FFB0 43100200 */  sra        $v0, $v0, 1
    /* 207B4 8002FFB4 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 207B8 8002FFB8 0E0082A0 */  sb         $v0, 0xE($a0)
    /* 207BC 8002FFBC 0D0082A0 */  sb         $v0, 0xD($a0)
    /* 207C0 8002FFC0 0C0082A0 */  sb         $v0, 0xC($a0)
  .L8002FFC4:
    /* 207C4 8002FFC4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 207C8 8002FFC8 1000B08F */  lw         $s0, 0x10($sp)
    /* 207CC 8002FFCC 0800E003 */  jr         $ra
    /* 207D0 8002FFD0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002FED8
