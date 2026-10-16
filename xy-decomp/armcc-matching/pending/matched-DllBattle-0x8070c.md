Module: DllBattle
Offset: 0x8070c
Size: 0x3c
Match: 15/15
One-line: script-command handler: reads one float argument, substitutes 50.0f if it is negative, and stores it into the object's float field at +248.
Style: natural
Note: Float arg reader (veneer 0x1acc); the 0.0f compare constant and the 50.0f default both live in the literal pool (hence 15 words incl. 2 pool words).
