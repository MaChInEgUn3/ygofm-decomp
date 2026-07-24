nonmatching func_8001572C, 0x54

glabel func_8001572C
    /* 5F2C 8001572C 3D028293 */  lbu        $v0, %gp_rel(D_8009B145)($gp)
    /* 5F30 80015730 00000000 */  nop
    /* 5F34 80015734 10004010 */  beqz       $v0, .L80015778
    /* 5F38 80015738 FF00033C */   lui       $v1, (0xFFFFFF >> 16)
    /* 5F3C 8001573C FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 5F40 80015740 0F80023C */  lui        $v0, %hi(D_800E9EC8)
    /* 5F44 80015744 C89E43AC */  sw         $v1, %lo(D_800E9EC8)($v0)
    /* 5F48 80015748 C89E4224 */  addiu      $v0, $v0, %lo(D_800E9EC8)
    /* 5F4C 8001574C 90000324 */  addiu      $v1, $zero, 0x90
    /* 5F50 80015750 060043A0 */  sb         $v1, 0x6($v0)
    /* 5F54 80015754 0C000324 */  addiu      $v1, $zero, 0xC
    /* 5F58 80015758 070043A0 */  sb         $v1, 0x7($v0)
    /* 5F5C 8001575C 01000224 */  addiu      $v0, $zero, 0x1
    /* 5F60 80015760 440282A3 */  sb         $v0, %gp_rel(D_8009B14C)($gp)
    /* 5F64 80015764 3C0282A3 */  sb         $v0, %gp_rel(D_8009B144)($gp)
    /* 5F68 80015768 430282A3 */  sb         $v0, %gp_rel(D_8009B14B)($gp)
    /* 5F6C 8001576C 3B0282A3 */  sb         $v0, %gp_rel(D_8009B143)($gp)
    /* 5F70 80015770 420282A3 */  sb         $v0, %gp_rel(D_8009B14A)($gp)
    /* 5F74 80015774 3A0282A3 */  sb         $v0, %gp_rel(D_8009B142)($gp)
  .L80015778:
    /* 5F78 80015778 0800E003 */  jr         $ra
    /* 5F7C 8001577C 00000000 */   nop
endlabel func_8001572C
