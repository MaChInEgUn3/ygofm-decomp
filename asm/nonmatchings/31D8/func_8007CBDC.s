nonmatching func_8007CBDC, 0xB0

glabel func_8007CBDC
    /* 6D3DC 8007CBDC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6D3E0 8007CBE0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6D3E4 8007CBE4 FF008430 */  andi       $a0, $a0, 0xFF
    /* 6D3E8 8007CBE8 05000224 */  addiu      $v0, $zero, 0x5
    /* 6D3EC 8007CBEC 0E008210 */  beq        $a0, $v0, .L8007CC28
    /* 6D3F0 8007CBF0 2130A000 */   addu      $a2, $a1, $zero
    /* 6D3F4 8007CBF4 0980023C */  lui        $v0, %hi(D_80093884)
    /* 6D3F8 8007CBF8 84384290 */  lbu        $v0, %lo(D_80093884)($v0)
    /* 6D3FC 8007CBFC 00000000 */  nop
    /* 6D400 8007CC00 80100200 */  sll        $v0, $v0, 2
    /* 6D404 8007CC04 0980013C */  lui        $at, %hi(D_80093954)
    /* 6D408 8007CC08 21082200 */  addu       $at, $at, $v0
    /* 6D40C 8007CC0C 5439228C */  lw         $v0, %lo(D_80093954)($at)
    /* 6D410 8007CC10 00000000 */  nop
    /* 6D414 8007CC14 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 6D418 8007CC18 18004004 */  bltz       $v0, .L8007CC7C
    /* 6D41C 8007CC1C 2110C200 */   addu      $v0, $a2, $v0
    /* 6D420 8007CC20 0CF30108 */  j          .L8007CC30
    /* 6D424 8007CC24 00000000 */   nop
  .L8007CC28:
    /* 6D428 8007CC28 21100000 */  addu       $v0, $zero, $zero
    /* 6D42C 8007CC2C 2110C200 */  addu       $v0, $a2, $v0
  .L8007CC30:
    /* 6D430 8007CC30 00004590 */  lbu        $a1, 0x0($v0)
    /* 6D434 8007CC34 0980043C */  lui        $a0, %hi(D_800938B4)
    /* 6D438 8007CC38 B4388424 */  addiu      $a0, $a0, %lo(D_800938B4)
    /* 6D43C 8007CC3C FF00A330 */  andi       $v1, $a1, 0xFF
    /* 6D440 8007CC40 C2110300 */  srl        $v0, $v1, 7
    /* 6D444 8007CC44 000082A0 */  sb         $v0, 0x0($a0)
    /* 6D448 8007CC48 82110300 */  srl        $v0, $v1, 6
    /* 6D44C 8007CC4C 01004230 */  andi       $v0, $v0, 0x1
    /* 6D450 8007CC50 010082A0 */  sb         $v0, 0x1($a0)
    /* 6D454 8007CC54 42110300 */  srl        $v0, $v1, 5
    /* 6D458 8007CC58 01004230 */  andi       $v0, $v0, 0x1
    /* 6D45C 8007CC5C 42180300 */  srl        $v1, $v1, 1
    /* 6D460 8007CC60 01006330 */  andi       $v1, $v1, 0x1
    /* 6D464 8007CC64 020082A0 */  sb         $v0, 0x2($a0)
    /* 6D468 8007CC68 030083A0 */  sb         $v1, 0x3($a0)
    /* 6D46C 8007CC6C E4FF85A0 */  sb         $a1, -0x1C($a0)
    /* 6D470 8007CC70 DCFF8424 */  addiu      $a0, $a0, -0x24
    /* 6D474 8007CC74 5BF3010C */  jal        func_8007CD6C
    /* 6D478 8007CC78 2128C000 */   addu      $a1, $a2, $zero
  .L8007CC7C:
    /* 6D47C 8007CC7C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6D480 8007CC80 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6D484 8007CC84 0800E003 */  jr         $ra
    /* 6D488 8007CC88 00000000 */   nop
endlabel func_8007CBDC
