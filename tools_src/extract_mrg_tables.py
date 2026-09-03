"""Decode fusion / equip / ritual / rank out of WA_MRG.MRG using the sector
arithmetic the game itself uses (func_8001798C, func_800179F4, func_800171A8).
Usage: extract_mrg_tables.py <WA_MRG.MRG> [outdir]

WA_MRG.MRG is /DATA/WA_MRG.MRG on the retail disc (LBA 10102); pass the raw
file (2048-byte sectors, i.e. already de-rawed from the .img).  Sector
numbers below are relative to the start of that file, which is what the game's
own arithmetic uses (setFilePosTable stores the file's LBA and func_80014E1C
adds it).

Per-terrain duel blob (func_8001798C): sector 0x16C6 + 235*terrain, 235
sectors, dispatched chunk by chunk by func_800171A8; its jump table
(jtbl_800100C0) gives the case order, the record's +0x1C field the size, and
the sizes sum to exactly 235*0x800 -- which is the proof of the layout.
Per-duelist block (func_800179F4): sector 0x1D33 + 3*opponent, 3 sectors, to
D_801781D8; the rank table D_801798A8 is +0x16D0 inside it.

Output is gitignored raw game data; this script and decode_tables.py are the
method."""
import sys, struct, csv, hashlib, importlib.util, os
here=os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, here)
import decode_tables as dt
mrg=open(sys.argv[1],'rb').read()
out=sys.argv[2] if len(sys.argv)>2 else os.path.join(here,'..','third_party','carddata')
os.makedirs(out, exist_ok=True)
S=2048
# names are optional: cards.tsv is produced from the executable by the card extractor and is gitignored
names={}
cards=os.path.join(out,'cards.tsv')
if os.path.exists(cards):
    names={int(r['card_number']):r['name'] for r in csv.DictReader(open(cards),delimiter='\t')}
class _Names(dict):
    def __missing__(self, k): return str(k)   # no cards.tsv: print the id
names=_Names(names)
# --- per-terrain duel blob: sector 0x16C6 + 235*terrain, 235 sectors (func_8001798C) ---
LAYOUT=[(0x00000,0x20000,'VRAM (768,256)'),(0x20000,0x2000,'staging -> LoadImage2 rect(256,240,256,16)'),
        (0x22000,0x2800,'equip table -> D_8017A1D8'),(0x24800,0x10000,'fusion table -> D_8017C2D8'),
        (0x34800,0x800,'ritual table -> D_801799D8'),(0x35000,0x1000,'staging -> LoadImage2 rect(0,240,256,8)'),
        (0x36000,0x10000,'VRAM (512,?)'),(0x46000,0x16000,'overlay code -> *D_800101DC (0x80146000)'),
        (0x5C000,0x1800,'-> D_801A8000'),(0x5D800,0x1800,'-> D_801A9800'),(0x5F000,0x4000,'VRAM (832,0)'),
        (0x63000,0x2800,'-> *D_80010000 (0x80100000)'),(0x65800,0x10000,'VRAM (640,256)')]
assert sum(s for _,s,_ in LAYOUT)==235*S
def blob(t): b=(0x16C6+235*t)*S; return mrg[b:b+235*S]
b0=blob(0)
F=list(dt.decode_fusion(b0[0x24800:0x34800],max_id=723)); E=list(dt.decode_equip(b0[0x22000:0x24800])); R=list(dt.decode_ritual(b0[0x34800:0x35000]))
assert all(1<=x<=722 for r in F for x in r) and all(1<=x<=722 for r in E for x in r)
same=[t for t in range(7) if all(blob(t)[o:o+s]==b0[o:o+s] for o,s,_ in LAYOUT[2:5])]
print("fusion rows=%d  equip rows=%d (keys=%d)  ritual rows=%d ; terrains with identical tables: %s"%(len(F),len(E),len({k for k,_ in E}),len(R),same))
with open(os.path.join(out,'fusion.tsv'),'w') as f:
    f.write("card_a\tcard_b\tresult\tname_a\tname_b\tname_result\n")
    for a,b,c in F: f.write("%d\t%d\t%d\t%s\t%s\t%s\n"%(a,b,c,names[a],names[b],names[c]))
with open(os.path.join(out,'equip.tsv'),'w') as f:
    f.write("equip_id\tmonster_id\tequip_name\tmonster_name\n")
    for k,m in E: f.write("%d\t%d\t%s\t%s\n"%(k,m,names[k],names[m]))
# --- per-duelist block: sector 0x1D33 + 3*duelist, 3 sectors -> D_801781D8 (func_800179F4); rank at D_801798A8 = +0x16D0 ---
with open(os.path.join(out,'rank.tsv'),'w') as f:
    f.write("duelist\trow\tpairs\n")
    for d in range(40):
        blk=mrg[(0x1D33+3*d)*S:(0x1D33+3*d+3)*S]
        rk=dt.decode_rank(blk[0x16D0:0x16D0+200])
        for i,row in enumerate(rk): f.write("%d\t%d\t%s\n"%(d,i,row))
        if d in (0,1,38): print("duelist %2d rank:"%d, rk[:3], "...")
# stats
from collections import Counter
print("fusion: distinct results=%d, top results=%s"%(len({c for *_,c in F}),[(names[c],n) for c,n in Counter(c for *_,c in F).most_common(3)]))
td=[i for i,n in names.items() if n=='Thunder Dragon']; print("Thunder Dragon",td,"+ itself ->",[names[c] for a,b,c in F if a in td and b in td])
print("equip: Legendary Sword? key 301 =",names[301],"members",sum(1 for k,_ in E if k==301))

# --- per-duelist block, the rest of it: deck weights and the three drop pools.
# Each is 722 x u16 and sums to 2048 (the draw is a 0..2047 roll walked
# against cumulative weights); the runtime pools D_8017878C / D_80178D40 /
# D_801792F4 are these offsets from D_801781D8.
POOLS=[("deck",0x0),("pow",0x5B4),("bcd",0xB68),("tec",0x111C)]
# Block index = opponent id (D_8009B361), 1-based; block 0 duplicates block 1.
# Names assigned by matching each block's pools against the Neoseeker guide's
# per-duelist "cards won" lists (92-100% per duelist); see the_game.md 6.4.
DUELISTS=["(unused: copy of 1)","Simon Muran","Teana","Jono","Villager 1","Villager 2","Villager 3","Seto","Heishin",
 "Rex Raptor","Weevil Underwood","Mai Valentine","Bandit Keith","Shadi","Yami Bakura","Pegasus","Isis","Kaiba",
 "Mage Soldier","Jono 2nd","Teana 2nd","Ocean Mage","High Mage Secmeton","Forest Mage","High Mage Anubisius",
 "Mountain Mage","High Mage Atenza","Desert Mage","High Mage Martis","Meadow Mage","High Mage Kepura",
 "Labyrinth Mage","Seto 2nd","Guardian Sebek","Guardian Neku","Heishin 2nd","Seto 3rd","DarkNite","Nitemare","Duel Master K"]
blocks=[mrg[(0x1D33+3*d)*S:(0x1D33+3*d+3)*S] for d in range(40)]   # 0 unused, 1..38 campaign order, 39 Duel Master K
with open(os.path.join(out,'drops.tsv'),'w') as f, open(os.path.join(out,'deck_weights.tsv'),'w') as g:
    f.write("duelist_id\tduelist\tpool\tcard_id\tcard\tweight\n"); g.write("duelist_id\tduelist\tcard_id\tcard\tweight\n")
    for d,blk in enumerate(blocks):
        for nm,off in POOLS:
            w=struct.unpack_from('<722H',blk,off); assert sum(w)==2048, (d,nm,sum(w))
            for i,x in enumerate(w):
                if x:
                    if nm=="deck": g.write("%d\t%s\t%d\t%s\t%d\n"%(d,DUELISTS[d],i+1,names[i+1],x))
                    else: f.write("%d\t%s\t%s\t%d\t%s\t%d\n"%(d,DUELISTS[d],nm,i+1,names[i+1],x))
dups=[(a,b) for a in range(40) for b in range(a+1,40) if blocks[a]==blocks[b]]
pdups=[(a,b) for a in range(40) for b in range(a+1,40) if blocks[a][0x5B4:0x16D0]==blocks[b][0x5B4:0x16D0]]
print("drops: 40 x 4 weight tables, all sum 2048; identical whole blocks: %s; identical pool triples: %s"%(dups,pdups))
