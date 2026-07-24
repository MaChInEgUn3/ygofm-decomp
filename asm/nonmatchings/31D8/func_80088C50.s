/* Handwritten function */
nonmatching func_80088C50, 0x1FC

glabel func_80088C50
    /* 79450 80088C50 04008884 */  lh         $t0, 0x4($a0)
    /* 79454 80088C54 25100500 */  or         $v0, $zero, $a1
    /* 79458 80088C58 0980033C */  lui        $v1, %hi(D_80095638)
    /* 7945C 80088C5C 38566324 */  addiu      $v1, $v1, %lo(D_80095638)
    /* 79460 80088C60 00008C8C */  lw         $t4, 0x0($a0)
    /* 79464 80088C64 C35F0800 */  sra        $t3, $t0, 31
    /* 79468 80088C68 20400B01 */  add        $t0, $t0, $t3 /* handwritten instruction */
    /* 7946C 80088C6C 26400B01 */  xor        $t0, $t0, $t3
    /* 79470 80088C70 80400800 */  sll        $t0, $t0, 2
    /* 79474 80088C74 FC3F0831 */  andi       $t0, $t0, 0x3FFC
    /* 79478 80088C78 20400301 */  add        $t0, $t0, $v1 /* handwritten instruction */
    /* 7947C 80088C7C 0000068D */  lw         $a2, 0x0($t0)
    /* 79480 80088C80 03440C00 */  sra        $t0, $t4, 16
    /* 79484 80088C84 C3570800 */  sra        $t2, $t0, 31
    /* 79488 80088C88 20400A01 */  add        $t0, $t0, $t2 /* handwritten instruction */
    /* 7948C 80088C8C 26400A01 */  xor        $t0, $t0, $t2
    /* 79490 80088C90 80400800 */  sll        $t0, $t0, 2
    /* 79494 80088C94 FC3F0831 */  andi       $t0, $t0, 0x3FFC
    /* 79498 80088C98 20400301 */  add        $t0, $t0, $v1 /* handwritten instruction */
    /* 7949C 80088C9C 0000058D */  lw         $a1, 0x0($t0)
    /* 794A0 80088CA0 00440C00 */  sll        $t0, $t4, 16
    /* 794A4 80088CA4 03440800 */  sra        $t0, $t0, 16
    /* 794A8 80088CA8 C34F0800 */  sra        $t1, $t0, 31
    /* 794AC 80088CAC 20400901 */  add        $t0, $t0, $t1 /* handwritten instruction */
    /* 794B0 80088CB0 26400901 */  xor        $t0, $t0, $t1
    /* 794B4 80088CB4 80400800 */  sll        $t0, $t0, 2
    /* 794B8 80088CB8 FC3F0831 */  andi       $t0, $t0, 0x3FFC
    /* 794BC 80088CBC 20400301 */  add        $t0, $t0, $v1 /* handwritten instruction */
    /* 794C0 80088CC0 0000048D */  lw         $a0, 0x0($t0)
    /* 794C4 80088CC4 000C0600 */  sll        $at, $a2, 16
    /* 794C8 80088CC8 03340600 */  sra        $a2, $a2, 16
    /* 794CC 80088CCC 00340600 */  sll        $a2, $a2, 16
    /* 794D0 80088CD0 20082B00 */  add        $at, $at, $t3 /* handwritten instruction */
    /* 794D4 80088CD4 26082B00 */  xor        $at, $at, $t3
    /* 794D8 80088CD8 020C0100 */  srl        $at, $at, 16
    /* 794DC 80088CDC 2530C100 */  or         $a2, $a2, $at
    /* 794E0 80088CE0 000C0500 */  sll        $at, $a1, 16
    /* 794E4 80088CE4 032C0500 */  sra        $a1, $a1, 16
    /* 794E8 80088CE8 002C0500 */  sll        $a1, $a1, 16
    /* 794EC 80088CEC 20082A00 */  add        $at, $at, $t2 /* handwritten instruction */
    /* 794F0 80088CF0 26082A00 */  xor        $at, $at, $t2
    /* 794F4 80088CF4 020C0100 */  srl        $at, $at, 16
    /* 794F8 80088CF8 2528A100 */  or         $a1, $a1, $at
    /* 794FC 80088CFC 000C0400 */  sll        $at, $a0, 16
    /* 79500 80088D00 03240400 */  sra        $a0, $a0, 16
    /* 79504 80088D04 00240400 */  sll        $a0, $a0, 16
    /* 79508 80088D08 20082900 */  add        $at, $at, $t1 /* handwritten instruction */
    /* 7950C 80088D0C 26082900 */  xor        $at, $at, $t1
    /* 79510 80088D10 020C0100 */  srl        $at, $at, 16
    /* 79514 80088D14 25208100 */  or         $a0, $a0, $at
    /* 79518 80088D18 03440400 */  sra        $t0, $a0, 16
    /* 7951C 80088D1C 00408848 */  mtc2       $t0, $8 /* handwritten instruction */
    /* 79520 80088D20 003C0500 */  sll        $a3, $a1, 16
    /* 79524 80088D24 033C0700 */  sra        $a3, $a3, 16
    /* 79528 80088D28 00488748 */  mtc2       $a3, $9 /* handwritten instruction */
    /* 7952C 80088D2C 001C0600 */  sll        $v1, $a2, 16
    /* 79530 80088D30 031C0300 */  sra        $v1, $v1, 16
    /* 79534 80088D34 00508348 */  mtc2       $v1, $10 /* handwritten instruction */
    /* 79538 80088D38 030C0600 */  sra        $at, $a2, 16
    /* 7953C 80088D3C 00588148 */  mtc2       $at, $11 /* handwritten instruction */
    /* 79540 80088D40 00000000 */  nop
    /* 79544 80088D44 00000000 */  nop
    /* 79548 80088D48 3D00984B */  gpf        1
    /* 7954C 80088D4C 030C0500 */  sra        $at, $a1, 16
    /* 79550 80088D50 18002800 */  mult       $at, $t0
    /* 79554 80088D54 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 79558 80088D58 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 7955C 80088D5C 00740400 */  sll        $t6, $a0, 16
    /* 79560 80088D60 00580A48 */  mfc2       $t2, $11 /* handwritten instruction */
    /* 79564 80088D64 03740E00 */  sra        $t6, $t6, 16
    /* 79568 80088D68 00408E48 */  mtc2       $t6, $8 /* handwritten instruction */
    /* 7956C 80088D6C 00488748 */  mtc2       $a3, $9 /* handwritten instruction */
    /* 79570 80088D70 00508348 */  mtc2       $v1, $10 /* handwritten instruction */
    /* 79574 80088D74 030C0600 */  sra        $at, $a2, 16
    /* 79578 80088D78 00588148 */  mtc2       $at, $11 /* handwritten instruction */
    /* 7957C 80088D7C 00000000 */  nop
    /* 79580 80088D80 00000000 */  nop
    /* 79584 80088D84 3D00984B */  gpf        1
    /* 79588 80088D88 12080000 */  mflo       $at
    /* 7958C 80088D8C 030B0100 */  sra        $at, $at, 12
    /* 79590 80088D90 100041A4 */  sh         $at, 0x10($v0)
    /* 79594 80088D94 00480B48 */  mfc2       $t3, $9 /* handwritten instruction */
    /* 79598 80088D98 00500C48 */  mfc2       $t4, $10 /* handwritten instruction */
    /* 7959C 80088D9C 00580D48 */  mfc2       $t5, $11 /* handwritten instruction */
    /* 795A0 80088DA0 030C0600 */  sra        $at, $a2, 16
    /* 795A4 80088DA4 00408148 */  mtc2       $at, $8 /* handwritten instruction */
    /* 795A8 80088DA8 030C0500 */  sra        $at, $a1, 16
    /* 795AC 80088DAC 00488148 */  mtc2       $at, $9 /* handwritten instruction */
    /* 795B0 80088DB0 18002E00 */  mult       $at, $t6
    /* 795B4 80088DB4 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 795B8 80088DB8 00588848 */  mtc2       $t0, $11 /* handwritten instruction */
    /* 795BC 80088DBC 22380700 */  neg        $a3, $a3 /* handwritten instruction */
    /* 795C0 80088DC0 FFFFE730 */  andi       $a3, $a3, 0xFFFF
    /* 795C4 80088DC4 3D00984B */  gpf        1
    /* 795C8 80088DC8 00480448 */  mfc2       $a0, $9 /* handwritten instruction */
    /* 795CC 80088DCC 00500548 */  mfc2       $a1, $10 /* handwritten instruction */
    /* 795D0 80088DD0 00580648 */  mfc2       $a2, $11 /* handwritten instruction */
    /* 795D4 80088DD4 00488148 */  mtc2       $at, $9 /* handwritten instruction */
    /* 795D8 80088DD8 12080000 */  mflo       $at
    /* 795DC 80088DDC 00408348 */  mtc2       $v1, $8 /* handwritten instruction */
    /* 795E0 80088DE0 030B0100 */  sra        $at, $at, 12
    /* 795E4 80088DE4 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 795E8 80088DE8 000C0100 */  sll        $at, $at, 16
    /* 795EC 80088DEC 00588848 */  mtc2       $t0, $11 /* handwritten instruction */
    /* 795F0 80088DF0 2538E100 */  or         $a3, $a3, $at
    /* 795F4 80088DF4 0C0047AC */  sw         $a3, 0xC($v0)
    /* 795F8 80088DF8 3D00984B */  gpf        1
    /* 795FC 80088DFC FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 79600 80088E00 2228A900 */  sub        $a1, $a1, $t1 /* handwritten instruction */
    /* 79604 80088E04 002C0500 */  sll        $a1, $a1, 16
    /* 79608 80088E08 2528A400 */  or         $a1, $a1, $a0
    /* 7960C 80088E0C 000045AC */  sw         $a1, 0x0($v0)
    /* 79610 80088E10 00480148 */  mfc2       $at, $9 /* handwritten instruction */
    /* 79614 80088E14 2030CC00 */  add        $a2, $a2, $t4 /* handwritten instruction */
    /* 79618 80088E18 00500E48 */  mfc2       $t6, $10 /* handwritten instruction */
    /* 7961C 80088E1C FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 79620 80088E20 00580F48 */  mfc2       $t7, $11 /* handwritten instruction */
    /* 79624 80088E24 000C0100 */  sll        $at, $at, 16
    /* 79628 80088E28 25082600 */  or         $at, $at, $a2
    /* 7962C 80088E2C 040041AC */  sw         $at, 0x4($v0)
    /* 79630 80088E30 2070CA01 */  add        $t6, $t6, $t2 /* handwritten instruction */
    /* 79634 80088E34 FFFFCE31 */  andi       $t6, $t6, 0xFFFF
    /* 79638 80088E38 2278ED01 */  sub        $t7, $t7, $t5 /* handwritten instruction */
    /* 7963C 80088E3C 007C0F00 */  sll        $t7, $t7, 16
    /* 79640 80088E40 2570CF01 */  or         $t6, $t6, $t7
    /* 79644 80088E44 0800E003 */  jr         $ra
    /* 79648 80088E48 08004EAC */   sw        $t6, 0x8($v0)
endlabel func_80088C50
    /* 7964C 80088E4C 00000000 */  nop
