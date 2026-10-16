## DllBattle push-less leaf families -- leftovers (2026-10-16)

Matched this round: float splat setters (0x29abc 0x3357c 0xc5dd8), vec3-by-value setters (0x12704 0x12a30 0x12af8 0x12b24), 8-byte copy to +1840 (0x3c10c..0x3c184, 6 fns, stride 8 on source offset 164..204), ==N getters (0x3d21c 0x762f4 0x81638), `(i&1)` indexed getters (0xc7304 0xc73f4), ldrsb getters (0xc8fec 0xc900c), 0x2b9dc (const float pair via vstmia).

Not matched:
- Conditional-store chain 0x41f94 0x434ec 0x439d4 0x3c960 0x43958: `if (g.v != K) g.v = K;` with g a pool-address global, v at +0x6c. Retail loads the ADDRESS into r1 first and the constant into r0 (pool order addr, K). armcc always puts const in r0 and address in r1 (or swaps pool order, 3-4/8). Tried: plain, local k, local pointer, `old` temp, `0x5d3 != g.v`, extra unused int arg, `return 0`/`return 1` variants -- best 5/8. Real fn probably has a different arg/return shape or inlined context.
- Vec3 copy via ldm/strd (0x126ec 0x12864 0x128d4 0x12a00 0x12ae0 0x12b0c): `ldm r1,{r2,r3,ip}; str ip; strd r2,r3`. armcc emits `ldm r1,{r1-r3}; add ip; stm` for struct copy, per-field ldr/str for field copies (known field-copy residue). 2/6.
- 0x4b9cc / 0x76ce8 (orr-shift) and 0x56a10 / 0x56a38 / 0x569fc / 0x56a48 / 0x56a58: NOT standalone functions -- they are tail blocks of switch/if chains (0x4b9c8 `bic; orr; str` tail is shared by a bitfield-set function that starts at ~0x4b990; 0x56a.. are case arms of one function using live s0). Skip as chunks; the enclosing functions are the real candidates.
