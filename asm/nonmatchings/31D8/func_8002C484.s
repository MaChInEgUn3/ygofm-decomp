nonmatching func_8002C484, 0x58

glabel func_8002C484
    /* 1CC84 8002C484 6666023C */  lui        $v0, (0x66666667 >> 16)
    /* 1CC88 8002C488 67664234 */  ori        $v0, $v0, (0x66666667 & 0xFFFF)
    /* 1CC8C 8002C48C 18008200 */  mult       $a0, $v0
    /* 1CC90 8002C490 C3170400 */  sra        $v0, $a0, 31
    /* 1CC94 8002C494 10300000 */  mfhi       $a2
    /* 1CC98 8002C498 83280600 */  sra        $a1, $a2, 2
    /* 1CC9C 8002C49C 2328A200 */  subu       $a1, $a1, $v0
    /* 1CCA0 8002C4A0 40100500 */  sll        $v0, $a1, 1
    /* 1CCA4 8002C4A4 21104500 */  addu       $v0, $v0, $a1
    /* 1CCA8 8002C4A8 80100200 */  sll        $v0, $v0, 2
    /* 1CCAC 8002C4AC 23104500 */  subu       $v0, $v0, $a1
    /* 1CCB0 8002C4B0 C0100200 */  sll        $v0, $v0, 3
    /* 1CCB4 8002C4B4 21104500 */  addu       $v0, $v0, $a1
    /* 1CCB8 8002C4B8 40100200 */  sll        $v0, $v0, 1
    /* 1CCBC 8002C4BC 80180500 */  sll        $v1, $a1, 2
    /* 1CCC0 8002C4C0 21186500 */  addu       $v1, $v1, $a1
    /* 1CCC4 8002C4C4 40180300 */  sll        $v1, $v1, 1
    /* 1CCC8 8002C4C8 23208300 */  subu       $a0, $a0, $v1
    /* 1CCCC 8002C4CC 00210400 */  sll        $a0, $a0, 4
    /* 1CCD0 8002C4D0 21104400 */  addu       $v0, $v0, $a0
    /* 1CCD4 8002C4D4 0800E003 */  jr         $ra
    /* 1CCD8 8002C4D8 0E004224 */   addiu     $v0, $v0, 0xE
endlabel func_8002C484
