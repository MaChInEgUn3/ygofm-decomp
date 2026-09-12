/* -4 (337/341), 2026-09-12. Flags PADRAO. Escrita do zero; menor funcao
 * limpa do pool desde que o piso subiu para 250 instrucoes.
 *
 * FORMA: maquina de estados no byte +0xE14 de um registo de 0xE20 indexado
 * por arg0, com jump table real (jtbl_8001170C) sobre `state - 1`. Dois
 * rotulos de saida decidem tudo: .L80056D54 e o EPILOGO, para onde 0 e 0xFF
 * saltam sem fazer nada, e .L80056D18 e a CAUDA COMUM de 1..0xB. A cauda e a
 * regra do delay slot -- `addiu $v0,$zero,0xFF` no slot do `bnez` com o
 * fall-through a sobrepor, logo atribuicao incondicional seguida de
 * condicional.
 *
 * TRAJETO: -17 -> -10 -> -6 -> -10 (recuo deliberado) -> -9 -> -8 -> -4.
 *
 * OS LEVERS, por ordem de ganho:
 *  1. o case 7 e um SWITCH de tres casos e nao uma cadeia if/else-if; o
 *     retail tem a arvore que o gcc gera para tres casos (pivo 0x3C, depois
 *     `< 0x3D`, depois 0x23 ou 0x3E). Sete instrucoes;
 *  2. os TRES bracos desse switch interno alcancam a cauda com `goto`
 *     explicito e nao com `break`. Quatro instrucoes. O permuter chegou ao
 *     mesmo numero por um `if (arg0)` com os dois bracos IDENTICOS, que e
 *     grafia que ninguem escreve; o `goto` da o mesmo e le-se como fonte.
 *     Medido por partes: so o 0x23 e -6, o 0x23 mais o 0x3E e -5, so o 0x3C
 *     e -6, e os tres e -4;
 *  3. os cinco ponteiros D_80010000/04/08/0C/10 precisam do braco AGREGADO:
 *     o escalar simples e small data a -G8 e sai `lw` gp-relativo, onde o
 *     retail tem `lui %hi`/`lw %lo`. Quatro instrucoes ao todo, e depois
 *     disso a contagem de %hi por simbolo bate EXATAMENTE em todos;
 *  4. a guarda do laco do case 4 compara contra o CONTADOR: `while (i < n)`
 *     e nao `if (n > 0)` com do/while. Uma instrucao, e tira o par
 *     blez/slt do censo.
 *
 * MEDIDO E MORTO:
 *  - largura dos locais: 22 combinacoes, quatro chegam a comprimento EXATO e
 *    NENHUMA foi instalada, porque cada estreitamento acrescenta `andi` e a
 *    serie e +3 -> +6 -> +8 -> +9. O zero e comprado com nove mascaras que o
 *    alvo nao tem. Todos os locais em s32 e a forma honesta;
 *  - flags: sweep_try, 29 linhas. -O1 -G0 chega a 341/341 e e FALSO -- tres
 *    funcoes que ja casam em -O2 ficam 1, 5 e 2 instrucoes mais longas em
 *    -O1 -G0, ou seja ~3%, e 3% de 331 e exatamente o deficit de entao;
 *  - a copia do valor do switch (`addu $v0,$v1,$zero` no alvo): quatro
 *    grafias empatam, o gcc coalesce toda copia de nivel de fonte;
 *  - o endereco do registo: um local por caso e -11, a expressao inline nos
 *    quatro casos e +45, um local so para o deslocamento e +5. O alvo
 *    partilha a multiplicacao e nao partilha o simbolo.
 *
 * CENSO ATUAL: ver o commit; sao quatro instrucoes em falta e o excesso e
 * pequeno. NAO MEDIDO ainda: o permuter a partir DESTA base.
 */
#define D_80010000_IS_AGGREGATE
#define D_8001000C_IS_AGGREGATE
#define D_80010010_IS_AGGREGATE
#define D_80010004_IS_AGGREGATE
#define D_80010008_IS_AGGREGATE
#include "common.h"

extern u8 D_80011594[];

void func_8005A468(s32, s32);
void func_8004DC38(u8 *, s32, s32, s32);

void func_80056828(s32 arg0) {
    u8 *rec;
    u8 *p;
    u8 **q;
    s32 t0;
    s32 st;
    s32 i;
    s32 n;
    s32 sum;
    s32 d;
    s32 v;
    s32 a;
    s32 c;
    s32 w;
    void (*fp)(s32, s32, s32);

    rec = arg0 * 0xE20 + D_800F2C40;
    t0 = func_80074170(1);
    st = rec[0xE14];
    if (st == 0 || st == 0xFF) {
        return;
    }

    switch (st) {
    case 1:
        a = D_80010008[0];
        v = 0xC000;
        switch (arg0) {
        case 0:
            a = (s32)D_80010000[0];
            break;
        case 1:
            a = (s32)D_80010004[0];
            break;
        }
        if (*(s32 *)a != 0) {
            v = *(s32 *)a;
        }
        func_8004CB0C(arg0, (u8 *)a, v, -1);
        break;
    case 2:
        func_8004D75C(arg0);
        break;
    case 3:
        func_8004D914(arg0);
        break;
    case 4:
        p = arg0 * 0xE20 + D_800F2C40;
        sum = 0;
        if (arg0 < 2) {
            n = p[0xE1B];
            i = 0;
            while (i < n) {
                do {
                    if (*(u16 *)(p + i * 8 + 0x33C) != 0xFFFF) {
                        d = i / 8;
                        if ((p[d + 0xBEC] >> (i - d * 8)) & 1) {
                            sum += 0x14;
                        } else {
                            sum += 0xC;
                        }
                    }
                    i++;
                } while (i < n);
            }
        }
        v = *(s32 *)(p + 0xDE0) + sum;
        *(s32 *)(p + 0xDF0) = v;
        *(s32 *)(p + 0xDF4) = v + *(u16 *)(p + 0xE02) * 4;
        func_8005A4C4(p, 0, 0, 0);
        break;
    case 5:
        p = arg0 * 0xE20 + D_800F2C40;
        q = (u8 **)(p + 0x1E0);
        i = 0;
        if (p[0xE1B] != 0) {
            do {
                *(u16 *)(q[0] + 8) = 0xFFFF;
                *(u16 *)(q[0] + 0x16) = *(u16 *)(q[0] + 0x18);
                *(u16 *)(q[0] + 0xA) = 0xFFFF;
                q[0][0xC] = q[0][0x1A];
                *(s32 *)(q[0] + 0x10) = 0;
                i++;
                q[0][0xD] = 0x10;
                q += 4;
            } while (i < (s32)p[0xE1B]);
        }
        break;
    case 6:
        rec[0xE1F] = 1;
        func_800590DC(arg0);
        rec[0xE1F] = 0;
        break;
    case 7:
        p = arg0 * 0xE20 + D_800F2C40;
        c = p[0xE16];
        n = *(u8 *)(p + 0xE0D) * 2;
        switch (c) {
        case 0x3C:
            func_8005A468(arg0, -n);
            goto tail56828;
        case 0x23:
            func_8005A468(arg0, 0);
            goto tail56828;
        case 0x3E:
            func_8005A468(arg0, n);
            goto tail56828;
        }
        if (arg0 >= 2) {
            rec[0xE1F] = 1;
        }
        break;
    case 8:
        func_800582C0(arg0, rec[0xE0C], *(u16 *)(rec + 0xE0A));
        break;
    case 9:
        p = arg0 * 0xE20 + D_800F2C40;
        v = *(s32 *)(p + 0xDE8);
        D_8009AFA0 = arg0;
        if (*(s32 *)(p + 0xD10) >= 0) {
            if (arg0 != 0) {
                fp = (void (*)(s32, s32, s32))(D_80010010[0] + 4);
            } else {
                fp = (void (*)(s32, s32, s32))(D_8001000C[0] + 4);
            }
            func_8005F198(1);
            fp(v, *(s32 *)(p + 0xD10) % 1000, *(s32 *)(p + 0xD10));
            func_8005F198(0);
        }
        c = p[0xBF5];
        p[0xE0E] = 6;
        w = *(u16 *)(p + 0xE06);
        i = 0;
        if (p[0xE1B] != 0) {
            do {
                a = p[0xBF5];
                if (c != 0) {
                    a = c;
                    (*(u8 **)(p + i * 16 + 0x1E0))[0xC] = c;
                }
                func_8004DC38(p, i, a, w);
                i++;
            } while (i < (s32)p[0xE1B]);
        }
        if (c != 0) {
            p[0xBF5] = c;
        }
        break;
    case 0xA:
        if (rec[0xE1D] == 0) {
            func_80048D08(arg0, (arg0 << 0xB) + D_801A8000);
        }
        break;
    case 0xB:
        if (rec[0xE1D] == 0) {
            rec[0xE1E] = 1;
        }
        rec[0xE1F] = 1;
        break;
    }

tail56828:
    func_8008E870(D_80011594, rec[0xE14], func_80074170(1) - t0);
    v = 0xFF;
    if (rec[0xE1F] == 0) {
        v = rec[0xE14] + 1;
    }
    rec[0xE14] = v;
}
