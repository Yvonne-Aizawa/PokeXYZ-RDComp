Module: DllField
Offset: 0x58ba0
Size: 0x20
Match: 8/8
One-line: Script handler: Imp(a, (s16)args[1], 0, 9, 0).
Style: trick(volatile-load) -- args pointer read through volatile so armcc keeps the full-word ldr + separate uxth/sxtb/and (retail) instead of folding into ldrh/ldrb
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
