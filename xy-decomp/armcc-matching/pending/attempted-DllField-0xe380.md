Module: DllField
Offset: 0xe380 (also 0xe3fc, 0xae58)
Size: 0x10
Match: 1/4
Tried 2026-10-15: plain zero stores, `s->a = s->b = 0`, int-returning, extra unused 2/3 params, int *p[0..1], reversed order, for-loop over int[2] (loop uses r2 for zero but emits a loop), register locals. All give mov r1,#0 (or a loop). Retail uses r2. Same residue class as 0xae58 in attempted.md.
