Module: DllBattle
Offset: 0xa5d60 (siblings 0xa6c74, 0xa6ce8, 0xa7344, 0xa7aa0 all 0x54; 0xa7e18 0x70)
Size: 0x54
What: `if (query(3)==c && query(58)==K) post(37, h(*(u16*)(a+56), 3))` (0x658d4 tail; 0xa7aa0 variant: query(38)==0, `(u8)` result, event 39).
Tried: plain inline; static helper h(p,n); local `int k=3`; struct with pad[56]+u16; helper returning the u16. All 8/21: retail saves `mov r4,r0; mov r5,r2` (a first, then c) and later reuses r5 for the literal 3 (`mov r5,#3; ldrh r0,[r0,#56]; mov r1,r5`), while armcc puts c in r4 and a in r5.
Lead: the odd `mov r5,#3` implies a source-level variable holding 3 that was allocated into c's dead register (an inlined accessor with a param?), and the a/c save order is again the callee-saved prologue-move swap.
