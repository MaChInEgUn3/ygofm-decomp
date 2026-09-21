/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80045514.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef struct {
    u32 a;
    u32 b;
} SoundCommandPair;
typedef struct {
    s32 field_00;
    s32 field_04;
    u8 pad_08[4];
    s32 field_0C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s16 field_1C;
    u8 field_1E;
    u8 field_1F;
} FileRequestSlot;
extern FileRequestSlot *D_8009B460 __attribute__((section(".data")));
typedef struct {
    s32 form;
    s32 version;
    s32 id;
    u32 file_size;
    u16 reserved_10;
    u16 program_count;
    u16 tone_count;
    u16 vag_count;
    u8 master_volume;
    u8 pan;
    u8 attribute_1;
    u8 attribute_2;
    u32 reserved_1C;
} SDVabHeader;
s32 func_800496C4(SDVabHeader *vab, s16 vab_id, s32 spu_addr);
s32 func_80014C40(FileRequestSlot *request, u8 *source);
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
    u8 pad_0000[0x0C];
    s32 spu_address;
    u8 pad_0010[0x40];
    u8 vab_header[1];
} SDMusicPackage;
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
extern SDValue *D_8009B45C __attribute__((section(".data")));
s32 func_80045484(void);
void func_80045514(void);
s32 func_80049A64(u8 *input, s16 vab_id);
void func_80049C40(s32 value);
void func_80049CB0(s32 value);
void func_80049F10(s16 left, s16 right);
typedef struct {
    s32 count;
    u8 pad0004[4];
    u16 keys[((0x1A0  - 0x08 ) / 2 ) ];
    SDNote data[((0x1A0  - 0x08 ) / 2 ) ];
} SDSeqBlock;
void func_800476B4(SDSeqBlock *input, u32 rate);
void func_8004545C(void);
void func_80049AF4(s32 start, s32 ambient);
typedef struct {
    u16 field_00;
    u16 count;
    u8 field_04[8];
    s32 payload_size;
    u16 index_records[16][2];
} CommandIndexTable;
void func_80045514(void)
{
    SDValue *entry_state;
    u32 first_word;
    u32 second_word;

    switch (D_8009B45C->field_007C) {
    case 81:
        func_800476B4((SDSeqBlock *)D_8009B45C->field_0058,
                     (u32)D_8009B45C->field_0050);
        goto clear_7d_7c;

    case 32:
        switch (D_8009B45C->field_007D) {
        case 0:
            if (func_80014C40(0, 0) != 0) {
                return;
            }
            if (D_8009B45C->field_04CC != 0) {
                return;
            }
            {
                SDValue *sd = D_8009B45C;
                FileRequestSlot *b = D_8009B460;
                s32 final_word;

                b->field_10 = (s32)sd->field_005C[4];
                b->field_0C = (s32)sd->field_005C[3];
                b->field_04 = (s32)sd->field_005C[1];
                b->field_18 = (s32)sd->field_005C[6];
                final_word = (s32)sd->field_005C[5];
                b->field_1F = 0;
                b->field_1C = 0;
                b->field_14 = final_word;
                D_8009B460->field_1E = 0;
            }
            D_8009B460->field_00 = (s32)D_8009B45C->field_005C[0];
            if (D_8009B460->field_18 == 0 && D_8009B460->field_14 == 0) {
                D_8009B45C->field_007D = 0;
                goto clear_7c;
            }
            switch ((s32)D_8009B45C->field_005C[0] & 0xF0) {
            case 0x10:
                D_8009B460->field_00 = 4;
                func_80014C40(D_8009B460, D_8009B45C->field_1629);
                break;
            case 0x20:
                D_8009B460->field_00 = 5;
                func_80014C40(D_8009B460, D_8009B45C->field_1619);
                break;
            case 0x40:
                D_8009B460->field_00 = 6;
                func_80014C40(D_8009B460, D_8009B45C->field_1639);
                break;
            }
            func_8004545C();
            D_8009B45C->field_007D = D_8009B45C->field_007D + 1;
            return;
        case 1:
            break;
        default:
            return;
        }
        if (D_8009B45C->busy != 0) {
            return;
        }
        D_8009B45C->field_007D = 0;
        D_8009B45C->field_007C = 0;
        if ((func_80045484() & 0xFF) != 0) {
            return;
        }
        D_8009B45C->flags_0040 = D_8009B45C->flags_0040 & 0xFFFC;
        return;

    case 17:
        switch (D_8009B45C->field_007D) {
        case 0:
            if (D_8009B45C->cd_volume == 0) {
                D_8009B45C->field_007D = 1;
                return;
            }
            if (D_8009B45C->field_0512 < 0) {
                return;
            }
            D_8009B45C->field_0512 = -0x20;
            D_8009B45C->field_0049 = 0;
            return;
        case 1:
            break;
        default:
            return;
        }
        D_8009B45C->field_0534 = 0xFFFF;
        if ((func_80045484() & 0xFF) != 0) {
            goto clear_7d_7c;
        }
        {
            SDValue *sd = D_8009B45C;
            u16 flags = sd->flags_0040;
            sd->field_007D = 0;
            sd->flags_0040 = flags & 0xFFF8;
            D_8009B45C->field_007C = 0;
        }
        return;

    case 33:
        if (func_80014C40(0, 0) != 0) {
            goto clear_7d_7c;
        }
        {
            SoundCommandPair *e;
            s32 base_offset;

            first_word = 0xFFFFFF;
            e = (SoundCommandPair *)(
                (u32)&((SoundCommandPair *)0)[D_8009B45C->field_004E]
                + (u32)D_8009B45C->field_0058);
            second_word = e->a;

            D_8009B460->field_10 = 0;
            D_8009B460->field_18 = 0;
            D_8009B460->field_0C = 0;
            D_8009B460->field_14 = 0;
            D_8009B460->field_1C = 0;
            D_8009B460->field_1F = D_8009B45C->field_0530;
            second_word &= first_word;
            D_8009B460->field_1E = D_8009B45C->field_0531;
            base_offset = (s32)D_8009B45C->field_0050;
            D_8009B460->field_00 = 6;
            second_word += base_offset;
            D_8009B460->field_04 = second_word;
            func_80014C40(D_8009B460, 0);
        }
        goto clear_7d_7c;

    case 36:
        if (func_80014C40(0, 0) != 0) {
            goto clear_7d_7c;
        }
        {
            u32 value_mask = 0xFFFFFF;
            SoundCommandPair *e;
            s32 request_offset;
            u32 low_a;

            entry_state = D_8009B45C;
            e = (SoundCommandPair *)((u32)entry_state->field_004E * 8
                                     + (u32)entry_state->field_0058);
            first_word = e->a;
            second_word = e->b;

            low_a = first_word & value_mask;
            value_mask &= second_word;
            entry_state->field_0528 = low_a;
            entry_state->field_0531 = (first_word & 0x1F000000) >> 24;
            entry_state->field_052C = value_mask;
            D_8009B45C->field_0530 = (second_word & 0x1F000000) >> 24;
            second_word >>= 31;
            D_8009B45C->field_0532 = second_word;
            first_word >>= 29;
            D_8009B45C->mix_multiplier = first_word;
            D_8009B45C->field_0528 =
                D_8009B45C->field_0528 + (s32)D_8009B45C->field_0050;
            D_8009B45C->field_052C =
                D_8009B45C->field_052C + (s32)D_8009B45C->field_0050;
            D_8009B460->field_10 = 0;
            D_8009B460->field_18 = 0;
            D_8009B460->field_0C = 0;
            D_8009B460->field_14 = 0;
            D_8009B460->field_1C = (u16)D_8009B45C->field_052C
                                   - (u16)D_8009B45C->field_0528 + 0x10;
            D_8009B460->field_1F = D_8009B45C->field_0530;
            D_8009B460->field_1E = D_8009B45C->field_0531;
            request_offset = D_8009B45C->field_0528;
            D_8009B460->field_00 = 6;
            D_8009B460->field_04 = request_offset;
            func_80014C40(D_8009B460, 0);
        }
        goto clear_7d_7c;

    case 41:
    case 42:
        if (D_8009B45C->field_007E != 0 && D_8009B45C->field_0512 != 0) {
            return;
        }
        D_8009B45C->field_007C = 0;
        goto clear_7d;

    case 72:
        if (D_8009B45C->field_157A != 0) {
            SDMusicPackage *list = (SDMusicPackage *)D_8009B45C->music_track;

            D_8009B45C->field_157A = func_800496C4(
                (SDVabHeader *)list->vab_header, 0, list->spu_address
            );
            if ((s16)D_8009B45C->field_157A != 0) {
                D_8009B45C->field_007C = 0;
                return;
            }
        }
        if (D_8009B45C->field_157E == 0) {
            if ((D_8009B45C->flags_0040 & 0x80) != 0) {
                func_80049C40(0);
                func_80049F10(0, 0);
                D_8009B45C->field_1586 = 0;
                D_8009B45C->field_1588 = 0;
                D_8009B45C->flags_0040 = D_8009B45C->flags_0040 & 0xFF7F;
            }
            func_80049CB0(D_8009B45C->field_157E);
            D_8009B45C->field_157E = -1;
        }
        {
            CommandIndexTable *l;
            u32 i;

            entry_state = D_8009B45C;
            l = (CommandIndexTable *)entry_state->music_track;
            i = entry_state->field_004E & 0xF;

            if (i >= l->count) {
                D_8009B45C->field_007C = 0;
                return;
            }
            D_8009B45C->field_157E = func_80049A64(
                (u8 *)(
                    (u32)&((u8 (*)[16])0)[l->index_records[i][0]] + (u32)l),
                                             entry_state->field_157A);
            if ((s16)D_8009B45C->field_157E == 0) {
                D_8009B45C->field_157C = D_8009B45C->field_004E;
                func_80049AF4(1, 1);
                {
                    SDValue *sd = D_8009B45C;
                    sd->field_158A = 0xFF;
                    sd->flags_0040 = sd->flags_0040 | 0x80;
                    sd->field_1588 = (u16)sd->field_0054;
                }
            }
        }
        D_8009B45C->field_007C = 0;
        goto clear_7d;

    case 0:
        break;
    }

    goto clear_7d_7c;

clear_7d:
    D_8009B45C->field_007D = 0;
    return;

clear_7d_7c:
    D_8009B45C->field_007D = 0;
clear_7c:
    D_8009B45C->field_007C = 0;
}
