/* 2026-09-05, still 8: retail computes (arg1 & 1) << 2 and the 0xFF FIRST, then
 * off = 0, then the D_800F2B50 base; we emit the base locals first. Naming the
 * shifted flag as a first statement (m), with and without off = 0 moved above
 * the base, and with the 0xFF named as well, are all -3 and 80: the name lets
 * gcc hoist the OR out of the pin and the h chain shortens. Not that lever. */
#include "common.h"

typedef struct 
{
  u8 unk0;
  u8 unk1[8];
  u8 unk9;
  u16 unkA;
  u16 unkC;
  u16 unkE;
  Word4 unk10;
  Word4 unk14;
} Rec58938;
void func_80058938(s32 arg0, s32 arg1, Word4 arg2, Word4 arg3, s32 arg4, s32 arg5)
{
  u8 *tbl;
  int new_var;
  u8 *base;
  Rec58938 *r;
  s32 off;
  s32 i;
  s32 o;
  u16 h;
  Rec58938 *end;
  base = D_800F2B50;
  tbl = D_800F2C40 + (arg0 * 3616);
  new_var = (arg0 & 1) << 1;
  off = 0;
  r = (Rec58938 *) base;
  end = r + 10;
  do
  {
    if ((r->unk0 & 1) == 0)
    {
      do
      {
        h = *((u16 *) (&r->unk0));
        h |= 1;
        h &= 0xFFFD;
        h |= new_var;
        h &= 0xFFFB;
        h |= (arg1 & 1) << 2;
      }
      while (0);
      i = 0;
      *((u16 *) (&r->unk0)) = h;
      h &= 0xFF07;
      h |= (tbl[0xBF5] & 0x1F) << 3;
      o = off;
      *((u16 *) (&r->unk0)) = h;
      off = (r->unkA = *((u16 *) (tbl + 0xE06)));
      r->unkC = 0;
      r->unkE = arg4 * 2;
      r->unk10 = arg2;
      r->unk14 = arg3;
      for (; i < 8; i++)
      {
        u8 *dst = (u8 *)((i + o) + (s32)base);
        if (arg5 != 0)
        {
          dst[1] = *((u8 *) (arg5 + i));
        }
        else
        {
          dst[1] = 0xFF;
        }
      }

      return;
    }
    r++;
    off += 0x18;
  }
  while (((s32) r) < ((s32) end));
}
