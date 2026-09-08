/* 327/329 -- DUAS instrucoes a menos -- e 268 diferencas, censo de
 * magnitude 10 (`nop -3, addu -2, sw +1, lw +1, addiu +1, beq +1, bne -1`)
 * (2026-09-08). Veio de -28/325 -> -23/325 -> -3/314 -> -1/307 -> -2/268.
 * Flags PADRAO (passo 0: gp=34, at=0, sem jump table, sem GTE).
 *
 * FORMA: editor de um valor hexadecimal na tela. Um braco de ENTRADA
 * (primeiro `D_8009B2EA & 0x80`) que decompoe o valor em digitos por
 * divisoes sucessivas, um braco de EDICAO guiado pelos bits de
 * D_8009B394/396 e D_8009B398/39A, e um rabo que preenche um buffer de
 * 0x28 bytes com espacos, poe um `*` na posicao do cursor e chama
 * func_8007EF84 tres vezes.
 *
 * O QUE A LEITURA DO LISTING ESTABELECEU (tudo confirmado no candidato):
 *  - **moldura -0x68**, com locais em 0x10 (20 bytes), 0x28 (16), 0x38 (20)
 *    e 0x50 (8), e BURACOS DE QUATRO BYTES em 0x24 e 0x4C. Os buracos sao o
 *    alinhamento de 8 que o gcc da a um ARRAY local de oito bytes ou mais;
 *  - os tres primeiros sao COPIAS DE STRUCT de D_80010250 (5 palavras),
 *    D_80010264 (4) e D_80010274 (5) -- o padrao do expand_block_move. O
 *    quarto e uma copia com `lwl`/`lwr` e `swl`/`swr` de D_8009AF4C, isto e,
 *    um objeto de ALINHAMENTO 1 (typedef com `u8 b[8]`);
 *  - `break 7` e `break 6` sao uma DIVISAO REAL com divisor VARIAVEL;
 *  - **o retail LE UM REGISTRADOR NAO INICIALIZADO**: em `.L800305BC` faz
 *    `or $a1,$a1,$a3` e, no caminho em que o laco nunca roda, `$a3` nunca
 *    foi escrito naquele braco. A fonte tinha um carry atribuido so dentro
 *    do laco e lido depois;
 *  - `func_8007EF84` e da familia do sprintf e nao leva prototipo.
 *
 * ALAVANCAS INSTALADAS, COM NUMEROS:
 *  - os SEIS halfwords de flags (D_8009B394, 396, 398, 39A, 3A4, 3A6) na
 *    FORMA NUA (`_IN_DATA`) valem cinco instrucoes; **e os mesmos seis
 *    tambem VOLATILE valem VINTE** (-23/325 -> -3/314). Sao as duas metades
 *    de uma alavanca so e nenhuma sozinha chega la;
 *  - **O BLOCO `fill` TEM QUE COMECAR PELO ENDERECO DO BUFFER, e isso vale
 *    SETE `lui`** (censo `lui -7` -> 0). O retail copia o `lui %hi` da
 *    primeira instrucao do bloco `fill` para o delay slot de cada um dos
 *    sete desvios que saltam para la, e desvia para o rotulo+4 (regra 31).
 *    Enquanto o endereco estava num local atribuido no TOPO da funcao, o
 *    bloco comecava por `addiu $s0,$zero,39` e nao havia nada para copiar.
 *    **ISTO RETRATA a linha "SETE grafias, todas 314, o `lui` NAO vem da
 *    forma do bloco" que estava aqui**: as sete grafias foram medidas com o
 *    local do topo ainda no lugar, isto e, com outra falta aberta (regra 3).
 *    A grafia que ganha e `r = D_800EAED8; i = 0x27; r = r + i;`; um SEGUNDO
 *    nome para a base (`z = D_800EAED8; r = z + i;`) e -5/310 e a forma
 *    indexada `r[i] = 0x20;` e -6/310;
 *  - `val` E `mask` declarados `s32` em vez de `u16`: censo de 19 para 10,
 *    `andi +3`, `lhu +2`, `lw -2` e `or +1` todos zerados. Um sozinho nao
 *    chega (`val` da 12, `mask` da 18) -- as duas metades sao a mesma
 *    alavanca. **Isto so pode ser medido depois do bloco `fill`**: na base
 *    de -1/307 os dois juntos eram -4/323, "muito pior" (regra 3 de novo);
 *  - **a polaridade do teste de sinal no laco de carry**: escrito
 *    `if (step >= 0) { if (car < *q) goto joined; } else { ... }` da o
 *    `bltz` do retail; escrito `if (step < 0) { ... } else if (...)` da
 *    `bgez` e desloca o bloco inteiro. Censo de 10 para 7, +1 instrucao.
 *    A forma com `goto neg;`/`goto zero;` da exatamente o mesmo;
 *  - **`cb = c;` e `db = d;` como ponteiros de base**: o retail carrega
 *    `addiu $t3,$sp,0x38` e `addiu $t4,$sp,0x50` (as bases de `c` e `d`)
 *    do topo da funcao ate o braco de EDICAO, e computa as bases de `a` e
 *    `b` DENTRO do braco que as usa (`addu $a3,$v0,$v1` com o indice
 *    primeiro). Sem os dois locais o gcc faz o inverso: iça `a` e `b` e
 *    computa `c` no delay slot. Com eles, -5/309 -> -2/268. A posicao da
 *    atribuicao NAO importa (topo, cabeca do braco, cabeca do sub-braco:
 *    identicos, regra 7), e a ordem `db`/`cb` tambem nao.
 *
 * O QUE FALTA -- DUAS instrucoes, censo de magnitude 10:
 *  - `nop -3`: tres delay slots que o retail deixa vazios e nos enchemos;
 *  - `addu -2`: o retail COPIA o ponteiro do halfword (`addu $t0,$v0,$zero`)
 *    antes de o usar em `lhu`/`sh`, e computa `addu $v1,$t1,$v0` para a base
 *    de `b` dentro do braco. Um segundo nome para o ponteiro NAO produz a
 *    copia (duas grafias, `p2` proprio e `p = p2;`, ambas identicas -- o gcc
 *    coalesce, regra 20);
 *  - `sw +1`/`lw +1`: salvamos $s3 alem de $s0-$s2 (moldura 112 contra 104).
 *    O $s3 e usado como TEMPORARIO das copias de struct, onde o retail usa
 *    $t5-$t8 -- isto e, temos um pseudo de vida longa a mais do que ele;
 *  - `addiu +1`: uma base de pilha computada duas vezes;
 *  - `beq +1`/`bne -1`: uma polaridade no rabo, sem efeito no comprimento.
 *
 * IRMAO MAIS LIMPO, GUARDADO: sem `cb`/`db` o candidato e 324/329 e 309,
 * com censo de magnitude SETE e so QUATRO opcodes (`nop -3, addu -2,
 * beq +1, bne -1`) -- nenhum `sw`/`lw`/`addiu` a mais, isto e, sem o $s3
 * extra. As cinco instrucoes que faltam la sao exatamente os tres `nop` e
 * os dois `addu`. Vale voltar a ele se o $s3 nao ceder.
 *
 * MEDIDO E MORTO (com NUMEROS, sobre a base de -1/307 ou -5/309):
 *  - forma indexada `a[i]` no laco de entrada: identico (307);
 *  - forma indexada `b[i]` no laco de carry: -3/278, censo igual;
 *  - `q = (s32 *)(i * 4 + (s32)a)`, `q = a + i` e um local de base `ab`:
 *    os TRES identicos a `&a[i]` (309) -- eixo errado (regra 7);
 *  - `p2` proprio no braco de entrada, e `p2` copiado para `p`: identicos.
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
    s32 *cb;
    u8 *db;
    s32 k;
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
    cb = c;
    db = d;
    t2 = (&D_8009B2C0)[(s8)D_8009B2DC];
    if ((D_8009B2EA & 0x80) == 0) {
        D_8009B2EA = D_8009B2EA | 0x80;
        if ((D_8009B2EA & 0x40) != 0) {
            i = (s8)t2 - 1;
            p = &(&D_8009B2C8)[(s8)D_8009B2DC];
            val = *p;
            q = &a[i];
            *p = 0;
            do {
                k = *q;
                n = val / k;
                q = q - 1;
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
        step = cb[e];
        if (((D_8009B394 | D_8009B396) & 0x4000) != 0) {
            step = -step;
        }
        if ((D_8009B2EA & 0x40) != 0) {
            mask = *(u16 *)(db + e * 2);
            i = e;
            n = (s8)t2;
            if (i < n) {
                q = &b[e];
                do {
                    car = val & mask;
                    val = val & ~mask;
                    car = car + step;
                    if (step >= 0) {
                        if (car < *q) {
                            goto joined;
                        }
                    } else {
                        if (car >= 0) {
                            goto joined;
                        }
                        val = val | ((*q - 1) & mask);
                    }
                    car = 0;
                    mask = mask * 0x10;
                    step = step * 0x10;
                    i = i + 1;
                    q = q + 1;
                } while (i < n);
            }
        joined:
            val = val | car;
        } else {
            val = (val + step) & (cb[(s8)t2] - 1);
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
            if ((s8)D_8009B2DC < (s8)D_8009B2E0) {
                f = (&D_8009B2C0)[(s8)D_8009B2DC] - 1;
                goto setpos;
            }
            D_8009B2DC = D_8009B2E0 - 1;
            D_8009B2E9 = 0;
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
    r = r + i;
    do {
        *r = 0x20;
        i = i - 1;
        r = r - 1;
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
