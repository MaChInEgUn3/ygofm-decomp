nonmatching func_8001D3C4, 0x154

glabel func_8001D3C4
    /* DBC4 8001D3C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DBC8 8001D3C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* DBCC 8001D3CC 1400BFAF */  sw         $ra, 0x14($sp)
    /* DBD0 8001D3D0 E60A010C */  jal        func_80042B98
    /* DBD4 8001D3D4 21808000 */   addu      $s0, $a0, $zero
    /* DBD8 8001D3D8 0F004014 */  bnez       $v0, .L8001D418
    /* DBDC 8001D3DC 00000000 */   nop
    /* DBE0 8001D3E0 2C000386 */  lh         $v1, 0x2C($s0)
    /* DBE4 8001D3E4 21000292 */  lbu        $v0, 0x21($s0)
    /* DBE8 8001D3E8 00000000 */  nop
    /* DBEC 8001D3EC 05006210 */  beq        $v1, $v0, .L8001D404
    /* DBF0 8001D3F0 00000000 */   nop
    /* DBF4 8001D3F4 08000296 */  lhu        $v0, 0x8($s0)
    /* DBF8 8001D3F8 00000000 */  nop
    /* DBFC 8001D3FC 04004234 */  ori        $v0, $v0, 0x4
    /* DC00 8001D400 080002A6 */  sh         $v0, 0x8($s0)
  .L8001D404:
    /* DC04 8001D404 60000296 */  lhu        $v0, 0x60($s0)
    /* DC08 8001D408 21200002 */  addu       $a0, $s0, $zero
    /* DC0C 8001D40C 5E0C010C */  jal        func_80043178
    /* DC10 8001D410 2E0002A6 */   sh        $v0, 0x2E($s0)
    /* DC14 8001D414 600000A6 */  sh         $zero, 0x60($s0)
  .L8001D418:
    /* DC18 8001D418 21000492 */  lbu        $a0, 0x21($s0)
    /* DC1C 8001D41C 2C000286 */  lh         $v0, 0x2C($s0)
    /* DC20 8001D420 00000000 */  nop
    /* DC24 8001D424 11008210 */  beq        $a0, $v0, .L8001D46C
    /* DC28 8001D428 80000224 */   addiu     $v0, $zero, 0x80
    /* DC2C 8001D42C 2E000386 */  lh         $v1, 0x2E($s0)
    /* DC30 8001D430 00000000 */  nop
    /* DC34 8001D434 1A004300 */  div        $zero, $v0, $v1
    /* DC38 8001D438 02006014 */  bnez       $v1, .L8001D444
    /* DC3C 8001D43C 00000000 */   nop
    /* DC40 8001D440 0D000700 */  break      7
  .L8001D444:
    /* DC44 8001D444 FFFF0124 */  addiu      $at, $zero, -0x1
    /* DC48 8001D448 04006114 */  bne        $v1, $at, .L8001D45C
    /* DC4C 8001D44C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* DC50 8001D450 02004114 */  bne        $v0, $at, .L8001D45C
    /* DC54 8001D454 00000000 */   nop
    /* DC58 8001D458 0D000600 */  break      6
  .L8001D45C:
    /* DC5C 8001D45C 12100000 */  mflo       $v0
    /* DC60 8001D460 00000000 */  nop
    /* DC64 8001D464 21108200 */  addu       $v0, $a0, $v0
    /* DC68 8001D468 210002A2 */  sb         $v0, 0x21($s0)
  .L8001D46C:
    /* DC6C 8001D46C 28000586 */  lh         $a1, 0x28($s0)
    /* DC70 8001D470 2A000686 */  lh         $a2, 0x2A($s0)
    /* DC74 8001D474 60000786 */  lh         $a3, 0x60($s0)
    /* DC78 8001D478 630C010C */  jal        func_8004318C
    /* DC7C 8001D47C 21200002 */   addu      $a0, $s0, $zero
    /* DC80 8001D480 2E000286 */  lh         $v0, 0x2E($s0)
    /* DC84 8001D484 00080324 */  addiu      $v1, $zero, 0x800
    /* DC88 8001D488 1A006200 */  div        $zero, $v1, $v0
    /* DC8C 8001D48C 02004014 */  bnez       $v0, .L8001D498
    /* DC90 8001D490 00000000 */   nop
    /* DC94 8001D494 0D000700 */  break      7
  .L8001D498:
    /* DC98 8001D498 FFFF0124 */  addiu      $at, $zero, -0x1
    /* DC9C 8001D49C 04004114 */  bne        $v0, $at, .L8001D4B0
    /* DCA0 8001D4A0 0080013C */   lui       $at, (0x80000000 >> 16)
    /* DCA4 8001D4A4 02006114 */  bne        $v1, $at, .L8001D4B0
    /* DCA8 8001D4A8 00000000 */   nop
    /* DCAC 8001D4AC 0D000600 */  break      6
  .L8001D4B0:
    /* DCB0 8001D4B0 12180000 */  mflo       $v1
    /* DCB4 8001D4B4 60000296 */  lhu        $v0, 0x60($s0)
    /* DCB8 8001D4B8 00000000 */  nop
    /* DCBC 8001D4BC 21104300 */  addu       $v0, $v0, $v1
    /* DCC0 8001D4C0 600002A6 */  sh         $v0, 0x60($s0)
    /* DCC4 8001D4C4 00140200 */  sll        $v0, $v0, 16
    /* DCC8 8001D4C8 03140200 */  sra        $v0, $v0, 16
    /* DCCC 8001D4CC 00084228 */  slti       $v0, $v0, 0x800
    /* DCD0 8001D4D0 0D004014 */  bnez       $v0, .L8001D508
    /* DCD4 8001D4D4 00000000 */   nop
    /* DCD8 8001D4D8 2C000292 */  lbu        $v0, 0x2C($s0)
    /* DCDC 8001D4DC 2800038E */  lw         $v1, 0x28($s0)
    /* DCE0 8001D4E0 210002A2 */  sb         $v0, 0x21($s0)
    /* DCE4 8001D4E4 FF004230 */  andi       $v0, $v0, 0xFF
    /* DCE8 8001D4E8 05004014 */  bnez       $v0, .L8001D500
    /* DCEC 8001D4EC 300003AE */   sw        $v1, 0x30($s0)
    /* DCF0 8001D4F0 08000296 */  lhu        $v0, 0x8($s0)
    /* DCF4 8001D4F4 00000000 */  nop
    /* DCF8 8001D4F8 FBFF4230 */  andi       $v0, $v0, 0xFFFB
    /* DCFC 8001D4FC 080002A6 */  sh         $v0, 0x8($s0)
  .L8001D500:
    /* DD00 8001D500 6C0000A2 */  sb         $zero, 0x6C($s0)
    /* DD04 8001D504 240000AE */  sw         $zero, 0x24($s0)
  .L8001D508:
    /* DD08 8001D508 1400BF8F */  lw         $ra, 0x14($sp)
    /* DD0C 8001D50C 1000B08F */  lw         $s0, 0x10($sp)
    /* DD10 8001D510 0800E003 */  jr         $ra
    /* DD14 8001D514 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001D3C4
