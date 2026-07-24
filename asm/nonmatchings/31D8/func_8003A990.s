nonmatching func_8003A990, 0x154

glabel func_8003A990
    /* 2B190 8003A990 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2B194 8003A994 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2B198 8003A998 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2B19C 8003A99C C7E7000C */  jal        func_80039F1C
    /* 2B1A0 8003A9A0 21808000 */   addu      $s0, $a0, $zero
    /* 2B1A4 8003A9A4 1B004014 */  bnez       $v0, .L8003AA14
    /* 2B1A8 8003A9A8 00040224 */   addiu     $v0, $zero, 0x400
    /* 2B1AC 8003A9AC 44000386 */  lh         $v1, 0x44($s0)
    /* 2B1B0 8003A9B0 00000000 */  nop
    /* 2B1B4 8003A9B4 1A004300 */  div        $zero, $v0, $v1
    /* 2B1B8 8003A9B8 02006014 */  bnez       $v1, .L8003A9C4
    /* 2B1BC 8003A9BC 00000000 */   nop
    /* 2B1C0 8003A9C0 0D000700 */  break      7
  .L8003A9C4:
    /* 2B1C4 8003A9C4 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 2B1C8 8003A9C8 04006114 */  bne        $v1, $at, .L8003A9DC
    /* 2B1CC 8003A9CC 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 2B1D0 8003A9D0 02004114 */  bne        $v0, $at, .L8003A9DC
    /* 2B1D4 8003A9D4 00000000 */   nop
    /* 2B1D8 8003A9D8 0D000600 */  break      6
  .L8003A9DC:
    /* 2B1DC 8003A9DC 12100000 */  mflo       $v0
    /* 2B1E0 8003A9E0 00040324 */  addiu      $v1, $zero, 0x400
    /* 2B1E4 8003A9E4 480003A6 */  sh         $v1, 0x48($s0)
    /* 2B1E8 8003A9E8 02004004 */  bltz       $v0, .L8003A9F4
    /* 2B1EC 8003A9EC 4A0002A6 */   sh        $v0, 0x4A($s0)
    /* 2B1F0 8003A9F0 480000A6 */  sh         $zero, 0x48($s0)
  .L8003A9F4:
    /* 2B1F4 8003A9F4 40000296 */  lhu        $v0, 0x40($s0)
    /* 2B1F8 8003A9F8 34000496 */  lhu        $a0, 0x34($s0)
    /* 2B1FC 8003A9FC 42000396 */  lhu        $v1, 0x42($s0)
    /* 2B200 8003AA00 36000596 */  lhu        $a1, 0x36($s0)
    /* 2B204 8003AA04 23104400 */  subu       $v0, $v0, $a0
    /* 2B208 8003AA08 23186500 */  subu       $v1, $v1, $a1
    /* 2B20C 8003AA0C 440002A6 */  sh         $v0, 0x44($s0)
    /* 2B210 8003AA10 460003A6 */  sh         $v1, 0x46($s0)
  .L8003AA14:
    /* 2B214 8003AA14 48000396 */  lhu        $v1, 0x48($s0)
    /* 2B218 8003AA18 4A000296 */  lhu        $v0, 0x4A($s0)
    /* 2B21C 8003AA1C 00000000 */  nop
    /* 2B220 8003AA20 21186200 */  addu       $v1, $v1, $v0
    /* 2B224 8003AA24 FFFF6224 */  addiu      $v0, $v1, -0x1
    /* 2B228 8003AA28 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 2B22C 8003AA2C FF03422C */  sltiu      $v0, $v0, 0x3FF
    /* 2B230 8003AA30 07004014 */  bnez       $v0, .L8003AA50
    /* 2B234 8003AA34 480003A6 */   sh        $v1, 0x48($s0)
    /* 2B238 8003AA38 40000586 */  lh         $a1, 0x40($s0)
    /* 2B23C 8003AA3C 42000686 */  lh         $a2, 0x42($s0)
    /* 2B240 8003AA40 57EA000C */  jal        func_8003A95C
    /* 2B244 8003AA44 21200002 */   addu      $a0, $s0, $zero
    /* 2B248 8003AA48 B5EA0008 */  j          .L8003AAD4
    /* 2B24C 8003AA4C 330000A2 */   sb        $zero, 0x33($s0)
  .L8003AA50:
    /* 2B250 8003AA50 00240300 */  sll        $a0, $v1, 16
    /* 2B254 8003AA54 DC19020C */  jal        func_80086770
    /* 2B258 8003AA58 03240400 */   sra       $a0, $a0, 16
    /* 2B25C 8003AA5C 44000686 */  lh         $a2, 0x44($s0)
    /* 2B260 8003AA60 00000000 */  nop
    /* 2B264 8003AA64 18004600 */  mult       $v0, $a2
    /* 2B268 8003AA68 12180000 */  mflo       $v1
    /* 2B26C 8003AA6C 02006104 */  bgez       $v1, .L8003AA78
    /* 2B270 8003AA70 00000000 */   nop
    /* 2B274 8003AA74 FF0F6324 */  addiu      $v1, $v1, 0xFFF
  .L8003AA78:
    /* 2B278 8003AA78 46000586 */  lh         $a1, 0x46($s0)
    /* 2B27C 8003AA7C 00000000 */  nop
    /* 2B280 8003AA80 18004500 */  mult       $v0, $a1
    /* 2B284 8003AA84 12200000 */  mflo       $a0
    /* 2B288 8003AA88 02008104 */  bgez       $a0, .L8003AA94
    /* 2B28C 8003AA8C 031B0300 */   sra       $v1, $v1, 12
    /* 2B290 8003AA90 FF0F8424 */  addiu      $a0, $a0, 0xFFF
  .L8003AA94:
    /* 2B294 8003AA94 4A000286 */  lh         $v0, 0x4A($s0)
    /* 2B298 8003AA98 00000000 */  nop
    /* 2B29C 8003AA9C 03004104 */  bgez       $v0, .L8003AAAC
    /* 2B2A0 8003AAA0 033B0400 */   sra       $a3, $a0, 12
    /* 2B2A4 8003AAA4 2318C300 */  subu       $v1, $a2, $v1
    /* 2B2A8 8003AAA8 2338A700 */  subu       $a3, $a1, $a3
  .L8003AAAC:
    /* 2B2AC 8003AAAC 21200002 */  addu       $a0, $s0, $zero
    /* 2B2B0 8003AAB0 40000596 */  lhu        $a1, 0x40($s0)
    /* 2B2B4 8003AAB4 42008694 */  lhu        $a2, 0x42($a0)
    /* 2B2B8 8003AAB8 2328A300 */  subu       $a1, $a1, $v1
    /* 2B2BC 8003AABC 002C0500 */  sll        $a1, $a1, 16
    /* 2B2C0 8003AAC0 032C0500 */  sra        $a1, $a1, 16
    /* 2B2C4 8003AAC4 2330C700 */  subu       $a2, $a2, $a3
    /* 2B2C8 8003AAC8 00340600 */  sll        $a2, $a2, 16
    /* 2B2CC 8003AACC 57EA000C */  jal        func_8003A95C
    /* 2B2D0 8003AAD0 03340600 */   sra       $a2, $a2, 16
  .L8003AAD4:
    /* 2B2D4 8003AAD4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2B2D8 8003AAD8 1000B08F */  lw         $s0, 0x10($sp)
    /* 2B2DC 8003AADC 0800E003 */  jr         $ra
    /* 2B2E0 8003AAE0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003A990
