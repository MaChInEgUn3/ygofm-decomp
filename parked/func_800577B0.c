/* 209/209 -- COMPRIMENTO EXATO -- e 49 diferencas (2026-09-08, segundo tick
 * do dia). Censo VAZIO. Vinha de -12/186 ontem e de -3/171 esta manha.
 *
 * MEDIR COM `as -G0` (nao ha linha em build.py):
 *   echo '{"func_800577B0": {"as": "-G0"}}' > config/flag_overrides.json
 *   .venv/bin/python tools_src/try_func.py func_800577B0 parked/func_800577B0.c
 *   rm -f config/flag_overrides.json      # NUNCA deixar entre turnos
 * gp=0 e seis `lui $at` de D_8009B0F4: o ramo facil da receita, e como o
 * conserto e o -G do ASSEMBLER e nao -mno-split-addresses, a jump table
 * (jtbl_8001179C) sobrevive.
 *
 * O QUE FECHOU O COMPRIMENTO -- TRES INSTANCIAS DE UM MECANISMO SO.
 * Esta funcao tem quatro rabos com as MESMAS instrucoes (o grupo de stores
 * do m1 aparece nos cases 1, 6 e 8; o par `sw 0xC` / `sw 8` aparece no case
 * 2 e no m3). O gcc funde os que terminam identicos; o retail nao funde
 * nenhum deles. O que decide e a ULTIMA instrucao antes do salto:
 *  1. **`do { w = 0x1000; } while (0);` no case 2 e `do { w = 0x800; }
 *     while (0);` no m3** -- sozinho, -3 para **209/209** e 160 -> 53
 *     diferencas. Sem o pino o agendador sobe a constante do `w` para
 *     cobrir o load-delay do D_8009B0F4, os dois bracos passam a terminar
 *     em [sw 0xC][sw 8][lui/lw b0f4] identicos e o cross-jump come os dois
 *     stores do case 2. Com o pino a ultima instrucao e `addiu $v1,0x1000`
 *     contra `addiu $v1,0x800` e nao ha sufixo comum. **Foi a maior
 *     alavanca isolada da funcao inteira.**
 *  2. `do { d = D_8009B118; } while (0);` nos cases 1 e 6, mesma razao um
 *     nivel acima (169 -> 161).
 *  3. Nome PROPRIO para o valor de D_8009B118 do case 8 (`e`, nao o `d`
 *     compartilhado): -5 -> -3. O rabo do case 8 e instrucao-por-instrucao
 *     igual ao do m1 e so os REGISTRADORES o separam no retail, entao dois
 *     nomes sao duas alocacoes e a fusao nao acontece.
 * E o irmao disso, pelo lado da alocacao: **o 0x19000 do case 8 usa o nome
 * `m` da mascara** (bracos mutuamente exclusivos, regra do emprestimo) --
 * poe a constante em $a0 como o retail e da $v1 ao ponteiro; 169 -> 161.
 * E **um nome proprio `g` para o ponteiro do m3** (cases 2, 7, 5/9), que o
 * retail carrega em $v0 enquanto o `b` do m0 vive em $v1: 53 -> 49.
 *
 * ALAVANCAS ANTERIORES (nao desfazer): layout dos bracos na ordem de
 * endereco do retail (os rotulos de juncao vao DEPOIS do braco que cai
 * neles); `one = 1;` no topo do m0, que encurta o sufixo comum com o m2 de
 * duas instrucoes para uma; **um nome para 0x10 e 0x10000** nos cases 1 e 6
 * (regra do func_80020BE4: duas constantes sequenciais no mesmo registrador
 * sao um nome so); `*(s32 *)(p + 0x30) = 0xD810` no case 8 (palavra, nao
 * halfword -- o retail tem `sw` e `ori 55312`); `hun`/`two` atravessando o
 * `jal` no case 6, que sao os $s0/$s1 salvos; locais de base no case 10.
 *
 * MEDIDO E MORTO (com numeros, nao refazer):
 *  - ordem de declaracao de `v` e `b` (0), de `s` e `t` (0 em TRES bases),
 *    ordem de ATRIBUICAO de `s` e `t` (0);
 *  - nomes separados y0..y2 para o segundo grupo de loads do case 10
 *    (0 em TRES bases);
 *  - `do { one = 1; } while (0);` no m0 (0 sobre uma base, pior sobre outra);
 *  - `do { w = ...; } while (0);` no fim dos cases 1 e 6 -- ao contrario dos
 *    cases 2 e 5/9, ali nao vale nada (-5/178);
 *  - `w = 0x30000; d = D_8009B118;` invertido no case 1: BYTE-IDENTICO;
 *  - um so nome para 0x10000 e para o `w` da juncao: funde o registrador mas
 *    dobra o reload de D_8009B0F4;
 *  - `do { *(s16 *)(p + 0x30) = 0; } while (0);` ANTES do `|=`: era o certo
 *    enquanto o comprimento estava errado e agora e +2/172. Instancia limpa
 *    da regra "grafia rejeitada com outra falta aberta e grafia nao medida",
 *    lida ao contrario.
 *
 * O QUE FALTA (49 diferencas, 13 blocos, nenhuma de comprimento):
 *  a) case 10 (~30 delas): $s0/$s1 trocados (retail: $s0 = D_800F2C40,
 *     $s1 = D_801DD000) e o gcc intercala os 4+3 loads com os stores, onde
 *     o retail agrupa 4 loads / 4 stores / 3 loads / 3 stores;
 *  b) o `sh` de p+0x30 (case 1) e de p+0x32 (case 6) cai cinco instrucoes
 *     adiante do lugar do retail, que o poe entre o `lui` da constante e o
 *     `or`;
 *  c) o `ori` da mascara do case 2, o `sw` de p+0x1C do case 6 e o `and` do
 *     m2, cada um uma posicao fora.
 *
 * Dois globais foram declarados para isto: D_80010014 e D_80010018, entradas
 * de ponteiro na mesma tabela do D_80010000.
 */
#define D_8009B0F4_IS_SCALAR
#include "common.h"

void func_8005B620(s32 *dst, s32 *src, s32 n);
void func_80081DE8(s16 *arg0, u8 *arg1);

void func_800577B0(u8 *p, s32 mode) {
    s16 sp[8];
    u8 *b;
    u8 *g;
    u8 *s;
    u8 *t;
    s32 v;
    s32 w;
    s32 n;
    s32 d;
    s32 m;
    s32 e;
    s32 hun;
    s32 two;
    s32 one;
    s32 x0;
    s32 x1;
    s32 x2;
    s32 x3;

    switch (mode) {
    case 0:
        m = 0xFFDCFFFF;
        *(s32 *)(p + 0x1C) = 0x30000;
        v = D_8009B0F4;
        b = D_80010000;
        v = v & m;
        goto m0;

    case 1:
        m = 0xFFDDFFFF;
        *(s16 *)(p + 0x32) = 0x100;
        *(s16 *)(p + 4) = 0x40;
        v = D_8009B0F4;
        n = 0x10;
        *(s16 *)(p + 6) = n;
        D_8009B0F4 = v & m;
        n = 0x10000;
        D_8009B0F4 |= n;
        *(s16 *)(p + 0x30) = 0;
        p[0x46] = 2;
        do { d = D_8009B118; } while (0);
        w = 0x30000;
        goto m1;

    case 2:
        m = 0xFFDCFFFF;
        g = D_801DD000;
        *(s32 *)(p + 0xC) = (s32)g;
        *(s32 *)(p + 8) = (s32)g;
        v = D_8009B0F4;
        do { w = 0x1000; } while (0);
        goto m2;

    case 3:
        sp[1] = 0xF8;
        sp[2] = 0x100;
        sp[0] = 0;
        sp[3] = 8;
        func_80081DE8(&sp[0], D_801DD000);
        m = 0xFFDCFFFF;
        *(s32 *)(p + 0x1C) = 0x5000;
        v = D_8009B0F4;
        b = D_80010014;
        v = v & m;
        goto m0;

    case 4:
        m = 0xFFDCFFFF;
        *(s32 *)(p + 0x1C) = 0x5000;
        v = D_8009B0F4;
        b = D_80010018;
        v = v & m;
    m0:
        one = 1;
        D_8009B0F4 = v;
        *(s32 *)(p + 0xC) = (s32)b;
        *(s32 *)(p + 8) = (s32)b;
        p[0x46] = one;
        return;

    case 6:
        hun = 0x100;
        two = 2;
        sp[4] = hun;
        sp[5] = 0xF0;
        sp[6] = hun;
        sp[7] = two;
        func_80081DE8(&sp[4], D_801DD000);
        m = 0xFFDDFFFF;
        *(s16 *)(p + 0x30) = 0x180;
        *(s16 *)(p + 4) = 0x40;
        v = D_8009B0F4;
        n = 0x10;
        *(s16 *)(p + 6) = n;
        D_8009B0F4 = v & m;
        n = 0x10000;
        D_8009B0F4 |= n;
        *(s16 *)(p + 0x32) = hun;
        p[0x46] = two;
        do { d = D_8009B118; } while (0);
        w = 0x4000;
    m1:
        *(s32 *)(p + 0x1C) = w;
        *(s32 *)(p + 8) = d;
        *(s32 *)(p + 0xC) = d + 0x800;
        return;

    case 7:
        m = 0xFFDCFFFF;
        g = D_801A8000;
        goto m3;

    case 8:
        m = 0x19000;
        p[0x46] = 3;
        e = D_8009B118;
        *(s32 *)(p + 0x30) = 0xD810;
        *(s32 *)(p + 0x1C) = m;
        *(s32 *)(p + 8) = e;
        *(s32 *)(p + 0xC) = e + 0x800;
        return;

    case 5:
    case 9:
        m = 0xFFDCFFFF;
        g = D_801DD000;
    m3:
        *(s32 *)(p + 0xC) = (s32)g;
        *(s32 *)(p + 8) = (s32)g;
        v = D_8009B0F4;
        do { w = 0x800; } while (0);
    m2:
        *(s32 *)(p + 0x1C) = w;
        D_8009B0F4 = v & m;
        p[0x46] = 1;
        return;

    case 10:
        s = D_800F2C40;
        t = D_801DD000;
        func_8005B620((s32 *)(s + 0xBF8), (s32 *)t, 0x40);
        x0 = *(s32 *)(t + 0x100);
        x1 = *(s32 *)(t + 0x104);
        x2 = *(s32 *)(t + 0x108);
        x3 = *(s32 *)(t + 0x10C);
        *(s32 *)(s + 0xCF8) = x0;
        *(s32 *)(s + 0xCFC) = x1;
        *(s32 *)(s + 0xD00) = x2;
        *(s32 *)(s + 0xD04) = x3;
        x0 = *(s32 *)(t + 0x110);
        x1 = *(s32 *)(t + 0x114);
        x2 = *(s32 *)(t + 0x118);
        *(s32 *)(s + 0xD08) = x0;
        *(s32 *)(s + 0xD0C) = x1;
        *(s32 *)(s + 0xD10) = x2;
        *(s32 *)(s + 0xD08) = -1;
        *(s32 *)(s + 0xD0C) = -1;
        *(s32 *)(s + 0xD10) = -1;
        *(s16 *)(s + 0xCF8) = 0;
        *(s16 *)(s + 0xCFA) = 0;
        s[0xE14] = 1;
        return;
    }
}
