## DllField script-command handlers whose only miss is the arg-load width (0x93d10, 0x948f0, 0x93b30, 0x94d18, 0x9aeb8) -- 2026-10-16

Handlers `int Fn(int self, int *args)` reading `args[1]` and narrowing it. Retail does a full `ldr rX,[r1,#4]` then `uxth`/`sxtb`/`strb`;
armcc always folds the narrowing into the load (`ldrh`/`ldrb`), for every form tried (`unsigned short i = a[1]`, `int v=a[1]; short i=v`,
`a[1] & 0xffff`). Same residue class as ldrd/ldrh narrowing. Each is otherwise 11/12 or 12/12 with the right body:
- 0x93d10 (0x2c): `*(char*)(*(char**)(*(char**)(*(char**)(mgr+12)+28)) + 0x1539c) = args[1]; return 0` (local `char *q = b + 0x1539c` reproduces the split `add`s); miss ldr vs ldrb.
- 0x948f0 (0x2c): `return ((int*)(tbl396 + (u16)args[1]*28))[5]`; miss ldr vs ldrh.
- 0x93b30 (0x30): `H1(mgr[11], (u16)args[1]); H2(mgr); return 0`; miss ldr vs ldrh.
- 0x94d18 (0x30): `H(b + 0x14cd0, (signed char)args[1])`; miss ldr vs ldrb.
- 0x9aeb8 (0x30) sibling of matched 0x9af9c: `& 15` form emits `ldrb` instead of retail `ldrh; and #15`.
Also stuck: 0x98bc0 (0x2c, uxth scheduled before `mov r3,#0`), 0x9d8f4 (0x2c, zero-register: retail materialises `mov r1,#0` after the adds), 0x9a618 (0x2c, pool-reg allocation differs).
