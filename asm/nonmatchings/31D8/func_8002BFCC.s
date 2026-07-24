nonmatching func_8002BFCC, 0x434

glabel func_8002BFCC
    /* 1C7CC 8002BFCC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 1C7D0 8002BFD0 3800BFAF */  sw         $ra, 0x38($sp)
    /* 1C7D4 8002BFD4 3400B5AF */  sw         $s5, 0x34($sp)
    /* 1C7D8 8002BFD8 3000B4AF */  sw         $s4, 0x30($sp)
    /* 1C7DC 8002BFDC 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 1C7E0 8002BFE0 2800B2AF */  sw         $s2, 0x28($sp)
    /* 1C7E4 8002BFE4 2400B1AF */  sw         $s1, 0x24($sp)
    /* 1C7E8 8002BFE8 2000B0AF */  sw         $s0, 0x20($sp)
    /* 1C7EC 8002BFEC 0A80013C */  lui        $at, %hi(D_8009B148)
    /* 1C7F0 8002BFF0 48B120A4 */  sh         $zero, %lo(D_8009B148)($at)
    /* 1C7F4 8002BFF4 0A80013C */  lui        $at, %hi(D_8009B146)
    /* 1C7F8 8002BFF8 46B120A4 */  sh         $zero, %lo(D_8009B146)($at)
    /* 1C7FC 8002BFFC 9AD5000C */  jal        func_80035668
    /* 1C800 8002C000 21200000 */   addu      $a0, $zero, $zero
    /* 1C804 8002C004 5DA5000C */  jal        func_80029574
    /* 1C808 8002C008 21200000 */   addu      $a0, $zero, $zero
    /* 1C80C 8002C00C D1021324 */  addiu      $s3, $zero, 0x2D1
    /* 1C810 8002C010 1880043C */  lui        $a0, (0x801805A2 >> 16)
    /* 1C814 8002C014 A2058434 */  ori        $a0, $a0, (0x801805A2 & 0xFFFF)
    /* 1C818 8002C018 0F80033C */  lui        $v1, %hi(D_800EA0E8)
    /* 1C81C 8002C01C E8A06324 */  addiu      $v1, $v1, %lo(D_800EA0E8)
    /* 1C820 8002C020 00010224 */  addiu      $v0, $zero, 0x100
    /* 1C824 8002C024 280062A4 */  sh         $v0, 0x28($v1)
    /* 1C828 8002C028 2A0062A4 */  sh         $v0, 0x2A($v1)
    /* 1C82C 8002C02C 00020224 */  addiu      $v0, $zero, 0x200
    /* 1C830 8002C030 2C0062A4 */  sh         $v0, 0x2C($v1)
    /* 1C834 8002C034 F0000224 */  addiu      $v0, $zero, 0xF0
    /* 1C838 8002C038 2E0062A4 */  sh         $v0, 0x2E($v1)
  .L8002C03C:
    /* 1C83C 8002C03C 01006226 */  addiu      $v0, $s3, 0x1
    /* 1C840 8002C040 000082A4 */  sh         $v0, 0x0($a0)
    /* 1C844 8002C044 FFFF7326 */  addiu      $s3, $s3, -0x1
    /* 1C848 8002C048 FCFF6106 */  bgez       $s3, .L8002C03C
    /* 1C84C 8002C04C FEFF8424 */   addiu     $a0, $a0, -0x2
    /* 1C850 8002C050 21200000 */  addu       $a0, $zero, $zero
    /* 1C854 8002C054 21288000 */  addu       $a1, $a0, $zero
    /* 1C858 8002C058 CD1D0624 */  addiu      $a2, $zero, 0x1DCD
    /* 1C85C 8002C05C 8A000724 */  addiu      $a3, $zero, 0x8A
    /* 1C860 8002C060 0380023C */  lui        $v0, %hi(func_8002BD0C)
    /* 1C864 8002C064 0CBD4224 */  addiu      $v0, $v0, %lo(func_8002BD0C)
    /* 1C868 8002C068 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1C86C 8002C06C 1400A0AF */  sw         $zero, 0x14($sp)
    /* 1C870 8002C070 8753000C */  jal        func_80014E1C
    /* 1C874 8002C074 1800A0AF */   sw        $zero, 0x18($sp)
    /* 1C878 8002C078 F94D000C */  jal        func_800137E4
    /* 1C87C 8002C07C 00000000 */   nop
    /* 1C880 8002C080 CFAF000C */  jal        func_8002BF3C
    /* 1C884 8002C084 00000000 */   nop
    /* 1C888 8002C088 0F80033C */  lui        $v1, %hi(D_800E9DBC)
    /* 1C88C 8002C08C 0380023C */  lui        $v0, %hi(func_80029EC4)
    /* 1C890 8002C090 C49E4224 */  addiu      $v0, $v0, %lo(func_80029EC4)
    /* 1C894 8002C094 64A5000C */  jal        func_80029590
    /* 1C898 8002C098 BC9D62AC */   sw        $v0, %lo(D_800E9DBC)($v1)
    /* 1C89C 8002C09C 0F80023C */  lui        $v0, %hi(D_800EA1E8)
    /* 1C8A0 8002C0A0 50038393 */  lbu        $v1, %gp_rel(D_8009B258)($gp)
    /* 1C8A4 8002C0A4 E8A15524 */  addiu      $s5, $v0, %lo(D_800EA1E8)
    /* 1C8A8 8002C0A8 E8A140A0 */  sb         $zero, %lo(D_800EA1E8)($v0)
    /* 1C8AC 8002C0AC 002E0300 */  sll        $a1, $v1, 24
    /* 1C8B0 8002C0B0 03260500 */  sra        $a0, $a1, 24
    /* 1C8B4 8002C0B4 0A008228 */  slti       $v0, $a0, 0xA
    /* 1C8B8 8002C0B8 11004014 */  bnez       $v0, .L8002C100
    /* 1C8BC 8002C0BC 21308000 */   addu      $a2, $a0, $zero
    /* 1C8C0 8002C0C0 6666023C */  lui        $v0, (0x66666667 >> 16)
    /* 1C8C4 8002C0C4 67664234 */  ori        $v0, $v0, (0x66666667 & 0xFFFF)
    /* 1C8C8 8002C0C8 18008200 */  mult       $a0, $v0
    /* 1C8CC 8002C0CC C3170500 */  sra        $v0, $a1, 31
    /* 1C8D0 8002C0D0 10600000 */  mfhi       $t4
    /* 1C8D4 8002C0D4 83180C00 */  sra        $v1, $t4, 2
    /* 1C8D8 8002C0D8 23186200 */  subu       $v1, $v1, $v0
    /* 1C8DC 8002C0DC 80100300 */  sll        $v0, $v1, 2
    /* 1C8E0 8002C0E0 21104300 */  addu       $v0, $v0, $v1
    /* 1C8E4 8002C0E4 40100200 */  sll        $v0, $v0, 1
    /* 1C8E8 8002C0E8 23108200 */  subu       $v0, $a0, $v0
    /* 1C8EC 8002C0EC C0180200 */  sll        $v1, $v0, 3
    /* 1C8F0 8002C0F0 23186200 */  subu       $v1, $v1, $v0
    /* 1C8F4 8002C0F4 40180300 */  sll        $v1, $v1, 1
    /* 1C8F8 8002C0F8 4FB00008 */  j          .L8002C13C
    /* 1C8FC 8002C0FC AE006524 */   addiu     $a1, $v1, 0xAE
  .L8002C100:
    /* 1C900 8002C100 6666023C */  lui        $v0, (0x66666667 >> 16)
    /* 1C904 8002C104 67664234 */  ori        $v0, $v0, (0x66666667 & 0xFFFF)
    /* 1C908 8002C108 1800C200 */  mult       $a2, $v0
    /* 1C90C 8002C10C C3170500 */  sra        $v0, $a1, 31
    /* 1C910 8002C110 10600000 */  mfhi       $t4
    /* 1C914 8002C114 83180C00 */  sra        $v1, $t4, 2
    /* 1C918 8002C118 23186200 */  subu       $v1, $v1, $v0
    /* 1C91C 8002C11C 80100300 */  sll        $v0, $v1, 2
    /* 1C920 8002C120 21104300 */  addu       $v0, $v0, $v1
    /* 1C924 8002C124 40100200 */  sll        $v0, $v0, 1
    /* 1C928 8002C128 2310C200 */  subu       $v0, $a2, $v0
    /* 1C92C 8002C12C C0180200 */  sll        $v1, $v0, 3
    /* 1C930 8002C130 23186200 */  subu       $v1, $v1, $v0
    /* 1C934 8002C134 40180300 */  sll        $v1, $v1, 1
    /* 1C938 8002C138 0E006524 */  addiu      $a1, $v1, 0xE
  .L8002C13C:
    /* 1C93C 8002C13C 6666033C */  lui        $v1, (0x66666667 >> 16)
    /* 1C940 8002C140 51038293 */  lbu        $v0, %gp_rel(D_8009B259)($gp)
    /* 1C944 8002C144 67666334 */  ori        $v1, $v1, (0x66666667 & 0xFFFF)
    /* 1C948 8002C148 00160200 */  sll        $v0, $v0, 24
    /* 1C94C 8002C14C 03360200 */  sra        $a2, $v0, 24
    /* 1C950 8002C150 1800C300 */  mult       $a2, $v1
    /* 1C954 8002C154 2120A002 */  addu       $a0, $s5, $zero
    /* 1C958 8002C158 1200A5A6 */  sh         $a1, 0x12($s5)
    /* 1C95C 8002C15C 0800A5A6 */  sh         $a1, 0x8($s5)
    /* 1C960 8002C160 C3170200 */  sra        $v0, $v0, 31
    /* 1C964 8002C164 10600000 */  mfhi       $t4
    /* 1C968 8002C168 83280C00 */  sra        $a1, $t4, 2
    /* 1C96C 8002C16C 2328A200 */  subu       $a1, $a1, $v0
    /* 1C970 8002C170 40100500 */  sll        $v0, $a1, 1
    /* 1C974 8002C174 21104500 */  addu       $v0, $v0, $a1
    /* 1C978 8002C178 80100200 */  sll        $v0, $v0, 2
    /* 1C97C 8002C17C 23104500 */  subu       $v0, $v0, $a1
    /* 1C980 8002C180 C0100200 */  sll        $v0, $v0, 3
    /* 1C984 8002C184 21104500 */  addu       $v0, $v0, $a1
    /* 1C988 8002C188 40100200 */  sll        $v0, $v0, 1
    /* 1C98C 8002C18C 80180500 */  sll        $v1, $a1, 2
    /* 1C990 8002C190 21186500 */  addu       $v1, $v1, $a1
    /* 1C994 8002C194 40180300 */  sll        $v1, $v1, 1
    /* 1C998 8002C198 2330C300 */  subu       $a2, $a2, $v1
    /* 1C99C 8002C19C 00310600 */  sll        $a2, $a2, 4
    /* 1C9A0 8002C1A0 21104600 */  addu       $v0, $v0, $a2
    /* 1C9A4 8002C1A4 0E004224 */  addiu      $v0, $v0, 0xE
    /* 1C9A8 8002C1A8 1400A2A6 */  sh         $v0, 0x14($s5)
    /* 1C9AC 8002C1AC 98A9000C */  jal        func_8002A660
    /* 1C9B0 8002C1B0 0A00A2A6 */   sh        $v0, 0xA($s5)
    /* 1C9B4 8002C1B4 0B00010C */  jal        func_8004002C
    /* 1C9B8 8002C1B8 02001024 */   addiu     $s0, $zero, 0x2
    /* 1C9BC 8002C1BC 21204000 */  addu       $a0, $v0, $zero
    /* 1C9C0 8002C1C0 2B00010C */  jal        func_800400AC
    /* 1C9C4 8002C1C4 02000524 */   addiu     $a1, $zero, 0x2
    /* 1C9C8 8002C1C8 21A04000 */  addu       $s4, $v0, $zero
    /* 1C9CC 8002C1CC 21208002 */  addu       $a0, $s4, $zero
    /* 1C9D0 8002C1D0 10000524 */  addiu      $a1, $zero, 0x10
    /* 1C9D4 8002C1D4 D8000624 */  addiu      $a2, $zero, 0xD8
    /* 1C9D8 8002C1D8 21380000 */  addu       $a3, $zero, $zero
    /* 1C9DC 8002C1DC 01000224 */  addiu      $v0, $zero, 0x1
    /* 1C9E0 8002C1E0 1B001124 */  addiu      $s1, $zero, 0x1B
    /* 1C9E4 8002C1E4 1400A2AF */  sw         $v0, 0x14($sp)
    /* 1C9E8 8002C1E8 27010224 */  addiu      $v0, $zero, 0x127
    /* 1C9EC 8002C1EC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C9F0 8002C1F0 1800B1AF */  sw         $s1, 0x18($sp)
    /* 1C9F4 8002C1F4 3301010C */  jal        func_800404CC
    /* 1C9F8 8002C1F8 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 1C9FC 8002C1FC 21208002 */  addu       $a0, $s4, $zero
    /* 1CA00 8002C200 80001224 */  addiu      $s2, $zero, 0x80
    /* 1CA04 8002C204 460A010C */  jal        func_80042918
    /* 1CA08 8002C208 5F0092A2 */   sb        $s2, 0x5F($s4)
    /* 1CA0C 8002C20C 08008296 */  lhu        $v0, 0x8($s4)
    /* 1CA10 8002C210 01001324 */  addiu      $s3, $zero, 0x1
    /* 1CA14 8002C214 08004234 */  ori        $v0, $v0, 0x8
    /* 1CA18 8002C218 080082A6 */  sh         $v0, 0x8($s4)
    /* 1CA1C 8002C21C 0B00010C */  jal        func_8004002C
    /* 1CA20 8002C220 4800B4AE */   sw        $s4, 0x48($s5)
    /* 1CA24 8002C224 21204000 */  addu       $a0, $v0, $zero
    /* 1CA28 8002C228 2B00010C */  jal        func_800400AC
    /* 1CA2C 8002C22C 21280002 */   addu      $a1, $s0, $zero
    /* 1CA30 8002C230 21A04000 */  addu       $s4, $v0, $zero
    /* 1CA34 8002C234 21208002 */  addu       $a0, $s4, $zero
    /* 1CA38 8002C238 47010224 */  addiu      $v0, $zero, 0x147
    /* 1CA3C 8002C23C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1CA40 8002C240 1400B0AF */  sw         $s0, 0x14($sp)
    /* 1CA44 8002C244 1800B1AF */  sw         $s1, 0x18($sp)
    /* 1CA48 8002C248 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 1CA4C 8002C24C 0800A586 */  lh         $a1, 0x8($s5)
    /* 1CA50 8002C250 0A00A686 */  lh         $a2, 0xA($s5)
    /* 1CA54 8002C254 3301010C */  jal        func_800404CC
    /* 1CA58 8002C258 21380000 */   addu      $a3, $zero, $zero
    /* 1CA5C 8002C25C 1D80023C */  lui        $v0, %hi(D_801D4244)
    /* 1CA60 8002C260 44424B24 */  addiu      $t3, $v0, %lo(D_801D4244)
    /* 1CA64 8002C264 15000A24 */  addiu      $t2, $zero, 0x15
    /* 1CA68 8002C268 14000924 */  addiu      $t1, $zero, 0x14
    /* 1CA6C 8002C26C 16000824 */  addiu      $t0, $zero, 0x16
    /* 1CA70 8002C270 17000724 */  addiu      $a3, $zero, 0x17
    /* 1CA74 8002C274 70010624 */  addiu      $a2, $zero, 0x170
    /* 1CA78 8002C278 0400A426 */  addiu      $a0, $s5, 0x4
    /* 1CA7C 8002C27C 21280000 */  addu       $a1, $zero, $zero
    /* 1CA80 8002C280 5F0092A2 */  sb         $s2, 0x5F($s4)
    /* 1CA84 8002C284 4400B4AE */  sw         $s4, 0x44($s5)
    /* 1CA88 8002C288 5600A0A2 */  sb         $zero, 0x56($s5)
    /* 1CA8C 8002C28C 5400A0A6 */  sh         $zero, 0x54($s5)
  .L8002C290:
    /* 1CA90 8002C290 2110AB00 */  addu       $v0, $a1, $t3
    /* 1CA94 8002C294 560080A0 */  sb         $zero, 0x56($a0)
    /* 1CA98 8002C298 5400A0A6 */  sh         $zero, 0x54($s5)
    /* 1CA9C 8002C29C 0000428C */  lw         $v0, 0x0($v0)
    /* 1CAA0 8002C2A0 00000000 */  nop
    /* 1CAA4 8002C2A4 83160200 */  sra        $v0, $v0, 26
    /* 1CAA8 8002C2A8 1F004330 */  andi       $v1, $v0, 0x1F
    /* 1CAAC 8002C2AC 0D006A10 */  beq        $v1, $t2, .L8002C2E4
    /* 1CAB0 8002C2B0 16006228 */   slti      $v0, $v1, 0x16
    /* 1CAB4 8002C2B4 05004010 */  beqz       $v0, .L8002C2CC
    /* 1CAB8 8002C2B8 00000000 */   nop
    /* 1CABC 8002C2BC 07006910 */  beq        $v1, $t1, .L8002C2DC
    /* 1CAC0 8002C2C0 60010224 */   addiu     $v0, $zero, 0x160
    /* 1CAC4 8002C2C4 BBB00008 */  j          .L8002C2EC
    /* 1CAC8 8002C2C8 540082A4 */   sh        $v0, 0x54($a0)
  .L8002C2CC:
    /* 1CACC 8002C2CC 06006810 */  beq        $v1, $t0, .L8002C2E8
    /* 1CAD0 8002C2D0 90010224 */   addiu     $v0, $zero, 0x190
    /* 1CAD4 8002C2D4 04006714 */  bne        $v1, $a3, .L8002C2E8
    /* 1CAD8 8002C2D8 60010224 */   addiu     $v0, $zero, 0x160
  .L8002C2DC:
    /* 1CADC 8002C2DC BBB00008 */  j          .L8002C2EC
    /* 1CAE0 8002C2E0 540086A4 */   sh        $a2, 0x54($a0)
  .L8002C2E4:
    /* 1CAE4 8002C2E4 80010224 */  addiu      $v0, $zero, 0x180
  .L8002C2E8:
    /* 1CAE8 8002C2E8 540082A4 */  sh         $v0, 0x54($a0)
  .L8002C2EC:
    /* 1CAEC 8002C2EC 04008424 */  addiu      $a0, $a0, 0x4
    /* 1CAF0 8002C2F0 01007326 */  addiu      $s3, $s3, 0x1
    /* 1CAF4 8002C2F4 D302622A */  slti       $v0, $s3, 0x2D3
    /* 1CAF8 8002C2F8 E5FF4014 */  bnez       $v0, .L8002C290
    /* 1CAFC 8002C2FC 0400A524 */   addiu     $a1, $a1, 0x4
    /* 1CB00 8002C300 1D80023C */  lui        $v0, %hi(D_801D5608)
    /* 1CB04 8002C304 085640AC */  sw         $zero, %lo(D_801D5608)($v0)
    /* 1CB08 8002C308 01001324 */  addiu      $s3, $zero, 0x1
    /* 1CB0C 8002C30C 21884000 */  addu       $s1, $v0, $zero
    /* 1CB10 8002C310 80001224 */  addiu      $s2, $zero, 0x80
    /* 1CB14 8002C314 0400B026 */  addiu      $s0, $s5, 0x4
  .L8002C318:
    /* 1CB18 8002C318 2AB3000C */  jal        func_8002CCA8
    /* 1CB1C 8002C31C 20016426 */   addiu     $a0, $s3, 0x120
    /* 1CB20 8002C320 0D004010 */  beqz       $v0, .L8002C358
    /* 1CB24 8002C324 21206002 */   addu      $a0, $s3, $zero
    /* 1CB28 8002C328 0856228E */  lw         $v0, %lo(D_801D5608)($s1)
    /* 1CB2C 8002C32C 00000000 */  nop
    /* 1CB30 8002C330 01004224 */  addiu      $v0, $v0, 0x1
    /* 1CB34 8002C334 085622AE */  sw         $v0, %lo(D_801D5608)($s1)
    /* 1CB38 8002C338 46B1000C */  jal        func_8002C518
    /* 1CB3C 8002C33C 560012A2 */   sb        $s2, 0x56($s0)
    /* 1CB40 8002C340 05004104 */  bgez       $v0, .L8002C358
    /* 1CB44 8002C344 00000000 */   nop
    /* 1CB48 8002C348 56000292 */  lbu        $v0, 0x56($s0)
    /* 1CB4C 8002C34C 00000000 */  nop
    /* 1CB50 8002C350 01004234 */  ori        $v0, $v0, 0x1
    /* 1CB54 8002C354 560002A2 */  sb         $v0, 0x56($s0)
  .L8002C358:
    /* 1CB58 8002C358 01007326 */  addiu      $s3, $s3, 0x1
    /* 1CB5C 8002C35C D302622A */  slti       $v0, $s3, 0x2D3
    /* 1CB60 8002C360 EDFF4014 */  bnez       $v0, .L8002C318
    /* 1CB64 8002C364 04001026 */   addiu     $s0, $s0, 0x4
    /* 1CB68 8002C368 03000424 */  addiu      $a0, $zero, 0x3
    /* 1CB6C 8002C36C ABED000C */  jal        func_8003B6AC
    /* 1CB70 8002C370 01000524 */   addiu     $a1, $zero, 0x1
    /* 1CB74 8002C374 03000424 */  addiu      $a0, $zero, 0x3
    /* 1CB78 8002C378 F8000524 */  addiu      $a1, $zero, 0xF8
    /* 1CB7C 8002C37C 58000624 */  addiu      $a2, $zero, 0x58
    /* 1CB80 8002C380 E8FF0724 */  addiu      $a3, $zero, -0x18
    /* 1CB84 8002C384 90000224 */  addiu      $v0, $zero, 0x90
    /* 1CB88 8002C388 10001124 */  addiu      $s1, $zero, 0x10
    /* 1CB8C 8002C38C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1CB90 8002C390 F9D6000C */  jal        func_80035BE4
    /* 1CB94 8002C394 1400B1AF */   sw        $s1, 0x14($sp)
    /* 1CB98 8002C398 21804000 */  addu       $s0, $v0, $zero
    /* 1CB9C 8002C39C 21200002 */  addu       $a0, $s0, $zero
    /* 1CBA0 8002C3A0 5A0011A2 */  sb         $s1, 0x5A($s0)
    /* 1CBA4 8002C3A4 85E6000C */  jal        func_80039A14
    /* 1CBA8 8002C3A8 5B0011A2 */   sb        $s1, 0x5B($s0)
    /* 1CBAC 8002C3AC 2800048E */  lw         $a0, 0x28($s0)
    /* 1CBB0 8002C3B0 4F0A010C */  jal        func_8004293C
    /* 1CBB4 8002C3B4 00000000 */   nop
    /* 1CBB8 8002C3B8 2800038E */  lw         $v1, 0x28($s0)
    /* 1CBBC 8002C3BC 00000000 */  nop
    /* 1CBC0 8002C3C0 08006294 */  lhu        $v0, 0x8($v1)
    /* 1CBC4 8002C3C4 2120A002 */  addu       $a0, $s5, $zero
    /* 1CBC8 8002C3C8 F7FF4230 */  andi       $v0, $v0, 0xFFF7
    /* 1CBCC 8002C3CC BDA8000C */  jal        func_8002A2F4
    /* 1CBD0 8002C3D0 080062A4 */   sh        $v0, 0x8($v1)
    /* 1CBD4 8002C3D4 C2FF000C */  jal        func_8003FF08
    /* 1CBD8 8002C3D8 D0720424 */   addiu     $a0, $zero, 0x72D0
    /* 1CBDC 8002C3DC 3800BF8F */  lw         $ra, 0x38($sp)
    /* 1CBE0 8002C3E0 3400B58F */  lw         $s5, 0x34($sp)
    /* 1CBE4 8002C3E4 3000B48F */  lw         $s4, 0x30($sp)
    /* 1CBE8 8002C3E8 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 1CBEC 8002C3EC 2800B28F */  lw         $s2, 0x28($sp)
    /* 1CBF0 8002C3F0 2400B18F */  lw         $s1, 0x24($sp)
    /* 1CBF4 8002C3F4 2000B08F */  lw         $s0, 0x20($sp)
    /* 1CBF8 8002C3F8 0800E003 */  jr         $ra
    /* 1CBFC 8002C3FC 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8002BFCC
