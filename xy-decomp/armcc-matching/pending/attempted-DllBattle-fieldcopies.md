# DllBattle field-copy helpers 0x5fa8c / 0x5faa0 / 0xc9e68 / 0x747fc (agent a2b3c46c)

Targets (all leaf, `bx lr` ending):
- 0x5fa8c (0x14): ldr r2,[r1]; str r2,[r0]; ldrh r3,[r1,#4]; strh r3,[r0,#4]
- 0x5faa0 (0x14): same with ldrb/strb at +4 (not tried; same residue expected)
- 0xc9e68 (0x1c): u32 (r2), u16 (r3), u8 (ip) copy
- 0x747fc (0x14): ldr r2,[r1]; ldr r3,[r1,#4]; str r2,[r0]; str r3,[r0,#4]

Residue: every candidate gets the right opcodes but armcc reuses r1/r2 for the second
temp (`ldrh r1,[r1,#4]`) whereas retail uses a fresh r3 (and ip for the third). 3/5 and 3/7.
For 0x747fc the loads are both hoisted before the stores in retail; plain `d[0]=s[0];d[1]=s[1]`
gives ldr/str/ldr/str (2/5), and locals-first / pointer-to-unsigned / struct assignment all
collapse to `ldm r1,{r1,r2}; stm r0,{r1,r2}`.
Tried: direct casts, locals declared at top, struct member-wise copies, struct assignment,
loads-first locals. Likely the retail source inlined these from a larger function (the
temps are never recycled), so an isolated compile cannot reproduce the allocation.
