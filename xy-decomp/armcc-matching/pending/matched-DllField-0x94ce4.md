Module: DllField
Offset: 0x94ce4
Size: 0x34
Match: 13/13
One-line: Fn(self): fetches the manager; if self->+72 is non-null calls V(self72->+404); then W2(mgr->+28, 1); returns 1.
Style: trick(redundant-local) -- extra local q = o ? o->+404 : o steers armcc to keep self in r4 and mgr in r5 (retail order); without it regalloc swaps r4/r5.
