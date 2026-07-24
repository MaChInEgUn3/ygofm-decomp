nonmatching func_8001B8B8, 0x80

glabel func_8001B8B8
    /* C0B8 8001B8B8 21280000 */  addu       $a1, $zero, $zero
    /* C0BC 8001B8BC 4000063C */  lui        $a2, (0x404040 >> 16)
    /* C0C0 8001B8C0 4040C634 */  ori        $a2, $a2, (0x404040 & 0xFFFF)
    /* C0C4 8001B8C4 0F80023C */  lui        $v0, %hi(D_800EA030)
    /* C0C8 8001B8C8 30A04324 */  addiu      $v1, $v0, %lo(D_800EA030)
  .L8001B8CC:
    /* C0CC 8001B8CC 09006290 */  lbu        $v0, 0x9($v1)
    /* C0D0 8001B8D0 00000000 */  nop
    /* C0D4 8001B8D4 04004014 */  bnez       $v0, .L8001B8E8
    /* C0D8 8001B8D8 00000000 */   nop
    /* C0DC 8001B8DC 0000628C */  lw         $v0, 0x0($v1)
    /* C0E0 8001B8E0 00000000 */  nop
    /* C0E4 8001B8E4 0C0046AC */  sw         $a2, 0xC($v0)
  .L8001B8E8:
    /* C0E8 8001B8E8 0100A524 */  addiu      $a1, $a1, 0x1
    /* C0EC 8001B8EC 0500A228 */  slti       $v0, $a1, 0x5
    /* C0F0 8001B8F0 F6FF4014 */  bnez       $v0, .L8001B8CC
    /* C0F4 8001B8F4 0C006324 */   addiu     $v1, $v1, 0xC
    /* C0F8 8001B8F8 15008290 */  lbu        $v0, 0x15($a0)
    /* C0FC 8001B8FC 00000000 */  nop
    /* C100 8001B900 0B004014 */  bnez       $v0, .L8001B930
    /* C104 8001B904 8000053C */   lui       $a1, (0x808080 >> 16)
    /* C108 8001B908 0F80033C */  lui        $v1, %hi(D_800EA030)
    /* C10C 8001B90C 0E008480 */  lb         $a0, 0xE($a0)
    /* C110 8001B910 30A06324 */  addiu      $v1, $v1, %lo(D_800EA030)
    /* C114 8001B914 40100400 */  sll        $v0, $a0, 1
    /* C118 8001B918 21104400 */  addu       $v0, $v0, $a0
    /* C11C 8001B91C 80100200 */  sll        $v0, $v0, 2
    /* C120 8001B920 21104300 */  addu       $v0, $v0, $v1
    /* C124 8001B924 0000428C */  lw         $v0, 0x0($v0)
    /* C128 8001B928 8080A534 */  ori        $a1, $a1, (0x808080 & 0xFFFF)
    /* C12C 8001B92C 0C0045AC */  sw         $a1, 0xC($v0)
  .L8001B930:
    /* C130 8001B930 0800E003 */  jr         $ra
    /* C134 8001B934 00000000 */   nop
endlabel func_8001B8B8
