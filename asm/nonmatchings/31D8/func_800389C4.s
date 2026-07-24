nonmatching func_800389C4, 0x14

glabel func_800389C4
    /* 291C4 800389C4 34008294 */  lhu        $v0, 0x34($a0)
    /* 291C8 800389C8 00000000 */  nop
    /* 291CC 800389CC F7FF4230 */  andi       $v0, $v0, 0xFFF7
    /* 291D0 800389D0 0800E003 */  jr         $ra
    /* 291D4 800389D4 340082A4 */   sh        $v0, 0x34($a0)
endlabel func_800389C4
