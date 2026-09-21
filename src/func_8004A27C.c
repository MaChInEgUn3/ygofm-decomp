/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_voice_volume.c (SD_SetVoiceVolume), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern void func_80077450 (SpuVoiceAttr *arg);
extern SDSecondaryState *D_8009B458 __attribute__((section(".data")));
extern const s32 D_80011434[20];
void func_8004A27C(s32 voice, s32 left, s32 right);
void func_8004A27C(s32 voice, s32 left, s32 right) {
    SDSecondaryState *s;

    s = D_8009B458;
    s->voice_attr.mask = (0x01 <<  0)  | (0x01 <<  1)  | (0x01 <<  2)  | (0x01 <<  3) ;
    s->voice_attr.voice = D_80011434[voice];
    s->voice_attr.volume.left = (left * (u16)s->field_0514) >> 7;
    s->voice_attr.volume.right = (right * (u16)s->field_0516) >> 7;
    s->voice_attr.volmode.left = 0 ;
    s->voice_attr.volmode.right = 0 ;
    func_80077450(&s->voice_attr);
}
