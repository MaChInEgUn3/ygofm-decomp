/* 240/240 -- COMPRIMENTO EXATO -- e 199 diferencas, censo `sw +1, lw +1,
 * nop +1, addiu -1, lui -2` (2026-09-08). PRIMEIRO C, exato no primeiro
 * rascunho que compilou. Flags PADRAO (passo 0: gp=27, at=0, SEM jump
 * table).
 *
 * FORMA: rotina de SETUP de tela -- 32 chamadas a 25 callees distintos,
 * zeragem de nove globais, dois objetos criados por
 * `func_800400AC(func_8004002C(), N)` e configurados, e um bloco final que
 * escolhe um par de buffers.
 *
 * TRES LEITURAS DO LISTING QUE O RASCUNHO DO M2C NAO DAVA:
 *  - **`sllv $a2,$v0,$s0` prova que o deslocamento e uma VARIAVEL.** O
 *    retail poe 1 em $s0 e o usa DUAS vezes: na comparacao
 *    `D_8009B369 != 1` e como amount do shift que faz `x * 3`. Escrito
 *    `(D_8009B361[0] << one) + D_8009B361[0]` com `one` local, sai `sllv`;
 *    escrito `* 3` sairia `sll 1` fixo;
 *  - `$s1` carrega 0x100 (usado em dois stores) e depois 0xB (usado como
 *    argumento de pilha das duas chamadas a func_800404CC) -- **duas
 *    constantes sequenciais no mesmo registrador, UM NOME** (regra 25);
 *  - `lb $v0,-0x1($v0)` com `$v0 = %lo(D_8009B361)` e uma leitura de
 *    D_8009B360, nao um campo negativo como o m2c escreveu.
 * E os simbolos `.data` (D_8009B360/361/364/369) sao lidos `lui %hi`/`lbu
 * %lo`, entao usam o BRACO DE ARRAY (`D_8009B364[0]`), nao o escalar
 * gp-relativo -- foi o que o compilador reclamou primeiro.
 *
 * O QUE FALTA (199 diferencas): **salvamos UM callee-saved a mais** ($s0 a
 * $s3 contra $s0 a $s2 do retail), e a moldura vai a 56 bytes em vez de 48.
 * O retail carrega TRES valores em $s0 em sequencia -- o 1, a base
 * D_800EA0E8 e o bit de sinal de D_8009B361 -- e eles nunca coexistem.
 * MEDIDO E MORTO: os tres num nome so da -1 com 209; o 1 com a base num
 * nome e o sinal separado da -1 com 207; a base com o sinal num nome e o 1
 * separado da -1 com 207. As tres fusoes tiram uma instrucao a mais do que
 * deviam, entao falta a outra metade do par (regra 17).
 * Tres declaracoes novas em variables.h: D_8009B1D8, D_8009B1DC e
 * D_8009B21C, os tres ponteiros gp-relativos que esta rotina grava.
 */
#include "common.h"

void func_800164FC(void);
void func_80016E70(void);

void func_800179F4(void) {
    u8 *e;
    u8 *o;
    s32 one;
    s32 hun;
    s32 sgn;

    func_8004763C();
    func_80047AD0(1);
    func_80012D84(4);
    one = 1;
    func_800137E4();
    func_80014E1C(0, 0, D_8009B364[0] * 0xEB + 0x16C6, 0xEB, func_800171A8, 0, 0);
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
        if (D_8009B361[0] >= 0) {
            func_80014E1C(0, 0, (D_8009B361[0] << one) + D_8009B361[0] + 0x1D33, 3, 0, 0, D_801781D8);
        }
        D_8009B1D5 = 0;
        D_8009B23A = one;
        func_8001778C();
        func_80017708();
        func_800175A0();
        D_8009B16C |= 0x1000;
    }
    D_8009B1C8 = (u8 *)&D_800E9FF0[D_8009B1D5];
    e = D_800EA0E8;
    func_800178BC();
    D_800F284A[0] = (D_8009B1D5 << 11) + 0x400;
    func_8001352C();
    func_800176D0();
    hun = 0x100;
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
    hun = 0xB;
    func_8001755C();
    func_800137E4();
    D_8009B22C = &D_800907D8[D_8009B1D5 * 0x14];
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0xC, 0x18, 4, 2, D_8009B364[0], hun, 0x2DC);
    func_80042918(o);
    *(u16 *)(o + 8) = *(u16 *)(o + 8) | 8;
    D_8009B214 = o;
    sgn = (u32)D_8009B361[0] >> 31;
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0x118, 0x20, 4, sgn, 0, hun, 0x2EC);
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
    if (D_8009B369[0] != 1) {
        u8 *a;
        u8 *b;
        D_8009B1DC = (u8 *)0;
        D_8009B1D8 = (u8 *)0;
        a = (u8 *)0;
        if (D_8009B360[0] < 0) {
            if (D_8009B361[0] < 0) {
                a = D_801D1200;
                b = a + 0x1000;
                D_8009B1D8 = a;
                D_8009B1DC = b;
            } else {
                a = D_801D0200;
                D_8009B1D8 = a;
                b = (u8 *)0;
                if (D_8009B361[0] >= 0x27) {
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
