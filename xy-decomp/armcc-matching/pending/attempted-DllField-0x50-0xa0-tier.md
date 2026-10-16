## DllField 0x50-0xa0 tier sweep (2026-10-16) -- shapes NOT matched

Scan recipe: bound functions at `push {..lr}` and in-module `bl` targets, size 0x50-0xa0, exclude matched/ and
the GetMgr callers / other agents' ranges, drop any body with a post-link `nop` word (relax-only class, e.g. the
0x11fa0 / 0x11ff0 / 0x12ccc / 0x12d1c destructors that contain `nop` before `bl`).

Useful new lever: the `ordering-local` form (`O *a = s->a; void *vt = VT; s->vt = vt;`) cracks the
"member load before vtable pool-load" dtor shape (DllField 0x3954c + 4 siblings matched). Switch with
`case 16: case 56:` reproduces a three-compare `cmp #16 / #22 / #56` chain (an `||` chain gives `cmpne`).
An `unsigned` loop counter fixes `bcc` vs `blt`.

- DllField@0x14fa0 (0x50), 0xe7168 (this-0x74 variant, 0x50), 0x12040 (0x5c, +0x80/+0x89): `if (chk(a, 0x60, 0) == 0) return 1; if (this->o && !this->b) o->vt[2](o); return 0;`
  Best 2/20: armcc emits `mov r3,r1` BEFORE the push and passes r3 as arg 0; retail does `mov r4,r0; mov r0,r1` after the push (a is forwarded straight). Tried int / void* arg, C and C++.
- DllField@0x394f4 / 0x396d0 / 0x3a644 / 0x3a908 / 0x3cd5c (0x58, tail-calling `b 0x1c8` dtor variants): retail stores the vtable via the ORIGINAL r0 (`str r2,[r0]` after `mov r4,r0`), loads the member into r1 and calls through r2 (`ldr r0,[r1]; ldr r2,[r0,#4]; mov r0,r1; blx r2`). The ordering-local form that solved the non-tail sibling gives r4-based stores (4/22).
- DllField@0x47fec (0x5c): `if (cur != v) { switch (h->mode) { 1: h->o1->vt[18](o1); 2: h->o2->vt[11](o2); } cur = v; }` (h = this+0x1f8, cur at +0x218). Callee-saved swap: retail keeps this in r5 / v in r4 (and loads the mode into r2 before computing h into r0); armcc picks r4/r5 the other way and loads mode into r0. 7/23.
- DllField@0x7ee64 (0x5c): `t = this->tbl; hi = t[idx].b; if (t[idx].a & 0xff) err(0,0,0); go(this->base + hi*64, d, 0, c)` (tail call). Only the callee-saved assignment (r6=c first, r7=d later) and the `ldrh [r0, r2]` with r2 = 2 + idx*4 addressing differ. 3/23.
- DllField@0x4f214 (0x54): `c = chk(b); set(p, c ? 32 : 33); go(this, b, 1, 1, (signed char)(c ? 11 : 8)); return 1`. Retail keeps an `sxtb` of the value (r5) before the stack-arg store; armcc folds the cast away because it sees the constants. Interleaving of the conditional moves is already identical (11/21).
- DllField@0xe1bf0 / 0xe1f8c (0x50, script-command handlers, constant 2 / 3): retail pushes r4-r8 and keeps the constant in r7 (`mov r7,#2` early), non-tail final call; plain code gives a 4-register push and a tail call. Same class as the arg-load-width script handlers in attempted.md.
