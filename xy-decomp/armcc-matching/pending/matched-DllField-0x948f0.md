Module: DllField
Offset: 0x948f0
Size: 0x2c
Match: 11/11
One-line: Script handler: returns field +20 of the 28-byte table entry u16(args[1]) in mgr->+12->+28->+396.
Style: trick(volatile-load) -- args pointer read through volatile so armcc keeps the full-word ldr + separate uxth/sxtb/and (retail) instead of folding into ldrh/ldrb
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
