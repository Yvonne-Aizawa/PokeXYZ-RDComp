Module: DllPuzzle / DllBox / DllGts / DllHeading (dtor "release member, zero via r1" class)
Offsets: DllPuzzle@0xb3fc, DllHeading@0x87e4/0x881c, DllBox@0x1dfac/0x1df3c, DllGts@0x9824
Status: NOT cracked for the dtor shape (the leaf variant IS cracked, see matched-DllField-0xae58.md etc.)

Learned about armcc's allocation:
- Leaf case (DllField zero-two-ints, zero in r2): armcc puts a materialized constant in the lowest
  free scratch reg other than r0=this. Retail had r1 LIVE (passthrough incoming arg). Unused params
  do NOT keep r1 live; returning x does but adds `mov r0,r1`. A `long long` return built from
  ((long long)x<<32)|(unsigned)t keeps r1 live with zero extra code -> masked 4/4 on 0xae58/0xe3fc/0xe380.
- Dtor ordering residue (pool word in r1 BEFORE member load in r0) IS solved, natural-ish:
      void **vt = VT; void *m = o->f14; o->vptr = vt; if (m) { fn(m); o->f14 = 0; } return fn268(o);
  (declarations in that order; swapping the vt/m lines or storing vptr first gives the old
  mismatch). Puzzle@0xb3fc -> 12/14, Heading@0x87e4 -> 12/14, 0x881c (return o) -> 11/13: ONLY the
  zero reg differs (retail `mov r1,#0; str r1,[r4,#20]`, ours r0).
- After the call both r0 and r1 are free; armcc picks r0, retail picks r1. Variants tried on top of the
  fixed ordering, all still r0: hoisted z=0 (goes callee-saved r5, worse), reusing vt/m locals as zero
  (const-folds), (vt-vt)/(vt&0)/(m==0) forms (folded or extra code), int/void*-returning callee with
  ignored result, inline memset(&f14,0,4), member wrapped in struct assigned from static const zero
  (adds pool loads), *(int*)&f14=0, do{}while(0), empty else, 64-bit zero cast, char zero.
- Not tried / ideas: need r0 live across the store via a use that emits no code. The leaf trick works
  because the passthrough is the return value; in the dtor r0 is clobbered by the call and the tail
  `mov r0,r4` defines it fresh, so there is no natural r0-live value. A C++ context with an inlined
  smart-pointer reset() might create the extra live value; unexplored. DllBox 0x1dfac/0x1df3c not
  re-run with the new ordering (they have the extra vtable-call prefix).
