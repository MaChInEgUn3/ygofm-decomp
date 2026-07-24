nonmatching func_8007E1E0, 0x78

glabel func_8007E1E0
    /* 6E9E0 8007E1E0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6E9E4 8007E1E4 21200000 */  addu       $a0, $zero, $zero
    /* 6E9E8 8007E1E8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 6E9EC 8007E1EC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6E9F0 8007E1F0 18FA010C */  jal        func_8007E860
    /* 6E9F4 8007E1F4 1800B0AF */   sw        $s0, 0x18($sp)
    /* 6E9F8 8007E1F8 C9EF010C */  jal        func_8007BF24
    /* 6E9FC 8007E1FC 00000000 */   nop
    /* 6EA00 8007E200 C4F9010C */  jal        func_8007E710
    /* 6EA04 8007E204 21204000 */   addu      $a0, $v0, $zero
    /* 6EA08 8007E208 0980013C */  lui        $at, %hi(D_80093A18)
    /* 6EA0C 8007E20C C5EF010C */  jal        func_8007BF14
    /* 6EA10 8007E210 183A22AC */   sw        $v0, %lo(D_80093A18)($at)
    /* 6EA14 8007E214 C9EF010C */  jal        func_8007BF24
    /* 6EA18 8007E218 FF005030 */   andi      $s0, $v0, 0xFF
    /* 6EA1C 8007E21C D0EF010C */  jal        func_8007BF40
    /* 6EA20 8007E220 21884000 */   addu      $s1, $v0, $zero
    /* 6EA24 8007E224 21200002 */  addu       $a0, $s0, $zero
    /* 6EA28 8007E228 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 6EA2C 8007E22C 21282002 */  addu       $a1, $s1, $zero
    /* 6EA30 8007E230 FF004630 */  andi       $a2, $v0, 0xFF
    /* 6EA34 8007E234 0880073C */  lui        $a3, %hi(func_8007E258)
    /* 6EA38 8007E238 58E2E724 */  addiu      $a3, $a3, %lo(func_8007E258)
    /* 6EA3C 8007E23C 1AED010C */  jal        func_8007B468
    /* 6EA40 8007E240 1000A3AF */   sw        $v1, 0x10($sp)
    /* 6EA44 8007E244 2000BF8F */  lw         $ra, 0x20($sp)
    /* 6EA48 8007E248 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6EA4C 8007E24C 1800B08F */  lw         $s0, 0x18($sp)
    /* 6EA50 8007E250 0800E003 */  jr         $ra
    /* 6EA54 8007E254 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007E1E0
