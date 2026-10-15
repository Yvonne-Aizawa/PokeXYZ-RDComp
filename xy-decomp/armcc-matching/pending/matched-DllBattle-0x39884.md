Module: DllBattle
Offset: 0x39884
Size: 0x150
Match: 84/84
One-line: state classifier via chain of virtual calls (returns 0..3)
Style: natural -- vtable typed as unprototyped fn pointers (slots have differing arities)
Note: needed `int (**vt)()` so slots 0x42/0x10 are called with no extra arg while others take (this,1)/(this,0).
