Module: DllBattle
Offset: 0xa6494
Size: 0x20
Match: 8/8
One-line: forwarder `fnX(a,b,c,d,2,0)` (0xa6120 family)
Style: trick(redundant-local) -- the 5th stack arg goes through a named local only to make armcc emit retail's `mov r4,#X; mov ip,#Y` order
