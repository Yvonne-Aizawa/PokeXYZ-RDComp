DllField GetMgr (0x16c0) family -- shapes NOT yet matched (2026-10-16 round a, scan of every `bl 0x16c0` caller)

Scan found 626 callers of 0x16c0 not in matched/ at scan time; 44 + 2 matched this round (shapes: tail-call with
constant add I, void-call+add J/K, flag-arg A, null-check blne D, ldrsb C, a[1]-arg F/G, bare call, dtor thunk 0xbbb54).
Only one `bl 0x6d64c` caller exists (0xbbb54, matched); 0x6d64c itself is a ctor/dtor body (not attempted).

Shapes seen but not tried (all use the same chain idiom; candidates for the next round, offsets are examples):
- uxth-arg + helper-call(0x865cc) + cmp + conditional tail: 0x59270, 0x592a8, 0x592e0, 0x5a6b4, 0x5d698, 0x92d34 (two nested calls, `beq` around a tail `b`).
- ldrd/uxth pair args: 0x589fc, 0x5ab58, 0x58af4, 0x5a9e8, 0x95130, 0x95f78, 0x5e808, 0x923f0 (`push {r4,r5,r6,lr}`; ldrd of two args).
- jump-table dispatchers on `ldrb [..,#460]` (cmp #9; ldrcc pc,[pc,r0,lsl #2]): 0x94d48, 0x957fc, 0x930ac -- need --mask-ranges.
- vldr/vcvt float getters: 0x92330, 0x92370.
- struct-by-sp arg (strb r0,[sp]; strb r1,[sp,#1]): 0x5ef18.
- `mov r4,r0` (self kept) + 3-4 call sequences: 0x945e4, 0x95190, 0x9752c, 0x91330, 0x91364.
- >0x38-byte callers (about 470 of the 626) were not shaped at all.
