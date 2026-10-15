## DllBag@0x10844 (size 0x58) and DllBag@0x1089c (size 0x54)

0x10844: sibling of 0x7330/0xc508 but fnB(this) is called first (before the b==1
test), `b = this->q->b` (q @+0x44) loaded into r6 before the call. Best: 15/22 with
the sibling `struct Sub *s = &this->sub` style where the true branch uses s->p->h,
s->v etc (prologue + else branch match; true branch uses [r4]/[r4,#48]!). Retail
true branch instead uses `ldr r3,[r5,#8]` (this, not s), hoists mov r1,#0/r2,#75/r0,#1,
then strh/str [r5,#56]!/str [r5,#8]. Every variant that writes the true branch via
`this` flips register allocation (this->r4, s->r6/r5, b->r5): 8-9/22. Needs a source
form where s (=this+8) stays live in r4 but the true branch addresses via this.

0x1089c: `fnC(this->y->ctx, this+0x50, 5, 0, 0, 0)` (two stack zeros); this->st=55;
this->y->flag(+0x2c)=1; return 4. Best 14/21: tail differs: retail does
`ldr r0,[r4,#76]; mov r1,#1; mov r2,#4; strb r1,[r0,#44]; mov r0,r2` (return value
4 lives in r2, hoisted before the store); mine emits ldr r1/mov r0,#1/strb/mov r0,#4.
`int r=4;` variant spills to r5 (8/21). Unsolved.
