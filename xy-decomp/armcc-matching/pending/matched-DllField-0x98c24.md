Module: DllField
Offset: 0x98c24
Size: 0x28
Match: 10/10
One-line: Script-command handler: stores u16 args[1] into *(mgr->+12->+28->+56) and returns 0.
Style: trick(volatile-load) -- args is volatile int* so armcc keeps ldr+uxth instead of ldrh
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
