nonmatching func_8001EFD4, 0xFC

glabel func_8001EFD4
    /* F7D4 8001EFD4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* F7D8 8001EFD8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* F7DC 8001EFDC 1800B2AF */  sw         $s2, 0x18($sp)
    /* F7E0 8001EFE0 1400B1AF */  sw         $s1, 0x14($sp)
    /* F7E4 8001EFE4 1000B0AF */  sw         $s0, 0x10($sp)
    /* F7E8 8001EFE8 6A008290 */  lbu        $v0, 0x6A($a0)
    /* F7EC 8001EFEC 00000000 */  nop
    /* F7F0 8001EFF0 C0180200 */  sll        $v1, $v0, 3
    /* F7F4 8001EFF4 23186200 */  subu       $v1, $v1, $v0
    /* F7F8 8001EFF8 80180300 */  sll        $v1, $v1, 2
    /* F7FC 8001EFFC 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* F800 8001F000 D87A4424 */  addiu      $a0, $v0, %lo(D_801A7AD8)
    /* F804 8001F004 0500A014 */  bnez       $a1, .L8001F01C
    /* F808 8001F008 21906400 */   addu      $s2, $v1, $a0
    /* F80C 8001F00C 325C000C */  jal        func_800170C8
    /* F810 8001F010 21204002 */   addu      $a0, $s2, $zero
    /* F814 8001F014 2E7C0008 */  j          .L8001F0B8
    /* F818 8001F018 FFFF4230 */   andi      $v0, $v0, 0xFFFF
  .L8001F01C:
    /* F81C 8001F01C 6A00A290 */  lbu        $v0, 0x6A($a1)
    /* F820 8001F020 00000000 */  nop
    /* F824 8001F024 C0180200 */  sll        $v1, $v0, 3
    /* F828 8001F028 23186200 */  subu       $v1, $v1, $v0
    /* F82C 8001F02C 80180300 */  sll        $v1, $v1, 2
    /* F830 8001F030 21806400 */  addu       $s0, $v1, $a0
    /* F834 8001F034 325C000C */  jal        func_800170C8
    /* F838 8001F038 21200002 */   addu      $a0, $s0, $zero
    /* F83C 8001F03C 21184000 */  addu       $v1, $v0, $zero
    /* F840 8001F040 16000296 */  lhu        $v0, 0x16($s0)
    /* F844 8001F044 00000000 */  nop
    /* F848 8001F048 00084230 */  andi       $v0, $v0, 0x800
    /* F84C 8001F04C 02004010 */  beqz       $v0, .L8001F058
    /* F850 8001F050 FFFF7130 */   andi      $s1, $v1, 0xFFFF
    /* F854 8001F054 028C0300 */  srl        $s1, $v1, 16
  .L8001F058:
    /* F858 8001F058 16004296 */  lhu        $v0, 0x16($s2)
    /* F85C 8001F05C 00000000 */  nop
    /* F860 8001F060 00084230 */  andi       $v0, $v0, 0x800
    /* F864 8001F064 05004010 */  beqz       $v0, .L8001F07C
    /* F868 8001F068 21204002 */   addu      $a0, $s2, $zero
    /* F86C 8001F06C DE7B000C */  jal        func_8001EF78
    /* F870 8001F070 21280002 */   addu      $a1, $s0, $zero
    /* F874 8001F074 217C0008 */  j          .L8001F084
    /* F878 8001F078 00000000 */   nop
  .L8001F07C:
    /* F87C 8001F07C C77B000C */  jal        func_8001EF1C
    /* F880 8001F080 21280002 */   addu      $a1, $s0, $zero
  .L8001F084:
    /* F884 8001F084 0C005114 */  bne        $v0, $s1, .L8001F0B8
    /* F888 8001F088 23105100 */   subu      $v0, $v0, $s1
    /* F88C 8001F08C 16004296 */  lhu        $v0, 0x16($s2)
    /* F890 8001F090 00000000 */  nop
    /* F894 8001F094 00084230 */  andi       $v0, $v0, 0x800
    /* F898 8001F098 07004014 */  bnez       $v0, .L8001F0B8
    /* F89C 8001F09C 21100000 */   addu      $v0, $zero, $zero
    /* F8A0 8001F0A0 16000296 */  lhu        $v0, 0x16($s0)
    /* F8A4 8001F0A4 00000000 */  nop
    /* F8A8 8001F0A8 00084230 */  andi       $v0, $v0, 0x800
    /* F8AC 8001F0AC 02004014 */  bnez       $v0, .L8001F0B8
    /* F8B0 8001F0B0 21100000 */   addu      $v0, $zero, $zero
    /* F8B4 8001F0B4 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8001F0B8:
    /* F8B8 8001F0B8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* F8BC 8001F0BC 1800B28F */  lw         $s2, 0x18($sp)
    /* F8C0 8001F0C0 1400B18F */  lw         $s1, 0x14($sp)
    /* F8C4 8001F0C4 1000B08F */  lw         $s0, 0x10($sp)
    /* F8C8 8001F0C8 0800E003 */  jr         $ra
    /* F8CC 8001F0CC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001EFD4
