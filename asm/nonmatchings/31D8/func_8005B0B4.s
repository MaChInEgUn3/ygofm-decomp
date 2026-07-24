nonmatching func_8005B0B4, 0x1AC

glabel func_8005B0B4
    /* 4B8B4 8005B0B4 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 4B8B8 8005B0B8 4000B6AF */  sw         $s6, 0x40($sp)
    /* 4B8BC 8005B0BC 21B08000 */  addu       $s6, $a0, $zero
    /* 4B8C0 8005B0C0 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4B8C4 8005B0C4 5800A28F */  lw         $v0, 0x58($sp)
    /* 4B8C8 8005B0C8 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 4B8CC 8005B0CC 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 4B8D0 8005B0D0 5C00B597 */  lhu        $s5, 0x5C($sp)
    /* 4B8D4 8005B0D4 FF00C630 */  andi       $a2, $a2, 0xFF
    /* 4B8D8 8005B0D8 3000B2AF */  sw         $s2, 0x30($sp)
    /* 4B8DC 8005B0DC 6000B293 */  lbu        $s2, 0x60($sp)
    /* 4B8E0 8005B0E0 FF00E730 */  andi       $a3, $a3, 0xFF
    /* 4B8E4 8005B0E4 4400BFAF */  sw         $ra, 0x44($sp)
    /* 4B8E8 8005B0E8 3800B4AF */  sw         $s4, 0x38($sp)
    /* 4B8EC 8005B0EC 3400B3AF */  sw         $s3, 0x34($sp)
    /* 4B8F0 8005B0F0 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 4B8F4 8005B0F4 2800B0AF */  sw         $s0, 0x28($sp)
    /* 4B8F8 8005B0F8 08005430 */  andi       $s4, $v0, 0x8
    /* 4B8FC 8005B0FC 07005130 */  andi       $s1, $v0, 0x7
    /* 4B900 8005B100 FF003032 */  andi       $s0, $s1, 0xFF
    /* 4B904 8005B104 0600023A */  xori       $v0, $s0, 0x6
    /* 4B908 8005B108 0100532C */  sltiu      $s3, $v0, 0x1
    /* 4B90C 8005B10C 636A010C */  jal        func_8005A98C
    /* 4B910 8005B110 1000B2AF */   sw        $s2, 0x10($sp)
    /* 4B914 8005B114 0700102E */  sltiu      $s0, $s0, 0x7
    /* 4B918 8005B118 11000012 */  beqz       $s0, .L8005B160
    /* 4B91C 8005B11C 00000000 */   nop
    /* 4B920 8005B120 0C008012 */  beqz       $s4, .L8005B154
    /* 4B924 8005B124 21202002 */   addu      $a0, $s1, $zero
    /* 4B928 8005B128 AA2A023C */  lui        $v0, (0x2AAAAAAB >> 16)
    /* 4B92C 8005B12C ABAA4234 */  ori        $v0, $v0, (0x2AAAAAAB & 0xFFFF)
    /* 4B930 8005B130 03008424 */  addiu      $a0, $a0, 0x3
    /* 4B934 8005B134 18008200 */  mult       $a0, $v0
    /* 4B938 8005B138 C31F0400 */  sra        $v1, $a0, 31
    /* 4B93C 8005B13C 10400000 */  mfhi       $t0
    /* 4B940 8005B140 23180301 */  subu       $v1, $t0, $v1
    /* 4B944 8005B144 40100300 */  sll        $v0, $v1, 1
    /* 4B948 8005B148 21104300 */  addu       $v0, $v0, $v1
    /* 4B94C 8005B14C 40100200 */  sll        $v0, $v0, 1
    /* 4B950 8005B150 23208200 */  subu       $a0, $a0, $v0
  .L8005B154:
    /* 4B954 8005B154 FF008230 */  andi       $v0, $a0, 0xFF
    /* 4B958 8005B158 00130200 */  sll        $v0, $v0, 12
    /* 4B95C 8005B15C 1800A2AF */  sw         $v0, 0x18($sp)
  .L8005B160:
    /* 4B960 8005B160 03006012 */  beqz       $s3, .L8005B170
    /* 4B964 8005B164 FFFFA232 */   andi      $v0, $s5, 0xFFFF
    /* 4B968 8005B168 656C0108 */  j          .L8005B194
    /* 4B96C 8005B16C 1E00A0A7 */   sh        $zero, 0x1E($sp)
  .L8005B170:
    /* 4B970 8005B170 1E00A397 */  lhu        $v1, 0x1E($sp)
    /* 4B974 8005B174 00000000 */  nop
    /* 4B978 8005B178 18006200 */  mult       $v1, $v0
    /* 4B97C 8005B17C 12100000 */  mflo       $v0
    /* 4B980 8005B180 02004104 */  bgez       $v0, .L8005B18C
    /* 4B984 8005B184 00000000 */   nop
    /* 4B988 8005B188 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8005B18C:
    /* 4B98C 8005B18C 03130200 */  sra        $v0, $v0, 12
    /* 4B990 8005B190 1E00A2A7 */  sh         $v0, 0x1E($sp)
  .L8005B194:
    /* 4B994 8005B194 1C00A697 */  lhu        $a2, 0x1C($sp)
    /* 4B998 8005B198 1E00A797 */  lhu        $a3, 0x1E($sp)
    /* 4B99C 8005B19C FF004232 */  andi       $v0, $s2, 0xFF
    /* 4B9A0 8005B1A0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 4B9A4 8005B1A4 1800A58F */  lw         $a1, 0x18($sp)
    /* 4B9A8 8005B1A8 E86A010C */  jal        func_8005ABA0
    /* 4B9AC 8005B1AC 2000A427 */   addiu     $a0, $sp, 0x20
    /* 4B9B0 8005B1B0 0A008012 */  beqz       $s4, .L8005B1DC
    /* 4B9B4 8005B1B4 00000000 */   nop
    /* 4B9B8 8005B1B8 2000A293 */  lbu        $v0, 0x20($sp)
    /* 4B9BC 8005B1BC 2200A393 */  lbu        $v1, 0x22($sp)
    /* 4B9C0 8005B1C0 23104202 */  subu       $v0, $s2, $v0
    /* 4B9C4 8005B1C4 2000A2A3 */  sb         $v0, 0x20($sp)
    /* 4B9C8 8005B1C8 2100A293 */  lbu        $v0, 0x21($sp)
    /* 4B9CC 8005B1CC 23184302 */  subu       $v1, $s2, $v1
    /* 4B9D0 8005B1D0 2200A3A3 */  sb         $v1, 0x22($sp)
    /* 4B9D4 8005B1D4 23104202 */  subu       $v0, $s2, $v0
    /* 4B9D8 8005B1D8 2100A2A3 */  sb         $v0, 0x21($sp)
  .L8005B1DC:
    /* 4B9DC 8005B1DC 2000A293 */  lbu        $v0, 0x20($sp)
    /* 4B9E0 8005B1E0 00000000 */  nop
    /* 4B9E4 8005B1E4 02004014 */  bnez       $v0, .L8005B1F0
    /* 4B9E8 8005B1E8 00000000 */   nop
    /* 4B9EC 8005B1EC 01000224 */  addiu      $v0, $zero, 0x1
  .L8005B1F0:
    /* 4B9F0 8005B1F0 2100A393 */  lbu        $v1, 0x21($sp)
    /* 4B9F4 8005B1F4 00000000 */  nop
    /* 4B9F8 8005B1F8 02006014 */  bnez       $v1, .L8005B204
    /* 4B9FC 8005B1FC 2000A2A3 */   sb        $v0, 0x20($sp)
    /* 4BA00 8005B200 01000324 */  addiu      $v1, $zero, 0x1
  .L8005B204:
    /* 4BA04 8005B204 2200A293 */  lbu        $v0, 0x22($sp)
    /* 4BA08 8005B208 00000000 */  nop
    /* 4BA0C 8005B20C 02004014 */  bnez       $v0, .L8005B218
    /* 4BA10 8005B210 2100A3A3 */   sb        $v1, 0x21($sp)
    /* 4BA14 8005B214 01000224 */  addiu      $v0, $zero, 0x1
  .L8005B218:
    /* 4BA18 8005B218 2200A2A3 */  sb         $v0, 0x22($sp)
    /* 4BA1C 8005B21C 2110C002 */  addu       $v0, $s6, $zero
    /* 4BA20 8005B220 2000A883 */  lb         $t0, 0x20($sp)
    /* 4BA24 8005B224 2100A983 */  lb         $t1, 0x21($sp)
    /* 4BA28 8005B228 2200AA83 */  lb         $t2, 0x22($sp)
    /* 4BA2C 8005B22C 0000C8A2 */  sb         $t0, 0x0($s6)
    /* 4BA30 8005B230 0100C9A2 */  sb         $t1, 0x1($s6)
    /* 4BA34 8005B234 0200CAA2 */  sb         $t2, 0x2($s6)
    /* 4BA38 8005B238 4400BF8F */  lw         $ra, 0x44($sp)
    /* 4BA3C 8005B23C 4000B68F */  lw         $s6, 0x40($sp)
    /* 4BA40 8005B240 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 4BA44 8005B244 3800B48F */  lw         $s4, 0x38($sp)
    /* 4BA48 8005B248 3400B38F */  lw         $s3, 0x34($sp)
    /* 4BA4C 8005B24C 3000B28F */  lw         $s2, 0x30($sp)
    /* 4BA50 8005B250 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 4BA54 8005B254 2800B08F */  lw         $s0, 0x28($sp)
    /* 4BA58 8005B258 0800E003 */  jr         $ra
    /* 4BA5C 8005B25C 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8005B0B4
