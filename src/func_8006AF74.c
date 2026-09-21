/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_subdivided_effect.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern MATRIX *func_80087480(MATRIX *m0,MATRIX *m1);
extern MATRIX *func_80087D30(SVECTOR *r,MATRIX *m);
extern void func_800871D0();
extern void func_80087274();
extern void func_80087970(SVECTOR *v0,VECTOR *v1,long *flag);
extern long func_80087B30(SVECTOR *v0,SVECTOR *v1,SVECTOR *v2,
			long *sxy0,long *sxy1,long *sxy2,
			long *p,long *otz,long *flag);
extern void func_800828E0(POLY_G3 *p) ;
extern void func_80082960(POLY_G4 *p) ;
void    func_80083FB0(GsLINE * lp, GsOT * ot, unsigned short pri);
extern void *func_8008E3D0 ( );
extern char *index  (const char *, char);
extern u32 D_800915E8[];
void func_80057E20(s32 index, ModelEffectAdjustment *out);
s32 func_80058E1C(void);
GsOT *func_80058F10(void);
extern VECTOR D_8001185C;
extern char D_8001186C[];
s32 func_8006AF74(ModelSubdividedEffect *data, s32 mode);
s16 *func_8006BCA4(s16 *a, s16 *b, s16 *c, s16 *out, s32 depth);
Triplet *func_8006C120(u8 *a, u8 *b, u8 *c, Triplet *out, s32 depth);
void func_8006C2FC(u8 *output, s32 first, s32 second, s32 third);
s32 func_80058DCC(void);
void *func_80059220(void);
s32 func_8006AF74(ModelSubdividedEffect *data, s32 mode)
{
    MATRIX base;
    MATRIX matrix;
    POLY_G3 triangle;
    POLY_G4 quad;
    GsLINE line;
    SVECTOR rotation;
    SVECTOR position;
    VECTOR scale;
    ModelEffectAdjustment bounds;
    s32 flag;
    s32 interpolation;
    s32 depth;
    GsOT *ot;
    s32 i;
    ModelSubdividedEffect *effect;
    ModelSubdividedEffectConfig *config;
    SVECTOR *vertex;
    Triplet *color;
    SVECTOR **vertices;
    u8 **colors;
    s32 height;
    s32 elapsed;
    s32 remaining;
    s32 work;
    s32 red, green, blue;

    func_8008E3D0(&rotation, 0, sizeof(rotation));
    func_8008E3D0(&position, 0, sizeof(position));
    scale = D_8001185C;
    effect = data;
    func_80058DCC();
    {
        s32 ticks = func_80058E1C();
        if (mode >= 0) {
            config = effect->config = (ModelSubdividedEffectConfig *)D_800915E8;
            func_80057E20(func_80058DCC(), &bounds);
            work = height = bounds.max;
            work /= 2;
            height /= 2;
            work = (( work ) < (  config->minimum_radius ) ? (  config->minimum_radius ) : (( work ) > (  700 ) ? (  700 ) : ( work ))) ;
            height = (( height ) < (  config->minimum_height ) ? (  config->minimum_height ) : (( height ) > (  700 ) ? (  700 ) : ( height ))) ;
            vertex = &effect->vertices[0];
            vertex->vx = 0;
            vertex->vy = -height;
            vertex->vz = 0;
            vertex = &effect->vertices[1];
            vertex->vx = 0;
            vertex->vy = 0;
            vertex->vz = -work;
            vertex = &effect->vertices[2];
            vertex->vx = -work;
            vertex->vy = 0;
            vertex->vz = 0;
            vertex = &effect->vertices[3];
            vertex->vx = 0;
            vertex->vy = 0;
            vertex->vz = work;
            vertex = &effect->vertices[4];
            vertex->vx = work;
            vertex->vy = 0;
            vertex->vz = 0;
            vertex = &effect->vertices[5];
            vertex->vx = 0;
            vertex->vy = height;
            vertex->vz = 0;
            color = effect->colors;
            for (i = 0; i < 6; color++, i++) {
                func_8006C2FC(*color, config->colors[0][i],
                    config->colors[1][i], config->colors[2][i]);
            }
            vertex = effect->vertices;
            color = effect->colors;
            vertices = effect->vertex_links;
            colors = effect->color_links;
            for (i = 1; i < 5; i++) {
                *vertices = vertex;
                vertices++;
                *colors = color[0];
                colors++;
                *vertices = &vertex[i];
                vertices++;
                *colors = color[i];
                colors++;
                *vertices = &effect->vertices[i % 4] + 1;
                vertices++;
                *colors = effect->colors[i % 4] + 4;
                colors++;
            }
            for (i = 1; i < 5; i++) {
                *vertices = &vertex[5];
                vertices++;
                *colors = color[5];
                colors++;
                *vertices = &effect->vertices[i % 4] + 1;
                vertices++;
                *colors = effect->colors[i % 4] + 4;
                colors++;
                *vertices = &vertex[i];
                vertices++;
                *colors = color[i];
                colors++;
            }
            vertex = effect->subdivided_vertices;
            color = effect->subdivided_colors;
            vertices = effect->vertex_links;
            colors = effect->color_links;
            for (i = 0; i < 8; i++) {
                func_8006BCA4((s16 *)vertices[0], (s16 *)vertices[1],
                    (s16 *)vertices[2], (s16 *)vertex, 2);
                vertices += 3;
                vertex += 48;
                func_8006C120(colors[0], colors[1], colors[2], color, 2);
                colors += 3;
                color += 48;
            }
            effect->elapsed = 0;
            effect->remaining = config->fade_duration;
            effect->field_130C = 0;
            effect->field_130D = 0;
            func_8008E870(D_8001186C, 0x1318, 0x1318);
            return 0;
        }

        config = effect->config;
        vertex = effect->subdivided_vertices;
        ot = func_80058F10();
        base = *(MATRIX *)func_80059220();
        color = effect->subdivided_colors;
        func_800871D0();
        func_800828E0(&triangle);
        func_80082960(&quad);
        line.attribute = 0x50000000;
        elapsed = effect->elapsed;
        remaining = effect->remaining;
        rotation.vx = 0;
        rotation.vy = (u32)elapsed << 5;
        rotation.vz = 0;
        func_800855D0(&base);
        func_80058FB0(func_80058DCC(), (u16 *)&position);
        func_800855D0(&base);
         
        func_80087970(&position, (VECTOR *)matrix.t, (long *)&flag);
        func_80087D30(&rotation, &matrix);
        func_80087480(&base, &matrix);
        func_80087670(&matrix, &scale);
        func_800855D0(&matrix);
        {
            s32 triangle_index;
            for (triangle_index = 0; triangle_index < 128; triangle_index++) {
                work = func_80087B30(vertex, vertex + 1, vertex + 2,
                    (long *)&triangle.x0, (long *)&triangle.x1, (long *)&triangle.x2,
                    (long *)&interpolation, (long *)&depth, (long *)&flag);
                if (remaining >= 0 && remaining < config->fade_duration) {
                    red = (*color)[0] * remaining / config->fade_duration;
                    green = (*color)[1] * remaining / config->fade_duration;
                    blue = (*color)[2] * remaining / config->fade_duration;
                    color++;
                    triangle.r0 = red;
                    triangle.g0 = green;
                    triangle.b0 = blue;
                    red = (*color)[0] * remaining / config->fade_duration;
                    green = (*color)[1] * remaining / config->fade_duration;
                    blue = (*color)[2] * remaining / config->fade_duration;
                    color++;
                    triangle.r1 = red;
                    triangle.g1 = green;
                    triangle.b1 = blue;
                    red = (*color)[0] * remaining / config->fade_duration;
                    green = (*color)[1] * remaining / config->fade_duration;
                    blue = (*color)[2] * remaining / config->fade_duration;
                    color++;
                    triangle.r2 = red;
                    triangle.g2 = green;
                    triangle.b2 = blue;
                } else if (elapsed >= 0 && elapsed < config->growth_duration) {
                    red = (*color)[0] * elapsed / config->growth_duration;
                    green = (*color)[1] * elapsed / config->growth_duration;
                    blue = (*color)[2] * elapsed / config->growth_duration;
                    color++;
                    triangle.r0 = red;
                    triangle.g0 = green;
                    triangle.b0 = blue;
                    red = (*color)[0] * elapsed / config->growth_duration;
                    green = (*color)[1] * elapsed / config->growth_duration;
                    blue = (*color)[2] * elapsed / config->growth_duration;
                    color += 2;
                    triangle.r1 = red;
                    triangle.r2 = red;
                    triangle.g1 = green;
                    triangle.g2 = green;
                    triangle.b1 = blue;
                    triangle.b2 = blue;
                } else {
                    triangle.r0 = (*color)[0];
                    triangle.g0 = (*color)[1];
                    triangle.b0 = (*color)[2];
                    color++;
                    triangle.r1 = (*color)[0];
                    triangle.g1 = (*color)[1];
                    triangle.b1 = (*color)[2];
                    color++;
                    triangle.r2 = (*color)[0];
                    triangle.g2 = (*color)[1];
                    triangle.b2 = (*color)[2];
                    color++;
                }
                if (depth >= 0 && flag >= 0 && work > 0) {
                    func_8005B260((u32 *)&triangle, ot, (u16)depth, 1);
                }
                vertex += 3;
            }
        }
        if (remaining >= 0 && remaining < config->fade_duration) {
            line.r = (remaining << 5) / config->fade_duration;
            line.g = (remaining << 5) / config->fade_duration;
            line.b = (remaining << 5) / config->fade_duration;
        } else if (elapsed >= 0 && elapsed < config->growth_duration) {
            line.r = (elapsed << 5) / config->growth_duration;
            line.g = (elapsed << 5) / config->growth_duration;
            line.b = (elapsed << 5) / config->growth_duration;
        } else {
            line.r = 32;
            line.g = 32;
            line.b = 32;
        }
        vertices = effect->vertex_links;
        for (i = 0; i < 8; i++) {
            work = func_80087B30(vertices[0], vertices[1], vertices[2],
                (long *)&triangle.x0, (long *)&triangle.x1, (long *)&triangle.x2,
                (long *)&interpolation, (long *)&depth, (long *)&flag);
            if (depth >= 0 && flag >= 0 && work > 0) {
                line.x0 = triangle.x0;
                line.y0 = triangle.y0;
                line.x1 = triangle.x1;
                line.y1 = triangle.y1;
                func_80083FB0(&line, ot, (u16)depth);
                line.x0 = triangle.x2;
                line.y0 = triangle.y2;
                func_80083FB0(&line, ot, (u16)depth);
                line.x1 = triangle.x0;
                line.y1 = triangle.y0;
                func_80083FB0(&line, ot, (u16)depth);
            }
            vertices += 3;
        }
        func_80087274();
        effect->elapsed += ticks;
        if (mode == -2) {
            effect->remaining -= ticks;
        }
        return (effect->remaining < 0) * 2;
    }
}
