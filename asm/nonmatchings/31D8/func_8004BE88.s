nonmatching func_8004BE88, 0x224

glabel func_8004BE88
    /* 3C688 8004BE88 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3C68C 8004BE8C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3C690 8004BE90 21888000 */  addu       $s1, $a0, $zero
    /* 3C694 8004BE94 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 3C698 8004BE98 51000224 */  addiu      $v0, $zero, 0x51
    /* 3C69C 8004BE9C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3C6A0 8004BEA0 1B00A210 */  beq        $a1, $v0, .L8004BF10
    /* 3C6A4 8004BEA4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3C6A8 8004BEA8 5200A228 */  slti       $v0, $a1, 0x52
    /* 3C6AC 8004BEAC 09004010 */  beqz       $v0, .L8004BED4
    /* 3C6B0 8004BEB0 58000224 */   addiu     $v0, $zero, 0x58
    /* 3C6B4 8004BEB4 7300A004 */  bltz       $a1, .L8004C084
    /* 3C6B8 8004BEB8 1000A228 */   slti      $v0, $a1, 0x10
    /* 3C6BC 8004BEBC 71004014 */  bnez       $v0, .L8004C084
    /* 3C6C0 8004BEC0 2F000224 */   addiu     $v0, $zero, 0x2F
    /* 3C6C4 8004BEC4 1000A210 */  beq        $a1, $v0, .L8004BF08
    /* 3C6C8 8004BEC8 01000224 */   addiu     $v0, $zero, 0x1
    /* 3C6CC 8004BECC 21300108 */  j          .L8004C084
    /* 3C6D0 8004BED0 00000000 */   nop
  .L8004BED4:
    /* 3C6D4 8004BED4 5D00A210 */  beq        $a1, $v0, .L8004C04C
    /* 3C6D8 8004BED8 5900A228 */   slti      $v0, $a1, 0x59
    /* 3C6DC 8004BEDC 05004010 */  beqz       $v0, .L8004BEF4
    /* 3C6E0 8004BEE0 54000224 */   addiu     $v0, $zero, 0x54
    /* 3C6E4 8004BEE4 5100A210 */  beq        $a1, $v0, .L8004C02C
    /* 3C6E8 8004BEE8 00000000 */   nop
    /* 3C6EC 8004BEEC 21300108 */  j          .L8004C084
    /* 3C6F0 8004BEF0 00000000 */   nop
  .L8004BEF4:
    /* 3C6F4 8004BEF4 59000224 */  addiu      $v0, $zero, 0x59
    /* 3C6F8 8004BEF8 5A00A210 */  beq        $a1, $v0, .L8004C064
    /* 3C6FC 8004BEFC 00000000 */   nop
    /* 3C700 8004BF00 21300108 */  j          .L8004C084
    /* 3C704 8004BF04 00000000 */   nop
  .L8004BF08:
    /* 3C708 8004BF08 1D300108 */  j          .L8004C074
    /* 3C70C 8004BF0C 240022A2 */   sb        $v0, 0x24($s1)
  .L8004BF10:
    /* 3C710 8004BF10 B92E010C */  jal        func_8004BAE4
    /* 3C714 8004BF14 21202002 */   addu      $a0, $s1, $zero
    /* 3C718 8004BF18 00840200 */  sll        $s0, $v0, 16
    /* 3C71C 8004BF1C B92E010C */  jal        func_8004BAE4
    /* 3C720 8004BF20 21202002 */   addu      $a0, $s1, $zero
    /* 3C724 8004BF24 00120200 */  sll        $v0, $v0, 8
    /* 3C728 8004BF28 25800202 */  or         $s0, $s0, $v0
    /* 3C72C 8004BF2C B92E010C */  jal        func_8004BAE4
    /* 3C730 8004BF30 21202002 */   addu      $a0, $s1, $zero
    /* 3C734 8004BF34 25800202 */  or         $s0, $s0, $v0
    /* 3C738 8004BF38 9303023C */  lui        $v0, (0x3938700 >> 16)
    /* 3C73C 8004BF3C 0A80043C */  lui        $a0, %hi(D_8009B458)
    /* 3C740 8004BF40 58B4848C */  lw         $a0, %lo(D_8009B458)($a0)
    /* 3C744 8004BF44 00874234 */  ori        $v0, $v0, (0x3938700 & 0xFFFF)
    /* 3C748 8004BF48 080890AC */  sw         $s0, 0x808($a0)
    /* 3C74C 8004BF4C 1B005000 */  divu       $zero, $v0, $s0
    /* 3C750 8004BF50 02000016 */  bnez       $s0, .L8004BF5C
    /* 3C754 8004BF54 00000000 */   nop
    /* 3C758 8004BF58 0D000700 */  break      7
  .L8004BF5C:
    /* 3C75C 8004BF5C 12800000 */  mflo       $s0
    /* 3C760 8004BF60 F01C033C */  lui        $v1, (0x1CF06ADB >> 16)
    /* 3C764 8004BF64 DB6A6334 */  ori        $v1, $v1, (0x1CF06ADB & 0xFFFF)
    /* 3C768 8004BF68 40101000 */  sll        $v0, $s0, 1
    /* 3C76C 8004BF6C 21105000 */  addu       $v0, $v0, $s0
    /* 3C770 8004BF70 C0100200 */  sll        $v0, $v0, 3
    /* 3C774 8004BF74 21105000 */  addu       $v0, $v0, $s0
    /* 3C778 8004BF78 80100200 */  sll        $v0, $v0, 2
    /* 3C77C 8004BF7C 19004300 */  multu      $v0, $v1
    /* 3C780 8004BF80 10180000 */  mfhi       $v1
    /* 3C784 8004BF84 23104300 */  subu       $v0, $v0, $v1
    /* 3C788 8004BF88 42100200 */  srl        $v0, $v0, 1
    /* 3C78C 8004BF8C 21186200 */  addu       $v1, $v1, $v0
    /* 3C790 8004BF90 82810300 */  srl        $s0, $v1, 6
    /* 3C794 8004BF94 0001022E */  sltiu      $v0, $s0, 0x100
    /* 3C798 8004BF98 02004014 */  bnez       $v0, .L8004BFA4
    /* 3C79C 8004BF9C 00000000 */   nop
    /* 3C7A0 8004BFA0 FF001024 */  addiu      $s0, $zero, 0xFF
  .L8004BFA4:
    /* 3C7A4 8004BFA4 FC078394 */  lhu        $v1, 0x7FC($a0)
    /* 3C7A8 8004BFA8 1E000224 */  addiu      $v0, $zero, 0x1E
    /* 3C7AC 8004BFAC 0C006210 */  beq        $v1, $v0, .L8004BFE0
    /* 3C7B0 8004BFB0 1F006228 */   slti      $v0, $v1, 0x1F
    /* 3C7B4 8004BFB4 05004010 */  beqz       $v0, .L8004BFCC
    /* 3C7B8 8004BFB8 18000224 */   addiu     $v0, $zero, 0x18
    /* 3C7BC 8004BFBC 06006210 */  beq        $v1, $v0, .L8004BFD8
    /* 3C7C0 8004BFC0 00000000 */   nop
    /* 3C7C4 8004BFC4 F92F0108 */  j          .L8004BFE4
    /* 3C7C8 8004BFC8 00000000 */   nop
  .L8004BFCC:
    /* 3C7CC 8004BFCC 3C000224 */  addiu      $v0, $zero, 0x3C
    /* 3C7D0 8004BFD0 04006214 */  bne        $v1, $v0, .L8004BFE4
    /* 3C7D4 8004BFD4 00000000 */   nop
  .L8004BFD8:
    /* 3C7D8 8004BFD8 F92F0108 */  j          .L8004BFE4
    /* 3C7DC 8004BFDC 42801000 */   srl       $s0, $s0, 1
  .L8004BFE0:
    /* 3C7E0 8004BFE0 82801000 */  srl        $s0, $s0, 2
  .L8004BFE4:
    /* 3C7E4 8004BFE4 0A80053C */  lui        $a1, %hi(D_8009B458)
    /* 3C7E8 8004BFE8 58B4A58C */  lw         $a1, %lo(D_8009B458)($a1)
    /* 3C7EC 8004BFEC 00000000 */  nop
    /* 3C7F0 8004BFF0 FA07A294 */  lhu        $v0, 0x7FA($a1)
    /* 3C7F4 8004BFF4 00000000 */  nop
    /* 3C7F8 8004BFF8 27004010 */  beqz       $v0, .L8004C098
    /* 3C7FC 8004BFFC 21180000 */   addu      $v1, $zero, $zero
    /* 3C800 8004C000 21206000 */  addu       $a0, $v1, $zero
  .L8004C004:
    /* 3C804 8004C004 2110A400 */  addu       $v0, $a1, $a0
    /* 3C808 8004C008 2E0550A4 */  sh         $s0, 0x52E($v0)
    /* 3C80C 8004C00C 2C0550A4 */  sh         $s0, 0x52C($v0)
    /* 3C810 8004C010 FA07A294 */  lhu        $v0, 0x7FA($a1)
    /* 3C814 8004C014 01006324 */  addiu      $v1, $v1, 0x1
    /* 3C818 8004C018 2B106200 */  sltu       $v0, $v1, $v0
    /* 3C81C 8004C01C F9FF4014 */  bnez       $v0, .L8004C004
    /* 3C820 8004C020 2C008424 */   addiu     $a0, $a0, 0x2C
    /* 3C824 8004C024 26300108 */  j          .L8004C098
    /* 3C828 8004C028 00000000 */   nop
  .L8004C02C:
    /* 3C82C 8004C02C B92E010C */  jal        func_8004BAE4
    /* 3C830 8004C030 21202002 */   addu      $a0, $s1, $zero
    /* 3C834 8004C034 B92E010C */  jal        func_8004BAE4
    /* 3C838 8004C038 21202002 */   addu      $a0, $s1, $zero
    /* 3C83C 8004C03C B92E010C */  jal        func_8004BAE4
    /* 3C840 8004C040 21202002 */   addu      $a0, $s1, $zero
    /* 3C844 8004C044 19300108 */  j          .L8004C064
    /* 3C848 8004C048 00000000 */   nop
  .L8004C04C:
    /* 3C84C 8004C04C B92E010C */  jal        func_8004BAE4
    /* 3C850 8004C050 21202002 */   addu      $a0, $s1, $zero
    /* 3C854 8004C054 0B2F010C */  jal        func_8004BC2C
    /* 3C858 8004C058 21202002 */   addu      $a0, $s1, $zero
    /* 3C85C 8004C05C 26300108 */  j          .L8004C098
    /* 3C860 8004C060 00000000 */   nop
  .L8004C064:
    /* 3C864 8004C064 B92E010C */  jal        func_8004BAE4
    /* 3C868 8004C068 21202002 */   addu      $a0, $s1, $zero
    /* 3C86C 8004C06C B92E010C */  jal        func_8004BAE4
    /* 3C870 8004C070 21202002 */   addu      $a0, $s1, $zero
  .L8004C074:
    /* 3C874 8004C074 B92E010C */  jal        func_8004BAE4
    /* 3C878 8004C078 21202002 */   addu      $a0, $s1, $zero
    /* 3C87C 8004C07C 26300108 */  j          .L8004C098
    /* 3C880 8004C080 00000000 */   nop
  .L8004C084:
    /* 3C884 8004C084 CD2E010C */  jal        func_8004BB34
    /* 3C888 8004C088 21202002 */   addu      $a0, $s1, $zero
    /* 3C88C 8004C08C 21202002 */  addu       $a0, $s1, $zero
    /* 3C890 8004C090 9B2F010C */  jal        func_8004BE6C
    /* 3C894 8004C094 21284000 */   addu      $a1, $v0, $zero
  .L8004C098:
    /* 3C898 8004C098 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3C89C 8004C09C 1400B18F */  lw         $s1, 0x14($sp)
    /* 3C8A0 8004C0A0 1000B08F */  lw         $s0, 0x10($sp)
    /* 3C8A4 8004C0A4 0800E003 */  jr         $ra
    /* 3C8A8 8004C0A8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8004BE88
