Module: DllField
Offset: 0xc2b64
Size: 0x20
Match: 8/8
One-line: this->[152] non-null && import() != 0 bool getter (null returns the 0 loaded)
Style: natural -- loaded field reused as the result variable
Note: `if (f) return g(); return f;` style with a separate re-load does NOT match; use `v = f; if (v) v = g() != 0; return v;`.
