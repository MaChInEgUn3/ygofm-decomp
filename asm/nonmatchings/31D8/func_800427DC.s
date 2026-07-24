nonmatching func_800427DC, 0x48

glabel func_800427DC
    /* 32FDC 800427DC 08008294 */  lhu        $v0, 0x8($a0)
    /* 32FE0 800427E0 540080AC */  sw         $zero, 0x54($a0)
    /* 32FE4 800427E4 4C0080AC */  sw         $zero, 0x4C($a0)
    /* 32FE8 800427E8 440080AC */  sw         $zero, 0x44($a0)
    /* 32FEC 800427EC 3C0080AC */  sw         $zero, 0x3C($a0)
    /* 32FF0 800427F0 340080AC */  sw         $zero, 0x34($a0)
    /* 32FF4 800427F4 2C0080AC */  sw         $zero, 0x2C($a0)
    /* 32FF8 800427F8 100080AC */  sw         $zero, 0x10($a0)
    /* 32FFC 800427FC 210080A0 */  sb         $zero, 0x21($a0)
    /* 33000 80042800 200080A0 */  sb         $zero, 0x20($a0)
    /* 33004 80042804 220080A0 */  sb         $zero, 0x22($a0)
    /* 33008 80042808 1C0080A4 */  sh         $zero, 0x1C($a0)
    /* 3300C 8004280C 1A0080A4 */  sh         $zero, 0x1A($a0)
    /* 33010 80042810 180080A4 */  sh         $zero, 0x18($a0)
    /* 33014 80042814 5A0085A0 */  sb         $a1, 0x5A($a0)
    /* 33018 80042818 08004234 */  ori        $v0, $v0, 0x8
    /* 3301C 8004281C 0800E003 */  jr         $ra
    /* 33020 80042820 080082A4 */   sh        $v0, 0x8($a0)
endlabel func_800427DC
