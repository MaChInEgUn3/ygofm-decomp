/* MAIS PERTO, 2026-09-13. Escrita do zero; flags padrao (sem linha em
 * build.py). 532/532, CENSO VAZIO, 5 diferencas no try_func, uma delas o
 * renderer (%lo(.rodata) contra %lo(.rodata+48) na tabela; so o build
 * completo decide essa). Maquina de estados do cartao de memoria sobre
 * D_8009B3CF & 0xF, com o resultado de func_80044838 tratado antes.
 *
 * LEVERS, medidos um sobre o outro com try_func (v1 era -15):
 *  1. z = 0 num nome proprio ($s5): e o primeiro argumento de seis chamadas
 *     e o valor inicial dos contadores.
 *  2. Guarda do laco FntPrint escrita `if (z < D_8009B440)`, `i = z` antes
 *     dela e o incremento na condicao (`while (++i < D_8009B440)`).
 *  3. `case 1:` explicito antes do default no switch interno do caso 2.
 *  4. Casos 3 e 4 escritos inteiros, cada um `if (C8 == 0) { ... } else {
 *     D5 = 1; }`: o else do caso 4 fica e o do caso 3 salta para ele.
 *  5. Polaridade do teste de D_8009B3C7 (`if (!(C7 & 1)) { CF = 5; }`).
 *  6. No caso 7, `b = 1` nos dois ramos antes da chamada comum: 531 -> 532.
 *  7. O xor do laco do caso 8 sobre `((u8 *)0x80210000)[j]` num do/while.
 *  8. Divisao por 64 inline na chamada do caso 5 e escrita como
 *     `if (sz < 0) sz += 0x3F; ... sz >> 6` no caso 8.
 *  9. `do { D_8009B3CF = 8; } while (0);` depois do `|= 0x400` do caso 7.
 * 10. Nomes emprestados: `i` para o passo `s` dos casos 3/4 e para o indice
 *     `n` dos casos 5-8 (42 -> 25 -> 9), `a` para o valor de D_8009B3CC no
 *     caso 2 (35 -> 32).
 *
 * RESIDUO: o alvo soma 0x1C a g antes de somar o indice (`addiu $v1,$s2,28;
 * addu $s3,$v0,$v1`) e poe o `lui %hi(D_8009AF6C)` antes de `off = z`.
 * MEDIDO E NEUTRO OU PIOR: seis grafias do rec (grupo com parenteses, cast
 * para inteiro, nome para g + 0x1C, struct de 0x268 bytes indexada, membro
 * de struct), seis formas do laco (for, ordem de i/off, argumento extra),
 * ordem de declaracao de i/off, divisao inline no caso 8, nome novo para o
 * tamanho do caso 8.
 */
#define D_8009B34D_IN_DATA
#include "common.h"

extern s32 D_8009B440 __attribute__((section(".data")));
extern s32 D_8009B444 __attribute__((section(".data")));
extern s32 D_8009B438 __attribute__((section(".data")));
extern u8 D_8009B3D5;
extern s32 D_8009B3C8;
extern s32 D_8009B3E4;
extern u8 D_800EF6D0[];
extern u8 D_8009AF6C[];
extern u8 D_80010378[];
extern u8 D_80010398[];
extern u8 D_800103A4[];
extern void (*D_80090F88[])(u8 *, u8 *);
extern u8 D_80210000[];
extern u8 D_8021007A __attribute__((section(".data")));
extern u8 D_8021007B __attribute__((section(".data")));
extern u8 D_8021007C __attribute__((section(".data")));
extern u8 D_8021007D __attribute__((section(".data")));
extern u8 D_8021007E __attribute__((section(".data")));
extern u8 D_8021007F __attribute__((section(".data")));

s32 func_8007EF84();
s32 func_8008E870();
s32 func_80044838(s32 arg0, s32 *arg1, s32 *arg2);
s32 func_80044CD4(u8 *name);
u8 *func_8003D46C(s32 arg0, s32 arg1);
s32 func_8004413C(s32 arg0);
s32 func_800441DC(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_80044278(s32 arg0, s32 arg1, s32 arg2);
s32 func_800442E4(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_80044380(s32 arg0, s32 arg1, s32 arg2);
s32 func_800443EC(s32 arg0, u8 *arg1, s32 arg2);
void func_80035748(u8 *dst, s32 c, u32 len);
void func_80043EBC(void);
void func_80039794(void);

void func_8003DC1C(void)
{
    u8 *g;
    u8 *rec;
    u8 *e;
    u8 *name;
    s32 z;
    s32 i;
    s32 off;
    s32 r;
    s32 f;
    s32 s;
    s32 v;
    s32 t;
    s32 a;
    s32 n;
    s32 sz;
    s32 x;
    s32 j;
    s32 b;

    g = D_800EF6D0;
    rec = g + 0x1C + D_8009B3DD * 0x268;
    z = 0;
    if (D_8009B3CC & 0x2000) {
        i = z;
        if (z < D_8009B440) {
            off = z;
            do {
                func_8007EF84(D_8009AF6C, D_8009B444 + off);
                off += 0x28;
            } while (++i < D_8009B440);
        }
        func_8007EF84(D_80010378, rec[0xC]);
    }
    r = -1;
    if (D_8009B3CC & 0x4000) {
        r = func_80044838(1, &D_8009B3E4, &D_8009B3C8);
    }
    if ((D_8009B3CC & 0x1000) && r != 0 && r == 1) {
        switch (D_8009B3E4) {
        case 2:
            a = D_8009B3CC;
            D_8009B3CC = a | 0x2000;
            switch (D_8009B3C8) {
            case 3:
                D_8009B3CC = a | 0x2800;
            case 0:
                rec[0xC] = D_8009B438;
                goto clear;
            case 4:
                D_8009B3CC = a | 0x2002;
                D_8009B3D5 = 1;
                break;
            case 1:
            default:
                D_8009B3D5 = 2;
                break;
            }
            break;
        case 3:
            if (D_8009B3C8 == 0) {
                i = *(s16 *)(g + 0x16);
                v = *(u16 *)(g + 0x12) - i;
                *(s16 *)(g + 0x12) = v;
                if ((s16)v <= 0) {
                    goto clear;
                }
                *(s32 *)rec = *(s32 *)rec + i;
                *(u16 *)(g + 0x14) += i;
                if (*(s16 *)(g + 0x12) < *(s16 *)(g + 0x16)) {
                    *(s16 *)(g + 0x16) = *(u16 *)(g + 0x12);
                }
            } else {
                D_8009B3D5 = 1;
            }
            break;
        case 4:
            if (D_8009B3C8 == 0) {
                i = *(s16 *)(g + 0x16);
                v = *(u16 *)(g + 0x12) - i;
                *(s16 *)(g + 0x12) = v;
                if ((s16)v <= 0) {
                    goto clear;
                }
                *(s32 *)rec = *(s32 *)rec + i;
                *(u16 *)(g + 0x14) += i;
                if (*(s16 *)(g + 0x12) < *(s16 *)(g + 0x16)) {
                    *(s16 *)(g + 0x16) = *(u16 *)(g + 0x12);
                }
            } else {
                D_8009B3D5 = 1;
            }
            break;
        case 8:
        case 11:
        case 12:
            D_8009B3D5 = 1;
            if (D_8009B3C8 == 0) {
            clear:
                D_8009B3D5 = 0;
            }
            break;
        }
    }
    t = D_8009B3C1 & 0xF;
    if (t != 0) {
        r = 1;
        D_80090F88[t](g, rec);
    }
    if (r >= 0) {
        return;
    }
    if (D_8009B3CC & 0x400) {
        e = (u8 *)D_800EB0F8 + g[0x1A] * 100;
        func_80039794();
        if ((*(s32 *)(e + 0x34) & 0x2008) == 0x2000) {
            D_8009B3CC &= 0xFBFF;
        }
        return;
    }
    switch (D_8009B3CF & 0xF) {
    case 0:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            D_8009B3C1 = 1;
            return;
        }
        if (D_8009B34D != 0) {
            D_8009B3C1 = 2;
            return;
        }
        ((void (*)(s32))func_80043E30)(1);
        func_80043EBC();
        D_8009B3CF = 1;
        D_8009B3CC |= 0x4000;
    case 1:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            D_8009B3CC |= 0x1000;
            func_8004413C(z);
            return;
        }
        D_8009B3CF = 4;
    case 4:
        f = D_8009B3CC;
        if (!(f & 0x2000)) {
            return;
        }
        D_8009B3CC = f & 0xEFFF;
        a = 0xD2;
        if (D_8009B3D5 == 2) {
            goto msg;
        }
        if (!(D_8009B3C7 & 1)) {
            D_8009B3CF = 5;
            return;
        }
        D_8009B3CF = 7;
        return;
    case 5:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            i = func_80044CD4(D_80010384);
            if (i < 0 || (D_8009B3CC & 2)) {
                a = 0xD3;
                goto msg;
            }
            func_80044278(z, 0x80210000, *(s32 *)(D_8009B444 + i * 0x28 + 0x20) / 64);
            return;
        }
        a = 0xD8;
        if (D_8009B3D5 != 0) {
            goto msg;
        }
        D_8009B3CF = 6;
    case 6:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            name = D_80010384;
            i = func_80044CD4(name);
            a = 0xD3;
            if (i < 0) {
                goto msg;
            }
            if (D_8009B3CC & 2) {
                goto msg;
            }
            func_8003D46C(0x80D5, 0);
            rec[0xD] = i;
            D_8009B3CC |= 0x1000;
            func_800441DC(z, name, 0x80200000, 0x200, 0x1E00);
            return;
        }
        a = 0xD7;
        if (D_8009B3D5 == 1) {
            a = 0xD8;
        }
        goto msg;
    case 7:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            if (D_8009B3CC & 2) {
                D_8009B3CF = 9;
                return;
            }
            name = D_80010384;
            if (func_80044CD4(name) < 0) {
                D_8009B3CF = 10;
                return;
            }
            func_8003D46C(0x80D6, 0);
            func_800356A0((u8 *)0x80300000, D_801D4000, 0x200);
            func_80035748((u8 *)0x80300200, 0x86, 0x800);
            func_800442E4(z, name, 0x80300000, 0, 0xA00);
            D_8009B3CC |= 0x1000;
            return;
        }
        a = 0xD7;
        if (D_8009B3D5 == 1) {
            a = 0xD9;
            b = 1;
        } else {
            b = 1;
            D_8009B3CF = 8;
        }
        func_8003D46C(a, b);
        D_8009B3CC |= 0x400;
        do {
            D_8009B3CF = 8;
        } while (0);
    case 8:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            i = func_80044CD4(D_80010384);
            x = 0;
            j = x;
            D_8021007E = 1;
            D_8021007D = 0xFF;
            D_8021007C = 0xFF;
            D_8021007B = 0xFF;
            D_8021007A = 0xFF;
            do {
                x ^= ((u8 *)0x80210000)[j];
                j++;
            } while (j < 0x7F);
            sz = *(s32 *)(D_8009B444 + i * 0x28 + 0x20);
            D_8021007F = x;
            if (sz < 0) {
                sz += 0x3F;
            }
            func_80044380(z, 0x80210000, sz >> 6);
            return;
        }
        if (D_8009B3D5 == 0) {
            return;
        }
        a = 0xD9;
    msg:
        func_8003D46C(a, 1);
        D_8009B3CC |= 0x400;
        return;
    case 9:
    case 10:
        if (!(D_8009B3CF & 0x80)) {
            D_8009B3CF |= 0x80;
            if (rec[0xC] < g[0x10]) {
                return;
            }
            func_800443EC(z, D_80010384, g[0x10]);
            return;
        }
        if (D_8009B3D5 == 0) {
            func_8008E870(D_80010398);
        }
        func_8008E870(D_800103A4);
        return;
    }
}
