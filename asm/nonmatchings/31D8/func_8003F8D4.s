nonmatching func_8003F8D4, 0x404

glabel func_8003F8D4
    /* 300D4 8003F8D4 E2048293 */  lbu        $v0, %gp_rel(D_8009B3EA)($gp)
    /* 300D8 8003F8D8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 300DC 8003F8DC 2400BFAF */  sw         $ra, 0x24($sp)
    /* 300E0 8003F8E0 0F004330 */  andi       $v1, $v0, 0xF
    /* 300E4 8003F8E4 0C00622C */  sltiu      $v0, $v1, 0xC
    /* 300E8 8003F8E8 F6004010 */  beqz       $v0, .L8003FCC4
    /* 300EC 8003F8EC 2000B0AF */   sw        $s0, 0x20($sp)
    /* 300F0 8003F8F0 0180023C */  lui        $v0, %hi(jtbl_800104F0)
    /* 300F4 8003F8F4 F0044224 */  addiu      $v0, $v0, %lo(jtbl_800104F0)
    /* 300F8 8003F8F8 80180300 */  sll        $v1, $v1, 2
    /* 300FC 8003F8FC 21186200 */  addu       $v1, $v1, $v0
    /* 30100 8003F900 0000628C */  lw         $v0, 0x0($v1)
    /* 30104 8003F904 00000000 */  nop
    /* 30108 8003F908 08004000 */  jr         $v0
    /* 3010C 8003F90C 00000000 */   nop
  jlabel .L8003F910
    /* 30110 8003F910 E2048393 */  lbu        $v1, %gp_rel(D_8009B3EA)($gp)
    /* 30114 8003F914 00000000 */  nop
    /* 30118 8003F918 80006230 */  andi       $v0, $v1, 0x80
    /* 3011C 8003F91C 17004014 */  bnez       $v0, .L8003F97C
    /* 30120 8003F920 20000524 */   addiu     $a1, $zero, 0x20
    /* 30124 8003F924 80006234 */  ori        $v0, $v1, 0x80
    /* 30128 8003F928 E20482A3 */  sb         $v0, %gp_rel(D_8009B3EA)($gp)
    /* 3012C 8003F92C E2FC000C */  jal        func_8003F388
    /* 30130 8003F930 00000000 */   nop
    /* 30134 8003F934 C2000524 */  addiu      $a1, $zero, 0xC2
    /* 30138 8003F938 20000624 */  addiu      $a2, $zero, 0x20
    /* 3013C 8003F93C 50000724 */  addiu      $a3, $zero, 0x50
    /* 30140 8003F940 E6048493 */  lbu        $a0, %gp_rel(D_8009B3EE)($gp)
    /* 30144 8003F944 D004838F */  lw         $v1, %gp_rel(D_8009B3D8)($gp)
    /* 30148 8003F948 00FC0224 */  addiu      $v0, $zero, -0x400
    /* 3014C 8003F94C 600062A4 */  sh         $v0, 0x60($v1)
    /* 30150 8003F950 00010224 */  addiu      $v0, $zero, 0x100
    /* 30154 8003F954 1000A2AF */  sw         $v0, 0x10($sp)
    /* 30158 8003F958 30000224 */  addiu      $v0, $zero, 0x30
    /* 3015C 8003F95C F9D6000C */  jal        func_80035BE4
    /* 30160 8003F960 1400A2AF */   sw        $v0, 0x14($sp)
    /* 30164 8003F964 21804000 */  addu       $s0, $v0, $zero
    /* 30168 8003F968 21200002 */  addu       $a0, $s0, $zero
    /* 3016C 8003F96C 10000224 */  addiu      $v0, $zero, 0x10
    /* 30170 8003F970 85E6000C */  jal        func_80039A14
    /* 30174 8003F974 590082A0 */   sb        $v0, 0x59($a0)
    /* 30178 8003F978 20000524 */  addiu      $a1, $zero, 0x20
  .L8003F97C:
    /* 3017C 8003F97C D004848F */  lw         $a0, %gp_rel(D_8009B3D8)($gp)
    /* 30180 8003F980 E6048793 */  lbu        $a3, %gp_rel(D_8009B3EE)($gp)
    /* 30184 8003F984 ACFC000C */  jal        func_8003F2B0
    /* 30188 8003F988 50000624 */   addiu     $a2, $zero, 0x50
    /* 3018C 8003F98C CE004014 */  bnez       $v0, .L8003FCC8
    /* 30190 8003F990 21100000 */   addu      $v0, $zero, $zero
    /* 30194 8003F994 01000224 */  addiu      $v0, $zero, 0x1
    /* 30198 8003F998 E20482A3 */  sb         $v0, %gp_rel(D_8009B3EA)($gp)
    /* 3019C 8003F99C 32FF0008 */  j          .L8003FCC8
    /* 301A0 8003F9A0 21100000 */   addu      $v0, $zero, $zero
  jlabel .L8003F9A4
    /* 301A4 8003F9A4 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* 301A8 8003F9A8 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* 301AC 8003F9AC 00000000 */  nop
    /* 301B0 8003F9B0 20004230 */  andi       $v0, $v0, 0x20
    /* 301B4 8003F9B4 06004010 */  beqz       $v0, .L8003F9D0
    /* 301B8 8003F9B8 00000000 */   nop
    /* 301BC 8003F9BC B8FF000C */  jal        func_8003FEE0
    /* 301C0 8003F9C0 08000424 */   addiu     $a0, $zero, 0x8
    /* 301C4 8003F9C4 D004838F */  lw         $v1, %gp_rel(D_8009B3D8)($gp)
    /* 301C8 8003F9C8 7EFE0008 */  j          .L8003F9F8
    /* 301CC 8003F9CC 82000224 */   addiu     $v0, $zero, 0x82
  .L8003F9D0:
    /* 301D0 8003F9D0 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* 301D4 8003F9D4 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* 301D8 8003F9D8 00000000 */  nop
    /* 301DC 8003F9DC 40004230 */  andi       $v0, $v0, 0x40
    /* 301E0 8003F9E0 B9004010 */  beqz       $v0, .L8003FCC8
    /* 301E4 8003F9E4 21100000 */   addu      $v0, $zero, $zero
    /* 301E8 8003F9E8 B8FF000C */  jal        func_8003FEE0
    /* 301EC 8003F9EC 07000424 */   addiu     $a0, $zero, 0x7
    /* 301F0 8003F9F0 D004838F */  lw         $v1, %gp_rel(D_8009B3D8)($gp)
    /* 301F4 8003F9F4 02000224 */  addiu      $v0, $zero, 0x2
  .L8003F9F8:
    /* 301F8 8003F9F8 E20482A3 */  sb         $v0, %gp_rel(D_8009B3EA)($gp)
    /* 301FC 8003F9FC 00040224 */  addiu      $v0, $zero, 0x400
    /* 30200 8003FA00 31FF0008 */  j          .L8003FCC4
    /* 30204 8003FA04 600062A4 */   sh        $v0, 0x60($v1)
  jlabel .L8003FA08
    /* 30208 8003FA08 20000524 */  addiu      $a1, $zero, 0x20
    /* 3020C 8003FA0C D004848F */  lw         $a0, %gp_rel(D_8009B3D8)($gp)
    /* 30210 8003FA10 E6048793 */  lbu        $a3, %gp_rel(D_8009B3EE)($gp)
    /* 30214 8003FA14 ACFC000C */  jal        func_8003F2B0
    /* 30218 8003FA18 00010624 */   addiu     $a2, $zero, 0x100
    /* 3021C 8003FA1C AA004014 */  bnez       $v0, .L8003FCC8
    /* 30220 8003FA20 21100000 */   addu      $v0, $zero, $zero
    /* 30224 8003FA24 E6048293 */  lbu        $v0, %gp_rel(D_8009B3EE)($gp)
    /* 30228 8003FA28 00000000 */  nop
    /* 3022C 8003FA2C 40200200 */  sll        $a0, $v0, 1
    /* 30230 8003FA30 21208200 */  addu       $a0, $a0, $v0
    /* 30234 8003FA34 C0200400 */  sll        $a0, $a0, 3
    /* 30238 8003FA38 21208200 */  addu       $a0, $a0, $v0
    /* 3023C 8003FA3C 80200400 */  sll        $a0, $a0, 2
    /* 30240 8003FA40 0F80023C */  lui        $v0, %hi(D_800EB0F8)
    /* 30244 8003FA44 F8B04224 */  addiu      $v0, $v0, %lo(D_800EB0F8)
    /* 30248 8003FA48 DFD6000C */  jal        func_80035B7C
    /* 3024C 8003FA4C 21208200 */   addu      $a0, $a0, $v0
    /* 30250 8003FA50 D004848F */  lw         $a0, %gp_rel(D_8009B3D8)($gp)
    /* 30254 8003FA54 DB00010C */  jal        func_8004036C
    /* 30258 8003FA58 00000000 */   nop
    /* 3025C 8003FA5C E2048293 */  lbu        $v0, %gp_rel(D_8009B3EA)($gp)
    /* 30260 8003FA60 D00480AF */  sw         $zero, %gp_rel(D_8009B3D8)($gp)
    /* 30264 8003FA64 80004230 */  andi       $v0, $v0, 0x80
    /* 30268 8003FA68 97004014 */  bnez       $v0, .L8003FCC8
    /* 3026C 8003FA6C 02000224 */   addiu     $v0, $zero, 0x2
    /* 30270 8003FA70 03000224 */  addiu      $v0, $zero, 0x3
    /* 30274 8003FA74 E20482A3 */  sb         $v0, %gp_rel(D_8009B3EA)($gp)
    /* 30278 8003FA78 1D80043C */  lui        $a0, %hi(D_801D1200)
    /* 3027C 8003FA7C 00128424 */  addiu      $a0, $a0, %lo(D_801D1200)
    /* 30280 8003FA80 80060524 */  addiu      $a1, $zero, 0x680
    /* 30284 8003FA84 0180063C */  lui        $a2, %hi(D_80010384)
    /* 30288 8003FA88 8403C624 */  addiu      $a2, $a2, %lo(D_80010384)
    /* 3028C 8003FA8C D6FD000C */  jal        func_8003F758
    /* 30290 8003FA90 01000724 */   addiu     $a3, $zero, 0x1
    /* 30294 8003FA94 32FF0008 */  j          .L8003FCC8
    /* 30298 8003FA98 21100000 */   addu      $v0, $zero, $zero
  jlabel .L8003FA9C
    /* 3029C 8003FA9C C3FD000C */  jal        func_8003F70C
    /* 302A0 8003FAA0 00000000 */   nop
    /* 302A4 8003FAA4 21184000 */  addu       $v1, $v0, $zero
    /* 302A8 8003FAA8 1E006010 */  beqz       $v1, .L8003FB24
    /* 302AC 8003FAAC 01000224 */   addiu     $v0, $zero, 0x1
    /* 302B0 8003FAB0 85006214 */  bne        $v1, $v0, .L8003FCC8
    /* 302B4 8003FAB4 21106000 */   addu      $v0, $v1, $zero
    /* 302B8 8003FAB8 E2048393 */  lbu        $v1, %gp_rel(D_8009B3EA)($gp)
    /* 302BC 8003FABC 00000000 */  nop
    /* 302C0 8003FAC0 40006230 */  andi       $v0, $v1, 0x40
    /* 302C4 8003FAC4 0B004010 */  beqz       $v0, .L8003FAF4
    /* 302C8 8003FAC8 1D80043C */   lui       $a0, %hi(D_801D1200)
    /* 302CC 8003FACC 00128424 */  addiu      $a0, $a0, %lo(D_801D1200)
    /* 302D0 8003FAD0 A2F4000C */  jal        func_8003D288
    /* 302D4 8003FAD4 00108524 */   addiu     $a1, $a0, 0x1000
    /* 302D8 8003FAD8 03004014 */  bnez       $v0, .L8003FAE8
    /* 302DC 8003FADC 0A000224 */   addiu     $v0, $zero, 0xA
    /* 302E0 8003FAE0 32FF0008 */  j          .L8003FCC8
    /* 302E4 8003FAE4 01000224 */   addiu     $v0, $zero, 0x1
  .L8003FAE8:
    /* 302E8 8003FAE8 E20482A3 */  sb         $v0, %gp_rel(D_8009B3EA)($gp)
    /* 302EC 8003FAEC 32FF0008 */  j          .L8003FCC8
    /* 302F0 8003FAF0 21100000 */   addu      $v0, $zero, $zero
  .L8003FAF4:
    /* 302F4 8003FAF4 1D80043C */  lui        $a0, %hi(D_801D2200)
    /* 302F8 8003FAF8 00228424 */  addiu      $a0, $a0, %lo(D_801D2200)
    /* 302FC 8003FAFC 80060524 */  addiu      $a1, $zero, 0x680
    /* 30300 8003FB00 0180063C */  lui        $a2, %hi(D_80010384)
    /* 30304 8003FB04 8403C624 */  addiu      $a2, $a2, %lo(D_80010384)
    /* 30308 8003FB08 40006234 */  ori        $v0, $v1, 0x40
    /* 3030C 8003FB0C E20482A3 */  sb         $v0, %gp_rel(D_8009B3EA)($gp)
    /* 30310 8003FB10 D6FD000C */  jal        func_8003F758
    /* 30314 8003FB14 01000724 */   addiu     $a3, $zero, 0x1
    /* 30318 8003FB18 21180000 */  addu       $v1, $zero, $zero
    /* 3031C 8003FB1C 10000224 */  addiu      $v0, $zero, 0x10
    /* 30320 8003FB20 F10482A3 */  sb         $v0, %gp_rel(D_8009B3F9)($gp)
  .L8003FB24:
    /* 30324 8003FB24 32FF0008 */  j          .L8003FCC8
    /* 30328 8003FB28 21106000 */   addu      $v0, $v1, $zero
  jlabel .L8003FB2C
    /* 3032C 8003FB2C E2048393 */  lbu        $v1, %gp_rel(D_8009B3EA)($gp)
    /* 30330 8003FB30 00000000 */  nop
    /* 30334 8003FB34 80006230 */  andi       $v0, $v1, 0x80
    /* 30338 8003FB38 1C004014 */  bnez       $v0, .L8003FBAC
    /* 3033C 8003FB3C C0006234 */   ori       $v0, $v1, 0xC0
    /* 30340 8003FB40 E20482A3 */  sb         $v0, %gp_rel(D_8009B3EA)($gp)
    /* 30344 8003FB44 E2FC000C */  jal        func_8003F388
    /* 30348 8003FB48 00000000 */   nop
    /* 3034C 8003FB4C 20000624 */  addiu      $a2, $zero, 0x20
    /* 30350 8003FB50 50000724 */  addiu      $a3, $zero, 0x50
    /* 30354 8003FB54 E6048493 */  lbu        $a0, %gp_rel(D_8009B3EE)($gp)
    /* 30358 8003FB58 B8048593 */  lbu        $a1, %gp_rel(D_8009B3C0)($gp)
    /* 3035C 8003FB5C D004838F */  lw         $v1, %gp_rel(D_8009B3D8)($gp)
    /* 30360 8003FB60 00FC0224 */  addiu      $v0, $zero, -0x400
    /* 30364 8003FB64 600062A4 */  sh         $v0, 0x60($v1)
    /* 30368 8003FB68 00010224 */  addiu      $v0, $zero, 0x100
    /* 3036C 8003FB6C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 30370 8003FB70 30000224 */  addiu      $v0, $zero, 0x30
    /* 30374 8003FB74 1400A2AF */  sw         $v0, 0x14($sp)
    /* 30378 8003FB78 08100224 */  addiu      $v0, $zero, 0x1008
    /* 3037C 8003FB7C 0ED7000C */  jal        func_80035C38
    /* 30380 8003FB80 1800A2AF */   sw        $v0, 0x18($sp)
    /* 30384 8003FB84 21804000 */  addu       $s0, $v0, $zero
    /* 30388 8003FB88 10000224 */  addiu      $v0, $zero, 0x10
    /* 3038C 8003FB8C 590002A2 */  sb         $v0, 0x59($s0)
  .L8003FB90:
    /* 30390 8003FB90 E5E5000C */  jal        func_80039794
    /* 30394 8003FB94 00000000 */   nop
    /* 30398 8003FB98 34000296 */  lhu        $v0, 0x34($s0)
    /* 3039C 8003FB9C 00000000 */  nop
    /* 303A0 8003FBA0 00204230 */  andi       $v0, $v0, 0x2000
    /* 303A4 8003FBA4 FAFF4010 */  beqz       $v0, .L8003FB90
    /* 303A8 8003FBA8 00000000 */   nop
  .L8003FBAC:
    /* 303AC 8003FBAC E2048293 */  lbu        $v0, %gp_rel(D_8009B3EA)($gp)
    /* 303B0 8003FBB0 00000000 */  nop
    /* 303B4 8003FBB4 40004230 */  andi       $v0, $v0, 0x40
    /* 303B8 8003FBB8 0D004010 */  beqz       $v0, .L8003FBF0
    /* 303BC 8003FBBC 20000524 */   addiu     $a1, $zero, 0x20
    /* 303C0 8003FBC0 D004848F */  lw         $a0, %gp_rel(D_8009B3D8)($gp)
    /* 303C4 8003FBC4 E6048793 */  lbu        $a3, %gp_rel(D_8009B3EE)($gp)
    /* 303C8 8003FBC8 ACFC000C */  jal        func_8003F2B0
    /* 303CC 8003FBCC 50000624 */   addiu     $a2, $zero, 0x50
    /* 303D0 8003FBD0 3D004014 */  bnez       $v0, .L8003FCC8
    /* 303D4 8003FBD4 21100000 */   addu      $v0, $zero, $zero
    /* 303D8 8003FBD8 E2048293 */  lbu        $v0, %gp_rel(D_8009B3EA)($gp)
    /* 303DC 8003FBDC 00000000 */  nop
    /* 303E0 8003FBE0 BF004230 */  andi       $v0, $v0, 0xBF
    /* 303E4 8003FBE4 E20482A3 */  sb         $v0, %gp_rel(D_8009B3EA)($gp)
    /* 303E8 8003FBE8 32FF0008 */  j          .L8003FCC8
    /* 303EC 8003FBEC 21100000 */   addu      $v0, $zero, $zero
  .L8003FBF0:
    /* 303F0 8003FBF0 E5E5000C */  jal        func_80039794
    /* 303F4 8003FBF4 00000000 */   nop
    /* 303F8 8003FBF8 0F80043C */  lui        $a0, %hi(D_800EB0F8)
    /* 303FC 8003FBFC E6048393 */  lbu        $v1, %gp_rel(D_8009B3EE)($gp)
    /* 30400 8003FC00 F8B08424 */  addiu      $a0, $a0, %lo(D_800EB0F8)
    /* 30404 8003FC04 40100300 */  sll        $v0, $v1, 1
    /* 30408 8003FC08 21104300 */  addu       $v0, $v0, $v1
    /* 3040C 8003FC0C C0100200 */  sll        $v0, $v0, 3
    /* 30410 8003FC10 21104300 */  addu       $v0, $v0, $v1
    /* 30414 8003FC14 80100200 */  sll        $v0, $v0, 2
    /* 30418 8003FC18 21104400 */  addu       $v0, $v0, $a0
    /* 3041C 8003FC1C 34004294 */  lhu        $v0, 0x34($v0)
    /* 30420 8003FC20 00000000 */  nop
    /* 30424 8003FC24 08004230 */  andi       $v0, $v0, 0x8
    /* 30428 8003FC28 27004014 */  bnez       $v0, .L8003FCC8
    /* 3042C 8003FC2C 21100000 */   addu      $v0, $zero, $zero
    /* 30430 8003FC30 0B000224 */  addiu      $v0, $zero, 0xB
    /* 30434 8003FC34 E20482A3 */  sb         $v0, %gp_rel(D_8009B3EA)($gp)
    /* 30438 8003FC38 32FF0008 */  j          .L8003FCC8
    /* 3043C 8003FC3C 21100000 */   addu      $v0, $zero, $zero
  jlabel .L8003FC40
    /* 30440 8003FC40 E2048393 */  lbu        $v1, %gp_rel(D_8009B3EA)($gp)
    /* 30444 8003FC44 00000000 */  nop
    /* 30448 8003FC48 80006230 */  andi       $v0, $v1, 0x80
    /* 3044C 8003FC4C 06004014 */  bnez       $v0, .L8003FC68
    /* 30450 8003FC50 20000524 */   addiu     $a1, $zero, 0x20
    /* 30454 8003FC54 80006234 */  ori        $v0, $v1, 0x80
    /* 30458 8003FC58 D004838F */  lw         $v1, %gp_rel(D_8009B3D8)($gp)
    /* 3045C 8003FC5C E20482A3 */  sb         $v0, %gp_rel(D_8009B3EA)($gp)
    /* 30460 8003FC60 00040224 */  addiu      $v0, $zero, 0x400
    /* 30464 8003FC64 600062A4 */  sh         $v0, 0x60($v1)
  .L8003FC68:
    /* 30468 8003FC68 D004848F */  lw         $a0, %gp_rel(D_8009B3D8)($gp)
    /* 3046C 8003FC6C E6048793 */  lbu        $a3, %gp_rel(D_8009B3EE)($gp)
    /* 30470 8003FC70 ACFC000C */  jal        func_8003F2B0
    /* 30474 8003FC74 00010624 */   addiu     $a2, $zero, 0x100
    /* 30478 8003FC78 12004014 */  bnez       $v0, .L8003FCC4
    /* 3047C 8003FC7C 00000000 */   nop
    /* 30480 8003FC80 E6048293 */  lbu        $v0, %gp_rel(D_8009B3EE)($gp)
    /* 30484 8003FC84 00000000 */  nop
    /* 30488 8003FC88 40200200 */  sll        $a0, $v0, 1
    /* 3048C 8003FC8C 21208200 */  addu       $a0, $a0, $v0
    /* 30490 8003FC90 C0200400 */  sll        $a0, $a0, 3
    /* 30494 8003FC94 21208200 */  addu       $a0, $a0, $v0
    /* 30498 8003FC98 80200400 */  sll        $a0, $a0, 2
    /* 3049C 8003FC9C 0F80023C */  lui        $v0, %hi(D_800EB0F8)
    /* 304A0 8003FCA0 F8B04224 */  addiu      $v0, $v0, %lo(D_800EB0F8)
    /* 304A4 8003FCA4 DFD6000C */  jal        func_80035B7C
    /* 304A8 8003FCA8 21208200 */   addu      $a0, $a0, $v0
    /* 304AC 8003FCAC D004848F */  lw         $a0, %gp_rel(D_8009B3D8)($gp)
    /* 304B0 8003FCB0 DB00010C */  jal        func_8004036C
    /* 304B4 8003FCB4 00000000 */   nop
    /* 304B8 8003FCB8 D00480AF */  sw         $zero, %gp_rel(D_8009B3D8)($gp)
    /* 304BC 8003FCBC 32FF0008 */  j          .L8003FCC8
    /* 304C0 8003FCC0 02000224 */   addiu     $v0, $zero, 0x2
  jlabel .L8003FCC4
    /* 304C4 8003FCC4 21100000 */  addu       $v0, $zero, $zero
  .L8003FCC8:
    /* 304C8 8003FCC8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 304CC 8003FCCC 2000B08F */  lw         $s0, 0x20($sp)
    /* 304D0 8003FCD0 0800E003 */  jr         $ra
    /* 304D4 8003FCD4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003F8D4
