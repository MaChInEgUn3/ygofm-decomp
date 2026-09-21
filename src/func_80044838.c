/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/mem_card_driver.c (MemCard_ProcessRequest), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern long func_800738D0(char *, unsigned long);
extern long func_80073910(long);
extern long func_800738E0(long, long, long);
extern long func_800738F0(long, void *, long);
extern long func_80073900(long, void *, long);
extern void func_8008B370(void);
extern long func_8008B380(long drv);
extern long func_8008B390(long drv);
extern long func_8008B350(long chan, long block, unsigned char *buf);
extern long func_8008B360(long chan, long block, unsigned char *buf);
s32 func_80044838(s32 mode, s32 *request, s32 *result);
extern long D_800F2AE0[];
extern volatile s32 D_8009B450;
extern u8 D_8009B437;
extern long D_800F2AF0[];
extern s8 D_8009B43E;
extern u8 D_8009B44F;
extern u16 D_8009B44C;
extern u16 D_8009B434;
extern char D_800F2B00[];
extern s32 D_8009B430;
extern u8 D_8009B436;
extern u8 D_8009B43C;
s32 func_80044470(s32 chan, const char *pattern, struct DIRENTRY *cursor,
                     s32 *out_count);
s32 func_80044608(void);
extern struct DIRENTRY *D_8009B444;
extern s32 D_8009B438;
void func_80043D48(long *handles);
void func_80043D48(long *handles);
s32 func_80044470(s32 chan, const char *pattern, struct DIRENTRY *cursor,
                      s32 *out_count);
s32 func_80044608(void);
s32 func_80044838(s32 arg0, s32 *out_state, s32 *out_result)
{
    s32 r;
    s32 fd;
    s32 tries;
    s32 mode;
    s32 resume_step;

    if (D_8009B43E < 0)
        return -1;
    if (arg0 != 0) {
        if ((func_8008B380(D_8009B437 != 0) & 0xE) != 0)
            return 0;
    } else {
        func_8008B390(D_8009B437 != 0);
    }
    switch ((s8)((u8)D_8009B43E - 1)) {
    case 0:
    case 1:
        if (func_80044608() >= 0)
            goto finish;
        return 0;
    case 10:
    case 11:
        resume_step = 1;
        switch (D_8009B44F) {
        case 0:
            {
                s32 directory_result = func_80044608();
                if (directory_result < 0)
                    return 0;
                if (directory_result != 0) {
                    D_8009B450 = 2;
                    goto finish;
                }
            }
            D_8009B43C = 0xA;
            D_8009B44F = D_8009B44F + 1;
        case 1:
            func_80043D48(D_800F2AF0);
            func_8008B370();
            if (D_8009B43E == 0xB) {
                func_8008B360(D_8009B437, D_8009B44C,
                           (u8 *)D_8009B430);
            } else {
                func_8008B350(D_8009B437, D_8009B44C,
                            (u8 *)D_8009B430);
            }
            D_8009B44F = D_8009B44F + 1;
            return 0;
        case 2:
            goto sub_two;
        }
        goto finish;
    case 2:
    case 3:
        resume_step = 1;
        switch (D_8009B44F) {
        case 0:
            {
                s32 directory_result = func_80044608();
                if (directory_result < 0)
                    return 0;
                if (directory_result != 0) {
                    D_8009B450 = 2;
                    goto finish;
                }
            }
            D_8009B436 = 0x14;
            D_8009B44F = D_8009B44F + 1;
        case 1:
            D_8009B43C = D_8009B43C - 1;
            if ((s8)D_8009B43C < 0) {
                D_8009B450 = 2;
                goto finish;
            }
            mode = 0x8001;
            if (D_8009B43E == 4)
                mode = 0x8002;
            tries = 0xA;
            do {
                fd = func_800738D0(D_800F2B00, mode);
                tries--;
                if (fd != -1)
                    goto opened;
            } while (tries >= 0);
            return 0;
opened:
            tries = 0xA;
            do {
                r = func_800738E0(fd, D_8009B44C, 0);
                if (r != -1)
                    goto seeked;
            } while (--tries >= 0);
            func_80073910(fd);
            return 0;
seeked:
            func_80043D48(D_800F2AE0);
            tries = 0xA;
            do {
                s32 transfer_result;

                if (D_8009B43E == 4) {
                    transfer_result = func_80073900(fd, (void *)D_8009B430,
                                            D_8009B434);
                } else {
                    transfer_result = func_800738F0(fd, (void *)D_8009B430,
                                           D_8009B434);
                }
                if (transfer_result == 0)
                    goto transferred;
            } while (--tries >= 0);
            func_80073910(fd);
            return 0;
transferred:
            D_8009B43C = 0x14;
            D_8009B44F = D_8009B44F + 1;
            func_80073910(fd);
            return 0;
        case 2:
            goto sub_two;
        }
        goto finish;
sub_two:
        if (D_8009B450 == 0)
            goto finish;
        D_8009B436 = D_8009B436 - 1;
        if ((s8)D_8009B436 < 0)
            goto finish;
        D_8009B44F = resume_step;
        return 0;
    case 7:
        if (D_8009B44F == 0)
            goto poll_write;
        if (D_8009B44F == 1)
            goto reopen;
        goto finish;
poll_write:
        {
            s32 directory_result = func_80044608();
            if (directory_result < 0)
                return 0;
            if (directory_result == 0)
                goto check_size;
        }
        D_8009B450 = 2;
        goto finish;
check_size:
        if (D_8009B438 + D_8009B434 < 0x10)
            goto write_dirent;
        D_8009B450 = 7;
        goto finish;
write_dirent:
        if (func_80044470(D_8009B437, D_800F2B00,
                              D_8009B444, 0) == 0)
            goto start_reopen;
        D_8009B450 = 6;
        goto finish;
opened_ok:
        func_80073910(fd);
        D_8009B450 = 0;
        goto finish;
start_reopen:
        D_8009B43C = 0xA;
        D_8009B44F = D_8009B44F + 1;
reopen:
         
        for (tries = 0xA;;) {
            fd = func_800738D0(D_800F2B00,
                      (D_8009B434 << 16) | 0x200);
            if (fd != -1)
                goto opened_ok;
            if (--tries < 0) {
                D_8009B43C = D_8009B43C - 1;
                if ((s8)D_8009B43C > 0)
                    return 0;
                D_8009B450 = 2;
                goto finish;
            }
        }
    }
finish:
    *out_result = D_8009B450;
    *out_state = D_8009B43E;
    D_8009B43E = -1;
    return 1;
}
