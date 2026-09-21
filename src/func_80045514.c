/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80045514.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern SDValue *D_8009B45C __attribute__((section(".data")));
void func_80045514(void)
{
    SDValue *entry_state;
    u32 first_word;
    u32 second_word;

    switch (D_8009B45C->field_007C) {
    case 81:
        func_800476B4((SDSeqBlock *)D_8009B45C->field_0058,
                     (u32)D_8009B45C->field_0050);
        goto clear_7d_7c;

    case 32:
        switch (D_8009B45C->field_007D) {
        case 0:
            if (func_80014C40(0, 0) != 0) {
                return;
            }
            if (D_8009B45C->field_04CC != 0) {
                return;
            }
            {
                SDValue *sd = D_8009B45C;
                FileRequestSlot *b = D_8009B460;
                s32 final_word;

                b->field_10 = (s32)sd->field_005C[4];
                b->field_0C = (s32)sd->field_005C[3];
                b->field_04 = (s32)sd->field_005C[1];
                b->field_18 = (s32)sd->field_005C[6];
                final_word = (s32)sd->field_005C[5];
                b->field_1F = 0;
                b->field_1C = 0;
                b->field_14 = final_word;
                D_8009B460->field_1E = 0;
            }
            D_8009B460->field_00 = (s32)D_8009B45C->field_005C[0];
            if (D_8009B460->field_18 == 0 && D_8009B460->field_14 == 0) {
                D_8009B45C->field_007D = 0;
                goto clear_7c;
            }
            switch ((s32)D_8009B45C->field_005C[0] & 0xF0) {
            case 0x10:
                D_8009B460->field_00 = 4;
                func_80014C40(D_8009B460, D_8009B45C->field_1629);
                break;
            case 0x20:
                D_8009B460->field_00 = 5;
                func_80014C40(D_8009B460, D_8009B45C->field_1619);
                break;
            case 0x40:
                D_8009B460->field_00 = 6;
                func_80014C40(D_8009B460, D_8009B45C->field_1639);
                break;
            }
            func_8004545C();
            D_8009B45C->field_007D = D_8009B45C->field_007D + 1;
            return;
        case 1:
            break;
        default:
            return;
        }
        if (D_8009B45C->busy != 0) {
            return;
        }
        D_8009B45C->field_007D = 0;
        D_8009B45C->field_007C = 0;
        if ((func_80045484() & 0xFF) != 0) {
            return;
        }
        D_8009B45C->flags_0040 = D_8009B45C->flags_0040 & 0xFFFC;
        return;

    case 17:
        switch (D_8009B45C->field_007D) {
        case 0:
            if (D_8009B45C->cd_volume == 0) {
                D_8009B45C->field_007D = 1;
                return;
            }
            if (D_8009B45C->field_0512 < 0) {
                return;
            }
            D_8009B45C->field_0512 = -0x20;
            D_8009B45C->field_0049 = 0;
            return;
        case 1:
            break;
        default:
            return;
        }
        D_8009B45C->field_0534 = 0xFFFF;
        if ((func_80045484() & 0xFF) != 0) {
            goto clear_7d_7c;
        }
        {
            SDValue *sd = D_8009B45C;
            u16 flags = sd->flags_0040;
            sd->field_007D = 0;
            sd->flags_0040 = flags & 0xFFF8;
            D_8009B45C->field_007C = 0;
        }
        return;

    case 33:
        if (func_80014C40(0, 0) != 0) {
            goto clear_7d_7c;
        }
        {
            SoundCommandPair *e;
            s32 base_offset;

            first_word = 0xFFFFFF;
            e = (SoundCommandPair *)(
                (u32)&((SoundCommandPair *)0)[D_8009B45C->field_004E]
                + (u32)D_8009B45C->field_0058);
            second_word = e->a;

            D_8009B460->field_10 = 0;
            D_8009B460->field_18 = 0;
            D_8009B460->field_0C = 0;
            D_8009B460->field_14 = 0;
            D_8009B460->field_1C = 0;
            D_8009B460->field_1F = D_8009B45C->field_0530;
            second_word &= first_word;
            D_8009B460->field_1E = D_8009B45C->field_0531;
            base_offset = (s32)D_8009B45C->field_0050;
            D_8009B460->field_00 = 6;
            second_word += base_offset;
            D_8009B460->field_04 = second_word;
            func_80014C40(D_8009B460, 0);
        }
        goto clear_7d_7c;

    case 36:
        if (func_80014C40(0, 0) != 0) {
            goto clear_7d_7c;
        }
        {
            u32 value_mask = 0xFFFFFF;
            SoundCommandPair *e;
            s32 request_offset;
            u32 low_a;

            entry_state = D_8009B45C;
            e = (SoundCommandPair *)((u32)entry_state->field_004E * 8
                                     + (u32)entry_state->field_0058);
            first_word = e->a;
            second_word = e->b;

            low_a = first_word & value_mask;
            value_mask &= second_word;
            entry_state->field_0528 = low_a;
            entry_state->field_0531 = (first_word & 0x1F000000) >> 24;
            entry_state->field_052C = value_mask;
            D_8009B45C->field_0530 = (second_word & 0x1F000000) >> 24;
            second_word >>= 31;
            D_8009B45C->field_0532 = second_word;
            first_word >>= 29;
            D_8009B45C->mix_multiplier = first_word;
            D_8009B45C->field_0528 =
                D_8009B45C->field_0528 + (s32)D_8009B45C->field_0050;
            D_8009B45C->field_052C =
                D_8009B45C->field_052C + (s32)D_8009B45C->field_0050;
            D_8009B460->field_10 = 0;
            D_8009B460->field_18 = 0;
            D_8009B460->field_0C = 0;
            D_8009B460->field_14 = 0;
            D_8009B460->field_1C = (u16)D_8009B45C->field_052C
                                   - (u16)D_8009B45C->field_0528 + 0x10;
            D_8009B460->field_1F = D_8009B45C->field_0530;
            D_8009B460->field_1E = D_8009B45C->field_0531;
            request_offset = D_8009B45C->field_0528;
            D_8009B460->field_00 = 6;
            D_8009B460->field_04 = request_offset;
            func_80014C40(D_8009B460, 0);
        }
        goto clear_7d_7c;

    case 41:
    case 42:
        if (D_8009B45C->field_007E != 0 && D_8009B45C->field_0512 != 0) {
            return;
        }
        D_8009B45C->field_007C = 0;
        goto clear_7d;

    case 72:
        if (D_8009B45C->field_157A != 0) {
            SDMusicPackage *list = (SDMusicPackage *)D_8009B45C->music_track;

            D_8009B45C->field_157A = func_800496C4(
                (SDVabHeader *)list->vab_header, 0, list->spu_address
            );
            if ((s16)D_8009B45C->field_157A != 0) {
                D_8009B45C->field_007C = 0;
                return;
            }
        }
        if (D_8009B45C->field_157E == 0) {
            if ((D_8009B45C->flags_0040 & 0x80) != 0) {
                func_80049C40(0);
                func_80049F10(0, 0);
                D_8009B45C->field_1586 = 0;
                D_8009B45C->field_1588 = 0;
                D_8009B45C->flags_0040 = D_8009B45C->flags_0040 & 0xFF7F;
            }
            func_80049CB0(D_8009B45C->field_157E);
            D_8009B45C->field_157E = -1;
        }
        {
            CommandIndexTable *l;
            u32 i;

            entry_state = D_8009B45C;
            l = (CommandIndexTable *)entry_state->music_track;
            i = entry_state->field_004E & 0xF;

            if (i >= l->count) {
                D_8009B45C->field_007C = 0;
                return;
            }
            D_8009B45C->field_157E = func_80049A64(
                (u8 *)(
                    (u32)&((u8 (*)[16])0)[l->index_records[i][0]] + (u32)l),
                                             entry_state->field_157A);
            if ((s16)D_8009B45C->field_157E == 0) {
                D_8009B45C->field_157C = D_8009B45C->field_004E;
                func_80049AF4(1, 1);
                {
                    SDValue *sd = D_8009B45C;
                    sd->field_158A = 0xFF;
                    sd->flags_0040 = sd->flags_0040 | 0x80;
                    sd->field_1588 = (u16)sd->field_0054;
                }
            }
        }
        D_8009B45C->field_007C = 0;
        goto clear_7d;

    case 0:
        break;
    }

    goto clear_7d_7c;

clear_7d:
    D_8009B45C->field_007D = 0;
    return;

clear_7d_7c:
    D_8009B45C->field_007D = 0;
clear_7c:
    D_8009B45C->field_007C = 0;
}
