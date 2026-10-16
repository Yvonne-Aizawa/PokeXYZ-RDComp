Module: DllField
Offset: 0xbbb54
Size: 0x10
Match: 4/4
One-line: Deleting-destructor thunk: calls 0x6d64c (dtor body, returns this) then tail-calls free helper 0x1c8.
Style: natural -- nested call, outer call in tail position.
Note: only caller of 0x6d64c in DllField; 0x6d64c itself (ctor/dtor body storing vtable ptrs at +0/+56) not attempted.
