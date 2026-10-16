Module: DllField
Offset: 0x9ea7c
Size: 0x18
Match: 6/6
One-line: Gets the manager object from the shared accessor (0x16c0), walks the pointer chain +12 -> +100 -> +2712 and returns the loaded word.
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
Note: Thunk family on callee 0x16c0 (shape: ret, chain [12, 100, 2712]).
