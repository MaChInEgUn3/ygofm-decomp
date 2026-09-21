/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/movie_frame_pipeline.c (Movie_WaitAndDecodeFrame), profile gcc_2_8_1_g8.
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
	u8 minute;		 
	u8 second;		 
	u8 sector;		 
	u8 track;		 
} CdlLOC;
typedef struct {
    u16 id;
    u16 type;
    u16 secCount;
    u16 nSectors;
    u32  frameCount;
    u32  frameSize;

    u16 width;
    u16 height;
    u32  dummy1;
    u32  dummy2;
    CdlLOC  loc;
} StHEADER;
u32	func_800784D0(u32 *base);
u32	func_800785C0(u32 **addr,u32 **header);
int     func_800783DC(CdlLOC *loc);
int func_800781F0(CdlLOC *p);
s32 func_8005BFC8(s32 resync);
extern u8 D_8009B060;
extern u8 D_8009B063;
extern u8 D_8009B064;
extern u8 D_8009B066;
extern u32 D_8009B068;
extern u32 D_8009B06C;
extern u32 D_8009B070;
typedef struct {
    u8 head[0x2400];
    RECT slots[4];
    RECT frame;
    RECT strip;
} MovieWorkArea;
extern u8 *D_8009B498;
extern CdlLOC D_8009B49C;
typedef	u16 DECDCTTAB[34816];
extern int func_800902A0(u32 *bs, u32 *buf, DECDCTTAB table);
void func_8005C62C(CdlLOC *loc);
int func_80074170(int mode);
s32 func_8005BFC8(s32 resync) {
    u32 *ring;
    StHEADER *hdr;
    s32 timeouts;
    s32 now;
    s32 last;
     


    s32 set;
    MovieWorkArea *rects;
    StHEADER *header;
    u32 width;
    u32 frame_width;
    u16 height;
    s32 columns;
    s32 wide;
    u32 *base;

    if (D_8009B063 != 0) {
        return 1;
    }
    set = 1;
    if (resync != 0) {
        D_8009B068 = func_800783DC(&D_8009B49C);
    }
    for (;;) {
        last = func_80074170(-1);
        timeouts = 0;
        for (;;) {
            if (func_800785C0(&ring, (u32 **)&hdr) == 0) {
                break;
            }
            now = func_80074170(-1);
            if (now - last < 60) {
                continue;
            }
            if (D_8009B063 != 0) {
                goto fail;
            }
            timeouts++;
            if (resync != 0 || timeouts >= 10) {
                func_8005C62C(&D_8009B49C);
                timeouts = 0;
            }
             


            last = now;
            continue;
         


        fail:
            return 1;
        }

        if (func_800781F0(&hdr->loc) + hdr->nSectors * 2 >= D_8009B070) {
            D_8009B063 = set;
        }
        if (D_8009B068 >= D_8009B06C) {
            D_8009B064 = set;
        }
        if (hdr->frameCount >= D_8009B06C) {
            D_8009B064 = set;
        }
        if (D_8009B063 == 0) {
            if (hdr->frameCount < D_8009B068) {
                func_800784D0(ring);
                continue;
            }
        }
        break;
    }
    D_8009B066 = (D_8009B066 + 1) & 1;
    func_800902A0(ring, (u32 *)(D_8009B498 + 0x1B000 + D_8009B066 * 0xE000),
               (u16 *)D_8009B498);

    rects = (MovieWorkArea *)(D_8009B498 + 0x40000);
    width = hdr->width;
    frame_width = D_8009B060 != 0 ? width * 3 / 2 : width;
    columns = 0x10;
    *(u16 *)&rects->frame.w = frame_width;

     

    header = hdr;
    rects = (MovieWorkArea *)(D_8009B498 + 0x40000);
    height = header->height;
    wide = D_8009B060;
    *(u16 *)&rects->frame.h = height;
    if (wide != 0) {
        columns = 0x18;
    }
    base = ring;
    *(u16 *)&rects->strip.w = columns;
    *(u16 *)&rects->strip.h = header->height;
    func_800784D0(base);
    return 0;
}
