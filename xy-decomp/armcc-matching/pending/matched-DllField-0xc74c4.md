Module: DllField
Offset: 0xc74c4
Size: 0x28
Match: 10/10
One-line: if import check(this) true: clear words +164/+168, return byte +188; else 0
Style: natural -- early-return-0 guard then clears and byte read
Note: byte-identical sibling at 0xcac98 (also matched, same C).
