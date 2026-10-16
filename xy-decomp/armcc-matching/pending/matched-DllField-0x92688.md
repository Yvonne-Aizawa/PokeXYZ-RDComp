Module: DllField
Offset: 0x92688
Size: 0x2c
Match: 11/11
One-line: Reads args[1], fetches the manager and calls Helper(mgr->+12->+28->+36, args[1], 10); returns 0.
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
Note: script-command handler shape (args array in r1, returns 0 or a value); shared accessor 0x16c0.
