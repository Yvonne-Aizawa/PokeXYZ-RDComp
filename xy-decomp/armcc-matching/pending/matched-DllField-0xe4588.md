Module: DllField
Offset: 0xe4588
Size: 0x20
Match: 8/8
One-line: returns (import(this->[8]->[20]) < 6) as an unsigned compare
Style: natural -- unsigned result compared to a constant
Note: movcc/movcs retail pair = unsigned compare; a signed `<` gives movlt/movge.
