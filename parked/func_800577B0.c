/* 209/209 -- COMPRIMENTO EXATO -- e 31 diferencas, em 9 blocos (2026-09-08).
 * Censo VAZIO. Trajetoria: -12/186 -> -3/171 -> 209/209 e 49 -> 45 -> 31.
 *
 * MEDIR COM `as -G0` (nao ha linha em build.py):
 *   echo '{"func_800577B0": {"as": "-G0"}}' > config/flag_overrides.json
 *   .venv/bin/python tools_src/try_func.py func_800577B0 parked/func_800577B0.c
 *   rm -f config/flag_overrides.json      # NUNCA deixar entre turnos
 * gp=0 e seis `lui $at` de D_8009B0F4; o conserto e o -G do ASSEMBLER e nao
 * -mno-split-addresses, entao a jump table (jtbl_8001179C) sobrevive.
 *
 * DUAS FAMILIAS DE ALAVANCA RESOLVERAM ESTA FUNCAO INTEIRA.
 *
 * (1) `do { UMA COISA } while (0);` -- oito usos, tres papeis distintos:
 *   a) **impedir o agendador de subir a constante do `w`**, e com isso
 *      impedir um cross-jump que o retail nao faz. `do { w = 0x1000; }
 *      while (0);` no case 2 e `do { w = 0x800; } while (0);` no m3 levaram
 *      sozinhos de -3/160 para **209/209 e 53**: sem eles os dois bracos
 *      terminam em [sw 0xC][sw 8][lui/lw b0f4] identicos e o gcc come os
 *      dois stores do case 2. Mesma coisa com `do { d = D_8009B118; }
 *      while (0);` nos cases 1 e 6 (169 -> 161).
 *   b) **pinar UM store de p+0x1C** nas duas juncoes: no m2 e 45 -> 43 e no
 *      m1 e 42 -> 39, cada um valendo por si.
 *   c) os QUATRO grupos do case 10, que dao exatamente os 4 loads / 4 stores
 *      / 3 loads / 3 stores do retail; sem eles o agendador intercala tudo
 *      num pipeline rolante de tres registradores.
 *
 * (2) EMPRESTIMO DE NOME ENTRE BRACOS MUTUAMENTE EXCLUSIVOS -- quatro usos:
 *   - **um nome para 0x10 e 0x10000** nos cases 1 e 6 (o retail carrega os
 *     dois no mesmo $v1; regra do func_80020BE4);
 *   - o 0x19000 do case 8 usa o nome `m` da mascara, o que o poe em $a0 como
 *     o retail e da $v1 ao ponteiro (169 -> 161);
 *   - nome PROPRIO (`e`) para o D_8009B118 do case 8: o rabo dele e
 *     instrucao-por-instrucao igual ao do m1 e no retail so os registradores
 *     o separam, entao dois nomes sao duas alocacoes e a fusao nao acontece;
 *   - o D_801DD000 do CASE 10 usa o `g` do m3 (48 -> 45), o que troca $s0 e
 *     $s1 para os do retail. **CONTRAPESO explicito**: o preco e `g`
 *     callee-saved nos tres bracos do m3, onde o retail o quer em $v0. Foi
 *     RE-MEDIDO na base limpa (rule 3) e continua valendo: desfaze-lo e 34
 *     contra 31, e passar para o `b` do m0 e 35.
 *
 * A ULTIMA ALAVANCA, e a maior depois do comprimento: **partir o segundo
 * read-modify-write com uma leitura NOMEADA, com o `sh` no meio.**
 * `n = 0x10000; v = D_8009B0F4; *(s16 *)(p + 0x30) = 0; D_8009B0F4 = v | n;`
 * e 39 -> **31**, porque o retail emite [reload][lui n][sh][or] e nenhuma
 * posicao do `sh` em torno de um `|=` compacto chega la: antes do `|=` ele
 * sai tres instrucoes cedo, depois cinco tarde, e pinado com
 * `do { } while (0)` e +2 (quebra o cross-jump que segura o comprimento).
 * Nome emprestado (`v`, morto ali) e nome fresco dao o MESMO 31.
 *
 * OUTRAS QUE VALERAM: layout dos bracos na ordem de endereco do retail (os
 * rotulos de juncao vao DEPOIS do braco que cai neles); `one = 1;` no topo
 * do m0, que encurta o sufixo comum com o m2 de duas instrucoes para uma;
 * `*(s32 *)(p + 0x30) = 0xD810` no case 8 (PALAVRA -- `sw` e `ori 55312`);
 * `hun`/`two` atravessando o `jal` no case 6, que sao os $s0/$s1 salvos;
 * locais de base no case 10.
 *
 * MEDIDO E MORTO, COM NUMEROS (nao refazer):
 *  - PERMUTER: 580 iteracoes, -j 2, oito saidas. O melhor score dele (880)
 *    re-mede 58 com -1 de comprimento, e o melhor por try_func e 49 -- pior
 *    que a base de 45 que ele recebeu. Terceira confirmacao da regra 8. As
 *    duas ideias legiveis nos diffs: escrever D_801DD000 inline como
 *    argumento da chamada (contraria o `addu $a1,$s1,$zero` do retail) e
 *    emprestar um `x1 = 0x40` do case 6 para o terceiro argumento -- nenhuma
 *    das duas move nada sozinha;
 *  - `neg = -1;` nomeado logo depois do `jal` do case 10, com e sem pino,
 *    sobre TRES bases: 49, 49, 49, 49, 35, 35. Emprestar o `w` para ele: 41;
 *  - case 10 emprestando `b` (56, 49, 35), `two` (47), `hun`+`two` (47),
 *    `e` (46) para os locais de base;
 *  - ordem de declaracao de `s` e `t`, ordem de ATRIBUICAO, e as duas
 *    juntas: 48, 48, 48 -- tres grafias iguais, eixo errado;
 *  - `t` declarado por ultimo (48), `t` atribuido antes do `switch` (189);
 *  - nomes separados y0..y2 para o segundo grupo de loads (0 em QUATRO
 *    bases);
 *  - `do { one = 1; } while (0);` no m0 (0 numa base, pior noutra);
 *  - `do { w = ...; } while (0);` no fim dos cases 1 e 6 -- ao contrario dos
 *    cases 2 e 5/9, ali nao vale nada (-5/178);
 *  - `w = 0x30000; d = D_8009B118;` invertido no case 1: BYTE-IDENTICO;
 *  - um so nome para 0x10000 e para o `w` da juncao: funde o registrador mas
 *    dobra o reload de D_8009B0F4;
 *  - `do { D_8009B0F4 |= n; } while (0);` e `do { n = 0x10000; } while (0);`
 *    nos cases 1 e 6: +2 os dois.
 *
 * O QUE FALTA (31 diferencas, 9 blocos, duas causas):
 *  a) case 10, ~14 delas: os quatro registradores dos loads sao
 *     $v1/$a0/$a1/$v0 e o retail usa $a3/$t0/$t1/$t2, poupando $v0 -- que
 *     ele mantem com o -1 vivo desde logo depois do `jal`. Nenhuma grafia
 *     do -1 chega la;
 *  b) o contrapeso: `g` em $s1 nos tres bracos do m3 onde o retail o quer em
 *     $v0 (e com ele o `ori` da mascara do case 2, uma posicao fora).
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
        v = D_8009B0F4;
        *(s16 *)(p + 0x30) = 0;
        D_8009B0F4 = v | n;
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
        v = D_8009B0F4;
        *(s16 *)(p + 0x32) = hun;
        D_8009B0F4 = v | n;
        p[0x46] = two;
        do { d = D_8009B118; } while (0);
        w = 0x4000;
    m1:
        do { *(s32 *)(p + 0x1C) = w; } while (0);
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
        do { *(s32 *)(p + 0x1C) = w; } while (0);
        D_8009B0F4 = v & m;
        p[0x46] = 1;
        return;

    case 10:
        s = D_800F2C40;
        g = D_801DD000;
        func_8005B620((s32 *)(s + 0xBF8), (s32 *)g, 0x40);
        do {
            x0 = *(s32 *)(g + 0x100);
            x1 = *(s32 *)(g + 0x104);
            x2 = *(s32 *)(g + 0x108);
            x3 = *(s32 *)(g + 0x10C);
        } while (0);
        do {
            *(s32 *)(s + 0xCF8) = x0;
            *(s32 *)(s + 0xCFC) = x1;
            *(s32 *)(s + 0xD00) = x2;
            *(s32 *)(s + 0xD04) = x3;
        } while (0);
        do {
            x0 = *(s32 *)(g + 0x110);
            x1 = *(s32 *)(g + 0x114);
            x2 = *(s32 *)(g + 0x118);
        } while (0);
        do {
            *(s32 *)(s + 0xD08) = x0;
            *(s32 *)(s + 0xD0C) = x1;
            *(s32 *)(s + 0xD10) = x2;
        } while (0);
        *(s32 *)(s + 0xD08) = -1;
        *(s32 *)(s + 0xD0C) = -1;
        *(s32 *)(s + 0xD10) = -1;
        *(s16 *)(s + 0xCF8) = 0;
        *(s16 *)(s + 0xCFA) = 0;
        s[0xE14] = 1;
        return;
    }
}
