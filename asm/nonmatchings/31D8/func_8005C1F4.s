nonmatching func_8005C1F4, 0x180

glabel func_8005C1F4
    /* 4C9F4 8005C1F4 58018293 */  lbu        $v0, %gp_rel(D_8009B060)($gp)
    /* 4C9F8 8005C1F8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4C9FC 8005C1FC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4CA00 8005C200 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4CA04 8005C204 0A004010 */  beqz       $v0, .L8005C230
    /* 4CA08 8005C208 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4CA0C 8005C20C 0F80023C */  lui        $v0, %hi(D_800F5D44)
    /* 4CA10 8005C210 445D428C */  lw         $v0, %lo(D_800F5D44)($v0)
    /* 4CA14 8005C214 00000000 */  nop
    /* 4CA18 8005C218 06004010 */  beqz       $v0, .L8005C234
    /* 4CA1C 8005C21C 0400023C */   lui       $v0, (0x42400 >> 16)
    /* 4CA20 8005C220 A8E1010C */  jal        func_800786A0
    /* 4CA24 8005C224 00000000 */   nop
    /* 4CA28 8005C228 0F80013C */  lui        $at, %hi(D_800F5D44)
    /* 4CA2C 8005C22C 445D20AC */  sw         $zero, %lo(D_800F5D44)($at)
  .L8005C230:
    /* 4CA30 8005C230 0400023C */  lui        $v0, (0x42400 >> 16)
  .L8005C234:
    /* 4CA34 8005C234 00244234 */  ori        $v0, $v0, (0x42400 & 0xFFFF)
    /* 4CA38 8005C238 0300113C */  lui        $s1, (0x37000 >> 16)
    /* 4CA3C 8005C23C 00703136 */  ori        $s1, $s1, (0x37000 & 0xFFFF)
    /* 4CA40 8005C240 0400103C */  lui        $s0, (0x4242E >> 16)
    /* 4CA44 8005C244 5F018393 */  lbu        $v1, %gp_rel(D_8009B067)($gp)
    /* 4CA48 8005C248 9005868F */  lw         $a2, %gp_rel(D_8009B498)($gp)
    /* 4CA4C 8005C24C C0200300 */  sll        $a0, $v1, 3
    /* 4CA50 8005C250 21208200 */  addu       $a0, $a0, $v0
    /* 4CA54 8005C254 2120C400 */  addu       $a0, $a2, $a0
    /* 4CA58 8005C258 40100300 */  sll        $v0, $v1, 1
    /* 4CA5C 8005C25C 21104300 */  addu       $v0, $v0, $v1
    /* 4CA60 8005C260 00290200 */  sll        $a1, $v0, 4
    /* 4CA64 8005C264 2328A200 */  subu       $a1, $a1, $v0
    /* 4CA68 8005C268 002A0500 */  sll        $a1, $a1, 8
    /* 4CA6C 8005C26C 2128B100 */  addu       $a1, $a1, $s1
    /* 4CA70 8005C270 21106000 */  addu       $v0, $v1, $zero
    /* 4CA74 8005C274 2118C000 */  addu       $v1, $a2, $zero
    /* 4CA78 8005C278 C0100200 */  sll        $v0, $v0, 3
    /* 4CA7C 8005C27C 21106200 */  addu       $v0, $v1, $v0
    /* 4CA80 8005C280 21105000 */  addu       $v0, $v0, $s0
    /* 4CA84 8005C284 21187000 */  addu       $v1, $v1, $s0
    /* 4CA88 8005C288 2B246888 */  lwl        $t0, (0x4242B & 0xFFFF)($v1)
    /* 4CA8C 8005C28C 28246898 */  lwr        $t0, (0x42428 & 0xFFFF)($v1)
    /* 4CA90 8005C290 2F246988 */  lwl        $t1, (0x4242F & 0xFFFF)($v1)
    /* 4CA94 8005C294 2C246998 */  lwr        $t1, (0x4242C & 0xFFFF)($v1)
    /* 4CA98 8005C298 032448A8 */  swl        $t0, (0x42403 & 0xFFFF)($v0)
    /* 4CA9C 8005C29C 002448B8 */  swr        $t0, (0x42400 & 0xFFFF)($v0)
    /* 4CAA0 8005C2A0 072449A8 */  swl        $t1, (0x42407 & 0xFFFF)($v0)
    /* 4CAA4 8005C2A4 042449B8 */  swr        $t1, (0x42404 & 0xFFFF)($v0)
    /* 4CAA8 8005C2A8 5EFE010C */  jal        func_8007F978
    /* 4CAAC 8005C2AC 2128C500 */   addu      $a1, $a2, $a1
    /* 4CAB0 8005C2B0 5F018293 */  lbu        $v0, %gp_rel(D_8009B067)($gp)
    /* 4CAB4 8005C2B4 00000000 */  nop
    /* 4CAB8 8005C2B8 01004524 */  addiu      $a1, $v0, 0x1
    /* 4CABC 8005C2BC 0200A104 */  bgez       $a1, .L8005C2C8
    /* 4CAC0 8005C2C0 2118A000 */   addu      $v1, $a1, $zero
    /* 4CAC4 8005C2C4 04004324 */  addiu      $v1, $v0, 0x4
  .L8005C2C8:
    /* 4CAC8 8005C2C8 FC016330 */  andi       $v1, $v1, 0x1FC
    /* 4CACC 8005C2CC 9005878F */  lw         $a3, %gp_rel(D_8009B498)($gp)
    /* 4CAD0 8005C2D0 2318A300 */  subu       $v1, $a1, $v1
    /* 4CAD4 8005C2D4 5F0183A3 */  sb         $v1, %gp_rel(D_8009B067)($gp)
    /* 4CAD8 8005C2D8 2130F000 */  addu       $a2, $a3, $s0
    /* 4CADC 8005C2DC 2824C294 */  lhu        $v0, (0x42428 & 0xFFFF)($a2)
    /* 4CAE0 8005C2E0 2C24C494 */  lhu        $a0, (0x4242C & 0xFFFF)($a2)
    /* 4CAE4 8005C2E4 2024C384 */  lh         $v1, (0x42420 & 0xFFFF)($a2)
    /* 4CAE8 8005C2E8 21104400 */  addu       $v0, $v0, $a0
    /* 4CAEC 8005C2EC 2824C2A4 */  sh         $v0, (0x42428 & 0xFFFF)($a2)
    /* 4CAF0 8005C2F0 00140200 */  sll        $v0, $v0, 16
    /* 4CAF4 8005C2F4 2424C484 */  lh         $a0, (0x42424 & 0xFFFF)($a2)
    /* 4CAF8 8005C2F8 03140200 */  sra        $v0, $v0, 16
    /* 4CAFC 8005C2FC 21186400 */  addu       $v1, $v1, $a0
    /* 4CB00 8005C300 2A104300 */  slt        $v0, $v0, $v1
    /* 4CB04 8005C304 15004010 */  beqz       $v0, .L8005C35C
    /* 4CB08 8005C308 01000224 */   addiu     $v0, $zero, 0x1
    /* 4CB0C 8005C30C 2C24C584 */  lh         $a1, (0x4242C & 0xFFFF)($a2)
    /* 4CB10 8005C310 2E24C284 */  lh         $v0, (0x4242E & 0xFFFF)($a2)
    /* 4CB14 8005C314 00000000 */  nop
    /* 4CB18 8005C318 1800A200 */  mult       $a1, $v0
    /* 4CB1C 8005C31C 5F018393 */  lbu        $v1, %gp_rel(D_8009B067)($gp)
    /* 4CB20 8005C320 00000000 */  nop
    /* 4CB24 8005C324 40100300 */  sll        $v0, $v1, 1
    /* 4CB28 8005C328 21104300 */  addu       $v0, $v0, $v1
    /* 4CB2C 8005C32C 00210200 */  sll        $a0, $v0, 4
    /* 4CB30 8005C330 23208200 */  subu       $a0, $a0, $v0
    /* 4CB34 8005C334 00220400 */  sll        $a0, $a0, 8
    /* 4CB38 8005C338 21209100 */  addu       $a0, $a0, $s1
    /* 4CB3C 8005C33C 2120E400 */  addu       $a0, $a3, $a0
    /* 4CB40 8005C340 12280000 */  mflo       $a1
    /* 4CB44 8005C344 C2170500 */  srl        $v0, $a1, 31
    /* 4CB48 8005C348 2128A200 */  addu       $a1, $a1, $v0
    /* 4CB4C 8005C34C 6D3F020C */  jal        func_8008FDB4
    /* 4CB50 8005C350 43280500 */   sra       $a1, $a1, 1
    /* 4CB54 8005C354 D8700108 */  j          .L8005C360
    /* 4CB58 8005C358 00000000 */   nop
  .L8005C35C:
    /* 4CB5C 8005C35C 5A0182A3 */  sb         $v0, %gp_rel(D_8009B062)($gp)
  .L8005C360:
    /* 4CB60 8005C360 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4CB64 8005C364 1400B18F */  lw         $s1, 0x14($sp)
    /* 4CB68 8005C368 1000B08F */  lw         $s0, 0x10($sp)
    /* 4CB6C 8005C36C 0800E003 */  jr         $ra
    /* 4CB70 8005C370 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8005C1F4
