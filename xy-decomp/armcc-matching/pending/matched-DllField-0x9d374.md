Module: DllField
Offset: 0x9d374
Size: 0x30
Match: 12/12
One-line: Script-command handler: H1(mgr->+12->+28->+20, u16 args[1]) then tail-calls H2(result, 2).
Style: trick(volatile-load) -- args is volatile int* so armcc keeps ldr+uxth instead of ldrh
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
