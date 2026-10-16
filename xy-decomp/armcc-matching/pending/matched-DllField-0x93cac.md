Module: DllField
Offset: 0x93cac
Size: 0x40
Match: 16/16
One-line: Script handler: r = Q(G(mgr->+12->+72), u16 args[1]); if (r) T(r,0,0); returns 0.
Style: trick(volatile-load) -- args pointer read through volatile so armcc keeps the full-word ldr + separate uxth/sxtb/and (retail) instead of folding into ldrh/ldrb
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
