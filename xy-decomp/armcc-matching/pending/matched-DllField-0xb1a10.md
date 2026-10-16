Module: DllField
Offset: 0xb1a10
Size: 0x50
Match: 20/20
One-line: dtor stage: install vtable, virtual-delete member +0x430 and free handle +4 (each if set, zeroed), return this
Style: natural -- vtable store first, then two guarded member releases
Note: size includes the trailing pool word (0xb1a5c); at 0x4c it is 19/19.
