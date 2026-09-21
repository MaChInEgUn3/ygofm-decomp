/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_voice_envelope.c (SD_SetVoiceEnvelopeFromTone), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern void func_80077450 (SpuVoiceAttr *arg);
extern SDSecondaryState *D_8009B458 __attribute__((section(".data")));
extern const s32 D_80011434[20];
void func_8004A6F8(s32 index, SDToneEnvelopeView *tone);
void func_8004A6F8(s32 index, SDToneEnvelopeView *tone)
{
    SDSecondaryState *p = D_8009B458;

    p->voice_attr.mask =
        (0x01 <<  8)  | (0x01 << 17)  | (0x01 << 18) ;
    p->voice_attr.voice = D_80011434[index];
    p->voice_attr.adsr1 = tone->adsr1;
    p->voice_attr.adsr2 = tone->adsr2;
    p->voice_attr.a_mode = tone->a_mode;
    func_80077450(&p->voice_attr);
}
