#!/bin/bash

# Compile NASM assembly code
nasm -f elf32 ../calculadora.asm -o calculadora-asm.o
if [ $? -ne 0 ]; then
    echo "NASM compilation failed for calculadora.asm"
    exit 1
fi

# Compile calculadora-aux.c with reference to calculadora-asm.o
gcc -m32 -c ../calculadora-aux.c -o calculadora-aux.o
if [ $? -ne 0 ]; then
    echo "Compilation failed for calculadora-aux.c"
    exit 1
fi

# Link calculadora-aux.o with calculadora-asm.o to form a complete calculadora-aux.o
ld -m elf_i386 -r calculadora-aux.o calculadora-asm.o -o combined-calculadora-aux.o
if [ $? -ne 0 ]; then
    echo "Linking failed for calculadora-aux.o and calculadora-asm.o"
    exit 1
fi

# Compile and link test_esOperacionContinua with the combined object file
gcc -m32 -o test_esOperacionContinua test_esOperacionContinua.c combined-calculadora-aux.o
if [ $? -ne 0 ]; then
    echo "Compilation failed for test_esOperacionContinua.c"
    exit 1
fi

# Run test_esOperacionContinua
./test_esOperacionContinua
if [ $? -ne 0 ]; then
    echo "Tests failed in test_esOperacionContinua"
    exit 1
fi

# Compile and link test_LimpiarInput with the combined object file
gcc -m32 -o test_LimpiarInput test_LimpiarInput.c combined-calculadora-aux.o
if [ $? -ne 0 ]; then
    echo "Compilation failed for test_LimpiarInput.c"
    exit 1
fi

# Run test_LimpiarInput
./test_LimpiarInput
if [ $? -ne 0 ]; then
    echo "Tests failed in test_LimpiarInput"
    exit 1
fi

echo "All tests passed!"