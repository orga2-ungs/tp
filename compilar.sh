nasm -f elf calculadora.asm -o calculadora-asm.o
gcc -m32 -c calculadora-aux.c -o calculadora-aux.o
gcc -m32 -c calculadora.c -o calculadora-c.o
gcc -m32 calculadora-c.o calculadora-aux.o calculadora-asm.o -o calculadora
./calculadora