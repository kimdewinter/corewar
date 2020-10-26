
.name		"Chronos"
.comment	"Time flies like and arrow, Fruit flies like a banana"

		sti r1, %:loop1, %1
loop1: 	live %1
		fork %:loop2
loop2:	sti r1, %:life1, %1
life1: 	live %42
		fork %:loop1
		ld %1, r2
		fork %:life1
loop3: 	sti r1, %:life1, %1
		xor r15, r15, r15
		zjmp %:life1
loop4:	sti r1, %:life1, %1
		xor r15, r15, r15
		zjmp %:loop2
end:
