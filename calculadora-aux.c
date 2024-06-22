#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculadora-aux.h"

void LimpiarEspacios(const char* input, char* output) {
    const char *p = input;
    char *q = output;
    while (*p != '\0') {
        if (!isspace(*p)) {
            *q++ = *p;
        }
        p++;
    }
    *q = '\0';
}

void LimpiarInput(const char* input, int* num1, char* operador, int* num2) {
    char inputLimpio[100];
    LimpiarEspacios(input, inputLimpio);

    int primerOperandoSigno = 1;
    int segundoOperandoSigno = 1;

    // Caso 1: primer char es * o /, es operacion continuada
    if (inputLimpio[0] == '*' || inputLimpio[0] == '/') {
        *operador = inputLimpio[0];
        *num1 = 0;  // pensar como asignar resultado anterior
        *num2 = atoi(inputLimpio + 1);
        return;
    }

    // Caso 2: primer char es + o - Y no hay otros operadores en el resto del input
    if ((inputLimpio[0] == '+' || inputLimpio[0] == '-') && strpbrk(inputLimpio + 1, "+-*/") == NULL) {
        *operador = inputLimpio[0];
        *num1 = 0;  // Will be replaced by previous result in the caller function
        *num2 = atoi(inputLimpio + 1);
        return;
    }

    // Caso 3: Caso general dos operandos y un operador
    char *operador_pos = strpbrk(inputLimpio + 1, "+-*/");
    if(operador_pos == NULL){
        printf("Error: Operacion no valida.\n");
        *num1 = 0;
        *operador = '+';
        *num2 = 0;
        return;
    }
    *operador = *operador_pos;
    *operador_pos = '\0';
    *num1 = atoi(inputLimpio); // acabo de descubrir que atoi considera signos
    *num2 = atoi(operador_pos + 1);
}

int LeerPregunta(int numOperacion, int *num1, char *operando, int *num2) {
  char input[100];
  printf("%d:input> ", numOperacion);
  fgets(input, sizeof(input), stdin);

  if(input[0] == 'q') return 0;   // salir
  if(input[0] == 'h') return 2;   // ayuda

  LimpiarInput(input, num1, operando, num2);
  return 1;   // continuar con operacion
}

int CalcularOperacion(int Operando1, char Operador, int Operando2) {
  return 1;//recibir_operacion(Operando1, Operador, Operando2);
}

int ObtenerCodigoError(){
  return 1;//obtener_codigo_error();
}

void MostrarResultado(int numOperacion, int resultado) {
  printf("%d:output> %d\n", numOperacion, resultado);
  resultado_anterior = resultado;
}

void MostrarError(int codigo_error){
  if (codigo_error == 1){
   printf("Error: division por cero.\n");
  }
  if (codigo_error == 2){
   printf("Error: operacion invalida.\n");
  }     
  if (codigo_error == 3){
   printf("Error: resultado de la division no es un entero\n");
  }  
}

void MostrarAyuda() {
  printf("\nUSO\nIngresar dos operandos separados por un operador.\n");
  printf("Por e.j., '10 + 10', '10 - 10', '10 * 10', '10 / 10'.\n");
  printf("Se permiten números negativos.\n");
  printf("Por e.j., '-10 + -10', '-10 - -10', '-10 * -10', '-10 / -10'.\n");
  printf("No se permiten más de dos operandos ni números de punto flotante.\n\n");
  printf("Para usar el resultado anterior como primer operando, ingrese la operación sin el primer operando.\n");
  printf("Por e.j., si el resultado anterior es 10, puede ingresar '+ 5' para calcular '10 + 5'.\n\n");
}

void ImprimirCartel(){
  printf("_________          .__          ___.             __   \n");
  printf("\\_   ___ \\ _____   |  |    ____ \\_ |__    ____ _/  |_ \n");
  printf("/    \\  \\/ \\__  \\  |  |  _/ ___\\ | __ \\  /  _ \\\\   __\\\n");
  printf("\\     \\____ / __ \\_|  |__\\  \\___ | \\_\\ \\(  <_> )|  |  \n");
  printf(" \\______  /(____  /|____/ \\___  >|___  / \\____/ |__|  \n");
  printf("        \\/      \\/            \\/     \\/               \n\n");
  printf("Ingrese la operacion a calcular, q para salir o h para ayuda.\n");
}