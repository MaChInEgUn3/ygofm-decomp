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

/* Seven words passed by value: the o32 ABI copies anything over 16 bytes
 * into the caller's outgoing area and passes its address. */
typedef struct {
    s32 w[7];
} Words7;

/* Script opcode handler: dispatched from a table by a byte from the stream. */
typedef void (*ObjFn)(u8 *);

#endif /* TYPES_H */