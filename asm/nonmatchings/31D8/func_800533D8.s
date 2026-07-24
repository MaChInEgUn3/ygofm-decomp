nonmatching func_800533D8, 0xE0

glabel func_800533D8
    /* 43BD8 800533D8 E0FDBD27 */  addiu      $sp, $sp, -0x220
    /* 43BDC 800533DC 1200A327 */  addiu      $v1, $sp, 0x12
    /* 43BE0 800533E0 FFFF0434 */  ori        $a0, $zero, 0xFFFF
    /* 43BE4 800533E4 FE000224 */  addiu      $v0, $zero, 0xFE
    /* 43BE8 800533E8 1802BFAF */  sw         $ra, 0x218($sp)
    /* 43BEC 800533EC 1000A0A7 */  sh         $zero, 0x10($sp)
  .L800533F0:
    /* 43BF0 800533F0 000064A4 */  sh         $a0, 0x0($v1)
    /* 43BF4 800533F4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 43BF8 800533F8 FDFF4104 */  bgez       $v0, .L800533F0
    /* 43BFC 800533FC 02006324 */   addiu     $v1, $v1, 0x2
    /* 43C00 80053400 00020224 */  addiu      $v0, $zero, 0x200
    /* 43C04 80053404 1002A2A7 */  sh         $v0, 0x210($sp)
    /* 43C08 80053408 F0000224 */  addiu      $v0, $zero, 0xF0
    /* 43C0C 8005340C 1202A2A7 */  sh         $v0, 0x212($sp)
    /* 43C10 80053410 00010224 */  addiu      $v0, $zero, 0x100
    /* 43C14 80053414 1402A2A7 */  sh         $v0, 0x214($sp)
    /* 43C18 80053418 01000224 */  addiu      $v0, $zero, 0x1
    /* 43C1C 8005341C 1602A2A7 */  sh         $v0, 0x216($sp)
  .L80053420:
    /* 43C20 80053420 C908020C */  jal        func_80082324
    /* 43C24 80053424 03000424 */   addiu     $a0, $zero, 0x3
    /* 43C28 80053428 FDFF4014 */  bnez       $v0, .L80053420
    /* 43C2C 8005342C 1002A427 */   addiu     $a0, $sp, 0x210
  .L80053430:
    /* 43C30 80053430 7A07020C */  jal        func_80081DE8
    /* 43C34 80053434 1000A527 */   addiu     $a1, $sp, 0x10
    /* 43C38 80053438 FDFF4014 */  bnez       $v0, .L80053430
    /* 43C3C 8005343C 1002A427 */   addiu     $a0, $sp, 0x210
  .L80053440:
    /* 43C40 80053440 C908020C */  jal        func_80082324
    /* 43C44 80053444 03000424 */   addiu     $a0, $zero, 0x3
    /* 43C48 80053448 FDFF4014 */  bnez       $v0, .L80053440
    /* 43C4C 8005344C 00000000 */   nop
    /* 43C50 80053450 4758010C */  jal        func_8005611C
    /* 43C54 80053454 21200000 */   addu      $a0, $zero, $zero
    /* 43C58 80053458 4758010C */  jal        func_8005611C
    /* 43C5C 8005345C 01000424 */   addiu     $a0, $zero, 0x1
    /* 43C60 80053460 4758010C */  jal        func_8005611C
    /* 43C64 80053464 02000424 */   addiu     $a0, $zero, 0x2
    /* 43C68 80053468 21200000 */  addu       $a0, $zero, $zero
    /* 43C6C 8005346C 0F80023C */  lui        $v0, %hi(D_800F2B50)
    /* 43C70 80053470 502B4324 */  addiu      $v1, $v0, %lo(D_800F2B50)
  .L80053474:
    /* 43C74 80053474 00006294 */  lhu        $v0, 0x0($v1)
    /* 43C78 80053478 01008424 */  addiu      $a0, $a0, 0x1
    /* 43C7C 8005347C FEFF4230 */  andi       $v0, $v0, 0xFFFE
    /* 43C80 80053480 000062A4 */  sh         $v0, 0x0($v1)
    /* 43C84 80053484 0A008228 */  slti       $v0, $a0, 0xA
    /* 43C88 80053488 FAFF4014 */  bnez       $v0, .L80053474
    /* 43C8C 8005348C 18006324 */   addiu     $v1, $v1, 0x18
    /* 43C90 80053490 930080A3 */  sb         $zero, %gp_rel(D_8009AF9B)($gp)
    /* 43C94 80053494 940080AF */  sw         $zero, %gp_rel(D_8009AF9C)($gp)
    /* 43C98 80053498 B866010C */  jal        func_80059AE0
    /* 43C9C 8005349C 00800434 */   ori       $a0, $zero, 0x8000
    /* 43CA0 800534A0 1802BF8F */  lw         $ra, 0x218($sp)
    /* 43CA4 800534A4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 43CA8 800534A8 8C0080A3 */  sb         $zero, %gp_rel(D_8009AF94)($gp)
    /* 43CAC 800534AC 920082A3 */  sb         $v0, %gp_rel(D_8009AF9A)($gp)
    /* 43CB0 800534B0 0800E003 */  jr         $ra
    /* 43CB4 800534B4 2002BD27 */   addiu     $sp, $sp, 0x220
endlabel func_800533D8
