# Corewar
A game for programmer-connoiseurs of assembly, bytecode & strategy.

Written in C, tested and compatible with macOS and Linux.<br/>
It is a school project inspired by the original Core War by Jones & Dewdney.

## Quick Start
- clone the repository
- compile the assembler and virtual machine with:
>make 
- assemble the champions with:
>./asm champs/kire_carpetbomber.s
>./asm champs/zork.s
- make it fight in the arena with:
>./corewar champs/kire_carpetbomber.s champs/zork.s

### Compile options
>make<br/>
>make re<br/>
>make clean<br/>
>make fclean<br/>

### Corewar virtual machine flags
Dump memory after N cycles then exits:
>./corewar -dump N

Print output from "aff" (Default is to hide it):
>./corewar -a

## Extended Explanation
This project consists out of two modules, the ASM assembler and the Corewar virtual machine.<br/>
ASM can take a champion's code, written in (pseudo)assembly, and convert it into (pseudo)machinecode.

Champion code looks like this example champion, *zork.s*
>.name "zork"<br/>
>.comment "I'M ALIIIIVE"<br/>
><br/>
>l2:	sti r1, %:live, %1<br/>
>		and r1, %0, r1<br/>
><br/>
>live:	live %1<br/>
>		zjmp %:live

It is a kind of pseudo-assembly that can contain one of about a dozen instructions.<br/>
It can range from something as simple as reporting to the *Corewar* VM that the champion is still alive,<br/>
to something as complex as cloning the champion-process("cursor") onto another position in the arena.<br/>

The ASM then assembles the *zork.s* into a *zork.cor*.<br/>
When we run it without an opponent like `./corewar -dump 1000 zork.cor`,<br/>
and make it dump the core(memory arena) after 1000 cycles,<br/>
it will look like this:<br/>
![](https://i.imgur.com/UOJW6ot.png)
The code on the first line is *zork.s*' s assembly code,<br/>
converted into *zork.cor*'s hexadecimal bytecode,<br/>
which can be read and executed by the *corewar* virtual machine.<br/>
The virtual machine reads the code from left to right, and executes it accordingly.<br/>
Code can also jump back to the left with a `zjump` command.<br/>

The syntax on how to write a champion and how to understand and interpret bytecode is somewhat complex.<br/>
For more information you can read through [the assignment PDF](https://docdro.id/9pVK3Wi "the assignment PDF").

For more information on the original Core War,<br/>
read [this](https://en.wikipedia.org/wiki/Core_War "this") wikipedia article.