Module: DllField
Offset: 0x9d688
Size: 0x2c
Match: 11/11
One-line: Calls F(8), then tail-calls H(mgr->+12->+28, F's result).
Style: natural -- plain call, member load, tail call
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
