Module: DllField
Offset: 0x5912c
Size: 0x34
Match: 13/13
One-line: Script handler: u16 b[1] with (*(manager +12 -> +28)) + 0x3410 to a helper; returns 0.
Style: trick(volatile) -- b read through a volatile pointer only so armcc emits ldr+narrow (uxth/and) instead of ldrh/ldrb.
