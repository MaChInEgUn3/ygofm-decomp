#ifndef COMMON_H
#define COMMON_H

/*
 * Project-wide header pulled in by every generated source file.
 *
 * Right now this only wires up splat's INCLUDE_ASM/INCLUDE_RODATA machinery,
 * which is what lets a .c file that is still 100% un-decompiled build into
 * byte-identical output: each INCLUDE_ASM line assembles the original
 * function's .s straight into the object.
 *
 * As functions get decompiled, shared typedefs/structs/prototypes belong
 * here (or in headers included from here).
 */

/* Use macro.inc (modern GNU as) rather than labels.inc (original PsyQ
 * assembler). We assemble with mipsel-none-elf-as, so we need the gas
 * flavor of the glabel/endlabel/nonmatching macros. */
#define INCLUDE_ASM_USE_MACRO_INC 1

#include "include_asm.h"

#endif /* COMMON_H */
