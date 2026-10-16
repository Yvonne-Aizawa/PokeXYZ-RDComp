Module: DllCommendation
Offset: 0x7dc
Size: 0x2c
Stuck: 2/11. Like 0x808 (matched) but import call takes (r0=arg2, r1=0x30, r2=0). Retail does `mov r0,r1` first then consts; armcc emits `mov r3,r1` + extra mov r0,r3 in every C shape tried (void*/int/uchar arg types, local consts, reordered/extra args). Lead: unknown; maybe arg is a re-loaded member or a wrapper inline.
