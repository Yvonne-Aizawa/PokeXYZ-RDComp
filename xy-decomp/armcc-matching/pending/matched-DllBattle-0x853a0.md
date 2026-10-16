Module: DllBattle
Offset: 0x853a0
Size: 0x5c
Match: 23/23
One-line: script-command handler: reads one flag, then for every object in the row (index = ctx3->+12) of the per-row object lists (counts at +804, arrays at +844) calls virtual slot 42 (+0xa8) with (flag != 0).
Style: trick(redundant-local) -- `q = o` copy only to fix armcc's register assignment; sibling of 0x7bae0.
Note: Differs from 0x7bae0 only in the vtable slot.
