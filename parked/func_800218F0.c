/* MAIS PERTO, 2026-09-13. Escrita do zero; flags padrao (sem linha em
 * build.py). 496/498, excesso de censo 1 (lui +1; nop -3), 20 blocos
 * estruturais. Tela de resultado do duelo: cria os objetos da pontuacao e
 * atualiza os contadores de vitoria em D_8009B1D8.
 *
 * LEVERS, medidos um sobre o outro com try_func (v1 era 492/498, excesso 3,
 * 38 blocos):
 *  1. Os testes de D_8009B360/D_8009B361 e de D_8009B165 escritos com `goto`
 *     para dois rotulos, `join:` com a releitura de D_8009B165 e `join2:`
 *     logo depois. Sem isso os tres desvios caem num rotulo que comeca com
 *     o `lui %hi(D_8009B360)` e o reorg copia esse `lui` para os tres slots
 *     onde o alvo tem `nop` (excesso 3 -> 1).
 *  2. `do { } while (0);` em volta do teto 0xF423F de +0x5E0: o par do
 *     0xF423F deixa de ocupar os slots de leitura (492 -> 494).
 *  3. `do { } while (0);` em volta de `D_8009B1E8 = D_801799D8;`: o `lui` de
 *     D_801D5708 volta para depois do store (blocos -2).
 *  5. O teto 0xF423F relido por lvalues volateis, o ponteiro
 *     `*(u8 *volatile *)&D_8009B1D8` e o `*(volatile u32 *)` de +0x5E0: o
 *     alvo recarrega os dois depois do store (494 -> 495 -> 496). Volatil
 *     tambem no `+=` chega a 498 com lw +1 e foi rejeitado.
 *  4. A divisao por 10 sobre um nome (`v = v - 0x32; ... v / 10`), c10 e tex
 *     atribuidos depois da criacao do objeto, e o elemento de D_8009B1D8
 *     lido antes do `|= 0x2000` de D_8009B16C.
 *
 * RESIDUO: tres `nop` de leitura, um `lui` copiado para slot, a ordem de x/j no laco das
 * fichas e os registradores dos incrementos de +0x518/+0x51A.
 * MEDIDO E PIOR (troca de comprimento por excesso): nome novo para o valor
 * dos incrementos (+2 com addiu +1), leituras nomeadas de +0x39/+0x38 nos
 * argumentos (addu +2). NEUTRO: tres grafias do indice de D_8009B360, ordem
 * de declaracao de x/j, emprestimo de i para x ou j, leitura de D_8009B361
 * como u8.
 */
#define D_8009B146_IN_DATA
#define D_8009B338_IN_DATA
#define D_8009B394_IN_DATA_VOLATILE
#define D_8009B398_IN_DATA
#include "common.h"

extern u8 D_8009B34E __attribute__((section(".data")));
extern u8 D_8009B355 __attribute__((section(".data")));
extern u16 D_8009B32E __attribute__((section(".data")));
extern s32 D_801D56A8[];

void func_80015C84(void);
void func_80015BD8(u8 arg0, u8 arg1);
void func_800428A8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7, u8 *arg8);
s32 func_80021810(s32 a0);
void func_800156B8(s32 arg0);
void func_80021894(s32 arg0);
void func_80021480(s32 arg0);
void func_80021598(void);

void func_800218F0(void)
{
    u8 *p;
    u8 *o;
    u8 *q;
    u8 **pp;
    u8 *tex;
    s32 f;
    s32 a;
    s32 v;
    s32 i;
    s32 j;
    s32 k;
    s32 x;
    s32 one;
    s32 c0b;
    s32 c20c;
    s32 c8;
    s32 c10;
    s16 r;
    s32 ix;
    s32 w;
    u8 **b1d8;
    u8 **pp2;

    p = D_800F2848;
    *(u16 *)(p + 2) += 2;
    func_8001352C();
    f = D_8009B23A;
    if (!(f & 0x8000)) {
        D_8009B23A = f | 0x8000;
        func_80015C84();
        func_80015BD8(0x80, 2);
        do {
            D_8009B1E8 = D_801799D8;
        } while (0);
        D_801D5708[0] = 4;
        D_8009B148 = 0;
        D_8009B146 = 0;
        D_8009B34E = 0;
        D_8009B355 = 0;
        D_801D5708[1] = 4;
        D_801D5708[D_8009B165] = 0;
        a = 0x72E1;
        if (D_8009B165 != 0) {
            a = 0x72F1;
            D_8009B355 = 1;
            D_8009B32E = (s8)D_8009B361[0] - 0x7CD8;
        }
        func_8003FF08(a);
        if (D_8009B360[0] < 0 && D_8009B361[0] < 0) {
            D_8009B34E = 1;
            D_8009B355 += 2;
        }
        D_8009B1E8[0x39] = 0;
        func_80021598();
        v = *(s32 *)(D_8009B1E8 + D_8009B165 * 4 + 0x2C);
        if (v < 0x32) {
            D_8009B1E8[0x39] = 1;
            if (v < 0) {
                v = 0;
            }
            v = 0x63 - v;
        }
        if (v >= 0x64) {
            v = 0x63;
        }
        v = v - 0x32;
        D_8009B1E8[0x38] = v / 10;
        D_8009B1E8[0x37] = 0;
        o = func_800400AC(func_8004002C(), 2);
        one = 1;
        c0b = 0xB;
        c20c = 0x20C;
        func_800404CC(o, 0x20, 0x10, 3, one, 2, c0b, c20c);
        func_80042918(o);
        *(u16 *)(o + 8) |= 0x28;
        o = func_800400AC(func_8004002C(), 2);
        func_800404CC(o, 0x120, 0x10, 3, one, 0, c0b, c20c);
        func_80042918(o);
        i = 9;
        *(u16 *)(o + 8) |= 0x28;
        o = func_800400AC(func_8004002C(), 2);
        func_800428A8(o, 0, 8, 0, 4, 0, 0x10, 8, D_801AF000);
        func_80042918(o);
        func_800428EC(o, -1);
        q = D_8009B1E8 + 0x24;
        *(u16 *)(o + 8) |= 0x20;
        *(u8 **)D_8009B1E8 = o;
        do {
            *(s32 *)(q + 4) = 0;
            i--;
            q -= 4;
        } while (i >= 0);
        D_8009B338 = 0;
        if (D_8009B360[0] >= 0) {
            goto join;
        }
        if (D_8009B361[0] < 0) {
            goto join;
        }
        ix = D_8009B165;
        if (ix != 0) {
            goto join2;
        }
        D_8009B1E8[0x3A] = D_8009B1E8[0x38] + 1;
        a = (D_8009B1E8[0x39] != 0) * 2;
        if (D_8009B1E8[0x38] < 3) {
            a = 1;
        }
        j = 0;
        r = func_80021810(a);
        D_8009B338 = r;
        *(s16 *)(D_8009B1E8 + 0x3C) = r;
        D_801D56A8[0] = r;
        k = 8;
        if (D_8009B1E8[0x3A] != 0) {
            x = 0xA0;
            do {
                j++;
                o = func_800400AC(func_8004002C(), 2);
                func_800404CC(o, x, 0xC0, 3, 4, 0, 0xB, 0x20C);
                func_80042918(o);
                x += 0x14;
                *(u16 *)(o + 8) |= 0x20;
                *(u8 **)(D_8009B1E8 + k + 4) = o;
                k += 4;
            } while (j < D_8009B1E8[0x3A]);
        }
    join:
        ix = D_8009B165;
    join2:
        if (D_8009B360[ix] < 0) {
            c8 = 8;
            o = func_800400AC(func_8004002C(), 2);
            c10 = 0x10;
            tex = D_801AF000;
            func_800428A8(o, 0, c10, 0, 5, D_8009B1E8[0x39], c10, c8, tex);
            func_80042918(o);
            func_800428EC(o, -2);
            *(u16 *)(o + 8) |= 0x20;
            *(u8 **)(D_8009B1E8 + 4) = o;
            o = func_800400AC(func_8004002C(), 2);
            func_800428A8(o, 0, c10, 0, 6, D_8009B1E8[0x38], c10, c8, tex);
            func_80042918(o);
            func_800428EC(o, -1);
            *(u16 *)(o + 8) |= 0x20;
            *(u8 **)(D_8009B1E8 + 8) = o;
        }
        goto tail;
    }
    if (f & 0x4000) {
        p = D_800E9EC8;
        if (p[6] & 0x80) {
            return;
        }
        if (!(f & 0x2000)) {
            D_8009B23A = f | 0x2000;
            func_80015904();
            p[4] = 0xFF;
            func_800156B8(0xFF);
            return;
        }
        q = (&D_8009B1D8)[D_8009B165];
        D_8009B16C |= 0x2000;
        if (q == 0) {
            return;
        }
        if (D_8009B360[0] < 0 && D_8009B361[0] >= 0) {
            *(u32 *)(D_8009B1D8 + 0x5E0) += D_8009B1E8[0x3A];
            do {
                if (*(volatile u32 *)(*(u8 *volatile *)&D_8009B1D8 + 0x5E0) > 0xF423F) {
                    *(u32 *)(D_8009B1D8 + 0x5E0) = 0xF423F;
                }
            } while (0);
            func_80021894(*(s16 *)(D_8009B1E8 + 0x3C));
            return;
        }
        pp = &D_8009B1D8 + D_8009B165;
        v = *(u16 *)(*pp + 0x518) + 1;
        *(u16 *)(*pp + 0x518) = v;
        if ((u16)v >= 0x2710) {
            *(u16 *)(*pp + 0x518) = 0x270F;
        }
        pp = &D_8009B1D8 + (D_8009B165 ^ 1);
        v = *(u16 *)(*pp + 0x51A) + 1;
        *(u16 *)(*pp + 0x51A) = v;
        if ((u16)v >= 0x2710) {
            *(u16 *)(*pp + 0x51A) = 0x270F;
        }
        return;
    }
    if (D_8009B394 & 0xA000) {
        D_8009B1E8[0x37]++;
        if (D_8009B394 & 0x8000) {
            v = D_8009B1E8[0x37] - 2;
            D_8009B1E8[0x37] = v;
            if ((s8)v < 0) {
                D_8009B1E8[0x37] = 2;
            }
        }
        if ((s8)D_8009B1E8[0x37] >= 3) {
            D_8009B1E8[0x37] = 0;
        }
        func_8003FEE0(6);
    tail:
        func_80021480((s8)D_8009B1E8[0x37]);
        return;
    }
    if (D_8009B398 & 0x40) {
        D_8009B23A = f | 0x4000;
        func_80015BD8(0, 6);
        func_8003FEE0(0x30);
    }
}
