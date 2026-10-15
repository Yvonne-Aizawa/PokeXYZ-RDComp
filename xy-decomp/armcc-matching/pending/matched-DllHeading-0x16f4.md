Module: DllHeading
Offset: 0x16f4
Size: 0x40
Match: 16/16
One-line: Sibling of @0x868/@0x8ac family: vtable passed in, tail call; forwards two child fields to handle o->q->h, returns/tail-calls with base adjusted by -4.
Style: trick(void-ptr-passthrough) -- callee declared void*, (char*)fn(p)-4 avoids a spare mov
