Module: DllField
Offset: 0x97a74
Size: 0x58
Match: 22/22
One-line: Script handler: if Q(...) succeeds, s = G2(); s ? tail Z(s) : Err(0,0,0); returns 0.
Style: trick(volatile-load) -- args pointer read through volatile so armcc keeps the full-word ldr + separate uxth/sxtb/and (retail) instead of folding into ldrh/ldrb
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
