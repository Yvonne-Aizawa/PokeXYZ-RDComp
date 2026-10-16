Module: DllField
Offset: 0x9484c
Size: 0x48
Match: 18/18
One-line: Script handler: sibling of 0x928ac, returns u16 at o->+144 + i*12 + 336 (the local unsigned short *p stops armcc folding the offset into ldrh imm: retail add #336; ldrh [r0]).
Style: trick(volatile-load) -- volatile arg read after GetMgr() keeps retail full-word ldr + and #255; also a local halfword pointer p so armcc keeps add #336 + ldrh [r0]
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
