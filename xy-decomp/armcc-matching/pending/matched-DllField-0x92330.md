Module: DllField
Offset: 0x92330
Size: 0x40
Match: 16/16
One-line: Float-field getter: if mgr->+28->+148 (float*) is non-null returns (int)f[0], else calls the assert/error stub (0x200 veneer) and returns 0.
Style: natural -- plain call, pointer-chain loads; no tricks.
