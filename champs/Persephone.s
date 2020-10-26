.name		"Persephone"
.comment	"plants and shit"

sti r1, %:loop1, %1
fork %:loop1
sti r1, %:setup1, %1
setup1: live %1
fork %:loop2
loop1: live %504
ld %1, r15
zjmp %:loop1
loop2: live %505
ld %2, r14
zjmp %:loop
