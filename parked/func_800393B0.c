/* 249/249 -- COMPRIMENTO EXATO -- e 139 diferencas, censo `lb +1, addu +1,
 * sll +1` (2026-09-08, primeiro dia). Flags PADRAO (passo 0: gp=13, at=0,
 * sem `break`, sem jump table).
 *
 * FORMA: passo de uma maquina de estados de sequenciador. Um braco de
 * INICIALIZACAO sob `if ((flags & 0x4000) == 0)` contra um braco de PASSO;
 * tres tabelas de ponteiro de funcao chamadas indiretamente (D_80090C50 por
 * D_8009B27C, D_80090E64 por `unk51 & 0x1F`, D_80090F18 por
 * `(s16)D_8009B33A - 0xF0`), e um laco `while (1)` com tres saidas.
 *
 * AS QUATRO LEITURAS QUE LEVARAM -7/203 A 0/139:
 *  1. **D_8009B33A e VOLATILE.** O retail faz `sh` e logo em seguida `lhu`
 *     do mesmo simbolo no MESMO bloco -- o gcc encaminharia o valor -- e le
 *     `lhu` seguido de `sll 16`/`sra 16` onde um `u16` normal daria `lh`
 *     numa instrucao so. -7 -> 0 e 203 -> 157 numa palavra.
 *  2. **A largura do banco e `u16`, nao `s32`.** Sozinha a mudanca para
 *     `s32` e -9; junto com o volatile e -2 e depois -1. As comparacoes do
 *     retail sao `slt` com sinal sobre o valor ja estendido pelo `lhu`.
 *  3. **A mascara 0xFFFF0000 tem UM NOME ATRIBUIDO EM CADA BRACO.** O
 *     retail materializa `lui $a0,0xFFFF` duas vezes -- uma no delay slot do
 *     `j` do primeiro braco e outra dentro do segundo -- e com a mascara
 *     escrita inline na juncao ela sai uma vez so, na cabeca da juncao.
 *     -2 -> -1 e 201 -> 159.
 *  4. **D_8009B27C usa o braco de ARRAY.** O retail le o byte com
 *     `lui %hi`/`lbu %lo` e o halfword com outro par; o braco escalar da
 *     um `lbu` gp-relativo numa instrucao so, que era a ultima falta de
 *     comprimento. -1 -> 0 e 159 -> 139.
 * Os dois simbolos de tabela D_80090E64 e D_80090F18 sao novos em
 * variables.h (`ObjFn[]`), e func_800391E4 ganhou prototipo em functions.h.
 *
 * O QUE FALTA: 139 diferencas com censo `lb +1, addu +1, sll +1` -- tres
 * opcodes, todos no braco do passo. Ordem dos dois primeiros bracos do
 * banco: com `d` antes de `b` sao 141, com `b` antes de `d` 139 (instalado),
 * embora o retail materialize `d` primeiro -- re-medir quando o resto
 * fechar.
 */
#define D_8009B27C_IS_AGGREGATE
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
    Rec1C *r;
    ObjFn *t;
    s32 c;

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
            v = ((s32)b & m) + *(u16 *)(b + (n + d) * 2);
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
        D_80090C50[*(u8 *)D_8009B27C]();
        if (D_8009B27C[0] == 0) {
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
    while (1) {
        q = *(u8 **)(p + (s8)p[0x58] * 4);
        D_8009B33A = *q;
        *(u8 **)(p + (s8)p[0x58] * 4) = q + 1;
        if ((s16)D_8009B33A < 0xF0) {
            break;
        }
        D_8009B350 = 0;
        t[(s16)D_8009B33A - 0xF0](p);
        if (D_8009B350 < 0) {
            break;
        }
        if (D_8009B350 == 1) {
            return;
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
