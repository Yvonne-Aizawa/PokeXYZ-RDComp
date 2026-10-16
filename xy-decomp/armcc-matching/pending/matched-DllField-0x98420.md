Module: DllField
Offset: 0x98420
Size: 0x2c
Match: 11/11
One-line: Calls helper on mgr->+12->+28->*->+0x15fa8 with constant 4, returns the high halfword (result >> 16).
Style: natural -- plain pointer-chain loads, call, shift
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
