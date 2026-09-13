/* 448/448 com CENSO VAZIO e 10 diferencas, 2026-09-13. Escrita do zero.
 * FLAGS: cc "-quiet -O2 -G8 -fno-strength-reduce", assembler padrao.
 *
 * Desenhador de sprite sobre a memoria de rascunho: 0x1F800320 (pacote),
 * 0x1F800344 (so no caminho do func_80041F90), 0x1F800378 (estado) e
 * 0x1F8003A4 (flags), mais um laco sobre registros de 6 bytes. Irma direta
 * da func_80040588, que usa o mesmo trio de rascunho.
 *
 * LEVERS INSTALADOS, cada um medido sobre o anterior:
 *  1. D_8009B146_IN_DATA (s16 em .data) e nao _SIZED: o alvo le com
 *     `lui %hi` + `lh %lo` no mesmo registrador. A arm u16[4] da `lhu`.
 *     Com o arm escalar a indexacao `[0]` sai junto, senao nao compila.
 *  2. `(s8)q[0xE] < 0` e nao `& 0x80`: o alvo testa o sinal com sll 24/bgez.
 *  3. -fno-strength-reduce: sem ele o gcc cria uma TERCEIRA variavel de
 *     inducao para `r[-1]` (fr+5 alem de fr+4 e fr+6), que toma o registrador
 *     do `g`; o `g` vai para a pilha e o frame cresce de 72 para 80. Com a
 *     flag: comprimento exato, frame 72, as duas givs do alvo ($s4 = fp+4,
 *     $s2 = fp+6). `pb[1]` no lugar de `r[-1]` tambem tira o `g` da pilha mas
 *     fica +2. E o sintoma que o WORKFLOW ja registra para essa flag.
 *  4. `e[0x66]` lido dentro de cada braco do bit 0x1000000 e somado depois.
 *  5. a leitura de e+0x46 nomeada antes dos dois zeros em q+0x1A/q+0x18,
 *     num nome proprio (`w46`); com o nome compartilhado `v1` custa 2.
 *  6. `x14 = *(s32 *)(q + 0x14)` antes dos stores em g, e os dois argumentos
 *     do func_80041F90 em locais antes de `D_8009B424 = 0`.
 *  7. `t2 = *(u16 *)(r + 2)` como u32 (s32 da `sra`): elimina um `lhu`. O
 *     comprimento exato de antes era esse lhu cancelando um nop.
 *  8. `kc` para testar o valor calculado de k+0xC em vez de reler a memoria.
 *  9. `c16 = e[0xE]` logo depois do store de q[0x15].
 * 10. `s8v = t0 >> 8` logo depois de t0.
 * 11. o mesmo `t0` recebe `arg2 | 0x10000/0x20000/0x30000` dentro do laco
 *     (o alvo reusa $t0) e SEM `do { } while (0)`: com um `m` separado o
 *     do/while ajudava, com o t0 compartilhado ele atrapalha (171 -> 29).
 * 12. no braco h+0x1C == 0: `t0 = ta & 0xFF;` e `t0 += ...` separados, e
 *     `ta &= 0x300;` como statement (29 -> 23, com o 5: 21).
 *
 * 13. `do { n--; pb += 6; } while (0);` no fim do laco (21 -> 10). Veio do
 *     permuter (output-345-1), que escreveu o mesmo par em `if (h) {..}
 *     else {..}` com bracos identicos; o do/while tem o mesmo efeito e e o
 *     que alguem escreveria. Resolve toda a troca $s5/$s6 entre arg2 e n.
 *     A outra saida boa (355-1) fazia `*(u16 *)(h + 0x10) = (n = e[0x5E])`:
 *     sozinha 21 -> 12, mas junto com o 13 volta a 12, entao nao entra;
 *     o `h - -0xE` dela vale zero.
 *
 * MEDIDOS E NEUTROS: `n` declarado primeiro (21, igual), `ta = ta + m` na
 * soma com e[0x66] (igual), operandos de q[0xF] trocados ou nomeados
 * (pior, traz `sra`), `c16` com o `do { } while (0)` ainda presente.
 *
 * RESIDUO (10, tudo registrador): o destino da soma com e[0x66] (5 linhas)
 * e a posicao do `ta &= 0x300` (5).
 */
#define D_8009B146_IN_DATA
#define D_8009B424_IS_VOLATILE
#include "common.h"

void func_8004158C(u8 *e, s32 arg1, s32 arg2) {
    u8 *k;
    u8 *h;
    u8 *q;
    u8 *fr;
    u8 *r;
    u8 *pb;
    s32 sx;
    s32 sy;
    s32 n;
    s32 a2;
    s32 a3;
    s32 t0;
    s32 ta;
    s32 v1;
    s32 m;
    s32 w46;
    s32 s8v;
    s32 c16;
    s32 kc;
    u32 t2;
    s32 x14;
    s32 ax;
    s32 ay;
    u8 *g;

    k = (u8 *)0x1F8003A4;
    sx = *(s16 *)(e + 0x30);
    sy = *(s16 *)(e + 0x32);
    if ((*(u16 *)(e + 8) & 8) == 0) {
        sx -= D_8009B146;
        sy -= D_8009B148;
    }
    h = (u8 *)0x1F800378;
    *(u16 *)(h + 0x14) = *(u16 *)(e + 0x48);
    *(u16 *)(h + 0x16) = *(u16 *)(e + 0x4A);
    q = (u8 *)0x1F800320;
    *(u16 *)(h + 0x1A) = *(u16 *)(e + 8) & 4;
again:
    *(s32 *)(h + 4) = *(s32 *)(e + 4);
    *(u16 *)(h + 0x10) = e[0x5E];
    *(u16 *)(h + 0x12) = e[0x5F];
    n = (*(u8 **)(e + 0x4C))[0];
    if (n == 0) {
        goto end;
    }
    *(s32 *)(k + 0x10) = (*(u8 **)(e + 0x4C))[1];
    if (*(s32 *)(h + 4) & 0x1000000) {
        *(s32 *)(h + 0x1C) = 1;
        m = (*(u8 **)(e + 0x4C))[2];
        ta = e[0x66];
        m = m * 2;
    } else {
        *(s32 *)(h + 0x1C) = 0;
        ta = e[0x66];
        m = (*(u8 **)(e + 0x4C))[2];
    }
    m = ta + m;
    *(u16 *)(h + 0x18) = m;
    *(u16 *)(q + 0xC) = m;
    *(u16 *)(h + 0xC) = *(u16 *)(e + 0x40);
    *(u16 *)(h + 0xE) = *(u16 *)(e + 0x42);
    if (*(u16 *)(e + 8) & 0x20) {
        *(u16 *)(h + 0xC) = *(u16 *)(h + 0xC) + (((*(u8 **)(e + 0x4C))[3] & 0xF) << 4);
        *(u16 *)(h + 0xE) = *(u16 *)(h + 0xE) + ((*(u8 **)(e + 0x4C))[3] >> 4);
    }
    fr = *(u8 **)(e + 0x4C);
    *(s32 *)(q + 0x20) = e[0x22] * 0x1680;
    *(u16 *)(q + 0x1C) = *(u16 *)(e + 0x44);
    w46 = *(u16 *)(e + 0x46);
    *(u16 *)(q + 0x1A) = 0;
    *(u16 *)(q + 0x18) = 0;
    *(u16 *)(q + 0x1E) = w46;
    q[0x14] = e[0xC];
    q[0x15] = e[0xD];
    c16 = e[0xE];
    pb = fr + 4;
    *(u16 *)(q + 0x10) = *(u16 *)(h + 0xC);
    *(u16 *)(q + 0x12) = *(u16 *)(h + 0xE);
    *(s32 *)(k + 8) = 0;
    *(s32 *)(k + 4) = 0;
    kc = *(s32 *)(h + 4) & 0x8000000;
    *(s32 *)(k + 0xC) = kc;
    q[0x16] = c16;
    if (kc != 0) {
        *(s32 *)(h + 4) = *(s32 *)(h + 4) & 0xF7FFFFFF;
    }
    v1 = *(s32 *)(h + 4);
    if (v1 & 0x800000) {
        *(s32 *)(h + 4) = v1 & 0xF7FFFFFF;
        *(s32 *)(k + 8) = 0x2000;
        *(s32 *)(k + 4) = 0x2000;
    }
    g = (u8 *)0;
    *(s32 *)(h + 0x28) = 0;
    if (*(u16 *)(h + 0x1A) != 0) {
        g = (u8 *)0x1F800344;
        x14 = *(s32 *)(q + 0x14);
        g[3] = 9;
        *(s32 *)(g + 4) = x14;
        g[7] = 0x2C;
        ax = sx + *(s16 *)(e + 0x18);
        ay = sy + *(s16 *)(e + 0x1A);
        D_8009B424 = 0;
        if (func_80041F90(e, ax, ay, h + 0x20) <= 0) {
            goto end;
        }
        if (D_8009B424 != 0) {
            goto again;
        }
        *(s32 *)(h + 0x28) = 0xF0000;
    }
    arg2 &= 0xFFFF;
    r = fr + 6;
    do {
        *(s32 *)(q + 0) = *(s32 *)(h + 4);
        *(u16 *)(h + 8) = *(u16 *)(r + 0);
        t2 = *(u16 *)(r + 2);
        *(u16 *)(h + 0xA) = t2;
        *(u16 *)(q + 8) = ((t2 >> 2) & 0x78) + 8;
        *(u16 *)(q + 0xA) = ((*(u16 *)(h + 0xA) >> 6) & 0x78) + 8;
        if (*(s32 *)(k + 0x10) & 0x10) {
            a2 = pb[0] | ((*(u16 *)(r + 0) & 0xC000) >> 6);
            if (a2 & 0x200) {
                a2 |= -0x200;
            }
            a3 = r[-1] | ((*(u16 *)(r + 2) & 0xC000) >> 6);
            if (a3 & 0x200) {
                a3 |= -0x200;
            }
        } else {
            a2 = (s8)pb[0];
            a3 = (s8)r[-1];
        }
        v1 = *(s32 *)(k + 4);
        if (v1 != 0) {
            a2 = -(a2 + *(u16 *)(q + 8));
        }
        if (*(s32 *)(k + 0x10) & 0xE0) {
            *(s32 *)(k + 8) = (*(u16 *)(h + 8) ^ v1) & 0x2000;
            if (*(s32 *)(h + 0x1C) != 0) {
                *(u16 *)(q + 0xC) = *(u16 *)(h + 0x18) + ((*(u16 *)(r + 0) >> 9) & 0xE);
                *(u16 *)(q + 0x10) = *(u16 *)(h + 0xC);
                *(u16 *)(q + 0x12) = *(u16 *)(h + 0xE) + (*(u16 *)(h + 0xA) & 0x1F);
            } else {
                ta = *(u16 *)(h + 0xC);
                t0 = ta & 0xFF;
                t0 += (*(u16 *)(h + 0xA) & 0xF) << 4;
                *(u16 *)(q + 0xC) = *(u16 *)(h + 0x18) + ((*(u16 *)(r + 0) >> 10) & 7);
                ta &= 0x300;
                *(u16 *)(q + 0x10) = ta | (t0 & 0xFF);
                *(u16 *)(q + 0x12) = *(u16 *)(h + 0xE) + (t0 >> 8);
            }
        }
        *(u16 *)(q + 4) = sx + a2;
        *(u16 *)(q + 6) = sy + a3;
        t0 = ((*(u16 *)(h + 8) & 0x1F) << 3) + *(u16 *)(h + 0x10);
        s8v = t0 >> 8;
        q[0xE] = t0;
        t0 = arg2 | 0x10000;
        q[0xF] = ((*(u16 *)(h + 8) & 0x3E0) >> 2) + h[0x12];
        *(u16 *)(q + 0xC) = *(u16 *)(q + 0xC) + s8v;
        if (*(s32 *)(k + 8) != 0) {
            t0 = arg2 | 0x20000;
            *(s32 *)(q + 0) = *(s32 *)(q + 0) | 0x800000;
            if (q[0xF] + *(u16 *)(q + 0xA) >= 0x100) {
                *(u16 *)(q + 0xA) = *(u16 *)(q + 0xA) - 1;
            }
            if (*(s32 *)(h + 0x1C) != 0) {
                if (q[0xE] + *(u16 *)(q + 8) >= 0x100 && (s8)q[0xE] < 0 &&
                    *(u16 *)(q + 0xC) != 0x1F) {
                    *(u16 *)(q + 0xC) = *(u16 *)(q + 0xC) + 1;
                    q[0xE] = q[0xE] + 0x80;
                    *(s32 *)(k + 0x10) = *(s32 *)(k + 0x10) | 0x80;
                    goto done;
                }
                if (q[0xE] != 0) {
                    goto done;
                }
                if (*(u16 *)(q + 0xC) != 0x10) {
                    *(u16 *)(q + 0xC) = *(u16 *)(q + 0xC) - 1;
                    q[0xE] = 0x80;
                    *(s32 *)(k + 0x10) = *(s32 *)(k + 0x10) | 0x80;
                    goto done;
                }
            }
            if (q[0xE] == 0) {
                q[0xE] = q[0xE] + 1;
                *(u16 *)(q + 8) = *(u16 *)(q + 8) - 1;
            }
        }
    done:
        if (*(u16 *)(h + 0x1A) == 0) {
            if (*(s32 *)(k + 0xC) != 0) {
                if (*(s16 *)(q + 4) >= 0x140 || *(s16 *)(q + 4) + *(u16 *)(q + 8) <= 0 ||
                    *(s16 *)(q + 6) >= 0xF0 || *(s16 *)(q + 6) + *(u16 *)(q + 0xA) <= 0) {
                    goto next;
                }
            } else {
                t0 = arg2 | 0x30000;
                *(u16 *)(q + 0x18) = *(u16 *)(h + 0x14) - a2;
                *(u16 *)(q + 0x1A) = *(u16 *)(h + 0x16) - a3;
                *(u16 *)(q + 4) = *(u16 *)(q + 4) + *(u16 *)(q + 0x18);
                *(u16 *)(q + 6) = *(u16 *)(q + 6) + *(u16 *)(q + 0x1A);
            }
        }
        func_80042188(q, g, arg1, t0 | *(s32 *)(h + 0x28), h + 0x20);
    next:
        r += 6;
        do {
            n--;
            pb += 6;
        } while (0);
    } while (n != 0);
end:
    ;
}
