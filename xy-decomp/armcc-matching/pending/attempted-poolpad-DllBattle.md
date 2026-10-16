## DllBattle pool-pad sweep (trace-prefix family) -- unmatched leftovers

Scan method: a word-level scan of DllBattle .text for `zero word right after a terminator, followed by a
pc-loaded pool word` gave 111 start candidates; the short ones with the trace prefix
(`k=..; if (c->v != k) c->v = k;`) were tried. 8 landed in `poolpad/` (see poolpad-1..7 and 0x71208 notes).
Useful finding: the same `int k` prefix gets k->r2/old->r0 in some bodies and the retail k->r0/old->r2 in
others; no source-level spelling was found that flips it (int/unsigned/old-local/`k != c->v` all tried).

- 0x3981c (0x58): `if (f1(o,0)) { f2(o,0,0); f3(o->p190+0x280); return 1;} return 0` with the trace on arg2 (c=r1).
  Everything matches except the head allocation (retail `ldr r0,=k; ldr r2,[r1,#108]; cmp r2,r0`, ours k=r2/old=r0).
  Same register flip blocks 0x3cb48 and 0x724bc (same body with an `if (o->b6b8 == 255) return 1` front).
- 0x3badc (0x40) / 0x3f274 (0x40): `f1(p->q65c, 3); f2(p->q65c, 2, 1)` tail call; armcc emits `mov r2,#1; mov r1,#2`,
  retail `mov r1,#2; mov r2,#1` (tried int/uchar arg types, C++ member call, local copies).
- 0x3cbb4 (0x78): body matches (vcall slot 4, f1(0)/f2 pairs) but r5/r6 swapped (retail zero=r6, p+0x230=r5);
  naming the zero as a local `z` flips it but then reorders the head (`mov r3,#0` / ip use).
- 0x3ea10, 0x3f34c, 0x410f4: use `ip` as the trace pointer (in_ip); not attempted.
- 0x73dec / 0x74c08: inlined dead-code accessor chain (`cmp r0,#0` after `mov r0,#1`); not attempted.
- DllField: the same pad-word scan only yields mid-function pools (0x9ac4, 0x10a84, ...) or big functions
  (>= 0xb0 bytes); no new short candidates besides the three already in poolpad/.
