/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_effect_request.c (SD_SEPlay), profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
s16 func_800451E0(u16 value, s32 unused);
typedef struct {
    short left;	        
    short right;        
} SpuVolume;
typedef struct {
    unsigned long	voice;		 



    unsigned long	mask;		 
    SpuVolume		volume;		 
    SpuVolume		volmode;	 
    SpuVolume		volumex;	 
    unsigned short	pitch;		 
    unsigned short	note;		 
    unsigned short	sample_note;	 
    short		envx;		 
    unsigned long	addr;		 
    unsigned long	loop_addr;	 
    long		a_mode;		 
    long		s_mode;		 
    long		r_mode;		 
    unsigned short	ar;		 
    unsigned short	dr;		 
    unsigned short	sr;		 
    unsigned short	rr;		 
    unsigned short	sl;		 
    unsigned short	adsr1;		 
    unsigned short	adsr2;		 
} SpuVoiceAttr;
typedef struct {
    u8 command;
    u8 field_0001;
    s16 field_0002;
    s32 field_0004;
    s32 field_0008;
    s32 field_000C;
    s32 field_0010;
    s32 field_0014;
    s32 field_0018;
    s32 field_001C;
    s32 field_0020;
    s32 field_0024;
    s32 field_0028;
    s32 field_002C;
} SDCommand;
typedef struct {
     
    u16 sector_offset;
    u8 pad_0002[2];
    u32 field_0004;
} SDValueLink;
typedef struct {
    u8 volume;
    u8 timer;
    u8 pad0002[2];
    u16 pitch;
    u16 field_0006;
} SDNote;
typedef union {
    u32 sum;
    s16 halves[2];
} SDLevelWord;
typedef struct {
    u16 field_0000;
    u16 field_0002;
    u16 field_0004;
    u8 pad0006[0x36];
    u32 field_003C;
    u16 flags_0040;
    u16 mix_scale;
    u16 field_0044;
    u8 pad0046[2];
    u8 output_type;
    u8 field_0049;
    u8 flags_004A;
    u8 pad004B;
    s16 command_count;
    u16 field_004E;
    u32 field_0050;
    u32 field_0054;
    u32 field_0058;
    u32 field_005C[8];
    u8 field_007C;
    u8 field_007D;
    u8 field_007E;
    u8 pad007F;
     


















    union {
        SDCommand c[16 ];
        u8 b[16  * 0x30];
    } commands;
    u8 pad0380[4];
     







    SpuVoiceAttr voice_attr;
    s32 field_03C4;
    s32 field_03C8;
    u16 field_03CC;
    u16 field_03CE;
    u8 pad03D0[0x34];
    u16 voice_ids[4 ];
    u8 field_040C[4 ];
    u8 voice_flags[4 ];
    u16 voice_volume_left[4 ];
    u16 voice_volume_right[4 ];
    u8 voice_value[4 ];
    u8 voice_step[4 ];
    u16 voice_timer[4 ];
    u8 voice_active_mask;
    u8 field_0435;
    u8 pad0436[2];
    u32 field_0438;
    u16 *field_043C;
    u16 field_0440;
    u16 field_0442;
    SDNote *field_0444;
    SDValueLink *field_0448;
    u16 field_044C[2 ][32 ];
    s32 field_04CC;
    u8 pad04D0[0x510 - ((0x44C  + 2  * (1 << 6 ) )  + 4)];
    s16 cd_volume;
    s16 field_0512;
    u8 channel_volume[2];
    u8 pad0516[2];
     


    u8 *bank_0518[3];
    u8 pad0524[4];
    u32 field_0528;
    u32 field_052C;
    u8 field_0530;
    u8 field_0531;
    u8 field_0532;
    u8 mix_multiplier;
    u16 field_0534;
    u8 pad0536[2];
    s32 decoded_half;
    u8 buffer_053C[4][0x200];
    u8 pad0D3C[0x800];
    u8 *buffer_ptrs_153C[4];
    SDLevelWord output_level;
    SDLevelWord field_1550;
    u8 pad1554[0xC];
    u8 *field_1560;
    u16 *music_track;
    u8 pad1568[0x10];
    s16 field_1578;
    s16 field_157A;
     
    s16 field_157C;
    s16 field_157E;
    s16 field_1580;
    s16 field_1582;
    u8 field_1584;
    u8 pad1585;
    s16 field_1586;
    s16 field_1588;
    u8 field_158A;
    u8 pad158B[0x4D];
    u8 field_15D8[0x14];
    u8 field_15EC;
    u8 field_15ED;
    u8 field_15EE;
    u8 field_15EF;
    u8 pad15F0[4];
    s16 field_15F4;
    u8 pad15F6[0x22];
    u8 busy;
     



    u8 field_1619[0x10];
    u8 field_1629[0x10];
    u8 field_1639[0x10];
     

    u8 field_1649;
    u8 field_164A;
    u8 field_164B;
} SDValue;
extern SDValue *D_8009B45C;
void func_80048658(s32 id, s32 volume, s32 pan);
void func_800482B0(s32 id, s16 pitch, u8 volume, s16 pan, u32 mode, u8 value);
typedef union {
    u64 all;
    struct { s32 original; s32 copy; } words;
} SDSEPlayIdPair;
void func_80048658(s32 arg0, s32 arg1, s32 arg2)
{
    SDSEPlayIdPair tags;
    s32 vol;
    s32 pan;
    u8 last_arg;
    u16 stop_value;
    s32 lo;
    s32 hi;
    s32 n;
    u8 *e;
    s32 t2;

     

    if (arg0 & 0x8000) {
        tags.words.original = arg0;
        pan = arg2;
        arg0 = arg1;
        tags.words.copy = tags.words.original;
        vol = arg0;
        stop_value = tags.words.original;
    } else {
        tags.words.original = arg0;
        pan = arg2;
        arg0 = arg1;
        tags.words.copy = tags.words.original;
        vol = arg0;
        stop_value = tags.words.original;
    }
    if (tags.words.original & 0x8000) {
        func_800451E0(stop_value & 0xFFFF, 0);
        return;
    }
    if ((tags.words.original & 0xF000) == 0x4000) {
        SDValue *a = D_8009B45C;
        u8 *table;
        u16 v;
        s32 n;

        lo = (tags.words.original & 0x1F) << 1;
        t2 = tags.words.original & 0x100;
        hi = t2;
        hi = (hi != 0) << 6;

        table = (u8 *)&a->field_044C;
        v = *(u16 *)(table + (lo + hi));
        if (v == 0xFFFF) {
            return;
        }
        n = a->field_043C[v];
        if (n == 0xFFFF) {
            return;
        }
        e = (u8 *)(n * 8 + (u32)a->field_0444);
        t2 = e[2];
        last_arg = t2;
        vol &= 0xFF;
        func_800482B0(v, 0, vol, (s16)pan, e[3], last_arg & 0xFF);
    } else {
        SDValue *b = D_8009B45C;

        n = b->field_043C[tags.words.copy & 0xFFFF];
        if (n == 0xFFFF) {
            return;
        }
        e = (u8 *)(n * 8 + (u32)b->field_0444);
        t2 = e[2];
        last_arg = t2;
        vol &= 0xFF;
        func_800482B0(tags.words.copy & 0xFFFF, 0, vol, (s16)pan, e[3], last_arg & 0xFF);
    }
}
