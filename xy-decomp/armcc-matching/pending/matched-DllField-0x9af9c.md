Module: DllField
Offset: 0x9af9c
Size: 0x30
Match: 12/12
One-line: Calls H(q) on the sub-object at mgr->+12->+28->[0] + 0x1aeec, then returns bits 4+ of its u16 field at +4.
Style: natural -- plain call, pointer-chain loads, helper call; no tricks.
Note: script-command handler shape (args array in r1, returns 0 or a value); shared accessor 0x16c0.
