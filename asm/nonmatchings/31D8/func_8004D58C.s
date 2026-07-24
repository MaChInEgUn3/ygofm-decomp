nonmatching func_8004D58C, 0x1D0

glabel func_8004D58C
    /* 3DD8C 8004D58C 21580000 */  addu       $t3, $zero, $zero
    /* 3DD90 8004D590 21706001 */  addu       $t6, $t3, $zero
    /* 3DD94 8004D594 21406001 */  addu       $t0, $t3, $zero
    /* 3DD98 8004D598 FFFF0F34 */  ori        $t7, $zero, 0xFFFF
    /* 3DD9C 8004D59C 21686001 */  addu       $t5, $t3, $zero
    /* 3DDA0 8004D5A0 21606001 */  addu       $t4, $t3, $zero
    /* 3DDA4 8004D5A4 C0100400 */  sll        $v0, $a0, 3
    /* 3DDA8 8004D5A8 23104400 */  subu       $v0, $v0, $a0
    /* 3DDAC 8004D5AC 00110200 */  sll        $v0, $v0, 4
    /* 3DDB0 8004D5B0 21104400 */  addu       $v0, $v0, $a0
    /* 3DDB4 8004D5B4 40110200 */  sll        $v0, $v0, 5
    /* 3DDB8 8004D5B8 0F80033C */  lui        $v1, %hi(D_800F2C40)
    /* 3DDBC 8004D5BC 402C6324 */  addiu      $v1, $v1, %lo(D_800F2C40)
    /* 3DDC0 8004D5C0 21484300 */  addu       $t1, $v0, $v1
    /* 3DDC4 8004D5C4 21502001 */  addu       $t2, $t1, $zero
    /* 3DDC8 8004D5C8 060E20A5 */  sh         $zero, 0xE06($t1)
    /* 3DDCC 8004D5CC 080E20A5 */  sh         $zero, 0xE08($t1)
    /* 3DDD0 8004D5D0 D80D20AD */  sw         $zero, 0xDD8($t1)
    /* 3DDD4 8004D5D4 DC0D20AD */  sw         $zero, 0xDDC($t1)
    /* 3DDD8 8004D5D8 E00D20AD */  sw         $zero, 0xDE0($t1)
    /* 3DDDC 8004D5DC E40D20AD */  sw         $zero, 0xDE4($t1)
    /* 3DDE0 8004D5E0 F00D20AD */  sw         $zero, 0xDF0($t1)
  .L8004D5E4:
    /* 3DDE4 8004D5E4 C40740A5 */  sh         $zero, 0x7C4($t2)
    /* 3DDE8 8004D5E8 21380000 */  addu       $a3, $zero, $zero
    /* 3DDEC 8004D5EC 2130A001 */  addu       $a2, $t5, $zero
    /* 3DDF0 8004D5F0 21208001 */  addu       $a0, $t4, $zero
  .L8004D5F4:
    /* 3DDF4 8004D5F4 21182601 */  addu       $v1, $t1, $a2
    /* 3DDF8 8004D5F8 0200C624 */  addiu      $a2, $a2, 0x2
    /* 3DDFC 8004D5FC 21102401 */  addu       $v0, $t1, $a0
    /* 3DE00 8004D600 02008424 */  addiu      $a0, $a0, 0x2
    /* 3DE04 8004D604 0100E724 */  addiu      $a3, $a3, 0x1
    /* 3DE08 8004D608 C8024FA4 */  sh         $t7, 0x2C8($v0)
    /* 3DE0C 8004D60C 3A00E228 */  slti       $v0, $a3, 0x3A
    /* 3DE10 8004D610 F8FF4014 */  bnez       $v0, .L8004D5F4
    /* 3DE14 8004D614 500760A4 */   sh        $zero, 0x750($v1)
    /* 3DE18 8004D618 7600AD25 */  addiu      $t5, $t5, 0x76
    /* 3DE1C 8004D61C 74008C25 */  addiu      $t4, $t4, 0x74
    /* 3DE20 8004D620 01000825 */  addiu      $t0, $t0, 0x1
    /* 3DE24 8004D624 0A000229 */  slti       $v0, $t0, 0xA
    /* 3DE28 8004D628 EEFF4014 */  bnez       $v0, .L8004D5E4
    /* 3DE2C 8004D62C 76004A25 */   addiu     $t2, $t2, 0x76
    /* 3DE30 8004D630 07000824 */  addiu      $t0, $zero, 0x7
    /* 3DE34 8004D634 21102801 */  addu       $v0, $t1, $t0
  .L8004D638:
    /* 3DE38 8004D638 EC0B40A0 */  sb         $zero, 0xBEC($v0)
    /* 3DE3C 8004D63C FFFF0825 */  addiu      $t0, $t0, -0x1
    /* 3DE40 8004D640 FDFF0105 */  bgez       $t0, .L8004D638
    /* 3DE44 8004D644 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 3DE48 8004D648 1000A58C */  lw         $a1, 0x10($a1)
    /* 3DE4C 8004D64C 00000000 */  nop
    /* 3DE50 8004D650 4000A010 */  beqz       $a1, .L8004D754
    /* 3DE54 8004D654 03000624 */   addiu     $a2, $zero, 0x3
    /* 3DE58 8004D658 02000424 */  addiu      $a0, $zero, 0x2
    /* 3DE5C 8004D65C FFFF0324 */  addiu      $v1, $zero, -0x1
  .L8004D660:
    /* 3DE60 8004D660 0800A28C */  lw         $v0, 0x8($a1)
    /* 3DE64 8004D664 00000000 */  nop
    /* 3DE68 8004D668 09004010 */  beqz       $v0, .L8004D690
    /* 3DE6C 8004D66C 00000000 */   nop
    /* 3DE70 8004D670 0F00A290 */  lbu        $v0, 0xF($a1)
    /* 3DE74 8004D674 00000000 */  nop
    /* 3DE78 8004D678 02004614 */  bne        $v0, $a2, .L8004D684
    /* 3DE7C 8004D67C 00000000 */   nop
    /* 3DE80 8004D680 0400AB8C */  lw         $t3, 0x4($a1)
  .L8004D684:
    /* 3DE84 8004D684 02004414 */  bne        $v0, $a0, .L8004D690
    /* 3DE88 8004D688 00000000 */   nop
    /* 3DE8C 8004D68C 0400AE8C */  lw         $t6, 0x4($a1)
  .L8004D690:
    /* 3DE90 8004D690 0000A58C */  lw         $a1, 0x0($a1)
    /* 3DE94 8004D694 00000000 */  nop
    /* 3DE98 8004D698 F1FFA314 */  bne        $a1, $v1, .L8004D660
    /* 3DE9C 8004D69C 00000000 */   nop
    /* 3DEA0 8004D6A0 24006011 */  beqz       $t3, .L8004D734
    /* 3DEA4 8004D6A4 08006B25 */   addiu     $t3, $t3, 0x8
    /* 3DEA8 8004D6A8 0000678D */  lw         $a3, 0x0($t3)
    /* 3DEAC 8004D6AC 04006B25 */  addiu      $t3, $t3, 0x4
    /* 3DEB0 8004D6B0 0000E294 */  lhu        $v0, 0x0($a3)
    /* 3DEB4 8004D6B4 00000000 */  nop
    /* 3DEB8 8004D6B8 18004010 */  beqz       $v0, .L8004D71C
    /* 3DEBC 8004D6BC 21400000 */   addu      $t0, $zero, $zero
    /* 3DEC0 8004D6C0 01000A24 */  addiu      $t2, $zero, 0x1
    /* 3DEC4 8004D6C4 2130E000 */  addu       $a2, $a3, $zero
  .L8004D6C8:
    /* 3DEC8 8004D6C8 02000105 */  bgez       $t0, .L8004D6D4
    /* 3DECC 8004D6CC 21100001 */   addu      $v0, $t0, $zero
    /* 3DED0 8004D6D0 07000225 */  addiu      $v0, $t0, 0x7
  .L8004D6D4:
    /* 3DED4 8004D6D4 C3100200 */  sra        $v0, $v0, 3
    /* 3DED8 8004D6D8 21282201 */  addu       $a1, $t1, $v0
    /* 3DEDC 8004D6DC C0100200 */  sll        $v0, $v0, 3
    /* 3DEE0 8004D6E0 0400C38C */  lw         $v1, 0x4($a2)
    /* 3DEE4 8004D6E4 EC0BA490 */  lbu        $a0, 0xBEC($a1)
    /* 3DEE8 8004D6E8 00016330 */  andi       $v1, $v1, 0x100
    /* 3DEEC 8004D6EC 04006010 */  beqz       $v1, .L8004D700
    /* 3DEF0 8004D6F0 23100201 */   subu      $v0, $t0, $v0
    /* 3DEF4 8004D6F4 04104A00 */  sllv       $v0, $t2, $v0
    /* 3DEF8 8004D6F8 C1350108 */  j          .L8004D704
    /* 3DEFC 8004D6FC 25108200 */   or        $v0, $a0, $v0
  .L8004D700:
    /* 3DF00 8004D700 21108000 */  addu       $v0, $a0, $zero
  .L8004D704:
    /* 3DF04 8004D704 EC0BA2A0 */  sb         $v0, 0xBEC($a1)
    /* 3DF08 8004D708 0000E294 */  lhu        $v0, 0x0($a3)
    /* 3DF0C 8004D70C 01000825 */  addiu      $t0, $t0, 0x1
    /* 3DF10 8004D710 2B100201 */  sltu       $v0, $t0, $v0
    /* 3DF14 8004D714 ECFF4014 */  bnez       $v0, .L8004D6C8
    /* 3DF18 8004D718 0400C624 */   addiu     $a2, $a2, 0x4
  .L8004D71C:
    /* 3DF1C 8004D71C 0000628D */  lw         $v0, 0x0($t3)
    /* 3DF20 8004D720 00000000 */  nop
    /* 3DF24 8004D724 D80D22AD */  sw         $v0, 0xDD8($t1)
    /* 3DF28 8004D728 0400628D */  lw         $v0, 0x4($t3)
    /* 3DF2C 8004D72C 00000000 */  nop
    /* 3DF30 8004D730 DC0D22AD */  sw         $v0, 0xDDC($t1)
  .L8004D734:
    /* 3DF34 8004D734 0700C011 */  beqz       $t6, .L8004D754
    /* 3DF38 8004D738 0400CE25 */   addiu     $t6, $t6, 0x4
    /* 3DF3C 8004D73C 0000C28D */  lw         $v0, 0x0($t6)
    /* 3DF40 8004D740 00000000 */  nop
    /* 3DF44 8004D744 E00D22AD */  sw         $v0, 0xDE0($t1)
    /* 3DF48 8004D748 0400C28D */  lw         $v0, 0x4($t6)
    /* 3DF4C 8004D74C 00000000 */  nop
    /* 3DF50 8004D750 E40D22AD */  sw         $v0, 0xDE4($t1)
  .L8004D754:
    /* 3DF54 8004D754 0800E003 */  jr         $ra
    /* 3DF58 8004D758 00000000 */   nop
endlabel func_8004D58C
