/*
 * DllBattle @ 0x60e00 (size 0x74) -- masked match 29/29, USING --mask-ranges 0x14:0x18 (jump table).
 * CASE-VALUE-TO-BODY MAPPING IS A HYPOTHESIS: the mask only proves the two case bodies, the
 * shared tail and the default-error block are byte-correct and in this order. Which of the 6 table
 * slots (0..5) point at the "r=1" body, the "pack" body, or straight to the shared return is NOT proven;
 * the slots below (0 -> 1, 1 -> pack, 2..5 -> 0) are a guess from physical body order.
 * What it does: maps a small selector to a packed code. One selector yields 1; another yields
 * 2 | (((calc(g_inst.f54, 3) + 2) << 3) & 0x1f8) (a 6-bit field + 2 tag bit, calc = import call, g_inst =
 * a relocated global object read at +0x54); the other in-range selectors return 0; out of range calls the
 * game's assert/error stub err(0,0,0) and returns 0.
 * Style: natural
 *
 * Verify:
 *   python3 xy-decomp/armcc-matching/tools/fingerprint_fn.py \
 *     DllBattle 0x60e00 0x74 xy-decomp/armcc-matching/matched/DllBattle/0x60e00.c --mask-ranges 0x14:0x18
 */
typedef struct S { char pad[0x54]; int f; } S;
extern S g_inst;
extern int calc(int, int);
extern void err(int, int, int);
int fn(int k)
{
    int r = 0;
    switch (k) {
    case 0: r = 1; break;
    case 1: r = ((calc(g_inst.f, 3) + 2) << 3 & 0x1f8) | 2; break;
    case 2: case 3: case 4: case 5: break;
    default: err(0, 0, 0); break;
    }
    return r;
}
