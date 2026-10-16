Module: DllField (callers of bl 0x16c0, file offsets 0x90000-0x98000) -- round 2026-10-16-b

Matched this round: see pending/matched-DllField-0x9*.md (29 functions).

Stuck (all one instruction off unless noted):
- ldrb/ldrh narrowing family (retail `ldr r,[a,#4]` + `and #255` / `uxth` / `sxtb` at use; armcc narrows the load to ldrb/ldrh whatever the cast form -- &255, (unsigned char), (signed char), &0xffff, int local first): 0x9515c, 0x923f0, 0x93d10, 0x948f0, 0x928f0, 0x93b30, 0x94d18, 0x97ee4, 0x916a8, 0x922bc, 0x947ec, 0x93cac, 0x92d34, 0x91330, 0x90b24, 0x92424, 0x97a74, 0x95df0, 0x928ac, 0x94894, 0x9484c, 0x90c00 (every other word matches).
- Large-offset byte access (0x1539c via `add #0x15000; add #0x39c; ldrb/strb [r0]` -- armcc folds 0x39c into the ldrb imm for every C form tried, incl. nested structs): 0x93cec, 0x93d10, 0x92e28/0x94cb8 (0x1539d, literal-reg form, 7/9 words only).
- Bitset set/clear (0x93468 `|=`, 0x955cc `&=~`): 14/17, only the shift-amount/constant registers swap (r2<->r3); tried 6 spellings (%8, &7 temp, unsigned char m, reordered |).
- 0x9056c: r4/r5 swapped (self and mgr roles); 0x94580: retail does `ldr r0,[..#344]; mov r6,r0` before the a[1] load (5/21 words).
- Struct-on-stack out-params 0x9713c / 0x971e4: 21/27, retail loads `[m+72]+252` into r2 first then `mov r0,sp; ldr r1,[r2,#124]`, ours folds into r0; the D() arg setup (`add r2`/`add r1` before `mov r0,sp`) is also reversed.
- 0x97250: load ordering (m=[p+12] first, then a=[p+28]) not reproduced (15/23).
- nop-window family (`bl 0x200` + `nop {0}`; relaxed-only): 0x925f0, 0x94ec0, 0x94f04, 0x94f48, 0x959bc, 0x968e4, 0x93d90, 0x94f8c, 0x925a0, 0x93058, 0x969fc, 0x94e68, 0x915f4.
- Not tried: 0x926b4, 0x927b0, 0x94c58, 0x920dc/0x95a00/0x95c88/0x905c8 (operator-new constructors), 0x95fa4, 0x97acc, 0x9461c.
