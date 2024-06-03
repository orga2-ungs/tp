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

void LeerPregunta() {
    char input[100];
    printf("Ingrese la operacion a calcular (e.j., '10 + 10', '10 - 10', '10 * 10', '10 / 10')\n");
    fgets(input, sizeof(input), stdin);
    LimpiarInput(input, &num1, &operando, &num2);
}

int CalcularOperacion(int Operando1, char Operador, int Operando2) {
  return recibir_operacion(Operando1, Operador, Operando2);
}

int ObtenerCodigoError(){
  return obtener_codigo_error();
}

void MostrarResultado(int resultado) {
  printf("El resultado de la operación es: %d\n", resultado);
}

int seguirOperando() {
  char input[10];
  printf("Ingrese 1 para continuar y 0 para salir\n");

  fgets(input, sizeof(input), stdin);
  char *token = strtok(input, " ");
  int respuesta = atoi(token);
  return respuesta;
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


int main() {
  int continuar = 1;
  
  while(continuar) {
    LeerPregunta();
    int resultado = CalcularOperacion(num1, operando, num2);
    int codigo_error = ObtenerCodigoError();
    if (codigo_error != 0){
     MostrarError(codigo_error);
    } else {
     MostrarResultado(resultado);
    } 
    continuar = seguirOperando();
  }
  return 0;
}
