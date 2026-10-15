Module: DllBag
Offset: 0x13848
Size: 0x38
Match: 14/14
One-line: dtor-stage: install vtable, free buf at +0x14 if non-null, zero it, tail-call base dtor f300(this)
Style: trick(ordering-local) -- local `vt = VT` only forces the vtable pool load before the member load
