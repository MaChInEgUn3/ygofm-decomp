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
void func_800175A0(void);
void func_80016E70(DisplayObject *widget);
void func_8001778C(void);
void func_800164FC(void);
void func_800176D0(void);
void func_80017708(void);
void func_80012D84(s32 count);
s32 func_8004002C(void);
void *func_800400AC(s32 index, s32 key);
void func_800404CC(
    void *object, s32 x, s32 y, s32 field_67, s32 field_68,
    s32 field_69, s32 color, s32 texture
);
FileTransferDescriptor *func_80014E1C(
    s32, u8 *, s32, s32, FileTransferCallback, s32, s32
);
void func_800137E4(void);
s32 func_800428EC(DisplayObject *object, s8 value);
void func_80042918(DisplayObject *object);
void func_8001352C(void);
extern void (*D_800E9DB0[4])(void);
void func_8004763C(void);
s32 func_80047AD0(s32 value);
void func_800179F4(void);
void func_8001755C(void);
void func_8002C598(void);
void func_80029574(s32 index);
void func_80035668(u32 value);
void func_800178BC(void);
s32 func_800181EC(CardObject *object);
u8 *func_8002C604(s32 id);
DuelEffectRequest *func_8002C68C(s32 id);
void func_80024954(DuelCardRecord *object);
void func_80024D34(s32 slot, s32 card_id);
void func_8001825C(void);
void func_800157DC(void);
void func_8003FF08(u32);
void func_8003FEE0(u32);
void func_80018080(DuelCardDisplayObject *object);
void func_80018608(void);
void func_80024734(void);
void func_80024824(void);
void func_80018FEC(void);
s32 func_800358FC(s32 divisor);
void func_800156DC(void);
void func_80015C84();
void func_8004036C(void *object);
void *func_80042B40(s32 value);
void func_800472A8(s32 arg0);
void func_8003FF58(s32);
void func_8003FF88(u32);
void func_80059C18(s32 value);
extern int  func_8008E590(void);
void func_80024914(DuelCardRecord *object);
void func_8001944C(DisplayObject *object);
DisplayObject *func_80019564(DisplayObjectConfigView *source);
void func_80026BA4(s32 value, s32 flag);
u8 *func_800291E0(s32 index, s32 x, s32 y);
void func_80029528(s32 index);
FileTransferDescriptor *func_80029164(s32 slot, s32 value);
void func_80019608(void);
void func_800429D8(DisplayObjectVelocity *object);
void func_80042A00(DisplayObjectVelocity *object);
void func_80042A78(DisplayObjectVelocity *object);
s32 func_80042AD8(s32 value, s32 target, s32 step);
s32 func_80042B08(s32 value, s32 step);
void func_80043178(DisplayObjectSnapshot *object);
void func_8004318C(
    DisplayObjectPosition *object, s32 arg1, s32 arg2, s32 arg3);
s32 func_800170C8(DuelCardRecord *card);
u8 *func_80017F04(DuelCardRecord *arg0, s32 arg1, s32 arg2);
s32 func_80019A08(s32 equipment, s32 monster);
s32 func_80019A60(s32 card_a, s32 card_b);
u8 *func_800249E0(s32, s32);
extern DuelCardStagingDeckView D_8015C424_cards asm("D_8015C424");
extern int func_80086770(int a);
extern int func_800866A0(int a);
extern int func_80081ED4(RECT *rect, u32 *p);
void func_80019CC8(void *card_id);
void func_80019BA0(
    DisplayObject *object, u8 field_21, s16 x, s16 y
);
void func_80035B7C(struct DuelEffectChannel *record);
void func_80019D18(void);
void func_80019BD0(DisplayObject *object);
void func_80043230(
    DisplayObjectPosition *object,
    int target_x,
    int target_y,
    int phase);
void func_8001B170(void);
s32 func_8001F364(void);
s16 func_8001B0CC(s32 index);
s32 func_8003700C(struct DuelEffectChannel *record);
void *func_80035C38(
    s32 index, s32 string_id, s32 x, s32 y, s32 width, s32 height, s32 flags
);
void func_80039794(void);
s32 func_80025028(s32 card_id);
void func_8003B6AC(s32 range, s32 layout);
DuelCardDisplayObject *func_80018004(
    DuelCardRecord *card, s32 x, s32 y
);
extern int func_8008E870(const char *fmt, ...);
void func_8001BD88(void);
void func_800240B0(DuelCardPickCursor *cursor);
void func_8001B938(DuelSelectionRecord *selection);
void func_8001BAF0(void);
void func_8001B8B8(DuelSelectionRecord *side);
s32 func_80024060(DuelCursorStatus *object);
s32 func_80024088(DuelFieldCursor *cursor, s8 dir);
void func_80023144(DuelFieldDisplaySource *source, s32 index);
void *func_80040468(struct DisplayObject *object, s32 field_67,
                    s32 field_68, s32 field_69, s32 color, s32 texture);
void func_8001B780(DuelHandStackState *state);
void func_8001B7AC(DuelHandStackState *state);
s32 func_80017034(DuelCardRecord *card);
s32 func_8001BD48(void);
void func_800705D8(u8 *script);
s32 func_80070650(void);
void func_80028220(void);
void func_8001D670(void);
int func_8001700C(DuelCardRecord *object);
void func_80017E3C(DuelCardDisplayObject *object);
void func_800234E4(DuelFieldDisplaySource *source);
void func_8001D240(DisplayObject *object);
void func_8001D344(DisplayObject *object);
void func_8001D3C4(DisplayObject *o);
DisplayObject *func_8001D518(DisplayObject *source);
s32 func_8001D5B4(DuelFieldCursor *cursor);
s32 func_80020988(void);
void func_80022D94(s32 frames, s32 x, s32 z, s32 y, s32 value);
s32 func_8001EE44(DuelCardRecord *left, DuelCardRecord *right);
void func_800156B8(s32);
void func_80015904(void);
void func_80015C0C(void);
void func_80015CC0(void);
s32 func_8001EFD4(DisplayObject *left, DisplayObject *right);
s32 func_8001F0D0(u8 *record);
void func_8001F55C(void);
void func_8003FF34(void);
s32 func_80049120(void);
void func_8001ED20(DisplayObject *object);
void func_800428A8(
    DisplayObject *object,
    s32 arg1,
    s32 arg2,
    s32 arg3,
    s32 arg4,
    s32 arg5,
    s32 arg6,
    s32 arg7,
    void *resource
);
void func_80020BE4(FileTransferDescriptor *descriptor, s32 mode);
s32 func_8004703C(void);
void func_80020D4C(DisplayObject *object);
void func_80020EE8(DuelCardDisplayObject *object);
void func_80020F4C(void);
void func_80021598(void);
void func_800218F0(void);
void func_80021480(s32 page);
s32 func_80021810(s32 pool_index);
void func_80021894(s32 card_id);
void func_80015BD8(s32, s32);
void func_800220B8(void);
s32 func_80023090(DuelFieldCursor *cursor_a, DuelFieldCursor *cursor_b);
void *func_80035BE4(
    s32 index, s32 string_id, s32 x, s32 y, s32 width, s32 height
);
void func_80039A14(struct DuelEffectChannel *object);
void func_80040410(DisplayObjectConfig *object, s32 value);
void func_80022FF0(DisplayParent *parent, s32 clear);
s32 func_800235C0(void);
void func_80039934(struct DuelEffectChannel *record, s32 x, s32 y);
DisplayObject *func_80018150(int arg0, int arg1);
void func_80022674(DuelCardTurnObject *p);
void func_800229F4(DuelCardTurnObject *p);
void func_80023D08(GridCursor *o, s32 dir);
void func_800245EC(FileTransferDescriptor *, s32);
void func_800356A0(u8 *destination, u8 *source, u32 length);
extern u8 D_800907D8_flat[] asm("D_800907D8");
void func_80025D30(void);
s32 func_80024E24(void);
void func_800260D0(void);
s32 func_8002C7E8(DuelRitualResult *out, s32 ritual_id);
void func_80042A28(DisplayObjectVelocity *object);
extern int func_8007F9D8(RECT *rect, u32 *p);
void func_800262D4(void);
s32 func_80026C0C(s32 start);
s32 func_80026C6C(DuelCardRecord **out, s32 arg1, s32 arg2);
s32 func_80026D18(DuelCardRecord **out, s32 arg1, s32 arg2);
s32 func_80026DC8(void);
s32 func_80027060(void);
int func_8002712C(void);
s32 func_80027228(void);
int func_8002778C(DuelSelectionSource *source);
s32 func_800278A0(DuelSelectionSource *source);
int func_800282E8(void);
void func_800283F4(void);
void func_800357E8(s32 arg0, s32 arg1, u8 *arg2);
s32 func_80041F90(struct DisplayObject *obj, s32 x, s32 y,
                  struct ProjectionOut *out);
void func_80028B08(DisplayObject *object, s32 arg1);
extern void func_800878B0(long ofx,long ofy);
void func_800559D4(s32 index);
void func_800540B4(s32 index);
void func_800556E8(s32 index);
void func_8005B260(u32 *src, GsOT *ot, s32 idx, s32 flags);
void func_80029684(LINE_G3 *packet, GsOT *ot, SVECTOR *points,
                  long *control, s32 origin, s32 span);
void func_800297DC(LINE_G3 *packet, GsOT *ot, SVECTOR *points,
                  long *control, s32 origin, s32 span);
void func_80029934(void);
unsigned int func_80029EB0(unsigned char *base, int index);
void    func_800849F0(GsSPRITE * sp, GsOT * ot, unsigned short pri);
void    func_80084130(GsGLINE * lp, GsOT * ot, unsigned short pri);
void func_80029EC4(void);
int func_80058DD8(int index);
void    func_800857C0(long h);
void func_80014FA4(void);
void func_8002ACA4(u8 *state);
void func_80058FB0(s32 idx, u16 *out);
void func_80057AF4(s32 index, s32 anim, s32 flag);
void func_80047EC4(void);
DisplayObject *func_8002ABB4(DisplayObject *src, int add);
s32 func_80059AA8(s32 index, s32 value);
s32 func_80056504(
    s32 slot, s32 model, s32 p2, s32 p3, s32 p4, s32 p5, s32 arg6
);
s32 func_8005F1B8(s32 level, s32 value);
void func_80056828(s32 index);
void func_800530C4(void);
void func_800533D8(void);
void func_800595C8(s32 index, s32 x, s32 y, s32 z);
void func_800597C8(s32 idx, s32 flag, s32 val);
unsigned char *func_800591C0(unsigned int index, unsigned int light);
void func_80059AE0(s32 value);
void *func_800591FC(void);
void func_8002BAB4(void);
void func_80057F38(u8 *view);
s32 func_80058E68(s32 index);
void func_8002A788(u8 *state);
void func_8002BD0C(FileTransferDescriptor *object, s32 mode);
void func_80048D08(s32 side, u32 *src);
s32 func_8003F70C(void);
void func_80033C90(void);
void func_8003F87C(void);
s32 func_8002E3B4(void);
void func_8002EE94(void);
s32 func_8002EE5C(void);
void func_8002E370(MenuRecord *record);
s32 func_8003735C(DuelEffectChannel *channel);
extern int func_80082324(int max_count);
s8 *func_80039E9C(void);
void func_8002FD10(s16 arg0);
void func_8002FB78(
    FileTransferDescriptor *descriptor, s32 stage
);
DisplayObject *func_8002E3FC(void);
extern int func_8007EF84();
s32 func_80030294(void);
void func_800358A0(s32 value, s32 count_arg, u8 *data_arg);
void func_800316F0(
    GsSPRITE *sprite, GsOT *ot, const u8 *digits, s32 count
);
void func_80031784(
    GsSPRITE *sprite, GsOT *ordering_table, u8 *data, s32 selected);
void func_80031874(DisplayObject *obj, GsOT *ot);
void func_80032328(void);
void func_80032370(void);
void func_80031E5C(BuildDeckTransitionState *record);
void func_8003201C(BuildDeckTransitionState *state);
void func_80032C48(CardList *list);
void func_800323F8(u8 *base, void *deck, s32 other, s32 flags);
extern void func_8008E400(void *, size_t, size_t, int (*)());
void func_80031E04(CardList *list, s32 count);
s32 func_800330BC(CardList *list);

#endif /* KG_FUNCTIONS_H */
