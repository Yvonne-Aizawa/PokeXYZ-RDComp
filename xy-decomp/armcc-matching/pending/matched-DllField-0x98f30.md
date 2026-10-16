Module: DllField
Offset: 0x98f30
Size: 0x28
Match: 10/10
One-line: Calls helper on mgr->+12->+28->+52 then clears byte +1604 of it; returns 0.
Style: natural -- plain pointer-chain loads, call, byte store
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
