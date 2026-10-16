Module: DllField
Offset: 0x95df0
Size: 0x5c
Match: 23/23
One-line: Script handler: if Q(...) succeeds, s = G2(); s ? Z(s,0) : Err(0,0,0); returns 0.
Style: trick(volatile-load) -- args pointer read through volatile so armcc keeps the full-word ldr + separate uxth/sxtb/and (retail) instead of folding into ldrh/ldrb
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
