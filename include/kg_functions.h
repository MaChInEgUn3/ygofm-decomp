/* Prototypes from krystalgamer/memories-decomp, as the ported units in src/
 * declare them. Included ONLY by those units, like kg_types.h: a
 * non-ported unit never sees this file. Built by
 * tools_src/kg_decls.py fold-externs from the units' own inline copies,
 * in first-seen order over the sorted file names, each text once. A
 * symbol two ported units declare differently is NOT here -- that
 * disagreement is a codegen knob (.data, volatile, const, width,
 * array-versus-scalar) and it stays inline in the unit that wants it. */
#ifndef KG_FUNCTIONS_H
#define KG_FUNCTIONS_H

#include "kg_types.h"

extern DISPENV *func_8007FEFC(DISPENV *env);
extern int func_8007F350(int mode);
void    func_80085D80(GsOT * ot);
void    func_800862C0(PACKET * outpacketp);
void    func_80085DB0(unsigned short offset, unsigned short point, GsOT * otp);
GsOT   *func_80085E10(GsOT * ot_src, GsOT * ot_dest);
void    func_80085500(void);
int     func_80085320(void);
void func_80012E5C(void);
void func_800359B0(void);
extern void func_80086DC8();
extern void func_800878D0(long h);
void    func_80084DD0(unsigned short x, unsigned short y, unsigned short intmode,
		              unsigned short dith, unsigned short varmmode);
void    func_80085740(void);
void    func_800856A0(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1);
void    func_800855B0(long x, long y);
void func_8008B7B0( long val );
extern void func_8008E5C0(unsigned int);
void func_800136E4(void);
void func_8003CBE8(void);
void func_80013154(struct GraphicsFrameBuffer *base);
extern u32 *func_8007EC68(int id);
void func_80012D4C(void);
void func_8003CB7C(void);
void func_80013360(void);
int func_8007E3D0(void *madr, int size);
CdlCB func_8007E860(CdlCB func);
void func_8007DDD4( void );
extern int func_80081DE8(RECT *rect, u32 *p);
extern unsigned long func_80077150 (unsigned char *addr, unsigned long size);
extern unsigned long func_800771B0 (unsigned long addr);
int func_8007B1F4( u8 com, u8* param, DslCB cbsync, int count );
int func_8007B468( u8 mode, DslLOC* pos, u8 com, DslCB func, int count );
extern long func_80077240 (long flag);
CdlLOC *func_8007E600(s32 sector, CdlLOC *position);
void func_800140A0(u8 event);
void func_80014134(u8 event);
void func_800141A8(u8 event);
void func_80014220(s32 event);
void func_8001455C(void);
extern u8 D_8009B11C_byte asm("D_8009B11C");
extern void (*D_8009B0F0)(void);
extern void (*D_8009B120)(void);
void func_80014294(u8 event);
void func_80014308(u8 event);
void func_80014390(u8 event, u8 *result);
void func_800144B8(void);
extern MATRIX *func_80088C50(SVECTOR *r,MATRIX *m);
extern MATRIX *func_80087670(MATRIX *m,VECTOR *v);
extern void func_80089CC0(SVECTOR *v0,SVECTOR *v1,long *flag);
extern long func_800879A0(long sxy0,long sxy1,long sxy2);
extern long func_80087C70(SVECTOR *v0,SVECTOR *v1,CVECTOR *v2,
			long *sxy,CVECTOR *v3,long *flag);
extern void func_80082840(void *p, int abe) ;
void    func_80084320(void *pp, GsOT * ot, unsigned short pri);
void    func_80085600(MATRIX * mp);
void    func_800855D0(MATRIX * mp);
void func_80015EF4(void *record, POLY_GT4 *prim, POLY_FT4 *sprite, s32 *color);
void func_800171A8(FileTransferDescriptor *d, s32 stage);
void func_800245A0(void *arg0, void *arg1);

#endif /* KG_FUNCTIONS_H */
