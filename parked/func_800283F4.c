/* 326/334 -- OITO instrucoes a menos -- e 272 diferencas, censo de magnitude
 * 28 (2026-09-08, PRIMEIRO RASCUNHO que compila). Flags PADRAO (passo 0:
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
 * MEDIDO ATE AQUI:
 *  - **D_8009B246 e lido `lh` em cinco sitios e o `u16` da `lhu`.** Tanto um
 *    `(s16)` em dois sitios quanto a declaracao `s16` guardada
 *    (`D_8009B246_IS_SIGNED`) movem UM `lhu` para `lh` -- censo de magnitude
 *    30 para 28 com a contagem parada em 272, que e o caso do WORKFLOW em que
 *    so o censo enxerga o progresso. Faltam QUATRO `lh`;
 *  - remover o local `e` para D_800EA0E8 e escrever o simbolo inline nos
 *    quatro stores nao muda nada (272, censo identico).
 *
 * O QUE FALTA: `lui -8` domina o censo -- o retail materializa oito enderecos
 * a mais do que nos, o que combina com D_8009B338 e D_8009B140 ainda no braco
 * escalar em vez da forma nua, e com o `-0x400` que o retail carrega em $s0
 * desde o inicio do bloco de setup. Depois disso, `lh -4`, `bne +2`, `lw +2`,
 * `bltz -2`, `sll -2`.
 * Tres declaracoes novas em variables.h (D_8009B240, D_8009B24C e D_8009B250,
 * os ponteiros gp-relativos que a rotina grava) e o braco
 * `D_8009B246_IS_SIGNED`.
 */
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
        *(u16 *)(o + 0x32) = *(u16 *)(o + 0x32) + D_8009B24B;
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
                func_80043230(e, 0x148, *(u16 *)(e + 0x32), v);
                *(u16 *)(e + 0x60) = *(u16 *)(e + 0x60) - 0x55;
                if (*(s16 *)(e + 0x60) <= 0) {
                    *(s16 *)(e + 0x30) = 0x400;
                    goto z0;
                }
            } else {
                func_80043230(e, 0x94, *(u16 *)(e + 0x32), v);
                *(u16 *)(e + 0x60) = *(u16 *)(e + 0x60) + 0x55;
                if ((*(u16 *)(e + 0x60) & 0x8000) == 0) {
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
                func_80043230(o, -0x8C, *(u16 *)(o + 0x32), v);
                *(u16 *)(o + 0x60) = *(u16 *)(o + 0x60) - 0x55;
                if (*(s16 *)(o + 0x60) <= 0) {
                    k = 0x400;
                    goto z1;
                }
            } else {
                func_80043230(o, 2, *(u16 *)(o + 0x32), v);
                *(u16 *)(o + 0x60) = *(u16 *)(o + 0x60) + 0x55;
                k = 2;
                if ((*(u16 *)(o + 0x60) & 0x8000) == 0) {
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
