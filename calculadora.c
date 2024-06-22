// #include <stdio.h>
#include "calculadora-aux.h"

int LeerPregunta(int numOperacion, int *num1, char *operando, int *num2, int *es_operacion_continua) {
  char input[100];
  printf("%d:input> ", numOperacion);
  fgets(input, sizeof(input), stdin);

  if(input[0] == 'q') return 0;   // salir
  if(input[0] == 'h') return 2;   // ayuda

  LimpiarInput(input, num1, operando, num2);
  *es_operacion_continua = esOperacionContinuada(input);
  return 1;
}


int main() {
    ImprimirCartel();
    int num1;
    char operando;
    int num2;
    int numOperacion = 1;
    int resultado_anterior = 0;
    int es_operacion_continua = 0;

    while (1) {
        int input = LeerPregunta(numOperacion, &num1, &operando, &num2, int &es_operacion_continua);
        if (input == 0) {
            break;  // Salir del bucle si se ingresa 'q'
        } else if (input == 2) {
            MostrarAyuda();
            continue;  // Continuar con el bucle si se ingresa 'h'
        }

        if (es_operacion_continua) {
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
