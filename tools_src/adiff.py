"""Alinha os opcodes dos dois fluxos de try_func com difflib e separa as
diferencas SO-DE-REGISTRADOR das ESTRUTURAIS.

O diff da try_func e posicional: uma instrucao deslocada marca como
diferente todas as linhas depois dela, e isso JA INVERTEU uma ordenacao
(func_80030294: um candidato de 248 e melhor que um de 235). Uso:

    .venv/bin/python tools_src/adiff.py <saida-da-try_func.txt> ...

Imprime, por arquivo: quantas linhas casam exatas depois do alinhamento,
quantas diferem SO no nome do registrador, quantas instrucoes ficam em
blocos estruturais, e quantos blocos sao.
"""
import sys,difflib
def load(p):
    lines=open(p).read().split('\n')
    st=[i for i,l in enumerate(lines) if l.startswith('TARGET')][0]+2
    T=[];B=[]
    for l in lines[st:]:
        if l.startswith('---') or not l.strip(): continue
        if 'target instruction' in l: break
        t=l[:45].rstrip(); b=l[45:].replace('<<','').rstrip()
        if t: T.append(t)
        if b: B.append(b)
    return T,B
for p in sys.argv[1:]:
    T,B=load(p)
    sm=difflib.SequenceMatcher(None,[x.split()[0] for x in T],[x.split()[0] for x in B],autojunk=False)
    same=0;regdiff=0;struct=0;groups=0
    for tag,i1,i2,j1,j2 in sm.get_opcodes():
        if tag=='equal':
            for a,b in zip(T[i1:i2],B[j1:j2]):
                if a==b: same+=1
                else: regdiff+=1
        else:
            groups+=1; struct+=max(i2-i1,j2-j1)
    print(f"{p.split('/')[-1]:12s} aligned-equal={same} reg-only={regdiff} struct={struct} groups={groups}")
