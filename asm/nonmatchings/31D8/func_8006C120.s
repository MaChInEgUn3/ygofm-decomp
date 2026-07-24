nonmatching func_8006C120, 0x1DC

glabel func_8006C120
    /* 5C920 8006C120 A8FFBD27 */  addiu      $sp, $sp, -0x58
    /* 5C924 8006C124 3000B0AF */  sw         $s0, 0x30($sp)
    /* 5C928 8006C128 21808000 */  addu       $s0, $a0, $zero
    /* 5C92C 8006C12C 3800B2AF */  sw         $s2, 0x38($sp)
    /* 5C930 8006C130 2190A000 */  addu       $s2, $a1, $zero
    /* 5C934 8006C134 3400B1AF */  sw         $s1, 0x34($sp)
    /* 5C938 8006C138 2188C000 */  addu       $s1, $a2, $zero
    /* 5C93C 8006C13C 4800B6AF */  sw         $s6, 0x48($sp)
    /* 5C940 8006C140 21B0E000 */  addu       $s6, $a3, $zero
    /* 5C944 8006C144 1800A427 */  addiu      $a0, $sp, 0x18
    /* 5C948 8006C148 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 5C94C 8006C14C 6800B38F */  lw         $s3, 0x68($sp)
    /* 5C950 8006C150 21280002 */  addu       $a1, $s0, $zero
    /* 5C954 8006C154 5400BFAF */  sw         $ra, 0x54($sp)
    /* 5C958 8006C158 5000BEAF */  sw         $fp, 0x50($sp)
    /* 5C95C 8006C15C 4C00B7AF */  sw         $s7, 0x4C($sp)
    /* 5C960 8006C160 4400B5AF */  sw         $s5, 0x44($sp)
    /* 5C964 8006C164 C3B0010C */  jal        func_8006C30C
    /* 5C968 8006C168 4000B4AF */   sw        $s4, 0x40($sp)
    /* 5C96C 8006C16C 1C00B727 */  addiu      $s7, $sp, 0x1C
    /* 5C970 8006C170 2120E002 */  addu       $a0, $s7, $zero
    /* 5C974 8006C174 C3B0010C */  jal        func_8006C30C
    /* 5C978 8006C178 21284002 */   addu      $a1, $s2, $zero
    /* 5C97C 8006C17C 2000BE27 */  addiu      $fp, $sp, 0x20
    /* 5C980 8006C180 2120C003 */  addu       $a0, $fp, $zero
    /* 5C984 8006C184 C3B0010C */  jal        func_8006C30C
    /* 5C988 8006C188 21282002 */   addu      $a1, $s1, $zero
    /* 5C98C 8006C18C 2400B527 */  addiu      $s5, $sp, 0x24
    /* 5C990 8006C190 2120A002 */  addu       $a0, $s5, $zero
    /* 5C994 8006C194 21284002 */  addu       $a1, $s2, $zero
    /* 5C998 8006C198 CCB0010C */  jal        func_8006C330
    /* 5C99C 8006C19C 21302002 */   addu      $a2, $s1, $zero
    /* 5C9A0 8006C1A0 2800B427 */  addiu      $s4, $sp, 0x28
    /* 5C9A4 8006C1A4 21208002 */  addu       $a0, $s4, $zero
    /* 5C9A8 8006C1A8 21282002 */  addu       $a1, $s1, $zero
    /* 5C9AC 8006C1AC CCB0010C */  jal        func_8006C330
    /* 5C9B0 8006C1B0 21300002 */   addu      $a2, $s0, $zero
    /* 5C9B4 8006C1B4 2C00B127 */  addiu      $s1, $sp, 0x2C
    /* 5C9B8 8006C1B8 21202002 */  addu       $a0, $s1, $zero
    /* 5C9BC 8006C1BC 21280002 */  addu       $a1, $s0, $zero
    /* 5C9C0 8006C1C0 CCB0010C */  jal        func_8006C330
    /* 5C9C4 8006C1C4 21304002 */   addu      $a2, $s2, $zero
    /* 5C9C8 8006C1C8 FFFF7326 */  addiu      $s3, $s3, -0x1
    /* 5C9CC 8006C1CC 1A006012 */  beqz       $s3, .L8006C238
    /* 5C9D0 8006C1D0 1800A427 */   addiu     $a0, $sp, 0x18
    /* 5C9D4 8006C1D4 21282002 */  addu       $a1, $s1, $zero
    /* 5C9D8 8006C1D8 21308002 */  addu       $a2, $s4, $zero
    /* 5C9DC 8006C1DC 2138C002 */  addu       $a3, $s6, $zero
    /* 5C9E0 8006C1E0 48B0010C */  jal        func_8006C120
    /* 5C9E4 8006C1E4 1000B3AF */   sw        $s3, 0x10($sp)
    /* 5C9E8 8006C1E8 2120E002 */  addu       $a0, $s7, $zero
    /* 5C9EC 8006C1EC 2128A002 */  addu       $a1, $s5, $zero
    /* 5C9F0 8006C1F0 21302002 */  addu       $a2, $s1, $zero
    /* 5C9F4 8006C1F4 21384000 */  addu       $a3, $v0, $zero
    /* 5C9F8 8006C1F8 48B0010C */  jal        func_8006C120
    /* 5C9FC 8006C1FC 1000B3AF */   sw        $s3, 0x10($sp)
    /* 5CA00 8006C200 2120C003 */  addu       $a0, $fp, $zero
    /* 5CA04 8006C204 21288002 */  addu       $a1, $s4, $zero
    /* 5CA08 8006C208 2130A002 */  addu       $a2, $s5, $zero
    /* 5CA0C 8006C20C 21384000 */  addu       $a3, $v0, $zero
    /* 5CA10 8006C210 48B0010C */  jal        func_8006C120
    /* 5CA14 8006C214 1000B3AF */   sw        $s3, 0x10($sp)
    /* 5CA18 8006C218 2120A002 */  addu       $a0, $s5, $zero
    /* 5CA1C 8006C21C 21288002 */  addu       $a1, $s4, $zero
    /* 5CA20 8006C220 21302002 */  addu       $a2, $s1, $zero
    /* 5CA24 8006C224 21384000 */  addu       $a3, $v0, $zero
    /* 5CA28 8006C228 48B0010C */  jal        func_8006C120
    /* 5CA2C 8006C22C 1000B3AF */   sw        $s3, 0x10($sp)
    /* 5CA30 8006C230 B3B00108 */  j          .L8006C2CC
    /* 5CA34 8006C234 00000000 */   nop
  .L8006C238:
    /* 5CA38 8006C238 2120C002 */  addu       $a0, $s6, $zero
    /* 5CA3C 8006C23C C3B0010C */  jal        func_8006C30C
    /* 5CA40 8006C240 1800A527 */   addiu     $a1, $sp, 0x18
    /* 5CA44 8006C244 0400C426 */  addiu      $a0, $s6, 0x4
    /* 5CA48 8006C248 C3B0010C */  jal        func_8006C30C
    /* 5CA4C 8006C24C 21282002 */   addu      $a1, $s1, $zero
    /* 5CA50 8006C250 0800C426 */  addiu      $a0, $s6, 0x8
    /* 5CA54 8006C254 C3B0010C */  jal        func_8006C30C
    /* 5CA58 8006C258 21288002 */   addu      $a1, $s4, $zero
    /* 5CA5C 8006C25C 0C00C426 */  addiu      $a0, $s6, 0xC
    /* 5CA60 8006C260 C3B0010C */  jal        func_8006C30C
    /* 5CA64 8006C264 2128E002 */   addu      $a1, $s7, $zero
    /* 5CA68 8006C268 1000C426 */  addiu      $a0, $s6, 0x10
    /* 5CA6C 8006C26C C3B0010C */  jal        func_8006C30C
    /* 5CA70 8006C270 2128A002 */   addu      $a1, $s5, $zero
    /* 5CA74 8006C274 1400C426 */  addiu      $a0, $s6, 0x14
    /* 5CA78 8006C278 C3B0010C */  jal        func_8006C30C
    /* 5CA7C 8006C27C 21282002 */   addu      $a1, $s1, $zero
    /* 5CA80 8006C280 1800C426 */  addiu      $a0, $s6, 0x18
    /* 5CA84 8006C284 C3B0010C */  jal        func_8006C30C
    /* 5CA88 8006C288 2128C003 */   addu      $a1, $fp, $zero
    /* 5CA8C 8006C28C 1C00C426 */  addiu      $a0, $s6, 0x1C
    /* 5CA90 8006C290 C3B0010C */  jal        func_8006C30C
    /* 5CA94 8006C294 21288002 */   addu      $a1, $s4, $zero
    /* 5CA98 8006C298 2000C426 */  addiu      $a0, $s6, 0x20
    /* 5CA9C 8006C29C C3B0010C */  jal        func_8006C30C
    /* 5CAA0 8006C2A0 2128A002 */   addu      $a1, $s5, $zero
    /* 5CAA4 8006C2A4 2400C426 */  addiu      $a0, $s6, 0x24
    /* 5CAA8 8006C2A8 C3B0010C */  jal        func_8006C30C
    /* 5CAAC 8006C2AC 2128A002 */   addu      $a1, $s5, $zero
    /* 5CAB0 8006C2B0 2800C426 */  addiu      $a0, $s6, 0x28
    /* 5CAB4 8006C2B4 C3B0010C */  jal        func_8006C30C
    /* 5CAB8 8006C2B8 21288002 */   addu      $a1, $s4, $zero
    /* 5CABC 8006C2BC 2C00C426 */  addiu      $a0, $s6, 0x2C
    /* 5CAC0 8006C2C0 C3B0010C */  jal        func_8006C30C
    /* 5CAC4 8006C2C4 21282002 */   addu      $a1, $s1, $zero
    /* 5CAC8 8006C2C8 3000C226 */  addiu      $v0, $s6, 0x30
  .L8006C2CC:
    /* 5CACC 8006C2CC 5400BF8F */  lw         $ra, 0x54($sp)
    /* 5CAD0 8006C2D0 5000BE8F */  lw         $fp, 0x50($sp)
    /* 5CAD4 8006C2D4 4C00B78F */  lw         $s7, 0x4C($sp)
    /* 5CAD8 8006C2D8 4800B68F */  lw         $s6, 0x48($sp)
    /* 5CADC 8006C2DC 4400B58F */  lw         $s5, 0x44($sp)
    /* 5CAE0 8006C2E0 4000B48F */  lw         $s4, 0x40($sp)
    /* 5CAE4 8006C2E4 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 5CAE8 8006C2E8 3800B28F */  lw         $s2, 0x38($sp)
    /* 5CAEC 8006C2EC 3400B18F */  lw         $s1, 0x34($sp)
    /* 5CAF0 8006C2F0 3000B08F */  lw         $s0, 0x30($sp)
    /* 5CAF4 8006C2F4 0800E003 */  jr         $ra
    /* 5CAF8 8006C2F8 5800BD27 */   addiu     $sp, $sp, 0x58
endlabel func_8006C120
