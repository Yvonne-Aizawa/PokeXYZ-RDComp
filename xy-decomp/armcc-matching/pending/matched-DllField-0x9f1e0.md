Module: DllField
Offset: 0x9f1e0
Size: 0x1c
Match: 7/7
One-line: Gets the manager object from the shared accessor (0x16c0), walks the pointer chain +12 -> +100 -> +2084, adds a field offset and returns the signed byte (`ldrsb`) found there.
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
