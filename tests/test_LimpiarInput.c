#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../calculadora-aux.h"

void assertIntEqual(int expected, int actual, const char *message) {
    if (expected != actual) {
        fprintf(stderr, "Assertion failed: %s\n", message);
        fprintf(stderr, "Expected: %d, Actual: %d\n", expected, actual);
        exit(1);
    }
}

void assertCharEqual(char expected, char actual, const char *message) {
    if (expected != actual) {
        fprintf(stderr, "Assertion failed: %s\n", message);
        fprintf(stderr, "Expected: '%c', Actual: '%c'\n", expected, actual);
        exit(1);
    }
}

void test_LimpiarInput() {
    int num1, num2;
    char operador;

    // Test 1: Basic addition
    LimpiarInput("1+2", &num1, &operador, &num2, NULL);
    assertIntEqual(1, num1, "Test 1: num1");
    assertCharEqual('+', operador, "Test 1: operador");
    assertIntEqual(2, num2, "Test 1: num2");

    // Test 2: Basic subtraction
    LimpiarInput("3-2", &num1, &operador, &num2, NULL);
    assertIntEqual(3, num1, "Test 2: num1");
    assertCharEqual('-', operador, "Test 2: operador");
    assertIntEqual(2, num2, "Test 2: num2");

    // Test 3: Multiplication with spaces
    LimpiarInput(" 4 * 5 ", &num1, &operador, &num2, NULL);
    assertIntEqual(4, num1, "Test 3: num1");
    assertCharEqual('*', operador, "Test 3: operador");
    assertIntEqual(5, num2, "Test 3: num2");

    // Test 4: Division
    LimpiarInput("6/3", &num1, &operador, &num2, NULL);
    assertIntEqual(6, num1, "Test 4: num1");
    assertCharEqual('/', operador, "Test 4: operador");
    assertIntEqual(3, num2, "Test 4: num2");

    // Test 5: Negative numbers
    LimpiarInput("-1+2", &num1, &operador, &num2, NULL);
    assertIntEqual(-1, num1, "Test 5: num1");
    assertCharEqual('+', operador, "Test 5: operador");
    assertIntEqual(2, num2, "Test 5: num2");

    // Test 5B: Segundo operando negativo
    LimpiarInput("1+-2", &num1, &operador, &num2, NULL);
    assertIntEqual(1, num1, "Test 5B: num1");
    assertCharEqual('+', operador, "Test 5B: operador");
    assertIntEqual(-2, num2, "Test 5B: num2");

    // Test 6: Dos operandos negativos
    LimpiarInput("-3*-2", &num1, &operador, &num2, NULL);
    assertIntEqual(-3, num1, "Test 6: num1");
    assertCharEqual('*', operador, "Test 6: operador");
    assertIntEqual(-2, num2, "Test 6: num2");

    // Test 7: Operacion continuada
    // NOT YET IMPLEMENTED
    // int resultado_anterior = 0;
    // LimpiarInput("+5", &num1, &operador, &num2);
    // assertIntEqual(resultado_anterior, num1, "Test 7: num1");
    // assertCharEqual('+', operador, "Test 7: operador");
    // assertIntEqual(5, num2, "Test 7: num2");

    // Test 8: Operacion invalida
    LimpiarInput("invalid", &num1, &operador, &num2, NULL);
    assertIntEqual(0, num1, "Test 8: num1");
    assertCharEqual('+', operador, "Test 8: operador");
    assertIntEqual(0, num2, "Test 8: num2");

    printf("All LimpiarInput tests finished!\n");
}

int main() {
    test_LimpiarInput();
    return 0;
}
