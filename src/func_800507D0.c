/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_intro_controller.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern ModelSlot D_800F2C40[3 ];
extern s8 D_8009AF9A;
extern u8 D_8009AFA4[4];
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
void func_80057AF4(s32 index, s32 anim, s32 flag);
void func_80059F18(s32 first, s32 second, s32 third, s32 fourth);
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
extern int  func_8008E590(void);
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
