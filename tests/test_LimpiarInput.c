#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
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
    int resultado_anterior = 0;
    LimpiarInput("+5", &num1, &operador, &num2, &resultado_anterior);
    assertIntEqual(resultado_anterior, num1, "Test 7: num1");
    assertCharEqual('+', operador, "Test 7: operador");
    assertIntEqual(5, num2, "Test 7: num2");

    // Test 8: Operacion invalida
    LimpiarInput("invalid", &num1, &operador, &num2, NULL);
    assertIntEqual(0, num1, "Test 8: num1");
    assertCharEqual('+', operador, "Test 8: operador");
    assertIntEqual(0, num2, "Test 8: num2");

    // Test 9: Minimo valor entero
    char minIntInput[50];
    sprintf(minIntInput, "%d+1", INT_MIN);
    LimpiarInput(minIntInput, &num1, &operador, &num2, NULL);
    assertIntEqual(INT_MIN, num1, "Test 9: num1 (min int)");
    assertCharEqual('+', operador, "Test 9: operador (min int)");
    assertIntEqual(1, num2, "Test 9: num2 (min int)");

    // Test 10: Maximo valor entero
    char maxIntInput[50];
    sprintf(maxIntInput, "%d-1", INT_MAX);
    LimpiarInput(maxIntInput, &num1, &operador, &num2, NULL);
    assertIntEqual(INT_MAX, num1, "Test 10: num1 (max int)");
    assertCharEqual('-', operador, "Test 10: operador (max int)");
    assertIntEqual(1, num2, "Test 10: num2 (max int)");

    // Test 11: Input con espacios
    LimpiarInput(" 100   +   200 ", &num1, &operador, &num2, NULL);
    assertIntEqual(100, num1, "Test 11: num1 (spaces)");
    assertCharEqual('+', operador, "Test 11: operador (spaces)");
    assertIntEqual(200, num2, "Test 11: num2 (spaces)");

    // Test 12: Operacion continuada con resultado anterior
    resultado_anterior = 0;
    LimpiarInput("+10", &num1, &operador, &num2, &resultado_anterior);
    assertIntEqual(0, num1, "Test 12: num1");
    assertCharEqual('+', operador, "Test 12: operador");
    assertIntEqual(10, num2, "Test 12: num2");

    // Test 13: Combinar signo con operador
    LimpiarInput("10+-5", &num1, &operador, &num2, NULL);
    assertIntEqual(10, num1, "Test 13: num1");
    assertCharEqual('+', operador, "Test 13: operador");
    assertIntEqual(-5, num2, "Test 13: num2");

    printf("All LimpiarInput tests finished!\n");
}

int main() {
    test_LimpiarInput();
    return 0;
}
