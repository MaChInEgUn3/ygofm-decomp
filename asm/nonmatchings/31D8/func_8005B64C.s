nonmatching func_8005B64C, 0x210

glabel func_8005B64C
    /* 4BE4C 8005B64C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4BE50 8005B650 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4BE54 8005B654 21808000 */  addu       $s0, $a0, $zero
    /* 4BE58 8005B658 0500A22C */  sltiu      $v0, $a1, 0x5
    /* 4BE5C 8005B65C 7B004010 */  beqz       $v0, .L8005B84C
    /* 4BE60 8005B660 1C00BFAF */   sw        $ra, 0x1C($sp)
    /* 4BE64 8005B664 0180023C */  lui        $v0, %hi(jtbl_800117D8)
    /* 4BE68 8005B668 D8174224 */  addiu      $v0, $v0, %lo(jtbl_800117D8)
    /* 4BE6C 8005B66C 80180500 */  sll        $v1, $a1, 2
    /* 4BE70 8005B670 21186200 */  addu       $v1, $v1, $v0
    /* 4BE74 8005B674 0000628C */  lw         $v0, 0x0($v1)
    /* 4BE78 8005B678 00000000 */  nop
    /* 4BE7C 8005B67C 08004000 */  jr         $v0
    /* 4BE80 8005B680 00000000 */   nop
  jlabel .L8005B684
    /* 4BE84 8005B684 DDFF043C */  lui        $a0, (0xFFDDFFFF >> 16)
    /* 4BE88 8005B688 FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 4BE8C 8005B68C 00020224 */  addiu      $v0, $zero, 0x200
    /* 4BE90 8005B690 300002A6 */  sh         $v0, 0x30($s0)
    /* 4BE94 8005B694 00010224 */  addiu      $v0, $zero, 0x100
    /* 4BE98 8005B698 320002A6 */  sh         $v0, 0x32($s0)
    /* 4BE9C 8005B69C 40000224 */  addiu      $v0, $zero, 0x40
    /* 4BEA0 8005B6A0 040002A6 */  sh         $v0, 0x4($s0)
    /* 4BEA4 8005B6A4 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 4BEA8 8005B6A8 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 4BEAC 8005B6AC 10000324 */  addiu      $v1, $zero, 0x10
    /* 4BEB0 8005B6B0 060003A6 */  sh         $v1, 0x6($s0)
    /* 4BEB4 8005B6B4 24104400 */  and        $v0, $v0, $a0
    /* 4BEB8 8005B6B8 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 4BEBC 8005B6BC F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 4BEC0 8005B6C0 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 4BEC4 8005B6C4 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 4BEC8 8005B6C8 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 4BECC 8005B6CC 25104300 */  or         $v0, $v0, $v1
    /* 4BED0 8005B6D0 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 4BED4 8005B6D4 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 4BED8 8005B6D8 02000224 */  addiu      $v0, $zero, 0x2
    /* 4BEDC 8005B6DC 460002A2 */  sb         $v0, 0x46($s0)
    /* 4BEE0 8005B6E0 0A80023C */  lui        $v0, %hi(D_8009B118)
    /* 4BEE4 8005B6E4 18B1428C */  lw         $v0, %lo(D_8009B118)($v0)
    /* 4BEE8 8005B6E8 0200033C */  lui        $v1, (0x20000 >> 16)
    /* 4BEEC 8005B6EC 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 4BEF0 8005B6F0 080002AE */  sw         $v0, 0x8($s0)
    /* 4BEF4 8005B6F4 00084224 */  addiu      $v0, $v0, 0x800
    /* 4BEF8 8005B6F8 136E0108 */  j          .L8005B84C
    /* 4BEFC 8005B6FC 0C0002AE */   sw        $v0, 0xC($s0)
  jlabel .L8005B700
    /* 4BF00 8005B700 DDFF043C */  lui        $a0, (0xFFDDFFFF >> 16)
    /* 4BF04 8005B704 FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 4BF08 8005B708 80030224 */  addiu      $v0, $zero, 0x380
    /* 4BF0C 8005B70C 300002A6 */  sh         $v0, 0x30($s0)
    /* 4BF10 8005B710 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 4BF14 8005B714 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 4BF18 8005B718 40000324 */  addiu      $v1, $zero, 0x40
    /* 4BF1C 8005B71C 320000A6 */  sh         $zero, 0x32($s0)
    /* 4BF20 8005B720 040003A6 */  sh         $v1, 0x4($s0)
    /* 4BF24 8005B724 24104400 */  and        $v0, $v0, $a0
    /* 4BF28 8005B728 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 4BF2C 8005B72C F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 4BF30 8005B730 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 4BF34 8005B734 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 4BF38 8005B738 0100043C */  lui        $a0, (0x10000 >> 16)
    /* 4BF3C 8005B73C 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 4BF40 8005B740 25104400 */  or         $v0, $v0, $a0
    /* 4BF44 8005B744 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 4BF48 8005B748 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 4BF4C 8005B74C 02000224 */  addiu      $v0, $zero, 0x2
    /* 4BF50 8005B750 460002A2 */  sb         $v0, 0x46($s0)
    /* 4BF54 8005B754 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 4BF58 8005B758 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 4BF5C 8005B75C 10000224 */  addiu      $v0, $zero, 0x10
    /* 4BF60 8005B760 060002A6 */  sh         $v0, 0x6($s0)
    /* 4BF64 8005B764 080003AE */  sw         $v1, 0x8($s0)
    /* 4BF68 8005B768 00086324 */  addiu      $v1, $v1, 0x800
    /* 4BF6C 8005B76C 136E0108 */  j          .L8005B84C
    /* 4BF70 8005B770 0C0003AE */   sw        $v1, 0xC($s0)
  jlabel .L8005B774
    /* 4BF74 8005B774 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 4BF78 8005B778 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 4BF7C 8005B77C 1E80023C */  lui        $v0, %hi(D_801DD000)
    /* 4BF80 8005B780 00D04224 */  addiu      $v0, $v0, %lo(D_801DD000)
    /* 4BF84 8005B784 0C0002AE */  sw         $v0, 0xC($s0)
    /* 4BF88 8005B788 080002AE */  sw         $v0, 0x8($s0)
    /* 4BF8C 8005B78C 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 4BF90 8005B790 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 4BF94 8005B794 0D6E0108 */  j          .L8005B834
    /* 4BF98 8005B798 00100324 */   addiu     $v1, $zero, 0x1000
  jlabel .L8005B79C
    /* 4BF9C 8005B79C 0A80023C */  lui        $v0, %hi(D_8009B058)
    /* 4BFA0 8005B7A0 1E80053C */  lui        $a1, %hi(D_801DD000)
    /* 4BFA4 8005B7A4 1000A427 */  addiu      $a0, $sp, 0x10
    /* 4BFA8 8005B7A8 58B04924 */  addiu      $t1, $v0, %lo(D_8009B058)
    /* 4BFAC 8005B7AC 03002689 */  lwl        $a2, 0x3($t1)
    /* 4BFB0 8005B7B0 00002699 */  lwr        $a2, 0x0($t1)
    /* 4BFB4 8005B7B4 07002789 */  lwl        $a3, 0x7($t1)
    /* 4BFB8 8005B7B8 04002799 */  lwr        $a3, 0x4($t1)
    /* 4BFBC 8005B7BC 1300A6AB */  swl        $a2, 0x13($sp)
    /* 4BFC0 8005B7C0 1000A6BB */  swr        $a2, 0x10($sp)
    /* 4BFC4 8005B7C4 1700A7AB */  swl        $a3, 0x17($sp)
    /* 4BFC8 8005B7C8 1400A7BB */  swr        $a3, 0x14($sp)
    /* 4BFCC 8005B7CC 7A07020C */  jal        func_80081DE8
    /* 4BFD0 8005B7D0 00D0A524 */   addiu     $a1, $a1, %lo(D_801DD000)
    /* 4BFD4 8005B7D4 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 4BFD8 8005B7D8 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 4BFDC 8005B7DC 00800234 */  ori        $v0, $zero, 0x8000
    /* 4BFE0 8005B7E0 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 4BFE4 8005B7E4 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 4BFE8 8005B7E8 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 4BFEC 8005B7EC 0180033C */  lui        $v1, %hi(D_8001002C)
    /* 4BFF0 8005B7F0 2C00638C */  lw         $v1, %lo(D_8001002C)($v1)
    /* 4BFF4 8005B7F4 24104400 */  and        $v0, $v0, $a0
    /* 4BFF8 8005B7F8 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 4BFFC 8005B7FC F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 4C000 8005B800 01000224 */  addiu      $v0, $zero, 0x1
    /* 4C004 8005B804 0C0003AE */  sw         $v1, 0xC($s0)
    /* 4C008 8005B808 126E0108 */  j          .L8005B848
    /* 4C00C 8005B80C 080003AE */   sw        $v1, 0x8($s0)
  jlabel .L8005B810
    /* 4C010 8005B810 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 4C014 8005B814 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 4C018 8005B818 1B80023C */  lui        $v0, %hi(D_801AF800)
    /* 4C01C 8005B81C 00F84224 */  addiu      $v0, $v0, %lo(D_801AF800)
    /* 4C020 8005B820 0C0002AE */  sw         $v0, 0xC($s0)
    /* 4C024 8005B824 080002AE */  sw         $v0, 0x8($s0)
    /* 4C028 8005B828 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 4C02C 8005B82C F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 4C030 8005B830 00080324 */  addiu      $v1, $zero, 0x800
  .L8005B834:
    /* 4C034 8005B834 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 4C038 8005B838 24104400 */  and        $v0, $v0, $a0
    /* 4C03C 8005B83C 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 4C040 8005B840 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 4C044 8005B844 01000224 */  addiu      $v0, $zero, 0x1
  .L8005B848:
    /* 4C048 8005B848 460002A2 */  sb         $v0, 0x46($s0)
  .L8005B84C:
    /* 4C04C 8005B84C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4C050 8005B850 1800B08F */  lw         $s0, 0x18($sp)
    /* 4C054 8005B854 0800E003 */  jr         $ra
    /* 4C058 8005B858 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8005B64C
