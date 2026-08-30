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

/* Both single-point and two-point ops copy/average 3 raw bytes (an RGB or
   xyz triple); see copy_bytes3.c / avg_bytes3.c. */
extern void func_8006C30C(u8 *dst, u8 *src);
extern void func_8006C330(u8 *dst, u8 *a, u8 *b);

/* Recursive 4-way triangle subdivision (classic "1 triangle -> 4 sub-
   triangles via edge midpoints" scheme), writing interpolated per-vertex
   data (color or position triples, 3 bytes each, stored 4-byte strided --
   likely a 4-byte PS1 color/vector struct with 1 pad byte) to an output
   cursor that's threaded through the whole recursion.

   arg0/arg1/arg2: the 3 corner values of the current triangle.
   arg3: output func_80073900-cursor; each leaf func_80073900 advances it by 0x30 (48)
         bytes -- 12 x 4-byte fields, i.e. 4 leaf sub-triangles' worth of
         3-byte-triple vertex data -- and the advanced pointer is returned.
   arg4: recursion depth counter; arg4==1 is the base case.

   Computes 3 corner copies (verts[0..2] = copy(arg0/1/2)) and 3 edge
   midpoints (verts[3] = avg(arg1,arg2), verts[4] = avg(arg2,arg0),
   verts[5] = avg(arg0,arg1)), then either recurses on the 4 sub-triangles
   (3 corner triangles + 1 center triangle, chaining the output cursor
   through all 4 calls) or, at the base case, writes the 4 sub-triangles'
   vertex triples directly. */
void *func_8006C120(u8 *in_arg0, u8 *in_arg1, u8 *in_arg2, u8 *in_arg3, s32 in_arg4) {
    register u8 *arg0 asm("s0") = in_arg0;
    register u8 *arg1 asm("s2") = in_arg1;
    register u8 *arg2 asm("s1") = in_arg2;
    register u8 *arg3 asm("s6") = in_arg3;
    register s32 arg4 asm("s3") = in_arg4;
    u32 verts[6];
    void *result;

    func_8006C30C((u8 *)&verts[0], arg0);
    func_8006C30C((u8 *)&verts[1], arg1);
    func_8006C30C((u8 *)&verts[2], arg2);
    {
    register u8 *p24 asm("s5") = (u8 *)&verts[3];
    func_8006C330(p24, arg1, arg2);
    {
    register u8 *p28 asm("s4") = (u8 *)&verts[4];
    func_8006C330(p28, arg2, arg0);
    arg2 = (u8 *)&verts[5];
    func_8006C330(arg2, arg0, arg1);
    arg4 = arg4 - 1;
    if (arg4 == 0) {
        func_8006C30C(arg3, (u8 *)&verts[0]);
        func_8006C30C(arg3 + 4, arg2);
        func_8006C30C(arg3 + 8, p28);
        func_8006C30C(arg3 + 0xC, (u8 *)&verts[1]);
        func_8006C30C(arg3 + 0x10, p24);
        func_8006C30C(arg3 + 0x14, arg2);
        func_8006C30C(arg3 + 0x18, (u8 *)&verts[2]);
        func_8006C30C(arg3 + 0x1C, p28);
        func_8006C30C(arg3 + 0x20, p24);
        func_8006C30C(arg3 + 0x24, p24);
        func_8006C30C(arg3 + 0x28, p28);
        func_8006C30C(arg3 + 0x2C, arg2);
        return arg3 + 0x30;
    }
    /* The 4th (outermost) recursive call is a genuine tail call in the
       source; gcc's tail-recursion-to-loop conversion would otherwise
       reuse this frame instead of emitting a real 4th `jal` + `j` to the
       shared epilogue like the target does, so the result is routed
       through a plain local and an empty asm barrier to block it. */
    result = func_8006C120(p24, p28, arg2,
        func_8006C120((u8 *)&verts[2], p28, p24,
            func_8006C120((u8 *)&verts[1], p24, arg2,
                func_8006C120((u8 *)&verts[0], arg2, p28, arg3, arg4),
                arg4),
            arg4),
        arg4);
    __asm__ volatile("" ::: "memory");
    return result;
    }
    }
}
