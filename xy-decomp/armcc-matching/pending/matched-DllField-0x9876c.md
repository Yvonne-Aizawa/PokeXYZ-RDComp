Module: DllField
Offset: 0x9876c
Size: 0x28
Match: 10/10
One-line: Reads the event argument word a[1] first, gets the manager object from the shared accessor (0x16c0), walks the pointer chain +12 -> +28 -> +36 and calls a helper with (loaded object, a[1]), returning 0.
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
