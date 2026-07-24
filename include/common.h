#ifndef COMMON_H
#define COMMON_H

/*
 * Project-wide header pulled in by every source file.
 *
 * It wires up splat's INCLUDE_ASM/INCLUDE_RODATA machinery (so a file that
 * is still un-decompiled can build into byte-identical output) and provides
 * the shared type and global declarations.
 */

/* Use macro.inc (modern GNU as) rather than labels.inc (original PsyQ
 * assembler). We assemble with mipsel-none-elf-as, so we need the gas
 * flavor of the glabel/endlabel/nonmatching macros. */
#define INCLUDE_ASM_USE_MACRO_INC 1

#include "include_asm.h"
#include "types.h"
#include "variables.h"

#endif /* COMMON_H */
