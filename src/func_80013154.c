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
extern void func_80086DC8();
extern void func_800878D0(long h);
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
extern int func_8007F350(int mode);
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
void    func_80084DD0(unsigned short x, unsigned short y, unsigned short intmode,
		              unsigned short dith, unsigned short varmmode);
void    func_80085740(void);
void    func_80085DB0(unsigned short offset, unsigned short point, GsOT * otp);
void    func_800856A0(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1);
void    func_800855B0(long x, long y);
void func_8008B7B0( long val );
extern void func_8008E5C0(unsigned int);
extern volatile u8 D_8009B14A __attribute__((section(".data")));
extern volatile u8 D_8009B14B __attribute__((section(".data")));
extern volatile u8 D_8009B14C __attribute__((section(".data")));
void func_800136E4(void);
extern DISPENV D_800E9D28;
extern volatile DRAWENV D_800FE048[];
extern DISPENV D_800FE0A8;
extern volatile u8 D_8009B142 __attribute__((section(".data")));
extern volatile u8 D_8009B143 __attribute__((section(".data")));
extern volatile u8 D_8009B144 __attribute__((section(".data")));
typedef struct GraphicsFrameBuffer GraphicsFrameBuffer;
extern u8 D_8009B0AD;
extern u8 D_8009B0D0;
extern u8 D_8009B0A8;
extern volatile u8 D_8009B0A0;
extern volatile u8 D_8009B0A1;
extern volatile u8 D_8009B0A2;
struct GraphicsFrameBuffer {
    u8 ordering_table_tags[0x5110];
    GsOT ordering_tables[4];
};
void func_8003CBE8(void);
extern volatile u8 D_8009B0A3;
struct GraphicsFrameBuffer;
void func_80013154(struct GraphicsFrameBuffer *base);
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
