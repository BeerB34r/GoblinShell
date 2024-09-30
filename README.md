# GoblinShell

Welcome to this here project here, the shell for goblins: GoblinShell (gosh)

## Disclaimer

I venture into this project with the goal of learning, not necessarily making a good or even functioning product. As such, i leave no guarantee the end result will be maintained, be safe to use, or anything else.
let it be known that this goblin bears no responsibility for what you may do with their foul concoctions.
*also feel free to yoink, deconstruct, reconstruct and otherwise fuck with anything in this repo. if i learned from it, maybe you can too. if you copy anything wholesale give me a shoutout though will ya? or else may your beverages always hover a few degrees above ambient temperature!*

## Formula
*3 scoops rotted brain, 5tbsp lobotomite drool, (4/3)πtsp^3 orb of scrying (prepondered is fine), programming sock-sweat to taste*

In preparation for a project at school, along with a less-than healthy interest in **sh**enaniganery (shell shenaniganery), this project is an attempt to slowly, but (hopefully) surely, create a POSIX compliant implementation of sh in C.

The overarching program structure will (probably) be as follows:
- Lexer
  - Taking a stream of characters (1-by-1, without peeking) and converting them into a stream of tokens
- Parser
  - Taking a stream of tokens and converting them into an abstract syntax tree
- Executor
  - Taking an abstract syntax tree, executing the contained instructions and processing their side-effects. calling the Lexer and Parser as needed when AST's, tokens, and characters run out.

## Installation

Should you for whatever reason want to transcribe these accursed runes unto your sacred sorcerous spellcasting device, you would be wise to follow the following instructions:
```Insert make instructions here ***when we get some***```
