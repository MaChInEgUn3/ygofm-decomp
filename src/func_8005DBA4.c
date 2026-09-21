/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_keyframe_update.c, profile gcc_2_8_1_g8_split_no_strength_reduce.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern SVECTOR D_800F5768[3 ];
extern Key D_800F5788[10];
void func_8005EBF4(Key *cur, s32 k, s32 scale, s32 den, s16 *out);
void func_8005E808(Key *key);
void func_8005F070(s32 enabled);
extern Key *D_8009B074;
extern u8 D_8009B078;
extern u8 D_8009B079;
extern s8 D_8009B07A;
extern u8 D_8009B07B;
extern u8 D_8009B07C;
void func_8005DBA4(void);
s32 func_80058E1C(void);
void func_80058434(s32 direction, s32 yaw, s32 pitch, s32 distance, s32 unused);
static inline s32 Keyframe_ApplyDeadzone(s16 *axis, s32 amount)
{
    s32 value = *axis;
    if (value > 0) {
        s32 result = value - amount;
        return result < 0 ? 0 : result;
    } else {
        s32 result = value + amount;
        return result > 0 ? 0 : result;
    }
}
void func_8005DBA4(void)
{
    s32 *outputs[2];
    s16 position[4];
    s16 evaluated[4];
    s16 target[4];
    s16 delta[4];
    s32 active;
    s32 persistent;
    s32 channel;
    s32 offset;
    s32 **output;
    s16 *pose;
    s16 *interpolated;

    outputs[0] = func_800591FC();
    outputs[1] = outputs[0] + 3;
    persistent = 0;
    active = 0;
    if (!D_8009B078 || !D_8009B074) {
        return;
    }
    if (D_8009B079 && (D_8009B07B != 1 || D_8009B07C != 1)) {
        Key *key = D_800F5788;
        s32 i;
        for (i = 0; i < D_8009B078; i++) {
            func_8005E808(key++);
        }
        D_8009B079 = 0;
        D_8009B07A = -1;
    }
    if (D_8009B074->duration != 0x4000) {
        Key *previous = D_8009B074;
        s32 step = func_80058E1C();
        s32 elapsed;
        if (D_8009B074->progress + step <
            D_8009B074->duration) {
            step = func_80058E1C();
            elapsed = D_8009B074->progress + step;
        } else {
            elapsed = D_8009B074->duration;
        }
        previous->progress = elapsed;
    }
    channel = 0;
    interpolated = evaluated;
    output = outputs;
    pose = (s16 *)D_800F5768;
    offset = 0;
    do {
        u8 *key = (u8 *)D_8009B074;
        s16 *record = (s16 *)(key + offset);
        if (record[3] == 0) {
            goto next_channel;
        }
        switch (record[3]) {
        case 0x80:
        case 0x81: {
            s32 slot = (s16)((u16)record[3] & 0xFF7F);
            s32 elapsed = ((Key *)( key )) ->progress;
            s32 duration = ((Key *)( key )) ->duration;
            s32 remaining;
            if (func_80058DD8(slot) != 1) {
                break;
            }
            func_80058FB0(slot, (u16 *)position);
            {
                s16 *relative = (s16 *)((u8 *)D_8009B074 + offset);
                position[0] += (u16)relative[0];
                position[1] += (u16)relative[1];
                position[2] += (u16)relative[2];
            }
            remaining = duration - elapsed;
            (*output)[0] = pose[0] * remaining / duration
                + position[0] * elapsed / duration;
            (*output)[1] = pose[1] * remaining / duration
                + position[1] * elapsed / duration;
            (*output)[2] = pose[2] * remaining / duration
                + position[2] * elapsed / duration;
            break;
        }
        case 1: {
            s32 j;
            s16 *component;
            s32 **destination;
            func_8005EBF4(((Key *)( key )) , channel,
                ((Key *)( key )) ->progress, 0, interpolated);
            j = 0;
            destination = output;
            component = interpolated;
            for (; j < 3; j++) {
                (*destination)[j] = *component++;
            }
            break;
        }
        case 2:
        case 3: {
            s32 slot;
            s32 amount;
            persistent++;
            slot = record[0];
            amount = record[1];
            if (func_80058DD8(slot) != 1) {
                break;
            }
            func_80058FB0(slot, (u16 *)target);
            {
                s16 *following = (s16 *)((u8 *)D_8009B074 + offset);
                delta[0] = target[0] - (u16)following[8];
                delta[1] = target[1] - (u16)following[9];
                delta[2] = target[2] - (u16)following[10];
                if (following[3] == 2) {
                    if (amount == 0) {
                        amount = 10;
                    }
                    {
                        s32 value = delta[0];
                        if (value > 0) {
                            value -= amount;
                            if (value < 0) {
                                value = 0;
                            }
                        } else {
                            value += amount;
                            if (value > 0) {
                                value = 0;
                            }
                        }
                        delta[0] = value;
                    }
                    {

                        delta[1] = Keyframe_ApplyDeadzone(&delta[1], amount);
                    }
                    {
                        s32 value = delta[2];
                        if (value > 0) {
                            value -= amount;
                            if (value < 0) {
                                value = 0;
                            }
                        } else {
                            value += amount;
                            if (value > 0) {
                                value = 0;
                            }
                        }
                        delta[2] = value;
                    }
                    delta[0] = (( delta[0] ) > 0 ? (( delta[0] ) < (  60 ) ? ( delta[0] ) : (  60 )) : (( delta[0] ) > -(  60 ) ? ( delta[0] ) : -(  60 ))) ;
                    delta[1] = (( delta[1] ) > 0 ? (( delta[1] ) < (  60 ) ? ( delta[1] ) : (  60 )) : (( delta[1] ) > -(  60 ) ? ( delta[1] ) : -(  60 ))) ;
                    delta[2] = (( delta[2] ) > 0 ? (( delta[2] ) < (  60 ) ? ( delta[2] ) : (  60 )) : (( delta[2] ) > -(  60 ) ? ( delta[2] ) : -(  60 ))) ;
                    (*output)[0] += delta[0];
                    (*output)[1] += delta[1];
                    (*output)[2] += delta[2];
                    {
                        s16 *committed =
                            (s16 *)((u8 *)D_8009B074 + offset);
                        committed[8] += (u16)delta[0];
                        committed[9] += (u16)delta[1];
                        committed[10] += (u16)delta[2];
                    }
                } else {
                    if (amount == 0) {
                        amount = 2000;
                    }
                    delta[0] = (( delta[0] ) > 0 ? (( delta[0] ) < (  amount ) ? ( delta[0] ) : (  amount )) : (( delta[0] ) > -(  amount ) ? ( delta[0] ) : -(  amount ))) ;
                    delta[1] = (( delta[1] ) > 0 ? (( delta[1] ) < (  amount ) ? ( delta[1] ) : (  amount )) : (( delta[1] ) > -(  amount ) ? ( delta[1] ) : -(  amount ))) ;
                    delta[2] = (( delta[2] ) > 0 ? (( delta[2] ) < (  amount ) ? ( delta[2] ) : (  amount )) : (( delta[2] ) > -(  amount ) ? ( delta[2] ) : -(  amount ))) ;
                    (*output)[0] = pose[0] + delta[0];
                    (*output)[1] = pose[1] + delta[1];
                    (*output)[2] = pose[2] + delta[2];
                }
            }
            break;
        }
        case 5: {
            s32 amount = record[0];
            s32 first;
            s32 second;
            persistent++;
            if (((Key *)( key )) ->progress >= ((Key *)( key )) ->duration) {
                (*output)[0] = pose[0];
                (*output)[2] = pose[2];
                break;
            }
            first = func_8008E590();
            second = func_8008E590();
            first >>= 8;
            (*output)[0] = pose[0] + first % amount
                - ((second >> 8) % amount) / 2;
            first = func_8008E590();
            second = func_8008E590();
            first >>= 8;
            (*output)[2] = pose[2] + first % amount
                - ((second >> 8) % amount) / 2;
            break;
        }
        }
        active++;
next_channel:
        output++;
        pose += 4;
        channel++;
        offset += 8;
    } while (channel < 2);
    {
        s16 *orbit_pose;
        s32 **viewpoints;
        channel = 0;
        orbit_pose = (s16 *)D_800F5768;
        output = outputs;
        viewpoints = output;
        do {
            s32 elapsed;
            u8 *key = (u8 *)D_8009B074;
            s16 *record = (s16 *)(
                key + (u32)&((s16 (*)[4])0)[channel]
            );
            if (record[3] == 4) {
                s32 duration = (elapsed = ((Key *)( key )) ->progress,
                    ((Key *)( key )) ->duration);
                s32 yaw_step = record[1] * elapsed / duration;
                s32 pitch_step = record[2] * elapsed / duration;
                s32 radius = orbit_pose[8];
                s32 remaining = duration - elapsed;
                s32 yaw = yaw_step + orbit_pose[9];
                s32 pitch = pitch_step + orbit_pose[10];
                s32 cosine;
                s32 sine;
                s32 depth;
                s32 horizontal;
                s32 vertical;
                if (record[0] != 0) {
                    radius = (radius * remaining + record[0] * elapsed) / duration;
                }
                cosine = func_80086770(pitch);
                sine = func_800866A0(pitch);
                horizontal = radius * cosine / 0x1000;
                vertical = radius * sine / 0x1000;
                cosine = func_80086770(yaw);
                sine = func_800866A0(yaw);
                depth = horizontal * sine / 0x1000;
                horizontal = horizontal * cosine / 0x1000;
                {
                    s32 **opposite = viewpoints;
                    opposite += channel ^ 1;
                    (*output)[0] = (*opposite)[0] + horizontal;
                    (*output)[1] = (*opposite)[1] + vertical;
                    (*output)[2] = (*opposite)[2] + depth;
                }
            }
            channel++;
            output++;
        } while (channel < 2);
    }
    if (!active && D_8009B074->duration == 0x4000) {
        D_8009B074 = 0;
        D_8009B078 = 0;
        return;
    }
    if (D_8009B074->progress >=
        D_8009B074->duration) {
        func_8005F070(0);
        D_8009B074++;
        if (D_8009B074 - D_800F5788 >= D_8009B078) {
            if (D_8009B078 >= 2) {
                D_8009B074 = D_800F5788;
                D_8009B074->ready = 0;
            } else {
                D_8009B074 = 0;
                D_8009B078 = 0;
            }
        }
        if (D_8009B074) {
            func_8005E808(D_8009B074);
            if (D_8009B074->magnitude == 0) {
                func_8005DBA4();
            }
        }
    }
    if (persistent == 2) {
        func_80058434(1, 0x1000, 0, 0, 0);
    } else {
        func_80057F38(0);
    }
}
