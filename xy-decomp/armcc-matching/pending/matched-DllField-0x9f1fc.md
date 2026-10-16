Module: DllField
Offset: 0x9f1fc
Size: 0x30
Match: 12/12
One-line: Script-command handler: calls helper on mgr->+12->+100 with (u16 args[1] != 0); returns 0.
Style: trick(volatile-load) -- args is volatile int* so armcc keeps ldr+uxth instead of ldrh
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
