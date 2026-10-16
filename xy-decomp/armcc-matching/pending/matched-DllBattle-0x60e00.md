Module: DllBattle
Offset: 0x60e00
Size: 0x74
Match: 29/29 (with --mask-ranges 0x14:0x18)
One-line: switch(k) 6-slot jump table: selectors 1,3,4,5 return 1; selector 2 returns 2|(((calc(global.f54,3)+2)<<3)&0x1f8); selector 0 / >=6 call err(0,0,0) and return 0. Pool word = address of a global OBJECT (not pointer): needs `extern S g;` (g.f) not `S *g` or armcc emits an extra ldr.
Style: natural
Note: FINDING -- the jump-table slot->body mapping IS recoverable: the table words are zero in the file but each has an internal CRO relocation (header 0x128, 12B entries {seg-tag, type, last, srcseg, pad, addend}); new tools/jumptable_relocs.py <Module> <tbl_lo> <tbl_hi> prints slot -> target. Here slot0->err, slots1,3,4,5->body A, slot2->body B. So --mask-ranges matches can state the case mapping as relocation-derived fact instead of hypothesis (fold into README mask-ranges section and docs/decomp/armcc-toolchain.md).
