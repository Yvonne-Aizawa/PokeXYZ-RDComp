Module: DllZukan
Offset: 0x1f14
Size: 0x1c
Match: 7/7
One-line: If member at +0xe0 is non-null, tail-call its vtable slot 2 (byte +8) forwarding one extra arg.
Style: natural
Note: the retail uses r2 as the vtable temp, which only happens when r1 (a second incoming arg) is live and forwarded; a one-arg signature compiles to r1 and mismatches. Arg type guessed int.
