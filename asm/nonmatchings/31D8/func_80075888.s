nonmatching func_80075888, 0x64

glabel func_80075888
    /* 66088 80075888 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6608C 8007588C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 66090 80075890 21888000 */  addu       $s1, $a0, $zero
    /* 66094 80075894 1000B0AF */  sw         $s0, 0x10($sp)
    /* 66098 80075898 2180A000 */  addu       $s0, $a1, $zero
    /* 6609C 8007589C 0980023C */  lui        $v0, %hi(D_80092BA0)
    /* 660A0 800758A0 A02B4294 */  lhu        $v0, %lo(D_80092BA0)($v0)
    /* 660A4 800758A4 0980053C */  lui        $a1, %hi(D_80092BB0)
    /* 660A8 800758A8 B02BA58C */  lw         $a1, %lo(D_80092BB0)($a1)
    /* 660AC 800758AC 02000424 */  addiu      $a0, $zero, 0x2
    /* 660B0 800758B0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 660B4 800758B4 61D5010C */  jal        func_80075584
    /* 660B8 800758B8 0428A200 */   sllv      $a1, $v0, $a1
    /* 660BC 800758BC 61D5010C */  jal        func_80075584
    /* 660C0 800758C0 21200000 */   addu      $a0, $zero, $zero
    /* 660C4 800758C4 03000424 */  addiu      $a0, $zero, 0x3
    /* 660C8 800758C8 21282002 */  addu       $a1, $s1, $zero
    /* 660CC 800758CC 61D5010C */  jal        func_80075584
    /* 660D0 800758D0 21300002 */   addu      $a2, $s0, $zero
    /* 660D4 800758D4 21100002 */  addu       $v0, $s0, $zero
    /* 660D8 800758D8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 660DC 800758DC 1400B18F */  lw         $s1, 0x14($sp)
    /* 660E0 800758E0 1000B08F */  lw         $s0, 0x10($sp)
    /* 660E4 800758E4 0800E003 */  jr         $ra
    /* 660E8 800758E8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80075888
