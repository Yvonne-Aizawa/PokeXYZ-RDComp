Module: DllHeading
Offset: 0x1738
Size: 0x44
Match: 17/17
One-line: Sibling of @0x868/@0x8ac family: vtable from literal pool; forwards two child fields to handle o->q->h, returns/tail-calls with base adjusted by -4.
Style: trick(void-ptr-passthrough) -- callee declared void*, (char*)fn(p)-4 avoids a spare mov
