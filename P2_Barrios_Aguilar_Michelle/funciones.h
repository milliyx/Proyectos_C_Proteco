#ifndef FUNCIONES_H
#define FUNCIONES_H

void vercomandos();
void ordenarArreglo(float arreglo[], int tamaño);
float calcularMedia(float arreglo[], int tamaño);
float calcularMediana(float arreglo[], int tamaño);
float calcularModa(float arreglo[], int tamaño);
float calcularVarianza(float arreglo[], int tamaño);
float calcularDesviacionEstandar(float arreglo[], int tamaño);
float calcularCuartil1(float arreglo[], int tamaño);
float calcularCuartil3(float arreglo[], int tamaño);
float calcularRIC(float arreglo[], int tamaño);
float calcularRango(float arreglo[], int tamaño);
float encontrarMaximo(float arreglo[], int tamaño);
float encontrarMinimo(float arreglo[], int tamaño);
void imprimir(float arreglo[], int tamaño);
void cambiarDato(float arreglo[], int tamaño, int posicion, float nuevoValor);


#endif