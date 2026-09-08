/* 328/329 -- UMA instrucao a menos -- e 307 diferencas, censo de magnitude 27
 * (2026-09-08). Veio de -23/325 -> -3/314 -> -1/307. Flags PADRAO (passo 0: gp=34, at=0, sem jump table, sem GTE).
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
 *    alinhamento de 8 que o gcc da a um ARRAY local de oito bytes ou mais:
 *    0x10+20 = 0x24 sobe para 0x28, e 0x38+20 = 0x4C sobe para 0x50. Os
 *    quatro locais sao arrays, e a ordem de declaracao e a ordem dos
 *    offsets;
 *  - os tres primeiros sao COPIAS DE STRUCT de D_80010250 (5 palavras),
 *    D_80010264 (4) e D_80010274 (5) -- o padrao do expand_block_move. O
 *    quarto e uma copia com `lwl`/`lwr` e `swl`/`swr` de D_8009AF4C, isto e,
 *    um objeto de ALINHAMENTO 1 (typedef com `u8 b[8]`);
 *  - `break 7` e `break 6` sao uma DIVISAO REAL com divisor VARIAVEL, lido
 *    de uma tabela percorrida de tras para frente;
 *  - **o retail LE UM REGISTRADOR NAO INICIALIZADO**: em `.L800305BC` faz
 *    `or $a1,$a1,$a3` e, no caminho em que o laco nunca roda, `$a3` nunca
 *    foi escrito naquele braco. A fonte tinha um carry atribuido so dentro
 *    do laco e lido depois -- escrito assim, e o unico caso em que essa
 *    classe e legitima;
 *  - `func_8007EF84` e da familia do sprintf (docs/LIBRARY_FUNCS.txt) e nao
 *    leva prototipo: e chamado com 1, 2 e 4 argumentos.
 *
 * MEDIDO:
 *  - os SEIS halfwords de flags (D_8009B394, 396, 398, 39A, 3A4, 3A6) na
 *    FORMA NUA (`_IN_DATA`) valem cinco instrucoes: o retail materializa um
 *    `lui %hi` para cada uma das 28 referencias, sem CSE. -28/325 -> -23/325;
 *  - **e os mesmos seis tambem VOLATILE (`_IN_DATA_VOLATILE`) valem VINTE**:
 *    -23/325 -> -3/314, censo de magnitude 45 para 29. A forma nua separa os
 *    `lui`, mas nao impede o gcc de fazer CSE do VALOR carregado entre dois
 *    `if` seguidos -- o retail re-le o halfword em cada teste. Sao as duas
 *    metades de uma alavanca so, e nenhuma sozinha chega la. Tres bracos
 *    novos (`D_8009B396_IN_DATA_VOLATILE`, `D_8009B39A_IN_DATA_VOLATILE`,
 *    `D_8009B3A6_IN_DATA_VOLATILE`); B394, B398 e B3A4 ja tinham o seu;
 *  - D_800EAED8 na forma nua com tipo COMPLETO `[0x28]`: NAO muda nada. O
 *    retail materializa `%hi(D_800EAED8)` treze vezes, mas os usos tomam o
 *    ENDERECO COMO VALOR, e para isso o cc1psx emite o par proprio dele com
 *    ou sem o atributo de secao, e o gcc faz CSE desse par (regra 45 do
 *    outro lado). Um ponteiro de base nomeado como PRIMEIRA coisa do bloco
 *    `fill` tambem nao muda nada (-3/314), e usa-lo tambem no segundo
 *    endereco e pior (-6/313).
 *
 * QUARTA RODADA -- A LARGURA DE `val` E `mask`:
 *  - `val` declarado `s32` em vez de `u16` e -2/286 (contra -1/307), censo
 *    de magnitude 27 para 22, com `lhu` e `or` zerados. `mask` como `s32` da
 *    exatamente o mesmo (-2/286), e os DOIS juntos sao -4/323, muito pior.
 *    NAO INSTALADO porque a regra de ordenacao poe |erro de comprimento|
 *    primeiro e a base esta em -1 -- mas a diferenca de comprimento e de UMA
 *    instrucao e as duas contagens estao infladas por erros de comprimento
 *    diferentes, entao **RE-MEDIR `s32 val` assim que o comprimento fechar**;
 *  - o alinhamento mostra a raiz do que sobra: com o local do buffer, o gcc
 *    iça `lui`/`addiu %lo(D_800EAED8)` e as DUAS bases de array da pilha
 *    (`addiu $t1,$sp,16` e `addiu $t5,$sp,40`) para o topo da funcao, quatro
 *    instrucoes que o retail nao tem la -- ele computa cada base dentro do
 *    braco que a usa. E dai que vem o $s3 a mais.
 *
 * O QUE FALTA: UMA instrucao e censo de magnitude 27 (`lui -7, addiu +4,
 * andi +3, nop -3, lhu +2, lw -1, addu -1, bne -1, bltz -1, or +1, beq +1,
 * bgez +1, sw +1`). Os `lui -5` que sobram sao de D_800EAED8: o retail
 * copia o `lui` do bloco `fill` para o delay slot de cada desvio que salta
 * para la (regra 31), e o nosso bloco `fill` comeca com outra instrucao.
 * Ainda salvamos $s3 alem de $s0-$s2 (moldura 112 contra 104).
 * Seis declaracoes novas em variables.h (D_80010250, D_80010264, D_80010274,
 * D_8009AF4C, D_8009AF58, D_800EAED8) e seis bracos novos.
 *
 * MAIS UMA ALAVANCA E OITO NEGATIVOS (terceira rodada):
 *  - **o endereco de D_800EAED8 num local atribuido ANTES DE TODA a cadeia
 *    de `if`** (regra 44): -3/314 -> -1/307, censo de 29 para 27 e `lui` de
 *    -5 para -7... quer dizer, a contagem de `lui` PIOROU e mesmo assim o
 *    candidato ficou melhor, o que so o comprimento e a contagem mostram.
 *    Usar o mesmo local tambem no segundo endereco e -4/306: um a menos de
 *    diferenca mas tres instrucoes mais curto, entao NAO instalado;
 *  - MEDIDO E MORTO no bloco `fill`, SETE grafias, todas 314 com -3 ou -4:
 *    laco indexado `D_800EAED8[i] = 0x20;`, ponteiro de base como primeira
 *    linha, `&D_800EAED8[0x27]` direto, a ordem `ch`/`i`/`r`, e as tres
 *    versoes pinadas com `do { } while (0);` (base sozinha, base ja somada,
 *    base mais a constante). O `lui` que o retail poe no delay slot de cada
 *    desvio que salta para o `fill` NAO vem da forma do bloco.
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
    s32 k;
    u16 *p;
    u16 val;
    u16 mask;
    u8 t2;
    u8 f;
    u8 *r;
    u8 *z;

    ret = 0;
    z = D_800EAED8;
    *(Blk14 *)a = *(Blk14 *)D_80010250;
    *(Blk10 *)b = *(Blk10 *)D_80010264;
    *(Blk14 *)c = *(Blk14 *)D_80010274;
    *(Blk8 *)d = *(Blk8 *)D_8009AF4C;
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
        step = c[e];
        if (((D_8009B394 | D_8009B396) & 0x4000) != 0) {
            step = -step;
        }
        if ((D_8009B2EA & 0x40) != 0) {
            mask = *(u16 *)(d + e * 2);
            i = e;
            n = (s8)t2;
            if (i < n) {
                q = &b[e];
                do {
                    car = val & mask;
                    val = val & ~mask;
                    car = car + step;
                    if (step < 0) {
                        if (car >= 0) {
                            goto joined;
                        }
                        val = val | ((*q - 1) & mask);
                    } else if (car < *q) {
                        goto joined;
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
    i = 0x27;
    r = z + i;
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
