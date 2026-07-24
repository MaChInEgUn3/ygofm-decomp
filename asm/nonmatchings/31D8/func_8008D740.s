nonmatching func_8008D740, 0xD8

glabel func_8008D740
    /* 7DF40 8008D740 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7DF44 8008D744 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7DF48 8008D748 1000B0AF */  sw         $s0, 0x10($sp)
  .L8008D74C:
    /* 7DF4C 8008D74C 1080023C */  lui        $v0, %hi(D_800FE42C)
    /* 7DF50 8008D750 2CE4428C */  lw         $v0, %lo(D_800FE42C)($v0)
    /* 7DF54 8008D754 1080043C */  lui        $a0, %hi(D_800FE428)
    /* 7DF58 8008D758 28E4848C */  lw         $a0, %lo(D_800FE428)($a0)
    /* 7DF5C 8008D75C 1080033C */  lui        $v1, %hi(D_800FE430)
    /* 7DF60 8008D760 30E4638C */  lw         $v1, %lo(D_800FE430)($v1)
    /* 7DF64 8008D764 40100200 */  sll        $v0, $v0, 1
    /* 7DF68 8008D768 21208200 */  addu       $a0, $a0, $v0
    /* 7DF6C 8008D76C 80180300 */  sll        $v1, $v1, 2
    /* 7DF70 8008D770 1080023C */  lui        $v0, %hi(D_800FE434)
    /* 7DF74 8008D774 34E4428C */  lw         $v0, %lo(D_800FE434)($v0)
    /* 7DF78 8008D778 21208300 */  addu       $a0, $a0, $v1
    /* 7DF7C 8008D77C C0100200 */  sll        $v0, $v0, 3
    /* 7DF80 8008D780 21808200 */  addu       $s0, $a0, $v0
    /* 7DF84 8008D784 F1FF0012 */  beqz       $s0, .L8008D74C
    /* 7DF88 8008D788 00000000 */   nop
    /* 7DF8C 8008D78C 1080043C */  lui        $a0, %hi(D_800FE3F8)
    /* 7DF90 8008D790 F8E3848C */  lw         $a0, %lo(D_800FE3F8)($a0)
    /* 7DF94 8008D794 20CE010C */  jal        func_80073880
    /* 7DF98 8008D798 00000000 */   nop
    /* 7DF9C 8008D79C 1080043C */  lui        $a0, %hi(D_800FE3FC)
    /* 7DFA0 8008D7A0 FCE3848C */  lw         $a0, %lo(D_800FE3FC)($a0)
    /* 7DFA4 8008D7A4 20CE010C */  jal        func_80073880
    /* 7DFA8 8008D7A8 00000000 */   nop
    /* 7DFAC 8008D7AC 1080043C */  lui        $a0, %hi(D_800FE400)
    /* 7DFB0 8008D7B0 00E4848C */  lw         $a0, %lo(D_800FE400)($a0)
    /* 7DFB4 8008D7B4 20CE010C */  jal        func_80073880
    /* 7DFB8 8008D7B8 00000000 */   nop
    /* 7DFBC 8008D7BC 1080043C */  lui        $a0, %hi(D_800FE404)
    /* 7DFC0 8008D7C0 04E4848C */  lw         $a0, %lo(D_800FE404)($a0)
    /* 7DFC4 8008D7C4 20CE010C */  jal        func_80073880
    /* 7DFC8 8008D7C8 00000000 */   nop
    /* 7DFCC 8008D7CC 1080013C */  lui        $at, %hi(D_800FE434)
    /* 7DFD0 8008D7D0 34E420AC */  sw         $zero, %lo(D_800FE434)($at)
    /* 7DFD4 8008D7D4 1080023C */  lui        $v0, %hi(D_800FE434)
    /* 7DFD8 8008D7D8 34E4428C */  lw         $v0, %lo(D_800FE434)($v0)
    /* 7DFDC 8008D7DC 1080013C */  lui        $at, %hi(D_800FE430)
    /* 7DFE0 8008D7E0 30E422AC */  sw         $v0, %lo(D_800FE430)($at)
    /* 7DFE4 8008D7E4 1080023C */  lui        $v0, %hi(D_800FE430)
    /* 7DFE8 8008D7E8 30E4428C */  lw         $v0, %lo(D_800FE430)($v0)
    /* 7DFEC 8008D7EC 1080013C */  lui        $at, %hi(D_800FE42C)
    /* 7DFF0 8008D7F0 2CE422AC */  sw         $v0, %lo(D_800FE42C)($at)
    /* 7DFF4 8008D7F4 1080033C */  lui        $v1, %hi(D_800FE42C)
    /* 7DFF8 8008D7F8 2CE4638C */  lw         $v1, %lo(D_800FE42C)($v1)
    /* 7DFFC 8008D7FC 43101000 */  sra        $v0, $s0, 1
    /* 7E000 8008D800 1080013C */  lui        $at, %hi(D_800FE428)
    /* 7E004 8008D804 28E423AC */  sw         $v1, %lo(D_800FE428)($at)
    /* 7E008 8008D808 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7E00C 8008D80C 1000B08F */  lw         $s0, 0x10($sp)
    /* 7E010 8008D810 0800E003 */  jr         $ra
    /* 7E014 8008D814 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008D740
