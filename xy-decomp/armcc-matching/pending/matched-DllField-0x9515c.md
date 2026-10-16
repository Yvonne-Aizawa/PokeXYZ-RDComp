Module: DllField
Offset: 0x9515c
Size: 0x34
Match: 13/13
One-line: Script handler: H(mgr->+12->+28->+36, args[1], args[2]&255); returns 0.
Style: trick(volatile-load) -- args pointer read through volatile so armcc keeps the full-word ldr + separate uxth/sxtb/and (retail) instead of folding into ldrh/ldrb
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
