Module: DllField
Offset: 0xe1c4c
Size: 0x2c
Match: 11/11
One-line: f11(a->first); return f79(a, a->sub.y /*+17*/, 0, 5) as a NON-tail call returning the callee r0 (twin of 0xe1fe8)
Style: trick(wider-callee-return) -- callee declared long long, caller returns (int) of it: no extra code (low word is r0) but armcc stops tail-calling (matching int/int types give b, 6/11)
Note: recipe for "bl; pop {..,pc}" retail shapes with no mov r0,#N; resolves the attempted.md DllField@0xe1c4c entry. Struct-return, char/float/ptr return types, variadic, static wrapper did NOT block the tail call; only the wider-return cast did.
