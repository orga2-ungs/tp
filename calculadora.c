#include <stdio.h>
#include "calculadora-aux.h"

int resultado_anterior = 0;

int main() {
    ImprimirCartel();
    int num1;
    char operando;
    int num2;
    int numOperacion = 1;

    while (1) {
        int input = LeerPregunta(numOperacion, &num1, &operando, &num2);
        if (input == 0) {
            break;  // Salir del bucle si se ingresa 'q'
        } else if (input == 2) {
            MostrarAyuda();
            continue;  // Continuar con el bucle si se ingresa 'h'
        }

        if (num1 == 0 && operando != '+' && operando != '-') {
            num1 = resultado_anterior;
        }

        int resultado = CalcularOperacion(num1, operando, num2);
        int codigo_error = ObtenerCodigoError();
        if (codigo_error != 0) {
            MostrarError(codigo_error);
        } else {
            MostrarResultado(numOperacion, resultado);
        }
        resultado_anterior = resultado;
        numOperacion++;
    }

    return 0;
}
