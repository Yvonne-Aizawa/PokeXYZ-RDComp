Module: DllBattle
Offset: 0x3b534
Size: 0x44
Match: 15/15 code words (POOL-PAD, exit 3; fails without --pool-pad)
One-line: trace store 0x1465 into c->v (arg3 +0x6c) if different, then if o->p190->q240 is non-null call its vtable slot 1 and null the field
Style: natural -- local `q = p->q; if (q != 0)` (testing p->q twice gives movs r2,r0 + extra mov)
