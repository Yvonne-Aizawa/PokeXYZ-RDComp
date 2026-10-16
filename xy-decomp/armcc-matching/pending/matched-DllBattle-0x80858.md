Module: DllBattle
Offset: 0x80858
Size: 0x3c
Match: 15/15
One-line: script-command handler: reads one argument (float-reader veneer, stored as a raw word); if the indexed slot of the pointer table at +1044 is non-null and its +12 field is non-zero, stores the argument into slot->+116.
Style: trick(redundant-local) -- the copies `q = o` and `x = v` exist only to fix armcc's register assignment (r4/r5) and conditional-execution shape.
Note: Sibling of 0x80820.
