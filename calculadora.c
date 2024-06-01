#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// llamar funcion asm usando extern int suma(int a, int b);

extern int recibir_operacion(int operando1, char operador, int operando2);

int num1;
char operando;
int num2;

// Muestra un mensaje solicitando ingreso y se ingresa la pregunta
void LeerPregunta(){
    char input[100];
    printf("Ingrese la operacion a calcular (e.j., '10 + 10', '10 - 10', '10 * 10', '10 / 10')");
    //fgets(input, sizeof(input), stdin);
    char str[] = "10 + 10";
    char *token = strtok(str, " ");
    num1 = atoi(token);
    token = strtok(NULL, " ");
    operando = token[0];
    token = strtok(NULL, " ");
    num2 = atoi(token);
}

// Devuelve resultado de la operacion
int CalcularOperacion(int Operando1, char Operador, int Operando2) {
  int resultado = recibir_operacion(Operando1, Operador, Operando2);
  return resultado;
}

void MostrarResultado(int resultado){
  printf("EL resultado de la operación es: %d\n", resultado);
}

int main(){
  while(1){
    LeerPregunta();
    int resultado = CalcularOperacion(num1, operando, num2);
    MostrarResultado(resultado);
  }
  return 0;
}
