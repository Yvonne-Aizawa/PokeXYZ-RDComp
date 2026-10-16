Module: DllBattle
Offset: 0x89aac
Size: 0x20
Match: 8/8
One-line: script-command handler: reads one argument from the script context into a discarded local (rd(ctx,&v,1)), then forwards the battle object to a worker.
Style: natural
Note: Script-arg reader shape (veneer 0x504 = int arg fetch); sibling family of 0x86734/0x84af0/0x8638c/0x86bcc.
