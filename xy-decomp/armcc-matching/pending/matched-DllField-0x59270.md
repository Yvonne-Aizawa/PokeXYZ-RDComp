Module: DllField
Offset: 0x59270
Size: 0x38
Match: 14/14
One-line: Id check: u16 b[1] -> Q(H(manager +12 -> +72), id); on nonzero tail-calls a follow-up with Q's result.
Style: trick(volatile) -- b read through volatile int* so armcc emits ldr+uxth instead of ldrh.
