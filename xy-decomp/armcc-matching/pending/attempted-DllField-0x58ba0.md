## DllField@0x58ba0 (size 0x20) -- Imp(a, (short)b[1], 0, 9, 0)
Retail: ldr r1,[r1,#4]; mov r2,#0; mov r3,#9; str r2,[sp]; sxth r1,r1; bl. armcc narrows the int load+sxth to ldrh (4/8; the ldrd/ldrb-style narrowing residue). Tried int/short-param prototypes; same. Sibling 0x58bc0 same shape.
