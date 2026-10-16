Module: DllField
Offset: 0x9aeb8
Size: 0x30
Match: 12/12
One-line: Calls helper on mgr->+12->+28->*->+0x1aeec then returns the low 4 bits of the halfword at +4 of it.
Style: trick(volatile-load) -- halfword read through volatile so armcc keeps ldrh+and #15 (sibling of 0x9af9c)
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
