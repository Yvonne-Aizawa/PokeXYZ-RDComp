Module: DllBattle
Offset: 0x9c5dc
Size: 0x28
Match: 10/10
One-line: if member at this+224 is non-null, fa(member) then tail-call fb(a) with the 2nd arg; else no-op (void)
Style: natural
Note: sibling of the 0x8b2e8 family (same source, different pad[]); found by byte scan of DllBattle .text (19 hits of the exact pattern total, 6 already matched)
