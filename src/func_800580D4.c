/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_update_view_metrics.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u16 D_8009B47A;
extern u16 D_8009B47C;
static __inline__ void setup_rotation(
    SVECTOR *source,
    SVECTOR *copy,
    s32 turn,
    GsCOORDUNIT *unit
)
{
    source->vy = turn - D_8009B47A;
    source->vz = D_8009B47C;
    *copy = *source;

    unit->flg = 0;
    unit->rot.vx =
        turn - ((volatile ModelSlot *)D_800F2C40)->field_D18->rot.vx;
    unit->rot.vy =
        turn - ((volatile ModelSlot *)D_800F2C40)->field_D18->rot.vy;
    unit->rot.vz =
        turn - (u16)((volatile ModelSlot *)D_800F2C40)->field_D18->rot.vz;
    func_800889C0(&unit->rot, &unit->matrix);
}
static __inline__ void build_work_matrix(SVECTOR *rotation, MATRIX *work)
{
    func_80088E50(rotation, work);
}
void func_800580D4(s32 index, s32 arg1, u8 *arg2, GsCOORDUNIT *arg3)
{
    GsCOORDUNIT unit;
    SVECTOR ang;
    MATRIX ls;
    SVECTOR sv88;
    SVECTOR sv90;
    MATRIX work;
    u8 scratch[8];
    ModelSlot *slot;

    slot = &D_800F2C40[index];
    if (slot->entry_count < arg1) {
        arg1 = slot->field_E18;
    }

    func_8008A4A0(
        (GsCOORDUNIT *)(slot->entries + arg1 * 80 ),
        &ls
    );
    func_800855D0(&ls);

    func_80089CC0((SVECTOR *)arg2, &ang, (long *)scratch);

    unit.rot.vz = 0;
    unit.rot.vy = 0;
    unit.rot.vx = 0;
    func_80088E50(&unit.rot, &unit.matrix);

    unit.flg = 1;
    unit.matrix.t[0] = ang.vx;
    unit.matrix.t[1] = ang.vy;
    unit.matrix.t[2] = ang.vz;
    unit.workm = unit.matrix;
    unit.super = 0 ;
    func_8008E3D0(&sv90, 0, sizeof(sv90));

    setup_rotation(&sv90, &sv88, 0x1000 , arg3);

    build_work_matrix(&sv88, &work);
    func_80087370(&arg3->matrix, &work);

    arg3->matrix.t[2] = 0;
    arg3->matrix.t[1] = 0;
    arg3->matrix.t[0] = 0;
    arg3->super = &unit;
}
