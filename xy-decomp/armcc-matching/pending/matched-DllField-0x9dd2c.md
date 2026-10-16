Module: DllField
Offset: 0x9dd2c
Size: 0x24
Match: 9/9
One-line: Gets the manager object from the shared accessor (0x16c0), walks the pointer chain +12 -> +28 -> +0 -> +101552, adds a constant field offset to the loaded base pointer and tail-calls a helper with the resulting address (`pop {r4,lr}; b`).
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
