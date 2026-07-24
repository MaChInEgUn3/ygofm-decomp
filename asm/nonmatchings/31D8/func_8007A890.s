nonmatching func_8007A890, 0x30

glabel func_8007A890
    /* 6B090 8007A890 03000324 */  addiu      $v1, $zero, 0x3
    /* 6B094 8007A894 03008224 */  addiu      $v0, $a0, 0x3
    /* 6B098 8007A898 000080AC */  sw         $zero, 0x0($a0)
    /* 6B09C 8007A89C 040080A0 */  sb         $zero, 0x4($a0)
  .L8007A8A0:
    /* 6B0A0 8007A8A0 050040A0 */  sb         $zero, 0x5($v0)
    /* 6B0A4 8007A8A4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 6B0A8 8007A8A8 FDFF6104 */  bgez       $v1, .L8007A8A0
    /* 6B0AC 8007A8AC FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 6B0B0 8007A8B0 0C0080AC */  sw         $zero, 0xC($a0)
    /* 6B0B4 8007A8B4 100080AC */  sw         $zero, 0x10($a0)
    /* 6B0B8 8007A8B8 0800E003 */  jr         $ra
    /* 6B0BC 8007A8BC 140080AC */   sw        $zero, 0x14($a0)
endlabel func_8007A890
