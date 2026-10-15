Module: DllTownmap
Offset: 0x31a0 (size 0x30)
Match: 8/12 best; 5-6/12 with locals
Note: sibling dtor 0x31d4 MATCHED 14/14.
Tried (2026-10-15 retry): VT as char array; locals a=VT, b=a+0x40 in several orders; vptr readback. Retail: ldr r0,pool after mov r4,r0; add r1,r0,#64; str r0,[r4]; mov r0,r4; str r1,[r4,#116]. Locals variants hoist the pool load above push (ldr r1 first) -- wrong.
