Module: DllField
Offset: 0x5c5d4
Size: 0x1c
Match: 7/7
One-line: Script handler: u8 arg b[1] forwarded with the manager pointer to a helper (tail call).
Style: trick(volatile) -- b is read through a volatile pointer only so armcc emits ldr+narrow (uxth/and) instead of ldrh/ldrb.
