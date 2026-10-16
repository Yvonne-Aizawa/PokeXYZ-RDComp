Module: DllField
Offset: 0xa0cf4
Size: 0x40
Match: 16/16
One-line: Script-command handler: looks up an entry F(mgr->+16, u16 args[1]); returns its signed byte +30, or (after an error call E(0,0,0)) 0 if missing.
Style: trick(volatile-load) -- args is volatile int* so armcc keeps ldr+uxth instead of ldrh
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
