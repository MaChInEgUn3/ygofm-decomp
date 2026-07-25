#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types.h"

/*
 * Declarations for functions referenced across files -- callers, and
 * anywhere a function's address is taken. Declared centrally for the same
 * reason as the globals in variables.h: a signature mismatch between two
 * files changes codegen silently.
 *
 * A function listed here need not be decompiled; the declaration only has
 * to agree with how it is used, since the definition may still come from
 * assembly.
 */

void func_80019B2C(void);
void func_8004544C(void);

#endif /* FUNCTIONS_H */
