Module: DllField
Offset: 0x5aa14
Size: 0x1c
Match: masked match (all words, b/bl masked)
One-line: Getter: G(a)->+12->+28 chain, then reads the u16 at +292 (sub-struct at +288, field at +4).
Style: natural
Note: Needs a sub-struct (int; u16) at +288: a flat +292 offset makes armcc split the add differently (add #256 + ldrh #36).
