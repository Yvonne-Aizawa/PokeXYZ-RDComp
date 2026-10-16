Module: DllField
Offset: 0x98b84
Size: 0x38
Match: 14/14
One-line: Script-command handler: sets byte args[1] on object mgr->+12->+64 via helper, then returns whether a second helper on it is nonzero.
Style: trick(volatile-load) -- args is volatile int* so the narrowing and #255 happens after an ldr (not folded into ldrb); m/v locals only fix load order
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
