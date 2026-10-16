Module: DllBattle
Offset: 0x7af3c
Size: 0x64
Match: 25/25
One-line: script-command handler: reads an index and a flag from the script context, remaps the index through the table at +1744, then calls virtual slot 32 (+0x80) on the object at table +280 with (flag != 0).
Style: natural
Note: Index is overwritten in place (i = o->a[i]) before the second lookup; the reassigned address-taken local is why retail stores it back to the stack.
