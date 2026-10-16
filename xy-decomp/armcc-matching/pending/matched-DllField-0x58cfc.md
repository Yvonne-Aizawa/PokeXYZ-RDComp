Module: DllField
Offset: 0x58cfc
Size: 0x30
Match: 12/12
One-line: Script predicate: u16 b[1] checked through helper on manager +12 -> +28 -> +32; returns nonzero.
Style: trick(volatile) -- b read through a volatile pointer only so armcc emits ldr+narrow (uxth/and) instead of ldrh/ldrb.
