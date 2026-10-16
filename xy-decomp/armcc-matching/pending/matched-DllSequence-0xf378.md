Module: DllSequence
Offset: 0xf378
Size: 0x38
Match: 14/14
One-line: store -1 at this+0x34 then two 3-arg veneer calls on this+0x2c / this+0x30
Style: natural
Note: second call is a 3-arg veneer (mov r2,#1), not the 4-arg fnD of 0xb664.
