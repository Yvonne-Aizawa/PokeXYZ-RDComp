Module: DllBattle
Offset: 0x2b9dc
Size: 0x18
Match: 6/6
One-line: writes constant pair (-94.0f, -54.0f) to arg2->{x,y}; arg1 unused (default position/offset reset).
Style: trick(redundant-local) -- named float locals a,b make armcc pair them into one vstmia instead of two vstr
