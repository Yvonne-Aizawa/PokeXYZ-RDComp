Module: DllField
Offset: 0xbf9ac
Size: 0x10
Match: 4/4
One-line: Deleting-destructor thunk: runs a destructor on this (import call) then tail-calls operator delete (0x1c8) on the returned pointer.
Style: natural -- del(D(t))
