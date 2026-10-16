Module: DllField
Offset: 0x980fc
Size: 0x30
Match: 12/12
One-line: Script-command handler: reads args[1] (low byte), calls a helper on mgr->+12->+28->*->+0x15fa8 with it, returns the result as u16.
Style: trick(volatile-load) -- args is volatile int* only so armcc keeps ldr then and #255 instead of folding to ldrb
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
