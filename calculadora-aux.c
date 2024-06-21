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

    if (inputLimpio[0] == '-') { primerOperandoSigno = -1; }
    if (inputLimpio[0] == '+' || inputLimpio[0] == '-') { inputLimpio[0] = ' '; }

    char *operador_pos = strpbrk(inputLimpio, "+-*/");
    if (operador_pos != NULL) {
        *operador = *operador_pos;
        *operador_pos = '\0';
        
    } else {
        printf("Error: Operación no válida.\n");
        *num1 = 0;
        *operador = '+';
        *num2 = 0;
    }

    *num1 = atoi(inputLimpio) * primerOperandoSigno;
    if (inputLimpio[*(operador_pos + 1)] == '-') { segundoOperandoSigno = -1; }
    *num2 = atoi(operador_pos + 1) * segundoOperandoSigno;
}