nonmatching func_8007BC80, 0xA0

glabel func_8007BC80
    /* 6C480 8007BC80 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C484 8007BC84 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6C488 8007BC88 B8E8010C */  jal        func_8007A2E0
    /* 6C48C 8007BC8C 00000000 */   nop
    /* 6C490 8007BC90 69E8010C */  jal        func_8007A1A4
    /* 6C494 8007BC94 00000000 */   nop
    /* 6C498 8007BC98 0F80013C */  lui        $at, %hi(D_800F5F88)
    /* 6C49C 8007BC9C 885F20AC */  sw         $zero, %lo(D_800F5F88)($at)
    /* 6C4A0 8007BCA0 0F80023C */  lui        $v0, %hi(D_800F5F88)
    /* 6C4A4 8007BCA4 885F428C */  lw         $v0, %lo(D_800F5F88)($v0)
    /* 6C4A8 8007BCA8 0F80013C */  lui        $at, %hi(D_800F5F84)
    /* 6C4AC 8007BCAC 845F22AC */  sw         $v0, %lo(D_800F5F84)($at)
    /* 6C4B0 8007BCB0 0F80013C */  lui        $at, %hi(D_800F5F80)
    /* 6C4B4 8007BCB4 48EF010C */  jal        func_8007BD20
    /* 6C4B8 8007BCB8 805F20AC */   sw        $zero, %lo(D_800F5F80)($at)
    /* 6C4BC 8007BCBC 0980013C */  lui        $at, %hi(D_80093A0C)
    /* 6C4C0 8007BCC0 0C3A20AC */  sw         $zero, %lo(D_80093A0C)($at)
    /* 6C4C4 8007BCC4 B4F4010C */  jal        func_8007D2D0
    /* 6C4C8 8007BCC8 21200000 */   addu      $a0, $zero, $zero
    /* 6C4CC 8007BCCC 0880023C */  lui        $v0, %hi(func_8007C4E0)
    /* 6C4D0 8007BCD0 E0C44224 */  addiu      $v0, $v0, %lo(func_8007C4E0)
    /* 6C4D4 8007BCD4 0980013C */  lui        $at, %hi(D_800934E0)
    /* 6C4D8 8007BCD8 E03422AC */  sw         $v0, %lo(D_800934E0)($at)
    /* 6C4DC 8007BCDC 0880023C */  lui        $v0, %hi(func_8007CB48)
    /* 6C4E0 8007BCE0 48CB4224 */  addiu      $v0, $v0, %lo(func_8007CB48)
    /* 6C4E4 8007BCE4 0880053C */  lui        $a1, %hi(func_8007C188)
    /* 6C4E8 8007BCE8 88C1A524 */  addiu      $a1, $a1, %lo(func_8007C188)
    /* 6C4EC 8007BCEC 0980013C */  lui        $at, %hi(D_800934E4)
    /* 6C4F0 8007BCF0 E43422AC */  sw         $v0, %lo(D_800934E4)($at)
    /* 6C4F4 8007BCF4 15D1010C */  jal        func_80074454
    /* 6C4F8 8007BCF8 21200000 */   addu      $a0, $zero, $zero
    /* 6C4FC 8007BCFC 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C500 8007BD00 0980013C */  lui        $at, %hi(D_80093500)
    /* 6C504 8007BD04 003522AC */  sw         $v0, %lo(D_80093500)($at)
    /* 6C508 8007BD08 0980013C */  lui        $at, %hi(D_80093880)
    /* 6C50C 8007BD0C 803822AC */  sw         $v0, %lo(D_80093880)($at)
    /* 6C510 8007BD10 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C514 8007BD14 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6C518 8007BD18 0800E003 */  jr         $ra
    /* 6C51C 8007BD1C 00000000 */   nop
endlabel func_8007BC80
