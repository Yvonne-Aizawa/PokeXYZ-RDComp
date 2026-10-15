Module: DllHeading
Offset: 0x8c58
Size: 0x40
Match: 16/16
One-line: pushes two config ints (this+16/+20) into handle this->q->h, then returns/tail-calls with sub-object (this+4) base minus 4
Style: trick(void-ptr-passthrough) -- callee declared void*, (char*)fn(p)-4 avoids a spare mov
Note: sibling of DllHeading 0x16f4/0x1738 family
