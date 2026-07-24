nonmatching func_80044DA0, 0x20

glabel func_80044DA0
    /* 355A0 80044DA0 0A80023C */  lui        $v0, %hi(D_8009B45C)
    /* 355A4 80044DA4 5CB4428C */  lw         $v0, %lo(D_8009B45C)($v0)
    /* 355A8 80044DA8 80000324 */  addiu      $v1, $zero, 0x80
    /* 355AC 80044DAC 140543A0 */  sb         $v1, 0x514($v0)
    /* 355B0 80044DB0 0A80023C */  lui        $v0, %hi(D_8009B45C)
    /* 355B4 80044DB4 5CB4428C */  lw         $v0, %lo(D_8009B45C)($v0)
    /* 355B8 80044DB8 0800E003 */  jr         $ra
    /* 355BC 80044DBC 150543A0 */   sb        $v1, 0x515($v0)
endlabel func_80044DA0
