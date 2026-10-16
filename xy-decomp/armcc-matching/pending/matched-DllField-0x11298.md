Module: DllField
Offset: 0x11298
Size: 0x6c
Match: 27/27
One-line: event dispatch -- if this->f7c non-null and k in {0x21,0x27,0x3c} call that object's vtable slot 0/1/2 and return 0, else return 1 (compare-chain switch, no mask-ranges). NOTE: task named 0x112a8, which is the mid-function switch; real function start is 0x11298 (push {r4,lr}; ldr r0,[r0,#0x7c]).
Style: natural
