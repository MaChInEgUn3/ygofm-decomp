nonmatching func_8001F0D0, 0x294

glabel func_8001F0D0
    /* F8D0 8001F0D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F8D4 8001F0D4 1000BFAF */  sw         $ra, 0x10($sp)
    /* F8D8 8001F0D8 21380000 */  addu       $a3, $zero, $zero
    /* F8DC 8001F0DC 0100053C */  lui        $a1, (0x18000 >> 16)
    /* F8E0 8001F0E0 0080A534 */  ori        $a1, $a1, (0x18000 & 0xFFFF)
    /* F8E4 8001F0E4 1680023C */  lui        $v0, %hi(D_8015C424)
    /* F8E8 8001F0E8 24C44324 */  addiu      $v1, $v0, %lo(D_8015C424)
  .L8001F0EC:
    /* F8EC 8001F0EC 21106500 */  addu       $v0, $v1, $a1
    /* F8F0 8001F0F0 683C40A4 */  sh         $zero, 0x3C68($v0)
    /* F8F4 8001F0F4 0100E724 */  addiu      $a3, $a3, 0x1
    /* F8F8 8001F0F8 0600E228 */  slti       $v0, $a3, 0x6
    /* F8FC 8001F0FC FBFF4014 */  bnez       $v0, .L8001F0EC
    /* F900 8001F100 02006324 */   addiu     $v1, $v1, 0x2
    /* F904 8001F104 21500000 */  addu       $t2, $zero, $zero
    /* F908 8001F108 21384001 */  addu       $a3, $t2, $zero
    /* F90C 8001F10C 0980023C */  lui        $v0, %hi(D_800907D8)
    /* F910 8001F110 D8074E24 */  addiu      $t6, $v0, %lo(D_800907D8)
    /* F914 8001F114 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* F918 8001F118 D87A4D24 */  addiu      $t5, $v0, %lo(D_801A7AD8)
    /* F91C 8001F11C 1680023C */  lui        $v0, %hi(D_8015C424)
    /* F920 8001F120 24C44B24 */  addiu      $t3, $v0, %lo(D_8015C424)
    /* F924 8001F124 0100093C */  lui        $t1, (0x18000 >> 16)
    /* F928 8001F128 CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* F92C 8001F12C 00802935 */  ori        $t1, $t1, (0x18000 & 0xFFFF)
    /* F930 8001F130 80100300 */  sll        $v0, $v1, 2
    /* F934 8001F134 21104300 */  addu       $v0, $v0, $v1
    /* F938 8001F138 80600200 */  sll        $t4, $v0, 2
    /* F93C 8001F13C 2110EC00 */  addu       $v0, $a3, $t4
  .L8001F140:
    /* F940 8001F140 21104E00 */  addu       $v0, $v0, $t6
    /* F944 8001F144 00004390 */  lbu        $v1, 0x0($v0)
    /* F948 8001F148 00000000 */  nop
    /* F94C 8001F14C C0100300 */  sll        $v0, $v1, 3
    /* F950 8001F150 23104300 */  subu       $v0, $v0, $v1
    /* F954 8001F154 80100200 */  sll        $v0, $v0, 2
    /* F958 8001F158 21304D00 */  addu       $a2, $v0, $t5
    /* F95C 8001F15C 1600C294 */  lhu        $v0, 0x16($a2)
    /* F960 8001F160 00000000 */  nop
    /* F964 8001F164 00804230 */  andi       $v0, $v0, 0x8000
    /* F968 8001F168 15004010 */  beqz       $v0, .L8001F1C0
    /* F96C 8001F16C 00000000 */   nop
    /* F970 8001F170 0C00C594 */  lhu        $a1, 0xC($a2)
    /* F974 8001F174 00000000 */  nop
    /* F978 8001F178 57FDA224 */  addiu      $v0, $a1, -0x2A9
    /* F97C 8001F17C 0600422C */  sltiu      $v0, $v0, 0x6
    /* F980 8001F180 0F004010 */  beqz       $v0, .L8001F1C0
    /* F984 8001F184 001C0500 */   sll       $v1, $a1, 16
    /* F988 8001F188 031C0300 */  sra        $v1, $v1, 16
    /* F98C 8001F18C 57FD6824 */  addiu      $t0, $v1, -0x2A9
    /* F990 8001F190 01004A25 */  addiu      $t2, $t2, 0x1
    /* F994 8001F194 40100800 */  sll        $v0, $t0, 1
    /* F998 8001F198 21104B00 */  addu       $v0, $v0, $t3
    /* F99C 8001F19C 21104900 */  addu       $v0, $v0, $t1
    /* F9A0 8001F1A0 67FD6324 */  addiu      $v1, $v1, -0x299
    /* F9A4 8001F1A4 40180300 */  sll        $v1, $v1, 1
    /* F9A8 8001F1A8 683C45A4 */  sh         $a1, 0x3C68($v0)
    /* F9AC 8001F1AC 0000C28C */  lw         $v0, 0x0($a2)
    /* F9B0 8001F1B0 21186B00 */  addu       $v1, $v1, $t3
    /* F9B4 8001F1B4 6A004290 */  lbu        $v0, 0x6A($v0)
    /* F9B8 8001F1B8 21186900 */  addu       $v1, $v1, $t1
    /* F9BC 8001F1BC 683C62A4 */  sh         $v0, 0x3C68($v1)
  .L8001F1C0:
    /* F9C0 8001F1C0 0100E724 */  addiu      $a3, $a3, 0x1
    /* F9C4 8001F1C4 0500E228 */  slti       $v0, $a3, 0x5
    /* F9C8 8001F1C8 DDFF4014 */  bnez       $v0, .L8001F140
    /* F9CC 8001F1CC 2110EC00 */   addu      $v0, $a3, $t4
    /* F9D0 8001F1D0 41004011 */  beqz       $t2, .L8001F2D8
    /* F9D4 8001F1D4 21380000 */   addu      $a3, $zero, $zero
    /* F9D8 8001F1D8 6A008390 */  lbu        $v1, 0x6A($a0)
    /* F9DC 8001F1DC 1A80043C */  lui        $a0, %hi(D_801A7AD8)
    /* F9E0 8001F1E0 D87A8424 */  addiu      $a0, $a0, %lo(D_801A7AD8)
    /* F9E4 8001F1E4 C0100300 */  sll        $v0, $v1, 3
    /* F9E8 8001F1E8 23104300 */  subu       $v0, $v0, $v1
    /* F9EC 8001F1EC 80100200 */  sll        $v0, $v0, 2
    /* F9F0 8001F1F0 325C000C */  jal        func_800170C8
    /* F9F4 8001F1F4 21204400 */   addu      $a0, $v0, $a0
    /* F9F8 8001F1F8 FFFF4830 */  andi       $t0, $v0, 0xFFFF
    /* F9FC 8001F1FC FFFF0524 */  addiu      $a1, $zero, -0x1
    /* FA00 8001F200 0100063C */  lui        $a2, (0x18000 >> 16)
    /* FA04 8001F204 0080C634 */  ori        $a2, $a2, (0x18000 & 0xFFFF)
    /* FA08 8001F208 1680023C */  lui        $v0, %hi(D_8015C424)
    /* FA0C 8001F20C 24C44224 */  addiu      $v0, $v0, %lo(D_8015C424)
    /* FA10 8001F210 0A004424 */  addiu      $a0, $v0, 0xA
    /* FA14 8001F214 21108600 */  addu       $v0, $a0, $a2
    /* FA18 8001F218 683C4294 */  lhu        $v0, 0x3C68($v0)
    /* FA1C 8001F21C 1C008927 */  addiu      $t1, $gp, %gp_rel(D_8009AF24)
    /* FA20 8001F220 05004010 */  beqz       $v0, .L8001F238
    /* FA24 8001F224 05000724 */   addiu     $a3, $zero, 0x5
    /* FA28 8001F228 21008393 */  lbu        $v1, %gp_rel(D_8009AF29)($gp)
    /* FA2C 8001F22C 997C0008 */  j          .L8001F264
    /* FA30 8001F230 40100300 */   sll       $v0, $v1, 1
  .L8001F234:
    /* FA34 8001F234 2128E000 */  addu       $a1, $a3, $zero
  .L8001F238:
    /* FA38 8001F238 FFFFE724 */  addiu      $a3, $a3, -0x1
    /* FA3C 8001F23C 1000E004 */  bltz       $a3, .L8001F280
    /* FA40 8001F240 FEFF8424 */   addiu     $a0, $a0, -0x2
    /* FA44 8001F244 21108600 */  addu       $v0, $a0, $a2
    /* FA48 8001F248 683C4294 */  lhu        $v0, 0x3C68($v0)
    /* FA4C 8001F24C 00000000 */  nop
    /* FA50 8001F250 F9FF4010 */  beqz       $v0, .L8001F238
    /* FA54 8001F254 2110E900 */   addu      $v0, $a3, $t1
    /* FA58 8001F258 00004390 */  lbu        $v1, 0x0($v0)
    /* FA5C 8001F25C 00000000 */  nop
    /* FA60 8001F260 40100300 */  sll        $v0, $v1, 1
  .L8001F264:
    /* FA64 8001F264 21104300 */  addu       $v0, $v0, $v1
    /* FA68 8001F268 C0100200 */  sll        $v0, $v0, 3
    /* FA6C 8001F26C 21104300 */  addu       $v0, $v0, $v1
    /* FA70 8001F270 80100200 */  sll        $v0, $v0, 2
    /* FA74 8001F274 2A104800 */  slt        $v0, $v0, $t0
    /* FA78 8001F278 EEFF4010 */  beqz       $v0, .L8001F234
    /* FA7C 8001F27C 00000000 */   nop
  .L8001F280:
    /* FA80 8001F280 1400A004 */  bltz       $a1, .L8001F2D4
    /* FA84 8001F284 0100043C */   lui       $a0, (0x18000 >> 16)
    /* FA88 8001F288 00808434 */  ori        $a0, $a0, (0x18000 & 0xFFFF)
    /* FA8C 8001F28C A902A224 */  addiu      $v0, $a1, 0x2A9
    /* FA90 8001F290 1680033C */  lui        $v1, %hi(D_8015C424)
    /* FA94 8001F294 24C46324 */  addiu      $v1, $v1, %lo(D_8015C424)
    /* FA98 8001F298 220382A7 */  sh         $v0, %gp_rel(D_8009B22A)($gp)
    /* FA9C 8001F29C 1000A224 */  addiu      $v0, $a1, 0x10
    /* FAA0 8001F2A0 40100200 */  sll        $v0, $v0, 1
    /* FAA4 8001F2A4 21104300 */  addu       $v0, $v0, $v1
    /* FAA8 8001F2A8 21104400 */  addu       $v0, $v0, $a0
    /* FAAC 8001F2AC 683C4390 */  lbu        $v1, 0x3C68($v0)
    /* FAB0 8001F2B0 B27C0008 */  j          .L8001F2C8
    /* FAB4 8001F2B4 01000224 */   addiu     $v0, $zero, 0x1
  .L8001F2B8:
    /* FAB8 8001F2B8 0000C28C */  lw         $v0, 0x0($a2)
    /* FABC 8001F2BC 220383A7 */  sh         $v1, %gp_rel(D_8009B22A)($gp)
    /* FAC0 8001F2C0 6A004390 */  lbu        $v1, 0x6A($v0)
    /* FAC4 8001F2C4 01000224 */  addiu      $v0, $zero, 0x1
  .L8001F2C8:
    /* FAC8 8001F2C8 B00283A3 */  sb         $v1, %gp_rel(D_8009B1B8)($gp)
    /* FACC 8001F2CC D57C0008 */  j          .L8001F354
    /* FAD0 8001F2D0 00000000 */   nop
  .L8001F2D4:
    /* FAD4 8001F2D4 21380000 */  addu       $a3, $zero, $zero
  .L8001F2D8:
    /* FAD8 8001F2D8 0980023C */  lui        $v0, %hi(D_800907D8)
    /* FADC 8001F2DC D8074924 */  addiu      $t1, $v0, %lo(D_800907D8)
    /* FAE0 8001F2E0 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* FAE4 8001F2E4 D87A4824 */  addiu      $t0, $v0, %lo(D_801A7AD8)
    /* FAE8 8001F2E8 CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* FAEC 8001F2EC B2020524 */  addiu      $a1, $zero, 0x2B2
    /* FAF0 8001F2F0 80100300 */  sll        $v0, $v1, 2
    /* FAF4 8001F2F4 21104300 */  addu       $v0, $v0, $v1
    /* FAF8 8001F2F8 80200200 */  sll        $a0, $v0, 2
    /* FAFC 8001F2FC 2110E400 */  addu       $v0, $a3, $a0
  .L8001F300:
    /* FB00 8001F300 21104900 */  addu       $v0, $v0, $t1
    /* FB04 8001F304 00004390 */  lbu        $v1, 0x0($v0)
    /* FB08 8001F308 00000000 */  nop
    /* FB0C 8001F30C C0100300 */  sll        $v0, $v1, 3
    /* FB10 8001F310 23104300 */  subu       $v0, $v0, $v1
    /* FB14 8001F314 80100200 */  sll        $v0, $v0, 2
    /* FB18 8001F318 21304800 */  addu       $a2, $v0, $t0
    /* FB1C 8001F31C 1600C294 */  lhu        $v0, 0x16($a2)
    /* FB20 8001F320 00000000 */  nop
    /* FB24 8001F324 00804230 */  andi       $v0, $v0, 0x8000
    /* FB28 8001F328 05004010 */  beqz       $v0, .L8001F340
    /* FB2C 8001F32C 00000000 */   nop
    /* FB30 8001F330 0C00C384 */  lh         $v1, 0xC($a2)
    /* FB34 8001F334 00000000 */  nop
    /* FB38 8001F338 DFFF6510 */  beq        $v1, $a1, .L8001F2B8
    /* FB3C 8001F33C 00000000 */   nop
  .L8001F340:
    /* FB40 8001F340 0100E724 */  addiu      $a3, $a3, 0x1
    /* FB44 8001F344 0500E228 */  slti       $v0, $a3, 0x5
    /* FB48 8001F348 EDFF4014 */  bnez       $v0, .L8001F300
    /* FB4C 8001F34C 2110E400 */   addu      $v0, $a3, $a0
    /* FB50 8001F350 21100000 */  addu       $v0, $zero, $zero
  .L8001F354:
    /* FB54 8001F354 1000BF8F */  lw         $ra, 0x10($sp)
    /* FB58 8001F358 00000000 */  nop
    /* FB5C 8001F35C 0800E003 */  jr         $ra
    /* FB60 8001F360 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001F0D0
