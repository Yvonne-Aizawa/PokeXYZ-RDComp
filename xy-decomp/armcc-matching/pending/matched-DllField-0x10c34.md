Module: DllField
Offset: 0x10c34
Size: 0x20
Match: 8/8
One-line: flag setter: this->sub->[84]=0, this->sub->[85]=1 (sub = *(this+68), reloaded), this[73]=1
Style: trick(redundant-local) -- Without the z/o locals armcc hoists the sub-pointer into r2 and allocates the constants differently (5-vs-8 word mismatch); the locals `z=0,o=1` reproduce retail's register choice (r3 for pointer, r2=0, r1=1).
