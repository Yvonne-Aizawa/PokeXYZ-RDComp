Module: DllBattle
Offset: 0x7efb4
Size: 0x84
Match: 33/33
One-line: script-command handler: reads two float arguments, substitutes defaults (16.0f / 6000.0f) for zero values, and applies them to the sub-object at +496 via two setters.
Style: trick(redundant-local) -- named zero local z only to make armcc load the 0.0f pool constant before the first stack float (plain `x == 0.0f` swaps the two vldr).
Note: Likely min/max-distance (near/far) style arguments; pool = 0.0f, 16.0f, 6000.0f.
