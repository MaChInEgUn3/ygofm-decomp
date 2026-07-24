nonmatching func_80035BE4, 0x54

glabel func_80035BE4
    /* 263E4 80035BE4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 263E8 80035BE8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 263EC 80035BEC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 263F0 80035BF0 2188A000 */  addu       $s1, $a1, $zero
    /* 263F4 80035BF4 2128C000 */  addu       $a1, $a2, $zero
    /* 263F8 80035BF8 3C00A28F */  lw         $v0, 0x3C($sp)
    /* 263FC 80035BFC 2130E000 */  addu       $a2, $a3, $zero
    /* 26400 80035C00 1000A2AF */  sw         $v0, 0x10($sp)
    /* 26404 80035C04 3800A78F */  lw         $a3, 0x38($sp)
    /* 26408 80035C08 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2640C 80035C0C AED6000C */  jal        func_80035AB8
    /* 26410 80035C10 21808000 */   addu      $s0, $a0, $zero
    /* 26414 80035C14 21200002 */  addu       $a0, $s0, $zero
    /* 26418 80035C18 21282002 */  addu       $a1, $s1, $zero
    /* 2641C 80035C1C BCD6000C */  jal        func_80035AF0
    /* 26420 80035C20 21300000 */   addu      $a2, $zero, $zero
    /* 26424 80035C24 2000BF8F */  lw         $ra, 0x20($sp)
    /* 26428 80035C28 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 2642C 80035C2C 1800B08F */  lw         $s0, 0x18($sp)
    /* 26430 80035C30 0800E003 */  jr         $ra
    /* 26434 80035C34 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80035BE4
