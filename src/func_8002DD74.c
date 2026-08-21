/* The first half of what splat merged under this name; func_8002DDFC is the
 * other. `u32 v` rather than `s32`: with a signed word gcc narrows `v | 0x80`
 * to QImode, the constant becomes -128, it no longer fits an `ori` immediate
 * and gets hoisted into a callee-saved register -- two instructions and a
 * saved register the target does not have. Same word as func_80043BCC. */
#define D_8009B26C_IS_SCALAR
#include "common.h"

void func_8002DD74(void) {
    u32 v;

    func_8002CDE8();

    while (1) {
        func_80012D4C();
        v = D_8009B26C;
        if ((v & 0x80) == 0) {
            D_8009B26C = v | 0x80;
            func_8002CD8C();
        } else {
            D_80090B64[v & 0x1F]();
            if ((D_8009B26C & 0x40) == 0) {
                func_80015B00();
            }
        }
    }
}
