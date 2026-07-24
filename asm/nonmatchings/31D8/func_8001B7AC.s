nonmatching func_8001B7AC, 0x10C

glabel func_8001B7AC
    /* BFAC 8001B7AC C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* BFB0 8001B7B0 3000B2AF */  sw         $s2, 0x30($sp)
    /* BFB4 8001B7B4 21908000 */  addu       $s2, $a0, $zero
    /* BFB8 8001B7B8 3400BFAF */  sw         $ra, 0x34($sp)
    /* BFBC 8001B7BC 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* BFC0 8001B7C0 2800B0AF */  sw         $s0, 0x28($sp)
    /* BFC4 8001B7C4 0E004282 */  lb         $v0, 0xE($s2)
    /* BFC8 8001B7C8 00000000 */  nop
    /* BFCC 8001B7CC 40800200 */  sll        $s0, $v0, 1
    /* BFD0 8001B7D0 21800202 */  addu       $s0, $s0, $v0
    /* BFD4 8001B7D4 80801000 */  sll        $s0, $s0, 2
    /* BFD8 8001B7D8 0F80023C */  lui        $v0, %hi(D_800EA030)
    /* BFDC 8001B7DC 30A04224 */  addiu      $v0, $v0, %lo(D_800EA030)
    /* BFE0 8001B7E0 21800202 */  addu       $s0, $s0, $v0
    /* BFE4 8001B7E4 0000038E */  lw         $v1, 0x0($s0)
    /* BFE8 8001B7E8 00000000 */  nop
    /* BFEC 8001B7EC 32006294 */  lhu        $v0, 0x32($v1)
    /* BFF0 8001B7F0 00000000 */  nop
    /* BFF4 8001B7F4 FCFF4224 */  addiu      $v0, $v0, -0x4
    /* BFF8 8001B7F8 0B00010C */  jal        func_8004002C
    /* BFFC 8001B7FC 320062A4 */   sh        $v0, 0x32($v1)
    /* C000 8001B800 21204000 */  addu       $a0, $v0, $zero
    /* C004 8001B804 2B00010C */  jal        func_800400AC
    /* C008 8001B808 01000524 */   addiu     $a1, $zero, 0x1
    /* C00C 8001B80C 21884000 */  addu       $s1, $v0, $zero
    /* C010 8001B810 21202002 */  addu       $a0, $s1, $zero
    /* C014 8001B814 0000028E */  lw         $v0, 0x0($s0)
    /* C018 8001B818 10000724 */  addiu      $a3, $zero, 0x10
    /* C01C 8001B81C 30004584 */  lh         $a1, 0x30($v0)
    /* C020 8001B820 32004684 */  lh         $a2, 0x32($v0)
    /* C024 8001B824 10000224 */  addiu      $v0, $zero, 0x10
    /* C028 8001B828 1000A2AF */  sw         $v0, 0x10($sp)
    /* C02C 8001B82C 15004392 */  lbu        $v1, 0x15($s2)
    /* C030 8001B830 B8000224 */  addiu      $v0, $zero, 0xB8
    /* C034 8001B834 1800A2AF */  sw         $v0, 0x18($sp)
    /* C038 8001B838 0B000224 */  addiu      $v0, $zero, 0xB
    /* C03C 8001B83C 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* C040 8001B840 50020224 */  addiu      $v0, $zero, 0x250
    /* C044 8001B844 2000A2AF */  sw         $v0, 0x20($sp)
    /* C048 8001B848 FC000224 */  addiu      $v0, $zero, 0xFC
    /* C04C 8001B84C 2400A2AF */  sw         $v0, 0x24($sp)
    /* C050 8001B850 00190300 */  sll        $v1, $v1, 4
    /* C054 8001B854 4401010C */  jal        func_80040510
    /* C058 8001B858 1400A3AF */   sw        $v1, 0x14($sp)
    /* C05C 8001B85C 460A010C */  jal        func_80042918
    /* C060 8001B860 21202002 */   addu      $a0, $s1, $zero
    /* C064 8001B864 0000028E */  lw         $v0, 0x0($s0)
    /* C068 8001B868 00000000 */  nop
    /* C06C 8001B86C 16004590 */  lbu        $a1, 0x16($v0)
    /* C070 8001B870 21202002 */  addu       $a0, $s1, $zero
    /* C074 8001B874 0100A524 */  addiu      $a1, $a1, 0x1
    /* C078 8001B878 002E0500 */  sll        $a1, $a1, 24
    /* C07C 8001B87C 3B0A010C */  jal        func_800428EC
    /* C080 8001B880 032E0500 */   sra       $a1, $a1, 24
    /* C084 8001B884 040011AE */  sw         $s1, 0x4($s0)
    /* C088 8001B888 15004292 */  lbu        $v0, 0x15($s2)
    /* C08C 8001B88C 2F000424 */  addiu      $a0, $zero, 0x2F
    /* C090 8001B890 01004224 */  addiu      $v0, $v0, 0x1
    /* C094 8001B894 150042A2 */  sb         $v0, 0x15($s2)
    /* C098 8001B898 B8FF000C */  jal        func_8003FEE0
    /* C09C 8001B89C 090002A2 */   sb        $v0, 0x9($s0)
    /* C0A0 8001B8A0 3400BF8F */  lw         $ra, 0x34($sp)
    /* C0A4 8001B8A4 3000B28F */  lw         $s2, 0x30($sp)
    /* C0A8 8001B8A8 2C00B18F */  lw         $s1, 0x2C($sp)
    /* C0AC 8001B8AC 2800B08F */  lw         $s0, 0x28($sp)
    /* C0B0 8001B8B0 0800E003 */  jr         $ra
    /* C0B4 8001B8B4 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8001B7AC
