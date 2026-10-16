Module: DllField
Offset: 0x59848
Size: 0x40
Match: 16/16
One-line: Script handler: u16 id checked via Q(H(manager +12 -> +72), id); returns 9 if not found else V(r).
Style: trick(volatile) -- b read through a volatile pointer only so armcc emits ldr+narrow (uxth/and) instead of ldrh/ldrb.
