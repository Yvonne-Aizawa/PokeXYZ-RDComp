## DllBattle small push-functions, 0x30000-0x60000 sweep (unmatched)

- 0x422e8 (0x24): fnA(o->m@0xafc); o->y@0x876=0; o->x@0x874=1. Retail `mov r1,#0; mov r0,#1; strb r1; strb r0` (zero in r1); ours reuses r0 -- known zero-register residue. Tried store orders / dup store.
- 0x4bb2c (0x30): `if (i>=5) fnA(0,0,0); return o->v[i]` (u8 at +365+i). Only diff: prologue `mov r5,r0; mov r4,r1` vs ours `mov r4,r1; mov r5,r0` (10/12). Tried struct array and flat pointer index.
- 0x4cf8c (0x34): `if (i>=7) fnA(0,0,0); o->v[i]=val` (int array at +28). Callee-saved assignment swapped (9/13) -- val/o swap r5/r6.
- 0x4d318 (0x30): `return fnA(o,13)==fnA(o,14)`; o lands in r5 / first result r4 (ours) vs r4/r5 (retail), 8/12. Tried temporaries and if-form.
- 0x48344 (0x38): `if (vt[38](this)) fnA(this->m@0xb8, v); this->b@0x4e = v;` 12/14: retail loads the vfn into r1, ours r2 (v kept live in r1 differently); tried prototyped / unprototyped vt and local fn ptr.
- 0x4344c (0x2c): `r=vt[32](this); return r==103||r==104` -- retail uses `cmp 103; beq L; cmp 104; moveq 1; beq end; L: mov 0` (branch-vs-conditional-execution residue); fn ptr in r2 not r1.
