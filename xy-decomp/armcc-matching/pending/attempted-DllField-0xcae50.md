DllField 0xcae50 (size 0x6c, 27 words) + byte-sibling 0xcb41c (consts 75/77/78, bits 0x100000/0x200000)
-- state-handler: fa(this->[68],1); if (fb(p+184) && (r=fc(p+184)) != 83) { if r==85||r==86 flags(+164)|=0x1000000, return 1; else return 0 } else flags|=0x2000000, return 1.
Best: 25/27 words (goto-shared-store variant: `int v; ... v = f|0x1000000; goto st; ... st: *(int*)(s+164)=v; return 1;`).
Stuck on: retail's `return 0` path does `movne r0,#0; bne <final pop>` (shares the epilogue pop at the very end),
mine emits `movne; beq st; pop {r4,pc}` (inline pop for the 0 path) -> two words differ (branch-vs-conditional-execution class).
The plain nested-if version (store duplicated per arm) is 19/27; an `int ret` variable pushes to r5 (worse).
