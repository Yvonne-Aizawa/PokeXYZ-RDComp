Module: DllBattle
Offset: 0x4344c
Size: 0x2c
Match: 11/11
One-line: vt[0x80](this,a) result compared, returns r==103||r==104 (early-return spelling gives retail beq/moveq/beq shape)
Style: natural
Note: forwarded int arg puts vtable in r2; the `||` spelling instead gives cmpne/movne (the 0x42c30 sibling matched with it, this one needs the if-return form).
