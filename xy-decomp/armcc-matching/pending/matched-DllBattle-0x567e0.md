Module: DllBattle
Offset: 0x567e0
Size: 0x18
Match: 6/6
One-line: byte-splat fill of 8 bytes (low byte of arg replicated into a u32, stored twice)
Style: natural
Note: family "byte-splat fill" (push-less leaf): siblings 0x6fd18 (u32+u16, matched), 0xc9e84 (u32+u32+u16, matched); all `and r1,r1,#255; orr r1,r1,r1,lsl#8; orr r1,r1,r1,lsl#16`. Scan: DllBattle push-less leaf scan found 59 non-trivial candidates (Ghidra function bounds, size 0xc-0x60, no b/bl/push); other families listed in the pending notes of 0x76360/0x5daf8.
