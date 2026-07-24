nonmatching func_8005ABA0, 0x2C8

glabel func_8005ABA0
    /* 4B3A0 8005ABA0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4B3A4 8005ABA4 21608000 */  addu       $t4, $a0, $zero
    /* 4B3A8 8005ABA8 2800AB93 */  lbu        $t3, 0x28($sp)
    /* 4B3AC 8005ABAC 0200A104 */  bgez       $a1, .L8005ABB8
    /* 4B3B0 8005ABB0 2118A000 */   addu      $v1, $a1, $zero
    /* 4B3B4 8005ABB4 FF0FA324 */  addiu      $v1, $a1, 0xFFF
  .L8005ABB8:
    /* 4B3B8 8005ABB8 AA2A023C */  lui        $v0, (0x2AAAAAAB >> 16)
    /* 4B3BC 8005ABBC ABAA4234 */  ori        $v0, $v0, (0x2AAAAAAB & 0xFFFF)
    /* 4B3C0 8005ABC0 031B0300 */  sra        $v1, $v1, 12
    /* 4B3C4 8005ABC4 01006324 */  addiu      $v1, $v1, 0x1
    /* 4B3C8 8005ABC8 18006200 */  mult       $v1, $v0
    /* 4B3CC 8005ABCC C3170300 */  sra        $v0, $v1, 31
    /* 4B3D0 8005ABD0 10680000 */  mfhi       $t5
    /* 4B3D4 8005ABD4 2320A201 */  subu       $a0, $t5, $v0
    /* 4B3D8 8005ABD8 40100400 */  sll        $v0, $a0, 1
    /* 4B3DC 8005ABDC 21104400 */  addu       $v0, $v0, $a0
    /* 4B3E0 8005ABE0 40100200 */  sll        $v0, $v0, 1
    /* 4B3E4 8005ABE4 23206200 */  subu       $a0, $v1, $v0
    /* 4B3E8 8005ABE8 C2170400 */  srl        $v0, $a0, 31
    /* 4B3EC 8005ABEC 21108200 */  addu       $v0, $a0, $v0
    /* 4B3F0 8005ABF0 43500200 */  sra        $t2, $v0, 1
    /* 4B3F4 8005ABF4 01008230 */  andi       $v0, $a0, 0x1
    /* 4B3F8 8005ABF8 14004010 */  beqz       $v0, .L8005AC4C
    /* 4B3FC 8005ABFC 5555023C */   lui       $v0, (0x55555556 >> 16)
    /* 4B400 8005AC00 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* 4B404 8005AC04 01004325 */  addiu      $v1, $t2, 0x1
    /* 4B408 8005AC08 18006200 */  mult       $v1, $v0
    /* 4B40C 8005AC0C 10480000 */  mfhi       $t1
    /* 4B410 8005AC10 02004425 */  addiu      $a0, $t2, 0x2
    /* 4B414 8005AC14 00000000 */  nop
    /* 4B418 8005AC18 18008200 */  mult       $a0, $v0
    /* 4B41C 8005AC1C C3170300 */  sra        $v0, $v1, 31
    /* 4B420 8005AC20 23482201 */  subu       $t1, $t1, $v0
    /* 4B424 8005AC24 40100900 */  sll        $v0, $t1, 1
    /* 4B428 8005AC28 21104900 */  addu       $v0, $v0, $t1
    /* 4B42C 8005AC2C 23486200 */  subu       $t1, $v1, $v0
    /* 4B430 8005AC30 C3170400 */  sra        $v0, $a0, 31
    /* 4B434 8005AC34 10400000 */  mfhi       $t0
    /* 4B438 8005AC38 23400201 */  subu       $t0, $t0, $v0
    /* 4B43C 8005AC3C 40100800 */  sll        $v0, $t0, 1
    /* 4B440 8005AC40 21104800 */  addu       $v0, $v0, $t0
    /* 4B444 8005AC44 256B0108 */  j          .L8005AC94
    /* 4B448 8005AC48 23408200 */   subu      $t0, $a0, $v0
  .L8005AC4C:
    /* 4B44C 8005AC4C 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* 4B450 8005AC50 01004325 */  addiu      $v1, $t2, 0x1
    /* 4B454 8005AC54 18006200 */  mult       $v1, $v0
    /* 4B458 8005AC58 10400000 */  mfhi       $t0
    /* 4B45C 8005AC5C 02004425 */  addiu      $a0, $t2, 0x2
    /* 4B460 8005AC60 00000000 */  nop
    /* 4B464 8005AC64 18008200 */  mult       $a0, $v0
    /* 4B468 8005AC68 C3170300 */  sra        $v0, $v1, 31
    /* 4B46C 8005AC6C 23400201 */  subu       $t0, $t0, $v0
    /* 4B470 8005AC70 40100800 */  sll        $v0, $t0, 1
    /* 4B474 8005AC74 21104800 */  addu       $v0, $v0, $t0
    /* 4B478 8005AC78 23406200 */  subu       $t0, $v1, $v0
    /* 4B47C 8005AC7C C3170400 */  sra        $v0, $a0, 31
    /* 4B480 8005AC80 10480000 */  mfhi       $t1
    /* 4B484 8005AC84 23482201 */  subu       $t1, $t1, $v0
    /* 4B488 8005AC88 40100900 */  sll        $v0, $t1, 1
    /* 4B48C 8005AC8C 21104900 */  addu       $v0, $v0, $t1
    /* 4B490 8005AC90 23488200 */  subu       $t1, $a0, $v0
  .L8005AC94:
    /* 4B494 8005AC94 FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 4B498 8005AC98 0108C22C */  sltiu      $v0, $a2, 0x801
    /* 4B49C 8005AC9C 17004010 */  beqz       $v0, .L8005ACFC
    /* 4B4A0 8005ACA0 FFFFE330 */   andi      $v1, $a3, 0xFFFF
    /* 4B4A4 8005ACA4 00100224 */  addiu      $v0, $zero, 0x1000
    /* 4B4A8 8005ACA8 23104300 */  subu       $v0, $v0, $v1
    /* 4B4AC 8005ACAC 1800C200 */  mult       $a2, $v0
    /* 4B4B0 8005ACB0 80100800 */  sll        $v0, $t0, 2
    /* 4B4B4 8005ACB4 12180000 */  mflo       $v1
    /* 4B4B8 8005ACB8 02006104 */  bgez       $v1, .L8005ACC4
    /* 4B4BC 8005ACBC 2138A203 */   addu      $a3, $sp, $v0
    /* 4B4C0 8005ACC0 FF0F6324 */  addiu      $v1, $v1, 0xFFF
  .L8005ACC4:
    /* 4B4C4 8005ACC4 031B0300 */  sra        $v1, $v1, 12
    /* 4B4C8 8005ACC8 FF006431 */  andi       $a0, $t3, 0xFF
    /* 4B4CC 8005ACCC 18006400 */  mult       $v1, $a0
    /* 4B4D0 8005ACD0 12180000 */  mflo       $v1
    /* 4B4D4 8005ACD4 40100600 */  sll        $v0, $a2, 1
    /* 4B4D8 8005ACD8 00000000 */  nop
    /* 4B4DC 8005ACDC 18004400 */  mult       $v0, $a0
    /* 4B4E0 8005ACE0 80100A00 */  sll        $v0, $t2, 2
    /* 4B4E4 8005ACE4 2110A203 */  addu       $v0, $sp, $v0
    /* 4B4E8 8005ACE8 0000E3AC */  sw         $v1, 0x0($a3)
    /* 4B4EC 8005ACEC 12580000 */  mflo       $t3
    /* 4B4F0 8005ACF0 23186301 */  subu       $v1, $t3, $v1
    /* 4B4F4 8005ACF4 556B0108 */  j          .L8005AD54
    /* 4B4F8 8005ACF8 000043AC */   sw        $v1, 0x0($v0)
  .L8005ACFC:
    /* 4B4FC 8005ACFC 00100224 */  addiu      $v0, $zero, 0x1000
    /* 4B500 8005AD00 23104300 */  subu       $v0, $v0, $v1
    /* 4B504 8005AD04 1800C200 */  mult       $a2, $v0
    /* 4B508 8005AD08 80100A00 */  sll        $v0, $t2, 2
    /* 4B50C 8005AD0C 12200000 */  mflo       $a0
    /* 4B510 8005AD10 02008104 */  bgez       $a0, .L8005AD1C
    /* 4B514 8005AD14 2138A203 */   addu      $a3, $sp, $v0
    /* 4B518 8005AD18 FF0F8424 */  addiu      $a0, $a0, 0xFFF
  .L8005AD1C:
    /* 4B51C 8005AD1C 03130400 */  sra        $v0, $a0, 12
    /* 4B520 8005AD20 21104300 */  addu       $v0, $v0, $v1
    /* 4B524 8005AD24 FF006431 */  andi       $a0, $t3, 0xFF
    /* 4B528 8005AD28 18004400 */  mult       $v0, $a0
    /* 4B52C 8005AD2C 12100000 */  mflo       $v0
    /* 4B530 8005AD30 40180600 */  sll        $v1, $a2, 1
    /* 4B534 8005AD34 00000000 */  nop
    /* 4B538 8005AD38 18006400 */  mult       $v1, $a0
    /* 4B53C 8005AD3C 80180800 */  sll        $v1, $t0, 2
    /* 4B540 8005AD40 2118A303 */  addu       $v1, $sp, $v1
    /* 4B544 8005AD44 0000E2AC */  sw         $v0, 0x0($a3)
    /* 4B548 8005AD48 12580000 */  mflo       $t3
    /* 4B54C 8005AD4C 23106201 */  subu       $v0, $t3, $v0
    /* 4B550 8005AD50 000062AC */  sw         $v0, 0x0($v1)
  .L8005AD54:
    /* 4B554 8005AD54 AA2A023C */  lui        $v0, (0x2AAAAAAB >> 16)
    /* 4B558 8005AD58 ABAA4234 */  ori        $v0, $v0, (0x2AAAAAAB & 0xFFFF)
    /* 4B55C 8005AD5C 0010A424 */  addiu      $a0, $a1, 0x1000
    /* 4B560 8005AD60 18008200 */  mult       $a0, $v0
    /* 4B564 8005AD64 C3170400 */  sra        $v0, $a0, 31
    /* 4B568 8005AD68 10680000 */  mfhi       $t5
    /* 4B56C 8005AD6C 031B0D00 */  sra        $v1, $t5, 12
    /* 4B570 8005AD70 23186200 */  subu       $v1, $v1, $v0
    /* 4B574 8005AD74 40100300 */  sll        $v0, $v1, 1
    /* 4B578 8005AD78 21104300 */  addu       $v0, $v0, $v1
    /* 4B57C 8005AD7C 40130200 */  sll        $v0, $v0, 13
    /* 4B580 8005AD80 23208200 */  subu       $a0, $a0, $v0
    /* 4B584 8005AD84 40130A00 */  sll        $v0, $t2, 13
    /* 4B588 8005AD88 23208200 */  subu       $a0, $a0, $v0
    /* 4B58C 8005AD8C 00F08524 */  addiu      $a1, $a0, -0x1000
    /* 4B590 8005AD90 0400A104 */  bgez       $a1, .L8005ADA4
    /* 4B594 8005AD94 80100A00 */   sll       $v0, $t2, 2
    /* 4B598 8005AD98 00100224 */  addiu      $v0, $zero, 0x1000
    /* 4B59C 8005AD9C 23284400 */  subu       $a1, $v0, $a0
    /* 4B5A0 8005ADA0 80100A00 */  sll        $v0, $t2, 2
  .L8005ADA4:
    /* 4B5A4 8005ADA4 2120A203 */  addu       $a0, $sp, $v0
    /* 4B5A8 8005ADA8 80100800 */  sll        $v0, $t0, 2
    /* 4B5AC 8005ADAC 2118A203 */  addu       $v1, $sp, $v0
    /* 4B5B0 8005ADB0 0000828C */  lw         $v0, 0x0($a0)
    /* 4B5B4 8005ADB4 0000648C */  lw         $a0, 0x0($v1)
    /* 4B5B8 8005ADB8 00000000 */  nop
    /* 4B5BC 8005ADBC 23104400 */  subu       $v0, $v0, $a0
    /* 4B5C0 8005ADC0 18004500 */  mult       $v0, $a1
    /* 4B5C4 8005ADC4 80100900 */  sll        $v0, $t1, 2
    /* 4B5C8 8005ADC8 2118A203 */  addu       $v1, $sp, $v0
    /* 4B5CC 8005ADCC 12680000 */  mflo       $t5
    /* 4B5D0 8005ADD0 02130D00 */  srl        $v0, $t5, 12
    /* 4B5D4 8005ADD4 21104400 */  addu       $v0, $v0, $a0
    /* 4B5D8 8005ADD8 000062AC */  sw         $v0, 0x0($v1)
    /* 4B5DC 8005ADDC 0000A28F */  lw         $v0, 0x0($sp)
    /* 4B5E0 8005ADE0 0400A38F */  lw         $v1, 0x4($sp)
    /* 4B5E4 8005ADE4 00084224 */  addiu      $v0, $v0, 0x800
    /* 4B5E8 8005ADE8 02130200 */  srl        $v0, $v0, 12
    /* 4B5EC 8005ADEC 21204000 */  addu       $a0, $v0, $zero
    /* 4B5F0 8005ADF0 00086324 */  addiu      $v1, $v1, 0x800
    /* 4B5F4 8005ADF4 0800A28F */  lw         $v0, 0x8($sp)
    /* 4B5F8 8005ADF8 021B0300 */  srl        $v1, $v1, 12
    /* 4B5FC 8005ADFC 0000A4AF */  sw         $a0, 0x0($sp)
    /* 4B600 8005AE00 0400A3AF */  sw         $v1, 0x4($sp)
    /* 4B604 8005AE04 00084224 */  addiu      $v0, $v0, 0x800
    /* 4B608 8005AE08 022B0200 */  srl        $a1, $v0, 12
    /* 4B60C 8005AE0C 0001822C */  sltiu      $v0, $a0, 0x100
    /* 4B610 8005AE10 02004014 */  bnez       $v0, .L8005AE1C
    /* 4B614 8005AE14 0800A5AF */   sw        $a1, 0x8($sp)
    /* 4B618 8005AE18 FF000424 */  addiu      $a0, $zero, 0xFF
  .L8005AE1C:
    /* 4B61C 8005AE1C 0001622C */  sltiu      $v0, $v1, 0x100
    /* 4B620 8005AE20 02004014 */  bnez       $v0, .L8005AE2C
    /* 4B624 8005AE24 1000A4A3 */   sb        $a0, 0x10($sp)
    /* 4B628 8005AE28 FF000324 */  addiu      $v1, $zero, 0xFF
  .L8005AE2C:
    /* 4B62C 8005AE2C 1100A3A3 */  sb         $v1, 0x11($sp)
    /* 4B630 8005AE30 2118A000 */  addu       $v1, $a1, $zero
    /* 4B634 8005AE34 0001622C */  sltiu      $v0, $v1, 0x100
    /* 4B638 8005AE38 02004014 */  bnez       $v0, .L8005AE44
    /* 4B63C 8005AE3C 21108001 */   addu      $v0, $t4, $zero
    /* 4B640 8005AE40 FF000324 */  addiu      $v1, $zero, 0xFF
  .L8005AE44:
    /* 4B644 8005AE44 1200A3A3 */  sb         $v1, 0x12($sp)
    /* 4B648 8005AE48 1000AE83 */  lb         $t6, 0x10($sp)
    /* 4B64C 8005AE4C 1100AF83 */  lb         $t7, 0x11($sp)
    /* 4B650 8005AE50 1200B883 */  lb         $t8, 0x12($sp)
    /* 4B654 8005AE54 00008EA1 */  sb         $t6, 0x0($t4)
    /* 4B658 8005AE58 01008FA1 */  sb         $t7, 0x1($t4)
    /* 4B65C 8005AE5C 020098A1 */  sb         $t8, 0x2($t4)
    /* 4B660 8005AE60 0800E003 */  jr         $ra
    /* 4B664 8005AE64 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8005ABA0
