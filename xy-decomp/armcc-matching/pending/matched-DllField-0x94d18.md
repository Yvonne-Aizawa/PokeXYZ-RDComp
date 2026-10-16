Module: DllField
Offset: 0x94d18
Size: 0x30
Match: 12/12
One-line: Script handler: H(*(mgr->+12->+28) + 0x14cd0, (s8)args[1]); returns 0.
Style: trick(volatile-load) -- args pointer read through volatile so armcc keeps the full-word ldr + separate uxth/sxtb/and (retail) instead of folding into ldrh/ldrb
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
