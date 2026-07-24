/* Handwritten function */
nonmatching func_80089BCC, 0x30

glabel func_80089BCC
    /* 7A3CC 80089BCC 040041AF */  sw         $at, 0x4($k0) /* handwritten instruction */
    /* 7A3D0 80089BD0 080042AF */  sw         $v0, 0x8($k0) /* handwritten instruction */
    /* 7A3D4 80089BD4 0C0043AF */  sw         $v1, 0xC($k0) /* handwritten instruction */
    /* 7A3D8 80089BD8 7C005FAF */  sw         $ra, 0x7C($k0) /* handwritten instruction */
    /* 7A3DC 80089BDC 00700340 */  mfc0       $v1, $14 /* handwritten instruction */
    /* 7A3E0 80089BE0 00000000 */  nop
  alabel D_80089BE4
    /* 7A3E4 80089BE4 040041AF */  sw         $at, 0x4($k0) /* handwritten instruction */
    /* 7A3E8 80089BE8 080042AF */  sw         $v0, 0x8($k0) /* handwritten instruction */
    /* 7A3EC 80089BEC 00680240 */  mfc0       $v0, $13 /* handwritten instruction */
    /* 7A3F0 80089BF0 0C0043AF */  sw         $v1, 0xC($k0) /* handwritten instruction */
    /* 7A3F4 80089BF4 00700340 */  mfc0       $v1, $14 /* handwritten instruction */
    /* 7A3F8 80089BF8 7C005FAF */  sw         $ra, 0x7C($k0) /* handwritten instruction */
endlabel func_80089BCC
  alabel D_80089BFC
    /* 7A3FC 80089BFC 00000000 */  nop
