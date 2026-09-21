/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_voice_data.c (SD_InitSecondaryRuntime), profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern long func_80075BE0 (long on_off);
extern long func_80075DE0 (SpuReverbAttr *attr);
extern long func_80076790 (long on_off);
extern SDValue *D_8009B45C;
s32 func_80049600(u32 count);
void func_80048F14(void);
void func_80049544(void);
void func_80049594(s32 value);
void func_80048F14(void)
{
    SpuReverbAttr packet;
     

    SDValue *a;
    SDValue *b;
    SDValue *c;

    func_80076790(1 );
    func_80075BE0(1 );
    packet.mask = (0x01 <<  0)  | (0x01 <<  1)  | (0x01 <<  2) ;
    packet.mode = 2 ;
    packet.depth.left = 0x7FFF;
    packet.depth.right = 0x7FFF;
    func_80075DE0(&packet);
    b = D_8009B45C;
    b->field_1586 = 0;
    b->field_1588 = 0;
    b->field_158A = 0;
    a = D_8009B45C;
    a->field_1580 = 0xFF;
    a->field_1584 = 0xFF;
    c = D_8009B45C;
    a->field_1582 = 0;
    c->field_1578 = -1;
    c->field_157A = -1;
    c->field_157C = -1;
    c->field_157E = -1;
    c->music_track = (u16 *)0x801EA800;
    c->field_1560 = (u8 *)0x801E2000;
    c->music_track[0] = 0xFFFF;
    c->music_track[1] = 0;
    *(s32 *)&c->music_track[2] = 0;
    *(s32 *)&c->music_track[4] = 0;
    *(s32 *)&c->music_track[6] = 0x40000;
    func_80049594(2);
    func_80049600(0x14);
    func_80049544();
}
