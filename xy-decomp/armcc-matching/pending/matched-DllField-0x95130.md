Module: DllField
Offset: 0x95130
Size: 0x2c
Match: 11/11
One-line: Reads args[1], args[2] (one ldrd), fetches the manager and calls Helper(mgr->+12->+72->+316, a1, a2); returns 0. Sibling of 0x95f78.
Style: natural -- plain call, pointer-chain loads; no tricks.
