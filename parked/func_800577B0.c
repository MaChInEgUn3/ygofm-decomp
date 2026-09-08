/* -3 at 206/209, 171 differences (2026-09-08). CENSO: lw -1, lui -1, sw -3,
 * addiu -1, nop +3. Segundo dia de trabalho: -12 -> -3, 186 -> 171, e o
 * alinhamento difflib caiu de 21 blocos para 17.
 *
 * MEDIR COM `as -G0` (nao ha linha em build.py):
 *   echo '{"func_800577B0": {"as": "-G0"}}' > config/flag_overrides.json
 *   .venv/bin/python tools_src/try_func.py func_800577B0 parked/func_800577B0.c
 *   rm -f config/flag_overrides.json      # NUNCA deixar entre turnos
 * No assembler padrao e -30. gp=0 e seis `lui $at` de D_8009B0F4: o ramo
 * facil da receita, e como o conserto e o -G do ASSEMBLER e nao
 * -mno-split-addresses, a jump table (jtbl_8001179C) sobrevive.
 *
 * O QUE FOI MEDIDO E VALEU (cada um sozinho, sobre a base anterior):
 *  1. LAYOUT DOS BRACOS NA ORDEM DE ENDERECO DO RETAIL, -12 -> -8. Os
 *     rotulos de juncao ficam DEPOIS do braco que cai neles, nao dentro do
 *     primeiro braco que salta: m0 depois do case 4, m1 depois do case 6,
 *     m3/m2 depois do case 5/9. Escrito ao contrario, o case 0 cai no m0 e
 *     perde o `j` que o retail tem.
 *  2. `one = 1;` NOMEADO NO TOPO DE m0, -8 -> -6. Sem o nome o `addiu
 *     $v0,1` fica adjacente ao `sb`, o sufixo comum com o m2 vira DUAS
 *     instrucoes e o gcc faz cross-jump dos dois finais; com o nome no topo
 *     o sufixo comum e uma so e a fusao nao acontece. E a regra do
 *     find_cross_jump do WORKFLOW lida pelo lado do agendador.
 *  3. O `sh` do p+0x30 (e do p+0x32 no case 6) DEPOIS do `|=`, -6 -> -5:
 *     tira dois `nop` de delay slot de load.
 *  4. RABO DO m1 ESCRITO EM CADA BRACO (cases 1 e 6), em vez do `goto m1`:
 *     mag do censo 10 -> 7. Com o `goto`, os dois bracos terminam em
 *     [lui b118][lw b118] identicos e o gcc funde tambem essas duas, de modo
 *     que o case 1 fica SEM o load de D_8009B118 que o retail tem.
 *  5. **UM NOME PARA 0x10 E 0x10000**, 180 -> 164 diferencas. O retail usa
 *     $v1 para o `addiu $v1,16` do store em p+6 e depois para o `lui $v1,1`
 *     da mascara OR do mesmo braco -- dois constantes sequenciais que nunca
 *     coexistem, entao a fonte tinha UM nome. E a regra do func_80020BE4, e
 *     aqui foi a maior alavanca isolada do dia.
 *  6. Case 8: `*(s32 *)(p + 0x30) = 0xD810;` -- o retail tem `sw`, nao `sh`,
 *     e `ori $v0,$zero,55312` confirma o valor sem sinal.
 *  7. Case 6: `hun`/`two` nomeados atravessam o `jal` e sao os $s0/$s1 que o
 *     retail salva; case 10: locais de base para D_800F2C40 e D_801DD000,
 *     senao o 0xBF8 dobra dentro do `%lo` (regra 18).
 *
 * MEDIDO E MORTO (nao refazer):
 *  - trocar a ordem de declaracao de `v` e `b` (0), de `s` e `t` (0 em duas
 *    bases), nomes separados y0..y2 para o segundo grupo de loads do case 10
 *    (0 em duas bases);
 *  - `do { one = 1; } while (0);` no m0 (0 sobre z1, pior sobre v6);
 *  - `do { w = ...; } while (0);` no fim dos cases 1 e 6 (-5/178, pior);
 *  - um so nome para 0x10000 e para o `w` da juncao (v6): funde o registrador
 *    mas dobra o reload de D_8009B0F4 e paga 2 nop -- deficit real igual;
 *  - `w = 0x30000; d = D_8009B118;` em vez da ordem inversa no case 1, sobre
 *    a base com juncao: BYTE-IDENTICO (a9 == a5), eixo fechado.
 *
 * VARIANTE IRMA a 164 diferencas e -5 (mesmo deficit real, 2 nop a menos):
 * a mesma fonte com o `sh` do p+0x30/p+0x32 escrito DEPOIS do `|=` em vez do
 * `do { } while (0)` antes dele. Escolhida esta pela regra de ordenacao
 * (|erro de comprimento| primeiro).
 *
 * O QUE FALTA (6 instrucoes reais):
 *  a) sw -3, lw -1, addiu -1: o gcc guarda a copia do rabo do m1 do CASE 1 e
 *     manda o case 6 saltar para tras; o retail guarda a do CASE 6 (a juncao
 *     .L800579C8 fica logo depois do corpo do case 6) e o case 1 salta para
 *     frente. Nenhuma das duas grafias medidas ate agora poe a copia no
 *     braco certo.
 *  b) lui -1: no case 10 os $s0/$s1 estao trocados (retail: $s0 =
 *     D_800F2C40, $s1 = D_801DD000) e o gcc intercala os 4+3 loads com os
 *     stores, onde o retail agrupa 4 loads, 4 stores, 3 loads, 3 stores.
 *  c) o `sh` do p+0x30 ainda cai uma instrucao adiante do lugar do retail
 *     (que o poe entre o `lui` da constante e o `or`).
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
    u8 *s;
    u8 *t;
    s32 v;
    s32 w;
    s32 n;
    s32 d;
    s32 m;
    s32 c;
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
        do { *(s16 *)(p + 0x30) = 0; } while (0);
        D_8009B0F4 |= n;
        p[0x46] = 2;
        d = D_8009B118;
        *(s32 *)(p + 0x1C) = 0x30000;
        *(s32 *)(p + 8) = d;
        *(s32 *)(p + 0xC) = d + 0x800;
        return;

    case 2:
        m = 0xFFDCFFFF;
        b = D_801DD000;
        *(s32 *)(p + 0xC) = (s32)b;
        *(s32 *)(p + 8) = (s32)b;
        v = D_8009B0F4;
        w = 0x1000;
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
        do { *(s16 *)(p + 0x32) = hun; } while (0);
        D_8009B0F4 |= n;
        p[0x46] = two;
        d = D_8009B118;
        *(s32 *)(p + 0x1C) = 0x4000;
        *(s32 *)(p + 8) = d;
        *(s32 *)(p + 0xC) = d + 0x800;
        return;

    case 7:
        m = 0xFFDCFFFF;
        b = D_801A8000;
        goto m3;

    case 8:
        c = 0x19000;
        p[0x46] = 3;
        d = D_8009B118;
        *(s32 *)(p + 0x30) = 0xD810;
        *(s32 *)(p + 0x1C) = c;
        *(s32 *)(p + 8) = d;
        *(s32 *)(p + 0xC) = d + 0x800;
        return;

    case 5:
    case 9:
        m = 0xFFDCFFFF;
        b = D_801DD000;
    m3:
        *(s32 *)(p + 0xC) = (s32)b;
        *(s32 *)(p + 8) = (s32)b;
        v = D_8009B0F4;
        w = 0x800;
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
