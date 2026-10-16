Module: DllField
Offset: 0x9f170
Size: 0x18
Match: 6/6
One-line: Gets the manager object from the shared accessor (0x16c0), walks the pointer chain +12 -> +100, and tail-calls a helper with the loaded value (`pop {r4,lr}; b`).
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
Note: Thunk family on callee 0x16c0 (shape: tail, chain [12, 100]).
