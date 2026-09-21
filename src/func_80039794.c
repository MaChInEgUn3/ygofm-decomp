/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80039794.c, profile gcc_2_8_1_g8_split_no_strength_reduce.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u8 D_8009B0C1 __attribute__((section(".data")));
extern u16 D_8009B398 __attribute__((section(".data")));
void func_8003B50C(s32 value);
typedef struct {
    u16 code_00;
    u16 pad_02;
    s32 field_04;
    s32 field_08;
    s16 x_0C;
    s16 y_0E;
    u8 field_10;
    u8 flags_11;
    u8 field_12;
    u8 field_13;
    u8 pad_14;
    u8 field_15;
     
    u8 field_16;
    u8 field_17;
    u8 field_18;
    u8 pad_19[3];
} DuelEffectEntry;
struct DuelEffectChannel;
struct DisplayObject;
typedef struct DuelEffectChannel {
    u8 *text_00;
     










    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 field_07;
    u8 field_08;
    u8 field_09;
    u8 field_0A;
    u8 pad_0B;
    u16 field_0C;
    u16 field_0E;
     



    u8 field_10;
    u8 field_11;
    u8 pad_12;
    u8 field_13;
    u8 field_14;
    u8 field_15;
    u8 pad_16[10];
    DuelEffectEntry *entry_end_20;
    DuelEffectEntry *entry_head_24;
     



    struct DisplayObject *field_28;
     



    struct DisplayObject *field_2C;
    struct DisplayObject *field_30;
    u16 flags_34;
    u16 field_36;
    u16 field_38;
    u16 field_3A;
    s16 field_3C;
    s16 field_3E;
    s16 field_40;
    s16 field_42;
     

    u8 text_44[0x0D];
     

    u8 state_51;
     

    u8 delay_52;
    u8 field_53;
    u8 field_54;
    u8 pad_55;
    u8 field_56;
    u8 index_57;
     

    s8 stream_58;
    u8 field_59;
    u8 field_5A;
    u8 field_5B;
    u16 range_start_5C;
    u16 range_count_5E;
    u8 field_60;
    u8 field_61;
     


    u8 field_62;
    u8 pad_63;
} DuelEffectChannel;
extern DuelEffectChannel D_800EB0F8[4 ];
void func_80039D64(DuelEffectChannel *);
void func_8003FEE0(u32);
struct DisplayObject;
void func_8004036C(void *object);
typedef struct {
    void *obj;
    u16 flags;
} ChoiceView;
typedef struct {
    ChoiceView choice;
    u8 pad_08[sizeof(DuelEffectChannel) - sizeof(ChoiceView)];
} ChoiceChannelCursor;
typedef struct {
    u16 lo;
    u16 hi;
} TblEnt;
extern u8 D_8009B356;
void func_80039794(void);
struct DuelEffectChannel;
void func_800393B0(struct DuelEffectChannel *object);
extern s16 D_8009B35A;
struct DisplayObject *func_800374F4(DuelEffectChannel *record);
extern u32 D_801D9000[];
void func_80039794(void)
{
    DuelEffectChannel *p;
    ChoiceChannelCursor *q;
    s32 reset_value;
    TblEnt *table;
    s32 n;
    s32 cnt;
    s32 idx;
    s32 kind;
    s32 arg;
    u16 f;

    p = D_800EB0F8;
    n = 4;
    reset_value = -1;
    table = (TblEnt *)D_801D9000;
    q = (ChoiceChannelCursor *)&p->field_30;
    do {
        if (q->choice.flags & 0x8000) {
            D_8009B35A = 0;
            if ((q->choice.flags & 0x2000) == 0) {
                D_8009B35A = reset_value;
                cnt = -1;
                for (;;) {
                    func_800393B0(p);
                    cnt++;
                    f = q->choice.flags;
                    if (f & 0x2000) {
                        if (f & 8) {
                            q->choice.obj = func_800374F4(p);
                        }
                        break;
                    }
                    if (f & 0x1C00) {
                        goto reset;
                    }
                    if (cnt >= D_8009B0C1) {
                        break;
                    }
                    continue;
reset:
                    D_8009B35A = reset_value;
                }
            } else {
                if (q->choice.flags & 8) {
                    if (D_8009B398 & (0x40  | 0x80 ) ) {
                        q->choice.flags &= 0xFFF7;
                        func_8004036C(q->choice.obj);
                        q->choice.obj = 0;
                        func_8003FEE0(0xB);
                    }
                }
            }
            arg = -1;
            idx = D_8009B35A;
            if (idx >= 0) {
                kind = table[idx].hi & 7;
                if (kind == 4) {
                    arg = D_8009B356;
                } else {
                    D_8009B356 = kind;
                    arg = kind;
                }
            }
            func_8003B50C(arg);
            func_80039D64(p);
        }
        q++;
        n--;
        p++;
    } while (n != 0);
}
