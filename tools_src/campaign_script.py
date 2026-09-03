"""Campaign story data, read off the game's own structures.

Two things live here, both measured against SLUS_014.11 (NTSC-U):

1. The EVENT SCRIPT: func_8002FD10(scene) loads 49 sectors at WA_MRG.MRG
   sector 0x1E57 (callback func_8002FB78) and the third chunk, 4 KB at blob
   +0x8800, lands at D_801A8000. It starts with u16 offset[scene]; each scene
   is a byte stream run by func_8002FA54 through the 23-entry table
   D_80090C50 (opcode = byte & 0x1F). Opcode 3 is the flag opcode
   (func_8002E918): u16 operand, bit 14 = set/clear, else "if flag, jump".

2. The DIALOGUE TEXTS, in the executable: text id 0x5xx -> u16 table at
   0x801C0000 index (id - 0x100), pointer = 0x801B0000 + offset
   (func_800383DC). Bytes < 0xF0 are characters (0x00-0x5B decode with the
   community's table.tbl), 0xF0-0xFF are control codes dispatched through
   D_80090F18 (func_800393B0): F8 <op> is the sub-table D_80090EAC (op 0x19 =
   func_80038AB0 = "unlock duelist <byte>"), F9 <u16> is the flag opcode
   (func_80038D2C: bit 14 set/clear, else conditional jump with a u16 target),
   FD <u16> jump, FE newline, FF end.

Usage: campaign_script.py <WA_MRG.MRG> [datacrystal_notes.txt] [--md]
Prints the flag map (which dialogue sets / tests each save flag) and, with
--md, the markdown table used by docs/research/the_game.md.
"""
import sys, struct, re, collections, bisect, os
mrg=open(sys.argv[1],'rb').read(); S=2048
here=os.path.dirname(os.path.abspath(__file__)); root=os.path.dirname(here)
exe=open(os.path.join(root,'extracted','SLUS_014.11'),'rb').read(); D=0x8000F800
T=0x801C0000-D; BASE=0x801B0000-D
notes=[a for a in sys.argv[2:] if not a.startswith('--')]
names={}
if notes:
    for l in open(notes[0],encoding='utf-8',errors='replace'):
        m=re.match(r'^([0-9A-F]{3})\s+(.+)$',l.strip())
        if m: names[int(m.group(1),16)]=m.group(2)
tbl={}
tp=os.path.join(root,'third_party','tutorials','table.tbl')
if os.path.exists(tp):
    for l in open(tp,encoding='latin1'):
        l=l.rstrip('\n')
        if '=' in l: k,v=l.split('=',1); tbl[int(k,16)]=v
DUEL=["?","Simon Muran","Teana","Jono","Villager 1","Villager 2","Villager 3","Seto","Heishin","Rex Raptor","Weevil Underwood","Mai Valentine","Bandit Keith","Shadi","Yami Bakura","Pegasus","Isis","Kaiba","Mage Soldier","Jono 2nd","Teana 2nd","Ocean Mage","High Mage Secmeton","Forest Mage","High Mage Anubisius","Mountain Mage","High Mage Atenza","Desert Mage","High Mage Martis","Meadow Mage","High Mage Kepura","Labyrinth Mage","Seto 2nd","Guardian Sebek","Guardian Neku","Heishin 2nd","Seto 3rd","DarkNite","Nitemare"]
# ---------- event script ----------
scr=mrg[0x1E57*S+0x8800:0x1E57*S+0x9800]
u16=lambda o: struct.unpack_from('<H',scr,o)[0]
nsc=u16(0)//2; offs=[u16(i*2) for i in range(nsc)]
ev_tests=collections.defaultdict(set); ev=[]
for i,o in enumerate(offs):
    p=o; items=[]
    while p<0x1000:
        op=scr[p]&0x1F; p+=1
        if op==1: x=u16(p); p+=2+(4 if x&0x8000 else 0); items.append('bg %d'%(x&0xFFF))
        elif op==2: x=u16(p); p+=2; items.append('dialog %03X'%(x&0xFFF))
        elif op==3:
            a=u16(p); p+=2
            if a&0x4000: items.append('%s %02X'%('clr' if a&0x8000 else 'set',a&0x7FF))
            else: b=u16(p); p+=2; items.append('if%s %02X'%('!' if a&0x8000 else '',a&0x7FF)); ev_tests[a&0x7FF].add(i)
        elif op==4: x=u16(p); p+=2+(4 if x&0x8000 else 0)
        elif op==6: p+=6
        elif op==8: items.append('map %d'%scr[p]); p+=1; break
        elif op==9: p+=2
        elif op==10: c=scr[p]; p+=1+(2 if (c&0x3F)==0 or (c&2) else 0)
        elif op==11: p+=1
        elif op==12: items.append('goto'); p+=2; break
        elif op==13: p+=4
        elif op==17: p+=2
        elif op==20: p+=2
        elif op==21: items.append('ifDeckNotReady'); p+=2
        elif op in (18,19,22): items.append({18:'gameover',19:'credits',22:'title'}[op]); break
    ev.append((i,o,items))
# ---------- dialogue texts ----------
SUB={0:1,1:1,2:1,3:4,4:1,5:1,6:0,7:2,8:0,9:0,10:1,11:1,12:1,13:6,14:2,15:1,16:2,17:1,18:0,19:0,20:1,21:1,22:0,23:2,24:2,25:1,26:0}
ptr={}
for tid in list(range(0,0x100))+list(range(0x500,0x600)):
    idx=tid-0x100 if tid>=0x500 else tid; ptr[tid]=BASE+struct.unpack_from('<H',exe,T+idx*2)[0]
owners=sorted((a,t) for t,a in ptr.items()); starts=[a for a,_ in owners]
def owner(pos):
    i=bisect.bisect_right(starts,pos)-1; return owners[i][1] if i>=0 else None
def walk(a,end):
    p=a; out=[]
    while p<end:
        b=exe[p]
        if b<0xF0 or b in (0xFA,0xFE,0xFF): p+=1; continue
        if b<=0xF5: p+=2
        elif b==0xF6: p+=3
        elif b==0xF7: p+=4
        elif b==0xF8:
            op=exe[p+1]
            if op>=27: p+=1; continue
            if op==25: out.append((p,'UNLOCK',exe[p+2]))
            p+=2+SUB[op]
        elif b==0xF9:
            v=struct.unpack_from('<H',exe,p+1)[0]; f=v&0x7FF
            if v&0x4000: out.append((p,'CLR' if v&0x8000 else 'SET',f)); p+=3
            else: out.append((p,'IF!' if v&0x8000 else 'IF',f)); p+=5
        elif b==0xFB: t=exe[p+1]; p+=2+(0 if t&0x80 else 1)
        elif b in (0xFC,0xFD): p+=3
        else: p+=1
    return out
by=collections.defaultdict(lambda: collections.defaultdict(set))
for k,(a,t) in enumerate(owners):
    end=starts[k+1] if k+1<len(owners) else 0x1C8DA0
    for pos,kind,v in walk(a,end):
        o=owner(pos)
        if o is None: continue
        by[v if kind!='UNLOCK' else 0x1000+v][kind].add(o)
def snip(t):
    a=ptr[t]; return ''.join(tbl.get(b,'') if b<0x60 else (' ' if b==0xFE else '') for b in exe[a:a+160]).strip()
MEANING={0x47:'the tournament is over and the prince is back in Egypt (set by Simon in 56A)',0x48:"heard Simon's tale of the cards (505)",0x49:'Villager 1 has told you about the festival (50C)',0x4A:'talked to Villager 2 (510)',0x4B:'talked to Villager 3 (514)',0x4D:'saw the mages waiting for Seto at the shrine (53D)',0x4E:'Villager 1 has lost to you and changed his line (537)',0x4F:'Villager 2 has lost to you and gone home (53A)',0x50:'met Sadin at King\'s Valley (585/586)',0x51:'found the map to the Forbidden Ruins in the palace (581)',0x52:'handed the map to Sadin (585)',0x53:'entered the Forbidden Ruins (58A)',0x54:'looked at the map in the ruins (58A)',0x5A:'found the hidden Dueling Grounds (583)',0x5B:'set and re-tested inside Jono 2nd\'s hub dialogue (5DA); purpose read as a once-only line',0x5C:'the kidnapping scene has played (5DA; High Mage defeats test it)',0x5D:'all five High Mages beaten: Seto\'s "you defeated the High Mages" (5BF)',0x5E:'visited the hiding card shop (5D8)',0x5F:'set and re-tested inside dialogue 5DA; purpose read as a once-only line',0x60:'looked at the drawing in the ruins (58A)',0x61:'set and re-tested inside Teana 2nd\'s dialogue (5DB); purpose read as a once-only line',0x62:'set and re-tested inside dialogue 5DB; purpose read as a once-only line',0x63:'set and re-tested inside dialogue 5DC; purpose read as a once-only line',0x64:'set and re-tested inside dialogue 5DC; purpose read as a once-only line',0x65:'set and re-tested inside dialogue 5DD; purpose read as a once-only line',0x66:'set and re-tested inside dialogue 5DD; purpose read as a once-only line',0x67:'set and re-tested inside dialogue 5DE; purpose read as a once-only line',0x68:'set and re-tested inside dialogue 5DE; purpose read as a once-only line',0x69:'labyrinth: progress bit (5F2)',0x6A:'labyrinth: progress bit (5F3)',0x6B:'labyrinth: progress bit (5F3)',0x6C:'labyrinth: progress bit (5F3)',0x6D:'set with 0x5D after the fifth High Mage; tested by Seto at the labyrinth door (5EE)',0x6E:"Simon's evening lecture has happened (501/502)",0x6F:'Seto has challenged you at the festival (521/522)'}
fmt=lambda s: ','.join('%03X'%t for t in sorted(s))
if '--md' in sys.argv:
    print("| flag | set by (dialogue) | tested by | what it records |"); print("|---|---|---|---|")
    for f in range(0x20,0x46):
        d=by.get(f,{}); tests=sorted(d.get('IF',set())|d.get('IF!',set())); ev_t=sorted(ev_tests.get(f,()))
        if tests or ev_t: print("| `0x%02X` | (unlock opcode, with `0x%X`) | %s%s | %s beaten |"%(f,0x6E0+f-0x1F,fmt(tests),(' + events %s'%','.join(map(str,ev_t)) if ev_t else ''),DUEL[f-0x1F]))
    for f in sorted(k for k in by if 0x46<=k<0x80):
        d=by[f]; sets=sorted(d.get('SET',set())|d.get('CLR',set())); tests=sorted(d.get('IF',set())|d.get('IF!',set())); ev_t=sorted(ev_tests.get(f,()))
        print("| `0x%02X` | %s | %s%s | %s |"%(f,fmt(sets) or '—',fmt(tests) or '—',(' + events %s'%','.join(map(str,ev_t)) if ev_t else ''),MEANING.get(f,'(not read)')))
    print("\nEvents in the event script that test flags: %s"%', '.join('0x%02X→%s'%(f,','.join(map(str,sorted(v)))) for f,v in sorted(ev_tests.items())))
else:
    print("event script: %d scenes"%nsc)
    for f in sorted(by):
        if f>=0x1000: print("UNLOCK id %2d %-20s <- %s"%(f-0x1000,DUEL[f-0x1000],fmt(by[f]['UNLOCK'])))
        else: print("flag 0x%03X %s"%(f,' | '.join('%s %s'%(k,fmt(v)) for k,v in sorted(by[f].items()))))
