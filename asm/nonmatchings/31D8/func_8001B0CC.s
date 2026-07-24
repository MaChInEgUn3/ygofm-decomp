nonmatching func_8001B0CC, 0xA4

glabel func_8001B0CC
    /* B8CC 8001B0CC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* B8D0 8001B0D0 1800B0AF */  sw         $s0, 0x18($sp)
    /* B8D4 8001B0D4 21808000 */  addu       $s0, $a0, $zero
    /* B8D8 8001B0D8 0F80023C */  lui        $v0, %hi(D_800F2856)
    /* B8DC 8001B0DC 56284484 */  lh         $a0, %lo(D_800F2856)($v0)
    /* B8E0 8001B0E0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* B8E4 8001B0E4 341E020C */  jal        func_800878D0
    /* B8E8 8001B0E8 80801000 */   sll       $s0, $s0, 2
    /* B8EC 8001B0EC A0000424 */  addiu      $a0, $zero, 0xA0
    /* B8F0 8001B0F0 2C1E020C */  jal        func_800878B0
    /* B8F4 8001B0F4 6C000524 */   addiu     $a1, $zero, 0x6C
    /* B8F8 8001B0F8 1080043C */  lui        $a0, %hi(D_800FE148)
    /* B8FC 8001B0FC 7415020C */  jal        func_800855D0
    /* B900 8001B100 48E18424 */   addiu     $a0, $a0, %lo(D_800FE148)
    /* B904 8001B104 801F033C */  lui        $v1, (0x1F8003E0 >> 16)
    /* B908 8001B108 E0036334 */  ori        $v1, $v1, (0x1F8003E0 & 0xFFFF)
    /* B90C 8001B10C 0980023C */  lui        $v0, %hi(D_800908A0)
    /* B910 8001B110 A0084224 */  addiu      $v0, $v0, %lo(D_800908A0)
    /* B914 8001B114 21800202 */  addu       $s0, $s0, $v0
    /* B918 8001B118 00000496 */  lhu        $a0, 0x0($s0)
    /* B91C 8001B11C E8FF0224 */  addiu      $v0, $zero, -0x18
    /* B920 8001B120 020062A4 */  sh         $v0, 0x2($v1)
    /* B924 8001B124 000064A4 */  sh         $a0, 0x0($v1)
    /* B928 8001B128 02000296 */  lhu        $v0, 0x2($s0)
    /* B92C 8001B12C 00000000 */  nop
    /* B930 8001B130 040062A4 */  sh         $v0, 0x4($v1)
    /* B934 8001B134 000060C8 */  lwc2       $0, 0x0($v1)
    /* B938 8001B138 040061C8 */  lwc2       $1, 0x4($v1)
    /* B93C 8001B13C 00000000 */  nop
    /* B940 8001B140 00000000 */  nop
    /* B944 8001B144 0100184A */  rtps
    /* B948 8001B148 1000A227 */  addiu      $v0, $sp, 0x10
    /* B94C 8001B14C 00004EE8 */  swc2       $14, 0x0($v0)
    /* B950 8001B150 21200000 */  addu       $a0, $zero, $zero
    /* B954 8001B154 2C1E020C */  jal        func_800878B0
    /* B958 8001B158 21288000 */   addu      $a1, $a0, $zero
    /* B95C 8001B15C 1000A287 */  lh         $v0, 0x10($sp)
    /* B960 8001B160 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* B964 8001B164 1800B08F */  lw         $s0, 0x18($sp)
    /* B968 8001B168 0800E003 */  jr         $ra
    /* B96C 8001B16C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001B0CC
