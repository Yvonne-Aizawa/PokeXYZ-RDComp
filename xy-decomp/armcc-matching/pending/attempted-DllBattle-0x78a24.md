## DllBattle@0x78a24 (size 0x24) -- and sibling 0x7b2e4 (same shape, ldrb [r0,#365])

Shape: `r = A(o, *p); return B(o->field8, r)->u16 at +12`. Compiled with
`int r = fn5dc68(o,*p); return *(u16*)(fn707d4(*(int*)(o+8), r)+12);` (also the nested-call,
and a typed-struct form) -> 4/9..8/9: armcc hoists `ldr r2,[r4,#8]` right after the first bl and
adds `mov r0,r2` (one extra word, 10 vs 9). Retail does `mov r1,r0` then `ldr r0,[r4,#8]` (load
straight into r0 after the call). Lead: the second call's first arg is probably not a plain
field load (maybe an accessor/vt thing or a different arg order) -- unresolved.
