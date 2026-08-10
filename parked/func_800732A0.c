#include "common.h"

void func_800732A0(void)
{
  short new_var;
  u8 *p = (u8 *) D_800F5BE8;
  s32 n = 0;
  s32 i = n;
  new_var = i;
  while (i <= p[0xA3])
  {
    s32 c = p[new_var + 0x38];
    if (c >= 0xB)
    {
      D_800EAE88[n] = c;
      n++;
    }
    p++;
    p--;
    i++;
  }

}
