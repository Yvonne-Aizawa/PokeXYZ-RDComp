Module: DllField
Offset: 0x5e068
Size: 0x30
Match: 12/12
One-line: Script handler: b[1]&255 with (*(manager +12 -> +28)) + 0x1b814 to a helper (tail call).
Style: trick(volatile) -- b read through a volatile pointer only so armcc emits ldr+narrow (uxth/and) instead of ldrh/ldrb.
