Module: DllTownmap
Offset: 0xd68
Size: 0x1c
Match: 7/7
One-line: virtual wrapper - if this->[0x88], tail-call its vtable slot 3 forwarding two int args
Style: trick(extra-arg) -- two forwarded int args put the vtable in r3 (slot-4 sibling 0xb10 uses one arg -> r2)
