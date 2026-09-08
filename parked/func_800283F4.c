/* 334/334 -- COMPRIMENTO EXATO -- e 103 diferencas, censo de magnitude 8
 * (2026-09-08, primeiro dia). Veio de -8/272. Flags PADRAO (passo 0:
 * gp=30, at=4, sem `break`, sem jump table).
 *
 * FORMA: maquina de estados de uma animacao de entrada/saida. Um bloco de
 * SETUP sob `if (func_800282E8() == 0)` que cria dois objetos e varre
 * D_800EB0F8 em busca de um registro sem o bit 0x8000, contra uma cadeia de
 * quatro estados guiada pelos bits de D_8009B248.
 *
 * PASSO 0: os quatro `lui $at` sao stores nus em D_8009B0C0 (`sb`),
 * D_8009B338 (`sh`) e D_8009B140 (`sb`, duas vezes contando os dois
 * blocos); os trinta `%gp_rel` sao D_8009B248, D_8009B24C, D_8009B240,
 * D_8009B250, D_8009B254, D_8009B24B e D_8009B246. So D_8009B0C0 esta na
 * forma nua no candidato (`_IN_DATA`); D_8009B338 e D_8009B140 ainda nao.
 *
 * AS QUATRO LEITURAS QUE LEVARAM -8/272 A 0/103:
 *  1. **D_8009B338 e D_8009B140 NA FORMA NUA (`_IN_DATA`).** O listing grava
 *     os dois com `lui $at`/`sh` e `lui $at`/`sb`, que e a forma nua de um
 *     STORE; o braco escalar da um `%gp_rel` de UMA instrucao so. Cada um
 *     vale uma instrucao: -8 -> -7 (so B338, 223; so B140, 256) -> -6 (os
 *     dois, 228).
 *  2. **Cinco simbolos lidos `lui %hi` querem sair do small data**:
 *     D_8009AF76, D_8009B0F4, D_8009B134, D_8009B398 e D_8009B39A, todos com
 *     `_IN_DATA`. Sao os seis `lui` que faltavam: -6/228 -> 0/109.
 *  3. **O campo +0x32 e lido `lh`, nao `lhu`** -- quatro sitios, argumento de
 *     func_80043230.
 *  4. **O teste do campo +0x60 e `>= 0` sobre um `s16`**, nao
 *     `(x & 0x8000) == 0`: o retail tem `sll 16`/`bltz` e a mascara da
 *     `andi`/`bne`. As duas juntas: 109 -> 103.
 *  E **D_8009B246 e lido `lh` em cinco sitios**: a declaracao guardada
 *  `D_8009B246_IS_SIGNED` move um deles e os outros quatro sairam sozinhos
 *  com a leitura 3.
 *
 * MEDIDO E MORTO: remover o local `e` para D_800EA0E8 e escrever o simbolo
 * inline nos quatro stores (272, censo identico na base antiga); um local
 * para D_8009B24C no braco `(D_8009B248 & 0x20) == 0` (-6 e 107 -- tira SEIS
 * instrucoes, entao a leitura repetida que o retail tem nao e um local
 * daquele braco).
 *
 * O QUE FALTA: 103 diferencas, censo `sb -1, lw +2, lbu +1, nop +1,
 * andi -2, beq -1` (magnitude 8), em tres grupos:
 *  - a ORDEM do bloco de setup (indices 7 a 42): o retail materializa o 1 de
 *    D_8009B0C0, o argumento 3 e o `lh d_8009b246` antes dos quatro stores em
 *    D_800EA0E8, e poe o `-0x400` em $s0 mais cedo;
 *  - o braco `(D_8009B248 & 0x20) == 0` (indices 268 a 290): o retail le
 *    D_8009B24C uma vez em $s1 e tem um `andi 0xFF` de re-leitura que nos nao
 *    temos;
 *  - o rabo (indices 294 a 318): a cadeia `if`/`else if` de D_8009B26C e
 *    D_8009B398 sai com os blocos em outra ordem.
 * Tres declaracoes novas em variables.h (D_8009B240, D_8009B24C e D_8009B250)
 * e tres bracos novos: `D_8009B246_IS_SIGNED`, `D_8009B338_IN_DATA` e
 * `D_8009B140_IN_DATA`.
 */
#define D_8009AF76_IN_DATA
#define D_8009B0F4_IN_DATA
#define D_8009B134_IN_DATA
#define D_8009B398_IN_DATA
#define D_8009B39A_IN_DATA
#define D_8009B338_IN_DATA
#define D_8009B140_IN_DATA
#define D_8009B246_IS_SIGNED
#define D_8009B0C0_IN_DATA
#define D_8009B254_IS_SCALAR
#include "common.h"

s32 func_800282E8(void);
void func_80029574(s32 arg0);
u8 *func_800291E0(s32 arg0, s32 arg1, s32 arg2);
void func_80015BD8(u8 arg0, u8 arg1);
void func_80043230(u8 *arg0, s32 arg1, s32 arg2, s16 arg3);
void func_80029528(s32 arg0);

void func_800283F4(void) {
    u8 *e;
    u8 *o;
    u8 *g;
    s32 *t;
    Rec64 *r;
    s32 i;
    s32 k;
    s32 neg;
    s16 v;

    if (func_800282E8() == 0) {
        D_8009B0C0 = 1;
        neg = -0x400;
        func_80029574(3);
        e = D_800EA0E8;
        *(s16 *)(e + 0xEA) = 0x100;
        *(s16 *)(e + 0xE8) = 0;
        *(s16 *)(e + 0xEC) = 0;
        *(s16 *)(e + 0xEE) = 0xFF;
        func_80029164(3, D_8009B246);
        o = func_800291E0(3, -1, -1);
        *(s16 *)(o + 0x30) = -0x8C;
        o[0x21] = 0x80;
        *(s16 *)(o + 0x32) = *(s16 *)(o + 0x32) + D_8009B24B;
        *(u16 *)(o + 8) = *(u16 *)(o + 8) | 4;
        func_80043178(o);
        *(s16 *)(o + 0x60) = neg;
        func_80042918(o);
        func_800428EC(o, 0x14);
        D_8009B24C = o;
        o = func_800400AC(func_8004002C(), 2);
        func_800404CC(o, 0x148, D_8009B24B + 0xE, 0, 2, 0, 0xD, 0x107);
        *(s16 *)(o + 0x60) = neg;
        *(u16 *)(o + 8) = *(u16 *)(o + 8) | 8;
        func_80042918(o);
        func_800428EC(o, 0x14);
        func_80043178(o);
        i = 0;
        t = D_801D4244;
        r = D_800EB0F8;
        *(s16 *)(o + 0x60) = neg;
        D_8009B240 = o;
        D_8009B250 = (u8 *)0;
        do {
            if ((*(u16 *)((u8 *)r + 0x34) & 0x8000) == 0) {
                D_8009B338 = D_8009B246;
                k = 3;
                if (((t[(s16)D_8009B246 - 1] >> 0x1A) & 0x1F) >= 0x14) {
                    k = 4;
                }
                g = func_80035BE4(i, k, 0x148, 0xE, 0xA8, 0xC0);
                g[0x53] = 1;
                g[0x54] = 0;
                g[0x59] = 0x15;
                D_8009B250 = g;
                func_80039A14(g);
                break;
            }
            i = i + 1;
            r = r + 1;
        } while (i < 3);
        func_80015BD8(0x40, 2);
        D_8009B140 = D_8009AF76 - 0x13;
        func_8003FEE0(0x34);
        D_8009B248 = D_8009B248 | 0x40;
        return;
    }
    if ((D_8009B248 & 0x40) != 0) {
        e = D_8009B240;
        v = *(s16 *)(e + 0x60);
        if (v != 0) {
            if ((D_8009B248 & 0x10) != 0) {
                func_80043230(e, 0x148, *(s16 *)(e + 0x32), v);
                *(u16 *)(e + 0x60) = *(u16 *)(e + 0x60) - 0x55;
                if (*(s16 *)(e + 0x60) <= 0) {
                    *(s16 *)(e + 0x30) = 0x400;
                    goto z0;
                }
            } else {
                func_80043230(e, 0x94, *(s16 *)(e + 0x32), v);
                *(u16 *)(e + 0x60) = *(u16 *)(e + 0x60) + 0x55;
                if (*(s16 *)(e + 0x60) >= 0) {
                    *(s16 *)(e + 0x30) = 0x94;
                z0:
                    *(u16 *)(e + 0x60) = 0;
                }
            }
            if (D_8009B250 != (u8 *)0) {
                func_80039934(D_8009B250, *(s16 *)(e + 0x30), *(s16 *)(e + 0x32));
            }
        }
        o = D_8009B24C;
        v = *(s16 *)(o + 0x60);
        if (v != 0) {
            if ((D_8009B248 & 0x10) != 0) {
                func_80043230(o, -0x8C, *(s16 *)(o + 0x32), v);
                *(u16 *)(o + 0x60) = *(u16 *)(o + 0x60) - 0x55;
                if (*(s16 *)(o + 0x60) <= 0) {
                    k = 0x400;
                    goto z1;
                }
            } else {
                func_80043230(o, 2, *(s16 *)(o + 0x32), v);
                *(u16 *)(o + 0x60) = *(u16 *)(o + 0x60) + 0x55;
                k = 2;
                if (*(s16 *)(o + 0x60) >= 0) {
                z1:
                    *(s16 *)(o + 0x30) = k;
                    *(u16 *)(o + 0x60) = 0;
                }
            }
        }
        if (((D_8009B0F4 & 0x2000030) | D_8009B134) == 0 && *(s16 *)(D_8009B240 + 0x60) == 0 && *(s16 *)(D_8009B24C + 0x60) == 0) {
            k = D_8009B248 & 0x10;
            D_8009B248 = D_8009B248 & 0xBF;
            if (k != 0) {
                func_8004036C((s32)D_8009B240);
                func_80029528(3);
                if (D_8009B250 != (u8 *)0) {
                    func_80035B7C(D_8009B250);
                }
                D_8009B0C0 = 0;
                D_8009B254 = D_8009B254 | 0x40;
            }
        }
        return;
    }
    if ((D_8009B248 & 0x20) == 0) {
        D_8009B24C[0x21] = D_8009B24C[0x21] + 0xC;
        if (D_8009B24C[0x21] < 0x40) {
            D_8009B24C[0x21] = 0;
            *(u16 *)(D_8009B24C + 8) = *(u16 *)(D_8009B24C + 8) & 0xFFFB;
            D_8009B248 = D_8009B248 | 0x20;
        }
        return;
    }
    if ((D_8009B26C[0] & 0x1F) == 0xE) {
        if (((D_8009B398 | D_8009B39A) & 0x20) == 0) {
            return;
        }
    } else if ((D_8009B398 & 0x20) == 0) {
        return;
    }
    func_80043178(D_8009B240);
    *(s16 *)(D_8009B240 + 0x60) = 0x400;
    func_80043178(D_8009B24C);
    *(s16 *)(D_8009B24C + 0x60) = 0x400;
    func_80015BD8(0xFF, 2);
    func_8003FEE0(0x34);
    D_8009B248 = D_8009B248 | 0x50;
}
