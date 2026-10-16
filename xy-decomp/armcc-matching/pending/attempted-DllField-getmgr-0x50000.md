## DllField GetMgr (0x16c0) callers 0x50000-0x70000 -- residues (round 2026-10-16-b, agent ab622)

Cracked this round: `uxth`/`and #255` narrowing of a loaded word is produced by reading the argument through a
`volatile int *` (`unsigned short x = b[1];` -> `ldr r0,[r1,#4]; uxth r4,r0`; plain access gives `ldrh`/`ldrb`).
Style: trick(volatile). See the matched-DllField-0x59270 family. `b[1] & 255` also needs the volatile read AND the load
placed after the GetMgr call when retail does `mov r4,r1; bl; ldr r1,[r4,#4]` (0x5e068). Plain `b[1], b[2]` gives the
retail `add r4,r4,#4; ldm r4,{r1,r2}` (0x5c580).

Not matched:
- `ldrd r0,[r1,#4]` + two uxth/and (0x589fc, 0x58af4, 0x5ab58, 0x5a9e8, 0x5e808, 0x5ef18 struct-by-stack): best 1/11. `unsigned long long v` loads
  give `ldrh,ldrh` (or `add r0,r1,#4; ldrd r2,[r0]` with a volatile long long: wrong pair and extra add); `__packed` long long /
  struct, `struct{unsigned a,b;}` copy (volatile or not) never emit `ldrd r0,[r1,#4]`.
- 0x5e098 / 0x5e030 (`ldm r4,{r1,r2}` then `and r1,r1,#255`): armcc folds the `&255` into `ldrb`; volatile struct copy gives two ldr.
  Best 5/14 (non-volatile) / 11/14 (volatile struct, ldr,ldr instead of ldm).
- 0x588b0: retail `uxth r1,r4` sits AFTER the 4-load chain; armcc hoists it before (8/12, also with the chain in a local).
- 0x5cfc8 (sxth, same scheduling: `mov r1,r4` after the chain; 8/11).
- 0x5aa34 (`ldm r1,{r0,r5}; and r4,r0,#255`; 5/9: struct copy gives ldrb+ldr).
- 0x5bb78: `r = (r != -1)` always compiles to `adds r0,r0,#1; movne r0,#1` instead of retail `cmn r0,#1; moveq r0,#0; movne r0,#1`
  (12/16; tried ?:, early return, if/else).
- Not tried: 0x5bdf4.. (18-28-word bodies), jump-table dispatchers, vldr getters, 0x5c938/0x5d204 (bounds check + error call 0x200).
