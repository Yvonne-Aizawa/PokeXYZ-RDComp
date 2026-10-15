Module: DllField
Offset: 0xe3fc
Size: 0x10
Match: 4/4
One-line: leaf zeroing two adjacent int members at this+20/+24
Style: trick(live-r1-passthrough) -- long long return built from (r0,r1) args keeps r1 live so armcc zeroes via r2
Note: mechanism found for the "zero via r2 not r1" residue class (leaf case): zero goes in the lowest free scratch reg > live ones; a live passthrough r1 pushes it to r2.
