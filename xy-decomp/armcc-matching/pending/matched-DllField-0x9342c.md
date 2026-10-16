Module: DllField
Offset: 0x9342c
Size: 0x3c
Match: 15/15
One-line: Bit-set test: i = args[1]; b = mgr->+12->+28->[0]+0x12e4 (bitset header); returns (R(b, b[1])[i>>3] >> (i&7)) & 1.
Style: natural -- plain call, pointer-chain loads; no tricks.
