nonmatching func_8006CD78, 0x243C

glabel func_8006CD78
    /* 5D578 8006CD78 D8FEBD27 */  addiu      $sp, $sp, -0x128
    /* 5D57C 8006CD7C 0001B0AF */  sw         $s0, 0x100($sp)
    /* 5D580 8006CD80 21808000 */  addu       $s0, $a0, $zero
    /* 5D584 8006CD84 0401B1AF */  sw         $s1, 0x104($sp)
    /* 5D588 8006CD88 2188A000 */  addu       $s1, $a1, $zero
    /* 5D58C 8006CD8C 1401B5AF */  sw         $s5, 0x114($sp)
    /* 5D590 8006CD90 9000B527 */  addiu      $s5, $sp, 0x90
    /* 5D594 8006CD94 2120A002 */  addu       $a0, $s5, $zero
    /* 5D598 8006CD98 21280000 */  addu       $a1, $zero, $zero
    /* 5D59C 8006CD9C 08000624 */  addiu      $a2, $zero, 0x8
    /* 5D5A0 8006CDA0 2401BFAF */  sw         $ra, 0x124($sp)
    /* 5D5A4 8006CDA4 2001BEAF */  sw         $fp, 0x120($sp)
    /* 5D5A8 8006CDA8 1C01B7AF */  sw         $s7, 0x11C($sp)
    /* 5D5AC 8006CDAC 1801B6AF */  sw         $s6, 0x118($sp)
    /* 5D5B0 8006CDB0 1001B4AF */  sw         $s4, 0x110($sp)
    /* 5D5B4 8006CDB4 0C01B3AF */  sw         $s3, 0x10C($sp)
    /* 5D5B8 8006CDB8 F438020C */  jal        func_8008E3D0
    /* 5D5BC 8006CDBC 0801B2AF */   sw        $s2, 0x108($sp)
    /* 5D5C0 8006CDC0 9800B427 */  addiu      $s4, $sp, 0x98
    /* 5D5C4 8006CDC4 21208002 */  addu       $a0, $s4, $zero
    /* 5D5C8 8006CDC8 21280000 */  addu       $a1, $zero, $zero
    /* 5D5CC 8006CDCC F438020C */  jal        func_8008E3D0
    /* 5D5D0 8006CDD0 08000624 */   addiu     $a2, $zero, 0x8
    /* 5D5D4 8006CDD4 0180023C */  lui        $v0, %hi(D_8001188C)
    /* 5D5D8 8006CDD8 8C185924 */  addiu      $t9, $v0, %lo(D_8001188C)
    /* 5D5DC 8006CDDC 00002E8F */  lw         $t6, 0x0($t9)
    /* 5D5E0 8006CDE0 04002F8F */  lw         $t7, 0x4($t9)
    /* 5D5E4 8006CDE4 0800388F */  lw         $t8, 0x8($t9)
    /* 5D5E8 8006CDE8 A000AEAF */  sw         $t6, 0xA0($sp)
    /* 5D5EC 8006CDEC A400AFAF */  sw         $t7, 0xA4($sp)
    /* 5D5F0 8006CDF0 A800B8AF */  sw         $t8, 0xA8($sp)
    /* 5D5F4 8006CDF4 0C002E8F */  lw         $t6, 0xC($t9)
    /* 5D5F8 8006CDF8 00000000 */  nop
    /* 5D5FC 8006CDFC AC00AEAF */  sw         $t6, 0xAC($sp)
    /* 5D600 8006CE00 7363010C */  jal        func_80058DCC
    /* 5D604 8006CE04 21980002 */   addu      $s3, $s0, $zero
    /* 5D608 8006CE08 6800B227 */  addiu      $s2, $sp, 0x68
    /* 5D60C 8006CE0C A000B627 */  addiu      $s6, $sp, 0xA0
    /* 5D610 8006CE10 F0012006 */  bltz       $s1, .L8006D5D4
    /* 5D614 8006CE14 D800A2AF */   sw        $v0, 0xD8($sp)
    /* 5D618 8006CE18 21A80000 */  addu       $s5, $zero, $zero
    /* 5D61C 8006CE1C 0980023C */  lui        $v0, %hi(D_80091610)
    /* 5D620 8006CE20 10164624 */  addiu      $a2, $v0, %lo(D_80091610)
    /* 5D624 8006CE24 21386002 */  addu       $a3, $s3, $zero
    /* 5D628 8006CE28 0980023C */  lui        $v0, %hi(D_800916D4)
    /* 5D62C 8006CE2C D4164224 */  addiu      $v0, $v0, %lo(D_800916D4)
    /* 5D630 8006CE30 000062AE */  sw         $v0, 0x0($s3)
    /* 5D634 8006CE34 AE000224 */  addiu      $v0, $zero, 0xAE
    /* 5D638 8006CE38 8A0D62A6 */  sh         $v0, 0xD8A($s3)
    /* 5D63C 8006CE3C 203D0224 */  addiu      $v0, $zero, 0x3D20
    /* 5D640 8006CE40 8C0D62A6 */  sh         $v0, 0xD8C($s3)
  .L8006CE44:
    /* 5D644 8006CE44 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5D648 8006CE48 0000C494 */  lhu        $a0, 0x0($a2)
    /* 5D64C 8006CE4C 0600C594 */  lhu        $a1, 0x6($a2)
    /* 5D650 8006CE50 0400C394 */  lhu        $v1, 0x4($a2)
    /* 5D654 8006CE54 03008430 */  andi       $a0, $a0, 0x3
    /* 5D658 8006CE58 C0210400 */  sll        $a0, $a0, 7
    /* 5D65C 8006CE5C 0001A230 */  andi       $v0, $a1, 0x100
    /* 5D660 8006CE60 00140200 */  sll        $v0, $v0, 16
    /* 5D664 8006CE64 03150200 */  sra        $v0, $v0, 20
    /* 5D668 8006CE68 20004234 */  ori        $v0, $v0, 0x20
    /* 5D66C 8006CE6C 25208200 */  or         $a0, $a0, $v0
    /* 5D670 8006CE70 FF036330 */  andi       $v1, $v1, 0x3FF
    /* 5D674 8006CE74 82190300 */  srl        $v1, $v1, 6
    /* 5D678 8006CE78 25208300 */  or         $a0, $a0, $v1
    /* 5D67C 8006CE7C 0002A530 */  andi       $a1, $a1, 0x200
    /* 5D680 8006CE80 80280500 */  sll        $a1, $a1, 2
    /* 5D684 8006CE84 25208500 */  or         $a0, $a0, $a1
    /* 5D688 8006CE88 8E0DE4A4 */  sh         $a0, 0xD8E($a3)
    /* 5D68C 8006CE8C 1200C394 */  lhu        $v1, 0x12($a2)
    /* 5D690 8006CE90 1000C294 */  lhu        $v0, 0x10($a2)
    /* 5D694 8006CE94 1C00C624 */  addiu      $a2, $a2, 0x1C
    /* 5D698 8006CE98 80190300 */  sll        $v1, $v1, 6
    /* 5D69C 8006CE9C 02110200 */  srl        $v0, $v0, 4
    /* 5D6A0 8006CEA0 3F004230 */  andi       $v0, $v0, 0x3F
    /* 5D6A4 8006CEA4 25186200 */  or         $v1, $v1, $v0
    /* 5D6A8 8006CEA8 900DE3A4 */  sh         $v1, 0xD90($a3)
    /* 5D6AC 8006CEAC E5FFA01A */  blez       $s5, .L8006CE44
    /* 5D6B0 8006CEB0 0400E724 */   addiu     $a3, $a3, 0x4
    /* 5D6B4 8006CEB4 D800A48F */  lw         $a0, 0xD8($sp)
    /* 5D6B8 8006CEB8 885F010C */  jal        func_80057E20
    /* 5D6BC 8006CEBC 9800A527 */   addiu     $a1, $sp, 0x98
    /* 5D6C0 8006CEC0 21A80000 */  addu       $s5, $zero, $zero
    /* 5D6C4 8006CEC4 AA2A163C */  lui        $s6, (0x2AAAAAAB >> 16)
    /* 5D6C8 8006CEC8 ABAAD636 */  ori        $s6, $s6, (0x2AAAAAAB & 0xFFFF)
    /* 5D6CC 8006CECC 21886002 */  addu       $s1, $s3, $zero
    /* 5D6D0 8006CED0 21806002 */  addu       $s0, $s3, $zero
    /* 5D6D4 8006CED4 21A0A002 */  addu       $s4, $s5, $zero
  .L8006CED8:
    /* 5D6D8 8006CED8 481A020C */  jal        func_80086920
    /* 5D6DC 8006CEDC 21208002 */   addu      $a0, $s4, $zero
    /* 5D6E0 8006CEE0 21284000 */  addu       $a1, $v0, $zero
    /* 5D6E4 8006CEE4 9C00A287 */  lh         $v0, 0x9C($sp)
    /* 5D6E8 8006CEE8 9800A387 */  lh         $v1, 0x98($sp)
    /* 5D6EC 8006CEEC 9C00A497 */  lhu        $a0, 0x9C($sp)
    /* 5D6F0 8006CEF0 2A104300 */  slt        $v0, $v0, $v1
    /* 5D6F4 8006CEF4 9800A397 */  lhu        $v1, 0x98($sp)
    /* 5D6F8 8006CEF8 02004010 */  beqz       $v0, .L8006CF04
    /* 5D6FC 8006CEFC 08001226 */   addiu     $s2, $s0, 0x8
    /* 5D700 8006CF00 21206000 */  addu       $a0, $v1, $zero
  .L8006CF04:
    /* 5D704 8006CF04 00140400 */  sll        $v0, $a0, 16
    /* 5D708 8006CF08 03140200 */  sra        $v0, $v0, 16
    /* 5D70C 8006CF0C 40180500 */  sll        $v1, $a1, 1
    /* 5D710 8006CF10 18004300 */  mult       $v0, $v1
    /* 5D714 8006CF14 12100000 */  mflo       $v0
    /* 5D718 8006CF18 02004104 */  bgez       $v0, .L8006CF24
    /* 5D71C 8006CF1C 21208002 */   addu      $a0, $s4, $zero
    /* 5D720 8006CF20 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006CF24:
    /* 5D724 8006CF24 03130200 */  sra        $v0, $v0, 12
    /* 5D728 8006CF28 080002A6 */  sh         $v0, 0x8($s0)
    /* 5D72C 8006CF2C EC1A020C */  jal        func_80086BB0
    /* 5D730 8006CF30 020040A6 */   sh        $zero, 0x2($s2)
    /* 5D734 8006CF34 21304000 */  addu       $a2, $v0, $zero
    /* 5D738 8006CF38 9C00A597 */  lhu        $a1, 0x9C($sp)
    /* 5D73C 8006CF3C 9C00A387 */  lh         $v1, 0x9C($sp)
    /* 5D740 8006CF40 9800A487 */  lh         $a0, 0x98($sp)
    /* 5D744 8006CF44 9800A297 */  lhu        $v0, 0x98($sp)
    /* 5D748 8006CF48 2A186400 */  slt        $v1, $v1, $a0
    /* 5D74C 8006CF4C 02006010 */  beqz       $v1, .L8006CF58
    /* 5D750 8006CF50 00000000 */   nop
    /* 5D754 8006CF54 21284000 */  addu       $a1, $v0, $zero
  .L8006CF58:
    /* 5D758 8006CF58 00140500 */  sll        $v0, $a1, 16
    /* 5D75C 8006CF5C 03140200 */  sra        $v0, $v0, 16
    /* 5D760 8006CF60 40180600 */  sll        $v1, $a2, 1
    /* 5D764 8006CF64 18004300 */  mult       $v0, $v1
    /* 5D768 8006CF68 12100000 */  mflo       $v0
    /* 5D76C 8006CF6C 02004104 */  bgez       $v0, .L8006CF78
    /* 5D770 8006CF70 00000000 */   nop
    /* 5D774 8006CF74 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006CF78:
    /* 5D778 8006CF78 03130200 */  sra        $v0, $v0, 12
    /* 5D77C 8006CF7C 040042A6 */  sh         $v0, 0x4($s2)
    /* 5D780 8006CF80 08000286 */  lh         $v0, 0x8($s0)
    /* 5D784 8006CF84 00000000 */  nop
    /* 5D788 8006CF88 23100200 */  negu       $v0, $v0
    /* 5D78C 8006CF8C 18005600 */  mult       $v0, $s6
    /* 5D790 8006CF90 20000426 */  addiu      $a0, $s0, 0x20
    /* 5D794 8006CF94 C3170200 */  sra        $v0, $v0, 31
    /* 5D798 8006CF98 10700000 */  mfhi       $t6
    /* 5D79C 8006CF9C C3180E00 */  sra        $v1, $t6, 3
    /* 5D7A0 8006CFA0 23186200 */  subu       $v1, $v1, $v0
    /* 5D7A4 8006CFA4 200003A6 */  sh         $v1, 0x20($s0)
    /* 5D7A8 8006CFA8 020080A4 */  sh         $zero, 0x2($a0)
    /* 5D7AC 8006CFAC 0C000286 */  lh         $v0, 0xC($s0)
    /* 5D7B0 8006CFB0 00000000 */  nop
    /* 5D7B4 8006CFB4 23100200 */  negu       $v0, $v0
    /* 5D7B8 8006CFB8 18005600 */  mult       $v0, $s6
    /* 5D7BC 8006CFBC C3170200 */  sra        $v0, $v0, 31
    /* 5D7C0 8006CFC0 10700000 */  mfhi       $t6
    /* 5D7C4 8006CFC4 C3180E00 */  sra        $v1, $t6, 3
    /* 5D7C8 8006CFC8 23186200 */  subu       $v1, $v1, $v0
    /* 5D7CC 8006CFCC 040083A4 */  sh         $v1, 0x4($a0)
    /* 5D7D0 8006CFD0 0000628E */  lw         $v0, 0x0($s3)
    /* 5D7D4 8006CFD4 00000000 */  nop
    /* 5D7D8 8006CFD8 21105500 */  addu       $v0, $v0, $s5
    /* 5D7DC 8006CFDC 00004290 */  lbu        $v0, 0x0($v0)
    /* 5D7E0 8006CFE0 00000000 */  nop
    /* 5D7E4 8006CFE4 C2100200 */  srl        $v0, $v0, 3
    /* 5D7E8 8006CFE8 920D22A2 */  sb         $v0, 0xD92($s1)
    /* 5D7EC 8006CFEC 0000628E */  lw         $v0, 0x0($s3)
    /* 5D7F0 8006CFF0 00000000 */  nop
    /* 5D7F4 8006CFF4 21105500 */  addu       $v0, $v0, $s5
    /* 5D7F8 8006CFF8 03004290 */  lbu        $v0, 0x3($v0)
    /* 5D7FC 8006CFFC 55059426 */  addiu      $s4, $s4, 0x555
    /* 5D800 8006D000 C2100200 */  srl        $v0, $v0, 3
    /* 5D804 8006D004 930D22A2 */  sb         $v0, 0xD93($s1)
    /* 5D808 8006D008 0000628E */  lw         $v0, 0x0($s3)
    /* 5D80C 8006D00C 21804002 */  addu       $s0, $s2, $zero
    /* 5D810 8006D010 21105500 */  addu       $v0, $v0, $s5
    /* 5D814 8006D014 06004290 */  lbu        $v0, 0x6($v0)
    /* 5D818 8006D018 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5D81C 8006D01C C2100200 */  srl        $v0, $v0, 3
    /* 5D820 8006D020 940D22A2 */  sb         $v0, 0xD94($s1)
    /* 5D824 8006D024 0300A22A */  slti       $v0, $s5, 0x3
    /* 5D828 8006D028 ABFF4014 */  bnez       $v0, .L8006CED8
    /* 5D82C 8006D02C 04003126 */   addiu     $s1, $s1, 0x4
    /* 5D830 8006D030 9C00A497 */  lhu        $a0, 0x9C($sp)
    /* 5D834 8006D034 9C00A287 */  lh         $v0, 0x9C($sp)
    /* 5D838 8006D038 9800A387 */  lh         $v1, 0x98($sp)
    /* 5D83C 8006D03C 00000000 */  nop
    /* 5D840 8006D040 2A104300 */  slt        $v0, $v0, $v1
    /* 5D844 8006D044 9800A397 */  lhu        $v1, 0x98($sp)
    /* 5D848 8006D048 02004010 */  beqz       $v0, .L8006D054
    /* 5D84C 8006D04C 00000000 */   nop
    /* 5D850 8006D050 21206000 */  addu       $a0, $v1, $zero
  .L8006D054:
    /* 5D854 8006D054 001C0400 */  sll        $v1, $a0, 16
    /* 5D858 8006D058 03140300 */  sra        $v0, $v1, 16
    /* 5D85C 8006D05C C21F0300 */  srl        $v1, $v1, 31
    /* 5D860 8006D060 21104300 */  addu       $v0, $v0, $v1
    /* 5D864 8006D064 43100200 */  sra        $v0, $v0, 1
    /* 5D868 8006D068 C8004224 */  addiu      $v0, $v0, 0xC8
    /* 5D86C 8006D06C 800D62A6 */  sh         $v0, 0xD80($s3)
    /* 5D870 8006D070 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 5D874 8006D074 0102422C */  sltiu      $v0, $v0, 0x201
    /* 5D878 8006D078 03004014 */  bnez       $v0, .L8006D088
    /* 5D87C 8006D07C 21A80000 */   addu      $s5, $zero, $zero
    /* 5D880 8006D080 00020224 */  addiu      $v0, $zero, 0x200
    /* 5D884 8006D084 800D62A6 */  sh         $v0, 0xD80($s3)
  .L8006D088:
    /* 5D888 8006D088 21A06002 */  addu       $s4, $s3, $zero
    /* 5D88C 8006D08C 21906002 */  addu       $s2, $s3, $zero
    /* 5D890 8006D090 80000224 */  addiu      $v0, $zero, 0x80
    /* 5D894 8006D094 9E0D62A2 */  sb         $v0, 0xD9E($s3)
    /* 5D898 8006D098 9F0D62A2 */  sb         $v0, 0xD9F($s3)
    /* 5D89C 8006D09C A00D62A2 */  sb         $v0, 0xDA0($s3)
  .L8006D0A0:
    /* 5D8A0 8006D0A0 6439020C */  jal        func_8008E590
    /* 5D8A4 8006D0A4 00000000 */   nop
    /* 5D8A8 8006D0A8 6439020C */  jal        func_8008E590
    /* 5D8AC 8006D0AC 21804000 */   addu      $s0, $v0, $zero
    /* 5D8B0 8006D0B0 23800202 */  subu       $s0, $s0, $v0
    /* 5D8B4 8006D0B4 02000106 */  bgez       $s0, .L8006D0C0
    /* 5D8B8 8006D0B8 21100002 */   addu      $v0, $s0, $zero
    /* 5D8BC 8006D0BC FF0F0226 */  addiu      $v0, $s0, 0xFFF
  .L8006D0C0:
    /* 5D8C0 8006D0C0 038B0200 */  sra        $s1, $v0, 12
    /* 5D8C4 8006D0C4 00131100 */  sll        $v0, $s1, 12
    /* 5D8C8 8006D0C8 6439020C */  jal        func_8008E590
    /* 5D8CC 8006D0CC 23880202 */   subu      $s1, $s0, $v0
    /* 5D8D0 8006D0D0 6439020C */  jal        func_8008E590
    /* 5D8D4 8006D0D4 21804000 */   addu      $s0, $v0, $zero
    /* 5D8D8 8006D0D8 23800202 */  subu       $s0, $s0, $v0
    /* 5D8DC 8006D0DC 02000106 */  bgez       $s0, .L8006D0E8
    /* 5D8E0 8006D0E0 21200002 */   addu      $a0, $s0, $zero
    /* 5D8E4 8006D0E4 FF0F0426 */  addiu      $a0, $s0, 0xFFF
  .L8006D0E8:
    /* 5D8E8 8006D0E8 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5D8EC 8006D0EC 00000000 */  nop
    /* 5D8F0 8006D0F0 18005100 */  mult       $v0, $s1
    /* 5D8F4 8006D0F4 035B0400 */  sra        $t3, $a0, 12
    /* 5D8F8 8006D0F8 38004426 */  addiu      $a0, $s2, 0x38
    /* 5D8FC 8006D0FC 00130B00 */  sll        $v0, $t3, 12
    /* 5D900 8006D100 12180000 */  mflo       $v1
    /* 5D904 8006D104 02006104 */  bgez       $v1, .L8006D110
    /* 5D908 8006D108 23580202 */   subu      $t3, $s0, $v0
    /* 5D90C 8006D10C FF0F6324 */  addiu      $v1, $v1, 0xFFF
  .L8006D110:
    /* 5D910 8006D110 03130300 */  sra        $v0, $v1, 12
    /* 5D914 8006D114 380042A6 */  sh         $v0, 0x38($s2)
    /* 5D918 8006D118 020080A4 */  sh         $zero, 0x2($a0)
    /* 5D91C 8006D11C 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5D920 8006D120 00000000 */  nop
    /* 5D924 8006D124 18004B00 */  mult       $v0, $t3
    /* 5D928 8006D128 12100000 */  mflo       $v0
    /* 5D92C 8006D12C 02004104 */  bgez       $v0, .L8006D138
    /* 5D930 8006D130 00000000 */   nop
    /* 5D934 8006D134 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006D138:
    /* 5D938 8006D138 03130200 */  sra        $v0, $v0, 12
    /* 5D93C 8006D13C 040082A4 */  sh         $v0, 0x4($a0)
    /* 5D940 8006D140 40101100 */  sll        $v0, $s1, 1
    /* 5D944 8006D144 21105100 */  addu       $v0, $v0, $s1
    /* 5D948 8006D148 C0100200 */  sll        $v0, $v0, 3
    /* 5D94C 8006D14C 02004104 */  bgez       $v0, .L8006D158
    /* 5D950 8006D150 38025026 */   addiu     $s0, $s2, 0x238
    /* 5D954 8006D154 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006D158:
    /* 5D958 8006D158 03130200 */  sra        $v0, $v0, 12
    /* 5D95C 8006D15C 380242A6 */  sh         $v0, 0x238($s2)
    /* 5D960 8006D160 6439020C */  jal        func_8008E590
    /* 5D964 8006D164 F000ABAF */   sw        $t3, 0xF0($sp)
    /* 5D968 8006D168 F000AB8F */  lw         $t3, 0xF0($sp)
    /* 5D96C 8006D16C 02004104 */  bgez       $v0, .L8006D178
    /* 5D970 8006D170 21184000 */   addu      $v1, $v0, $zero
    /* 5D974 8006D174 FF0F4324 */  addiu      $v1, $v0, 0xFFF
  .L8006D178:
    /* 5D978 8006D178 031B0300 */  sra        $v1, $v1, 12
    /* 5D97C 8006D17C 001B0300 */  sll        $v1, $v1, 12
    /* 5D980 8006D180 23184300 */  subu       $v1, $v0, $v1
    /* 5D984 8006D184 40100300 */  sll        $v0, $v1, 1
    /* 5D988 8006D188 21104300 */  addu       $v0, $v0, $v1
    /* 5D98C 8006D18C C0100200 */  sll        $v0, $v0, 3
    /* 5D990 8006D190 23100200 */  negu       $v0, $v0
    /* 5D994 8006D194 02004104 */  bgez       $v0, .L8006D1A0
    /* 5D998 8006D198 00000000 */   nop
    /* 5D99C 8006D19C FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006D1A0:
    /* 5D9A0 8006D1A0 03130200 */  sra        $v0, $v0, 12
    /* 5D9A4 8006D1A4 020002A6 */  sh         $v0, 0x2($s0)
    /* 5D9A8 8006D1A8 40100B00 */  sll        $v0, $t3, 1
    /* 5D9AC 8006D1AC 21104B00 */  addu       $v0, $v0, $t3
    /* 5D9B0 8006D1B0 C0100200 */  sll        $v0, $v0, 3
    /* 5D9B4 8006D1B4 02004104 */  bgez       $v0, .L8006D1C0
    /* 5D9B8 8006D1B8 00000000 */   nop
    /* 5D9BC 8006D1BC FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006D1C0:
    /* 5D9C0 8006D1C0 03130200 */  sra        $v0, $v0, 12
    /* 5D9C4 8006D1C4 6439020C */  jal        func_8008E590
    /* 5D9C8 8006D1C8 040002A6 */   sh        $v0, 0x4($s0)
    /* 5D9CC 8006D1CC 21184000 */  addu       $v1, $v0, $zero
    /* 5D9D0 8006D1D0 03006104 */  bgez       $v1, .L8006D1E0
    /* 5D9D4 8006D1D4 83100200 */   sra       $v0, $v0, 2
    /* 5D9D8 8006D1D8 03006224 */  addiu      $v0, $v1, 0x3
    /* 5D9DC 8006D1DC 83100200 */  sra        $v0, $v0, 2
  .L8006D1E0:
    /* 5D9E0 8006D1E0 80100200 */  sll        $v0, $v0, 2
    /* 5D9E4 8006D1E4 23106200 */  subu       $v0, $v1, $v0
    /* 5D9E8 8006D1E8 400C82A6 */  sh         $v0, 0xC40($s4)
    /* 5D9EC 8006D1EC 02009426 */  addiu      $s4, $s4, 0x2
    /* 5D9F0 8006D1F0 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5D9F4 8006D1F4 4000A22A */  slti       $v0, $s5, 0x40
    /* 5D9F8 8006D1F8 A9FF4014 */  bnez       $v0, .L8006D0A0
    /* 5D9FC 8006D1FC 08005226 */   addiu     $s2, $s2, 0x8
    /* 5DA00 8006D200 21A80000 */  addu       $s5, $zero, $zero
    /* 5DA04 8006D204 01001724 */  addiu      $s7, $zero, 0x1
    /* 5DA08 8006D208 21A06002 */  addu       $s4, $s3, $zero
    /* 5DA0C 8006D20C 21B06002 */  addu       $s6, $s3, $zero
    /* 5DA10 8006D210 21806002 */  addu       $s0, $s3, $zero
  .L8006D214:
    /* 5DA14 8006D214 C0911500 */  sll        $s2, $s5, 7
    /* 5DA18 8006D218 481A020C */  jal        func_80086920
    /* 5DA1C 8006D21C 21204002 */   addu      $a0, $s2, $zero
    /* 5DA20 8006D220 800D6396 */  lhu        $v1, 0xD80($s3)
    /* 5DA24 8006D224 00000000 */  nop
    /* 5DA28 8006D228 18006200 */  mult       $v1, $v0
    /* 5DA2C 8006D22C 12100000 */  mflo       $v0
    /* 5DA30 8006D230 02004104 */  bgez       $v0, .L8006D23C
    /* 5DA34 8006D234 38041126 */   addiu     $s1, $s0, 0x438
    /* 5DA38 8006D238 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006D23C:
    /* 5DA3C 8006D23C 21204002 */  addu       $a0, $s2, $zero
    /* 5DA40 8006D240 03130200 */  sra        $v0, $v0, 12
    /* 5DA44 8006D244 380402A6 */  sh         $v0, 0x438($s0)
    /* 5DA48 8006D248 EC1A020C */  jal        func_80086BB0
    /* 5DA4C 8006D24C 020020A6 */   sh        $zero, 0x2($s1)
    /* 5DA50 8006D250 800D6396 */  lhu        $v1, 0xD80($s3)
    /* 5DA54 8006D254 00000000 */  nop
    /* 5DA58 8006D258 18006200 */  mult       $v1, $v0
    /* 5DA5C 8006D25C 12100000 */  mflo       $v0
    /* 5DA60 8006D260 02004104 */  bgez       $v0, .L8006D26C
    /* 5DA64 8006D264 00000000 */   nop
    /* 5DA68 8006D268 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006D26C:
    /* 5DA6C 8006D26C 03130200 */  sra        $v0, $v0, 12
    /* 5DA70 8006D270 040022A6 */  sh         $v0, 0x4($s1)
    /* 5DA74 8006D274 38040286 */  lh         $v0, 0x438($s0)
    /* 5DA78 8006D278 00000000 */  nop
    /* 5DA7C 8006D27C 23100200 */  negu       $v0, $v0
    /* 5DA80 8006D280 02004104 */  bgez       $v0, .L8006D28C
    /* 5DA84 8006D284 38050326 */   addiu     $v1, $s0, 0x538
    /* 5DA88 8006D288 7F004224 */  addiu      $v0, $v0, 0x7F
  .L8006D28C:
    /* 5DA8C 8006D28C C3110200 */  sra        $v0, $v0, 7
    /* 5DA90 8006D290 380502A6 */  sh         $v0, 0x538($s0)
    /* 5DA94 8006D294 F0FF0224 */  addiu      $v0, $zero, -0x10
    /* 5DA98 8006D298 020062A4 */  sh         $v0, 0x2($v1)
    /* 5DA9C 8006D29C 3C040286 */  lh         $v0, 0x43C($s0)
    /* 5DAA0 8006D2A0 00000000 */  nop
    /* 5DAA4 8006D2A4 23100200 */  negu       $v0, $v0
    /* 5DAA8 8006D2A8 02004104 */  bgez       $v0, .L8006D2B4
    /* 5DAAC 8006D2AC 00000000 */   nop
    /* 5DAB0 8006D2B0 7F004224 */  addiu      $v0, $v0, 0x7F
  .L8006D2B4:
    /* 5DAB4 8006D2B4 C3110200 */  sra        $v0, $v0, 7
    /* 5DAB8 8006D2B8 040062A4 */  sh         $v0, 0x4($v1)
    /* 5DABC 8006D2BC 481A020C */  jal        func_80086920
    /* 5DAC0 8006D2C0 21204002 */   addu      $a0, $s2, $zero
    /* 5DAC4 8006D2C4 02004104 */  bgez       $v0, .L8006D2D0
    /* 5DAC8 8006D2C8 38061126 */   addiu     $s1, $s0, 0x638
    /* 5DACC 8006D2CC 7F004224 */  addiu      $v0, $v0, 0x7F
  .L8006D2D0:
    /* 5DAD0 8006D2D0 21204002 */  addu       $a0, $s2, $zero
    /* 5DAD4 8006D2D4 C3110200 */  sra        $v0, $v0, 7
    /* 5DAD8 8006D2D8 380602A6 */  sh         $v0, 0x638($s0)
    /* 5DADC 8006D2DC EC1A020C */  jal        func_80086BB0
    /* 5DAE0 8006D2E0 020020A6 */   sh        $zero, 0x2($s1)
    /* 5DAE4 8006D2E4 02004104 */  bgez       $v0, .L8006D2F0
    /* 5DAE8 8006D2E8 00000000 */   nop
    /* 5DAEC 8006D2EC 7F004224 */  addiu      $v0, $v0, 0x7F
  .L8006D2F0:
    /* 5DAF0 8006D2F0 C3110200 */  sra        $v0, $v0, 7
    /* 5DAF4 8006D2F4 6439020C */  jal        func_8008E590
    /* 5DAF8 8006D2F8 040022A6 */   sh        $v0, 0x4($s1)
    /* 5DAFC 8006D2FC 21184000 */  addu       $v1, $v0, $zero
    /* 5DB00 8006D300 03006104 */  bgez       $v1, .L8006D310
    /* 5DB04 8006D304 C3100200 */   sra       $v0, $v0, 3
    /* 5DB08 8006D308 07006224 */  addiu      $v0, $v1, 0x7
    /* 5DB0C 8006D30C C3100200 */  sra        $v0, $v0, 3
  .L8006D310:
    /* 5DB10 8006D310 C0100200 */  sll        $v0, $v0, 3
    /* 5DB14 8006D314 23106200 */  subu       $v0, $v1, $v0
    /* 5DB18 8006D318 C00CC2A6 */  sh         $v0, 0xCC0($s6)
    /* 5DB1C 8006D31C A20D97A2 */  sb         $s7, 0xDA2($s4)
    /* 5DB20 8006D320 A30D97A2 */  sb         $s7, 0xDA3($s4)
    /* 5DB24 8006D324 A40D97A2 */  sb         $s7, 0xDA4($s4)
    /* 5DB28 8006D328 04009426 */  addiu      $s4, $s4, 0x4
    /* 5DB2C 8006D32C 0200D626 */  addiu      $s6, $s6, 0x2
    /* 5DB30 8006D330 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5DB34 8006D334 2000A22A */  slti       $v0, $s5, 0x20
    /* 5DB38 8006D338 B6FF4014 */  bnez       $v0, .L8006D214
    /* 5DB3C 8006D33C 08001026 */   addiu     $s0, $s0, 0x8
    /* 5DB40 8006D340 21A80000 */  addu       $s5, $zero, $zero
    /* 5DB44 8006D344 21886002 */  addu       $s1, $s3, $zero
  .L8006D348:
    /* 5DB48 8006D348 6439020C */  jal        func_8008E590
    /* 5DB4C 8006D34C 38073226 */   addiu     $s2, $s1, 0x738
    /* 5DB50 8006D350 6439020C */  jal        func_8008E590
    /* 5DB54 8006D354 21804000 */   addu      $s0, $v0, $zero
    /* 5DB58 8006D358 23800202 */  subu       $s0, $s0, $v0
    /* 5DB5C 8006D35C 02000106 */  bgez       $s0, .L8006D368
    /* 5DB60 8006D360 21180002 */   addu      $v1, $s0, $zero
    /* 5DB64 8006D364 FF0F0326 */  addiu      $v1, $s0, 0xFFF
  .L8006D368:
    /* 5DB68 8006D368 031B0300 */  sra        $v1, $v1, 12
    /* 5DB6C 8006D36C 001B0300 */  sll        $v1, $v1, 12
    /* 5DB70 8006D370 23180302 */  subu       $v1, $s0, $v1
    /* 5DB74 8006D374 80100300 */  sll        $v0, $v1, 2
    /* 5DB78 8006D378 21104300 */  addu       $v0, $v0, $v1
    /* 5DB7C 8006D37C 40110200 */  sll        $v0, $v0, 5
    /* 5DB80 8006D380 02004104 */  bgez       $v0, .L8006D38C
    /* 5DB84 8006D384 00000000 */   nop
    /* 5DB88 8006D388 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006D38C:
    /* 5DB8C 8006D38C 03130200 */  sra        $v0, $v0, 12
    /* 5DB90 8006D390 6439020C */  jal        func_8008E590
    /* 5DB94 8006D394 380722A6 */   sh        $v0, 0x738($s1)
    /* 5DB98 8006D398 6439020C */  jal        func_8008E590
    /* 5DB9C 8006D39C 21804000 */   addu      $s0, $v0, $zero
    /* 5DBA0 8006D3A0 23800202 */  subu       $s0, $s0, $v0
    /* 5DBA4 8006D3A4 02000106 */  bgez       $s0, .L8006D3B0
    /* 5DBA8 8006D3A8 21180002 */   addu      $v1, $s0, $zero
    /* 5DBAC 8006D3AC FF0F0326 */  addiu      $v1, $s0, 0xFFF
  .L8006D3B0:
    /* 5DBB0 8006D3B0 031B0300 */  sra        $v1, $v1, 12
    /* 5DBB4 8006D3B4 001B0300 */  sll        $v1, $v1, 12
    /* 5DBB8 8006D3B8 23180302 */  subu       $v1, $s0, $v1
    /* 5DBBC 8006D3BC 80100300 */  sll        $v0, $v1, 2
    /* 5DBC0 8006D3C0 21104300 */  addu       $v0, $v0, $v1
    /* 5DBC4 8006D3C4 40110200 */  sll        $v0, $v0, 5
    /* 5DBC8 8006D3C8 02004104 */  bgez       $v0, .L8006D3D4
    /* 5DBCC 8006D3CC 00000000 */   nop
    /* 5DBD0 8006D3D0 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006D3D4:
    /* 5DBD4 8006D3D4 03130200 */  sra        $v0, $v0, 12
    /* 5DBD8 8006D3D8 6439020C */  jal        func_8008E590
    /* 5DBDC 8006D3DC 020042A6 */   sh        $v0, 0x2($s2)
    /* 5DBE0 8006D3E0 6439020C */  jal        func_8008E590
    /* 5DBE4 8006D3E4 21804000 */   addu      $s0, $v0, $zero
    /* 5DBE8 8006D3E8 23800202 */  subu       $s0, $s0, $v0
    /* 5DBEC 8006D3EC 02000106 */  bgez       $s0, .L8006D3F8
    /* 5DBF0 8006D3F0 21180002 */   addu      $v1, $s0, $zero
    /* 5DBF4 8006D3F4 FF0F0326 */  addiu      $v1, $s0, 0xFFF
  .L8006D3F8:
    /* 5DBF8 8006D3F8 031B0300 */  sra        $v1, $v1, 12
    /* 5DBFC 8006D3FC 001B0300 */  sll        $v1, $v1, 12
    /* 5DC00 8006D400 23180302 */  subu       $v1, $s0, $v1
    /* 5DC04 8006D404 80100300 */  sll        $v0, $v1, 2
    /* 5DC08 8006D408 21104300 */  addu       $v0, $v0, $v1
    /* 5DC0C 8006D40C 40110200 */  sll        $v0, $v0, 5
    /* 5DC10 8006D410 02004104 */  bgez       $v0, .L8006D41C
    /* 5DC14 8006D414 00000000 */   nop
    /* 5DC18 8006D418 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006D41C:
    /* 5DC1C 8006D41C 03130200 */  sra        $v0, $v0, 12
    /* 5DC20 8006D420 040042A6 */  sh         $v0, 0x4($s2)
    /* 5DC24 8006D424 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5DC28 8006D428 2000A22A */  slti       $v0, $s5, 0x20
    /* 5DC2C 8006D42C C6FF4014 */  bnez       $v0, .L8006D348
    /* 5DC30 8006D430 08003126 */   addiu     $s1, $s1, 0x8
    /* 5DC34 8006D434 21A80000 */  addu       $s5, $zero, $zero
    /* 5DC38 8006D438 21A06002 */  addu       $s4, $s3, $zero
    /* 5DC3C 8006D43C 21886002 */  addu       $s1, $s3, $zero
  .L8006D440:
    /* 5DC40 8006D440 38082226 */  addiu      $v0, $s1, 0x838
    /* 5DC44 8006D444 380820A6 */  sh         $zero, 0x838($s1)
    /* 5DC48 8006D448 020040A4 */  sh         $zero, 0x2($v0)
    /* 5DC4C 8006D44C 6439020C */  jal        func_8008E590
    /* 5DC50 8006D450 040040A4 */   sh        $zero, 0x4($v0)
    /* 5DC54 8006D454 6439020C */  jal        func_8008E590
    /* 5DC58 8006D458 21804000 */   addu      $s0, $v0, $zero
    /* 5DC5C 8006D45C 23800202 */  subu       $s0, $s0, $v0
    /* 5DC60 8006D460 21180002 */  addu       $v1, $s0, $zero
    /* 5DC64 8006D464 02000106 */  bgez       $s0, .L8006D470
    /* 5DC68 8006D468 380A3226 */   addiu     $s2, $s1, 0xA38
    /* 5DC6C 8006D46C FF0F0326 */  addiu      $v1, $s0, 0xFFF
  .L8006D470:
    /* 5DC70 8006D470 031B0300 */  sra        $v1, $v1, 12
    /* 5DC74 8006D474 001B0300 */  sll        $v1, $v1, 12
    /* 5DC78 8006D478 23180302 */  subu       $v1, $s0, $v1
    /* 5DC7C 8006D47C 40100300 */  sll        $v0, $v1, 1
    /* 5DC80 8006D480 21104300 */  addu       $v0, $v0, $v1
    /* 5DC84 8006D484 40110200 */  sll        $v0, $v0, 5
    /* 5DC88 8006D488 02004104 */  bgez       $v0, .L8006D494
    /* 5DC8C 8006D48C 00000000 */   nop
    /* 5DC90 8006D490 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006D494:
    /* 5DC94 8006D494 03130200 */  sra        $v0, $v0, 12
    /* 5DC98 8006D498 6439020C */  jal        func_8008E590
    /* 5DC9C 8006D49C 380A22A6 */   sh        $v0, 0xA38($s1)
    /* 5DCA0 8006D4A0 6439020C */  jal        func_8008E590
    /* 5DCA4 8006D4A4 21804000 */   addu      $s0, $v0, $zero
    /* 5DCA8 8006D4A8 23800202 */  subu       $s0, $s0, $v0
    /* 5DCAC 8006D4AC 02000106 */  bgez       $s0, .L8006D4B8
    /* 5DCB0 8006D4B0 21180002 */   addu      $v1, $s0, $zero
    /* 5DCB4 8006D4B4 FF0F0326 */  addiu      $v1, $s0, 0xFFF
  .L8006D4B8:
    /* 5DCB8 8006D4B8 031B0300 */  sra        $v1, $v1, 12
    /* 5DCBC 8006D4BC 001B0300 */  sll        $v1, $v1, 12
    /* 5DCC0 8006D4C0 23180302 */  subu       $v1, $s0, $v1
    /* 5DCC4 8006D4C4 40100300 */  sll        $v0, $v1, 1
    /* 5DCC8 8006D4C8 21104300 */  addu       $v0, $v0, $v1
    /* 5DCCC 8006D4CC C0100200 */  sll        $v0, $v0, 3
    /* 5DCD0 8006D4D0 02004104 */  bgez       $v0, .L8006D4DC
    /* 5DCD4 8006D4D4 00000000 */   nop
    /* 5DCD8 8006D4D8 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006D4DC:
    /* 5DCDC 8006D4DC 03130200 */  sra        $v0, $v0, 12
    /* 5DCE0 8006D4E0 6439020C */  jal        func_8008E590
    /* 5DCE4 8006D4E4 020042A6 */   sh        $v0, 0x2($s2)
    /* 5DCE8 8006D4E8 6439020C */  jal        func_8008E590
    /* 5DCEC 8006D4EC 21804000 */   addu      $s0, $v0, $zero
    /* 5DCF0 8006D4F0 23800202 */  subu       $s0, $s0, $v0
    /* 5DCF4 8006D4F4 02000106 */  bgez       $s0, .L8006D500
    /* 5DCF8 8006D4F8 21180002 */   addu      $v1, $s0, $zero
    /* 5DCFC 8006D4FC FF0F0326 */  addiu      $v1, $s0, 0xFFF
  .L8006D500:
    /* 5DD00 8006D500 031B0300 */  sra        $v1, $v1, 12
    /* 5DD04 8006D504 001B0300 */  sll        $v1, $v1, 12
    /* 5DD08 8006D508 23180302 */  subu       $v1, $s0, $v1
    /* 5DD0C 8006D50C 40100300 */  sll        $v0, $v1, 1
    /* 5DD10 8006D510 21104300 */  addu       $v0, $v0, $v1
    /* 5DD14 8006D514 40110200 */  sll        $v0, $v0, 5
    /* 5DD18 8006D518 02004104 */  bgez       $v0, .L8006D524
    /* 5DD1C 8006D51C 00000000 */   nop
    /* 5DD20 8006D520 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006D524:
    /* 5DD24 8006D524 03130200 */  sra        $v0, $v0, 12
    /* 5DD28 8006D528 6439020C */  jal        func_8008E590
    /* 5DD2C 8006D52C 040042A6 */   sh        $v0, 0x4($s2)
    /* 5DD30 8006D530 21184000 */  addu       $v1, $v0, $zero
    /* 5DD34 8006D534 03006104 */  bgez       $v1, .L8006D544
    /* 5DD38 8006D538 83100200 */   sra       $v0, $v0, 2
    /* 5DD3C 8006D53C 03006224 */  addiu      $v0, $v1, 0x3
    /* 5DD40 8006D540 83100200 */  sra        $v0, $v0, 2
  .L8006D544:
    /* 5DD44 8006D544 80100200 */  sll        $v0, $v0, 2
    /* 5DD48 8006D548 23106200 */  subu       $v0, $v1, $v0
    /* 5DD4C 8006D54C 000D82A6 */  sh         $v0, 0xD00($s4)
    /* 5DD50 8006D550 02009426 */  addiu      $s4, $s4, 0x2
    /* 5DD54 8006D554 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5DD58 8006D558 4000A22A */  slti       $v0, $s5, 0x40
    /* 5DD5C 8006D55C B8FF4014 */  bnez       $v0, .L8006D440
    /* 5DD60 8006D560 08003126 */   addiu     $s1, $s1, 0x8
    /* 5DD64 8006D564 9000A527 */  addiu      $a1, $sp, 0x90
    /* 5DD68 8006D568 D800A48F */  lw         $a0, 0xD8($sp)
    /* 5DD6C 8006D56C 80000224 */  addiu      $v0, $zero, 0x80
    /* 5DD70 8006D570 220E62A2 */  sb         $v0, 0xE22($s3)
    /* 5DD74 8006D574 40000224 */  addiu      $v0, $zero, 0x40
    /* 5DD78 8006D578 230E62A2 */  sb         $v0, 0xE23($s3)
    /* 5DD7C 8006D57C 79000224 */  addiu      $v0, $zero, 0x79
    /* 5DD80 8006D580 EC63010C */  jal        func_80058FB0
    /* 5DD84 8006D584 240E62A2 */   sb        $v0, 0xE24($s3)
    /* 5DD88 8006D588 21200000 */  addu       $a0, $zero, $zero
    /* 5DD8C 8006D58C 9000A297 */  lhu        $v0, 0x90($sp)
    /* 5DD90 8006D590 FF000524 */  addiu      $a1, $zero, 0xFF
    /* 5DD94 8006D594 9200A0A7 */  sh         $zero, 0x92($sp)
    /* 5DD98 8006D598 380C62A6 */  sh         $v0, 0xC38($s3)
    /* 5DD9C 8006D59C 9200A297 */  lhu        $v0, 0x92($sp)
    /* 5DDA0 8006D5A0 21308000 */  addu       $a2, $a0, $zero
    /* 5DDA4 8006D5A4 3A0C62A6 */  sh         $v0, 0xC3A($s3)
    /* 5DDA8 8006D5A8 9400A397 */  lhu        $v1, 0x94($sp)
    /* 5DDAC 8006D5AC 01000224 */  addiu      $v0, $zero, 0x1
    /* 5DDB0 8006D5B0 820D60A6 */  sh         $zero, 0xD82($s3)
    /* 5DDB4 8006D5B4 840D60A6 */  sh         $zero, 0xD84($s3)
    /* 5DDB8 8006D5B8 040060AE */  sw         $zero, 0x4($s3)
    /* 5DDBC 8006D5BC 860D62A6 */  sh         $v0, 0xD86($s3)
    /* 5DDC0 8006D5C0 880D60A2 */  sb         $zero, 0xD88($s3)
    /* 5DDC4 8006D5C4 9621010C */  jal        func_80048658
    /* 5DDC8 8006D5C8 3C0C63A6 */   sh        $v1, 0xC3C($s3)
    /* 5DDCC 8006D5CC 61BC0108 */  j          .L8006F184
    /* 5DDD0 8006D5D0 21100000 */   addu      $v0, $zero, $zero
  .L8006D5D4:
    /* 5DDD4 8006D5D4 C463010C */  jal        func_80058F10
    /* 5DDD8 8006D5D8 00000000 */   nop
    /* 5DDDC 8006D5DC 8763010C */  jal        func_80058E1C
    /* 5DDE0 8006D5E0 DC00A2AF */   sw        $v0, 0xDC($sp)
    /* 5DDE4 8006D5E4 BB66010C */  jal        func_80059AEC
    /* 5DDE8 8006D5E8 01000424 */   addiu     $a0, $zero, 0x1
    /* 5DDEC 8006D5EC 741C020C */  jal        func_800871D0
    /* 5DDF0 8006D5F0 00000000 */   nop
    /* 5DDF4 8006D5F4 8864010C */  jal        func_80059220
    /* 5DDF8 8006D5F8 00000000 */   nop
    /* 5DDFC 8006D5FC D800A48F */  lw         $a0, 0xD8($sp)
    /* 5DE00 8006D600 00004E8C */  lw         $t6, 0x0($v0)
    /* 5DE04 8006D604 04004F8C */  lw         $t7, 0x4($v0)
    /* 5DE08 8006D608 0800588C */  lw         $t8, 0x8($v0)
    /* 5DE0C 8006D60C 0C00598C */  lw         $t9, 0xC($v0)
    /* 5DE10 8006D610 2800AEAF */  sw         $t6, 0x28($sp)
    /* 5DE14 8006D614 2C00AFAF */  sw         $t7, 0x2C($sp)
    /* 5DE18 8006D618 3000B8AF */  sw         $t8, 0x30($sp)
    /* 5DE1C 8006D61C 3400B9AF */  sw         $t9, 0x34($sp)
    /* 5DE20 8006D620 10004E8C */  lw         $t6, 0x10($v0)
    /* 5DE24 8006D624 14004F8C */  lw         $t7, 0x14($v0)
    /* 5DE28 8006D628 1800588C */  lw         $t8, 0x18($v0)
    /* 5DE2C 8006D62C 1C00598C */  lw         $t9, 0x1C($v0)
    /* 5DE30 8006D630 3800AEAF */  sw         $t6, 0x38($sp)
    /* 5DE34 8006D634 3C00AFAF */  sw         $t7, 0x3C($sp)
    /* 5DE38 8006D638 4000B8AF */  sw         $t8, 0x40($sp)
    /* 5DE3C 8006D63C 4400B9AF */  sw         $t9, 0x44($sp)
    /* 5DE40 8006D640 EC63010C */  jal        func_80058FB0
    /* 5DE44 8006D644 21288002 */   addu      $a1, $s4, $zero
    /* 5DE48 8006D648 9800A297 */  lhu        $v0, 0x98($sp)
    /* 5DE4C 8006D64C 9A00A0A7 */  sh         $zero, 0x9A($sp)
    /* 5DE50 8006D650 380C62A6 */  sh         $v0, 0xC38($s3)
    /* 5DE54 8006D654 9A00A297 */  lhu        $v0, 0x9A($sp)
    /* 5DE58 8006D658 00000000 */  nop
    /* 5DE5C 8006D65C 3A0C62A6 */  sh         $v0, 0xC3A($s3)
    /* 5DE60 8006D660 9C00A297 */  lhu        $v0, 0x9C($sp)
    /* 5DE64 8006D664 00000000 */  nop
    /* 5DE68 8006D668 3C0C62A6 */  sh         $v0, 0xC3C($s3)
    /* 5DE6C 8006D66C 820D6296 */  lhu        $v0, 0xD82($s3)
    /* 5DE70 8006D670 00000000 */  nop
    /* 5DE74 8006D674 09004014 */  bnez       $v0, .L8006D69C
    /* 5DE78 8006D678 2800B127 */   addiu     $s1, $sp, 0x28
    /* 5DE7C 8006D67C 9000A0A7 */  sh         $zero, 0x90($sp)
    /* 5DE80 8006D680 0400638E */  lw         $v1, 0x4($s3)
    /* 5DE84 8006D684 9400A0A7 */  sh         $zero, 0x94($sp)
    /* 5DE88 8006D688 80100300 */  sll        $v0, $v1, 2
    /* 5DE8C 8006D68C 21104300 */  addu       $v0, $v0, $v1
    /* 5DE90 8006D690 40110200 */  sll        $v0, $v0, 5
    /* 5DE94 8006D694 FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* 5DE98 8006D698 9200A2A7 */  sh         $v0, 0x92($sp)
  .L8006D69C:
    /* 5DE9C 8006D69C 7415020C */  jal        func_800855D0
    /* 5DEA0 8006D6A0 21202002 */   addu      $a0, $s1, $zero
    /* 5DEA4 8006D6A4 380C6426 */  addiu      $a0, $s3, 0xC38
    /* 5DEA8 8006D6A8 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 5DEAC 8006D6AC 5C1E020C */  jal        func_80087970
    /* 5DEB0 8006D6B0 D000A627 */   addiu     $a2, $sp, 0xD0
    /* 5DEB4 8006D6B4 2120A002 */  addu       $a0, $s5, $zero
    /* 5DEB8 8006D6B8 4800B027 */  addiu      $s0, $sp, 0x48
    /* 5DEBC 8006D6BC 4C1F020C */  jal        func_80087D30
    /* 5DEC0 8006D6C0 21280002 */   addu      $a1, $s0, $zero
    /* 5DEC4 8006D6C4 21202002 */  addu       $a0, $s1, $zero
    /* 5DEC8 8006D6C8 201D020C */  jal        func_80087480
    /* 5DECC 8006D6CC 21280002 */   addu      $a1, $s0, $zero
    /* 5DED0 8006D6D0 21200002 */  addu       $a0, $s0, $zero
    /* 5DED4 8006D6D4 9C1D020C */  jal        func_80087670
    /* 5DED8 8006D6D8 2128C002 */   addu      $a1, $s6, $zero
    /* 5DEDC 8006D6DC 7415020C */  jal        func_800855D0
    /* 5DEE0 8006D6E0 21200002 */   addu      $a0, $s0, $zero
    /* 5DEE4 8006D6E4 09000224 */  addiu      $v0, $zero, 0x9
    /* 5DEE8 8006D6E8 030042A2 */  sb         $v0, 0x3($s2)
    /* 5DEEC 8006D6EC 2C000224 */  addiu      $v0, $zero, 0x2C
    /* 5DEF0 8006D6F0 070042A2 */  sb         $v0, 0x7($s2)
    /* 5DEF4 8006D6F4 8A0D6296 */  lhu        $v0, 0xD8A($s3)
    /* 5DEF8 8006D6F8 00000000 */  nop
    /* 5DEFC 8006D6FC 160042A6 */  sh         $v0, 0x16($s2)
    /* 5DF00 8006D700 8C0D6396 */  lhu        $v1, 0xD8C($s3)
    /* 5DF04 8006D704 3F000224 */  addiu      $v0, $zero, 0x3F
    /* 5DF08 8006D708 0C0040A2 */  sb         $zero, 0xC($s2)
    /* 5DF0C 8006D70C 0D0040A2 */  sb         $zero, 0xD($s2)
    /* 5DF10 8006D710 140042A2 */  sb         $v0, 0x14($s2)
    /* 5DF14 8006D714 150040A2 */  sb         $zero, 0x15($s2)
    /* 5DF18 8006D718 1C0040A2 */  sb         $zero, 0x1C($s2)
    /* 5DF1C 8006D71C 1D0042A2 */  sb         $v0, 0x1D($s2)
    /* 5DF20 8006D720 240042A2 */  sb         $v0, 0x24($s2)
    /* 5DF24 8006D724 250042A2 */  sb         $v0, 0x25($s2)
    /* 5DF28 8006D728 0E0043A6 */  sh         $v1, 0xE($s2)
    /* 5DF2C 8006D72C 820D6296 */  lhu        $v0, 0xD82($s3)
    /* 5DF30 8006D730 00000000 */  nop
    /* 5DF34 8006D734 70014014 */  bnez       $v0, .L8006DCF8
    /* 5DF38 8006D738 00000000 */   nop
    /* 5DF3C 8006D73C 21A80000 */  addu       $s5, $zero, $zero
    /* 5DF40 8006D740 21B06002 */  addu       $s6, $s3, $zero
    /* 5DF44 8006D744 21686002 */  addu       $t5, $s3, $zero
  .L8006D748:
    /* 5DF48 8006D748 920DC292 */  lbu        $v0, 0xD92($s6)
    /* 5DF4C 8006D74C 00000000 */  nop
    /* 5DF50 8006D750 09004014 */  bnez       $v0, .L8006D778
    /* 5DF54 8006D754 01000E24 */   addiu     $t6, $zero, 0x1
    /* 5DF58 8006D758 930DC292 */  lbu        $v0, 0xD93($s6)
    /* 5DF5C 8006D75C 00000000 */  nop
    /* 5DF60 8006D760 05004014 */  bnez       $v0, .L8006D778
    /* 5DF64 8006D764 00000000 */   nop
    /* 5DF68 8006D768 940DC292 */  lbu        $v0, 0xD94($s6)
    /* 5DF6C 8006D76C 00000000 */  nop
    /* 5DF70 8006D770 58014010 */  beqz       $v0, .L8006DCD4
    /* 5DF74 8006D774 00000000 */   nop
  .L8006D778:
    /* 5DF78 8006D778 E000AEA7 */  sh         $t6, 0xE0($sp)
    /* 5DF7C 8006D77C 920DC292 */  lbu        $v0, 0xD92($s6)
    /* 5DF80 8006D780 21580000 */  addu       $t3, $zero, $zero
    /* 5DF84 8006D784 040042A2 */  sb         $v0, 0x4($s2)
    /* 5DF88 8006D788 930DC292 */  lbu        $v0, 0xD93($s6)
    /* 5DF8C 8006D78C 2160A001 */  addu       $t4, $t5, $zero
    /* 5DF90 8006D790 050042A2 */  sb         $v0, 0x5($s2)
    /* 5DF94 8006D794 940DC292 */  lbu        $v0, 0xD94($s6)
    /* 5DF98 8006D798 0800B425 */  addiu      $s4, $t5, 0x8
    /* 5DF9C 8006D79C 060042A2 */  sb         $v0, 0x6($s2)
  .L8006D7A0:
    /* 5DFA0 8006D7A0 21800000 */  addu       $s0, $zero, $zero
    /* 5DFA4 8006D7A4 E000AF97 */  lhu        $t7, 0xE0($sp)
    /* 5DFA8 8006D7A8 FEFF6925 */  addiu      $t1, $t3, -0x2
    /* 5DFAC 8006D7AC 00140F00 */  sll        $v0, $t7, 16
    /* 5DFB0 8006D7B0 03140200 */  sra        $v0, $v0, 16
    /* 5DFB4 8006D7B4 23100200 */  negu       $v0, $v0
    /* 5DFB8 8006D7B8 E000A2A7 */  sh         $v0, 0xE0($sp)
    /* 5DFBC 8006D7BC 00140200 */  sll        $v0, $v0, 16
    /* 5DFC0 8006D7C0 03540200 */  sra        $t2, $v0, 16
  .L8006D7C4:
    /* 5DFC4 8006D7C4 21880000 */  addu       $s1, $zero, $zero
    /* 5DFC8 8006D7C8 FFFF1E24 */  addiu      $fp, $zero, -0x1
    /* 5DFCC 8006D7CC 01001724 */  addiu      $s7, $zero, 0x1
  .L8006D7D0:
    /* 5DFD0 8006D7D0 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5DFD4 8006D7D4 00000000 */  nop
    /* 5DFD8 8006D7D8 82100200 */  srl        $v0, $v0, 2
    /* 5DFDC 8006D7DC 23100200 */  negu       $v0, $v0
    /* 5DFE0 8006D7E0 18004201 */  mult       $t2, $v0
    /* 5DFE4 8006D7E4 12700000 */  mflo       $t6
    /* 5DFE8 8006D7E8 01000226 */  addiu      $v0, $s0, 0x1
    /* 5DFEC 8006D7EC 00000000 */  nop
    /* 5DFF0 8006D7F0 1800C201 */  mult       $t6, $v0
    /* 5DFF4 8006D7F4 B200A0A7 */  sh         $zero, 0xB2($sp)
    /* 5DFF8 8006D7F8 12780000 */  mflo       $t7
    /* 5DFFC 8006D7FC B000AFA7 */  sh         $t7, 0xB0($sp)
    /* 5E000 8006D800 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E004 8006D804 00000000 */  nop
    /* 5E008 8006D808 82100200 */  srl        $v0, $v0, 2
    /* 5E00C 8006D80C 03002105 */  bgez       $t1, .L8006D81C
    /* 5E010 8006D810 23100200 */   negu      $v0, $v0
    /* 5E014 8006D814 08B60108 */  j          .L8006D820
    /* 5E018 8006D818 18005E00 */   mult      $v0, $fp
  .L8006D81C:
    /* 5E01C 8006D81C 18005700 */  mult       $v0, $s7
  .L8006D820:
    /* 5E020 8006D820 12700000 */  mflo       $t6
    /* 5E024 8006D824 B400AEA7 */  sh         $t6, 0xB4($sp)
    /* 5E028 8006D828 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E02C 8006D82C 00000000 */  nop
    /* 5E030 8006D830 82100200 */  srl        $v0, $v0, 2
    /* 5E034 8006D834 23100200 */  negu       $v0, $v0
    /* 5E038 8006D838 18004201 */  mult       $t2, $v0
    /* 5E03C 8006D83C 12700000 */  mflo       $t6
    /* 5E040 8006D840 00000000 */  nop
    /* 5E044 8006D844 00000000 */  nop
    /* 5E048 8006D848 1800D001 */  mult       $t6, $s0
    /* 5E04C 8006D84C BA00A0A7 */  sh         $zero, 0xBA($sp)
    /* 5E050 8006D850 12780000 */  mflo       $t7
    /* 5E054 8006D854 B800AFA7 */  sh         $t7, 0xB8($sp)
    /* 5E058 8006D858 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E05C 8006D85C 00000000 */  nop
    /* 5E060 8006D860 82100200 */  srl        $v0, $v0, 2
    /* 5E064 8006D864 03002105 */  bgez       $t1, .L8006D874
    /* 5E068 8006D868 23100200 */   negu      $v0, $v0
    /* 5E06C 8006D86C 1EB60108 */  j          .L8006D878
    /* 5E070 8006D870 18005E00 */   mult      $v0, $fp
  .L8006D874:
    /* 5E074 8006D874 18005700 */  mult       $v0, $s7
  .L8006D878:
    /* 5E078 8006D878 12700000 */  mflo       $t6
    /* 5E07C 8006D87C BC00AEA7 */  sh         $t6, 0xBC($sp)
    /* 5E080 8006D880 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E084 8006D884 00000000 */  nop
    /* 5E088 8006D888 82100200 */  srl        $v0, $v0, 2
    /* 5E08C 8006D88C 23100200 */  negu       $v0, $v0
    /* 5E090 8006D890 18004201 */  mult       $t2, $v0
    /* 5E094 8006D894 12700000 */  mflo       $t6
    /* 5E098 8006D898 01000226 */  addiu      $v0, $s0, 0x1
    /* 5E09C 8006D89C 00000000 */  nop
    /* 5E0A0 8006D8A0 1800C201 */  mult       $t6, $v0
    /* 5E0A4 8006D8A4 C200A0A7 */  sh         $zero, 0xC2($sp)
    /* 5E0A8 8006D8A8 12780000 */  mflo       $t7
    /* 5E0AC 8006D8AC C000AFA7 */  sh         $t7, 0xC0($sp)
    /* 5E0B0 8006D8B0 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E0B4 8006D8B4 00000000 */  nop
    /* 5E0B8 8006D8B8 82100200 */  srl        $v0, $v0, 2
    /* 5E0BC 8006D8BC 04002105 */  bgez       $t1, .L8006D8D0
    /* 5E0C0 8006D8C0 23180200 */   negu      $v1, $v0
    /* 5E0C4 8006D8C4 23101100 */  negu       $v0, $s1
    /* 5E0C8 8006D8C8 35B60108 */  j          .L8006D8D4
    /* 5E0CC 8006D8CC 18006200 */   mult      $v1, $v0
  .L8006D8D0:
    /* 5E0D0 8006D8D0 18007100 */  mult       $v1, $s1
  .L8006D8D4:
    /* 5E0D4 8006D8D4 12700000 */  mflo       $t6
    /* 5E0D8 8006D8D8 C400AEA7 */  sh         $t6, 0xC4($sp)
    /* 5E0DC 8006D8DC 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E0E0 8006D8E0 00000000 */  nop
    /* 5E0E4 8006D8E4 82100200 */  srl        $v0, $v0, 2
    /* 5E0E8 8006D8E8 23100200 */  negu       $v0, $v0
    /* 5E0EC 8006D8EC 18004201 */  mult       $t2, $v0
    /* 5E0F0 8006D8F0 12700000 */  mflo       $t6
    /* 5E0F4 8006D8F4 00000000 */  nop
    /* 5E0F8 8006D8F8 00000000 */  nop
    /* 5E0FC 8006D8FC 1800D001 */  mult       $t6, $s0
    /* 5E100 8006D900 CA00A0A7 */  sh         $zero, 0xCA($sp)
    /* 5E104 8006D904 12780000 */  mflo       $t7
    /* 5E108 8006D908 C800AFA7 */  sh         $t7, 0xC8($sp)
    /* 5E10C 8006D90C 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E110 8006D910 00000000 */  nop
    /* 5E114 8006D914 82100200 */  srl        $v0, $v0, 2
    /* 5E118 8006D918 04002105 */  bgez       $t1, .L8006D92C
    /* 5E11C 8006D91C 23180200 */   negu      $v1, $v0
    /* 5E120 8006D920 23101100 */  negu       $v0, $s1
    /* 5E124 8006D924 4CB60108 */  j          .L8006D930
    /* 5E128 8006D928 18006200 */   mult      $v1, $v0
  .L8006D92C:
    /* 5E12C 8006D92C 18007100 */  mult       $v1, $s1
  .L8006D930:
    /* 5E130 8006D930 12700000 */  mflo       $t6
    /* 5E134 8006D934 CC00AEA7 */  sh         $t6, 0xCC($sp)
    /* 5E138 8006D938 B000A397 */  lhu        $v1, 0xB0($sp)
    /* 5E13C 8006D93C 08008295 */  lhu        $v0, 0x8($t4)
    /* 5E140 8006D940 00000000 */  nop
    /* 5E144 8006D944 21186200 */  addu       $v1, $v1, $v0
    /* 5E148 8006D948 B000A3A7 */  sh         $v1, 0xB0($sp)
    /* 5E14C 8006D94C B200A397 */  lhu        $v1, 0xB2($sp)
    /* 5E150 8006D950 02008296 */  lhu        $v0, 0x2($s4)
    /* 5E154 8006D954 00000000 */  nop
    /* 5E158 8006D958 21186200 */  addu       $v1, $v1, $v0
    /* 5E15C 8006D95C B200A3A7 */  sh         $v1, 0xB2($sp)
    /* 5E160 8006D960 B400A397 */  lhu        $v1, 0xB4($sp)
    /* 5E164 8006D964 04008296 */  lhu        $v0, 0x4($s4)
    /* 5E168 8006D968 00000000 */  nop
    /* 5E16C 8006D96C 21186200 */  addu       $v1, $v1, $v0
    /* 5E170 8006D970 B400A3A7 */  sh         $v1, 0xB4($sp)
    /* 5E174 8006D974 B800A397 */  lhu        $v1, 0xB8($sp)
    /* 5E178 8006D978 08008295 */  lhu        $v0, 0x8($t4)
    /* 5E17C 8006D97C 00000000 */  nop
    /* 5E180 8006D980 21186200 */  addu       $v1, $v1, $v0
    /* 5E184 8006D984 B800A3A7 */  sh         $v1, 0xB8($sp)
    /* 5E188 8006D988 BA00A397 */  lhu        $v1, 0xBA($sp)
    /* 5E18C 8006D98C 02008296 */  lhu        $v0, 0x2($s4)
    /* 5E190 8006D990 00000000 */  nop
    /* 5E194 8006D994 21186200 */  addu       $v1, $v1, $v0
    /* 5E198 8006D998 BA00A3A7 */  sh         $v1, 0xBA($sp)
    /* 5E19C 8006D99C BC00A397 */  lhu        $v1, 0xBC($sp)
    /* 5E1A0 8006D9A0 04008296 */  lhu        $v0, 0x4($s4)
    /* 5E1A4 8006D9A4 00000000 */  nop
    /* 5E1A8 8006D9A8 21186200 */  addu       $v1, $v1, $v0
    /* 5E1AC 8006D9AC BC00A3A7 */  sh         $v1, 0xBC($sp)
    /* 5E1B0 8006D9B0 C000A397 */  lhu        $v1, 0xC0($sp)
    /* 5E1B4 8006D9B4 08008295 */  lhu        $v0, 0x8($t4)
    /* 5E1B8 8006D9B8 00000000 */  nop
    /* 5E1BC 8006D9BC 21186200 */  addu       $v1, $v1, $v0
    /* 5E1C0 8006D9C0 C000A3A7 */  sh         $v1, 0xC0($sp)
    /* 5E1C4 8006D9C4 C200A397 */  lhu        $v1, 0xC2($sp)
    /* 5E1C8 8006D9C8 02008296 */  lhu        $v0, 0x2($s4)
    /* 5E1CC 8006D9CC 00000000 */  nop
    /* 5E1D0 8006D9D0 21186200 */  addu       $v1, $v1, $v0
    /* 5E1D4 8006D9D4 C400A297 */  lhu        $v0, 0xC4($sp)
    /* 5E1D8 8006D9D8 C200A3A7 */  sh         $v1, 0xC2($sp)
    /* 5E1DC 8006D9DC 04008396 */  lhu        $v1, 0x4($s4)
    /* 5E1E0 8006D9E0 B000A427 */  addiu      $a0, $sp, 0xB0
    /* 5E1E4 8006D9E4 21104300 */  addu       $v0, $v0, $v1
    /* 5E1E8 8006D9E8 C400A2A7 */  sh         $v0, 0xC4($sp)
    /* 5E1EC 8006D9EC C800A297 */  lhu        $v0, 0xC8($sp)
    /* 5E1F0 8006D9F0 08008395 */  lhu        $v1, 0x8($t4)
    /* 5E1F4 8006D9F4 B800A527 */  addiu      $a1, $sp, 0xB8
    /* 5E1F8 8006D9F8 21104300 */  addu       $v0, $v0, $v1
    /* 5E1FC 8006D9FC C800A2A7 */  sh         $v0, 0xC8($sp)
    /* 5E200 8006DA00 CA00A297 */  lhu        $v0, 0xCA($sp)
    /* 5E204 8006DA04 02008396 */  lhu        $v1, 0x2($s4)
    /* 5E208 8006DA08 C000A627 */  addiu      $a2, $sp, 0xC0
    /* 5E20C 8006DA0C 21104300 */  addu       $v0, $v0, $v1
    /* 5E210 8006DA10 CA00A2A7 */  sh         $v0, 0xCA($sp)
    /* 5E214 8006DA14 CC00A297 */  lhu        $v0, 0xCC($sp)
    /* 5E218 8006DA18 04008396 */  lhu        $v1, 0x4($s4)
    /* 5E21C 8006DA1C C800A727 */  addiu      $a3, $sp, 0xC8
    /* 5E220 8006DA20 21104300 */  addu       $v0, $v0, $v1
    /* 5E224 8006DA24 CC00A2A7 */  sh         $v0, 0xCC($sp)
    /* 5E228 8006DA28 03000224 */  addiu      $v0, $zero, 0x3
    /* 5E22C 8006DA2C 23185000 */  subu       $v1, $v0, $s0
    /* 5E230 8006DA30 00190300 */  sll        $v1, $v1, 4
    /* 5E234 8006DA34 23105100 */  subu       $v0, $v0, $s1
    /* 5E238 8006DA38 00110200 */  sll        $v0, $v0, 4
    /* 5E23C 8006DA3C 0F006824 */  addiu      $t0, $v1, 0xF
    /* 5E240 8006DA40 0D0042A2 */  sb         $v0, 0xD($s2)
    /* 5E244 8006DA44 150042A2 */  sb         $v0, 0x15($s2)
    /* 5E248 8006DA48 0F004224 */  addiu      $v0, $v0, 0xF
    /* 5E24C 8006DA4C 1D0042A2 */  sb         $v0, 0x1D($s2)
    /* 5E250 8006DA50 250042A2 */  sb         $v0, 0x25($s2)
    /* 5E254 8006DA54 08004226 */  addiu      $v0, $s2, 0x8
    /* 5E258 8006DA58 0C0043A2 */  sb         $v1, 0xC($s2)
    /* 5E25C 8006DA5C 140048A2 */  sb         $t0, 0x14($s2)
    /* 5E260 8006DA60 1C0043A2 */  sb         $v1, 0x1C($s2)
    /* 5E264 8006DA64 240048A2 */  sb         $t0, 0x24($s2)
    /* 5E268 8006DA68 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5E26C 8006DA6C 10004226 */  addiu      $v0, $s2, 0x10
    /* 5E270 8006DA70 1400A2AF */  sw         $v0, 0x14($sp)
    /* 5E274 8006DA74 18004226 */  addiu      $v0, $s2, 0x18
    /* 5E278 8006DA78 1800A2AF */  sw         $v0, 0x18($sp)
    /* 5E27C 8006DA7C 20004226 */  addiu      $v0, $s2, 0x20
    /* 5E280 8006DA80 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 5E284 8006DA84 D400A227 */  addiu      $v0, $sp, 0xD4
    /* 5E288 8006DA88 2000A2AF */  sw         $v0, 0x20($sp)
    /* 5E28C 8006DA8C D000A227 */  addiu      $v0, $sp, 0xD0
    /* 5E290 8006DA90 2400A2AF */  sw         $v0, 0x24($sp)
    /* 5E294 8006DA94 E800A9AF */  sw         $t1, 0xE8($sp)
    /* 5E298 8006DA98 EC00AAAF */  sw         $t2, 0xEC($sp)
    /* 5E29C 8006DA9C F000ABAF */  sw         $t3, 0xF0($sp)
    /* 5E2A0 8006DAA0 F400ACAF */  sw         $t4, 0xF4($sp)
    /* 5E2A4 8006DAA4 AC1E020C */  jal        func_80087AB0
    /* 5E2A8 8006DAA8 F800ADAF */   sw        $t5, 0xF8($sp)
    /* 5E2AC 8006DAAC 21304000 */  addu       $a2, $v0, $zero
    /* 5E2B0 8006DAB0 E800A98F */  lw         $t1, 0xE8($sp)
    /* 5E2B4 8006DAB4 EC00AA8F */  lw         $t2, 0xEC($sp)
    /* 5E2B8 8006DAB8 F000AB8F */  lw         $t3, 0xF0($sp)
    /* 5E2BC 8006DABC F400AC8F */  lw         $t4, 0xF4($sp)
    /* 5E2C0 8006DAC0 F800AD8F */  lw         $t5, 0xF8($sp)
    /* 5E2C4 8006DAC4 0E00C004 */  bltz       $a2, .L8006DB00
    /* 5E2C8 8006DAC8 00000000 */   nop
    /* 5E2CC 8006DACC D000A28F */  lw         $v0, 0xD0($sp)
    /* 5E2D0 8006DAD0 00000000 */  nop
    /* 5E2D4 8006DAD4 0A004004 */  bltz       $v0, .L8006DB00
    /* 5E2D8 8006DAD8 21204002 */   addu      $a0, $s2, $zero
    /* 5E2DC 8006DADC DC00A58F */  lw         $a1, 0xDC($sp)
    /* 5E2E0 8006DAE0 FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 5E2E4 8006DAE4 986C010C */  jal        func_8005B260
    /* 5E2E8 8006DAE8 01000724 */   addiu     $a3, $zero, 0x1
    /* 5E2EC 8006DAEC F800AD8F */  lw         $t5, 0xF8($sp)
    /* 5E2F0 8006DAF0 F400AC8F */  lw         $t4, 0xF4($sp)
    /* 5E2F4 8006DAF4 F000AB8F */  lw         $t3, 0xF0($sp)
    /* 5E2F8 8006DAF8 EC00AA8F */  lw         $t2, 0xEC($sp)
    /* 5E2FC 8006DAFC E800A98F */  lw         $t1, 0xE8($sp)
  .L8006DB00:
    /* 5E300 8006DB00 FFFFDE27 */  addiu      $fp, $fp, -0x1
    /* 5E304 8006DB04 01003126 */  addiu      $s1, $s1, 0x1
    /* 5E308 8006DB08 0400222A */  slti       $v0, $s1, 0x4
    /* 5E30C 8006DB0C 30FF4014 */  bnez       $v0, .L8006D7D0
    /* 5E310 8006DB10 0100F726 */   addiu     $s7, $s7, 0x1
    /* 5E314 8006DB14 01001026 */  addiu      $s0, $s0, 0x1
    /* 5E318 8006DB18 0400022A */  slti       $v0, $s0, 0x4
    /* 5E31C 8006DB1C 29FF4014 */  bnez       $v0, .L8006D7C4
    /* 5E320 8006DB20 00000000 */   nop
    /* 5E324 8006DB24 01006B25 */  addiu      $t3, $t3, 0x1
    /* 5E328 8006DB28 04006229 */  slti       $v0, $t3, 0x4
    /* 5E32C 8006DB2C 1CFF4014 */  bnez       $v0, .L8006D7A0
    /* 5E330 8006DB30 00000000 */   nop
    /* 5E334 8006DB34 0800A285 */  lh         $v0, 0x8($t5)
    /* 5E338 8006DB38 00000000 */  nop
    /* 5E33C 8006DB3C 02004104 */  bgez       $v0, .L8006DB48
    /* 5E340 8006DB40 00000000 */   nop
    /* 5E344 8006DB44 23100200 */  negu       $v0, $v0
  .L8006DB48:
    /* 5E348 8006DB48 21004228 */  slti       $v0, $v0, 0x21
    /* 5E34C 8006DB4C 11004010 */  beqz       $v0, .L8006DB94
    /* 5E350 8006DB50 0800A425 */   addiu     $a0, $t5, 0x8
    /* 5E354 8006DB54 0A00A285 */  lh         $v0, 0xA($t5)
    /* 5E358 8006DB58 00000000 */  nop
    /* 5E35C 8006DB5C 02004104 */  bgez       $v0, .L8006DB68
    /* 5E360 8006DB60 00000000 */   nop
    /* 5E364 8006DB64 23100200 */  negu       $v0, $v0
  .L8006DB68:
    /* 5E368 8006DB68 21004228 */  slti       $v0, $v0, 0x21
    /* 5E36C 8006DB6C 09004010 */  beqz       $v0, .L8006DB94
    /* 5E370 8006DB70 00000000 */   nop
    /* 5E374 8006DB74 0C00A285 */  lh         $v0, 0xC($t5)
    /* 5E378 8006DB78 00000000 */  nop
    /* 5E37C 8006DB7C 02004104 */  bgez       $v0, .L8006DB88
    /* 5E380 8006DB80 00000000 */   nop
    /* 5E384 8006DB84 23100200 */  negu       $v0, $v0
  .L8006DB88:
    /* 5E388 8006DB88 21004228 */  slti       $v0, $v0, 0x21
    /* 5E38C 8006DB8C 11004014 */  bnez       $v0, .L8006DBD4
    /* 5E390 8006DB90 00000000 */   nop
  .L8006DB94:
    /* 5E394 8006DB94 0800A295 */  lhu        $v0, 0x8($t5)
    /* 5E398 8006DB98 2000A395 */  lhu        $v1, 0x20($t5)
    /* 5E39C 8006DB9C 2000A525 */  addiu      $a1, $t5, 0x20
    /* 5E3A0 8006DBA0 21104300 */  addu       $v0, $v0, $v1
    /* 5E3A4 8006DBA4 0800A2A5 */  sh         $v0, 0x8($t5)
    /* 5E3A8 8006DBA8 02008294 */  lhu        $v0, 0x2($a0)
    /* 5E3AC 8006DBAC 0200A394 */  lhu        $v1, 0x2($a1)
    /* 5E3B0 8006DBB0 00000000 */  nop
    /* 5E3B4 8006DBB4 21104300 */  addu       $v0, $v0, $v1
    /* 5E3B8 8006DBB8 020082A4 */  sh         $v0, 0x2($a0)
    /* 5E3BC 8006DBBC 04008294 */  lhu        $v0, 0x4($a0)
    /* 5E3C0 8006DBC0 0400A394 */  lhu        $v1, 0x4($a1)
    /* 5E3C4 8006DBC4 00000000 */  nop
    /* 5E3C8 8006DBC8 21104300 */  addu       $v0, $v0, $v1
    /* 5E3CC 8006DBCC FFB60108 */  j          .L8006DBFC
    /* 5E3D0 8006DBD0 040082A4 */   sh        $v0, 0x4($a0)
  .L8006DBD4:
    /* 5E3D4 8006DBD4 820D6296 */  lhu        $v0, 0xD82($s3)
    /* 5E3D8 8006DBD8 00000000 */  nop
    /* 5E3DC 8006DBDC 04004014 */  bnez       $v0, .L8006DBF0
    /* 5E3E0 8006DBE0 0800A225 */   addiu     $v0, $t5, 0x8
    /* 5E3E4 8006DBE4 01000224 */  addiu      $v0, $zero, 0x1
    /* 5E3E8 8006DBE8 820D62A6 */  sh         $v0, 0xD82($s3)
    /* 5E3EC 8006DBEC 0800A225 */  addiu      $v0, $t5, 0x8
  .L8006DBF0:
    /* 5E3F0 8006DBF0 0800A0A5 */  sh         $zero, 0x8($t5)
    /* 5E3F4 8006DBF4 020040A4 */  sh         $zero, 0x2($v0)
    /* 5E3F8 8006DBF8 040040A4 */  sh         $zero, 0x4($v0)
  .L8006DBFC:
    /* 5E3FC 8006DBFC 820D6296 */  lhu        $v0, 0xD82($s3)
    /* 5E400 8006DC00 00000000 */  nop
    /* 5E404 8006DC04 29004014 */  bnez       $v0, .L8006DCAC
    /* 5E408 8006DC08 80000324 */   addiu     $v1, $zero, 0x80
    /* 5E40C 8006DC0C 0000628E */  lw         $v0, 0x0($s3)
    /* 5E410 8006DC10 00000000 */  nop
    /* 5E414 8006DC14 21105500 */  addu       $v0, $v0, $s5
    /* 5E418 8006DC18 00004290 */  lbu        $v0, 0x0($v0)
    /* 5E41C 8006DC1C 920DC392 */  lbu        $v1, 0xD92($s6)
    /* 5E420 8006DC20 42200200 */  srl        $a0, $v0, 1
    /* 5E424 8006DC24 F7FF8224 */  addiu      $v0, $a0, -0x9
    /* 5E428 8006DC28 2A106200 */  slt        $v0, $v1, $v0
    /* 5E42C 8006DC2C 03004010 */  beqz       $v0, .L8006DC3C
    /* 5E430 8006DC30 08006224 */   addiu     $v0, $v1, 0x8
    /* 5E434 8006DC34 10B70108 */  j          .L8006DC40
    /* 5E438 8006DC38 920DC2A2 */   sb        $v0, 0xD92($s6)
  .L8006DC3C:
    /* 5E43C 8006DC3C 920DC4A2 */  sb         $a0, 0xD92($s6)
  .L8006DC40:
    /* 5E440 8006DC40 0000628E */  lw         $v0, 0x0($s3)
    /* 5E444 8006DC44 00000000 */  nop
    /* 5E448 8006DC48 21105500 */  addu       $v0, $v0, $s5
    /* 5E44C 8006DC4C 03004290 */  lbu        $v0, 0x3($v0)
    /* 5E450 8006DC50 930DC392 */  lbu        $v1, 0xD93($s6)
    /* 5E454 8006DC54 42200200 */  srl        $a0, $v0, 1
    /* 5E458 8006DC58 F7FF8224 */  addiu      $v0, $a0, -0x9
    /* 5E45C 8006DC5C 2A106200 */  slt        $v0, $v1, $v0
    /* 5E460 8006DC60 03004010 */  beqz       $v0, .L8006DC70
    /* 5E464 8006DC64 08006224 */   addiu     $v0, $v1, 0x8
    /* 5E468 8006DC68 1DB70108 */  j          .L8006DC74
    /* 5E46C 8006DC6C 930DC2A2 */   sb        $v0, 0xD93($s6)
  .L8006DC70:
    /* 5E470 8006DC70 930DC4A2 */  sb         $a0, 0xD93($s6)
  .L8006DC74:
    /* 5E474 8006DC74 0000628E */  lw         $v0, 0x0($s3)
    /* 5E478 8006DC78 00000000 */  nop
    /* 5E47C 8006DC7C 21105500 */  addu       $v0, $v0, $s5
    /* 5E480 8006DC80 06004290 */  lbu        $v0, 0x6($v0)
    /* 5E484 8006DC84 940DC392 */  lbu        $v1, 0xD94($s6)
    /* 5E488 8006DC88 42200200 */  srl        $a0, $v0, 1
    /* 5E48C 8006DC8C F7FF8224 */  addiu      $v0, $a0, -0x9
    /* 5E490 8006DC90 2A106200 */  slt        $v0, $v1, $v0
    /* 5E494 8006DC94 03004010 */  beqz       $v0, .L8006DCA4
    /* 5E498 8006DC98 08006224 */   addiu     $v0, $v1, 0x8
    /* 5E49C 8006DC9C 35B70108 */  j          .L8006DCD4
    /* 5E4A0 8006DCA0 940DC2A2 */   sb        $v0, 0xD94($s6)
  .L8006DCA4:
    /* 5E4A4 8006DCA4 35B70108 */  j          .L8006DCD4
    /* 5E4A8 8006DCA8 940DC4A2 */   sb        $a0, 0xD94($s6)
  .L8006DCAC:
    /* 5E4AC 8006DCAC 20000224 */  addiu      $v0, $zero, 0x20
    /* 5E4B0 8006DCB0 920D63A2 */  sb         $v1, 0xD92($s3)
    /* 5E4B4 8006DCB4 930D62A2 */  sb         $v0, 0xD93($s3)
    /* 5E4B8 8006DCB8 940D62A2 */  sb         $v0, 0xD94($s3)
    /* 5E4BC 8006DCBC 960D62A2 */  sb         $v0, 0xD96($s3)
    /* 5E4C0 8006DCC0 970D63A2 */  sb         $v1, 0xD97($s3)
    /* 5E4C4 8006DCC4 980D62A2 */  sb         $v0, 0xD98($s3)
    /* 5E4C8 8006DCC8 9A0D62A2 */  sb         $v0, 0xD9A($s3)
    /* 5E4CC 8006DCCC 9B0D62A2 */  sb         $v0, 0xD9B($s3)
    /* 5E4D0 8006DCD0 9C0D63A2 */  sb         $v1, 0xD9C($s3)
  .L8006DCD4:
    /* 5E4D4 8006DCD4 0400D626 */  addiu      $s6, $s6, 0x4
    /* 5E4D8 8006DCD8 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5E4DC 8006DCDC 0300A22A */  slti       $v0, $s5, 0x3
    /* 5E4E0 8006DCE0 99FE4014 */  bnez       $v0, .L8006D748
    /* 5E4E4 8006DCE4 0800AD25 */   addiu     $t5, $t5, 0x8
    /* 5E4E8 8006DCE8 820D6296 */  lhu        $v0, 0xD82($s3)
    /* 5E4EC 8006DCEC 00000000 */  nop
    /* 5E4F0 8006DCF0 2D034010 */  beqz       $v0, .L8006E9A8
    /* 5E4F4 8006DCF4 00000000 */   nop
  .L8006DCF8:
    /* 5E4F8 8006DCF8 9C0D628E */  lw         $v0, 0xD9C($s3)
    /* 5E4FC 8006DCFC FFFF033C */  lui        $v1, (0xFFFF0000 >> 16)
    /* 5E500 8006DD00 24104300 */  and        $v0, $v0, $v1
    /* 5E504 8006DD04 05004014 */  bnez       $v0, .L8006DD1C
    /* 5E508 8006DD08 00000000 */   nop
    /* 5E50C 8006DD0C A00D6292 */  lbu        $v0, 0xDA0($s3)
    /* 5E510 8006DD10 00000000 */  nop
    /* 5E514 8006DD14 1C014010 */  beqz       $v0, .L8006E188
    /* 5E518 8006DD18 00000000 */   nop
  .L8006DD1C:
    /* 5E51C 8006DD1C 9E0D6292 */  lbu        $v0, 0xD9E($s3)
    /* 5E520 8006DD20 00000000 */  nop
    /* 5E524 8006DD24 040042A2 */  sb         $v0, 0x4($s2)
    /* 5E528 8006DD28 9F0D6292 */  lbu        $v0, 0xD9F($s3)
    /* 5E52C 8006DD2C 01000F24 */  addiu      $t7, $zero, 0x1
    /* 5E530 8006DD30 E000AFA7 */  sh         $t7, 0xE0($sp)
    /* 5E534 8006DD34 050042A2 */  sb         $v0, 0x5($s2)
    /* 5E538 8006DD38 A00D6292 */  lbu        $v0, 0xDA0($s3)
    /* 5E53C 8006DD3C 21580000 */  addu       $t3, $zero, $zero
    /* 5E540 8006DD40 060042A2 */  sb         $v0, 0x6($s2)
  .L8006DD44:
    /* 5E544 8006DD44 21A80000 */  addu       $s5, $zero, $zero
    /* 5E548 8006DD48 E000B897 */  lhu        $t8, 0xE0($sp)
    /* 5E54C 8006DD4C FEFF7625 */  addiu      $s6, $t3, -0x2
    /* 5E550 8006DD50 00141800 */  sll        $v0, $t8, 16
    /* 5E554 8006DD54 03140200 */  sra        $v0, $v0, 16
    /* 5E558 8006DD58 23100200 */  negu       $v0, $v0
    /* 5E55C 8006DD5C E000A2A7 */  sh         $v0, 0xE0($sp)
    /* 5E560 8006DD60 00140200 */  sll        $v0, $v0, 16
    /* 5E564 8006DD64 03BC0200 */  sra        $s7, $v0, 16
  .L8006DD68:
    /* 5E568 8006DD68 21880000 */  addu       $s1, $zero, $zero
    /* 5E56C 8006DD6C FFFF1424 */  addiu      $s4, $zero, -0x1
    /* 5E570 8006DD70 01001024 */  addiu      $s0, $zero, 0x1
  .L8006DD74:
    /* 5E574 8006DD74 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E578 8006DD78 00000000 */  nop
    /* 5E57C 8006DD7C 82100200 */  srl        $v0, $v0, 2
    /* 5E580 8006DD80 23100200 */  negu       $v0, $v0
    /* 5E584 8006DD84 1800E202 */  mult       $s7, $v0
    /* 5E588 8006DD88 12700000 */  mflo       $t6
    /* 5E58C 8006DD8C 0100A226 */  addiu      $v0, $s5, 0x1
    /* 5E590 8006DD90 00000000 */  nop
    /* 5E594 8006DD94 1800C201 */  mult       $t6, $v0
    /* 5E598 8006DD98 B200A0A7 */  sh         $zero, 0xB2($sp)
    /* 5E59C 8006DD9C 12780000 */  mflo       $t7
    /* 5E5A0 8006DDA0 B000AFA7 */  sh         $t7, 0xB0($sp)
    /* 5E5A4 8006DDA4 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E5A8 8006DDA8 00000000 */  nop
    /* 5E5AC 8006DDAC 82100200 */  srl        $v0, $v0, 2
    /* 5E5B0 8006DDB0 0300C106 */  bgez       $s6, .L8006DDC0
    /* 5E5B4 8006DDB4 23100200 */   negu      $v0, $v0
    /* 5E5B8 8006DDB8 71B70108 */  j          .L8006DDC4
    /* 5E5BC 8006DDBC 18005400 */   mult      $v0, $s4
  .L8006DDC0:
    /* 5E5C0 8006DDC0 18005000 */  mult       $v0, $s0
  .L8006DDC4:
    /* 5E5C4 8006DDC4 12700000 */  mflo       $t6
    /* 5E5C8 8006DDC8 B400AEA7 */  sh         $t6, 0xB4($sp)
    /* 5E5CC 8006DDCC 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E5D0 8006DDD0 00000000 */  nop
    /* 5E5D4 8006DDD4 82100200 */  srl        $v0, $v0, 2
    /* 5E5D8 8006DDD8 23100200 */  negu       $v0, $v0
    /* 5E5DC 8006DDDC 1800E202 */  mult       $s7, $v0
    /* 5E5E0 8006DDE0 12700000 */  mflo       $t6
    /* 5E5E4 8006DDE4 00000000 */  nop
    /* 5E5E8 8006DDE8 00000000 */  nop
    /* 5E5EC 8006DDEC 1800D501 */  mult       $t6, $s5
    /* 5E5F0 8006DDF0 BA00A0A7 */  sh         $zero, 0xBA($sp)
    /* 5E5F4 8006DDF4 12780000 */  mflo       $t7
    /* 5E5F8 8006DDF8 B800AFA7 */  sh         $t7, 0xB8($sp)
    /* 5E5FC 8006DDFC 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E600 8006DE00 00000000 */  nop
    /* 5E604 8006DE04 82100200 */  srl        $v0, $v0, 2
    /* 5E608 8006DE08 0300C106 */  bgez       $s6, .L8006DE18
    /* 5E60C 8006DE0C 23100200 */   negu      $v0, $v0
    /* 5E610 8006DE10 87B70108 */  j          .L8006DE1C
    /* 5E614 8006DE14 18005400 */   mult      $v0, $s4
  .L8006DE18:
    /* 5E618 8006DE18 18005000 */  mult       $v0, $s0
  .L8006DE1C:
    /* 5E61C 8006DE1C 12700000 */  mflo       $t6
    /* 5E620 8006DE20 BC00AEA7 */  sh         $t6, 0xBC($sp)
    /* 5E624 8006DE24 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E628 8006DE28 00000000 */  nop
    /* 5E62C 8006DE2C 82100200 */  srl        $v0, $v0, 2
    /* 5E630 8006DE30 23100200 */  negu       $v0, $v0
    /* 5E634 8006DE34 1800E202 */  mult       $s7, $v0
    /* 5E638 8006DE38 12700000 */  mflo       $t6
    /* 5E63C 8006DE3C 0100A226 */  addiu      $v0, $s5, 0x1
    /* 5E640 8006DE40 00000000 */  nop
    /* 5E644 8006DE44 1800C201 */  mult       $t6, $v0
    /* 5E648 8006DE48 C200A0A7 */  sh         $zero, 0xC2($sp)
    /* 5E64C 8006DE4C 12780000 */  mflo       $t7
    /* 5E650 8006DE50 C000AFA7 */  sh         $t7, 0xC0($sp)
    /* 5E654 8006DE54 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E658 8006DE58 00000000 */  nop
    /* 5E65C 8006DE5C 82100200 */  srl        $v0, $v0, 2
    /* 5E660 8006DE60 0400C106 */  bgez       $s6, .L8006DE74
    /* 5E664 8006DE64 23180200 */   negu      $v1, $v0
    /* 5E668 8006DE68 23101100 */  negu       $v0, $s1
    /* 5E66C 8006DE6C 9EB70108 */  j          .L8006DE78
    /* 5E670 8006DE70 18006200 */   mult      $v1, $v0
  .L8006DE74:
    /* 5E674 8006DE74 18007100 */  mult       $v1, $s1
  .L8006DE78:
    /* 5E678 8006DE78 12700000 */  mflo       $t6
    /* 5E67C 8006DE7C C400AEA7 */  sh         $t6, 0xC4($sp)
    /* 5E680 8006DE80 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E684 8006DE84 00000000 */  nop
    /* 5E688 8006DE88 82100200 */  srl        $v0, $v0, 2
    /* 5E68C 8006DE8C 23100200 */  negu       $v0, $v0
    /* 5E690 8006DE90 1800E202 */  mult       $s7, $v0
    /* 5E694 8006DE94 12700000 */  mflo       $t6
    /* 5E698 8006DE98 00000000 */  nop
    /* 5E69C 8006DE9C 00000000 */  nop
    /* 5E6A0 8006DEA0 1800D501 */  mult       $t6, $s5
    /* 5E6A4 8006DEA4 CA00A0A7 */  sh         $zero, 0xCA($sp)
    /* 5E6A8 8006DEA8 12780000 */  mflo       $t7
    /* 5E6AC 8006DEAC C800AFA7 */  sh         $t7, 0xC8($sp)
    /* 5E6B0 8006DEB0 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E6B4 8006DEB4 00000000 */  nop
    /* 5E6B8 8006DEB8 82100200 */  srl        $v0, $v0, 2
    /* 5E6BC 8006DEBC 0400C106 */  bgez       $s6, .L8006DED0
    /* 5E6C0 8006DEC0 23180200 */   negu      $v1, $v0
    /* 5E6C4 8006DEC4 23101100 */  negu       $v0, $s1
    /* 5E6C8 8006DEC8 B5B70108 */  j          .L8006DED4
    /* 5E6CC 8006DECC 18006200 */   mult      $v1, $v0
  .L8006DED0:
    /* 5E6D0 8006DED0 18007100 */  mult       $v1, $s1
  .L8006DED4:
    /* 5E6D4 8006DED4 12700000 */  mflo       $t6
    /* 5E6D8 8006DED8 CC00AEA7 */  sh         $t6, 0xCC($sp)
    /* 5E6DC 8006DEDC B000A427 */  addiu      $a0, $sp, 0xB0
    /* 5E6E0 8006DEE0 B800A527 */  addiu      $a1, $sp, 0xB8
    /* 5E6E4 8006DEE4 C000A627 */  addiu      $a2, $sp, 0xC0
    /* 5E6E8 8006DEE8 C800A727 */  addiu      $a3, $sp, 0xC8
    /* 5E6EC 8006DEEC 03000224 */  addiu      $v0, $zero, 0x3
    /* 5E6F0 8006DEF0 23185500 */  subu       $v1, $v0, $s5
    /* 5E6F4 8006DEF4 00190300 */  sll        $v1, $v1, 4
    /* 5E6F8 8006DEF8 23105100 */  subu       $v0, $v0, $s1
    /* 5E6FC 8006DEFC 00110200 */  sll        $v0, $v0, 4
    /* 5E700 8006DF00 0F006824 */  addiu      $t0, $v1, 0xF
    /* 5E704 8006DF04 0D0042A2 */  sb         $v0, 0xD($s2)
    /* 5E708 8006DF08 150042A2 */  sb         $v0, 0x15($s2)
    /* 5E70C 8006DF0C 0F004224 */  addiu      $v0, $v0, 0xF
    /* 5E710 8006DF10 1D0042A2 */  sb         $v0, 0x1D($s2)
    /* 5E714 8006DF14 250042A2 */  sb         $v0, 0x25($s2)
    /* 5E718 8006DF18 08004226 */  addiu      $v0, $s2, 0x8
    /* 5E71C 8006DF1C 0C0043A2 */  sb         $v1, 0xC($s2)
    /* 5E720 8006DF20 140048A2 */  sb         $t0, 0x14($s2)
    /* 5E724 8006DF24 1C0043A2 */  sb         $v1, 0x1C($s2)
    /* 5E728 8006DF28 240048A2 */  sb         $t0, 0x24($s2)
    /* 5E72C 8006DF2C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5E730 8006DF30 10004226 */  addiu      $v0, $s2, 0x10
    /* 5E734 8006DF34 1400A2AF */  sw         $v0, 0x14($sp)
    /* 5E738 8006DF38 18004226 */  addiu      $v0, $s2, 0x18
    /* 5E73C 8006DF3C 1800A2AF */  sw         $v0, 0x18($sp)
    /* 5E740 8006DF40 20004226 */  addiu      $v0, $s2, 0x20
    /* 5E744 8006DF44 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 5E748 8006DF48 D400A227 */  addiu      $v0, $sp, 0xD4
    /* 5E74C 8006DF4C 2000A2AF */  sw         $v0, 0x20($sp)
    /* 5E750 8006DF50 D000A227 */  addiu      $v0, $sp, 0xD0
    /* 5E754 8006DF54 2400A2AF */  sw         $v0, 0x24($sp)
    /* 5E758 8006DF58 AC1E020C */  jal        func_80087AB0
    /* 5E75C 8006DF5C F000ABAF */   sw        $t3, 0xF0($sp)
    /* 5E760 8006DF60 21304000 */  addu       $a2, $v0, $zero
    /* 5E764 8006DF64 F000AB8F */  lw         $t3, 0xF0($sp)
    /* 5E768 8006DF68 0A00C004 */  bltz       $a2, .L8006DF94
    /* 5E76C 8006DF6C 00000000 */   nop
    /* 5E770 8006DF70 D000A28F */  lw         $v0, 0xD0($sp)
    /* 5E774 8006DF74 00000000 */  nop
    /* 5E778 8006DF78 06004004 */  bltz       $v0, .L8006DF94
    /* 5E77C 8006DF7C 21204002 */   addu      $a0, $s2, $zero
    /* 5E780 8006DF80 DC00A58F */  lw         $a1, 0xDC($sp)
    /* 5E784 8006DF84 FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 5E788 8006DF88 986C010C */  jal        func_8005B260
    /* 5E78C 8006DF8C 01000724 */   addiu     $a3, $zero, 0x1
    /* 5E790 8006DF90 F000AB8F */  lw         $t3, 0xF0($sp)
  .L8006DF94:
    /* 5E794 8006DF94 FFFF9426 */  addiu      $s4, $s4, -0x1
    /* 5E798 8006DF98 01003126 */  addiu      $s1, $s1, 0x1
    /* 5E79C 8006DF9C 0400222A */  slti       $v0, $s1, 0x4
    /* 5E7A0 8006DFA0 74FF4014 */  bnez       $v0, .L8006DD74
    /* 5E7A4 8006DFA4 01001026 */   addiu     $s0, $s0, 0x1
    /* 5E7A8 8006DFA8 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5E7AC 8006DFAC 0400A22A */  slti       $v0, $s5, 0x4
    /* 5E7B0 8006DFB0 6DFF4014 */  bnez       $v0, .L8006DD68
    /* 5E7B4 8006DFB4 00000000 */   nop
    /* 5E7B8 8006DFB8 01006B25 */  addiu      $t3, $t3, 0x1
    /* 5E7BC 8006DFBC 04006229 */  slti       $v0, $t3, 0x4
    /* 5E7C0 8006DFC0 60FF4014 */  bnez       $v0, .L8006DD44
    /* 5E7C4 8006DFC4 00000000 */   nop
    /* 5E7C8 8006DFC8 840D6296 */  lhu        $v0, 0xD84($s3)
    /* 5E7CC 8006DFCC 00000000 */  nop
    /* 5E7D0 8006DFD0 0200422C */  sltiu      $v0, $v0, 0x2
    /* 5E7D4 8006DFD4 1E004014 */  bnez       $v0, .L8006E050
    /* 5E7D8 8006DFD8 01000224 */   addiu     $v0, $zero, 0x1
    /* 5E7DC 8006DFDC 9E0D6392 */  lbu        $v1, 0xD9E($s3)
    /* 5E7E0 8006DFE0 00000000 */  nop
    /* 5E7E4 8006DFE4 0900622C */  sltiu      $v0, $v1, 0x9
    /* 5E7E8 8006DFE8 03004014 */  bnez       $v0, .L8006DFF8
    /* 5E7EC 8006DFEC F8FF6224 */   addiu     $v0, $v1, -0x8
    /* 5E7F0 8006DFF0 FFB70108 */  j          .L8006DFFC
    /* 5E7F4 8006DFF4 9E0D62A2 */   sb        $v0, 0xD9E($s3)
  .L8006DFF8:
    /* 5E7F8 8006DFF8 9E0D60A2 */  sb         $zero, 0xD9E($s3)
  .L8006DFFC:
    /* 5E7FC 8006DFFC 9F0D6392 */  lbu        $v1, 0xD9F($s3)
    /* 5E800 8006E000 00000000 */  nop
    /* 5E804 8006E004 0900622C */  sltiu      $v0, $v1, 0x9
    /* 5E808 8006E008 03004014 */  bnez       $v0, .L8006E018
    /* 5E80C 8006E00C F8FF6224 */   addiu     $v0, $v1, -0x8
    /* 5E810 8006E010 07B80108 */  j          .L8006E01C
    /* 5E814 8006E014 9F0D62A2 */   sb        $v0, 0xD9F($s3)
  .L8006E018:
    /* 5E818 8006E018 9F0D60A2 */  sb         $zero, 0xD9F($s3)
  .L8006E01C:
    /* 5E81C 8006E01C A00D6392 */  lbu        $v1, 0xDA0($s3)
    /* 5E820 8006E020 00000000 */  nop
    /* 5E824 8006E024 0900622C */  sltiu      $v0, $v1, 0x9
    /* 5E828 8006E028 03004014 */  bnez       $v0, .L8006E038
    /* 5E82C 8006E02C F8FF6224 */   addiu     $v0, $v1, -0x8
    /* 5E830 8006E030 0FB80108 */  j          .L8006E03C
    /* 5E834 8006E034 A00D62A2 */   sb        $v0, 0xDA0($s3)
  .L8006E038:
    /* 5E838 8006E038 A00D60A2 */  sb         $zero, 0xDA0($s3)
  .L8006E03C:
    /* 5E83C 8006E03C 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E840 8006E040 00000000 */  nop
    /* 5E844 8006E044 02004224 */  addiu      $v0, $v0, 0x2
    /* 5E848 8006E048 62B80108 */  j          .L8006E188
    /* 5E84C 8006E04C 800D62A6 */   sh        $v0, 0xD80($s3)
  .L8006E050:
    /* 5E850 8006E050 820D6396 */  lhu        $v1, 0xD82($s3)
    /* 5E854 8006E054 00000000 */  nop
    /* 5E858 8006E058 25006214 */  bne        $v1, $v0, .L8006E0F0
    /* 5E85C 8006E05C 02000224 */   addiu     $v0, $zero, 0x2
    /* 5E860 8006E060 9E0D6392 */  lbu        $v1, 0xD9E($s3)
    /* 5E864 8006E064 00000000 */  nop
    /* 5E868 8006E068 F600622C */  sltiu      $v0, $v1, 0xF6
    /* 5E86C 8006E06C 02004014 */  bnez       $v0, .L8006E078
    /* 5E870 8006E070 08006224 */   addiu     $v0, $v1, 0x8
    /* 5E874 8006E074 FF000224 */  addiu      $v0, $zero, 0xFF
  .L8006E078:
    /* 5E878 8006E078 9E0D62A2 */  sb         $v0, 0xD9E($s3)
    /* 5E87C 8006E07C 9F0D6392 */  lbu        $v1, 0xD9F($s3)
    /* 5E880 8006E080 00000000 */  nop
    /* 5E884 8006E084 F600622C */  sltiu      $v0, $v1, 0xF6
    /* 5E888 8006E088 02004014 */  bnez       $v0, .L8006E094
    /* 5E88C 8006E08C 08006224 */   addiu     $v0, $v1, 0x8
    /* 5E890 8006E090 FF000224 */  addiu      $v0, $zero, 0xFF
  .L8006E094:
    /* 5E894 8006E094 9F0D62A2 */  sb         $v0, 0xD9F($s3)
    /* 5E898 8006E098 A00D6392 */  lbu        $v1, 0xDA0($s3)
    /* 5E89C 8006E09C 00000000 */  nop
    /* 5E8A0 8006E0A0 F600622C */  sltiu      $v0, $v1, 0xF6
    /* 5E8A4 8006E0A4 02004014 */  bnez       $v0, .L8006E0B0
    /* 5E8A8 8006E0A8 08006224 */   addiu     $v0, $v1, 0x8
    /* 5E8AC 8006E0AC FF000224 */  addiu      $v0, $zero, 0xFF
  .L8006E0B0:
    /* 5E8B0 8006E0B0 A00D62A2 */  sb         $v0, 0xDA0($s3)
    /* 5E8B4 8006E0B4 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E8B8 8006E0B8 00000000 */  nop
    /* 5E8BC 8006E0BC 04004224 */  addiu      $v0, $v0, 0x4
    /* 5E8C0 8006E0C0 800D62A6 */  sh         $v0, 0xD80($s3)
    /* 5E8C4 8006E0C4 9C0D628E */  lw         $v0, 0xD9C($s3)
    /* 5E8C8 8006E0C8 FFFF033C */  lui        $v1, (0xFFFF0000 >> 16)
    /* 5E8CC 8006E0CC 24104300 */  and        $v0, $v0, $v1
    /* 5E8D0 8006E0D0 2D004314 */  bne        $v0, $v1, .L8006E188
    /* 5E8D4 8006E0D4 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 5E8D8 8006E0D8 A00D6392 */  lbu        $v1, 0xDA0($s3)
    /* 5E8DC 8006E0DC 00000000 */  nop
    /* 5E8E0 8006E0E0 29006214 */  bne        $v1, $v0, .L8006E188
    /* 5E8E4 8006E0E4 02000224 */   addiu     $v0, $zero, 0x2
    /* 5E8E8 8006E0E8 62B80108 */  j          .L8006E188
    /* 5E8EC 8006E0EC 820D62A6 */   sh        $v0, 0xD82($s3)
  .L8006E0F0:
    /* 5E8F0 8006E0F0 25006214 */  bne        $v1, $v0, .L8006E188
    /* 5E8F4 8006E0F4 00000000 */   nop
    /* 5E8F8 8006E0F8 9E0D6392 */  lbu        $v1, 0xD9E($s3)
    /* 5E8FC 8006E0FC 00000000 */  nop
    /* 5E900 8006E100 8900622C */  sltiu      $v0, $v1, 0x89
    /* 5E904 8006E104 02004014 */  bnez       $v0, .L8006E110
    /* 5E908 8006E108 80000224 */   addiu     $v0, $zero, 0x80
    /* 5E90C 8006E10C F8FF6224 */  addiu      $v0, $v1, -0x8
  .L8006E110:
    /* 5E910 8006E110 9E0D62A2 */  sb         $v0, 0xD9E($s3)
    /* 5E914 8006E114 9F0D6392 */  lbu        $v1, 0xD9F($s3)
    /* 5E918 8006E118 00000000 */  nop
    /* 5E91C 8006E11C 8900622C */  sltiu      $v0, $v1, 0x89
    /* 5E920 8006E120 02004014 */  bnez       $v0, .L8006E12C
    /* 5E924 8006E124 80000224 */   addiu     $v0, $zero, 0x80
    /* 5E928 8006E128 F8FF6224 */  addiu      $v0, $v1, -0x8
  .L8006E12C:
    /* 5E92C 8006E12C 9F0D62A2 */  sb         $v0, 0xD9F($s3)
    /* 5E930 8006E130 A00D6392 */  lbu        $v1, 0xDA0($s3)
    /* 5E934 8006E134 00000000 */  nop
    /* 5E938 8006E138 8900622C */  sltiu      $v0, $v1, 0x89
    /* 5E93C 8006E13C 02004014 */  bnez       $v0, .L8006E148
    /* 5E940 8006E140 80000224 */   addiu     $v0, $zero, 0x80
    /* 5E944 8006E144 F8FF6224 */  addiu      $v0, $v1, -0x8
  .L8006E148:
    /* 5E948 8006E148 A00D62A2 */  sb         $v0, 0xDA0($s3)
    /* 5E94C 8006E14C 800D6296 */  lhu        $v0, 0xD80($s3)
    /* 5E950 8006E150 00000000 */  nop
    /* 5E954 8006E154 FEFF4224 */  addiu      $v0, $v0, -0x2
    /* 5E958 8006E158 800D62A6 */  sh         $v0, 0xD80($s3)
    /* 5E95C 8006E15C 9C0D628E */  lw         $v0, 0xD9C($s3)
    /* 5E960 8006E160 FFFF033C */  lui        $v1, (0xFFFF0000 >> 16)
    /* 5E964 8006E164 24104300 */  and        $v0, $v0, $v1
    /* 5E968 8006E168 8080033C */  lui        $v1, (0x80800000 >> 16)
    /* 5E96C 8006E16C 06004314 */  bne        $v0, $v1, .L8006E188
    /* 5E970 8006E170 80000224 */   addiu     $v0, $zero, 0x80
    /* 5E974 8006E174 A00D6392 */  lbu        $v1, 0xDA0($s3)
    /* 5E978 8006E178 00000000 */  nop
    /* 5E97C 8006E17C 02006214 */  bne        $v1, $v0, .L8006E188
    /* 5E980 8006E180 01000224 */   addiu     $v0, $zero, 0x1
    /* 5E984 8006E184 820D62A6 */  sh         $v0, 0xD82($s3)
  .L8006E188:
    /* 5E988 8006E188 900D628E */  lw         $v0, 0xD90($s3)
    /* 5E98C 8006E18C FFFF033C */  lui        $v1, (0xFFFF0000 >> 16)
    /* 5E990 8006E190 24104300 */  and        $v0, $v0, $v1
    /* 5E994 8006E194 05004014 */  bnez       $v0, .L8006E1AC
    /* 5E998 8006E198 00000000 */   nop
    /* 5E99C 8006E19C 940D6292 */  lbu        $v0, 0xD94($s3)
    /* 5E9A0 8006E1A0 00000000 */  nop
    /* 5E9A4 8006E1A4 E1004010 */  beqz       $v0, .L8006E52C
    /* 5E9A8 8006E1A8 00000000 */   nop
  .L8006E1AC:
    /* 5E9AC 8006E1AC 940D628E */  lw         $v0, 0xD94($s3)
    /* 5E9B0 8006E1B0 00000000 */  nop
    /* 5E9B4 8006E1B4 24104300 */  and        $v0, $v0, $v1
    /* 5E9B8 8006E1B8 05004014 */  bnez       $v0, .L8006E1D0
    /* 5E9BC 8006E1BC 00000000 */   nop
    /* 5E9C0 8006E1C0 980D6292 */  lbu        $v0, 0xD98($s3)
    /* 5E9C4 8006E1C4 00000000 */  nop
    /* 5E9C8 8006E1C8 D8004010 */  beqz       $v0, .L8006E52C
    /* 5E9CC 8006E1CC 00000000 */   nop
  .L8006E1D0:
    /* 5E9D0 8006E1D0 980D628E */  lw         $v0, 0xD98($s3)
    /* 5E9D4 8006E1D4 00000000 */  nop
    /* 5E9D8 8006E1D8 24104300 */  and        $v0, $v0, $v1
    /* 5E9DC 8006E1DC 05004014 */  bnez       $v0, .L8006E1F4
    /* 5E9E0 8006E1E0 00000000 */   nop
    /* 5E9E4 8006E1E4 9C0D6292 */  lbu        $v0, 0xD9C($s3)
    /* 5E9E8 8006E1E8 00000000 */  nop
    /* 5E9EC 8006E1EC CF004010 */  beqz       $v0, .L8006E52C
    /* 5E9F0 8006E1F0 00000000 */   nop
  .L8006E1F4:
    /* 5E9F4 8006E1F4 7415020C */  jal        func_800855D0
    /* 5E9F8 8006E1F8 2800A427 */   addiu     $a0, $sp, 0x28
    /* 5E9FC 8006E1FC 380C6426 */  addiu      $a0, $s3, 0xC38
    /* 5EA00 8006E200 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 5EA04 8006E204 5C1E020C */  jal        func_80087970
    /* 5EA08 8006E208 D000A627 */   addiu     $a2, $sp, 0xD0
    /* 5EA0C 8006E20C 9000A427 */  addiu      $a0, $sp, 0x90
    /* 5EA10 8006E210 4800B027 */  addiu      $s0, $sp, 0x48
    /* 5EA14 8006E214 4C1F020C */  jal        func_80087D30
    /* 5EA18 8006E218 21280002 */   addu      $a1, $s0, $zero
    /* 5EA1C 8006E21C 21200002 */  addu       $a0, $s0, $zero
    /* 5EA20 8006E220 9C1D020C */  jal        func_80087670
    /* 5EA24 8006E224 A000A527 */   addiu     $a1, $sp, 0xA0
    /* 5EA28 8006E228 7415020C */  jal        func_800855D0
    /* 5EA2C 8006E22C 21200002 */   addu      $a0, $s0, $zero
    /* 5EA30 8006E230 21A80000 */  addu       $s5, $zero, $zero
    /* 5EA34 8006E234 E0FF1724 */  addiu      $s7, $zero, -0x20
    /* 5EA38 8006E238 20001624 */  addiu      $s6, $zero, 0x20
    /* 5EA3C 8006E23C 2800BE27 */  addiu      $fp, $sp, 0x28
    /* 5EA40 8006E240 21806002 */  addu       $s0, $s3, $zero
    /* 5EA44 8006E244 21A06002 */  addu       $s4, $s3, $zero
  .L8006E248:
    /* 5EA48 8006E248 5555023C */  lui        $v0, (0x55555556 >> 16)
    /* 5EA4C 8006E24C 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* 5EA50 8006E250 1800A202 */  mult       $s5, $v0
    /* 5EA54 8006E254 C31F1500 */  sra        $v1, $s5, 31
    /* 5EA58 8006E258 10700000 */  mfhi       $t6
    /* 5EA5C 8006E25C 2318C301 */  subu       $v1, $t6, $v1
    /* 5EA60 8006E260 40100300 */  sll        $v0, $v1, 1
    /* 5EA64 8006E264 21104300 */  addu       $v0, $v0, $v1
    /* 5EA68 8006E268 2310A202 */  subu       $v0, $s5, $v0
    /* 5EA6C 8006E26C 80100200 */  sll        $v0, $v0, 2
    /* 5EA70 8006E270 21106202 */  addu       $v0, $s3, $v0
    /* 5EA74 8006E274 920D4390 */  lbu        $v1, 0xD92($v0)
    /* 5EA78 8006E278 00000000 */  nop
    /* 5EA7C 8006E27C 040043A2 */  sb         $v1, 0x4($s2)
    /* 5EA80 8006E280 930D4390 */  lbu        $v1, 0xD93($v0)
    /* 5EA84 8006E284 00000000 */  nop
    /* 5EA88 8006E288 050043A2 */  sb         $v1, 0x5($s2)
    /* 5EA8C 8006E28C 940D4290 */  lbu        $v0, 0xD94($v0)
    /* 5EA90 8006E290 00000000 */  nop
    /* 5EA94 8006E294 060042A2 */  sb         $v0, 0x6($s2)
    /* 5EA98 8006E298 400C0296 */  lhu        $v0, 0xC40($s0)
    /* 5EA9C 8006E29C 00000000 */  nop
    /* 5EAA0 8006E2A0 01004230 */  andi       $v0, $v0, 0x1
    /* 5EAA4 8006E2A4 40110200 */  sll        $v0, $v0, 5
    /* 5EAA8 8006E2A8 0C0042A2 */  sb         $v0, 0xC($s2)
    /* 5EAAC 8006E2AC 400C0296 */  lhu        $v0, 0xC40($s0)
    /* 5EAB0 8006E2B0 00000000 */  nop
    /* 5EAB4 8006E2B4 42100200 */  srl        $v0, $v0, 1
    /* 5EAB8 8006E2B8 40110200 */  sll        $v0, $v0, 5
    /* 5EABC 8006E2BC 40004224 */  addiu      $v0, $v0, 0x40
    /* 5EAC0 8006E2C0 0D0042A2 */  sb         $v0, 0xD($s2)
    /* 5EAC4 8006E2C4 400C0296 */  lhu        $v0, 0xC40($s0)
    /* 5EAC8 8006E2C8 00000000 */  nop
    /* 5EACC 8006E2CC 01004230 */  andi       $v0, $v0, 0x1
    /* 5EAD0 8006E2D0 40110200 */  sll        $v0, $v0, 5
    /* 5EAD4 8006E2D4 1F004224 */  addiu      $v0, $v0, 0x1F
    /* 5EAD8 8006E2D8 140042A2 */  sb         $v0, 0x14($s2)
    /* 5EADC 8006E2DC 400C0296 */  lhu        $v0, 0xC40($s0)
    /* 5EAE0 8006E2E0 00000000 */  nop
    /* 5EAE4 8006E2E4 42100200 */  srl        $v0, $v0, 1
    /* 5EAE8 8006E2E8 40110200 */  sll        $v0, $v0, 5
    /* 5EAEC 8006E2EC 40004224 */  addiu      $v0, $v0, 0x40
    /* 5EAF0 8006E2F0 150042A2 */  sb         $v0, 0x15($s2)
    /* 5EAF4 8006E2F4 400C0296 */  lhu        $v0, 0xC40($s0)
    /* 5EAF8 8006E2F8 00000000 */  nop
    /* 5EAFC 8006E2FC 01004230 */  andi       $v0, $v0, 0x1
    /* 5EB00 8006E300 40110200 */  sll        $v0, $v0, 5
    /* 5EB04 8006E304 1C0042A2 */  sb         $v0, 0x1C($s2)
    /* 5EB08 8006E308 400C0296 */  lhu        $v0, 0xC40($s0)
    /* 5EB0C 8006E30C 21880000 */  addu       $s1, $zero, $zero
    /* 5EB10 8006E310 42100200 */  srl        $v0, $v0, 1
    /* 5EB14 8006E314 40110200 */  sll        $v0, $v0, 5
    /* 5EB18 8006E318 5F004224 */  addiu      $v0, $v0, 0x5F
    /* 5EB1C 8006E31C 1D0042A2 */  sb         $v0, 0x1D($s2)
    /* 5EB20 8006E320 400C0296 */  lhu        $v0, 0xC40($s0)
    /* 5EB24 8006E324 38008626 */  addiu      $a2, $s4, 0x38
    /* 5EB28 8006E328 01004230 */  andi       $v0, $v0, 0x1
    /* 5EB2C 8006E32C 40110200 */  sll        $v0, $v0, 5
    /* 5EB30 8006E330 1F004224 */  addiu      $v0, $v0, 0x1F
    /* 5EB34 8006E334 240042A2 */  sb         $v0, 0x24($s2)
    /* 5EB38 8006E338 400C0296 */  lhu        $v0, 0xC40($s0)
    /* 5EB3C 8006E33C 2128C003 */  addu       $a1, $fp, $zero
    /* 5EB40 8006E340 42100200 */  srl        $v0, $v0, 1
    /* 5EB44 8006E344 40110200 */  sll        $v0, $v0, 5
    /* 5EB48 8006E348 5F004224 */  addiu      $v0, $v0, 0x5F
    /* 5EB4C 8006E34C 250042A2 */  sb         $v0, 0x25($s2)
    /* 5EB50 8006E350 B000B7A7 */  sh         $s7, 0xB0($sp)
    /* 5EB54 8006E354 B200B7A7 */  sh         $s7, 0xB2($sp)
    /* 5EB58 8006E358 B400A0A7 */  sh         $zero, 0xB4($sp)
    /* 5EB5C 8006E35C B800B6A7 */  sh         $s6, 0xB8($sp)
    /* 5EB60 8006E360 BA00B7A7 */  sh         $s7, 0xBA($sp)
    /* 5EB64 8006E364 BC00A0A7 */  sh         $zero, 0xBC($sp)
    /* 5EB68 8006E368 C000B7A7 */  sh         $s7, 0xC0($sp)
    /* 5EB6C 8006E36C C200B6A7 */  sh         $s6, 0xC2($sp)
    /* 5EB70 8006E370 C400A0A7 */  sh         $zero, 0xC4($sp)
    /* 5EB74 8006E374 C800B6A7 */  sh         $s6, 0xC8($sp)
    /* 5EB78 8006E378 CA00B6A7 */  sh         $s6, 0xCA($sp)
    /* 5EB7C 8006E37C CC00A0A7 */  sh         $zero, 0xCC($sp)
  .L8006E380:
    /* 5EB80 8006E380 8800A294 */  lhu        $v0, 0x88($a1)
    /* 5EB84 8006E384 38008396 */  lhu        $v1, 0x38($s4)
    /* 5EB88 8006E388 8800A424 */  addiu      $a0, $a1, 0x88
    /* 5EB8C 8006E38C 21104300 */  addu       $v0, $v0, $v1
    /* 5EB90 8006E390 8800A2A4 */  sh         $v0, 0x88($a1)
    /* 5EB94 8006E394 02008294 */  lhu        $v0, 0x2($a0)
    /* 5EB98 8006E398 0200C394 */  lhu        $v1, 0x2($a2)
    /* 5EB9C 8006E39C 01003126 */  addiu      $s1, $s1, 0x1
    /* 5EBA0 8006E3A0 21104300 */  addu       $v0, $v0, $v1
    /* 5EBA4 8006E3A4 020082A4 */  sh         $v0, 0x2($a0)
    /* 5EBA8 8006E3A8 04008294 */  lhu        $v0, 0x4($a0)
    /* 5EBAC 8006E3AC 0400C394 */  lhu        $v1, 0x4($a2)
    /* 5EBB0 8006E3B0 00000000 */  nop
    /* 5EBB4 8006E3B4 21104300 */  addu       $v0, $v0, $v1
    /* 5EBB8 8006E3B8 040082A4 */  sh         $v0, 0x4($a0)
    /* 5EBBC 8006E3BC 0400222A */  slti       $v0, $s1, 0x4
    /* 5EBC0 8006E3C0 EFFF4014 */  bnez       $v0, .L8006E380
    /* 5EBC4 8006E3C4 0800A524 */   addiu     $a1, $a1, 0x8
    /* 5EBC8 8006E3C8 B000A427 */  addiu      $a0, $sp, 0xB0
    /* 5EBCC 8006E3CC B800A527 */  addiu      $a1, $sp, 0xB8
    /* 5EBD0 8006E3D0 C000A627 */  addiu      $a2, $sp, 0xC0
    /* 5EBD4 8006E3D4 C800A727 */  addiu      $a3, $sp, 0xC8
    /* 5EBD8 8006E3D8 08004226 */  addiu      $v0, $s2, 0x8
    /* 5EBDC 8006E3DC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5EBE0 8006E3E0 10004226 */  addiu      $v0, $s2, 0x10
    /* 5EBE4 8006E3E4 1400A2AF */  sw         $v0, 0x14($sp)
    /* 5EBE8 8006E3E8 18004226 */  addiu      $v0, $s2, 0x18
    /* 5EBEC 8006E3EC 1800A2AF */  sw         $v0, 0x18($sp)
    /* 5EBF0 8006E3F0 20004226 */  addiu      $v0, $s2, 0x20
    /* 5EBF4 8006E3F4 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 5EBF8 8006E3F8 D400A227 */  addiu      $v0, $sp, 0xD4
    /* 5EBFC 8006E3FC 2000A2AF */  sw         $v0, 0x20($sp)
    /* 5EC00 8006E400 D000A227 */  addiu      $v0, $sp, 0xD0
    /* 5EC04 8006E404 AC1E020C */  jal        func_80087AB0
    /* 5EC08 8006E408 2400A2AF */   sw        $v0, 0x24($sp)
    /* 5EC0C 8006E40C 21304000 */  addu       $a2, $v0, $zero
    /* 5EC10 8006E410 0A00C004 */  bltz       $a2, .L8006E43C
    /* 5EC14 8006E414 38008426 */   addiu     $a0, $s4, 0x38
    /* 5EC18 8006E418 D000A28F */  lw         $v0, 0xD0($sp)
    /* 5EC1C 8006E41C 00000000 */  nop
    /* 5EC20 8006E420 05004004 */  bltz       $v0, .L8006E438
    /* 5EC24 8006E424 21204002 */   addu      $a0, $s2, $zero
    /* 5EC28 8006E428 DC00A58F */  lw         $a1, 0xDC($sp)
    /* 5EC2C 8006E42C FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 5EC30 8006E430 986C010C */  jal        func_8005B260
    /* 5EC34 8006E434 01000724 */   addiu     $a3, $zero, 0x1
  .L8006E438:
    /* 5EC38 8006E438 38008426 */  addiu      $a0, $s4, 0x38
  .L8006E43C:
    /* 5EC3C 8006E43C 38008296 */  lhu        $v0, 0x38($s4)
    /* 5EC40 8006E440 38028396 */  lhu        $v1, 0x238($s4)
    /* 5EC44 8006E444 38028526 */  addiu      $a1, $s4, 0x238
    /* 5EC48 8006E448 21104300 */  addu       $v0, $v0, $v1
    /* 5EC4C 8006E44C 380082A6 */  sh         $v0, 0x38($s4)
    /* 5EC50 8006E450 02008294 */  lhu        $v0, 0x2($a0)
    /* 5EC54 8006E454 0200A394 */  lhu        $v1, 0x2($a1)
    /* 5EC58 8006E458 00000000 */  nop
    /* 5EC5C 8006E45C 21104300 */  addu       $v0, $v0, $v1
    /* 5EC60 8006E460 020082A4 */  sh         $v0, 0x2($a0)
    /* 5EC64 8006E464 04008294 */  lhu        $v0, 0x4($a0)
    /* 5EC68 8006E468 0400A394 */  lhu        $v1, 0x4($a1)
    /* 5EC6C 8006E46C 00000000 */  nop
    /* 5EC70 8006E470 21104300 */  addu       $v0, $v0, $v1
    /* 5EC74 8006E474 040082A4 */  sh         $v0, 0x4($a0)
    /* 5EC78 8006E478 400C0496 */  lhu        $a0, 0xC40($s0)
    /* 5EC7C 8006E47C 00000000 */  nop
    /* 5EC80 8006E480 01008324 */  addiu      $v1, $a0, 0x1
    /* 5EC84 8006E484 02006104 */  bgez       $v1, .L8006E490
    /* 5EC88 8006E488 21106000 */   addu      $v0, $v1, $zero
    /* 5EC8C 8006E48C 04008224 */  addiu      $v0, $a0, 0x4
  .L8006E490:
    /* 5EC90 8006E490 83100200 */  sra        $v0, $v0, 2
    /* 5EC94 8006E494 80100200 */  sll        $v0, $v0, 2
    /* 5EC98 8006E498 23106200 */  subu       $v0, $v1, $v0
    /* 5EC9C 8006E49C 400C02A6 */  sh         $v0, 0xC40($s0)
    /* 5ECA0 8006E4A0 02001026 */  addiu      $s0, $s0, 0x2
    /* 5ECA4 8006E4A4 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5ECA8 8006E4A8 4000A22A */  slti       $v0, $s5, 0x40
    /* 5ECAC 8006E4AC 66FF4014 */  bnez       $v0, .L8006E248
    /* 5ECB0 8006E4B0 08009426 */   addiu     $s4, $s4, 0x8
    /* 5ECB4 8006E4B4 21186002 */  addu       $v1, $s3, $zero
    /* 5ECB8 8006E4B8 0C006526 */  addiu      $a1, $s3, 0xC
  .L8006E4BC:
    /* 5ECBC 8006E4BC 920D6490 */  lbu        $a0, 0xD92($v1)
    /* 5ECC0 8006E4C0 00000000 */  nop
    /* 5ECC4 8006E4C4 1000822C */  sltiu      $v0, $a0, 0x10
    /* 5ECC8 8006E4C8 03004014 */  bnez       $v0, .L8006E4D8
    /* 5ECCC 8006E4CC F1FF8224 */   addiu     $v0, $a0, -0xF
    /* 5ECD0 8006E4D0 37B90108 */  j          .L8006E4DC
    /* 5ECD4 8006E4D4 920D62A0 */   sb        $v0, 0xD92($v1)
  .L8006E4D8:
    /* 5ECD8 8006E4D8 920D60A0 */  sb         $zero, 0xD92($v1)
  .L8006E4DC:
    /* 5ECDC 8006E4DC 930D6490 */  lbu        $a0, 0xD93($v1)
    /* 5ECE0 8006E4E0 00000000 */  nop
    /* 5ECE4 8006E4E4 1000822C */  sltiu      $v0, $a0, 0x10
    /* 5ECE8 8006E4E8 03004014 */  bnez       $v0, .L8006E4F8
    /* 5ECEC 8006E4EC F1FF8224 */   addiu     $v0, $a0, -0xF
    /* 5ECF0 8006E4F0 3FB90108 */  j          .L8006E4FC
    /* 5ECF4 8006E4F4 930D62A0 */   sb        $v0, 0xD93($v1)
  .L8006E4F8:
    /* 5ECF8 8006E4F8 930D60A0 */  sb         $zero, 0xD93($v1)
  .L8006E4FC:
    /* 5ECFC 8006E4FC 940D6490 */  lbu        $a0, 0xD94($v1)
    /* 5ED00 8006E500 00000000 */  nop
    /* 5ED04 8006E504 1000822C */  sltiu      $v0, $a0, 0x10
    /* 5ED08 8006E508 03004014 */  bnez       $v0, .L8006E518
    /* 5ED0C 8006E50C F1FF8224 */   addiu     $v0, $a0, -0xF
    /* 5ED10 8006E510 47B90108 */  j          .L8006E51C
    /* 5ED14 8006E514 940D62A0 */   sb        $v0, 0xD94($v1)
  .L8006E518:
    /* 5ED18 8006E518 940D60A0 */  sb         $zero, 0xD94($v1)
  .L8006E51C:
    /* 5ED1C 8006E51C 04006324 */  addiu      $v1, $v1, 0x4
    /* 5ED20 8006E520 2A106500 */  slt        $v0, $v1, $a1
    /* 5ED24 8006E524 E5FF4014 */  bnez       $v0, .L8006E4BC
    /* 5ED28 8006E528 00000000 */   nop
  .L8006E52C:
    /* 5ED2C 8006E52C 8E0D6296 */  lhu        $v0, 0xD8E($s3)
    /* 5ED30 8006E530 C0FF0424 */  addiu      $a0, $zero, -0x40
    /* 5ED34 8006E534 160042A6 */  sh         $v0, 0x16($s2)
    /* 5ED38 8006E538 900D6296 */  lhu        $v0, 0xD90($s3)
    /* 5ED3C 8006E53C 40000324 */  addiu      $v1, $zero, 0x40
    /* 5ED40 8006E540 0E0042A6 */  sh         $v0, 0xE($s2)
    /* 5ED44 8006E544 00FF0224 */  addiu      $v0, $zero, -0x100
    /* 5ED48 8006E548 B000A4A7 */  sh         $a0, 0xB0($sp)
    /* 5ED4C 8006E54C B200A2A7 */  sh         $v0, 0xB2($sp)
    /* 5ED50 8006E550 B400A0A7 */  sh         $zero, 0xB4($sp)
    /* 5ED54 8006E554 B800A3A7 */  sh         $v1, 0xB8($sp)
    /* 5ED58 8006E558 BA00A2A7 */  sh         $v0, 0xBA($sp)
    /* 5ED5C 8006E55C BC00A0A7 */  sh         $zero, 0xBC($sp)
    /* 5ED60 8006E560 C000A4A7 */  sh         $a0, 0xC0($sp)
    /* 5ED64 8006E564 C200A0A7 */  sh         $zero, 0xC2($sp)
    /* 5ED68 8006E568 C400A0A7 */  sh         $zero, 0xC4($sp)
    /* 5ED6C 8006E56C C800A3A7 */  sh         $v1, 0xC8($sp)
    /* 5ED70 8006E570 CA00A0A7 */  sh         $zero, 0xCA($sp)
    /* 5ED74 8006E574 CC00A0A7 */  sh         $zero, 0xCC($sp)
    /* 5ED78 8006E578 860D6296 */  lhu        $v0, 0xD86($s3)
    /* 5ED7C 8006E57C 00000000 */  nop
    /* 5ED80 8006E580 D8004010 */  beqz       $v0, .L8006E8E4
    /* 5ED84 8006E584 21A80000 */   addu      $s5, $zero, $zero
    /* 5ED88 8006E588 4800B627 */  addiu      $s6, $sp, 0x48
    /* 5ED8C 8006E58C D000B727 */  addiu      $s7, $sp, 0xD0
    /* 5ED90 8006E590 21806002 */  addu       $s0, $s3, $zero
    /* 5ED94 8006E594 21886002 */  addu       $s1, $s3, $zero
    /* 5ED98 8006E598 21A06002 */  addu       $s4, $s3, $zero
  .L8006E59C:
    /* 5ED9C 8006E59C A20D0292 */  lbu        $v0, 0xDA2($s0)
    /* 5EDA0 8006E5A0 00000000 */  nop
    /* 5EDA4 8006E5A4 09004014 */  bnez       $v0, .L8006E5CC
    /* 5EDA8 8006E5A8 00000000 */   nop
    /* 5EDAC 8006E5AC A30D0292 */  lbu        $v0, 0xDA3($s0)
    /* 5EDB0 8006E5B0 00000000 */  nop
    /* 5EDB4 8006E5B4 05004014 */  bnez       $v0, .L8006E5CC
    /* 5EDB8 8006E5B8 00000000 */   nop
    /* 5EDBC 8006E5BC A40D0292 */  lbu        $v0, 0xDA4($s0)
    /* 5EDC0 8006E5C0 00000000 */  nop
    /* 5EDC4 8006E5C4 BF004010 */  beqz       $v0, .L8006E8C4
    /* 5EDC8 8006E5C8 00000000 */   nop
  .L8006E5CC:
    /* 5EDCC 8006E5CC 380C6396 */  lhu        $v1, 0xC38($s3)
    /* 5EDD0 8006E5D0 00000000 */  nop
    /* 5EDD4 8006E5D4 9800A3A7 */  sh         $v1, 0x98($sp)
    /* 5EDD8 8006E5D8 3A0C6496 */  lhu        $a0, 0xC3A($s3)
    /* 5EDDC 8006E5DC 00000000 */  nop
    /* 5EDE0 8006E5E0 9A00A4A7 */  sh         $a0, 0x9A($sp)
    /* 5EDE4 8006E5E4 3C0C6596 */  lhu        $a1, 0xC3C($s3)
    /* 5EDE8 8006E5E8 00000000 */  nop
    /* 5EDEC 8006E5EC 9C00A5A7 */  sh         $a1, 0x9C($sp)
    /* 5EDF0 8006E5F0 38042296 */  lhu        $v0, 0x438($s1)
    /* 5EDF4 8006E5F4 00000000 */  nop
    /* 5EDF8 8006E5F8 21186200 */  addu       $v1, $v1, $v0
    /* 5EDFC 8006E5FC 9800A3A7 */  sh         $v1, 0x98($sp)
    /* 5EE00 8006E600 38042326 */  addiu      $v1, $s1, 0x438
    /* 5EE04 8006E604 02006294 */  lhu        $v0, 0x2($v1)
    /* 5EE08 8006E608 00000000 */  nop
    /* 5EE0C 8006E60C 21208200 */  addu       $a0, $a0, $v0
    /* 5EE10 8006E610 9A00A4A7 */  sh         $a0, 0x9A($sp)
    /* 5EE14 8006E614 04006294 */  lhu        $v0, 0x4($v1)
    /* 5EE18 8006E618 2800A427 */  addiu      $a0, $sp, 0x28
    /* 5EE1C 8006E61C 2128A200 */  addu       $a1, $a1, $v0
    /* 5EE20 8006E620 7415020C */  jal        func_800855D0
    /* 5EE24 8006E624 9C00A5A7 */   sh        $a1, 0x9C($sp)
    /* 5EE28 8006E628 9800A427 */  addiu      $a0, $sp, 0x98
    /* 5EE2C 8006E62C 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 5EE30 8006E630 5C1E020C */  jal        func_80087970
    /* 5EE34 8006E634 2130E002 */   addu      $a2, $s7, $zero
    /* 5EE38 8006E638 9000A427 */  addiu      $a0, $sp, 0x90
    /* 5EE3C 8006E63C 4C1F020C */  jal        func_80087D30
    /* 5EE40 8006E640 2128C002 */   addu      $a1, $s6, $zero
    /* 5EE44 8006E644 2120C002 */  addu       $a0, $s6, $zero
    /* 5EE48 8006E648 9C1D020C */  jal        func_80087670
    /* 5EE4C 8006E64C A000A527 */   addiu     $a1, $sp, 0xA0
    /* 5EE50 8006E650 7415020C */  jal        func_800855D0
    /* 5EE54 8006E654 2120C002 */   addu      $a0, $s6, $zero
    /* 5EE58 8006E658 C00C8296 */  lhu        $v0, 0xCC0($s4)
    /* 5EE5C 8006E65C 0D0040A2 */  sb         $zero, 0xD($s2)
    /* 5EE60 8006E660 40110200 */  sll        $v0, $v0, 5
    /* 5EE64 8006E664 0C0042A2 */  sb         $v0, 0xC($s2)
    /* 5EE68 8006E668 C00C8296 */  lhu        $v0, 0xCC0($s4)
    /* 5EE6C 8006E66C 150040A2 */  sb         $zero, 0x15($s2)
    /* 5EE70 8006E670 40110200 */  sll        $v0, $v0, 5
    /* 5EE74 8006E674 1F004224 */  addiu      $v0, $v0, 0x1F
    /* 5EE78 8006E678 140042A2 */  sb         $v0, 0x14($s2)
    /* 5EE7C 8006E67C C00C8296 */  lhu        $v0, 0xCC0($s4)
    /* 5EE80 8006E680 3F000324 */  addiu      $v1, $zero, 0x3F
    /* 5EE84 8006E684 1D0043A2 */  sb         $v1, 0x1D($s2)
    /* 5EE88 8006E688 40110200 */  sll        $v0, $v0, 5
    /* 5EE8C 8006E68C 1C0042A2 */  sb         $v0, 0x1C($s2)
    /* 5EE90 8006E690 C00C8296 */  lhu        $v0, 0xCC0($s4)
    /* 5EE94 8006E694 B000A427 */  addiu      $a0, $sp, 0xB0
    /* 5EE98 8006E698 250043A2 */  sb         $v1, 0x25($s2)
    /* 5EE9C 8006E69C 40110200 */  sll        $v0, $v0, 5
    /* 5EEA0 8006E6A0 1F004224 */  addiu      $v0, $v0, 0x1F
    /* 5EEA4 8006E6A4 240042A2 */  sb         $v0, 0x24($s2)
    /* 5EEA8 8006E6A8 A20D0292 */  lbu        $v0, 0xDA2($s0)
    /* 5EEAC 8006E6AC B800A527 */  addiu      $a1, $sp, 0xB8
    /* 5EEB0 8006E6B0 040042A2 */  sb         $v0, 0x4($s2)
    /* 5EEB4 8006E6B4 A30D0292 */  lbu        $v0, 0xDA3($s0)
    /* 5EEB8 8006E6B8 C000A627 */  addiu      $a2, $sp, 0xC0
    /* 5EEBC 8006E6BC 050042A2 */  sb         $v0, 0x5($s2)
    /* 5EEC0 8006E6C0 A40D0292 */  lbu        $v0, 0xDA4($s0)
    /* 5EEC4 8006E6C4 C800A727 */  addiu      $a3, $sp, 0xC8
    /* 5EEC8 8006E6C8 060042A2 */  sb         $v0, 0x6($s2)
    /* 5EECC 8006E6CC 08004226 */  addiu      $v0, $s2, 0x8
    /* 5EED0 8006E6D0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5EED4 8006E6D4 10004226 */  addiu      $v0, $s2, 0x10
    /* 5EED8 8006E6D8 1400A2AF */  sw         $v0, 0x14($sp)
    /* 5EEDC 8006E6DC 18004226 */  addiu      $v0, $s2, 0x18
    /* 5EEE0 8006E6E0 1800A2AF */  sw         $v0, 0x18($sp)
    /* 5EEE4 8006E6E4 20004226 */  addiu      $v0, $s2, 0x20
    /* 5EEE8 8006E6E8 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 5EEEC 8006E6EC D400A227 */  addiu      $v0, $sp, 0xD4
    /* 5EEF0 8006E6F0 2000A2AF */  sw         $v0, 0x20($sp)
    /* 5EEF4 8006E6F4 AC1E020C */  jal        func_80087AB0
    /* 5EEF8 8006E6F8 2400B7AF */   sw        $s7, 0x24($sp)
    /* 5EEFC 8006E6FC 21304000 */  addu       $a2, $v0, $zero
    /* 5EF00 8006E700 0900C004 */  bltz       $a2, .L8006E728
    /* 5EF04 8006E704 00000000 */   nop
    /* 5EF08 8006E708 D000A28F */  lw         $v0, 0xD0($sp)
    /* 5EF0C 8006E70C 00000000 */  nop
    /* 5EF10 8006E710 05004004 */  bltz       $v0, .L8006E728
    /* 5EF14 8006E714 21204002 */   addu      $a0, $s2, $zero
    /* 5EF18 8006E718 DC00A58F */  lw         $a1, 0xDC($sp)
    /* 5EF1C 8006E71C FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 5EF20 8006E720 986C010C */  jal        func_8005B260
    /* 5EF24 8006E724 01000724 */   addiu     $a3, $zero, 0x1
  .L8006E728:
    /* 5EF28 8006E728 C00C8496 */  lhu        $a0, 0xCC0($s4)
    /* 5EF2C 8006E72C 00000000 */  nop
    /* 5EF30 8006E730 01008324 */  addiu      $v1, $a0, 0x1
    /* 5EF34 8006E734 02006104 */  bgez       $v1, .L8006E740
    /* 5EF38 8006E738 21106000 */   addu      $v0, $v1, $zero
    /* 5EF3C 8006E73C 08008224 */  addiu      $v0, $a0, 0x8
  .L8006E740:
    /* 5EF40 8006E740 C3100200 */  sra        $v0, $v0, 3
    /* 5EF44 8006E744 C0100200 */  sll        $v0, $v0, 3
    /* 5EF48 8006E748 23106200 */  subu       $v0, $v1, $v0
    /* 5EF4C 8006E74C C00C82A6 */  sh         $v0, 0xCC0($s4)
    /* 5EF50 8006E750 840D6296 */  lhu        $v0, 0xD84($s3)
    /* 5EF54 8006E754 00000000 */  nop
    /* 5EF58 8006E758 0200422C */  sltiu      $v0, $v0, 0x2
    /* 5EF5C 8006E75C 16004010 */  beqz       $v0, .L8006E7B8
    /* 5EF60 8006E760 00000000 */   nop
    /* 5EF64 8006E764 A20D0392 */  lbu        $v1, 0xDA2($s0)
    /* 5EF68 8006E768 00000000 */  nop
    /* 5EF6C 8006E76C 6100622C */  sltiu      $v0, $v1, 0x61
    /* 5EF70 8006E770 02004014 */  bnez       $v0, .L8006E77C
    /* 5EF74 8006E774 1F006224 */   addiu     $v0, $v1, 0x1F
    /* 5EF78 8006E778 80000224 */  addiu      $v0, $zero, 0x80
  .L8006E77C:
    /* 5EF7C 8006E77C A20D02A2 */  sb         $v0, 0xDA2($s0)
    /* 5EF80 8006E780 A30D0392 */  lbu        $v1, 0xDA3($s0)
    /* 5EF84 8006E784 00000000 */  nop
    /* 5EF88 8006E788 6100622C */  sltiu      $v0, $v1, 0x61
    /* 5EF8C 8006E78C 02004014 */  bnez       $v0, .L8006E798
    /* 5EF90 8006E790 1F006224 */   addiu     $v0, $v1, 0x1F
    /* 5EF94 8006E794 80000224 */  addiu      $v0, $zero, 0x80
  .L8006E798:
    /* 5EF98 8006E798 A30D02A2 */  sb         $v0, 0xDA3($s0)
    /* 5EF9C 8006E79C A40D0392 */  lbu        $v1, 0xDA4($s0)
    /* 5EFA0 8006E7A0 00000000 */  nop
    /* 5EFA4 8006E7A4 6100622C */  sltiu      $v0, $v1, 0x61
    /* 5EFA8 8006E7A8 02004014 */  bnez       $v0, .L8006E7B4
    /* 5EFAC 8006E7AC 1F006224 */   addiu     $v0, $v1, 0x1F
    /* 5EFB0 8006E7B0 80000224 */  addiu      $v0, $zero, 0x80
  .L8006E7B4:
    /* 5EFB4 8006E7B4 A40D02A2 */  sb         $v0, 0xDA4($s0)
  .L8006E7B8:
    /* 5EFB8 8006E7B8 840D6396 */  lhu        $v1, 0xD84($s3)
    /* 5EFBC 8006E7BC 01000224 */  addiu      $v0, $zero, 0x1
    /* 5EFC0 8006E7C0 13006214 */  bne        $v1, $v0, .L8006E810
    /* 5EFC4 8006E7C4 02000224 */   addiu     $v0, $zero, 0x2
    /* 5EFC8 8006E7C8 38042426 */  addiu      $a0, $s1, 0x438
    /* 5EFCC 8006E7CC 38042296 */  lhu        $v0, 0x438($s1)
    /* 5EFD0 8006E7D0 38052396 */  lhu        $v1, 0x538($s1)
    /* 5EFD4 8006E7D4 38052526 */  addiu      $a1, $s1, 0x538
    /* 5EFD8 8006E7D8 21104300 */  addu       $v0, $v0, $v1
    /* 5EFDC 8006E7DC 380422A6 */  sh         $v0, 0x438($s1)
    /* 5EFE0 8006E7E0 02008294 */  lhu        $v0, 0x2($a0)
    /* 5EFE4 8006E7E4 0200A394 */  lhu        $v1, 0x2($a1)
    /* 5EFE8 8006E7E8 00000000 */  nop
    /* 5EFEC 8006E7EC 21104300 */  addu       $v0, $v0, $v1
    /* 5EFF0 8006E7F0 020082A4 */  sh         $v0, 0x2($a0)
    /* 5EFF4 8006E7F4 04008294 */  lhu        $v0, 0x4($a0)
    /* 5EFF8 8006E7F8 0400A394 */  lhu        $v1, 0x4($a1)
    /* 5EFFC 8006E7FC 00000000 */  nop
    /* 5F000 8006E800 21104300 */  addu       $v0, $v0, $v1
    /* 5F004 8006E804 040082A4 */  sh         $v0, 0x4($a0)
    /* 5F008 8006E808 840D6396 */  lhu        $v1, 0xD84($s3)
    /* 5F00C 8006E80C 02000224 */  addiu      $v0, $zero, 0x2
  .L8006E810:
    /* 5F010 8006E810 2C006214 */  bne        $v1, $v0, .L8006E8C4
    /* 5F014 8006E814 38042426 */   addiu     $a0, $s1, 0x438
    /* 5F018 8006E818 38042296 */  lhu        $v0, 0x438($s1)
    /* 5F01C 8006E81C 38062396 */  lhu        $v1, 0x638($s1)
    /* 5F020 8006E820 38062526 */  addiu      $a1, $s1, 0x638
    /* 5F024 8006E824 21104300 */  addu       $v0, $v0, $v1
    /* 5F028 8006E828 380422A6 */  sh         $v0, 0x438($s1)
    /* 5F02C 8006E82C 02008294 */  lhu        $v0, 0x2($a0)
    /* 5F030 8006E830 0200A394 */  lhu        $v1, 0x2($a1)
    /* 5F034 8006E834 00000000 */  nop
    /* 5F038 8006E838 21104300 */  addu       $v0, $v0, $v1
    /* 5F03C 8006E83C 020082A4 */  sh         $v0, 0x2($a0)
    /* 5F040 8006E840 04008294 */  lhu        $v0, 0x4($a0)
    /* 5F044 8006E844 0400A394 */  lhu        $v1, 0x4($a1)
    /* 5F048 8006E848 00000000 */  nop
    /* 5F04C 8006E84C 21104300 */  addu       $v0, $v0, $v1
    /* 5F050 8006E850 040082A4 */  sh         $v0, 0x4($a0)
    /* 5F054 8006E854 3A062296 */  lhu        $v0, 0x63A($s1)
    /* 5F058 8006E858 00000000 */  nop
    /* 5F05C 8006E85C 02004224 */  addiu      $v0, $v0, 0x2
    /* 5F060 8006E860 3A0622A6 */  sh         $v0, 0x63A($s1)
    /* 5F064 8006E864 A20D0392 */  lbu        $v1, 0xDA2($s0)
    /* 5F068 8006E868 00000000 */  nop
    /* 5F06C 8006E86C 0900622C */  sltiu      $v0, $v1, 0x9
    /* 5F070 8006E870 03004014 */  bnez       $v0, .L8006E880
    /* 5F074 8006E874 F8FF6224 */   addiu     $v0, $v1, -0x8
    /* 5F078 8006E878 21BA0108 */  j          .L8006E884
    /* 5F07C 8006E87C A20D02A2 */   sb        $v0, 0xDA2($s0)
  .L8006E880:
    /* 5F080 8006E880 A20D00A2 */  sb         $zero, 0xDA2($s0)
  .L8006E884:
    /* 5F084 8006E884 A30D0392 */  lbu        $v1, 0xDA3($s0)
    /* 5F088 8006E888 00000000 */  nop
    /* 5F08C 8006E88C 0900622C */  sltiu      $v0, $v1, 0x9
    /* 5F090 8006E890 03004014 */  bnez       $v0, .L8006E8A0
    /* 5F094 8006E894 F8FF6224 */   addiu     $v0, $v1, -0x8
    /* 5F098 8006E898 29BA0108 */  j          .L8006E8A4
    /* 5F09C 8006E89C A30D02A2 */   sb        $v0, 0xDA3($s0)
  .L8006E8A0:
    /* 5F0A0 8006E8A0 A30D00A2 */  sb         $zero, 0xDA3($s0)
  .L8006E8A4:
    /* 5F0A4 8006E8A4 A40D0392 */  lbu        $v1, 0xDA4($s0)
    /* 5F0A8 8006E8A8 00000000 */  nop
    /* 5F0AC 8006E8AC 0900622C */  sltiu      $v0, $v1, 0x9
    /* 5F0B0 8006E8B0 03004014 */  bnez       $v0, .L8006E8C0
    /* 5F0B4 8006E8B4 F8FF6224 */   addiu     $v0, $v1, -0x8
    /* 5F0B8 8006E8B8 31BA0108 */  j          .L8006E8C4
    /* 5F0BC 8006E8BC A40D02A2 */   sb        $v0, 0xDA4($s0)
  .L8006E8C0:
    /* 5F0C0 8006E8C0 A40D00A2 */  sb         $zero, 0xDA4($s0)
  .L8006E8C4:
    /* 5F0C4 8006E8C4 04001026 */  addiu      $s0, $s0, 0x4
    /* 5F0C8 8006E8C8 08003126 */  addiu      $s1, $s1, 0x8
    /* 5F0CC 8006E8CC 860D6296 */  lhu        $v0, 0xD86($s3)
    /* 5F0D0 8006E8D0 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5F0D4 8006E8D4 2A10A202 */  slt        $v0, $s5, $v0
    /* 5F0D8 8006E8D8 30FF4014 */  bnez       $v0, .L8006E59C
    /* 5F0DC 8006E8DC 02009426 */   addiu     $s4, $s4, 0x2
    /* 5F0E0 8006E8E0 860D6296 */  lhu        $v0, 0xD86($s3)
  .L8006E8E4:
    /* 5F0E4 8006E8E4 00000000 */  nop
    /* 5F0E8 8006E8E8 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 5F0EC 8006E8EC 80100200 */  sll        $v0, $v0, 2
    /* 5F0F0 8006E8F0 21186202 */  addu       $v1, $s3, $v0
    /* 5F0F4 8006E8F4 A20D6290 */  lbu        $v0, 0xDA2($v1)
    /* 5F0F8 8006E8F8 00000000 */  nop
    /* 5F0FC 8006E8FC 4100422C */  sltiu      $v0, $v0, 0x41
    /* 5F100 8006E900 0B004010 */  beqz       $v0, .L8006E930
    /* 5F104 8006E904 00000000 */   nop
    /* 5F108 8006E908 A30D6290 */  lbu        $v0, 0xDA3($v1)
    /* 5F10C 8006E90C 00000000 */  nop
    /* 5F110 8006E910 4100422C */  sltiu      $v0, $v0, 0x41
    /* 5F114 8006E914 06004010 */  beqz       $v0, .L8006E930
    /* 5F118 8006E918 00000000 */   nop
    /* 5F11C 8006E91C A40D6290 */  lbu        $v0, 0xDA4($v1)
    /* 5F120 8006E920 00000000 */  nop
    /* 5F124 8006E924 4100422C */  sltiu      $v0, $v0, 0x41
    /* 5F128 8006E928 1F004014 */  bnez       $v0, .L8006E9A8
    /* 5F12C 8006E92C 00000000 */   nop
  .L8006E930:
    /* 5F130 8006E930 840D6296 */  lhu        $v0, 0xD84($s3)
    /* 5F134 8006E934 00000000 */  nop
    /* 5F138 8006E938 1E004014 */  bnez       $v0, .L8006E9B4
    /* 5F13C 8006E93C 0200422C */   sltiu     $v0, $v0, 0x2
    /* 5F140 8006E940 860D6396 */  lhu        $v1, 0xD86($s3)
    /* 5F144 8006E944 AAAA023C */  lui        $v0, (0xAAAAAAAB >> 16)
    /* 5F148 8006E948 ABAA4234 */  ori        $v0, $v0, (0xAAAAAAAB & 0xFFFF)
    /* 5F14C 8006E94C 19006200 */  multu      $v1, $v0
    /* 5F150 8006E950 10700000 */  mfhi       $t6
    /* 5F154 8006E954 42200E00 */  srl        $a0, $t6, 1
    /* 5F158 8006E958 40100400 */  sll        $v0, $a0, 1
    /* 5F15C 8006E95C 21104400 */  addu       $v0, $v0, $a0
    /* 5F160 8006E960 23186200 */  subu       $v1, $v1, $v0
    /* 5F164 8006E964 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 5F168 8006E968 04006014 */  bnez       $v1, .L8006E97C
    /* 5F16C 8006E96C 01000424 */   addiu     $a0, $zero, 0x1
    /* 5F170 8006E970 FF000524 */  addiu      $a1, $zero, 0xFF
    /* 5F174 8006E974 9621010C */  jal        func_80048658
    /* 5F178 8006E978 21300000 */   addu      $a2, $zero, $zero
  .L8006E97C:
    /* 5F17C 8006E97C 860D6296 */  lhu        $v0, 0xD86($s3)
    /* 5F180 8006E980 00000000 */  nop
    /* 5F184 8006E984 01004224 */  addiu      $v0, $v0, 0x1
    /* 5F188 8006E988 860D62A6 */  sh         $v0, 0xD86($s3)
    /* 5F18C 8006E98C FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 5F190 8006E990 2100422C */  sltiu      $v0, $v0, 0x21
    /* 5F194 8006E994 04004014 */  bnez       $v0, .L8006E9A8
    /* 5F198 8006E998 20000224 */   addiu     $v0, $zero, 0x20
    /* 5F19C 8006E99C 860D62A6 */  sh         $v0, 0xD86($s3)
    /* 5F1A0 8006E9A0 01000224 */  addiu      $v0, $zero, 0x1
    /* 5F1A4 8006E9A4 840D62A6 */  sh         $v0, 0xD84($s3)
  .L8006E9A8:
    /* 5F1A8 8006E9A8 840D6296 */  lhu        $v0, 0xD84($s3)
    /* 5F1AC 8006E9AC 00000000 */  nop
    /* 5F1B0 8006E9B0 0200422C */  sltiu      $v0, $v0, 0x2
  .L8006E9B4:
    /* 5F1B4 8006E9B4 B2014014 */  bnez       $v0, .L8006F080
    /* 5F1B8 8006E9B8 FFFF033C */   lui       $v1, (0xFFFF0000 >> 16)
    /* 5F1BC 8006E9BC 200E628E */  lw         $v0, 0xE20($s3)
    /* 5F1C0 8006E9C0 00000000 */  nop
    /* 5F1C4 8006E9C4 24104300 */  and        $v0, $v0, $v1
    /* 5F1C8 8006E9C8 05004014 */  bnez       $v0, .L8006E9E0
    /* 5F1CC 8006E9CC 00000000 */   nop
    /* 5F1D0 8006E9D0 240E6292 */  lbu        $v0, 0xE24($s3)
    /* 5F1D4 8006E9D4 00000000 */  nop
    /* 5F1D8 8006E9D8 A9014010 */  beqz       $v0, .L8006F080
    /* 5F1DC 8006E9DC 00000000 */   nop
  .L8006E9E0:
    /* 5F1E0 8006E9E0 8A0D6296 */  lhu        $v0, 0xD8A($s3)
    /* 5F1E4 8006E9E4 2800A427 */  addiu      $a0, $sp, 0x28
    /* 5F1E8 8006E9E8 160042A6 */  sh         $v0, 0x16($s2)
    /* 5F1EC 8006E9EC 8C0D6296 */  lhu        $v0, 0xD8C($s3)
    /* 5F1F0 8006E9F0 01000F24 */  addiu      $t7, $zero, 0x1
    /* 5F1F4 8006E9F4 E000AFA7 */  sh         $t7, 0xE0($sp)
    /* 5F1F8 8006E9F8 0E0042A6 */  sh         $v0, 0xE($s2)
    /* 5F1FC 8006E9FC E0FD0224 */  addiu      $v0, $zero, -0x220
    /* 5F200 8006EA00 9800A0A7 */  sh         $zero, 0x98($sp)
    /* 5F204 8006EA04 9A00A2A7 */  sh         $v0, 0x9A($sp)
    /* 5F208 8006EA08 9C00A0A7 */  sh         $zero, 0x9C($sp)
    /* 5F20C 8006EA0C 380C6296 */  lhu        $v0, 0xC38($s3)
    /* 5F210 8006EA10 21A80000 */  addu       $s5, $zero, $zero
    /* 5F214 8006EA14 9800A2A7 */  sh         $v0, 0x98($sp)
    /* 5F218 8006EA18 3A0C6296 */  lhu        $v0, 0xC3A($s3)
    /* 5F21C 8006EA1C 40001424 */  addiu      $s4, $zero, 0x40
    /* 5F220 8006EA20 E0FD4224 */  addiu      $v0, $v0, -0x220
    /* 5F224 8006EA24 9A00A2A7 */  sh         $v0, 0x9A($sp)
    /* 5F228 8006EA28 3C0C6296 */  lhu        $v0, 0xC3C($s3)
    /* 5F22C 8006EA2C 7F001124 */  addiu      $s1, $zero, 0x7F
    /* 5F230 8006EA30 7415020C */  jal        func_800855D0
    /* 5F234 8006EA34 9C00A2A7 */   sh        $v0, 0x9C($sp)
    /* 5F238 8006EA38 9800A427 */  addiu      $a0, $sp, 0x98
    /* 5F23C 8006EA3C 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 5F240 8006EA40 5C1E020C */  jal        func_80087970
    /* 5F244 8006EA44 D000A627 */   addiu     $a2, $sp, 0xD0
    /* 5F248 8006EA48 9000A427 */  addiu      $a0, $sp, 0x90
    /* 5F24C 8006EA4C 4800B027 */  addiu      $s0, $sp, 0x48
    /* 5F250 8006EA50 4C1F020C */  jal        func_80087D30
    /* 5F254 8006EA54 21280002 */   addu      $a1, $s0, $zero
    /* 5F258 8006EA58 21200002 */  addu       $a0, $s0, $zero
    /* 5F25C 8006EA5C 9C1D020C */  jal        func_80087670
    /* 5F260 8006EA60 A000A527 */   addiu     $a1, $sp, 0xA0
    /* 5F264 8006EA64 7415020C */  jal        func_800855D0
    /* 5F268 8006EA68 21200002 */   addu      $a0, $s0, $zero
  .L8006EA6C:
    /* 5F26C 8006EA6C E000B897 */  lhu        $t8, 0xE0($sp)
    /* 5F270 8006EA70 00000000 */  nop
    /* 5F274 8006EA74 00141800 */  sll        $v0, $t8, 16
    /* 5F278 8006EA78 03140200 */  sra        $v0, $v0, 16
    /* 5F27C 8006EA7C 23100200 */  negu       $v0, $v0
    /* 5F280 8006EA80 E000A2A7 */  sh         $v0, 0xE0($sp)
    /* 5F284 8006EA84 00140200 */  sll        $v0, $v0, 16
    /* 5F288 8006EA88 43120200 */  sra        $v0, $v0, 9
    /* 5F28C 8006EA8C 23100200 */  negu       $v0, $v0
    /* 5F290 8006EA90 B000A2A7 */  sh         $v0, 0xB0($sp)
    /* 5F294 8006EA94 FEFFA226 */  addiu      $v0, $s5, -0x2
    /* 5F298 8006EA98 02004104 */  bgez       $v0, .L8006EAA4
    /* 5F29C 8006EA9C 80FF0224 */   addiu     $v0, $zero, -0x80
    /* 5F2A0 8006EAA0 80000224 */  addiu      $v0, $zero, 0x80
  .L8006EAA4:
    /* 5F2A4 8006EAA4 B200A2A7 */  sh         $v0, 0xB2($sp)
    /* 5F2A8 8006EAA8 FEFFA226 */  addiu      $v0, $s5, -0x2
    /* 5F2AC 8006EAAC B400A0A7 */  sh         $zero, 0xB4($sp)
    /* 5F2B0 8006EAB0 03004004 */  bltz       $v0, .L8006EAC0
    /* 5F2B4 8006EAB4 B800A0A7 */   sh        $zero, 0xB8($sp)
    /* 5F2B8 8006EAB8 B1BA0108 */  j          .L8006EAC4
    /* 5F2BC 8006EABC 80FF0224 */   addiu     $v0, $zero, -0x80
  .L8006EAC0:
    /* 5F2C0 8006EAC0 80000224 */  addiu      $v0, $zero, 0x80
  .L8006EAC4:
    /* 5F2C4 8006EAC4 BA00A2A7 */  sh         $v0, 0xBA($sp)
    /* 5F2C8 8006EAC8 B000A427 */  addiu      $a0, $sp, 0xB0
    /* 5F2CC 8006EACC E000B997 */  lhu        $t9, 0xE0($sp)
    /* 5F2D0 8006EAD0 B800A527 */  addiu      $a1, $sp, 0xB8
    /* 5F2D4 8006EAD4 BC00A0A7 */  sh         $zero, 0xBC($sp)
    /* 5F2D8 8006EAD8 C200A0A7 */  sh         $zero, 0xC2($sp)
    /* 5F2DC 8006EADC C400A0A7 */  sh         $zero, 0xC4($sp)
    /* 5F2E0 8006EAE0 C800A0A7 */  sh         $zero, 0xC8($sp)
    /* 5F2E4 8006EAE4 CA00A0A7 */  sh         $zero, 0xCA($sp)
    /* 5F2E8 8006EAE8 CC00A0A7 */  sh         $zero, 0xCC($sp)
    /* 5F2EC 8006EAEC 00141900 */  sll        $v0, $t9, 16
    /* 5F2F0 8006EAF0 43120200 */  sra        $v0, $v0, 9
    /* 5F2F4 8006EAF4 23100200 */  negu       $v0, $v0
    /* 5F2F8 8006EAF8 C000A2A7 */  sh         $v0, 0xC0($sp)
    /* 5F2FC 8006EAFC 220E6292 */  lbu        $v0, 0xE22($s3)
    /* 5F300 8006EB00 C000A627 */  addiu      $a2, $sp, 0xC0
    /* 5F304 8006EB04 040042A2 */  sb         $v0, 0x4($s2)
    /* 5F308 8006EB08 230E6292 */  lbu        $v0, 0xE23($s3)
    /* 5F30C 8006EB0C C800A727 */  addiu      $a3, $sp, 0xC8
    /* 5F310 8006EB10 050042A2 */  sb         $v0, 0x5($s2)
    /* 5F314 8006EB14 240E6392 */  lbu        $v1, 0xE24($s3)
    /* 5F318 8006EB18 3F000224 */  addiu      $v0, $zero, 0x3F
    /* 5F31C 8006EB1C 1D0042A2 */  sb         $v0, 0x1D($s2)
    /* 5F320 8006EB20 250042A2 */  sb         $v0, 0x25($s2)
    /* 5F324 8006EB24 08004226 */  addiu      $v0, $s2, 0x8
    /* 5F328 8006EB28 0C0054A2 */  sb         $s4, 0xC($s2)
    /* 5F32C 8006EB2C 0D0040A2 */  sb         $zero, 0xD($s2)
    /* 5F330 8006EB30 140051A2 */  sb         $s1, 0x14($s2)
    /* 5F334 8006EB34 150040A2 */  sb         $zero, 0x15($s2)
    /* 5F338 8006EB38 1C0054A2 */  sb         $s4, 0x1C($s2)
    /* 5F33C 8006EB3C 240051A2 */  sb         $s1, 0x24($s2)
    /* 5F340 8006EB40 060043A2 */  sb         $v1, 0x6($s2)
    /* 5F344 8006EB44 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5F348 8006EB48 10004226 */  addiu      $v0, $s2, 0x10
    /* 5F34C 8006EB4C 1400A2AF */  sw         $v0, 0x14($sp)
    /* 5F350 8006EB50 18004226 */  addiu      $v0, $s2, 0x18
    /* 5F354 8006EB54 1800A2AF */  sw         $v0, 0x18($sp)
    /* 5F358 8006EB58 20004226 */  addiu      $v0, $s2, 0x20
    /* 5F35C 8006EB5C 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 5F360 8006EB60 D400A227 */  addiu      $v0, $sp, 0xD4
    /* 5F364 8006EB64 2000A2AF */  sw         $v0, 0x20($sp)
    /* 5F368 8006EB68 D000A227 */  addiu      $v0, $sp, 0xD0
    /* 5F36C 8006EB6C AC1E020C */  jal        func_80087AB0
    /* 5F370 8006EB70 2400A2AF */   sw        $v0, 0x24($sp)
    /* 5F374 8006EB74 21304000 */  addu       $a2, $v0, $zero
    /* 5F378 8006EB78 0A00C004 */  bltz       $a2, .L8006EBA4
    /* 5F37C 8006EB7C B000A427 */   addiu     $a0, $sp, 0xB0
    /* 5F380 8006EB80 D000A28F */  lw         $v0, 0xD0($sp)
    /* 5F384 8006EB84 00000000 */  nop
    /* 5F388 8006EB88 05004004 */  bltz       $v0, .L8006EBA0
    /* 5F38C 8006EB8C 21204002 */   addu      $a0, $s2, $zero
    /* 5F390 8006EB90 DC00A58F */  lw         $a1, 0xDC($sp)
    /* 5F394 8006EB94 FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 5F398 8006EB98 986C010C */  jal        func_8005B260
    /* 5F39C 8006EB9C 01000724 */   addiu     $a3, $zero, 0x1
  .L8006EBA0:
    /* 5F3A0 8006EBA0 B000A427 */  addiu      $a0, $sp, 0xB0
  .L8006EBA4:
    /* 5F3A4 8006EBA4 220E6292 */  lbu        $v0, 0xE22($s3)
    /* 5F3A8 8006EBA8 B800A527 */  addiu      $a1, $sp, 0xB8
    /* 5F3AC 8006EBAC 42100200 */  srl        $v0, $v0, 1
    /* 5F3B0 8006EBB0 040042A2 */  sb         $v0, 0x4($s2)
    /* 5F3B4 8006EBB4 230E6292 */  lbu        $v0, 0xE23($s3)
    /* 5F3B8 8006EBB8 C000A627 */  addiu      $a2, $sp, 0xC0
    /* 5F3BC 8006EBBC 42100200 */  srl        $v0, $v0, 1
    /* 5F3C0 8006EBC0 050042A2 */  sb         $v0, 0x5($s2)
    /* 5F3C4 8006EBC4 240E6292 */  lbu        $v0, 0xE24($s3)
    /* 5F3C8 8006EBC8 C800A727 */  addiu      $a3, $sp, 0xC8
    /* 5F3CC 8006EBCC 0C0054A2 */  sb         $s4, 0xC($s2)
    /* 5F3D0 8006EBD0 0D0054A2 */  sb         $s4, 0xD($s2)
    /* 5F3D4 8006EBD4 140051A2 */  sb         $s1, 0x14($s2)
    /* 5F3D8 8006EBD8 150054A2 */  sb         $s4, 0x15($s2)
    /* 5F3DC 8006EBDC 1C0054A2 */  sb         $s4, 0x1C($s2)
    /* 5F3E0 8006EBE0 1D0051A2 */  sb         $s1, 0x1D($s2)
    /* 5F3E4 8006EBE4 240051A2 */  sb         $s1, 0x24($s2)
    /* 5F3E8 8006EBE8 250051A2 */  sb         $s1, 0x25($s2)
    /* 5F3EC 8006EBEC 42100200 */  srl        $v0, $v0, 1
    /* 5F3F0 8006EBF0 060042A2 */  sb         $v0, 0x6($s2)
    /* 5F3F4 8006EBF4 08004226 */  addiu      $v0, $s2, 0x8
    /* 5F3F8 8006EBF8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5F3FC 8006EBFC 10004226 */  addiu      $v0, $s2, 0x10
    /* 5F400 8006EC00 1400A2AF */  sw         $v0, 0x14($sp)
    /* 5F404 8006EC04 18004226 */  addiu      $v0, $s2, 0x18
    /* 5F408 8006EC08 1800A2AF */  sw         $v0, 0x18($sp)
    /* 5F40C 8006EC0C 20004226 */  addiu      $v0, $s2, 0x20
    /* 5F410 8006EC10 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 5F414 8006EC14 D400A227 */  addiu      $v0, $sp, 0xD4
    /* 5F418 8006EC18 2000A2AF */  sw         $v0, 0x20($sp)
    /* 5F41C 8006EC1C D000A227 */  addiu      $v0, $sp, 0xD0
    /* 5F420 8006EC20 AC1E020C */  jal        func_80087AB0
    /* 5F424 8006EC24 2400A2AF */   sw        $v0, 0x24($sp)
    /* 5F428 8006EC28 21304000 */  addu       $a2, $v0, $zero
    /* 5F42C 8006EC2C 0900C004 */  bltz       $a2, .L8006EC54
    /* 5F430 8006EC30 00000000 */   nop
    /* 5F434 8006EC34 D000A28F */  lw         $v0, 0xD0($sp)
    /* 5F438 8006EC38 00000000 */  nop
    /* 5F43C 8006EC3C 05004004 */  bltz       $v0, .L8006EC54
    /* 5F440 8006EC40 21204002 */   addu      $a0, $s2, $zero
    /* 5F444 8006EC44 DC00A58F */  lw         $a1, 0xDC($sp)
    /* 5F448 8006EC48 FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 5F44C 8006EC4C 986C010C */  jal        func_8005B260
    /* 5F450 8006EC50 01000724 */   addiu     $a3, $zero, 0x1
  .L8006EC54:
    /* 5F454 8006EC54 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5F458 8006EC58 0400A22A */  slti       $v0, $s5, 0x4
    /* 5F45C 8006EC5C 83FF4014 */  bnez       $v0, .L8006EA6C
    /* 5F460 8006EC60 80000224 */   addiu     $v0, $zero, 0x80
    /* 5F464 8006EC64 1F000324 */  addiu      $v1, $zero, 0x1F
    /* 5F468 8006EC68 0D0042A2 */  sb         $v0, 0xD($s2)
    /* 5F46C 8006EC6C 150042A2 */  sb         $v0, 0x15($s2)
    /* 5F470 8006EC70 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 5F474 8006EC74 1D0042A2 */  sb         $v0, 0x1D($s2)
    /* 5F478 8006EC78 250042A2 */  sb         $v0, 0x25($s2)
    /* 5F47C 8006EC7C FCFF0224 */  addiu      $v0, $zero, -0x4
    /* 5F480 8006EC80 0C0040A2 */  sb         $zero, 0xC($s2)
    /* 5F484 8006EC84 140043A2 */  sb         $v1, 0x14($s2)
    /* 5F488 8006EC88 1C0040A2 */  sb         $zero, 0x1C($s2)
    /* 5F48C 8006EC8C 240043A2 */  sb         $v1, 0x24($s2)
    /* 5F490 8006EC90 B000A2A7 */  sh         $v0, 0xB0($sp)
    /* 5F494 8006EC94 04000224 */  addiu      $v0, $zero, 0x4
    /* 5F498 8006EC98 B200A0A7 */  sh         $zero, 0xB2($sp)
    /* 5F49C 8006EC9C B400A0A7 */  sh         $zero, 0xB4($sp)
    /* 5F4A0 8006ECA0 B800A2A7 */  sh         $v0, 0xB8($sp)
    /* 5F4A4 8006ECA4 BA00A0A7 */  sh         $zero, 0xBA($sp)
    /* 5F4A8 8006ECA8 BC00A0A7 */  sh         $zero, 0xBC($sp)
    /* 5F4AC 8006ECAC 220E6292 */  lbu        $v0, 0xE22($s3)
    /* 5F4B0 8006ECB0 00000000 */  nop
    /* 5F4B4 8006ECB4 82100200 */  srl        $v0, $v0, 2
    /* 5F4B8 8006ECB8 040042A2 */  sb         $v0, 0x4($s2)
    /* 5F4BC 8006ECBC 230E6292 */  lbu        $v0, 0xE23($s3)
    /* 5F4C0 8006ECC0 21A80000 */  addu       $s5, $zero, $zero
    /* 5F4C4 8006ECC4 82100200 */  srl        $v0, $v0, 2
    /* 5F4C8 8006ECC8 050042A2 */  sb         $v0, 0x5($s2)
    /* 5F4CC 8006ECCC 240E6292 */  lbu        $v0, 0xE24($s3)
    /* 5F4D0 8006ECD0 21806002 */  addu       $s0, $s3, $zero
    /* 5F4D4 8006ECD4 82100200 */  srl        $v0, $v0, 2
    /* 5F4D8 8006ECD8 060042A2 */  sb         $v0, 0x6($s2)
  .L8006ECDC:
    /* 5F4DC 8006ECDC FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 5F4E0 8006ECE0 C000A2A7 */  sh         $v0, 0xC0($sp)
    /* 5F4E4 8006ECE4 02000224 */  addiu      $v0, $zero, 0x2
    /* 5F4E8 8006ECE8 C200A0A7 */  sh         $zero, 0xC2($sp)
    /* 5F4EC 8006ECEC C400A0A7 */  sh         $zero, 0xC4($sp)
    /* 5F4F0 8006ECF0 C800A2A7 */  sh         $v0, 0xC8($sp)
    /* 5F4F4 8006ECF4 CA00A0A7 */  sh         $zero, 0xCA($sp)
    /* 5F4F8 8006ECF8 CC00A0A7 */  sh         $zero, 0xCC($sp)
    /* 5F4FC 8006ECFC 38070296 */  lhu        $v0, 0x738($s0)
    /* 5F500 8006ED00 38070326 */  addiu      $v1, $s0, 0x738
    /* 5F504 8006ED04 FEFF4224 */  addiu      $v0, $v0, -0x2
    /* 5F508 8006ED08 C000A2A7 */  sh         $v0, 0xC0($sp)
    /* 5F50C 8006ED0C 02006294 */  lhu        $v0, 0x2($v1)
    /* 5F510 8006ED10 00000000 */  nop
    /* 5F514 8006ED14 C200A2A7 */  sh         $v0, 0xC2($sp)
    /* 5F518 8006ED18 04006294 */  lhu        $v0, 0x4($v1)
    /* 5F51C 8006ED1C B000A427 */  addiu      $a0, $sp, 0xB0
    /* 5F520 8006ED20 C400A2A7 */  sh         $v0, 0xC4($sp)
    /* 5F524 8006ED24 38070296 */  lhu        $v0, 0x738($s0)
    /* 5F528 8006ED28 B800A527 */  addiu      $a1, $sp, 0xB8
    /* 5F52C 8006ED2C 02004224 */  addiu      $v0, $v0, 0x2
    /* 5F530 8006ED30 C800A2A7 */  sh         $v0, 0xC8($sp)
    /* 5F534 8006ED34 02006294 */  lhu        $v0, 0x2($v1)
    /* 5F538 8006ED38 C000A627 */  addiu      $a2, $sp, 0xC0
    /* 5F53C 8006ED3C CA00A2A7 */  sh         $v0, 0xCA($sp)
    /* 5F540 8006ED40 04006294 */  lhu        $v0, 0x4($v1)
    /* 5F544 8006ED44 C800A727 */  addiu      $a3, $sp, 0xC8
    /* 5F548 8006ED48 CC00A2A7 */  sh         $v0, 0xCC($sp)
    /* 5F54C 8006ED4C 08004226 */  addiu      $v0, $s2, 0x8
    /* 5F550 8006ED50 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5F554 8006ED54 10004226 */  addiu      $v0, $s2, 0x10
    /* 5F558 8006ED58 1400A2AF */  sw         $v0, 0x14($sp)
    /* 5F55C 8006ED5C 18004226 */  addiu      $v0, $s2, 0x18
    /* 5F560 8006ED60 1800A2AF */  sw         $v0, 0x18($sp)
    /* 5F564 8006ED64 20004226 */  addiu      $v0, $s2, 0x20
    /* 5F568 8006ED68 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 5F56C 8006ED6C D400A227 */  addiu      $v0, $sp, 0xD4
    /* 5F570 8006ED70 2000A2AF */  sw         $v0, 0x20($sp)
    /* 5F574 8006ED74 D000A227 */  addiu      $v0, $sp, 0xD0
    /* 5F578 8006ED78 AC1E020C */  jal        func_80087AB0
    /* 5F57C 8006ED7C 2400A2AF */   sw        $v0, 0x24($sp)
    /* 5F580 8006ED80 21304000 */  addu       $a2, $v0, $zero
    /* 5F584 8006ED84 0900C004 */  bltz       $a2, .L8006EDAC
    /* 5F588 8006ED88 00000000 */   nop
    /* 5F58C 8006ED8C D000A28F */  lw         $v0, 0xD0($sp)
    /* 5F590 8006ED90 00000000 */  nop
    /* 5F594 8006ED94 05004004 */  bltz       $v0, .L8006EDAC
    /* 5F598 8006ED98 21204002 */   addu      $a0, $s2, $zero
    /* 5F59C 8006ED9C DC00A58F */  lw         $a1, 0xDC($sp)
    /* 5F5A0 8006EDA0 FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 5F5A4 8006EDA4 986C010C */  jal        func_8005B260
    /* 5F5A8 8006EDA8 01000724 */   addiu     $a3, $zero, 0x1
  .L8006EDAC:
    /* 5F5AC 8006EDAC 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5F5B0 8006EDB0 2000A22A */  slti       $v0, $s5, 0x20
    /* 5F5B4 8006EDB4 C9FF4014 */  bnez       $v0, .L8006ECDC
    /* 5F5B8 8006EDB8 08001026 */   addiu     $s0, $s0, 0x8
    /* 5F5BC 8006EDBC 21A80000 */  addu       $s5, $zero, $zero
    /* 5F5C0 8006EDC0 E0FF1724 */  addiu      $s7, $zero, -0x20
    /* 5F5C4 8006EDC4 20001624 */  addiu      $s6, $zero, 0x20
    /* 5F5C8 8006EDC8 2800BE27 */  addiu      $fp, $sp, 0x28
    /* 5F5CC 8006EDCC 21806002 */  addu       $s0, $s3, $zero
    /* 5F5D0 8006EDD0 21A06002 */  addu       $s4, $s3, $zero
  .L8006EDD4:
    /* 5F5D4 8006EDD4 220E6292 */  lbu        $v0, 0xE22($s3)
    /* 5F5D8 8006EDD8 00000000 */  nop
    /* 5F5DC 8006EDDC 040042A2 */  sb         $v0, 0x4($s2)
    /* 5F5E0 8006EDE0 230E6292 */  lbu        $v0, 0xE23($s3)
    /* 5F5E4 8006EDE4 00000000 */  nop
    /* 5F5E8 8006EDE8 050042A2 */  sb         $v0, 0x5($s2)
    /* 5F5EC 8006EDEC 240E6292 */  lbu        $v0, 0xE24($s3)
    /* 5F5F0 8006EDF0 00000000 */  nop
    /* 5F5F4 8006EDF4 060042A2 */  sb         $v0, 0x6($s2)
    /* 5F5F8 8006EDF8 000D0296 */  lhu        $v0, 0xD00($s0)
    /* 5F5FC 8006EDFC 00000000 */  nop
    /* 5F600 8006EE00 01004230 */  andi       $v0, $v0, 0x1
    /* 5F604 8006EE04 40110200 */  sll        $v0, $v0, 5
    /* 5F608 8006EE08 0C0042A2 */  sb         $v0, 0xC($s2)
    /* 5F60C 8006EE0C 000D0296 */  lhu        $v0, 0xD00($s0)
    /* 5F610 8006EE10 00000000 */  nop
    /* 5F614 8006EE14 42100200 */  srl        $v0, $v0, 1
    /* 5F618 8006EE18 40110200 */  sll        $v0, $v0, 5
    /* 5F61C 8006EE1C 40004224 */  addiu      $v0, $v0, 0x40
    /* 5F620 8006EE20 0D0042A2 */  sb         $v0, 0xD($s2)
    /* 5F624 8006EE24 000D0296 */  lhu        $v0, 0xD00($s0)
    /* 5F628 8006EE28 00000000 */  nop
    /* 5F62C 8006EE2C 01004230 */  andi       $v0, $v0, 0x1
    /* 5F630 8006EE30 40110200 */  sll        $v0, $v0, 5
    /* 5F634 8006EE34 1F004224 */  addiu      $v0, $v0, 0x1F
    /* 5F638 8006EE38 140042A2 */  sb         $v0, 0x14($s2)
    /* 5F63C 8006EE3C 000D0296 */  lhu        $v0, 0xD00($s0)
    /* 5F640 8006EE40 00000000 */  nop
    /* 5F644 8006EE44 42100200 */  srl        $v0, $v0, 1
    /* 5F648 8006EE48 40110200 */  sll        $v0, $v0, 5
    /* 5F64C 8006EE4C 40004224 */  addiu      $v0, $v0, 0x40
    /* 5F650 8006EE50 150042A2 */  sb         $v0, 0x15($s2)
    /* 5F654 8006EE54 000D0296 */  lhu        $v0, 0xD00($s0)
    /* 5F658 8006EE58 00000000 */  nop
    /* 5F65C 8006EE5C 01004230 */  andi       $v0, $v0, 0x1
    /* 5F660 8006EE60 40110200 */  sll        $v0, $v0, 5
    /* 5F664 8006EE64 1C0042A2 */  sb         $v0, 0x1C($s2)
    /* 5F668 8006EE68 000D0296 */  lhu        $v0, 0xD00($s0)
    /* 5F66C 8006EE6C 21880000 */  addu       $s1, $zero, $zero
    /* 5F670 8006EE70 42100200 */  srl        $v0, $v0, 1
    /* 5F674 8006EE74 40110200 */  sll        $v0, $v0, 5
    /* 5F678 8006EE78 5F004224 */  addiu      $v0, $v0, 0x5F
    /* 5F67C 8006EE7C 1D0042A2 */  sb         $v0, 0x1D($s2)
    /* 5F680 8006EE80 000D0296 */  lhu        $v0, 0xD00($s0)
    /* 5F684 8006EE84 38088626 */  addiu      $a2, $s4, 0x838
    /* 5F688 8006EE88 01004230 */  andi       $v0, $v0, 0x1
    /* 5F68C 8006EE8C 40110200 */  sll        $v0, $v0, 5
    /* 5F690 8006EE90 1F004224 */  addiu      $v0, $v0, 0x1F
    /* 5F694 8006EE94 240042A2 */  sb         $v0, 0x24($s2)
    /* 5F698 8006EE98 000D0296 */  lhu        $v0, 0xD00($s0)
    /* 5F69C 8006EE9C 2128C003 */  addu       $a1, $fp, $zero
    /* 5F6A0 8006EEA0 42100200 */  srl        $v0, $v0, 1
    /* 5F6A4 8006EEA4 40110200 */  sll        $v0, $v0, 5
    /* 5F6A8 8006EEA8 5F004224 */  addiu      $v0, $v0, 0x5F
    /* 5F6AC 8006EEAC 250042A2 */  sb         $v0, 0x25($s2)
    /* 5F6B0 8006EEB0 B000B7A7 */  sh         $s7, 0xB0($sp)
    /* 5F6B4 8006EEB4 B200B7A7 */  sh         $s7, 0xB2($sp)
    /* 5F6B8 8006EEB8 B400A0A7 */  sh         $zero, 0xB4($sp)
    /* 5F6BC 8006EEBC B800B6A7 */  sh         $s6, 0xB8($sp)
    /* 5F6C0 8006EEC0 BA00B7A7 */  sh         $s7, 0xBA($sp)
    /* 5F6C4 8006EEC4 BC00A0A7 */  sh         $zero, 0xBC($sp)
    /* 5F6C8 8006EEC8 C000B7A7 */  sh         $s7, 0xC0($sp)
    /* 5F6CC 8006EECC C200B6A7 */  sh         $s6, 0xC2($sp)
    /* 5F6D0 8006EED0 C400A0A7 */  sh         $zero, 0xC4($sp)
    /* 5F6D4 8006EED4 C800B6A7 */  sh         $s6, 0xC8($sp)
    /* 5F6D8 8006EED8 CA00B6A7 */  sh         $s6, 0xCA($sp)
    /* 5F6DC 8006EEDC CC00A0A7 */  sh         $zero, 0xCC($sp)
  .L8006EEE0:
    /* 5F6E0 8006EEE0 8800A294 */  lhu        $v0, 0x88($a1)
    /* 5F6E4 8006EEE4 38088396 */  lhu        $v1, 0x838($s4)
    /* 5F6E8 8006EEE8 8800A424 */  addiu      $a0, $a1, 0x88
    /* 5F6EC 8006EEEC 21104300 */  addu       $v0, $v0, $v1
    /* 5F6F0 8006EEF0 8800A2A4 */  sh         $v0, 0x88($a1)
    /* 5F6F4 8006EEF4 02008294 */  lhu        $v0, 0x2($a0)
    /* 5F6F8 8006EEF8 0200C394 */  lhu        $v1, 0x2($a2)
    /* 5F6FC 8006EEFC 01003126 */  addiu      $s1, $s1, 0x1
    /* 5F700 8006EF00 21104300 */  addu       $v0, $v0, $v1
    /* 5F704 8006EF04 020082A4 */  sh         $v0, 0x2($a0)
    /* 5F708 8006EF08 04008294 */  lhu        $v0, 0x4($a0)
    /* 5F70C 8006EF0C 0400C394 */  lhu        $v1, 0x4($a2)
    /* 5F710 8006EF10 00000000 */  nop
    /* 5F714 8006EF14 21104300 */  addu       $v0, $v0, $v1
    /* 5F718 8006EF18 040082A4 */  sh         $v0, 0x4($a0)
    /* 5F71C 8006EF1C 0400222A */  slti       $v0, $s1, 0x4
    /* 5F720 8006EF20 EFFF4014 */  bnez       $v0, .L8006EEE0
    /* 5F724 8006EF24 0800A524 */   addiu     $a1, $a1, 0x8
    /* 5F728 8006EF28 B000A427 */  addiu      $a0, $sp, 0xB0
    /* 5F72C 8006EF2C B800A527 */  addiu      $a1, $sp, 0xB8
    /* 5F730 8006EF30 C000A627 */  addiu      $a2, $sp, 0xC0
    /* 5F734 8006EF34 C800A727 */  addiu      $a3, $sp, 0xC8
    /* 5F738 8006EF38 08004226 */  addiu      $v0, $s2, 0x8
    /* 5F73C 8006EF3C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5F740 8006EF40 10004226 */  addiu      $v0, $s2, 0x10
    /* 5F744 8006EF44 1400A2AF */  sw         $v0, 0x14($sp)
    /* 5F748 8006EF48 18004226 */  addiu      $v0, $s2, 0x18
    /* 5F74C 8006EF4C 1800A2AF */  sw         $v0, 0x18($sp)
    /* 5F750 8006EF50 20004226 */  addiu      $v0, $s2, 0x20
    /* 5F754 8006EF54 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 5F758 8006EF58 D400A227 */  addiu      $v0, $sp, 0xD4
    /* 5F75C 8006EF5C 2000A2AF */  sw         $v0, 0x20($sp)
    /* 5F760 8006EF60 D000A227 */  addiu      $v0, $sp, 0xD0
    /* 5F764 8006EF64 AC1E020C */  jal        func_80087AB0
    /* 5F768 8006EF68 2400A2AF */   sw        $v0, 0x24($sp)
    /* 5F76C 8006EF6C 21304000 */  addu       $a2, $v0, $zero
    /* 5F770 8006EF70 0A00C004 */  bltz       $a2, .L8006EF9C
    /* 5F774 8006EF74 38088426 */   addiu     $a0, $s4, 0x838
    /* 5F778 8006EF78 D000A28F */  lw         $v0, 0xD0($sp)
    /* 5F77C 8006EF7C 00000000 */  nop
    /* 5F780 8006EF80 05004004 */  bltz       $v0, .L8006EF98
    /* 5F784 8006EF84 21204002 */   addu      $a0, $s2, $zero
    /* 5F788 8006EF88 DC00A58F */  lw         $a1, 0xDC($sp)
    /* 5F78C 8006EF8C FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 5F790 8006EF90 986C010C */  jal        func_8005B260
    /* 5F794 8006EF94 01000724 */   addiu     $a3, $zero, 0x1
  .L8006EF98:
    /* 5F798 8006EF98 38088426 */  addiu      $a0, $s4, 0x838
  .L8006EF9C:
    /* 5F79C 8006EF9C 38088296 */  lhu        $v0, 0x838($s4)
    /* 5F7A0 8006EFA0 380A8396 */  lhu        $v1, 0xA38($s4)
    /* 5F7A4 8006EFA4 380A8526 */  addiu      $a1, $s4, 0xA38
    /* 5F7A8 8006EFA8 21104300 */  addu       $v0, $v0, $v1
    /* 5F7AC 8006EFAC 380882A6 */  sh         $v0, 0x838($s4)
    /* 5F7B0 8006EFB0 02008294 */  lhu        $v0, 0x2($a0)
    /* 5F7B4 8006EFB4 0200A394 */  lhu        $v1, 0x2($a1)
    /* 5F7B8 8006EFB8 00000000 */  nop
    /* 5F7BC 8006EFBC 21104300 */  addu       $v0, $v0, $v1
    /* 5F7C0 8006EFC0 020082A4 */  sh         $v0, 0x2($a0)
    /* 5F7C4 8006EFC4 04008294 */  lhu        $v0, 0x4($a0)
    /* 5F7C8 8006EFC8 0400A394 */  lhu        $v1, 0x4($a1)
    /* 5F7CC 8006EFCC 00000000 */  nop
    /* 5F7D0 8006EFD0 21104300 */  addu       $v0, $v0, $v1
    /* 5F7D4 8006EFD4 040082A4 */  sh         $v0, 0x4($a0)
    /* 5F7D8 8006EFD8 000D0496 */  lhu        $a0, 0xD00($s0)
    /* 5F7DC 8006EFDC 00000000 */  nop
    /* 5F7E0 8006EFE0 01008324 */  addiu      $v1, $a0, 0x1
    /* 5F7E4 8006EFE4 02006104 */  bgez       $v1, .L8006EFF0
    /* 5F7E8 8006EFE8 21106000 */   addu      $v0, $v1, $zero
    /* 5F7EC 8006EFEC 04008224 */  addiu      $v0, $a0, 0x4
  .L8006EFF0:
    /* 5F7F0 8006EFF0 83100200 */  sra        $v0, $v0, 2
    /* 5F7F4 8006EFF4 80100200 */  sll        $v0, $v0, 2
    /* 5F7F8 8006EFF8 23106200 */  subu       $v0, $v1, $v0
    /* 5F7FC 8006EFFC 000D02A6 */  sh         $v0, 0xD00($s0)
    /* 5F800 8006F000 02001026 */  addiu      $s0, $s0, 0x2
    /* 5F804 8006F004 3A0A8296 */  lhu        $v0, 0xA3A($s4)
    /* 5F808 8006F008 0100B526 */  addiu      $s5, $s5, 0x1
    /* 5F80C 8006F00C 02004224 */  addiu      $v0, $v0, 0x2
    /* 5F810 8006F010 3A0A82A6 */  sh         $v0, 0xA3A($s4)
    /* 5F814 8006F014 4000A22A */  slti       $v0, $s5, 0x40
    /* 5F818 8006F018 6EFF4014 */  bnez       $v0, .L8006EDD4
    /* 5F81C 8006F01C 08009426 */   addiu     $s4, $s4, 0x8
    /* 5F820 8006F020 220E6392 */  lbu        $v1, 0xE22($s3)
    /* 5F824 8006F024 00000000 */  nop
    /* 5F828 8006F028 1000622C */  sltiu      $v0, $v1, 0x10
    /* 5F82C 8006F02C 03004014 */  bnez       $v0, .L8006F03C
    /* 5F830 8006F030 F1FF6224 */   addiu     $v0, $v1, -0xF
    /* 5F834 8006F034 10BC0108 */  j          .L8006F040
    /* 5F838 8006F038 220E62A2 */   sb        $v0, 0xE22($s3)
  .L8006F03C:
    /* 5F83C 8006F03C 220E60A2 */  sb         $zero, 0xE22($s3)
  .L8006F040:
    /* 5F840 8006F040 230E6392 */  lbu        $v1, 0xE23($s3)
    /* 5F844 8006F044 00000000 */  nop
    /* 5F848 8006F048 1000622C */  sltiu      $v0, $v1, 0x10
    /* 5F84C 8006F04C 03004014 */  bnez       $v0, .L8006F05C
    /* 5F850 8006F050 F1FF6224 */   addiu     $v0, $v1, -0xF
    /* 5F854 8006F054 18BC0108 */  j          .L8006F060
    /* 5F858 8006F058 230E62A2 */   sb        $v0, 0xE23($s3)
  .L8006F05C:
    /* 5F85C 8006F05C 230E60A2 */  sb         $zero, 0xE23($s3)
  .L8006F060:
    /* 5F860 8006F060 240E6392 */  lbu        $v1, 0xE24($s3)
    /* 5F864 8006F064 00000000 */  nop
    /* 5F868 8006F068 1000622C */  sltiu      $v0, $v1, 0x10
    /* 5F86C 8006F06C 03004014 */  bnez       $v0, .L8006F07C
    /* 5F870 8006F070 F1FF6224 */   addiu     $v0, $v1, -0xF
    /* 5F874 8006F074 20BC0108 */  j          .L8006F080
    /* 5F878 8006F078 240E62A2 */   sb        $v0, 0xE24($s3)
  .L8006F07C:
    /* 5F87C 8006F07C 240E60A2 */  sb         $zero, 0xE24($s3)
  .L8006F080:
    /* 5F880 8006F080 880D6282 */  lb         $v0, 0xD88($s3)
    /* 5F884 8006F084 00000000 */  nop
    /* 5F888 8006F088 06004004 */  bltz       $v0, .L8006F0A4
    /* 5F88C 8006F08C 05000524 */   addiu     $a1, $zero, 0x5
    /* 5F890 8006F090 880D6692 */  lbu        $a2, 0xD88($s3)
    /* 5F894 8006F094 D800A48F */  lw         $a0, 0xD8($sp)
    /* 5F898 8006F098 2138C000 */  addu       $a3, $a2, $zero
    /* 5F89C 8006F09C 2FBC0108 */  j          .L8006F0BC
    /* 5F8A0 8006F0A0 1000A6AF */   sw        $a2, 0x10($sp)
  .L8006F0A4:
    /* 5F8A4 8006F0A4 80000224 */  addiu      $v0, $zero, 0x80
    /* 5F8A8 8006F0A8 21280000 */  addu       $a1, $zero, $zero
    /* 5F8AC 8006F0AC 21304000 */  addu       $a2, $v0, $zero
    /* 5F8B0 8006F0B0 D800A48F */  lw         $a0, 0xD8($sp)
    /* 5F8B4 8006F0B4 21384000 */  addu       $a3, $v0, $zero
    /* 5F8B8 8006F0B8 1000A2AF */  sw         $v0, 0x10($sp)
  .L8006F0BC:
    /* 5F8BC 8006F0BC 6465010C */  jal        func_80059590
    /* 5F8C0 8006F0C0 00000000 */   nop
    /* 5F8C4 8006F0C4 840D6296 */  lhu        $v0, 0xD84($s3)
    /* 5F8C8 8006F0C8 00000000 */  nop
    /* 5F8CC 8006F0CC 0C004010 */  beqz       $v0, .L8006F100
    /* 5F8D0 8006F0D0 00000000 */   nop
    /* 5F8D4 8006F0D4 880D6392 */  lbu        $v1, 0xD88($s3)
    /* 5F8D8 8006F0D8 00000000 */  nop
    /* 5F8DC 8006F0DC 7C00622C */  sltiu      $v0, $v1, 0x7C
    /* 5F8E0 8006F0E0 03004010 */  beqz       $v0, .L8006F0F0
    /* 5F8E4 8006F0E4 04006224 */   addiu     $v0, $v1, 0x4
    /* 5F8E8 8006F0E8 40BC0108 */  j          .L8006F100
    /* 5F8EC 8006F0EC 880D62A2 */   sb        $v0, 0xD88($s3)
  .L8006F0F0:
    /* 5F8F0 8006F0F0 80000224 */  addiu      $v0, $zero, 0x80
    /* 5F8F4 8006F0F4 880D62A2 */  sb         $v0, 0xD88($s3)
    /* 5F8F8 8006F0F8 02000224 */  addiu      $v0, $zero, 0x2
    /* 5F8FC 8006F0FC 840D62A6 */  sh         $v0, 0xD84($s3)
  .L8006F100:
    /* 5F900 8006F100 0400628E */  lw         $v0, 0x4($s3)
    /* 5F904 8006F104 00000000 */  nop
    /* 5F908 8006F108 01004224 */  addiu      $v0, $v0, 0x1
    /* 5F90C 8006F10C 9D1C020C */  jal        func_80087274
    /* 5F910 8006F110 040062AE */   sw        $v0, 0x4($s3)
    /* 5F914 8006F114 200E628E */  lw         $v0, 0xE20($s3)
    /* 5F918 8006F118 FFFF033C */  lui        $v1, (0xFFFF0000 >> 16)
    /* 5F91C 8006F11C 24104300 */  and        $v0, $v0, $v1
    /* 5F920 8006F120 18004014 */  bnez       $v0, .L8006F184
    /* 5F924 8006F124 21100000 */   addu      $v0, $zero, $zero
    /* 5F928 8006F128 240E6292 */  lbu        $v0, 0xE24($s3)
    /* 5F92C 8006F12C 00000000 */  nop
    /* 5F930 8006F130 14004014 */  bnez       $v0, .L8006F184
    /* 5F934 8006F134 21100000 */   addu      $v0, $zero, $zero
    /* 5F938 8006F138 A00D628E */  lw         $v0, 0xDA0($s3)
    /* 5F93C 8006F13C 00000000 */  nop
    /* 5F940 8006F140 24104300 */  and        $v0, $v0, $v1
    /* 5F944 8006F144 0F004014 */  bnez       $v0, .L8006F184
    /* 5F948 8006F148 21100000 */   addu      $v0, $zero, $zero
    /* 5F94C 8006F14C A40D6292 */  lbu        $v0, 0xDA4($s3)
    /* 5F950 8006F150 00000000 */  nop
    /* 5F954 8006F154 0B004014 */  bnez       $v0, .L8006F184
    /* 5F958 8006F158 21100000 */   addu      $v0, $zero, $zero
    /* 5F95C 8006F15C 9C0D628E */  lw         $v0, 0xD9C($s3)
    /* 5F960 8006F160 00000000 */  nop
    /* 5F964 8006F164 24104300 */  and        $v0, $v0, $v1
    /* 5F968 8006F168 06004014 */  bnez       $v0, .L8006F184
    /* 5F96C 8006F16C 21100000 */   addu      $v0, $zero, $zero
    /* 5F970 8006F170 A00D6392 */  lbu        $v1, 0xDA0($s3)
    /* 5F974 8006F174 00000000 */  nop
    /* 5F978 8006F178 02006010 */  beqz       $v1, .L8006F184
    /* 5F97C 8006F17C 02000224 */   addiu     $v0, $zero, 0x2
    /* 5F980 8006F180 21100000 */  addu       $v0, $zero, $zero
  .L8006F184:
    /* 5F984 8006F184 2401BF8F */  lw         $ra, 0x124($sp)
    /* 5F988 8006F188 2001BE8F */  lw         $fp, 0x120($sp)
    /* 5F98C 8006F18C 1C01B78F */  lw         $s7, 0x11C($sp)
    /* 5F990 8006F190 1801B68F */  lw         $s6, 0x118($sp)
    /* 5F994 8006F194 1401B58F */  lw         $s5, 0x114($sp)
    /* 5F998 8006F198 1001B48F */  lw         $s4, 0x110($sp)
    /* 5F99C 8006F19C 0C01B38F */  lw         $s3, 0x10C($sp)
    /* 5F9A0 8006F1A0 0801B28F */  lw         $s2, 0x108($sp)
    /* 5F9A4 8006F1A4 0401B18F */  lw         $s1, 0x104($sp)
    /* 5F9A8 8006F1A8 0001B08F */  lw         $s0, 0x100($sp)
    /* 5F9AC 8006F1AC 0800E003 */  jr         $ra
    /* 5F9B0 8006F1B0 2801BD27 */   addiu     $sp, $sp, 0x128
endlabel func_8006CD78
