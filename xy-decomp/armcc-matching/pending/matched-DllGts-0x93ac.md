Module: DllGts
Offset: 0x93ac
Size: 0x34
Match: 13/13
One-line: if fn(this) returns this->r@0x1c; else if byte@4 set: this->r@0x14=6, return 1; else return 2
Style: natural
Note: easy leftover in DllGts: 0x7c74 (size 0x18) = fn(this->c@0x20,1); return 4 masks 6/6 (unsaved, over budget).
