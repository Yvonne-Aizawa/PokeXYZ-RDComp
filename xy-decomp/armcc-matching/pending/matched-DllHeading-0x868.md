Module: DllHeading
Offset: 0x868
Size: 0x40
Match: 16/16
One-line: Stores passed-in vtable, forwards two field values to the handle at o->q->h, then tail-calls with the adjusted base pointer.
Style: trick(void-ptr-passthrough) -- callee returns void*, result offset (char*)fn(p)-4 then tail-called
