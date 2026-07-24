nonmatching func_8003D03C, 0xB8

glabel func_8003D03C
    /* 2D83C 8003D03C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2D840 8003D040 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2D844 8003D044 21888000 */  addu       $s1, $a0, $zero
    /* 2D848 8003D048 1D80053C */  lui        $a1, %hi(D_801D4000)
    /* 2D84C 8003D04C 0040A524 */  addiu      $a1, $a1, %lo(D_801D4000)
    /* 2D850 8003D050 00020624 */  addiu      $a2, $zero, 0x200
    /* 2D854 8003D054 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2D858 8003D058 A8D5000C */  jal        func_800356A0
    /* 2D85C 8003D05C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2D860 8003D060 0A80023C */  lui        $v0, %hi(D_8009B0C4)
    /* 2D864 8003D064 C4B0428C */  lw         $v0, %lo(D_8009B0C4)($v0)
    /* 2D868 8003D068 0A80033C */  lui        $v1, %hi(D_8009B408)
    /* 2D86C 8003D06C 08B46380 */  lb         $v1, %lo(D_8009B408)($v1)
    /* 2D870 8003D070 000620AE */  sw         $zero, 0x600($s1)
    /* 2D874 8003D074 03006104 */  bgez       $v1, .L8003D084
    /* 2D878 8003D078 080622AE */   sw        $v0, 0x608($s1)
    /* 2D87C 8003D07C 0A80013C */  lui        $at, %hi(D_8009B408)
    /* 2D880 8003D080 08B420A0 */  sb         $zero, %lo(D_8009B408)($at)
  .L8003D084:
    /* 2D884 8003D084 0A80023C */  lui        $v0, %hi(D_8009B408)
    /* 2D888 8003D088 08B44290 */  lbu        $v0, %lo(D_8009B408)($v0)
    /* 2D88C 8003D08C 00023026 */  addiu      $s0, $s1, 0x200
    /* 2D890 8003D090 DE0722A2 */  sb         $v0, 0x7DE($s1)
    /* 2D894 8003D094 B004828F */  lw         $v0, %gp_rel(D_8009B3B8)($gp)
    /* 2D898 8003D098 21200002 */  addu       $a0, $s0, $zero
    /* 2D89C 8003D09C 01004224 */  addiu      $v0, $v0, 0x1
    /* 2D8A0 8003D0A0 040622AE */  sw         $v0, 0x604($s1)
    /* 2D8A4 8003D0A4 C5F3000C */  jal        func_8003CF14
    /* 2D8A8 8003D0A8 840C22AE */   sw        $v0, 0xC84($s1)
    /* 2D8AC 8003D0AC F2F3000C */  jal        func_8003CFC8
    /* 2D8B0 8003D0B0 21200002 */   addu      $a0, $s0, $zero
    /* 2D8B4 8003D0B4 21180000 */  addu       $v1, $zero, $zero
    /* 2D8B8 8003D0B8 21102302 */  addu       $v0, $s1, $v1
  .L8003D0BC:
    /* 2D8BC 8003D0BC 280840A0 */  sb         $zero, 0x828($v0)
    /* 2D8C0 8003D0C0 01006324 */  addiu      $v1, $v1, 0x1
    /* 2D8C4 8003D0C4 5800622C */  sltiu      $v0, $v1, 0x58
    /* 2D8C8 8003D0C8 FCFF4014 */  bnez       $v0, .L8003D0BC
    /* 2D8CC 8003D0CC 21102302 */   addu      $v0, $s1, $v1
    /* 2D8D0 8003D0D0 80082426 */  addiu      $a0, $s1, 0x880
    /* 2D8D4 8003D0D4 00022526 */  addiu      $a1, $s1, 0x200
    /* 2D8D8 8003D0D8 A8D5000C */  jal        func_800356A0
    /* 2D8DC 8003D0DC 80060624 */   addiu     $a2, $zero, 0x680
    /* 2D8E0 8003D0E0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2D8E4 8003D0E4 1400B18F */  lw         $s1, 0x14($sp)
    /* 2D8E8 8003D0E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D8EC 8003D0EC 0800E003 */  jr         $ra
    /* 2D8F0 8003D0F0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003D03C
