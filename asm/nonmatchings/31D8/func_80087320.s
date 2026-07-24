/* Handwritten function */
nonmatching func_80087320, 0x48

glabel func_80087320
    /* 77B20 80087320 00004848 */  cfc2       $t0, $0 /* handwritten instruction */
    /* 77B24 80087324 00084948 */  cfc2       $t1, $1 /* handwritten instruction */
    /* 77B28 80087328 00104A48 */  cfc2       $t2, $2 /* handwritten instruction */
    /* 77B2C 8008732C 00184B48 */  cfc2       $t3, $3 /* handwritten instruction */
    /* 77B30 80087330 00204C48 */  cfc2       $t4, $4 /* handwritten instruction */
    /* 77B34 80087334 000088AC */  sw         $t0, 0x0($a0)
    /* 77B38 80087338 040089AC */  sw         $t1, 0x4($a0)
    /* 77B3C 8008733C 08008AAC */  sw         $t2, 0x8($a0)
    /* 77B40 80087340 0C008BAC */  sw         $t3, 0xC($a0)
    /* 77B44 80087344 10008CAC */  sw         $t4, 0x10($a0)
    /* 77B48 80087348 00284848 */  cfc2       $t0, $5 /* handwritten instruction */
    /* 77B4C 8008734C 00304948 */  cfc2       $t1, $6 /* handwritten instruction */
    /* 77B50 80087350 00384A48 */  cfc2       $t2, $7 /* handwritten instruction */
    /* 77B54 80087354 140088AC */  sw         $t0, 0x14($a0)
    /* 77B58 80087358 180089AC */  sw         $t1, 0x18($a0)
    /* 77B5C 8008735C 1C008AAC */  sw         $t2, 0x1C($a0)
    /* 77B60 80087360 0800E003 */  jr         $ra
    /* 77B64 80087364 00000000 */   nop
endlabel func_80087320
    /* 77B68 80087368 00000000 */  nop
    /* 77B6C 8008736C 00000000 */  nop
