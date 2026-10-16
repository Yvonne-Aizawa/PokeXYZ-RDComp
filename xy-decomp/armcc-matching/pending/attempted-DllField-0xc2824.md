Module: DllField
Offset: 0xc2824 (siblings 0xcd2dc plain; 0xc27ec, 0xcd2a4 deleting variants)
Size: 0x34 / 0x38
Match: 8/13 best
One-line: dtor: vptr = pool addr; free member [+20] via import if non-null, zero it, return this.
Style: n/a
Note: retail order is ldr r1,[pool]; ldr r0,[r0,#20]; str r1,[r4]; cmp; ... zero via r1. Tried extern char VT[] (8/13: vptr store before member load), member-read-first local (7/13: pool ldr after member ldr, str after cmp). Known member-load-order destructor residue; also zeroing via r1 not r0.
