Module: DllField
Offset: 0x930ac
Size: 0xd8
Match: 54/54
One-line: Script handler: fetches the mode byte block at mgr->+12->+28->+460, asks F(self,args[1],&out) for an output record, then writes out[0] from the mode (0/2/6 -> 0; 4/5/8 -> err + 1; 1/3 -> the mode itself; else err + mode) and copies the u32 at +4 and bytes +8/+9 into out[1..3]; returns 0.
Style: natural
Note: needs --mask-ranges 0x38:0x24 (jump table); case mapping from jumptable_relocs.py
