## DllField@0x92424 (size 0x58) -- volatile-load retry 2026-10-16

- What it is: `i = (u16)args[1]; m = mgr->+12; r = Q(G(m->+72), i); if (r) { o = m->+72->+344->+12; T(o, F2(F1(r))); } return 0`.
- Lever applied (`volatile int *b`, `unsigned short i = b[1]`): arg handling and first half match (retail `ldr r4,[r0,#12]` = m, `movs r5,r0`).
- Stuck on 11/22: retail does `movs r5,r0` (result kept in callee-saved r5) and runs the `+72 +344 +12` chain through r0, then `mov r0,r5; bl F1; bl F2; mov r1,r0; mov r0,r4; bl T`. Ours keeps `r` in r0 (plain `cmp r0,#0`), runs the chain through r1 and never copies. Hoisting `o` before the call, `F2(F1(r))` split into locals not yet tried beyond one variant.
- Lead: r is probably used after the chain in a way that forces the copy (e.g. `r` also passed to `F1` after another call, or chain computed via a call); try a local used after F1.
