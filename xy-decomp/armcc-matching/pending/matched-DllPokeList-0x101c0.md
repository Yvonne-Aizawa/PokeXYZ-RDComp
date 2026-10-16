Module: DllPokeList
Offset: 0x101c0
Size: 0x2c
Match: 11/11
One-line: getter, true if field +0x40 is zero and field +0x44 is even or zero (tst #1; cmpne #0)
Style: natural
Note: write (b & 1) == 0 before b == 0 or armcc emits cmp/tstne instead of tst/cmpne. Identical sibling shape at 0x10228 (not done).
