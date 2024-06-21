#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

extern int recibir_operacion(int operando1, char operador, int operando2);
extern int obtener_codigo_error(void);

int num1;
char operando;
int num2;
int resultado_anterior = 0;

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

void LimpiarInput(const char* input, int* num1, char* operando, int* num2) {
    char inputLimpio[100];
    LimpiarEspacios(input, inputLimpio);

    int operandoNegativo = 0;

    if (inputLimpio[0] == '-') {
      operandoNegativo = 1;
      inputLimpio[0] = ' ';
    }

    char *operador_pos = strpbrk(inputLimpio, "+-*/");
    if (operador_pos != NULL) {
        *operando = *operador_pos;
        *operador_pos = '\0';
        *num1 = atoi(inputLimpio);
        *num2 = atoi(operador_pos + 1);

        if (operandoNegativo) {
          *num1 = *num1 * (-1);
        }
    } else {
        printf("Error: Operación no válida.\n");
        *num1 = 0;
        *operando = '+';
        *num2 = 0;
    }
}

int LeerPregunta(int numOperacion) {
  char input[100];
  printf("%d:input> ", numOperacion);
  fgets(input, sizeof(input), stdin);

  if(input[0] == 'q') return 0;   // salir
  if(input[0] == 'h') return 2;   // ayuda

  LimpiarInput(input, &num1, &operando, &num2);
  return 1;   // continuar con operacion
}

int CalcularOperacion(int Operando1, char Operador, int Operando2) {
  return recibir_operacion(Operando1, Operador, Operando2);
}

int ObtenerCodigoError(){
  return obtener_codigo_error();
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

int main() {
  printf("_________          .__          ___.             __   \n");
  printf("\\_   ___ \\ _____   |  |    ____ \\_ |__    ____ _/  |_ \n");
  printf("/    \\  \\/ \\__  \\  |  |  _/ ___\\ | __ \\  /  _ \\\\   __\\\n");
  printf("\\     \\____ / __ \\_|  |__\\  \\___ | \\_\\ \\(  <_> )|  |  \n");
  printf(" \\______  /(____  /|____/ \\___  >|___  / \\____/ |__|  \n");
  printf("        \\/      \\/            \\/     \\/               \n\n");
  printf("Ingrese la operacion a calcular, q para salir o h para ayuda.\n");
  int input;
  int numOperacion = 1;

  while(input = LeerPregunta(numOperacion)) {
    if (input == 2) {
      MostrarAyuda();
      continue;
    }

    if (num1 == 0 && operando != '+' && operando != '-'){
        num1 = resultado_anterior;
    }
      
    int resultado = CalcularOperacion(num1, operando, num2);
    int codigo_error = ObtenerCodigoError();
    if (codigo_error != 0) {
      MostrarError(codigo_error);
    } else {
      MostrarResultado(numOperacion, resultado);
    }
    numOperacion++;
  }
  return 0;
}
