Module: DllBattle
Offset: 0x704ac
Size: 0x20
Match: 8/8
One-line: bit-pack builder + store: *p = (a<<4 & 0x70) | 3 | (b<<7 & 0x380) (two fields, constant tag 3).
Style: trick(redundant-local) -- named mask locals m1/m2 hoist both constants (retail puts mov ip,#0x70 / mov r3,#0x380 first) and tag orr split into its own statement
