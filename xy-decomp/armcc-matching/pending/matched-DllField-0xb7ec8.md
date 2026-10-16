Module: DllField
Offset: 0xb7ec8
Size: 0x2c
Match: 11/11
One-line: secondary-base dtor stage -- store vtable arg, `if (this[32]) Free(this, this+32)`, return Base(this+8)-8 (one of 24 identical sites)
Style: trick(volatile-store) -- vptr store via volatile pointer only to keep `mov r4,r0` before the store; the if-converted `addne/blne` comes from an inline C++ member (.cpp)
Note: cracked the "branch vs conditional execution" residue: an inline member `Reset(){ if(m) fr(this,&m); }` makes armcc load the test into r1 (r0 stays `this`), so the arm is 2 instrs and gets if-converted. Same body as a free function gives `beq` (4/11).
