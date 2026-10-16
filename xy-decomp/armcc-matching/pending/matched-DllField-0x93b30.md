Module: DllField
Offset: 0x93b30
Size: 0x30
Match: 12/12
One-line: Script handler: H1(mgr->+44, u16 args[1]); H2(mgr); returns 0.
Style: trick(volatile-load) -- args pointer read through volatile so armcc keeps the full-word ldr + separate uxth/sxtb/and (retail) instead of folding into ldrh/ldrb
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
