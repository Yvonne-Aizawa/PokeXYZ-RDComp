Module: DllField
Offset: 0x98e28
Size: 0x28
Match: 10/10
One-line: Gets the manager object from the shared accessor (0x16c0), walks the pointer chain +12 -> +28 -> +0 -> +85200, adds a constant field offset and passes the resulting address to a void helper, returning 0.
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
