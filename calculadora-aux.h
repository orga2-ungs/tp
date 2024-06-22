#ifndef CALCULADORA_H
#define CALCULADORA_H

void LimpiarInput(const char* input, int* num1, char* operador, int* num2, int* resultado_anterior);
void LimpiarEspacios(const char* input, char* output);
int CalcularOperacion(int Operando1, char Operador, int Operando2);
int ObtenerCodigoError();
void MostrarResultado(int numOperacion, int resultado);
void MostrarError(int codigo_error);
void MostrarAyuda();
void ImprimirCartel();
int esOperacionContinuada(const char *input);

#endif // CALCULADORA_H
