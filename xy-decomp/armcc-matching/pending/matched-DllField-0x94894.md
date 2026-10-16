Module: DllField
Offset: 0x94894
Size: 0x44
Match: 17/17
One-line: Script handler: sibling of 0x928ac, returns word at o->+144 + i*12 + 340. Volatile read after GetMgr().
Style: trick(volatile-load) -- args pointer read through volatile so armcc keeps the full-word ldr + separate uxth/sxtb/and (retail) instead of folding into ldrh/ldrb
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
