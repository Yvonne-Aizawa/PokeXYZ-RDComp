Module: DllField
Offset: 0x593cc
Size: 0x24
Match: 9/9
One-line: Script handler: u16 arg b[1] forwarded with the manager's +16 -> +4 object to a helper (tail call).
Style: trick(volatile) -- b is read through a volatile pointer only so armcc emits ldr+narrow (uxth/and) instead of ldrh/ldrb.
