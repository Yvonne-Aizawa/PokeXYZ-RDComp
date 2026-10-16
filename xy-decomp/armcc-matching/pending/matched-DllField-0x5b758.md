Module: DllField
Offset: 0x5b758
Size: 0x28
Match: 10/10
One-line: Script handler: u8 arg b[1] forwarded with the manager's +12 -> +28 -> +20 object to a helper (tail call).
Style: trick(volatile) -- b is read through a volatile pointer only so armcc emits ldr+narrow (uxth/and) instead of ldrh/ldrb.
