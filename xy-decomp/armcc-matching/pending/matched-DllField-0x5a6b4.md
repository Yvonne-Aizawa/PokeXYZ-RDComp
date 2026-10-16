Module: DllField
Offset: 0x5a6b4
Size: 0x4c
Match: 19/19
One-line: Same id check; on success returns Tail(r), else Other(0,0,0) and returns 0.
Style: trick(volatile) -- b read through volatile int* so armcc emits ldr+uxth instead of ldrh.
