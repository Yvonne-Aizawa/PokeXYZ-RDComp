Module: DllField
Offset: 0x9ad74
Size: 0x1c
Match: 7/7
One-line: Gets the manager object from the shared accessor (0x16c0), walks the pointer chain +12 -> +28 -> +56 -> +8 and returns the loaded word.
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
Note: Thunk family on callee 0x16c0 (shape: ret, chain [12, 28, 56, 8]).
