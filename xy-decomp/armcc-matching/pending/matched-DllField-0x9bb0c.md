Module: DllField
Offset: 0x9bb0c
Size: 0x1c
Match: 7/7
One-line: Gets the manager object from the shared accessor (0x16c0), walks the pointer chain +12 -> +72 -> +408, and tail-calls a helper with the loaded value (`pop {r4,lr}; b`).
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
Note: Thunk family on callee 0x16c0 (shape: tail, chain [12, 72, 408]).
