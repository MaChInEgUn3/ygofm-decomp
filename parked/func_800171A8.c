/* -1 em 236/237, 146 diferencas, censo `sb -1, sw -2, nop +2` (2026-09-08).
 * PRIMEIRO C, escrito num tick a partir do listing e das alavancas do
 * func_800577B0, que casou hoje e e a MESMA familia de despachante
 * D_8009B0F4.
 *
 * MEDIR COM `as -G0` (nao ha linha em build.py):
 *   echo '{"func_800171A8": {"as": "-G0"}}' > config/flag_overrides.json
 *   .venv/bin/python tools_src/try_func.py func_800171A8 parked/func_800171A8.c
 *   rm -f config/flag_overrides.json      # NUNCA deixar entre turnos
 * Passo 0: `gp=0, at=8` (todos D_8009B0F4), uma jump table (jtbl_800100C0).
 * Ramo facil da receita: sem `%gp_rel` nenhum, qualquer -G e livre, e como o
 * conserto e o -G do ASSEMBLER a jump table sobrevive.
 *
 * FORMA: `switch (mode)` com jump table de TREZE entradas (0..12, cases em
 * ordem crescente, que e a ordem dos bracos na memoria) e CINCO juncoes
 * alcancadas por `goto`, cada uma escrita DEPOIS do braco que cai nela:
 * m3EC (case 9), m400 (m3EC), m480 (case 10), m4B8 (case 11), m4F8
 * (case 12).
 *
 * A PROTOTIPAGEM PRECISOU DE GUARDA: functions.h declarava
 * `void func_800171A8(void);` porque func_8001798C toma o ENDERECO dela como
 * um callback `void (*)(void)`. A assinatura real e `(u8 *p, s32 mode)`, e
 * so o arquivo que a define pede a completa (`FUNC_800171A8_FULL`), como no
 * func_80017F04.
 *
 * O QUE JA VALEU, e e a regra 26 aplicada duas vezes:
 *  - `do { w = K; } while (0);` nos quatro bracos que saltam para o m400
 *    (cases 2, 3, 4 e o proprio m3EC): **-17 para -6**. Sem o pino os
 *    bracos terminam em [sw 0xC][sw 8][lui/lw b0f4] identicos e o
 *    cross-jump come os dois stores de cada um;
 *  - o mesmo pino nos dois bracos que caem no m480 (cases 0 e 10): **-6
 *    para -1**, e as diferencas de 222 para 146.
 *
 * MEDIDO E MORTO: `do { v = v & m; } while (0);` nos quatro bracos do m4B8
 * (cases 1, 5, 7, 11) e -9 sozinho e -4 sobre a base atual -- ali o `and`
 * no delay slot NAO quer pino.
 *
 * O QUE FALTA (146 diferencas, censo `sb -1, sw -2, nop +2`): a mascara `m`
 * esta em $a1 e o retail a quer em $a0, e todo o resto do braco segue. E o
 * mesmo estado inicial do func_800577B0, onde a alavanca foi UM NOME PARA
 * DUAS CONSTANTES SEQUENCIAIS (la, 0x10 e 0x10000). Aqui o candidato ja e
 * o m4F8, onde o retail reusa $a0 para a mascara e para o 0x10000 -- isso
 * ja esta escrito assim. Faltam os cases 0 e 10, que usam $v1 para o
 * 0x10000 e portanto sao nomes separados.
 */
#define D_8009B0F4_IS_SCALAR
#define FUNC_800171A8_FULL
#include "common.h"

void func_80081DE8(s16 *arg0, s32 arg1);

void func_800171A8(u8 *p, s32 mode) {
    u8 *b;
    s32 v;
    s32 w;
    s32 d;
    s32 m;
    s32 n;
    s32 hun;

    switch (mode) {
    case 0:
        m = 0xFFDDFFFF;
        *(s16 *)(p + 0x30) = 0x300;
        *(s16 *)(p + 0x32) = 0x100;
        *(s16 *)(p + 4) = 0x40;
        v = D_8009B0F4;
        *(s16 *)(p + 6) = 0x10;
        D_8009B0F4 = v & m;
        n = 0x10000;
        D_8009B0F4 |= n;
        p[0x46] = 2;
        d = D_8009B118;
        do { w = 0x20000; } while (0);
        goto m480;

    case 1:
        m = 0xFFDCFFFF;
        *(s32 *)(p + 0x1C) = 0x2000;
        v = D_8009B0F4;
        b = (u8 *)D_8009B118;
        v = v & m;
        goto m4B8;

    case 2:
        D_800E9D70[0] = 0x100;
        D_800E9D70[1] = 0xF0;
        D_800E9D70[2] = 0x100;
        D_800E9D70[3] = 0x10;
        func_80081DE8(D_800E9D70, D_8009B118);
        m = 0xFFDCFFFF;
        b = D_8017A1D8;
        *(s32 *)(p + 0xC) = (s32)b;
        *(s32 *)(p + 8) = (s32)b;
        v = D_8009B0F4;
        do { w = 0x2800; } while (0);
        goto m400;

    case 3:
        m = 0xFFDCFFFF;
        b = (u8 *)D_8017C2D8;
        *(s32 *)(p + 0xC) = (s32)b;
        *(s32 *)(p + 8) = (s32)b;
        v = D_8009B0F4;
        do { w = 0x10000; } while (0);
        goto m400;

    case 4:
        m = 0xFFDCFFFF;
        b = D_801799D8;
        *(s32 *)(p + 0xC) = (s32)b;
        *(s32 *)(p + 8) = (s32)b;
        v = D_8009B0F4;
        do { w = 0x800; } while (0);
        goto m400;

    case 5:
        m = 0xFFDCFFFF;
        *(s32 *)(p + 0x1C) = 0x1000;
        v = D_8009B0F4;
        b = (u8 *)D_8009B118;
        v = v & m;
        goto m4B8;

    case 6:
        D_800E9D70[0] = 0;
        D_800E9D70[1] = 0xF0;
        hun = 0x100;
        D_800E9D70[2] = hun;
        D_800E9D70[3] = 8;
        func_80081DE8(D_800E9D70, D_8009B118);
        m = 0xFFDDFFFF;
        *(s16 *)(p + 0x30) = 0x200;
        v = D_8009B0F4;
        w = 0x40;
        *(s16 *)(p + 0x32) = hun;
        goto m4F8;

    case 7:
        m = 0xFFDCFFFF;
        *(s32 *)(p + 0x1C) = 0x16000;
        v = D_8009B0F4;
        b = D_800101DC;
        v = v & m;
        goto m4B8;

    case 8:
        m = 0xFFDCFFFF;
        b = D_801A8000;
        goto m3EC;

    case 9:
        m = 0xFFDCFFFF;
        b = D_801A9800;
    m3EC:
        *(s32 *)(p + 0xC) = (s32)b;
        *(s32 *)(p + 8) = (s32)b;
        v = D_8009B0F4;
        do { w = 0x1800; } while (0);
    m400:
        *(s32 *)(p + 0x1C) = w;
        D_8009B0F4 = v & m;
        p[0x46] = 1;
        return;

    case 10:
        m = 0xFFDDFFFF;
        *(s16 *)(p + 0x30) = 0x340;
        *(s16 *)(p + 4) = 0x40;
        v = D_8009B0F4;
        *(s16 *)(p + 6) = 0x10;
        D_8009B0F4 = v & m;
        n = 0x10000;
        v = D_8009B0F4;
        *(s16 *)(p + 0x32) = 0;
        D_8009B0F4 = v | n;
        p[0x46] = 2;
        d = D_8009B118;
        do { w = 0x4000; } while (0);
    m480:
        *(s32 *)(p + 0x1C) = w;
        *(s32 *)(p + 8) = d;
        *(s32 *)(p + 0xC) = d + 0x800;
        return;

    case 11:
        m = 0xFFDCFFFF;
        *(s32 *)(p + 0x1C) = 0x2800;
        v = D_8009B0F4;
        b = D_80010000;
        v = v & m;
    m4B8:
        D_8009B0F4 = v;
        *(s32 *)(p + 0xC) = (s32)b;
        *(s32 *)(p + 8) = (s32)b;
        p[0x46] = 1;
        return;

    case 12:
        m = 0xFFDDFFFF;
        *(s16 *)(p + 0x30) = 0x280;
        *(s16 *)(p + 0x32) = 0x100;
        v = D_8009B0F4;
        w = 0x40;
    m4F8:
        *(s16 *)(p + 4) = w;
        D_8009B0F4 = v & m;
        m = 0x10000;
        *(s32 *)(p + 0x1C) = m;
        D_8009B0F4 |= m;
        p[0x46] = 2;
        d = D_8009B118;
        *(s16 *)(p + 6) = 0x10;
        *(s32 *)(p + 8) = d;
        *(s32 *)(p + 0xC) = d + 0x800;
        return;
    }
}
