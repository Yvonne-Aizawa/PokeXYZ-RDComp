Module: DllSalon
Offset: 0xdd0
Size: 0x2c
Match: 11/11
One-line: globals init: -1 to 64-bit slot (array+8) via strd, 0 to another 64-bit global
Style: trick(volatile-strd) -- volatile on 64-bit global only to get strd
