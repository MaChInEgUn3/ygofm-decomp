nonmatching func_80015870, 0x48

glabel func_80015870
    /* 6070 80015870 3D028293 */  lbu        $v0, %gp_rel(D_8009B145)($gp)
    /* 6074 80015874 00000000 */  nop
    /* 6078 80015878 0D004010 */  beqz       $v0, .L800158B0
    /* 607C 8001587C FF00033C */   lui       $v1, (0xFFFFFF >> 16)
    /* 6080 80015880 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 6084 80015884 0F80023C */  lui        $v0, %hi(D_800E9EC8)
    /* 6088 80015888 C89E43AC */  sw         $v1, %lo(D_800E9EC8)($v0)
    /* 608C 8001588C C89E4224 */  addiu      $v0, $v0, %lo(D_800E9EC8)
    /* 6090 80015890 B0000324 */  addiu      $v1, $zero, 0xB0
    /* 6094 80015894 060043A0 */  sb         $v1, 0x6($v0)
    /* 6098 80015898 0C000324 */  addiu      $v1, $zero, 0xC
    /* 609C 8001589C 070043A0 */  sb         $v1, 0x7($v0)
    /* 60A0 800158A0 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 60A4 800158A4 420282A3 */  sb         $v0, %gp_rel(D_8009B14A)($gp)
    /* 60A8 800158A8 430282A3 */  sb         $v0, %gp_rel(D_8009B14B)($gp)
    /* 60AC 800158AC 440282A3 */  sb         $v0, %gp_rel(D_8009B14C)($gp)
  .L800158B0:
    /* 60B0 800158B0 0800E003 */  jr         $ra
    /* 60B4 800158B4 00000000 */   nop
endlabel func_80015870
