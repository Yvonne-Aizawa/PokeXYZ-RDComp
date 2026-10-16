Module: DllField
Offset: 0x9170c
Size: 0x24
Match: 9/9
One-line: Gets the manager object from the shared accessor (0x16c0), walks the pointer chain +12 -> +72 -> +404; if the loaded pointer is non-null calls a helper with it (conditional `blne`), returns 0.
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
