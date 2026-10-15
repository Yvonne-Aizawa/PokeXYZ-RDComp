Module: DllSalon
Offset: 0x790
Size: 0x20
Match: 8/8
One-line: secondary-base thunk: call, store vptr post-indexed +0x24, call, return result-0x24
Style: trick(void-ptr-passthrough) -- void* callee and (char*)fn(p)-0x24 to avoid spare mov
