nonmatching func_8001B938, 0x1B8

glabel func_8001B938
    /* C138 8001B938 CD028293 */  lbu        $v0, %gp_rel(D_8009B1D5)($gp)
    /* C13C 8001B93C 00000000 */  nop
    /* C140 8001B940 C0180200 */  sll        $v1, $v0, 3
    /* C144 8001B944 23186200 */  subu       $v1, $v1, $v0
    /* C148 8001B948 00190300 */  sll        $v1, $v1, 4
    /* C14C 8001B94C 0F80023C */  lui        $v0, %hi(D_800E9F48)
    /* C150 8001B950 489F4224 */  addiu      $v0, $v0, %lo(D_800E9F48)
    /* C154 8001B954 21186200 */  addu       $v1, $v1, $v0
    /* C158 8001B958 AC0283AF */  sw         $v1, %gp_rel(D_8009B1B4)($gp)
    /* C15C 8001B95C 190060A0 */  sb         $zero, 0x19($v1)
    /* C160 8001B960 AC02838F */  lw         $v1, %gp_rel(D_8009B1B4)($gp)
    /* C164 8001B964 01000224 */  addiu      $v0, $zero, 0x1
    /* C168 8001B968 130062A0 */  sb         $v0, 0x13($v1)
    /* C16C 8001B96C AC02838F */  lw         $v1, %gp_rel(D_8009B1B4)($gp)
    /* C170 8001B970 74000224 */  addiu      $v0, $zero, 0x74
    /* C174 8001B974 0C0062A4 */  sh         $v0, 0xC($v1)
    /* C178 8001B978 180060A0 */  sb         $zero, 0x18($v1)
    /* C17C 8001B97C AC02838F */  lw         $v1, %gp_rel(D_8009B1B4)($gp)
    /* C180 8001B980 02000224 */  addiu      $v0, $zero, 0x2
    /* C184 8001B984 110062A0 */  sb         $v0, 0x11($v1)
    /* C188 8001B988 AC02828F */  lw         $v0, %gp_rel(D_8009B1B4)($gp)
    /* C18C 8001B98C 03000724 */  addiu      $a3, $zero, 0x3
    /* C190 8001B990 120047A0 */  sb         $a3, 0x12($v0)
    /* C194 8001B994 15008290 */  lbu        $v0, 0x15($a0)
    /* C198 8001B998 00000000 */  nop
    /* C19C 8001B99C 2C004014 */  bnez       $v0, .L8001BA50
    /* C1A0 8001B9A0 0400053C */   lui       $a1, (0x48000 >> 16)
    /* C1A4 8001B9A4 0080A534 */  ori        $a1, $a1, (0x48000 & 0xFFFF)
    /* C1A8 8001B9A8 0F80033C */  lui        $v1, %hi(D_800EA030)
    /* C1AC 8001B9AC 0E008480 */  lb         $a0, 0xE($a0)
    /* C1B0 8001B9B0 30A06324 */  addiu      $v1, $v1, %lo(D_800EA030)
    /* C1B4 8001B9B4 40100400 */  sll        $v0, $a0, 1
    /* C1B8 8001B9B8 21104400 */  addu       $v0, $v0, $a0
    /* C1BC 8001B9BC 80100200 */  sll        $v0, $v0, 2
    /* C1C0 8001B9C0 21104300 */  addu       $v0, $v0, $v1
    /* C1C4 8001B9C4 0000468C */  lw         $a2, 0x0($v0)
    /* C1C8 8001B9C8 1680033C */  lui        $v1, %hi(D_8015C424)
    /* C1CC 8001B9CC 6A00C490 */  lbu        $a0, 0x6A($a2)
    /* C1D0 8001B9D0 24C46324 */  addiu      $v1, $v1, %lo(D_8015C424)
    /* C1D4 8001B9D4 C0100400 */  sll        $v0, $a0, 3
    /* C1D8 8001B9D8 23104400 */  subu       $v0, $v0, $a0
    /* C1DC 8001B9DC 80100200 */  sll        $v0, $v0, 2
    /* C1E0 8001B9E0 21104300 */  addu       $v0, $v0, $v1
    /* C1E4 8001B9E4 21104500 */  addu       $v0, $v0, $a1
    /* C1E8 8001B9E8 B836428C */  lw         $v0, 0x36B8($v0)
    /* C1EC 8001B9EC 1D80033C */  lui        $v1, %hi(D_801D4244)
    /* C1F0 8001B9F0 00004284 */  lh         $v0, 0x0($v0)
    /* C1F4 8001B9F4 44426324 */  addiu      $v1, $v1, %lo(D_801D4244)
    /* C1F8 8001B9F8 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* C1FC 8001B9FC 80100200 */  sll        $v0, $v0, 2
    /* C200 8001BA00 21104300 */  addu       $v0, $v0, $v1
    /* C204 8001BA04 0000428C */  lw         $v0, 0x0($v0)
    /* C208 8001BA08 00000000 */  nop
    /* C20C 8001BA0C 83160200 */  sra        $v0, $v0, 26
    /* C210 8001BA10 1F004430 */  andi       $a0, $v0, 0x1F
    /* C214 8001BA14 14008228 */  slti       $v0, $a0, 0x14
    /* C218 8001BA18 0D004014 */  bnez       $v0, .L8001BA50
    /* C21C 8001BA1C 00000000 */   nop
    /* C220 8001BA20 2100C290 */  lbu        $v0, 0x21($a2)
    /* C224 8001BA24 00000000 */  nop
    /* C228 8001BA28 03004014 */  bnez       $v0, .L8001BA38
    /* C22C 8001BA2C 15000224 */   addiu     $v0, $zero, 0x15
    /* C230 8001BA30 07008214 */  bne        $a0, $v0, .L8001BA50
    /* C234 8001BA34 00000000 */   nop
  .L8001BA38:
    /* C238 8001BA38 AC02828F */  lw         $v0, %gp_rel(D_8009B1B4)($gp)
    /* C23C 8001BA3C 00000000 */  nop
    /* C240 8001BA40 110047A0 */  sb         $a3, 0x11($v0)
    /* C244 8001BA44 AC02838F */  lw         $v1, %gp_rel(D_8009B1B4)($gp)
    /* C248 8001BA48 04000224 */  addiu      $v0, $zero, 0x4
    /* C24C 8001BA4C 120062A0 */  sb         $v0, 0x12($v1)
  .L8001BA50:
    /* C250 8001BA50 AC02838F */  lw         $v1, %gp_rel(D_8009B1B4)($gp)
    /* C254 8001BA54 00000000 */  nop
    /* C258 8001BA58 11006290 */  lbu        $v0, 0x11($v1)
    /* C25C 8001BA5C 0980053C */  lui        $a1, %hi(D_800907D8)
    /* C260 8001BA60 100062A0 */  sb         $v0, 0x10($v1)
    /* C264 8001BA64 AC02828F */  lw         $v0, %gp_rel(D_8009B1B4)($gp)
    /* C268 8001BA68 D807A524 */  addiu      $a1, $a1, %lo(D_800907D8)
    /* C26C 8001BA6C 10004280 */  lb         $v0, 0x10($v0)
    /* C270 8001BA70 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* C274 8001BA74 80180200 */  sll        $v1, $v0, 2
    /* C278 8001BA78 21186200 */  addu       $v1, $v1, $v0
    /* C27C 8001BA7C 80100400 */  sll        $v0, $a0, 2
    /* C280 8001BA80 21104400 */  addu       $v0, $v0, $a0
    /* C284 8001BA84 80100200 */  sll        $v0, $v0, 2
    /* C288 8001BA88 21186200 */  addu       $v1, $v1, $v0
    /* C28C 8001BA8C 21186500 */  addu       $v1, $v1, $a1
    /* C290 8001BA90 00006290 */  lbu        $v0, 0x0($v1)
    /* C294 8001BA94 21200000 */  addu       $a0, $zero, $zero
    /* C298 8001BA98 C0180200 */  sll        $v1, $v0, 3
    /* C29C 8001BA9C 23186200 */  subu       $v1, $v1, $v0
    /* C2A0 8001BAA0 80180300 */  sll        $v1, $v1, 2
    /* C2A4 8001BAA4 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* C2A8 8001BAA8 D87A4224 */  addiu      $v0, $v0, %lo(D_801A7AD8)
    /* C2AC 8001BAAC 21186200 */  addu       $v1, $v1, $v0
  .L8001BAB0:
    /* C2B0 8001BAB0 16006294 */  lhu        $v0, 0x16($v1)
    /* C2B4 8001BAB4 00000000 */  nop
    /* C2B8 8001BAB8 00804230 */  andi       $v0, $v0, 0x8000
    /* C2BC 8001BABC 04004014 */  bnez       $v0, .L8001BAD0
    /* C2C0 8001BAC0 00000000 */   nop
    /* C2C4 8001BAC4 AC02828F */  lw         $v0, %gp_rel(D_8009B1B4)($gp)
    /* C2C8 8001BAC8 B86E0008 */  j          .L8001BAE0
    /* C2CC 8001BACC 0F0044A0 */   sb        $a0, 0xF($v0)
  .L8001BAD0:
    /* C2D0 8001BAD0 01008424 */  addiu      $a0, $a0, 0x1
    /* C2D4 8001BAD4 05008228 */  slti       $v0, $a0, 0x5
    /* C2D8 8001BAD8 F5FF4014 */  bnez       $v0, .L8001BAB0
    /* C2DC 8001BADC 1C006324 */   addiu     $v1, $v1, 0x1C
  .L8001BAE0:
    /* C2E0 8001BAE0 03000224 */  addiu      $v0, $zero, 0x3
    /* C2E4 8001BAE4 5A0282A7 */  sh         $v0, %gp_rel(D_8009B162)($gp)
    /* C2E8 8001BAE8 0800E003 */  jr         $ra
    /* C2EC 8001BAEC 00000000 */   nop
endlabel func_8001B938
