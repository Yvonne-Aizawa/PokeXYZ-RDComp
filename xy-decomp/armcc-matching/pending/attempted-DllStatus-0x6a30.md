## DllStatus@0x6a30 / 0x6a00 / 0xa630 / 0xa664 (sizes 0x34/0x2c/0x2c/0x28)

- What it is: secondary-base ctor-stage family: `this->vt=VT; (this+8)->vt=VT+20; f448(this+8); return f450(this+8)-8` (0x6a00 takes vt as arg and tail-calls f310; 0xa630/0xa664 are the this-8 adjusted-thunk versions, f448(this) with r0 passthrough, f450(o+8)).
- Tried: char* cursors, struct members, hoisted `q=VT+20`, o=this-8 forms, store reorderings.
- Stuck on: 0xa664 best 7/10 (only scheduling: retail does `sub r4,r0,#8` first then `add r2,r1,#20`, ours sinks the sub after the stores); 0x6a30 retail hoists `add r1,r0,#20` before `str r0,[r4]` and `add r0,r4,#8` before the second store, best 9/13.
- Lead for next time: none yet (scheduler-order class).

## DllStatus@0x2fd8 (size 0x64) -- relaxed-only
- Relaxed match (--relax-nops) only: retail has a nop between `cmp r0,#0` and `beq`. Source: `f480(buf,this->f4); start=n; for(;;){n++; if((unsigned)n>=6){n=start;break;} if(f4b0(this->f16,n,buf))break;} f490(buf); return n;` (buf[4]). Same for 0x2e90.
