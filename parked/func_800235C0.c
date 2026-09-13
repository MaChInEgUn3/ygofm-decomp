/* 466/466 com excesso de 1 no censo (j +1, nop -1), 2026-09-13. Escrita
 * do zero. FLAGS: padrao (-quiet -O2 -G8). Listagem gp=42, at=0.
 *
 * update_active_move_record no transplante do Unchiga (STUB la);
 * unmatched_asm sem nota e sem PR no krystalgamer.
 *
 * LEVERS, cada um medido sobre o anterior (try_func: comprimento, censo,
 * adiff):
 *  1. corpo inteiro dentro de `if (f != 0) { ... return busy; }` e
 *     `return 0;` no fim: o 0 vai direto para $v0 no slot do beqz e o
 *     epilogo e um so. `return 0` antecipado da -4; um acumulador `ret`
 *     da -3 e prende o zero em $s0.
 *  2. nos dois lacos `% 15`, o indice como giv (`t = D_801A7AD8 + i*0x1C`,
 *     `g = D_8015C424 + i*0x1C`) e o 0x48000 somado num segundo nome
 *     (`h = g + 0x48000; *(h + 0x36B4)`). Com o 0x48000 no mesmo `+` ele
 *     entra no giv; com cursores explicitos as inits saem antes das
 *     constantes. Os dois lacos casam por inteiro.
 *  3. `a = i * 0x3C + 0xE;` num nome antes da soma: o giv inclui o 0xE.
 *     +1 -> exato.
 *  4. indice de D_800907AC somado como inteiro, com a base por ultimo.
 *  5. `do { busy = 1; } while (0);` no bloco 0x40.
 *  6. `*(volatile s16 *)&D_8009B204 != 0` no teste: o alvo le `lh` para o
 *     teste e `lhu` para `n`; sem o volatile as duas leituras viram uma.
 *  7. `n <<= 16; if (n == 0)`: o sll no proprio registrador. Com 6, +1 ->
 *     exato e o excesso cai de 2 para 1.
 *
 * MEDIDO E PIOR OU NEUTRO: retorno `s8` (excesso 3); `off = 0x48000`
 * local (entra no giv, +1); base local `bb = D_8015C424` (+1); leitura
 * `*(u16 *)&D_8009B204` para n (troca o lhu que falta por um lh).
 *
 * RESIDUO: um `j` a mais e um `nop` a menos no censo; a copia
 * `moving = busy` sai cedo em $t0 onde o alvo a poe em $s1 no slot do
 * bltz/bgez; ordem dos argumentos da func_80040410.
 */
#include "common.h"

u8 *func_80018150(s32 arg0, s32 arg1);
void func_80022FF0(u8 *arg0, s32 arg1);
void func_8002348C(u8 *arg0);
void func_800234E4(u8 *arg0);
u8 *func_80042B40(s32 arg0);
void func_80043230(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80022674(u8 *p);
void func_800229F4(u8 *p);

s32 func_800235C0(void)
{
    u8 *rec;
    u8 *pos;
    u8 *o;
    u8 *t;
    u8 *g;
    u8 *h;
    s32 busy;
    s32 moving;
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 n;
    s32 ret;
    u16 f;

    f = D_8009B162;
    rec = D_8009B1B4;
    pos = D_800F2848;
    if (f != 0) {
    busy = 0;
    if (!(f & 0x8000)) {
        f |= 0x8000;
        D_8009B162 = f;
        if (f & 1) {
            func_80022D94(0x10, 0x14E, 0x3FE, D_8009AF20[D_8009B1D5],
                          *(s16 *)((u8 *)((s8)rec[0x10] * 2 + rec[0x18] * 8 + D_8009B1D5 * 16 + (s32)D_800907AC)));
        }
        if (D_8009B162 & 4) {
            func_80022D94(0x10, 0x258, 0x100, D_8009AF20[D_8009B1D5], 0);
            i = 5;
            func_8004036C(*(s32 *)(rec + 4));
            *(s32 *)(rec + 4) = 0;
            for (; i < 0x1E; i++) {
                if (i % 15 >= 5 && (t = D_801A7AD8 + i * 0x1C, *(u16 *)(t + 0x16) & 0x8000)) {
                    g = D_8015C424 + i * 0x1C;
                    h = g + 0x48000;
                    o = *(u8 **)(h + 0x36B4);
                    o[0x6C] = 1;
                    *(s16 *)(o + 0x60) = 4;
                    *(s32 *)(o + 0x24) = (s32)func_800229F4;
                }
            }
            D_8009B162 |= 0x4000;
        }
        if (D_8009B162 & 2) {
            o = func_80018150(0, 0xF0);
            a = rec[0x13];
            rec[0x16] = 0x24;
            if (a != 0) {
                func_80040410(o, a);
                rec[0x16] = 7;
            }
            func_800428EC(o, (s8)(-(rec[0x17] * 2) - 2));
            *(s16 *)(o + 0x28) = 0;
            *(s16 *)(o + 0x2A) = *(u16 *)(rec + 0xC);
            func_80043178(o);
            *(s16 *)(o + 0x60) = -0x400;
            o[0x6C] = 2;
            *(u8 **)rec = o;
            if (*(s32 *)(rec + 8) != 0) {
                for (i = 0; i < 5; i++) {
                    t = *(u8 **)(i * 0xC + *(s32 *)(rec + 8));
                    if (t != 0) {
                        a = i * 0x3C + 0xE;
                        *(s16 *)(t + 0x30) = *(u16 *)(o + 0x30) + a;
                        *(s16 *)(*(u8 **)(i * 0xC + *(s32 *)(rec + 8)) + 0x32) = *(u16 *)(o + 0x32) - 0x1C;
                    }
                }
            }
            func_80022FF0(rec, 0);
        }
        if (D_8009B162 & 8) {
            o = *(u8 **)rec;
            *(s16 *)(o + 0x2A) = 0xF0;
            *(s16 *)(o + 0x28) = *(u16 *)(o + 0x30);
            func_80043178(o);
            *(s16 *)(o + 0x60) = 0x400;
            o[0x6C] = 2;
            func_80022FF0(rec, 1);
        }
        busy = 0;
    }
    moving = busy;
    if (D_8009B162 & 0x40) {
        o = *(u8 **)(rec + 4);
        if (*(s16 *)(o + 0x60) != 0) {
            a = ((*(s16 *)(o + 0x28) << 8) | o[0x62]) + *(s16 *)(o + 0x36);
            o[0x62] = a;
            *(s16 *)(o + 0x28) = a >> 8;
            a = ((*(s16 *)(o + 0x2A) << 8) | o[0x64]) + *(s16 *)(o + 0x3A);
            *(s16 *)(o + 0x2A) = a >> 8;
            o[0x64] = a;
            c = *(u16 *)(o + 0x60) - 1;
            *(s16 *)(o + 0x60) = c;
            do {
                busy = 1;
            } while (0);
            if ((s16)c <= 0) {
                busy = 0;
                *(s16 *)(o + 0x60) = 0;
                *(s32 *)(o + 0x28) = *(s32 *)(o + 0x2C);
            }
        }
    }
    o = *(u8 **)rec;
    if ((D_8009B162 & 2) && o[0x6C] != 0) {
        busy = 1;
        func_80043230(o, *(s16 *)(o + 0x28), *(s16 *)(o + 0x2A), *(s16 *)(o + 0x60));
        c = *(u16 *)(o + 0x60) + 0x40;
        *(s16 *)(o + 0x60) = c;
        moving = busy;
        if (!((s16)c < 0)) {
            o[0x6C] = 0;
            *(s32 *)(o + 0x30) = *(s32 *)(o + 0x28);
        }
    }
    if ((D_8009B162 & 8) && o[0x6C] != 0) {
        busy = 1;
        func_80043230(o, *(s16 *)(o + 0x28), *(s16 *)(o + 0x2A), *(s16 *)(o + 0x60));
        c = *(u16 *)(o + 0x60) - 0x40;
        *(s16 *)(o + 0x60) = c;
        moving = busy;
        if ((s16)c < 0) {
            func_80035B7C((u8 *)&D_800EB0F8[rec[0x14]]);
            func_8004036C((s32)o);
            *(u8 **)rec = 0;
            if (*(s32 *)(rec + 8) != 0) {
                for (i = 0; i < 5; i++) {
                    func_8004036C(*(s32 *)(i * 0xC + *(s32 *)(rec + 8)));
                    *(s32 *)(i * 0xC + *(s32 *)(rec + 8)) = 0;
                    func_8004036C(*(s32 *)(i * 0xC + *(s32 *)(rec + 8) + 4));
                    *(s32 *)(i * 0xC + *(s32 *)(rec + 8) + 4) = 0;
                }
            }
            o[0x6C] = 0;
            moving = 0;
        }
    }
    if (moving != 0) {
        func_80039934((u8 *)&D_800EB0F8[rec[0x14]], *(s16 *)(o + 0x30) + 0x10,
                      *(s16 *)(o + 0x32) + (s8)rec[0x16]);
    }
    if (D_8009B162 & 0x4000) {
        busy = 1;
        if (func_80042B40(busy) != 0) {
            return busy;
        }
        D_8009B162 &= 0xBFFF;
    }
    n = D_8009B204 - 1;
    if (*(volatile s16 *)&D_8009B204 != 0) {
        busy = 1;
        D_8009B204 = n;
        a = D_8009B1C4 + D_8009B1FC;
        b = D_8009B15C + D_8009B198;
        D_8009B1C4 = a;
        D_8009B15C = b;
        *(s16 *)pos = a >> 16;
        *(s16 *)(pos + 4) = b >> 16;
        c = D_8009B158 + D_8009B194;
        d = D_8009B224 + D_8009B168;
        D_8009B158 = c;
        D_8009B224 = d;
        *(s16 *)(pos + 2) = c >> 16;
        *(s32 *)(pos + 0x24) = d >> 16;
        n <<= 16;
        if (n == 0) {
            *(s16 *)pos = D_8009B1EE;
            *(s16 *)(pos + 4) = D_8009B192;
            *(s16 *)(pos + 2) = D_8009B190;
            *(s32 *)(pos + 0x24) = D_8009B166;
            if (D_8009B162 & 1) {
                for (i = 5; i < 0x1E; i++) {
                    if (i % 15 >= 5 && (t = D_801A7AD8 + i * 0x1C, *(u16 *)(t + 0x16) & 0x8000)) {
                        g = D_8015C424 + i * 0x1C;
                        h = g + 0x48000;
                        o = *(u8 **)(h + 0x36B4);
                        o[0x6C] = 1;
                        *(s16 *)(o + 0x60) = 4;
                        *(s32 *)(o + 0x24) = (s32)func_80022674;
                    }
                }
                D_8009B162 |= 0x4000;
            }
        }
        func_8001352C();
    }
    if (busy == 0) {
        if (D_8009B162 & 1) {
            func_800234E4(rec);
            func_8002348C(rec);
        }
        D_8009B162 = 0;
    }
    return busy;
    }
    return 0;
}
