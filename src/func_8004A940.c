/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_secondary_object_selection.c (SD_SelectSecondaryObject), profile gcc_2_8_1_g0.
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
    u8 program;
    u8 pan;
    u8 pad0002;
    u8 volume;
    u8 field_0004;
    u8 expression;
    u8 field_0006;
    u8 pitch_bend_msb;
    s32 field_0008;
    s32 field_000C;
    u8 field_0010;
    u8 parameter_selector;
    u8 control_mode;
    u8 control_value;
    s16 field_0014;
    u8 pad0016[2];
} SDSecondaryRecord;
typedef struct {
    u8 voice_index;
    u8 pad0001[2];
    u8 channel_index;
    u8 pad0004;
    u8 field_0005;
    u8 note;
    u8 pad0007;
    u8 field_0008;
    u8 field_0009;
    u8 field_000A;
    u8 field_000B;
     

    u8 pan;
    u8 field_000D;
    u8 field_000E;
    u8 field_000F;
    u8 pitch_bend_positive_scale;
    u8 pitch_bend_negative_scale;
    u8 field_0012;
    u8 field_0013;
     

    u16 level_left;
    u16 level_right;
    u8 pad0018[2];
    s16 cached_pitch_bend;
    s16 field_001C;
    u16 field_001E;
    u8 pad0020[8];
} SDSecondaryObject;
typedef struct {
    s16 field_0000;
    u8 pad0002[2];
    u8 *field_0004;
    s32 field_0008;
    s32 field_000C;
    s32 field_0010;
    u8 *field_0014;
    u8 field_0018;
    u8 field_0019;
    u8 field_001A;
    u8 field_001B;
} SDSecondaryTransfer;
typedef struct {
    s32 pos;
    s32 pos_saved;
    s32 chunk_length;
    s32 chunk_end;
    s32 chunk_start;
    u16 tempo_accumulator;
    u16 tempo_step;
    u16 field_0018;
    u16 field_0018_saved;
    u32 delta_remaining;
    u32 delta_remaining_saved;
    u8 ended;
    u8 ended_saved;
    u8 loop_count;
    u8 field_0027;
    u8 running_status_held;
    u8 running_status;
    u8 running_status_saved;
    u8 field_002B;
} SDSequenceTrack;
typedef struct {
    SDSecondaryRecord channels[16 ];
    SDSecondaryObject objects[20 ];
    u8 pad04A0[4];
    SDSecondaryTransfer transfer;
    SpuVoiceAttr voice_attr;
    u8 flag_0500;
    u8 flag_0501;
    u8 flag_0502;
    u8 event_guard;
    long event_handle;
    u8 field_0508;
    u8 field_0509;
    u8 pad050A[2];
    void (*field_050C)(void);
    s16 object_count;
    s16 field_0512;
    u16 field_0514;
    u16 field_0516;
    SDSequenceTrack tracks[16 ];
    u8 pad07D8[4];
    u8 *field_07DC;
    s16 field_07E0;
    s16 field_07E2;
    s16 field_07E4;
    s16 field_07E6;
    u8 *field_07E8;
    s32 field_07EC;
    s32 field_07F0;
    s32 field_07F4;
    u16 field_07F8;
    u16 track_count;
    u16 timebase;
    u8 pad07FE[2];
    u8 field_0800;
    u8 field_0801;
    u8 pad0802[2];
    s32 field_0804;
    s32 field_0808;
    s32 field_080C;
    s32 field_0810;
    u8 field_0814;
    u8 field_0815;
    u8 pad0816[2];
    u32 bytes_consumed;
    s32 field_081C;
    u8 pad0820[0x24];
    u8 field_0844;
    u8 field_0845;
    u8 pad0846[2];
} SDSecondaryState;
extern SDSecondaryState *D_8009B458;
s32 func_8004A8E4(s32 index, s32 value);
s32 func_8004A940(s32 value, s32 variant);
extern 
s32 func_8004A940(s32 value, s32 variant)
{
    SDSecondaryState *state = D_8009B458;
    s32 i;
    s32 result = -1;
    u32 best;

     
    do {
        do {
            do {
                i = 0;
                if (state->object_count > 0) {
                    s32 none = 0x63 ;
                    s32 count = state->object_count;
                    do {
                        if (state->objects[i].channel_index == none) {
                            return i;
                        }
                        i++;
                    } while (i < count);
                }

                state = D_8009B458;
                i = 0;
                if (state->object_count > 0) {
                    s32 count = state->object_count;
                    do {
                        if (state->objects[i].field_000D == 0) {
                            return func_8004A8E4(i, (u8)value);
                        }
                        i++;
                    } while (i < count);
                }

                state = D_8009B458;
                i = 0;
                if (state->object_count > 0) {
                    do {
                        u8 owner = state->objects[i].channel_index;
                        if (owner == (u8)value &&
                            state->objects[i].field_0005 == (u8)variant) {
                            return func_8004A8E4(i, owner);
                        }
                        state = D_8009B458;
                        i++;
                    } while (i < state->object_count);
                }

                state = D_8009B458;
                i = 0;
                if (state->object_count > 0) {
                    s32 count = state->object_count;
                    do {
                        if (state->objects[i].field_000D == 0) {
                            return func_8004A8E4(i, (u8)value);
                        }
                        i++;
                    } while (i < count);
                }
            } while (0);
        } while (0);
    } while (0);

    state = D_8009B458;
    best = 0xFFFF;
    i = 0;
    if (state->object_count > 0) {
        s32 count = state->object_count;
        do {
            u16 candidate = state->objects[i].field_001E;
            if (candidate < best) {
                best = candidate;
                result = i;
            }
            i++;
        } while (i < count);
    }
    if (best >= 0xFFFF) {
        return -1;
    }
    return func_8004A8E4(result, (u8)value);
}
