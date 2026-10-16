## DllBattle script-command handlers 0x7a444 / 0x84af0 / 0x7ade8 / 0x8711c / 0x88130 / 0x83888 / 0x85080 / 0x7b5c4 (2026-10-16, push 0x14-0x80 scan of 0x60000-0x90000)

Family: `fn(ctx, obj[, args])` handlers that read script arguments through the
three read veneers (0x504 int, 0x1ab4 vec3/word, 0x1acc float) with `rd(a, &v, 1)`.
15 of this family matched (see matched/DllBattle/0x89aac ... 0x853a0). Useful
recipes found: the pointer-table-by-script-index heads need a redundant `O *q = o;`
copy (and `int x = v;` before the member load) to get retail's r4/r5 assignment
and `[sp]`-before-member load order (trick(redundant-local)); a block-scoped
`float z = 0.0f;` makes armcc load the zero pool constant first.

Not matched:
- 0x7a444 (0x30) `rd; fnB(b, v != 0)` and 0x84af0 (0x38) `fnB(b, v != 0, v != 0)`: retail
  does `ldr r0,[sp]; cmp r0,#0; movne r1,#1; moveq r1,#0; mov r0,r4; bl` (flag computed in r0/r1
  BEFORE `mov r0,r4`, both movne/moveq); ours loads into r1, emits `mov r0,r4` early and only
  `movne r1,#1`. Tried `!!v`, `?:`, if/else, `(unsigned char)`, C++ bool param, local `f`: all 5/12.
- 0x7ade8 (0x48): `rd; rd; if (b->c1858) fnC(b->p296)`; retail has `mov r1,r4` before the `cmp`
  and `ldrne r0,[r1,#296]` (conditional ldr+bl, no branch). 1-arg form is 12/18 (missing the mov r1,r4);
  2-arg `fnC(p, b)` forces a branch (12/18 too).
- 0x8711c (0x78): vec3 initialised from pool {0.2f,-0.45f,-0.55f} via `vstmia r0,{s0-s2}` with r0=sp
  (retail `mov r5,r0` first). Brace init / member stores / inline setter all give an `ldm/stm` copy from
  the pool instead (0-1/30). Tail (mode==1 && flag -> negate z -> setter) is the matched 0x82cb4 shape.
- 0x88130 (0x70): same as matched 0x853a0 but each iteration re-checks `k < o->n[i]` and null-checks the
  object. Best 22/28: retail keeps row pointer in r6 / count in r5, ours r5/r6 swapped; tried q=o copy,
  row struct pointer, if/continue/ternary forms.
- 0x83888 / 0x85080 (0x84): two vec3 reads, then per object in the row copy them to +284/+296 (+260/+272).
  retail uses two separate dest pointers (`add r6,r2,#284; add r2,r2,#296; stm; ...; stm`) and the count in r1;
  ours uses `stmia r1!`. 20/33 best (explicit `&x->a` locals); struct copy and per-field forms worse.
- 0x7b5c4 (0x40): relaxation nop before a tail `bl` (known nop residue).
