nonmatching func_8001EE44, 0xD8

glabel func_8001EE44
    /* F644 8001EE44 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F648 8001EE48 0300A014 */  bnez       $a1, .L8001EE58
    /* F64C 8001EE4C 1000BFAF */   sw        $ra, 0x10($sp)
    /* F650 8001EE50 C37B0008 */  j          .L8001EF0C
    /* F654 8001EE54 21100000 */   addu      $v0, $zero, $zero
  .L8001EE58:
    /* F658 8001EE58 16008294 */  lhu        $v0, 0x16($a0)
    /* F65C 8001EE5C 00000000 */  nop
    /* F660 8001EE60 00024230 */  andi       $v0, $v0, 0x200
    /* F664 8001EE64 09004010 */  beqz       $v0, .L8001EE8C
    /* F668 8001EE68 1D80023C */   lui       $v0, %hi(D_801D4244)
    /* F66C 8001EE6C 0C008384 */  lh         $v1, 0xC($a0)
    /* F670 8001EE70 44424224 */  addiu      $v0, $v0, %lo(D_801D4244)
    /* F674 8001EE74 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* F678 8001EE78 80180300 */  sll        $v1, $v1, 2
    /* F67C 8001EE7C 21186200 */  addu       $v1, $v1, $v0
    /* F680 8001EE80 0000628C */  lw         $v0, 0x0($v1)
    /* F684 8001EE84 AB7B0008 */  j          .L8001EEAC
    /* F688 8001EE88 83140200 */   sra       $v0, $v0, 18
  .L8001EE8C:
    /* F68C 8001EE8C 0C008384 */  lh         $v1, 0xC($a0)
    /* F690 8001EE90 44424224 */  addiu      $v0, $v0, %lo(D_801D4244)
    /* F694 8001EE94 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* F698 8001EE98 80180300 */  sll        $v1, $v1, 2
    /* F69C 8001EE9C 21186200 */  addu       $v1, $v1, $v0
    /* F6A0 8001EEA0 0000628C */  lw         $v0, 0x0($v1)
    /* F6A4 8001EEA4 00000000 */  nop
    /* F6A8 8001EEA8 83150200 */  sra        $v0, $v0, 22
  .L8001EEAC:
    /* F6AC 8001EEAC 0F004430 */  andi       $a0, $v0, 0xF
    /* F6B0 8001EEB0 1600A294 */  lhu        $v0, 0x16($a1)
    /* F6B4 8001EEB4 00000000 */  nop
    /* F6B8 8001EEB8 00024230 */  andi       $v0, $v0, 0x200
    /* F6BC 8001EEBC 09004010 */  beqz       $v0, .L8001EEE4
    /* F6C0 8001EEC0 1D80023C */   lui       $v0, %hi(D_801D4244)
    /* F6C4 8001EEC4 0C00A384 */  lh         $v1, 0xC($a1)
    /* F6C8 8001EEC8 44424224 */  addiu      $v0, $v0, %lo(D_801D4244)
    /* F6CC 8001EECC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* F6D0 8001EED0 80180300 */  sll        $v1, $v1, 2
    /* F6D4 8001EED4 21186200 */  addu       $v1, $v1, $v0
    /* F6D8 8001EED8 0000628C */  lw         $v0, 0x0($v1)
    /* F6DC 8001EEDC C17B0008 */  j          .L8001EF04
    /* F6E0 8001EEE0 83140200 */   sra       $v0, $v0, 18
  .L8001EEE4:
    /* F6E4 8001EEE4 0C00A384 */  lh         $v1, 0xC($a1)
    /* F6E8 8001EEE8 44424224 */  addiu      $v0, $v0, %lo(D_801D4244)
    /* F6EC 8001EEEC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* F6F0 8001EEF0 80180300 */  sll        $v1, $v1, 2
    /* F6F4 8001EEF4 21186200 */  addu       $v1, $v1, $v0
    /* F6F8 8001EEF8 0000628C */  lw         $v0, 0x0($v1)
    /* F6FC 8001EEFC 00000000 */  nop
    /* F700 8001EF00 83150200 */  sra        $v0, $v0, 22
  .L8001EF04:
    /* F704 8001EF04 E0B2000C */  jal        func_8002CB80
    /* F708 8001EF08 0F004530 */   andi      $a1, $v0, 0xF
  .L8001EF0C:
    /* F70C 8001EF0C 1000BF8F */  lw         $ra, 0x10($sp)
    /* F710 8001EF10 00000000 */  nop
    /* F714 8001EF14 0800E003 */  jr         $ra
    /* F718 8001EF18 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001EE44
