/* MATCH (2026-09-08). Dois dias: -12/186 -> -3/171 -> 49 -> 45 -> 31 -> 16
 * -> 7 -> 0. Despachante da familia D_8009B0F4 com jump table real
 * (jtbl_8001179C); assembla com `as -G0` (PER_FUNC_AS_FLAGS em build.py):
 * gp=0 e seis `lui $at`, o ramo facil da receita, e como o conserto e o -G
 * do ASSEMBLER e nao -mno-split-addresses, a jump table sobrevive.
 *
 * As quatro alavancas que a fecharam, na ordem em que renderam:
 *
 * 1. LAYOUT DOS BRACOS NA ORDEM DE ENDERECO DO RETAIL -- os rotulos de
 *    juncao vao DEPOIS do braco que cai neles (m0 depois do case 4, m1
 *    depois do case 6, m3/m2 depois do case 5/9), nao dentro do primeiro
 *    braco que salta.
 *
 * 2. `do { UMA COISA } while (0);` -- nove usos em QUATRO papeis distintos,
 *    e esta funcao e o caso de referencia do idioma:
 *    a) impedir o agendador de subir a constante de uma juncao, e com isso
 *       impedir um cross-jump que o retail nao faz. A funcao tem quatro
 *       rabos com as MESMAS instrucoes (o grupo de stores do m1 nos cases 1,
 *       6 e 8; o par `sw 0xC`/`sw 8` no case 2 e no m3); o gcc funde os que
 *       TERMINAM identicos e quem decide e a ULTIMA instrucao antes do
 *       salto. `do { w = 0x1000; } while (0);` no case 2 e
 *       `do { w = 0x800; } while (0);` no m3 sozinhos levaram de -3 para
 *       COMPRIMENTO EXATO;
 *    b) pinar UM store de p+0x1C em cada juncao (45 -> 43 no m2, 42 -> 39
 *       no m1);
 *    c) manter o par `lui`/`ori` de uma constante de 32 bits adjacente --
 *       `do { m = 0xFFDCFFFF; } while (0);` no case 2 foi a ULTIMA
 *       diferenca, 7 -> MATCH. Sem ele o agendador larga o `ori` seis
 *       instrucoes adiante. Escrever a mascara depois do ponteiro em vez de
 *       pinar e 8, ou seja, nao e ordem: e o pino;
 *    d) (retirado no fim) agrupar loads e stores -- ver o ponto 4.
 *
 * 3. EMPRESTIMO DE NOME ENTRE BRACOS MUTUAMENTE EXCLUSIVOS, tres usos que
 *    sobreviveram: um nome para 0x10 e 0x10000 nos cases 1 e 6 (o retail
 *    carrega os dois no mesmo $v1); o 0x19000 do case 8 usando o nome da
 *    mascara, que o poe em $a0; e um nome PROPRIO para o D_8009B118 do case
 *    8, cujo rabo e instrucao-por-instrucao igual ao do m1 e no retail so os
 *    registradores o separam.
 *    E PARTIR UM READ-MODIFY-WRITE COM UMA LEITURA NOMEADA para poder por um
 *    store no meio: `n = 0x10000; v = D_8009B0F4; *(s16 *)(p + 0x30) = 0;
 *    D_8009B0F4 = v | n;` foi 39 -> 31, porque o retail emite
 *    [reload][lui n][sh][or] e nenhuma posicao do `sh` em torno de um `|=`
 *    compacto chega la.
 *
 * 4. **O CASE 10 E UMA COPIA DE STRUCT DE 28 BYTES, NAO SETE STORES.**
 *    31 -> 16 numa linha. O bloco de 4 loads / 4 stores / 3 loads / 3 stores
 *    e literalmente o expansor de block-move do gcc para MIPS, que emite ate
 *    quatro `lw` e depois os `sw` correspondentes; 28 bytes dao 4+4 e 3+3.
 *    Escrito como sete pares nomeados era preciso pinar cada grupo com
 *    `do { } while (0)` para chegar ao mesmo AGRUPAMENTO, e mesmo assim os
 *    quatro registradores ficavam $v1/$a0/$a1/$v0 onde o retail usa
 *    $a3/$t0/$t1/$t2 -- que sao os que o expansor escolhe. **Quando um bloco
 *    de loads e stores casa exatamente com 4+4/3+3, procure a copia de
 *    struct antes de nomear temporarios.**
 *
 * E O CONTRAPESO QUE SE DESFEZ SOZINHO: enquanto o case 10 era escrito a
 * mao, o unico jeito de acertar seus $s0/$s1 era o ponteiro dele emprestar
 * o nome do ponteiro do m3 (48 -> 45), ao preco de esse nome ficar
 * callee-saved nos tres bracos do m3, onde o retail o quer em $v0. Com a
 * copia de struct no lugar, separar os dois nomes -- que era 34 contra 31 --
 * passou a ser 16 -> **7**. Instancia limpa da regra: uma grafia rejeitada
 * enquanto outra falta estava aberta nao foi medida.
 */
#define D_8009B0F4_IS_SCALAR
#include "common.h"

typedef struct { s32 w[7]; } Rec28;

void func_8005B620(s32 *dst, s32 *src, s32 n);
void func_80081DE8(s16 *arg0, u8 *arg1);

void func_800577B0(u8 *p, s32 mode) {
    s16 sp[8];
    u8 *b;
    u8 *g;
    u8 *t;
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
        do { m = 0xFFDCFFFF; } while (0);
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
        t = D_801DD000;
        func_8005B620((s32 *)(s + 0xBF8), (s32 *)t, 0x40);
        *(Rec28 *)(s + 0xCF8) = *(Rec28 *)(t + 0x100);
        *(s32 *)(s + 0xD08) = -1;
        *(s32 *)(s + 0xD0C) = -1;
        *(s32 *)(s + 0xD10) = -1;
        *(s16 *)(s + 0xCF8) = 0;
        *(s16 *)(s + 0xCFA) = 0;
        s[0xE14] = 1;
        return;
    }
}
