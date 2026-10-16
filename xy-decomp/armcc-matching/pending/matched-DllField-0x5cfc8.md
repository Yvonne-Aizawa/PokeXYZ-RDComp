Module: DllField
Offset: 0x5cfc8
Size: 0x2c
Match: 11/11
One-line: Script handler: H(mgr->+12->+72->+240, (s16)args[1]); returns 0. Chain load made volatile to pin the late 'mov r1,r4' arg move.
Style: trick(volatile-load) -- volatile arg read (full ldr + sxth) plus a volatile final chain load so armcc schedules mov r1,r4 after the chain like retail
Note: arg-load-width residue class; fixed by the volatile-load lever (see attempted.md 2026-10-16 entries).
