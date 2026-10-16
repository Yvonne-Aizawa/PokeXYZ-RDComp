Module: DllBattle
Offset: 0x7bae0
Size: 0x5c
Match: 23/23
One-line: script-command handler: reads one flag from the script context, then for every object in the row (index = ctx3->+12) of the per-row object lists (counts at +804, pointer arrays at +844) calls virtual slot 32 (+0x80) with (flag != 0).
Style: trick(redundant-local) -- `q = o` copy only to fix armcc's register assignment (r6 = row pointer); 20/23 without it.
Note: Same shape as 0x853a0 (vtable slot 42 / +0xa8 instead of 32).
