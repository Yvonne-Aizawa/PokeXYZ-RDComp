Module: DllBattle (also DllPokeList 0xa50 / 0xaac)
Offset: 0x3038 (size 0x6c)
Match: 16/27
Tried (2026-10-15 retry): vt local + virtual-call release. Retail has a post-link nop word at 0x308c (unmaskable without --relax-nops, so never a pure masked match) and loads the pool into r1 before push; ours loads after push.
DllPokeList 0xa50 likewise has a nop word at 0xa94 (between the two bl) -- relaxed-only at best; not retried beyond prior 12/20.
