/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

typedef struct {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} Rect;

struct Obj {
    u8 pad0[0x30];
    u16 f30;
    u16 f32;
};

extern s32 func_80082324(s32 ms);
extern void func_80081ED4(Rect *rect, u16 *table);
extern void func_80081DE8(Rect *rect, u16 *table);
extern u8 D_8009B0AC[9];
#define D_8009B0AC (D_8009B0AC[0])
extern Rect D_800E9D70[2];
#define D_800E9D70 (D_800E9D70[0])
extern u16 D_8015C424[0x6B30];

void func_8001944C(struct Obj *arg0) {
    s32 page;
    register u16 *table asm("s0");

    do {
    } while (func_80082324(0xA) != 0);
    __asm__ volatile ("");

    page = 0;
    if (D_8009B0AC == 0) {
        page = 0x140;
    }

    {
        register u8 *rect_page asm("v1") = (u8 *)0x800F0000;
        Rect *rect;

        __asm__ volatile ("" : "+r" (rect_page));
        rect = (Rect *)(rect_page - 0x6290);
        __asm__ volatile ("" : "+r" (rect));
        table = D_8015C424;
        __asm__ volatile ("" : "+r" (table));
        ((Rect *)(rect_page - 0x6290))->x = (s16)(arg0->f30 + page);
        rect->y = (u16)arg0->f32;
        rect->w = 0x8C;
        rect->h = 0xC4;
        func_80081ED4(rect, table);
    }

    {
        register u16 *p asm("a1") = table;
        register s32 n asm("a2") = 0x6B30;

        __asm__ volatile ("" : "+r" (p));
        __asm__ volatile ("" : "+r" (n));
        do {
            n--;
            *p |= 0x8000;
            p++;
        } while (n != 0);
    }

    {
        register u8 *table_page asm("v1") = (u8 *)0x80160000;
        u16 *fields;
        register u8 *rect_page asm("a2");
        Rect *rect;

        __asm__ volatile ("" : "+r" (table_page));
        fields = (u16 *)(table_page - 0x3BDC);
        __asm__ volatile ("" : "+r" (fields));
        rect_page = (u8 *)0x800F0000;
        __asm__ volatile ("" : "+r" (rect_page));
        rect = (Rect *)(rect_page - 0x6290);
        __asm__ volatile ("" : "+r" (rect));
        fields[0x6B2E] = 0;
        fields[0x6B2F] = 0;
        fields[0x6AA5] = 0;
        fields[0x6AA4] = 0;
        fields[0x6AA3] = 0;
        fields[0x6A18] = 0;
        fields[0x117] = 0;
        fields[0x8C] = 0;
        fields[0x8A] = 0;
        fields[0x8B] = 0;
        fields[0x1] = 0;
        *(u16 *)(rect_page - 0x6290) = 0x140;
        rect->y = 0x100;
        rect->w = 0x8C;
        *(u16 *)(table_page - 0x3BDC) = 0;
        rect->h = 0xC4;
        func_80081DE8(rect, fields);
    }
}
