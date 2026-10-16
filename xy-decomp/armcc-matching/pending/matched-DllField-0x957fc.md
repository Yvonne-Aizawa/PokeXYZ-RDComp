Module: DllField
Offset: 0x957fc
Size: 0x84
Match: 33/33
One-line: Maps the mode byte at mgr->+12->+28->+460 to a result: 1->1, 3->2, 4->3, 5->4, 8->err(0,0,0) then 1, anything else -> 0.
Style: natural
Note: needs --mask-ranges 0x20:0x24 (jump table); case mapping from jumptable_relocs.py
