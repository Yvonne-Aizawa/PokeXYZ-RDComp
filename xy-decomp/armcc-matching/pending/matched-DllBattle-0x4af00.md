Module: DllBattle
Offset: 0x4af00
Size: 0x30
Match: 12/12
One-line: range-check assert (x>=2 -> fnA(0,0,0)) then return x==0
Style: natural
Note: same "bounds assert" prologue (cmp #N; bcc; mov r2,#0; mov r1,r2; mov r0,r2; bl) appears in 0x4bb2c / 0x4cf8c (not matched, reg-alloc residue).
