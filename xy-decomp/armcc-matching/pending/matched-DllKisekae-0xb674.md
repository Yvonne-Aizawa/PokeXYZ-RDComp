Module: DllKisekae
Offset: 0xb674
Size: 0x38
Match: 14/14
One-line: destructor: install vtable, free owned member +0x14 if non-null and zero it, tail-call base dtor
Style: trick(ordering-local) -- vt local + hoisted member load fix pool/member load order
Note: vtable pool load precedes member load here; needs `void *vt=VT; void *m=o->m;`
