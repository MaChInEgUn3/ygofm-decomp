/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/main_services.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern volatile DRAWENV D_800FE048[];
extern volatile u8 D_8009B142 __attribute__((section(".data")));
extern volatile u8 D_8009B143 __attribute__((section(".data")));
extern volatile u8 D_8009B144 __attribute__((section(".data")));
extern volatile u8 D_8009B0A0;
void func_80013154(GraphicsFrameBuffer *base)
{
    GraphicsFrameBuffer *buf;
    s32 k;
    s32 six;
    u16 count;

    func_8007F350(0);
    func_80084DD0(320 , 240 , 4, 1, 0);
    func_800856A0(0, 0, 0x140, 0);
    six = 6;
    buf = base;
    D_8009B0AD = 1;
    D_8009B0D0 = 1;
    D_8009B0A8 = 0;
    D_8009B14C = 1;
    D_8009B144 = 1;
    D_8009B14B = 1;
    D_8009B143 = 1;
    D_8009B14A = 1;
    D_8009B142 = 1;
    D_800FE048[0].isbg = 1;
    D_800FE048[0].dtd = 1;
    D_800FE048[0].r0 = 1;
    D_800FE048[0].g0 = 1;
    D_800FE048[0].b0 = 1;
    count = six;
    D_8009B0A0 = 2;
    D_8009B0A1 = count;
    D_8009B0A2 = 0xC;
    D_8009B0A3 = count;
next:
    k = 3;
    buf->ordering_tables[0].length = 2;
    buf->ordering_tables[1].org =
        (GsOT_TAG *)(buf->ordering_table_tags + 0x10);
    buf->ordering_tables[2].length = 0xC;
    buf->ordering_tables[2].org =
        (GsOT_TAG *)(buf->ordering_table_tags + 0x110);
    buf->ordering_tables[0].org = (GsOT_TAG *)buf->ordering_table_tags;
    buf->ordering_tables[1].length = six;
    buf->ordering_tables[3].length = six;
    buf->ordering_tables[3].org =
        (GsOT_TAG *)(buf->ordering_table_tags + 0x4110);
    do {
        func_80085DB0(0, k, &buf->ordering_tables[k]);
        k--;
    } while (k >= 0);
    buf++;
    if ((s32)buf < (s32)(base + 2)) {
        goto next;
    }
    D_800E9D28 = D_800FE0A8;
    func_80086DC8();
    func_80085740();
    func_800855B0(0, 0);
    func_800878D0(0x12C );
    func_8003CBE8();
    func_8008B7B0(1);
    func_800136E4();
    func_8008E5C0(0x56 );
}
