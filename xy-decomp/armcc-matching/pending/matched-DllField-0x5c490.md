Module: DllField
Offset: 0x5c490
Size: 0x2c
Match: 11/11
One-line: Script handler: u16 arg b[1] and (*(manager +12 -> +28)) + 724 to a helper (tail call).
Style: trick(volatile) -- b is read through a volatile pointer only so armcc emits ldr+narrow (uxth/and) instead of ldrh/ldrb.
