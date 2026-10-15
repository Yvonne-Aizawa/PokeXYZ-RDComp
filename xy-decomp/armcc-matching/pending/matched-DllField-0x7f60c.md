Module: DllField
Offset: 0x7f60c
Size: 0x10
Match: 4/4
One-line: table getter: `unsigned short get(int i,int,int,struct E *t){return t[i].k;}` -- 12-byte entries (add r0,r0,r0 lsl1; add r0,r3,r0,lsl2), u16 at +10 (table pointer arrives in r3, 4th arg). Siblings differing only in ldrh offset: 0x7f628 (+22), 0x7f65c (+8), 0x7f678 (+20).
Style: natural
Note: the 4th-arg-in-r3 means the real function has 3 leading args (probably this + 2) before the table ptr, or the table is a global loaded by an inlined caller; the C signature is only a register-shape placeholder.
