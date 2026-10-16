Module: DllBattle
Offset: 0x74ff8
Size: 0x58
Match: 22/22
One-line: if f18e4(h,0,1) then f18ec(h,0,1,0); f34c(h,0,0,0); return 1 else 0, h = this+0xd38 handle.
Style: trick(redundant-local) -- pointer-to-member local `pp = &o->fld` reproduces retail's cached &fld register.
