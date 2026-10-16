## DllBattle event predicates saving c (r2) then d (r3) in that order -- 0xbc89c 0xbe5b8 0xbef24 0xc282c 0xc18d8 0xc3cd0 0xc44ac 0xc1ff8

Module: DllBattle
Offset: 0xc282c (representative)
Size: 0x24
Match: 7/9

`if (g(2) == c) *d = 0;` -- body correct, retail prologue is `mov r4,r2; mov r5,r3`, armcc emits `mov r5,r3; mov r4,r2`. Other members: 0xbc89c `if (g(2)==c && g(83)==0) *d = post(83,1)` (14/16), 0xc3cd0 `if (g(2)==c && d[3]) post(54,2048)` (13/15). Tried d as short*/char*, early-return form, local alias of d. Same family as the b+c residue (attempted-DllBattle-bc-saved-family.md); armcc's d-first order is what the natural source gives for the matched 0xc489c / 0xc1e40 / 0xbf0b0 shapes.
