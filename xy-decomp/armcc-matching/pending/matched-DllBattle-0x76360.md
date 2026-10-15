Module: DllBattle
Offset: 0x76360
Size: 0x24
Match: 9/9
One-line: zero-init 25-byte struct (six u32 zero stores + zero u8 at +24)
Style: natural
Note: family "zero-init struct" siblings (unattempted, untried C = same pattern of literal zero stores): 0xc5c18 (size 0x28, strb +24/+25 first then six u32... 8 stores), 0x71840 (0x10, u32 + u16), 0xc9e58 (0x10, u32 + u8@4), 0xc9e30 (0x28, two functions: u32,u32,u16 and u32,u32,u32). Other untried push-less families from the scan: field copies 0x5fa8c (u32+u16), 0x5faa0 (u32+u8), 0xc9e68 (u32+u16+u8), 0x747fc (2x u32); bit-test getters 0x4aa9c / 0x51c28 (`ldrb [27]; and #64; lsr #6`); bitset-test 0x4c818 / 0x4ca4c (bit index in r1, bytes at +0x166/+0x169); add-offset getters 0x1cc04, 0xc86c8, 0xc8754, 0x4c278, 0x4c7fc (`add r0,r0,#256; ldrh [N]`); bit-pack builders 0x704ac, 0x76e20, 0x797b0.
