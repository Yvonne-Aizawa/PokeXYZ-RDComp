## DllField@0x90c00 (size 0x54) -- volatile-load retry, 2026-10-16

- What it is: handler `(self, args)`: `o = self->+68; GetMgr(); s = (s16)args[2]; id = (u16)args[1]; tab = o->+144; x = mgr->+12->+72; r = (s == -1) ? tab->+16 : Q(G(x), s); if (r) T(r, id & 255); return 0`.
- Lever applied: `volatile int *b` read (`int a1 = b[1]; int a2 = b[2];` first) gives the retail `ldr r2,[r1,#4]; ldr r1,[r1,#8]; uxth/sxth` and the whole body shape (cmn / ldreq / blne). Best 19/21.
- Stuck on: callee-saved assignment only -- retail `o -> r5, id -> r6`, ours `o -> r6, id -> r5` (with `tab` volatile / hoisted `x = *(int*)(m+72)` before the `if` the instruction order matches exactly; without them the `ldr r1,[tab]` / `ldr r0,[r0,#72]` order differs). Declaration-order variants of o/s/id/a1/a2 (5 tried) all keep the swap; the variant that gets the right registers (volatile tab read inside the `if`) has the wrong load order.
- Lead: same r5/r6 swap class as 0x9e550 / 0x9d970.
