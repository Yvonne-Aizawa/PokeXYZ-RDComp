Module: DllBattle
Offset: 0x7a780
Size: 0x30
Match: 12/12
One-line: static-style helper (this in arg2): if !this->vt[0x42](this) tail-call fn(this->+0x190)
Style: trick(extra-arg) -- unused first arg so `this` arrives in r1
