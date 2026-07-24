nonmatching func_8008D560, 0x108

glabel func_8008D560
    /* 7DD60 8008D560 1080043C */  lui        $a0, %hi(D_800FE3F8)
    /* 7DD64 8008D564 F8E3848C */  lw         $a0, %lo(D_800FE3F8)($a0)
    /* 7DD68 8008D568 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7DD6C 8008D56C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7DD70 8008D570 20CE010C */  jal        func_80073880
    /* 7DD74 8008D574 00000000 */   nop
    /* 7DD78 8008D578 1080043C */  lui        $a0, %hi(D_800FE3FC)
    /* 7DD7C 8008D57C FCE3848C */  lw         $a0, %lo(D_800FE3FC)($a0)
    /* 7DD80 8008D580 20CE010C */  jal        func_80073880
    /* 7DD84 8008D584 00000000 */   nop
    /* 7DD88 8008D588 1080043C */  lui        $a0, %hi(D_800FE400)
    /* 7DD8C 8008D58C 00E4848C */  lw         $a0, %lo(D_800FE400)($a0)
    /* 7DD90 8008D590 20CE010C */  jal        func_80073880
    /* 7DD94 8008D594 00000000 */   nop
    /* 7DD98 8008D598 1080043C */  lui        $a0, %hi(D_800FE404)
    /* 7DD9C 8008D59C 04E4848C */  lw         $a0, %lo(D_800FE404)($a0)
    /* 7DDA0 8008D5A0 20CE010C */  jal        func_80073880
    /* 7DDA4 8008D5A4 00000000 */   nop
    /* 7DDA8 8008D5A8 1080043C */  lui        $a0, %hi(D_800FE408)
    /* 7DDAC 8008D5AC 08E4848C */  lw         $a0, %lo(D_800FE408)($a0)
    /* 7DDB0 8008D5B0 20CE010C */  jal        func_80073880
    /* 7DDB4 8008D5B4 00000000 */   nop
    /* 7DDB8 8008D5B8 1080043C */  lui        $a0, %hi(D_800FE40C)
    /* 7DDBC 8008D5BC 0CE4848C */  lw         $a0, %lo(D_800FE40C)($a0)
    /* 7DDC0 8008D5C0 20CE010C */  jal        func_80073880
    /* 7DDC4 8008D5C4 00000000 */   nop
    /* 7DDC8 8008D5C8 1080043C */  lui        $a0, %hi(D_800FE410)
    /* 7DDCC 8008D5CC 10E4848C */  lw         $a0, %lo(D_800FE410)($a0)
    /* 7DDD0 8008D5D0 20CE010C */  jal        func_80073880
    /* 7DDD4 8008D5D4 00000000 */   nop
    /* 7DDD8 8008D5D8 1080043C */  lui        $a0, %hi(D_800FE414)
    /* 7DDDC 8008D5DC 14E4848C */  lw         $a0, %lo(D_800FE414)($a0)
    /* 7DDE0 8008D5E0 20CE010C */  jal        func_80073880
    /* 7DDE4 8008D5E4 00000000 */   nop
    /* 7DDE8 8008D5E8 1080013C */  lui        $at, %hi(D_800FE424)
    /* 7DDEC 8008D5EC 24E420AC */  sw         $zero, %lo(D_800FE424)($at)
    /* 7DDF0 8008D5F0 1080023C */  lui        $v0, %hi(D_800FE424)
    /* 7DDF4 8008D5F4 24E4428C */  lw         $v0, %lo(D_800FE424)($v0)
    /* 7DDF8 8008D5F8 1080013C */  lui        $at, %hi(D_800FE420)
    /* 7DDFC 8008D5FC 20E422AC */  sw         $v0, %lo(D_800FE420)($at)
    /* 7DE00 8008D600 1080023C */  lui        $v0, %hi(D_800FE420)
    /* 7DE04 8008D604 20E4428C */  lw         $v0, %lo(D_800FE420)($v0)
    /* 7DE08 8008D608 1080013C */  lui        $at, %hi(D_800FE41C)
    /* 7DE0C 8008D60C 1CE422AC */  sw         $v0, %lo(D_800FE41C)($at)
    /* 7DE10 8008D610 1080023C */  lui        $v0, %hi(D_800FE41C)
    /* 7DE14 8008D614 1CE4428C */  lw         $v0, %lo(D_800FE41C)($v0)
    /* 7DE18 8008D618 1080013C */  lui        $at, %hi(D_800FE418)
    /* 7DE1C 8008D61C 18E422AC */  sw         $v0, %lo(D_800FE418)($at)
    /* 7DE20 8008D620 1080013C */  lui        $at, %hi(D_800FE434)
    /* 7DE24 8008D624 34E420AC */  sw         $zero, %lo(D_800FE434)($at)
    /* 7DE28 8008D628 1080023C */  lui        $v0, %hi(D_800FE434)
    /* 7DE2C 8008D62C 34E4428C */  lw         $v0, %lo(D_800FE434)($v0)
    /* 7DE30 8008D630 1080013C */  lui        $at, %hi(D_800FE430)
    /* 7DE34 8008D634 30E422AC */  sw         $v0, %lo(D_800FE430)($at)
    /* 7DE38 8008D638 1080023C */  lui        $v0, %hi(D_800FE430)
    /* 7DE3C 8008D63C 30E4428C */  lw         $v0, %lo(D_800FE430)($v0)
    /* 7DE40 8008D640 1080013C */  lui        $at, %hi(D_800FE42C)
    /* 7DE44 8008D644 2CE422AC */  sw         $v0, %lo(D_800FE42C)($at)
    /* 7DE48 8008D648 1080023C */  lui        $v0, %hi(D_800FE42C)
    /* 7DE4C 8008D64C 2CE4428C */  lw         $v0, %lo(D_800FE42C)($v0)
    /* 7DE50 8008D650 1080013C */  lui        $at, %hi(D_800FE428)
    /* 7DE54 8008D654 28E422AC */  sw         $v0, %lo(D_800FE428)($at)
    /* 7DE58 8008D658 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7DE5C 8008D65C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7DE60 8008D660 0800E003 */  jr         $ra
    /* 7DE64 8008D664 00000000 */   nop
endlabel func_8008D560
