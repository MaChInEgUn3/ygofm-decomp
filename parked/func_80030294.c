/* 329/329 -- COMPRIMENTO EXATO, CENSO VAZIO -- e UMA UNICA divergencia
 * estrutural depois de ALINHAR os opcodes (2026-09-08): 294 linhas
 * iguais, 34 so-de-registrador, e DUAS instrucoes trocadas de lugar. Compilador e
 * assembler PADRAO: a linha `as -G2` que este park carregava foi APAGADA
 * de build.py, porque a -G2 o D_8009B2EC (4 bytes) sai do small data e o
 * retail o le `%gp_rel` -- a -G8 essa divergencia some sozinha.
 *
 * LEIA A CONTAGEM ALINHADA, NAO A DA try_func. O diff da try_func e
 * POSICIONAL e ja INVERTEU a ordenacao aqui uma vez (um candidato de 248
 * era melhor que um de 235). Use `tools_src/adiff.py <saida>`: este
 * candidato e 294 iguais / 34 so-registrador / 2 estruturais.
 *
 * FORMA: editor de um valor hexadecimal na tela. Um braco de ENTRADA
 * (primeiro `D_8009B2EA & 0x80`) que decompoe o valor em digitos por
 * divisoes sucessivas, um braco de EDICAO guiado pelos bits de
 * D_8009B394/396 e D_8009B398/39A, e um rabo que preenche um buffer de
 * 0x28 bytes com espacos, poe um `*` na posicao do cursor e chama
 * func_8007EF84 tres vezes.
 *
 * LEITURAS DO LISTING, todas confirmadas:
 *  - moldura -0x68, locais em 0x10 (20), 0x28 (16), 0x38 (20) e 0x50 (8),
 *    com BURACOS DE QUATRO BYTES em 0x24 e 0x4C -- o alinhamento de oito
 *    que o gcc da a um array local de oito bytes ou mais;
 *  - as tres primeiras copias sao expand_block_move (3+3 / 2+2) e a quarta
 *    e `lwl`/`lwr` + `swl`/`swr`, isto e um objeto de ALINHAMENTO 1;
 *  - `break 7`/`break 6` sao divisao REAL com divisor VARIAVEL;
 *  - o retail LE UM REGISTRADOR NAO INICIALIZADO em `.L800305BC`
 *    (`or $a1,$a1,$a3` com `$a3` nunca escrito naquele caminho): o carry e
 *    atribuido so dentro do laco e lido depois;
 *  - `func_8007EF84` e da familia do sprintf e nao leva prototipo.
 *
 * AS ALAVANCAS, EM ORDEM, COM NUMEROS:
 *  1. os SEIS halfwords de flags na forma nua (`_IN_DATA`) valem cinco
 *     instrucoes, e os mesmos seis TAMBEM VOLATILE valem vinte;
 *  2. o bloco `fill` tem de COMECAR pelo endereco do buffer: vale SETE
 *     `lui`, porque o retail copia esse `lui` para o delay slot de cada um
 *     dos sete desvios que saltam para la (regra 31);
 *  3. `val` e `mask` como `s32` (nao `u16`): censo 19 -> 10;
 *  4. a polaridade do wrap do cursor e a do teste de sinal do laco de carry;
 *  5. o CURSOR do `fill` e um SEGUNDO nome, e a BASE vem primeiro;
 *  6. `db = d;` como ponteiro de base -- e SO ele. `cb = c;` junto, em
 *     QUALQUER posicao (antes ou depois das copias), derrama dois
 *     callee-saved: +4 instrucoes e `sw`/`lw` +2 no censo;
 *  7. as duas copias de registrador que faltavam, cada uma um NOME
 *     EMPRESTADO (regra 16, a forma do func_8002596C): `r` para o ponteiro
 *     do halfword no braco de entrada, e um segundo nome para o limite do
 *     laco de carry (`if (i < (s8)t2) { n = (s8)t2; ... }`);
 *  8. **OS DOIS LACOS INDEXAM O ARRAY**, sem cursor de fonte: `k = a[i];`
 *     em vez de `q = &a[i]; k = *q;`. O gcc CRIA o giv dentro do braco,
 *     que e onde o retail materializa `addiu $v1,$sp,16` e
 *     `addiu $v0,$sp,40`; com o cursor escrito na fonte as quatro bases de
 *     pilha sobem para o bloco de entrada e roubam $t5. Alinhado: 9
 *     divergencias -> 7. SONDA QUE PROVOU A CAUSA: apagar `q = &a[i];`
 *     faz o `addiu $?,$sp,16` do topo DESAPARECER, logo quem cria o pseudo
 *     e o USO e nao o expand_block_move (diagnostico anterior RETRATADO);
 *  9. a constante 0x20 do `fill` e um NOME atribuido ENTRE `r = D_800EAED8;`
 *     e `i = 0x27;` -- o retail materializa `addiu $a0,$zero,32` antes do
 *     `addiu $s0,$zero,39`. 7 -> 4 estruturais. (Na base velha isto era
 *     "identico", que e a regra 3 outra vez.);
 * 10. **`r = (u8 *)&D_8009B2C8; r = r + (s8)D_8009B2DC * 2;` EM DUAS
 *     ATRIBUICOES CONTRA O MESMO NOME.** Vale um `lui` e vinte e c * ALAVANCA 11: dentro do laco de entrada `e` NAO existe -- e
 * `*p = *p | (n << (i * 4));` escrito ANTES do `i = i - 1;`. Com um `e`
 * nomeado o `sll` do indice cai na latencia do `mult`, onde o retail poe
 * o decremento do giv do cursor; escrito inline, os dois trocam. 4
 * divergencias estruturais -> 2, e 43 linhas de registrador -> 39.
 *
 * ALAVANCA 12: `val = val + step; val = val & (c[(s8)t2] - 1);` em duas
 * atribuicoes contra `val`, nao `val = (val + step) & (...)` numa so. O
 * retail poe o resultado em $a1, que e o registrador do proprio `val`;
 * numa expressao o gcc usa um temporario. `+=`/`&=` da o mesmo. 39
 * linhas de registrador -> 37.
 *
 * ALAVANCA 13: `mask = *(u16 *)(db - -(e * 2));` -- a subtracao de uma
 * negacao, que e a receita do WORKFLOW para trocar a ordem dos operandos
 * de um `addu`. O retail tem `addu $v0,$t4,$v0` (base primeiro) e todas
 * as formas com `+` dao indice primeiro. 37 -> 36, e compoe com a 12.
 *
 * ALAVANCA 14: o braco de EDICAO escreve o mesmo endereco da alavanca 10,
 * `r = (u8 *)&D_8009B2C8; r = r + (s8)D_8009B2DC * 2; p = (u16 *)r;`, no
 * lugar da forma indexada. Fecha `sll`/`la`/`addu` das linhas 147-148 do
 * retail. 36 linhas de registrador -> 34. Notar que `p = (u16 *)&D_...;
 * p = p + (s8)D_8009B2DC;` -- a mesma ideia sem passar por `r` -- e 39,
 * i.e. PIOR que a forma indexada: e o `r` que importa, nao o partir em
 * duas.
 *
 * O QUE FALTA, com os opcodes ALINHADOS -- UMA troca de posicao:
 *  - T[68]/T[69]: o retail emite `sll $v0,$a0,1` (o indice) e depois
 *    `la $v1,D_8009B2C8` (a base); nos emitimos a base primeiro, que e a
 *    ordem em que as duas atribuicoes contra `r` estao escritas. Seis
 *    grafias medidas e TODAS identicas (os tres `do { } while (0);`
 *    possiveis, `r + dc + dc`, `&r[dc * 2]`, e o cast `(s32)r`), o que e
 *    o sinal de eixo errado -- mas a alavanca 10 ensinou que esse sinal
 *    tambem aparece quando o eixo esta certo e as grafias e que sao
 *    fracas. Classe do permuter.
 *
 * MEDIDO E MORTO NESTA BASE, com numeros: cinco grafias de `q = &b[e]`
 * (`(s32)b + e*4`, `e*4 + (s32)b`, `b + e`, `&b[0] + e`, e a posicao da
 * atribuicao) -- as cinco identicas, eixo errado; `dc = (s8)D_8009B2DC;`
 * nomeado e identico (e com `*p = val;` junto e -2, porque o retail
 * RECOMPUTA o endereco no store); `ea = D_8009B2EA;` nomeado e identico;
 * `do { i = (s8)t2 - 1; } while (0);` e identico; SEIS ordens do braco de
 * entrada (r/p/val antes de `i`, `i` partido em duas, `p` como nome
 * emprestado em vez de `r`, dois `do { } while (0);`) -- todas 4
 * estruturais na base anterior; `e = i * 4` reescrito como
 * `n << ((i + 1) * 4)` depois do decremento fecha o comprimento mas CRIA
 * UM SEGUNDO GIV (dois `addiu -4` no laco) -- era um falso zero, duas
 * faltas a cancelarem-se; tres outras ordens do laco de entrada
 * (`e = i * 4` acima do `n = val / k`, o `val -= k * n` antes do store, e
 * um `do { e = i * 4; } while (0);`) sao 4, 4 e 6 estruturais;
 * CINCO grafias que poem o INDICE como destino da soma do endereco do
 * braco de entrada (`ix` nomeado em tres posicoes, o cast `(s32)` inline,
 * e a cadeia `ix = ix + (s32)r; r = (u8 *)ix;`) sao -1 e 3 estruturais ou
 * identicas -- as que fecham a ordem matam a COPIA emprestada da alavanca
 * 7, que e o `addu $t0,$v0,$zero`; cinco grafias do mesmo endereco no
 * braco de EDICAO sao identicas ou piores; e QUATRO separacoes de nome
 * (`n` do braco de edicao, `i` do braco de edicao, `i` do `fill`, `i` do
 * `out`) sao 74, 47, 42 e 61 linhas de registrador contra 36 -- os nomes
 * partilhados entre fases estao CERTOS aqui, que e a regra 16 ao
 * contrario; os quatro flags de escalonamento
 * (`-fno-schedule-insns`, `-fno-schedule-insns2`, os dois, e
 * `-fno-delayed-branch`) sao 21, 23, 47 e 42 estruturais;
 * `-fno-cse-follow-jumps` poe `&b` no braco mas custa uma releitura de
 * D_8009B2DC (+1 `lb`, -1 `addiu`), e com `dc` nomeado fica 329/329 com
 * censo 2 -- pior que o censo vazio daqui. Assembler: -G0 e 45
 * estruturais, -G1 e 15, -G2 e 7, -G4 e -G8 sao 5.
 */
#define D_8009B394_IN_DATA_VOLATILE
#define D_8009B396_IN_DATA_VOLATILE
#define D_8009B398_IN_DATA_VOLATILE
#define D_8009B39A_IN_DATA_VOLATILE
#define D_8009B3A4_IN_DATA_VOLATILE
#define D_8009B3A6_IN_DATA_VOLATILE
#include "common.h"

typedef struct { s32 w[5]; } Blk14;
typedef struct { s32 w[4]; } Blk10;
typedef struct { u8 b[8]; } Blk8;

s32 func_80030294(void) {
    s32 a[5];
    s32 b[4];
    s32 c[5];
    u8 d[8];
    s32 ret;
    s32 i;
    s32 n;
    s32 e;
    s32 step;
    s32 car;
    s32 *q;
    u8 *db;
    s32 k;
    u8 *z;
    u16 *p;
    s32 val;
    s32 mask;
    u8 t2;
    u8 f;
    u8 *r;
    s32 sc;

    ret = 0;
    *(Blk14 *)a = *(Blk14 *)D_80010250;
    *(Blk10 *)b = *(Blk10 *)D_80010264;
    *(Blk14 *)c = *(Blk14 *)D_80010274;
    *(Blk8 *)d = *(Blk8 *)D_8009AF4C;
    db = d;
    t2 = (&D_8009B2C0)[(s8)D_8009B2DC];
    if ((D_8009B2EA & 0x80) == 0) {
        D_8009B2EA = D_8009B2EA | 0x80;
        if ((D_8009B2EA & 0x40) != 0) {
            i = (s8)t2 - 1;
            r = (u8 *)&D_8009B2C8;
            r = r + (s8)D_8009B2DC * 2;
            p = (u16 *)r;
            val = *p;
            *p = 0;
            do {
                k = a[i];
                n = val / k;
                *p = *p | (n << (i * 4));
                i = i - 1;
                val = val - k * n;
            } while (i >= 0);
        }
        goto fill;
    }
    if ((D_8009B2EA & 1) != 0) {
        goto fill;
    }
    if (((D_8009B3A4 | D_8009B3A6) & 0x800) != 0) {
        goto fill;
    }
    if (((D_8009B398 | D_8009B39A) & 0xC0) != 0) {
        ret = 1;
        goto out;
    }
    if (((D_8009B398 | D_8009B39A) & 0x20) != 0) {
        ret = -1;
        goto out;
    }
    if (((D_8009B394 | D_8009B396) & 0x5000) != 0) {
        r = (u8 *)&D_8009B2C8;
        r = r + (s8)D_8009B2DC * 2;
        p = (u16 *)r;
        e = (s8)D_8009B2E9;
        val = *p;
        step = c[e];
        if (((D_8009B394 | D_8009B396) & 0x4000) != 0) {
            step = -step;
        }
        if ((D_8009B2EA & 0x40) != 0) {
            mask = *(u16 *)(db - -(e * 2));
            i = e;
            if (i < (s8)t2) {
                n = (s8)t2;
                do {
                    car = val & mask;
                    val = val & ~mask;
                    car = car + step;
                    if (step >= 0) {
                        if (car < b[i]) {
                            goto joined;
                        }
                    } else {
                        if (car >= 0) {
                            goto joined;
                        }
                        val = val | ((b[i] - 1) & mask);
                    }
                    car = 0;
                    mask = mask * 0x10;
                    step = step * 0x10;
                    i = i + 1;
                } while (i < n);
            }
        joined:
            val = val | car;
        } else {
            val = val + step;
            val = val & (c[(s8)t2] - 1);
        }
        (&D_8009B2C8)[(s8)D_8009B2DC] = val;
    }
    if (((D_8009B394 | D_8009B396) & 0xA000) == 0) {
        goto out;
    }
    if (((D_8009B394 | D_8009B396) & 0x2000) != 0) {
        D_8009B2E9 = D_8009B2E9 - 1;
        if ((s8)D_8009B2E9 < 0) {
            D_8009B2DC = D_8009B2DC + 1;
            if ((s8)D_8009B2DC >= (s8)D_8009B2E0) {
                D_8009B2DC = D_8009B2E0 - 1;
                D_8009B2E9 = 0;
                goto fill;
            }
            f = (&D_8009B2C0)[(s8)D_8009B2DC] - 1;
            goto setpos;
        }
    } else {
        D_8009B2E9 = D_8009B2E9 + 1;
        if ((s8)D_8009B2E9 >= (s8)t2) {
            D_8009B2E9 = 0;
            D_8009B2DC = D_8009B2DC - 1;
            if ((s8)D_8009B2DC < 0) {
                f = D_8009B2C0 - 1;
                D_8009B2DC = 0;
            setpos:
                D_8009B2E9 = f;
            }
        }
    }
fill:
    r = D_800EAED8;
    sc = 0x20;
    i = 0x27;
    z = r + i;
    do {
        *z = sc;
        i = i - 1;
        z = z - 1;
    } while (i >= 0);
    r = &D_800EAED8[(s8)(&D_8009B2B4)[(s8)D_8009B2DC] - (s8)D_8009B2E9];
    r[0] = 0x2A;
    r[1] = 0;
out:
    i = (s8)D_8009B2B8;
    if (i != 0) {
        do {
            func_8007EF84(D_8009AF54);
            i = i - 1;
        } while (i != 0);
    }
    func_8007EF84(D_8009B2EC, D_8009B2C8, D_8009B2CA, D_8009B2CC);
    func_8007EF84(D_8009AF58, D_800EAED8);
    return ret;
}
