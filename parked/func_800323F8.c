/* 464/464 com CENSO VAZIO e 26 diferencas, 2026-09-13. Escrita do zero.
 * FLAGS: -quiet -O2 -G8 -fno-strength-reduce (try_func precisa delas passadas
 * a mao; ainda nao ha linha em build.py). Listagem gp=2 (D_8009B2FC), at=2
 * (os sh $zero de D_8009B146/148): arm D_8009B146_IN_DATA.
 *
 * Inicializa os dois registros de 0x6344 bytes do duelo e depois cria
 * onze objetos de tela com func_800400AC/func_800404CC/func_800428EC.
 * No transplante do Unchiga consta como STUB; no krystalgamer, unmatched_asm
 * sem nota e sem PR aberta.
 *
 * LEVERS, cada um medido sobre o anterior (try_func: comprimento, censo,
 * adiff):
 *  1. -fno-strength-reduce: os laços do alvo mantem contadores e cursores
 *     explicitos sem vies. Sem a flag o melhor foi +7; com ela, +2.
 *  2. cursores explicitos: tabela D_801D07BC de tras para frente
 *     (`pt = t7 + 15; pt--`), `pj = p + j` com `pj++`, `c = p + 0x2D58`
 *     com `c += 0x10`, `w++` num u16 *, `c = q + 0xD`. +2 -> exato.
 *  3. o endereco de D_80090DD8 somado como inteiro num local `z` e lido
 *     como `z[1]`: sem isso o [1] dobra no %lo do invariante hoistado.
 *  4. `v--; v *= 4; v += (s32)tb;` e `*(s32 *)v` direto, depois do store
 *     de v: o store fica primeiro e o slot do beqz fica nop, como no alvo.
 *     Grupos estruturais 9 -> 7.
 *  5. no rabo, gravar +0x30 ANTES de +0x4C (sem nome). Com uma leitura
 *     nomeada entre eles e -2 (somem as copias de o2); sem nome e com a
 *     ordem do rascunho e +1 (nop extra). +1 -> exato, 29 diferencas.
 *  6. o segundo z e `p + x` feitos no proprio registrador (29 -> 26).
 *
 * MEDIDO E PIOR OU NEUTRO: os locais dd/tb para as bases com strength
 * reduction ligado (+8); tb removido (+1); `q = p + 4` antes do `do` (igual);
 * `dd` local com o z (+1); leitura em v com `v <<= 4` e `(s32)p + x` (27);
 * ints declarados antes dos ponteiros (27).
 *
 * RESIDUO (26), so registrador: D_80090DD8/D_801D4244 hoistados em $fp/$s7
 * na ordem trocada (o alvo poe os dois antes de `q = p + 4`); no primeiro
 * bloco t7 e k com $a2/$t1 trocados por $a3/$a2; no segundo, r/cnt/k/w com
 * $t1/$a3/$t0/$a2 trocados por $t2/$t0/$a2/$a3.
 */
#define D_8009B146_IN_DATA
#include "common.h"

void func_80031874();

void func_800323F8(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3)
{
    u8 *p;
    u8 *q;
    u8 *o;
    u8 *o2;
    u8 *r;
    u8 *c;
    u8 *b;
    u8 *s;
    u8 *z;
    u8 *dd;
    u16 *t7;
    u16 *w;
    u16 *pt;
    u8 *pj;
    u8 *pk;
    s32 *tb;
    s32 *e;
    s32 i;
    s32 j;
    s32 k;
    s32 x;
    s32 one;
    s32 f80;
    s32 cnt;
    s32 sum;
    s32 v;

    func_80032328();
    func_8003FF08(0x70E0);
    D_8009B148 = 0;
    D_8009B146 = 0;
    p = arg0;
    func_80032370();
    i = 0;
    one = 1;
    tb = D_801D4244;
    q = p + 4;
    D_8009B2FC = p;
    p[0x6343] = arg3;
    *(u8 **)p = arg1;
    *(s32 *)(p + 0x6344) = arg2;
    p[0x6342] = 0;
    p[0xC686] = 0;
    do {
        if (*(s32 *)p != 0) {
            t7 = D_801D07BC;
            q[0x6066] = 0;
            j = 1;
            pj = p + j;
            do {
                pj[0x606A] = 0;
                k = 15;
                pk = pj;
                pt = t7 + 15;
                do {
                    if ((s16)*pt == j) {
                        pk[0x606A] = k + 1;
                    }
                    k--;
                    pt--;
                } while (k >= 0);
                j++;
                pj++;
            } while (j < 0x2D3);
            r = p + 0x2D50;
            cnt = 0;
            q[0x5A93] = one;
            k = cnt;
            *(s16 *)(q + 0x5A8A) = 0;
            *(s16 *)(q + 0x5A88) = 0;
            q[0x5A94] = 0;
            q[0x5A92] = 0;
            z = (u8 *)(q[0x5A93] * 16 + (s32)D_80090DD8);
            q[0x5A91] = z[1] & 0xF;
            c = p + 0x2D58;
            w = *(u16 **)p;
            for (; k < 0x28; k++, c += 0x10, w++) {
                c[5] = 0;
                *(s16 *)(c - 4) = 0;
                v = *w;
                if (v != 0) {
                    *(s16 *)(c - 4) = v;
                    v--;
                    v *= 4;
                    v += (s32)tb;
                    c[5] = one;
                    c[2] = (*(s32 *)v >> 26) & 0x1F;
                    *(s16 *)(c - 2) = (*(s32 *)v & 0x1FF) * 10;
                    cnt++;
                    *(s16 *)c = ((*(s32 *)v >> 9) & 0x1FF) * 10;
                }
            }
            *(s16 *)(r + 0x284) = -1;
            *(s32 *)(q + 0x5A9C) = cnt;
            *(s16 *)(q + 0x5A8C) = 0x28;
            *(s16 *)(q + 0x5A8E) = 0x28;
            func_80032C48(p + 0x2D50);
            func_8003201C(p);
            r = q;
            sum = 0;
            j = sum;
            f80 = 0x80;
            q[0x2D47] = 0;
            *(s16 *)(q + 0x2D3E) = 0;
            *(s16 *)(q + 0x2D3C) = 0;
            *(s16 *)(q + 0x2D40) = 0x2D2;
            q[0x2D48] = 0;
            q[0x2D46] = 0;
            v = q[0x2D47] * 16;
            v += (s32)D_80090DD8;
            q[0x2D45] = ((u8 *)v)[1] & 0xF;
            c = q + 0xD;
            e = tb;
            b = *(u8 **)p + 0x50;
            for (; j < 0x2D2; e++, j++, c += 0x10, b++) {
                x = j + 1;
                c[0] = 0;
                *(s16 *)(c - 9) = x;
                c[-3] = (*e >> 26) & 0x1F;
                *(s16 *)(c - 7) = (*e & 0x1FF) * 10;
                *(s16 *)(c - 5) = ((*e >> 9) & 0x1FF) * 10;
                x += (s32)p;
                s = (u8 *)x;
                s[0x5D97] = *b;
                if (*b != 0) {
                    c[0] = one;
                    sum += *b;
                } else if (s[0x5AC4] != 0) {
                    c[0] = f80;
                }
            }
            *(s16 *)(r + 0x2D24) = 0;
            *(s32 *)(q + 0x5A98) = sum;
            *(s16 *)(q + 0x2D42) = 0x2D2;
            *(s16 *)(q + 0x2D40) = 0x2D2;
            func_80032C48(q);
        }
        i++;
        q += 0x6344;
        p += 0x6344;
    } while (i < 2);

    p = D_8009B2FC;
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0, 0, 0, 4, 0, 0xC, 0x208);
    o2 = func_800400AC(func_8004002C(), 6);
    o2[0x67] = 0;
    *(s32 *)(o2 + 0x30) = *(s32 *)(o + 0x30);
    *(s32 *)(o2 + 0x4C) = (s32)func_80031874;
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0x140, 0, 0, 4, 1, 0xC, 0x208);
    o2 = func_800400AC(func_8004002C(), 6);
    o2[0x67] = 1;
    *(s32 *)(o2 + 0x30) = *(s32 *)(o + 0x30);
    *(s32 *)(o2 + 0x4C) = (s32)func_80031874;
    *(s16 *)(p + 0x633E) = 2;
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0x136, 0x29, 0, 4, 0xC, 0xC, 0x208);
    *(u16 *)(o + 8) |= 0x20;
    func_800428EC(o, 8);
    *(u8 **)(p + 0x2D3C) = o;
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0x26A, 0x29, 0, 4, 0xC, 0xC, 0x208);
    *(u16 *)(o + 8) |= 0x20;
    func_800428EC(o, 8);
    *(u8 **)(p + 0x5A88) = o;
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0, 0x2A, 0, 4, 2, 0xC, 0x208);
    *(u16 *)(o + 8) |= 0x20;
    func_800428EC(o, 0xA);
    *(u8 **)(p + 0x2D38) = o;
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0x148, 0x2A, 0, 4, 3, 0xC, 0x218);
    *(u16 *)(o + 8) |= 0x20;
    func_800428EC(o, 0xA);
    *(u8 **)(p + 0x5A84) = o;
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0, 0, 0, 4, 9, 0xC, 0x208);
    *(u16 *)(o + 8) |= 0x20;
    func_800428EC(o, 0xA);
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0x140, 0, 0, 4, 0xA, 0xC, 0x208);
    *(u16 *)(o + 8) |= 0x20;
    func_800428EC(o, 0xA);
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0, 0, 0, 4, 0xB, 0xC, 0x208);
    *(u16 *)(o + 8) |= 0x20;
    func_800428EC(o, -4);
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0x140, 0, 0, 4, 0xB, 0xC, 0x208);
    *(u16 *)(o + 8) |= 0x20;
    func_800428EC(o, -4);
    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0x140, 0, 3, 0, 3, 0xB, 0x2F8);
    func_800428EC(o, -4);
    func_80031E5C(p);
}
