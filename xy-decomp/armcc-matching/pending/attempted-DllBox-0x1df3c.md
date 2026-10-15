Module: DllBox
Offset: 0x1df3c (size 0x70) and 0x1dfac (size 0x6c incl. pool)
Match: 20/28 and 23/25
Tried (2026-10-15 retry): 0x1dfac natural form with extern char VT1[]/VT2[] = 23/25, only the zero-in-r1 diff (same as DllPuzzle 0xb3fc). 0x1df3c with a vt1 local = 20/28: retail loads VT1 into r2, member into r1, and delays `mov r4,r0`; ours does mov r4,r0 first and uses r1/r0. Adding a vt2 local spills to r5/r6 (8/28).
