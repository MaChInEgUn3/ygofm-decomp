/* MATCH, 2026-09-13. Escrita do zero. duel_action_resolution_dispatch no
 * transplante do Unchiga (STUB la). FLAGS: padrao, sem linha em build.py.
 * Jump table de 17 casos sobre (s8)(D_8009AF9A + 1).
 *
 * LEVERS, medidos um sobre o outro com try_func:
 *  0. D_80010014/18 no arm .data (D_80010014_IN_DATA): saem bare ao lado
 *     dos dois flags de um byte em %gp_rel. Um `as -G1` da o mesmo MATCH;
 *     o arm diz a verdade sobre os objetos e dispensa a flag.
 *  1. D_800F4875 e D_800F3A54 como arrays sem tamanho: o alvo poe o `lui` do
 *     primeiro no slot do bnez (par proprio do cc1psx). No arm .data o slot
 *     fica nop e sobra +1.
 *  2. caso 15 com a comparacao invertida, `x - base[0xE0D] * f() <= E06`: o
 *     alvo le +0xE06 depois da multiplicacao. +1 -> exato, censo vazio.
 *  3. o registro do caso 15 como `base + 0x7C4 - -(idx * 0x76)`: base
 *     primeiro no addu. `&base[...]` e o `+` simples dao idx primeiro.
 *  4. D_8009AFFC sem tamanho e copiado como `*(Pack8 *)D_8009AFFC`: o par
 *     do endereco passa por $v0 e o `lui` sobe para o prologo com o `a0 = 1`.
 *     Com a struct de 8 bytes declarada o simbolo sai bare no mesmo
 *     registrador; um `do { } while (0)` em volta da copia chegou a 17
 *     diferencas e deixa de ser necessario com este arm.
 *
 * MEDIDO E NEUTRO: quatro ordens de declaracao dos locais (todas iguais);
 * a ordem das atribuicoes do topo mudou so os blocos, nao a contagem.
 */
#define D_8009B0F4_IN_DATA
#define D_8009B134_IN_DATA
#define D_80010014_IN_DATA
#include "common.h"

typedef struct {
    u8 b[8];
} Pack8;

void func_800156DC(void);
s32 func_8004703C(void);
s32 func_80056504(s32 arg0, s32 id, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_80056828(s32 arg0);
void func_80057AF4(s32 a0, s32 a1, s32 a2);
s32 func_80058E1C(void);
void func_800597C8(s32 idx, s32 flag, s32 val);
void func_80059AEC(u8 arg0);
void func_8005D994(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 arg5);

void func_8004FE2C(void)
{
    Pack8 v;
    u8 *base;
    u8 *b0;
    u8 *b2;
    s32 (*cb1)(s32, s32);
    s32 (*cb2)(s32, s32);
    s32 x;

    v = *(Pack8 *)D_8009AFFC;
    base = D_800F2C40;
    cb1 = (s32 (*)(s32, s32))(D_80010014 + 4);
    cb2 = (s32 (*)(s32, s32))(D_80010018 + 4);
    func_80059AEC(1);
    if ((u8)D_8009AF9A - 8U < 2 && base[0xE15] == 0) {
        D_8009AFA0 = 0;
        if (cb1(D_80010024, -1) == 2) {
            base[0xE15]++;
        }
    }
    if (D_8009AF9A >= 0xA && D_800F4875[0] == 0) {
        D_8009AFA0 = 0;
        if (cb2(D_80010028, -1) == 2) {
            func_80059700(0, 0);
            func_800156DC();
            D_8009AF9A = 0xF;
        }
    }
    switch ((s8)(D_8009AF9A + 1)) {
    case 0:
        if (D_800F3A54[0] == 0xFF) {
            if (((D_8009B0F4 & 0x2000030) | D_8009B134) == 0) {
                func_80056504(0, 0x309, 0, 0, 0, 0, 4);
            }
        } else {
            func_80056828(0);
        }
        b0 = D_800F2C40;
        if (b0[0xE1F] != 0) {
            func_8005F3B8(0, 0x2710, 0xE00, 0, 0);
            func_800597C8(0, 1, 0);
            if (base[0xE0F] != 0) {
                func_80057AF4(0, 0, 0);
            }
            func_80059700(0, 1);
            func_80059590(0, 5, 0, 0, 0);
            base[0xBF6] = 1;
            base[0xBF4] = 2;
            func_80047314(0x7310);
            *(s32 *)(b0 + 0xD08) = -1;
            *(s32 *)(b0 + 0xD0C) = -1;
            *(s32 *)(b0 + 0xD10) = -1;
            D_8009AFA0 = 0;
            cb1(D_80010024, 0);
            cb2(D_80010028, 0);
            b0[0xE15] = 0;
            b0[0x1C35] = 0;
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 1:
        if (func_8004703C() & 0x80) {
            *(s16 *)((u8 *)&v + 2) = -0x7D0;
            func_800597C8(0, 0, 0xA);
            func_8005D994(0, 0x7D0, 0x100, 0x100, (u8 *)&v, 0x6E);
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 2:
        b2 = D_800F2C40;
        if ((s8)b2[0xDC0] >= 0) {
            b2[0xDC0] += 2;
            b2[0xDC1] += 2;
            b2[0xDC2] += 2;
        } else {
            func_80059590(0, 0, 0x80, 0x80, 0x80);
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 3:
        if (func_8005FB08() != 0 && *(u16 *)(base + 0xE06) >= 0x780) {
            func_800597C8(0, 0, 0);
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 4:
        if (*(u16 *)(base + 0xE06) >= 0x780) {
            func_800597C8(0, 0, 0);
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 5:
        if (*(u16 *)(base + 0xE06) >= 0x1E0) {
            func_800597C8(0, 0, 0);
            *(s16 *)((u8 *)&v + 0) = -0x9C4;
            *(s16 *)((u8 *)&v + 2) = -0x5DC;
            *(s16 *)((u8 *)&v + 4) = 0x3E8;
            func_8005F3B8(0, 0xBB8, -0x100, -0x100, (s32)&v);
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 6:
        if (*(u16 *)(base + 0xE06) >= 0x1E0) {
            func_800597C8(0, 0, 0);
            *(s16 *)((u8 *)&v + 0) = 0x9C4;
            *(s16 *)((u8 *)&v + 2) = -0x5DC;
            *(s16 *)((u8 *)&v + 4) = 0x3E8;
            func_8005F3B8(0, 0xBB8, 0x100, -0x100, (s32)&v);
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 7:
        if (*(u16 *)(base + 0xE06) >= 0x1E0) {
            func_800597C8(0, 0, 0);
            *(s16 *)((u8 *)&v + 0) = -0x1F4;
            *(s16 *)((u8 *)&v + 2) = 0x5DC;
            *(s16 *)((u8 *)&v + 4) = 0x3E8;
            func_8005F3B8(0, 0xBB8, -0x200, -0x100, (s32)&v);
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 8:
        if (*(u16 *)(base + 0xE06) >= 0x1E0) {
            func_800597C8(0, 0, 0);
            *(s16 *)((u8 *)&v + 0) = 0x1F4;
            *(s16 *)((u8 *)&v + 2) = 0x5DC;
            *(s16 *)((u8 *)&v + 4) = 0x3E8;
            func_8005F3B8(0, 0xBB8, 0x200, -0x100, (s32)&v);
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 9:
        if (*(u16 *)(base + 0xE06) >= 0x1E0) {
            *(s16 *)((u8 *)&v + 2) = -0x7D0;
            func_8005F3B8(0, 0xDAC, 0x40, 0x200, (s32)&v);
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 10:
        if (base[0xBF5] == 2) {
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 11:
        if (*(u16 *)(base + 0xE06) >= 0x8C0) {
            *(s16 *)((u8 *)&v + 2) = -0x5DC;
            func_8005D994(0, 0xDAC, 0, -0x80, (u8 *)&v, 0x28);
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 12:
        if (*(u16 *)(base + 0xE06) >= 0xE60) {
            *(s16 *)((u8 *)&v + 4) = -0x3E8;
            func_8005F3B8(0, 0x1388, 0x200, -0x100, (s32)&v);
            func_800597C8(0, 0, 0xBE);
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 13:
        if (*(u16 *)(base + 0xE06) >= 0xE60) {
            *(s16 *)((u8 *)&v + 4) = -0x3E8;
            func_8005F3B8(0, 0x1388, -0x200, -0x100, (s32)&v);
            func_800597C8(0, 0, 0xBE);
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 14:
        if (*(u16 *)(base + 0xE06) >= 0xE60) {
            *(s16 *)((u8 *)&v + 2) = -0x3E8;
            func_8005F3B8(0, 0xBB8, 0, -0x80, (s32)&v);
            func_800597C8(0, 0, 0xBE);
            D_8009AF9A = D_8009AF9A + 1;
        }
        break;
    case 15:
        x = *(u16 *)(base + 0x7C4 - -(base[0xBF5] * 0x76)) * 16;
        if (x - base[0xE0D] * func_80058E1C() <= *(u16 *)(base + 0xE06)) {
            func_80059700(0, 0);
        }
        break;
    case 16:
        D_8009AF9A = -2;
        break;
    }
}
