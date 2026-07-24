nonmatching func_80040CAC, 0x68

glabel func_80040CAC
    /* 314AC 80040CAC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 314B0 80040CB0 0F80023C */  lui        $v0, %hi(D_800EFE38)
    /* 314B4 80040CB4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 314B8 80040CB8 38FE5084 */  lh         $s0, %lo(D_800EFE38)($v0)
    /* 314BC 80040CBC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 314C0 80040CC0 0F000006 */  bltz       $s0, .L80040D00
    /* 314C4 80040CC4 1400B1AF */   sw        $s1, 0x14($sp)
    /* 314C8 80040CC8 0F80023C */  lui        $v0, %hi(D_800EFE48)
    /* 314CC 80040CCC 48FE5124 */  addiu      $s1, $v0, %lo(D_800EFE48)
    /* 314D0 80040CD0 C0101000 */  sll        $v0, $s0, 3
  .L80040CD4:
    /* 314D4 80040CD4 23105000 */  subu       $v0, $v0, $s0
    /* 314D8 80040CD8 00110200 */  sll        $v0, $v0, 4
    /* 314DC 80040CDC 21205100 */  addu       $a0, $v0, $s1
    /* 314E0 80040CE0 2400828C */  lw         $v0, 0x24($a0)
    /* 314E4 80040CE4 02009084 */  lh         $s0, 0x2($a0)
    /* 314E8 80040CE8 03004010 */  beqz       $v0, .L80040CF8
    /* 314EC 80040CEC 00000000 */   nop
    /* 314F0 80040CF0 09F84000 */  jalr       $v0
    /* 314F4 80040CF4 00000000 */   nop
  .L80040CF8:
    /* 314F8 80040CF8 F6FF0106 */  bgez       $s0, .L80040CD4
    /* 314FC 80040CFC C0101000 */   sll       $v0, $s0, 3
  .L80040D00:
    /* 31500 80040D00 1800BF8F */  lw         $ra, 0x18($sp)
    /* 31504 80040D04 1400B18F */  lw         $s1, 0x14($sp)
    /* 31508 80040D08 1000B08F */  lw         $s0, 0x10($sp)
    /* 3150C 80040D0C 0800E003 */  jr         $ra
    /* 31510 80040D10 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80040CAC
