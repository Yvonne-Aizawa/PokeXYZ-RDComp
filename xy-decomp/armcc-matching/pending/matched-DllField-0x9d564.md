Module: DllField
Offset: 0x9d564
Size: 0x44
Match: 17/17
One-line: Script-command handler: if mgr->+12->+72->+408 is non-null tail-calls H(o, args[1]); else E(0,0,0) and returns 1.
Style: natural -- plain null test, tail call, fallthrough call
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
