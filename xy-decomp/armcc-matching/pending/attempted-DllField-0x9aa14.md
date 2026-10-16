## DllField@0x9aa14 / 0x9ad24 / 0xa0290 / 0x923f0 / 0x5e098 / 0x5e030 / 0x5aa34 -- ldm/ldrd/writeback variants, volatile-load retry 2026-10-16

All have the arg-load-width pattern PLUS a multi-word load instruction retail uses to fetch the args:
- 0x9aa14 (0x3c): retail `add r1,r1,#4; push; ldm r1,{r4,r5,r6}; bl; ...; sxtb r3,r6; sxtb r2,r5; sxtb r1,r4` then `H(*(mgr+12->+28)->* + 0x14cd0, ...)`. A plain `struct {int x,y,z;}` copy of `b+1` gives the exact body but each field is read as `ldrb` (armcc folds the narrowing into the load; 0/15 only because of the prologue shift). `volatile struct` copy / `volatile int*` give three separate `ldr`s, never `ldm`. Mixed plain-struct-read + volatile narrowing read not found (the narrowing cannot be separated from the load without a store to a volatile).
- 0x9ad24 (0x5c, `ldm {r4-r8}` of 5 args): same.
- 0x923f0 (0x38, `ldrd r0,[r1,#4]; and r5,r0,#255; and r4,r1,#255`): plain `long long v = *(long long*)(b+4); (int)v&255, (int)(v>>32)&255` gets two `ldrb` (folds); `volatile long long` gets `add r0,r1,#4; ldrd r2,[r0]` hoisted before the push (the ldrd imm form is not used for volatile) -- 0/14.
- 0xa0290 (0x2c): retail `ldr r3,[r4,#4]!` (pre-index writeback) then `ldr r0,[r0,#20]`, then `ldr r1,[r4,#4]`. `volatile int *p = b; x = *++p; y = p[1];` gives 8/11: no writeback, and `ldr r1,[r4,#8]` precedes the `ldr r0,[r0,#20]`; non-volatile first read folds to `ldrh`.
- 0x5e098 / 0x5e030 (0x38): `ldm r4,{r1,r2}` + `and r1,r1,#255` (callee gets args[1]&255, args[2]); not retried beyond the earlier note (volatile struct -> two ldr).
- 0x5aa34 (0x24): `ldm r1,{r0,r5}; and r4,r0,#255`, same.
- Lead: needs a construct that makes armcc form `ldm`/`ldrd` for a pair of adjacent loads while keeping the narrowing at the use (e.g. a struct-by-value parameter / inline-asm barrier); none found.
