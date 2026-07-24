nonmatching func_8005BB7C, 0x2C0

glabel func_8005BB7C
    /* 4C37C 8005BB7C 10FCBD27 */  addiu      $sp, $sp, -0x3F0
    /* 4C380 8005BB80 E003B0AF */  sw         $s0, 0x3E0($sp)
    /* 4C384 8005BB84 21808000 */  addu       $s0, $a0, $zero
    /* 4C388 8005BB88 21200000 */  addu       $a0, $zero, $zero
    /* 4C38C 8005BB8C E803BFAF */  sw         $ra, 0x3E8($sp)
    /* 4C390 8005BB90 B3FD010C */  jal        func_8007F6CC
    /* 4C394 8005BB94 E403B1AF */   sw        $s1, 0x3E4($sp)
    /* 4C398 8005BB98 D613010C */  jal        func_80044F58
    /* 4C39C 8005BB9C 21200000 */   addu      $a0, $zero, $zero
    /* 4C3A0 8005BBA0 01000224 */  addiu      $v0, $zero, 0x1
    /* 4C3A4 8005BBA4 21200000 */  addu       $a0, $zero, $zero
    /* 4C3A8 8005BBA8 5B0182A3 */  sb         $v0, %gp_rel(D_8009B063)($gp)
    /* 4C3AC 8005BBAC 9F3F020C */  jal        func_8008FE7C
    /* 4C3B0 8005BBB0 00000000 */   nop
    /* 4C3B4 8005BBB4 B4E0010C */  jal        func_800782D0
    /* 4C3B8 8005BBB8 00000000 */   nop
    /* 4C3BC 8005BBBC 09000424 */  addiu      $a0, $zero, 0x9
  .L8005BBC0:
    /* 4C3C0 8005BBC0 21280000 */  addu       $a1, $zero, $zero
    /* 4C3C4 8005BBC4 FCF9010C */  jal        func_8007E7F0
    /* 4C3C8 8005BBC8 2130A000 */   addu      $a2, $a1, $zero
    /* 4C3CC 8005BBCC FCFF4010 */  beqz       $v0, .L8005BBC0
    /* 4C3D0 8005BBD0 09000424 */   addiu     $a0, $zero, 0x9
    /* 4C3D4 8005BBD4 59018293 */  lbu        $v0, %gp_rel(D_8009B061)($gp)
    /* 4C3D8 8005BBD8 00000000 */  nop
    /* 4C3DC 8005BBDC 03004014 */  bnez       $v0, .L8005BBEC
    /* 4C3E0 8005BBE0 21200000 */   addu      $a0, $zero, $zero
    /* 4C3E4 8005BBE4 03000012 */  beqz       $s0, .L8005BBF4
    /* 4C3E8 8005BBE8 00000000 */   nop
  .L8005BBEC:
    /* 4C3EC 8005BBEC 5A71010C */  jal        func_8005C568
    /* 4C3F0 8005BBF0 00010524 */   addiu     $a1, $zero, 0x100
  .L8005BBF4:
    /* 4C3F4 8005BBF4 58018293 */  lbu        $v0, %gp_rel(D_8009B060)($gp)
    /* 4C3F8 8005BBF8 00000000 */  nop
    /* 4C3FC 8005BBFC 89004010 */  beqz       $v0, .L8005BE24
    /* 4C400 8005BC00 00000000 */   nop
    /* 4C404 8005BC04 C814020C */  jal        func_80085320
    /* 4C408 8005BC08 21800000 */   addu      $s0, $zero, $zero
    /* 4C40C 8005BC0C 21884000 */  addu       $s1, $v0, $zero
    /* 4C410 8005BC10 2000A327 */  addiu      $v1, $sp, 0x20
  .L8005BC14:
    /* 4C414 8005BC14 0A80023C */  lui        $v0, %hi(D_8009B144)
    /* 4C418 8005BC18 44B14290 */  lbu        $v0, %lo(D_8009B144)($v0)
    /* 4C41C 8005BC1C 03001026 */  addiu      $s0, $s0, 0x3
    /* 4C420 8005BC20 000062A0 */  sb         $v0, 0x0($v1)
    /* 4C424 8005BC24 0A80023C */  lui        $v0, %hi(D_8009B143)
    /* 4C428 8005BC28 43B14290 */  lbu        $v0, %lo(D_8009B143)($v0)
    /* 4C42C 8005BC2C 01006324 */  addiu      $v1, $v1, 0x1
    /* 4C430 8005BC30 000062A0 */  sb         $v0, 0x0($v1)
    /* 4C434 8005BC34 0A80023C */  lui        $v0, %hi(D_8009B142)
    /* 4C438 8005BC38 42B14290 */  lbu        $v0, %lo(D_8009B142)($v0)
    /* 4C43C 8005BC3C 01006324 */  addiu      $v1, $v1, 0x1
    /* 4C440 8005BC40 000062A0 */  sb         $v0, 0x0($v1)
    /* 4C444 8005BC44 C003022A */  slti       $v0, $s0, 0x3C0
    /* 4C448 8005BC48 F2FF4014 */  bnez       $v0, .L8005BC14
    /* 4C44C 8005BC4C 01006324 */   addiu     $v1, $v1, 0x1
    /* 4C450 8005BC50 1800A0A7 */  sh         $zero, 0x18($sp)
    /* 4C454 8005BC54 21800000 */  addu       $s0, $zero, $zero
    /* 4C458 8005BC58 1080033C */  lui        $v1, %hi(D_800FE0D4)
    /* 4C45C 8005BC5C D4E0638C */  lw         $v1, %lo(D_800FE0D4)($v1)
    /* 4C460 8005BC60 00121100 */  sll        $v0, $s1, 8
    /* 4C464 8005BC64 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 4C468 8005BC68 E0010224 */  addiu      $v0, $zero, 0x1E0
    /* 4C46C 8005BC6C 1C00A2A7 */  sh         $v0, 0x1C($sp)
    /* 4C470 8005BC70 01000224 */  addiu      $v0, $zero, 0x1
    /* 4C474 8005BC74 0F006018 */  blez       $v1, .L8005BCB4
    /* 4C478 8005BC78 1E00A2A7 */   sh        $v0, 0x1E($sp)
  .L8005BC7C:
    /* 4C47C 8005BC7C 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4C480 8005BC80 5EFE010C */  jal        func_8007F978
    /* 4C484 8005BC84 2000A527 */   addiu     $a1, $sp, 0x20
    /* 4C488 8005BC88 B3FD010C */  jal        func_8007F6CC
    /* 4C48C 8005BC8C 21200000 */   addu      $a0, $zero, $zero
    /* 4C490 8005BC90 01001026 */  addiu      $s0, $s0, 0x1
    /* 4C494 8005BC94 1A00A297 */  lhu        $v0, 0x1A($sp)
    /* 4C498 8005BC98 1080033C */  lui        $v1, %hi(D_800FE0D4)
    /* 4C49C 8005BC9C D4E0638C */  lw         $v1, %lo(D_800FE0D4)($v1)
    /* 4C4A0 8005BCA0 01004224 */  addiu      $v0, $v0, 0x1
    /* 4C4A4 8005BCA4 2A180302 */  slt        $v1, $s0, $v1
    /* 4C4A8 8005BCA8 F4FF6014 */  bnez       $v1, .L8005BC7C
    /* 4C4AC 8005BCAC 1A00A2A7 */   sh        $v0, 0x1A($sp)
    /* 4C4B0 8005BCB0 21800000 */  addu       $s0, $zero, $zero
  .L8005BCB4:
    /* 4C4B4 8005BCB4 1080033C */  lui        $v1, %hi(D_800FE0D0)
    /* 4C4B8 8005BCB8 D0E06394 */  lhu        $v1, %lo(D_800FE0D0)($v1)
    /* 4C4BC 8005BCBC 1080043C */  lui        $a0, %hi(D_800FE0D4)
    /* 4C4C0 8005BCC0 D4E0848C */  lw         $a0, %lo(D_800FE0D4)($a0)
    /* 4C4C4 8005BCC4 40010224 */  addiu      $v0, $zero, 0x140
    /* 4C4C8 8005BCC8 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 4C4CC 8005BCCC 01000224 */  addiu      $v0, $zero, 0x1
    /* 4C4D0 8005BCD0 1A00A0A7 */  sh         $zero, 0x1A($sp)
    /* 4C4D4 8005BCD4 1E00A2A7 */  sh         $v0, 0x1E($sp)
    /* 4C4D8 8005BCD8 0E008018 */  blez       $a0, .L8005BD14
    /* 4C4DC 8005BCDC 1C00A3A7 */   sh        $v1, 0x1C($sp)
  .L8005BCE0:
    /* 4C4E0 8005BCE0 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4C4E4 8005BCE4 5EFE010C */  jal        func_8007F978
    /* 4C4E8 8005BCE8 2000A527 */   addiu     $a1, $sp, 0x20
    /* 4C4EC 8005BCEC B3FD010C */  jal        func_8007F6CC
    /* 4C4F0 8005BCF0 21200000 */   addu      $a0, $zero, $zero
    /* 4C4F4 8005BCF4 01001026 */  addiu      $s0, $s0, 0x1
    /* 4C4F8 8005BCF8 1A00A297 */  lhu        $v0, 0x1A($sp)
    /* 4C4FC 8005BCFC 1080033C */  lui        $v1, %hi(D_800FE0D4)
    /* 4C500 8005BD00 D4E0638C */  lw         $v1, %lo(D_800FE0D4)($v1)
    /* 4C504 8005BD04 01004224 */  addiu      $v0, $v0, 0x1
    /* 4C508 8005BD08 2A180302 */  slt        $v1, $s0, $v1
    /* 4C50C 8005BD0C F4FF6014 */  bnez       $v1, .L8005BCE0
    /* 4C510 8005BD10 1A00A2A7 */   sh        $v0, 0x1A($sp)
  .L8005BD14:
    /* 4C514 8005BD14 B3FD010C */  jal        func_8007F6CC
    /* 4C518 8005BD18 21200000 */   addu      $a0, $zero, $zero
    /* 4C51C 8005BD1C 5CD0010C */  jal        func_80074170
    /* 4C520 8005BD20 21200000 */   addu      $a0, $zero, $zero
    /* 4C524 8005BD24 4015020C */  jal        func_80085500
    /* 4C528 8005BD28 21800000 */   addu      $s0, $zero, $zero
    /* 4C52C 8005BD2C 0100223A */  xori       $v0, $s1, 0x1
    /* 4C530 8005BD30 1080033C */  lui        $v1, %hi(D_800FE0D4)
    /* 4C534 8005BD34 D4E0638C */  lw         $v1, %lo(D_800FE0D4)($v1)
    /* 4C538 8005BD38 00120200 */  sll        $v0, $v0, 8
    /* 4C53C 8005BD3C 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 4C540 8005BD40 E0010224 */  addiu      $v0, $zero, 0x1E0
    /* 4C544 8005BD44 1C00A2A7 */  sh         $v0, 0x1C($sp)
    /* 4C548 8005BD48 01000224 */  addiu      $v0, $zero, 0x1
    /* 4C54C 8005BD4C 1800A0A7 */  sh         $zero, 0x18($sp)
    /* 4C550 8005BD50 0E006018 */  blez       $v1, .L8005BD8C
    /* 4C554 8005BD54 1E00A2A7 */   sh        $v0, 0x1E($sp)
  .L8005BD58:
    /* 4C558 8005BD58 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4C55C 8005BD5C 5EFE010C */  jal        func_8007F978
    /* 4C560 8005BD60 2000A527 */   addiu     $a1, $sp, 0x20
    /* 4C564 8005BD64 B3FD010C */  jal        func_8007F6CC
    /* 4C568 8005BD68 21200000 */   addu      $a0, $zero, $zero
    /* 4C56C 8005BD6C 01001026 */  addiu      $s0, $s0, 0x1
    /* 4C570 8005BD70 1A00A297 */  lhu        $v0, 0x1A($sp)
    /* 4C574 8005BD74 1080033C */  lui        $v1, %hi(D_800FE0D4)
    /* 4C578 8005BD78 D4E0638C */  lw         $v1, %lo(D_800FE0D4)($v1)
    /* 4C57C 8005BD7C 01004224 */  addiu      $v0, $v0, 0x1
    /* 4C580 8005BD80 2A180302 */  slt        $v1, $s0, $v1
    /* 4C584 8005BD84 F4FF6014 */  bnez       $v1, .L8005BD58
    /* 4C588 8005BD88 1A00A2A7 */   sh        $v0, 0x1A($sp)
  .L8005BD8C:
    /* 4C58C 8005BD8C B3FD010C */  jal        func_8007F6CC
    /* 4C590 8005BD90 21200000 */   addu      $a0, $zero, $zero
    /* 4C594 8005BD94 5CD0010C */  jal        func_80074170
    /* 4C598 8005BD98 21200000 */   addu      $a0, $zero, $zero
    /* 4C59C 8005BD9C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4C5A0 8005BDA0 1080013C */  lui        $at, %hi(D_800FE0CC)
    /* 4C5A4 8005BDA4 CCE022A4 */  sh         $v0, %lo(D_800FE0CC)($at)
    /* 4C5A8 8005BDA8 4015020C */  jal        func_80085500
    /* 4C5AC 8005BDAC 00000000 */   nop
    /* 4C5B0 8005BDB0 21200000 */  addu       $a0, $zero, $zero
    /* 4C5B4 8005BDB4 21288000 */  addu       $a1, $a0, $zero
    /* 4C5B8 8005BDB8 40010624 */  addiu      $a2, $zero, 0x140
    /* 4C5BC 8005BDBC A815020C */  jal        func_800856A0
    /* 4C5C0 8005BDC0 21388000 */   addu      $a3, $a0, $zero
    /* 4C5C4 8005BDC4 40010424 */  addiu      $a0, $zero, 0x140
    /* 4C5C8 8005BDC8 F0000524 */  addiu      $a1, $zero, 0xF0
    /* 4C5CC 8005BDCC 04000624 */  addiu      $a2, $zero, 0x4
    /* 4C5D0 8005BDD0 01000724 */  addiu      $a3, $zero, 0x1
    /* 4C5D4 8005BDD4 D813020C */  jal        func_80084F60
    /* 4C5D8 8005BDD8 1000A0AF */   sw        $zero, 0x10($sp)
    /* 4C5DC 8005BDDC 0A80053C */  lui        $a1, %hi(D_8009B144)
    /* 4C5E0 8005BDE0 44B1A590 */  lbu        $a1, %lo(D_8009B144)($a1)
    /* 4C5E4 8005BDE4 0A80063C */  lui        $a2, %hi(D_8009B143)
    /* 4C5E8 8005BDE8 43B1C690 */  lbu        $a2, %lo(D_8009B143)($a2)
    /* 4C5EC 8005BDEC 0A80073C */  lui        $a3, %hi(D_8009B142)
    /* 4C5F0 8005BDF0 42B1E790 */  lbu        $a3, %lo(D_8009B142)($a3)
    /* 4C5F4 8005BDF4 1080023C */  lui        $v0, %hi(D_800FE0D0)
    /* 4C5F8 8005BDF8 D0E0428C */  lw         $v0, %lo(D_800FE0D0)($v0)
    /* 4C5FC 8005BDFC 1080033C */  lui        $v1, %hi(D_800FE0D4)
    /* 4C600 8005BE00 D4E06394 */  lhu        $v1, %lo(D_800FE0D4)($v1)
    /* 4C604 8005BE04 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4C608 8005BE08 1800A0A7 */  sh         $zero, 0x18($sp)
    /* 4C60C 8005BE0C 1A00A0A7 */  sh         $zero, 0x1A($sp)
    /* 4C610 8005BE10 40100200 */  sll        $v0, $v0, 1
    /* 4C614 8005BE14 1C00A2A7 */  sh         $v0, 0x1C($sp)
    /* 4C618 8005BE18 14FE010C */  jal        func_8007F850
    /* 4C61C 8005BE1C 1E00A3A7 */   sh        $v1, 0x1E($sp)
    /* 4C620 8005BE20 580180A3 */  sb         $zero, %gp_rel(D_8009B060)($gp)
  .L8005BE24:
    /* 4C624 8005BE24 E803BF8F */  lw         $ra, 0x3E8($sp)
    /* 4C628 8005BE28 E403B18F */  lw         $s1, 0x3E4($sp)
    /* 4C62C 8005BE2C E003B08F */  lw         $s0, 0x3E0($sp)
    /* 4C630 8005BE30 21100000 */  addu       $v0, $zero, $zero
    /* 4C634 8005BE34 0800E003 */  jr         $ra
    /* 4C638 8005BE38 F003BD27 */   addiu     $sp, $sp, 0x3F0
endlabel func_8005BB7C
