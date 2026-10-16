Module: DllField
Offset: 0x59c98
Size: 0x1c
Match: masked match (all words, b/bl masked)
One-line: Calls H(G(a), b[1]) -- second arg is loaded from the second param before the first call -- and returns 0.
Style: natural
Note: b[1] is read into callee-saved r4 before the getter call.
