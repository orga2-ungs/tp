#ifndef CALCULADORA_H
#define CALCULADORA_H

void LimpiarInput(const char* input, int* num1, char* operador, int* num2);
void LimpiarEspacios(const char* input, char* output);
int LeerPregunta(int numOperacion, int *num1, char *operando, int *num2, int *operacion_continuada);
int CalcularOperacion(int Operando1, char Operador, int Operando2);
int ObtenerCodigoError();
void MostrarResultado(int numOperacion, int resultado);
void MostrarError(int codigo_error);
void MostrarAyuda();
void ImprimirCartel();
int esOperacionContinua(const char *input);

#endif // CALCULADORA_H
