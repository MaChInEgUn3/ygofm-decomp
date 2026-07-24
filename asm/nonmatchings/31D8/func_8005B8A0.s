nonmatching func_8005B8A0, 0x2DC

glabel func_8005B8A0
    /* 4C0A0 8005B8A0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 4C0A4 8005B8A4 2400B1AF */  sw         $s1, 0x24($sp)
    /* 4C0A8 8005B8A8 21888000 */  addu       $s1, $a0, $zero
    /* 4C0AC 8005B8AC 2800B2AF */  sw         $s2, 0x28($sp)
    /* 4C0B0 8005B8B0 2190A000 */  addu       $s2, $a1, $zero
    /* 4C0B4 8005B8B4 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 4C0B8 8005B8B8 4800A38F */  lw         $v1, 0x48($sp)
    /* 4C0BC 8005B8BC 4C00A58F */  lw         $a1, 0x4C($sp)
    /* 4C0C0 8005B8C0 0180043C */  lui        $a0, %hi(D_80010000)
    /* 4C0C4 8005B8C4 0000848C */  lw         $a0, %lo(D_80010000)($a0)
    /* 4C0C8 8005B8C8 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 4C0CC 8005B8CC 3000BFAF */  sw         $ra, 0x30($sp)
    /* 4C0D0 8005B8D0 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4C0D4 8005B8D4 5B0180A3 */  sb         $zero, %gp_rel(D_8009B063)($gp)
    /* 4C0D8 8005B8D8 5C0180A3 */  sb         $zero, %gp_rel(D_8009B064)($gp)
    /* 4C0DC 8005B8DC 5D0182A3 */  sb         $v0, %gp_rel(D_8009B065)($gp)
    /* 4C0E0 8005B8E0 680187AF */  sw         $a3, %gp_rel(D_8009B070)($gp)
    /* 4C0E4 8005B8E4 580183A3 */  sb         $v1, %gp_rel(D_8009B060)($gp)
    /* 4C0E8 8005B8E8 FF006330 */  andi       $v1, $v1, 0xFF
    /* 4C0EC 8005B8EC 900584AF */  sw         $a0, %gp_rel(D_8009B498)($gp)
    /* 4C0F0 8005B8F0 590185A3 */  sb         $a1, %gp_rel(D_8009B061)($gp)
    /* 4C0F4 8005B8F4 5D006010 */  beqz       $v1, .L8005BA6C
    /* 4C0F8 8005B8F8 2198C000 */   addu      $s3, $a2, $zero
    /* 4C0FC 8005B8FC C814020C */  jal        func_80085320
    /* 4C100 8005B900 00000000 */   nop
    /* 4C104 8005B904 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4C108 8005B908 21804000 */  addu       $s0, $v0, $zero
    /* 4C10C 8005B90C 80101000 */  sll        $v0, $s0, 2
    /* 4C110 8005B910 21105000 */  addu       $v0, $v0, $s0
    /* 4C114 8005B914 0A80053C */  lui        $a1, %hi(D_8009B144)
    /* 4C118 8005B918 44B1A590 */  lbu        $a1, %lo(D_8009B144)($a1)
    /* 4C11C 8005B91C 0A80063C */  lui        $a2, %hi(D_8009B143)
    /* 4C120 8005B920 43B1C690 */  lbu        $a2, %lo(D_8009B143)($a2)
    /* 4C124 8005B924 0A80073C */  lui        $a3, %hi(D_8009B142)
    /* 4C128 8005B928 42B1E790 */  lbu        $a3, %lo(D_8009B142)($a3)
    /* 4C12C 8005B92C 1080033C */  lui        $v1, %hi(D_800FE0D0)
    /* 4C130 8005B930 D0E06394 */  lhu        $v1, %lo(D_800FE0D0)($v1)
    /* 4C134 8005B934 1080083C */  lui        $t0, %hi(D_800FE0D4)
    /* 4C138 8005B938 D4E00895 */  lhu        $t0, %lo(D_800FE0D4)($t0)
    /* 4C13C 8005B93C 80110200 */  sll        $v0, $v0, 6
    /* 4C140 8005B940 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 4C144 8005B944 1A00A0A7 */  sh         $zero, 0x1A($sp)
    /* 4C148 8005B948 1C00A3A7 */  sh         $v1, 0x1C($sp)
    /* 4C14C 8005B94C 14FE010C */  jal        func_8007F850
    /* 4C150 8005B950 1E00A8A7 */   sh        $t0, 0x1E($sp)
    /* 4C154 8005B954 B3FD010C */  jal        func_8007F6CC
    /* 4C158 8005B958 21200000 */   addu      $a0, $zero, $zero
    /* 4C15C 8005B95C 5CD0010C */  jal        func_80074170
    /* 4C160 8005B960 21200000 */   addu      $a0, $zero, $zero
    /* 4C164 8005B964 4015020C */  jal        func_80085500
    /* 4C168 8005B968 0100103A */   xori      $s0, $s0, 0x1
    /* 4C16C 8005B96C 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4C170 8005B970 80101000 */  sll        $v0, $s0, 2
    /* 4C174 8005B974 21105000 */  addu       $v0, $v0, $s0
    /* 4C178 8005B978 0A80053C */  lui        $a1, %hi(D_8009B144)
    /* 4C17C 8005B97C 44B1A590 */  lbu        $a1, %lo(D_8009B144)($a1)
    /* 4C180 8005B980 0A80063C */  lui        $a2, %hi(D_8009B143)
    /* 4C184 8005B984 43B1C690 */  lbu        $a2, %lo(D_8009B143)($a2)
    /* 4C188 8005B988 0A80073C */  lui        $a3, %hi(D_8009B142)
    /* 4C18C 8005B98C 42B1E790 */  lbu        $a3, %lo(D_8009B142)($a3)
    /* 4C190 8005B990 1080033C */  lui        $v1, %hi(D_800FE0D0)
    /* 4C194 8005B994 D0E06394 */  lhu        $v1, %lo(D_800FE0D0)($v1)
    /* 4C198 8005B998 1080083C */  lui        $t0, %hi(D_800FE0D4)
    /* 4C19C 8005B99C D4E00895 */  lhu        $t0, %lo(D_800FE0D4)($t0)
    /* 4C1A0 8005B9A0 80110200 */  sll        $v0, $v0, 6
    /* 4C1A4 8005B9A4 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 4C1A8 8005B9A8 1A00A0A7 */  sh         $zero, 0x1A($sp)
    /* 4C1AC 8005B9AC 1C00A3A7 */  sh         $v1, 0x1C($sp)
    /* 4C1B0 8005B9B0 14FE010C */  jal        func_8007F850
    /* 4C1B4 8005B9B4 1E00A8A7 */   sh        $t0, 0x1E($sp)
    /* 4C1B8 8005B9B8 1080033C */  lui        $v1, %hi(D_800FE0D0)
    /* 4C1BC 8005B9BC D0E0638C */  lw         $v1, %lo(D_800FE0D0)($v1)
    /* 4C1C0 8005B9C0 00010224 */  addiu      $v0, $zero, 0x100
    /* 4C1C4 8005B9C4 1800A0A7 */  sh         $zero, 0x18($sp)
    /* 4C1C8 8005B9C8 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 4C1CC 8005B9CC 40100300 */  sll        $v0, $v1, 1
    /* 4C1D0 8005B9D0 21104300 */  addu       $v0, $v0, $v1
    /* 4C1D4 8005B9D4 C0120200 */  sll        $v0, $v0, 11
    /* 4C1D8 8005B9D8 02004104 */  bgez       $v0, .L8005B9E4
    /* 4C1DC 8005B9DC 00000000 */   nop
    /* 4C1E0 8005B9E0 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8005B9E4:
    /* 4C1E4 8005B9E4 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4C1E8 8005B9E8 0A80053C */  lui        $a1, %hi(D_8009B144)
    /* 4C1EC 8005B9EC 44B1A590 */  lbu        $a1, %lo(D_8009B144)($a1)
    /* 4C1F0 8005B9F0 0A80063C */  lui        $a2, %hi(D_8009B143)
    /* 4C1F4 8005B9F4 43B1C690 */  lbu        $a2, %lo(D_8009B143)($a2)
    /* 4C1F8 8005B9F8 0A80073C */  lui        $a3, %hi(D_8009B142)
    /* 4C1FC 8005B9FC 42B1E790 */  lbu        $a3, %lo(D_8009B142)($a3)
    /* 4C200 8005BA00 1080033C */  lui        $v1, %hi(D_800FE0D4)
    /* 4C204 8005BA04 D4E06394 */  lhu        $v1, %lo(D_800FE0D4)($v1)
    /* 4C208 8005BA08 03130200 */  sra        $v0, $v0, 12
    /* 4C20C 8005BA0C 1C00A2A7 */  sh         $v0, 0x1C($sp)
    /* 4C210 8005BA10 14FE010C */  jal        func_8007F850
    /* 4C214 8005BA14 1E00A3A7 */   sh        $v1, 0x1E($sp)
    /* 4C218 8005BA18 B3FD010C */  jal        func_8007F6CC
    /* 4C21C 8005BA1C 21200000 */   addu      $a0, $zero, $zero
    /* 4C220 8005BA20 5CD0010C */  jal        func_80074170
    /* 4C224 8005BA24 21200000 */   addu      $a0, $zero, $zero
    /* 4C228 8005BA28 01000224 */  addiu      $v0, $zero, 0x1
    /* 4C22C 8005BA2C 1080013C */  lui        $at, %hi(D_800FE0CC)
    /* 4C230 8005BA30 CCE022A4 */  sh         $v0, %lo(D_800FE0CC)($at)
    /* 4C234 8005BA34 4015020C */  jal        func_80085500
    /* 4C238 8005BA38 00000000 */   nop
    /* 4C23C 8005BA3C 21200000 */  addu       $a0, $zero, $zero
    /* 4C240 8005BA40 21288000 */  addu       $a1, $a0, $zero
    /* 4C244 8005BA44 21308000 */  addu       $a2, $a0, $zero
    /* 4C248 8005BA48 A815020C */  jal        func_800856A0
    /* 4C24C 8005BA4C 00010724 */   addiu     $a3, $zero, 0x100
    /* 4C250 8005BA50 40010424 */  addiu      $a0, $zero, 0x140
    /* 4C254 8005BA54 F0000524 */  addiu      $a1, $zero, 0xF0
    /* 4C258 8005BA58 04000624 */  addiu      $a2, $zero, 0x4
    /* 4C25C 8005BA5C 01000724 */  addiu      $a3, $zero, 0x1
    /* 4C260 8005BA60 2110E000 */  addu       $v0, $a3, $zero
    /* 4C264 8005BA64 D813020C */  jal        func_80084F60
    /* 4C268 8005BA68 1000A2AF */   sw        $v0, 0x10($sp)
  .L8005BA6C:
    /* 4C26C 8005BA6C 07002012 */  beqz       $s1, .L8005BA8C
    /* 4C270 8005BA70 00000000 */   nop
    /* 4C274 8005BA74 94058C27 */  addiu      $t4, $gp, %gp_rel(D_8009B49C)
    /* 4C278 8005BA78 0300298A */  lwl        $t1, 0x3($s1)
    /* 4C27C 8005BA7C 0000299A */  lwr        $t1, 0x0($s1)
    /* 4C280 8005BA80 00000000 */  nop
    /* 4C284 8005BA84 030089A9 */  swl        $t1, 0x3($t4)
    /* 4C288 8005BA88 000089B9 */  swr        $t1, 0x0($t4)
  .L8005BA8C:
    /* 4C28C 8005BA8C 04004012 */  beqz       $s2, .L8005BAA0
    /* 4C290 8005BA90 01000224 */   addiu     $v0, $zero, 0x1
    /* 4C294 8005BA94 600192AF */  sw         $s2, %gp_rel(D_8009B068)($gp)
    /* 4C298 8005BA98 A96E0108 */  j          .L8005BAA4
    /* 4C29C 8005BA9C 00000000 */   nop
  .L8005BAA0:
    /* 4C2A0 8005BAA0 600182AF */  sw         $v0, %gp_rel(D_8009B068)($gp)
  .L8005BAA4:
    /* 4C2A4 8005BAA4 04006012 */  beqz       $s3, .L8005BAB8
    /* 4C2A8 8005BAA8 FFFF0234 */   ori       $v0, $zero, 0xFFFF
    /* 4C2AC 8005BAAC 640193AF */  sw         $s3, %gp_rel(D_8009B06C)($gp)
    /* 4C2B0 8005BAB0 AF6E0108 */  j          .L8005BABC
    /* 4C2B4 8005BAB4 00000000 */   nop
  .L8005BAB8:
    /* 4C2B8 8005BAB8 640182AF */  sw         $v0, %gp_rel(D_8009B06C)($gp)
  .L8005BABC:
    /* 4C2BC 8005BABC 5E0180A3 */  sb         $zero, %gp_rel(D_8009B066)($gp)
    /* 4C2C0 8005BAC0 5F0180A3 */  sb         $zero, %gp_rel(D_8009B067)($gp)
    /* 4C2C4 8005BAC4 F83E020C */  jal        func_8008FBE0
    /* 4C2C8 8005BAC8 21200000 */   addu      $a0, $zero, $zero
    /* 4C2CC 8005BACC 0680043C */  lui        $a0, %hi(func_8005C1F4)
    /* 4C2D0 8005BAD0 9F3F020C */  jal        func_8008FE7C
    /* 4C2D4 8005BAD4 F4C18424 */   addiu     $a0, $a0, %lo(func_8005C1F4)
    /* 4C2D8 8005BAD8 9005848F */  lw         $a0, %gp_rel(D_8009B498)($gp)
    /* 4C2DC 8005BADC 7C41020C */  jal        func_800905F0
    /* 4C2E0 8005BAE0 00000000 */   nop
    /* 4C2E4 8005BAE4 0100023C */  lui        $v0, (0x11000 >> 16)
    /* 4C2E8 8005BAE8 00104234 */  ori        $v0, $v0, (0x11000 & 0xFFFF)
    /* 4C2EC 8005BAEC 9005848F */  lw         $a0, %gp_rel(D_8009B498)($gp)
    /* 4C2F0 8005BAF0 14000524 */  addiu      $a1, $zero, 0x14
    /* 4C2F4 8005BAF4 70E0010C */  jal        func_800781C0
    /* 4C2F8 8005BAF8 21208200 */   addu      $a0, $a0, $v0
    /* 4C2FC 8005BAFC 9CE0010C */  jal        func_80078270
    /* 4C300 8005BB00 00000000 */   nop
    /* 4C304 8005BB04 21380000 */  addu       $a3, $zero, $zero
    /* 4C308 8005BB08 0680023C */  lui        $v0, %hi(func_8005C690)
    /* 4C30C 8005BB0C 58018493 */  lbu        $a0, %gp_rel(D_8009B060)($gp)
    /* 4C310 8005BB10 6001858F */  lw         $a1, %gp_rel(D_8009B068)($gp)
    /* 4C314 8005BB14 6401868F */  lw         $a2, %gp_rel(D_8009B06C)($gp)
    /* 4C318 8005BB18 90C64224 */  addiu      $v0, $v0, %lo(func_8005C690)
    /* 4C31C 8005BB1C 10E1010C */  jal        func_80078440
    /* 4C320 8005BB20 1000A2AF */   sw        $v0, 0x10($sp)
    /* 4C324 8005BB24 6401838F */  lw         $v1, %gp_rel(D_8009B06C)($gp)
    /* 4C328 8005BB28 00000000 */  nop
    /* 4C32C 8005BB2C 0500622C */  sltiu      $v0, $v1, 0x5
    /* 4C330 8005BB30 02004014 */  bnez       $v0, .L8005BB3C
    /* 4C334 8005BB34 FCFF6224 */   addiu     $v0, $v1, -0x4
    /* 4C338 8005BB38 640182AF */  sw         $v0, %gp_rel(D_8009B06C)($gp)
  .L8005BB3C:
    /* 4C33C 8005BB3C 94058427 */  addiu      $a0, $gp, %gp_rel(D_8009B49C)
    /* 4C340 8005BB40 8B71010C */  jal        func_8005C62C
    /* 4C344 8005BB44 00000000 */   nop
    /* 4C348 8005BB48 F26F010C */  jal        func_8005BFC8
    /* 4C34C 8005BB4C 21200000 */   addu      $a0, $zero, $zero
    /* 4C350 8005BB50 21184000 */  addu       $v1, $v0, $zero
    /* 4C354 8005BB54 02006014 */  bnez       $v1, .L8005BB60
    /* 4C358 8005BB58 00000000 */   nop
    /* 4C35C 8005BB5C 21100000 */  addu       $v0, $zero, $zero
  .L8005BB60:
    /* 4C360 8005BB60 3000BF8F */  lw         $ra, 0x30($sp)
    /* 4C364 8005BB64 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 4C368 8005BB68 2800B28F */  lw         $s2, 0x28($sp)
    /* 4C36C 8005BB6C 2400B18F */  lw         $s1, 0x24($sp)
    /* 4C370 8005BB70 2000B08F */  lw         $s0, 0x20($sp)
    /* 4C374 8005BB74 0800E003 */  jr         $ra
    /* 4C378 8005BB78 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8005B8A0
