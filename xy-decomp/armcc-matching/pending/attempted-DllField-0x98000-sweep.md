## DllField GetMgr (`0x16c0`) callers, file offsets 0x98000-0xa6000 -- sweep notes (2026-10-16, round b)

NEW LEVER (fixes the whole "arg-load width" residue class in `attempted.md`, e.g. 0x93d10 / 0x948f0 / 0x93b30 / 0x94d18 / 0x9aeb8):
declare the script-command args pointer `volatile int *a` (or read the field through `*(volatile int *)`). armcc then keeps a full
`ldr` and emits the separate `uxth` / `sxth` / `and #255` that retail has, instead of folding the narrowing into `ldrh`/`ldrb`.
Tagged `Style: trick(volatile-load)`. 0x9aeb8 (`& 15` ldrh) matched via `*(volatile unsigned short *)(p + 4) & 15`. The other
handlers listed in that attempted.md entry (outside 0x98000-0xa6000) should be retried with it.

Not matched (left for later):
- 0x9e550 / 0x9e74c / 0x9e3bc (0x44): `H(base, a[2]&255, a[1]!=0)` etc. Body right (volatile-load); only the callee-saved r4/r5 assignment is swapped
  (retail first-computed flag -> r5, ours r4). Declaration/compute-order variants tried (4); same swap class as 0x9ddc8 and 0x9d970.
- 0x9d970 (0x64): virtual call slot 13 on `F590(8)`'s result; body right, r5/r6 swapped (obj/sub-object).
- 0x9ddc8 (0x50): retail pushes `{r3-r7}` (two spare callee-saved regs) -- ours `{r3-r5}`; size/prologue mismatch.
- 0x9de9c, 0x99810 family (0x99930, 0x99ea0, 0x9accc, 0x99ef8): retail has `mov r0,rN; ldr r0,[r0,#off]` redundant moves (inline-member-on-this shape); plain C folds them. Not tried in C++.
- 0xa0b14 (0x64): stack-struct init + 3 calls; right body, retail schedules `mov r2,#37` after the pointer-chain loads and keeps the chain temp in r0 (ours r1).
- 0x9aa14 / 0x9ad24 (`ldm r1,{r4,r5,r6}` of 3-5 args then `sxtb`): folds to per-arg `ldrb`; volatile struct gives plain `ldr`s, never `ldm`.
- 0xa0290 (`ldr r3,[r4,#4]!` writeback + two uxth): volatile gives `ldr`s without the pre-index writeback (5 diffs).
- 0x9e844 (0x38): `r = H(..); if (r<0 || r>3) r = 0; return r;` retail keeps two signed compares + branches; armcc folds to unsigned `cmp #3; movhi/movcs` for every phrasing.
- 0x98c6c / 0x993dc / 0x99868 / 0x9a7cc / 0x9ff88 / 0xa0c74 and others whose disassembly shows `nop {0}`: relaxed-only (branch-relaxation nops), not matchable under the strict verifier.
- ldrd-pair handlers (0x9e074, 0x9e518, 0x9e790, 0x9eefc, 0xa0030, 0xa1238, 0xa1334, 0xa137c, 0x9966c): `ldrd` of two adjacent args -- known ldrd residue.
- 0x9a618 (pool-register), 0x9d8f4 (zero-register), 0x98158/0x9844c/0x986c0/0x9870c (not looked at): untouched this round.
