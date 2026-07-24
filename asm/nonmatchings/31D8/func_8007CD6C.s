nonmatching func_8007CD6C, 0x48

glabel func_8007CD6C
    /* 6D56C 8007CD6C 0C00A010 */  beqz       $a1, .L8007CDA0
    /* 6D570 8007CD70 00000000 */   nop
    /* 6D574 8007CD74 0D008010 */  beqz       $a0, .L8007CDAC
    /* 6D578 8007CD78 21180000 */   addu      $v1, $zero, $zero
  .L8007CD7C:
    /* 6D57C 8007CD7C 0000A290 */  lbu        $v0, 0x0($a1)
    /* 6D580 8007CD80 0100A524 */  addiu      $a1, $a1, 0x1
    /* 6D584 8007CD84 01006324 */  addiu      $v1, $v1, 0x1
    /* 6D588 8007CD88 000082A0 */  sb         $v0, 0x0($a0)
    /* 6D58C 8007CD8C 08006228 */  slti       $v0, $v1, 0x8
    /* 6D590 8007CD90 FAFF4014 */  bnez       $v0, .L8007CD7C
    /* 6D594 8007CD94 01008424 */   addiu     $a0, $a0, 0x1
    /* 6D598 8007CD98 6BF30108 */  j          .L8007CDAC
    /* 6D59C 8007CD9C 00000000 */   nop
  .L8007CDA0:
    /* 6D5A0 8007CDA0 02008010 */  beqz       $a0, .L8007CDAC
    /* 6D5A4 8007CDA4 00000000 */   nop
    /* 6D5A8 8007CDA8 000080A0 */  sb         $zero, 0x0($a0)
  .L8007CDAC:
    /* 6D5AC 8007CDAC 0800E003 */  jr         $ra
    /* 6D5B0 8007CDB0 00000000 */   nop
endlabel func_8007CD6C
    /* 6D5B4 8007CDB4 00000000 */  nop
    /* 6D5B8 8007CDB8 00000000 */  nop
    /* 6D5BC 8007CDBC 00000000 */  nop
