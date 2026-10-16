## DllBattle event-trigger predicates that save BOTH b (r1) and c (r2) -- ~213 functions in 0xb8000-0xca000 (e.g. 0xb8d3c, 0xb8008, 0xb8048, 0xb9c70, 0xbfc9c, 0xc06c8, 0xbca9c)

Module: DllBattle
Offset: 0xb8d3c (representative; full list = every unmatched 0x6b91c caller in range whose prologue has `mov rN, r1`)
Size: 0x40
Match: 14/16

Shape (0xb8d3c): `if (g(3) == c && h1(b) == 1) post(44, 50)` -- retail prologue is `push {r4,r5,r6,lr}; mov r5,r1; mov r4,r2` (b first), armcc here emits `mov r4,r2; mov r5,r1`. Body otherwise identical (14/16, only the two prologue words differ). Same residue already logged in attempted.md for 0xa7cd0/0xa7188/0xc1244; this confirms it covers ~213 more functions here (the largest unmatched cluster in the range).

Tried (all the same 14/16): plain `&&` form, nested ifs, `(void)b;` first, `int bb = b; int cc = c;` locals in both orders, swapping the parameter order/names, calling h1(b) first. No natural form found.

Observation: the move order is NOT simply allocation order. Retail (b,c) emits r1-first; (d,c) = 0xc489c emits r3-first (matched, natural); (c,d) = 0xbc89c/0xbe5b8/0xbef24/0xc282c/0xc3cd0 emit r2-first while armcc here emits r3-first. So the (c,d) and (b,c) shapes both need the opposite order from what we produce; a single missing source-level fact (a 4th arg, an intermediate struct/vtable local) might explain both.
