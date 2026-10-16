Module: DllBattle
Offset: 0xa60c8 (and all b+c / c+d savers in 0xa5000-0xad000)
Size: 0x58
What: event-trigger predicates that must save both b and c (or c and d) across the 0x6b91c call: 0xa60c8/0xa67b4/0xa6924/0xa6a64/0xa6d98/0xa7130/0xa7788/0xa8530 (store-struct-then-0x67b48 family, 0x69f7c alloc), 0xa64bc/0xa629c/0xa6b90/0xa80a8/0xaa608/0xab074 (0x544a0 lookup + u16@12 compare), 0xa6504, 0xa79d4, 0xa71f4 (r4=c vs r0=b ordering), 0xa85cc/0xabb48/0xacbc8/0xacc94 (c,d), 0xa7e18 (a,c).
Tried: natural source for each (all other words match; e.g. 0xa64bc, 0xa629c, 0xa79d4 differ ONLY in the first two prologue moves: retail `mov r5,r1; mov r4,r2`, ours `mov r4,r2; mov r5,r1`). Same residue as the known 0xa7cd0/0xa7188/0xc1244 swap; no new lever found. 0xaa608 additionally compiled `v==380||v==381` to `mvnne r1,#380` instead of retail `subne #256; subsne #125` (likely a different source shape for the range test).
