# Corewar
A game for programmer-connoiseurs of assembly, bytecode & strategy.

Written in C, tested and compatible with macOS and Linux.
A school project inspired by the original Core War by Jones & Dewdney.

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
>make
>make re
>make clean
>make fclean

#### Corewar virtual machine flags
Dumps memory after N cycles then exits:
>./corewar -dump N

Prints output from "aff" (Default is to hide it):
>./corewar -a

### Extended Explanation
This project consists out of two modules, the ASM assembler and the Corewar virtual machine. ASM can take a champion's code, written in (pseudo)assembly, and convert it into (pseudo)machinecode.

Champion code looks like this example champion, *zork.s*
>.name "zork"
.comment "I'M ALIIIIVE"

>l2:		sti r1, %:live, %1
		and r1, %0, r1

>live:	live %1
		zjmp %:live

Which the ASM assembles into *zork.cor*.
When we run it without an opponent like `./corewar -dump 1000 zork.cor`,
and make it dump the core(memory arena) after 1000 cycles,
it will look like this:
![](https://i.imgur.com/UOJW6ot.png)
The code on the first line is *zork.s*' s assembly code,
converted into hexadecimal bytecode,
which can be read and executed by the *corewar* virtual machine.

The syntax on how to write a champion and how to understand and interpret bytecode is somewhat complex. For more information you can read through the assignment PDF.