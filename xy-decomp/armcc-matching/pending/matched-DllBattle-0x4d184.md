Module: DllBattle
Offset: 0x4d184
Size: 0x44
Match: 17/17
One-line: range-checked hi-lo getter: asserts (fnA(0,0,0)) when i >= o->count (u8 at +338), then returns byte(+287+14i) - byte(+286+14i) (hi minus lo of a 14-byte-stride record; sibling of 0x520e4).
Style: trick(ordering-local) -- local 'lo' forces the retail load order (lo byte first)
