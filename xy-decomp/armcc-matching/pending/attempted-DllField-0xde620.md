## DllField@0xde620 (size 0x28; family of ~11 byte-identical-modulo-immediates: 0xde620/0xde67c/0xde6d8/0xde734/0xde790/0xde7ec (kind=2), 0xdf3b0/0xdf40c/0xdf468/0xdf4c4 (kind=3), 0xdcafc (kind=4))

Retail: `push {r4,lr}; ldr r0,[pool]; add r4,r1,#12; mov r1,#K; strb r1,[r4,#4]; str r0,[r4]; mov r0,#22; bl imp; strh r0,[r4,#6]; pop`.
Shape: fills a record at out+12 {vtable ptr, byte kind @+4, short id @+6 = import(22)}.
- Tried: struct Rec* at out+12 with `vt=VT; kind=2; id=imp(22)` -> 5/10; armcc hoists the pool ldr above `push` and stores through r1 offsets, never through r4.
- Tried: kind store first -> 4/10 (kind and pool-load both hoisted above the push).
- Tried: `volatile` struct pointer -> 6/10 (push first, but still stores via r1 offsets, order kind-then-vt).
- Lead: retail stores through r4 after `add r4,r1,#12` with push first; the original probably passes `&out->rec` into something or has the pointer live across the call for a reason armcc sees; untested: make the record pointer a by-reference of an inlined ctor.

## DllField@0xb1bb8 (size 0x2c; 24 byte-identical sites incl. 0xb1ccc, 0xb231c, 0xb253c, 0xb2864, 0xb29ac)

Retail dtor stage: `str r1,[r0]` (vt passed in), `ldr r1,[r0,#32]; cmp r1,#0; addne r1,r0,#32; blne local` then `add r0,r4,#8; bl base; sub r0,r0,#8`.
- Tried: `*(void**)this=vt; if (this[32]) Free(this, this+32); return Base(this+8)-8;` -> 4/11; armcc emits `beq`-branch form (ldr r0 first, add r1 after) instead of the conditional-execution blne with r1 reused.
- Known class: branch-vs-conditional-execution residue. 24 sites make a solution valuable.
