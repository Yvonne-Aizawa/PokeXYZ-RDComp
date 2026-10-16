Module: DllField
Offset: 0x9e018
Size: 0x5c
Match: 23/23
One-line: Gets mgr->+12 and the animation sub-object t at mgr->+12->+72->+240->+2740; reads two floats (A, B) from mgr->+12->+28->+40 and calls C(t+420, t, A, B); returns 0.
Style: natural -- plain loads, two float-returning calls, call with float args
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
