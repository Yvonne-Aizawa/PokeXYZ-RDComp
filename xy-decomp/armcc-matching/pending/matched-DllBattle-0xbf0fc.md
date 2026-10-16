Module: DllBattle
Offset: 0xbf0fc
Size: 0x4c
Match: 19/19
One-line: *d = 0; if (g(2) == c && g(22) == 0) *d = post(22, 14) (stores the veneer's result through d).
Style: trick(redundant-local) -- the post-event arg ({K}) is held in a callee-saved register (mov r6,#{K}) hoisted above the first query; a named local reproduces that
