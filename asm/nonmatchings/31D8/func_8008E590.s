nonmatching func_8008E590, 0x30

glabel func_8008E590
    /* 7ED90 8008E590 C641033C */  lui        $v1, (0x41C64E6D >> 16)
    /* 7ED94 8008E594 1080023C */  lui        $v0, %hi(D_800FE6F8)
    /* 7ED98 8008E598 F8E6428C */  lw         $v0, %lo(D_800FE6F8)($v0)
    /* 7ED9C 8008E59C 6D4E6334 */  ori        $v1, $v1, (0x41C64E6D & 0xFFFF)
    /* 7EDA0 8008E5A0 18004300 */  mult       $v0, $v1
    /* 7EDA4 8008E5A4 12200000 */  mflo       $a0
    /* 7EDA8 8008E5A8 39308224 */  addiu      $v0, $a0, 0x3039
    /* 7EDAC 8008E5AC 1080013C */  lui        $at, %hi(D_800FE6F8)
    /* 7EDB0 8008E5B0 F8E622AC */  sw         $v0, %lo(D_800FE6F8)($at)
    /* 7EDB4 8008E5B4 02140200 */  srl        $v0, $v0, 16
    /* 7EDB8 8008E5B8 0800E003 */  jr         $ra
    /* 7EDBC 8008E5BC FF7F4230 */   andi      $v0, $v0, 0x7FFF
endlabel func_8008E590
