/* 329/329 -- COMPRIMENTO EXATO -- CENSO VAZIO, e SETE divergencias
 * estruturais depois de ALINHAR os opcodes (2026-09-08). Compilador
 * PADRAO, assembler `as -G2` (linha em build.py).
 *
 * LEIA ESTE NUMERO E NAO O DA try_func. O diff da try_func e POSICIONAL:
 * este candidato marca 248 e o seu irmao com o laco de `b` por cursor
 * marca 235, e o de 248 e o MELHOR dos dois -- alinhando os dois fluxos
 * com difflib sobre os opcodes (scratchpad/30294/adiff.py) da
 * 253 iguais / 72 so-registrador / 7 estruturais contra
 * 212 iguais / 112 so-registrador / 9 estruturais. A contagem posicional
 * INVERTEU a ordem, que e exatamente a armadilha que o WORKFLOW descreve.
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
 *  6. **`as -G2`**: a unica linha de assembler que serve. O `-G1` e +6 e o
 *     `-G4` e -1; a -G2 o `%hi(D_800EAED8)` do delay slot volta e o censo
 *     perde o `lui -1`. Achado pelo `sweep_try.py`, que nunca tinha sido
 *     rodado nesta funcao;
 *  7. **`db = d;`** como ponteiro de base -- e SO ele. Com `cb = c;` junto,
 *     o gcc iça uma base de pilha a mais e derrama $s3 (+4 e +2 `sw`/`lw`);
 *     sem nenhum dos dois falta uma `addiu` (-1). Censo 4 -> 2;
 *  8. **as DUAS copias de registrador que faltavam, cada uma um NOME
 *     EMPRESTADO** (regra 16, a forma do func_8002596C):
 *     - o ponteiro do halfword no braco de entrada: `r = (u8 *)&(&D_8009B2C8)
 *       [(s8)D_8009B2DC]; p = (u16 *)r;`, onde `r` e o ponteiro do buffer do
 *       `fill`, morto naquele ponto. Emprestar `q` da o mesmo; `z` e -1 e um
 *       `nop`, `db` e `cb` nao mudam nada. Um `p2` PROPRIO nao produz copia
 *       nenhuma (tres medicoes, o gcc coalesce);
 *     - o limite do laco de carry: o retail compara contra `$v1` e COPIA
 *       `$v1` para `$t0` no delay slot do `beqz`, isto e o guarda e o laco
 *       usam nomes diferentes. `if (i < (s8)t2) { n = (s8)t2; ... }` fecha o
 *       censo. Um `m` intermediario da o mesmo (244); emprestar `k` ou
 *       `step` e 245.
 *
 * O QUE FALTA, com os opcodes ALINHADOS: SETE instrucoes, e as quatro
 * ultimas sao o MESMO fenomeno -- uma instrucao nossa icada UM slot cedo
 * demais, para dentro de um delay slot que o retail preenche de outro
 * jeito:
 *  - T[64] o retail poe `lui %hi(D_800EAED8)` no delay slot do
 *    `beq` (a copia de delay slot do bloco `fill`, regra 31) e nos pomos
 *    ali o nosso `sll $v1,$a0,1` (o `dc * 2` do endereco), que o retail so
 *    emite em T[68];
 *  - T[93]/T[94] o mesmo com `sll ...,2`;
 *  - T[283]/T[284] o mesmo com `addu $v0,$v1,$s0`;
 *  - T[311] o mesmo com `lui %hi(D_8009B2EC)`.
 * As QUATRO bases de pilha agora caem onde o retail as tem: `&c` em T[42],
 * `&d` em T[59] (registrador EXATO, $t4), `&a` em T[71] e `&b` em T[173].
 *
 * A ALAVANCA QUE ABRIU ISSO (nona): os DOIS lacos indexam o array em vez
 * de andar um cursor de fonte. `k = a[i];` sem `q = &a[i];` faz o gcc
 * CRIAR o giv dentro do braco -- que e onde o retail materializa
 * `addiu $v1,$sp,16` -- em vez de icar a base para o bloco de entrada.
 * Sozinho no laco de `a` isso e 244 -> 235 posicional (112 so-registrador);
 * sozinho no laco de `b` e 269 posicional mas 81 so-registrador; nos DOIS
 * e 248 posicional e 72 so-registrador, o melhor. SONDA QUE PROVOU A CAUSA:
 * apagar `q = &a[i];` faz o `addiu $?,$sp,16` do topo DESAPARECER, logo
 * quem cria o pseudo e o USO e nao o expand_block_move -- o paragrafo
 * anterior deste cabecalho, que culpava a copia de struct, esta RETRATADO.
 *
 * MEDIDO E MORTO NESTA BASE, com numeros: cinco grafias de `q = &b[e]`
 * (`(s32)b + e*4`, `e*4 + (s32)b`, `b + e`, `&b[0] + e`, e a posicao da
 * atribuicao) -- as CINCO dao 244 na base velha, eixo errado; `cb = c;`
 * em qualquer posicao derrama dois callee-saved (+4 e `sw`/`lw` +2), e
 * antes das copias tambem; `db = d;` antes das copias e identico;
 * `dc = (s8)D_8009B2DC;` nomeado e identico (e com `*p = val;` junto e -2,
 * porque o retail RECOMPUTA o endereco no store); `ea = D_8009B2EA;`
 * nomeado e identico. `-fno-cse-follow-jumps` poe `&b` no braco mas custa
 * uma releitura de D_8009B2DC (+1 `lb`, -1 `addiu`, 294 posicional), e com
 * `dc` nomeado fica 329/329 com censo 2 -- pior que o censo vazio daqui.
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
            r = (u8 *)&(&D_8009B2C8)[(s8)D_8009B2DC];
            p = (u16 *)r;
            val = *p;
            *p = 0;
            do {
                k = a[i];
                n = val / k;
                e = i * 4;
                i = i - 1;
                *p = *p | (n << e);
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
        p = &(&D_8009B2C8)[(s8)D_8009B2DC];
        e = (s8)D_8009B2E9;
        val = *p;
        step = c[e];
        if (((D_8009B394 | D_8009B396) & 0x4000) != 0) {
            step = -step;
        }
        if ((D_8009B2EA & 0x40) != 0) {
            mask = *(u16 *)(db + e * 2);
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
            val = (val + step) & (c[(s8)t2] - 1);
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
    i = 0x27;
    z = r + i;
    do {
        *z = 0x20;
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
