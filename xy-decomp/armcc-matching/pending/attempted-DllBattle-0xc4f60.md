Module: DllBattle
Offset: 0xc4f60
Size: 0x44
Match: 15/17

`if (g(3) == c && (ushort)g(18) == 505) post(54, 3072)`: retail compares via `sub r1,r0,#256; subs r1,r1,#249; bne` (two-step subtract), armcc emits `mvn r1,#504; cmn r0,r1`. Tried `- 256 - 249 == 0`, `- 256 == 249`, `g(18) - 505 == 0`. The retail split suggests the constant is built as 256 + 249 (macro/enum arithmetic); source form unknown.
