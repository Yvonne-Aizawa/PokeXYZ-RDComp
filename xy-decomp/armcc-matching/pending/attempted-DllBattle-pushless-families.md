# DllBattle push-less leaf scan (2026-10-16) -- family shapes + unmatched siblings

Scan recipe: disassemble .text (0x180..+0xcd1fc), cut chunks at push/pop/b/bl/bx-lr/.word, keep
chunks ending in `bx lr`, 3..24 words, not already in matched/. 884 chunks; ~590 are
`<pool junk>; mov r1,#N; str r1,[r0]; ldr r0,[pc]; bx lr` (vtable-less "return singleton" stubs at
0xa4xxx-0xa8xxx, 0xbef08.. -- junk-prefix chunks, real functions start at the mov; NOT tried).

Matched this round: 0x4b81c 0x4bf14 0x544ec (ldr,ldr,ldrb chain), 0x4b8d4 0xc7580 (ldr,ldrb),
0x76e20 0x9e638 (pack `(a<<3&0x1f8)|3`), 0x797b0 0x704ac (two-field packs, trick(redundant-local):
named mask locals m1/m2 + split `v |= tag` reproduce retail's hoisted constants; plain expression
loads constants interleaved = 1-2/N).

Untried families (offsets are chunk starts; leading pool-junk words may shift the true start):
- vstr s0 x3 [r0,#64/68/72] + strb r2,[r0,#76]: 0x29abc 0x3357c 0xc5dd8 (float-vec3 zero/init setter, s0 is an incoming float arg)
- strb from vstmia (vec3 copy to +4 with flag +76): 0x12704 0x12a30 0x12af8 0x12b24; ldm/strd variants 0x126ec 0x12864 0x128d4 0x12a00 0x12ae0 0x12b0c
- 8-byte copy to +1840 with strb +1836: 0x3c10c 0x3c124 0x3c13c 0x3c154 0x3c16c 0x3c184
- ldr/ldr/ldr/cmp/strne (conditional store): 0x41f94 0x434ec 0x439d4 (+ mov variants 0x3c960 0x43958)
- ldrb cmp #N moveq/movne (==N getter): 0x3d21c(!=1 ->#7) 0x762f4(==3,+1684) 0x81638(==6,+16) -- eq/ne boolean getters, probably `return v==N`
- cmp r1,#0 moveq/movne (bool not): 0x366c 0x4a614(r0); 0x71434/0x9e5a0 conditional-movne leaves
- ands/movne mask-test getters (known residue class, `bit-test`): 0x78be4 0x795f8 (+32->+72 &7) 0xc79d0
- indexed ldr `(i&1)*4` +2840/2844: 0xc7304 0xc73f4 ; ldrsb at 2048+116/117: 0xc8fec 0xc900c
- orr-shift-or setters `r1 = r2 | r1<<N; *p = r1`: 0x4b9cc (<<9), 0x76ce8 (<<25)
- vldr/vstmia float pair copies: 0x56a10 0x56a48 0x569fc 0x56a38 0x56a58 0x2b9dc
