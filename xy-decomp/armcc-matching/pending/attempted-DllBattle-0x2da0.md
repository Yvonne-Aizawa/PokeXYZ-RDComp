## DllBattle@0x2da0 (size 0x38) and 0x2dd8 (size 0x34)

- What it is: dtor stages: install vtable, free member at +0x14 if non-null and zero it; 0x2da0 tail-calls a base dtor with this, 0x2dd8 returns this.
- Tried: dtor recipe (`void *vt = VT; void *p = this->m; this->vt = vt; if (p) {free(p); this->m = 0;}`), which matches DllBag@0x13848 / DllBattleHouseConnect@0x2fc.
- Stuck on: 12/14 (0x2da0) and 11/13 (0x2dd8). Only the zero constant differs: retail `mov r1,#0; str r1,[r4,#20]`, armcc emits `mov r0,#0; str r0,[r4,#20]` (reuses dead p reg). Hoisting a `z = 0` local made it worse (5/13).
- Lead for next time: none yet; zero-register residue.

## DllBattle@0x12f84 (size 0x48)

- What it is: dtor stage like matched 0x12fcc but with a tail `b` to base dtor.
- Tried: 0x12fcc shape + tail call; vt-local dropped / vtable store hoisted (3 variants).
- Stuck on: 2/18 words, candidate is 17 words vs retail 18. Retail keeps member in r1 and vtable in r2 (`ldr r2,pool; ldr r1,[r0,#8]; mov r4,r0; str r2,[r0]`), vcall as `ldr r0,[r1]; ldr r2,[r0,#4]; mov r0,r1; blx r2`; armcc puts the member in r0.
- Lead for next time: none yet.
