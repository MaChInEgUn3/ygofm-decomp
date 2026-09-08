/* 207/209 -- DUAS instrucoes a menos -- e, com os opcodes ALINHADOS
 * (tools_src/adiff.py), 205 linhas iguais, DUAS so-de-registrador e UM
 * grupo estrutural. Primeiro rascunho do dia, flags PADRAO.
 *
 * FORMA: maquina de estados sobre `D_8009B3EB & 0xF`, com TRES jump
 * tables -- jtbl_80010410 (10 casos), jtbl_80010438 (5) e jtbl_80010450
 * (6), contiguas em .rodata de 0x80010410 a 0x80010467 com uma palavra de
 * padding em 0x8001044C que o `.align 3` poe. O m2c funde as tres num so
 * `switch` (ha `case 1:` repetido); separa-las e ler as tabelas.
 *
 * LEITURAS DO LISTING, confirmadas:
 *  - `%gp_rel` = 42 e `lui $at` = 0, logo flags PADRAO e nenhum trabalho
 *    de enderecamento (passo 0);
 *  - D_8009B34D e lido `lui %hi`/`lb %lo` -> arm `_IN_DATA`;
 *  - D_8009B3D4 e escrito `%gp_rel` e NAO tinha arm escalar em
 *    variables.h (so `.data`, `[4]` e o `[]` implicito): foi acrescentado
 *    `D_8009B3D4_IS_SCALAR`;
 *  - o caso 0 CAI no caso 1 e o caso 2 CAI no caso 3;
 *  - `.L8003E6EC` e o MEIO do bloco do caso 5 do terceiro switch: o
 *    `bnez` do caso 2 salta para la depois de a constante 6 ja estar em
 *    $v0 pelo delay slot. Escrito como dois `D_8009B3EB = 6; return;`
 *    separados, o cross-jumping reproduz isso;
 *  - dois rabos de juncao: `.L8003E7B8` poe `a1 = 0x18` e cai em
 *    `.L8003E7BC`, que chama. Sao os rotulos `call18:` e `call:`.
 *
 * O QUE ESTA FUNCAO E, e veio da functions.csv do krystalgamer, nao do
 * m2c: os tres callees de biblioteca sao do LIBMCRD --
 * func_8008BC90 = **MemCardAccept**, func_8008C638 = **MemCardReadFile**,
 * func_8008CA78 = **MemCardGetDirentry**. Logo isto e a maquina de
 * estados do CARTAO DE MEMORIA, e as assinaturas reais confirmam os
 * argumentos que o listing mostra:
 *   MemCardGetDirentry(chan, name, dir, files, ofs, max)
 *     -> (D_8009B3F9, D_800EFE18, D_800EFBC0, &sp18, 0, 0xF)
 *   MemCardReadFile(chan, name, adrs, ofs, bytes)
 *     -> (D_8009B3F9, D_800EFE18, D_8009B3D0, D_8009B3C4, D_8009B3C2)
 * ou seja D_800EFE18 e o NOME do ficheiro, D_800EFBC0 e um DIRENTRY,
 * D_8009B3D0 e o endereco de destino e D_8009B3C4/C2 sao offset e
 * tamanho. Nao muda o codegen (sao todos inteiros e ponteiros, e o
 * WORKFLOW ja diz que uma chamada de biblioteca assim nao leva
 * prototipo), mas muda a leitura -- e e exatamente o ponto que o
 * krystalgamer levantou no Discord hoje: um agente que re-deriva os tipos
 * a partir do m2c bate na parede que a definicao verdadeira resolve.
 *
 * SONDA QUE RESPONDE A PERGUNTA CERTA (2026-09-08, dez linhas pelo
 * cc1psx): um `switch` de dez casos com DOIS bracos textualmente
 * identicos e compilado com UMA SO copia a -O1, -O2,
 * `-fno-thread-jumps`, `-fno-delayed-branch`, `-fno-expensive-
 * optimizations`, `-fno-cse-follow-jumps` e `-fno-peephole` -- e com
 * DUAS a -O0. A entrada da tabela do braco mais cedo e REDIRECIONADA
 * para o bloco do mais tarde. Seis grafias do braco na sonda (chamada
 * inline, literal inline, um `goto` para dentro do outro braco, um store
 * extra antes, e o outro braco pelo rabo longo) dao TODAS uma copia,
 * porque o cross-jumping funde o SUFIXO COMUM MAXIMO, nao o bloco
 * inteiro.
 * Consequencia, e e o que reenquadra a busca: **o retail tem duas copias
 * byte a byte iguais (2EF70 e 2EFA4, ambas `j .L8003E7B8` +
 * `addiu $a0,0xD3`), logo a fonte original NAO pode ter tido dois bracos
 * que terminassem da mesma maneira.** Ou uma das duas leituras de `case`
 * esta errada, ou o bloco e alcancado de um modo que este candidato nao
 * modela. Nenhum dos dois rotulos e referenciado de mais lado nenhum --
 * so das entradas 6 e 8 da jtbl_80010410 (verificado com grep em asm/).
 *
 * O QUE FALTA: os casos 6 e 8 sao IDENTICOS (`a0 = 0xD3; j call18;`) e o
 * retail tem DUAS copias; o gcc funde-as, logo faltam duas instrucoes.
 * Medidas e mortas cinco grafias -- a chamada escrita por extenso num dos
 * bracos, nos dois, `y = 0x18; goto call;` no caso 8, e um
 * `do { x = 0xD3; } while (0);` -- e as CINCO dao exatamente o mesmo, o
 * que quer dizer que o braco do caso 8 nunca chega a existir: as duas
 * entradas da tabela apontam para o mesmo rotulo. E a varredura de flags
 * completa (27 linhas do sweep_try.py) tem o padrao como melhor, com o
 * segundo melhor a 143.
 *
 * MAIS MEDIDO E MORTO: CINCO ordens de `case` na fonte -- (5,7,6,8,9),
 * (5,6,8,7,9), (5,7,8,6,9) e (6,5,7,8,9) sao todas identicas ao numerico,
 * e so (5,6,7,9,8), isto e o `case 8` escrito DEPOIS do `case 9`, muda
 * alguma coisa: da 209/209 mas e um FALSO ZERO (censo `addiu -1, nop +1`,
 * 8 instrucoes em 3 grupos estruturais), porque o bloco fundido apenas
 * MUDA DE SITIO, para depois do rabo, e paga um `j`/`nop`. E o permuter,
 * duas rodadas de 110s a `-j 1` a partir daqui (score base 415), zero
 * saidas.
 */
#define D_8009B34D_IN_DATA
#define D_8009B3D4_IS_SCALAR
#include "common.h"

void func_8003E490(void) {
    s32 sp18;
    s32 x;
    s32 y;

    switch (D_8009B3EB & 0xF) {
    case 0:
        if ((D_8009B3EB & 0x80) == 0) {
            D_8009B3EB = D_8009B3EB | 0x80;
            x = 0xC8;
            y = 0x20;
            goto call;
        }
        D_8009B3EB = 1;
        if (D_8009B34D != 0) {
            D_8009B3EB = 9;
            return;
        }
    case 1:
        if ((D_8009B3EB & 0x80) == 0) {
            y = 0xD4;
            D_8009B3EB = D_8009B3EB | 0x80;
            D_801D5648[0] = (D_8009B3F9 >> 4) + 1;
            if ((D_8009B3FA & 0x200) != 0) {
                y = 0xC0;
            }
            func_8003E46C(y, 0);
            do {
            } while (func_8008BC90(D_8009B3F9) == 0);
            goto setflag;
        }
        switch (D_8009B3F4) {
        case 0:
        case 3:
            D_8009B3EB = 2;
            return;
        case 1:
            D_8009B3EB = 5;
            return;
        case 2:
        case 4:
            D_8009B3EB = 6;
            return;
        }
        return;
    case 2:
        if (func_8008CA78(D_8009B3F9, D_800EFE18, D_800EFBC0, &sp18, 0, 0xF) != 0) {
            D_8009B3EB = 6;
            return;
        }
        if (sp18 == 0) {
            D_8009B3EB = 6;
            return;
        }
        D_8009B3EB = 3;
    case 3:
        if ((D_8009B3EB & 0x80) == 0) {
            D_8009B3EB = D_8009B3EB | 0x80;
            func_8003E46C(0xD5, 0);
            func_8008C638(D_8009B3F9, D_800EFE18, D_8009B3D0, D_8009B3C4, D_8009B3C2);
setflag:
            D_8009B3FA = D_8009B3FA | 0x1000;
            return;
        }
        switch (D_8009B3F4) {
        case 0:
            D_8009B3EB = 7;
            if (func_8003D174((u8 *)D_8009B3D0) != 0) {
                return;
            }
            D_8009B3EB = 4;
            if ((D_8009B3FA & 0x400) != 0) {
                x = 0xBD;
                goto call18;
            }
            D_8009B3FA = D_8009B3FA | 0x400;
            return;
        case 1:
            D_8009B3EB = 5;
            return;
        case 2:
        case 3:
            D_8009B3EB = 8;
            return;
        case 4:
            return;
        case 5:
            D_8009B3EB = 6;
            return;
        }
        return;
    case 4:
        if ((D_8009B3EB & 0x80) == 0) {
            D_8009B3EB = D_8009B3EB | 0x80;
            x = 0xBD;
            y = 0x10;
            goto call;
        }
        if ((D_8009B3EB & 0x40) == 0) {
            D_8009B3EB = D_8009B3EB | 0x40;
            x = 0xBC;
            y = 0x20;
            goto call;
        }
        D_8009B3EB = 9;
        if (D_8009B34D != 0) {
            return;
        }
        D_8009B3EB = 3;
        D_8009B3C4 = D_8009B3C4 + 0x680;
        return;
    case 5:
        x = 0xC1;
        goto call18;
    case 6:
        x = 0xD3;
        goto call18;
    case 7:
        D_8009B3EF = 1;
        x = 0xD0;
        if ((D_8009B3FA & 0x200) != 0) {
            y = 8;
            goto call;
        }
        D_8009B3D4 = 0;
        y = 0x18;
        goto call;
    case 8:
        x = 0xD3;
        goto call18;
    case 9:
        D_8009B3EF = 3;
        x = 0xC7;
call18:
        y = 0x18;
call:
        func_8003E46C(x, y);
        return;
    }
}
