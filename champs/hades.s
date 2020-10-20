.name "Hades"
.comment "The disney movie makes me look worse than I am"

		sti r1, %:init1, %1
init1:	live %1
		fork %:loop2

loop1:	sti r1, %:life1, %1
		and r1, %0, r1
life1:	live %1
		zjmp %:life1

loop2:	sti r1, %:life2, %1
		and r1, %0, r1
life2:	live %1
		zjmp %:life2
