/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/main_services.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef struct {
	short x, y;		 
	short w, h;		 
} RECT;
typedef struct {
	RECT	disp;		 
	RECT	screen;		 
	u8	isinter;	 
	u8	isrgb24;	 
	u8	pad0, pad1;	 
} DISPENV;
extern u32 *func_8007EC68(int id);
extern u16 D_8009B098;
extern DISPENV D_800E9D28;
void func_80012D4C(void);
extern volatile u16 D_8009B398 __attribute__((section(".data")));
extern volatile u16 D_8009B3A4 __attribute__((section(".data")));
void func_8003CB7C(void);
void func_80013360(void);
void func_80013360(void)
{
    RECT *origin;
    RECT *r;

    origin = &D_800E9D28.disp;
    origin->x = 0;
    origin->y = 0;
    D_8009B098 |= 0x2000;

    func_80012D4C();
    r = origin;
    while ((D_8009B398 & 0x800 ) == 0) {
        s32 step;

        if (D_8009B3A4 & 0xF000 ) {
            step = 2;
            if (D_8009B3A4 & 0x40 ) {
                step = 4;
            }
            if (D_8009B3A4 & 0x2000 ) {
                r->x += step;
            }
            if (D_8009B3A4 & 0x8000 ) {
                r->x -= step;
            }
            if (D_8009B3A4 & 0x1000 ) {
                r->y -= step;
            }
            if (D_8009B3A4 & 0x4000 ) {
                r->y += step;
            }
        }
        func_8007EC68(-1);
        func_80012D4C();
    }

    D_8009B098 &= 0xDFFF;
    func_8003CB7C();
}
