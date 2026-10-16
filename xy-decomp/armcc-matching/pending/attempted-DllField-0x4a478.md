## DllField@0x4a478 (size 0x20) -- dtor stage: install vptr, call import, return this
push {r4,lr}; mov r4,r0; ldr r0,[pool vptr]; str r0,[r4]; mov r0,r4; bl; mov r0,r4; pop.
Tried: `a->vp = vt; Imp(a); return a;` and a local-vt variant. 0/8 -- armcc loads the pool vptr into r1 BEFORE push (retail: after mov r4,r0 reusing r0). Known vptr-install scheduling residue class. Siblings 0x4a458 / 0x530ec (str r1,[r0]; bl; tail b) are same family.
