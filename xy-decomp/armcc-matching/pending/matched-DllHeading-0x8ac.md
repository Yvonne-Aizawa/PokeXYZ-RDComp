Module: DllHeading
Offset: 0x8ac
Size: 0x44
Match: 17/17
One-line: Same as @0x868 but vtable from literal pool, returns the adjusted pointer.
Style: trick(void-ptr-passthrough) -- callee declared void*, (char*)fn(p)-4 avoids a spare mov
