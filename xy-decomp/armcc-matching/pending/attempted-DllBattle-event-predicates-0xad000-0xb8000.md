## DllBattle event-trigger predicates 0xad000-0xb8000 (bl 0x6b91c callers) -- prologue-move swap residue (round 2026-10-16-b)

Scan: 226 non-matched `bl 0x6b91c` callers in range. Matched the c-only / c-in-r4 shapes (see pending/matched-DllBattle-*.md; 11 functions).

Stuck (all the SAME 2-word residue, rest of body right):
- c AND d saved (`push {r4,r5,r6,lr}`; `fn(a,b,c,int *d)`): 0xb67b0 13/15, 0xb6e80 17/19, 0xb47dc 14/16, 0xb6ecc 14/16, 0xb57f8 18/20, 0xb73c8 19/21.
  Retail moves the LOWER arg first (`mov r4,r2; mov r5,r3` or `mov r5,r2; mov r4,r3`); armcc always emits the higher arg (`mov rX,r3`) first. Register assignment is already right.
- b AND c saved (0xb76c8 14/16 `if (g(3)==c && h(b)) post(83,1)`, same family 0xb0e94, 0xb0b4c, 0xae96c, 0xb1314 ...): retail `mov r5,r1; mov r4,r2`, ours `mov r4,r2; mov r5,r1`.
- Tried on 0xb67b0: local copies of c/d in either order, struct pointer, nested ifs, unsigned params, int return, hoisting the d load before the g call (changes code). None change the move order.
- Lead: the retail source probably had a different arg-forwarding shape (inlined helper taking (b,c) / (c,d) in order) -- not found.

Not attempted (bigger bodies): 0xadce8 (ldrh+cmp ?: literal-pool pick), 0xb5574, 0xb79c0, 0xb67ec/0xb68c4 style d-writers, loop at 0xb6438.
