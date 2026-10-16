## DllBattle@0x4bed4 (size 0x20)

- What it is: `return fnA(o->m@0x5c, k, 16) == 5;` (k passes through in r1).
- Tried: plain `void *` member, typed struct, int member, unprototyped `fnA()`, local `n = 16` / local `m`, if/else return form.
- Stuck on: 6/8 — retail emits `mov r2,#16` BEFORE `ldr r0,[r0,#92]`; armcc always loads r0 first. Everything else identical.
- Lead for next time: the retail order suggests the 16 is materialised before the member load (maybe an inlined accessor or the constant being a prior expression); untested: constant passed via a static/global-typed enum, or `k` reassigned.
