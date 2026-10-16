Module: DllBattle
Offset: 0x750a4
Size: 0x84
Match: 33/33
One-line: handle (this+0xd38) call pair, then converts an 8-byte {int,int} table entry [i] to a float vec (3-float array) and passes it to a third call.
Style: trick(redundant-local) -- `void **pp = &o->fld` caches the member address like retail.
Note: the vec must be float v[3] (z unused) to land at sp+4; float v[2] puts it at sp+8. Size includes the trailing table-address pool word.
