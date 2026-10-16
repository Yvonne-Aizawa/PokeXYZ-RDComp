Module: DllField
Offset: 0xcff28
Size: 0x60
Match: 24/24
One-line: State-handler step: if byte [+276]==0 calls P(this, -float[+272], 0); then Q(this, byte[+277]); R(this, 0.0f, 0.0f); clears halfword [+0x102] and byte [+260]; returns 1.
Style: trick(redundant-local) -- p = t+0x100 named local pins retail's early add r5,r0,#256 and the strh [r5,#2]
