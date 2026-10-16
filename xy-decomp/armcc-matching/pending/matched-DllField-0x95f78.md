Module: DllField
Offset: 0x95f78
Size: 0x2c
Match: 11/11
One-line: Reads args[1], args[2] (one ldrd), fetches the manager and calls Helper(mgr->+12->+72->+316, a1, a2) (different callee than 0x95130); returns 0.
Style: natural -- plain call, pointer-chain loads; no tricks.
