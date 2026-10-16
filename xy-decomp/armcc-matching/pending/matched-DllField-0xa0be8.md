Module: DllField
Offset: 0xa0be8
Size: 0x20
Match: 8/8
One-line: Tail-calls H(mgr->+24, mgr->+12->+72->+252) and returns its result.
Style: natural -- plain pointer-chain loads and tail call
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
