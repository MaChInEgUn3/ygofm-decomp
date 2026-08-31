/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

struct Slot4 {
    u8 type;
    u8 id;
    u16 pos;
};

struct DuelRec5106C {
    u8 pad000[0x7C4];
    u8 rows[0x76 * 9];
    u8 padBEA[0xBF5 - (0x7C4 + 0x76 * 9)];
    u8 selected;
    u8 padBF6[2];
    struct Slot4 slots[0x40];
    u8 padCF8[0xD08 - 0xCF8];
    s32 values[4];
    u8 padD18[0xDC0 - 0xD18];
    u32 flags;
    u8 padDC4[0xDD0 - 0xDC4];
    s16 x;
    u8 padDD2[2];
    s16 y;
    u8 padDD6[0xDFE - 0xDD6];
    u8 slot;
    u8 padDFF[0xE06 - 0xDFF];
    u16 cycle;
    u16 progress;
    u8 padE0A[3];
    u8 scale;
    u8 mode;
    u8 padE0F[0xE16 - 0xE0F];
    u8 state;
    u8 padE17[0xE1E - 0xE17];
    u8 enabled;
    u8 live;
};

extern struct DuelRec5106C D_800F2C40[];
extern s32 func_80058E1C(void);
extern void func_8007EF84(void *);
extern void func_8005A6A8(s16, s16, u8 *, u8 *);
extern void func_80045334(s32);
extern void func_80048658(s32, s32, s32);
extern char D_80011508[];

/* Advances and draws one duel animation row and its active object slots. */
void func_8005106C(s32 arg0) {
    char text[0x50];
    u8 out[2];
    struct DuelRec5106C *rec;
    u8 *slotp;
    u8 *rowp;
    s32 selected;
    s32 width;
    s32 active;
    s32 object_base;
    s32 span;
    s32 object;
    s32 pos;

    rec = &D_800F2C40[arg0];
    if (rec->live == 0) {
        return;
    }
    if ((((u8 *)&rec->flags)[3] >= 2) && ((rec->flags & 0xFFFFFF) == 0)) {
        return;
    }
    if (rec->enabled == 0) {
        return;
    }

    selected = rec->selected;
    rowp = (u8 *)rec;
    rowp += selected * 0x76;
    width = *(u16 *)(rowp + 0x7C4);
    width *= 0x10;
    span = rec->scale * func_80058E1C();
    slotp = (u8 *)rec + 0xBF8;
    object_base = (arg0 << 8) + 0x4000;
    if (width != 0) {
        arg0 = rec->cycle % width;
    } else {
        arg0 = 0;
    }

    active = 0;
    if (rec->values[rec->slot] >= 0) {
        if ((rec->mode != 8) &&
            ((rec->mode != 2) || (rec->slot + 3 == selected))) {
            active = 1;
        }
        if (active != 0) {
            s32 step;
            register s32 delta asm("v1");

            step = func_80058E1C();
            arg0 = rec->progress;
            delta = rec->scale * step;
            delta = arg0 + delta;
            rec->progress = delta;
            selected = *(volatile u8 *)&rec->slot + 3;
            func_8008F200(text, D_80011508, rec->values[rec->slot] / 1000,
                    rec->values[rec->slot] % 1000,
                    *(volatile u16 *)&rec->progress >> 4);
            func_8007EF84(text);
        }
    }

    if ((active == 0) && (rec->state == 0x23)) {
        return;
    }
    func_8005A6A8(rec->x, rec->y, &out[0], &out[1]);
    for (active = 0; active < 0x40; active++, slotp += 4) {
        register u16 narrow asm("v0");
        register s32 mask asm("v1");

        __asm__ __volatile__("" : "+r"(slotp));
        narrow = *(u16 *)(slotp + 2);
        mask = narrow & 0x8000;
        __asm__("" : "+r"(mask));
        narrow = mask & 0xFFFF;
        object = narrow | slotp[1];
        if (narrow == 0) {
            object = (object_base & 0xFFFF) | slotp[1];
        }
        if (slotp[0] == 0) {
            return;
        }
        if (slotp[0] == selected) {
            if ((mask != 0) && (arg0 == 0)) {
                func_80045334(object);
            }
            pos = *(u16 *)(slotp + 2) & 0x7FFF;
            if ((pos >= arg0) && (pos < arg0 + span)) {
                func_80048658(object, 0xFF, 0);
            }
        }
    }
}
