/* -9 em 286/295, 279 diferencas (2026-09-08). PRIMEIRO C escrito para esta
 * funcao, num passo, a partir do rascunho do m2c mais a leitura do listing.
 * Flags PADRAO -- passo 0 diz `gp=56, at=0, uma jump table (jr $v0)`, o caso
 * comum, sem nenhum trabalho de enderecamento.
 *
 * FORMA: maquina de estados de retry. `switch ((s8)((u8)D_8009B43E - 1))`
 * com jump table real (jtbl_80010548, 12 entradas, `sltiu $v0,$v1,0xC`), e
 * dentro dela DOIS `switch (D_8009B44F)` com cases 0/1/2 cujo `case 0` CAI
 * no `case 1`. A ordem dos bracos na memoria e 0/1, 10/11, 2/3, 7, default,
 * que e a ordem em que os cases estao escritos (regra da ordem dos cases).
 * Os dois switches internos sao IDENTICOS na arvore de comparacao e o retail
 * funde a aresta `>= 2` dos dois em .L800449DC, com o corpo do case 2 em
 * .L80044B38 -- por isso o `case 2:` esta escrito por extenso nos dois.
 *
 * CENSO: `sw -4, nop -4, lw -1, addu -1, beq -2, bne +2, addiu +2, j -1,
 * bgez -1, bgtz -1, blez +1, bltz +1`.
 * DUAS FALTAS IDENTIFICADAS, nenhuma resolvida ainda:
 *  a) **o retail salva SETE callee-saved ($s0-$s6) e nos salvamos SEIS**.
 *     Papeis dele: $s0 = contador, $s1 = handle, $s2 = modo/-1/4, $s3 =
 *     -1 / %hi(D_800F2B00), $s4 = %hi(D_800F2B00) / 2, $s5 = arg2, $s6 =
 *     arg1. Nos temos arg1 em $s5 e arg2 em $s4, ou seja falta um valor de
 *     vida longa. Vale 1 `sw` no prologo e 1 `lw` no epilogo.
 *  b) o retail tem CINCO `sw` em D_8009B450 e nos temos dois: as varias
 *     atribuicoes `D_8009B450 = 2;` (tres bracos `case 0` mais o fim do
 *     case 7) foram fundidas pelo cross-jump, e o retail so funde tres
 *     delas -- a do case 7 ele materializa em $s4 ANTES do laco.
 *
 * MEDIDO E MORTO:
 *  - um nome por laco para as sentinelas (-1, 4, 2) que o retail carrega em
 *    callee-saved -- `n1..n5`, cinco nomes, BYTE-IDENTICO ao inline. O gcc
 *    ja os mantem em registrador; nomear nao cria o setimo. Eixo errado.
 *
 * PROXIMO: pinar o `2` do case 7 com `do { n5 = 2; } while (0);` antes do
 * laco (a alavanca do func_800577B0 contra o cross-jump), e procurar qual
 * valor deveria viver em $s6.
 *
 * Uma declaracao nova em variables.h: `extern u8 D_8009B436;`, contador de
 * um byte entre o u16 D_8009B434 e D_8009B437.
 */
#define D_8009B450_IS_SCALAR
#include "common.h"

s32 func_80044608(void);
void func_80043D48(s32 *arg0);
s32 func_80044470(s32 arg0, s32 arg1, u8 *arg2, s32 *arg3);

s32 func_80044838(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 h;
    s32 mode;
    s32 i;
    s32 r;
    s32 c;

    if (D_8009B43E < 0) {
        return -1;
    }
    if (arg0 != 0) {
        if (func_8008B380(D_8009B437 != 0) & 0xE) {
            return 0;
        }
    } else {
        func_8008B390(D_8009B437 != 0);
    }
    switch ((s8)((u8)D_8009B43E - 1)) {
    case 0:
    case 1:
        if (func_80044608() < 0) {
            return 0;
        }
        break;

    case 10:
    case 11:
        switch (D_8009B44F) {
        case 0:
            r = func_80044608();
            if (r < 0) {
                return 0;
            }
            if (r != 0) {
                D_8009B450 = 2;
                break;
            }
            D_8009B43C = 0xA;
            D_8009B44F += 1;
        case 1:
            func_80043D48(D_800F2AF0);
            func_8008B370();
            if (D_8009B43E == 0xB) {
                func_8008B360(D_8009B437, D_8009B44C, D_8009B430);
            } else {
                func_8008B350(D_8009B437, D_8009B44C, D_8009B430);
            }
            D_8009B44F += 1;
            return 0;
        case 2:
            if (D_8009B450 != 0) {
                c = D_8009B436 - 1;
                D_8009B436 = c;
                if ((s8)c >= 0) {
                    D_8009B44F = 1;
                    return 0;
                }
            }
            break;
        }
        break;

    case 2:
    case 3:
        switch (D_8009B44F) {
        case 0:
            r = func_80044608();
            if (r < 0) {
                return 0;
            }
            if (r != 0) {
                D_8009B450 = 2;
                break;
            }
            D_8009B436 = 0x14;
            D_8009B44F += 1;
        case 1:
            c = D_8009B43C - 1;
            D_8009B43C = c;
            if ((s8)c < 0) {
                D_8009B450 = 2;
                break;
            }
            mode = 0x8001;
            if (D_8009B43E == 4) {
                mode = 0x8002;
            }
            i = 0xA;
            do {
                h = func_800738D0(D_800F2B00, mode);
                i -= 1;
                if (h != -1) {
                    goto got;
                }
            } while (i >= 0);
            return 0;
        got:
            i = 0xA;
            do {
                r = func_800738E0(h, D_8009B44C, 0);
                i -= 1;
                if (r != -1) {
                    goto got2;
                }
            } while (i >= 0);
            goto rel;
        got2:
            func_80043D48(D_800F2AE0);
            i = 0xA;
            do {
                if (D_8009B43E == 4) {
                    r = func_80073900(h, D_8009B430, D_8009B434);
                } else {
                    r = func_800738F0(h, D_8009B430, D_8009B434);
                }
                i -= 1;
                if (r == 0) {
                    goto ok;
                }
            } while (i >= 0);
            goto rel;
        ok:
            D_8009B43C = 0x14;
            D_8009B44F += 1;
        rel:
            func_80073910(h);
            return 0;
        case 2:
            if (D_8009B450 != 0) {
                c = D_8009B436 - 1;
                D_8009B436 = c;
                if ((s8)c >= 0) {
                    D_8009B44F = 1;
                    return 0;
                }
            }
            break;
        }
        break;

    case 7:
        switch (D_8009B44F) {
        case 0:
            r = func_80044608();
            if (r < 0) {
                return 0;
            }
            if (r != 0) {
                D_8009B450 = 2;
                break;
            }
            if (D_8009B438 + D_8009B434 >= 0x10) {
                D_8009B450 = 7;
                break;
            }
            if (func_80044470(D_8009B437, (s32)D_800F2B00, (u8 *)D_8009B444, (s32 *)0) != 0) {
                D_8009B450 = 6;
                break;
            }
            D_8009B43C = 0xA;
            D_8009B44F += 1;
        case 1:
            i = 0xA;
            do {
                h = func_800738D0(D_800F2B00, (D_8009B434 << 16) | 0x200);
                i -= 1;
                if (h != -1) {
                    func_80073910(h);
                    D_8009B450 = 0;
                    goto out;
                }
            } while (i >= 0);
            c = D_8009B43C - 1;
            D_8009B43C = c;
            if ((s8)c > 0) {
                return 0;
            }
            D_8009B450 = 2;
        out:
            break;
        }
        break;
    }
    *arg2 = D_8009B450;
    *arg1 = D_8009B43E;
    D_8009B43E = -1;
    return 1;
}
