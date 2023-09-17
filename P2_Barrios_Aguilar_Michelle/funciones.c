#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "funciones.h"

// Función para imprimir la tabla de comandos
void vercomandos()
{
    printf("\n\t|   COMANDO   |                  FUNCION                                          |\t");
    printf("\n\t|---------------------------------------------------------------------------------|\t");
    printf("\n\t|    ayuda    | Imprime nuevamente la tabla de ayuda.                             |\t");
    printf("\n\t|    salir    | Termina el programa.                                              |\t");
    printf("\n\t|      n      | Cambiar la cantidad de datos (por defec, n=100).                  |\t");
    printf("\n\t|    datos    | Cambiar todos los datos con los que usted desea trabajar.         |\t");
    printf("\n\t|   cambiar   | Cambiar un dato en la posicion especifica.                        |\t");
    printf("\n\t|   imprimir  | Imprimir los datos ordenados con los que se trabajan actualmente. |\t");
    printf("\n\t|    media    | Calcular la media aritmetica del conjunto de datos                |\t");
    printf("\n\t|   mediana   | Calcular la mediana del conjunto de datos.                        |\t");
    printf("\n\t|     moda    | Calcular la moda del conjunto de datos.                           |\t");
    printf("\n\t|   varianza  | Calcular la varianza del conjunto de datos.                       |\t");
    printf("\n\t|   desvest   | Calcular la desviacion estandar del conjunto de datos.            |\t");
    printf("\n\t|  cuartil_1  | Calcular el primer cuartil del conjunto de datos.                 |\t");
    printf("\n\t|  cuartil_3  | Calcular el tercer cuartil del conjunto de datos.                 |\t");
    printf("\n\t|     ric     | Calcular el rango intercuartilado del conjunto de datos.          |\t");
    printf("\n\t|    rango    | Calcular el rango del conjunto de datos.                          |\t");
    printf("\n\t|    todos    | Calcular todas las medidas del sobre el conjunto de datos.        |\t");
}

// Función que implementa un algoritmo de ordenamiento llamado BubbleSort que sirve para ordenar los elementos de un arreglo de menor a mayor
// tomado de mi clase de EDA II con el profesor Edgar Tista
void ordenarArreglo(float arreglo[], int tamaño)
{
    for (int i = 0; i < tamaño - 1; i++)
    {
        for (int j = 0; j < tamaño - i - 1; j++)
        {
            if (arreglo[j] > arreglo[j + 1])
            {
                float temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}

// Función para calcular la media de un arreglo
float calcularMedia(float arreglo[], int tamaño)
{
    float suma = 0;
    for (int i = 0; i < tamaño; i++)
    {
        suma += arreglo[i];
    }
    return suma / tamaño;
}

// Función para calcular la mediana de un arreglo en la que usamos la función de ordenamiento de burbuja, ya que la mediana es el valor que se encuentra a la mitad de los datos del arreglo o en su defecto, el promedio de los dos valores centrales del arreglo
float calcularMediana(float arreglo[], int tamaño)
{
    ordenarArreglo(arreglo, tamaño);

    float mediana;
    //comprueba si el tamaño es par o impar mediante una condicional
    //la mejor manera de hacerlo es mediante el modulo de 2, ya que si el tamaño es par, el modulo de 2 es 0, y si es impar, el modulo de 2 es 1
    if (tamaño % 2 == 0)
    {
        int i = tamaño / 2;
        mediana = (arreglo[i - 1] + arreglo[i]) / 2;
    }
    else
    {
        int i = (tamaño + 1) / 2;
        mediana = arreglo[i - 1];
    }

    return mediana;
}

// Función para calcular la moda de un arreglo
// La moda es el valor o los valoes que más se repite en un conjunto de datos por lo que para calcularla, primero debemos encontrar la frecuencia de cada dato en el arreglo y luego encontrar el dato que tenga la frecuencia más alta, si hay más de un dato con la frecuencia más alta, entonces hay más de una moda
//Como se trabaja con arreglos tuve que acudir a una investigación rapida a chatgpt ya que no se me ocurria nada para este comando,  le pregunté para ver que podia hacer a partir del codigo que ya tenia y encontre este codigo que me ayudo a resolver el problema. Lo explico a continuación:
//Se inicializa un arreglo de frecuencias que tiene el mismo tamaño que el arreglo que el usuario redimensionó, este arreglo de frecuencias está incializado en 0 ya que el contenido se usa para almacenar las frecuencias mediante el recorrido el arreglo original y se va comparando cada dato con todos los demas datos del arreglo, si el dato se repite, entonces se aumenta en 1 la frecuencia del dato en el arreglo de frecuencias. Despues de este proceso se busca la frecuencia más alta en el arreglo de frecuencias y se guarda en una variable llamada modaFrecuencia
//Despues de esto, se crea un arreglo de modas que tiene el mismo tamaño que el arreglo original, este arreglo de modas se inicializa en 0 y se usa para almacenar los datos que tienen la frecuencia más alta, para esto se recorre el arreglo de frecuencias y se compara cada frecuencia con la frecuencia más alta, si la frecuencia es igual a la frecuencia más alta, entonces se guarda el dato en el arreglo de modas y se aumenta en 1 el contador de modas. Finalmente, se imprime el arreglo de modas, si el contador de modas es mayor a 0, entonces se imprime el primer dato del arreglo de modas, si no, se imprime un mensaje de que no hay moda

float calcularModa(float arreglo[], int tamaño)
{
    // Inicializar un arreglo de frecuencias
    int frecuencias[tamaño];
    for (int i = 0; i < tamaño; i++)
    {
        frecuencias[i] = 0;
    }
    // Calcular las frecuencias
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = i; j < tamaño; j++)
        {
            if (arreglo[i] == arreglo[j])
            {
                frecuencias[i]++;
            }
        }
    }
    // Encontrar la frecuencia más alta
    int modaFrecuencia = 0;
    for (int i = 0; i < tamaño; i++)
    {
        if (frecuencias[i] > modaFrecuencia)
        {
            modaFrecuencia = frecuencias[i];
        }
    }
    // Encontrar los datos que tienen la frecuencia más alta
    float moda[tamaño];
    int modaCount = 0;
    for (int i = 0; i < tamaño; i++)
    {
        if (frecuencias[i] == modaFrecuencia)
        {
            moda[modaCount] = arreglo[i];
            modaCount++;
        }
    }
    // Imprimir los datos que tienen la frecuencia más alta
    for (int i = 0; i < modaCount; i++)
    {
        printf("%.2f ", moda[i]);
    }
    printf("\n");
    // Imprimir un mensaje si no hay moda
    //NAN es una macro que significa Not A Number, se usa para indicar que un valor no es un numero, en este caso, se usa para indicar que no hay moda
    return modaCount > 0 ? moda[0] : NAN;
}

// Función para calcular la varianza de un arreglo
float calcularVarianza(float arreglo[], int tamaño)
{
    // Calcular la media mediante la función ya creada
    float media = calcularMedia(arreglo, tamaño);

    float ssd = 0;
    for (int i = 0; i < tamaño; i++)
    {
        float diferencia = arreglo[i] - media;
        ssd += diferencia * diferencia;
    }

    float varianza = ssd / (tamaño - 1);

    return varianza;
}

// Función para calcular la desviación estándar de un arreglo
float calcularDesviacionEstandar(float arreglo[], int tamaño)
{
    // Calcular la desviacion estandar mediante la función ya creada
    float varianza = calcularVarianza(arreglo, tamaño);
    float desviacion_estandar = sqrt(varianza);

    return desviacion_estandar;
}

// Funcion para calcular el cuartil 1
float calcularCuartil1(float arreglo[], int tamaño)
{
    float indice = 0.25 * (tamaño + 1);

    // Si el índice no es un número entero, interpola entre los valores cercanos
    if (indice != (int)indice)
    {
        int i = (int)indice;
        float fraccion = indice - i;
        return arreglo[i - 1] + fraccion * (arreglo[i] - arreglo[i - 1]);
    }
    else
    {
        int i = (int)indice;
        return arreglo[i - 1];
    }
}

// Función para calcular el cuartil 3 (Q3) de un arreglo ordenado
float calcularCuartil3(float arreglo[], int tamaño)
{

    float indice = 0.75 * (tamaño + 1);

    // Si el índice no es un número entero, interpola entre los valores cercanos
    if (indice != (int)indice)
    {
        int i = (int)indice;
        float fraccion = indice - i;
        return arreglo[i - 1] + fraccion * (arreglo[i] - arreglo[i - 1]);
    }
    else
    {
        int i = (int)indice;
        return arreglo[i - 1];
    }
}

// Función para calcular el rango de un arreglo (la diferencia entre el valor máximo y el valor mínimo)
float calcularRango(float arreglo[], int tamaño)
{
        // Llamamos a las funciones para encontrar el máximo y el mínimo
        float maximo = encontrarMaximo(arreglo, tamaño);
        float minimo = encontrarMinimo(arreglo, tamaño);

        // Calculamos el rango como la diferencia entre el máximo y el mínimo
        float rango = maximo - minimo;

        return rango;
}

// Función para encontrar el valor máximo en un arreglo
float encontrarMaximo(float arreglo[], int tamaño)
{
    float maximo = arreglo[0]; // Suponemos que el primer elemento es el máximo inicialmente

    for (int i = 1; i < tamaño; i++)
    {
        if (arreglo[i] > maximo)
        {
            maximo = arreglo[i]; // Actualizamos el máximo si encontramos un valor mayor
        }
    }

    return maximo;
}

// Función para encontrar el valor mínimo en un arreglo
float encontrarMinimo(float arreglo[], int tamaño)
{
    float minimo = arreglo[0]; // Suponemos que el primer elemento es el mínimo inicialmente

    for (int i = 1; i < tamaño; i++)
    {
        if (arreglo[i] < minimo)
        {
            minimo = arreglo[i]; // Actualizamos el mínimo si encontramos un valor menor
        }
    }

    return minimo;
}

// Función para calcular el rango intercuartílico (IQR) de un arreglo
float calcularRIC(float arreglo[], int tamaño)
{
            ordenarArreglo(arreglo, tamaño);

        // Calcular el cuartil 1 (Q1) y el cuartil 3 (Q3)
        float q1 = calcularCuartil1(arreglo, tamaño);
        float q3 = calcularCuartil3(arreglo, tamaño);
        float iqr = q3 - q1;
        return iqr;
    }

// Función para cambiar un dato especifico del arreglo
void cambiarDato(float arreglo[], int tamaño, int posicion, float nuevoValor)
{
    if (posicion >= 0 && posicion < tamaño)
    {
        arreglo[posicion] = nuevoValor;
        printf("Dato en la posición %d cambiado a %.2f\n", posicion, nuevoValor);
    }
    else
    {
        printf("Posición fuera de rango. No se pudo cambiar el dato.\n");
    }
}
