nonmatching func_8007149C, 0x74

glabel func_8007149C
    /* 61C9C 8007149C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 61CA0 800714A0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 61CA4 800714A4 63C1010C */  jal        func_8007058C
    /* 61CA8 800714A8 00000000 */   nop
    /* 61CAC 800714AC 21184000 */  addu       $v1, $v0, $zero
    /* 61CB0 800714B0 21300000 */  addu       $a2, $zero, $zero
    /* 61CB4 800714B4 0B000524 */  addiu      $a1, $zero, 0xB
    /* 61CB8 800714B8 1B80023C */  lui        $v0, %hi(D_801AB000)
    /* 61CBC 800714BC 00B04224 */  addiu      $v0, $v0, %lo(D_801AB000)
    /* 61CC0 800714C0 84004424 */  addiu      $a0, $v0, 0x84
  .L800714C4:
    /* 61CC4 800714C4 00008284 */  lh         $v0, 0x0($a0)
    /* 61CC8 800714C8 00000000 */  nop
    /* 61CCC 800714CC 02004010 */  beqz       $v0, .L800714D8
    /* 61CD0 800714D0 00000000 */   nop
    /* 61CD4 800714D4 0100C624 */  addiu      $a2, $a2, 0x1
  .L800714D8:
    /* 61CD8 800714D8 0100A524 */  addiu      $a1, $a1, 0x1
    /* 61CDC 800714DC 3800A228 */  slti       $v0, $a1, 0x38
    /* 61CE0 800714E0 F8FF4014 */  bnez       $v0, .L800714C4
    /* 61CE4 800714E4 0C008424 */   addiu     $a0, $a0, 0xC
    /* 61CE8 800714E8 0F80023C */  lui        $v0, %hi(D_800F5B98)
    /* 61CEC 800714EC 985B4224 */  addiu      $v0, $v0, %lo(D_800F5B98)
    /* 61CF0 800714F0 80180300 */  sll        $v1, $v1, 2
    /* 61CF4 800714F4 21186200 */  addu       $v1, $v1, $v0
    /* 61CF8 800714F8 FBFFC224 */  addiu      $v0, $a2, -0x5
    /* 61CFC 800714FC 000062AC */  sw         $v0, 0x0($v1)
    /* 61D00 80071500 1000BF8F */  lw         $ra, 0x10($sp)
    /* 61D04 80071504 00000000 */  nop
    /* 61D08 80071508 0800E003 */  jr         $ra
    /* 61D0C 8007150C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007149C
