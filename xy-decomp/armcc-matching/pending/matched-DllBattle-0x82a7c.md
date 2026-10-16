Module: DllBattle
Offset: 0x82a7c
Size: 0x60
Match: 24/24
One-line: script-command handler: reads an int and a float; if the indexed slot of the pointer table at +1044 is non-null, calls a worker with (slot->+8, int, (float)(unsigned)float) -- the float is truncated to an unsigned integer value and converted back.
Style: trick(redundant-local) -- `q = o` and `x = v` copies only to fix register assignment and the [sp]-before-member load order (22/24 without x).
Note: Sibling of 0x80820.
