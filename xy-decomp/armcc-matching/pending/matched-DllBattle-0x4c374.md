Module: DllBattle
Offset: 0x4c374
Size: 0x3c
Match: 15/15
One-line: range-checked (i<11) getter `o->p->v[i] != 0` with assert stub on out-of-range
Style: natural
Note: write the in-range case first (`if (i < 11) return ...; fnA(0,0,0); return 0;`); the `if (i >= 11)` form flips bcs/bcc and block order.
