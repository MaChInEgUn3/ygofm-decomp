nonmatching func_8005A468, 0x5C

glabel func_8005A468
    /* 4AC68 8005A468 C0100400 */  sll        $v0, $a0, 3
    /* 4AC6C 8005A46C 23104400 */  subu       $v0, $v0, $a0
    /* 4AC70 8005A470 00110200 */  sll        $v0, $v0, 4
    /* 4AC74 8005A474 21104400 */  addu       $v0, $v0, $a0
    /* 4AC78 8005A478 40110200 */  sll        $v0, $v0, 5
    /* 4AC7C 8005A47C 0F80033C */  lui        $v1, %hi(D_800F2C40)
    /* 4AC80 8005A480 402C6324 */  addiu      $v1, $v1, %lo(D_800F2C40)
    /* 4AC84 8005A484 21304300 */  addu       $a2, $v0, $v1
    /* 4AC88 8005A488 E001C424 */  addiu      $a0, $a2, 0x1E0
    /* 4AC8C 8005A48C 1B0EC290 */  lbu        $v0, 0xE1B($a2)
    /* 4AC90 8005A490 00000000 */  nop
    /* 4AC94 8005A494 09004010 */  beqz       $v0, .L8005A4BC
    /* 4AC98 8005A498 21180000 */   addu      $v1, $zero, $zero
  .L8005A49C:
    /* 4AC9C 8005A49C 0000828C */  lw         $v0, 0x0($a0)
    /* 4ACA0 8005A4A0 00000000 */  nop
    /* 4ACA4 8005A4A4 0D0045A0 */  sb         $a1, 0xD($v0)
    /* 4ACA8 8005A4A8 1B0EC290 */  lbu        $v0, 0xE1B($a2)
    /* 4ACAC 8005A4AC 01006324 */  addiu      $v1, $v1, 0x1
    /* 4ACB0 8005A4B0 2A106200 */  slt        $v0, $v1, $v0
    /* 4ACB4 8005A4B4 F9FF4014 */  bnez       $v0, .L8005A49C
    /* 4ACB8 8005A4B8 04008424 */   addiu     $a0, $a0, 0x4
  .L8005A4BC:
    /* 4ACBC 8005A4BC 0800E003 */  jr         $ra
    /* 4ACC0 8005A4C0 00000000 */   nop
endlabel func_8005A468
