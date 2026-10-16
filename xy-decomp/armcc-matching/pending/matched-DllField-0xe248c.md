Module: DllField
Offset: 0xe248c
Size: 0x24
Match: 9/9
One-line: o = arg->[4]; return o->vtable[55](o, 0) != 0
Style: natural -- plain virtual call, result != 0
Note: the fn at 0xe24b0 (`mov r0,#12; bx lr`, 2 words) is the next function, a trivial return-12 stub.
