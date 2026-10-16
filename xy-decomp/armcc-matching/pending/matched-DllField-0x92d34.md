Module: DllField
Offset: 0x92d34
Size: 0x38
Match: 14/14
One-line: Script handler: r = Q(G(mgr->+12->+72), u16 args[1]); if (r) tail-call Tail(r).
Style: trick(volatile-load) -- args pointer read through volatile so armcc keeps the full-word ldr + separate uxth/sxtb/and (retail) instead of folding into ldrh/ldrb
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
