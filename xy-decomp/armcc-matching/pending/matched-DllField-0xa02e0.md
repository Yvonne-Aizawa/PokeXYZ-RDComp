Module: DllField
Offset: 0xa02e0
Size: 0x40
Match: 16/16
One-line: Member function: asks helper H1(mgr->+24, u16 field this->+68->+148); if true returns (H2() == 0), else 1.
Style: trick(volatile-load) -- the int field is read through volatile so armcc keeps ldr+uxth instead of ldrh; q/m locals only fix load order
Note: GetMgr-family caller (bl 0x16c0), file offsets 0x98000-0xa6000 sweep.
