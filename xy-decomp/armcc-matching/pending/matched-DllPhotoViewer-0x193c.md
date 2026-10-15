Module: DllPhotoViewer
Offset: 0x193c
Size: 0x38
Match: 14/14
One-line: dtor-stage: install vtable, free buf at +0x14 if non-null, zero it, tail-call base f218(this)
Style: trick(ordering-local) -- local vt = VT forces the vtable pool load ahead of the member load
Note: retail-ordering dtor retry (2026-10-15); vtable declared as extern char VT[], size includes trailing pool word.
