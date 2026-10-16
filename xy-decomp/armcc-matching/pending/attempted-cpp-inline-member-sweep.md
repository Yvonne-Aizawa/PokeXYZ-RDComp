Module: DllField / DllBattle (sweep)
Offset: 0xb6844 0xb76c8 0xbe3e8 0xb4e84 0xb0334 0xcae50 0xcb41c 0xde620 DllBattle 0x7198c 0x73524 0x78a24 0x77338
Style: n/a (no match)

2026-10-16 C++ inline-member sweep (the DllField@0xb1bb8 mechanism). One NEW match came out of it:
DllField@0x2948c (matched-DllField-0x2948c.md; trick(cpp-inline-member)). The mechanism generalises as
"write the pointee-side logic as an inline member called on the loaded pointer", but only that one flipped.
Everything below stayed stuck; what was tried, so nobody repeats it:

- DllField 0xb6844 / 0xb76c8 (secondary-base dtor pair): with a volatile-stored first vptr (or a plain store)
  plus `Reset()` member the tail is exact; best 19/22 (plain `o->vt = v`, stores [56],[0],[80]) -- only the head
  `add r2,r1,#48` (retail keeps v+48 in r2 and v+32 in r0; ours puts v+48 in r0) and the pool `ldr` displacement
  differ. NEW FINDING: the pool displacement is NOT a code diff we can fix -- retail's function starts at 4 mod 8
  so the literal pool word is 8-aligned after a 0 pad word (ldr disp 40 vs our 36); the standalone verifier
  compile (text starts at 0) can never emit that pad. Same class as DllBattle@0x71a2c. Even a perfect head
  cannot reach a masked 22/22 for these two; needs a verifier option to tolerate pool-alignment padding.
  Tried head forms: locals q/t in both orders, typed `void **v` arithmetic (v+8, v+12), early `v+48`.
- DllField 0xbe3e8 / 0xb4e84 (`movs r1,r0`): inline member Go(a) {r=fa(m,a,1); if(r) fb(this,r);} in 8 phrasings
  (if-init, bool temp, extra copy, helper member taking r, volatile r, int/unsigned/char* typing): all 6/11 (cmp
  r0,#0 then mov r1,r0). 0xb0334 as a member: 8/17 and it never pushes {r4-r6}; retail keeps the result in
  r5 (callee-saved) across only loads, so some extra live value (r6 = 8-byte push alignment pad?) exists in the
  original that none of these reproduce.
- DllField 0xcae50 / 0xcb41c: member Go() on the object, plain/goto/shared-store/ret-variable/destructor-in-class
  forms: 19/27 plain, 25/27 goto-shared-store (unchanged). Retail `movne r0,#0; bne <final pop>` needs the
  return-0 path to share the final epilogue after `mov r0,#1`; no form produced it.
- DllField 0xde620 (record fill): inline member Init()/ctor/placement-new, volatile kind member (best 7/11,
  same as before), integer-address round-trip, identity-helper, reference alias: none make armcc compute
  `add r4,r1,#12` before the stores and reuse r1 for the constant.
- DllBattle 0x7198c / 0x73524: whole predicate chain as an inline member of the pointee, && / if-return /
  nested-if forms, volatile loads: volatile fixes `ldr` vs `ldrb` (9/16) but armcc still if-converts the second
  load (`ldreq/tsteq`); in 0x73524 the volatile load is if-converted too (4/16). No form blocks the conversion.
- DllBattle 0x78a24 / 0x77338 family: member Go() with m loaded in member scope, nested helper member, volatile m:
  all 4/9 (`ldr r2,[r4,#8]` hoisted before `mov r1,r0`; even volatile m is hoisted).
