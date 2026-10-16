Module: DllBattle
Offset: 0x75050
Size: 0x54
Match: 21/21
One-line: three calls on the handle at this+0xd38 (18ec(h,0,0,0); 34c(h,0,0,1); 18f4(h,0,1,1,1)), handle reloaded each call.
Style: trick(redundant-local) -- accessed via `void **pp = &o->fld`; direct o->fld gives 2/21.
Note: siblings 0x74ff8 and 0x750a4 share the field.
