Module: DllField
Offset: 0x5e278
Size: 0x38
Match: 14/14
One-line: Script handler: if helper(u16 b[1]) succeeds, calls a second helper with manager +12 -> +28 and the id; returns 0.
Style: trick(volatile) -- b read through a volatile pointer only so armcc emits ldr+narrow (uxth/and) instead of ldrh/ldrb.
