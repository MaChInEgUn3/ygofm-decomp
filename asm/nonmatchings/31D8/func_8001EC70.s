nonmatching func_8001EC70, 0xB0

glabel func_8001EC70
    /* F470 8001EC70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F474 8001EC74 1000B0AF */  sw         $s0, 0x10($sp)
    /* F478 8001EC78 1400BFAF */  sw         $ra, 0x14($sp)
    /* F47C 8001EC7C E60A010C */  jal        func_80042B98
    /* F480 8001EC80 21808000 */   addu      $s0, $a0, $zero
    /* F484 8001EC84 05004014 */  bnez       $v0, .L8001EC9C
    /* F488 8001EC88 00000000 */   nop
    /* F48C 8001EC8C 5E0C010C */  jal        func_80043178
    /* F490 8001EC90 21200002 */   addu      $a0, $s0, $zero
    /* F494 8001EC94 600000A6 */  sh         $zero, 0x60($s0)
    /* F498 8001EC98 2E0000A6 */  sh         $zero, 0x2E($s0)
  .L8001EC9C:
    /* F49C 8001EC9C 28000586 */  lh         $a1, 0x28($s0)
    /* F4A0 8001ECA0 2A000686 */  lh         $a2, 0x2A($s0)
    /* F4A4 8001ECA4 60000786 */  lh         $a3, 0x60($s0)
    /* F4A8 8001ECA8 630C010C */  jal        func_8004318C
    /* F4AC 8001ECAC 21200002 */   addu      $a0, $s0, $zero
    /* F4B0 8001ECB0 2C000286 */  lh         $v0, 0x2C($s0)
    /* F4B4 8001ECB4 00080324 */  addiu      $v1, $zero, 0x800
    /* F4B8 8001ECB8 1A006200 */  div        $zero, $v1, $v0
    /* F4BC 8001ECBC 02004014 */  bnez       $v0, .L8001ECC8
    /* F4C0 8001ECC0 00000000 */   nop
    /* F4C4 8001ECC4 0D000700 */  break      7
  .L8001ECC8:
    /* F4C8 8001ECC8 FFFF0124 */  addiu      $at, $zero, -0x1
    /* F4CC 8001ECCC 04004114 */  bne        $v0, $at, .L8001ECE0
    /* F4D0 8001ECD0 0080013C */   lui       $at, (0x80000000 >> 16)
    /* F4D4 8001ECD4 02006114 */  bne        $v1, $at, .L8001ECE0
    /* F4D8 8001ECD8 00000000 */   nop
    /* F4DC 8001ECDC 0D000600 */  break      6
  .L8001ECE0:
    /* F4E0 8001ECE0 12180000 */  mflo       $v1
    /* F4E4 8001ECE4 60000296 */  lhu        $v0, 0x60($s0)
    /* F4E8 8001ECE8 00000000 */  nop
    /* F4EC 8001ECEC 21104300 */  addu       $v0, $v0, $v1
    /* F4F0 8001ECF0 600002A6 */  sh         $v0, 0x60($s0)
    /* F4F4 8001ECF4 00140200 */  sll        $v0, $v0, 16
    /* F4F8 8001ECF8 03140200 */  sra        $v0, $v0, 16
    /* F4FC 8001ECFC 00084228 */  slti       $v0, $v0, 0x800
    /* F500 8001ED00 03004014 */  bnez       $v0, .L8001ED10
    /* F504 8001ED04 00000000 */   nop
    /* F508 8001ED08 6C0000A2 */  sb         $zero, 0x6C($s0)
    /* F50C 8001ED0C 240000AE */  sw         $zero, 0x24($s0)
  .L8001ED10:
    /* F510 8001ED10 1400BF8F */  lw         $ra, 0x14($sp)
    /* F514 8001ED14 1000B08F */  lw         $s0, 0x10($sp)
    /* F518 8001ED18 0800E003 */  jr         $ra
    /* F51C 8001ED1C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001EC70
