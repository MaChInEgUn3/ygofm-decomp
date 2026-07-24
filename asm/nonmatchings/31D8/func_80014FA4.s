nonmatching func_80014FA4, 0x6C

glabel func_80014FA4
    /* 57A4 80014FA4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 57A8 80014FA8 0002023C */  lui        $v0, (0x2000030 >> 16)
    /* 57AC 80014FAC EC01838F */  lw         $v1, %gp_rel(D_8009B0F4)($gp)
    /* 57B0 80014FB0 2C02848F */  lw         $a0, %gp_rel(D_8009B134)($gp)
    /* 57B4 80014FB4 30004234 */  ori        $v0, $v0, (0x2000030 & 0xFFFF)
    /* 57B8 80014FB8 24186200 */  and        $v1, $v1, $v0
    /* 57BC 80014FBC 25186400 */  or         $v1, $v1, $a0
    /* 57C0 80014FC0 0F006010 */  beqz       $v1, .L80015000
    /* 57C4 80014FC4 1000BFAF */   sw        $ra, 0x10($sp)
    /* 57C8 80014FC8 EC01828F */  lw         $v0, %gp_rel(D_8009B0F4)($gp)
    /* 57CC 80014FCC 00000000 */  nop
    /* 57D0 80014FD0 10004230 */  andi       $v0, $v0, 0x10
    /* 57D4 80014FD4 09004010 */  beqz       $v0, .L80014FFC
    /* 57D8 80014FD8 80000224 */   addiu     $v0, $zero, 0x80
    /* 57DC 80014FDC EC01828F */  lw         $v0, %gp_rel(D_8009B0F4)($gp)
    /* 57E0 80014FE0 0800033C */  lui        $v1, (0x80000 >> 16)
    /* 57E4 80014FE4 24104300 */  and        $v0, $v0, $v1
    /* 57E8 80014FE8 04004010 */  beqz       $v0, .L80014FFC
    /* 57EC 80014FEC 80000224 */   addiu     $v0, $zero, 0x80
    /* 57F0 80014FF0 0454000C */  jal        func_80015010
    /* 57F4 80014FF4 00000000 */   nop
    /* 57F8 80014FF8 80000224 */  addiu      $v0, $zero, 0x80
  .L80014FFC:
    /* 57FC 80014FFC 2C0282AF */  sw         $v0, %gp_rel(D_8009B134)($gp)
  .L80015000:
    /* 5800 80015000 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5804 80015004 00000000 */  nop
    /* 5808 80015008 0800E003 */  jr         $ra
    /* 580C 8001500C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80014FA4
