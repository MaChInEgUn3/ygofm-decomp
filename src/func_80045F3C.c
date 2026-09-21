/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_runtime.c (SD_UpdateRuntime), profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern void func_80076ED0 (long on_off, unsigned long voice_bit);
extern void func_800773C4 (char *status);
extern SDValue *D_8009B45C;
void func_80045C98(void);
void func_80045F3C(void);
void func_80045514(void);
s16 func_80049F50(void);
void func_80049C40(s32 value);
void func_80045F3C(void)
{
    SDValue *p;
    SDCommand *e;
    s32 mask;
    s32 i;
    s32 off;
    s32 value;
    SDValue *loop_state;
    SDValue *q;
    SDValue *r;

    func_800773C4((char *)D_8009B45C->field_15D8);
    p = D_8009B45C;
    mask = (p->field_15EC == 3) << 20 ;
    if (p->field_15ED == 3) {
        mask |= (1 << 20 )  << 1;
    }
    if (p->field_15EE == 3) {
        mask |= (1 << 20 )  << 2;
    }
    if (p->field_15EF == 3) {
        mask |= (1 << 20 )  << 3;
    }
    if (mask != 0) {
        func_80076ED0(0, mask);
    }

    p = D_8009B45C;
    if ((p->flags_0040 & 0x80) != 0 &&
        p->field_157E != -1 &&
        func_80049F50() != 1) {
        func_80049C40(D_8009B45C->field_157E);
        p = D_8009B45C;
        value = p->flags_0040;
        p->field_1588 = -0x80;
        p->field_158A = 0;
        value &= 0xFF7F;
        p->flags_0040 = value;
    }

    func_80045C98();
    p = D_8009B45C;
    if (p->field_007C != 0) {
        func_80045514();
        return;
    }
    if (p->command_count == 0) {
        return;
    }
    e = &p->commands.c[0];
     

    value = p->commands.c[0].command;
    switch (value) {
    case 0x44:
        if (p->field_1588 == 0) {
            p->field_1588 = (u16)e->field_0008;
            p->field_1584 = (u8)e->field_0002;
        }
        break;
    case 0x45:
        if (p->field_1588 == 0) {
            p->field_1588 = (u16)e->field_0008;
            p->field_1584 = (u8)e->field_0002;
        }
        break;
    case 0x29:
        if (p->field_0512 == 0) {
            p->field_0512 = (u16)e->field_0008;
            p->field_0049 = (u8)e->field_0002;
        }
        break;
    case 0x2A:
        if (p->field_0512 == 0) {
            p->field_0512 = (u16)e->field_0008;
            p->field_0049 = (u8)e->field_0002;
        }
        break;
    }

    p = D_8009B45C;
    p->field_007C = e->command;
    D_8009B45C->field_007D = 0;
    p = D_8009B45C;
    p->field_004E = (u16)e->field_0002;
    p->field_0050 = e->field_0004;
    p->field_0054 = e->field_0008;
    p->field_0058 = e->field_000C;
    p->field_007E = e->field_0001;
     

    r = D_8009B45C;
    *(SDCommandTail *)&r->field_005C[0] = *(SDCommandTail *)&e->field_0010;
    q = D_8009B45C;
    q->field_15F4 = 8;
    q->command_count = q->command_count - 1;
    func_80045514();

    loop_state = D_8009B45C;
    e++;
    i = 0;
    if (loop_state->command_count <= 0) {
        return;
    }
    off = 0;
    do {
         



        loop_state->commands.b[off] = e->command;
        *(SDCommand *)((u8 *)D_8009B45C + off + 0x80 ) =
            *e;
        off += sizeof(SDCommand);
        loop_state = D_8009B45C;
        i += 1;
        e++;
    } while (i < loop_state->command_count);
}
