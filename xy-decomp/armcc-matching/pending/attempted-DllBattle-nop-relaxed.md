Module: DllBattle
Offset: 0xc2a58 (siblings 0xc2afc 0xc2b88 0xc4b58 0xc556c; also 0xc23f4, 0xbce68/0xc1cb8/0xc4618 two-block variants)
Size: 0x54
Match: relaxed-only

`if (g(4)==c && (ushort)g(30) != K) post(66,1) else *d = 0`-style predicates whose retail bytes carry the post-link branch-relaxation `nop nop` pair before the final `b`. Only matchable with --relax-nops, which does not count as a masked match, so none were saved.
