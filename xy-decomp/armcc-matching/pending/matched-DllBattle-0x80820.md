Module: DllBattle
Offset: 0x80820
Size: 0x38
Match: 14/14
One-line: script-command handler: reads one int argument; if the indexed slot (index = ctx3->+12) of the pointer table at +1044 is non-null, passes the argument and slot->+8 to a worker.
Style: trick(redundant-local) -- the copies `q = o` and `x = v` exist only to fix armcc's r4/r5 register assignment and the [sp]-before-member load order; without both the output is 11/14.
Note: Pointer-table-by-script-index family (0x80858, 0x82a7c share the head).
