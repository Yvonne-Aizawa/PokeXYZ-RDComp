Module: DllBattle
Offset: 0xbd2dc
Size: 0x60
Match: 15/24

`if (g(3) == c) { v = (ushort)g(18); if (h(v, 30) != 0 || v == 26 || v == 136) post(50, K); }` -- retail does `cmp r4,#26; beq T; cmp r4,#136; bne end` with T the shared tail-call block; armcc fuses to `cmpne r4,#136; bne` and orders the tail call differently. Tried negated early return, if/else with a duplicated post call, `||` forms. The retail layout suggests the post call is reachable from two separate branches.
