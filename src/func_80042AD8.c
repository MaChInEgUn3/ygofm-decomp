#include "common.h"

/* Steps `x` toward `limit` by `step`, clamping so it never overshoots.
 * The sign of `limit` picks the direction. */
int func_80042AD8(int x, int limit, int step) {
    if (limit < 0) {
        x -= step;
        if (x < limit) {
            x = limit;
        }
    } else {
        x += step;
        if (x > limit) {
            x = limit;
        }
    }
    return x;
}
