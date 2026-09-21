/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_sequence_parser.c (SD_DispatchSequenceChannelEvent), profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern SDSecondaryState *D_8009B458;
void func_8004B374(s32 channel, s32 value, s32 unused);
void func_8004B49C(s32 arg0, s32 arg1, u8 arg2);
void func_8004B6E8(u8 index, s32 value);
void func_8004B70C(u8 index, s32 unused, s32 value);
void func_8004C114(SDSequenceTrack *p, s32 status, u8 d1, u8 d2);
void func_8004ADE8(s32 channel, s32 note, s32 velocity);
void func_8004C114(SDSequenceTrack *p, s32 status, u8 d1, u8 d2) {
    SDSequenceTrack *t;
    u8 ch;
    s32 i;
    u8 v;

    ch = status & 0x0F ;
    switch (status & 0xF0 ) {
    case 0x80 :
        func_8004B374(ch, d1, d2);
        break;
    case 0x90 :
        if (d2 != 0) {
            func_8004ADE8(ch, d1, d2);
        } else {
            func_8004B374(ch, d1, 0);
        }
        break;
    case 0xB0 :
        if (d1 == 0x63 ) {
            if (d2 == 0x14 ) {
                SDSecondaryState *seq;

                seq = D_8009B458;
                if (seq->field_07F8 != 0) {
                    if (seq->track_count != 0) {
                        i = 0;
                        do {
                            t = &seq->tracks[i];
                            t->ended_saved = t->ended;
                            t->running_status_saved = t->running_status;
                            t->loop_count = d2;
                            t->pos_saved = t->pos;
                            t->delta_remaining_saved = t->delta_remaining;
                            t->field_0018_saved = t->field_0018;
                            seq = D_8009B458;
                            i++;
                        } while (i < seq->track_count);
                    }
                    D_8009B458->field_07F4 = D_8009B458->field_07F0;
                } else {
                    p->loop_count = 0x7F ;
                    p->pos_saved = p->pos;
                }
            } else if (d2 == 0x1E ) {
                v = p->loop_count;
                if (v != 0) {
                    SDSecondaryState *seq;

                    if (v < 0x7F ) {
                        p->loop_count = v - 1;
                    }
                    seq = D_8009B458;
                    if (seq->field_07F8 != 0) {
                        if (seq->track_count != 0) {
                            i = 0;
                            do {
                                t = &seq->tracks[i];
                                t->ended = t->ended_saved;
                                t->running_status = t->running_status_saved;
                                t->pos = t->pos_saved;
                                t->delta_remaining = t->delta_remaining_saved;
                                t->field_0018 = t->field_0018_saved;
                                seq = D_8009B458;
                                i++;
                            } while (i < seq->track_count);
                        }
                        D_8009B458->field_07F0 = D_8009B458->field_07F4;
                    } else {
                        p->pos = p->pos_saved;
                    }
                }
            }
        }
        if (d1 == 6 ) {
            SDSecondaryState *seq;

            seq = D_8009B458;
            if (seq->channels[ch].control_mode == 0x14 ) {
                if (seq->field_07F8 != 0) {
                    if (seq->track_count != 0) {
                        i = 0;
                        do {
                            seq->tracks[i].loop_count = d2;
                            seq = D_8009B458;
                            i++;
                        } while (i < seq->track_count);
                    }
                } else {
                    p->loop_count = d2;
                    break;
                }
            }
        }
        func_8004B49C(ch, d1, d2);
        break;
    case 0xC0 :
        func_8004B6E8(ch, d1);
        break;
    case 0xE0 :
        func_8004B70C(ch, d1, d2);
        break;
    }
}
