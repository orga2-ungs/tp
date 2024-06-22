#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculadora-aux.h"

int main() {
    char inputLimpio[100] = "-1+1";
    
    // Initialize operador_pos inside main or any other function
    char *operador_pos = strpbrk(inputLimpio+1, "+-*/");

    if (operador_pos != NULL) {
        printf("Found operator: %c\n", *operador_pos);
    } else {
        printf("No operator found.\n");
    }

    return 0;
}