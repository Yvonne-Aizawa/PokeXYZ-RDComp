Module: DllBattle
Offset: 0x5daf8
Size: 0x14
Match: 5/5
One-line: bounds-checked u32 array getter: i < this->u8[+24] ? ((u32*)this)[i] : 0
Style: natural
Note: family "counted u32 array getter": identical-bytes sibling at 0x76384 (size 0x14, not separately saved; same C matches). Related byte-array variant at 0xc87a0 (`ldrbhi r0,[r0,r1]; movls r0,#6`, count at +25) is untried. Conditional-execution forms (ldrhi/movls) DID match here.
