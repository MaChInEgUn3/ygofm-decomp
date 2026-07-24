nonmatching func_8004A3BC, 0x80

glabel func_8004A3BC
    /* 3ABBC 8004A3BC FF00A330 */  andi       $v1, $a1, 0xFF
    /* 3ABC0 8004A3C0 4000622C */  sltiu      $v0, $v1, 0x40
    /* 3ABC4 8004A3C4 0D004010 */  beqz       $v0, .L8004A3FC
    /* 3ABC8 8004A3C8 40000224 */   addiu     $v0, $zero, 0x40
    /* 3ABCC 8004A3CC 11008290 */  lbu        $v0, 0x11($a0)
    /* 3ABD0 8004A3D0 00000000 */  nop
    /* 3ABD4 8004A3D4 0B004010 */  beqz       $v0, .L8004A404
    /* 3ABD8 8004A3D8 40000224 */   addiu     $v0, $zero, 0x40
    /* 3ABDC 8004A3DC 11008390 */  lbu        $v1, 0x11($a0)
    /* 3ABE0 8004A3E0 FF00A430 */  andi       $a0, $a1, 0xFF
    /* 3ABE4 8004A3E4 23104400 */  subu       $v0, $v0, $a0
    /* 3ABE8 8004A3E8 40180300 */  sll        $v1, $v1, 1
    /* 3ABEC 8004A3EC 18006200 */  mult       $v1, $v0
    /* 3ABF0 8004A3F0 12300000 */  mflo       $a2
    /* 3ABF4 8004A3F4 0C290108 */  j          .L8004A430
    /* 3ABF8 8004A3F8 23100600 */   negu      $v0, $a2
  .L8004A3FC:
    /* 3ABFC 8004A3FC 03006214 */  bne        $v1, $v0, .L8004A40C
    /* 3AC00 8004A400 00000000 */   nop
  .L8004A404:
    /* 3AC04 8004A404 0800E003 */  jr         $ra
    /* 3AC08 8004A408 21100000 */   addu      $v0, $zero, $zero
  .L8004A40C:
    /* 3AC0C 8004A40C 10008290 */  lbu        $v0, 0x10($a0)
    /* 3AC10 8004A410 00000000 */  nop
    /* 3AC14 8004A414 FBFF4010 */  beqz       $v0, .L8004A404
    /* 3AC18 8004A418 FF00A230 */   andi      $v0, $a1, 0xFF
    /* 3AC1C 8004A41C 10008390 */  lbu        $v1, 0x10($a0)
    /* 3AC20 8004A420 C1FF4224 */  addiu      $v0, $v0, -0x3F
    /* 3AC24 8004A424 40180300 */  sll        $v1, $v1, 1
    /* 3AC28 8004A428 18006200 */  mult       $v1, $v0
    /* 3AC2C 8004A42C 12100000 */  mflo       $v0
  .L8004A430:
    /* 3AC30 8004A430 00140200 */  sll        $v0, $v0, 16
    /* 3AC34 8004A434 0800E003 */  jr         $ra
    /* 3AC38 8004A438 03140200 */   sra       $v0, $v0, 16
endlabel func_8004A3BC
