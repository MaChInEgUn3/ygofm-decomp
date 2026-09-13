/* MAIS PERTO, 2026-09-13. Escrita do zero; flags padrao (sem linha em
 * build.py). 474/474, CENSO VAZIO, 56 diferencas, 6 blocos estruturais.
 * Maquina de estados de seis passos sobre D_8009B210 & 0xF (jump table).
 *
 * LEVERS, medidos um sobre o outro com try_func:
 *  1. D_800E9EF0_IS_PTR_VOLATILE: sem ele faltam sete `lw` de recarga
 *     (465 -> 482 com o arm; a versao nao volatil fica em 462/464).
 *  2. O store `*(u8 **)&D_800E9EF0[1] = h` por um lvalue NAO volatil: so
 *     assim ele vai para o slot do jal func_800428EC (477 -> 476).
 *  3. `m = D_8009B34D;` lido num nome antes do store de +0x16: 476 -> 474 e
 *     censo vazio.
 *  4. Nomes novos onde um nome atravessava uma chamada noutro caso (n0 no
 *     topo, g/h e q2 no caso 2, q3/w no caso 3, g2 no caso 4): cada um tira
 *     um registrador salvo que o alvo nao tem.
 *  5. `c <<= 16; if (c > 0)` para o `sll` no proprio registrador, e a
 *     leitura `(u16)D_8009B20C[1]` para o `lhu`.
 *  6. func_80024D34 recebe quatro argumentos: o alvo deixa D_8009B210 em $a2
 *     e &D_800EA128 em $a3 antes do desvio.
 *  7. `y = *(s16 **)(p + 4); w = (u16)D_8009B1A0; *y = w;`: 8 -> 6 blocos.
 *
 * RESIDUO: no caso 3 o alvo materializa D_801A7AD8 antes de D_800EA128 e le
 * +0x2A antes do byte +3; o indice de D_8009B360 e carregado antes do `lui`;
 * trocas de registrador nos casos 1 e 2.
 * MEDIDO E NEUTRO OU PIOR: posicao da declaracao de `e`, ordem f/p/e, quatro
 * grafias do indice de D_8009B360 (cast (s32), nome para o indice, base
 * local), `c = load; c = c - 1`, nomes c1/c2 por caso, reuso de q2 na
 * segunda leitura do ramo else.
 */
#define D_800E9EF0_IS_PTR_VOLATILE
#define FUNC_80017F04_FULL
#define D_8009B338_IN_DATA
#define D_8009B34D_IN_DATA
#define D_8009B398_IN_DATA
#include "common.h"

extern u8 D_8009B19C;
extern u8 *D_8009B1C0;
extern u8 D_800E9EF8[];
extern u8 D_800EA128[];

u8 *func_800291E0(s32 arg0, s32 arg1, s32 arg2);
void func_800429D8(u8 *arg0);
void func_8001944C(u8 *arg0);
void func_80019CC8(s32 arg0);
void func_8003FF88(s32 arg0);
void func_80029528(s32 arg0);
void func_80024D34(s32 arg0, s32 arg1, s32 arg2, u8 *arg3);
void func_8007F9D8(u8 *rect, u8 *p);
s32 func_8008E590(void);
s32 func_8003700C(u8 *arg0);
void func_80043230(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80039794(void);
void func_8001EC70(u8 *arg0);

void func_800262D4(void)
{
    u8 *o;
    u8 *p;
    u8 *e;
    u8 *q;
    s16 r;
    s32 v;
    s32 c;
    s32 b;
    s32 f;
    s32 k;
    u8 *t;
    u8 *n0;
    u8 *q3;
    s32 w;
    s32 m;
    s32 ix;
    s32 k2;
    s16 *y;
    u8 *q2;
    u8 *g2;
    u8 *g;
    u8 *h;
    u8 *bs;

    if (func_80024E24() == 0) {
        D_8009B1A0 = func_8002C7E8((s32)D_800E9EF8, D_8009B1D2);
        if (D_8009B1A0 != 0) {
            func_80019CC8(D_8009B1A0);
            n0 = func_8002C604(0x16);
            D_8009B17C = n0;
            D_8009B210 = 0;
            *(s16 *)(n0 + 0x1A) = D_8009B1D2;
            func_8003FF88(0x8022);
            return;
        }
        D_8009B220 = 0;
        return;
    }
    switch (D_8009B210 & 0xF) {
    case 0:
        if (D_8009B17C[0x1D] != 0) {
            D_8009B19C = (D_800E9EF0[3])[0x6A];
            func_80024914(D_801A7AD8 + (D_800E9EF0[2])[0x6A] * 28);
            func_80024914(D_801A7AD8 + (D_800E9EF0[3])[0x6A] * 28);
            func_80024914(D_801A7AD8 + (D_800E9EF0[4])[0x6A] * 28);
            D_8009B210 = 1;
        }
        break;
    case 1:
        o = D_8009B1C0;
        if (!(D_8009B210 & 0x80)) {
            D_8009B210 |= 0x80;
            o = func_800291E0(1, -1, -1);
            *(s16 *)(o + 0x30) = 0x5A;
            *(s16 *)(o + 0x32) = -0x22;
            *(s16 *)(o + 0x60) = 0x18;
            *(s16 *)(o + 0x46) = 0;
            *(s16 *)(o + 0x44) = 0;
            *(s32 *)(o + 4) &= 0xF7FFFFFF;
            *(u16 *)(o + 8) |= 4;
            func_800429D8(o);
            *(s16 *)(o + 0x38) = 0x255;
            D_8009B1C0 = o;
            func_8003FEE0(0x26);
        }
        func_80042A28(o);
        v = *(u16 *)(o + 0x44) + 0xAA;
        c = *(u16 *)(o + 0x60) - 1;
        *(s16 *)(o + 0x60) = c;
        c <<= 16;
        *(s16 *)(o + 0x44) = v;
        *(s16 *)(o + 0x46) = v;
        if (c > 0) {
            break;
        }
        *(s16 *)(o + 0x46) = 0x1000;
        *(s16 *)(o + 0x44) = 0x1000;
        *(s16 *)(o + 0x32) = 0x16;
        D_8009B210 = 2;
        *(s32 *)(o + 4) |= 0x8000000;
        *(u16 *)(o + 8) &= 0xFFFB;
        break;
    case 2:
        o = D_8009B1C0;
        if (!(D_8009B210 & 0x80)) {
            D_8009B210 |= 0x80;
            D_8009B20C[1] = 0x20;
        }
        if (!(D_8009B210 & 0x40)) {
            c = (u16)D_8009B20C[1] - 1;
            D_8009B20C[1] = c;
            c <<= 16;
            if (c > 0) {
                break;
            }
            D_8009B210 |= 0x40;
            func_8001944C(o);
            g = func_80019564(o);
            D_800E9EF0[0] = g;
            *(s32 *)(g + 4) |= 0x50000000;
            *(s32 *)(D_800E9EF0[0] + 4) &= 0xF7FFFFFF;
            h = func_80019564(o);
            *(u8 **)&D_800E9EF0[1] = h;
            func_800428EC(h, -1);
            *(s32 *)(D_800E9EF0[1] + 4) |= 0x60000000;
            *(s32 *)(D_800E9EF0[1] + 4) &= 0xF7FFFFFF;
            func_80029528(1);
        } else {
            e = D_800E9EF0[0];
            v = *(s16 *)(e + 0x44) + 0x80;
            q2 = D_800E9EF0[1];
            *(s16 *)(q2 + 0x46) = v;
            *(s16 *)(q2 + 0x44) = v;
            *(s16 *)(e + 0x46) = v;
            *(s16 *)(e + 0x44) = v;
            e = D_800E9EF0[0];
            c = e[0xC] - 4;
            if (c < 0) {
                c = 0;
            }
            c = c | ((c << 16) | (c << 8));
            *(s32 *)(e + 0xC) = c;
            *(s32 *)(D_800E9EF0[1] + 0xC) = c;
            if (c != 0) {
                break;
            }
            func_8004036C((s32)D_800E9EF0[0]);
            func_8004036C((s32)D_800E9EF0[1]);
            D_8009B210 = 3;
        }
        break;
    case 3:
        p = D_801A7AD8 + D_8009B19C * 28;
        f = D_8009B210;
        e = D_800EA128;
        if (!(f & 0x80)) {
            y = *(s16 **)(p + 4);
            w = (u16)D_8009B1A0;
            *y = w;
            q3 = *(u8 **)(p + 4);
            D_8009B210 = f | 0x80;
            *(s16 *)(p + 0xC) = w;
            b = q3[3];
            *(s16 *)(e + 8) = *(u16 *)(e + 0x28) + 0x38;
            *(s16 *)(e + 0xC) = 8;
            *(s16 *)(e + 0xE) = 0x58;
            *(s16 *)(e + 0xA) = *(u16 *)(e + 0x2A);
            func_8007F9D8(e + 8, D_8018C2D8 + b * 0x580);
            break;
        }
        func_80024D34(D_8009B19C, *(s8 *)(*(u8 **)(p + 4) + 2), f, e);
        o = *(u8 **)p;
        D_800E9EF0[0] = o;
        *(s16 *)(o + 0x32) = -0xF0;
        if (*(s8 *)(D_8009B1D5 + (s32)D_8009B360) >= 0) {
            *(u16 *)(p + 0x16) &= 0xFDFF;
            if (func_8008E590() & 1) {
                *(u16 *)(p + 0x16) |= 0x200;
            }
            D_8009B210 = 5;
            break;
        }
        D_800E9EF0[1] = func_80017F04(p, 0x86, 0xF0);
        D_8009B210 = 4;
    case 4:
        o = *(u8 **)D_800E9EF4;
        if (!(D_8009B210 & 0x80)) {
            D_8009B210 |= 0x80;
            *(s16 *)(o + 0x28) = 0x86;
            *(s16 *)(o + 0x2A) = 0x2A;
            *(s16 *)(o + 0x2C) = 0x10;
            o[0x6C] = 1;
            *(s32 *)(o + 0x24) = (s32)func_8001EC70;
            break;
        }
        if (!(D_8009B210 & 0x40)) {
            if (func_80042B40(1) != 0) {
                break;
            }
            k = 0x48000;
            bs = D_8015C424;
            g2 = bs + o[0x6A] * 28 + k;
            D_8009B338 = *(u16 *)(g2 + 0x36C0);
            q = func_80035C38(0, 0x21, 0x48, 0x6E, 0xB0, 0x30, 0x20);
            q[0x5A] = 8;
            q[0x5B] = 0x10;
            do {
                func_80039794();
            } while (*(s32 *)(q + 0x30) == 0);
            D_8009B210 |= 0x40;
            break;
        }
        if (!(D_8009B210 & 0x20)) {
            t = (u8 *)D_800EB0F8;
            if (func_8003700C(t) != 0) {
                break;
            }
            if (!(D_8009B398 & 0xC0)) {
                break;
            }
            func_8003FEE0(7);
            *(s16 *)(o + 0x28) = 0x86;
            *(s16 *)(o + 0x2A) = -0x80;
            *(s16 *)(o + 0x2C) = 0x10;
            o[0x6C] = 1;
            *(s32 *)(o + 0x24) = (s32)func_8001EC70;
            q = D_801A7AD8 + o[0x6A] * 28;
            v = *(u16 *)(q + 0x16) & 0xFDFF;
            m = D_8009B34D;
            *(u16 *)(q + 0x16) = v;
            if (m != 0) {
                *(u16 *)(q + 0x16) = v | 0x200;
            }
            func_80035B7C(t);
            D_8009B210 |= 0x20;
            break;
        }
        if (func_80042B40(1) != 0) {
            break;
        }
        func_8004036C((s32)o);
        D_8009B210 = 5;
        break;
    case 5:
        o = D_800E9EF0[0];
        if (!(D_8009B210 & 0x80)) {
            D_8009B210 |= 0x80;
            func_80043178(o);
            *(s16 *)(o + 0x60) = -0x400;
        }
        func_80043230(o, *(s16 *)(o + 0x30), -0x18, *(s16 *)(o + 0x60));
        v = *(u16 *)(o + 0x60) + 0x2A;
        *(s16 *)(o + 0x60) = v;
        v <<= 16;
        if (v < 0) {
            break;
        }
        *(s16 *)(o + 0x32) = -0x18;
        D_8009B220 = 0;
        break;
    }
}
