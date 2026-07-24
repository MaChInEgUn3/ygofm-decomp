nonmatching func_8005BE3C, 0x18C

glabel func_8005BE3C
    /* 4C63C 8005BE3C 5B018293 */  lbu        $v0, %gp_rel(D_8009B063)($gp)
    /* 4C640 8005BE40 88FFBD27 */  addiu      $sp, $sp, -0x78
    /* 4C644 8005BE44 7400BFAF */  sw         $ra, 0x74($sp)
    /* 4C648 8005BE48 09004014 */  bnez       $v0, .L8005BE70
    /* 4C64C 8005BE4C 7000B0AF */   sw        $s0, 0x70($sp)
    /* 4C650 8005BE50 5C018293 */  lbu        $v0, %gp_rel(D_8009B064)($gp)
    /* 4C654 8005BE54 00000000 */  nop
    /* 4C658 8005BE58 0E004010 */  beqz       $v0, .L8005BE94
    /* 4C65C 8005BE5C 1000A427 */   addiu     $a0, $sp, 0x10
    /* 4C660 8005BE60 5D018293 */  lbu        $v0, %gp_rel(D_8009B065)($gp)
    /* 4C664 8005BE64 00000000 */  nop
    /* 4C668 8005BE68 03004014 */  bnez       $v0, .L8005BE78
    /* 4C66C 8005BE6C C0FF4224 */   addiu     $v0, $v0, -0x40
  .L8005BE70:
    /* 4C670 8005BE70 EE6F0108 */  j          .L8005BFB8
    /* 4C674 8005BE74 01000224 */   addiu     $v0, $zero, 0x1
  .L8005BE78:
    /* 4C678 8005BE78 02004104 */  bgez       $v0, .L8005BE84
    /* 4C67C 8005BE7C 00000000 */   nop
    /* 4C680 8005BE80 21100000 */  addu       $v0, $zero, $zero
  .L8005BE84:
    /* 4C684 8005BE84 5D0182A3 */  sb         $v0, %gp_rel(D_8009B065)($gp)
    /* 4C688 8005BE88 D613010C */  jal        func_80044F58
    /* 4C68C 8005BE8C FF004430 */   andi      $a0, $v0, 0xFF
    /* 4C690 8005BE90 1000A427 */  addiu      $a0, $sp, 0x10
  .L8005BE94:
    /* 4C694 8005BE94 5A0180A3 */  sb         $zero, %gp_rel(D_8009B062)($gp)
    /* 4C698 8005BE98 B2FF010C */  jal        func_8007FEC8
    /* 4C69C 8005BE9C 00000000 */   nop
    /* 4C6A0 8005BEA0 0400033C */  lui        $v1, (0x42424 >> 16)
    /* 4C6A4 8005BEA4 9005828F */  lw         $v0, %gp_rel(D_8009B498)($gp)
    /* 4C6A8 8005BEA8 1000A487 */  lh         $a0, 0x10($sp)
    /* 4C6AC 8005BEAC 21304300 */  addu       $a2, $v0, $v1
    /* 4C6B0 8005BEB0 58018293 */  lbu        $v0, %gp_rel(D_8009B060)($gp)
    /* 4C6B4 8005BEB4 2424C384 */  lh         $v1, (0x42424 & 0xFFFF)($a2)
    /* 4C6B8 8005BEB8 03004010 */  beqz       $v0, .L8005BEC8
    /* 4C6BC 8005BEBC 2138C000 */   addu      $a3, $a2, $zero
    /* 4C6C0 8005BEC0 B36F0108 */  j          .L8005BECC
    /* 4C6C4 8005BEC4 E0010224 */   addiu     $v0, $zero, 0x1E0
  .L8005BEC8:
    /* 4C6C8 8005BEC8 40010224 */  addiu      $v0, $zero, 0x140
  .L8005BECC:
    /* 4C6CC 8005BECC 23104300 */  subu       $v0, $v0, $v1
    /* 4C6D0 8005BED0 C21F0200 */  srl        $v1, $v0, 31
    /* 4C6D4 8005BED4 21104300 */  addu       $v0, $v0, $v1
    /* 4C6D8 8005BED8 43100200 */  sra        $v0, $v0, 1
    /* 4C6DC 8005BEDC 21208200 */  addu       $a0, $a0, $v0
    /* 4C6E0 8005BEE0 0100033C */  lui        $v1, (0x1B000 >> 16)
    /* 4C6E4 8005BEE4 00B06334 */  ori        $v1, $v1, (0x1B000 & 0xFFFF)
    /* 4C6E8 8005BEE8 58018593 */  lbu        $a1, %gp_rel(D_8009B060)($gp)
    /* 4C6EC 8005BEEC 5E018293 */  lbu        $v0, %gp_rel(D_8009B066)($gp)
    /* 4C6F0 8005BEF0 0400103C */  lui        $s0, (0x4242E >> 16)
    /* 4C6F4 8005BEF4 2824E4A4 */  sh         $a0, 0x2428($a3)
    /* 4C6F8 8005BEF8 2024C4A4 */  sh         $a0, 0x2420($a2)
    /* 4C6FC 8005BEFC 9005868F */  lw         $a2, %gp_rel(D_8009B498)($gp)
    /* 4C700 8005BF00 C0200200 */  sll        $a0, $v0, 3
    /* 4C704 8005BF04 23208200 */  subu       $a0, $a0, $v0
    /* 4C708 8005BF08 40230400 */  sll        $a0, $a0, 13
    /* 4C70C 8005BF0C 21208300 */  addu       $a0, $a0, $v1
    /* 4C710 8005BF10 2120C400 */  addu       $a0, $a2, $a0
    /* 4C714 8005BF14 2130D000 */  addu       $a2, $a2, $s0
    /* 4C718 8005BF18 2624C384 */  lh         $v1, (0x42426 & 0xFFFF)($a2)
    /* 4C71C 8005BF1C F0000224 */  addiu      $v0, $zero, 0xF0
    /* 4C720 8005BF20 23104300 */  subu       $v0, $v0, $v1
    /* 4C724 8005BF24 C21F0200 */  srl        $v1, $v0, 31
    /* 4C728 8005BF28 21104300 */  addu       $v0, $v0, $v1
    /* 4C72C 8005BF2C 1200A397 */  lhu        $v1, 0x12($sp)
    /* 4C730 8005BF30 43100200 */  sra        $v0, $v0, 1
    /* 4C734 8005BF34 21186200 */  addu       $v1, $v1, $v0
    /* 4C738 8005BF38 2A24C3A4 */  sh         $v1, (0x4242A & 0xFFFF)($a2)
    /* 4C73C 8005BF3C 4E3F020C */  jal        func_8008FD38
    /* 4C740 8005BF40 2224C3A4 */   sh        $v1, (0x42422 & 0xFFFF)($a2)
    /* 4C744 8005BF44 9005878F */  lw         $a3, %gp_rel(D_8009B498)($gp)
    /* 4C748 8005BF48 00000000 */  nop
    /* 4C74C 8005BF4C 2180F000 */  addu       $s0, $a3, $s0
    /* 4C750 8005BF50 2C240586 */  lh         $a1, (0x4242C & 0xFFFF)($s0)
    /* 4C754 8005BF54 2E240286 */  lh         $v0, (0x4242E & 0xFFFF)($s0)
    /* 4C758 8005BF58 00000000 */  nop
    /* 4C75C 8005BF5C 1800A200 */  mult       $a1, $v0
    /* 4C760 8005BF60 0300063C */  lui        $a2, (0x37000 >> 16)
    /* 4C764 8005BF64 5F018393 */  lbu        $v1, %gp_rel(D_8009B067)($gp)
    /* 4C768 8005BF68 0070C634 */  ori        $a2, $a2, (0x37000 & 0xFFFF)
    /* 4C76C 8005BF6C 40100300 */  sll        $v0, $v1, 1
    /* 4C770 8005BF70 21104300 */  addu       $v0, $v0, $v1
    /* 4C774 8005BF74 00210200 */  sll        $a0, $v0, 4
    /* 4C778 8005BF78 23208200 */  subu       $a0, $a0, $v0
    /* 4C77C 8005BF7C 00220400 */  sll        $a0, $a0, 8
    /* 4C780 8005BF80 21208600 */  addu       $a0, $a0, $a2
    /* 4C784 8005BF84 2120E400 */  addu       $a0, $a3, $a0
    /* 4C788 8005BF88 12280000 */  mflo       $a1
    /* 4C78C 8005BF8C C2170500 */  srl        $v0, $a1, 31
    /* 4C790 8005BF90 2128A200 */  addu       $a1, $a1, $v0
    /* 4C794 8005BF94 6D3F020C */  jal        func_8008FDB4
    /* 4C798 8005BF98 43280500 */   sra       $a1, $a1, 1
    /* 4C79C 8005BF9C F26F010C */  jal        func_8005BFC8
    /* 4C7A0 8005BFA0 01000424 */   addiu     $a0, $zero, 0x1
    /* 4C7A4 8005BFA4 04004014 */  bnez       $v0, .L8005BFB8
    /* 4C7A8 8005BFA8 00000000 */   nop
    /* 4C7AC 8005BFAC 7571010C */  jal        func_8005C5D4
    /* 4C7B0 8005BFB0 00000000 */   nop
    /* 4C7B4 8005BFB4 21100000 */  addu       $v0, $zero, $zero
  .L8005BFB8:
    /* 4C7B8 8005BFB8 7400BF8F */  lw         $ra, 0x74($sp)
    /* 4C7BC 8005BFBC 7000B08F */  lw         $s0, 0x70($sp)
    /* 4C7C0 8005BFC0 0800E003 */  jr         $ra
    /* 4C7C4 8005BFC4 7800BD27 */   addiu     $sp, $sp, 0x78
endlabel func_8005BE3C
