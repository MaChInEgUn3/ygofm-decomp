nonmatching func_8001BAF0, 0x258

glabel func_8001BAF0
    /* C2F0 8001BAF0 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* C2F4 8001BAF4 21200000 */  addu       $a0, $zero, $zero
    /* C2F8 8001BAF8 1000A527 */  addiu      $a1, $sp, 0x10
    /* C2FC 8001BAFC 4400BFAF */  sw         $ra, 0x44($sp)
    /* C300 8001BB00 4000BEAF */  sw         $fp, 0x40($sp)
    /* C304 8001BB04 3C00B7AF */  sw         $s7, 0x3C($sp)
    /* C308 8001BB08 3800B6AF */  sw         $s6, 0x38($sp)
    /* C30C 8001BB0C 3400B5AF */  sw         $s5, 0x34($sp)
    /* C310 8001BB10 3000B4AF */  sw         $s4, 0x30($sp)
    /* C314 8001BB14 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* C318 8001BB18 2800B2AF */  sw         $s2, 0x28($sp)
    /* C31C 8001BB1C 2400B1AF */  sw         $s1, 0x24($sp)
    /* C320 8001BB20 2000B0AF */  sw         $s0, 0x20($sp)
  .L8001BB24:
    /* C324 8001BB24 C002828F */  lw         $v0, %gp_rel(D_8009B1C8)($gp)
    /* C328 8001BB28 2118A400 */  addu       $v1, $a1, $a0
    /* C32C 8001BB2C 21104400 */  addu       $v0, $v0, $a0
    /* C330 8001BB30 1A004290 */  lbu        $v0, 0x1A($v0)
    /* C334 8001BB34 01008424 */  addiu      $a0, $a0, 0x1
    /* C338 8001BB38 000062A0 */  sb         $v0, 0x0($v1)
    /* C33C 8001BB3C 05008228 */  slti       $v0, $a0, 0x5
    /* C340 8001BB40 F8FF4014 */  bnez       $v0, .L8001BB24
    /* C344 8001BB44 0F80023C */   lui       $v0, %hi(D_800EAE88)
    /* C348 8001BB48 21200000 */  addu       $a0, $zero, $zero
    /* C34C 8001BB4C 88AE4724 */  addiu      $a3, $v0, %lo(D_800EAE88)
    /* C350 8001BB50 1000A327 */  addiu      $v1, $sp, 0x10
    /* C354 8001BB54 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* C358 8001BB58 21108700 */  addu       $v0, $a0, $a3
  .L8001BB5C:
    /* C35C 8001BB5C 00004590 */  lbu        $a1, 0x0($v0)
    /* C360 8001BB60 00000000 */  nop
    /* C364 8001BB64 0800A010 */  beqz       $a1, .L8001BB88
    /* C368 8001BB68 1000A228 */   slti      $v0, $a1, 0x10
    /* C36C 8001BB6C 02004010 */  beqz       $v0, .L8001BB78
    /* C370 8001BB70 2110A300 */   addu      $v0, $a1, $v1
    /* C374 8001BB74 F5FF46A0 */  sb         $a2, -0xB($v0)
  .L8001BB78:
    /* C378 8001BB78 01008424 */  addiu      $a0, $a0, 0x1
    /* C37C 8001BB7C 05008228 */  slti       $v0, $a0, 0x5
    /* C380 8001BB80 F6FF4014 */  bnez       $v0, .L8001BB5C
    /* C384 8001BB84 21108700 */   addu      $v0, $a0, $a3
  .L8001BB88:
    /* C388 8001BB88 1B80083C */  lui        $t0, %hi(D_801AB000)
    /* C38C 8001BB8C 00B00825 */  addiu      $t0, $t0, %lo(D_801AB000)
    /* C390 8001BB90 20CE1E25 */  addiu      $fp, $t0, -0x31E0
    /* C394 8001BB94 0F80163C */  lui        $s6, %hi(D_800EAE88)
    /* C398 8001BB98 88AED626 */  addiu      $s6, $s6, %lo(D_800EAE88)
  .L8001BB9C:
    /* C39C 8001BB9C 0000C592 */  lbu        $a1, 0x0($s6)
    /* C3A0 8001BBA0 00000000 */  nop
    /* C3A4 8001BBA4 5C00A010 */  beqz       $a1, .L8001BD18
    /* C3A8 8001BBA8 1000A228 */   slti      $v0, $a1, 0x10
    /* C3AC 8001BBAC 53004014 */  bnez       $v0, .L8001BCFC
    /* C3B0 8001BBB0 0980023C */   lui       $v0, %hi(D_800907CC)
    /* C3B4 8001BBB4 21980000 */  addu       $s3, $zero, $zero
    /* C3B8 8001BBB8 CC074424 */  addiu      $a0, $v0, %lo(D_800907CC)
    /* C3BC 8001BBBC 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* C3C0 8001BBC0 D87A5724 */  addiu      $s7, $v0, %lo(D_801A7AD8)
    /* C3C4 8001BBC4 0F80023C */  lui        $v0, %hi(D_800EA030)
    /* C3C8 8001BBC8 30A05424 */  addiu      $s4, $v0, %lo(D_800EA030)
  .L8001BBCC:
    /* C3CC 8001BBCC 1000A227 */  addiu      $v0, $sp, 0x10
    /* C3D0 8001BBD0 21A85300 */  addu       $s5, $v0, $s3
    /* C3D4 8001BBD4 0000A382 */  lb         $v1, 0x0($s5)
    /* C3D8 8001BBD8 00000000 */  nop
    /* C3DC 8001BBDC 43006004 */  bltz       $v1, .L8001BCEC
    /* C3E0 8001BBE0 40100500 */   sll       $v0, $a1, 1
    /* C3E4 8001BBE4 21104500 */  addu       $v0, $v0, $a1
    /* C3E8 8001BBE8 80100200 */  sll        $v0, $v0, 2
    /* C3EC 8001BBEC 1B80093C */  lui        $t1, %hi(D_801AB000)
    /* C3F0 8001BBF0 00B02925 */  addiu      $t1, $t1, %lo(D_801AB000)
    /* C3F4 8001BBF4 21104900 */  addu       $v0, $v0, $t1
    /* C3F8 8001BBF8 40800300 */  sll        $s0, $v1, 1
    /* C3FC 8001BBFC 21800302 */  addu       $s0, $s0, $v1
    /* C400 8001BC00 40801000 */  sll        $s0, $s0, 1
    /* C404 8001BC04 21801E02 */  addu       $s0, $s0, $fp
    /* C408 8001BC08 0B004390 */  lbu        $v1, 0xB($v0)
    /* C40C 8001BC0C 02000582 */  lb         $a1, 0x2($s0)
    /* C410 8001BC10 40100300 */  sll        $v0, $v1, 1
    /* C414 8001BC14 21104300 */  addu       $v0, $v0, $v1
    /* C418 8001BC18 40100200 */  sll        $v0, $v0, 1
    /* C41C 8001BC1C 21105E00 */  addu       $v0, $v0, $fp
    /* C420 8001BC20 02004390 */  lbu        $v1, 0x2($v0)
    /* C424 8001BC24 00000000 */  nop
    /* C428 8001BC28 020003A2 */  sb         $v1, 0x2($s0)
    /* C42C 8001BC2C 020045A0 */  sb         $a1, 0x2($v0)
    /* C430 8001BC30 CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* C434 8001BC34 03000A8A */  lwl        $t2, 0x3($s0)
    /* C438 8001BC38 00000A9A */  lwr        $t2, 0x0($s0)
    /* C43C 8001BC3C 04000B86 */  lh         $t3, 0x4($s0)
    /* C440 8001BC40 1B00AAAB */  swl        $t2, 0x1B($sp)
    /* C444 8001BC44 1800AABB */  swr        $t2, 0x18($sp)
    /* C448 8001BC48 1C00ABA7 */  sh         $t3, 0x1C($sp)
    /* C44C 8001BC4C 03004A88 */  lwl        $t2, 0x3($v0)
    /* C450 8001BC50 00004A98 */  lwr        $t2, 0x0($v0)
    /* C454 8001BC54 04004B84 */  lh         $t3, 0x4($v0)
    /* C458 8001BC58 03000AAA */  swl        $t2, 0x3($s0)
    /* C45C 8001BC5C 00000ABA */  swr        $t2, 0x0($s0)
    /* C460 8001BC60 04000BA6 */  sh         $t3, 0x4($s0)
    /* C464 8001BC64 1B00AA8B */  lwl        $t2, 0x1B($sp)
    /* C468 8001BC68 1800AA9B */  lwr        $t2, 0x18($sp)
    /* C46C 8001BC6C 1C00AB87 */  lh         $t3, 0x1C($sp)
    /* C470 8001BC70 03004AA8 */  swl        $t2, 0x3($v0)
    /* C474 8001BC74 00004AB8 */  swr        $t2, 0x0($v0)
    /* C478 8001BC78 04004BA4 */  sh         $t3, 0x4($v0)
    /* C47C 8001BC7C 02000582 */  lb         $a1, 0x2($s0)
    /* C480 8001BC80 80100300 */  sll        $v0, $v1, 2
    /* C484 8001BC84 21104300 */  addu       $v0, $v0, $v1
    /* C488 8001BC88 21106202 */  addu       $v0, $s3, $v0
    /* C48C 8001BC8C 21104400 */  addu       $v0, $v0, $a0
    /* C490 8001BC90 00005190 */  lbu        $s1, 0x0($v0)
    /* C494 8001BC94 0000928E */  lw         $s2, 0x0($s4)
    /* C498 8001BC98 7892000C */  jal        func_800249E0
    /* C49C 8001BC9C 21202002 */   addu      $a0, $s1, $zero
    /* C4A0 8001BCA0 C0201100 */  sll        $a0, $s1, 3
    /* C4A4 8001BCA4 23209100 */  subu       $a0, $a0, $s1
    /* C4A8 8001BCA8 80200400 */  sll        $a0, $a0, 2
    /* C4AC 8001BCAC 30004586 */  lh         $a1, 0x30($s2)
    /* C4B0 8001BCB0 32004686 */  lh         $a2, 0x32($s2)
    /* C4B4 8001BCB4 0160000C */  jal        func_80018004
    /* C4B8 8001BCB8 21209700 */   addu      $a0, $a0, $s7
    /* C4BC 8001BCBC 21204002 */  addu       $a0, $s2, $zero
    /* C4C0 8001BCC0 DB00010C */  jal        func_8004036C
    /* C4C4 8001BCC4 000082AE */   sw        $v0, 0x0($s4)
    /* C4C8 8001BCC8 C002828F */  lw         $v0, %gp_rel(D_8009B1C8)($gp)
    /* C4CC 8001BCCC 02000392 */  lbu        $v1, 0x2($s0)
    /* C4D0 8001BCD0 21105300 */  addu       $v0, $v0, $s3
    /* C4D4 8001BCD4 1A0043A0 */  sb         $v1, 0x1A($v0)
    /* C4D8 8001BCD8 0B006226 */  addiu      $v0, $s3, 0xB
    /* C4DC 8001BCDC 0000C2A2 */  sb         $v0, 0x0($s6)
    /* C4E0 8001BCE0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* C4E4 8001BCE4 3F6F0008 */  j          .L8001BCFC
    /* C4E8 8001BCE8 0000A2A2 */   sb        $v0, 0x0($s5)
  .L8001BCEC:
    /* C4EC 8001BCEC 01007326 */  addiu      $s3, $s3, 0x1
    /* C4F0 8001BCF0 0500622A */  slti       $v0, $s3, 0x5
    /* C4F4 8001BCF4 B5FF4014 */  bnez       $v0, .L8001BBCC
    /* C4F8 8001BCF8 0C009426 */   addiu     $s4, $s4, 0xC
  .L8001BCFC:
    /* C4FC 8001BCFC 0100D626 */  addiu      $s6, $s6, 0x1
    /* C500 8001BD00 0F800A3C */  lui        $t2, %hi(D_800EAE88)
    /* C504 8001BD04 88AE4A25 */  addiu      $t2, $t2, %lo(D_800EAE88)
    /* C508 8001BD08 05004225 */  addiu      $v0, $t2, 0x5
    /* C50C 8001BD0C 2A10C202 */  slt        $v0, $s6, $v0
    /* C510 8001BD10 A2FF4014 */  bnez       $v0, .L8001BB9C
    /* C514 8001BD14 00000000 */   nop
  .L8001BD18:
    /* C518 8001BD18 4400BF8F */  lw         $ra, 0x44($sp)
    /* C51C 8001BD1C 4000BE8F */  lw         $fp, 0x40($sp)
    /* C520 8001BD20 3C00B78F */  lw         $s7, 0x3C($sp)
    /* C524 8001BD24 3800B68F */  lw         $s6, 0x38($sp)
    /* C528 8001BD28 3400B58F */  lw         $s5, 0x34($sp)
    /* C52C 8001BD2C 3000B48F */  lw         $s4, 0x30($sp)
    /* C530 8001BD30 2C00B38F */  lw         $s3, 0x2C($sp)
    /* C534 8001BD34 2800B28F */  lw         $s2, 0x28($sp)
    /* C538 8001BD38 2400B18F */  lw         $s1, 0x24($sp)
    /* C53C 8001BD3C 2000B08F */  lw         $s0, 0x20($sp)
    /* C540 8001BD40 0800E003 */  jr         $ra
    /* C544 8001BD44 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8001BAF0
