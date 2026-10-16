Module: DllField
Offset: 0x590fc
Size: 0x30
Match: 12/12
One-line: Script handler: u16 b[1] with (*(manager +12 -> +28)) + 0x3410 to a helper (tail call).
Style: trick(volatile) -- b read through a volatile pointer only so armcc emits ldr+narrow (uxth/and) instead of ldrh/ldrb.
