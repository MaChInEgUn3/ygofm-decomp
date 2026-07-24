nonmatching func_800490F0, 0x18

glabel func_800490F0
    /* 398F0 800490F0 0A80023C */  lui        $v0, %hi(D_8009B45C)
    /* 398F4 800490F4 5CB4428C */  lw         $v0, %lo(D_8009B45C)($v0)
    /* 398F8 800490F8 00000000 */  nop
    /* 398FC 800490FC 821544A4 */  sh         $a0, 0x1582($v0)
    /* 39900 80049100 0800E003 */  jr         $ra
    /* 39904 80049104 841545A0 */   sb        $a1, 0x1584($v0)
endlabel func_800490F0
