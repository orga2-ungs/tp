#!/bin/bash

# Compile test_esOperacionContinua.c
gcc -o test_esOperacionContinua test_esOperacionContinua.c ../calculadora-aux.c
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

# Compile test_LimpiarInput.c
gcc -o test_LimpiarInput test_LimpiarInput.c ../calculadora-aux.c
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