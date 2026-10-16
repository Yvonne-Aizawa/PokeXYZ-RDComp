## DllBattle@0x2da0 (size 0x38) and 0x2dd8 (size 0x34)

- What it is: dtor stages: install vtable, free member at +0x14 if non-null and zero it; 0x2da0 tail-calls a base dtor with this, 0x2dd8 returns this.
- Tried: dtor recipe (`void *vt = VT; void *p = this->m; this->vt = vt; if (p) {free(p); this->m = 0;}`), which matches DllBag@0x13848 / DllBattleHouseConnect@0x2fc.
- Stuck on: 12/14 (0x2da0) and 11/13 (0x2dd8). Only the zero constant differs: retail `mov r1,#0; str r1,[r4,#20]`, armcc emits `mov r0,#0; str r0,[r4,#20]` (reuses dead p reg). Hoisting a `z = 0` local made it worse (5/13).
- Lead for next time: none yet; zero-register residue.
