#include <stdio.h>

// llamar funcion asm usando extern int suma(int a, int b);

int num1;
char operando;
int num2;

// Muestra un mensaje solicitando ingreso y se ingresa la pregunta
void LeerPregunta(){
    char input[100];
    printf("Ingrese la operacion a calcular (e.j., '10 + 10', '10 - 10', '10 * 10', '10 / 10')");
    fgets(input, sizeof(input), stdin);
    char *token = strtok(input, " ");
    int num1 = atoi(token);
    token = strtok(NULL, " ");
    char operando = token[0];
    token = strtok(NULL, " ");
    int num2 = atoi(token);
}

// Devuelve resultado de la operacion
int CalcularOperacion(int Operando1, char Operador, int Operando2){
  //test
  return 1;
}

void MostrarResultado(int resultado){
  printf(resultado);
}

int main(){
  while(true){
    LeerPregunta();
    int resultado = CalcularOperacion(num1, operando, num2);
    MostrarResultado(resultado);
  }
  return 0;
}
