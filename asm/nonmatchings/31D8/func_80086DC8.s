/* Handwritten function */
nonmatching func_80086DC8, 0x80

glabel func_80086DC8
    /* 775C8 80086DC8 0980013C */  lui        $at, %hi(D_80095198)
    /* 775CC 80086DCC 98513FAC */  sw         $ra, %lo(D_80095198)($at)
    /* 775D0 80086DD0 C826020C */  jal        func_80089B20
    /* 775D4 80086DD4 00000000 */   nop
    /* 775D8 80086DD8 09801F3C */  lui        $ra, %hi(D_80095198)
    /* 775DC 80086DDC 9851FF8F */  lw         $ra, %lo(D_80095198)($ra)
    /* 775E0 80086DE0 00000000 */  nop
    /* 775E4 80086DE4 00600240 */  mfc0       $v0, $12 /* handwritten instruction */
    /* 775E8 80086DE8 0040033C */  lui        $v1, (0x40000000 >> 16)
    /* 775EC 80086DEC 25104300 */  or         $v0, $v0, $v1
    /* 775F0 80086DF0 00608240 */  mtc0       $v0, $12 /* handwritten instruction */
    /* 775F4 80086DF4 00000000 */  nop
    /* 775F8 80086DF8 55010824 */  addiu      $t0, $zero, 0x155
    /* 775FC 80086DFC 00E8C848 */  ctc2       $t0, $29 /* handwritten instruction */
    /* 77600 80086E00 00000000 */  nop
    /* 77604 80086E04 00010824 */  addiu      $t0, $zero, 0x100
    /* 77608 80086E08 00F0C848 */  ctc2       $t0, $30 /* handwritten instruction */
    /* 7760C 80086E0C 00000000 */  nop
    /* 77610 80086E10 E8030824 */  addiu      $t0, $zero, 0x3E8
    /* 77614 80086E14 00D0C848 */  ctc2       $t0, $26 /* handwritten instruction */
    /* 77618 80086E18 00000000 */  nop
    /* 7761C 80086E1C 9EEF0824 */  addiu      $t0, $zero, -0x1062
    /* 77620 80086E20 00D8C848 */  ctc2       $t0, $27 /* handwritten instruction */
    /* 77624 80086E24 00000000 */  nop
    /* 77628 80086E28 4001083C */  lui        $t0, (0x1400000 >> 16)
    /* 7762C 80086E2C 00E0C848 */  ctc2       $t0, $28 /* handwritten instruction */
    /* 77630 80086E30 00000000 */  nop
    /* 77634 80086E34 00C0C048 */  ctc2       $zero, $24 /* handwritten instruction */
    /* 77638 80086E38 00C8C048 */  ctc2       $zero, $25 /* handwritten instruction */
    /* 7763C 80086E3C 00000000 */  nop
    /* 77640 80086E40 0800E003 */  jr         $ra
    /* 77644 80086E44 00000000 */   nop
endlabel func_80086DC8
    /* 77648 80086E48 00000000 */  nop
    /* 7764C 80086E4C 00000000 */  nop
