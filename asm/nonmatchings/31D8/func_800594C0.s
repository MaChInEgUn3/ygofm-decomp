nonmatching func_800594C0, 0x60

glabel func_800594C0
    /* 49CC0 800594C0 C0100400 */  sll        $v0, $a0, 3
    /* 49CC4 800594C4 23104400 */  subu       $v0, $v0, $a0
    /* 49CC8 800594C8 00110200 */  sll        $v0, $v0, 4
    /* 49CCC 800594CC 21104400 */  addu       $v0, $v0, $a0
    /* 49CD0 800594D0 40110200 */  sll        $v0, $v0, 5
    /* 49CD4 800594D4 0F80033C */  lui        $v1, %hi(D_800F2C40)
    /* 49CD8 800594D8 402C6324 */  addiu      $v1, $v1, %lo(D_800F2C40)
    /* 49CDC 800594DC 0B00A010 */  beqz       $a1, .L8005950C
    /* 49CE0 800594E0 21184300 */   addu      $v1, $v0, $v1
    /* 49CE4 800594E4 0000A68C */  lw         $a2, 0x0($a1)
    /* 49CE8 800594E8 0400A78C */  lw         $a3, 0x4($a1)
    /* 49CEC 800594EC 0800A88C */  lw         $t0, 0x8($a1)
    /* 49CF0 800594F0 0C00A98C */  lw         $t1, 0xC($a1)
    /* 49CF4 800594F4 B00D66AC */  sw         $a2, 0xDB0($v1)
    /* 49CF8 800594F8 B40D67AC */  sw         $a3, 0xDB4($v1)
    /* 49CFC 800594FC B80D68AC */  sw         $t0, 0xDB8($v1)
    /* 49D00 80059500 BC0D69AC */  sw         $t1, 0xDBC($v1)
    /* 49D04 80059504 0800E003 */  jr         $ra
    /* 49D08 80059508 00000000 */   nop
  .L8005950C:
    /* 49D0C 8005950C 00100224 */  addiu      $v0, $zero, 0x1000
    /* 49D10 80059510 B80D62AC */  sw         $v0, 0xDB8($v1)
    /* 49D14 80059514 B40D62AC */  sw         $v0, 0xDB4($v1)
    /* 49D18 80059518 0800E003 */  jr         $ra
    /* 49D1C 8005951C B00D62AC */   sw        $v0, 0xDB0($v1)
endlabel func_800594C0
