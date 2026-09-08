/* 240/240 -- COMPRIMENTO EXATO -- e 9 diferencas, em DOIS grupos
 * (2026-09-08). Flags PADRAO (passo 0: gp=27, at=0, SEM jump table).
 * Veio de 199 -> 38 -> 9 no mesmo dia.
 *
 * FORMA: rotina de SETUP de tela -- 32 chamadas a 25 callees distintos,
 * zeragem de nove globais, dois objetos criados por
 * `func_800400AC(func_8004002C(), N)` e configurados, e um bloco final que
 * escolhe um par de buffers.
 *
 * AS CINCO ALAVANCAS, na ordem em que foram medidas:
 *
 * 1. **D_8009B361 e D_8009B364 NA FORMA NUA (`_IN_DATA`), que e o que tira
 *    o callee-saved a mais.** O retail materializa `%hi(D_8009B361)`
 *    QUATRO vezes e `%hi(D_8009B364)` DUAS, cada uma no seu registrador e
 *    nenhuma compartilhada; com o braco de array (o par proprio do cc1psx)
 *    o gcc faz CSE de um `%hi` para dentro de $s3, a funcao salva $s0-$s3
 *    contra os $s0-$s2 do retail e a moldura vai a 56 bytes. Com o
 *    atributo de secao a referencia e UMA pseudo-instrucao, nao ha o que
 *    compartilhar, e o prologo casa exatamente: 199 -> 135. Medido: so
 *    B361 136, B361+B369 136, B361+B364 **135**, os quatro (com
 *    D_8009B360) +1 e 164.
 *
 * 2. **`e = D_800EA0E8;` escrito DEPOIS de `func_8001352C()`.** O par
 *    `lui`/`addiu` de D_800EA0E8 e partido pelo escalonador e cada metade
 *    cai no delay slot de uma chamada DIFERENTE. Varredura 2D de 20 pontos
 *    (5 posicoes de `e` x 4 de `hun`): e0 135, e1 127, e2 127, e3 239/148,
 *    e4 238/70. **A posicao de `hun` nao vale NADA** -- as quatro dao o
 *    mesmo numero em cada linha, que e a assinatura de eixo errado.
 *
 * 3. **0x100 e 0xB em DOIS NOMES, nao um.** Contradiz a leitura original
 *    (a regra "duas constantes sequenciais no mesmo registrador sao um
 *    nome so"): o retail POE as duas em $s1 e mesmo assim a fonte tinha
 *    dois nomes -- com um nome so o pseudo de 0x100 rouba $s1 do ponteiro
 *    `o` e o 256 e materializado tres chamadas cedo. 70 -> 41. A regra
 *    vale quando o retail materializa a segunda constante NO registrador
 *    que a primeira acabou de vagar; aqui as duas vidas nem se tocam.
 *
 * 4. **D_8009B360 e um `-1` sobre o ENDERECO de D_8009B361** (41 -> 38).
 *
 * 5. **E esse endereco tem que ser atribuido ANTES do desvio.** O retail
 *    le D_8009B360 com TRES instrucoes -- `lui %hi(D_8009B361)` / `addiu
 *    %lo(D_8009B361)` / `lb -1($v0)` -- e o cc1psx dobra o -1 dentro do
 *    `%lo` em TODA grafia escrita no mesmo bloco basico: oito medidas,
 *    todas exatamente 239/38 (eixo errado). Uma sonda de seis linhas pelo
 *    cc1psx mostra o mecanismo: o gcc 2.8 nao tem CSE global, entao um
 *    `p = &A;` num bloco e um `p[-1]` em OUTRO nao podem ser dobrados e
 *    saem `la` + `lb -1($2)`. `p = &D_8009B361;` escrito acima do
 *    `if (D_8009B369[0] != 1)` e 38 -> 9 e devolve o comprimento exato.
 *    As tres posicoes medidas (topo da funcao, antes do store de
 *    D_800E9DBC, colada no `if`) dao 9 -- o que importa e so estar em
 *    outro bloco.
 *
 * O QUE FALTA -- DOIS GRUPOS, so alocacao e escalonamento:
 *  - o retail materializa `lui %hi(func_800164FC)` ANTES do
 *    `lw D_8009B21C` e completa o par com `addiu %lo` DEPOIS dele, isto e,
 *    parte o par do endereco da funcao em volta do load; nos partimos o de
 *    D_800E9DBC. Medido e morto: um local `cb` para o ponteiro de funcao,
 *    antes e depois do store (9 e 9 -- o gcc propaga a constante), um
 *    local `w` para a leitura de D_8009B21C (9), e trocar as duas linhas
 *    (11). Um `do { } while (0);` em volta do store e +1 e 45;
 *  - `lui $a0,%hi(D_801D1200)` / `addiu $a0,$a0,%lo` no retail, contra
 *    `lui $v0` / `addiu $a0,$v0` nosso: mesmo par, registrador
 *    intermediario diferente. Medido e morto: mover o store de
 *    D_8009B1D8 para o meio (9), escrever `b` a partir do simbolo em vez
 *    de `a` (10), e atribuicoes encadeadas (9).
 *
 * DUAS LEITURAS DO LISTING QUE O RASCUNHO DO M2C NAO DAVA (ainda validas):
 *  - **`sllv $a2,$v0,$s0` prova que o deslocamento e uma VARIAVEL.** O
 *    retail poe 1 em $s0 e o usa DUAS vezes: na comparacao
 *    `D_8009B369 != 1` e como amount do shift que faz `x * 3`;
 *  - D_8009B369, lido `lui %hi`/`lbu %lo`, usa o BRACO DE ARRAY.
 * Tres declaracoes novas em variables.h: D_8009B1D8, D_8009B1DC e
 * D_8009B21C, os tres ponteiros gp-relativos que esta rotina grava.
 */
#define D_8009B361_IN_DATA
#define D_8009B364_IN_DATA
#include "common.h"

void func_800164FC(void);
void func_80016E70(void);

void func_800179F4(void) {
    u8 *e;
    u8 *o;
    s32 one;
    s32 hun;
    s32 elv;
    s32 sgn;
    s8 *p;

    func_8004763C();
    func_80047AD0(1);
    func_80012D84(4);
    one = 1;
    func_800137E4();
    func_80014E1C(0, 0, D_8009B364 * 0xEB + 0x16C6, 0xEB, func_800171A8, 0, 0);
    func_800137E4();
    D_8009B238 = -1;
    D_8009B23A = 0xB;
    D_8009B164 = 0;
    D_8009B162 = 0;
    D_8009B1D4 = 0;
    D_8009B204 = 0;
    D_8009B220 = 0;
    D_8009B16C = 0;
    D_8009B174 = 0;
    if (D_8009B369[0] != one) {
        if (D_8009B361 >= 0) {
            func_80014E1C(0, 0, (D_8009B361 << one) + D_8009B361 + 0x1D33, 3, 0, 0, D_801781D8);
        }
        D_8009B1D5 = 0;
        D_8009B23A = one;
        func_8001778C();
        func_80017708();
        func_800175A0();
        D_8009B16C |= 0x1000;
    }
    D_8009B1C8 = (u8 *)&D_800E9FF0[D_8009B1D5];
    func_800178BC();
    D_800F284A[0] = (D_8009B1D5 << 11) + 0x400;
    func_8001352C();
    e = D_800EA0E8;
    hun = 0x100;
    func_800176D0();
    func_8002C598();
    func_80029574(0);
    *(s16 *)(e + 0x28) = 0;
    *(s16 *)(e + 0x2A) = hun;
    *(s16 *)(e + 0x2C) = 0;
    *(s16 *)(e + 0x2E) = 0xFF;
    func_80029574(1);
    *(s16 *)(e + 0x68) = 0x40;
    *(s16 *)(e + 0x6A) = hun;
    *(s16 *)(e + 0x6C) = 0;
    *(s16 *)(e + 0x6E) = 0xFE;
    func_80035668(0);
    elv = 0xB;
    func_8001755C();
    func_800137E4();
    D_8009B22C = &D_800907D8[D_8009B1D5 * 0x14];
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0xC, 0x18, 4, 2, D_8009B364, elv, 0x2DC);
    func_80042918(o);
    *(u16 *)(o + 8) = *(u16 *)(o + 8) | 8;
    D_8009B214 = o;
    sgn = (u32)D_8009B361 >> 31;
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0x118, 0x20, 4, sgn, 0, elv, 0x2EC);
    func_80042918(o);
    *(u16 *)(o + 8) = *(u16 *)(o + 8) | 8;
    if (D_8009B1D5 != 0) {
        *(u16 *)(o + 0x40) = *(u16 *)(o + 0x40) + 0x10;
    }
    D_8009B21C = o;
    o = func_800400AC(func_8004002C(), 6);
    func_80042918(o);
    func_800428EC(o, 1);
    *(s32 *)(o + 0x4C) = (s32)func_80016E70;
    *(s32 *)(o + 0x50) = (s32)D_8009B21C;
    D_800E9DBC[0] = func_800164FC;
    p = &D_8009B361;
    if (D_8009B369[0] != 1) {
        u8 *a;
        u8 *b;
        D_8009B1DC = (u8 *)0;
        D_8009B1D8 = (u8 *)0;
        a = (u8 *)0;
        if (p[-1] < 0) {
            if (D_8009B361 < 0) {
                a = D_801D1200;
                b = a + 0x1000;
                D_8009B1D8 = a;
                D_8009B1DC = b;
            } else {
                a = D_801D0200;
                D_8009B1D8 = a;
                b = (u8 *)0;
                if (D_8009B361 >= 0x27) {
                    goto join;
                }
            }
        } else {
        join:
            b = a;
        }
        func_800245A0(a, b);
    }
}
