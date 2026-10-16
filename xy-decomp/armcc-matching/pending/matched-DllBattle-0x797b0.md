Module: DllBattle
Offset: 0x797b0
Size: 0x1c
Match: 7/7
One-line: bit-pack builder: (b<<3 & 0x1f8) | 4 | (a<<9 & 0x7e00) -- two fields plus constant tag 4. Retail hoists both mask constants before the shifts/ands; plain expression loads them interleaved.
Style: trick(redundant-local) -- named mask locals m1/m2 force armcc to materialise both constants up front (retail order), and the lone `v |= 4` split keeps the tag orr before the final or
