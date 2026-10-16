Module: DllBattle
Offset: 0xa68e4
Size: 0x20
Match: 8/8
One-line: forwarder `fnX(a,b,c,d,4,0)` (0xa6120 family)
Style: trick(redundant-local) -- the 5th stack arg goes through a named local only to make armcc emit retail's `mov r4,#X; mov ip,#Y` order
