Module: DllField
Offset: 0x979dc
Size: 0x48
Match: 18/18
One-line: Calls G(mgr->+12->+72->+244), then B(mgr); if G returned 0 calls the assert/error stub (0x528 veneer); returns 0.
Style: natural -- plain call, pointer-chain loads; no tricks.
