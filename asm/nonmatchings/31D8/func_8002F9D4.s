nonmatching func_8002F9D4, 0x54

glabel func_8002F9D4
    /* 201D4 8002F9D4 8803838F */  lw         $v1, %gp_rel(D_8009B290)($gp)
    /* 201D8 8002F9D8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 201DC 8002F9DC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 201E0 8002F9E0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 201E4 8002F9E4 02006224 */  addiu      $v0, $v1, 0x2
    /* 201E8 8002F9E8 880382AF */  sw         $v0, %gp_rel(D_8009B290)($gp)
    /* 201EC 8002F9EC 01006290 */  lbu        $v0, 0x1($v1)
    /* 201F0 8002F9F0 00006390 */  lbu        $v1, 0x0($v1)
    /* 201F4 8002F9F4 00120200 */  sll        $v0, $v0, 8
    /* 201F8 8002F9F8 97BB000C */  jal        func_8002EE5C
    /* 201FC 8002F9FC 25806200 */   or        $s0, $v1, $v0
    /* 20200 8002FA00 04004014 */  bnez       $v0, .L8002FA14
    /* 20204 8002FA04 1B80023C */   lui       $v0, %hi(D_801A8000)
    /* 20208 8002FA08 00804224 */  addiu      $v0, $v0, %lo(D_801A8000)
    /* 2020C 8002FA0C 21100202 */  addu       $v0, $s0, $v0
    /* 20210 8002FA10 880382AF */  sw         $v0, %gp_rel(D_8009B290)($gp)
  .L8002FA14:
    /* 20214 8002FA14 1400BF8F */  lw         $ra, 0x14($sp)
    /* 20218 8002FA18 1000B08F */  lw         $s0, 0x10($sp)
    /* 2021C 8002FA1C 740380A7 */  sh         $zero, %gp_rel(D_8009B27C)($gp)
    /* 20220 8002FA20 0800E003 */  jr         $ra
    /* 20224 8002FA24 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002F9D4
