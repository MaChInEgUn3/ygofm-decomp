nonmatching func_8004B9E0, 0xC0

glabel func_8004B9E0
    /* 3C1E0 8004B9E0 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3C1E4 8004B9E4 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3C1E8 8004B9E8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3C1EC 8004B9EC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3C1F0 8004B9F0 01056290 */  lbu        $v0, 0x501($v1)
    /* 3C1F4 8004B9F4 00000000 */  nop
    /* 3C1F8 8004B9F8 25004014 */  bnez       $v0, .L8004BA90
    /* 3C1FC 8004B9FC 01000224 */   addiu     $v0, $zero, 0x1
    /* 3C200 8004BA00 010562A0 */  sb         $v0, 0x501($v1)
    /* 3C204 8004BA04 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3C208 8004BA08 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3C20C 8004BA0C 00000000 */  nop
    /* 3C210 8004BA10 02054290 */  lbu        $v0, 0x502($v0)
    /* 3C214 8004BA14 00000000 */  nop
    /* 3C218 8004BA18 15004010 */  beqz       $v0, .L8004BA70
    /* 3C21C 8004BA1C 00000000 */   nop
    /* 3C220 8004BA20 3232010C */  jal        func_8004C8C8
    /* 3C224 8004BA24 00000000 */   nop
    /* 3C228 8004BA28 3232010C */  jal        func_8004C8C8
    /* 3C22C 8004BA2C 00000000 */   nop
    /* 3C230 8004BA30 3232010C */  jal        func_8004C8C8
    /* 3C234 8004BA34 00000000 */   nop
    /* 3C238 8004BA38 3232010C */  jal        func_8004C8C8
    /* 3C23C 8004BA3C 00000000 */   nop
    /* 3C240 8004BA40 3232010C */  jal        func_8004C8C8
    /* 3C244 8004BA44 00000000 */   nop
    /* 3C248 8004BA48 3232010C */  jal        func_8004C8C8
    /* 3C24C 8004BA4C 00000000 */   nop
    /* 3C250 8004BA50 3232010C */  jal        func_8004C8C8
    /* 3C254 8004BA54 00000000 */   nop
    /* 3C258 8004BA58 3232010C */  jal        func_8004C8C8
    /* 3C25C 8004BA5C 00000000 */   nop
    /* 3C260 8004BA60 3232010C */  jal        func_8004C8C8
    /* 3C264 8004BA64 00000000 */   nop
    /* 3C268 8004BA68 3232010C */  jal        func_8004C8C8
    /* 3C26C 8004BA6C 00000000 */   nop
  .L8004BA70:
    /* 3C270 8004BA70 1332010C */  jal        func_8004C84C
    /* 3C274 8004BA74 00000000 */   nop
    /* 3C278 8004BA78 BF2A010C */  jal        func_8004AAFC
    /* 3C27C 8004BA7C 00000000 */   nop
    /* 3C280 8004BA80 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3C284 8004BA84 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3C288 8004BA88 00000000 */  nop
    /* 3C28C 8004BA8C 010540A0 */  sb         $zero, 0x501($v0)
  .L8004BA90:
    /* 3C290 8004BA90 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3C294 8004BA94 00000000 */  nop
    /* 3C298 8004BA98 0800E003 */  jr         $ra
    /* 3C29C 8004BA9C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004B9E0
