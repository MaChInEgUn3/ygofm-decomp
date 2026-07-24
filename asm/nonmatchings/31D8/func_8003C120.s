nonmatching func_8003C120, 0x194

glabel func_8003C120
    /* 2C920 8003C120 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2C924 8003C124 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2C928 8003C128 21808000 */  addu       $s0, $a0, $zero
    /* 2C92C 8003C12C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2C930 8003C130 01001124 */  addiu      $s1, $zero, 0x1
    /* 2C934 8003C134 2B00B110 */  beq        $a1, $s1, .L8003C1E4
    /* 2C938 8003C138 1800BFAF */   sw        $ra, 0x18($sp)
    /* 2C93C 8003C13C 0200A228 */  slti       $v0, $a1, 0x2
    /* 2C940 8003C140 05004010 */  beqz       $v0, .L8003C158
    /* 2C944 8003C144 00000000 */   nop
    /* 2C948 8003C148 0A00A010 */  beqz       $a1, .L8003C174
    /* 2C94C 8003C14C DDFF043C */   lui       $a0, (0xFFDDFFFF >> 16)
    /* 2C950 8003C150 A8F00008 */  j          .L8003C2A0
    /* 2C954 8003C154 00000000 */   nop
  .L8003C158:
    /* 2C958 8003C158 02000224 */  addiu      $v0, $zero, 0x2
    /* 2C95C 8003C15C 2F00A210 */  beq        $a1, $v0, .L8003C21C
    /* 2C960 8003C160 03000224 */   addiu     $v0, $zero, 0x3
    /* 2C964 8003C164 4200A210 */  beq        $a1, $v0, .L8003C270
    /* 2C968 8003C168 DCFF043C */   lui       $a0, (0xFFDCFFFF >> 16)
    /* 2C96C 8003C16C A8F00008 */  j          .L8003C2A0
    /* 2C970 8003C170 00000000 */   nop
  .L8003C174:
    /* 2C974 8003C174 FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 2C978 8003C178 00010224 */  addiu      $v0, $zero, 0x100
    /* 2C97C 8003C17C 320002A6 */  sh         $v0, 0x32($s0)
    /* 2C980 8003C180 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C984 8003C184 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C988 8003C188 40000324 */  addiu      $v1, $zero, 0x40
    /* 2C98C 8003C18C 300000A6 */  sh         $zero, 0x30($s0)
    /* 2C990 8003C190 040003A6 */  sh         $v1, 0x4($s0)
    /* 2C994 8003C194 24104400 */  and        $v0, $v0, $a0
    /* 2C998 8003C198 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C99C 8003C19C F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C9A0 8003C1A0 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C9A4 8003C1A4 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C9A8 8003C1A8 0100043C */  lui        $a0, (0x10000 >> 16)
    /* 2C9AC 8003C1AC 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 2C9B0 8003C1B0 25104400 */  or         $v0, $v0, $a0
    /* 2C9B4 8003C1B4 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C9B8 8003C1B8 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C9BC 8003C1BC 02000224 */  addiu      $v0, $zero, 0x2
    /* 2C9C0 8003C1C0 460002A2 */  sb         $v0, 0x46($s0)
    /* 2C9C4 8003C1C4 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 2C9C8 8003C1C8 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 2C9CC 8003C1CC 10000224 */  addiu      $v0, $zero, 0x10
    /* 2C9D0 8003C1D0 060002A6 */  sh         $v0, 0x6($s0)
    /* 2C9D4 8003C1D4 080003AE */  sw         $v1, 0x8($s0)
    /* 2C9D8 8003C1D8 00086324 */  addiu      $v1, $v1, 0x800
    /* 2C9DC 8003C1DC A8F00008 */  j          .L8003C2A0
    /* 2C9E0 8003C1E0 0C0003AE */   sw        $v1, 0xC($s0)
  .L8003C1E4:
    /* 2C9E4 8003C1E4 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2C9E8 8003C1E8 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C9EC 8003C1EC 00080224 */  addiu      $v0, $zero, 0x800
    /* 2C9F0 8003C1F0 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 2C9F4 8003C1F4 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C9F8 8003C1F8 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C9FC 8003C1FC 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 2CA00 8003C200 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 2CA04 8003C204 24104400 */  and        $v0, $v0, $a0
    /* 2CA08 8003C208 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2CA0C 8003C20C F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2CA10 8003C210 0C0003AE */  sw         $v1, 0xC($s0)
    /* 2CA14 8003C214 A7F00008 */  j          .L8003C29C
    /* 2CA18 8003C218 080003AE */   sw        $v1, 0x8($s0)
  .L8003C21C:
    /* 2CA1C 8003C21C 00010324 */  addiu      $v1, $zero, 0x100
    /* 2CA20 8003C220 F0000224 */  addiu      $v0, $zero, 0xF0
    /* 2CA24 8003C224 020002A6 */  sh         $v0, 0x2($s0)
    /* 2CA28 8003C228 04000224 */  addiu      $v0, $zero, 0x4
    /* 2CA2C 8003C22C 0A80053C */  lui        $a1, %hi(D_8009B118)
    /* 2CA30 8003C230 18B1A58C */  lw         $a1, %lo(D_8009B118)($a1)
    /* 2CA34 8003C234 21200002 */  addu       $a0, $s0, $zero
    /* 2CA38 8003C238 000003A6 */  sh         $v1, 0x0($s0)
    /* 2CA3C 8003C23C 040003A6 */  sh         $v1, 0x4($s0)
    /* 2CA40 8003C240 7A07020C */  jal        func_80081DE8
    /* 2CA44 8003C244 060002A6 */   sh        $v0, 0x6($s0)
    /* 2CA48 8003C248 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2CA4C 8003C24C FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2CA50 8003C250 1B80023C */  lui        $v0, %hi(D_801AF000)
    /* 2CA54 8003C254 00F04224 */  addiu      $v0, $v0, %lo(D_801AF000)
    /* 2CA58 8003C258 0C0002AE */  sw         $v0, 0xC($s0)
    /* 2CA5C 8003C25C 080002AE */  sw         $v0, 0x8($s0)
    /* 2CA60 8003C260 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2CA64 8003C264 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2CA68 8003C268 A3F00008 */  j          .L8003C28C
    /* 2CA6C 8003C26C 00080324 */   addiu     $v1, $zero, 0x800
  .L8003C270:
    /* 2CA70 8003C270 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2CA74 8003C274 1480023C */  lui        $v0, (0x80140000 >> 16)
    /* 2CA78 8003C278 0C0002AE */  sw         $v0, 0xC($s0)
    /* 2CA7C 8003C27C 080002AE */  sw         $v0, 0x8($s0)
    /* 2CA80 8003C280 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2CA84 8003C284 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2CA88 8003C288 00800334 */  ori        $v1, $zero, 0x8000
  .L8003C28C:
    /* 2CA8C 8003C28C 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 2CA90 8003C290 24104400 */  and        $v0, $v0, $a0
    /* 2CA94 8003C294 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2CA98 8003C298 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
  .L8003C29C:
    /* 2CA9C 8003C29C 460011A2 */  sb         $s1, 0x46($s0)
  .L8003C2A0:
    /* 2CAA0 8003C2A0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2CAA4 8003C2A4 1400B18F */  lw         $s1, 0x14($sp)
    /* 2CAA8 8003C2A8 1000B08F */  lw         $s0, 0x10($sp)
    /* 2CAAC 8003C2AC 0800E003 */  jr         $ra
    /* 2CAB0 8003C2B0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003C120
