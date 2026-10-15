## DllTownmap@0xaa4 (size 0x6c) -- relaxed-only, NOT a masked match

- What it is: dtor stage - store VT, virtual-delete members [0x14] (slot 6) / [0x18] (slot 1) zeroing, fn1b8(this+0x1c), return fn228(this+0x1c)-0x1c.
- Tried: natural C with `char*` return `(char*)fn228(p)-0x1c` (void* callee).
- Result: 26/26 with --relax-nops (1 nop elided before the bl fn228); masked 21/27 because the retail nop is not reproducible. Sibling 0xa34 is the same with pop {..,lr}+tail b fn230.
- Lead: code matches exactly; only the post-link nop differs.

## DllTownmap@0x928 / @0x94c (size 0x24 each)

- What it is: `o=this[1]; if(o) o[1]=K; this[0x34]=1; tail fn(this[0x14],0)` with K = 1 (0x928) / 0 (0x94c).
- Stuck on: 0x94c 5/9, 0x928 mismatched. Retail loads K into r1 unconditionally before the cmp and reloads 1 for the second store; armcc emits a conditional movne / reuses r1. Tried a static helper with K as a parameter.
- Lead: none yet.
