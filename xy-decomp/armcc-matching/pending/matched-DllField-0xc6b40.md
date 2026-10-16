Module: DllField
Offset: 0xc6b40
Size: 0x10
Match: 4/4
One-line: Deleting-destructor thunk: calls the local destructor at 0xc6b50 then tail-calls operator delete (0x1c8) on the returned pointer.
Style: natural -- del(D(t))
