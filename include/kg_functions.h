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
void func_80033CF8(s32 dx, s32 dy, s32 dz);
u32 *func_80033DB0(GsARGUNIT_NORMAL *arg);
u32 *func_8006151C(GsARGUNIT_NORMAL *arg);
u32 *func_80034830(GsARGUNIT_NORMAL *arg);
u32 *func_80061A84(GsARGUNIT_NORMAL *arg);
extern long func_80087BC0(SVECTOR *v0,SVECTOR *v1,SVECTOR *v2,SVECTOR *v3,
			long *sxy0,long *sxy1,long *sxy2,long *sxy3,
			long *p,long *otz,long *flag);
extern void func_80082980(POLY_GT4 *p) ;
void func_80035E20(DisplayObject *obj, GsOT *ot);
void func_80036C14(DuelEffectChannel *channel, s32 tagged_value);
void func_80037DA4(DuelEffectChannel *object);
void func_80039F44(DisplayEffectState *object);
void func_80039FD4(MenuRecord *record);
void func_80038EB0(EffectObject *object);
s32 func_80037C74(DuelEffectChannel *object);
void func_800373C8(DuelEffectChannel *channel, u8 a1, u8 a2);
void func_80035CA8(s32 value);
void func_80035DB8(s32 value);
void func_800393B0(struct DuelEffectChannel *object);
void func_800391E4(struct DuelEffectChannel *record);
extern void (*D_8009B340)(volatile DuelEffectChannel *object);
extern void (*D_80090F18[])(u8 *);
void func_8003B50C(s32 value);
void func_80039D64(DuelEffectChannel *);
struct DisplayObject *func_800374F4(DuelEffectChannel *record);
extern int func_8007F978(RECT *rect, u32 *p);
s32 func_80039F1C(DisplayEffectState *object);
FileTransferDescriptor *func_80014EEC(
    s32, u8 *, s32, s32, FileTransferCallback, s32, s32
);
void func_8003A01C(
    FileTransferDescriptor *descriptor, s32 mode);
s32 func_8003A1EC(
    MenuRecord *record, DisplayObject **out, s32 resource_index);
void func_8003A560(DisplayEffectVramState *state);
s32 func_8004413C(s32 channel);
s32 func_800441DC(s32 channel, s32 name, s32 buffer, s32 offset, s32 size);
s32 func_800442E4(s32 channel, s32 name, s32 buffer, s32 offset, s32 size);
s32 func_80044278(s32 channel, s32 buffer, s32 sector);
s32 func_80044380(s32 channel, s32 buffer, s32 sector);
s32 func_800443EC(s32 channel, s32 name, s32 blocks);
s32 func_80044838(s32 mode, s32 *request, s32 *result);
s32 func_80044CD4(u8 *name);
extern void (*D_80090F88[5 ])(
    MemCardWorkRoot *root, MemCardWorkSlot *slot
);
void func_8003DC1C(void);
void func_80043E30(long val);
void func_80043EBC(void);
DuelEffectChannel *func_8003D46C(s32 value, s32 set_flags);
void func_80035748(u8 *destination, s32 value, u32 length);
long func_8008BC90( long chan );
long func_8008C638( long chan, char* file, unsigned long* adrs, long ofs, long bytes );
long func_8008CA78( long chan, char* name, struct DIRENTRY* dir, long* files, long ofs, long max );
void func_8003E46C(s32 value, s32 bits);
void func_8003E490(void);
s32 func_8003D174(u8 *);
long func_8008C858( long chan, char* file, unsigned long* adrs, long ofs ,long bytes );
long func_8008CE04( long chan, char* file, long blocks );
long func_8008CF00( long chan );
void func_8003E854(void);
extern long func_80073900(long, void *, long);
s32 func_80044544(struct DIRENTRY *entry, s32 count);
s32 func_80044598(u8 *name, struct DIRENTRY *entry, s32 count);
s32 func_8003D2B8(
    SaveDataState *left,
    SaveDataState *right
);
s32 func_8003D288(
    SaveDataState *left,
    SaveDataState *right
);
void func_8003EED0(void);
void func_800408D0(DisplayObject *e, s32 tex, s32 mode_arg);
void    func_800844F0(GsSPRITE * sp, GsOT * ot, unsigned short pri);
void    func_80084B70(GsSPRITE * sp, GsOT * ot, unsigned short pri);
POLY_FT4 *func_80089260(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, SVECTOR *v3,
			u32 *uv0, u32 *uv1, u32 *uv2, u32 *uv3,
			CVECTOR *rgbc, POLY_FT4 *s, u32 *ot, DIVPOLYGON4 *divp);
void func_80042C08(DisplayObject *object, GsOT *ot);
extern long func_800738D0(char *, unsigned long);
extern long func_80073910(long);
extern long func_800738E0(long, long, long);
extern long func_800738F0(long, void *, long);
extern void func_8008B370(void);
extern long func_8008B380(long drv);
extern long func_8008B390(long drv);
extern long func_8008B350(long chan, long block, unsigned char *buf);
extern long func_8008B360(long chan, long block, unsigned char *buf);
s32 func_80044470(s32 chan, const char *pattern, struct DIRENTRY *cursor,
                     s32 *out_count);
s32 func_80044608(void);
void func_80043D48(long *handles);
extern long func_80076D20 (SpuDecodedData *d_data, long flag);
s32 func_80045054(void);
extern SDValue *volatile g_SDValue_output_level asm("D_8009B45C");
s32 func_80045BE8(SDCommand *);
void func_800464F0(void);
s32 func_80045208(u16 code, s32 unused);
void func_80044DA0(void);
s32 func_800496C4(SDVabHeader *vab, s16 vab_id, s32 spu_addr);
s32 func_80014C40(FileRequestSlot *request, u8 *source);
s32 func_80045484(void);
void func_80045514(void);
s32 func_80049A64(u8 *input, s16 vab_id);
void func_80049C40(s32 value);
void func_80049CB0(s32 value);
void func_80049F10(s16 left, s16 right);
void func_800476B4(SDSeqBlock *input, u32 rate);
void func_8004545C(void);
void func_80049AF4(s32 start, s32 ambient);
void func_80044DC0(s16 a0);
void func_80045C98(void);
extern void func_80076ED0 (long on_off, unsigned long voice_bit);
extern void func_800773C4 (char *status);
void func_80045F3C(void);
s16 func_80049F50(void);
void func_80046294(void);
extern void func_80077120 (SpuVoiceAttr *attr);
void func_8004803C(u16 id, u8 voice, s32 pitch_add, u8 volume,
                   s16 pan, u8 flags, u8 value);
extern void func_80077C50 (int vNum, short *envx);
s16 func_800451E0(u16 value, s32 unused);
s32 func_80047F38(u8 value);
void func_800482B0(s32 id, s16 pitch, u8 volume, s16 pan, u32 mode, u8 value);
void func_80048658(s32 id, s32 volume, s32 pan);
void func_80044E90(s32 pan);
void func_80047864(s32 index);
void func_80048A28(s32 arg0, s32 arg1, s32 arg2);
void func_80048C70(u32 *dst, u32 *src);
extern long func_80075BE0 (long on_off);
extern long func_80075DE0 (SpuReverbAttr *attr);
extern long func_80076790 (long on_off);
s32 func_80049600(u32 count);
void func_80048F14(void);
void func_80049544(void);
void func_80049594(s32 value);
s32 func_80049FB4(s32 note_high, s32 note_low, s32 base, s32 offset);
extern void func_80077450 (SpuVoiceAttr *arg);
void func_8004A27C(s32 voice, s32 left, s32 right);
void func_8004A6F8(s32 index, SDToneEnvelopeView *tone);
s32 func_8004A854(s32 value);
s32 func_8004A8E4(s32 index, s32 value);
s32 func_8004A940(s32 value, s32 variant);
extern unsigned long func_80076820 (long on_off, unsigned long voice_bit);
extern unsigned long func_80076B10 (void);
void func_8004A0FC(SDSecondaryObject *object,
                                 SDSecondaryRecord *channel);
s32 func_8004A3BC(SDSecondaryObject *entry, s32 value);
void func_8004ADE8(s32 channel, s32 note, s32 velocity);
void func_8004B374(s32 channel, s32 value, s32 unused);
void func_8004B49C(s32 arg0, s32 arg1, u8 arg2);
void func_8004B6E8(u8 index, s32 value);
void func_8004B70C(u8 index, s32 unused, s32 value);
void func_8004C114(SDSequenceTrack *p, s32 status, u8 d1, u8 d2);
extern u32 *func_80089E20(GsARGUNIT *);
extern GsCOORDUNIT *func_8008A420(u32 *, u32 *);
extern int func_80089F80(u32 *, GsTYPEUNIT *, GsOT *, u32 *);
extern void func_8008A280(u32 *);
s32 func_8004D134(s32 mode, u16 *kind, u8 *ctx, s32 *best, s32 *total);
void func_8004D58C(s32 slot, u8 *commands);
void func_8006086C(ModelHandlerObject *object);
void func_80060AEC(ModelHandlerObject *object);
void func_80060220(
    s32 model_index, ModelTypeUnit *unit, u8 *scratch);
void func_8005C6A0(s32 *object, ModelSlot *entry);
s32 func_8005A3D0(ModelSlot *model, GsCOORDUNIT *parent);
void func_8004CB0C(s32 slot, u8 *hmd, s32 size, s32 flags);
void func_8004D75C(s32 slot);
void func_8004DC38(ModelSlot *slot, s32 i, s32 n, u32 pos);
extern void func_80089C20(SVECTOR *v0,CVECTOR *v1,CVECTOR *v2);
extern long func_80087AB0(SVECTOR *v0,SVECTOR *v1,SVECTOR *v2,SVECTOR *v3,
			long *sxy0,long *sxy1,long *sxy2,long *sxy3,
			long *p,long *flag);
int     func_800857E0(int id, GsF_LIGHT * lt);
void    func_80085D50(long r, long g, long b);
void func_8004DE24(void);
void *func_80059220(void);
void func_8004E7B0(s32 force);
extern s32 (*D_800114E8[4])(s32, s32);
void func_80059284(s32 index, s32 value);
void func_80059590(
    s32 slot,
    s32 mode,
    s32 target0,
    s32 target1,
    s32 target2
);
void func_80047314(u32 value);
void func_8005F27C(s32 mode, s32 coefficient, SVECTOR *offset);
void func_8005F3B8(s32 mode, s32 y, s32 a, s32 b, SVECTOR *offset);
void func_8005F588(s32 value);
void func_8005F5C8(s32 mode, s32 coefficient, SVECTOR *offset, s32 arg);
void func_8005F714(s32 first, s32 second, s32 arg);
ModelEffectCoefficient *func_8005F1A4(s32 index);
void func_8005A188(int value);
int func_8005A878(int arg);
s32 func_8005A618(s32 index);
s32 func_8005FB08(void);
s32 func_8005FB14(void);
s32 func_8005F174(void);
void func_8005F180(s32 value);
s32 func_80058E1C(void);
void func_80050F24(s32 index);
void func_80059EBC(s32 value);
void func_80059F18(s32 first, s32 second, s32 third, s32 fourth);
void func_8005A010(s32 first, s32 second);
void func_8005A0DC(s32 value);
s32 func_8005A2E0(s32 index);
void func_8004EB00(void);
void func_80050584(s32 index);
void func_800507D0(void);
void func_80059AEC(s32 value);
void func_801807B0(void);
void func_80181C4C(s32 value);
s32 func_80180A24(void);
void func_80049394(u16 *track);
void func_800493F8(void);
s32 func_80051350(s32 mode, s32 min_extent, s32 depth);
extern long func_80086E50(long a);
void func_80051A48(void);
void func_80052694(s32 arg0);
void func_80058434(s32 direction, s32 yaw, s32 pitch, s32 distance, s32 unused);
s32 func_8005A8C4(s32 index, s32 type);
void func_800528AC(void);
void func_80052D2C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_8005F18C(void);
extern void *func_8008E3D0 ( );
void func_80053248(s32 idx, ...);
void func_8005611C(s32 arg0);
s32 func_800534B8(void);
void func_8005922C(struct _GsCOORDUNIT *unit, VECTOR *scale);
extern long func_80087A50(SVECTOR *v0,SVECTOR *v1,SVECTOR *v2,
			long *sxy0,long *sxy1,long *sxy2,long *p,long *flag);
extern void func_8008A150(GsUNIT *, GsOT *, u32 *);
extern void func_8008A760(GsCOORDUNIT *, MATRIX *);
extern void func_8008AA30(GsCOORDUNIT *, MATRIX *, MATRIX *);
void func_80057E20(s32 index, ModelEffectAdjustment *out);
void func_80059700(s32 index, s32 sign);
void func_8005A53C(
    s32 (*fn)(s32),
    ModelHandlerRunEntry *entry,
    s32 arg2,
    s32 count
);
s32 func_8005AE68(u16 color, s32 flags, u16 scale);
s32 func_8005FE44(s32 arg0);
void func_8005106C(s32 index);
void func_8005F198(s32 value);
void func_80056D7C(FileTransferDescriptor *object, s32 mode);
void func_80057544(FileTransferDescriptor *object, s32 mode);
void func_800577B0(FileTransferDescriptor *object, s32 mode);
int func_80074170(int mode);
void func_8004D914(s32 slot);
void func_800590DC(s32 index);
void func_8005A468(s32 index, s32 speed);
void func_8005A4C4(ModelSlot *record, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_800582C0(s32 side, s32 tint, s32 level);
void func_8005B620(s32 *destination, const s32 *source, u32 count);
extern MATRIX *func_80087370(MATRIX *m0,MATRIX *m1);
extern MATRIX *func_800889C0(SVECTOR *r,MATRIX *m);
extern MATRIX *func_80088E50(SVECTOR *r,MATRIX *m);
extern void func_8008A4A0(GsCOORDUNIT *, MATRIX *);
void func_800580D4(s32 index, s32 arg1, u8 *arg2, struct _GsCOORDUNIT *arg3);
void func_80058938(
    s32 slot, s32 selection, ModelTintColor start, ModelTintColor end,
    s32 duration, const u8 *part_mask);
Color *func_8005ABA0(Color *out, s32 h, u16 s, u16 v, u8 lim);
HsvT *func_8005A98C(HsvT *out, u8 r, u8 g, u8 b, u8 lim);
extern void Color_RgbToHsl_void(
    HsvT *out, u8 r, u8 g, u8 b, u8 lim
) asm("func_8005A98C");
extern void Color_HslToRgb_wide(
    Color *out, s32 h, u32 s, u32 v, s32 lim
) asm("func_8005ABA0");
Color *func_8005B0B4(
    Color *out, u8 r, u8 g, u8 b, s32 flags, u16 scale, u8 lim);
void func_8005B36C(
    u32 *src,
    GsOT *ot,
    s32 idx,
    s32 offx,
    s32 offy,
    s32 maskx,
    s32 masky
);
void func_8005B4D8(u32 *src, GsOT *ot, s32 idx, s32 flags);
extern DRAWENV *func_8007FEC8(DRAWENV *env);
s32 func_8005BE3C(void);
s32 func_8005BFC8(s32 resync);
extern void func_8008FD38(u32 *buf, int mode);
extern void func_8008FDB4(u32 *buf, int size);
s32 func_8005C5D4(void);
void func_80044F58(s32 value);
u32	func_800784D0(u32 *base);
u32	func_800785C0(u32 **addr,u32 **header);
int     func_800783DC(CdlLOC *loc);
int func_800781F0(CdlLOC *p);
extern int func_800902A0(u32 *bs, u32 *buf, DECDCTTAB table);
void func_8005C62C(CdlLOC *loc);
void	func_800786A0(void);
void func_8005C1F4(void);
extern void func_8008FBD0(s32 status) __attribute__((noreturn));
u32 *func_8005C7BC(GsARGUNIT_ANIM *ctx);
extern MATRIX *func_80089060(SVECTOR *r,MATRIX *m);
s32 func_8005D378(GsARGUNIT_ANIM *ctx);
void func_8005EBF4(Key *cur, s32 k, s32 scale, s32 den, s16 *out);
void func_8005E808(Key *key);
void func_8005F070(s32 enabled);
void func_8005DBA4(void);
void func_8005FB30(Key *key);
void func_8005F7B0(s32 value, s32 arg);
void func_80060B38(DisplayObject *obj, GsOT *ot);
void func_80060E70(u16 *entries, s32 side, s32 flag, s32 ignored);
extern MATRIX *func_80087480(MATRIX *m0,MATRIX *m1);
extern MATRIX *func_80087D30(SVECTOR *r,MATRIX *m);
extern void func_800871D0();
extern void func_80087274();
extern void func_80087970(SVECTOR *v0,VECTOR *v1,long *flag);
extern long func_80087B30(SVECTOR *v0,SVECTOR *v1,SVECTOR *v2,
			long *sxy0,long *sxy1,long *sxy2,
			long *p,long *otz,long *flag);
extern void func_800828E0(POLY_G3 *p) ;
extern void func_80082960(POLY_G4 *p) ;
void    func_80083FB0(GsLINE * lp, GsOT * ot, unsigned short pri);
extern char *index  (const char *, char);
GsOT *func_80058F10(void);
s32 func_8006AF74(ModelSubdividedEffect *data, s32 mode);
s16 *func_8006BCA4(s16 *a, s16 *b, s16 *c, s16 *out, s32 depth);
Triplet *func_8006C120(u8 *a, u8 *b, u8 *c, Triplet *out, s32 depth);
void func_8006C2FC(u8 *output, s32 first, s32 second, s32 third);
s32 func_80058DCC(void);
extern long func_80089C70(long sz0,long sz1,long sz2);
extern void func_80087CC0(SVECTOR *v0,DVECTOR *v1,u16 *sz,u16 *p,
			u16 *flag,long n);
extern int func_80086920(int a);
extern int func_80086BB0(int a);
s32 func_8006C37C(ModelDiscEffectState *arg0, s32 arg1);
s32 func_8006CD78(void *data, s32 arg1);
s32 func_8006F1B4(void *data, s32 arg1);
s32 func_80070920(s32 mode, s32 index);
void func_80070738(s32 kind, s32 *low, s32 *high);
s32 func_8007058C(void);
void func_80071700(void);
void func_80071CB0(void);
void func_800707C4(s32 kind, s32 *low, s32 *high);
void func_80071FC8(void);
void func_8007214C(void);
s8 func_80070710(void);
void func_80072A48(void);
void func_800734DC(void);

#endif /* KG_FUNCTIONS_H */
