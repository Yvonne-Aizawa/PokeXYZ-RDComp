Module: DllField
Offset: 0xcc4d8
Size: 0x6c
Match: 27/27
One-line: State-handler: A(this->[+68],1); if Cur(sub@+184) != 103 returns 37; else Go(this), fetches a 16-byte struct via Get(sub) and passes its address to Use(obj, &v) (0xb0334); returns 1.
Style: natural -- 16-byte struct returned into a local, passed by address
