Module: DllKisekae
Offset: 0xb6ac
Size: 0x34
Match: 13/13
One-line: destructor: free owned member +0x14 if non-null and zero it, install vtable, return this
Style: trick(ordering-local) -- hoisted member load placed before vtable pool load
Note: size includes trailing pool word. Member-load-first order matched with `void *m=o->m; o->vptr=VT;` (no vt local); sibling 0xb674 needs the opposite.
