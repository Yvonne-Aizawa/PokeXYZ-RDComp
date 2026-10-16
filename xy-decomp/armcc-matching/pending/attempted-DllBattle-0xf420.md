## DllBattle@0xf420 (0x1c), 0xf3fc (0x24), 0xca9c (0x20) -- u8-masked arg wrappers

- What they are: virtual-override wrappers `fn(this, a, int *args) { import(this->@0x40, args[0] & 0xff [, args[1]...]); return 1; }` (f420: one masked arg; f3fc: two masked args, args[0], args[1]; ca9c: `ldm r2,{r1,r3}` then `and r1,r1,#255`, second arg unmasked).
- Tried: `& 0xff`, `(unsigned char)` casts, `unsigned char` callee params, local copy, struct copy `S s = *args`, by-value struct param.
- Stuck on: armcc narrows the load to `ldrb r1,[r2]` (5/7 on f420) and drops the `and`; retail does a full-word `ldr` then `and r1,r1,#255` placed after the `ldr r0`. Only `volatile unsigned *args` reproduces f420 (7/7 masked) -- that is a trick(volatile-load), not recorded under matched/.
- Lead: the original probably copies the whole arg struct (ldm for ca9c) with a u8 narrowing at the call; a natural form that defeats ldrb narrowing is unknown.
