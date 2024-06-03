#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

extern int recibir_operacion(int operando1, char operador, int operando2);
extern int obtener_codigo_error(void);

int num1;
char operando;
int num2;

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

    char *operador_pos = strpbrk(inputLimpio, "+-*/");
    if (operador_pos != NULL) {
        *operando = *operador_pos;
        *operador_pos = '\0';
        *num1 = atoi(inputLimpio);
        *num2 = atoi(operador_pos + 1);
    } else {
        printf("Error: Operación no válida.\n");
        *num1 = 0;
        *operando = '+';
        *num2 = 0;
    }
}

int GetInput() {
  char input[100];
  printf("input> ");
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

void MostrarResultado(int resultado) {
  printf("output> %d\n", resultado);
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
  if (codigo_error == 4){
   printf("Error: resultado de la resta negativo.\n");
  }     
}

void MostrarAyuda() {
  printf("(e.j., '10 + 10', '10 - 10', '10 * 10', '10 / 10')\n");
}

int main() {
  printf("Ingrese la operacion a calcular, q para salir o h para ayuda\n");
  int input;

  while(input = GetInput()) {
    if (input == 2) {
      MostrarAyuda();
      continue;
    }
    int resultado = CalcularOperacion(num1, operando, num2);
    int codigo_error = ObtenerCodigoError();
    if (codigo_error != 0) {
      MostrarError(codigo_error);
    } else {
      MostrarResultado(resultado);
    }
  }
  return 0;
}
