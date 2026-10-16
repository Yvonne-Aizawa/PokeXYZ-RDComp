Module: DllField
Offset: 0x5a380
Size: 0x30
Match: 12/12
One-line: Script handler: u8 b[1] with (*(manager +12 -> +28)) + 0xee8 to a helper; returns 0.
Style: trick(volatile) -- b read through a volatile pointer only so armcc emits ldr+narrow (uxth/and) instead of ldrh/ldrb.
