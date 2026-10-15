## DllZukan@0x8adc (size 0xd4)
Table lookup: loop i<7 over a 28-byte-stride global table comparing field0 to arg; on hit,
scan short arr[o->n@0xd4] at 0xd6 for i and store index to short@0xe4, range check (u8)i<7 else err(0,0,0),
store byte global, fn(o,i), fn2(o->q@0xe8->@0xd4,0), vtable slot 2 call with (p@0xd0, i&0xff); returns 0, else 1.
Best: 46/53. Only diffs are a register swap in the inner scan loop: retail has count in r1 / j in r0
(cmp r1,r0; bgt), mine gets count r0 / j r1 (blt). Tried for/while/do-while, n hoisted vs o->n each iter,
short j (adds sxth, worse). Lead: find the shape that makes armcc allocate n before j (maybe the scan is an
inlined helper).

## DllGts@0x9824 (size 0x38)
Dtor-ish: p=this->p@0x20; if p {p->vt[6](p); this->p=0}; fn(this+0x24); return this->r@0x14.
Best: 12/14. Retail keeps the zero for the store in r1 (mov r1,#0; str r1,[r4,#32]); armcc gives mov r0,#0.
Tried int-returning virtual, local zero var.
