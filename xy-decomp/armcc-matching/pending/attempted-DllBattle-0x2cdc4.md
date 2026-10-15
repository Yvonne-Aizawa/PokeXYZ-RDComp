## DllBattle@0x2cdc4 (0x38), 0x2cbfc (0x38), 0x2ce44 (0x38), 0x2c630 (0x50, probably same issue)
- Shapes: `if (vt[0x98](o)) fa(o->x /*+0x12c*/, a)`; `if (vt[0x98](o)) { o->b346 = a; tail fa(o); }`; same with b348 (a = incoming r1 int).
- Stuck at 12/14: only the vtable-slot register differs. Retail does `mov r5,r1; ldr r1,[r0,#0x98]; blx r1`; armcc always emits `ldr r2 ... blx r2` whenever an int arg is live across the virtual call.
- Tried: plain / negated / early-return forms, arg types int/char/short/unsigned/void*, local copy of the arg, static helper, function-pointer local, C++ member `virtual int v38()`, reordered x load. All 12/14.
- Float-arg siblings (0x2ca28, 0x2d5d8) match since the arg is in s0, so the issue is int-arg register allocation. Lead: some extra-arg trick (cf. 0xc9018 note) or an unknown original arg shape.
