/* 295/295 -- COMPRIMENTO EXATO -- e 88 diferencas, censo `addiu +1, nop -1`
 * (magnitude 2, 17 blocos). 2026-09-08, escrita do zero hoje:
 * -9/279 -> +2/130 -> 295/295 e 95 -> 89 -> 88.
 * Flags PADRAO (passo 0: gp=56, at=0, uma jump table jtbl_80010548).
 *
 * FORMA: maquina de estados de retry. `switch ((s8)((u8)D_8009B43E - 1))`
 * com jump table real de 12 entradas, e dentro DOIS `switch (D_8009B44F)`
 * com cases 0/1/2 cujo `case 0` CAI no `case 1`. A ordem dos bracos na
 * memoria e 0/1, 10/11, 2/3, 7, default -- a ordem em que os cases estao
 * escritos. Os dois switches internos sao identicos e o retail funde a
 * aresta `>= 2` dos dois (.L800449DC) com o corpo do case 2 em .L80044B38:
 * esse corpo esta escrito POR EXTENSO nos dois, porque escrever a fusao a
 * mao com `goto` e pior nas duas direcoes (99 e 166 contra 95).
 *
 * AS TRES EDICOES QUE A TROUXERAM ATE AQUI:
 *
 * 1. **`do { k = 2; } while (0);` no preheader do laco do case 7**, com
 *    `D_8009B450 = k;` depois: -9/279 para +2/**130**. A funcao tem sete
 *    `D_8009B450 = K;` que terminam todas em [sw $v0,D_8009B450][j tail]; o
 *    `find_cross_jump` compara as instrucoes antes de um salto com as
 *    instrucoes antes do ROTULO, e o bloco que precede o rotulo do tail e o
 *    fim desse laco. No retail o ultimo store dali e `sw $s4,...` --
 *    registrador DIFERENTE, porque o 2 esta materializado antes do laco --
 *    e isso sozinho quebra a cadeia inteira: retail cinco stores, nos dois.
 *    O nome SEM o pino e byte-identico ao literal.
 *
 * 2. **O bloco `func_80073910(h); D_8009B450 = 0;` do case 7 escrito DENTRO
 *    do `if` anterior, depois do `break`**: +2/130 para **295/295 e 95**. O
 *    retail o poe entre o `break` do teste do func_80044470 e o resto do
 *    case 0, com o `beqz` saltando por cima; um rotulo dentro de um bloco
 *    alcancado por `goto` de fora e a unica grafia que move o bloco.
 *
 * 3. **UM PAR ACOPLADO, e cada metade sozinha e uma REGRESSAO**: 95 -> 89.
 *    (i) `func_80073910(h); return 0;` escrito nos TRES caminhos em vez de
 *    um `rel:` compartilhado -- sozinho e +1 com 65 diferencas. O retail
 *    compartilha so `jal`/`nop`/`j`/`addu $v0,$zero,$zero` e DUPLICA o
 *    `addu $a0,$s1,$zero` em cada predecessor, que e a regra do
 *    func_80030998: argumento duplicado com o rabo compartilhado e uma
 *    chamada escrita em cada braco. (ii) o `i -= 1;` do laco 3 movido para
 *    ANTES do `if`/`else` -- sozinho e -1 com 121. Juntas dao comprimento
 *    exato e magnitude 2.
 *
 * MEDIDO E MORTO, COM NUMEROS (nao refazer):
 *  - nomear o TERCEIRO argumento (o literal 0) da chamada do laco 2, com e
 *    sem `do { } while (0)`, e nomear tambem o segundo: 88, 88, 88 --
 *    identicos a base. Eixo errado;
 *  - `do { D_8009B43C = 0x14; } while (0);` no bloco `ok`, que era a
 *    tentativa obvia de impedir a constante de subir para o delay slot do
 *    `beq`: 89, pior;
 *  - o `i -= 1;` do laco 3 de volta para DEPOIS do `if`/`else` sobre esta
 *    base: +1 com censo `addiu +2, nop -1` -- a metade (ii) do par continua
 *    valendo;
 *  - o `i -= 1;` do laco 2 movido para antes da chamada: 91. So o do laco
 *    do case 7 valeu (89 -> 88), o que fecha qual dos tres queria a grafia
 *    e e mais uma instancia de dois sitios da mesma funcao andando em
 *    direcoes opostas;
 *  - a FORMA do laco 3: `for (i = 0xA; i >= 0; )`, `while (i >= 0)` e
 *    `do { ... if (i < 0) goto rel; } while (1);` dao 95, 95, 95 -- os tres
 *    IDENTICOS a base. A polaridade da aresta de volta nao vem dali;
 *  - os tres lacos escritos como `goto` em vez de `do { } while`: -1/135,
 *    -4/280, -5/278. O passo de laco do gcc esta rodando e icando
 *    invariantes, e a forma `goto` perde as notas NOTE_INSN_LOOP;
 *  - o corpo do `case 2` escrito UMA vez com `goto` do outro switch: 99 com
 *    o corpo no segundo braco e 166 com ele no primeiro, contra 95;
 *  - um nome por laco para as sentinelas (-1, 4, 2): cinco nomes,
 *    BYTE-IDENTICO ao inline. O gcc ja as mantem em registrador;
 *  - `k = 2;` sem o `do { } while (0)`: byte-identico ao literal;
 *  - as tres posicoes do `i -= 1;` nos lacos 2 e 3 medidas ANTES do par
 *    acoplado: 132, 130, 132 contra 130. Foi essa a medicao que escondeu a
 *    metade (ii) por um tick.
 *
 * O QUE FALTA (89 diferencas, 18 blocos, censo `addiu +1, nop -1`):
 *  a) nos lacos 2 e do case 7 o retail poe o ULTIMO ARGUMENTO da chamada no
 *     delay slot do `jal` e o `addiu $s0,-1` no delay slot do `bne`; nos
 *     fazemos o contrario. O laco 1, que tem dois argumentos e nenhum
 *     literal, sai exato;
 *  b) sobra um `addiu $s0,-1` duplicado no laco 3 e falta um `nop`;
 *  c) o `addiu $s4,$zero,2` sai duas posicoes cedo no preheader do case 7;
 *  d) um `beq` do `case 2` vai para um rotulo diferente do tail.
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
            func_80073910(h);
            return 0;
        got2:
            func_80043D48(D_800F2AE0);
            i = 0xA;
            do {
                i -= 1;
                if (D_8009B43E == 4) {
                    r = func_80073900(h, D_8009B430, D_8009B434);
                } else {
                    r = func_800738F0(h, D_8009B430, D_8009B434);
                }
                if (r == 0) {
                    goto ok;
                }
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
                i -= 1;
                h = func_800738D0(D_800F2B00, (D_8009B434 << 16) | 0x200);
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
