Module: DllField
Offset: 0xb7e90
Size: 0x30
Match: 12/12
One-line: Secondary-base deleting-dtor stage (one of 25 identical sites): this->vptr = vt (arg r1, volatile store); if (this->m@+32) Free(this, &this->m); then tail-calls operator delete on Base(this+8) - 8.
Style: trick(volatile-store) -- vptr store via volatile pointer pins the mov r4,r0 copy ahead of the store; Reset() as inline C++ member (see 0xb1bb8.cpp)
