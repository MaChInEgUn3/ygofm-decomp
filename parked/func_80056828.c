/* PRIMEIRO RASCUNHO, 2026-09-12: 324 contra 341 (-17), 320 diferencas
 * posicionais (infladas pelo deslocamento -- ler o censo, nao a contagem).
 * Flags PADRAO. Escrita do zero a partir do rascunho do m2c; e a menor
 * funcao limpa que sobrou no pool, agora que o piso e 250 instrucoes.
 *
 * FORMA, lida da listagem e nao do m2c: maquina de estados que despacha no
 * byte +0xE14 de um registo de 0xE20 indexado por arg0. Dois rotulos
 * distintos e isso decide a estrutura -- .L80056D54 e o EPILOGO (estados 0 e
 * 0xFF retornam sem fazer nada) e .L80056D18 e a CAUDA COMUM, que toda a
 * gama 1..0xB alcanca e que faz o log e o avanco de estado. Ha jump table
 * real (jtbl_8001170C) com `sltiu $v0,$v1,0xB` sobre `state - 1`, logo o
 * `switch` e sobre os casos 1..0xB e os dois testes de saida sao escritos a
 * mao antes dele.
 *
 * A cauda e a regra do delay slot: `addiu $v0,$zero,0xFF` esta no slot do
 * `bnez` e o fall-through sobrepoe com `rec[0xE14] + 1`, o que em C e uma
 * atribuicao incondicional seguida de uma condicional, nao dois bracos.
 *
 * CENSO DESTE RASCUNHO, que e o mapa do que falta:
 *   beq -7, bne +4  -> polaridade de ramo, provavelmente a arvore do case 7,
 *                      que eu achatei numa cadeia if/else-if e o retail tem
 *                      como arvore aninhada (!= 0x3C, < 0x3D, != 0x23,
 *                      != 0x3E);
 *   lui -5          -> cinco materializacoes de endereco a menos;
 *   j -4            -> quatro saltos incondicionais a menos, ou seja casos
 *                      que deviam saltar para a cauda e estao a cair nela;
 *   slti -2, slt -1 -> comparacoes em falta;
 *   andi +3         -> tres mascaras a mais, leituras de byte que o retail
 *                      nao mascara.
 *
 * NAO MEDIDO AINDA: nada de flags, nada de permuter. O proximo passo e a
 * arvore do case 7 e depois os `j`, por essa ordem, porque o censo diz que
 * sao os dois maiores blocos.
 */
#include "common.h"

extern u8 D_80011594[];
extern u8 *D_80010004;
extern s32 D_8001000C;
extern s32 D_80010010;

void func_8005A468(s32, s32);
void func_8004DC38(u8 *, s32, s32, s32);

void func_80056828(s32 arg0) {
    u8 *rec;
    u8 *p;
    u8 **q;
    s32 t0;
    s32 st;
    s32 i;
    s32 n;
    s32 sum;
    s32 d;
    s32 v;
    s32 a;
    u8 c;
    u16 w;
    void (*fp)(s32, s32, s32);

    rec = arg0 * 0xE20 + D_800F2C40;
    t0 = func_80074170(1);
    st = rec[0xE14];
    if (st == 0 || st == 0xFF) {
        return;
    }

    switch (st) {
    case 1:
        a = D_80010008;
        v = 0xC000;
        if (arg0 == 0) {
            a = (s32)D_80010000;
        } else if (arg0 == 1) {
            a = (s32)D_80010004;
        }
        if (*(s32 *)a != 0) {
            v = *(s32 *)a;
        }
        func_8004CB0C(arg0, (u8 *)a, v, -1);
        break;
    case 2:
        func_8004D75C(arg0);
        break;
    case 3:
        func_8004D914(arg0);
        break;
    case 4:
        p = arg0 * 0xE20 + D_800F2C40;
        sum = 0;
        if (arg0 < 2) {
            n = p[0xE1B];
            i = 0;
            if (n > 0) {
                do {
                    if (*(u16 *)(p + i * 8 + 0x33C) != 0xFFFF) {
                        d = i / 8;
                        if ((p[d + 0xBEC] >> (i - d * 8)) & 1) {
                            sum += 0x14;
                        } else {
                            sum += 0xC;
                        }
                    }
                    i++;
                } while (i < n);
            }
        }
        v = *(s32 *)(p + 0xDE0) + sum;
        *(s32 *)(p + 0xDF0) = v;
        *(s32 *)(p + 0xDF4) = v + *(u16 *)(p + 0xE02) * 4;
        func_8005A4C4(p, 0, 0, 0);
        break;
    case 5:
        p = arg0 * 0xE20 + D_800F2C40;
        q = (u8 **)(p + 0x1E0);
        i = 0;
        if (p[0xE1B] != 0) {
            do {
                *(u16 *)(q[0] + 8) = 0xFFFF;
                *(u16 *)(q[0] + 0x16) = *(u16 *)(q[0] + 0x18);
                *(u16 *)(q[0] + 0xA) = 0xFFFF;
                q[0][0xC] = q[0][0x1A];
                *(s32 *)(q[0] + 0x10) = 0;
                i++;
                q[0][0xD] = 0x10;
                q += 4;
            } while (i < (s32)p[0xE1B]);
        }
        break;
    case 6:
        rec[0xE1F] = 1;
        func_800590DC(arg0);
        rec[0xE1F] = 0;
        break;
    case 7:
        p = arg0 * 0xE20 + D_800F2C40;
        c = p[0xE16];
        n = *(u8 *)(p + 0xE0D) * 2;
        if (c == 0x3C) {
            func_8005A468(arg0, -n);
        } else if (c == 0x23) {
            func_8005A468(arg0, 0);
        } else if (c == 0x3E) {
            func_8005A468(arg0, n);
        }
        if (arg0 >= 2) {
            rec[0xE1F] = 1;
        }
        break;
    case 8:
        func_800582C0(arg0, p[0xE0C], *(u16 *)(p + 0xE0A));
        break;
    case 9:
        p = arg0 * 0xE20 + D_800F2C40;
        v = *(s32 *)(p + 0xDE8);
        D_8009AFA0 = arg0;
        if (*(s32 *)(p + 0xD10) >= 0) {
            if (arg0 != 0) {
                fp = (void (*)(s32, s32, s32))(D_80010010 + 4);
            } else {
                fp = (void (*)(s32, s32, s32))(D_8001000C + 4);
            }
            func_8005F198(1);
            fp(v, *(s32 *)(p + 0xD10) % 1000, *(s32 *)(p + 0xD10));
            func_8005F198(0);
        }
        c = p[0xBF5];
        p[0xE0E] = 6;
        w = *(u16 *)(p + 0xE06);
        i = 0;
        if (p[0xE1B] != 0) {
            do {
                a = p[0xBF5];
                if (c != 0) {
                    a = c;
                    (*(u8 **)(p + i * 16 + 0x1E0))[0xC] = c;
                }
                func_8004DC38(p, i, a, w);
                i++;
            } while (i < (s32)p[0xE1B]);
        }
        if (c != 0) {
            p[0xBF5] = c;
        }
        break;
    case 0xA:
        if (rec[0xE1D] == 0) {
            func_80048D08(arg0, (arg0 << 0xB) + D_801A8000);
        }
        break;
    case 0xB:
        if (rec[0xE1D] == 0) {
            rec[0xE1E] = 1;
        }
        rec[0xE1F] = 1;
        break;
    }

    func_8008E870(D_80011594, rec[0xE14], func_80074170(1) - t0);
    v = 0xFF;
    if (rec[0xE1F] == 0) {
        v = rec[0xE14] + 1;
    }
    rec[0xE14] = v;
}
