Module: DllBattle
Offset: 0xb09d0
Size: 0x40
Match: 16/16
One-line: event predicate: if (g(3) == c) { v = g(31); adjust(&v, 7); post(31, v) } (tail call 0x658d4). Callees: 0x6b91c query, 0x4b990 in-place adjust helper, 0x658d4 post veneer.
Style: natural
