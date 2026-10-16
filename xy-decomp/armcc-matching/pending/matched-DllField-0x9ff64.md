Module: DllField
Offset: 0x9ff64
Size: 0x24
Match: 9/9
One-line: Script-command handler: calls helper on mgr->+20 with u16 args[1]; returns 0.
Style: trick(volatile-load) -- args is volatile int* so armcc keeps ldr+uxth instead of ldrh
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
