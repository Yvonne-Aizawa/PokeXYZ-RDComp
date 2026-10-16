Module: DllBattle
Offset: 0x36d64
Size: 0x10
Match: 4/4
One-line: chained call `fnB(fnA(o))`, second call a tail call
Style: natural
Note: the 0x14 span a naive scan sees includes the next function's `b` at 0x36d74.
