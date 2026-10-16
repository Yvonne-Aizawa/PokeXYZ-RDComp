## DllField@0x72534 (size 0x20; same bytes at 0x72554, 0x7dbc4 tail, 0x70f58 variant)

44-byte struct copy from src+12 into dst: `add r2,r0,#12; vldmia r2,{s0-s7}; vstmia r1,{s0-s7}; ldrd r2,[r0,#44]; ldr r0,[r0,#52]; str r0,[r1,#40]; strd r2,[r1,#32]; bx lr`.
Tried (armcc -O2 -Otime): plain struct assignment (float f[11]; float f[8]+3 floats; long long+int tail; V4 sub-structs) -> push/ldm/stm cores, 1/8; float[8] struct assign + 3 scalar float copies -> ldm/stm + vldr/vstr, 0/8. Retail uses VFP vldmia for the first 8 words and an LDRD/STRD pair for the next 2 words, which no assignment form produced. Not matched; skipped 0x72554/0x7dbc4/0x70f58 (same class).
