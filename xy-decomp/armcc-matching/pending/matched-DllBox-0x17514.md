Module: DllBox
Offset: 0x17514
Size: 0x30
Match: 12/12
One-line: state-step; calls 5-arg import(ctx->h, 25, &o->b, ctx->f, 0) via o->ctx, returns 38
Style: natural -- plain member accesses; using o->ctx twice (no local) gives the retail store-0-first order
Note: a local `Ctx *c` or `int z=0` loads ctx first (9/12); direct o->ctx->x in args matches.
