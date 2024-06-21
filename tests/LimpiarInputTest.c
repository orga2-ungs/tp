#include <stdio.h>
#include <assert.h>
#include "../calculadora.h"

void test_LimpiarInput() {
    int num1, num2;
    char operador;

    // Test 1: Basic addition
    LimpiarInput("1+2", &num1, &operador, &num2);
    assert(num1 == 1);
    assert(operador == '+');
    assert(num2 == 2);

    // Test 2: Basic subtraction
    // LimpiarInput("3-2", &num1, &operador, &num2);
    // assert(num1 == 3);
    // assert(operador == '-');
    // assert(num2 == 2);

    // // Test 3: Multiplication with spaces
    // LimpiarInput(" 4 * 5 ", &num1, &operador, &num2);
    // assert(num1 == 4);
    // assert(operador == '*');
    // assert(num2 == 5);

    // // Test 4: Division
    // LimpiarInput("6/3", &num1, &operador, &num2);
    // assert(num1 == 6);
    // assert(operador == '/');
    // assert(num2 == 3);

    // // Test 5: Negative numbers
    // LimpiarInput("-1+2", &num1, &operador, &num2);
    // assert(num1 == -1);
    // assert(operador == '+');
    // assert(num2 == 2);

    // // Test 6: Both operands negative
    // LimpiarInput("-3*-2", &num1, &operador, &num2);
    // assert(num1 == -3);
    // assert(operador == '*');
    // assert(num2 == -2);

    // // Test 7: Previous output use (simulated by skipping the first number)
    // int resultado_anterior = 10;
    // LimpiarInput("+5", &num1, &operador, &num2);
    // assert(num1 == 10);
    // assert(operador == '+');
    // assert(num2 == 5);

    // // Test 8: Invalid operation
    // LimpiarInput("invalid", &num1, &operador, &num2);
    // assert(num1 == 0);
    // assert(operador == '+');
    // assert(num2 == 0);

    printf("All tests passed!\n");
}

int main() {
    test_LimpiarInput();
    return 0;
}
