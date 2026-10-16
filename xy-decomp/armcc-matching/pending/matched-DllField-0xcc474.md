Module: DllField
Offset: 0xcc474
Size: 0x58
Match: 22/22
One-line: State-handler step: calls an import on this->[68] (arg 1); if byte +145 is set and the state id at this->[68]+184 is 104, sets bit 0x80000 in flags +168, clears +148 and returns 1; otherwise returns 38.
Style: natural -- one short-circuit condition, early return 38
