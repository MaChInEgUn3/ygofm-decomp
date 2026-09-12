/* 331 contra 341 (-10), 2026-09-12. Segunda volta. Flags PADRAO.
 * Escrita do zero; e a menor funcao limpa do pool desde que o piso subiu
 * para 250 instrucoes.
 *
 * FORMA, lida da listagem: maquina de estados no byte +0xE14 de um registo
 * de 0xE20 indexado por arg0. Dois rotulos de saida distintos e sao eles que
 * decidem a estrutura -- .L80056D54 e o EPILOGO (estados 0 e 0xFF retornam
 * sem fazer nada) e .L80056D18 e a CAUDA COMUM de toda a gama 1..0xB, com o
 * log e o avanco de estado. Jump table real, jtbl_8001170C, com
 * `sltiu $v0,$v1,0xB` sobre `state - 1`.
 *
 * A cauda e a regra do delay slot: `addiu $v0,$zero,0xFF` no slot do `bnez`
 * com o fall-through a sobrepor -- atribuicao incondicional seguida de
 * condicional, nao dois bracos.
 *
 * GANHO DESTA VOLTA (-17 -> -10): o case 7 e um SWITCH de tres casos, nao a
 * cadeia if/else-if que eu tinha escrito. O retail tem a arvore de
 * comparacao que o gcc gera para tres casos -- pivo em 0x3C, depois
 * `< 0x3D` a escolher a subarvore, depois 0x23 ou 0x3E -- e nenhuma cadeia
 * a produz. Vale SETE instrucoes. As tres ordens de caso dao o mesmo, entao
 * a ordem nao entra.
 *
 * BUG CORRIGIDO, e o modo como aparece e a licao: o case 8 usava `p` sem o
 * atribuir, herdando o que o case 7 tivesse deixado. A correcao custa
 * EXATAMENTE ZERO instrucoes (331 com e sem), e e por isso que passou
 * despercebida -- a contagem nao ve erro de leitura, so o m2c e a listagem.
 *
 * MEDIDO E MORTO nesta volta, sobre o `lui -5`: o alvo materializa
 * %hi(D_800F2C40) CINCO vezes e nos uma. Tres tentativas, todas piores --
 * um local por caso (-11, uma pior), a expressao inteira inline nos quatro
 * casos (+45, porque recomputa a cadeia sll/subu/sll/addu/sll da
 * multiplicacao), e um local so para o deslocamento com o simbolo inline
 * (+5, e o censo passa a sll -12 / addu +11). O alvo partilha a
 * multiplicacao e NAO partilha o simbolo, e nenhuma das tres formas obvias
 * faz as duas coisas.
 *
 * CENSO ATUAL: lui -5, beq -3, addu -3, addiu -2, j -2, sh -1, slt -1,
 * bne +1, blez +1, lw +1, andi +3.
 * FLAGS MEDIDAS (2026-09-12): sweep_try, 29 linhas. A melhor por CONTAGEM
 * e -O1 -G0 com 304, e ela chega a 341/341, COMPRIMENTO EXATO -- o que
 * parece um achado e NAO e. Controle: tres funcoes que JA CASAM em -O2,
 * recompiladas em -O1 -G0, ficam mais longas (147->148, 173->178, 77->79),
 * ou seja o -O1 acrescenta cerca de 3%. Tres por cento de 331 e DEZ, que e
 * exatamente o deficit -- o zero sao duas faltas a cancelar-se. A base
 * continua em -O2 -G8 e o trabalho continua na FONTE.
 * Nenhuma outra linha da varredura acerta o comprimento: -O1 -G8 e -4,
 * -O2 -G0 e -6, -O2 -G0 -fno-strength-reduce e -6.
 * TERCEIRA VOLTA (-10 -> -6), duas coisas e ambas lidas do alinhamento:
 *  1. o despacho INTERNO do case 1 tambem e um `switch (arg0)` e nao a
 *     cadeia if/else-if -- o alvo tem `beq $s0,$zero` e nos tinhamos
 *     `bne`, que e a polaridade que uma cadeia produz. Vale duas
 *     instrucoes;
 *  2. D_80010000, D_80010004 e D_80010008 saem no alvo com `lui %hi` /
 *     `lw %lo` e em nos saiam `lw` GP-RELATIVO, porque o escalar simples e
 *     small data a -G8. Com o braco agregado nos tres, mais duas.
 *     D_80010004 nao estava declarado em variables.h e D_80010008 so tinha
 *     a forma escalar; os dois ganharam braco _IS_AGGREGATE guardado, e o
 *     build completo continua a fechar, logo nenhum outro consumidor mexe.
 * QUARTA VOLTA, E E UM RECUO DELIBERADO DE -6 PARA -10.
 * A largura dos locais foi varrida -- 22 combinacoes -- e QUATRO chegam a
 * 341/341, comprimento EXATO. Nenhuma foi instalada, porque o censo diz o
 * que elas sao: cada estreitamento acrescenta `andi`, e a serie e
 * +3 (base) -> +6 -> +8 -> +9 nas de comprimento exato. Ou seja, o zero e
 * comprado com NOVE mascaras que o alvo nao tem. E o mesmo falso zero do
 * -O1 -G0 que este ficheiro ja documenta, por outro caminho.
 * A direcao honesta e a oposta: com TODOS os locais em s32 as mascaras
 * desaparecem (andi 0) e sobram DEZ opcodes, todos em DEFICIT e nenhum em
 * excesso -- addiu -2, lui -2, sh -1, j -1, sw -1, slt -1, addu -1, beq -1,
 * bne -1, e um unico blez +1. Isso e uma lista de compras, e e melhor estado
 * de diagnostico do que -6 com tres mascaras espurias a mascarar parte do
 * deficit.
 * QUINTA VOLTA (-10 -> -9), e fecha o eixo dos simbolos: D_8001000C e
 * D_80010010 tambem saiam GP-RELATIVOS em nos e com `lui %hi` no alvo,
 * pelo mesmo motivo dos outros tres. Com os bracos agregados, a contagem
 * de %hi por simbolo passa a bater EXATAMENTE em todos -- D_800F2C40 cinco
 * vezes, e uma vez cada para D_80010000, D_80010004, D_80010008,
 * D_8001000C, D_80010010, D_80011594 e D_801A8000, mais o gp-relativo de
 * D_8009AFA0. Nenhum simbolo divergente sobra, e `lui` saiu do censo.
 * CENSO ATUAL, dez opcodes e comprimento -9: addiu -2, nop -1, sw -1,
 * bne -1, slt -1, beq -1, sh -1, j -1, addu -1, e um blez +1. O par
 * blez +1 / slt -1 cheira a uma comparacao escrita como `<= 0` onde o alvo
 * tem `<` contra outra coisa; e o proximo a olhar.
 * NAO MEDIDO: permuter.
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
            if (n > 0) {
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
            break;
        case 0x23:
            func_8005A468(arg0, 0);
            break;
        case 0x3E:
            func_8005A468(arg0, n);
            break;
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

    func_8008E870(D_80011594, rec[0xE14], func_80074170(1) - t0);
    v = 0xFF;
    if (rec[0xE1F] == 0) {
        v = rec[0xE14] + 1;
    }
    rec[0xE14] = v;
}
