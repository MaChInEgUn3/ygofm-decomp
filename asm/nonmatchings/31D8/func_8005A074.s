nonmatching func_8005A074, 0x68

glabel func_8005A074
    /* 4A874 8005A074 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4A878 8005A078 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4A87C 8005A07C 21888000 */  addu       $s1, $a0, $zero
    /* 4A880 8005A080 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4A884 8005A084 5D7C010C */  jal        func_8005F174
    /* 4A888 8005A088 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4A88C 8005A08C 21804000 */  addu       $s0, $v0, $zero
    /* 4A890 8005A090 01000224 */  addiu      $v0, $zero, 0x1
    /* 4A894 8005A094 05000216 */  bne        $s0, $v0, .L8005A0AC
    /* 4A898 8005A098 0F80033C */   lui       $v1, %hi(D_800F2B20)
    /* 4A89C 8005A09C 637C010C */  jal        func_8005F18C
    /* 4A8A0 8005A0A0 00000000 */   nop
    /* 4A8A4 8005A0A4 08005010 */  beq        $v0, $s0, .L8005A0C8
    /* 4A8A8 8005A0A8 0F80033C */   lui       $v1, %hi(D_800F2B20)
  .L8005A0AC:
    /* 4A8AC 8005A0AC 202B6324 */  addiu      $v1, $v1, %lo(D_800F2B20)
    /* 4A8B0 8005A0B0 02002106 */  bgez       $s1, .L8005A0BC
    /* 4A8B4 8005A0B4 21102002 */   addu      $v0, $s1, $zero
    /* 4A8B8 8005A0B8 23100200 */  negu       $v0, $v0
  .L8005A0BC:
    /* 4A8BC 8005A0BC 40100200 */  sll        $v0, $v0, 1
    /* 4A8C0 8005A0C0 0A0062A4 */  sh         $v0, 0xA($v1)
    /* 4A8C4 8005A0C4 080060A4 */  sh         $zero, 0x8($v1)
  .L8005A0C8:
    /* 4A8C8 8005A0C8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4A8CC 8005A0CC 1400B18F */  lw         $s1, 0x14($sp)
    /* 4A8D0 8005A0D0 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A8D4 8005A0D4 0800E003 */  jr         $ra
    /* 4A8D8 8005A0D8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8005A074
