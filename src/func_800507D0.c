/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_intro_controller.c, profile gcc_2_8_1_g8_split.
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
typedef struct  {
	short	m[3][3];	 
        long    t[3];		 
} MATRIX;
typedef struct {		 
	short	vx, vy;
	short	vz, pad;
} SVECTOR;
typedef struct {
    u32 field_00;
    void *field_04;
} ModelSlotHeadEntry;
typedef struct {
    u16 values[58 ];
    u16 max;
} ModelSlotRow;
typedef struct {
    u32 rewrite_idx;
    u16 size;
    u16 num;
    u16 ii;
    u16 aframe;
    u8 sid;
    s8 speed;
    u16 srcii;
    s16 rframe;
    u16 tframe;
    u16 ci;
    u16 ti;
    u16 start;
    u8 start_sid;
    u8 traveling;
} ModelSlotPart;
typedef struct {
    u8 frame;
    u8 id;
    u16 flags;
} ModelSlotSoundEntry;
typedef struct {
    s32 field_00;
    s32 field_04;
    s32 field_08;
    u8 field_0C[3];
    u8 pad_0F;
} ModelSlotLightEntry;
typedef struct {
    s32 field_00;
    s32 field_04;
    s32 field_08;
    s32 field_0C;
} ModelSlotS32Quad;
typedef union {
    struct {
        u8 field_00[0xA];
        u8 field_0A[2];
    } bytes;
    struct {
        u16 field_00;
        u16 field_02;
        u8 field_04[4];
        u32 field_08;
    } values;
     




    struct {
        u8 pad_00[7];
        u8 min_x;
        u8 min_y;
        u8 min_z;
        u8 pad_0A[2];
    } thresholds;
} ModelSlotCF8Prefix;
typedef struct {
    ModelSlotCF8Prefix prefix;
    u16 field_0C[2];
    s32 field_10;
    s32 field_14;
    s32 field_18;
} ModelSlotCF8Block;
typedef struct {
    ModelSlotHeadEntry field_000[60 ];
    ModelSlotPart *field_1E0[58 ];
     



    u16 field_2C8[10 ][58 ];
    ModelSlotRow field_750[10 ];
     



    u8 field_BEC[8];
    u8 field_BF4;
    u8 field_BF5;
    u8 field_BF6;
    u8 field_BF7;
    ModelSlotSoundEntry sound_entries[64 ];
    ModelSlotCF8Block field_CF8;
    u8 *entries;
     



    struct _GsCOORDUNIT *field_D18;
     

    struct _GsCOORDUNIT *field_D1C;
    u8 pad_D20[0x50];
    ModelSlotLightEntry field_D70[3];
    s32 field_DA0[3];
    u8 pad_DAC[4];
    ModelSlotS32Quad field_DB0;
    u8 field_DC0[8];
    u16 field_DC8[4];
    s16 field_DD0[4];
     



    s32 *field_DD8;
    u8 *field_DDC;
    u8 *field_DE0;
    u8 *field_DE4;
     

    s32 field_DE8;
    s32 field_DEC;
     



    s32 field_DF0;
    s32 field_DF4;
    u16 field_DF8;
    u16 field_DFA;
    u16 field_DFC;
    u8 field_DFE;
    u8 field_DFF;
     


    u16 field_E00;
     
    u16 field_E02;
    u16 field_E04;
    u16 field_E06;
     



    u16 field_E08;
     


    u16 field_E0A;
     


    u8 field_E0C;
    u8 field_E0D;
    u8 field_E0E;
    u8 field_E0F;
    u8 field_E10;
    u8 field_E11;
    u8 field_E12;
    u8 field_E13;
    u8 field_E14;
    u8 field_E15;
    u8 field_E16;
    u8 entry_count;
    u8 field_E18;
    u8 field_E19;
    u8 field_E1A;
    u8 field_E1B;
    u8 field_E1C;
     



    u8 field_E1D;
    u8 field_E1E;
    u8 field_E1F;
} ModelSlot;
typedef char ModelSlot_field_750_max_offset_must_be_0x7C4[
    ((u32)&((( ModelSlot  *)0)->  field_750[0].max ))  == 0x7C4 ? 1 : -1
];
extern ModelSlot D_800F2C40[3 ];
extern s8 D_8009AF9A;
extern u8 D_8009AFA4[4];
typedef union {
    u32 word;
    u8 bytes[4];
    u16 halfwords[2];
    struct {
        u8 field_00;
        u8 field_01;
        s16 height;
    } fields;
} ModelDebugState;
extern ModelDebugState D_8009B004;
void func_80059590(
    s32 slot,
    s32 mode,
    s32 target0,
    s32 target1,
    s32 target2
);
s32 func_8004703C(void);
void func_80047314(u32 value);
typedef struct FileTransferDescriptor FileTransferDescriptor;
typedef void (*FileTransferCallback)();
struct FileTransferDescriptor {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u32 value_08;
    u32 value_0C;
     

    s32 total_bytes;
    s32 file_bytes;
    u8 *loader_argument;
     

    u32 phase_size;
    FileTransferCallback phase_callback;
    s32 absolute_lba;
    s32 phase_remaining;
    u32 status_flags;
     












    union {
        struct {
            u16 counter;
            u16 field_32;
        } h;
        u32 word;
    } field_30;
    s32 direct_destination;
    void *callback_data;
    u32 position;
    u32 result;
    u16 buffer_index;
    u8 done;
    u8 substate;
};
void func_80057AF4(s32 index, s32 anim, s32 flag);
void func_80059F18(s32 first, s32 second, s32 third, s32 fourth);
struct _GsCOORDUNIT;
void func_80050584(s32 index);
void func_800507D0(void);
void func_8004763C(void);
void func_80059AEC(s32 value);
FileTransferDescriptor *func_80014E1C(
    s32, u8 *, s32, s32, FileTransferCallback, s32, s32
);
void func_800137E4(void);
extern s32 D_80010030 __attribute__((section(".data")));
extern void *D_80010034 __attribute__((section(".data")));
typedef struct _GsCOORDUNIT {
	unsigned long		flg;
	MATRIX			matrix;
	MATRIX			workm;
	SVECTOR			rot;
	struct _GsCOORDUNIT	*super;
}	GsCOORDUNIT;
extern int  func_8008E590(void);
struct _GsCOORDUNIT;
extern ;
void func_801807B0(void);
void func_80181C4C(s32 value);
s32 func_80180A24(void);
extern u8 D_800114F8[];
void func_80049394(u16 *track);
void func_800493F8(void);
void func_800507D0(void)
{
  s8 phase_value;
  ModelSlot *first_base;
  ModelSlot *cross_base;
  ModelSlot *lookup_base;
  ModelSlot *fade_models;
  u8 *fade_a;
  u8 *fade_b;
  s32 active_offset;
  u8 *active_color;
  s32 red_sample;
  s32 red_target;
  s32 green_sample;
  s32 green_target;
  s32 red;
  s32 blue_target;
  s8 next_red;
  s32 green;
  s8 next_green;
  s32 blue;
  s8 next_blue;
  s32 *active_model;
  u32 frame;
  s32 animation;
  s8 next_phase;
  s32 peer;
  s32 crossfade_offset;
  u8 *outgoing_color;
  u8 *incoming_color;
  u32 peer_red;
  u32 peer_green;
  u32 peer_blue;
  s32 result;

  func_80059AEC(1);
  switch ( D_8009AF9A )
  {
    case -1:
      func_80014E1C(1, D_800114F8, 1223, 16, 0, 0, D_80010030);
      func_800137E4();
      D_8009B004.fields.field_01 = 0;
      D_8009B004.fields.field_00 = 0;
      D_8009AFA4[3]  = 0;
      D_800F2C40[0].field_E1F = 0;
      D_800F2C40[1].field_E1F = 0;
      func_80059590(0, 2, 0, 0, 0);
      func_80059590(1, 2, 0, 0, 0);
      func_801807B0();
      func_80181C4C(0);
      func_80049394((u16 *)D_80010034);
      func_80047314(29488);
      phase_value = D_8009AF9A + 1;
      goto store_phase;
    case 0:
      first_base = D_800F2C40;
      active_offset = (u32)&((ModelSlot *)0)[(u8)D_8009AFA4[3] ];
      if ( ((ModelSlot *)( ((u8 *)( first_base ))  + active_offset )) ->field_E1F )
      {
        if ( (((ModelSlot *)( ((u8 *)( D_800F2C40 ))  + active_offset )) ->field_E15 & 3) == 0 )
        {
          active_color = ((ModelSlot *)( 
              ((u8 *)( D_800F2C40 ))  + active_offset )) ->field_DC0;
          red_sample = func_8008E590() >> 8;
          red_sample %= 24;
          red_target = red_sample + 8;
          green_sample = func_8008E590() >> 8;
          green_sample %= 24;
          green_target = green_sample + 8;
          blue_target = func_8008E590() >> 8;
          blue_target %= 24;
          blue_target += 8;
          red = active_color[0];
          if ( red != red_target )
          {
            if ( red >= red_target )
              next_red = red - 1;
            else
              next_red = red + 1;
            active_color[0] = next_red;
          }
          green = active_color[1];
          if ( green != green_target )
          {
            if ( green >= green_target )
              next_green = green - 1;
            else
              next_green = green + 1;
            active_color[1] = next_green;
          }
          blue = active_color[2];
          if ( blue != blue_target )
          {
            if ( blue >= blue_target )
              next_blue = blue - 1;
            else
              next_blue = blue + 1;
            active_color[2] = next_blue;
          }
        }
        if ( !D_8009B004.fields.field_01 )
          func_80050584((u8)D_8009AFA4[3]  ^ 1);
        lookup_base = D_800F2C40;
        active_model = (s32 *)&lookup_base[(u8)D_8009AFA4[3] ];
        if ( ! ((ModelSlot *)( active_model )) ->field_E0F )
        {
          frame = ((ModelSlot *)( active_model )) ->field_E15;
          animation = -1;
          if ( !(u8)(frame % 0x1E) )
          {
            switch ( (u8)(frame / 0x1E) )
            {
              case 1u:
                animation = 2;
                break;
              case 3u:
                animation = 7;
                break;
              case 0u:
              case 2u:
              case 4u:
                animation = 1;
                break;
              default:
                break;
            }
            if ( animation < 0 )
            {
              if ( D_8009B004.fields.field_01 )
              {
                next_phase = 2;
                goto set_phase_and_tick;
              }
              peer = (u8)D_8009AFA4[3]  ^ 1;
              if ( ((ModelSlot *)( 
                       ((u8 *)( D_800F2C40 ))  +
                       (904 * peer) * 4 )) ->field_E1F )
              {
                func_80059F18(1, -1, peer, 90);
                next_phase = D_8009AF9A + 1;
                goto set_phase_and_tick;
              }
            }
            else
            {
              func_80057AF4((u8)D_8009AFA4[3] , animation, 1);
            }
          }
          goto tick_active_slot;
        }
      }
      else
      {
        func_80050584((u8)D_8009AFA4[3] );
        if ( ((ModelSlot *)( 
                 ((u8 *)( D_800F2C40 ))  +
                 (904 * (u8)D_8009AFA4[3] ) * 4 )) ->field_E1F )
          func_80059F18(1, -1, (u8)D_8009AFA4[3] , 30);
      }
      goto poll_module;
    case 1:
      cross_base = D_800F2C40;
      crossfade_offset = 904 * (u8)D_8009AFA4[3] ;
      if ( (((ModelSlot *)( 
                ((u8 *)( cross_base ))  +
                (crossfade_offset) * 4 )) ->field_E15 & 3) == 0 )
      {
        outgoing_color = ((ModelSlot *)( 
            ((u8 *)( D_800F2C40 ))  +
            (crossfade_offset) * 4 )) ->field_DC0;
        incoming_color = ((ModelSlot *)( 
            ((u8 *)( D_800F2C40 ))  +
            (904 * ((u8)D_8009AFA4[3]  ^ 1)) * 4 )) ->field_DC0;
        if ( outgoing_color[0] )
          --outgoing_color[0];
        if (outgoing_color[1])
          --outgoing_color[1];
        if (outgoing_color[2])
          --outgoing_color[2];
        peer_red = incoming_color[0];
        if ( peer_red < 8 )
          incoming_color[0] = peer_red + 1;
        peer_green = incoming_color[1];
        if ( peer_green < 8 )
          incoming_color[1] = peer_green + 1;
        peer_blue = incoming_color[2];
        if ( peer_blue < 8 )
          incoming_color[2] = peer_blue + 1;
        if ( !outgoing_color[0] && !outgoing_color[1] && !outgoing_color[2] )
        {
          ((ModelSlot *)( 
              ((u8 *)( cross_base ))  +
              (904 * (u8)D_8009AFA4[3] ) * 4 )) ->field_E1F = 0;
          D_8009AF9A = 0;
          D_8009AFA4[3]  ^= 1u;
        }
      }
      goto tick_active_slot;
    case 2:
      fade_models = D_800F2C40;
      if ( (((ModelSlot *)( 
                ((u8 *)( fade_models ))  +
                (904 * (u8)D_8009AFA4[3] ) * 4 )) ->field_E15 & 3) != 0 )
        goto tick_active_slot;
      fade_a = fade_models[0].field_DC0;
      fade_b = fade_models[1].field_DC0;
      if ( fade_models[0].field_DC0[0] )
        --fade_models[0].field_DC0[0];
      if ( fade_a[1] )
        --fade_a[1];
      if ( fade_a[2] )
        --fade_a[2];
      if ( fade_models[1].field_DC0[0] )
        fade_models[1].field_DC0[0] = fade_models[1].field_DC0[0] - 1;
      if ( fade_b[1] )
        --fade_b[1];
      if ( fade_b[2] )
        --fade_b[2];
      if ( fade_models[0].field_DC0[0]
        || fade_a[1] || fade_a[2]
        || fade_models[1].field_DC0[0]
        || fade_b[1] || fade_b[2] )
      {
        goto tick_active_slot;
      }
      fade_models[1].field_E1F = 0;
      fade_models[0].field_E1F = 0;
      next_phase = D_8009AF9A + 1;
      goto set_phase_and_tick;
set_phase_and_tick:
      D_8009AF9A = next_phase;
tick_active_slot:
      ++ ((ModelSlot *)( ((u8 *)( D_800F2C40 ))  + (904 * (u8)D_8009AFA4[3] ) * 4 )) ->field_E15;
      goto poll_module;
    case 3:
      func_800493F8();
      func_8004763C();
      phase_value = -2;
store_phase:
      D_8009AF9A = phase_value;
      goto poll_module;
    default:
      goto poll_module;
  }
poll_module:
      if ( D_8009B004.fields.field_00 )
      {
        result = func_80180A24();
        if ( result )
        {
          result = D_8009B004.fields.field_01;
          if ( !D_8009B004.fields.field_01 )
          {
            result = (s16)func_8004703C();
            if ( (s16)result != 128 )
            {
              ++D_8009B004.fields.field_01;
              D_8009AF9A = 2;
            }
          }
        }
      }
      else
      {
        if (func_8004703C() & 0x80)
        {
          result = (u8)D_800F2C40[0].field_E1F;
          if ( D_800F2C40[0].field_E1F )
          {
            result = D_8009B004.fields.field_00 + 1;
            ++D_8009B004.fields.field_00;
          }
        }
      }
      return;
}
