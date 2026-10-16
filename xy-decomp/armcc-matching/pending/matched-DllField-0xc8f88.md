Module: DllField
Offset: 0xc8f88
Size: 0x3c
Match: 15/15
One-line: state-handler step: import(this[100],this[180]) == 0 -> 50; else second import, state[180]=13, returns byte this[189]
Style: trick(ordering-local) -- byte read held in a local before the state store, else armcc emits the ldrb after the str
