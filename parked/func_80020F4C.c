/* 334/333 -- UMA instrucao a mais -- e, com os opcodes ALINHADOS
 * (tools_src/adiff.py), 274 linhas iguais, 46 so-de-registrador e 22
 * instrucoes em 14 grupos estruturais. Primeiro rascunho, flags PADRAO.
 * Censo: `nop -1, addiu -1, addu +1, sw +1, lw +1` -- o `sw`/`lw` a mais e
 * UM CALLEE-SAVED A MAIS (o retail salva $s0-$s5 e o $ra em 0x28..0x40 com
 * moldura 0x48; nos salvamos oito e poimos o $ra em 0x44), e as faltas
 * cancelam-se parcialmente, logo o comprimento +1 e um FALSO quase-zero.
 *
 * FORMA: maquina de estados do ecra de titulo/demo. Dois niveis: um braco
 * de INICIALIZACAO (`D_8009B23A & 0x8000` ainda nao posto) e, depois, um
 * `switch (D_8009B174 & 0xF)` com os casos 1..4. QUATRO casos dao uma
 * ARVORE de comparacoes e nao uma jump table -- o limiar do gcc 2.8 neste
 * alvo e cinco -- e a arvore do retail (`beq 2`, `slti 3`, `beq 1`,
 * `beq 3`, `beq 4`) e exatamente a que o gcc constroi para {1,2,3,4}.
 *
 * PASSO 0: `%gp_rel` = 31 e `lui $at` = 2, e os DOIS `$at` sao o mesmo
 * simbolo (D_8009B362, dois `sb`), que ja tinha braco `_IN_DATA` -- a
 * forma mais barata do WORKFLOW, sem `-G` nem tamanho inflado. Zero jump
 * tables, zero `break 7`.
 *
 * AS ASSINATURAS VIERAM DE src/, NAO DO m2c, e tres delas eram diferentes:
 * `func_80042B40(s32)` devolve `u8 *` onde o m2c escreveu tres argumentos;
 * `func_8004703C(void)` onde ele escreveu dois; e `func_800428A8` leva
 * `(u8 *, s32 x8)` onde ele inventou `(u8*, u8, u8, ?, s32...)`. O unico
 * callee de biblioteca, func_8008E590, e o **rand** (config/sdk_names.txt),
 * e func_800358FC(n) e `rand() % n`.
 *
 * TRES SIMBOLOS NAO EXISTIAM em variables.h e foram acrescentados:
 * D_8009B1E0 (u16 gp-relativo), e D_80090928/D_80090960 -- duas tabelas
 * paralelas de sete registos de quatro bytes, escolhidas pelo SINAL de
 * D_8009B361 e indexadas por `D_8009B165 * 28`.
 *
 * O QUE FALTA, pelos grupos do adiff:
 *  - T[146-169]: o retail iça `&D_80090928` para $s5 antes do laco e
 *    RE-MATERIALIZA `&D_80090960` DENTRO dele; nos içamos os dois, o que
 *    e o callee-saved a mais. E o teste de custo do loop.c a hastear um
 *    invariante e nao o outro (WORKFLOW: qual deles nao esta estabelecido);
 *  - T[59-67]: a ordem do `lhu 0x32` no braco de inicializacao;
 *  - T[208-218]: a ordem entre `sh 0x18,0x4A`, `lw 4` e a copia `$a0 = $s0`
 *    antes do func_80042918;
 *  - T[281-292]: uma copia `addu $s2,$s0` a mais e a releitura de
 *    D_8009B174 no caso 3.
 */
#define D_8009B362_IN_DATA
#define D_8009B0F4_IN_DATA
#define D_8009B134_IN_DATA
#define D_8009B361_IN_DATA
#define D_8009B398_IN_DATA
#include "common.h"

extern void func_80020BE4(void);
extern void func_80020D4C(void);
extern void func_80020EE8(void);
extern void func_8001EC70(void);

void func_80020F4C(void) {
    u8 **b;
    u8 **e;
    u8 *p;
    u8 *r;
    s32 i;
    s32 off;
    s32 n;
    s32 k;

    b = (u8 **)D_801799D8;
    if ((D_8009B23A & 0x8000) == 0) {
        D_8009B23A = D_8009B23A | 0x8000;
        func_8003FF34();
        D_8009B362 = 0;
        if (D_8009B165 != 0) {
            D_8009B362 = 1;
        }
        D_8009B238 = D_8009B165;
        func_80014E1C(0, (u8 *)0, 0x1DAB, 0x22, (void *)func_80020BE4, 0, 0);
        n = 0x72E0;
        if (D_8009B165 != 0) {
            if (D_8009B361 >= 0) {
                n = 0x72F0;
            }
        }
        D_8009B1E0 = n;
        p = D_8009B214;
        *(s16 *)(p + 0x28) = -0x74;
        *(s16 *)(p + 0x2C) = 0x30;
        p[0x6C] = 1;
        *(void **)(p + 0x24) = (void *)func_8001EC70;
        *(u16 *)(p + 0x2A) = *(u16 *)(p + 0x32);
        p = D_8009B21C;
        *(s16 *)(p + 0x28) = 0x198;
        *(s16 *)(p + 0x2C) = 0x30;
        p[0x6C] = 1;
        *(void **)(p + 0x24) = (void *)func_8001EC70;
        D_8009B174 = 1;
        *(u16 *)(p + 0x2A) = *(u16 *)(p + 0x32);
        return;
    }
    if (D_8009B162 != 0) {
        return;
    }
    switch (D_8009B174 & 0xF) {
    case 1:
        if ((D_8009B174 & 0x80) == 0) {
            if (((D_8009B0F4 & 0x2000030) | D_8009B134) == 0) {
                D_8009B174 = D_8009B174 | 0x80;
                D_8009B162 = 8;
                k = D_8009B361;
                if (k < 0) {
                    k = 1;
                }
                func_80014E1C(0, (u8 *)0, k * 3 + 0x1D33, 3, (void *)0, 0,
                              (s32)(b - 0x600));
                func_800472A8(D_8009B1E0);
            }
            return;
        }
        if (((D_8009B0F4 & 0x2000030) | D_8009B134) == 0) {
            D_8009B174 = 2;
            func_8003FF08(D_8009B1E0);
        }
        return;
    case 2:
        if ((D_8009B174 & 0x80) == 0) {
            D_8009B174 = D_8009B174 | 0x80;
            i = 0;
            e = b;
            off = 0;
            do {
                if (D_8009B361 >= 0) {
                    r = &D_80090928[off] + D_8009B165 * 28;
                } else {
                    r = &D_80090960[off] + D_8009B165 * 28;
                }
                *e = (u8 *)0;
                if (r[2] != 0) {
                    p = func_800400AC(func_8004002C(), 2);
                    func_800428A8(p, r[0], r[1], 0, D_8009B165, r[2], 0x11, 9,
                                  (s32)D_801AF000);
                    if (p[0x69] >= 0x1A) {
                        *(u16 *)(p + 0x40) = *(u16 *)(p + 0x40) + 0x10;
                    }
                    *(u16 *)(p + 8) = *(u16 *)(p + 8) | 0x28;
                    *(s32 *)(p + 4) = *(s32 *)(p + 4) | 0x50000000;
                    *(s16 *)(p + 0x4A) = 0x18;
                    *(s16 *)(p + 0x48) = r[3];
                    func_80042918(p);
                    *(s32 *)(p + 0x2C) = *(s32 *)(p + 0x30);
                    *(s16 *)(p + 0x28) = (func_8008E590() & 0x3F) + 0x140;
                    *(s16 *)(p + 0x2A) = func_800358FC(0x1000);
                    p[0x6C] = 1;
                    *(void **)(p + 0x24) = (void *)func_80020D4C;
                    *e = p;
                }
                e = e + 3;
                i = i + 1;
                off = off + 4;
            } while (i < 7);
            return;
        }
        if (((D_8009B0F4 & 0x2000030) | D_8009B134) == 0) {
            if (func_80042B40(1) == (u8 *)0) {
                D_8009B174 = 3;
            }
        }
        return;
    case 3:
        if ((D_8009B174 & 0x80) == 0) {
            D_8009B174 = D_8009B174 | 0x80;
            D_8009B1D0 = 0x258;
        }
        if ((D_8009B174 & 0x40) == 0) {
            i = 0;
            D_8009B1D0 = D_8009B1D0 - 1;
            if ((s16)D_8009B1D0 > 0) {
                if ((D_8009B398 & 0xE0) == 0) {
                    if ((func_8004703C() & 0x80) != 0) {
                        return;
                    }
                }
            }
            e = b;
            D_8009B174 = D_8009B174 | 0x40;
            do {
                p = *e;
                if (p != (u8 *)0) {
                    p[0x6C] = 1;
                    *(void **)(p + 0x24) = (void *)func_80020EE8;
                }
                i = i + 1;
                e = e + 3;
            } while (i < 7);
            return;
        }
        if (func_80042B40(1) == (u8 *)0) {
            D_8009B174 = 4;
        }
        return;
    case 4:
        if ((D_8009B174 & 0x80) == 0) {
            D_8009B174 = D_8009B174 | 0x80;
        }
        if ((D_800E9ECE[0] & 0x80) == 0) {
            D_8009B23A = 0xD;
        }
        return;
    }
}
