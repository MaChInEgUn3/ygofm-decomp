nonmatching func_8005C568, 0x5C

glabel func_8005C568
    /* 4CD68 8005C568 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 4CD6C 8005C56C 2800B0AF */  sw         $s0, 0x28($sp)
    /* 4CD70 8005C570 21808000 */  addu       $s0, $a0, $zero
    /* 4CD74 8005C574 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 4CD78 8005C578 2188A000 */  addu       $s1, $a1, $zero
    /* 4CD7C 8005C57C 3000BFAF */  sw         $ra, 0x30($sp)
    /* 4CD80 8005C580 FD00020C */  jal        func_800803F4
    /* 4CD84 8005C584 1000A427 */   addiu     $a0, $sp, 0x10
  .L8005C588:
    /* 4CD88 8005C588 C908020C */  jal        func_80082324
    /* 4CD8C 8005C58C 03000424 */   addiu     $a0, $zero, 0x3
    /* 4CD90 8005C590 FDFF4014 */  bnez       $v0, .L8005C588
    /* 4CD94 8005C594 1000A427 */   addiu     $a0, $sp, 0x10
  .L8005C598:
    /* 4CD98 8005C598 21280002 */  addu       $a1, $s0, $zero
    /* 4CD9C 8005C59C F007020C */  jal        func_80081FC0
    /* 4CDA0 8005C5A0 21302002 */   addu      $a2, $s1, $zero
    /* 4CDA4 8005C5A4 FCFF4014 */  bnez       $v0, .L8005C598
    /* 4CDA8 8005C5A8 1000A427 */   addiu     $a0, $sp, 0x10
    /* 4CDAC 8005C5AC 3000BF8F */  lw         $ra, 0x30($sp)
    /* 4CDB0 8005C5B0 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 4CDB4 8005C5B4 2800B08F */  lw         $s0, 0x28($sp)
    /* 4CDB8 8005C5B8 21100000 */  addu       $v0, $zero, $zero
    /* 4CDBC 8005C5BC 0800E003 */  jr         $ra
    /* 4CDC0 8005C5C0 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8005C568
