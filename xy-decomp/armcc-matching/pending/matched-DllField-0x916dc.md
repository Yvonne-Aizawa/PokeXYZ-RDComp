Module: DllField
Offset: 0x916dc
Size: 0x30
Match: 12/12
One-line: If mgr->+28 has a non-null pointer at +148, calls H() and clears the word at (mgr->+28)+124+24; returns 0.
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
Note: script-command handler shape (args array in r1, returns 0 or a value); shared accessor 0x16c0.
