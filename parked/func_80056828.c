/* 341/341 com CENSO VAZIO e 219 diferencas, 2026-09-13. Flags PADRAO.
 * Escrita do zero; e a menor funcao limpa do pool desde que o piso subiu
 * para 250 instrucoes.
 *
 * FORMA: maquina de estados no byte +0xE14 de um registo de 0xE20 indexado
 * por arg0, com jump table real (jtbl_8001170C) sobre `state - 1`. Dois
 * rotulos de saida decidem tudo: .L80056D54 e o EPILOGO, para onde 0 e 0xFF
 * saltam sem fazer nada, e .L80056D18 e a CAUDA COMUM de 1..0xB. A cauda e a
 * regra do delay slot -- `addiu $v0,$zero,0xFF` no slot do `bnez` com o
 * fall-through a sobrepor.
 *
 * LEVERS INSTALADOS:
 *  1. o case 7 e um SWITCH de tres casos e nao uma cadeia if/else-if; o
 *     retail tem a arvore que o gcc gera para tres casos (pivo 0x3C, depois
 *     `< 0x3D`, depois 0x23 ou 0x3E). Sete instrucoes;
 *  2. os cinco ponteiros D_80010000/04/08/0C/10 querem o braco AGREGADO: o
 *     escalar simples e small data a -G8 e sai `lw` gp-relativo onde o retail
 *     tem `lui %hi`/`lw %lo`. Quatro instrucoes, e depois disso a contagem de
 *     %hi por simbolo bate EXATAMENTE em todos;
 *  3. a guarda do laco do case 4 compara contra o CONTADOR e nao contra
 *     zero, e e um `if` com do/while por dentro, nao um `while`;
 *  4. `i = 0;` fica ACIMA do `if (arg0 < 2)`, noutro bloco basico. O gcc 2.8
 *     nao tem CSE global, entao a comparacao no bloco de baixo nao consegue
 *     dobrar `0 < n` em `n != 0` e sai o `slt $v0,$a2,$v1` do alvo, com o
 *     `addu $a2,$zero,$zero` no slot do `beq` de cima. Dentro do mesmo bloco
 *     -- que foi onde as primeiras tentativas puseram o zero -- o gcc dobra
 *     sempre, e por isso tres grafias com um segundo nome para o zero deram
 *     todas o mesmo. Uma familia de censo, e as tres posicoes acima do `if`
 *     (junto a `sum = 0`, antes dele, e antes do `p =`) dao o mesmo.
 *
 * TRES FALSOS GANHOS APANHADOS NESTA FUNCAO, e todos pelo mesmo mecanismo --
 * comprar comprimento com instrucoes que o alvo NAO TEM. O teste que os
 * pega e o EXCESSO do censo, nao o comprimento:
 *  - largura dos locais: 22 combinacoes, quatro chegam a comprimento EXATO,
 *    com `andi` a subir +3 -> +6 -> +8 -> +9. Nove mascaras compram o zero;
 *  - flags: -O1 -G0 chega a 341/341, e o controle mostra que tres funcoes que
 *    JA CASAM ficam ~3% mais longas em -O1 -G0, que e exatamente o deficit;
 *  - `goto` para a cauda nos tres bracos do switch interno: da -4 e mantem
 *    TRES `jal func_8005A468` onde o alvo tem UM. Com `break` o gcc faz o
 *    cross-jump para um so `jal`, como o retail, e o comprimento volta a -8
 *    com o excesso do censo a cair de 4 para 1. A forma com `break` e a certa
 *    e o -4 era mentira. (A ORDEM dos tres casos nao entra: 0x23/0x3E/0x3C e
 *    0x3C/0x3E/0x23 dao o mesmo censo, e 0x3E/0x23/0x3C e -10.)
 *
 * TAMBEM MEDIDO E MORTO: a copia do valor do switch (`addu $v0,$v1,$zero` no
 * alvo) -- quatro grafias empatam, o gcc coalesce toda copia de fonte; e o
 * endereco do registo -- um local por caso -11, inline nos quatro casos +45,
 * um local so para o deslocamento +5.
 *
 * 13/09, -8 -> -2 e 309 -> 270 diferencas, em dois levers que o censo
 * separou e a contagem posicional nao separava:
 *  4. func_8005A4C4 leva CINCO argumentos e este sitio passava quatro. Nao
 *     foi deducao: src/func_80056250.c JA CASA e chama
 *     `func_8005A4C4(p, 0, 0, 0, arg0 == 1 ? 0x800 : 0);`. O alvo mostra a
 *     mesma forma -- `addiu $v0,$zero,1` / `bne $s0,$v0,L12` com
 *     `addiu $v0,$zero,2048` no slot, `j L13` com `sw $v0,16($sp)` no slot,
 *     e `sw $zero,16($sp)` no outro braco. Os dois sitios escritos a mao
 *     (um por braco do `if`) dao EXATAMENTE o mesmo que o ternario, 270 e
 *     o mesmo censo, entao fica o ternario, que e a grafia do irmao;
 *  5. `*(s32 *)(q[0] + 0x10) = 0;` no case 5 e um `sw` onde o alvo tem
 *     `sh $zero,16($v0)`. Sozinho vale ZERO diferencas e ZERO comprimento
 *     -- 309 antes e 309 depois -- e o censo diz que esta certo: leva `sh`
 *     de -1 a 0, e junto com o lever 4 as duas familias `sw`/`sh` somem.
 *     E o caso da regra "uma edicao que vale zero diferencas ainda pode ser
 *     a edicao certa; le o censo, nao o total".
 *  6. no laco do case 5, `v = 0x10;` logo depois do store de 0xFFFF em +8,
 *     e o mesmo `v` como deslocamento (`q[0] + v`) e como valor
 *     (`q[0][0xD] = v`). `v` e o nome do case 4 e ninguem o le depois do
 *     laco, entao a semantica nao muda. 234 -> 219, mesmo comprimento, censo
 *     VAZIO antes e depois, e o adiff diz que e so registrador: exatas
 *     191 -> 206, so-registrador 140 -> 125, estruturais 18/15 -> 18/15.
 *     Veio do permuter (output-2155-1). A outra metade daquela saida, a
 *     atribuicao encadeada `v = (*(s32 *)(p + 0xDF0) = ...)`, vale ZERO nas
 *     duas ordens (A1/A2 = 234, AB1 = AB2 = B = 219). A saida crua e 340/341
 *     porque nao parte desta base, e por isso o scorer a rejeitou com razao.
 *
 * QUARTO FALSO GANHO, 13/09: o permuter (output-3710-5, score 3710) chega a
 * -4 com `unsigned long long nv = *(u8 *)(p + 0xE0D) * 2; n = nv;`. Compra 4
 * instrucoes de comprimento com TRES `addu` a mais -- o par de registos do
 * inteiro de 64 bits -- e o EXCESSO do censo sobe de 1 para 4. Rejeitado
 * pelo mesmo teste que pegou os outros tres.
 *
 * A GUARDA EXTERNA DO CASE 4 E UM `if`, NAO UM `while`. As duas sao
 * identicas em semantica -- o `do/while` interno ja volta a testar -- e a
 * forma com `while` emite um `sll` a mais, que o alvo NAO TEM. Trocar por
 * `if` tira esse `sll` e custa uma instrucao de comprimento: -2 com excesso
 * de um passa a -3 com excesso ZERO. Fica o `if`, pela regra desta propria
 * funcao: todo ganho de comprimento que SOBE o excesso e uma troca a
 * desfazer, e ja foram quatro falsos ganhos aqui por esse mecanismo. Quem
 * reler isto tem os dois numeros para julgar de novo.
 *
 * MEDIDO E MORTO, o segundo nome para o limite do laco (o alvo tem
 * `addu $t0,$v1,$zero`, uma copia de n logo depois da guarda): `m = n;` dentro
 * do `if`, o mesmo com um `k` para o zero, e a guarda a ler o campo com o
 * corpo a ler `n` dao os TRES o mesmo censo que nao ter copia nenhuma -- o
 * gcc coalesce toda copia de fonte. Reler o campo no teste do `while` e
 * `lbu +1`. Quatro grafias empatadas e o sinal de eixo errado.
 *
 * O `nop` QUE FALTAVA ERA O BRACO `.data` DE D_80010004, e a primeira
 * medicao disso estava errada por uma razao que nao era o braco. O alvo poe
 * um `nop` no slot do `beq $s0,$v0,L4` e nos enfiavamos la a metade `lui`
 * do par `%hi`/`%lo` do braco AGREGADO -- e a regra do WORKFLOW: a forma
 * NUA e uma pseudo-instrucao, e o preenchedor nao pode levar metade dela.
 * O que enganou foi a INDEXACAO: com o braco agregado o simbolo e
 * `u8 *D_80010004[]` e `[0]` da o ponteiro; com o braco `.data` e
 * `u8 *D_80010004` e `[0]` passa a indexar um BYTE, o que mete um `lbu` e
 * um `nop` novos e faz a medicao ler como falso ganho (+2, `lbu +1`,
 * `nop +1`). Tirando o `[0]`, o censo fica VAZIO.
 *
 * SEGUNDO NOME PARA arg0 (m), atribuido no TOPO da funcao e usado nos cases
 * 9 e 0xA e no braco 0x3E do case 7: e o `addu` que faltava. O permuter
 * achou isto como uma leitura NAO INICIALIZADA (`sum = arg0;` dentro do
 * case 7, com os cases 9 e 0xA a ler `sum`), que sao bracos mutuamente
 * exclusivos e portanto impossivel de instalar. A grafia honesta vale o
 * mesmo censo. A POSICAO importa e a honesta nao e a melhor: no topo da
 * funcao da 17 grupos estruturais, dentro do case 7 (a forma ilegal) da 15,
 * e um `m = arg0;` por braco -- que tambem e legal -- da -4 e tres
 * familias. Mecanismo sem grafia legitima conhecida para a posicao.
 *
 * MEDIDO E MORTO: o ponteiro nomeado `e = (s32 *)(p + 0xD10)` no case 9,
 * que veio na mesma saida do permuter, vale EXATAMENTE zero -- sozinho e
 * com o segundo nome junto. O `m` e o lever inteiro.
 *
 * CENSO ATUAL: VAZIO. Comprimento exato, multiset de opcodes exato, zero
 * excesso e zero deficit. O que sobra sao 234 diferencas posicionais, todas
 * de alocacao de registo e ordem de operando -- que e exatamente o estado
 * em que o permuter e a ferramenta certa.
 */
#define D_80010000_IS_AGGREGATE
#define D_8001000C_IS_AGGREGATE
#define D_80010010_IS_AGGREGATE
#define D_80010004_IN_DATA
#define D_80010008_IS_AGGREGATE
#include "common.h"

extern u8 D_80011594[];

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
    s32 c;
    s32 w;
    void (*fp)(s32, s32, s32);
    s32 m;

    m = arg0;
    rec = arg0 * 0xE20 + D_800F2C40;
    t0 = func_80074170(1);
    st = rec[0xE14];
    if (st == 0 || st == 0xFF) {
        return;
    }

    switch (st) {
    case 1:
        a = D_80010008[0];
        v = 0xC000;
        switch (arg0) {
        case 0:
            a = (s32)D_80010000[0];
            break;
        case 1:
            a = (s32)D_80010004;
            break;
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
        i = 0;
        if (arg0 < 2) {
            n = p[0xE1B];
            if (i < n) {
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
        func_8005A4C4(p, 0, 0, 0, arg0 == 1 ? 0x800 : 0);
        break;
    case 5:
        p = arg0 * 0xE20 + D_800F2C40;
        q = (u8 **)(p + 0x1E0);
        i = 0;
        if (p[0xE1B] != 0) {
            do {
                *(u16 *)(q[0] + 8) = 0xFFFF;
                v = 0x10;
                *(u16 *)(q[0] + 0x16) = *(u16 *)(q[0] + 0x18);
                *(u16 *)(q[0] + 0xA) = 0xFFFF;
                q[0][0xC] = q[0][0x1A];
                *(s16 *)(q[0] + v) = 0;
                i++;
                q[0][0xD] = v;
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
        switch (c) {
        case 0x23:
            func_8005A468(arg0, 0);
            break;
        case 0x3E:
            func_8005A468(m, n);
            break;
        case 0x3C:
            func_8005A468(arg0, -n);
            break;
        }
        if (arg0 >= 2) {
            rec[0xE1F] = 1;
        }
        break;
    case 8:
        func_800582C0(arg0, rec[0xE0C], *(u16 *)(rec + 0xE0A));
        break;
    case 9:
        p = m * 0xE20 + D_800F2C40;
        v = *(s32 *)(p + 0xDE8);
        D_8009AFA0 = m;
        if (*(s32 *)(p + 0xD10) >= 0) {
            if (arg0 != 0) {
                fp = (void (*)(s32, s32, s32))(D_80010010[0] + 4);
            } else {
                fp = (void (*)(s32, s32, s32))(D_8001000C[0] + 4);
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
            func_80048D08(m, (arg0 << 0xB) + D_801A8000);
        }
        break;
    case 0xB:
        if (rec[0xE1D] == 0) {
            rec[0xE1E] = 1;
        }
        rec[0xE1F] = 1;
        break;
    }

tail56828:
    func_8008E870(D_80011594, rec[0xE14], func_80074170(1) - t0);
    v = 0xFF;
    if (rec[0xE1F] == 0) {
        v = rec[0xE14] + 1;
    }
    rec[0xE14] = v;
}
