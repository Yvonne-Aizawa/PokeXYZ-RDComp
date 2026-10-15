Module: DllField
Offset: 0x74dc8
Size: 0x10
Match: 4/4
One-line: sets this->kind(+134)=1, returns &arg1->sub at +256. Family `mov r2,#K; strb r2,[r0,#134]; add r0,r1,#OFF; bx lr` (consecutive 0x10-byte functions, likely per-type virtual overrides): 0x74dd8 (K=2,OFF=276), 0x74de8 (3,296), 0x74df8 (3,308), 0x74e08 (3,320), 0x74e18 (4,332).
Style: natural
