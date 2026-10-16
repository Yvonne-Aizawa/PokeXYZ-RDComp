Module: DllField
Offset: 0x2948c
Size: 0x44
Match: 17/17
One-line: guarded release: `t = this->t; if (t) { if (t->x) { fa(arg, t->x); t->st = -1; } else fb(0,0,0) }` (else arm is a tail call)
Style: trick(cpp-inline-member) -- body written as an inline C++ member of the pointee (`U::Go`), called on the loaded pointer; plain C gives 5/17 (armcc if-converts / reshapes the branch layout), the inline member keeps retail's layout (same mechanism as DllField@0xb1bb8). .cpp suffix -> --cpp.
Note: previously logged as "branch-vs-conditional-execution" in README unmatched list. No byte-identical siblings elsewhere in the corpus.
