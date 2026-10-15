Module: DllField
Offset: 0x412d0
Size: 0xc
Match: 3/3
One-line: setter storing two int args at this+28/+32 (add r0,#28; stm). Family shape: same as 0x76ec; identical-byte unmatched siblings at 0x1959c 0x41f24 0x42f7c 0x444f0 0x4344c 0x9888 (+28) and 0x417f8 (+44) -- same C with the pad size changed.
Style: natural
Note: found by a push-less-leaf scan of DllField .text (split at bx lr/branches; ~250 chunks with >2 insns, unmatched). Scan script lives only in scratchpad; recipe: objdump -D whole .text, cut chunks at push/pop/b/bl/bx, keep chunks ending `bx lr` with no branches, strip leading literal-pool junk.
