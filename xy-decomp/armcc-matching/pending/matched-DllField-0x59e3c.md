Module: DllField
Offset: 0x59e3c
Size: 0x30
Match: 12/12
One-line: Reads the event argument word a[1] first, gets the manager object from the shared accessor (0x16c0), walks the pointer chain +12 -> +28 -> +0, adds a field offset and calls a helper with (address, a[1]), returning 0.
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
