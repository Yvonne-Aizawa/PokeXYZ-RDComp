# Tool: --pool-pad (2026-10-16)

- `tools/fingerprint_fn.py --pool-pad`: fallback compare tolerating 1-2 all-zero target pad words (start/end/code-pool boundary), masking only literal ldr/vldr displacements, requiring same pool words/order; prints `*** POOL-PAD MATCH ***`, exit 3. Default behaviour unchanged. Self-test `tools/test_pool_pad.py` (12 checks, all pass).
- New dir `poolpad/` (not counted in headline totals): DllBattle@0x71a2c (0x2c), DllField@0xb6844 and @0xb76c8 (0x5c each; Style trick(declaration-order)).
- README + docs/decomp/armcc-toolchain.md already updated in this branch (sections dated 2026-10-16). attempted.md entries for these three functions can be marked resolved-as-POOL-PAD.

## Policy question for the user
Keep POOL-PAD as its own tier (`poolpad/`, current) or promote to `matched/` with the `Verify: ... --pool-pad` header line? Recommendation: promote, since the pad is a pure link-layout fact like branch immediates and the same pool words are still enforced; until decided the dir stays out of the total (heatmap does not scan it).
