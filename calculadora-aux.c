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
        // if (inputLimpio[1] == '-') {
        //     segundoOperandoSigno = -1;
        // }
        *num1 = 0;  // pensar como asignar resultado anterior
        *num2 = atoi(inputLimpio + 1);
        return;
    }

    // Caso 2: primer char es + o - Y no hay otros operadores en el resto del input
    if ((inputLimpio[0] == '+' || inputLimpio[0] == '-') && strpbrk(inputLimpio + 1, "+-*/") == NULL) {
        *operador = inputLimpio[0];
        // if (inputLimpio[1] == '-') {
        //     segundoOperandoSigno = -1;
        // }
        *num1 = 0;  // Will be replaced by previous result in the caller function
        *num2 = atoi(inputLimpio + 1);
        return;
    }

    // Caso 3: Caso general dos operandos y un operador
    // if (inputLimpio[0] == '-') {primerOperandoSigno = -1;}
    //if (inputLimpio[0] == '-' || inputLimpio[0] == '+'){ inputLimpio[0] = ' ';}
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

    // if (inputLimpio[*(operador_pos + 1)] == '-') { 
    //     segundoOperandoSigno = -1; 
    // }
        
    *num2 = atoi(operador_pos + 1);
}

// int main(){
//     int num1, num2;
//     char operador;
//     LimpiarInput("-1+2", &num1, &operador, &num2);
//     return 0;
// }