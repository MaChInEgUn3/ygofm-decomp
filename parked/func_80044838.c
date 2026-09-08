/* 295/295 -- COMPRIMENTO EXATO -- e 95 diferencas (2026-09-08). Primeiro C
 * escrito hoje: -9/279 -> +2/130 -> 295/295 e 95, em duas edicoes.
 * Flags PADRAO (passo 0: gp=56, at=0, uma jump table jtbl_80010548).
 *
 * FORMA: maquina de estados de retry. `switch ((s8)((u8)D_8009B43E - 1))`
 * com jump table real de 12 entradas, e dentro DOIS `switch (D_8009B44F)`
 * com cases 0/1/2 cujo `case 0` CAI no `case 1`. A ordem dos bracos na
 * memoria e 0/1, 10/11, 2/3, 7, default, que e a ordem em que os cases estao
 * escritos. Os dois switches internos sao identicos e o retail funde a
 * aresta `>= 2` dos dois (.L800449DC) com o corpo do case 2 em .L80044B38 --
 * por isso o `case 2:` esta escrito por extenso nos dois.
 *
 * AS DUAS EDICOES QUE FECHARAM O COMPRIMENTO, e as duas sao regras que
 * vieram de func_800577B0 no mesmo dia:
 *
 * 1. **`do { k = 2; } while (0);` no preheader do laco do case 7**, com o
 *    `D_8009B450 = k;` depois dele: -9 e 279 diferencas para +2 e **130**.
 *    O mecanismo e o do func_800577B0 lido pelo lado da ALOCACAO. A funcao
 *    tem sete `D_8009B450 = K;` que terminam todas em [sw $v0,D_8009B450]
 *    [j tail]; o cross-jump do gcc compara as instrucoes antes de um salto
 *    com as instrucoes antes do ROTULO do salto, e o bloco que precede o
 *    rotulo do tail e justamente o fim do laco do case 7. No retail esse
 *    ultimo store e `sw $s4,...` -- registrador DIFERENTE, porque o 2 esta
 *    materializado em $s4 antes do laco -- e isso sozinho quebra a cadeia
 *    inteira: o retail tem CINCO stores e nos tinhamos dois. O nome sem o
 *    pino e byte-identico ao literal (o gcc propaga a constante).
 *
 * 2. **O bloco `func_80073910(h); D_8009B450 = 0;` escrito DENTRO do `if`
 *    anterior, depois do `break`**: +2 e 130 para **295/295 e 95**. O retail
 *    poe esse bloco em .L80044C0C, entre o `break` do teste do func_80044470
 *    e o resto do case 0, e o `beqz` salta por cima dele. Um rotulo dentro
 *    de um bloco alcancado por `goto` de fora e C legal e e a unica grafia
 *    que move o bloco (regra do func_8002538C).
 *
 * MEDIDO E MORTO, COM NUMEROS:
 *  - um nome por laco para as sentinelas (-1, 4, 2) que o retail carrega em
 *    callee-saved -- cinco nomes, BYTE-IDENTICO ao inline. O gcc ja as
 *    mantem em registrador;
 *  - `k = 2;` sem o `do { } while (0)`: byte-identico ao literal;
 *  - os TRES lacos escritos como `goto` em vez de `do { } while`: -1/135
 *    (laco 3), -4/280 (laco do case 7), -5/278 (os dois). O `do`/`while` e o
 *    certo: o passo de laco do gcc esta rodando e icando invariantes, e a
 *    forma `goto` nao tem as notas NOTE_INSN_LOOP e perde a icagem;
 *  - o `i -= 1;` do laco 3 movido para ANTES do `if`/`else` (-1, 121
 *    diferencas, magnitude do censo 5) e para DENTRO dos dois bracos
 *    (-1, 123, magnitude 7). O primeiro TIRA o `addiu` duplicado -- o gcc
 *    copia a primeira instrucao do bloco de juncao para o delay slot do
 *    `j` do braco `then` (salto para alvo+4), e o retail deixa esse slot
 *    `nop` porque no dele a juncao ja comeca pelo `beq`. Fica registrado
 *    como CANDIDATO A PAR ACOPLADO: tem magnitude menor que a base mas
 *    perde uma instrucao, entao so vale junto com o que devolver o `nop`;
 *  - a posicao do `i -= 1;` nos lacos 2 e 3 (antes da chamada, depois do
 *    teste, e as duas): 132, 130, 132 contra 130 -- tres grafias, o mesmo
 *    numero, EIXO ERRADO.
 *
 * O QUE FALTA (95 diferencas, 21 blocos, censo `addiu +2, bltz +1,
 * bgez -1, addu -1, nop -1`):
 *  a) nos tres lacos que ainda diferem, o retail poe o ULTIMO ARGUMENTO da
 *     chamada no delay slot do `jal` e o `addiu $s0,-1` no delay slot do
 *     `bne`; nos fazemos o contrario. O laco 1, que tem dois argumentos e
 *     nenhum literal, sai exato;
 *  b) o laco 3 tem a aresta de volta invertida (`bltz` para fora onde o
 *     retail tem `bgez` para dentro) e o `D_8009B43C = 0x14` sobe junto;
 *  c) o `addiu $s4,$zero,2` sai duas posicoes cedo no preheader do case 7.
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
                i -= 1;
                if (r != -1) {
                    goto got2;
                }
            } while (i >= 0);
            goto rel;
        got2:
            func_80043D48(D_800F2AE0);
            i = 0xA;
            do {
                if (D_8009B43E == 4) {
                    r = func_80073900(h, D_8009B430, D_8009B434);
                } else {
                    r = func_800738F0(h, D_8009B430, D_8009B434);
                }
                i -= 1;
                if (r == 0) {
                    goto ok;
                }
            } while (i >= 0);
            goto rel;
        ok:
            D_8009B43C = 0x14;
            D_8009B44F += 1;
        rel:
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
                i -= 1;
                if (h != -1) {
                    goto rel7;
                }
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
