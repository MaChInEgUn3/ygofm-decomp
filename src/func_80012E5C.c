/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/graphics_frame.c (Graphics_BeginFrame), profile gcc_2_8_1_g8_split_comm.
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
	u32	tag;
	u32	code[15];
} DR_ENV;
typedef struct {
	RECT	clip;		 
	short	ofs[2];		 
	RECT	tw;		 
	u16 tpage;		 
	u8	dtd;		 
	u8	dfe;		 
	u8	isbg;		 
	u8	r0, g0, b0;	 
	DR_ENV	dr_env;		 
} DRAWENV;
typedef struct {
	RECT	disp;		 
	RECT	screen;		 
	u8	isinter;	 
	u8	isrgb24;	 
	u8	pad0, pad1;	 
} DISPENV;
extern DISPENV *func_8007FEFC(DISPENV *env);
extern int func_8007F350(int mode);
typedef unsigned char PACKET;
typedef struct {
	unsigned p:24;
	unsigned char num:8;
}       GsOT_TAG;
typedef struct {
	unsigned long length;
	GsOT_TAG *org;
	unsigned long offset;
	unsigned long point;
	GsOT_TAG *tag;
}       GsOT;
void    func_80085D80(GsOT * ot);
void    func_800862C0(PACKET * outpacketp);
void    func_80085DB0(unsigned short offset, unsigned short point, GsOT * otp);
GsOT   *func_80085E10(GsOT * ot_src, GsOT * ot_dest);
void    func_80085500(void);
int     func_80085320(void);
extern 
extern u8 D_8009B318 __attribute__((section(".data")));
extern u16 D_8009B098;
extern DISPENV D_800E9D28;
extern u8 D_8009B0AC;
extern DRAWENV D_800FE048[];
extern u8 D_8009B142 __attribute__((section(".data")));
extern u8 D_8009B143 __attribute__((section(".data")));
extern u8 D_8009B144 __attribute__((section(".data")));
typedef struct GraphicsFrameBuffer GraphicsFrameBuffer;
extern GraphicsFrameBuffer D_8009B4A8[];
extern GraphicsFrameBuffer *D_8009B0B4;
extern u8 D_800A5768[];
extern u8 D_8009B0AD;
extern u8 D_8009B0D0;
extern u8 D_8009B0A8;
extern u8 D_8009B0A0[4];
void func_80012E5C(void);
extern u8 D_8009B141 __attribute__((section(".data")));
struct GraphicsFrameBuffer {
    u8 ordering_table_tags[0x5110];
    GsOT ordering_tables[4];
};
extern GsOT *D_800E9D90[4];
extern u8 D_8009AFA2 __attribute__((section(".data")));
void func_800359B0(void);
extern u8 D_8009B0A8;
extern u8 D_8009B0AD;
extern u8 D_8009B0D0;
extern u16 D_8009B098;
extern u8 D_8009B0A0[4];
extern u8 D_8009B0AC;
extern GraphicsFrameBuffer *D_8009B0B4;
void func_80012E5C(void)
{
    s32 i;
    GsOT **slot;
    s32 idx;
    GsOT *ptr;
    u8 *arg;
    GsOT **base;

    if (D_8009B0A8 == 0) {
        D_800FE048[0].isbg = D_8009B0D0;
        D_800FE048[0].dtd = D_8009B0AD;
        D_800FE048[0].r0 = D_8009B144;
        D_800FE048[0].g0 = D_8009B143;
        D_800FE048[0].b0 = D_8009B142;
        func_80085500();
        if ((D_8009B098 & 0x2000) != 0) {
            func_8007FEFC(&D_800E9D28);
        }
    }
    func_8007F350(1);
    if ((D_8009B318 & 0x80) != 0) {
        func_800359B0();
    }
    if ((D_8009B318 & 0x80) == 0) {
        if (D_8009B141 != 0) {
            func_80085E10(&D_8009B0B4->ordering_tables[1],
                     &D_8009B0B4->ordering_tables[0]);
            if ((D_8009B141 & 0x80 ) == 0) {
                func_80085E10(&D_8009B0B4->ordering_tables[2],
                         &D_8009B0B4->ordering_tables[0]);
                func_80085E10(&D_8009B0B4->ordering_tables[3],
                         &D_8009B0B4->ordering_tables[0]);
            }
            func_80085D80(&D_8009B0B4->ordering_tables[0]);
        }
    }
    idx = func_80085320();
    i = 3;
    D_8009B0AC = idx;
    arg = &D_800A5768[
        D_8009B0AC * 140000 
    ];
    D_8009AFA2 = idx;
    D_8009B0B4 =
        &D_8009B4A8[D_8009B0AC];
    func_800862C0((PACKET *)arg);
    base = D_800E9D90;
    slot = base + 3;
    do {
        ptr = &D_8009B0B4->ordering_tables[i];
        *slot = ptr;
        slot--;
        ptr->length = D_8009B0A0[i];
        func_80085DB0(0, 0, ptr);
        i--;
    } while (i >= 0);
}
