nonmatching func_8002FB78, 0x198

glabel func_8002FB78
    /* 20378 8002FB78 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2037C 8002FB7C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 20380 8002FB80 21808000 */  addu       $s0, $a0, $zero
    /* 20384 8002FB84 01000624 */  addiu      $a2, $zero, 0x1
    /* 20388 8002FB88 2C00A610 */  beq        $a1, $a2, .L8002FC3C
    /* 2038C 8002FB8C 1400BFAF */   sw        $ra, 0x14($sp)
    /* 20390 8002FB90 0200A228 */  slti       $v0, $a1, 0x2
    /* 20394 8002FB94 05004010 */  beqz       $v0, .L8002FBAC
    /* 20398 8002FB98 00000000 */   nop
    /* 2039C 8002FB9C 0A00A010 */  beqz       $a1, .L8002FBC8
    /* 203A0 8002FBA0 DDFF043C */   lui       $a0, (0xFFDDFFFF >> 16)
    /* 203A4 8002FBA4 40BF0008 */  j          .L8002FD00
    /* 203A8 8002FBA8 00000000 */   nop
  .L8002FBAC:
    /* 203AC 8002FBAC 02000224 */  addiu      $v0, $zero, 0x2
    /* 203B0 8002FBB0 2C00A210 */  beq        $a1, $v0, .L8002FC64
    /* 203B4 8002FBB4 03000224 */   addiu     $v0, $zero, 0x3
    /* 203B8 8002FBB8 4400A210 */  beq        $a1, $v0, .L8002FCCC
    /* 203BC 8002FBBC DCFF043C */   lui       $a0, (0xFFDCFFFF >> 16)
    /* 203C0 8002FBC0 40BF0008 */  j          .L8002FD00
    /* 203C4 8002FBC4 00000000 */   nop
  .L8002FBC8:
    /* 203C8 8002FBC8 FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 203CC 8002FBCC 40030224 */  addiu      $v0, $zero, 0x340
    /* 203D0 8002FBD0 300002A6 */  sh         $v0, 0x30($s0)
    /* 203D4 8002FBD4 40000224 */  addiu      $v0, $zero, 0x40
    /* 203D8 8002FBD8 040002A6 */  sh         $v0, 0x4($s0)
    /* 203DC 8002FBDC 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 203E0 8002FBE0 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 203E4 8002FBE4 10000324 */  addiu      $v1, $zero, 0x10
    /* 203E8 8002FBE8 060003A6 */  sh         $v1, 0x6($s0)
    /* 203EC 8002FBEC 24104400 */  and        $v0, $v0, $a0
    /* 203F0 8002FBF0 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 203F4 8002FBF4 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 203F8 8002FBF8 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 203FC 8002FBFC F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 20400 8002FC00 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 20404 8002FC04 320000A6 */  sh         $zero, 0x32($s0)
    /* 20408 8002FC08 25104300 */  or         $v0, $v0, $v1
    /* 2040C 8002FC0C 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 20410 8002FC10 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 20414 8002FC14 02000224 */  addiu      $v0, $zero, 0x2
    /* 20418 8002FC18 460002A2 */  sb         $v0, 0x46($s0)
    /* 2041C 8002FC1C 0A80023C */  lui        $v0, %hi(D_8009B118)
    /* 20420 8002FC20 18B1428C */  lw         $v0, %lo(D_8009B118)($v0)
    /* 20424 8002FC24 00800334 */  ori        $v1, $zero, 0x8000
    /* 20428 8002FC28 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 2042C 8002FC2C 080002AE */  sw         $v0, 0x8($s0)
    /* 20430 8002FC30 00084224 */  addiu      $v0, $v0, 0x800
    /* 20434 8002FC34 40BF0008 */  j          .L8002FD00
    /* 20438 8002FC38 0C0002AE */   sw        $v0, 0xC($s0)
  .L8002FC3C:
    /* 2043C 8002FC3C DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 20440 8002FC40 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 20444 8002FC44 00080224 */  addiu      $v0, $zero, 0x800
    /* 20448 8002FC48 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 2044C 8002FC4C 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 20450 8002FC50 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 20454 8002FC54 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 20458 8002FC58 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 2045C 8002FC5C 3BBF0008 */  j          .L8002FCEC
    /* 20460 8002FC60 24104400 */   and       $v0, $v0, $a0
  .L8002FC64:
    /* 20464 8002FC64 00010324 */  addiu      $v1, $zero, 0x100
    /* 20468 8002FC68 F0000224 */  addiu      $v0, $zero, 0xF0
    /* 2046C 8002FC6C 0A80053C */  lui        $a1, %hi(D_8009B118)
    /* 20470 8002FC70 18B1A58C */  lw         $a1, %lo(D_8009B118)($a1)
    /* 20474 8002FC74 21200002 */  addu       $a0, $s0, $zero
    /* 20478 8002FC78 000003A6 */  sh         $v1, 0x0($s0)
    /* 2047C 8002FC7C 020002A6 */  sh         $v0, 0x2($s0)
    /* 20480 8002FC80 040003A6 */  sh         $v1, 0x4($s0)
    /* 20484 8002FC84 7A07020C */  jal        func_80081DE8
    /* 20488 8002FC88 060006A6 */   sh        $a2, 0x6($s0)
    /* 2048C 8002FC8C DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 20490 8002FC90 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 20494 8002FC94 1B80023C */  lui        $v0, %hi(D_801A8000)
    /* 20498 8002FC98 00804224 */  addiu      $v0, $v0, %lo(D_801A8000)
    /* 2049C 8002FC9C 0C0002AE */  sw         $v0, 0xC($s0)
    /* 204A0 8002FCA0 080002AE */  sw         $v0, 0x8($s0)
    /* 204A4 8002FCA4 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 204A8 8002FCA8 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 204AC 8002FCAC 00100324 */  addiu      $v1, $zero, 0x1000
    /* 204B0 8002FCB0 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 204B4 8002FCB4 24104400 */  and        $v0, $v0, $a0
    /* 204B8 8002FCB8 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 204BC 8002FCBC F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 204C0 8002FCC0 01000224 */  addiu      $v0, $zero, 0x1
    /* 204C4 8002FCC4 40BF0008 */  j          .L8002FD00
    /* 204C8 8002FCC8 460002A2 */   sb        $v0, 0x46($s0)
  .L8002FCCC:
    /* 204CC 8002FCCC FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 204D0 8002FCD0 00F00234 */  ori        $v0, $zero, 0xF000
    /* 204D4 8002FCD4 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 204D8 8002FCD8 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 204DC 8002FCDC F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 204E0 8002FCE0 0180033C */  lui        $v1, %hi(D_80010000)
    /* 204E4 8002FCE4 0000638C */  lw         $v1, %lo(D_80010000)($v1)
    /* 204E8 8002FCE8 24104400 */  and        $v0, $v0, $a0
  .L8002FCEC:
    /* 204EC 8002FCEC 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 204F0 8002FCF0 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 204F4 8002FCF4 0C0003AE */  sw         $v1, 0xC($s0)
    /* 204F8 8002FCF8 080003AE */  sw         $v1, 0x8($s0)
    /* 204FC 8002FCFC 460006A2 */  sb         $a2, 0x46($s0)
  .L8002FD00:
    /* 20500 8002FD00 1400BF8F */  lw         $ra, 0x14($sp)
    /* 20504 8002FD04 1000B08F */  lw         $s0, 0x10($sp)
    /* 20508 8002FD08 0800E003 */  jr         $ra
    /* 2050C 8002FD0C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002FB78
