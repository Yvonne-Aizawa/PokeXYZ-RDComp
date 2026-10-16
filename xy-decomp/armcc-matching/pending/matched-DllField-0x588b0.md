Module: DllField
Offset: 0x588b0
Size: 0x30
Match: 12/12
One-line: Script handler: H(mgr->+12->+72->+240->+2740 + 420, (u16)args[1]); returns 0. Two volatile chain loads pin the late uxth.
Style: trick(volatile-load) -- volatile arg read (full ldr; uxth at use) plus volatile last two chain loads so armcc keeps uxth after the chain like retail
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
