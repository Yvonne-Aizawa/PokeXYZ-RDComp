Module: DllPuzzle
Offset: 0xb3fc (size 0x38)
Match: 12/14
What it is: dtor stage, tail-call base. Twin 0xbf80 now MATCHES (14/14, trick ordering-local).
Tried (2026-10-15 retry): local vt=VT + extern char VT[] gets everything but the zero: retail does `mov r1,#0; str r1,[r4,#20]` (zero in r1), ours uses r0. Also tried int member, f1f8 returning void* with (r&0), z=0 local hoisted (6/14), reusing the vt local as the zero (12/14).
Stuck on: only the 2-word zero-register diff. Same diff blocks DllBox 0x1dfac/0x1df3c.
