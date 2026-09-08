/* 295/295 -- COMPRIMENTO EXATO -- e **11 diferencas**, censo VAZIO, e das
 * onze SEIS sao numeracao de rotulo. 2026-09-08, escrita do zero hoje:
 * -9/279 -> +2/130 -> 95 -> 89 -> 88 -> 46 -> 11.
 * Flags PADRAO (passo 0: gp=56, at=0, uma jump table jtbl_80010548).
 *
 * FORMA: maquina de estados de retry. `switch ((s8)((u8)D_8009B43E - 1))`
 * com jump table real de 12 entradas, e dentro DOIS `switch (D_8009B44F)`
 * com cases 0/1/2 cujo `case 0` CAI no `case 1`. Ordem dos bracos na
 * memoria: 0/1, 10/11, 2/3, 7, default -- a ordem dos cases na fonte. O
 * corpo do `case 2` esta por extenso nos DOIS switches internos, porque o
 * retail funde a aresta `>= 2` dos dois e escrever a fusao a mao com `goto`
 * e pior nas duas direcoes (99 e 166 contra 95).
 *
 * A ALAVANCA DESTE TICK, e a que vale levar: **O DECREMENTO DO CONTADOR VAI
 * DEPOIS DO TESTE DE SAIDA, NAO ANTES.** Nos tres lacos o retail tem
 * `bne/beq <saida>` com `addiu $s0,-1` no DELAY SLOT dessa mesma
 * instrucao -- o preenchedor puxa do fio de fall-through, ou seja de DEPOIS
 * do desvio. Escrito antes da chamada, antes do teste ou entre o `if`/`else`
 * e o teste, o decremento cai no delay slot do `jal` ou no do `j` do braco
 * `then` (onde o gcc o duplica). Escrito DEPOIS do `if (x) goto ...;` ele
 * cai onde o retail o tem. E semanticamente igual porque `i` esta morto no
 * caminho do `goto`.
 * Os numeros, um laco por vez sobre a base de 88: laco 3 sozinho +1/55,
 * laco 2 sozinho 85, os dois 46 (+1), e o do case 7 fechando **11**.
 * O laco 1 nunca precisou: tem dois argumentos e nenhum literal, e sai
 * exato desde o primeiro rascunho.
 *
 * AS OUTRAS TRES EDICOES (todas regras de func_800577B0, do mesmo dia):
 * 1. **`do { k = 2; } while (0);` no preheader do laco do case 7**, com
 *    `D_8009B450 = k;` depois: -9/279 para +2/130. A funcao tem sete
 *    `D_8009B450 = K;` que terminam todas em [sw $v0,D_8009B450][j tail]; o
 *    `find_cross_jump` compara as instrucoes antes de um salto com as que
 *    precedem FISICAMENTE O ROTULO, e esse bloco e o fim desse laco. No
 *    retail o ultimo store dali e `sw $s4,...` -- registrador DIFERENTE --
 *    e isso sozinho quebra a cadeia (retail cinco stores, nos dois). Sem o
 *    pino, `k = 2;` e byte-identico ao literal, e o pino continua sendo
 *    load-bearing na base atual: tira-lo agora e -9 outra vez.
 * 2. O bloco `func_80073910(h); D_8009B450 = 0;` do case 7 escrito DENTRO
 *    do `if` anterior, DEPOIS do `break`: +2/130 para 295/295 e 95.
 * 3. `func_80073910(h); return 0;` escrito nos TRES caminhos em vez de um
 *    `rel:` compartilhado (regra do func_80030998: o retail compartilha so
 *    `jal`/`nop`/`j`/`addu $v0` e DUPLICA o `addu $a0,$s1,$zero` em cada
 *    predecessor; o tell e o delay slot do `jal` ficar `nop`).
 *
 * MEDIDO E MORTO, COM NUMEROS (nao refazer):
 *  - **O PERMUTER RODOU AQUI (1253 iteracoes, -j 2) E NAO ACHOU NADA**:
 *    zero diretorios `output-*` com `--better-only`. Quinta confirmacao de
 *    que o score dele nao e a contagem, e a primeira vez que ele satura
 *    numa base de comprimento exato e censo vazio;
 *  - o `k = 2;` movido para DENTRO do laco do case 7 (primeira e ultima
 *    instrucao do corpo, com e sem pino): -9, -9, -3, -3. Era a hipotese de
 *    que o `addiu $s4,2` do retail e uma invariante icada pelo passo de
 *    laco, e ela esta FALSIFICADA;
 *  - quatro agrupamentos do `i = 0xA;` com o pino (`do { i = 0xA; k = 2; }`,
 *    `do { k = 2; i = 0xA; }`, um `do { } while (0);` vazio depois, e os
 *    dois pinados separados): 11, 11, 11, 11 -- quatro grafias iguais,
 *    EIXO ERRADO;
 *  - nomear a sentinela -1 do laco do case 7 antes do pino: 12; nomear a
 *    base D_800F2B00: +1/45; as duas: -1/162;
 *  - a FORMA do laco 3 (`for`, `while`, `do/while(1)` com goto): 95, 95, 95;
 *  - os tres lacos como `goto` em vez de `do { } while`: -1/135, -4/280,
 *    -5/278 (perdem as notas NOTE_INSN_LOOP e com elas a icagem);
 *  - o corpo do `case 2` escrito uma vez com `goto`: 99 e 166;
 *  - cinco nomes para as sentinelas de laco: byte-identico ao inline;
 *  - nomear o terceiro argumento (o literal 0) do laco 2, com e sem pino, e
 *    nomear tambem o segundo: 88, 88, 88;
 *  - `do { D_8009B43C = 0x14; } while (0);` no bloco `ok`: 89;
 *  - `k = 2;` sem o pino, e `k = 2;` antes de `i = 0xA;`: -9 os dois;
 *  - `do { k = 2; } while (0);` ANTES de `i = 0xA;`: 13.
 *
 * O QUE FALTA (11 diferencas, censo VAZIO):
 *  a) SEIS sao numeracao de rotulo: um `beq` do `case 2` aponta para um
 *     rotulo nosso que o try_func numera 26 onde o retail numera 5, e dai
 *     para frente todos os numeros andam um. Provavelmente o MESMO endereco
 *     com um rotulo a mais no nosso lado -- mas a build completa ainda
 *     acusa diferenca, entao NAO e so o renderizador;
 *  b) tres sao a ordem do preheader do case 7: o retail tem
 *     `lui $s3,%hi` / `addiu $s2,-1` / `addiu $s4,2` e nos temos o
 *     `addiu $s4,2` primeiro. Ele vem do pino, e todas as reordenacoes do
 *     pino medidas ate agora sao piores;
 *  c) duas sao os alvos `L31/L32` e `L32/L33` do mesmo laco.
 * A build completa foi rodada com o candidato em src/ e reprovou, entao as
 * onze sao reais ou pelo menos uma delas e.
 */
#define D_8009B450_IS_SCALAR
#include "common.h"

s32 func_80044608(void);
void func_80043D48(s32 *arg0);
s32 func_80044470(s32 arg0, s32 arg1, u8 *arg2, s32 *arg3);

s32 func_80044838(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 h;
    s32 mode;
    s32 i;
    s32 r;
    s32 c;
    s32 k;

    if (D_8009B43E < 0) {
        return -1;
    }
    if (arg0 != 0) {
        if (func_8008B380(D_8009B437 != 0) & 0xE) {
            return 0;
        }
    } else {
        func_8008B390(D_8009B437 != 0);
    }
    switch ((s8)((u8)D_8009B43E - 1)) {
    case 0:
    case 1:
        if (func_80044608() < 0) {
            return 0;
        }
        break;

    case 10:
    case 11:
        switch (D_8009B44F) {
        case 0:
            r = func_80044608();
            if (r < 0) {
                return 0;
            }
            if (r != 0) {
                D_8009B450 = 2;
                break;
            }
            D_8009B43C = 0xA;
            D_8009B44F += 1;
        case 1:
            func_80043D48(D_800F2AF0);
            func_8008B370();
            if (D_8009B43E == 0xB) {
                func_8008B360(D_8009B437, D_8009B44C, D_8009B430);
            } else {
                func_8008B350(D_8009B437, D_8009B44C, D_8009B430);
            }
            D_8009B44F += 1;
            return 0;
        case 2:
            if (D_8009B450 != 0) {
                c = D_8009B436 - 1;
                D_8009B436 = c;
                if ((s8)c >= 0) {
                    D_8009B44F = 1;
                    return 0;
                }
            }
            break;
        }
        break;

    case 2:
    case 3:
        switch (D_8009B44F) {
        case 0:
            r = func_80044608();
            if (r < 0) {
                return 0;
            }
            if (r != 0) {
                D_8009B450 = 2;
                break;
            }
            D_8009B436 = 0x14;
            D_8009B44F += 1;
        case 1:
            c = D_8009B43C - 1;
            D_8009B43C = c;
            if ((s8)c < 0) {
                D_8009B450 = 2;
                break;
            }
            mode = 0x8001;
            if (D_8009B43E == 4) {
                mode = 0x8002;
            }
            i = 0xA;
            do {
                h = func_800738D0(D_800F2B00, mode);
                i -= 1;
                if (h != -1) {
                    goto got;
                }
            } while (i >= 0);
            return 0;
        got:
            i = 0xA;
            do {
                r = func_800738E0(h, D_8009B44C, 0);
                if (r != -1) {
                    goto got2;
                }
                i -= 1;
            } while (i >= 0);
            func_80073910(h);
            return 0;
        got2:
            func_80043D48(D_800F2AE0);
            i = 0xA;
            do {
                if (D_8009B43E == 4) {
                    r = func_80073900(h, D_8009B430, D_8009B434);
                } else {
                    r = func_800738F0(h, D_8009B430, D_8009B434);
                }
                if (r == 0) {
                    goto ok;
                }
                i -= 1;
            } while (i >= 0);
            func_80073910(h);
            return 0;
        ok:
            D_8009B43C = 0x14;
            D_8009B44F += 1;
            func_80073910(h);
            return 0;
        case 2:
            if (D_8009B450 != 0) {
                c = D_8009B436 - 1;
                D_8009B436 = c;
                if ((s8)c >= 0) {
                    D_8009B44F = 1;
                    return 0;
                }
            }
            break;
        }
        break;

    case 7:
        switch (D_8009B44F) {
        case 0:
            r = func_80044608();
            if (r < 0) {
                return 0;
            }
            if (r != 0) {
                D_8009B450 = 2;
                break;
            }
            if (D_8009B438 + D_8009B434 >= 0x10) {
                D_8009B450 = 7;
                break;
            }
            if (func_80044470(D_8009B437, (s32)D_800F2B00, (u8 *)D_8009B444, (s32 *)0) != 0) {
                D_8009B450 = 6;
                break;
            rel7:
                func_80073910(h);
                D_8009B450 = 0;
                break;
            }
            D_8009B43C = 0xA;
            D_8009B44F += 1;
        case 1:
            i = 0xA;
            do { k = 2; } while (0);
            do {
                h = func_800738D0(D_800F2B00, (D_8009B434 << 16) | 0x200);
                if (h != -1) {
                    goto rel7;
                }
                i -= 1;
            } while (i >= 0);
            c = D_8009B43C - 1;
            D_8009B43C = c;
            if ((s8)c > 0) {
                return 0;
            }
            D_8009B450 = k;
            break;
        }
        break;
    }
    *arg2 = D_8009B450;
    *arg1 = D_8009B43E;
    D_8009B43E = -1;
    return 1;
}
