Module: DllField
Offset: 0x93d10
Size: 0x2c
Match: 11/11
One-line: Script handler: stores the low byte of args[1] into mgr->+12->+28->*->+0x1539c, returns 0.
Style: trick(volatile-load) -- args pointer read through volatile so armcc keeps the full-word ldr + separate uxth/sxtb/and (retail) instead of folding into ldrh/ldrb
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
