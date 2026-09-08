/* 249/249 -- COMPRIMENTO EXATO -- e 18 diferencas, censo `nop -1, lw +1`
 * (2026-09-08, primeiro dia). Flags PADRAO (passo 0:
 * gp=13, at=0, sem `break`, sem jump table). Veio de -7/203 -> 0/139 -> +1/92 -> 0/23 -> 0/18
 * no mesmo dia.
 *
 * FORMA: passo de uma maquina de estados de sequenciador. Um braco de
 * INICIALIZACAO sob `if ((flags & 0x4000) == 0)` contra um braco de PASSO;
 * tres tabelas de ponteiro de funcao chamadas indiretamente (D_80090C50 por
 * D_8009B27C, D_80090E64 por `unk51 & 0x1F`, D_80090F18 por
 * `(s16)D_8009B33A - 0xF0` atraves de um LOCAL DE BASE, que e o que poe o
 * -0x3C0 no deslocamento do `lw`), e um laco escrito com `goto`.
 *
 * AS SETE LEITURAS, na ordem em que foram medidas:
 *  1. **D_8009B33A e VOLATILE.** O retail faz `sh` e logo em seguida `lhu`
 *     do mesmo simbolo no MESMO bloco -- o gcc encaminharia -- e le `lhu` +
 *     `sll 16` + `sra 16` onde um `u16` normal daria um `lh` numa instrucao
 *     so. -7/203 -> 0/157 numa palavra.
 *  2. **A largura do banco e `u16`, nao `s32`**: sozinha a troca para `s32`
 *     e -9, e junto com o volatile -2. As comparacoes do retail sao `slt`
 *     com sinal sobre o valor ja estendido pelo `lhu`.
 *  3. **A mascara 0xFFFF0000 tem UM NOME ATRIBUIDO EM CADA BRACO.** O retail
 *     materializa `lui $a0,0xFFFF` duas vezes, uma no delay slot do `j` do
 *     primeiro braco e outra dentro do segundo; escrita inline na juncao ela
 *     sai uma vez so, na cabeca da juncao. -2/201 -> -1/159.
 *  4. **D_8009B27C** primeiro no braco de ARRAY (-1/159 -> 0/139) e depois,
 *     ver 6, no braco `.data`.
 *  5. **O endereco do slot do cursor e UM LOCAL.** `*(u8 **)(p + (s8)p[0x58]
 *     * 4)` escrito duas vezes (para ler e para gravar `q + 1`) da `lb`,
 *     `sll` e `addu` duplicados; o retail calcula o endereco UMA vez em $a0
 *     e usa `lw 0($a0)` e `sw 0($a0)`. Censo de tres opcodes para dois.
 *  6. **D_8009B27C na FORMA NUA (`_IN_DATA`).** O retail materializa
 *     `%hi(D_8009B27C)` DUAS vezes, uma para o byte e outra para o halfword;
 *     no braco de array o gcc faz CSE do `%hi` para dentro de um
 *     callee-saved a mais. Censo de dois opcodes para um.
 *  7. **O LACO E ESCRITO COM `goto`, nao com `while (1)`.** O retail
 *     materializa o literal 1 (a comparacao `D_8009B350 == 1`) DENTRO do
 *     laco a cada iteracao; com `while (1)` o gcc o iça para $s2, um
 *     callee-saved a mais. Um laco de rotulo e `goto` nao carrega as
 *     NOTE_INSN_LOOP do gcc 2.8, entao nao ha movimento de invariante.
 *     +1/203 -> -2/80, e a queda de diferencas e a maior da funcao.
 *  8. **D_8009B350 e VOLATILE**: o retail le o simbolo DUAS vezes depois da
 *     chamada indireta (`lw`, `bltz`, `nop`, `lw` de novo) e o gcc faz CSE
 *     das duas. -2/80 -> +1/92 e o censo de dois opcodes para UM.
 *
 *  9. **A LEITURA NOMEADA DO VALOR TESTADO E A RE-LEITURA DO SLOT.** O
 *     retail poe `sw $v1,0($a0)` no delay slot do `bne` e deixa um `nop`
 *     no delay slot do `lbu`; com `*a = q + 1;` o gcc emite o store cedo
 *     demais e o delay slot do `bne` fica vazio. Duas edicoes juntas
 *     resolvem: `w = (s16)D_8009B33A;` entre o store do global e o
 *     incremento (+1/92 -> -1/86) e `*a = *a + 1;` em vez de `*a = q + 1;`
 *     (-1/86 -> 0/23). MEDIDO E MORTO no mesmo eixo: o incremento antes do
 *     store do global (+1/92), depois do store e antes da leitura nomeada
 *     (+1/92), `*a = &q[1];` (-1/86), `q++; *a = q;` (-1/86), `*a = q + 1;`
 *     seguido de `q = q + 1;` (-1/86) e `D_8009B33A = *(*a)++;` (+1/92).
 *
 * 10. **A LEITURA DA TABELA DE BANCO E UM NOME, E A MASCARA E APLICADA NA
 *     PROPRIA BASE.** `v = *(u16 *)(b + (n + d) * 2); b = (u8 *)((s32)b &
 *     m); v = (s32)b + v;` e 23 -> 18. MEDIDO E MORTO no mesmo bloco: so o
 *     nome da leitura sem a mascara na base (20), `d` antes de `b` no
 *     primeiro braco (25 na base antiga, 23 nesta), nomear tambem a leitura
 *     do TERCEIRO braco (37), as duas juntas (38), `d` antes de `b` nos dois
 *     bracos (-1 e 215), e acumular o resultado inteiro dentro de `b` com o
 *     store final em `(s32)b` (36, e 37 com `d` primeiro).
 *
 * O QUE FALTA: 18 diferencas, censo `nop -1, lw +1`, em dois grupos.
 *  - a cabeca do laco (indices 170 a 185): a re-leitura do slot custa um
 *    `lw` que o retail nao tem e falta o `nop` do delay slot do `lbu`; o
 *    resto e so o registrador do endereco ($a0 no retail, $v1 aqui);
 *  - o bloco de selecao de banco (indices 33 a 43, 52, 65 e 67): o retail
 *    materializa `d` antes da base `b` e acumula em $v1, e nenhuma das seis
 *    grafias medidas alcanca isso.
 * EIXO DE FLAGS FECHADO por sweep_try (27 linhas): o padrao O2 G8 e o
 * melhor com 18; as G0 231, as G2 226, `-mno-split-addresses` 252, O1 265.
 * Novos em variables.h: D_80090E64 e D_80090F18 (`ObjFn[]`) e o braco
 * `D_8009B27C_IN_DATA`; func_800391E4 ganhou prototipo em functions.h.
 */
#define D_8009B27C_IN_DATA
#define D_8009B350_IS_VOLATILE
#define D_8009B33A_IS_VOLATILE
#define D_8009B3A4_IS_AGGREGATE
#define D_8009B398_IS_AGGREGATE
#include "common.h"

void func_800393B0(u8 *p) {
    u16 f;
    s32 n;
    s32 v;
    s32 d;
    s32 m;
    u8 *b;
    u8 *q;
    u8 **a;
    Rec1C *r;
    ObjFn *t;
    s32 c;
    s32 w;

    f = *(u16 *)(p + 0x34);
    if ((f & 0x4000) == 0) {
        f = f | 0x4000;
        *(u16 *)(p + 0x34) = f;
        if ((f & 2) == 0) {
            func_80039E9C();
        }
        if ((*(u16 *)(p + 0x34) & 0x100) != 0) {
            p[0x5B] = 8;
            p[0x5A] = 8;
        }
        n = *(u16 *)(p + 0x36);
        D_8009B357 = 0;
        D_8009B340 = (ObjFn)0;
        p[0x52] = 1;
        p[0x60] = 0;
        p[0x58] = 0;
        if (0xCFFF < n) {
            b = D_801C0000;
            d = 0xFFFF3000;
            m = 0xFFFF0000;
            goto join;
        }
        if (0x7FFF < n) {
            b = D_801D5800;
            m = 0xFFFF0000;
            d = -0x8000;
        join:
            v = *(u16 *)(b + (n + d) * 2);
            b = (u8 *)((s32)b & m);
            v = (s32)b + v;
        } else {
            if (n >= 0x500) {
                n = n - 0x100;
            }
            v = ((s32)D_801B0000 & 0xFFFF0000) + *(u16 *)(D_801C0000 + n * 2);
        }
        *(s32 *)p = v;
        p[0x56] = 0;
        p[0x51] = 0;
        func_8004036C(*(s32 *)(p + 0x30));
        func_8004036C(*(s32 *)(p + 0x2C));
        *(s32 *)(p + 0x30) = 0;
        *(s32 *)(p + 0x2C) = 0;
        func_800391E4(p);
        if ((*(u16 *)(p + 0x34) & 0x40) == 0) {
            r = &D_800EB288[*(u16 *)(p + 0x5C)];
            *(Rec1C **)(p + 0x24) = r;
            *(Rec1C **)(p + 0x20) = r;
            func_80035CA8(p[0x57]);
            func_80035DB8(p[0x57]);
        }
        return;
    }
    if (D_8009B357 != 0) {
        D_80090C50[*(u8 *)&D_8009B27C]();
        if (D_8009B27C == 0) {
            D_8009B357 = 0;
        }
    }
    if (p[0x51] != 0) {
        D_80090E64[p[0x51] & 0x1F](p);
        *(u16 *)(p + 0x34) = *(u16 *)(p + 0x34) & 0xFBFF;
        return;
    }
    if ((*(u16 *)(p + 0x34) & 0x1C00) == 0) {
        if ((D_8009B3A4[0] & 0x80) || (D_8009B398[0] & 0xC0)) {
            func_800373C8(p, 0, 0);
            p[0x52] = 1;
            *(u16 *)(p + 0x34) = *(u16 *)(p + 0x34) | 0x400;
        }
        p[0x52] = p[0x52] - 1;
        if (p[0x52] != 0) {
            return;
        }
    }
    p[0x52] = p[0x53];
    t = D_80090F18;
top:
    a = (u8 **)(p + (s8)p[0x58] * 4);
    q = *a;
    D_8009B33A = *q;
    w = (s16)D_8009B33A;
    *a = *a + 1;
    if (w >= 0xF0) {
        D_8009B350 = 0;
        t[(s16)D_8009B33A - 0xF0](p);
        if (D_8009B350 >= 0) {
            if (D_8009B350 == 1) {
                return;
            }
            goto top;
        }
    }
    if (func_80037C74(p) != 0) {
        p[0x51] = 4;
        return;
    }
    D_8009B35A = D_8009B33A;
    func_80036C14(p, D_801D9000[(s16)D_8009B33A] & 0x8FF0FFFF);
    c = p[0x60] + 1;
    p[0x60] = c;
    if (p[0x61] != 0 && (u8)c >= p[0x61]) {
        *(u16 *)(p + 0x34) = *(u16 *)(p + 0x34) | 0x2000;
    }
    *(u16 *)(p + 0x38) = *(u16 *)(p + 0x38) + p[0x5A];
}
