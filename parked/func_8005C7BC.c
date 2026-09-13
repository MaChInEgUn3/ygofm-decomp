/* 461/461 com CENSO VAZIO e 24 diferencas, 2026-09-13. Escrita do zero.
 * FLAGS: padrao (-quiet -O2 -G8). Listagem gp=0, at=0.
 *
 * Sequenciador de animacao por chaves: percorre os registros de arg0[0],
 * anda uma tabela de chaves u32 por arg0+0x1C e chama o callback da tabela
 * em arg0+0x18 com arg0 (func_8005CEF0 e um desses callbacks). O arquivo
 * original era S3000000.C: a busca de chave aparece expandida QUATRO vezes
 * com o `_assert` do PsyQ na mesma linha 0x57, entao e uma `static inline`
 * (ou macro) e esta escrita assim. As strings do assert sao D_800117EC e
 * D_80011814, referenciadas por extern para dar o mesmo par %hi/%lo.
 *
 * LEVERS, cada um medido sobre o anterior:
 *  1. assinatura `u8 *func_8005C7BC(u8 **arg0)` (a PROVISIONAL de
 *     functions.h) com `((u8 *)arg0)` inline em todo uso: v2 ja e 461/461,
 *     13 blocos estruturais.
 *  2. o contador em `u16 vt`: o alvo testa o `andi 0xFFFF` duas vezes.
 *  3. rec[0x16] (ou rec[0x14]) lido UMA vez em `t` antes da segunda busca:
 *     sem isso sobram dois `andi`. So o 2 e +1, so o 3 e -2; juntos acertam.
 *  4. no braco dir == 1: `rec[0x12] = t; t -= rec10; rec[0x10] = t;` -- o
 *     destino da subtracao e `t`.
 *  5. o final: a subtracao gravada DIRETO em rec+0x10 (num local `x` ela vira
 *     `lb` onde o alvo tem `lbu` + sll/sra) e um store compartilhado de
 *     0x7000/0x6000 por `y` e um rotulo, com o ramo dir == -1 relendo
 *     rec+0x10. v2 -> F: 352 -> 42 diferencas e censo vazio.
 *  6. `count` declarado antes de `cur`: acerta os slots de pilha da
 *     contagem e da tabela (42 -> 38).
 *  7. nomes proprios `t16` e `t14` para as duas leituras antes da segunda
 *     busca, em vez do `t` compartilhado (38 -> 24). Um nome proprio no
 *     bloco do `t -= rec10` e neutro.
 *
 * MEDIDO E NEUTRO: ordem dos parametros da inline.
 *
 * RESIDUO (24): 8 sao so nome -- `jal func_8008e870` contra `jal printf` e
 * `jal func_8008fbd0` contra `jal exit`, mesmo endereco (sdk_names.txt); o
 * build completo decide. O resto e registrador: arg0 e a constante 0xFFFF
 * com $t1/$t0 trocados e o bloco do `t -= rec10`.
 */
#include "common.h"

extern char D_800117EC[];
extern char D_80011814[];

static inline s32 func_8005C7BC_seek(u8 *rec, u32 *keys, s32 idx)
{
    s32 step;
    u32 k;
    s32 lo;
    s32 hi;

    step = 1;
    if ((s8)rec[0xD] < 0) {
        step = -1;
    }
    while ((k = keys[(u16)idx]) & 0x80000000) {
        if ((k & 0xC0000000) == 0x80000000) {
            lo = (k & 0x7F0000) >> 16;
            if (lo == 0 || rec[0xC] == lo) {
                hi = (k & 0x3F800000) >> 23;
                if (lo != 0 || hi != 0) {
                    rec[0xC] = hi;
                }
                idx = k;
                continue;
            }
        } else if ((k & 0xC0000000) == 0xC0000000) {
            lo = (k & 0x7F0000) >> 16;
            hi = (k & 0x3F800000) >> 23;
            if (hi == 1) {
                if (lo == 0 || rec[0xC] == lo) {
                    return 0xFFFF;
                }
            }
        } else {
            printf(D_800117EC, D_80011814, 0x57);
            exit(1);
        }
        idx += step;
    }
    return idx;
}

u8 *func_8005C7BC(u8 **arg0)
{
    s32 count;
    u8 *cur;
    u8 *rec;
    u8 *table;
    u32 *keys;
    u8 *base;
    s32 *out;
    s32 (*fn)(u8 **);
    s32 i;
    s32 dir;
    s32 v;
    s32 t;
    s32 tb;
    s32 t16;
    s32 t14;
    s32 x;
    s32 y;
    u16 vt;

    cur = *(u8 **)((u8 *)arg0) + 4;
    table = *(u8 **)(((u8 *)arg0) + 0x18);
    keys = *(u32 **)(((u8 *)arg0) + 0x1C);
    count = *(u16 *)(*(u8 **)((u8 *)arg0) + 2);
    base = *(u8 **)(((u8 *)arg0) + 0x20);
    for (i = 0; i < count; i++, cur += *(u16 *)(cur + 4) * 4) {
        vt = *(u16 *)(cur + 0xA);
        rec = cur;
        if (vt == 0) {
            continue;
        }
        if (vt != 0xFFFF) {
            *(u16 *)(cur + 0xA) = vt - 1;
        }
        dir = 1;
        if ((s8)cur[0xD] < 0) {
            dir = -1;
        }
        if (*(s16 *)(cur + 0x10) == 0x7000) {
            dir = 1;
            *(s16 *)(cur + 0x10) = 0;
        } else if (*(s16 *)(cur + 0x10) == 0x6000) {
            dir = -1;
            *(s16 *)(cur + 0x10) = 0;
        }
    again:
        if (*(s16 *)(rec + 0x10) == 0 || *(u16 *)(rec + 0x12) == 0) {
            rec[0x1B] = 0;
            if (dir == 1) {
                if (keys[*(u16 *)(rec + 0x16)] & 0x80000000) {
                    v = func_8005C7BC_seek(rec, keys, *(u16 *)(rec + 0x16) + dir);
                    *(u16 *)(rec + 0x16) = v;
                    if ((v & 0xFFFF) == 0xFFFF) {
                        goto dead;
                    }
                }
                t16 = *(u16 *)(rec + 0x16);
                *(u16 *)(rec + 0x14) = t16;
                v = func_8005C7BC_seek(rec, keys, t16 + dir);
                *(u16 *)(rec + 0x16) = v;
            } else {
                if (keys[*(u16 *)(rec + 0x14)] & 0x80000000) {
                    v = func_8005C7BC_seek(rec, keys, *(u16 *)(rec + 0x14) + dir);
                    *(u16 *)(rec + 0x14) = v;
                    if ((v & 0xFFFF) == 0xFFFF) {
                        goto dead;
                    }
                }
                t14 = *(u16 *)(rec + 0x14);
                *(u16 *)(rec + 0x16) = t14;
                v = func_8005C7BC_seek(rec, keys, t14 + dir);
                *(u16 *)(rec + 0x14) = v;
            }
            if ((v & 0xFFFF) == 0xFFFF) {
            dead:
                *(u16 *)(rec + 0xA) = 0;
                continue;
            }
            if (dir == 1) {
                tb = ((u8 *)&keys[*(u16 *)(rec + 0x16)])[2] << 4;
                *(u16 *)(rec + 0x12) = tb;
                tb -= *(u16 *)(rec + 0x10);
                *(u16 *)(rec + 0x10) = tb;
            } else {
                *(u16 *)(rec + 0x12) = ((u8 *)&keys[*(u16 *)(rec + 0x16)])[2] << 4;
            }
        }
        fn = *(s32 (**)(u8 **))(table + ((((u8 *)&keys[*(u16 *)(rec + 0x16)])[3] & 0x7F) << 2) + 4);
        out = (s32 *)(((u8 *)arg0) + (*(s32 *)(((u8 *)arg0) + 0x14) * 4 + 0x14));
        out[0] = (s32)cur;
        out[1] = (s32)(base + *(u16 *)&keys[*(u16 *)(rec + 0x14)] * 4);
        out[2] = (s32)(base + *(u16 *)&keys[*(u16 *)(rec + 0x16)] * 4);
        if (*(u16 *)(rec + 8) != 0xFFFF) {
            out[3] = (s32)(base + *(u16 *)&keys[*(u16 *)(rec + 8)] * 4);
        } else {
            out[3] = 0;
        }
        if (*(u16 *)(rec + 0x14) != *(u16 *)(rec + 0x16)) {
            if (fn(arg0) == 1) {
                *(s16 *)(rec + 0x10) = 0;
                goto again;
            }
            if (((u8 *)&keys[*(u16 *)(rec + 0x16)])[2] == 0) {
                goto again;
            }
            *(s16 *)(rec + 0x10) = *(u16 *)(rec + 0x10) - (s8)rec[0xD];
            if (dir == 1) {
                if (*(s16 *)(rec + 0x10) < 0) {
                    y = 0x7000;
                    goto st;
                }
            }
            if (dir == -1) {
                if (*(s16 *)(rec + 0x10) >= *(u16 *)(rec + 0x12)) {
                    y = 0x6000;
                st:
                    *(s16 *)(rec + 0x10) = y;
                }
            }
        }
    }
    return *(u8 **)((u8 *)arg0) + **(u16 **)((u8 *)arg0) * 4;
}
