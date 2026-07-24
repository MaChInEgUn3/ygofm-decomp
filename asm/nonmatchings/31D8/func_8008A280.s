nonmatching func_8008A280, 0x194

glabel func_8008A280
    /* 7AA80 8008A280 21408000 */  addu       $t0, $a0, $zero
    /* 7AA84 8008A284 04008424 */  addiu      $a0, $a0, 0x4
    /* 7AA88 8008A288 0000838C */  lw         $v1, 0x0($a0)
    /* 7AA8C 8008A28C 00000000 */  nop
    /* 7AA90 8008A290 01006230 */  andi       $v0, $v1, 0x1
    /* 7AA94 8008A294 5D004014 */  bnez       $v0, .L8008A40C
    /* 7AA98 8008A298 01006234 */   ori       $v0, $v1, 0x1
    /* 7AA9C 8008A29C 000082AC */  sw         $v0, 0x0($a0)
    /* 7AAA0 8008A2A0 04008424 */  addiu      $a0, $a0, 0x4
    /* 7AAA4 8008A2A4 0000828C */  lw         $v0, 0x0($a0)
    /* 7AAA8 8008A2A8 21380000 */  addu       $a3, $zero, $zero
    /* 7AAAC 8008A2AC 80100200 */  sll        $v0, $v0, 2
    /* 7AAB0 8008A2B0 21100201 */  addu       $v0, $t0, $v0
    /* 7AAB4 8008A2B4 21284000 */  addu       $a1, $v0, $zero
    /* 7AAB8 8008A2B8 000085AC */  sw         $a1, 0x0($a0)
    /* 7AABC 8008A2BC 0000AA8C */  lw         $t2, 0x0($a1)
    /* 7AAC0 8008A2C0 00000000 */  nop
    /* 7AAC4 8008A2C4 16004019 */  blez       $t2, .L8008A320
    /* 7AAC8 8008A2C8 0400A524 */   addiu     $a1, $a1, 0x4
    /* 7AACC 8008A2CC FF7F093C */  lui        $t1, (0x7FFFFFFF >> 16)
    /* 7AAD0 8008A2D0 FFFF2935 */  ori        $t1, $t1, (0x7FFFFFFF & 0xFFFF)
  .L8008A2D4:
    /* 7AAD4 8008A2D4 0000A68C */  lw         $a2, 0x0($a1)
    /* 7AAD8 8008A2D8 0400A524 */  addiu      $a1, $a1, 0x4
    /* 7AADC 8008A2DC 0C00C018 */  blez       $a2, .L8008A310
    /* 7AAE0 8008A2E0 21180000 */   addu      $v1, $zero, $zero
  .L8008A2E4:
    /* 7AAE4 8008A2E4 0000A28C */  lw         $v0, 0x0($a1)
    /* 7AAE8 8008A2E8 00000000 */  nop
    /* 7AAEC 8008A2EC 04004104 */  bgez       $v0, .L8008A300
    /* 7AAF0 8008A2F0 24104900 */   and       $v0, $v0, $t1
    /* 7AAF4 8008A2F4 80100200 */  sll        $v0, $v0, 2
    /* 7AAF8 8008A2F8 21100201 */  addu       $v0, $t0, $v0
    /* 7AAFC 8008A2FC 0000A2AC */  sw         $v0, 0x0($a1)
  .L8008A300:
    /* 7AB00 8008A300 01006324 */  addiu      $v1, $v1, 0x1
    /* 7AB04 8008A304 2A106600 */  slt        $v0, $v1, $a2
    /* 7AB08 8008A308 F6FF4014 */  bnez       $v0, .L8008A2E4
    /* 7AB0C 8008A30C 0400A524 */   addiu     $a1, $a1, 0x4
  .L8008A310:
    /* 7AB10 8008A310 0100E724 */  addiu      $a3, $a3, 0x1
    /* 7AB14 8008A314 2A10EA00 */  slt        $v0, $a3, $t2
    /* 7AB18 8008A318 EEFF4014 */  bnez       $v0, .L8008A2D4
    /* 7AB1C 8008A31C 00000000 */   nop
  .L8008A320:
    /* 7AB20 8008A320 04008424 */  addiu      $a0, $a0, 0x4
    /* 7AB24 8008A324 00008A8C */  lw         $t2, 0x0($a0)
    /* 7AB28 8008A328 04008424 */  addiu      $a0, $a0, 0x4
    /* 7AB2C 8008A32C 37004019 */  blez       $t2, .L8008A40C
    /* 7AB30 8008A330 21380000 */   addu      $a3, $zero, $zero
    /* 7AB34 8008A334 FFFF0C24 */  addiu      $t4, $zero, -0x1
    /* 7AB38 8008A338 00800B3C */  lui        $t3, (0x80000000 >> 16)
    /* 7AB3C 8008A33C FF7F063C */  lui        $a2, (0x7FFFFFFF >> 16)
    /* 7AB40 8008A340 FFFFC634 */  ori        $a2, $a2, (0x7FFFFFFF & 0xFFFF)
  .L8008A344:
    /* 7AB44 8008A344 0000828C */  lw         $v0, 0x0($a0)
    /* 7AB48 8008A348 00000000 */  nop
    /* 7AB4C 8008A34C 2B004010 */  beqz       $v0, .L8008A3FC
    /* 7AB50 8008A350 80100200 */   sll       $v0, $v0, 2
    /* 7AB54 8008A354 21100201 */  addu       $v0, $t0, $v0
    /* 7AB58 8008A358 21284000 */  addu       $a1, $v0, $zero
    /* 7AB5C 8008A35C 000085AC */  sw         $a1, 0x0($a0)
    /* 7AB60 8008A360 0000A28C */  lw         $v0, 0x0($a1)
    /* 7AB64 8008A364 00000000 */  nop
    /* 7AB68 8008A368 18004C10 */  beq        $v0, $t4, .L8008A3CC
    /* 7AB6C 8008A36C 00000000 */   nop
    /* 7AB70 8008A370 FFFF0924 */  addiu      $t1, $zero, -0x1
  .L8008A374:
    /* 7AB74 8008A374 0800A28C */  lw         $v0, 0x8($a1)
    /* 7AB78 8008A378 00000000 */  nop
    /* 7AB7C 8008A37C 24104B00 */  and        $v0, $v0, $t3
    /* 7AB80 8008A380 1E004010 */  beqz       $v0, .L8008A3FC
    /* 7AB84 8008A384 00000000 */   nop
    /* 7AB88 8008A388 0000A28C */  lw         $v0, 0x0($a1)
    /* 7AB8C 8008A38C 0400A38C */  lw         $v1, 0x4($a1)
    /* 7AB90 8008A390 80100200 */  sll        $v0, $v0, 2
    /* 7AB94 8008A394 21100201 */  addu       $v0, $t0, $v0
    /* 7AB98 8008A398 80180300 */  sll        $v1, $v1, 2
    /* 7AB9C 8008A39C 0000A2AC */  sw         $v0, 0x0($a1)
    /* 7ABA0 8008A3A0 0800A28C */  lw         $v0, 0x8($a1)
    /* 7ABA4 8008A3A4 21180301 */  addu       $v1, $t0, $v1
    /* 7ABA8 8008A3A8 0400A3AC */  sw         $v1, 0x4($a1)
    /* 7ABAC 8008A3AC 24104600 */  and        $v0, $v0, $a2
    /* 7ABB0 8008A3B0 0800A2AC */  sw         $v0, 0x8($a1)
    /* 7ABB4 8008A3B4 0000A58C */  lw         $a1, 0x0($a1)
    /* 7ABB8 8008A3B8 00000000 */  nop
    /* 7ABBC 8008A3BC 0000A28C */  lw         $v0, 0x0($a1)
    /* 7ABC0 8008A3C0 00000000 */  nop
    /* 7ABC4 8008A3C4 EBFF4914 */  bne        $v0, $t1, .L8008A374
    /* 7ABC8 8008A3C8 00000000 */   nop
  .L8008A3CC:
    /* 7ABCC 8008A3CC 0800A28C */  lw         $v0, 0x8($a1)
    /* 7ABD0 8008A3D0 00000000 */  nop
    /* 7ABD4 8008A3D4 24104B00 */  and        $v0, $v0, $t3
    /* 7ABD8 8008A3D8 08004010 */  beqz       $v0, .L8008A3FC
    /* 7ABDC 8008A3DC 00000000 */   nop
    /* 7ABE0 8008A3E0 0400A28C */  lw         $v0, 0x4($a1)
    /* 7ABE4 8008A3E4 0800A38C */  lw         $v1, 0x8($a1)
    /* 7ABE8 8008A3E8 80100200 */  sll        $v0, $v0, 2
    /* 7ABEC 8008A3EC 21100201 */  addu       $v0, $t0, $v0
    /* 7ABF0 8008A3F0 24186600 */  and        $v1, $v1, $a2
    /* 7ABF4 8008A3F4 0400A2AC */  sw         $v0, 0x4($a1)
    /* 7ABF8 8008A3F8 0800A3AC */  sw         $v1, 0x8($a1)
  .L8008A3FC:
    /* 7ABFC 8008A3FC 0100E724 */  addiu      $a3, $a3, 0x1
    /* 7AC00 8008A400 2A10EA00 */  slt        $v0, $a3, $t2
    /* 7AC04 8008A404 CFFF4014 */  bnez       $v0, .L8008A344
    /* 7AC08 8008A408 04008424 */   addiu     $a0, $a0, 0x4
  .L8008A40C:
    /* 7AC0C 8008A40C 0800E003 */  jr         $ra
    /* 7AC10 8008A410 00000000 */   nop
endlabel func_8008A280
    /* 7AC14 8008A414 00000000 */  nop
    /* 7AC18 8008A418 00000000 */  nop
    /* 7AC1C 8008A41C 00000000 */  nop
