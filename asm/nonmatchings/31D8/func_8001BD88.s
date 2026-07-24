nonmatching func_8001BD88, 0x14B8

glabel func_8001BD88
    /* C588 8001BD88 CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* C58C 8001BD8C C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* C590 8001BD90 3800BFAF */  sw         $ra, 0x38($sp)
    /* C594 8001BD94 3400B5AF */  sw         $s5, 0x34($sp)
    /* C598 8001BD98 3000B4AF */  sw         $s4, 0x30($sp)
    /* C59C 8001BD9C 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* C5A0 8001BDA0 2800B2AF */  sw         $s2, 0x28($sp)
    /* C5A4 8001BDA4 2400B1AF */  sw         $s1, 0x24($sp)
    /* C5A8 8001BDA8 2000B0AF */  sw         $s0, 0x20($sp)
    /* C5AC 8001BDAC C0100300 */  sll        $v0, $v1, 3
    /* C5B0 8001BDB0 23104300 */  subu       $v0, $v0, $v1
    /* C5B4 8001BDB4 00110200 */  sll        $v0, $v0, 4
    /* C5B8 8001BDB8 0F80033C */  lui        $v1, %hi(D_800E9F10)
    /* C5BC 8001BDBC 109F7024 */  addiu      $s0, $v1, %lo(D_800E9F10)
    /* C5C0 8001BDC0 32038397 */  lhu        $v1, %gp_rel(D_8009B23A)($gp)
    /* C5C4 8001BDC4 21905000 */  addu       $s2, $v0, $s0
    /* C5C8 8001BDC8 00806230 */  andi       $v0, $v1, 0x8000
    /* C5CC 8001BDCC 41004014 */  bnez       $v0, .L8001BED4
    /* C5D0 8001BDD0 00806234 */   ori       $v0, $v1, 0x8000
    /* C5D4 8001BDD4 320382A7 */  sh         $v0, %gp_rel(D_8009B23A)($gp)
    /* C5D8 8001BDD8 06000524 */  addiu      $a1, $zero, 0x6
    /* C5DC 8001BDDC 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* C5E0 8001BDE0 F09E4224 */  addiu      $v0, $v0, %lo(D_800E9EF0)
    /* C5E4 8001BDE4 18004224 */  addiu      $v0, $v0, 0x18
  .L8001BDE8:
    /* C5E8 8001BDE8 000040AC */  sw         $zero, 0x0($v0)
    /* C5EC 8001BDEC FFFFA524 */  addiu      $a1, $a1, -0x1
    /* C5F0 8001BDF0 FDFFA104 */  bgez       $a1, .L8001BDE8
    /* C5F4 8001BDF4 FCFF4224 */   addiu     $v0, $v0, -0x4
    /* C5F8 8001BDF8 840280AF */  sw         $zero, %gp_rel(D_8009B18C)($gp)
    /* C5FC 8001BDFC 800280AF */  sw         $zero, %gp_rel(D_8009B188)($gp)
    /* C600 8001BE00 AC0292AF */  sw         $s2, %gp_rel(D_8009B1B4)($gp)
    /* C604 8001BE04 5A0280A7 */  sh         $zero, %gp_rel(D_8009B162)($gp)
    /* C608 8001BE08 0E0040A2 */  sb         $zero, 0xE($s2)
    /* C60C 8001BE0C 0B00010C */  jal        func_8004002C
    /* C610 8001BE10 150040A2 */   sb        $zero, 0x15($s2)
    /* C614 8001BE14 21204000 */  addu       $a0, $v0, $zero
    /* C618 8001BE18 2B00010C */  jal        func_800400AC
    /* C61C 8001BE1C 02000524 */   addiu     $a1, $zero, 0x2
    /* C620 8001BE20 21984000 */  addu       $s3, $v0, $zero
    /* C624 8001BE24 21206002 */  addu       $a0, $s3, $zero
    /* C628 8001BE28 03000524 */  addiu      $a1, $zero, 0x3
    /* C62C 8001BE2C 21300000 */  addu       $a2, $zero, $zero
    /* C630 8001BE30 02000724 */  addiu      $a3, $zero, 0x2
    /* C634 8001BE34 0B000224 */  addiu      $v0, $zero, 0xB
    /* C638 8001BE38 1000A2AF */  sw         $v0, 0x10($sp)
    /* C63C 8001BE3C 0C020224 */  addiu      $v0, $zero, 0x20C
    /* C640 8001BE40 1A01010C */  jal        func_80040468
    /* C644 8001BE44 1400A2AF */   sw        $v0, 0x14($sp)
    /* C648 8001BE48 08006296 */  lhu        $v0, 0x8($s3)
    /* C64C 8001BE4C 21206002 */  addu       $a0, $s3, $zero
    /* C650 8001BE50 28004234 */  ori        $v0, $v0, 0x28
    /* C654 8001BE54 460A010C */  jal        func_80042918
    /* C658 8001BE58 080062A6 */   sh        $v0, 0x8($s3)
    /* C65C 8001BE5C 21206002 */  addu       $a0, $s3, $zero
    /* C660 8001BE60 3B0A010C */  jal        func_800428EC
    /* C664 8001BE64 0A000524 */   addiu     $a1, $zero, 0xA
    /* C668 8001BE68 21204002 */  addu       $a0, $s2, $zero
    /* C66C 8001BE6C E06D000C */  jal        func_8001B780
    /* C670 8001BE70 040053AE */   sw        $s3, 0x4($s2)
    /* C674 8001BE74 0980043C */  lui        $a0, %hi(D_800907CC)
    /* C678 8001BE78 CC078424 */  addiu      $a0, $a0, %lo(D_800907CC)
    /* C67C 8001BE7C CD028593 */  lbu        $a1, %gp_rel(D_8009B1D5)($gp)
    /* C680 8001BE80 0E004282 */  lb         $v0, 0xE($s2)
    /* C684 8001BE84 80180500 */  sll        $v1, $a1, 2
    /* C688 8001BE88 21186500 */  addu       $v1, $v1, $a1
    /* C68C 8001BE8C 21104300 */  addu       $v0, $v0, $v1
    /* C690 8001BE90 21104400 */  addu       $v0, $v0, $a0
    /* C694 8001BE94 00004590 */  lbu        $a1, 0x0($v0)
    /* C698 8001BE98 518C000C */  jal        func_80023144
    /* C69C 8001BE9C 21204002 */   addu      $a0, $s2, $zero
    /* C6A0 8001BEA0 01000224 */  addiu      $v0, $zero, 0x1
    /* C6A4 8001BEA4 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* C6A8 8001BEA8 CD028293 */  lbu        $v0, %gp_rel(D_8009B1D5)($gp)
    /* C6AC 8001BEAC 0A80033C */  lui        $v1, %hi(D_8009B360)
    /* C6B0 8001BEB0 60B36324 */  addiu      $v1, $v1, %lo(D_8009B360)
    /* C6B4 8001BEB4 21104300 */  addu       $v0, $v0, $v1
    /* C6B8 8001BEB8 00004280 */  lb         $v0, 0x0($v0)
    /* C6BC 8001BEBC 00000000 */  nop
    /* C6C0 8001BEC0 D6044004 */  bltz       $v0, .L8001D21C
    /* C6C4 8001BEC4 02000224 */   addiu     $v0, $zero, 0x2
    /* C6C8 8001BEC8 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* C6CC 8001BECC 87740008 */  j          .L8001D21C
    /* C6D0 8001BED0 00000000 */   nop
  .L8001BED4:
    /* C6D4 8001BED4 00406230 */  andi       $v0, $v1, 0x4000
    /* C6D8 8001BED8 12004010 */  beqz       $v0, .L8001BF24
    /* C6DC 8001BEDC 00000000 */   nop
    /* C6E0 8001BEE0 AC02848F */  lw         $a0, %gp_rel(D_8009B1B4)($gp)
    /* C6E4 8001BEE4 2C90000C */  jal        func_800240B0
    /* C6E8 8001BEE8 00000000 */   nop
    /* C6EC 8001BEEC CC028293 */  lbu        $v0, %gp_rel(D_8009B1D4)($gp)
    /* C6F0 8001BEF0 00000000 */  nop
    /* C6F4 8001BEF4 C9044014 */  bnez       $v0, .L8001D21C
    /* C6F8 8001BEF8 00000000 */   nop
    /* C6FC 8001BEFC CD028293 */  lbu        $v0, %gp_rel(D_8009B1D5)($gp)
    /* C700 8001BF00 00000000 */  nop
    /* C704 8001BF04 C0180200 */  sll        $v1, $v0, 3
    /* C708 8001BF08 23186200 */  subu       $v1, $v1, $v0
    /* C70C 8001BF0C 00190300 */  sll        $v1, $v1, 4
    /* C710 8001BF10 32038297 */  lhu        $v0, %gp_rel(D_8009B23A)($gp)
    /* C714 8001BF14 21187000 */  addu       $v1, $v1, $s0
    /* C718 8001BF18 AC0283AF */  sw         $v1, %gp_rel(D_8009B1B4)($gp)
    /* C71C 8001BF1C 86740008 */  j          .L8001D218
    /* C720 8001BF20 FFBF4230 */   andi      $v0, $v0, 0xBFFF
  .L8001BF24:
    /* C724 8001BF24 0E004282 */  lb         $v0, 0xE($s2)
    /* C728 8001BF28 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* C72C 8001BF2C 40200200 */  sll        $a0, $v0, 1
    /* C730 8001BF30 21208200 */  addu       $a0, $a0, $v0
    /* C734 8001BF34 80200400 */  sll        $a0, $a0, 2
    /* C738 8001BF38 0F80023C */  lui        $v0, %hi(D_800EA030)
    /* C73C 8001BF3C 30A04224 */  addiu      $v0, $v0, %lo(D_800EA030)
    /* C740 8001BF40 21A08200 */  addu       $s4, $a0, $v0
    /* C744 8001BF44 0F006330 */  andi       $v1, $v1, 0xF
    /* C748 8001BF48 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* C74C 8001BF4C 0600622C */  sltiu      $v0, $v1, 0x6
    /* C750 8001BF50 B2044010 */  beqz       $v0, .L8001D21C
    /* C754 8001BF54 0180023C */   lui       $v0, %hi(jtbl_80010148)
    /* C758 8001BF58 48014224 */  addiu      $v0, $v0, %lo(jtbl_80010148)
    /* C75C 8001BF5C 80180300 */  sll        $v1, $v1, 2
    /* C760 8001BF60 21186200 */  addu       $v1, $v1, $v0
    /* C764 8001BF64 0000628C */  lw         $v0, 0x0($v1)
    /* C768 8001BF68 00000000 */  nop
    /* C76C 8001BF6C 08004000 */  jr         $v0
    /* C770 8001BF70 00000000 */   nop
  jlabel .L8001BF74
    /* C774 8001BF74 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* C778 8001BF78 00000000 */  nop
    /* C77C 8001BF7C 80006230 */  andi       $v0, $v1, 0x80
    /* C780 8001BF80 03004014 */  bnez       $v0, .L8001BF90
    /* C784 8001BF84 80006234 */   ori       $v0, $v1, 0x80
    /* C788 8001BF88 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* C78C 8001BF8C 040380A7 */  sh         $zero, %gp_rel(D_8009B20C)($gp)
  .L8001BF90:
    /* C790 8001BF90 04038397 */  lhu        $v1, %gp_rel(D_8009B20C)($gp)
    /* C794 8001BF94 01001024 */  addiu      $s0, $zero, 0x1
    /* C798 8001BF98 0F006430 */  andi       $a0, $v1, 0xF
    /* C79C 8001BF9C 28009010 */  beq        $a0, $s0, .L8001C040
    /* C7A0 8001BFA0 02008228 */   slti      $v0, $a0, 0x2
    /* C7A4 8001BFA4 05004010 */  beqz       $v0, .L8001BFBC
    /* C7A8 8001BFA8 00000000 */   nop
    /* C7AC 8001BFAC 0A008010 */  beqz       $a0, .L8001BFD8
    /* C7B0 8001BFB0 00806230 */   andi      $v0, $v1, 0x8000
    /* C7B4 8001BFB4 87740008 */  j          .L8001D21C
    /* C7B8 8001BFB8 00000000 */   nop
  .L8001BFBC:
    /* C7BC 8001BFBC 02001024 */  addiu      $s0, $zero, 0x2
    /* C7C0 8001BFC0 7B009010 */  beq        $a0, $s0, .L8001C1B0
    /* C7C4 8001BFC4 03000224 */   addiu     $v0, $zero, 0x3
    /* C7C8 8001BFC8 2B018210 */  beq        $a0, $v0, .L8001C478
    /* C7CC 8001BFCC 00000000 */   nop
    /* C7D0 8001BFD0 87740008 */  j          .L8001D21C
    /* C7D4 8001BFD4 00000000 */   nop
  .L8001BFD8:
    /* C7D8 8001BFD8 09004014 */  bnez       $v0, .L8001C000
    /* C7DC 8001BFDC 00806234 */   ori       $v0, $v1, 0x8000
    /* C7E0 8001BFE0 040382A7 */  sh         $v0, %gp_rel(D_8009B20C)($gp)
    /* C7E4 8001BFE4 88A0000C */  jal        func_80028220
    /* C7E8 8001BFE8 00000000 */   nop
    /* C7EC 8001BFEC 1B80043C */  lui        $a0, %hi(D_801A8000)
    /* C7F0 8001BFF0 76C1010C */  jal        func_800705D8
    /* C7F4 8001BFF4 00808424 */   addiu     $a0, $a0, %lo(D_801A8000)
    /* C7F8 8001BFF8 87740008 */  j          .L8001D21C
    /* C7FC 8001BFFC 00000000 */   nop
  .L8001C000:
    /* C800 8001C000 94C1010C */  jal        func_80070650
    /* C804 8001C004 00000000 */   nop
    /* C808 8001C008 84044010 */  beqz       $v0, .L8001D21C
    /* C80C 8001C00C 0F80023C */   lui       $v0, %hi(D_800EAE89)
    /* C810 8001C010 89AE4390 */  lbu        $v1, %lo(D_800EAE89)($v0)
    /* C814 8001C014 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* C818 8001C018 DA0282A3 */  sb         $v0, %gp_rel(D_8009B1E2)($gp)
    /* C81C 8001C01C 960280A7 */  sh         $zero, %gp_rel(D_8009B19E)($gp)
    /* C820 8001C020 02006010 */  beqz       $v1, .L8001C02C
    /* C824 8001C024 00000000 */   nop
    /* C828 8001C028 960290A7 */  sh         $s0, %gp_rel(D_8009B19E)($gp)
  .L8001C02C:
    /* C82C 8001C02C 040390A7 */  sh         $s0, %gp_rel(D_8009B20C)($gp)
    /* C830 8001C030 BC6E000C */  jal        func_8001BAF0
    /* C834 8001C034 00000000 */   nop
    /* C838 8001C038 87740008 */  j          .L8001D21C
    /* C83C 8001C03C 00000000 */   nop
  .L8001C040:
    /* C840 8001C040 00806230 */  andi       $v0, $v1, 0x8000
    /* C844 8001C044 26004014 */  bnez       $v0, .L8001C0E0
    /* C848 8001C048 00806334 */   ori       $v1, $v1, 0x8000
    /* C84C 8001C04C 040383A7 */  sh         $v1, %gp_rel(D_8009B20C)($gp)
    /* C850 8001C050 0F80033C */  lui        $v1, %hi(D_800EAE88)
    /* C854 8001C054 DA028293 */  lbu        $v0, %gp_rel(D_8009B1E2)($gp)
    /* C858 8001C058 88AE6324 */  addiu      $v1, $v1, %lo(D_800EAE88)
    /* C85C 8001C05C 01004224 */  addiu      $v0, $v0, 0x1
    /* C860 8001C060 DA0282A3 */  sb         $v0, %gp_rel(D_8009B1E2)($gp)
    /* C864 8001C064 00160200 */  sll        $v0, $v0, 24
    /* C868 8001C068 03160200 */  sra        $v0, $v0, 24
    /* C86C 8001C06C 21104300 */  addu       $v0, $v0, $v1
    /* C870 8001C070 00005090 */  lbu        $s0, 0x0($v0)
    /* C874 8001C074 00000000 */  nop
    /* C878 8001C078 0F000016 */  bnez       $s0, .L8001C0B8
    /* C87C 8001C07C 0B00022A */   slti      $v0, $s0, 0xB
    /* C880 8001C080 2E6E000C */  jal        func_8001B8B8
    /* C884 8001C084 21204002 */   addu      $a0, $s2, $zero
    /* C888 8001C088 96028297 */  lhu        $v0, %gp_rel(D_8009B19E)($gp)
    /* C88C 8001C08C 02000324 */  addiu      $v1, $zero, 0x2
    /* C890 8001C090 040383A7 */  sh         $v1, %gp_rel(D_8009B20C)($gp)
    /* C894 8001C094 01004230 */  andi       $v0, $v0, 0x1
    /* C898 8001C098 960282A7 */  sh         $v0, %gp_rel(D_8009B19E)($gp)
    /* C89C 8001C09C 02004010 */  beqz       $v0, .L8001C0A8
    /* C8A0 8001C0A0 03000224 */   addiu     $v0, $zero, 0x3
    /* C8A4 8001C0A4 040382A7 */  sh         $v0, %gp_rel(D_8009B20C)($gp)
  .L8001C0A8:
    /* C8A8 8001C0A8 B8FF000C */  jal        func_8003FEE0
    /* C8AC 8001C0AC 07000424 */   addiu     $a0, $zero, 0x7
    /* C8B0 8001C0B0 87740008 */  j          .L8001D21C
    /* C8B4 8001C0B4 00000000 */   nop
  .L8001C0B8:
    /* C8B8 8001C0B8 05004010 */  beqz       $v0, .L8001C0D0
    /* C8BC 8001C0BC 0180043C */   lui       $a0, %hi(D_80010060)
    /* C8C0 8001C0C0 1C3A020C */  jal        func_8008E870
    /* C8C4 8001C0C4 60008424 */   addiu     $a0, $a0, %lo(D_80010060)
    /* C8C8 8001C0C8 87740008 */  j          .L8001D21C
    /* C8CC 8001C0CC 00000000 */   nop
  .L8001C0D0:
    /* C8D0 8001C0D0 F5FF0226 */  addiu      $v0, $s0, -0xB
    /* C8D4 8001C0D4 020382A3 */  sb         $v0, %gp_rel(D_8009B20A)($gp)
    /* C8D8 8001C0D8 06000224 */  addiu      $v0, $zero, 0x6
    /* C8DC 8001C0DC DC0282A7 */  sh         $v0, %gp_rel(D_8009B1E4)($gp)
  .L8001C0E0:
    /* C8E0 8001C0E0 DC028297 */  lhu        $v0, %gp_rel(D_8009B1E4)($gp)
    /* C8E4 8001C0E4 00000000 */  nop
    /* C8E8 8001C0E8 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* C8EC 8001C0EC DC0282A7 */  sh         $v0, %gp_rel(D_8009B1E4)($gp)
    /* C8F0 8001C0F0 00140200 */  sll        $v0, $v0, 16
    /* C8F4 8001C0F4 4904401C */  bgtz       $v0, .L8001D21C
    /* C8F8 8001C0F8 06000224 */   addiu     $v0, $zero, 0x6
    /* C8FC 8001C0FC DC0282A7 */  sh         $v0, %gp_rel(D_8009B1E4)($gp)
    /* C900 8001C100 0E004382 */  lb         $v1, 0xE($s2)
    /* C904 8001C104 02038283 */  lb         $v0, %gp_rel(D_8009B20A)($gp)
    /* C908 8001C108 00000000 */  nop
    /* C90C 8001C10C 1B006210 */  beq        $v1, $v0, .L8001C17C
    /* C910 8001C110 00000000 */   nop
    /* C914 8001C114 B8FF000C */  jal        func_8003FEE0
    /* C918 8001C118 06000424 */   addiu     $a0, $zero, 0x6
    /* C91C 8001C11C 0E004382 */  lb         $v1, 0xE($s2)
    /* C920 8001C120 02038283 */  lb         $v0, %gp_rel(D_8009B20A)($gp)
    /* C924 8001C124 00000000 */  nop
    /* C928 8001C128 2A104300 */  slt        $v0, $v0, $v1
    /* C92C 8001C12C 0E004392 */  lbu        $v1, 0xE($s2)
    /* C930 8001C130 02004014 */  bnez       $v0, .L8001C13C
    /* C934 8001C134 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* C938 8001C138 01006224 */  addiu      $v0, $v1, 0x1
  .L8001C13C:
    /* C93C 8001C13C 0E0042A2 */  sb         $v0, 0xE($s2)
    /* C940 8001C140 E06D000C */  jal        func_8001B780
    /* C944 8001C144 21204002 */   addu      $a0, $s2, $zero
    /* C948 8001C148 0980043C */  lui        $a0, %hi(D_800907CC)
    /* C94C 8001C14C CC078424 */  addiu      $a0, $a0, %lo(D_800907CC)
    /* C950 8001C150 CD028593 */  lbu        $a1, %gp_rel(D_8009B1D5)($gp)
    /* C954 8001C154 0E004282 */  lb         $v0, 0xE($s2)
    /* C958 8001C158 80180500 */  sll        $v1, $a1, 2
    /* C95C 8001C15C 21186500 */  addu       $v1, $v1, $a1
    /* C960 8001C160 21104300 */  addu       $v0, $v0, $v1
    /* C964 8001C164 21104400 */  addu       $v0, $v0, $a0
    /* C968 8001C168 00004590 */  lbu        $a1, 0x0($v0)
    /* C96C 8001C16C 518C000C */  jal        func_80023144
    /* C970 8001C170 21204002 */   addu      $a0, $s2, $zero
    /* C974 8001C174 87740008 */  j          .L8001D21C
    /* C978 8001C178 00000000 */   nop
  .L8001C17C:
    /* C97C 8001C17C 96028297 */  lhu        $v0, %gp_rel(D_8009B19E)($gp)
    /* C980 8001C180 00000000 */  nop
    /* C984 8001C184 01004230 */  andi       $v0, $v0, 0x1
    /* C988 8001C188 03004010 */  beqz       $v0, .L8001C198
    /* C98C 8001C18C 00000000 */   nop
    /* C990 8001C190 EB6D000C */  jal        func_8001B7AC
    /* C994 8001C194 21204002 */   addu      $a0, $s2, $zero
  .L8001C198:
    /* C998 8001C198 04038297 */  lhu        $v0, %gp_rel(D_8009B20C)($gp)
    /* C99C 8001C19C 00000000 */  nop
    /* C9A0 8001C1A0 FF7F4230 */  andi       $v0, $v0, 0x7FFF
    /* C9A4 8001C1A4 040382A7 */  sh         $v0, %gp_rel(D_8009B20C)($gp)
    /* C9A8 8001C1A8 87740008 */  j          .L8001D21C
    /* C9AC 8001C1AC 00000000 */   nop
  .L8001C1B0:
    /* C9B0 8001C1B0 0000938E */  lw         $s3, 0x0($s4)
    /* C9B4 8001C1B4 00806230 */  andi       $v0, $v1, 0x8000
    /* C9B8 8001C1B8 3A004014 */  bnez       $v0, .L8001C2A4
    /* C9BC 8001C1BC 00406230 */   andi      $v0, $v1, 0x4000
    /* C9C0 8001C1C0 0400053C */  lui        $a1, (0x48000 >> 16)
    /* C9C4 8001C1C4 0080A534 */  ori        $a1, $a1, (0x48000 & 0xFFFF)
    /* C9C8 8001C1C8 00C06234 */  ori        $v0, $v1, 0xC000
    /* C9CC 8001C1CC 1680033C */  lui        $v1, %hi(D_8015C424)
    /* C9D0 8001C1D0 040382A7 */  sh         $v0, %gp_rel(D_8009B20C)($gp)
    /* C9D4 8001C1D4 6A006492 */  lbu        $a0, 0x6A($s3)
    /* C9D8 8001C1D8 24C46324 */  addiu      $v1, $v1, %lo(D_8015C424)
    /* C9DC 8001C1DC C0100400 */  sll        $v0, $a0, 3
    /* C9E0 8001C1E0 23104400 */  subu       $v0, $v0, $a0
    /* C9E4 8001C1E4 80100200 */  sll        $v0, $v0, 2
    /* C9E8 8001C1E8 21104300 */  addu       $v0, $v0, $v1
    /* C9EC 8001C1EC 21104500 */  addu       $v0, $v0, $a1
    /* C9F0 8001C1F0 1D80033C */  lui        $v1, %hi(D_801D4244)
    /* C9F4 8001C1F4 C0364484 */  lh         $a0, 0x36C0($v0)
    /* C9F8 8001C1F8 44426324 */  addiu      $v1, $v1, %lo(D_801D4244)
    /* C9FC 8001C1FC FFFF8224 */  addiu      $v0, $a0, -0x1
    /* CA00 8001C200 80100200 */  sll        $v0, $v0, 2
    /* CA04 8001C204 21104300 */  addu       $v0, $v0, $v1
    /* CA08 8001C208 0000428C */  lw         $v0, 0x0($v0)
    /* CA0C 8001C20C 00000000 */  nop
    /* CA10 8001C210 83160200 */  sra        $v0, $v0, 26
    /* CA14 8001C214 1F004230 */  andi       $v0, $v0, 0x1F
    /* CA18 8001C218 14004228 */  slti       $v0, $v0, 0x14
    /* CA1C 8001C21C 09004010 */  beqz       $v0, .L8001C244
    /* CA20 8001C220 0F80023C */   lui       $v0, %hi(D_800EAE90)
    /* CA24 8001C224 90AE4290 */  lbu        $v0, %lo(D_800EAE90)($v0)
    /* CA28 8001C228 00000000 */  nop
    /* CA2C 8001C22C 06004014 */  bnez       $v0, .L8001C248
    /* CA30 8001C230 21206002 */   addu      $a0, $s3, $zero
    /* CA34 8001C234 03000224 */  addiu      $v0, $zero, 0x3
    /* CA38 8001C238 040382A7 */  sh         $v0, %gp_rel(D_8009B20C)($gp)
    /* CA3C 8001C23C 87740008 */  j          .L8001D21C
    /* CA40 8001C240 00000000 */   nop
  .L8001C244:
    /* CA44 8001C244 21206002 */  addu       $a0, $s3, $zero
  .L8001C248:
    /* CA48 8001C248 86000224 */  addiu      $v0, $zero, 0x86
    /* CA4C 8001C24C 280082A4 */  sh         $v0, 0x28($a0)
    /* CA50 8001C250 5A000224 */  addiu      $v0, $zero, 0x5A
    /* CA54 8001C254 2A0082A4 */  sh         $v0, 0x2A($a0)
    /* CA58 8001C258 10000224 */  addiu      $v0, $zero, 0x10
    /* CA5C 8001C25C 2C0082A4 */  sh         $v0, 0x2C($a0)
    /* CA60 8001C260 01000224 */  addiu      $v0, $zero, 0x1
    /* CA64 8001C264 6C0082A0 */  sb         $v0, 0x6C($a0)
    /* CA68 8001C268 0280023C */  lui        $v0, %hi(func_8001EC70)
    /* CA6C 8001C26C 16008590 */  lbu        $a1, 0x16($a0)
    /* CA70 8001C270 70EC4224 */  addiu      $v0, $v0, %lo(func_8001EC70)
    /* CA74 8001C274 240082AC */  sw         $v0, 0x24($a0)
    /* CA78 8001C278 0400A524 */  addiu      $a1, $a1, 0x4
    /* CA7C 8001C27C 002E0500 */  sll        $a1, $a1, 24
    /* CA80 8001C280 3B0A010C */  jal        func_800428EC
    /* CA84 8001C284 032E0500 */   sra       $a1, $a1, 24
    /* CA88 8001C288 0400438E */  lw         $v1, 0x4($s2)
    /* CA8C 8001C28C 00000000 */  nop
    /* CA90 8001C290 08006294 */  lhu        $v0, 0x8($v1)
    /* CA94 8001C294 00000000 */  nop
    /* CA98 8001C298 BFFF4230 */  andi       $v0, $v0, 0xFFBF
    /* CA9C 8001C29C 87740008 */  j          .L8001D21C
    /* CAA0 8001C2A0 080062A4 */   sh        $v0, 0x8($v1)
  .L8001C2A4:
    /* CAA4 8001C2A4 2C004010 */  beqz       $v0, .L8001C358
    /* CAA8 8001C2A8 00206230 */   andi      $v0, $v1, 0x2000
    /* CAAC 8001C2AC D00A010C */  jal        func_80042B40
    /* CAB0 8001C2B0 01000424 */   addiu     $a0, $zero, 0x1
    /* CAB4 8001C2B4 D9034014 */  bnez       $v0, .L8001D21C
    /* CAB8 8001C2B8 00000000 */   nop
    /* CABC 8001C2BC 04038297 */  lhu        $v0, %gp_rel(D_8009B20C)($gp)
    /* CAC0 8001C2C0 00000000 */  nop
    /* CAC4 8001C2C4 FFBF4330 */  andi       $v1, $v0, 0xBFFF
    /* CAC8 8001C2C8 00104230 */  andi       $v0, $v0, 0x1000
    /* CACC 8001C2CC 040383A7 */  sh         $v1, %gp_rel(D_8009B20C)($gp)
    /* CAD0 8001C2D0 0F004010 */  beqz       $v0, .L8001C310
    /* CAD4 8001C2D4 21206002 */   addu      $a0, $s3, $zero
    /* CAD8 8001C2D8 16006592 */  lbu        $a1, 0x16($s3)
    /* CADC 8001C2DC 00000000 */  nop
    /* CAE0 8001C2E0 FCFFA524 */  addiu      $a1, $a1, -0x4
    /* CAE4 8001C2E4 002E0500 */  sll        $a1, $a1, 24
    /* CAE8 8001C2E8 3B0A010C */  jal        func_800428EC
    /* CAEC 8001C2EC 032E0500 */   sra       $a1, $a1, 24
    /* CAF0 8001C2F0 0400448E */  lw         $a0, 0x4($s2)
    /* CAF4 8001C2F4 00000000 */  nop
    /* CAF8 8001C2F8 08008294 */  lhu        $v0, 0x8($a0)
    /* CAFC 8001C2FC 03000324 */  addiu      $v1, $zero, 0x3
    /* CB00 8001C300 040383A7 */  sh         $v1, %gp_rel(D_8009B20C)($gp)
    /* CB04 8001C304 40004234 */  ori        $v0, $v0, 0x40
    /* CB08 8001C308 87740008 */  j          .L8001D21C
    /* CB0C 8001C30C 080082A4 */   sh        $v0, 0x8($a0)
  .L8001C310:
    /* CB10 8001C310 36006296 */  lhu        $v0, 0x36($s3)
    /* CB14 8001C314 38006396 */  lhu        $v1, 0x38($s3)
    /* CB18 8001C318 2C0062A6 */  sh         $v0, 0x2C($s3)
    /* CB1C 8001C31C 0F80023C */  lui        $v0, %hi(D_800EAE90)
    /* CB20 8001C320 2E0063A6 */  sh         $v1, 0x2E($s3)
    /* CB24 8001C324 90AE4290 */  lbu        $v0, %lo(D_800EAE90)($v0)
    /* CB28 8001C328 00000000 */  nop
    /* CB2C 8001C32C BB034010 */  beqz       $v0, .L8001D21C
    /* CB30 8001C330 00000000 */   nop
    /* CB34 8001C334 B8FF000C */  jal        func_8003FEE0
    /* CB38 8001C338 0B000424 */   addiu     $a0, $zero, 0xB
    /* CB3C 8001C33C 04038297 */  lhu        $v0, %gp_rel(D_8009B20C)($gp)
    /* CB40 8001C340 08006396 */  lhu        $v1, 0x8($s3)
    /* CB44 8001C344 00204234 */  ori        $v0, $v0, 0x2000
    /* CB48 8001C348 04006334 */  ori        $v1, $v1, 0x4
    /* CB4C 8001C34C 040382A7 */  sh         $v0, %gp_rel(D_8009B20C)($gp)
    /* CB50 8001C350 87740008 */  j          .L8001D21C
    /* CB54 8001C354 080063A6 */   sh        $v1, 0x8($s3)
  .L8001C358:
    /* CB58 8001C358 17004010 */  beqz       $v0, .L8001C3B8
    /* CB5C 8001C35C 0400053C */   lui       $a1, (0x48000 >> 16)
    /* CB60 8001C360 21006292 */  lbu        $v0, 0x21($s3)
    /* CB64 8001C364 00000000 */  nop
    /* CB68 8001C368 08004224 */  addiu      $v0, $v0, 0x8
    /* CB6C 8001C36C 210062A2 */  sb         $v0, 0x21($s3)
    /* CB70 8001C370 00160200 */  sll        $v0, $v0, 24
    /* CB74 8001C374 A9034104 */  bgez       $v0, .L8001D21C
    /* CB78 8001C378 80000224 */   addiu     $v0, $zero, 0x80
    /* CB7C 8001C37C 1A80033C */  lui        $v1, %hi(D_801A7AD8)
    /* CB80 8001C380 6A006492 */  lbu        $a0, 0x6A($s3)
    /* CB84 8001C384 D87A6324 */  addiu      $v1, $v1, %lo(D_801A7AD8)
    /* CB88 8001C388 210062A2 */  sb         $v0, 0x21($s3)
    /* CB8C 8001C38C C0100400 */  sll        $v0, $a0, 3
    /* CB90 8001C390 23104400 */  subu       $v0, $v0, $a0
    /* CB94 8001C394 80100200 */  sll        $v0, $v0, 2
    /* CB98 8001C398 21104300 */  addu       $v0, $v0, $v1
    /* CB9C 8001C39C 04038397 */  lhu        $v1, %gp_rel(D_8009B20C)($gp)
    /* CBA0 8001C3A0 16004494 */  lhu        $a0, 0x16($v0)
    /* CBA4 8001C3A4 FFDF6330 */  andi       $v1, $v1, 0xDFFF
    /* CBA8 8001C3A8 00108434 */  ori        $a0, $a0, 0x1000
    /* CBAC 8001C3AC 040383A7 */  sh         $v1, %gp_rel(D_8009B20C)($gp)
    /* CBB0 8001C3B0 87740008 */  j          .L8001D21C
    /* CBB4 8001C3B4 160044A4 */   sh        $a0, 0x16($v0)
  .L8001C3B8:
    /* CBB8 8001C3B8 0080A534 */  ori        $a1, $a1, (0x48000 & 0xFFFF)
    /* CBBC 8001C3BC 1680033C */  lui        $v1, %hi(D_8015C424)
    /* CBC0 8001C3C0 6A006492 */  lbu        $a0, 0x6A($s3)
    /* CBC4 8001C3C4 24C46324 */  addiu      $v1, $v1, %lo(D_8015C424)
    /* CBC8 8001C3C8 C0100400 */  sll        $v0, $a0, 3
    /* CBCC 8001C3CC 23104400 */  subu       $v0, $v0, $a0
    /* CBD0 8001C3D0 80100200 */  sll        $v0, $v0, 2
    /* CBD4 8001C3D4 21104300 */  addu       $v0, $v0, $v1
    /* CBD8 8001C3D8 21104500 */  addu       $v0, $v0, $a1
    /* CBDC 8001C3DC 1D80033C */  lui        $v1, %hi(D_801D4244)
    /* CBE0 8001C3E0 C0364484 */  lh         $a0, 0x36C0($v0)
    /* CBE4 8001C3E4 44426324 */  addiu      $v1, $v1, %lo(D_801D4244)
    /* CBE8 8001C3E8 FFFF8224 */  addiu      $v0, $a0, -0x1
    /* CBEC 8001C3EC 80100200 */  sll        $v0, $v0, 2
    /* CBF0 8001C3F0 21104300 */  addu       $v0, $v0, $v1
    /* CBF4 8001C3F4 0000428C */  lw         $v0, 0x0($v0)
    /* CBF8 8001C3F8 00000000 */  nop
    /* CBFC 8001C3FC 83160200 */  sra        $v0, $v0, 26
    /* CC00 8001C400 1F005030 */  andi       $s0, $v0, 0x1F
    /* CC04 8001C404 1400022A */  slti       $v0, $s0, 0x14
    /* CC08 8001C408 0F004014 */  bnez       $v0, .L8001C448
    /* CC0C 8001C40C 0280023C */   lui       $v0, %hi(func_8001EC70)
    /* CC10 8001C410 21006292 */  lbu        $v0, 0x21($s3)
    /* CC14 8001C414 00000000 */  nop
    /* CC18 8001C418 0B004014 */  bnez       $v0, .L8001C448
    /* CC1C 8001C41C 0280023C */   lui       $v0, %hi(func_8001EC70)
    /* CC20 8001C420 17000224 */  addiu      $v0, $zero, 0x17
    /* CC24 8001C424 07000212 */  beq        $s0, $v0, .L8001C444
    /* CC28 8001C428 15000224 */   addiu     $v0, $zero, 0x15
    /* CC2C 8001C42C 05000212 */  beq        $s0, $v0, .L8001C444
    /* CC30 8001C430 0F80023C */   lui       $v0, %hi(D_800E9EF0)
    /* CC34 8001C434 F09E53AC */  sw         $s3, %lo(D_800E9EF0)($v0)
    /* CC38 8001C438 C002828F */  lw         $v0, %gp_rel(D_8009B1C8)($gp)
    /* CC3C 8001C43C 64730008 */  j          .L8001CD90
    /* CC40 8001C440 00000000 */   nop
  .L8001C444:
    /* CC44 8001C444 0280023C */  lui        $v0, %hi(func_8001EC70)
  .L8001C448:
    /* CC48 8001C448 04038397 */  lhu        $v1, %gp_rel(D_8009B20C)($gp)
    /* CC4C 8001C44C 70EC4224 */  addiu      $v0, $v0, %lo(func_8001EC70)
    /* CC50 8001C450 240062AE */  sw         $v0, 0x24($s3)
    /* CC54 8001C454 00506334 */  ori        $v1, $v1, 0x5000
    /* CC58 8001C458 040383A7 */  sh         $v1, %gp_rel(D_8009B20C)($gp)
    /* CC5C 8001C45C 2C00638E */  lw         $v1, 0x2C($s3)
    /* CC60 8001C460 10000224 */  addiu      $v0, $zero, 0x10
    /* CC64 8001C464 2C0062A6 */  sh         $v0, 0x2C($s3)
    /* CC68 8001C468 01000224 */  addiu      $v0, $zero, 0x1
    /* CC6C 8001C46C 6C0062A2 */  sb         $v0, 0x6C($s3)
    /* CC70 8001C470 87740008 */  j          .L8001D21C
    /* CC74 8001C474 280063AE */   sw        $v1, 0x28($s3)
  .L8001C478:
    /* CC78 8001C478 5A028297 */  lhu        $v0, %gp_rel(D_8009B162)($gp)
    /* CC7C 8001C47C 00000000 */  nop
    /* CC80 8001C480 12004014 */  bnez       $v0, .L8001C4CC
    /* CC84 8001C484 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* CC88 8001C488 00806230 */  andi       $v0, $v1, 0x8000
    /* CC8C 8001C48C 12004014 */  bnez       $v0, .L8001C4D8
    /* CC90 8001C490 00C06234 */   ori       $v0, $v1, 0xC000
    /* CC94 8001C494 040382A7 */  sh         $v0, %gp_rel(D_8009B20C)($gp)
    /* CC98 8001C498 4E6E000C */  jal        func_8001B938
    /* CC9C 8001C49C 21204002 */   addu      $a0, $s2, $zero
    /* CCA0 8001C4A0 0F80023C */  lui        $v0, %hi(D_800EAE8E)
    /* CCA4 8001C4A4 8EAE4390 */  lbu        $v1, %lo(D_800EAE8E)($v0)
    /* CCA8 8001C4A8 00000000 */  nop
    /* CCAC 8001C4AC FAFF6224 */  addiu      $v0, $v1, -0x6
    /* CCB0 8001C4B0 020382A3 */  sb         $v0, %gp_rel(D_8009B20A)($gp)
    /* CCB4 8001C4B4 00160200 */  sll        $v0, $v0, 24
    /* CCB8 8001C4B8 04004104 */  bgez       $v0, .L8001C4CC
    /* CCBC 8001C4BC FFFF0224 */   addiu     $v0, $zero, -0x1
    /* CCC0 8001C4C0 FFFF6224 */  addiu      $v0, $v1, -0x1
    /* CCC4 8001C4C4 020382A3 */  sb         $v0, %gp_rel(D_8009B20A)($gp)
    /* CCC8 8001C4C8 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8001C4CC:
    /* CCCC 8001C4CC 580282A3 */  sb         $v0, %gp_rel(D_8009B160)($gp)
    /* CCD0 8001C4D0 87740008 */  j          .L8001D21C
    /* CCD4 8001C4D4 00000000 */   nop
  .L8001C4D8:
    /* CCD8 8001C4D8 AC02848F */  lw         $a0, %gp_rel(D_8009B1B4)($gp)
    /* CCDC 8001C4DC 58028583 */  lb         $a1, %gp_rel(D_8009B160)($gp)
    /* CCE0 8001C4E0 2290000C */  jal        func_80024088
    /* CCE4 8001C4E4 00000000 */   nop
    /* CCE8 8001C4E8 4C034014 */  bnez       $v0, .L8001D21C
    /* CCEC 8001C4EC 00000000 */   nop
    /* CCF0 8001C4F0 AC02848F */  lw         $a0, %gp_rel(D_8009B1B4)($gp)
    /* CCF4 8001C4F4 02038383 */  lb         $v1, %gp_rel(D_8009B20A)($gp)
    /* CCF8 8001C4F8 0F008280 */  lb         $v0, 0xF($a0)
    /* CCFC 8001C4FC 00000000 */  nop
    /* CD00 8001C500 9C024310 */  beq        $v0, $v1, .L8001CF74
    /* CD04 8001C504 00000000 */   nop
    /* CD08 8001C508 580280A3 */  sb         $zero, %gp_rel(D_8009B160)($gp)
    /* CD0C 8001C50C 0F008280 */  lb         $v0, 0xF($a0)
    /* CD10 8001C510 00000000 */  nop
    /* CD14 8001C514 2A106200 */  slt        $v0, $v1, $v0
    /* CD18 8001C518 40034010 */  beqz       $v0, .L8001D21C
    /* CD1C 8001C51C 00000000 */   nop
    /* CD20 8001C520 580290A3 */  sb         $s0, %gp_rel(D_8009B160)($gp)
    /* CD24 8001C524 87740008 */  j          .L8001D21C
    /* CD28 8001C528 00000000 */   nop
  jlabel .L8001C52C
    /* CD2C 8001C52C 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* CD30 8001C530 00000000 */  nop
    /* CD34 8001C534 80006230 */  andi       $v0, $v1, 0x80
    /* CD38 8001C538 0D004014 */  bnez       $v0, .L8001C570
    /* CD3C 8001C53C 80006234 */   ori       $v0, $v1, 0x80
    /* CD40 8001C540 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* CD44 8001C544 21280000 */  addu       $a1, $zero, $zero
    /* CD48 8001C548 8000043C */  lui        $a0, (0x808080 >> 16)
    /* CD4C 8001C54C 80808434 */  ori        $a0, $a0, (0x808080 & 0xFFFF)
    /* CD50 8001C550 0F80023C */  lui        $v0, %hi(D_800EA030)
    /* CD54 8001C554 30A04324 */  addiu      $v1, $v0, %lo(D_800EA030)
  .L8001C558:
    /* CD58 8001C558 0000628C */  lw         $v0, 0x0($v1)
    /* CD5C 8001C55C 0100A524 */  addiu      $a1, $a1, 0x1
    /* CD60 8001C560 0C0044AC */  sw         $a0, 0xC($v0)
    /* CD64 8001C564 0500A228 */  slti       $v0, $a1, 0x5
    /* CD68 8001C568 FBFF4014 */  bnez       $v0, .L8001C558
    /* CD6C 8001C56C 0C006324 */   addiu     $v1, $v1, 0xC
  .L8001C570:
    /* CD70 8001C570 526F000C */  jal        func_8001BD48
    /* CD74 8001C574 00000000 */   nop
    /* CD78 8001C578 28034014 */  bnez       $v0, .L8001D21C
    /* CD7C 8001C57C 00000000 */   nop
    /* CD80 8001C580 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* CD84 8001C584 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* CD88 8001C588 00000000 */  nop
    /* CD8C 8001C58C 10004230 */  andi       $v0, $v0, 0x10
    /* CD90 8001C590 1D004010 */  beqz       $v0, .L8001C608
    /* CD94 8001C594 0400063C */   lui       $a2, (0x48000 >> 16)
    /* CD98 8001C598 0080C634 */  ori        $a2, $a2, (0x48000 & 0xFFFF)
    /* CD9C 8001C59C 0980043C */  lui        $a0, %hi(D_800907CC)
    /* CDA0 8001C5A0 CC078424 */  addiu      $a0, $a0, %lo(D_800907CC)
    /* CDA4 8001C5A4 CD028593 */  lbu        $a1, %gp_rel(D_8009B1D5)($gp)
    /* CDA8 8001C5A8 0E004282 */  lb         $v0, 0xE($s2)
    /* CDAC 8001C5AC 80180500 */  sll        $v1, $a1, 2
    /* CDB0 8001C5B0 21186500 */  addu       $v1, $v1, $a1
    /* CDB4 8001C5B4 21104300 */  addu       $v0, $v0, $v1
    /* CDB8 8001C5B8 21104400 */  addu       $v0, $v0, $a0
    /* CDBC 8001C5BC 00004490 */  lbu        $a0, 0x0($v0)
    /* CDC0 8001C5C0 14000224 */  addiu      $v0, $zero, 0x14
    /* CDC4 8001C5C4 1680033C */  lui        $v1, %hi(D_8015C424)
    /* CDC8 8001C5C8 24C46324 */  addiu      $v1, $v1, %lo(D_8015C424)
    /* CDCC 8001C5CC 0A80013C */  lui        $at, %hi(D_8009B24B)
    /* CDD0 8001C5D0 4BB222A0 */  sb         $v0, %lo(D_8009B24B)($at)
    /* CDD4 8001C5D4 C0100400 */  sll        $v0, $a0, 3
    /* CDD8 8001C5D8 23104400 */  subu       $v0, $v0, $a0
    /* CDDC 8001C5DC 80100200 */  sll        $v0, $v0, 2
    /* CDE0 8001C5E0 21104300 */  addu       $v0, $v0, $v1
    /* CDE4 8001C5E4 21104600 */  addu       $v0, $v0, $a2
    /* CDE8 8001C5E8 C0364484 */  lh         $a0, 0x36C0($v0)
    /* CDEC 8001C5EC 02000224 */  addiu      $v0, $zero, 0x2
    /* CDF0 8001C5F0 0A80013C */  lui        $at, %hi(D_8009B254)
    /* CDF4 8001C5F4 54B222A0 */  sb         $v0, %lo(D_8009B254)($at)
    /* CDF8 8001C5F8 0A80013C */  lui        $at, %hi(D_8009B246)
    /* CDFC 8001C5FC 46B224A4 */  sh         $a0, %lo(D_8009B246)($at)
    /* CE00 8001C600 87740008 */  j          .L8001D21C
    /* CE04 8001C604 00000000 */   nop
  .L8001C608:
    /* CE08 8001C608 0A80023C */  lui        $v0, %hi(D_8009B394)
    /* CE0C 8001C60C 94B34294 */  lhu        $v0, %lo(D_8009B394)($v0)
    /* CE10 8001C610 00000000 */  nop
    /* CE14 8001C614 00A04230 */  andi       $v0, $v0, 0xA000
    /* CE18 8001C618 21004010 */  beqz       $v0, .L8001C6A0
    /* CE1C 8001C61C 00000000 */   nop
    /* CE20 8001C620 0A80023C */  lui        $v0, %hi(D_8009B394)
    /* CE24 8001C624 94B34294 */  lhu        $v0, %lo(D_8009B394)($v0)
    /* CE28 8001C628 0E005082 */  lb         $s0, 0xE($s2)
    /* CE2C 8001C62C 00204230 */  andi       $v0, $v0, 0x2000
    /* CE30 8001C630 07004010 */  beqz       $v0, .L8001C650
    /* CE34 8001C634 00000000 */   nop
    /* CE38 8001C638 01001026 */  addiu      $s0, $s0, 0x1
    /* CE3C 8001C63C 0500022A */  slti       $v0, $s0, 0x5
    /* CE40 8001C640 F6024010 */  beqz       $v0, .L8001D21C
    /* CE44 8001C644 21204002 */   addu      $a0, $s2, $zero
    /* CE48 8001C648 97710008 */  j          .L8001C65C
    /* CE4C 8001C64C 00000000 */   nop
  .L8001C650:
    /* CE50 8001C650 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* CE54 8001C654 F1020006 */  bltz       $s0, .L8001D21C
    /* CE58 8001C658 21204002 */   addu      $a0, $s2, $zero
  .L8001C65C:
    /* CE5C 8001C65C E06D000C */  jal        func_8001B780
    /* CE60 8001C660 0E0050A2 */   sb        $s0, 0xE($s2)
    /* CE64 8001C664 0980043C */  lui        $a0, %hi(D_800907CC)
    /* CE68 8001C668 CC078424 */  addiu      $a0, $a0, %lo(D_800907CC)
    /* CE6C 8001C66C CD028593 */  lbu        $a1, %gp_rel(D_8009B1D5)($gp)
    /* CE70 8001C670 0E004282 */  lb         $v0, 0xE($s2)
    /* CE74 8001C674 80180500 */  sll        $v1, $a1, 2
    /* CE78 8001C678 21186500 */  addu       $v1, $v1, $a1
    /* CE7C 8001C67C 21104300 */  addu       $v0, $v0, $v1
    /* CE80 8001C680 21104400 */  addu       $v0, $v0, $a0
    /* CE84 8001C684 00004590 */  lbu        $a1, 0x0($v0)
    /* CE88 8001C688 518C000C */  jal        func_80023144
    /* CE8C 8001C68C 21204002 */   addu      $a0, $s2, $zero
    /* CE90 8001C690 B8FF000C */  jal        func_8003FEE0
    /* CE94 8001C694 06000424 */   addiu     $a0, $zero, 0x6
    /* CE98 8001C698 87740008 */  j          .L8001D21C
    /* CE9C 8001C69C 00000000 */   nop
  .L8001C6A0:
    /* CEA0 8001C6A0 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* CEA4 8001C6A4 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* CEA8 8001C6A8 00000000 */  nop
    /* CEAC 8001C6AC FFFF4330 */  andi       $v1, $v0, 0xFFFF
    /* CEB0 8001C6B0 00100224 */  addiu      $v0, $zero, 0x1000
    /* CEB4 8001C6B4 0E006214 */  bne        $v1, $v0, .L8001C6F0
    /* CEB8 8001C6B8 00000000 */   nop
    /* CEBC 8001C6BC 0A80023C */  lui        $v0, %hi(D_8009B3A4)
    /* CEC0 8001C6C0 A4B34294 */  lhu        $v0, %lo(D_8009B3A4)($v0)
    /* CEC4 8001C6C4 00000000 */  nop
    /* CEC8 8001C6C8 09004314 */  bne        $v0, $v1, .L8001C6F0
    /* CECC 8001C6CC 00000000 */   nop
    /* CED0 8001C6D0 09008292 */  lbu        $v0, 0x9($s4)
    /* CED4 8001C6D4 00000000 */  nop
    /* CED8 8001C6D8 D0024014 */  bnez       $v0, .L8001D21C
    /* CEDC 8001C6DC 00000000 */   nop
    /* CEE0 8001C6E0 EB6D000C */  jal        func_8001B7AC
    /* CEE4 8001C6E4 21204002 */   addu      $a0, $s2, $zero
    /* CEE8 8001C6E8 87740008 */  j          .L8001D21C
    /* CEEC 8001C6EC 00000000 */   nop
  .L8001C6F0:
    /* CEF0 8001C6F0 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* CEF4 8001C6F4 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* CEF8 8001C6F8 00000000 */  nop
    /* CEFC 8001C6FC 20004230 */  andi       $v0, $v0, 0x20
    /* CF00 8001C700 0D004014 */  bnez       $v0, .L8001C738
    /* CF04 8001C704 00000000 */   nop
    /* CF08 8001C708 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* CF0C 8001C70C 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* CF10 8001C710 00000000 */  nop
    /* CF14 8001C714 FFFF4330 */  andi       $v1, $v0, 0xFFFF
    /* CF18 8001C718 00400224 */  addiu      $v0, $zero, 0x4000
    /* CF1C 8001C71C 2D006214 */  bne        $v1, $v0, .L8001C7D4
    /* CF20 8001C720 00000000 */   nop
    /* CF24 8001C724 0A80023C */  lui        $v0, %hi(D_8009B3A4)
    /* CF28 8001C728 A4B34294 */  lhu        $v0, %lo(D_8009B3A4)($v0)
    /* CF2C 8001C72C 00000000 */  nop
    /* CF30 8001C730 28004314 */  bne        $v0, $v1, .L8001C7D4
    /* CF34 8001C734 00000000 */   nop
  .L8001C738:
    /* CF38 8001C738 09009092 */  lbu        $s0, 0x9($s4)
    /* CF3C 8001C73C 00000000 */  nop
    /* CF40 8001C740 B6020012 */  beqz       $s0, .L8001D21C
    /* CF44 8001C744 00000000 */   nop
    /* CF48 8001C748 B8FF000C */  jal        func_8003FEE0
    /* CF4C 8001C74C 2F000424 */   addiu     $a0, $zero, 0x2F
    /* CF50 8001C750 0000838E */  lw         $v1, 0x0($s4)
    /* CF54 8001C754 090080A2 */  sb         $zero, 0x9($s4)
    /* CF58 8001C758 32006294 */  lhu        $v0, 0x32($v1)
    /* CF5C 8001C75C 00000000 */  nop
    /* CF60 8001C760 04004224 */  addiu      $v0, $v0, 0x4
    /* CF64 8001C764 320062A4 */  sh         $v0, 0x32($v1)
    /* CF68 8001C768 0400848E */  lw         $a0, 0x4($s4)
    /* CF6C 8001C76C DB00010C */  jal        func_8004036C
    /* CF70 8001C770 00000000 */   nop
    /* CF74 8001C774 0F80023C */  lui        $v0, %hi(D_800EA030)
    /* CF78 8001C778 040080AE */  sw         $zero, 0x4($s4)
    /* CF7C 8001C77C 30A05424 */  addiu      $s4, $v0, %lo(D_800EA030)
    /* CF80 8001C780 21280000 */  addu       $a1, $zero, $zero
    /* CF84 8001C784 15004292 */  lbu        $v0, 0x15($s2)
    /* CF88 8001C788 04008426 */  addiu      $a0, $s4, 0x4
    /* CF8C 8001C78C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* CF90 8001C790 150042A2 */  sb         $v0, 0x15($s2)
  .L8001C794:
    /* CF94 8001C794 05008390 */  lbu        $v1, 0x5($a0)
    /* CF98 8001C798 00000000 */  nop
    /* CF9C 8001C79C 2A107000 */  slt        $v0, $v1, $s0
    /* CFA0 8001C7A0 06004014 */  bnez       $v0, .L8001C7BC
    /* CFA4 8001C7A4 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* CFA8 8001C7A8 050082A0 */  sb         $v0, 0x5($a0)
    /* CFAC 8001C7AC FEFF6224 */  addiu      $v0, $v1, -0x2
    /* CFB0 8001C7B0 0000838C */  lw         $v1, 0x0($a0)
    /* CFB4 8001C7B4 00110200 */  sll        $v0, $v0, 4
    /* CFB8 8001C7B8 5C0062A0 */  sb         $v0, 0x5C($v1)
  .L8001C7BC:
    /* CFBC 8001C7BC 0100A524 */  addiu      $a1, $a1, 0x1
    /* CFC0 8001C7C0 0500A228 */  slti       $v0, $a1, 0x5
    /* CFC4 8001C7C4 F3FF4014 */  bnez       $v0, .L8001C794
    /* CFC8 8001C7C8 0C008424 */   addiu     $a0, $a0, 0xC
    /* CFCC 8001C7CC 87740008 */  j          .L8001D21C
    /* CFD0 8001C7D0 00000000 */   nop
  .L8001C7D4:
    /* CFD4 8001C7D4 0A80023C */  lui        $v0, %hi(D_8009B3A4)
    /* CFD8 8001C7D8 A4B34294 */  lhu        $v0, %lo(D_8009B3A4)($v0)
    /* CFDC 8001C7DC 00000000 */  nop
    /* CFE0 8001C7E0 03004230 */  andi       $v0, $v0, 0x3
    /* CFE4 8001C7E4 0F004010 */  beqz       $v0, .L8001C824
    /* CFE8 8001C7E8 00000000 */   nop
    /* CFEC 8001C7EC CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* CFF0 8001C7F0 32038497 */  lhu        $a0, %gp_rel(D_8009B23A)($gp)
    /* CFF4 8001C7F4 CC0280A3 */  sb         $zero, %gp_rel(D_8009B1D4)($gp)
    /* CFF8 8001C7F8 C0100300 */  sll        $v0, $v1, 3
    /* CFFC 8001C7FC 23104300 */  subu       $v0, $v0, $v1
    /* D000 8001C800 00110200 */  sll        $v0, $v0, 4
    /* D004 8001C804 0F80033C */  lui        $v1, %hi(D_800E9F2C)
    /* D008 8001C808 2C9F6324 */  addiu      $v1, $v1, %lo(D_800E9F2C)
    /* D00C 8001C80C 21104300 */  addu       $v0, $v0, $v1
    /* D010 8001C810 00408434 */  ori        $a0, $a0, 0x4000
    /* D014 8001C814 AC0282AF */  sw         $v0, %gp_rel(D_8009B1B4)($gp)
    /* D018 8001C818 320384A7 */  sh         $a0, %gp_rel(D_8009B23A)($gp)
    /* D01C 8001C81C 87740008 */  j          .L8001D21C
    /* D020 8001C820 00000000 */   nop
  .L8001C824:
    /* D024 8001C824 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* D028 8001C828 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* D02C 8001C82C 00000000 */  nop
    /* D030 8001C830 C0004230 */  andi       $v0, $v0, 0xC0
    /* D034 8001C834 79024010 */  beqz       $v0, .L8001D21C
    /* D038 8001C838 01000224 */   addiu     $v0, $zero, 0x1
    /* D03C 8001C83C 15004392 */  lbu        $v1, 0x15($s2)
    /* D040 8001C840 00000000 */  nop
    /* D044 8001C844 75026210 */  beq        $v1, $v0, .L8001D21C
    /* D048 8001C848 00000000 */   nop
    /* D04C 8001C84C B8FF000C */  jal        func_8003FEE0
    /* D050 8001C850 07000424 */   addiu     $a0, $zero, 0x7
    /* D054 8001C854 04000224 */  addiu      $v0, $zero, 0x4
    /* D058 8001C858 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D05C 8001C85C 2E6E000C */  jal        func_8001B8B8
    /* D060 8001C860 21204002 */   addu      $a0, $s2, $zero
    /* D064 8001C864 97730008 */  j          .L8001CE5C
    /* D068 8001C868 00000000 */   nop
  jlabel .L8001C86C
    /* D06C 8001C86C 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* D070 8001C870 0000938E */  lw         $s3, 0x0($s4)
    /* D074 8001C874 80006230 */  andi       $v0, $v1, 0x80
    /* D078 8001C878 1D004014 */  bnez       $v0, .L8001C8F0
    /* D07C 8001C87C 40006230 */   andi      $v0, $v1, 0x40
    /* D080 8001C880 C0006234 */  ori        $v0, $v1, 0xC0
    /* D084 8001C884 30006396 */  lhu        $v1, 0x30($s3)
    /* D088 8001C888 32006596 */  lhu        $a1, 0x32($s3)
    /* D08C 8001C88C 21206002 */  addu       $a0, $s3, $zero
    /* D090 8001C890 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D094 8001C894 86000224 */  addiu      $v0, $zero, 0x86
    /* D098 8001C898 280062A6 */  sh         $v0, 0x28($s3)
    /* D09C 8001C89C 5A000224 */  addiu      $v0, $zero, 0x5A
    /* D0A0 8001C8A0 2A0062A6 */  sh         $v0, 0x2A($s3)
    /* D0A4 8001C8A4 2C0063A6 */  sh         $v1, 0x2C($s3)
    /* D0A8 8001C8A8 5E0C010C */  jal        func_80043178
    /* D0AC 8001C8AC 2E0065A6 */   sh        $a1, 0x2E($s3)
    /* D0B0 8001C8B0 16006592 */  lbu        $a1, 0x16($s3)
    /* D0B4 8001C8B4 21206002 */  addu       $a0, $s3, $zero
    /* D0B8 8001C8B8 600060A6 */  sh         $zero, 0x60($s3)
    /* D0BC 8001C8BC 0400A524 */  addiu      $a1, $a1, 0x4
    /* D0C0 8001C8C0 002E0500 */  sll        $a1, $a1, 24
    /* D0C4 8001C8C4 3B0A010C */  jal        func_800428EC
    /* D0C8 8001C8C8 032E0500 */   sra       $a1, $a1, 24
    /* D0CC 8001C8CC 0400438E */  lw         $v1, 0x4($s2)
    /* D0D0 8001C8D0 00000000 */  nop
    /* D0D4 8001C8D4 08006294 */  lhu        $v0, 0x8($v1)
    /* D0D8 8001C8D8 00000000 */  nop
    /* D0DC 8001C8DC BFFF4230 */  andi       $v0, $v0, 0xFFBF
    /* D0E0 8001C8E0 080062A4 */  sh         $v0, 0x8($v1)
    /* D0E4 8001C8E4 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* D0E8 8001C8E8 00000000 */  nop
    /* D0EC 8001C8EC 40006230 */  andi       $v0, $v1, 0x40
  .L8001C8F0:
    /* D0F0 8001C8F0 8C004010 */  beqz       $v0, .L8001CB24
    /* D0F4 8001C8F4 20006230 */   andi      $v0, $v1, 0x20
    /* D0F8 8001C8F8 28006586 */  lh         $a1, 0x28($s3)
    /* D0FC 8001C8FC 2A006686 */  lh         $a2, 0x2A($s3)
    /* D100 8001C900 60006786 */  lh         $a3, 0x60($s3)
    /* D104 8001C904 630C010C */  jal        func_8004318C
    /* D108 8001C908 21206002 */   addu      $a0, $s3, $zero
    /* D10C 8001C90C 60006296 */  lhu        $v0, 0x60($s3)
    /* D110 8001C910 00000000 */  nop
    /* D114 8001C914 AA004224 */  addiu      $v0, $v0, 0xAA
    /* D118 8001C918 600062A6 */  sh         $v0, 0x60($s3)
    /* D11C 8001C91C 00140200 */  sll        $v0, $v0, 16
    /* D120 8001C920 03140200 */  sra        $v0, $v0, 16
    /* D124 8001C924 00084228 */  slti       $v0, $v0, 0x800
    /* D128 8001C928 3C024014 */  bnez       $v0, .L8001D21C
    /* D12C 8001C92C 00000000 */   nop
    /* D130 8001C930 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* D134 8001C934 2800638E */  lw         $v1, 0x28($s3)
    /* D138 8001C938 BF004630 */  andi       $a2, $v0, 0xBF
    /* D13C 8001C93C 10004230 */  andi       $v0, $v0, 0x10
    /* D140 8001C940 6C0286A3 */  sb         $a2, %gp_rel(D_8009B174)($gp)
    /* D144 8001C944 19004010 */  beqz       $v0, .L8001C9AC
    /* D148 8001C948 300063AE */   sw        $v1, 0x30($s3)
    /* D14C 8001C94C 0400438E */  lw         $v1, 0x4($s2)
    /* D150 8001C950 00000000 */  nop
    /* D154 8001C954 08006294 */  lhu        $v0, 0x8($v1)
    /* D158 8001C958 00000000 */  nop
    /* D15C 8001C95C 40004234 */  ori        $v0, $v0, 0x40
    /* D160 8001C960 080062A4 */  sh         $v0, 0x8($v1)
    /* D164 8001C964 16006592 */  lbu        $a1, 0x16($s3)
    /* D168 8001C968 21206002 */  addu       $a0, $s3, $zero
    /* D16C 8001C96C FCFFA524 */  addiu      $a1, $a1, -0x4
    /* D170 8001C970 002E0500 */  sll        $a1, $a1, 24
    /* D174 8001C974 3B0A010C */  jal        func_800428EC
    /* D178 8001C978 032E0500 */   sra       $a1, $a1, 24
    /* D17C 8001C97C 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* D180 8001C980 00000000 */  nop
    /* D184 8001C984 20004230 */  andi       $v0, $v0, 0x20
    /* D188 8001C988 04004010 */  beqz       $v0, .L8001C99C
    /* D18C 8001C98C 04000224 */   addiu     $v0, $zero, 0x4
    /* D190 8001C990 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D194 8001C994 87740008 */  j          .L8001D21C
    /* D198 8001C998 00000000 */   nop
  .L8001C99C:
    /* D19C 8001C99C 01000224 */  addiu      $v0, $zero, 0x1
    /* D1A0 8001C9A0 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D1A4 8001C9A4 87740008 */  j          .L8001D21C
    /* D1A8 8001C9A8 00000000 */   nop
  .L8001C9AC:
    /* D1AC 8001C9AC 0400053C */  lui        $a1, (0x48000 >> 16)
    /* D1B0 8001C9B0 0080A534 */  ori        $a1, $a1, (0x48000 & 0xFFFF)
    /* D1B4 8001C9B4 1680033C */  lui        $v1, %hi(D_8015C424)
    /* D1B8 8001C9B8 6A006492 */  lbu        $a0, 0x6A($s3)
    /* D1BC 8001C9BC 24C46324 */  addiu      $v1, $v1, %lo(D_8015C424)
    /* D1C0 8001C9C0 C0100400 */  sll        $v0, $a0, 3
    /* D1C4 8001C9C4 23104400 */  subu       $v0, $v0, $a0
    /* D1C8 8001C9C8 80100200 */  sll        $v0, $v0, 2
    /* D1CC 8001C9CC 21104300 */  addu       $v0, $v0, $v1
    /* D1D0 8001C9D0 21104500 */  addu       $v0, $v0, $a1
    /* D1D4 8001C9D4 B836428C */  lw         $v0, 0x36B8($v0)
    /* D1D8 8001C9D8 1D80033C */  lui        $v1, %hi(D_801D4244)
    /* D1DC 8001C9DC 00004484 */  lh         $a0, 0x0($v0)
    /* D1E0 8001C9E0 44426324 */  addiu      $v1, $v1, %lo(D_801D4244)
    /* D1E4 8001C9E4 FFFF8224 */  addiu      $v0, $a0, -0x1
    /* D1E8 8001C9E8 80100200 */  sll        $v0, $v0, 2
    /* D1EC 8001C9EC 21104300 */  addu       $v0, $v0, $v1
    /* D1F0 8001C9F0 0000428C */  lw         $v0, 0x0($v0)
    /* D1F4 8001C9F4 00000000 */  nop
    /* D1F8 8001C9F8 83160200 */  sra        $v0, $v0, 26
    /* D1FC 8001C9FC 1F005030 */  andi       $s0, $v0, 0x1F
    /* D200 8001CA00 1400022A */  slti       $v0, $s0, 0x14
    /* D204 8001CA04 03004014 */  bnez       $v0, .L8001CA14
    /* D208 8001CA08 15000224 */   addiu     $v0, $zero, 0x15
    /* D20C 8001CA0C 0A000216 */  bne        $s0, $v0, .L8001CA38
    /* D210 8001CA10 00000000 */   nop
  .L8001CA14:
    /* D214 8001CA14 21006292 */  lbu        $v0, 0x21($s3)
    /* D218 8001CA18 00000000 */  nop
    /* D21C 8001CA1C 06004014 */  bnez       $v0, .L8001CA38
    /* D220 8001CA20 10000224 */   addiu     $v0, $zero, 0x10
    /* D224 8001CA24 600062A6 */  sh         $v0, 0x60($s3)
    /* D228 8001CA28 2000C234 */  ori        $v0, $a2, 0x20
    /* D22C 8001CA2C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D230 8001CA30 B8FF000C */  jal        func_8003FEE0
    /* D234 8001CA34 0B000424 */   addiu     $a0, $zero, 0xB
  .L8001CA38:
    /* D238 8001CA38 0B00010C */  jal        func_8004002C
    /* D23C 8001CA3C 01001224 */   addiu     $s2, $zero, 0x1
    /* D240 8001CA40 21204000 */  addu       $a0, $v0, $zero
    /* D244 8001CA44 2B00010C */  jal        func_800400AC
    /* D248 8001CA48 02000524 */   addiu     $a1, $zero, 0x2
    /* D24C 8001CA4C 21A04000 */  addu       $s4, $v0, $zero
    /* D250 8001CA50 21208002 */  addu       $a0, $s4, $zero
    /* D254 8001CA54 03000724 */  addiu      $a3, $zero, 0x3
    /* D258 8001CA58 02000224 */  addiu      $v0, $zero, 0x2
    /* D25C 8001CA5C 0B001124 */  addiu      $s1, $zero, 0xB
    /* D260 8001CA60 30006586 */  lh         $a1, 0x30($s3)
    /* D264 8001CA64 32006686 */  lh         $a2, 0x32($s3)
    /* D268 8001CA68 0C021024 */  addiu      $s0, $zero, 0x20C
    /* D26C 8001CA6C 1000B2AF */  sw         $s2, 0x10($sp)
    /* D270 8001CA70 1400A2AF */  sw         $v0, 0x14($sp)
    /* D274 8001CA74 1800B1AF */  sw         $s1, 0x18($sp)
    /* D278 8001CA78 1C00B0AF */  sw         $s0, 0x1C($sp)
    /* D27C 8001CA7C F8FFA524 */  addiu      $a1, $a1, -0x8
    /* D280 8001CA80 3301010C */  jal        func_800404CC
    /* D284 8001CA84 1E00C624 */   addiu     $a2, $a2, 0x1E
    /* D288 8001CA88 460A010C */  jal        func_80042918
    /* D28C 8001CA8C 21208002 */   addu      $a0, $s4, $zero
    /* D290 8001CA90 21208002 */  addu       $a0, $s4, $zero
    /* D294 8001CA94 3B0A010C */  jal        func_800428EC
    /* D298 8001CA98 0A000524 */   addiu     $a1, $zero, 0xA
    /* D29C 8001CA9C 08008296 */  lhu        $v0, 0x8($s4)
    /* D2A0 8001CAA0 00000000 */  nop
    /* D2A4 8001CAA4 28004234 */  ori        $v0, $v0, 0x28
    /* D2A8 8001CAA8 080082A6 */  sh         $v0, 0x8($s4)
    /* D2AC 8001CAAC 800294AF */  sw         $s4, %gp_rel(D_8009B188)($gp)
    /* D2B0 8001CAB0 0B00010C */  jal        func_8004002C
    /* D2B4 8001CAB4 00000000 */   nop
    /* D2B8 8001CAB8 21204000 */  addu       $a0, $v0, $zero
    /* D2BC 8001CABC 2B00010C */  jal        func_800400AC
    /* D2C0 8001CAC0 02000524 */   addiu     $a1, $zero, 0x2
    /* D2C4 8001CAC4 21A04000 */  addu       $s4, $v0, $zero
    /* D2C8 8001CAC8 21208002 */  addu       $a0, $s4, $zero
    /* D2CC 8001CACC 30006586 */  lh         $a1, 0x30($s3)
    /* D2D0 8001CAD0 32006686 */  lh         $a2, 0x32($s3)
    /* D2D4 8001CAD4 03000724 */  addiu      $a3, $zero, 0x3
    /* D2D8 8001CAD8 1000B2AF */  sw         $s2, 0x10($sp)
    /* D2DC 8001CADC 1400A0AF */  sw         $zero, 0x14($sp)
    /* D2E0 8001CAE0 1800B1AF */  sw         $s1, 0x18($sp)
    /* D2E4 8001CAE4 1C00B0AF */  sw         $s0, 0x1C($sp)
    /* D2E8 8001CAE8 3C00A524 */  addiu      $a1, $a1, 0x3C
    /* D2EC 8001CAEC 3301010C */  jal        func_800404CC
    /* D2F0 8001CAF0 1E00C624 */   addiu     $a2, $a2, 0x1E
    /* D2F4 8001CAF4 460A010C */  jal        func_80042918
    /* D2F8 8001CAF8 21208002 */   addu      $a0, $s4, $zero
    /* D2FC 8001CAFC 21208002 */  addu       $a0, $s4, $zero
    /* D300 8001CB00 3B0A010C */  jal        func_800428EC
    /* D304 8001CB04 0A000524 */   addiu     $a1, $zero, 0xA
    /* D308 8001CB08 08008296 */  lhu        $v0, 0x8($s4)
    /* D30C 8001CB0C 00000000 */  nop
    /* D310 8001CB10 28004234 */  ori        $v0, $v0, 0x28
    /* D314 8001CB14 080082A6 */  sh         $v0, 0x8($s4)
    /* D318 8001CB18 840294AF */  sw         $s4, %gp_rel(D_8009B18C)($gp)
    /* D31C 8001CB1C 87740008 */  j          .L8001D21C
    /* D320 8001CB20 00000000 */   nop
  .L8001CB24:
    /* D324 8001CB24 2B004010 */  beqz       $v0, .L8001CBD4
    /* D328 8001CB28 00000000 */   nop
    /* D32C 8001CB2C 08006296 */  lhu        $v0, 0x8($s3)
    /* D330 8001CB30 21006392 */  lbu        $v1, 0x21($s3)
    /* D334 8001CB34 60006492 */  lbu        $a0, 0x60($s3)
    /* D338 8001CB38 04004234 */  ori        $v0, $v0, 0x4
    /* D33C 8001CB3C 21186400 */  addu       $v1, $v1, $a0
    /* D340 8001CB40 080062A6 */  sh         $v0, 0x8($s3)
    /* D344 8001CB44 21106000 */  addu       $v0, $v1, $zero
    /* D348 8001CB48 210063A2 */  sb         $v1, 0x21($s3)
    /* D34C 8001CB4C 7F006330 */  andi       $v1, $v1, 0x7F
    /* D350 8001CB50 B2016014 */  bnez       $v1, .L8001D21C
    /* D354 8001CB54 FF004230 */   andi      $v0, $v0, 0xFF
    /* D358 8001CB58 05004014 */  bnez       $v0, .L8001CB70
    /* D35C 8001CB5C 00000000 */   nop
    /* D360 8001CB60 08006296 */  lhu        $v0, 0x8($s3)
    /* D364 8001CB64 00000000 */  nop
    /* D368 8001CB68 FBFF4230 */  andi       $v0, $v0, 0xFFFB
    /* D36C 8001CB6C 080062A6 */  sh         $v0, 0x8($s3)
  .L8001CB70:
    /* D370 8001CB70 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* D374 8001CB74 00000000 */  nop
    /* D378 8001CB78 DF004330 */  andi       $v1, $v0, 0xDF
    /* D37C 8001CB7C 10004230 */  andi       $v0, $v0, 0x10
    /* D380 8001CB80 6C0283A3 */  sb         $v1, %gp_rel(D_8009B174)($gp)
    /* D384 8001CB84 A5014010 */  beqz       $v0, .L8001D21C
    /* D388 8001CB88 00000000 */   nop
  .L8001CB8C:
    /* D38C 8001CB8C 8002848F */  lw         $a0, %gp_rel(D_8009B188)($gp)
    /* D390 8001CB90 DB00010C */  jal        func_8004036C
    /* D394 8001CB94 00000000 */   nop
    /* D398 8001CB98 8402848F */  lw         $a0, %gp_rel(D_8009B18C)($gp)
    /* D39C 8001CB9C DB00010C */  jal        func_8004036C
    /* D3A0 8001CBA0 00000000 */   nop
    /* D3A4 8001CBA4 840280AF */  sw         $zero, %gp_rel(D_8009B18C)($gp)
    /* D3A8 8001CBA8 800280AF */  sw         $zero, %gp_rel(D_8009B188)($gp)
    /* D3AC 8001CBAC 2C00628E */  lw         $v0, 0x2C($s3)
    /* D3B0 8001CBB0 21206002 */  addu       $a0, $s3, $zero
    /* D3B4 8001CBB4 5E0C010C */  jal        func_80043178
    /* D3B8 8001CBB8 280062AE */   sw        $v0, 0x28($s3)
    /* D3BC 8001CBBC 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* D3C0 8001CBC0 600060A6 */  sh         $zero, 0x60($s3)
    /* D3C4 8001CBC4 50004234 */  ori        $v0, $v0, 0x50
    /* D3C8 8001CBC8 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D3CC 8001CBCC 87740008 */  j          .L8001D21C
    /* D3D0 8001CBD0 00000000 */   nop
  .L8001CBD4:
    /* D3D4 8001CBD4 0A80023C */  lui        $v0, %hi(D_8009B394)
    /* D3D8 8001CBD8 94B34294 */  lhu        $v0, %lo(D_8009B394)($v0)
    /* D3DC 8001CBDC 00000000 */  nop
    /* D3E0 8001CBE0 00A04230 */  andi       $v0, $v0, 0xA000
    /* D3E4 8001CBE4 0E004010 */  beqz       $v0, .L8001CC20
    /* D3E8 8001CBE8 10000224 */   addiu     $v0, $zero, 0x10
    /* D3EC 8001CBEC 600062A6 */  sh         $v0, 0x60($s3)
    /* D3F0 8001CBF0 0A80023C */  lui        $v0, %hi(D_8009B394)
    /* D3F4 8001CBF4 94B34294 */  lhu        $v0, %lo(D_8009B394)($v0)
    /* D3F8 8001CBF8 20006334 */  ori        $v1, $v1, 0x20
    /* D3FC 8001CBFC 6C0283A3 */  sb         $v1, %gp_rel(D_8009B174)($gp)
    /* D400 8001CC00 00204230 */  andi       $v0, $v0, 0x2000
    /* D404 8001CC04 02004010 */  beqz       $v0, .L8001CC10
    /* D408 8001CC08 F0FF0224 */   addiu     $v0, $zero, -0x10
    /* D40C 8001CC0C 600062A6 */  sh         $v0, 0x60($s3)
  .L8001CC10:
    /* D410 8001CC10 B8FF000C */  jal        func_8003FEE0
    /* D414 8001CC14 0B000424 */   addiu     $a0, $zero, 0xB
    /* D418 8001CC18 87740008 */  j          .L8001D21C
    /* D41C 8001CC1C 00000000 */   nop
  .L8001CC20:
    /* D420 8001CC20 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* D424 8001CC24 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* D428 8001CC28 00000000 */  nop
    /* D42C 8001CC2C 20004230 */  andi       $v0, $v0, 0x20
    /* D430 8001CC30 0D004010 */  beqz       $v0, .L8001CC68
    /* D434 8001CC34 00000000 */   nop
    /* D438 8001CC38 B8FF000C */  jal        func_8003FEE0
    /* D43C 8001CC3C 08000424 */   addiu     $a0, $zero, 0x8
    /* D440 8001CC40 21006292 */  lbu        $v0, 0x21($s3)
    /* D444 8001CC44 00000000 */  nop
    /* D448 8001CC48 D0FF4010 */  beqz       $v0, .L8001CB8C
    /* D44C 8001CC4C 10000324 */   addiu     $v1, $zero, 0x10
    /* D450 8001CC50 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* D454 8001CC54 600063A6 */  sh         $v1, 0x60($s3)
    /* D458 8001CC58 30004234 */  ori        $v0, $v0, 0x30
    /* D45C 8001CC5C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D460 8001CC60 87740008 */  j          .L8001D21C
    /* D464 8001CC64 00000000 */   nop
  .L8001CC68:
    /* D468 8001CC68 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* D46C 8001CC6C 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* D470 8001CC70 00000000 */  nop
    /* D474 8001CC74 C0004230 */  andi       $v0, $v0, 0xC0
    /* D478 8001CC78 68014010 */  beqz       $v0, .L8001D21C
    /* D47C 8001CC7C 00000000 */   nop
    /* D480 8001CC80 B8FF000C */  jal        func_8003FEE0
    /* D484 8001CC84 07000424 */   addiu     $a0, $zero, 0x7
    /* D488 8001CC88 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* D48C 8001CC8C 6A006392 */  lbu        $v1, 0x6A($s3)
    /* D490 8001CC90 D87A4424 */  addiu      $a0, $v0, %lo(D_801A7AD8)
    /* D494 8001CC94 C0100300 */  sll        $v0, $v1, 3
    /* D498 8001CC98 23104300 */  subu       $v0, $v0, $v1
    /* D49C 8001CC9C 80100200 */  sll        $v0, $v0, 2
    /* D4A0 8001CCA0 21104400 */  addu       $v0, $v0, $a0
    /* D4A4 8001CCA4 16004394 */  lhu        $v1, 0x16($v0)
    /* D4A8 8001CCA8 00000000 */  nop
    /* D4AC 8001CCAC FFEF6330 */  andi       $v1, $v1, 0xEFFF
    /* D4B0 8001CCB0 160043A4 */  sh         $v1, 0x16($v0)
    /* D4B4 8001CCB4 21006292 */  lbu        $v0, 0x21($s3)
    /* D4B8 8001CCB8 00000000 */  nop
    /* D4BC 8001CCBC 0B004010 */  beqz       $v0, .L8001CCEC
    /* D4C0 8001CCC0 0400053C */   lui       $a1, (0x48000 >> 16)
    /* D4C4 8001CCC4 6A006292 */  lbu        $v0, 0x6A($s3)
    /* D4C8 8001CCC8 00000000 */  nop
    /* D4CC 8001CCCC C0180200 */  sll        $v1, $v0, 3
    /* D4D0 8001CCD0 23186200 */  subu       $v1, $v1, $v0
    /* D4D4 8001CCD4 80180300 */  sll        $v1, $v1, 2
    /* D4D8 8001CCD8 21186400 */  addu       $v1, $v1, $a0
    /* D4DC 8001CCDC 16006294 */  lhu        $v0, 0x16($v1)
    /* D4E0 8001CCE0 00000000 */  nop
    /* D4E4 8001CCE4 00104234 */  ori        $v0, $v0, 0x1000
    /* D4E8 8001CCE8 160062A4 */  sh         $v0, 0x16($v1)
  .L8001CCEC:
    /* D4EC 8001CCEC 0080A534 */  ori        $a1, $a1, (0x48000 & 0xFFFF)
    /* D4F0 8001CCF0 1680033C */  lui        $v1, %hi(D_8015C424)
    /* D4F4 8001CCF4 6A006492 */  lbu        $a0, 0x6A($s3)
    /* D4F8 8001CCF8 24C46324 */  addiu      $v1, $v1, %lo(D_8015C424)
    /* D4FC 8001CCFC C0100400 */  sll        $v0, $a0, 3
    /* D500 8001CD00 23104400 */  subu       $v0, $v0, $a0
    /* D504 8001CD04 80100200 */  sll        $v0, $v0, 2
    /* D508 8001CD08 21104300 */  addu       $v0, $v0, $v1
    /* D50C 8001CD0C 21104500 */  addu       $v0, $v0, $a1
    /* D510 8001CD10 1D80033C */  lui        $v1, %hi(D_801D4244)
    /* D514 8001CD14 C0364484 */  lh         $a0, 0x36C0($v0)
    /* D518 8001CD18 44426324 */  addiu      $v1, $v1, %lo(D_801D4244)
    /* D51C 8001CD1C FFFF8224 */  addiu      $v0, $a0, -0x1
    /* D520 8001CD20 80100200 */  sll        $v0, $v0, 2
    /* D524 8001CD24 21104300 */  addu       $v0, $v0, $v1
    /* D528 8001CD28 0000428C */  lw         $v0, 0x0($v0)
    /* D52C 8001CD2C 00000000 */  nop
    /* D530 8001CD30 83160200 */  sra        $v0, $v0, 26
    /* D534 8001CD34 1F005030 */  andi       $s0, $v0, 0x1F
    /* D538 8001CD38 1400022A */  slti       $v0, $s0, 0x14
    /* D53C 8001CD3C 1D004014 */  bnez       $v0, .L8001CDB4
    /* D540 8001CD40 00000000 */   nop
    /* D544 8001CD44 21006292 */  lbu        $v0, 0x21($s3)
    /* D548 8001CD48 00000000 */  nop
    /* D54C 8001CD4C 19004014 */  bnez       $v0, .L8001CDB4
    /* D550 8001CD50 17000224 */   addiu     $v0, $zero, 0x17
    /* D554 8001CD54 17000212 */  beq        $s0, $v0, .L8001CDB4
    /* D558 8001CD58 15000224 */   addiu     $v0, $zero, 0x15
    /* D55C 8001CD5C 15000212 */  beq        $s0, $v0, .L8001CDB4
    /* D560 8001CD60 00000000 */   nop
    /* D564 8001CD64 8002848F */  lw         $a0, %gp_rel(D_8009B188)($gp)
    /* D568 8001CD68 DB00010C */  jal        func_8004036C
    /* D56C 8001CD6C 00000000 */   nop
    /* D570 8001CD70 8402848F */  lw         $a0, %gp_rel(D_8009B18C)($gp)
    /* D574 8001CD74 DB00010C */  jal        func_8004036C
    /* D578 8001CD78 00000000 */   nop
    /* D57C 8001CD7C 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* D580 8001CD80 F09E53AC */  sw         $s3, %lo(D_800E9EF0)($v0)
    /* D584 8001CD84 C002828F */  lw         $v0, %gp_rel(D_8009B1C8)($gp)
    /* D588 8001CD88 840280AF */  sw         $zero, %gp_rel(D_8009B18C)($gp)
    /* D58C 8001CD8C 800280AF */  sw         $zero, %gp_rel(D_8009B188)($gp)
  .L8001CD90:
    /* D590 8001CD90 0E004382 */  lb         $v1, 0xE($s2)
    /* D594 8001CD94 00000000 */  nop
    /* D598 8001CD98 21104300 */  addu       $v0, $v0, $v1
    /* D59C 8001CD9C FFFF0324 */  addiu      $v1, $zero, -0x1
    /* D5A0 8001CDA0 1A0043A0 */  sb         $v1, 0x1A($v0)
    /* D5A4 8001CDA4 05000224 */  addiu      $v0, $zero, 0x5
    /* D5A8 8001CDA8 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D5AC 8001CDAC 87740008 */  j          .L8001D21C
    /* D5B0 8001CDB0 00000000 */   nop
  .L8001CDB4:
    /* D5B4 8001CDB4 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* D5B8 8001CDB8 00000000 */  nop
    /* D5BC 8001CDBC 70004234 */  ori        $v0, $v0, 0x70
    /* D5C0 8001CDC0 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D5C4 8001CDC4 E3720008 */  j          .L8001CB8C
    /* D5C8 8001CDC8 00000000 */   nop
  jlabel .L8001CDCC
    /* D5CC 8001CDCC 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* D5D0 8001CDD0 00000000 */  nop
    /* D5D4 8001CDD4 80006230 */  andi       $v0, $v1, 0x80
    /* D5D8 8001CDD8 0D004014 */  bnez       $v0, .L8001CE10
    /* D5DC 8001CDDC 40006230 */   andi      $v0, $v1, 0x40
    /* D5E0 8001CDE0 80006234 */  ori        $v0, $v1, 0x80
    /* D5E4 8001CDE4 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D5E8 8001CDE8 080380A7 */  sh         $zero, %gp_rel(D_8009B210)($gp)
    /* D5EC 8001CDEC 4E6E000C */  jal        func_8001B938
    /* D5F0 8001CDF0 21204002 */   addu      $a0, $s2, $zero
    /* D5F4 8001CDF4 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* D5F8 8001CDF8 00000000 */  nop
    /* D5FC 8001CDFC 40004234 */  ori        $v0, $v0, 0x40
    /* D600 8001CE00 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D604 8001CE04 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* D608 8001CE08 00000000 */  nop
    /* D60C 8001CE0C 40006230 */  andi       $v0, $v1, 0x40
  .L8001CE10:
    /* D610 8001CE10 19004010 */  beqz       $v0, .L8001CE78
    /* D614 8001CE14 00000000 */   nop
    /* D618 8001CE18 5A028297 */  lhu        $v0, %gp_rel(D_8009B162)($gp)
    /* D61C 8001CE1C 00000000 */  nop
    /* D620 8001CE20 FE004014 */  bnez       $v0, .L8001D21C
    /* D624 8001CE24 BF006230 */   andi      $v0, $v1, 0xBF
    /* D628 8001CE28 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D62C 8001CE2C 10006230 */  andi       $v0, $v1, 0x10
    /* D630 8001CE30 FA004010 */  beqz       $v0, .L8001D21C
    /* D634 8001CE34 01000224 */   addiu     $v0, $zero, 0x1
    /* D638 8001CE38 CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* D63C 8001CE3C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D640 8001CE40 C0100300 */  sll        $v0, $v1, 3
    /* D644 8001CE44 23104300 */  subu       $v0, $v0, $v1
    /* D648 8001CE48 00110200 */  sll        $v0, $v0, 4
    /* D64C 8001CE4C 0F80033C */  lui        $v1, %hi(D_800E9F10)
    /* D650 8001CE50 109F6324 */  addiu      $v1, $v1, %lo(D_800E9F10)
    /* D654 8001CE54 21104300 */  addu       $v0, $v0, $v1
    /* D658 8001CE58 AC0282AF */  sw         $v0, %gp_rel(D_8009B1B4)($gp)
  .L8001CE5C:
    /* D65C 8001CE5C 15004292 */  lbu        $v0, 0x15($s2)
    /* D660 8001CE60 00000000 */  nop
    /* D664 8001CE64 ED004014 */  bnez       $v0, .L8001D21C
    /* D668 8001CE68 03000224 */   addiu     $v0, $zero, 0x3
    /* D66C 8001CE6C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D670 8001CE70 87740008 */  j          .L8001D21C
    /* D674 8001CE74 00000000 */   nop
  .L8001CE78:
    /* D678 8001CE78 AC02848F */  lw         $a0, %gp_rel(D_8009B1B4)($gp)
    /* D67C 8001CE7C 1890000C */  jal        func_80024060
    /* D680 8001CE80 00000000 */   nop
    /* D684 8001CE84 E5004014 */  bnez       $v0, .L8001D21C
    /* D688 8001CE88 0980063C */   lui       $a2, %hi(D_800907D8)
    /* D68C 8001CE8C 0F80033C */  lui        $v1, %hi(D_800E9F10)
    /* D690 8001CE90 109F6324 */  addiu      $v1, $v1, %lo(D_800E9F10)
    /* D694 8001CE94 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* D698 8001CE98 D807C624 */  addiu      $a2, $a2, %lo(D_800907D8)
    /* D69C 8001CE9C C0100400 */  sll        $v0, $a0, 3
    /* D6A0 8001CEA0 23104400 */  subu       $v0, $v0, $a0
    /* D6A4 8001CEA4 00110200 */  sll        $v0, $v0, 4
    /* D6A8 8001CEA8 21104300 */  addu       $v0, $v0, $v1
    /* D6AC 8001CEAC 48004580 */  lb         $a1, 0x48($v0)
    /* D6B0 8001CEB0 47004280 */  lb         $v0, 0x47($v0)
    /* D6B4 8001CEB4 80180500 */  sll        $v1, $a1, 2
    /* D6B8 8001CEB8 21186500 */  addu       $v1, $v1, $a1
    /* D6BC 8001CEBC 21186200 */  addu       $v1, $v1, $v0
    /* D6C0 8001CEC0 80100400 */  sll        $v0, $a0, 2
    /* D6C4 8001CEC4 21104400 */  addu       $v0, $v0, $a0
    /* D6C8 8001CEC8 80100200 */  sll        $v0, $v0, 2
    /* D6CC 8001CECC 21186200 */  addu       $v1, $v1, $v0
    /* D6D0 8001CED0 21186600 */  addu       $v1, $v1, $a2
    /* D6D4 8001CED4 1A80043C */  lui        $a0, %hi(D_801A7AD8)
    /* D6D8 8001CED8 00006390 */  lbu        $v1, 0x0($v1)
    /* D6DC 8001CEDC D87A8424 */  addiu      $a0, $a0, %lo(D_801A7AD8)
    /* D6E0 8001CEE0 C0100300 */  sll        $v0, $v1, 3
    /* D6E4 8001CEE4 23104300 */  subu       $v0, $v0, $v1
    /* D6E8 8001CEE8 80100200 */  sll        $v0, $v0, 2
    /* D6EC 8001CEEC 0D5C000C */  jal        func_80017034
    /* D6F0 8001CEF0 21204400 */   addu      $a0, $v0, $a0
    /* D6F4 8001CEF4 21804000 */  addu       $s0, $v0, $zero
    /* D6F8 8001CEF8 0A000012 */  beqz       $s0, .L8001CF24
    /* D6FC 8001CEFC 14000224 */   addiu     $v0, $zero, 0x14
    /* D700 8001CF00 0A80013C */  lui        $at, %hi(D_8009B24B)
    /* D704 8001CF04 4BB222A0 */  sb         $v0, %lo(D_8009B24B)($at)
    /* D708 8001CF08 02000224 */  addiu      $v0, $zero, 0x2
    /* D70C 8001CF0C 0A80013C */  lui        $at, %hi(D_8009B246)
    /* D710 8001CF10 46B230A4 */  sh         $s0, %lo(D_8009B246)($at)
    /* D714 8001CF14 0A80013C */  lui        $at, %hi(D_8009B254)
    /* D718 8001CF18 54B222A0 */  sb         $v0, %lo(D_8009B254)($at)
    /* D71C 8001CF1C 87740008 */  j          .L8001D21C
    /* D720 8001CF20 00000000 */   nop
  .L8001CF24:
    /* D724 8001CF24 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* D728 8001CF28 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* D72C 8001CF2C 00000000 */  nop
    /* D730 8001CF30 20004230 */  andi       $v0, $v0, 0x20
    /* D734 8001CF34 09004010 */  beqz       $v0, .L8001CF5C
    /* D738 8001CF38 0C000324 */   addiu     $v1, $zero, 0xC
    /* D73C 8001CF3C 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* D740 8001CF40 5A0283A7 */  sh         $v1, %gp_rel(D_8009B162)($gp)
    /* D744 8001CF44 50004234 */  ori        $v0, $v0, 0x50
    /* D748 8001CF48 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D74C 8001CF4C B8FF000C */  jal        func_8003FEE0
    /* D750 8001CF50 08000424 */   addiu     $a0, $zero, 0x8
    /* D754 8001CF54 87740008 */  j          .L8001D21C
    /* D758 8001CF58 00000000 */   nop
  .L8001CF5C:
    /* D75C 8001CF5C 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* D760 8001CF60 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* D764 8001CF64 00000000 */  nop
    /* D768 8001CF68 C0004230 */  andi       $v0, $v0, 0xC0
    /* D76C 8001CF6C AB004010 */  beqz       $v0, .L8001D21C
    /* D770 8001CF70 00000000 */   nop
  .L8001CF74:
    /* D774 8001CF74 B8FF000C */  jal        func_8003FEE0
    /* D778 8001CF78 07000424 */   addiu     $a0, $zero, 0x7
    /* D77C 8001CF7C 06000524 */  addiu      $a1, $zero, 0x6
    /* D780 8001CF80 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* D784 8001CF84 F09E4224 */  addiu      $v0, $v0, %lo(D_800E9EF0)
    /* D788 8001CF88 18004224 */  addiu      $v0, $v0, 0x18
  .L8001CF8C:
    /* D78C 8001CF8C 000040AC */  sw         $zero, 0x0($v0)
    /* D790 8001CF90 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* D794 8001CF94 FDFFA104 */  bgez       $a1, .L8001CF8C
    /* D798 8001CF98 FCFF4224 */   addiu     $v0, $v0, -0x4
    /* D79C 8001CF9C AC02868F */  lw         $a2, %gp_rel(D_8009B1B4)($gp)
    /* D7A0 8001CFA0 00000000 */  nop
    /* D7A4 8001CFA4 1000C380 */  lb         $v1, 0x10($a2)
    /* D7A8 8001CFA8 0F00C480 */  lb         $a0, 0xF($a2)
    /* D7AC 8001CFAC 80100300 */  sll        $v0, $v1, 2
    /* D7B0 8001CFB0 21104300 */  addu       $v0, $v0, $v1
    /* D7B4 8001CFB4 21284400 */  addu       $a1, $v0, $a0
    /* D7B8 8001CFB8 0980033C */  lui        $v1, %hi(D_800907D8)
    /* D7BC 8001CFBC CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* D7C0 8001CFC0 D8076324 */  addiu      $v1, $v1, %lo(D_800907D8)
    /* D7C4 8001CFC4 80100400 */  sll        $v0, $a0, 2
    /* D7C8 8001CFC8 21104400 */  addu       $v0, $v0, $a0
    /* D7CC 8001CFCC 80100200 */  sll        $v0, $v0, 2
    /* D7D0 8001CFD0 2110A200 */  addu       $v0, $a1, $v0
    /* D7D4 8001CFD4 21104300 */  addu       $v0, $v0, $v1
    /* D7D8 8001CFD8 1A80033C */  lui        $v1, %hi(D_801A7AD8)
    /* D7DC 8001CFDC 00005090 */  lbu        $s0, 0x0($v0)
    /* D7E0 8001CFE0 D87A7524 */  addiu      $s5, $v1, %lo(D_801A7AD8)
    /* D7E4 8001CFE4 C0101000 */  sll        $v0, $s0, 3
    /* D7E8 8001CFE8 23105000 */  subu       $v0, $v0, $s0
    /* D7EC 8001CFEC 80100200 */  sll        $v0, $v0, 2
    /* D7F0 8001CFF0 21205500 */  addu       $a0, $v0, $s5
    /* D7F4 8001CFF4 16008294 */  lhu        $v0, 0x16($a0)
    /* D7F8 8001CFF8 940290A3 */  sb         $s0, %gp_rel(D_8009B19C)($gp)
    /* D7FC 8001CFFC 00804230 */  andi       $v0, $v0, 0x8000
    /* D800 8001D000 11004010 */  beqz       $v0, .L8001D048
    /* D804 8001D004 21880000 */   addu      $s1, $zero, $zero
    /* D808 8001D008 08008584 */  lh         $a1, 0x8($a0)
    /* D80C 8001D00C 0A008684 */  lh         $a2, 0xA($a0)
    /* D810 8001D010 0000938C */  lw         $s3, 0x0($a0)
    /* D814 8001D014 C15F000C */  jal        func_80017F04
    /* D818 8001D018 01001124 */   addiu     $s1, $zero, 0x1
    /* D81C 8001D01C 0F80033C */  lui        $v1, %hi(D_800E9EF0)
    /* D820 8001D020 F09E62AC */  sw         $v0, %lo(D_800E9EF0)($v1)
    /* D824 8001D024 6A006292 */  lbu        $v0, 0x6A($s3)
    /* D828 8001D028 00000000 */  nop
    /* D82C 8001D02C C0200200 */  sll        $a0, $v0, 3
    /* D830 8001D030 23208200 */  subu       $a0, $a0, $v0
    /* D834 8001D034 80200400 */  sll        $a0, $a0, 2
    /* D838 8001D038 4592000C */  jal        func_80024914
    /* D83C 8001D03C 21209500 */   addu      $a0, $a0, $s5
    /* D840 8001D040 20740008 */  j          .L8001D080
    /* D844 8001D044 00000000 */   nop
  .L8001D048:
    /* D848 8001D048 15004292 */  lbu        $v0, 0x15($s2)
    /* D84C 8001D04C 00000000 */  nop
    /* D850 8001D050 1D004014 */  bnez       $v0, .L8001D0C8
    /* D854 8001D054 01001024 */   addiu     $s0, $zero, 0x1
    /* D858 8001D058 0000828E */  lw         $v0, 0x0($s4)
    /* D85C 8001D05C 00000000 */  nop
    /* D860 8001D060 68004390 */  lbu        $v1, 0x68($v0)
    /* D864 8001D064 17000224 */  addiu      $v0, $zero, 0x17
    /* D868 8001D068 05006214 */  bne        $v1, $v0, .L8001D080
    /* D86C 8001D06C 02000224 */   addiu     $v0, $zero, 0x2
    /* D870 8001D070 1000C380 */  lb         $v1, 0x10($a2)
    /* D874 8001D074 00000000 */  nop
    /* D878 8001D078 68006210 */  beq        $v1, $v0, .L8001D21C
    /* D87C 8001D07C 00000000 */   nop
  .L8001D080:
    /* D880 8001D080 15004292 */  lbu        $v0, 0x15($s2)
    /* D884 8001D084 00000000 */  nop
    /* D888 8001D088 0F004014 */  bnez       $v0, .L8001D0C8
    /* D88C 8001D08C 01001024 */   addiu     $s0, $zero, 0x1
    /* D890 8001D090 0000828E */  lw         $v0, 0x0($s4)
    /* D894 8001D094 01000324 */  addiu      $v1, $zero, 0x1
    /* D898 8001D098 090083A2 */  sb         $v1, 0x9($s4)
    /* D89C 8001D09C 21004290 */  lbu        $v0, 0x21($v0)
    /* D8A0 8001D0A0 00000000 */  nop
    /* D8A4 8001D0A4 09004010 */  beqz       $v0, .L8001D0CC
    /* D8A8 8001D0A8 0F80023C */   lui       $v0, %hi(D_800EA030)
    /* D8AC 8001D0AC C002838F */  lw         $v1, %gp_rel(D_8009B1C8)($gp)
    /* D8B0 8001D0B0 00000000 */  nop
    /* D8B4 8001D0B4 04006290 */  lbu        $v0, 0x4($v1)
    /* D8B8 8001D0B8 00000000 */  nop
    /* D8BC 8001D0BC 01004224 */  addiu      $v0, $v0, 0x1
    /* D8C0 8001D0C0 040062A0 */  sb         $v0, 0x4($v1)
    /* D8C4 8001D0C4 01001024 */  addiu      $s0, $zero, 0x1
  .L8001D0C8:
    /* D8C8 8001D0C8 0F80023C */  lui        $v0, %hi(D_800EA030)
  .L8001D0CC:
    /* D8CC 8001D0CC 30A04924 */  addiu      $t1, $v0, %lo(D_800EA030)
    /* D8D0 8001D0D0 FFFF0724 */  addiu      $a3, $zero, -0x1
    /* D8D4 8001D0D4 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* D8D8 8001D0D8 F09E4824 */  addiu      $t0, $v0, %lo(D_800E9EF0)
    /* D8DC 8001D0DC 21280000 */  addu       $a1, $zero, $zero
  .L8001D0E0:
    /* D8E0 8001D0E0 21202001 */  addu       $a0, $t1, $zero
    /* D8E4 8001D0E4 80101100 */  sll        $v0, $s1, 2
    /* D8E8 8001D0E8 09008390 */  lbu        $v1, 0x9($a0)
    /* D8EC 8001D0EC 00000000 */  nop
    /* D8F0 8001D0F0 04007014 */  bne        $v1, $s0, .L8001D104
    /* D8F4 8001D0F4 21304800 */   addu      $a2, $v0, $t0
    /* D8F8 8001D0F8 C002828F */  lw         $v0, %gp_rel(D_8009B1C8)($gp)
    /* D8FC 8001D0FC 50740008 */  j          .L8001D140
    /* D900 8001D100 1A0047A0 */   sb        $a3, 0x1A($v0)
  .L8001D104:
    /* D904 8001D104 0100A524 */  addiu      $a1, $a1, 0x1
  .L8001D108:
    /* D908 8001D108 0500A228 */  slti       $v0, $a1, 0x5
    /* D90C 8001D10C 03004014 */  bnez       $v0, .L8001D11C
    /* D910 8001D110 0C008424 */   addiu     $a0, $a0, 0xC
    /* D914 8001D114 53740008 */  j          .L8001D14C
    /* D918 8001D118 08001024 */   addiu     $s0, $zero, 0x8
  .L8001D11C:
    /* D91C 8001D11C 09008290 */  lbu        $v0, 0x9($a0)
    /* D920 8001D120 00000000 */  nop
    /* D924 8001D124 F8FF5014 */  bne        $v0, $s0, .L8001D108
    /* D928 8001D128 0100A524 */   addiu     $a1, $a1, 0x1
    /* D92C 8001D12C FFFFA524 */  addiu      $a1, $a1, -0x1
    /* D930 8001D130 C002828F */  lw         $v0, %gp_rel(D_8009B1C8)($gp)
    /* D934 8001D134 00000000 */  nop
    /* D938 8001D138 21104500 */  addu       $v0, $v0, $a1
    /* D93C 8001D13C 1A0047A0 */  sb         $a3, 0x1A($v0)
  .L8001D140:
    /* D940 8001D140 0000828C */  lw         $v0, 0x0($a0)
    /* D944 8001D144 01003126 */  addiu      $s1, $s1, 0x1
    /* D948 8001D148 0000C2AC */  sw         $v0, 0x0($a2)
  .L8001D14C:
    /* D94C 8001D14C 01001026 */  addiu      $s0, $s0, 0x1
    /* D950 8001D150 0600022A */  slti       $v0, $s0, 0x6
    /* D954 8001D154 E2FF4014 */  bnez       $v0, .L8001D0E0
    /* D958 8001D158 21280000 */   addu      $a1, $zero, $zero
    /* D95C 8001D15C 06000224 */  addiu      $v0, $zero, 0x6
    /* D960 8001D160 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D964 8001D164 87740008 */  j          .L8001D21C
    /* D968 8001D168 00000000 */   nop
  jlabel .L8001D16C
    /* D96C 8001D16C 6C028493 */  lbu        $a0, %gp_rel(D_8009B174)($gp)
    /* D970 8001D170 00000000 */  nop
    /* D974 8001D174 80008230 */  andi       $v0, $a0, 0x80
    /* D978 8001D178 0C004014 */  bnez       $v0, .L8001D1AC
    /* D97C 8001D17C 0C000224 */   addiu     $v0, $zero, 0xC
    /* D980 8001D180 CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* D984 8001D184 5A0282A7 */  sh         $v0, %gp_rel(D_8009B162)($gp)
    /* D988 8001D188 80008234 */  ori        $v0, $a0, 0x80
    /* D98C 8001D18C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D990 8001D190 C0100300 */  sll        $v0, $v1, 3
    /* D994 8001D194 23104300 */  subu       $v0, $v0, $v1
    /* D998 8001D198 00110200 */  sll        $v0, $v0, 4
    /* D99C 8001D19C 0F80033C */  lui        $v1, %hi(D_800E9F48)
    /* D9A0 8001D1A0 489F6324 */  addiu      $v1, $v1, %lo(D_800E9F48)
    /* D9A4 8001D1A4 21104300 */  addu       $v0, $v0, $v1
    /* D9A8 8001D1A8 AC0282AF */  sw         $v0, %gp_rel(D_8009B1B4)($gp)
  .L8001D1AC:
    /* D9AC 8001D1AC 5A028297 */  lhu        $v0, %gp_rel(D_8009B162)($gp)
    /* D9B0 8001D1B0 00000000 */  nop
    /* D9B4 8001D1B4 19004014 */  bnez       $v0, .L8001D21C
    /* D9B8 8001D1B8 07000224 */   addiu     $v0, $zero, 0x7
    /* D9BC 8001D1BC 86740008 */  j          .L8001D218
    /* D9C0 8001D1C0 00000000 */   nop
  jlabel .L8001D1C4
    /* D9C4 8001D1C4 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* D9C8 8001D1C8 00000000 */  nop
    /* D9CC 8001D1CC 80006230 */  andi       $v0, $v1, 0x80
    /* D9D0 8001D1D0 0D004014 */  bnez       $v0, .L8001D208
    /* D9D4 8001D1D4 80006234 */   ori       $v0, $v1, 0x80
    /* D9D8 8001D1D8 CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* D9DC 8001D1DC 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* D9E0 8001D1E0 08000224 */  addiu      $v0, $zero, 0x8
    /* D9E4 8001D1E4 000080AE */  sw         $zero, 0x0($s4)
    /* D9E8 8001D1E8 5A0282A7 */  sh         $v0, %gp_rel(D_8009B162)($gp)
    /* D9EC 8001D1EC C0100300 */  sll        $v0, $v1, 3
    /* D9F0 8001D1F0 23104300 */  subu       $v0, $v0, $v1
    /* D9F4 8001D1F4 00110200 */  sll        $v0, $v0, 4
    /* D9F8 8001D1F8 0F80033C */  lui        $v1, %hi(D_800E9F10)
    /* D9FC 8001D1FC 109F6324 */  addiu      $v1, $v1, %lo(D_800E9F10)
    /* DA00 8001D200 21104300 */  addu       $v0, $v0, $v1
    /* DA04 8001D204 AC0282AF */  sw         $v0, %gp_rel(D_8009B1B4)($gp)
  .L8001D208:
    /* DA08 8001D208 5A028297 */  lhu        $v0, %gp_rel(D_8009B162)($gp)
    /* DA0C 8001D20C 00000000 */  nop
    /* DA10 8001D210 02004014 */  bnez       $v0, .L8001D21C
    /* DA14 8001D214 06000224 */   addiu     $v0, $zero, 0x6
  .L8001D218:
    /* DA18 8001D218 320382A7 */  sh         $v0, %gp_rel(D_8009B23A)($gp)
  .L8001D21C:
    /* DA1C 8001D21C 3800BF8F */  lw         $ra, 0x38($sp)
    /* DA20 8001D220 3400B58F */  lw         $s5, 0x34($sp)
    /* DA24 8001D224 3000B48F */  lw         $s4, 0x30($sp)
    /* DA28 8001D228 2C00B38F */  lw         $s3, 0x2C($sp)
    /* DA2C 8001D22C 2800B28F */  lw         $s2, 0x28($sp)
    /* DA30 8001D230 2400B18F */  lw         $s1, 0x24($sp)
    /* DA34 8001D234 2000B08F */  lw         $s0, 0x20($sp)
    /* DA38 8001D238 0800E003 */  jr         $ra
    /* DA3C 8001D23C 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8001BD88
