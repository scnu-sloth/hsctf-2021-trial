mov r1, 0
mov [r1], xxx
inc r1
...

mov r1, 0
mov r2, getchar()
push r2
inc r1
cmp r1, 32
jnz 7

mov r1, 0
add [r1], 64
inc r1
cmp r1, 32
jnz 14

mov r1, 64
pop r2
sub r1, 1
mov [r1], r2
cmp r1, 32
jnz 20

mov r1, 32
mov r2, r1
sub r2, 32
xor [r1], r2
inc r1
cmp r1, 64
jnz 27

mov r1, 32
add [r1], 32
inc r1
cmp r1, 64
jnz 35

mov r1, 0
mov r2, 32
xor [r1], 0xCC
cmp [r1], [r2]
jnz 51
inc r1
inc r2
cmp r1, 32
jnz 42
puts("Right!")
jmp 52
puts("Wrong!")
exit