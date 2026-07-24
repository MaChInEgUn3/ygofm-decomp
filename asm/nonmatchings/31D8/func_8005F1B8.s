nonmatching func_8005F1B8, 0xC4

glabel func_8005F1B8
    /* 4F9B8 8005F1B8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4F9BC 8005F1BC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4F9C0 8005F1C0 2180A000 */  addu       $s0, $a1, $zero
    /* 4F9C4 8005F1C4 02008228 */  slti       $v0, $a0, 0x2
    /* 4F9C8 8005F1C8 27004010 */  beqz       $v0, .L8005F268
    /* 4F9CC 8005F1CC 1C00BFAF */   sw        $ra, 0x1C($sp)
    /* 4F9D0 8005F1D0 0064010C */  jal        func_80059000
    /* 4F9D4 8005F1D4 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4F9D8 8005F1D8 1600A287 */  lh         $v0, 0x16($sp)
    /* 4F9DC 8005F1DC 00000000 */  nop
    /* 4F9E0 8005F1E0 32004228 */  slti       $v0, $v0, 0x32
    /* 4F9E4 8005F1E4 02004010 */  beqz       $v0, .L8005F1F0
    /* 4F9E8 8005F1E8 32000224 */   addiu     $v0, $zero, 0x32
    /* 4F9EC 8005F1EC 1600A2A7 */  sh         $v0, 0x16($sp)
  .L8005F1F0:
    /* 4F9F0 8005F1F0 1600A297 */  lhu        $v0, 0x16($sp)
    /* 4F9F4 8005F1F4 00000000 */  nop
    /* 4F9F8 8005F1F8 D4FE4224 */  addiu      $v0, $v0, -0x12C
    /* 4F9FC 8005F1FC 1600A2A7 */  sh         $v0, 0x16($sp)
    /* 4FA00 8005F200 00140200 */  sll        $v0, $v0, 16
    /* 4FA04 8005F204 031C0200 */  sra        $v1, $v0, 16
    /* 4FA08 8005F208 17006010 */  beqz       $v1, .L8005F268
    /* 4FA0C 8005F20C 21100002 */   addu      $v0, $s0, $zero
    /* 4FA10 8005F210 04006018 */  blez       $v1, .L8005F224
    /* 4FA14 8005F214 EE020424 */   addiu     $a0, $zero, 0x2EE
    /* 4FA18 8005F218 C2171000 */  srl        $v0, $s0, 31
    /* 4FA1C 8005F21C 21100202 */  addu       $v0, $s0, $v0
    /* 4FA20 8005F220 43100200 */  sra        $v0, $v0, 1
  .L8005F224:
    /* 4FA24 8005F224 18006200 */  mult       $v1, $v0
    /* 4FA28 8005F228 12180000 */  mflo       $v1
    /* 4FA2C 8005F22C 00000000 */  nop
    /* 4FA30 8005F230 00000000 */  nop
    /* 4FA34 8005F234 1A006400 */  div        $zero, $v1, $a0
    /* 4FA38 8005F238 02008014 */  bnez       $a0, .L8005F244
    /* 4FA3C 8005F23C 00000000 */   nop
    /* 4FA40 8005F240 0D000700 */  break      7
  .L8005F244:
    /* 4FA44 8005F244 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4FA48 8005F248 04008114 */  bne        $a0, $at, .L8005F25C
    /* 4FA4C 8005F24C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4FA50 8005F250 02006114 */  bne        $v1, $at, .L8005F25C
    /* 4FA54 8005F254 00000000 */   nop
    /* 4FA58 8005F258 0D000600 */  break      6
  .L8005F25C:
    /* 4FA5C 8005F25C 12100000 */  mflo       $v0
    /* 4FA60 8005F260 00000000 */  nop
    /* 4FA64 8005F264 21800202 */  addu       $s0, $s0, $v0
  .L8005F268:
    /* 4FA68 8005F268 21100002 */  addu       $v0, $s0, $zero
    /* 4FA6C 8005F26C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4FA70 8005F270 1800B08F */  lw         $s0, 0x18($sp)
    /* 4FA74 8005F274 0800E003 */  jr         $ra
    /* 4FA78 8005F278 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8005F1B8
