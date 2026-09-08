/* IRMAO de parked/func_80030294.c, guardado por causa da regra 19.
 *
 * 325/329 e 316 diferencas, censo de magnitude QUATRO e so TRES opcodes
 * (`addu -2, lui -1, addiu -1`): QUATRO instrucoes faltando e ZERO
 * sobrando. O candidato principal e -1/267 mas carrega `sw +1`/`lw +1` de
 * lixo (o $s3, moldura 112 contra 104), isto e tres faltando e duas
 * sobrando. Sao a mesma funcao vista de dois lados e nenhum dos dois e
 * obviamente o melhor -- este e o que nao tem nada a mais.
 *
 * A unica diferenca para o principal e que aqui NAO existem os locais
 * `cb = c;` e `db = d;`: `c` e `d` sao lidos direto. Com eles o gcc iça as
 * QUATRO bases de pilha para o topo (um pseudo de vida longa a mais do que
 * cabe nos caller-saved); sem eles iça TRES (sp+0x10, +0x28, +0x38) e o
 * retail iça DUAS (+0x38 e +0x50).
 *
 * NAO instalar sem reler a oitava rodada de docs/PARKED.txt: este candidato
 * com `-fno-cse-follow-jumps` da 329/329, comprimento EXATO, e e um FALSO
 * ZERO -- censo de magnitude dez, cinco faltando contra cinco sobrando.
 */
#define D_8009B394_IN_DATA_VOLATILE
#define D_8009B396_IN_DATA_VOLATILE
#define D_8009B398_IN_DATA_VOLATILE
#define D_8009B39A_IN_DATA_VOLATILE
#define D_8009B3A4_IN_DATA_VOLATILE
#define D_8009B3A6_IN_DATA_VOLATILE
#include "common.h"

typedef struct { s32 w[5]; } Blk14;
typedef struct { s32 w[4]; } Blk10;
typedef struct { u8 b[8]; } Blk8;

s32 func_80030294(void) {
    s32 a[5];
    s32 b[4];
    s32 c[5];
    u8 d[8];
    s32 ret;
    s32 i;
    s32 n;
    s32 e;
    s32 step;
    s32 car;
    s32 *q;
    s32 k;
    s32 ch;
    u8 *z;
    u16 *p;
    s32 val;
    s32 mask;
    u8 t2;
    u8 f;
    u8 *r;

    ret = 0;
    *(Blk14 *)a = *(Blk14 *)D_80010250;
    *(Blk10 *)b = *(Blk10 *)D_80010264;
    *(Blk14 *)c = *(Blk14 *)D_80010274;
    *(Blk8 *)d = *(Blk8 *)D_8009AF4C;
    t2 = (&D_8009B2C0)[(s8)D_8009B2DC];
    if ((D_8009B2EA & 0x80) == 0) {
        D_8009B2EA = D_8009B2EA | 0x80;
        if ((D_8009B2EA & 0x40) != 0) {
            i = (s8)t2 - 1;
            p = &(&D_8009B2C8)[(s8)D_8009B2DC];
            val = *p;
            q = &a[i];
            *p = 0;
            do {
                k = *q;
                n = val / k;
                q = q - 1;
                e = i * 4;
                i = i - 1;
                *p = *p | (n << e);
                val = val - k * n;
            } while (i >= 0);
        }
        goto fill;
    }
    if ((D_8009B2EA & 1) != 0) {
        goto fill;
    }
    if (((D_8009B3A4 | D_8009B3A6) & 0x800) != 0) {
        goto fill;
    }
    if (((D_8009B398 | D_8009B39A) & 0xC0) != 0) {
        ret = 1;
        goto out;
    }
    if (((D_8009B398 | D_8009B39A) & 0x20) != 0) {
        ret = -1;
        goto out;
    }
    if (((D_8009B394 | D_8009B396) & 0x5000) != 0) {
        p = &(&D_8009B2C8)[(s8)D_8009B2DC];
        e = (s8)D_8009B2E9;
        val = *p;
        step = c[e];
        if (((D_8009B394 | D_8009B396) & 0x4000) != 0) {
            step = -step;
        }
        if ((D_8009B2EA & 0x40) != 0) {
            mask = *(u16 *)(d + e * 2);
            i = e;
            n = (s8)t2;
            if (i < n) {
                q = &b[e];
                do {
                    car = val & mask;
                    val = val & ~mask;
                    car = car + step;
                    if (step >= 0) {
                        if (car < *q) {
                            goto joined;
                        }
                    } else {
                        if (car >= 0) {
                            goto joined;
                        }
                        val = val | ((*q - 1) & mask);
                    }
                    car = 0;
                    mask = mask * 0x10;
                    step = step * 0x10;
                    i = i + 1;
                    q = q + 1;
                } while (i < n);
            }
        joined:
            val = val | car;
        } else {
            val = (val + step) & (c[(s8)t2] - 1);
        }
        (&D_8009B2C8)[(s8)D_8009B2DC] = val;
    }
    if (((D_8009B394 | D_8009B396) & 0xA000) == 0) {
        goto out;
    }
    if (((D_8009B394 | D_8009B396) & 0x2000) != 0) {
        D_8009B2E9 = D_8009B2E9 - 1;
        if ((s8)D_8009B2E9 < 0) {
            D_8009B2DC = D_8009B2DC + 1;
            if ((s8)D_8009B2DC >= (s8)D_8009B2E0) {
                D_8009B2DC = D_8009B2E0 - 1;
                D_8009B2E9 = 0;
                goto fill;
            }
            f = (&D_8009B2C0)[(s8)D_8009B2DC] - 1;
            goto setpos;
        }
    } else {
        D_8009B2E9 = D_8009B2E9 + 1;
        if ((s8)D_8009B2E9 >= (s8)t2) {
            D_8009B2E9 = 0;
            D_8009B2DC = D_8009B2DC - 1;
            if ((s8)D_8009B2DC < 0) {
                f = D_8009B2C0 - 1;
                D_8009B2DC = 0;
            setpos:
                D_8009B2E9 = f;
            }
        }
    }
fill:
    r = D_800EAED8;
    i = 0x27;
    z = r + i;
    do {
        *z = 0x20;
        i = i - 1;
        z = z - 1;
    } while (i >= 0);
    r = &D_800EAED8[(s8)(&D_8009B2B4)[(s8)D_8009B2DC] - (s8)D_8009B2E9];
    r[0] = 0x2A;
    r[1] = 0;
out:
    i = (s8)D_8009B2B8;
    if (i != 0) {
        do {
            func_8007EF84(D_8009AF54);
            i = i - 1;
        } while (i != 0);
    }
    func_8007EF84(D_8009B2EC, D_8009B2C8, D_8009B2CA, D_8009B2CC);
    func_8007EF84(D_8009AF58, D_800EAED8);
    return ret;
}
