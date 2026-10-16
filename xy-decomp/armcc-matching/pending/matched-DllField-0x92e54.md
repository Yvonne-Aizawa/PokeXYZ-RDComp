Module: DllField
Offset: 0x92e54
Size: 0x34
Match: 13/13
One-line: Gets obj=mgr->+12->+72->+240->+2740; if Q(obj+844) is false, clears obj byte +232 and returns 1 (predicated strb/mov), else returns 0.
Style: natural -- plain call, pointer-chain loads; no tricks.
