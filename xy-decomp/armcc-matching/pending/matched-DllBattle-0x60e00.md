Module: DllBattle
Offset: 0x60e00
Size: 0x74
Match: 29/29 (with --mask-ranges 0x14:0x18; case-value-to-body mapping is a hypothesis)
One-line: switch(k) 6-slot jump table: one case returns 1, one returns 2|(((calc(global.f54,3)+2)<<3)&0x1f8), others 0, out-of-range calls err(0,0,0). Pool word = address of a global OBJECT (not pointer): needs `extern S g;` (g.f) not `S *g` or armcc emits an extra ldr.
Style: natural
Note: first --mask-ranges match under matched/. Table is words 0x14..0x2c (ldrcc at +0xc, b at +0x10).
