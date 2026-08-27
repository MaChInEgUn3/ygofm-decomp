#ifndef TYPES_H
#define TYPES_H

/* Fixed-width names for the R3000's types, matching the conventions the
 * PsyQ headers and the wider PS1 decomp community use. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/* Built on the stack and passed by address to func_80045BE8. Only the four
 * fields the callers touch are named; the size comes from the retail frame. */
typedef struct {
    u8 kind;
    u8 unk1;
    u16 unk2;
    u8 unk4[4];
    s32 unk8;
    u8 unkC[0x24];
} Msg30;

/* The dispatch in func_800603DC selects between handlers of this shape. */
typedef u8 *(*ByteFn)(u8 **);

typedef void (*VoidFn)(void);

/* PsyQ's SVECTOR: three signed halfwords and a pad, eight bytes. Copied whole
 * by func_8005A1F4, which is how its size is known. */
typedef struct {
    s16 vx;
    s16 vy;
    s16 vz;
    s16 pad;
} SVector;

/* PsyQ's MATRIX: a 3x3 fixed-point rotation, two bytes of pad, and a
 * three-word translation -- 32 bytes at alignment 4, which is what makes
 * `*dst = *src;` expand as eight aligned lw/sw rather than an lwl/lwr pair
 * per word. func_800580D4 copies one whole and the expansion is the tell. */
typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 t[3];
} Matrix;

/* Seven words passed by value: the o32 ABI copies anything over 16 bytes
 * into the caller's outgoing area and passes its address. */
typedef struct {
    s32 w[7];
} Words7;

/* Script opcode handler: dispatched from a table by a byte from the stream. */
typedef void (*ObjFn)(u8 *);
typedef void (*TickFn)(u8 *, s32);

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
} Cmd2C;

/* Four bytes passed and returned in one register. The byte-wise reassembly
   gcc emits around a call is the tell that a struct went by value. */
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} Word4;

#endif /* TYPES_H */
