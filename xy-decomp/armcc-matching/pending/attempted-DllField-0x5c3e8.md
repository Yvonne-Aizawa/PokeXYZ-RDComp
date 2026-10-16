## DllField@0x5c3e8 (size 0x1c; sibling 0x5c404 differs only in callee)

Shape: push {r4,lr}; ldrd r0,[r1,#4]; and r0,#255; uxth r4,r1; bl F; mul r0,r0,r4; pop. i.e. F((u8)b[1]) * (u16)b[2] with the pair loaded by one ldrd.
- Stuck on: 5/7. Plain u32 reads give ldrb+mov r4,r1+ldrh after call; a u64 load narrows to ldrb/ldrh (no ldrd). Retail ldrd means the 8 bytes are loaded as one 64-bit value and both halves stay live (maybe struct copy / long long passed on). Lead: try keeping the full u64 live (e.g. use v after the call) so armcc cannot narrow.
