Module: DllField
Offset: 0x9bb4c
Size: 0x20
Match: 8/8
One-line: Gets the manager object from the shared accessor (0x16c0), walks the pointer chain +12 -> +72 -> +408, passes the loaded value to a void helper and returns 0.
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
Note: Thunk family on callee 0x16c0 (shape: void0, chain [12, 72, 408]).
