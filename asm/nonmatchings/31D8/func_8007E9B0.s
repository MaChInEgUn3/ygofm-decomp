nonmatching func_8007E9B0, 0x2B8

glabel func_8007E9B0
    /* 6F1B0 8007E9B0 0980033C */  lui        $v1, %hi(D_80093C08)
    /* 6F1B4 8007E9B4 083C638C */  lw         $v1, %lo(D_80093C08)($v1)
    /* 6F1B8 8007E9B8 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 6F1BC 8007E9BC 2800B2AF */  sw         $s2, 0x28($sp)
    /* 6F1C0 8007E9C0 5C00B28F */  lw         $s2, 0x5C($sp)
    /* 6F1C4 8007E9C4 3400B5AF */  sw         $s5, 0x34($sp)
    /* 6F1C8 8007E9C8 5800B58F */  lw         $s5, 0x58($sp)
    /* 6F1CC 8007E9CC 3000B4AF */  sw         $s4, 0x30($sp)
    /* 6F1D0 8007E9D0 21A08000 */  addu       $s4, $a0, $zero
    /* 6F1D4 8007E9D4 3800B6AF */  sw         $s6, 0x38($sp)
    /* 6F1D8 8007E9D8 21B0A000 */  addu       $s6, $a1, $zero
    /* 6F1DC 8007E9DC 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 6F1E0 8007E9E0 2198C000 */  addu       $s3, $a2, $zero
    /* 6F1E4 8007E9E4 3C00B7AF */  sw         $s7, 0x3C($sp)
    /* 6F1E8 8007E9E8 21B8E000 */  addu       $s7, $a3, $zero
    /* 6F1EC 8007E9EC 4000BFAF */  sw         $ra, 0x40($sp)
    /* 6F1F0 8007E9F0 2400B1AF */  sw         $s1, 0x24($sp)
    /* 6F1F4 8007E9F4 08006228 */  slti       $v0, $v1, 0x8
    /* 6F1F8 8007E9F8 03004014 */  bnez       $v0, .L8007EA08
    /* 6F1FC 8007E9FC 2000B0AF */   sw        $s0, 0x20($sp)
    /* 6F200 8007EA00 0FFB0108 */  j          .L8007EC3C
    /* 6F204 8007EA04 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8007EA08:
    /* 6F208 8007EA08 03006014 */  bnez       $v1, .L8007EA18
    /* 6F20C 8007EA0C 40100300 */   sll       $v0, $v1, 1
    /* 6F210 8007EA10 0980013C */  lui        $at, %hi(D_80094610)
    /* 6F214 8007EA14 104620AC */  sw         $zero, %lo(D_80094610)($at)
  .L8007EA18:
    /* 6F218 8007EA18 21104300 */  addu       $v0, $v0, $v1
    /* 6F21C 8007EA1C 00210200 */  sll        $a0, $v0, 4
    /* 6F220 8007EA20 0980033C */  lui        $v1, %hi(D_80094610)
    /* 6F224 8007EA24 1046638C */  lw         $v1, %lo(D_80094610)($v1)
    /* 6F228 8007EA28 0100622E */  sltiu      $v0, $s3, 0x1
    /* 6F22C 8007EA2C 0980013C */  lui        $at, %hi(D_80093AB4)
    /* 6F230 8007EA30 21082400 */  addu       $at, $at, $a0
    /* 6F234 8007EA34 B43A22AC */  sw         $v0, %lo(D_80093AB4)($at)
    /* 6F238 8007EA38 21107200 */  addu       $v0, $v1, $s2
    /* 6F23C 8007EA3C 01044228 */  slti       $v0, $v0, 0x401
    /* 6F240 8007EA40 02004014 */  bnez       $v0, .L8007EA4C
    /* 6F244 8007EA44 00040224 */   addiu     $v0, $zero, 0x400
    /* 6F248 8007EA48 23904300 */  subu       $s2, $v0, $v1
  .L8007EA4C:
    /* 6F24C 8007EA4C 0980113C */  lui        $s1, %hi(D_80093A98)
    /* 6F250 8007EA50 983A3126 */  addiu      $s1, $s1, %lo(D_80093A98)
    /* 6F254 8007EA54 21209100 */  addu       $a0, $a0, $s1
    /* 6F258 8007EA58 21280000 */  addu       $a1, $zero, $zero
    /* 6F25C 8007EA5C 00010224 */  addiu      $v0, $zero, 0x100
    /* 6F260 8007EA60 1C00A2A7 */  sh         $v0, 0x1C($sp)
    /* 6F264 8007EA64 1E00A2A7 */  sh         $v0, 0x1E($sp)
    /* 6F268 8007EA68 1800A227 */  addiu      $v0, $sp, 0x18
    /* 6F26C 8007EA6C 1080073C */  lui        $a3, %hi(D_800FC7A0)
    /* 6F270 8007EA70 A0C7E794 */  lhu        $a3, %lo(D_800FC7A0)($a3)
    /* 6F274 8007EA74 21300000 */  addu       $a2, $zero, $zero
    /* 6F278 8007EA78 1800A0A7 */  sh         $zero, 0x18($sp)
    /* 6F27C 8007EA7C 1A00A0A7 */  sh         $zero, 0x1A($sp)
    /* 6F280 8007EA80 780A020C */  jal        func_800829E0
    /* 6F284 8007EA84 1000A2AF */   sw        $v0, 0x10($sp)
    /* 6F288 8007EA88 2900A012 */  beqz       $s5, .L8007EB30
    /* 6F28C 8007EA8C F0FF3026 */   addiu     $s0, $s1, -0x10
    /* 6F290 8007EA90 0980023C */  lui        $v0, %hi(D_80093C08)
    /* 6F294 8007EA94 083C428C */  lw         $v0, %lo(D_80093C08)($v0)
    /* 6F298 8007EA98 00000000 */  nop
    /* 6F29C 8007EA9C 40200200 */  sll        $a0, $v0, 1
    /* 6F2A0 8007EAA0 21208200 */  addu       $a0, $a0, $v0
    /* 6F2A4 8007EAA4 00210400 */  sll        $a0, $a0, 4
    /* 6F2A8 8007EAA8 700A020C */  jal        func_800829C0
    /* 6F2AC 8007EAAC 21209000 */   addu      $a0, $a0, $s0
    /* 6F2B0 8007EAB0 0980033C */  lui        $v1, %hi(D_80093C08)
    /* 6F2B4 8007EAB4 083C638C */  lw         $v1, %lo(D_80093C08)($v1)
    /* 6F2B8 8007EAB8 00000000 */  nop
    /* 6F2BC 8007EABC 40100300 */  sll        $v0, $v1, 1
    /* 6F2C0 8007EAC0 21104300 */  addu       $v0, $v0, $v1
    /* 6F2C4 8007EAC4 00110200 */  sll        $v0, $v0, 4
    /* 6F2C8 8007EAC8 21105000 */  addu       $v0, $v0, $s0
    /* 6F2CC 8007EACC 040040A0 */  sb         $zero, 0x4($v0)
    /* 6F2D0 8007EAD0 0980033C */  lui        $v1, %hi(D_80093C08)
    /* 6F2D4 8007EAD4 083C638C */  lw         $v1, %lo(D_80093C08)($v1)
    /* 6F2D8 8007EAD8 00000000 */  nop
    /* 6F2DC 8007EADC 40100300 */  sll        $v0, $v1, 1
    /* 6F2E0 8007EAE0 21104300 */  addu       $v0, $v0, $v1
    /* 6F2E4 8007EAE4 00110200 */  sll        $v0, $v0, 4
    /* 6F2E8 8007EAE8 21105000 */  addu       $v0, $v0, $s0
    /* 6F2EC 8007EAEC 050040A0 */  sb         $zero, 0x5($v0)
    /* 6F2F0 8007EAF0 0980033C */  lui        $v1, %hi(D_80093C08)
    /* 6F2F4 8007EAF4 083C638C */  lw         $v1, %lo(D_80093C08)($v1)
    /* 6F2F8 8007EAF8 0200A53A */  xori       $a1, $s5, 0x2
    /* 6F2FC 8007EAFC 40100300 */  sll        $v0, $v1, 1
    /* 6F300 8007EB00 21104300 */  addu       $v0, $v0, $v1
    /* 6F304 8007EB04 00110200 */  sll        $v0, $v0, 4
    /* 6F308 8007EB08 21105000 */  addu       $v0, $v0, $s0
    /* 6F30C 8007EB0C 060040A0 */  sb         $zero, 0x6($v0)
    /* 6F310 8007EB10 0980023C */  lui        $v0, %hi(D_80093C08)
    /* 6F314 8007EB14 083C428C */  lw         $v0, %lo(D_80093C08)($v0)
    /* 6F318 8007EB18 0100A52C */  sltiu      $a1, $a1, 0x1
    /* 6F31C 8007EB1C 40200200 */  sll        $a0, $v0, 1
    /* 6F320 8007EB20 21208200 */  addu       $a0, $a0, $v0
    /* 6F324 8007EB24 00210400 */  sll        $a0, $a0, 4
    /* 6F328 8007EB28 100A020C */  jal        func_80082840
    /* 6F32C 8007EB2C 21209000 */   addu      $a0, $a0, $s0
  .L8007EB30:
    /* 6F330 8007EB30 0980043C */  lui        $a0, %hi(D_80093C08)
    /* 6F334 8007EB34 083C848C */  lw         $a0, %lo(D_80093C08)($a0)
    /* 6F338 8007EB38 F0FF2226 */  addiu      $v0, $s1, -0x10
    /* 6F33C 8007EB3C 40180400 */  sll        $v1, $a0, 1
    /* 6F340 8007EB40 21186400 */  addu       $v1, $v1, $a0
    /* 6F344 8007EB44 00190300 */  sll        $v1, $v1, 4
    /* 6F348 8007EB48 0980043C */  lui        $a0, %hi(D_80094610)
    /* 6F34C 8007EB4C 1046848C */  lw         $a0, %lo(D_80094610)($a0)
    /* 6F350 8007EB50 21106200 */  addu       $v0, $v1, $v0
    /* 6F354 8007EB54 080054A4 */  sh         $s4, 0x8($v0)
    /* 6F358 8007EB58 0A0056A4 */  sh         $s6, 0xA($v0)
    /* 6F35C 8007EB5C 0C0053A4 */  sh         $s3, 0xC($v0)
    /* 6F360 8007EB60 0E0057A4 */  sh         $s7, 0xE($v0)
    /* 6F364 8007EB64 1080023C */  lui        $v0, %hi(D_800F83A0)
    /* 6F368 8007EB68 A0834224 */  addiu      $v0, $v0, %lo(D_800F83A0)
    /* 6F36C 8007EB6C 0980013C */  lui        $at, %hi(D_80093AA4)
    /* 6F370 8007EB70 21082300 */  addu       $at, $at, $v1
    /* 6F374 8007EB74 A43A32AC */  sw         $s2, %lo(D_80093AA4)($at)
    /* 6F378 8007EB78 0980013C */  lui        $at, %hi(D_80093AB0)
    /* 6F37C 8007EB7C 21082300 */  addu       $at, $at, $v1
    /* 6F380 8007EB80 B03A20AC */  sw         $zero, %lo(D_80093AB0)($at)
    /* 6F384 8007EB84 21108200 */  addu       $v0, $a0, $v0
    /* 6F388 8007EB88 00210400 */  sll        $a0, $a0, 4
    /* 6F38C 8007EB8C 0980013C */  lui        $at, %hi(D_80093AAC)
    /* 6F390 8007EB90 21082300 */  addu       $at, $at, $v1
    /* 6F394 8007EB94 AC3A22AC */  sw         $v0, %lo(D_80093AAC)($at)
    /* 6F398 8007EB98 1080023C */  lui        $v0, %hi(D_800F87A0)
    /* 6F39C 8007EB9C A0874224 */  addiu      $v0, $v0, %lo(D_800F87A0)
    /* 6F3A0 8007EBA0 0980053C */  lui        $a1, %hi(D_80093AAC)
    /* 6F3A4 8007EBA4 2128A300 */  addu       $a1, $a1, $v1
    /* 6F3A8 8007EBA8 AC3AA58C */  lw         $a1, %lo(D_80093AAC)($a1)
    /* 6F3AC 8007EBAC 21208200 */  addu       $a0, $a0, $v0
    /* 6F3B0 8007EBB0 0980013C */  lui        $at, %hi(D_80093AA8)
    /* 6F3B4 8007EBB4 21082300 */  addu       $at, $at, $v1
    /* 6F3B8 8007EBB8 A83A24AC */  sw         $a0, %lo(D_80093AA8)($at)
    /* 6F3BC 8007EBBC 0000A0A0 */  sb         $zero, 0x0($a1)
    /* 6F3C0 8007EBC0 0980033C */  lui        $v1, %hi(D_80093C08)
    /* 6F3C4 8007EBC4 083C638C */  lw         $v1, %lo(D_80093C08)($v1)
    /* 6F3C8 8007EBC8 00000000 */  nop
    /* 6F3CC 8007EBCC 40100300 */  sll        $v0, $v1, 1
    /* 6F3D0 8007EBD0 21104300 */  addu       $v0, $v0, $v1
    /* 6F3D4 8007EBD4 00110200 */  sll        $v0, $v0, 4
    /* 6F3D8 8007EBD8 0980103C */  lui        $s0, %hi(D_80093AA8)
    /* 6F3DC 8007EBDC 21800202 */  addu       $s0, $s0, $v0
    /* 6F3E0 8007EBE0 A83A108E */  lw         $s0, %lo(D_80093AA8)($s0)
    /* 6F3E4 8007EBE4 0A00401A */  blez       $s2, .L8007EC10
    /* 6F3E8 8007EBE8 21880000 */   addu      $s1, $zero, $zero
  .L8007EBEC:
    /* 6F3EC 8007EBEC 680A020C */  jal        func_800829A0
    /* 6F3F0 8007EBF0 21200002 */   addu      $a0, $s0, $zero
    /* 6F3F4 8007EBF4 1080023C */  lui        $v0, %hi(D_800FC7A2)
    /* 6F3F8 8007EBF8 A2C74294 */  lhu        $v0, %lo(D_800FC7A2)($v0)
    /* 6F3FC 8007EBFC 01003126 */  addiu      $s1, $s1, 0x1
    /* 6F400 8007EC00 0E0002A6 */  sh         $v0, 0xE($s0)
    /* 6F404 8007EC04 2A103202 */  slt        $v0, $s1, $s2
    /* 6F408 8007EC08 F8FF4014 */  bnez       $v0, .L8007EBEC
    /* 6F40C 8007EC0C 10001026 */   addiu     $s0, $s0, 0x10
  .L8007EC10:
    /* 6F410 8007EC10 0980053C */  lui        $a1, %hi(D_80093C08)
    /* 6F414 8007EC14 083CA524 */  addiu      $a1, $a1, %lo(D_80093C08)
    /* 6F418 8007EC18 0000A48C */  lw         $a0, 0x0($a1)
    /* 6F41C 8007EC1C 0980033C */  lui        $v1, %hi(D_80094610)
    /* 6F420 8007EC20 1046638C */  lw         $v1, %lo(D_80094610)($v1)
    /* 6F424 8007EC24 21108000 */  addu       $v0, $a0, $zero
    /* 6F428 8007EC28 01008424 */  addiu      $a0, $a0, 0x1
    /* 6F42C 8007EC2C 21187200 */  addu       $v1, $v1, $s2
    /* 6F430 8007EC30 0980013C */  lui        $at, %hi(D_80094610)
    /* 6F434 8007EC34 104623AC */  sw         $v1, %lo(D_80094610)($at)
    /* 6F438 8007EC38 0000A4AC */  sw         $a0, 0x0($a1)
  .L8007EC3C:
    /* 6F43C 8007EC3C 4000BF8F */  lw         $ra, 0x40($sp)
    /* 6F440 8007EC40 3C00B78F */  lw         $s7, 0x3C($sp)
    /* 6F444 8007EC44 3800B68F */  lw         $s6, 0x38($sp)
    /* 6F448 8007EC48 3400B58F */  lw         $s5, 0x34($sp)
    /* 6F44C 8007EC4C 3000B48F */  lw         $s4, 0x30($sp)
    /* 6F450 8007EC50 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 6F454 8007EC54 2800B28F */  lw         $s2, 0x28($sp)
    /* 6F458 8007EC58 2400B18F */  lw         $s1, 0x24($sp)
    /* 6F45C 8007EC5C 2000B08F */  lw         $s0, 0x20($sp)
    /* 6F460 8007EC60 0800E003 */  jr         $ra
    /* 6F464 8007EC64 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8007E9B0
