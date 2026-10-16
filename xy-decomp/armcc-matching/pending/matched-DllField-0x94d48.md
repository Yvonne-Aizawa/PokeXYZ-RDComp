Module: DllField
Offset: 0x94d48
Size: 0x6c
Match: 27/27 (with --mask-ranges 0x20:0x24; mapping recovered from relocations via tools/jumptable_relocs.py)
One-line: classifies mode byte inst()->+12->+28->+460: 0 for {0,2,6}, 1 for 8, 2 for {1,3}, err(0,0,0) then 2 for the rest. Note: cases that skip the error call and reach the shared `return 2` are written as `break` with `return 2` after the switch.
Style: natural
