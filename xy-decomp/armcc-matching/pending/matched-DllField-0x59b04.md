Module: DllField
Offset: 0x59b04
Size: 0x24
Match: 9/9
One-line: Same as 0x593cc with a different tail helper.
Style: trick(volatile) -- b is read through a volatile pointer only so armcc emits ldr+narrow (uxth/and) instead of ldrh/ldrb.
