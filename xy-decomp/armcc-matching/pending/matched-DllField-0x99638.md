Module: DllField
Offset: 0x99638
Size: 0x34
Match: 13/13
One-line: Script-command handler: calls sibling helper on mgr->+12->+28->*->+0x129a8 with sign-extended s16 args[1]; returns 0.
Style: trick(volatile-load) -- args is volatile int* so armcc keeps ldr+sxth instead of ldrsh
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
