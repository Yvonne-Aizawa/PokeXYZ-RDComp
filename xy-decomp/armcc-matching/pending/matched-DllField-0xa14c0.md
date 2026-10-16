Module: DllField
Offset: 0xa14c0
Size: 0x20
Match: 8/8
One-line: Script-command handler: tail-calls helper on mgr->+24 with u16 args[1] and returns its result.
Style: trick(volatile-load) -- args is volatile int* so armcc keeps ldr+uxth instead of ldrh
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
