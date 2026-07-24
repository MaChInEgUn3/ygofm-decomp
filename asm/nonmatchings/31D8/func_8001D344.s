nonmatching func_8001D344, 0x80

glabel func_8001D344
    /* DB44 8001D344 60008A84 */  lh         $t2, 0x60($a0)
    /* DB48 8001D348 03000724 */  addiu      $a3, $zero, 0x3
    /* DB4C 8001D34C 21480000 */  addu       $t1, $zero, $zero
    /* DB50 8001D350 0C008624 */  addiu      $a2, $a0, 0xC
    /* DB54 8001D354 21408000 */  addu       $t0, $a0, $zero
  .L8001D358:
    /* DB58 8001D358 0000C390 */  lbu        $v1, 0x0($a2)
    /* DB5C 8001D35C 28000585 */  lh         $a1, 0x28($t0)
    /* DB60 8001D360 00000000 */  nop
    /* DB64 8001D364 2A106500 */  slt        $v0, $v1, $a1
    /* DB68 8001D368 04004010 */  beqz       $v0, .L8001D37C
    /* DB6C 8001D36C 00000000 */   nop
    /* DB70 8001D370 21186A00 */  addu       $v1, $v1, $t2
    /* DB74 8001D374 E1740008 */  j          .L8001D384
    /* DB78 8001D378 2A106500 */   slt       $v0, $v1, $a1
  .L8001D37C:
    /* DB7C 8001D37C 23186A00 */  subu       $v1, $v1, $t2
    /* DB80 8001D380 2A10A300 */  slt        $v0, $a1, $v1
  .L8001D384:
    /* DB84 8001D384 03004014 */  bnez       $v0, .L8001D394
    /* DB88 8001D388 00000000 */   nop
    /* DB8C 8001D38C 2118A000 */  addu       $v1, $a1, $zero
    /* DB90 8001D390 FFFFE724 */  addiu      $a3, $a3, -0x1
  .L8001D394:
    /* DB94 8001D394 0000C3A0 */  sb         $v1, 0x0($a2)
    /* DB98 8001D398 0100C624 */  addiu      $a2, $a2, 0x1
    /* DB9C 8001D39C 01002925 */  addiu      $t1, $t1, 0x1
    /* DBA0 8001D3A0 03002229 */  slti       $v0, $t1, 0x3
    /* DBA4 8001D3A4 ECFF4014 */  bnez       $v0, .L8001D358
    /* DBA8 8001D3A8 02000825 */   addiu     $t0, $t0, 0x2
    /* DBAC 8001D3AC 0300E014 */  bnez       $a3, .L8001D3BC
    /* DBB0 8001D3B0 00000000 */   nop
    /* DBB4 8001D3B4 6C0080A0 */  sb         $zero, 0x6C($a0)
    /* DBB8 8001D3B8 240080AC */  sw         $zero, 0x24($a0)
  .L8001D3BC:
    /* DBBC 8001D3BC 0800E003 */  jr         $ra
    /* DBC0 8001D3C0 00000000 */   nop
endlabel func_8001D344
