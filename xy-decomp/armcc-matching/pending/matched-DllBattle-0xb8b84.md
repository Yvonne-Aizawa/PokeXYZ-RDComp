Module: DllBattle
Offset: 0xb8b84
Size: 0x50
Match: 20/20
One-line: battle event trigger: when query(3)==c and (u8)query(4)!=31 and check(c), posts helper(66,1)
Style: trick(static-helper) -- one-use static helper taking (c, v) only so the u8 query lands in r1 (and r1,r0,#255) as retail; inline form puts it in r0
