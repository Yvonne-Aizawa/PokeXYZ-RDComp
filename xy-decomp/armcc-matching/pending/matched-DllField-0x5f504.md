Module: DllField
Offset: 0x5f504
Size: 0x1c
Match: masked match (all words, b/bl masked)
One-line: Loads t=a->@68 first, calls G(a), then H(t->@144) and returns 0.
Style: natural
Note: The a->@68 load precedes the first call (callee-saved r4).
