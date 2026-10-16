Module: DllField
Offset: 0xcbc60
Size: 0x3c
Match: 15/15
One-line: State-handler step: calls an import on this->[68] (arg 1), then reads the state id of the object at this->[68]+184; if not 103 returns 36, else calls an import on this and returns 1.
Style: natural -- early return then call-and-return-1
