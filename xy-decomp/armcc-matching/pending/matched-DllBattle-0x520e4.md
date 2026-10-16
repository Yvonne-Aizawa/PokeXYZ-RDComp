Module: DllBattle
Offset: 0x520e4
Size: 0x38
Match: 14/14
One-line: range-checked byte getter: returns o->arr[i*14] (u8 at +286, stride 14) when i < o->count (u8 at +338); otherwise calls assert stub fnA(0,0,0) and returns 0.
Style: natural
