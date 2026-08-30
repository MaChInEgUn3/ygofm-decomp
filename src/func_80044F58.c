/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Sets a status flag, builds a 4-byte volume/id packet and hands it to
   func_8007CDC0 (real signature: func_8007CDC0(u_char *vol) sets CD-DA output volume; f1/f2
   pick which of two byte slots carries the id depending on D_8009B45C's f48
   flag), then updates two more D_8009B45C fields. D_8009B45C is re-fetched
   through a fresh alias at each access group (a/b/c/d) rather than cached
   once -- the real ROM reloads it the same way, see
   project_g0_licm_fresh_name_per_reload / project_d8009b45c_reload_pointer_trick. */
struct S8009B45C {
    char pad0[0x48];
    u8 f48;
    u8 f49;
    char pad1[0x510 - 0x4A];
    u16 f510;
    u16 f512;
    char pad2[0x533 - 0x514];
    u8 f533;
};

struct Local4 {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
};

extern struct S8009B45C *D_8009B45C;
extern struct S8009B45C *D_8009B45C;
extern struct S8009B45C *D_8009B45C;
extern struct S8009B45C *D_8009B45C;
extern void func_8007CDC0(struct Local4 *a0);

void func_80044F58(s32 a0) {
    struct Local4 local;
    s32 s0 = a0;

    D_8009B45C->f533 = 7;

    local.f0 = s0;
    local.f3 = 0;

    if (D_8009B45C->f48 == 0) {
        local.f1 = 0;
        local.f2 = s0;
    } else {
        local.f1 = s0;
        local.f2 = 0;
    }

    func_8007CDC0(&local);

    {
        struct S8009B45C *p = D_8009B45C;
        p->f49 = s0;
        p->f510 = s0;
    }
    D_8009B45C->f512 = 0;
}
