/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/mem_card_dialog_runtime.c (MemCardDialog_UpdateTradeSave), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
struct DIRENTRY {
	char name[20];
	long attr;
	long size;
	struct DIRENTRY *next;
	long head;
	char system[4];
};
long func_8008BC90( long chan );
long func_8008C638( long chan, char* file, unsigned long* adrs, long ofs, long bytes );
long func_8008C858( long chan, char* file, unsigned long* adrs, long ofs ,long bytes );
long func_8008CA78( long chan, char* name, struct DIRENTRY* dir, long* files, long ofs, long max );
typedef union {
    struct {
        u16 wins;
        u16 losses;
    } result;
    u16 counts[2];
} SaveDataDuelistRecord;
extern u8 D_8009B3C1;
extern u8 D_800EFE18[];
void func_8003E46C(s32 value, s32 bits);
extern u16 D_8009B3FA;
extern u8 D_8009B3EF;
extern u8 *D_8009B3D0;
extern u8 *D_8009B3E0;
extern u8 D_8009B3EC;
extern u8 D_800EFBC0[];
extern s32 D_801D5648[];
typedef struct {
    u16 player_deck[40 ];
    u8 card_quantities[722 ];
    u8 pad_322[
        0x334  -
        (40  * sizeof(u16) + 722 )
    ];
    s32 duelist_code;
    u8 pad_338[0x3DE  -
        (0x334  + sizeof(s32))];
     

    u8 field_3DE;
    u8 pad_3DF[
        0x400  -
        (0x3DE  + sizeof(u8))
    ];
     

    s32 field_400;
    u32 save_sequence;
    u32 vblank_counter;
    u8 player_name_sjis[(6  * sizeof(u16)) ];
    u8 campaign_flags[
        (0x7FF  + 1) >> 3 
    ];
    u16 duel_wins;
    u16 duel_losses;
    SaveDataDuelistRecord duelist_records[(5  * 8 ) ];
    u8 pad_5BC[
        0x5DC  -
        (0x51C + sizeof(SaveDataDuelistRecord) * (5  * 8 ) )
    ];
    u8 campaign_scene_index;
    u8 field_5DD;
    u8 output_type;
    u8 pad_5DF;
    u32 starchips;
} SaveDataState;
s32 func_8003D288(
    SaveDataState *left,
    SaveDataState *right
);
extern u8 D_801DC000[];
extern u8 D_8009B3F9;
extern u8 D_8009B3EB;
extern u16 D_8009B3C2;
extern u16 D_8009B3C4;
extern s32 D_8009B3F4;
void func_8003EED0(void);
void func_8003EED0(void)
{
    s32 files;
    u8 *record;

    if ((D_8009B3C1 & 0x80 ) == 0) {
        D_8009B3C1 |= 0x80 ;
        func_8003E46C(0xC0, 0);
        D_8009B3EB = 0;
    }
    switch (D_8009B3EB & 0xF) {
    case 0:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 ;
            D_801D5648[0] = (D_8009B3F9 >> 4) + 1;
            do {
            } while (func_8008BC90(D_8009B3F9) == 0);
            goto io_pending;
        }
        switch (D_8009B3F4) {
        case 1:
            func_8003E46C(0xC1, 0x18);
            break;
        case 0:
        case 3:
            D_8009B3EB = 1;
            D_8009B3F9 ^= 0x10;
            if (D_8009B3F9 != 0) {
                D_8009B3EB = 0;
            }
            break;
        case 2:
            func_8003E46C(0xDA, 0x18);
            break;
        case 4:
            func_8003E46C(0xC3, 0x18);
            break;
        }
        break;
    case 1:
        D_801D5648[0] = (D_8009B3F9 >> 4) + 1;
        if (func_8008CA78(D_8009B3F9, (char *)D_800EFE18,
                               (struct DIRENTRY *)D_800EFBC0, (long *)&files, 0,
                               15 ) != 0) {
            func_8003E46C(0xDA, 0x18);
            break;
        }
        if (files == 0) {
            func_8003E46C(0xC3, 0x18);
            break;
        }
        D_8009B3F9 ^= 0x10;
        if (D_8009B3F9 != 0) {
            D_8009B3EB = 1;
            break;
        }
        D_8009B3EB = 2;
         
    case 2:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 ;
            D_8009B3EC = 0;
            D_801D5648[0] = (D_8009B3F9 >> 4) + 1;
            func_8008C638(D_8009B3F9, (char *)D_800EFE18,
                            (unsigned long *)D_801DC000,
                            D_8009B3C4, 0x480);
            goto io_pending;
        }
        if ((D_8009B3EB & 0x40 ) == 0) {
            D_8009B3EB |= 0x40 ;
            if (D_8009B3F4 != 0) {
                func_8003E46C(0xDA, 0x18);
                break;
            }
        }
        record = D_8009B3D0;
        if (D_8009B3F9 != 0) {
            record = D_8009B3E0;
        }
        if (func_8003D288(
                (SaveDataState *)record,
                (SaveDataState *)D_801DC000) == 0) {
            if (D_8009B3EC != 0) {
                func_8003E46C(0xC3, 0x18);
                break;
            }
            D_8009B3EC++;
            D_8009B3EB &= ~0x40 ;
            func_8008C638(D_8009B3F9, (char *)D_800EFE18,
                            (unsigned long *)D_801DC000,
                            D_8009B3C4 + 0x680 , 0x480);
            goto io_pending;
        }
        D_8009B3F9 ^= 0x10;
        if (D_8009B3F9 != 0) {
            D_8009B3EB = 2;
            break;
        }
        D_8009B3EB = 3;
         
    case 3:
        if ((D_8009B3EB & 0x80 ) == 0) {
            D_8009B3EB |= 0x80 
                          | 0x40 ;
            func_8003E46C(0xC4, 0);
        }
        if ((D_8009B3EB & 0x40 ) == 0) {
            goto step;
        }
    func_80073900:
        D_8009B3EB &= ~0x40 ;
        if (D_8009B3F9 != 0) {
            func_8008C858(D_8009B3F9, (char *)D_800EFE18,
                             (unsigned long *)D_8009B3E0,
                             D_8009B3C4, 0x80);
        } else {
            func_8008C858(D_8009B3F9, (char *)D_800EFE18,
                             (unsigned long *)D_8009B3D0,
                             D_8009B3C4, 0x80);
        }
    io_pending:
        D_8009B3FA |= 0x1000 ;
        break;
    step:
        if (D_8009B3F4 != 0) {
            func_8003E46C(0xC5, 0x18);
            break;
        }
        D_8009B3EB |= 0x40 ;
        D_8009B3F9 ^= 0x10;
        if (D_8009B3F9 == 0) {
            D_8009B3D0 += 0x80;
            D_8009B3E0 += 0x80;
            D_8009B3C4 += 0x80;
            D_8009B3C2 -= 0x80;
            if (D_8009B3C2 == 0) {
                D_8009B3EF = 1;
                func_8003E46C(0xC6, 0x18);
                break;
            }
        }
        goto func_80073900;
    }
}
