#include "common.h"

/* arg0 is the record index func_80035AB8 scales, not a pointer -- see the
 * note on func_80035AB8 in functions.h. */
void func_80035BE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5) {
    func_80035AB8(arg0, arg2, arg3, arg4, arg5);
    func_80035AF0(arg0, arg1, 0);
}
