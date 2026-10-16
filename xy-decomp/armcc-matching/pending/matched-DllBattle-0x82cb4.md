Module: DllBattle
Offset: 0x82cb4
Size: 0x64
Match: 25/25
One-line: script-command handler: reads a vec3 and an int mode from the script context; if mode == 1 and the flag byte at +605 is set it negates the vector's z component, then passes the vector to a setter on the sub-object at +200.
Style: natural
Note: Sibling 0x8711c has the same tail but initialises the vec3 from three pool constants (0.2, -0.45, -0.55) instead of reading it; that init (vstmia from s0-s2 via r0=sp) did not reproduce, see attempted note.
