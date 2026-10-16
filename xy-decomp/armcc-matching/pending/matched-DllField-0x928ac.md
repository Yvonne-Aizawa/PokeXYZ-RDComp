Module: DllField
Offset: 0x928ac
Size: 0x44
Match: 17/17
One-line: Script handler: o = self->+68; GetMgr(); i = u8 args[1]; if (i >= 2) Err(0,0,0); returns byte at o->+144 + i*12 + 344. Volatile read placed AFTER the GetMgr() call (retail ldr [r5,#4] after bl).
Style: trick(volatile-load) -- args pointer read through volatile so armcc keeps the full-word ldr + separate uxth/sxtb/and (retail) instead of folding into ldrh/ldrb
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
