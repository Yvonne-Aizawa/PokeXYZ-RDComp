Module: DllField
Offset: 0x5edcc
Size: 0x3c
Match: 15/15
One-line: Script handler: u16 id checked via Q(H(manager +12 -> +72), id); returns 1 if not found else tail-calls Tail(r).
Style: trick(volatile) -- b read through a volatile pointer only so armcc emits ldr+narrow (uxth/and) instead of ldrh/ldrb.
