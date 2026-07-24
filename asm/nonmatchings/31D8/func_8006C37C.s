nonmatching func_8006C37C, 0x9FC

glabel func_8006C37C
    /* 5CB7C 8006C37C 40FCBD27 */  addiu      $sp, $sp, -0x3C0
    /* 5CB80 8006C380 9803B0AF */  sw         $s0, 0x398($sp)
    /* 5CB84 8006C384 21808000 */  addu       $s0, $a0, $zero
    /* 5CB88 8006C388 A403B3AF */  sw         $s3, 0x3A4($sp)
    /* 5CB8C 8006C38C A000B327 */  addiu      $s3, $sp, 0xA0
    /* 5CB90 8006C390 21206002 */  addu       $a0, $s3, $zero
    /* 5CB94 8006C394 C403A5AF */  sw         $a1, 0x3C4($sp)
    /* 5CB98 8006C398 21280000 */  addu       $a1, $zero, $zero
    /* 5CB9C 8006C39C 08000624 */  addiu      $a2, $zero, 0x8
    /* 5CBA0 8006C3A0 BC03BFAF */  sw         $ra, 0x3BC($sp)
    /* 5CBA4 8006C3A4 B803BEAF */  sw         $fp, 0x3B8($sp)
    /* 5CBA8 8006C3A8 B403B7AF */  sw         $s7, 0x3B4($sp)
    /* 5CBAC 8006C3AC B003B6AF */  sw         $s6, 0x3B0($sp)
    /* 5CBB0 8006C3B0 AC03B5AF */  sw         $s5, 0x3AC($sp)
    /* 5CBB4 8006C3B4 A803B4AF */  sw         $s4, 0x3A8($sp)
    /* 5CBB8 8006C3B8 A003B2AF */  sw         $s2, 0x3A0($sp)
    /* 5CBBC 8006C3BC F438020C */  jal        func_8008E3D0
    /* 5CBC0 8006C3C0 9C03B1AF */   sw        $s1, 0x39C($sp)
    /* 5CBC4 8006C3C4 A800B127 */  addiu      $s1, $sp, 0xA8
    /* 5CBC8 8006C3C8 21202002 */  addu       $a0, $s1, $zero
    /* 5CBCC 8006C3CC 21280000 */  addu       $a1, $zero, $zero
    /* 5CBD0 8006C3D0 F438020C */  jal        func_8008E3D0
    /* 5CBD4 8006C3D4 08000624 */   addiu     $a2, $zero, 0x8
    /* 5CBD8 8006C3D8 0180023C */  lui        $v0, %hi(D_8001187C)
    /* 5CBDC 8006C3DC 7C184D24 */  addiu      $t5, $v0, %lo(D_8001187C)
    /* 5CBE0 8006C3E0 0000AA8D */  lw         $t2, 0x0($t5)
    /* 5CBE4 8006C3E4 0400AB8D */  lw         $t3, 0x4($t5)
    /* 5CBE8 8006C3E8 0800AC8D */  lw         $t4, 0x8($t5)
    /* 5CBEC 8006C3EC B000AAAF */  sw         $t2, 0xB0($sp)
    /* 5CBF0 8006C3F0 B400ABAF */  sw         $t3, 0xB4($sp)
    /* 5CBF4 8006C3F4 B800ACAF */  sw         $t4, 0xB8($sp)
    /* 5CBF8 8006C3F8 0C00AA8D */  lw         $t2, 0xC($t5)
    /* 5CBFC 8006C3FC 00000000 */  nop
    /* 5CC00 8006C400 BC00AAAF */  sw         $t2, 0xBC($sp)
    /* 5CC04 8006C404 7363010C */  jal        func_80058DCC
    /* 5CC08 8006C408 21A80002 */   addu      $s5, $s0, $zero
    /* 5CC0C 8006C40C 8763010C */  jal        func_80058E1C
    /* 5CC10 8006C410 00000000 */   nop
    /* 5CC14 8006C414 C403AA8F */  lw         $t2, 0x3C4($sp)
    /* 5CC18 8006C418 B000B427 */  addiu      $s4, $sp, 0xB0
    /* 5CC1C 8006C41C BF004005 */  bltz       $t2, .L8006C71C
    /* 5CC20 8006C420 9003A2A3 */   sb        $v0, 0x390($sp)
    /* 5CC24 8006C424 0980023C */  lui        $v0, %hi(D_80091604)
    /* 5CC28 8006C428 04164224 */  addiu      $v0, $v0, %lo(D_80091604)
    /* 5CC2C 8006C42C 21F04000 */  addu       $fp, $v0, $zero
    /* 5CC30 8006C430 7363010C */  jal        func_80058DCC
    /* 5CC34 8006C434 0000BEAE */   sw        $fp, 0x0($s5)
    /* 5CC38 8006C438 21204000 */  addu       $a0, $v0, $zero
    /* 5CC3C 8006C43C 885F010C */  jal        func_80057E20
    /* 5CC40 8006C440 C000A527 */   addiu     $a1, $sp, 0xC0
    /* 5CC44 8006C444 C200A487 */  lh         $a0, 0xC2($sp)
    /* 5CC48 8006C448 C400A387 */  lh         $v1, 0xC4($sp)
    /* 5CC4C 8006C44C 00000000 */  nop
    /* 5CC50 8006C450 2A108300 */  slt        $v0, $a0, $v1
    /* 5CC54 8006C454 02004014 */  bnez       $v0, .L8006C460
    /* 5CC58 8006C458 21806000 */   addu      $s0, $v1, $zero
    /* 5CC5C 8006C45C 21808000 */  addu       $s0, $a0, $zero
  .L8006C460:
    /* 5CC60 8006C460 C400A287 */  lh         $v0, 0xC4($sp)
    /* 5CC64 8006C464 C400A397 */  lhu        $v1, 0xC4($sp)
    /* 5CC68 8006C468 05000216 */  bne        $s0, $v0, .L8006C480
    /* 5CC6C 8006C46C 21206000 */   addu      $a0, $v1, $zero
    /* 5CC70 8006C470 C000A287 */  lh         $v0, 0xC0($sp)
    /* 5CC74 8006C474 C000A397 */  lhu        $v1, 0xC0($sp)
    /* 5CC78 8006C478 25B10108 */  j          .L8006C494
    /* 5CC7C 8006C47C 2A100202 */   slt       $v0, $s0, $v0
  .L8006C480:
    /* 5CC80 8006C480 C200A287 */  lh         $v0, 0xC2($sp)
    /* 5CC84 8006C484 C000A387 */  lh         $v1, 0xC0($sp)
    /* 5CC88 8006C488 C200A497 */  lhu        $a0, 0xC2($sp)
    /* 5CC8C 8006C48C 2A104300 */  slt        $v0, $v0, $v1
    /* 5CC90 8006C490 C000A397 */  lhu        $v1, 0xC0($sp)
  .L8006C494:
    /* 5CC94 8006C494 03004010 */  beqz       $v0, .L8006C4A4
    /* 5CC98 8006C498 00140400 */   sll       $v0, $a0, 16
    /* 5CC9C 8006C49C 21206000 */  addu       $a0, $v1, $zero
    /* 5CCA0 8006C4A0 00140400 */  sll        $v0, $a0, 16
  .L8006C4A4:
    /* 5CCA4 8006C4A4 03840200 */  sra        $s0, $v0, 16
    /* 5CCA8 8006C4A8 80101000 */  sll        $v0, $s0, 2
    /* 5CCAC 8006C4AC 21105000 */  addu       $v0, $v0, $s0
    /* 5CCB0 8006C4B0 02004104 */  bgez       $v0, .L8006C4BC
    /* 5CCB4 8006C4B4 00000000 */   nop
    /* 5CCB8 8006C4B8 03004224 */  addiu      $v0, $v0, 0x3
  .L8006C4BC:
    /* 5CCBC 8006C4BC 0400C387 */  lh         $v1, 0x4($fp)
    /* 5CCC0 8006C4C0 83800200 */  sra        $s0, $v0, 2
    /* 5CCC4 8006C4C4 2A100302 */  slt        $v0, $s0, $v1
    /* 5CCC8 8006C4C8 04004014 */  bnez       $v0, .L8006C4DC
    /* 5CCCC 8006C4CC BD02022A */   slti      $v0, $s0, 0x2BD
    /* 5CCD0 8006C4D0 02004010 */  beqz       $v0, .L8006C4DC
    /* 5CCD4 8006C4D4 BC020324 */   addiu     $v1, $zero, 0x2BC
    /* 5CCD8 8006C4D8 21180002 */  addu       $v1, $s0, $zero
  .L8006C4DC:
    /* 5CCDC 8006C4DC 21806000 */  addu       $s0, $v1, $zero
    /* 5CCE0 8006C4E0 5555023C */  lui        $v0, (0x55555556 >> 16)
    /* 5CCE4 8006C4E4 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* 5CCE8 8006C4E8 18000202 */  mult       $s0, $v0
    /* 5CCEC 8006C4EC 0400B226 */  addiu      $s2, $s5, 0x4
    /* 5CCF0 8006C4F0 21A00000 */  addu       $s4, $zero, $zero
    /* 5CCF4 8006C4F4 1000B326 */  addiu      $s3, $s5, 0x10
    /* 5CCF8 8006C4F8 C3171000 */  sra        $v0, $s0, 31
    /* 5CCFC 8006C4FC 10500000 */  mfhi       $t2
    /* 5CD00 8006C500 23104201 */  subu       $v0, $t2, $v0
    /* 5CD04 8006C504 0400A2A6 */  sh         $v0, 0x4($s5)
    /* 5CD08 8006C508 020042A6 */  sh         $v0, 0x2($s2)
    /* 5CD0C 8006C50C 040040A6 */  sh         $zero, 0x4($s2)
    /* 5CD10 8006C510 0C00B226 */  addiu      $s2, $s5, 0xC
  .L8006C514:
    /* 5CD14 8006C514 C0891400 */  sll        $s1, $s4, 7
    /* 5CD18 8006C518 481A020C */  jal        func_80086920
    /* 5CD1C 8006C51C 21202002 */   addu      $a0, $s1, $zero
    /* 5CD20 8006C520 18000202 */  mult       $s0, $v0
    /* 5CD24 8006C524 12100000 */  mflo       $v0
    /* 5CD28 8006C528 02004104 */  bgez       $v0, .L8006C534
    /* 5CD2C 8006C52C 00000000 */   nop
    /* 5CD30 8006C530 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006C534:
    /* 5CD34 8006C534 03130200 */  sra        $v0, $v0, 12
    /* 5CD38 8006C538 000042A6 */  sh         $v0, 0x0($s2)
    /* 5CD3C 8006C53C EC1A020C */  jal        func_80086BB0
    /* 5CD40 8006C540 21202002 */   addu      $a0, $s1, $zero
    /* 5CD44 8006C544 18000202 */  mult       $s0, $v0
    /* 5CD48 8006C548 12100000 */  mflo       $v0
    /* 5CD4C 8006C54C 02004104 */  bgez       $v0, .L8006C558
    /* 5CD50 8006C550 00000000 */   nop
    /* 5CD54 8006C554 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006C558:
    /* 5CD58 8006C558 03130200 */  sra        $v0, $v0, 12
    /* 5CD5C 8006C55C FEFF62A6 */  sh         $v0, -0x2($s3)
    /* 5CD60 8006C560 EC1A020C */  jal        func_80086BB0
    /* 5CD64 8006C564 21202002 */   addu      $a0, $s1, $zero
    /* 5CD68 8006C568 18000202 */  mult       $s0, $v0
    /* 5CD6C 8006C56C 12100000 */  mflo       $v0
    /* 5CD70 8006C570 02004104 */  bgez       $v0, .L8006C57C
    /* 5CD74 8006C574 00000000 */   nop
    /* 5CD78 8006C578 FF7F4224 */  addiu      $v0, $v0, 0x7FFF
  .L8006C57C:
    /* 5CD7C 8006C57C C3130200 */  sra        $v0, $v0, 15
    /* 5CD80 8006C580 000062A6 */  sh         $v0, 0x0($s3)
    /* 5CD84 8006C584 08007326 */  addiu      $s3, $s3, 0x8
    /* 5CD88 8006C588 01009426 */  addiu      $s4, $s4, 0x1
    /* 5CD8C 8006C58C 2100822A */  slti       $v0, $s4, 0x21
    /* 5CD90 8006C590 E0FF4014 */  bnez       $v0, .L8006C514
    /* 5CD94 8006C594 08005226 */   addiu     $s2, $s2, 0x8
    /* 5CD98 8006C598 6666033C */  lui        $v1, (0x66666667 >> 16)
    /* 5CD9C 8006C59C 67666334 */  ori        $v1, $v1, (0x66666667 & 0xFFFF)
    /* 5CDA0 8006C5A0 80101000 */  sll        $v0, $s0, 2
    /* 5CDA4 8006C5A4 18004300 */  mult       $v0, $v1
    /* 5CDA8 8006C5A8 21A00000 */  addu       $s4, $zero, $zero
    /* 5CDAC 8006C5AC 04005326 */  addiu      $s3, $s2, 0x4
    /* 5CDB0 8006C5B0 C3170200 */  sra        $v0, $v0, 31
    /* 5CDB4 8006C5B4 10500000 */  mfhi       $t2
    /* 5CDB8 8006C5B8 43180A00 */  sra        $v1, $t2, 1
    /* 5CDBC 8006C5BC 23806200 */  subu       $s0, $v1, $v0
  .L8006C5C0:
    /* 5CDC0 8006C5C0 C0891400 */  sll        $s1, $s4, 7
    /* 5CDC4 8006C5C4 481A020C */  jal        func_80086920
    /* 5CDC8 8006C5C8 21202002 */   addu      $a0, $s1, $zero
    /* 5CDCC 8006C5CC 18000202 */  mult       $s0, $v0
    /* 5CDD0 8006C5D0 12100000 */  mflo       $v0
    /* 5CDD4 8006C5D4 02004104 */  bgez       $v0, .L8006C5E0
    /* 5CDD8 8006C5D8 00000000 */   nop
    /* 5CDDC 8006C5DC FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006C5E0:
    /* 5CDE0 8006C5E0 03130200 */  sra        $v0, $v0, 12
    /* 5CDE4 8006C5E4 000042A6 */  sh         $v0, 0x0($s2)
    /* 5CDE8 8006C5E8 EC1A020C */  jal        func_80086BB0
    /* 5CDEC 8006C5EC 21202002 */   addu      $a0, $s1, $zero
    /* 5CDF0 8006C5F0 18000202 */  mult       $s0, $v0
    /* 5CDF4 8006C5F4 12100000 */  mflo       $v0
    /* 5CDF8 8006C5F8 02004104 */  bgez       $v0, .L8006C604
    /* 5CDFC 8006C5FC 00000000 */   nop
    /* 5CE00 8006C600 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8006C604:
    /* 5CE04 8006C604 03130200 */  sra        $v0, $v0, 12
    /* 5CE08 8006C608 FEFF62A6 */  sh         $v0, -0x2($s3)
    /* 5CE0C 8006C60C EC1A020C */  jal        func_80086BB0
    /* 5CE10 8006C610 21202002 */   addu      $a0, $s1, $zero
    /* 5CE14 8006C614 18000202 */  mult       $s0, $v0
    /* 5CE18 8006C618 12100000 */  mflo       $v0
    /* 5CE1C 8006C61C 02004104 */  bgez       $v0, .L8006C628
    /* 5CE20 8006C620 00000000 */   nop
    /* 5CE24 8006C624 FF7F4224 */  addiu      $v0, $v0, 0x7FFF
  .L8006C628:
    /* 5CE28 8006C628 C3130200 */  sra        $v0, $v0, 15
    /* 5CE2C 8006C62C 000062A6 */  sh         $v0, 0x0($s3)
    /* 5CE30 8006C630 08007326 */  addiu      $s3, $s3, 0x8
    /* 5CE34 8006C634 01009426 */  addiu      $s4, $s4, 0x1
    /* 5CE38 8006C638 2100822A */  slti       $v0, $s4, 0x21
    /* 5CE3C 8006C63C E0FF4014 */  bnez       $v0, .L8006C5C0
    /* 5CE40 8006C640 08005226 */   addiu     $s2, $s2, 0x8
    /* 5CE44 8006C644 EB51033C */  lui        $v1, (0x51EB851F >> 16)
    /* 5CE48 8006C648 C403AA8F */  lw         $t2, 0x3C4($sp)
    /* 5CE4C 8006C64C 1F856334 */  ori        $v1, $v1, (0x51EB851F & 0xFFFF)
    /* 5CE50 8006C650 18004301 */  mult       $t2, $v1
    /* 5CE54 8006C654 10480000 */  mfhi       $t1
    /* 5CE58 8006C658 6666073C */  lui        $a3, (0x66666667 >> 16)
    /* 5CE5C 8006C65C 6766E734 */  ori        $a3, $a3, (0x66666667 & 0xFFFF)
    /* 5CE60 8006C660 18004701 */  mult       $t2, $a3
    /* 5CE64 8006C664 C3370A00 */  sra        $a2, $t2, 31
    /* 5CE68 8006C668 43110900 */  sra        $v0, $t1, 5
    /* 5CE6C 8006C66C 23104600 */  subu       $v0, $v0, $a2
    /* 5CE70 8006C670 40200200 */  sll        $a0, $v0, 1
    /* 5CE74 8006C674 21208200 */  addu       $a0, $a0, $v0
    /* 5CE78 8006C678 C0200400 */  sll        $a0, $a0, 3
    /* 5CE7C 8006C67C 21208200 */  addu       $a0, $a0, $v0
    /* 5CE80 8006C680 80200400 */  sll        $a0, $a0, 2
    /* 5CE84 8006C684 10400000 */  mfhi       $t0
    /* 5CE88 8006C688 23204401 */  subu       $a0, $t2, $a0
    /* 5CE8C 8006C68C 23284401 */  subu       $a1, $t2, $a0
    /* 5CE90 8006C690 1800A300 */  mult       $a1, $v1
    /* 5CE94 8006C694 83180800 */  sra        $v1, $t0, 2
    /* 5CE98 8006C698 23186600 */  subu       $v1, $v1, $a2
    /* 5CE9C 8006C69C 80100300 */  sll        $v0, $v1, 2
    /* 5CEA0 8006C6A0 21104300 */  addu       $v0, $v0, $v1
    /* 5CEA4 8006C6A4 40100200 */  sll        $v0, $v0, 1
    /* 5CEA8 8006C6A8 23104201 */  subu       $v0, $t2, $v0
    /* 5CEAC 8006C6AC 10480000 */  mfhi       $t1
    /* 5CEB0 8006C6B0 23208200 */  subu       $a0, $a0, $v0
    /* 5CEB4 8006C6B4 06004224 */  addiu      $v0, $v0, 0x6
    /* 5CEB8 8006C6B8 18008700 */  mult       $a0, $a3
    /* 5CEBC 8006C6BC 00190200 */  sll        $v1, $v0, 4
    /* 5CEC0 8006C6C0 21186200 */  addu       $v1, $v1, $v0
    /* 5CEC4 8006C6C4 C32F0500 */  sra        $a1, $a1, 31
    /* 5CEC8 8006C6C8 1E02A3A2 */  sb         $v1, 0x21E($s5)
    /* 5CECC 8006C6CC 43190900 */  sra        $v1, $t1, 5
    /* 5CED0 8006C6D0 23186500 */  subu       $v1, $v1, $a1
    /* 5CED4 8006C6D4 06006324 */  addiu      $v1, $v1, 0x6
    /* 5CED8 8006C6D8 00110300 */  sll        $v0, $v1, 4
    /* 5CEDC 8006C6DC 21104300 */  addu       $v0, $v0, $v1
    /* 5CEE0 8006C6E0 C3270400 */  sra        $a0, $a0, 31
    /* 5CEE4 8006C6E4 1C02A2A2 */  sb         $v0, 0x21C($s5)
    /* 5CEE8 8006C6E8 10400000 */  mfhi       $t0
    /* 5CEEC 8006C6EC 83180800 */  sra        $v1, $t0, 2
    /* 5CEF0 8006C6F0 23186400 */  subu       $v1, $v1, $a0
    /* 5CEF4 8006C6F4 06006324 */  addiu      $v1, $v1, 0x6
    /* 5CEF8 8006C6F8 00110300 */  sll        $v0, $v1, 4
    /* 5CEFC 8006C6FC 21104300 */  addu       $v0, $v0, $v1
    /* 5CF00 8006C700 1D02A2A2 */  sb         $v0, 0x21D($s5)
    /* 5CF04 8006C704 0600C387 */  lh         $v1, 0x6($fp)
    /* 5CF08 8006C708 21100000 */  addu       $v0, $zero, $zero
    /* 5CF0C 8006C70C 2802A0AE */  sw         $zero, 0x228($s5)
    /* 5CF10 8006C710 2C02A0A2 */  sb         $zero, 0x22C($s5)
    /* 5CF14 8006C714 52B30108 */  j          .L8006CD48
    /* 5CF18 8006C718 2402A3AE */   sw        $v1, 0x224($s5)
  .L8006C71C:
    /* 5CF1C 8006C71C 0000BE8E */  lw         $fp, 0x0($s5)
    /* 5CF20 8006C720 C463010C */  jal        func_80058F10
    /* 5CF24 8006C724 00000000 */   nop
    /* 5CF28 8006C728 5800A427 */  addiu      $a0, $sp, 0x58
    /* 5CF2C 8006C72C 380A020C */  jal        func_800828E0
    /* 5CF30 8006C730 8C03A2AF */   sw        $v0, 0x38C($sp)
    /* 5CF34 8006C734 580A020C */  jal        func_80082960
    /* 5CF38 8006C738 7800A427 */   addiu     $a0, $sp, 0x78
    /* 5CF3C 8006C73C 741C020C */  jal        func_800871D0
    /* 5CF40 8006C740 00000000 */   nop
    /* 5CF44 8006C744 8864010C */  jal        func_80059220
    /* 5CF48 8006C748 00000000 */   nop
    /* 5CF4C 8006C74C 1800B227 */  addiu      $s2, $sp, 0x18
    /* 5CF50 8006C750 00004A8C */  lw         $t2, 0x0($v0)
    /* 5CF54 8006C754 04004B8C */  lw         $t3, 0x4($v0)
    /* 5CF58 8006C758 08004C8C */  lw         $t4, 0x8($v0)
    /* 5CF5C 8006C75C 0C004D8C */  lw         $t5, 0xC($v0)
    /* 5CF60 8006C760 1800AAAF */  sw         $t2, 0x18($sp)
    /* 5CF64 8006C764 1C00ABAF */  sw         $t3, 0x1C($sp)
    /* 5CF68 8006C768 2000ACAF */  sw         $t4, 0x20($sp)
    /* 5CF6C 8006C76C 2400ADAF */  sw         $t5, 0x24($sp)
    /* 5CF70 8006C770 10004A8C */  lw         $t2, 0x10($v0)
    /* 5CF74 8006C774 14004B8C */  lw         $t3, 0x14($v0)
    /* 5CF78 8006C778 18004C8C */  lw         $t4, 0x18($v0)
    /* 5CF7C 8006C77C 1C004D8C */  lw         $t5, 0x1C($v0)
    /* 5CF80 8006C780 2800AAAF */  sw         $t2, 0x28($sp)
    /* 5CF84 8006C784 2C00ABAF */  sw         $t3, 0x2C($sp)
    /* 5CF88 8006C788 3000ACAF */  sw         $t4, 0x30($sp)
    /* 5CF8C 8006C78C 3400ADAF */  sw         $t5, 0x34($sp)
    /* 5CF90 8006C790 7415020C */  jal        func_800855D0
    /* 5CF94 8006C794 21204002 */   addu      $a0, $s2, $zero
    /* 5CF98 8006C798 A000A0A7 */  sh         $zero, 0xA0($sp)
    /* 5CF9C 8006C79C A200A0A7 */  sh         $zero, 0xA2($sp)
    /* 5CFA0 8006C7A0 A400A0A7 */  sh         $zero, 0xA4($sp)
    /* 5CFA4 8006C7A4 2C02A492 */  lbu        $a0, 0x22C($s5)
    /* 5CFA8 8006C7A8 00000000 */  nop
    /* 5CFAC 8006C7AC 03008430 */  andi       $a0, $a0, 0x3
    /* 5CFB0 8006C7B0 EC1A020C */  jal        func_80086BB0
    /* 5CFB4 8006C7B4 80220400 */   sll       $a0, $a0, 10
    /* 5CFB8 8006C7B8 21204000 */  addu       $a0, $v0, $zero
    /* 5CFBC 8006C7BC 2802A28E */  lw         $v0, 0x228($s5)
    /* 5CFC0 8006C7C0 0800C387 */  lh         $v1, 0x8($fp)
    /* 5CFC4 8006C7C4 00130200 */  sll        $v0, $v0, 12
    /* 5CFC8 8006C7C8 1A004300 */  div        $zero, $v0, $v1
    /* 5CFCC 8006C7CC 02006014 */  bnez       $v1, .L8006C7D8
    /* 5CFD0 8006C7D0 00000000 */   nop
    /* 5CFD4 8006C7D4 0D000700 */  break      7
  .L8006C7D8:
    /* 5CFD8 8006C7D8 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5CFDC 8006C7DC 04006114 */  bne        $v1, $at, .L8006C7F0
    /* 5CFE0 8006C7E0 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5CFE4 8006C7E4 02004114 */  bne        $v0, $at, .L8006C7F0
    /* 5CFE8 8006C7E8 00000000 */   nop
    /* 5CFEC 8006C7EC 0D000600 */  break      6
  .L8006C7F0:
    /* 5CFF0 8006C7F0 12180000 */  mflo       $v1
    /* 5CFF4 8006C7F4 03008104 */  bgez       $a0, .L8006C804
    /* 5CFF8 8006C7F8 03110400 */   sra       $v0, $a0, 4
    /* 5CFFC 8006C7FC 0F008424 */  addiu      $a0, $a0, 0xF
    /* 5D000 8006C800 03110400 */  sra        $v0, $a0, 4
  .L8006C804:
    /* 5D004 8006C804 21806200 */  addu       $s0, $v1, $v0
    /* 5D008 8006C808 B000B0AF */  sw         $s0, 0xB0($sp)
    /* 5D00C 8006C80C B400B0AF */  sw         $s0, 0xB4($sp)
    /* 5D010 8006C810 7363010C */  jal        func_80058DCC
    /* 5D014 8006C814 B800B0AF */   sw        $s0, 0xB8($sp)
    /* 5D018 8006C818 21204000 */  addu       $a0, $v0, $zero
    /* 5D01C 8006C81C EC63010C */  jal        func_80058FB0
    /* 5D020 8006C820 21282002 */   addu      $a1, $s1, $zero
    /* 5D024 8006C824 7415020C */  jal        func_800855D0
    /* 5D028 8006C828 21204002 */   addu      $a0, $s2, $zero
    /* 5D02C 8006C82C 21202002 */  addu       $a0, $s1, $zero
    /* 5D030 8006C830 4C00A527 */  addiu      $a1, $sp, 0x4C
    /* 5D034 8006C834 5C1E020C */  jal        func_80087970
    /* 5D038 8006C838 8803A627 */   addiu     $a2, $sp, 0x388
    /* 5D03C 8006C83C 21206002 */  addu       $a0, $s3, $zero
    /* 5D040 8006C840 3800B027 */  addiu      $s0, $sp, 0x38
    /* 5D044 8006C844 4C1F020C */  jal        func_80087D30
    /* 5D048 8006C848 21280002 */   addu      $a1, $s0, $zero
    /* 5D04C 8006C84C 21200002 */  addu       $a0, $s0, $zero
    /* 5D050 8006C850 9C1D020C */  jal        func_80087670
    /* 5D054 8006C854 21288002 */   addu      $a1, $s4, $zero
    /* 5D058 8006C858 7415020C */  jal        func_800855D0
    /* 5D05C 8006C85C 21200002 */   addu      $a0, $s0, $zero
    /* 5D060 8006C860 1C02A292 */  lbu        $v0, 0x21C($s5)
    /* 5D064 8006C864 2402A58E */  lw         $a1, 0x224($s5)
    /* 5D068 8006C868 00000000 */  nop
    /* 5D06C 8006C86C 18004500 */  mult       $v0, $a1
    /* 5D070 8006C870 12400000 */  mflo       $t0
    /* 5D074 8006C874 0600C387 */  lh         $v1, 0x6($fp)
    /* 5D078 8006C878 00000000 */  nop
    /* 5D07C 8006C87C 1A000301 */  div        $zero, $t0, $v1
    /* 5D080 8006C880 02006014 */  bnez       $v1, .L8006C88C
    /* 5D084 8006C884 00000000 */   nop
    /* 5D088 8006C888 0D000700 */  break      7
  .L8006C88C:
    /* 5D08C 8006C88C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5D090 8006C890 04006114 */  bne        $v1, $at, .L8006C8A4
    /* 5D094 8006C894 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5D098 8006C898 02000115 */  bne        $t0, $at, .L8006C8A4
    /* 5D09C 8006C89C 00000000 */   nop
    /* 5D0A0 8006C8A0 0D000600 */  break      6
  .L8006C8A4:
    /* 5D0A4 8006C8A4 12100000 */  mflo       $v0
    /* 5D0A8 8006C8A8 2802A68E */  lw         $a2, 0x228($s5)
    /* 5D0AC 8006C8AC 00000000 */  nop
    /* 5D0B0 8006C8B0 18004600 */  mult       $v0, $a2
    /* 5D0B4 8006C8B4 12400000 */  mflo       $t0
    /* 5D0B8 8006C8B8 0800C487 */  lh         $a0, 0x8($fp)
    /* 5D0BC 8006C8BC 00000000 */  nop
    /* 5D0C0 8006C8C0 1A000401 */  div        $zero, $t0, $a0
    /* 5D0C4 8006C8C4 02008014 */  bnez       $a0, .L8006C8D0
    /* 5D0C8 8006C8C8 00000000 */   nop
    /* 5D0CC 8006C8CC 0D000700 */  break      7
  .L8006C8D0:
    /* 5D0D0 8006C8D0 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5D0D4 8006C8D4 04008114 */  bne        $a0, $at, .L8006C8E8
    /* 5D0D8 8006C8D8 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5D0DC 8006C8DC 02000115 */  bne        $t0, $at, .L8006C8E8
    /* 5D0E0 8006C8E0 00000000 */   nop
    /* 5D0E4 8006C8E4 0D000600 */  break      6
  .L8006C8E8:
    /* 5D0E8 8006C8E8 12400000 */  mflo       $t0
    /* 5D0EC 8006C8EC 1D02A292 */  lbu        $v0, 0x21D($s5)
    /* 5D0F0 8006C8F0 00000000 */  nop
    /* 5D0F4 8006C8F4 18004500 */  mult       $v0, $a1
    /* 5D0F8 8006C8F8 12480000 */  mflo       $t1
    /* 5D0FC 8006C8FC 00000000 */  nop
    /* 5D100 8006C900 00000000 */  nop
    /* 5D104 8006C904 1A002301 */  div        $zero, $t1, $v1
    /* 5D108 8006C908 02006014 */  bnez       $v1, .L8006C914
    /* 5D10C 8006C90C 00000000 */   nop
    /* 5D110 8006C910 0D000700 */  break      7
  .L8006C914:
    /* 5D114 8006C914 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5D118 8006C918 04006114 */  bne        $v1, $at, .L8006C92C
    /* 5D11C 8006C91C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5D120 8006C920 02002115 */  bne        $t1, $at, .L8006C92C
    /* 5D124 8006C924 00000000 */   nop
    /* 5D128 8006C928 0D000600 */  break      6
  .L8006C92C:
    /* 5D12C 8006C92C 12380000 */  mflo       $a3
    /* 5D130 8006C930 1E02A292 */  lbu        $v0, 0x21E($s5)
    /* 5D134 8006C934 00000000 */  nop
    /* 5D138 8006C938 18004500 */  mult       $v0, $a1
    /* 5D13C 8006C93C 12480000 */  mflo       $t1
    /* 5D140 8006C940 00000000 */  nop
    /* 5D144 8006C944 00000000 */  nop
    /* 5D148 8006C948 1A002301 */  div        $zero, $t1, $v1
    /* 5D14C 8006C94C 02006014 */  bnez       $v1, .L8006C958
    /* 5D150 8006C950 00000000 */   nop
    /* 5D154 8006C954 0D000700 */  break      7
  .L8006C958:
    /* 5D158 8006C958 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5D15C 8006C95C 04006114 */  bne        $v1, $at, .L8006C970
    /* 5D160 8006C960 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5D164 8006C964 02002115 */  bne        $t1, $at, .L8006C970
    /* 5D168 8006C968 00000000 */   nop
    /* 5D16C 8006C96C 0D000600 */  break      6
  .L8006C970:
    /* 5D170 8006C970 12180000 */  mflo       $v1
    /* 5D174 8006C974 00000000 */  nop
    /* 5D178 8006C978 00000000 */  nop
    /* 5D17C 8006C97C 1800E600 */  mult       $a3, $a2
    /* 5D180 8006C980 12480000 */  mflo       $t1
    /* 5D184 8006C984 00000000 */  nop
    /* 5D188 8006C988 00000000 */  nop
    /* 5D18C 8006C98C 1A002401 */  div        $zero, $t1, $a0
    /* 5D190 8006C990 02008014 */  bnez       $a0, .L8006C99C
    /* 5D194 8006C994 00000000 */   nop
    /* 5D198 8006C998 0D000700 */  break      7
  .L8006C99C:
    /* 5D19C 8006C99C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5D1A0 8006C9A0 04008114 */  bne        $a0, $at, .L8006C9B4
    /* 5D1A4 8006C9A4 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5D1A8 8006C9A8 02002115 */  bne        $t1, $at, .L8006C9B4
    /* 5D1AC 8006C9AC 00000000 */   nop
    /* 5D1B0 8006C9B0 0D000600 */  break      6
  .L8006C9B4:
    /* 5D1B4 8006C9B4 12100000 */  mflo       $v0
    /* 5D1B8 8006C9B8 00000000 */  nop
    /* 5D1BC 8006C9BC 00000000 */  nop
    /* 5D1C0 8006C9C0 18006600 */  mult       $v1, $a2
    /* 5D1C4 8006C9C4 12180000 */  mflo       $v1
    /* 5D1C8 8006C9C8 00000000 */  nop
    /* 5D1CC 8006C9CC 00000000 */  nop
    /* 5D1D0 8006C9D0 1A006400 */  div        $zero, $v1, $a0
    /* 5D1D4 8006C9D4 02008014 */  bnez       $a0, .L8006C9E0
    /* 5D1D8 8006C9D8 00000000 */   nop
    /* 5D1DC 8006C9DC 0D000700 */  break      7
  .L8006C9E0:
    /* 5D1E0 8006C9E0 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5D1E4 8006C9E4 04008114 */  bne        $a0, $at, .L8006C9F8
    /* 5D1E8 8006C9E8 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5D1EC 8006C9EC 02006114 */  bne        $v1, $at, .L8006C9F8
    /* 5D1F0 8006C9F0 00000000 */   nop
    /* 5D1F4 8006C9F4 0D000600 */  break      6
  .L8006C9F8:
    /* 5D1F8 8006C9F8 12200000 */  mflo       $a0
    /* 5D1FC 8006C9FC 5C00A8A3 */  sb         $t0, 0x5C($sp)
    /* 5D200 8006CA00 5D00A2A3 */  sb         $v0, 0x5D($sp)
    /* 5D204 8006CA04 5E00A4A3 */  sb         $a0, 0x5E($sp)
    /* 5D208 8006CA08 0000C293 */  lbu        $v0, 0x0($fp)
    /* 5D20C 8006CA0C 2402A48E */  lw         $a0, 0x224($s5)
    /* 5D210 8006CA10 00000000 */  nop
    /* 5D214 8006CA14 18004400 */  mult       $v0, $a0
    /* 5D218 8006CA18 12400000 */  mflo       $t0
    /* 5D21C 8006CA1C 0600C387 */  lh         $v1, 0x6($fp)
    /* 5D220 8006CA20 00000000 */  nop
    /* 5D224 8006CA24 1A000301 */  div        $zero, $t0, $v1
    /* 5D228 8006CA28 02006014 */  bnez       $v1, .L8006CA34
    /* 5D22C 8006CA2C 00000000 */   nop
    /* 5D230 8006CA30 0D000700 */  break      7
  .L8006CA34:
    /* 5D234 8006CA34 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5D238 8006CA38 04006114 */  bne        $v1, $at, .L8006CA4C
    /* 5D23C 8006CA3C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5D240 8006CA40 02000115 */  bne        $t0, $at, .L8006CA4C
    /* 5D244 8006CA44 00000000 */   nop
    /* 5D248 8006CA48 0D000600 */  break      6
  .L8006CA4C:
    /* 5D24C 8006CA4C 12100000 */  mflo       $v0
    /* 5D250 8006CA50 2802A58E */  lw         $a1, 0x228($s5)
    /* 5D254 8006CA54 00000000 */  nop
    /* 5D258 8006CA58 18004500 */  mult       $v0, $a1
    /* 5D25C 8006CA5C 12480000 */  mflo       $t1
    /* 5D260 8006CA60 0800C887 */  lh         $t0, 0x8($fp)
    /* 5D264 8006CA64 00000000 */  nop
    /* 5D268 8006CA68 1A002801 */  div        $zero, $t1, $t0
    /* 5D26C 8006CA6C 02000015 */  bnez       $t0, .L8006CA78
    /* 5D270 8006CA70 00000000 */   nop
    /* 5D274 8006CA74 0D000700 */  break      7
  .L8006CA78:
    /* 5D278 8006CA78 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5D27C 8006CA7C 04000115 */  bne        $t0, $at, .L8006CA90
    /* 5D280 8006CA80 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5D284 8006CA84 02002115 */  bne        $t1, $at, .L8006CA90
    /* 5D288 8006CA88 00000000 */   nop
    /* 5D28C 8006CA8C 0D000600 */  break      6
  .L8006CA90:
    /* 5D290 8006CA90 12480000 */  mflo       $t1
    /* 5D294 8006CA94 0100C293 */  lbu        $v0, 0x1($fp)
    /* 5D298 8006CA98 00000000 */  nop
    /* 5D29C 8006CA9C 18004400 */  mult       $v0, $a0
    /* 5D2A0 8006CAA0 12700000 */  mflo       $t6
    /* 5D2A4 8006CAA4 00000000 */  nop
    /* 5D2A8 8006CAA8 00000000 */  nop
    /* 5D2AC 8006CAAC 1A00C301 */  div        $zero, $t6, $v1
    /* 5D2B0 8006CAB0 02006014 */  bnez       $v1, .L8006CABC
    /* 5D2B4 8006CAB4 00000000 */   nop
    /* 5D2B8 8006CAB8 0D000700 */  break      7
  .L8006CABC:
    /* 5D2BC 8006CABC FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5D2C0 8006CAC0 04006114 */  bne        $v1, $at, .L8006CAD4
    /* 5D2C4 8006CAC4 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5D2C8 8006CAC8 0200C115 */  bne        $t6, $at, .L8006CAD4
    /* 5D2CC 8006CACC 00000000 */   nop
    /* 5D2D0 8006CAD0 0D000600 */  break      6
  .L8006CAD4:
    /* 5D2D4 8006CAD4 12300000 */  mflo       $a2
    /* 5D2D8 8006CAD8 0200C293 */  lbu        $v0, 0x2($fp)
    /* 5D2DC 8006CADC 00000000 */  nop
    /* 5D2E0 8006CAE0 18004400 */  mult       $v0, $a0
    /* 5D2E4 8006CAE4 12700000 */  mflo       $t6
    /* 5D2E8 8006CAE8 00000000 */  nop
    /* 5D2EC 8006CAEC 00000000 */  nop
    /* 5D2F0 8006CAF0 1A00C301 */  div        $zero, $t6, $v1
    /* 5D2F4 8006CAF4 02006014 */  bnez       $v1, .L8006CB00
    /* 5D2F8 8006CAF8 00000000 */   nop
    /* 5D2FC 8006CAFC 0D000700 */  break      7
  .L8006CB00:
    /* 5D300 8006CB00 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5D304 8006CB04 04006114 */  bne        $v1, $at, .L8006CB18
    /* 5D308 8006CB08 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5D30C 8006CB0C 0200C115 */  bne        $t6, $at, .L8006CB18
    /* 5D310 8006CB10 00000000 */   nop
    /* 5D314 8006CB14 0D000600 */  break      6
  .L8006CB18:
    /* 5D318 8006CB18 12180000 */  mflo       $v1
    /* 5D31C 8006CB1C 00000000 */  nop
    /* 5D320 8006CB20 00000000 */  nop
    /* 5D324 8006CB24 1800C500 */  mult       $a2, $a1
    /* 5D328 8006CB28 12700000 */  mflo       $t6
    /* 5D32C 8006CB2C 00000000 */  nop
    /* 5D330 8006CB30 00000000 */  nop
    /* 5D334 8006CB34 1A00C801 */  div        $zero, $t6, $t0
    /* 5D338 8006CB38 02000015 */  bnez       $t0, .L8006CB44
    /* 5D33C 8006CB3C 00000000 */   nop
    /* 5D340 8006CB40 0D000700 */  break      7
  .L8006CB44:
    /* 5D344 8006CB44 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5D348 8006CB48 04000115 */  bne        $t0, $at, .L8006CB5C
    /* 5D34C 8006CB4C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5D350 8006CB50 0200C115 */  bne        $t6, $at, .L8006CB5C
    /* 5D354 8006CB54 00000000 */   nop
    /* 5D358 8006CB58 0D000600 */  break      6
  .L8006CB5C:
    /* 5D35C 8006CB5C 12100000 */  mflo       $v0
    /* 5D360 8006CB60 00000000 */  nop
    /* 5D364 8006CB64 00000000 */  nop
    /* 5D368 8006CB68 18006500 */  mult       $v1, $a1
    /* 5D36C 8006CB6C 12180000 */  mflo       $v1
    /* 5D370 8006CB70 00000000 */  nop
    /* 5D374 8006CB74 00000000 */  nop
    /* 5D378 8006CB78 1A006800 */  div        $zero, $v1, $t0
    /* 5D37C 8006CB7C 02000015 */  bnez       $t0, .L8006CB88
    /* 5D380 8006CB80 00000000 */   nop
    /* 5D384 8006CB84 0D000700 */  break      7
  .L8006CB88:
    /* 5D388 8006CB88 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5D38C 8006CB8C 04000115 */  bne        $t0, $at, .L8006CBA0
    /* 5D390 8006CB90 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5D394 8006CB94 02006114 */  bne        $v1, $at, .L8006CBA0
    /* 5D398 8006CB98 00000000 */   nop
    /* 5D39C 8006CB9C 0D000600 */  break      6
  .L8006CBA0:
    /* 5D3A0 8006CBA0 12400000 */  mflo       $t0
    /* 5D3A4 8006CBA4 21A00000 */  addu       $s4, $zero, $zero
    /* 5D3A8 8006CBA8 04001324 */  addiu      $s3, $zero, 0x4
    /* 5D3AC 8006CBAC 02001224 */  addiu      $s2, $zero, 0x2
    /* 5D3B0 8006CBB0 08001124 */  addiu      $s1, $zero, 0x8
    /* 5D3B4 8006CBB4 21806002 */  addu       $s0, $s3, $zero
    /* 5D3B8 8006CBB8 7802A727 */  addiu      $a3, $sp, 0x278
    /* 5D3BC 8006CBBC 6400A9A3 */  sb         $t1, 0x64($sp)
    /* 5D3C0 8006CBC0 6C00A9A3 */  sb         $t1, 0x6C($sp)
    /* 5D3C4 8006CBC4 F001A627 */  addiu      $a2, $sp, 0x1F0
    /* 5D3C8 8006CBC8 21B0C000 */  addu       $s6, $a2, $zero
    /* 5D3CC 8006CBCC 0400A426 */  addiu      $a0, $s5, 0x4
    /* 5D3D0 8006CBD0 E000A527 */  addiu      $a1, $sp, 0xE0
    /* 5D3D4 8006CBD4 21B8A000 */  addu       $s7, $a1, $zero
    /* 5D3D8 8006CBD8 6500A2A3 */  sb         $v0, 0x65($sp)
    /* 5D3DC 8006CBDC 6D00A2A3 */  sb         $v0, 0x6D($sp)
    /* 5D3E0 8006CBE0 0003A227 */  addiu      $v0, $sp, 0x300
    /* 5D3E4 8006CBE4 6600A8A3 */  sb         $t0, 0x66($sp)
    /* 5D3E8 8006CBE8 6E00A8A3 */  sb         $t0, 0x6E($sp)
    /* 5D3EC 8006CBEC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5D3F0 8006CBF0 43000224 */  addiu      $v0, $zero, 0x43
    /* 5D3F4 8006CBF4 301F020C */  jal        func_80087CC0
    /* 5D3F8 8006CBF8 1400A2AF */   sw        $v0, 0x14($sp)
  .L8006CBFC:
    /* 5D3FC 8006CBFC E200A397 */  lhu        $v1, 0xE2($sp)
    /* 5D400 8006CC00 F001A497 */  lhu        $a0, 0x1F0($sp)
    /* 5D404 8006CC04 E000A297 */  lhu        $v0, 0xE0($sp)
    /* 5D408 8006CC08 6200A3A7 */  sh         $v1, 0x62($sp)
    /* 5D40C 8006CC0C 2118F002 */  addu       $v1, $s7, $s0
    /* 5D410 8006CC10 6000A2A7 */  sh         $v0, 0x60($sp)
    /* 5D414 8006CC14 00006294 */  lhu        $v0, 0x0($v1)
    /* 5D418 8006CC18 00000000 */  nop
    /* 5D41C 8006CC1C 6800A2A7 */  sh         $v0, 0x68($sp)
    /* 5D420 8006CC20 02006294 */  lhu        $v0, 0x2($v1)
    /* 5D424 8006CC24 2118F102 */  addu       $v1, $s7, $s1
    /* 5D428 8006CC28 6A00A2A7 */  sh         $v0, 0x6A($sp)
    /* 5D42C 8006CC2C 00006294 */  lhu        $v0, 0x0($v1)
    /* 5D430 8006CC30 00000000 */  nop
    /* 5D434 8006CC34 7000A2A7 */  sh         $v0, 0x70($sp)
    /* 5D438 8006CC38 02006294 */  lhu        $v0, 0x2($v1)
    /* 5D43C 8006CC3C 00000000 */  nop
    /* 5D440 8006CC40 7200A2A7 */  sh         $v0, 0x72($sp)
    /* 5D444 8006CC44 2110D202 */  addu       $v0, $s6, $s2
    /* 5D448 8006CC48 00004594 */  lhu        $a1, 0x0($v0)
    /* 5D44C 8006CC4C 2110D302 */  addu       $v0, $s6, $s3
    /* 5D450 8006CC50 00004694 */  lhu        $a2, 0x0($v0)
    /* 5D454 8006CC54 1C27020C */  jal        func_80089C70
    /* 5D458 8006CC58 00000000 */   nop
    /* 5D45C 8006CC5C 0003A497 */  lhu        $a0, 0x300($sp)
    /* 5D460 8006CC60 0203A597 */  lhu        $a1, 0x302($sp)
    /* 5D464 8006CC64 0403A397 */  lhu        $v1, 0x304($sp)
    /* 5D468 8006CC68 25208500 */  or         $a0, $a0, $a1
    /* 5D46C 8006CC6C 25186400 */  or         $v1, $v1, $a0
    /* 5D470 8006CC70 20006430 */  andi       $a0, $v1, 0x20
    /* 5D474 8006CC74 C21F0200 */  srl        $v1, $v0, 31
    /* 5D478 8006CC78 21186200 */  addu       $v1, $v1, $v0
    /* 5D47C 8006CC7C 43180300 */  sra        $v1, $v1, 1
    /* 5D480 8006CC80 07006004 */  bltz       $v1, .L8006CCA0
    /* 5D484 8006CC84 8803A4AF */   sw        $a0, 0x388($sp)
    /* 5D488 8006CC88 05008014 */  bnez       $a0, .L8006CCA0
    /* 5D48C 8006CC8C 5800A427 */   addiu     $a0, $sp, 0x58
    /* 5D490 8006CC90 8C03A58F */  lw         $a1, 0x38C($sp)
    /* 5D494 8006CC94 FFFF6630 */  andi       $a2, $v1, 0xFFFF
    /* 5D498 8006CC98 986C010C */  jal        func_8005B260
    /* 5D49C 8006CC9C 01000724 */   addiu     $a3, $zero, 0x1
  .L8006CCA0:
    /* 5D4A0 8006CCA0 02007326 */  addiu      $s3, $s3, 0x2
    /* 5D4A4 8006CCA4 02005226 */  addiu      $s2, $s2, 0x2
    /* 5D4A8 8006CCA8 04003126 */  addiu      $s1, $s1, 0x4
    /* 5D4AC 8006CCAC 01009426 */  addiu      $s4, $s4, 0x1
    /* 5D4B0 8006CCB0 2000822A */  slti       $v0, $s4, 0x20
    /* 5D4B4 8006CCB4 D1FF4014 */  bnez       $v0, .L8006CBFC
    /* 5D4B8 8006CCB8 04001026 */   addiu     $s0, $s0, 0x4
    /* 5D4BC 8006CCBC 9D1C020C */  jal        func_80087274
    /* 5D4C0 8006CCC0 00000000 */   nop
    /* 5D4C4 8006CCC4 2C02A292 */  lbu        $v0, 0x22C($s5)
    /* 5D4C8 8006CCC8 00000000 */  nop
    /* 5D4CC 8006CCCC 01004224 */  addiu      $v0, $v0, 0x1
    /* 5D4D0 8006CCD0 2C02A2A2 */  sb         $v0, 0x22C($s5)
    /* 5D4D4 8006CCD4 C403AA8F */  lw         $t2, 0x3C4($sp)
    /* 5D4D8 8006CCD8 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 5D4DC 8006CCDC 07004215 */  bne        $t2, $v0, .L8006CCFC
    /* 5D4E0 8006CCE0 00000000 */   nop
    /* 5D4E4 8006CCE4 2402A28E */  lw         $v0, 0x224($s5)
    /* 5D4E8 8006CCE8 9003A393 */  lbu        $v1, 0x390($sp)
    /* 5D4EC 8006CCEC 00000000 */  nop
    /* 5D4F0 8006CCF0 23104300 */  subu       $v0, $v0, $v1
    /* 5D4F4 8006CCF4 4EB30108 */  j          .L8006CD38
    /* 5D4F8 8006CCF8 2402A2AE */   sw        $v0, 0x224($s5)
  .L8006CCFC:
    /* 5D4FC 8006CCFC 2802A38E */  lw         $v1, 0x228($s5)
    /* 5D500 8006CD00 9003A293 */  lbu        $v0, 0x390($sp)
    /* 5D504 8006CD04 00000000 */  nop
    /* 5D508 8006CD08 21186200 */  addu       $v1, $v1, $v0
    /* 5D50C 8006CD0C 08006004 */  bltz       $v1, .L8006CD30
    /* 5D510 8006CD10 2802A3AE */   sw        $v1, 0x228($s5)
    /* 5D514 8006CD14 0800C487 */  lh         $a0, 0x8($fp)
    /* 5D518 8006CD18 00000000 */  nop
    /* 5D51C 8006CD1C 2A108300 */  slt        $v0, $a0, $v1
    /* 5D520 8006CD20 05004010 */  beqz       $v0, .L8006CD38
    /* 5D524 8006CD24 21188000 */   addu      $v1, $a0, $zero
    /* 5D528 8006CD28 4DB30108 */  j          .L8006CD34
    /* 5D52C 8006CD2C 00000000 */   nop
  .L8006CD30:
    /* 5D530 8006CD30 21180000 */  addu       $v1, $zero, $zero
  .L8006CD34:
    /* 5D534 8006CD34 2802A3AE */  sw         $v1, 0x228($s5)
  .L8006CD38:
    /* 5D538 8006CD38 2402A28E */  lw         $v0, 0x224($s5)
    /* 5D53C 8006CD3C 00000000 */  nop
    /* 5D540 8006CD40 01004228 */  slti       $v0, $v0, 0x1
    /* 5D544 8006CD44 40100200 */  sll        $v0, $v0, 1
  .L8006CD48:
    /* 5D548 8006CD48 BC03BF8F */  lw         $ra, 0x3BC($sp)
    /* 5D54C 8006CD4C B803BE8F */  lw         $fp, 0x3B8($sp)
    /* 5D550 8006CD50 B403B78F */  lw         $s7, 0x3B4($sp)
    /* 5D554 8006CD54 B003B68F */  lw         $s6, 0x3B0($sp)
    /* 5D558 8006CD58 AC03B58F */  lw         $s5, 0x3AC($sp)
    /* 5D55C 8006CD5C A803B48F */  lw         $s4, 0x3A8($sp)
    /* 5D560 8006CD60 A403B38F */  lw         $s3, 0x3A4($sp)
    /* 5D564 8006CD64 A003B28F */  lw         $s2, 0x3A0($sp)
    /* 5D568 8006CD68 9C03B18F */  lw         $s1, 0x39C($sp)
    /* 5D56C 8006CD6C 9803B08F */  lw         $s0, 0x398($sp)
    /* 5D570 8006CD70 0800E003 */  jr         $ra
    /* 5D574 8006CD74 C003BD27 */   addiu     $sp, $sp, 0x3C0
endlabel func_8006C37C
