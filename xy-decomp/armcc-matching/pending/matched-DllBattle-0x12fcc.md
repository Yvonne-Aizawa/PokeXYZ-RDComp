Module: DllBattle
Offset: 0x12fcc
Size: 0x40
Match: 16/16
One-line: dtor stage: install vtable, vcall slot 1 on member @8 if non-null, free member @0xc if non-null (no zero), return this
Style: trick(ordering-local) -- local `vt = VT` and hoisted member load only fix pool-load vs member-load order
Note: size includes trailing pool word (0x3c without it fails by one word).
