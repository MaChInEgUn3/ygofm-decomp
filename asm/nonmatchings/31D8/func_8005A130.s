nonmatching func_8005A130, 0x58

glabel func_8005A130
    /* 4A930 8005A130 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4A934 8005A134 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4A938 8005A138 21888000 */  addu       $s1, $a0, $zero
    /* 4A93C 8005A13C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4A940 8005A140 5D7C010C */  jal        func_8005F174
    /* 4A944 8005A144 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4A948 8005A148 21804000 */  addu       $s0, $v0, $zero
    /* 4A94C 8005A14C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4A950 8005A150 05000216 */  bne        $s0, $v0, .L8005A168
    /* 4A954 8005A154 0F80023C */   lui       $v0, %hi(D_800F2B20)
    /* 4A958 8005A158 637C010C */  jal        func_8005F18C
    /* 4A95C 8005A15C 00000000 */   nop
    /* 4A960 8005A160 04005010 */  beq        $v0, $s0, .L8005A174
    /* 4A964 8005A164 0F80023C */   lui       $v0, %hi(D_800F2B20)
  .L8005A168:
    /* 4A968 8005A168 202B4224 */  addiu      $v0, $v0, %lo(D_800F2B20)
    /* 4A96C 8005A16C 060051A4 */  sh         $s1, 0x6($v0)
    /* 4A970 8005A170 040051A4 */  sh         $s1, 0x4($v0)
  .L8005A174:
    /* 4A974 8005A174 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4A978 8005A178 1400B18F */  lw         $s1, 0x14($sp)
    /* 4A97C 8005A17C 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A980 8005A180 0800E003 */  jr         $ra
    /* 4A984 8005A184 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8005A130
