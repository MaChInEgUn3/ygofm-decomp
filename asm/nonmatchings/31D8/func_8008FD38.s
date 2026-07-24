nonmatching func_8008FD38, 0x7C

glabel func_8008FD38
    /* 80538 8008FD38 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 8053C 8008FD3C 0100A230 */  andi       $v0, $a1, 0x1
    /* 80540 8008FD40 06004010 */  beqz       $v0, .L8008FD5C
    /* 80544 8008FD44 1000BFAF */   sw        $ra, 0x10($sp)
    /* 80548 8008FD48 FFF7033C */  lui        $v1, (0xF7FFFFFF >> 16)
    /* 8054C 8008FD4C 0000828C */  lw         $v0, 0x0($a0)
    /* 80550 8008FD50 FFFF6334 */  ori        $v1, $v1, (0xF7FFFFFF & 0xFFFF)
    /* 80554 8008FD54 5A3F0208 */  j          .L8008FD68
    /* 80558 8008FD58 24104300 */   and       $v0, $v0, $v1
  .L8008FD5C:
    /* 8055C 8008FD5C 0000828C */  lw         $v0, 0x0($a0)
    /* 80560 8008FD60 0008033C */  lui        $v1, (0x8000000 >> 16)
    /* 80564 8008FD64 25104300 */  or         $v0, $v0, $v1
  .L8008FD68:
    /* 80568 8008FD68 000082AC */  sw         $v0, 0x0($a0)
    /* 8056C 8008FD6C 0200A230 */  andi       $v0, $a1, 0x2
    /* 80570 8008FD70 04004010 */  beqz       $v0, .L8008FD84
    /* 80574 8008FD74 0002033C */   lui       $v1, (0x2000000 >> 16)
    /* 80578 8008FD78 0000828C */  lw         $v0, 0x0($a0)
    /* 8057C 8008FD7C 653F0208 */  j          .L8008FD94
    /* 80580 8008FD80 25104300 */   or        $v0, $v0, $v1
  .L8008FD84:
    /* 80584 8008FD84 FFFD033C */  lui        $v1, (0xFDFFFFFF >> 16)
    /* 80588 8008FD88 0000828C */  lw         $v0, 0x0($a0)
    /* 8058C 8008FD8C FFFF6334 */  ori        $v1, $v1, (0xFDFFFFFF & 0xFFFF)
    /* 80590 8008FD90 24104300 */  and        $v0, $v0, $v1
  .L8008FD94:
    /* 80594 8008FD94 000082AC */  sw         $v0, 0x0($a0)
    /* 80598 8008FD98 00008594 */  lhu        $a1, 0x0($a0)
    /* 8059C 8008FD9C E43F020C */  jal        func_8008FF90
    /* 805A0 8008FDA0 00000000 */   nop
    /* 805A4 8008FDA4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 805A8 8008FDA8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 805AC 8008FDAC 0800E003 */  jr         $ra
    /* 805B0 8008FDB0 00000000 */   nop
endlabel func_8008FD38
