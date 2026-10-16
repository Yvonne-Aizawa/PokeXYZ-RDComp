Module: DllField
Offset: 0x97ee4
Size: 0x30
Match: 12/12
One-line: Script handler: returns H(*(mgr->+12->+28) + 0x15fa8, args[1]&255) >> 16.
Style: trick(volatile-load) -- args pointer read through volatile so armcc keeps the full-word ldr + separate uxth/sxtb/and (retail) instead of folding into ldrh/ldrb
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
