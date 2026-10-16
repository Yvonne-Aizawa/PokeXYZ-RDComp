Module: DllField
Offset: 0x39728
Size: 0x50
Match: 20/20
One-line: dtor stage: install vtable, release member +4 through its vtable slot 1 and zero it, free import-owned member +12 and zero it, return this
Style: trick(ordering-local) -- member/vtable locals only to fix load / pool-load order (member load before vtable pool-load)
